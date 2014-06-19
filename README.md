
Xiaomi Router kernel
===

Support R1D router (with 1T sata disk). Mini will be supported in the furture.


Feature
---

+ 2.6.36 kernel
+ SPI Flash
+ SATA Support


Build
---

    $ export PATH=/path/to/toolchain/hndtools-arm-linux-2.6.36-uclibc-4.5.3/bin:$PATH
    $ cd /path/to/kernel/linux-2.6.36
    $ make ARCH=arm CROSS_COMPILE=arm-brcm-linux-uclibcgnueabi- vmlinux -j4

