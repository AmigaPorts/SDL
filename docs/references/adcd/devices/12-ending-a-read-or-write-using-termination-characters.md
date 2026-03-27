---
title: 12 / / Ending A Read Or Write Using Termination Characters
manual: devices
chapter: devices
section: 12-ending-a-read-or-write-using-termination-characters
functions: []
libraries: []
---

# 12 / / Ending A Read Or Write Using Termination Characters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Reads and writes from the serial device may terminate early if an error
occurs or if an end-of-file (EOF) is sensed.  For example, if a break is
detected on the line, any current read request will be returned with the
error SerErr_DetectedBreak.  The count of characters read to that point
will be in the io_Actual field of the request.

You can specify a set of possible end-of-file characters that the serial
device is to look for in the input stream  or output using the
SDCDMD_SETPARAMS command. These are contained in an io_TermArray that you
provide. io_TermArray is used only when the [SERF_EOFMODE](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md) flag is selected
(see the [Serial Flags](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md) section below).

If EOF mode is selected, each input data character read into or written
from the user's data block is compared against those in io_TermArray. If a
match is found, the [IOExtSer](devices/12-serial-device-device-interface.md) is terminated as complete, and the count of
characters transferred (including the termination character) is stored in
io_Actual.

To keep this search overhead as efficient as possible, the serial device
requires that the array of characters be in descending order. The array
has eight bytes and all must be valid (that is, do not pad with zeros
unless zero is a valid EOF character). Fill to the end of the array with
the lowest value termination character. When making an arbitrary choice of
EOF character(s), you will get the quickest response from the lowest
value(s) available.


```c
     [Terminate_Serial.c](devices/devices-dev-examples-terminate-serial-c.md) 
```
The read will terminate before the io_Length number of characters
is read if a "Q", "E", ETX, or EOT is detected in the serial input stream.

