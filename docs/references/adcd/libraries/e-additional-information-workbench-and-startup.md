---
title: E / Additional Information / Workbench And Startup
manual: libraries
chapter: libraries
section: e-additional-information-workbench-and-startup
functions: []
libraries: []
---

# E / Additional Information / Workbench And Startup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Under 1.3, the Workbench Screen and initial Shell (CLI) opened before the
first line in s:startup-sequence.  Some naughty programmers, in an attempt
to recover memory, would search for the bitplane pointers and appropriate
the memory for their own use.  This behavior is unsafe.

By default 2.0 opens the initial CLI on the first _output_ from the
s:startup-sequence.  This allows screen modes and other parameters to be
set before the user sees the screen.  However, this broke so many programs
that we put in the "silent-startup" hack.  A disk installed with 1.3
install opens the screen as before.  A disk installed under 2.0 opens
silently. Never steal the Workbench bitplanes.  You don't know where they
are, how big they are, what format they may be in, or even if they are
allocated.  Recovering the memory is a bit tricky.

Under 2.0, simply avoid any output from your s:startup-sequence.  If your
program opens a screen it will be the first screen the user ever sees.
Note that if ENDCLI is ever hit, the screen will pop open.

Under 1.3, after ENDCLI, use [CloseWorkbench()](libraries/3-public-screen-functions-the-default-public-screen-and.md) to close the screen.  This
also works under 2.0.  Loop on CloseWorkbench() with a delay between
loops.  Continue looping until CloseWorkbench() succeeds or too much time
has passed.  Note that a new program called EndRun is available for
starting non-returning programs from the startup-sequence.  EndRun will
reduce memory fragmentation and will close Workbench if it is open.
EndRun.lzh will be available in Commodore's Amiga listings area on BIX.

