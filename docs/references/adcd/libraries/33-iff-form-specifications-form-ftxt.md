---
title: 33 / IFF FORM Specifications / FORM FTXT
manual: libraries
chapter: libraries
section: 33-iff-form-specifications-form-ftxt
functions: [CollectionChunk]
libraries: [iffparse.library]
---

# 33 / IFF FORM Specifications / FORM FTXT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FTXT (Formatted TeXT) form is the standard format for sharing text on
the Amiga.  The Release 2 console device clip and paste functions, in
conjunction with the startup-sequence conclip command, pass clipped
console text through the clipboard as FTXT.

By supporting reading and writing of clipboard device FTXT, your
application will allow users to cut and paste text between your
application, other applications, and Amiga Shell windows.

The FTXT form is very simple.  Generally, for clip and paste operations,
you will only be concerned with the CHRS (character string) chunks of an
FTXT.  There may be one or more CHRS chunks, each of which contains a
non-NULL-terminated string of ASCII characters whose length is equal to
the length ([StoredProperty.sp_Size](autodocs-2.0/includes-libraries-iffparse-h.md)) of the chunk.

Be aware that if you [CollectionChunk()](libraries/33-management-functions-collectionchunk-and-findcollection.md) the CHRS chunks of an FTXT, the
list accumulated by IFFParse will be in reverse order from the chunk order
in the file.  See the [ClipFTXT.c](libraries/lib-examples-clipftxt-c.md) example at the end of this chapter for a
simple example of reading (and optionally writing) FTXT to and from the
clipboard.  See also the "[Clipboard Device](devices/3-clipboard-device.md)" and "[Console Device](devices/4-console-device.md)" chapters
of the Amiga ROM Kernel Reference Manual: Devices for more information on
Release 2 console clip and paste.

---

## See Also

- [CollectionChunk — iffparse.library](../autodocs/iffparse.library.md#collectionchunk)
