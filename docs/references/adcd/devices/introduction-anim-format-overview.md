---
title: Introduction / ANIM Format Overview
manual: devices
chapter: devices
section: introduction-anim-format-overview
functions: []
libraries: []
---

# Introduction / ANIM Format Overview

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The general philosophy of ANIMs is to present the initial frame as a
normal, run-length-encoded, IFF picture.  Subsequent frames are then
described by listing only their differences from a previous frame.
Normally, the "previous" frame is two frames back as that is the frame
remaining in the hidden screen buffer when double-buffering is used.  To
better understand this, suppose one has two screens, called A and B, and
the ability to instantly switch the display from one to the other.  The
normal playback mode is to load the initial frame into A and duplicate it
into B.  Then frame A is displayed on the screen.  Then the differences
for frame 2 are used to alter screen B and it is displayed.  Then the
differences for frame 3 are used to alter screen A and it is displayed,
and so on.  Note that frame 2 is stored as differences from frame 1, but
all other frames are stored as differences from two frames back.

ANIM is an IFF FORM and its basic format is as follows (this assumes the
reader has a basic understanding of IFF format files):


                FORM ANIM
                . FORM ILBM         first frame
                . . BMHD                normal type IFF data
                . . ANHD                optional animation header
                                        chunk for timing of 1st frame.
                . . CMAP
                . . BODY
                . FORM ILBM         frame 2
                . . ANHD                animation header chunk
                . . DLTA                delta mode data
                . FORM ILBM         frame 3
                . . ANHD
                . . DLTA
                     ...
The initial FORM ILBM can contain all the normal ILBM chunks, such as
CRNG, etc.  The BODY will normally be a standard run-length-encoded data
chunk (but may be any other legal compression mode as indicated by the
BMHD).  If desired, an ANHD chunk can appear here to provide timing data
for the first frame.  If it is here, the operation field should be =0.

The subsequent FORMs ILBM contain an ANHD, instead of a BMHD, which
duplicates some of BMHD and has additional parameters pertaining to the
animation frame.  The DLTA chunk contains the data for the delta
compression modes.  If the older XOR compression mode is used, then a BODY
chunk will be here.  In addition, other chunks may be placed in each of
these as deemed necessary (and as code is placed in player programs to
utilize them).  A good example would be CMAP chunks to alter the color
palette.  A basic assumption in ANIMs is that the size of the bitmap, and
the display mode (e.g. HAM) will not change through the animation.  Take
care when playing an ANIM that if a CMAP occurs with a frame, then the
change must be applied to both buffers.

Note that the DLTA chunks are not interleaved bitmap representations, thus
the use of the ILBM form is inappropriate for these frames. However, this
inconsistency was not noted until there were a number of commercial
products either released or close to release which generated/played this
format.  Therefore, this is probably an inconsistency which will have to
stay with us.

