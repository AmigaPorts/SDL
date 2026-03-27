---
title: Supporting the Interface in Software
manual: amiga-mail
chapter: amiga-mail
section: supporting-the-interface-in-software
functions: []
libraries: []
---

# Supporting the Interface in Software

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because this "+2" joystick adapter attaches to the parallel port,
supporting it in software is simply a matter of reading the correct
lines on the parallel port.

Many Amiga game programmers make the decision to throw away the OS and
directly manipulate the hardware.  These programmers will no doubt come
up with their own personal scheme for reading the appropriate
information from the port.  Other, more forward thinking developers,
may want to write their software in such a way as to be compatible with
the OS.

The following pair of code samples work in tandem to demonstrate one
method of reading the necessary information from the parallel port in
an OS friendly manner.  The C program [4play.c](amiga-mail/ix-1-4play-c.md) is a simple example that
demonstrates how to access the assembly functions.  The assembly
language program [read34.asm](amiga-mail/ix-1-read34-asm.md) properly allocates the parallel port and any
necessary signal lines, warning the OS not to let any other applications
use them.  Other assembly routines do the actual hardware level reading
and place the joystick values into C variables.  A cleanup routine
releases the port and signal lines.  The example does not mask out the
directional or fire button bits, it only prints the raw joystick data.
I'll leave it as an exercise for the reader to interpret the meaning of
the raw data.

   [lmkfile](amiga-mail/ix-1-lmkfile.md) 

