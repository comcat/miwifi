#
# Makefile for Broadcom Home Networking Division (HND) shared driver code
#
# Copyright (C) 2013, Broadcom Corporation. All Rights Reserved.
# 
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
# OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
# CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

SHARED   := ../../../arch/arm/plat-brcm/shared
WLSHARED := wlconfig_lx_shared
WLCFGDIR := $(src)/../wl/wl_arm/wl/config
WLSYSDIR := $(src)/../wl/wl_arm/wl/sys

EXTRA_CFLAGS += -Iarch/arm/plat-brcm/shared/bcmwifi/include

ifeq ($(CONFIG_BUZZZ_FUNC),y)
subdir-ccflags-y += -O0 -fno-inline -finstrument-functions
endif # CONFIG_BUZZZ_FUNC

obj-$(CONFIG_HND) := hnd.o shared_ksyms.o

ifneq ($(wildcard $(WLCFGDIR)),)
include $(WLCFGDIR)/$(WLSHARED)
include $(WLCFGDIR)/wl.mk
endif

hnd-objs := $(addprefix $(SHARED)/, $(sort $(WLFILES:.c=.o)))
HND_OBJS := $(addprefix $(src)/$(SHARED)/, $(sort $(WLFILES:.c=.o)))

EXTRA_CFLAGS += $(WLFLAGS) -DBCM5354 -DLINUX_HYBRID_POSTPROCESSING_REMOVAL

# For the ARM platform...
ifneq ($(CONFIG_MACH_BRCM_NS),)
EXTRA_CFLAGS    += -DROBO_SRAB -DBCMDMASGLISTOSL
endif

ifneq ($(CONFIG_BCM947XX),y)
HND_OBJS += $(SHARED)/nvramstubs.o
hnd-objs += $(SHARED)/nvramstubs.o
endif

ifeq ($(CONFIG_ET_47XX),y)
HND_OBJS += $(SHARED)/bcmrobo.o
hnd-objs += $(SHARED)/bcmrobo.o
else
ifeq ($(CONFIG_BCM57XX),y)
HND_OBJS += $(SHARED)/bcmrobo.o
hnd-objs += $(SHARED)/bcmrobo.o
endif
endif

ifdef CONFIG_USB_RNDIS
EXTRA_CFLAGS += -DCONFIG_USBRNDIS_RETAIL
endif                                  

ifeq ($(BCMDBG_MEM),1)
EXTRA_CFLAGS += -DBCMDBG_MEM
endif

$(src)/shared_ksyms.c:
	sh -e $(src)/shared_ksyms.sh $(HND_OBJS) > $@

$(src)/shared_ksyms.o: $(src)/shared_ksyms.c

clean-files += $(SHARED)/*.o $(SHARED)/.*.o.cmd
