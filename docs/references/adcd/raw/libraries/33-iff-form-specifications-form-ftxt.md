# 33 / IFF FORM Specifications / FORM FTXT


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
the length ([StoredProperty.sp_Size](../Includes_and_Autodocs_2._guide/node010B.html#line90)) of the chunk.

Be aware that if you [CollectionChunk()](../Libraries_Manual_guide/node0437.html) the CHRS chunks of an FTXT, the
list accumulated by IFFParse will be in reverse order from the chunk order
in the file.  See the [ClipFTXT.c](../Libraries_Manual_guide/node059F.html) example at the end of this chapter for a
simple example of reading (and optionally writing) FTXT to and from the
clipboard.  See also the "[Clipboard Device](../Devices_Manual_guide/node0065.html)" and "[Console Device](../Devices_Manual_guide/node0080.html)" chapters
of the Amiga ROM Kernel Reference Manual: Devices for more information on
Release 2 console clip and paste.

