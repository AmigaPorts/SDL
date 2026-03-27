---
title: D Troubleshooting Guide / A Final Word About Testing
manual: libraries
chapter: libraries
section: d-troubleshooting-guide-a-final-word-about-testing
functions: []
libraries: []
---

# D Troubleshooting Guide / A Final Word About Testing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Test your program with memory watchdog and invalidation tools on a wide
variety of systems and configurations.  Programs with coding errors may
appear to work properly on one or more configurations, but may fail or
cause fatal problems on another.  Make sure that your code is tested on
both a 68000 and a 68020/30, on machines with and without Fast RAM, and on
machines with and without enhanced chips.  Test all of your program
functions on every machine.

Test all error and abort code.  A program with missing error checks or
unsafe cleanup might work fine when all of the items it opens or allocates
are available, but may fail fatally when an error or problem is
encountered.  Try your code with missing files, filenames with spaces,
incorrect filenames, cancelled requesters, Ctrl-C, missing libraries or
devices, low memory, missing hardware, etc.

Test all of your text input functions with high-ASCII characters (such as
the character produced by pressing Alt-F then "A").  Note that [RAWKEY](libraries/9-event-message-classes-and-flags-other-flags.md)
codes can be different keyboard characters on national keyboards (higher
levels of keyboard input are automatically translated to the proper
characters).  If your program will be distributed internationally, support
and take advantage of the additional screen lines available on a PAL
system.  Enhanced Agnus chip machines may be switched to be PAL or NTSC
via motherboard jumper J102 in A2000s and jumper J200 in A3000s.  Note
that a base PAL machine will have less memory free due to the larger
display size.

Write good code.  Test it.  Then make it great.

