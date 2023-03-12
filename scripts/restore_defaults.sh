#! /bin/sh

# Usage: restore_defaults.sh {target}  [mode]
#        (mode = "")        -->  restore default for all files but keep parameters value according to "keep_restore_defaults" file
#        (mode = sw_update) -->  restore default for all files but keep parameters value according to "keep" file
#
# at all the modes the script will create a new configuration file if configuration file is missing for all interface.

#upper case to lower case
to_lower()
{
	echo "$1" | awk '{print tolower($0)}'
}

#lower case to upper case
to_upper()
{
	echo "$1" | awk '{print toupper($0)}'
}

#read create new nvram and consider keep_restore_defaults
restore_param_by_param()
{
	cp $current_file $old_nvram_tmp
	cp $default_file $default_nvram_tmp

	if [ -f $keep_file ]; then
		cp $keep_file $keep_tmp
	fi

	rm -rf $new_nvram_tmp

	echo "Update the new NVRAM temp file with _DEFAULT_s from the old NVRAM" > $output_dev

	while read new_nvram_line
	do
		# ignore empty lines, lines that start with '#'
		# a line that doesn't start with '#' but contains '#' is copied
		# i.e. ce_regulatory_table=20(36=24;40=26;52=30;149=25;153=26)#40(36=20;44=29;52=30;149=26;157=25)#80(36=21;52=30;149=27)
		if [ -z "$new_nvram_line" ] || [ "${new_nvram_line:0:1}" == "#" ]; then
			continue
		fi
		new_nvram_key=`echo $new_nvram_line | awk -F'=' '{print $1}'`

		key_exist=$(grep ^$new_nvram_key= $old_nvram_tmp)
		if [ -z "$key_exist" ]; then
			echo "$new_nvram_line" >> $new_nvram_tmp
		else
			if [ -f $keep_tmp ]; then
				key_keep=$(grep ^$new_nvram_key $keep_tmp)
				if [ ! -z "$key_keep" ]; then
					echo "$key_exist" >> $new_nvram_tmp
				else
					echo "$new_nvram_line" >> $new_nvram_tmp
				fi
			else
				echo "$new_nvram_line" >> $new_nvram_tmp
			fi
		fi
	done < $default_nvram_tmp

	mv $new_nvram_tmp $current_file
	rm -rf $old_nvram_tmp $keep_tmp $default_nvram_tmp
}

# test all files for restore exist either create new file or restore defaults 
# for old one
main_restore_function()
{
	if [ ! -f "$default_file" -a ! -h "$default_file" ]; then
		echo "ERROR: No defaults file! Aborting."
		exit 1
	fi

	if [ ! -f "$current_file" -a ! -h "$current_file" ]; then
		echo "No configuration file found, creating a new one" > $output_dev
		mkdir -p `dirname $current_file`
		cp $default_file $current_file
	else
		restore_param_by_param
	fi

	if [[ "$target" == "tcv"* ]] && [ "$iface_type" == "sta" ]; then
		upper_band="$(to_upper "$band")"
		$cl_install_dir/scripts/nvram_set $target ce_iface_type "2,0,0,0,0,0,0,0"
		if [ -z "$($cl_install_dir/scripts/nvram_get $target ws_ssid)" ]; then
			$cl_install_dir/scripts/nvram_set $target ws_ssid "CL6K_AP_$upper_band"
		fi
		if [ -z "$($cl_install_dir/scripts/nvram_get $target ws_auth_mode)" ]; then
			$cl_install_dir/scripts/nvram_set $target ws_auth_mode "WPA2PSK"
		fi
		if [ -z "$($cl_install_dir/scripts/nvram_get $target ws_key)" ]; then
			$cl_install_dir/scripts/nvram_set $target ws_key "12345678"
		fi
	fi
}

validate_tcv_restore()
{
	if [ "$1" == "tcv0" ] && [ ! -f "$cl_cfg_dir/cl_chip0.dat" ]; then
		echo "ERROR: restore_defaults of chip0 first"
		exit 1
	fi

	if [ "$1" == "tcv2" ] && [ ! -f "$cl_cfg_dir/cl_chip1.dat" ]; then
		echo "ERROR: restore_defaults of chip1 first"
		exit 1
	fi

	if [ "$1" == "tcv4" ] && [ ! -f "$cl_cfg_dir/cl_chip2.dat" ]; then
		echo "ERROR: restore_defaults of chip2 first"
		exit 1
	fi

	if [ "$1" == "tcv6" ] && [ ! -f "$cl_cfg_dir/cl_chip3.dat" ]; then
		echo "ERROR: restore_defaults of chip3 first"
		exit 1
	fi

	if [ -n "$2" ] && [ "$2" != "24g" -a "$2" != "5g" -a "$2" != "6g" ]; then
		echo "band $2 is invalid (should be 24g/5g/6g)"
		exit 1
	fi

	if [ -n "$3" ] && [ "$3" != "ap" -a "$3" != "sta" ]; then
		echo "iface type $3 is invalid (should be ap/sta)"
		exit 1
	fi
}

restore_rfic_file()
{
	local file=$cl_cfg_dir/rfic/$1.txt
	local backup_file=$cl_cfg_dir/rfic/backup_$1.txt

	if [ -f $file ] ; then
		echo "Remove $file and save a backup"
		cp $file $backup_file
		rm $file
	fi
}

