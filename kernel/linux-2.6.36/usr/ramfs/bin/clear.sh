#!/bin/sh

nvram set flag_tftp_bootup=off
nvram set flag_package_update=0
nvram set flag_try_sys1_failed=0
nvram set flag_try_sys2_failed=0
nvram set flag_load_sys1_failed=0
nvram set flag_boot_rootfs=1
nvram set flag_boot_type=1
nvram commit

