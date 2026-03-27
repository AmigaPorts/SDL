---
title: Level One-Minimal Support
manual: amiga-mail
chapter: amiga-mail
section: level-one-minimal-support
functions: []
libraries: []
---

# Level One-Minimal Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application that meets Level One support requires only a few
enhancements from a standard CDTV-only title.

  1) Supports input from the keyboard and the mouse.

  2) Runs under both Release 1.3 and Release 2 of the operating system
  (which is expected of all CDTV titles).

  3) Includes a way for the user to start the title from a CLI and the

     Workbench.  Such a title may reboot the system when it starts up.
     It may take over the entire system, refuse to multitask with other
     programs, have no cleanup code, and never exit.
Commodore has developed a standard icon and associated code, called
BootCD, which developers may include on their CDTV disc.  This icon
will appear from the Workbench.  If the user double-clicks it, a
message will appear telling the user to remove any floppy disks from
the drive, and warning that pressing the Continue gadget will reboot
the system.  If the user continues, BootCD will reset the system, and
the system will then boot directly from your title on CD-ROM.

