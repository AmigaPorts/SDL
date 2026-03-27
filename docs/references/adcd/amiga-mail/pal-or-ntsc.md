---
title: PAL or NTSC?
manual: amiga-mail
chapter: amiga-mail
section: pal-or-ntsc
functions: []
libraries: []
---

# PAL or NTSC?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some programs need to determine if the Workbench screen is in PAL or
NTSC mode.  Before release 2.0, it was impossible for the system to
switch between NTSC and PAL.  The PAL/NTSC state in which the machine
booted dictated the mode of its displays.  Pre-V36 systems could
determine the PAL/NTSC state of the machine by examining a bit the in
GfxBase->DisplayFlags field, which is set at boot time under all
versions of the OS.

Thanks to the ECS and the new system software, PAL and NTSC display
resolutions can coexist, which obsoletes examining GfxBase->DisplayFlags
to determine the PAL/NTSC state of a particular system.  Release 2.0
ignores the PAL/NTSC flag after it sets the flag at boot time.  This
means that under 2.0, if the system boots as NTSC, it is not possible
to open a PAL screen in a way that will work correctly with release 1.3.

To respect the user setup of the Workbench rather than the default
video mode, a program should use the V36 graphics.library and
intuition.library functions to determine the display mode ID of the
Workbench screen.  Using that ID, an application can open a screen or
find more information about the properties of the Workbench screen.
The [extscreen.c](amiga-mail/iv-17-extscreen-c.md) example at the end of this article shows how to check
for a PAL mode screen under any version of the operating system.

