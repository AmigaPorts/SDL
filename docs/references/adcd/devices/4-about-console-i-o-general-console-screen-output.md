---
title: 4 / About Console I/O / General Console Screen Output
manual: devices
chapter: devices
section: 4-about-console-i-o-general-console-screen-output
functions: []
libraries: []
---

# 4 / About Console I/O / General Console Screen Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Console character screen output (as compared to console command sequence
transmission) outputs all standard printable characters (character values
hex 20 through 7E and A0 through FF) normally.

Many control characters such as BACKSPACE (0x8) and RETURN (0x13) are
translated into their exact ANSI equivalent actions. The LINEFEED
character (0xA) is a bit different in that it can be translated into a
RETURN/LINEFEED action. The net effect is that the cursor moves to the
first column of the next line whenever an <LF> is displayed. This option
is set via the mode control sequences discussed under
[Control Sequences for Window Output.](devices/4-writing-to-the-console-device-control-sequences-for.md)

