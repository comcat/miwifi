
Xiaomi Router kernel
===

Support R1D router (with 1T sata disk). Mini will be supported in the furture.


Feature
---

+ Kernel 2.6.36 
+ SPI Flash     (MXIC 25L12835F)
+ SATA Support  (ASM1062)
+ Ethernet      (BCM47xx 1G)


Build
---

    $ export PATH=/path/to/toolchain/hndtools-arm-linux-2.6.36-uclibc-4.5.3/bin:$PATH
    $ cd /path/to/kernel/linux-2.6.36
    $ make ARCH=arm CROSS_COMPILE=arm-brcm-linux-uclibcgnueabi- vmlinux -j4

