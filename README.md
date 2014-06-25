
Xiaomi Router kernel
===

Support R1D router (with 1T sata disk). Mini will be supported in the furture.

The Kernel version is 2.6.36

WLAN driver are binary object file from Broadcom located in 'drivers/net/wl'


Feature
---

  o General Platform
    + ARM Cortex A9 Dual-Core
    + 32 KB I-cache and 32 KB D-cache per core
    + 256 KB L2 Cache (shared)
    + 128-entry TLB
    + SMP and AMP capable
    + Boot ROM

  o Bus
    + DDR3: Broadcom BCM4709 On-Chip DDR3 interface
    + PCI-E: Broadcom BCM4709 On-Chip PCI-E Controller 
    + USB: Broadcom BCM4709 On-Chip USB Controller
    + SPI: Broadcom BCM4709 On-Chip SPI Controller
    + SATA: ASMedia ASM1062 PCI-E SATA Controller

  o Network
    + Ethernet: Broadcom On-Chip 010/100/1000M  Ethernet Controller 
    + WLAN:
        + 2.4GHz: BCM43217, 802.11b/g/n Transceiver, PCIe 2.0 interface,
                   Radio + Baseband + MAC, 300Mbps
        + 5.0GHz: BCM4352, 2-Stream 802.11ac Transceiver (Support 802.11a/b/g/n)
                   PCIe 2.0 interface, Radio + Baseband + MAC, 867Mbps

  o Storage
    + NOR Flash: MXIC 25L12835F (16MB)
    + SATA Disk: Samsung 1T Sata disk 


Build
---

The following is validated in Ubuntu 12.04:

  $ sudo apt-get install lzma
  $ git clone git://github.com/comcat/miwifi.git
  $ export PATH=`pwd`/miwifi/toolchain/hndtools-arm-linux-2.6.36-uclibc-4.5.3/bin:$PATH
  $ cd miwifi/kernel/linux-2.6.36
  $ make ARCH=arm CROSS_COMPILE=arm-brcm-linux-uclibcgnueabi- vmlinuz -j4

The output image is arch/arm/boot/vmlinuz, you can load it from CFE via tftpboot
