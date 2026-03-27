---
title: Level Two-Support For Workbench Startup and Exit
manual: amiga-mail
chapter: amiga-mail
section: level-two-support-for-workbench-startup-and-exit
functions: []
libraries: []
---

# Level Two-Support For Workbench Startup and Exit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This level provides the user with a way to run CDTV applications
without rebooting the system.  A Level Two compliant title will also
return cleanly to the Workbench or the CLI when it is finished.  This
stage requires that a title:

  1) Supports input from the keyboard and the mouse.

  2) Runs under both Release 1.3 and Release 2.0 of the operating system.

  3) Launches from either the Workbench (via an icon) or the CLI.

  4) Manages any resources it allocates.

  5) Safely and Cleanly aborts in case any resource allocation fails.

  6) Cleans up properly upon exit, closing all libraries and devices, and

     returning all memory.
  7) Remembers the environment from which the user launched the title.

     If the user started the title from a CLI or Workbench, the title must
     be able to restore that environment cleanly.  If the title was booted
     directly from the CD-ROM, before exiting, the title should take
     precautions against leaving the system in an unusable environment.
     For example, if a title makes all of the Workbench colors black using
     the devs:system-configuration file, the user should not be allowed to
     return to the CLI or Workbench, as the user will only see a black
     screen.
In level two compatible titles, temporary assigns are acceptable.  The
application may assign system directories (such as fonts:, sys:, etc.)
to the CD during startup.  If it does so the title must restore any of
the assigns it reassigned.

A simple way to launch a title from a Workbench icon is using the IconX
utility.  This allows you to create a script that the system executes
when the user clicks on the program icon.  This script may contain any
assigns that a title requires.

An easy way a title can tell if the user booted directly from the
CD-ROM is checking for special command line arguments.  Imagine your
title is called ``MyApp''.  When the user boots the system from the
CD-ROM, the startup-sequence launches the application by using a
special command line, for example: ``MyApp ss''.  The ``ss'' tells the
title that the system was booted from the CD-ROM.  If the user starts
the application from the CLI, he would simply type ``MyApp''.  A title
might even utilize another special command line option to tell if it
was launched from an IconX script (i.e. ``MyApp iconx'').  Using this
method a title can detect how the user started it and can choose an
appropriate exit plan.

