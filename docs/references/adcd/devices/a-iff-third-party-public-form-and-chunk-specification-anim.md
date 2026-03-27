---
title: A / IFF Third Party Public Form and Chunk Specification / ANIM.brush.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-anim
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / ANIM.brush.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ANIM brush format


                    Dpaint Anim Brush IFF Format

             From a description by the author of DPaint,
                      Dan Silva, Electronic Arts
The "Anim Brushes" of DPaint III are saved on disk in the IFF "ANIM"
format. Basically, an ANIM Form consists of an initial ILBM which is the
first frame of the animation, and any number of subsequent "ILBM"S (which
aren't really ILBM's) each of which contains an ANHD animation header
chunk and a DLTA chunk comprised of the encoded difference between a frame
and a previous one.

To use ANIM terminology (for a description of the ANIM format, see the IFF
Anim Spec, by Gary Bonham). Anim Brushes use a "type 5" encoding, which is
a vertical, byte-oriented delta encoding (based on Jim Kent's RIFF).  The
deltas have an interleave of 1, meaning deltas are computed between
adjacent frames, rather than between frames 2 apart, which is the usual
ANIM custom for the purpose of fast hardware page-flipping.  Also, the
deltas use Exclusive Or to allow reversable play.

However, to my knowledge, all the existing Anim players in the Amiga world
will only play type 5 "Anim"s which have an interleave of 0 (i.e. 2) and
which use a Store operation rather than Exclusive Or, so no existing
programs will read Anim Brushes anyway.  The job of modifying existing
Anim readers to read Anim Brushes should be simplified, however.

Here is an outline of the structure of the IFF Form output by DPaint III
as an "Anim Brush".  The IFF Reader should of course be flexible enough to
tolerate variation in what chunks actually appear in the initial ILBM.


                  FORM ANIM
                      . FORM ILBM         first frame
                      . . BMHD
                      . . CMAP
                      . . DPPS
                      . . GRAB
                      . . CRNG
                      . . CRNG
                      . . CRNG
                      . . CRNG
                      . . CRNG
                      . . CRNG
                      . . DPAN     my own little chunk.
                      . . CAMG
                      . . BODY

                      . FORM ILBM         frame 2
                      . . ANHD                animation header chunk
                      . . DLTA                delta mode data

                      . FORM ILBM         frame 3
                      . . ANHD                animation header chunk
                      . . DLTA                delta mode data

                      . FORM ILBM         frame 4
                      . . ANHD                animation header chunk
                      . . DLTA                delta mode data
       ...
                   . FORM ILBM         frame N
                      . . ANHD                animation header chunk
                      . . DLTA                delta mode data
 [DPAN Chunk Format](devices/anim-brush-doc-dpan-chunk-format.md) 
 [ANHD Chunk Format](devices/anim-brush-doc-anhd-chunk-format.md) 
 [RIFF](devices/anim-brush-doc-riff.md) 

