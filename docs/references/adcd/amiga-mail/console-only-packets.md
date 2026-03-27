---
title: Console Only Packets
manual: amiga-mail
chapter: amiga-mail
section: console-only-packets
functions: [SetMode, WaitForChar]
libraries: [dos.library]
---

# Console Only Packets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The remaining packets are only used for console handlers and do not
need to be implemented by a file system.

ACTION_SCREEN_MODE       994    SetMode() in 2.0
ARG1:   LONG    Mode (zero or one)

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)
RES2:   CODE    Failure code if RES1 is DOSFALSE

Switch the console to and from RAW mode.  An ARG1 of one indicates
the unprocessed, raw mode while an ARG1 of zero indicates the
processed, ``cooked'' mode.


ACTION_CHANGE_SIGNAL     995    <sendpkt only>
ARG1:   LONG    The fh_Arg1 of the console file handle
ARG2:   APTR    MsgPort of the process to signal
ARG3:   LONG    Reserved, currently this must be zero

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)
RES2:   CODE    Failure code if RES1 is DOSFALSE

This packet redirects what process the console handler signals when
the user hits  Control-C, Control-D, Control-E, or Control-F.
Normally the process that opened the file handle receives the break
signal.


ACTION_WAIT_CHAR         20     WaitForChar()
ARG1:   ULONG   Timeout in microseconds

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)
RES2:   CODE    Failure code if RES1 is DOSFALSE

Performs a timed read of a character.  The WaitForChar() function
uses this packet.


ACTION_DISK_INFO         25      <sendpkt only>
ARG1:   BPTR    Pointer to an InfoData structure to fill in

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)

The ACTION_DISK_INFO packet has a special meaning for console style
handlers.  When presented with this packet, a console style handler
should return a pointer to the window associated with the open handle
in the InfoData structure's id_VolumeNode field (the InfoData
structure is defined in <dos/dos.h>).  Note that some consoles can
return a NULL Window pointer (for example, an AUTO CON: or a AUX:
console).  The Amiga's standard console handler, CON:, also returns a
pointer to the console handler's IO request in the id_InUse field.
In some cases, the IO request's io_Unit field (which normally point
to a ConUnit structure) will be NULL.  See also the ACTION_DISK_INFO
packet in the ``Volume Manipulation/Information'' section.

---

## See Also

- [SetMode — dos.library](../autodocs/dos.library.md#setmode)
- [WaitForChar — dos.library](../autodocs/dos.library.md#waitforchar)
