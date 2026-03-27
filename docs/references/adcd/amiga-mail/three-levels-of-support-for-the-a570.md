---
title: Three Levels of Support for the A570
manual: amiga-mail
chapter: amiga-mail
section: three-levels-of-support-for-the-a570
functions: []
libraries: []
---

# Three Levels of Support for the A570

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Full support for the A570 implies numerous constraints for the CDTV
developer.  He has to worry about supporting a keyboard, working with
different versions of the operating system, dealing with varying memory
configurations and working around differences between Amiga and CDTV
displays.  The issues of starting, exiting, and multitasking titles
remain.

There are several Amiga/CDTV configurations that may be booted into a
CLI or Workbench environment: Amiga + A570, any Amiga computer equipped
with a CD-ROM, and a CDTV player with a floppy or hard disk attached.
In these cases, the user may want to launch a CDTV title from that
environment.  If he does so, he will expect the title to exit cleanly,
release all memory, remove any special assigns that may have been
executed, etc.

Users may even want to multitask a title.  Most Amiga applications may
be multitasked, and the user may well expect the same from a CDTV
title.  Reference titles would be significantly enhanced if they
supported cutting-and-pasting directly into another application like a
word processor.  Those developing dictionary and encyclopedia titles
may want to provide access methods for users or other applications to
search on a key word.  Some may even want to add an ARexx port.

These issues, while reasonable requests from a user, add significant
new burdens to the developer.  Many CDTV titles are designed to take
over the machine.  Many of these titles require all the memory
available in the system (and even more, in some cases).  They often
make special assigns for fonts, data, etc.  Many include no clean-up
code.

Full compliance to AmigaDOS standards may be unreasonable for some
titles.  To address this problem, we have established three levels of
compatibility for CDTV titles running on Amigas: Minimal Support,
Support For Workbench Startup and Exit, and Full Multitasking Support.

 [Level One-Minimal Support](amiga-mail/level-one-minimal-support.md) 
 [Level Two-Support For Workbench Startup and Exit](amiga-mail/level-two-support-for-workbench-startup-and-exit.md) 
 [Level Three-Full Multitasking Support](amiga-mail/level-three-full-multitasking-support.md) 

