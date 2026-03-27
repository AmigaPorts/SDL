---
title: 11 / Amiga BootStrap / Bootblock Booting
manual: devices
chapter: devices
section: 11-amiga-bootstrap-bootblock-booting
functions: []
libraries: []
---

# 11 / Amiga BootStrap / Bootblock Booting

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In BootBlock booting the sequence of events is as follows:

   1. The disk device must contain valid boot blocks:


```c
       a) the device and unit from dn_Startup opens successfully,

       b) memory is available for the <de_BootBlocks> * <de_SizeBlock> * 4
          bytes of boot block code,

       c) the device commands CMD_CLEAR, [TD_CHANGENUM](autodocs-2.0/trackdisk-device-td-changenum.md), and CMD_READ of the
          boot blocks execute without error,

       d) the boot blocks start with the three characters "DOS" and pass
          the longword checksum (with carry wraparound), and

       e) memory is available to construct a boot node on the eb_MountList
          to describe the floppy.  If a device error is reported in 1.c.,
          or if memory is not available for 1.b. or 1.e., a recoverable
          alert is presented before continuing.
```
   2. The boot code in the boot blocks is invoked as follows:


```c
       a) The address of the entry point for the boot code is offset
          BB_ENTRY into the boot blocks in memory.

       b) The boot code is invoked with the I/O request used to issue the
          device commands in 1.c. above in register A1, with the io_Offset
          pointing to the beginning of the partition (the origin of the
          boot blocks) and SysBase in A6.
```
   3. The boot code returns with results in both D0 and A0.


```c
       a) Non-zero D0 indicates boot failure.  The recoverable alert
          AN_BootError is presented before continuing.

       b) Zero D0 indicates A0 contains a pointer to the function to
          complete the boot.  This completion function is chained to with
          SysBase in A6 after the strap module frees all its resources.
          It is usually the dos.library initialization function, from the
          dos.library resident tag.  Return from this function is
          identical to return from the strap module itself.
```
