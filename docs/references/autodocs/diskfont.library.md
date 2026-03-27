# diskfont.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 5

## Function Index

- **AvailFonts** — Inquire available memory & disk fonts.
- **DisposeFontContents** (V34) — Free the result from NewFontContents.
- **NewFontContents** (V34) — Create a FontContents image for a font.
- **NewScaledDiskFont** (V36) — Create a DiskFont scaled from another.
- **OpenDiskFont** — 

## Functions

### diskfont.library/AvailFonts

**Inquire available memory & disk fonts.**

**Synopsis:**
```c
int32 error = AvailFonts(STRPTR buffer, int32 bufBytes, uint32 flags);
```

**Description:**
AvailFonts fills a user supplied buffer with the structure,
described below, that contains information about all the
fonts available in memory and/or on disk.  Those fonts
available on disk need to be loaded into memory and opened
via OpenDiskFont, those already in memory are accessed via
OpenFont.  The TextAttr structure required by the open calls
is part of the information AvailFonts supplies.

When AvailFonts fails, it returns the number of extra bytes
it needed to complete the command.  Add this number to your
current buffer size, allocate a new buffer, and try again.

**Inputs:**
buffer - memory to be filled with struct AvailFontsHeader
	   followed by an array of AvailFonts elements, which
	   contains entries for the available fonts and their
	   names.

bufBytes - the number of bytes in the buffer

flags - AFF_MEMORY is set to search memory for fonts to fill
	   the structure, AFF_DISK is set to search the disk for
	   fonts to fill the structure.  AFF_SCALED is set to
	   not filter out memory fonts that are not designed.
	   AFF_BITMAP is set to filter out fonts that are not
	   stored in Amiga font format, i.e. to filter out
	   outline fonts.  Any combination may be specified.
	   AFF_TAGGED is set to fill the buffer with TAvailFonts
	   elements instead of AvailFonts elements.

	   In V50 AFF_OTAG was introduced, it has the reverse
	   effect of AFF_BITMAP and filters out all fonts that
	   do not have an .otag file, i.e. that are not accesible
	   via the bullet API.  When AFF_OTAG and AFF_SCALED are
	   both set, or AFF_TYPE is set, each font that is accesible
	   via the bullet API and that is freely scalable will be
	   shown with an additional entry with a (t)ta_YSize of 0,
	   if this entry is absent, the font is not scalable (i.e.
	   a non-Amiga bitmap font format that can be converted
	   but not scaled by the font engine).

	   In V50 AFF_CHARSET was introduced, if set, fonts in
	   all charsets are returned (dont forget to specify
	   AFF_TAGGED also to be able to distinguish fonts that
	   only differ in the charset), if not set, only fonts
	   in the current default charset are returned.
	   Fonts accesible via the bullet API will have the
	   special charset 1000 ("ISO-10646-UCS-2"), which means
	   something like "every charset you want" if AFF_CHARSET
	   was specified, if not, they will have the current
	   default charset.

	   In V50 AFF_TYPE was introduced, if set, the [t]af_Type
	   of disk fonts is not always AFF_DISK, but instead
	   AFF_DISK|AFF_BITMAP for bitmap fonts,
	   AFF_DISK|AFF_OTAG for .otag fonts,
	   AFF_DISK|AFF_OTAG|AFF_SCALED for scalable .otag fonts
	   (with a (t)ta_YSize of 0).

**Result:**
buffer - filled with struct AvailFontsHeader followed by the
	 [T]AvailFonts elements, There will be duplicate entries
	 for fonts found both in memory and on disk, differing
	 only by type.  The existance of a disk font in the
	 buffer indicates that it exists as an entry in a font
	 contents file -- the underlying font file has not been
	 checked for validity, thus an OpenDiskFont of it may
	 fail.

error -  if non-zero, this indicates the number of bytes needed
	 for AvailFonts in addition to those supplied.  Thus
	 structure elements were not returned because of
	 insufficient bufBytes.

**Example:**
```c
int32 afShortage, afSize;
struct AvailFontsHeader *afh;

...

afSize = 400;
do
{
    afh = (struct AvailFontsHeader *)
   IExec->AllocVecTags(afSize, TAG_END);
    if (afh)
    {
 afShortage = IDiskfont->AvailFonts(afh, afSize,
                                    AFF_MEMORY | AFF_DISK);
 if (afShortage)
 {
     IExec->FreeVec(afh);
     afSize += afShortage;
 }
    }
    else
    {
 fail("AllocMem of AvailFonts buffer afh failed\n");
 break;
    }
} while (afShortage);

// if (afh) non-zero here, then:
// 1. it points to a valid AvailFontsHeader
// 2. it must have FreeMem(afh, afSize) called for it after use
```

**Bugs:**
Prior to V50, this routine did not find the taglist stored
in tagged disk fonts when the AFF_TAGGED flag was specified,
except the font was already loaded to memory.  Fixed in V50.
Some V45 versions of this routine returned an invalid taglist
pointer for the Topaz/9 ROM font when AFF_TAGGED was specified.
Fixed in V45.7.  Prior to V50, versions with fontcache enabled
returned wrong results if AFF_BITMAP was set different at
cache creation and cache lookup time.

