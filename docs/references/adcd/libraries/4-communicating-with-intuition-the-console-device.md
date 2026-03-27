---
title: 4 / Communicating with Intuition / The Console Device
manual: libraries
chapter: libraries
section: 4-communicating-with-intuition-the-console-device
functions: []
libraries: []
---

# 4 / Communicating with Intuition / The Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An alternative to the message system used by the IDCMP is the console
device.  The console device gives your application input data translated
to ASCII characters or ANSI escape sequences.  Raw (untranslated) input is
also available through the console device as ANSI escape sequences.

The console device also provides for convenient output of control codes
and non-proportional (mono-spaced) text to the window.  Output is
character based, and includes capabilities such as automatic line wrapping
and scrolling.  The console device automatically formats and interprets
the output stream.  Output is kept within the window boundaries
automatically so the application need not worry about overwriting the
border (no [GimmeZeroZero](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) window required).

The console device must be opened by the application before it is used.
See the chapter entitled "[Intuition Input and Output Methods](libraries/9-intuition-input-and-output-methods-console-device-i-o.md)" or refer to
the "[Console Device](devices/4-console-device.md)" chapter of the Amiga ROM Kernel Reference Manual:
Devices for more information about using the console device with your
Intuition windows.

