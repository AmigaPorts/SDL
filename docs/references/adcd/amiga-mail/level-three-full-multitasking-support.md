---
title: Level Three-Full Multitasking Support
manual: amiga-mail
chapter: amiga-mail
section: level-three-full-multitasking-support
functions: []
libraries: []
---

# Level Three-Full Multitasking Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A title conforming to Level Three support allows users to multitask
freely (given sufficient memory).  These titles must include support
for points 1) through 7) above.  Furthermore, Level Three titles may
not re-assign any directory assigns that the system requires (i.e.
fonts:, sys:, s:, etc.).

If a title in this category needs to access a particular font on the
CD-ROM, it should not re-assign fonts: to cd0:fonts.  Instead, it
should refer to the full path name of the CD via the volume name of the
disc (for example, MyDisk:Data/MyFile).  You should not refer to the
device name (cd0:) since this may vary, either with more than one
CD-ROM peripheral attached, or a different device name for a
third-party drive.

If your title does refer to a volume name, be careful when
pre-mastering the title.  Make sure you enter the correct volume name
when running the ISO utility.  If another company does the
pre-mastering for you, make sure they use the correct volume name.