---

### diskfont.library/DisposeFontContents (V34)

**Free the result from NewFontContents.**

**Synopsis:**
```c
DisposeFontContents(fontContentsHeader)

VOID DisposeFontContents( struct FontContentsHeader * );
```

**Description:**
This function frees the array of FontContents entries
returned by NewFontContents.

**Inputs:**
fontContentsHeader - a struct FontContentsHeader pointer
              returned by NewFontContents.

   EXCEPTIONS
This command was first made available as of version 34.

A fontContentsHeader other than one acquired by a call
of NewFontContents will crash.

**See also:** NewFontContents()

---

### diskfont.library/NewFontContents (V34)

**Create a FontContents image for a font.**

**Synopsis:**
```c
fontContentsHeader = NewFontContents(fontsLock, fontName)

struct FontContentsHeader *NewFontContents( BPTR, STRPTR );
```

**Description:**
This function creates a new array of FontContents entries
that describe all the fonts associated with the fontName,
specifically, all those in the font directory whose name
is that of the font sans the ".font" suffix.

**Inputs:**
fontsLock - a DOS lock on the FONTS: directory (or other
     directory where the font contents file and associated
     font directory resides).
fontName -  the font name, with the ".font" suffix, which
     is also the name of the font contents file.

**Result:**
fontContentsHeader - a struct FontContentsHeader pointer
              that can be used for WriteFontContents()
              and must be freed with DisposeFontContents().

   EXCEPTIONS
This command was first made available as of version 34.

D0 is zero if the fontName is does not have a ".font" suffix,
if the fontName is too long, if a DOS error occurred, or if
memory could not be allocated for the fontContentsHeader.

**Notes:**
Prior to V50, the ".font" suffix had to be lowercase.

Prior to V50, this routine always returned zero for font
names longer than 30 chars. Since V50, this routine
accepts longer font names if the underlying file system
supports them without truncation. Since currently no
official way to find out the maximum file name length of
a file system exists and quiet truncation cant be accepted
("longname.fon" would not be accepted by AvailFonts()) this
is tested by creating a temporary test file with the same
name length as fontName in the directory specified by fontsLock
and comparing the FilePart returned by NameFromFH() with the
test file name. Even when the filesystem supports long names,
the V50 routine will not create a (T)FontContents structure
if the fontName without ".font" suffix plus "/" plus the file
name of the DiskFontHeader file plus the taglist of the
DiskFontHeader file wont fit in fc_FileName or tfc_FileName of
the (T)FontContents structure.  The V50 routine no longer
returns	zero if the font name is too long but there are
no valid DiskFontHeader files in the font directory, it returns
a FontContentsHeader structure with zero entries instead.

Since V50 the FixFonts utility supports long font names.
Previous versions did not call this routine for directorys
with names longer than 25 chars.

**Bugs:**
Prior to V50, this routine returned zero and lost memory if
there was a problem with any of the FontContents files.
Since V50 it returns a FontContentsHeader containing all
(T)FontContents structures that did not cause a problem.

**See also:** WriteFontContents() DisposeFontContents()

---

### diskfont.library/NewScaledDiskFont (V36)

**Create a DiskFont scaled from another.**

**Synopsis:**
```c
header = NewScaledDiskFont(srcFont, destTextAttr)

struct DiskFontHeader *NewScaledDiskFont( struct TextFont *,
	                                  struct TextAttr * );
```

**Inputs:**
srcFont -      the font from which the scaled font is to be
        constructed.
destTextAttr - the desired attributes for the new scaled
        font.  This may be a structure of type TextAttr or
        TTextAttr.

**Result:**
header - a pointer to a DiskFontHeader structure.  This is not
	 being managed by the diskfont.library, however.

**Notes:**
o   This function may use the blitter.
o   Fonts containing characters that render wholly outside
    the character advance cell are currently not scalable.
o   The font, and memory allocated for the scaled font can
    can be freed by calling StripFont() on the font,
    and then calling UnLoadSeg() on the segment created
    by this function.

    Both the TextFont structure, and segment pointer are contained
    within the DiskFontHeader struct.  The DiskFontHeader structure
    will also be freed as part of the UnLoadSeg() call.
    StripFont() is a new graphics.library call as of V36.

o   Prior to V46, this function stripped font names that did not
    fit in the dfh_Name field of the DiskFontHeader structure.
    Since V46, longer font names are stored in an extra segment
    that is added to the returned seglist and will be freed as
    part of the UnLoadSeg() call. In all versions, dfh_Name contains
    a stripped name, dfh_TF.tf_Message.mn_Node.ln_Name points to
    the stripped/unstripped name depending on the version,
    and dfh_DF.ln_Name should be ignored.

---

### diskfont.library/OpenDiskFont

**Synopsis:**
```c
struct TextFont *font = OpenDiskFont(struct TextAttr *textAttr);
```

**Description:**
This function finds the best matching font for the specified
textAttr on disk, loads it into memory, and returns a pointer
to the font that can be used in subsequent SetFont and CloseFont
calls. It is important to match this call with a corresponding
CloseFont call for effective management of font memory.

