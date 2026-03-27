---
title: Composite FORMs / PICS
manual: devices
chapter: devices
section: composite-forms-pics
functions: []
libraries: []
---

# Composite FORMs / PICS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The data [chunk](devices/primitive-data-types-chunks.md) inside a "PICS" data section has ID "PICT" and holds a
QuickDraw picture.  Issue: Allow more than one PICT in a PICS?  See Inside
Macintosh chapter "QuickDraw" for details on PICTs and how to create and
display them on the Macintosh computer.

The only standard property for PICS is "XY", an optional property that
indicates the position of the PICT relative to "the big picture".  The
contents of an XY is a QuickDraw Point.

Note: PICT may be limited to Macintosh use, in which case there"ll be
another format for structured graphics in other environments.

