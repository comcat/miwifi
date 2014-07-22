#!/bin/sh

restore=`nvram get restore_defaults`
boardflags2=`nvram get pci/1/1/boardflags2`
boardflags3=`nvram get telnet_en`
if [ -z "$boardflags2" ] || [ -z "$boardflags3" ]; then
	nvram_corrupt=1
fi

#restore: 1, 恢复出厂设置；2，ota升级 	#nvram_corrupt: 1, nvram被破坏
if [ -s /usr/share/xiaoqiang/xiaoqiang-defaults.txt ]; then
	if [ "$restore" = "1" ] || [ "$restore" = "2" ] || [ "$nvram_corrupt" = "1" ]; then
		cat /usr/share/xiaoqiang/xiaoqiang-defaults.txt | while read line
		do
			nvram set "$line"
		done

		#bdata sync
		nvram commit
	fi
fi

