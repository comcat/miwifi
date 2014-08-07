#!/bin/sh

nvram set flag_tftp_bootup=off

nvram unset flag_package_update
nvram unset flag_try_sys1_failed
nvram unset flag_try_sys2_failed
nvram unset flag_boot_rootfs
nvram unset flag_boot_type
nvram unset flag_ota_reboot
nvram unset flag_last_success

nvram unset flag_load_sys1_failed
nvram unset flag_tftp_booted

nvram commit

