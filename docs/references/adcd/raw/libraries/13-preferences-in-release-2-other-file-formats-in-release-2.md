# 13 / Preferences in Release 2 / Other File Formats in Release 2


Not every Preferences file is stored as an [IFF](../Libraries_Manual_guide/node0428.html) file of type PREF.  The
[palette.ilbm](../Libraries_Manual_guide/node0228.html#line11) and [pointer.ilbm](../Libraries_Manual_guide/node0228.html#line11) files contain a regular ILBM FORM to store
their imagery.  The [win.pat](../Libraries_Manual_guide/node0228.html#line11) and [wb.pat](../Libraries_Manual_guide/node0228.html#line11) files use a raw format with 16
bytes reserved, followed by a WORD giving the total size of the pattern, a
WORD giving the bitplane count, and byte arrays (currently 32 bytes) for
each bitplane.  The format of the wbconfig.prefs file is private.

