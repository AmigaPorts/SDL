# Step 1


All system supported fonts on the Amiga have a font contents file.
From this file, an application can determine a font's type, so the
application knows how to utilize the font.  The font contents file is
a FontContentsHeader structure (defined in <diskfont/diskfont.h>).
The first field of that structure (fch_FileID) contains an ID
identifying the font's type.  If that type is OTAG_ID (0x0F03), the
font is an outline and it should have a corresponding otag file.  The
otag file should be in the same directory as the font contents file.

