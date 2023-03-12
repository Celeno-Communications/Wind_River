#!/bin/sh

# This script is needed for transparent support of non-busybox platforms,
# which don't have the 'usleep' command. For such platforms, we define a
# function with the same name, which emulates 'usleep' by calling 'sleep'
# with a fractional timeout.
# Note that using 'sleep' like this on busybox doesn't work, because
# Busybox's sleep doesn't accept fractional timeouts.

which usleep > /dev/null ||
usleep()
{
	sleep $@e-6
}
