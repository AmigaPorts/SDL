---
title: 8 / The Keyboard / Limitations Of The Keyboard
manual: hardware
chapter: hardware
section: 8-the-keyboard-limitations-of-the-keyboard
functions: []
libraries: []
---

# 8 / The Keyboard / Limitations Of The Keyboard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga keyboard is a matrix of rows and columns with a key switch at
each intersection (see  [Appendix G](hardware/amiga-hardware-reference-manual-g-keyboard-interface.md)  for a diagram of the matrix). Because
of this, the keyboard is subject to a phenomenon called "phantom
keystrokes." While this is generally not a problem for typing, games may
require several keys be independently held down at once. By examining the
matrix, you can determine which keys may interfere with each other, and
which ones are always safe.

Phantom keystrokes occur when certain combinations of keys pressed are
pressed simultaneously.  For example, hold the "A" and "S" keys down
simultaneously.  Notice that "A" and "S" are transmitted.  While still
holding them down, press "Z".  On the original Amiga 1000 keyboard, both
the "Z" and a ghost "X" would be generated. Starting with the Amiga 500,
the controller was upgraded to notice simple phantom situations like the
one above; instead of generating a ghost, the controller will hold off
sending any character until the matrix has cleared (releasing "A" or "S"
would clear the matrix).  Some high-end Amiga keyboards may implement true
"N-key rollover," where any combination of keys can be detected
simultaneously.

All of the keyboards are designed so that phantoms will not happen during
normal typing, only when unusual key combinations like the one just
described are pressed.  Normally, the keyboard will appear to have "N-key
rollover," which means that you will run out of fingers before generating
a ghost character.

   About the qualifier keys.
   -------------------------
   Seven keys are not part of the matrix, and will never contribute to
   generating phantoms. These keys are:  Ctrl, the two Shift keys, the
   two Amiga keys, and the two Alt keys.

