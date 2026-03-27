---
title: Intuition Gadgets and Window Borders
manual: amiga-mail
chapter: amiga-mail
section: intuition-gadgets-and-window-borders
functions: []
libraries: []
---

# Intuition Gadgets and Window Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If 2.0 Intuition finds a gadget whose hit area (gadget Left/Top/
Width/Height) is substantially inside the border, it will be treated as
though it was declared in the border.  This is called ``bordersniffing''.
Gadgets declared as being in the border or detected by Intuition as being
in the border are refreshed each time after the border is refreshed, and
thus aren't clobbered.

Noteworthy special cases:

1) A gadget that has several pixels not in the border is not
   bordersniffed.  An example would be an 18-pixel high gadget in the
   bottom border of a SIZEBBOTTOM window.  About half the gadget will
   be clobbered by the border rendering.

2) A gadget that is not substantially in the border but has imagery that
   extends into the border cannot be sniffed out by Intuition.

3) A gadget that is substantially in the border but has imagery that
   extends into the main part of the window will be sniffed out as a
   border gadget, and this could change the refreshing results.  A
   common trick to put imagery in a window is to put a 1x1 or 0x0 dummy
   gadget at window location (0,0) and attach the window imagery to it.
   To support this, Intuition will never bordersniff gadgets of size |x|
   or smaller.

All these cases can be fixed by setting the appropriate GACT_xxxBORDER
gadget Activation flag.

4) In rare cases, buttons rendered with Border structures and JAM1 text
   may appear invisible under 2.0.  We apologize, but there is nothing
   that can be done on our end, even if the application technically did
   nothing wrong.

