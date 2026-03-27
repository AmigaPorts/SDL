---
title: 4 / Device Interface / Console Device Units
manual: devices
chapter: devices
section: 4-device-interface-console-device-units
functions: []
libraries: []
---

# 4 / Device Interface / Console Device Units

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The console device provides four units, three that require a console
window and one that does not. The unit type is specified when you open the
device. See the [Opening the Console Device](devices/4-device-interface-opening-the-console-device.md) section below for more
details.

The CONU_STANDARD unit (0) is generally used with a SMART_REFRESH window.
This unit has the least amount of overhead (e.g., memory usage and
rendering time), and is highly compatible with all versions of the
operating system.

As of V36, a character mapped console device was introduced.  There are
two variations of character mapped console units.  Both must be used with
SIMPLE_REFRESH windows and both have the ability to automatically redraw a
console window when resized or revealed.

A character mapped console can be opened which allows the user to
drag-select text with the mouse and COPY the highlighted area.  The copied
text can then be PASTEd into other console windows or other windows which
support reading data from the clipboard device.

Character mapped console units have more overhead than standard consoles
(e.g., rendering times and memory usage).

The CONU_LIBRARY unit (-1) does not require a console window.  It is
designed to be primarily used with the console device functions and also
with the console device commands that do not require a console window.

The Amiga uses the ECMA-94 Latin1 International 8-bit character set. See
[Appendix A](devices/ftxt-iff-formatted-appendix-a-character-code-table.md) (page 397) for a table of character codes.

