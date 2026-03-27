---
title: 7 / / Setting and Clearing Bits / Master Interrupt Enable
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-master-interrupt-enable
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Master Interrupt Enable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bit 14 of the  [interrupt registers](hardware/7-interrupts-interrupt-control-registers.md)  (INTEN) is for interrupt enable. This
is the master interrupt enable bit. If this bit is a 0, it disables all
other interrupts. You may wish to clear this bit to temporarily disable
all interrupts to do some critical processing task.

   Warning:
   --------
   This bit is used for enable/disable only. It creates no interrupt
   request.

