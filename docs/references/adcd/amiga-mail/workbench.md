---
title: Workbench
manual: amiga-mail
chapter: amiga-mail
section: workbench
functions: []
libraries: []
---

# Workbench

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* The Workbench GUI now has new screen sizes, screen top/left offsets,
  depths, modes, and fonts.

* Default Tool now searches paths.

* New Look (boxed) icons take more space.

* Do not use icons which have more 1bits set in PlanePick than planes in
  the ImageData (one IFF-to-Icon utility does this).  Such icons will
  appear trashed on deeper Workbenches.

* New Look colors have black and white swapped (as compared to 1.3).

* The Workbench screen may not be open at startup-sequence time until
  some output occurs to the initial Shell window.  This can break
  startup-sequence-started games that think they can steal WB's screen
  bitplanes.  Do not steal the WB screen's planes (For compatibility,
  booting off pre-2.0 disks forces the initial screen open.  This is not
  guaranteed to remain in the system).  Use startup code that can detach
  when RUN (such as cback.o) and use CloseWorkbench() to regain the
  screen's memory.

  Under 1.3 the Workbench Screen and initial CLI opened before the first
  line in s:startup-sequence.  Some naughty programmers, in an attempt to
  recover memory, would search for the bitplane pointers and appropriate
  the memory for their own use.  This behavior is highly unsafe.

  By default 2.0 opens the initial CLI on the first _output_ from the
  s:startup-sequence.  This allows screen modes and other parameters to be
  set before the user sees the screen.  However, this broke so many
  programs that we put in the ``silent-startup'' hack.  A disk installed
  with 1.3 install opens the screen as before.  A disk installed under 2.0
  opens silently.

  Never steal the Workbench bitplanes.  You don't know where they are, how
  big they are, what format they may be in, or even if they are allocated.
  Recovering the memory is a bit tricky.

  Under 2.0:  Simply avoid any output from your s:startup-sequence.  If
  your program opens a screen it will be the first screen the user ever
  sees.  Note that if ENDCLI is ever hit, the screen will pop open.

  Under 1.3:  After ENDCLI, call the CloseWorkbench() function to close
  the screen.  This also works under 2.0.  Loop on CloseWorkbench() with a
  delay between loops.  Continue looping until CloseWorkbench() succeeds
  or too much time has passed.  Note that a new program called EndRun is
  available for starting non-returning programs from the startup-sequence.
  EndRun will reduce memory fragmentation and will close Workbench if it
  is open.  EndRun.lzh will be available in Commodore's Amiga listings
  area on BIX.

