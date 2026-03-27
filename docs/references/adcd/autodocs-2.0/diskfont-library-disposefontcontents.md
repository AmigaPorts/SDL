---
title: diskfont.library/DisposeFontContents
manual: autodocs-2.0
chapter: autodocs-2.0
section: diskfont-library-disposefontcontents
functions: []
libraries: []
---

# diskfont.library/DisposeFontContents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
     DisposeFontContents -- Free the result from [NewFontContents](autodocs-2.0/diskfont-library-newfontcontents.md). (V34)
```
SYNOPSIS

```c
     DisposeFontContents(fontContentsHeader)
                         A1

     VOID DisposeFontContents( struct [FontContentsHeader](autodocs-2.0/includes-libraries-diskfont-h.md) * );
```
FUNCTION

```c
     This function frees the array of [FontContents](autodocs-2.0/includes-libraries-diskfont-h.md) entries
     returned by [NewFontContents](autodocs-2.0/diskfont-library-newfontcontents.md).
```
INPUTS

```c
     fontContentsHeader - a struct [FontContentsHeader](autodocs-2.0/includes-libraries-diskfont-h.md) pointer
         returned by [NewFontContents](autodocs-2.0/diskfont-library-newfontcontents.md).
```
EXCEPTIONS

```c
     This command was first made available as of version 34.

     A fontContentsHeader other than one acquired by a call
     [NewFontContents](autodocs-2.0/diskfont-library-newfontcontents.md) will crash.
```
SEE ALSO

```c
     [NewFontContents](autodocs-2.0/diskfont-library-newfontcontents.md) to get structure freed here.
```
