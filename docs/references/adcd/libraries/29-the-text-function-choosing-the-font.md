---
title: 29 / The Text Function / Choosing the Font
manual: libraries
chapter: libraries
section: 29-the-text-function-choosing-the-font
functions: [OpenDiskFont, OpenFont, SetFont]
libraries: [diskfont.library, graphics.library]
---

# 29 / The Text Function / Choosing the Font

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The graphics.library function [SetFont()](autodocs-2.0/graphics-library-setfont.md) changes the rastport's current
font:


```c
    void SetFont( struct RastPort *myrp, struct TextFont *mytf );
```
The parameter mytf is a pointer to an open, valid [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure.  The
system uses the TextFont structure to keep track of fonts (The TextFont
structure is discussed in detail later in this chapter).  The [OpenFont()](autodocs-2.0/graphics-library-openfont.md)
(from graphics.library) and [OpenDiskFont()](autodocs-2.0/diskfont-library-opendiskfont.md) (from diskfont.library)
functions both return a pointer to a valid TextFont structure.  The
OpenFont() function will only open fonts that have already been loaded and
are currently in the system list.  Normally applications use the
OpenDiskFont() call instead of OpenFont() because OpenDiskFont() can load
and open fonts from disk as well as open those that are already in the
system list.

Here are prototypes for these functions:


```c
    struct TextFont *OpenDiskFont( struct TextAttr *mytextAttr );
    struct TextFont *OpenFont( struct TextAttr *mytextAttr );
```
The mytextAttr argument  points to a TextAttr structure that describes the
requested font.  The TextAttr structure (from <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>) looks
like this:


```c
    struct TextAttr {
        STRPTR  ta_Name;            /* name of the font */
        UWORD   ta_YSize;           /* height of the font */
        UBYTE   ta_Style;           /* intrinsic font style */
        UBYTE   ta_Flags;           /* font preferences and flags */
    };
```
where ta_Name is a string naming the font to open, ta_YSize is the point
size of the font (normally in pixels), ta_Style is a bitfield describing
the font style, and ta_Flags is a bitfield that further describes
characteristics of the font.  Note that the name of the font can either be
the font name alone (<font name>.font) or it can be prepended with a full
path.  Without a path to the font, if the font is not already loaded into
the system list, [OpenDiskFont()](autodocs-2.0/diskfont-library-opendiskfont.md) will look in the FONTS: directory for the
font file.  If there is a path, OpenDiskFont() will look in that directory
for the font files, allowing the user to put fonts in any directory
(although this is discouraged).  [OpenFont()](autodocs-2.0/graphics-library-openfont.md) and OpenDiskFont() try to find
a font that matches your TextAttr description.  An important thing to
remember about OpenDiskFont() is that only a process can call it (as
opposed to a task).  This is primarily because the function has to use
dos.library to scan disks for font files.

The font styles for ta_Style (from <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>) are:




    FSF_UNDERLINED      The font is underlined
    FSF_BOLD            The font is bolded
    FSF_ITALIC          The font is italicized
    FSF_EXTENDED        The font is extra wide
The flags for ta_Flags (from <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>) are:




```c
    FPF_ROMFONT       This font is built into the ROM (currently, only
                      Topaz-8 and Topaz-9 are ROM fonts).
    FPF_DISKFONT      This font was loaded from disk (with
                      diskfont.library)
    FPF_REVPATH       This font is designed to be printed from from right
                      to left (Hebrew is written from right to left)
    FPF_TALLDOT       This font was designed for a Hires screen (640x200
                      NTSC, non-interlaced)
    FPF_WIDEDOT       This font was designed for a Lores Interlaced screen
                      (320x400 NTSC)
    FPF_PROPORTIONAL  The character widths of this font are not constant
    FPF_DESIGNED      This font size was explicitly designed at this size
                      rather than constructed.  If you do not set this bit
                      in your TextAttr, then the system may generate a
                      font for you by scaling an existing ROM or disk font
                      (under V36 and above).
```
For example to open an 11 point bold, italic Topaz font, the code would
look something like this:


```c
     [pseudotext.c](libraries/lib-examples-pseudotext-c.md) 
```
The example above uses the graphics.library's [SetFont()](autodocs-2.0/graphics-library-setfont.md) function to change
the rastport's current font.  Notice that this example restores the
rastport's original font (myrp->Font) before exiting.  This isn't normally
necessary unless some other process assumes the rastport's font (or other
drawing attributes) will not change.  Intuition does not rely on the
window's RPort.Font field for rendering or closing the default window
font, so applications can change that font without having to restore it.

Prior to Release 2, some applications assumed that any window they opened
would always use Topaz-8 without bothering to explicitly set it.  Since
Topaz-8 was the normal default font before Release 2, this was usually not
a problem.  However, under Release 2 and later versions of the OS, the
user can easily change the default system fonts with the Font Preferences
editor.  Hence, applications that make assumptions about the size of the
default font look terrible under Release 2 (and in some cases are
unusable).  Program designers should not make assumptions about the system
font, and wherever possible, honor the user font preferences.  See the
"[Preferences](libraries/13-preferences.md)" chapter of this manual for more information on how to find
user preferences.

---

## See Also

- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
