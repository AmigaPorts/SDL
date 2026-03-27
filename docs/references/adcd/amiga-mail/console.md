---
title: Console
manual: amiga-mail
chapter: amiga-mail
section: console
functions: []
libraries: []
---

# Console

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* By default, CON: now opens SIMPLE_REFRESH windows using the V36/V37
  console character mapped mode.  Because of some differences between
  character mapped consoles, and SMART_REFRESH non-mapped consoles, this
  may cause incompatibilities with some applications.  For example, the
  Amiga private sequences to set left/top offset, and set line/page length
  behave differently in character mapped console windows.  The only known
  work-around is to recompile asking for a CON: (or RAW:) window using the
  SMART flag.

* Simple refresh/character mapped console windows now support the
  ability to highlight, and copy text with the mouse.  This feature, as
  well as pasting text should be transparent to programs which use CON:
  for console input, and output.  Pasted text will appear in your input
  stream as if the user had typed it.

* While CONCLIP (see s:startup-sequence) is running, programs may
  receive ``<CSI>0 v'' in their input stream indicating the user wants to
  paste text from the clipboard.  This shouldn't cause any problems for
  programs which parse correctly (however we know that it does; the most
  common problems are outputting the sequence, or confusing it with
  another sequence like that for FKEY 1 which is ``<CSI>0~'').

* The console.device now renders a ghosted cursor in inactive console
  windows (both SMART_REFRESH, and SIMPLE_REFRESH with character maps).
  Therefore, rendering over the console's cursor with graphics.library
  calls can trash the cursor; if you must do this, first turn off the
  cursor.

* Some degree of unofficial support has been put in for programs which
  use SMART_REFRESH console windows, and use graphics.library calls mixed
  with console.device sequences to scroll, draw text, clear, etc.  This is
  not supported in SIMPLE_REFRESH windows with character maps, and is
  strongly discouraged in all cases.

* Closing an Intuition window before closing the attached console.device
  worked in the past; it will now crash or hang the machine.

* Under 1.2-1.3, vacated portions of a console window (e.g., areas
  vacated because of a clear, or a scroll) were filled in with the
  character cell color.  As of V36 this is no longer true; vacated areas
  are filled in with the global background color which can be set using
  the SGR sequence ``<ESC>[>##m'' where ## is a value between 0-7.  In
  order to set the background color under V36/V37, send the SGR to set
  background color, and a FormFeed to clear the screen.

* Note that SIMPLE_REFRESH character mapped consoles are immediately
  redrawn with the global background color when changed--this is not
  possible with SMART_REFRESH windows.

