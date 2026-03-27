---
title: A / IFF Third Party Public Form and Chunk Specification / ANBM.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-anbm
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / ANBM.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Animated bitmap form (Framer, Deluxe Video)

TITLE:  Form ANBM (animated bitmap form used by Framer, Deluxe Video)

(note from the author)

The format was designed for simplicity at a time when the IFF standard was
very new and strange to us all.  It was not designed to be a general
purpose animation format.  It was intended to be a private format for use
by DVideo, with the hope that a more powerful format would emerge as the
Amiga became more popular.

I hope you will publish this format (and we did!) so that other formats
will not inadvertantly conflict with it.

PURPOSE:  To define simple animated bitmaps for use in DeluxeVideo.

In Deluxe Video objects appear and move in the foreground with a picture
in the background.  Objects are "small" bitmaps usually saved as brushes
from DeluxePaint and pictures are large full screen bitmaps saved as files
from DeluxePaint.

Two new chunk headers are defined: ANBM and FSQN.

An animated bitmap (ANBM) is a series of bitmaps of the same size and
depth.  Each bitmap in the series is called a frame and is labeled by a
character, 'a b c ...' in the order they appear in the file.

The frame sequence chunk (FSQN) specifies the playback sequence of the
individual bitmaps to achieve animation. FSQN_CYCLE and FSQN_TOFRO specify
two algorithmic sequences.  If neither of these bits is set, an arbitrary
sequence can be used instead.



    ANBM         - identifies this file as an animated bitmap
    .FSQN        - playback sequence information
    .LIST ILBM   - LIST allows following ILBMs to share properties
    ..PROP ILBM  - properties follow
    ...BMHD      - bitmap header defines common size and depth
    ...CMAP      - colormap defines common colors
    ..FORM ILBM  - first frame follows
    ..BODY       - the first frame
       .         - FORM ILBM and BODY for each remaining frame
       .
       .
 [ANBM](devices/anbm-doc-anbm.md) 
 [FSQN](devices/anbm-doc-fsqn.md) 
 [Supporting Software](devices/anbm-doc-supporting-software.md) 

