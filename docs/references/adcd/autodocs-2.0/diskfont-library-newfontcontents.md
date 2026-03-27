---
title: diskfont.library/NewFontContents
manual: autodocs-2.0
chapter: autodocs-2.0
section: diskfont-library-newfontcontents
functions: []
libraries: []
---

# diskfont.library/NewFontContents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
     NewFontContents -- Create a [FontContents](autodocs-2.0/includes-libraries-diskfont-h.md) image for a font. (V34)
```
SYNOPSIS

```c
     fontContentsHeader = NewFontContents(fontsLock,fontName)
    D0                                   A0        A1

     struct [FontContentsHeader](autodocs-2.0/includes-libraries-diskfont-h.md) *NewFontContents( BPTR, char * );
```
FUNCTION

```c
     This function creates a new array of [FontContents](autodocs-2.0/includes-libraries-diskfont-h.md) entries
     that describe all the fonts associated with the fontName,
     specifically, all those in the font directory whose name
     is that of the font sans the ".font" suffix.
```
INPUTS

```c
     fontsLock - a DOS lock on the FONTS: directory (or other
         directory where the font contents file and associated
         font directory resides).
     fontName - the font name, with the ".font" suffix, which
         is also the name of the font contents file.
```
RESULT

```c
     fontContentsHeader - a struct [FontContentsHeader](autodocs-2.0/includes-libraries-diskfont-h.md) pointer.
```
EXCEPTIONS

     This command was first made available as of version 34.

     D0 is zero if the fontName is does not have a ".font" suffix,
     if the fontName is too long, if a DOS error occurred, or if
     memory could not be allocated for the fontContentsHeader.
SEE ALSO

```c
     [DisposeFontContents](autodocs-2.0/diskfont-library-disposefontcontents.md) to free the structure acquired here.
```
