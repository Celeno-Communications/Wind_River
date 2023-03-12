#!/bin/sh

[ -z "$CL_PCI_BASE_ADDR" ] && { echo "PCI BASE ADDR not set" ; exit 1 ; }
BA=$(( $CL_PCI_BASE_ADDR ))


# TestControl structure to set up test parameters for LMAC
# .version
mem `printf 0x%X $(( BA + 0x2000 ))` w 4
# .sequence
mem `printf 0x%X $(( BA + 0x2004 ))` w 1
# .cmd (should be IDLE at the beginning, 0 - IDLE, 1 - START)
mem `printf 0x%X $(( BA + 0x2008 ))` w 0
# .ep
mem `printf 0x%X $(( BA + 0x200c ))` w 2
# .lli_channel
mem `printf 0x%X $(( BA + 0x2010 ))` w 4
# .number_pdma
mem `printf 0x%X $(( BA + 0x2014 ))` w 11
# .direction (0 - LMAC to Host, 1 - Host to LMAC)
mem `printf 0x%X $(( BA + 0x2018 ))` w 0
# .packets.packet_count
mem `printf 0x%X $(( BA + 0x201c ))` w 0x100b
# .packets.number_bytes (= packet_count * packet_size)
mem `printf 0x%X $(( BA + 0x2020 ))` w $((0x100b * 1532))
# .packets.pattern
mem `printf 0x%X $(( BA + 0x2024 ))` w 3
# .stop_start_lli_at_packet
mem `printf 0x%X $(( BA + 0x2028 ))` w 0
# .ignore_lli_error
mem `printf 0x%X $(( BA + 0x202c ))` w 1
# .finalize_cond.cause
mem `printf 0x%X $(( BA + 0x2030 ))` w 0
# .finalize_cond.param1
mem `printf 0x%X $(( BA + 0x2034 ))` w 1


# TestControl structure to set up test parameters for SMAC
# .version
mem `printf 0x%X $(( BA + 0x4000 ))` w 4
# .sequence
mem `printf 0x%X $(( BA + 0x4004 ))` w 1
# .cmd (should be IDLE at the beginning, 0 - IDLE, 1 - START)
mem `printf 0x%X $(( BA + 0x4008 ))` w 0
# .ep
mem `printf 0x%X $(( BA + 0x400c ))` w 2
# .lli_channel
mem `printf 0x%X $(( BA + 0x4010 ))` w 0
# .number_pdma
mem `printf 0x%X $(( BA + 0x4014 ))` w 3
# .direction (0 - LMAC to Host, 1 - Host to LMAC)
mem `printf 0x%X $(( BA + 0x4018 ))` w 1
# .packets.packet_count
mem `printf 0x%X $(( BA + 0x401c ))` w 0x20
# .packets.number_bytes (= packet_count * packet_size)
mem `printf 0x%X $(( BA + 0x4020 ))` w $((0x20 * 160))
# .packets.pattern
mem `printf 0x%X $(( BA + 0x4024 ))` w 1
# .stop_start_lli_at_packet
mem `printf 0x%X $(( BA + 0x4028 ))` w 3
# .ignore_lli_error
mem `printf 0x%X $(( BA + 0x402c ))` w 0
# .finalize_cond.cause
mem `printf 0x%X $(( BA + 0x4030 ))` w 0
# .finalize_cond.param1
mem `printf 0x%X $(( BA + 0x4034 ))` w 1
