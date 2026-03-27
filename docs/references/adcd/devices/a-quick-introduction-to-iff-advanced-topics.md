---
title: A Quick Introduction to IFF/ Advanced Topics
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-advanced-topics
functions: []
libraries: []
---

# A Quick Introduction to IFF/ Advanced Topics

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CAT, LIST, and PROP

Sometimes you want to put several "files" into one, such as a picture
library. This is what CAT is for.  It "concatenates" FORM and LIST chunks.


          +--------------------+
          |                    |
          |   "CAT "           |  concatenation
          |                    |
          +--------------------+
          |   48160            |  48160 data bytes
          +--------------------+
          |                    |
          |   "ILBM"           |  This concatenation contains FORMs ILBM
          |                    |
          |  +--------------+  |
          |  |  "FORM"      |  |  A FORM ILBM
          |  |--------------|  |
          |  |   24070      |  |
          |  |--------------|  |
          |  |  "ILBM"      |  |
          |  |--------------|  |
          |  |  ....        |  |
          |  +--------------+  |
          |                    |
          |  +--------------+  |
          |  |  "FORM"      |  |  Another FORM ILBM
          |  |--------------|  |
          |  |   24070      |  |
          |  |--------------|  |
          |  |  "ILBM"      |  |
          |  |--------------|  |
          |  |  ....        |  |
          |  +--------------+  |
          |                    |
          +--------------------+
This example CAT holds two ILBMs. It can be shown outline-style:

  CAT ILBM
  ..FORM ILBM   \
  ....BMHD      | a complete FORM ILBM picture
  ....CMAP      |
  ....BODY      /
  ..FORM ILBM
  ....BMHD
  ....CMAP
  ....BODY

Sometimes you want to share the same color map across many pictures. LIST
and PROP do this:

  LIST ILBM
  ..PROP ILBM   default properties for FORMs ILBM
  ....CMAP      an ILBM CMAP chunk (there could be a BMHD chunk here, too)
  ..FORM ILBM
  ....BMHD      (there could be a CMAP here to override the default)
  ....BODY
  ..FORM ILBM
  ....BMHD      (there could be a CMAP here to override the default)
	....BODY

A LIST holds PROPs and [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s (and occasionally LISTs and CATs).  A PROP
[ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) contains default data (in the above example, just one [CMAP](devices/standard-properties-cmap.md) chunk) for
all FORMs ILBM in the LIST.  Any FORM may override the PROP-defined
default with its own [CMAP](devices/standard-properties-cmap.md).  All PROPs must appear at the beginning of a
LIST.  Each FORM type standardizes (among other things) which of its
chunks are "property chunks" (may appear in PROPs) and which are "data
chunks" (may not appear in PROPs).

