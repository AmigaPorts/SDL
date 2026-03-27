---
title: 4 Console Device / Copy and Paste Support
manual: devices
chapter: devices
section: 4-console-device-copy-and-paste-support
functions: []
libraries: []
---

# 4 Console Device / Copy and Paste Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As noted above, opening the console device with a unit of CONU_SNIPMAP
allows the user to drag-select text with the mouse and copy the selection
with Right-Amiga-C.

Internally, the snip is copied to a private buffer managed by the console
device where it can be copied to other console device windows by pressing
Right-Amiga-V.

However, your application should assume that the user is running the
Conclip" utility which is part of the standard Workbench 2.0
environment.  Conclip copies snips from the console device to the
clipboard device where they can be used by other applications which
support reading from the clipboard.

When Conclip is running and the user presses Right-Amiga-V, the console
device puts an escape sequence in your read stream - <CSI>0 v  (Hex 9B 30
20 76) - which tells you that the user wants to paste text from the
clipboard.

Upon receipt of this sequence, your application should read the contents
of the clipboard device, make a copy of any text found there and then
release the clipboard so that it can be used by other applications.  See
the "[Clipboard Device](devices/3-device-interface-reading-from-the-clipboard-device.md)" chapter for more information on reading data from
it.

You paste what you read from the clipboard by using successive writes to
the console.  In order to avoid problems with excessively long data in the
clipboard, you should limit the size of writes to something reasonable.
(We define reasonable as no more than 1K per write with the ideal amount
being 256 bytes.)  You should also continue to monitor the console read
stream for additional use input, paster requests and, possibly, RAW INPUT
EVENTS while you are doing this.

You should not open a character mapped console unit with COPY capability
if you are unable to support PASTE from the clipboard device.  The user
will reasonably expect to be able to PASTE into windows from which a COPY
can be done.

Keep in mind that users do make mistakes, so an UNDO mechanism for
aborting a PASTE is highly desirable - particularly if the user has just
accidentally pasted text into an application like a terminal program which
is sending data at a slow rate.

   Use CON:, You'll Be Glad You Did.
   ---------------------------------
   It is highly recommended that you consider using the console-handler
   (CON:) if you want a console window with COPY and PASTE
   capablilities. CON: provides you with free PASTE support and is
   considerably easier to open and use than using the console device
   directly.

