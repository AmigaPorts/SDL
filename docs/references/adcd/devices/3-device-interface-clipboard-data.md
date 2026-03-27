---
title: 3 / Device Interface / Clipboard Data
manual: devices
chapter: devices
section: 3-device-interface-clipboard-data
functions: []
libraries: []
---

# 3 / Device Interface / Clipboard Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Data on the clipboard resides in one of three places. When an application
posts a cut, the data resides in the private memory space of that
application. When an application writes to the clipboard, either of its
own volition or in response to a message from the clipboard requesting
that it satisfy a post, the data is copied to the clipboard which is
either memory or a special disk file. When the clipboard is not open, the
data resides in the special disk file located in the directory specified
by the CLIPS: logical AmigaDOS assign.

Data on the clipboard is self-identifying. It must be a correct IFF
(Interchange File Format) file; the rest of this section refers to IFF
concepts. See the [Appendix A](devices/appendix-a-iff-interchange-file-format.md) in this manual for a complete description of
IFF. If the top-level chunk is of type CAT with an identifier of CLIP,
that indicates that the contained chunks are different representations of
the same data, in decreasing order of preference on the part of the
producer of the clip. Any other data is as defined elsewhere (probably a
single representation of the cut data produced by an application).

The [IFFParse.Library](libraries/33-iffparse-library.md) also contains functions which simplify reading and
writing of IFF data to the clipboard device.  See the "[IFFParse Library](libraries/33-iffparse-library.md)"
chapter of the Amiga ROM Kernel Reference Manual: Libraries for more
information.

A clipboard tool, which is an application that allows a Workbench user to
view a clip, should understand the text (FTXT) and graphics (ILBM) form
types. Applications using the clipboard to export data should include at
least one of these types in a CAT CLIP so that their data can be
represented on the clipboard in some form for user feedback.

You should not, in any way, rely on the specifics of how files in CLIPS:
are handled or named.  The only proper way to read or write clipboard data
is via the clipboard device.

   Play Nice!
   ----------
   Keep in mind that while your task is reading from or writing to a
   clipboard unit, other tasks cannot.  Therefore, it is important to be
   fast.  If possible, make a copy of the clipboard data in RAM instead
   of processing it while the read or write is in progress.

