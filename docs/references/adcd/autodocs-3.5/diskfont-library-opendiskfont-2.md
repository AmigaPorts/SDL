---
title: diskfont.library/OpenDiskFont
manual: autodocs-3.5
chapter: autodocs-3.5
section: diskfont-library-opendiskfont-2
functions: [AvailFonts, OpenDiskFont]
libraries: [diskfont.library]
---

# diskfont.library/OpenDiskFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       OpenDiskFont - load and get a pointer to a disk font.
   SYNOPSIS

```c
       font = OpenDiskFont(textAttr)
       D0                  A0
```
   FUNCTION

```c
       This function finds the font with the specified textAttr on
       disk, loads it into memory, and returns a pointer to the font
       that can be used in subsequent [SetFont](autodocs-3.5/graphics-library-setfont-2.md) and [CloseFont](autodocs-3.5/graphics-library-closefont-2.md) calls.
       It is important to match this call with a corresponding
       [CloseFont](autodocs-3.5/graphics-library-closefont-2.md) call for effective management of font memory.

       If the font is already in memory, the copy in memory is used.
       The disk copy is not reloaded.
```
   INPUTS

```c
       textAttr - a [TextAttr](autodocs-3.5/include-graphics-text-h.md) structure that describes the text font
               attributes desired.
```
   RESULTS

       D0 is zero if the desired font cannot be found.
   NOTES

```c
       As of V36, OpenDiskFont() will automatically attempt to
       construct a font for you if:

               You have requested a font size which does not exist
               as a designed font, and

               You have not set the DESIGNED bit in the ta_Flags
               field of the [TextAttr](autodocs-3.5/include-graphics-text-h.md), or [TTextAttr](autodocs-3.5/include-graphics-text-h.md) struct.

       Constructed fonts are created by scaling a designed font.
       A designed font is one which typically resides on disk,
       or in ROM (e.g., a font which has been designed by hand
       using a drawing tool).  Designed fonts generally look better
       than fonts constructed by the font scaler, but designed
       fonts also require disk space for each font size.

       Always set the DESIGNED bit if you do not want constructed fonts,
       or use [AvailFonts()](autodocs-3.5/diskfont-library-availfonts-2.md) to find out which font sizes already exist.

       As of V37 the diskfont.library supported built-in outline
       fonts.  Then in V38 the outline font engine was moved to
       a new library, "bullet.library."
```
   BUGS

```c
       This routine will not work well with font names whose file
       name components are longer than the maximum allowed
       (30 characters).
```

---

## See Also

- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