restore_rfic_files()
{
	restore_rfic_file rf_init_overwrite
	restore_rfic_file rf_tcv0_overwrite
}

#run restore params for the specified target
run_action()
{
	old_nvram_tmp=$tmp_folder/"$target"_old

	# Make sure we are not restoring TCVX before its chip file is present
	validate_tcv_restore $target $band $iface_type

	case "$target" in
		"chip0"|"chip1"|"chip2"|"chip3")
			default_file_prefix=$cl_install_dir/config/cl_$target
			current_file=$cl_cfg_dir/cl_$target.dat

			if [ -f "${default_file_prefix}_bt.dat" ]; then
				cp ${default_file_prefix}_bt.dat $cl_cfg_dir/
			fi
		;;
		"tcv0"|"tcv2"|"tcv4"|"tcv6")
			default_file_prefix=$cl_install_dir/config/cl_"$target"_"$band"
			current_file=$cl_cfg_dir/cl_$target.dat
		;;
		"chip0_full")
			target="chip0"
			run_action
			target="tcv0"
			run_action
		;;
		"chip1_full")
			target="chip1"
			run_action
			target="tcv2"
			run_action
		;;
		"chip2_full")
			target="chip2"
			run_action
			target="tcv4"
			run_action
		;;
		"chip3_full")
			target="chip3"
			run_action
			target="tcv6"
			run_action
		;;
		"all")
			target="chip0"
			run_action
			target="chip1"
			run_action
			target="chip2"
			run_action
			target="chip3"
			run_action
			target="tcv0"
			run_action
			target="tcv2"
			run_action
			target="tcv4"
			run_action
			target="tcv6"
			run_action

			restore_rfic_files
		;;
		*)
			echo "Parameter is $target and not chip0|chip1|tcv0|tcv2|chip0_full|chip1_full|all"
			exit 2
		;;
	esac
	[ -f ${default_file_prefix}_default ] && default_file=${default_file_prefix}_default || default_file=${default_file_prefix}_default
	if [ "$sw_update" -eq 1 ]; then
		[ -f ${default_file_prefix}_default_keep ] && keep_file=${default_file_prefix}_default_keep || keep_file=${default_file_prefix}_default_keep
	else
		[ -f ${default_file_prefix}_default_keep_restore_defaults ] && keep_file=${default_file_prefix}_default_keep_restore_defaults || keep_file=${default_file_prefix}_default_keep_restore_defaults
	fi
	main_restore_function
}

#pre_run function sets all environment/global variables
pre_run()
{
	export cl_install_dir=${cl_install_dir-/cl6k}
	# test to see that environment settings exist
	if [ ! -f "$cl_install_dir/scripts/env.sh" ]
	then
		echo "env.sh missing, please make sure that cl_cfg_dir and cl_install_dir are set properly ..."
		exit 1
	else
		. "$cl_install_dir/scripts/env.sh"
	fi

	if [ -z "$1" ]
	then
		echo "target is not defined in restore_defaults!"
		exit 1
	fi

	sw_update=0

	if [ "$2" = "sw_update" ]
	then
		echo "Restore defaults on sw_update mode"
		sw_update=1
	fi

	output_dev="/dev/null"
	if [ "$3" = "debug" ]
	then
		output_dev="/dev/stdout"
	fi

	if [ -x /tmp ]; then
		tmp_folder=/tmp
	elif [ -x /var/tmp ]; then
		tmp_folder=/var/tmp
	else
		echo "ERROR: No temp dir to work in !!! Aborting."
		exit 1
	fi

	default_nvram_tmp=$tmp_folder/"$target"_default
	new_nvram_tmp=$tmp_folder/"$target"_new
	keep_tmp=$tmp_folder/"$target"_keep
	if [ "$TARGET_PLATFORM" != "EDK32" ]; then
		iface_type="sta"
		band="24g"
	fi
	source $cl_install_dir/scripts/init_dev_id.sh
}

do_print_usage()
{
	cat <<-EOF
	Usage:
		restore_defaults.sh <target> <band> <iface type>

		target:
		all - restore chip0, chip1, chip2, chip3, tcv0, tcv2, tcv4, tcv6
		chip0 - restore chip0
		chip1 - restore chip1
		chip2 - restore chip2
		chip3 - restore chip3
		tcv0 - restore tcv0
		tcv2 - restore tcv2
		tcv4 - restore tcv4
		tcv6 - restore tcv6
		chip0_full - restore chip0 and tcv0
		chip1_full - restore chip1 and tcv2
		chip2_full - restore chip2 and tcv4
		chip3_full - restore chip3 and tcv6

		band: (optional and only relevant for target: tcv*)
		24g|5g|6g

		iface type: (optional and only relevant for target: tcv*)
		ap|sta
	EOF
}

iface_type=ap
band=5g
pre_run $@
# parse command line parameters
while [[ $# -ge 1 ]]
do
	case "$1" in
		chip0|chip1|chip2|chip3|tcv0|tcv2|tcv4|tcv6|chip0_full|chip1_full|chip2_full|chip3_full|all)
			target=$1
		;;
		24g|5g|6g)
			band=$1
		;;
		ap|sta)
			iface_type=$1
		;;
		*)
			do_print_usage
			exit 0
		;;
	esac
	shift
done

run_action
