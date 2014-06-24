#
# Makefile for the Dualband Proxy STA
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
# $Id: Makefile 345839 2012-07-19 07:38:57Z $
#

obj-${CONFIG_DPSTA} := dpsta.o

DPSTASRC := src
DPSTAOBJ := $(DPSTASRC)/dpsta_linux.o
SYMOBJ := $(DPSTASRC)/dpsta_linux.o

# Search for sources under src/router/dpsta
ifneq (,$(wildcard $(src)/$(DPSTASRC)/*.c))
  EXTRA_CFLAGS += -I$(src)
  dpsta-objs := $(DPSTAOBJ) dpsta_ksyms.o
else
  dpsta-objs := dpsta_obj.o
endif

$(src)/dpsta_obj.o: $(src)/dpsta_arm/dpsta.obj FORCE
	$(call if_changed,genobj)

PHONY += $(src)/dpsta_ksyms.c

quiet_cmd_ksyms = CALL    $<
      cmd_ksyms = $(CONFIG_SHELL) -e $< $(src)/$(SYMOBJ) > $@

$(src)/dpsta_ksyms.c: $(src)/dpsta_ksyms.sh $(src)/$(SYMOBJ) FORCE
	$(call cmd,ksyms)

clean-files += $(DPSTASRC)/*.o $(DPSTASRC)/.*.o.cmd