If the font is already in memory, the copy in memory is used.
The disk copy is not reloaded. When memory is running low the
font cache in memory is automatically purged via
diskfont.library's expunge vector.

The struct (T)TextAttr tta_Name/ta_Name field specifies the name
of the font. Note that the name of the font can either be the
font name alone (<font name>.font) or it can be prepended with a
full path. Without a path to the font, if the font is not
already cached, OpenDiskFont() will look in the FONTS: directory
for the font file. If there is a path, OpenDiskFont() will look
in that directory for the font files, allowing the user to put
fonts in any directory (although this is discouraged). OpenFont()
and OpenDiskFont() try to find a font that best matches your
(T)TextAttr description.

**Inputs:**
textAttr - TextAttr or TTextAttr structure that describes the
    text font attributes desired.

**Result:**
Returns NULL if no matching font could be found.

**Notes:**
As of V36, OpenDiskFont() will automatically attempt to
construct a font for you if:

  - You have requested a font size which does not exist
    as a designed font, and

  - You have not set the DESIGNED bit in the ta_Flags
    field of the (T)TextAttr struct.

Constructed fonts are created by scaling a designed font.
A designed font is one which typically resides on disk,
or in ROM (e.g., a font which has been designed by hand
using a drawing tool). Designed fonts generally look better
than fonts constructed by the font scaler, but designed
fonts also require disk space for each font size.

Always set the DESIGNED bit if you do not want constructed fonts,
or use AvailFonts() to find out which font sizes already exist.

Since OpenDiskFont() and OpenFont() always try to open the font
that best matches your request, it is possible that (with the
DESIGNED bit set) the YSize of the opened font is not the same
as the requested YSize. It's also possible that you requested a
plain font but get a bold font etc. Maybe a future
diskfont.library will open Helvetica if you requested Arial or
vice versa, so keep in mind that you get the best match but
maybe a perfect match did not exist.

If the user requested a bold|italic|underlined font and the
opened font is not bold|italic|underlined, the system will add
the missing styles algorithmically if you don't forget to call
graphics.library/SetSoftStyle() with something like this:
if (myfont = OpenDiskFont(&mytextattr))
{
	SetFont(myrastport, myfont);
	SetSoftStyle(myrastport,
	             mytextattr.ta_Style ^ myfont->tf_Style,
	             FSF_BOLD | FSF_UNDERLINED | FSF_ITALIC);
	// Calling Text() here
	CloseFont(myfont);
}

If you have to construct a (T)TextAttr structure from an
opened TextFont that ensures fast opening of (hopefully)
the same font when used with OpenDiskFont() or OpenFont()
again, use ObtainTTextAttr() which does not forget to copy the
bold|italic|underlined|extended|fixed|colorfont|etc bits
and also makes a copy of the fonts taglist.

Simply re-using a TextAttr without style, flags and tags
information (the "fontname/size" scheme) can in worst case
lead to the fact that diskfont.library may e.g. try to construct
a non-bold font from a bold font via bullet API which may fail
each time if the font engine does not support this.

As of V37 the diskfont.library supported built-in outline
fonts. Then in V38 the outline font engine was moved to
a new library, "bullet.library."

As of V50 diskfont.library supports different charsets.
If you specify the charset with the TA_CharSet tag in the taglist
of the TTextAttr structure it will look for a tagged bitmap
font with the wanted charset or create a font with the
wanted charset via the font engine if the font has an .otag file
and a charset mapping table exists in L:CharSets. If not
specified, the current default charset is assumed. Note that
a charset match is heavily preferred when searching for a font
match.

It is not necessary to call ExtendFont() for the returned
font, OpenDiskFont() only returns successfully extended fonts.

As of V50 fontname_MIME-NAME.font is interpreted as
fontname.font with TA_CharSet tag. This allows expert users
to use fonts in different charsets than system default charset
with old applications.

The feature only works in combination with graphics.library V47+
to make sure OpenFont() opens the same font as OpenDiskFont().

Since V50 its possible that an AATextFont instead of a
TextFont is returned.

Since V50 the special tag TA_Rebuild (for bullet API font
installers only) is supported, see <graphics/text.h>.

Since V50.48 the special font charset X-Custom is supported
which can be used to mark fonts with symbols, musical notes
etc. to match any requested charset and to not be remapped to
current system default charset during load.

Prior to V51.6, this routine did not check if it was called
from a process, which should not happen (The RKRM says only
a process may call it) and could result in crashes or error
messages from dos.library. Since V51.7 this routine may be
safely called from a task.

**Bugs:**
Prior to V50, this routine will not work well with font names
whose file name components are longer than the maximum allowed
(30 characters). Since V50, this routine accepts font names of
any length without crashing. The maximum possible font name
length now is limited by MAXFONTPATH (256) which is the maximum
for the name including path components.

**See also:** graphics.library/OpenFont(), graphics.library/CloseFont(),
graphics.library/SetSoftStyle(), OpenOutlineFont(),
graphics/text.h

---
