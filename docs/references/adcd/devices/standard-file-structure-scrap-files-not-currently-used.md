---
title: Standard File Structure / Scrap Files (not currently used)
manual: devices
chapter: devices
section: standard-file-structure-scrap-files-not-currently-used
functions: []
libraries: []
---

# Standard File Structure / Scrap Files (not currently used)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A "scrap file" is for maximum interconnectivity in getting data between
programs; the core of a clipboard function.  Scrap files may have type
"IFF " or filename extension ".IFF".

A scrap file is typically a [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  containing alternate representations of
the same basic information.  Include as many alternatives as you can
readily generate.  This redundancy improves interconnectivity in
situations where we can't make all programs read and write super-general
formats.  [Inside Macintosh chapter "Scrap Manager".]  E.g., a
graphically-annotated musical score might be supplemented by a stripped
down 4-voice melody and by a text (the lyrics).

The originating program should write the alternate representations in
order of "preference": most preferred (most comprehensive) type to least
preferred (least comprehensive) type.  A receiving program should either
use the first appearing type that it understands or search for its own
"preferred" type.

A scrap file should have at most one alternative of any type.  (A [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) of
same type objects is OK as one of the alternatives.)  But don't count on
this when reading; ignore extra sections of a type.  Then a program that
reads scrap files can read something out of single purpose files.

