---
title: 32 / Expansion Board Drivers / ROM Based and Autoboot Drivers
manual: libraries
chapter: libraries
section: 32-expansion-board-drivers-rom-based-and-autoboot-drivers
functions: []
libraries: []
---

# 32 / Expansion Board Drivers / ROM Based and Autoboot Drivers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Since 1.3, the system software supports the initialization of ROM drivers
residing on expansion peripherals, including the ability for drivers to
provide a DOS node which the system can boot from. This feature is known
as Autoboot.

Automatic boot from a ROM-equipped expansion board is accomplished before
DOS is initialized.  This facility makes it possible to automatically boot
from a hard disk without any floppy disks inserted.  Likewise, it is
possible to automatically boot from any device which supports the ROM
protocol, even allowing the initialization of a disk operating system
other than the Amiga's dos.library.  ROM-based drivers contain several
special entry points that are called at different stages of system
initialization. These three stages are known as DIAG, ROMTAG INIT and BOOT.

 [Events At DIAG Time](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)    [Events At ROMTAG INIT Time](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md)    [Events At BOOT Time](libraries/32-rom-based-and-autoboot-drivers-events-at-boot-time.md) 

