---
title: Introduction / Playing ANIMs
manual: devices
chapter: devices
section: introduction-playing-anims
functions: []
libraries: []
---

# Introduction / Playing ANIMs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Playback of ANIMs will usually require two buffers, as mentioned above,
and double-buffering between them.  The frame data from the ANIM file is
used to modify the hidden frame to the next frame to be shown.  When using
the XOR mode, the usual run- length-decoding routine can be easily
modified to do the exclusive-or operation required.  Note that runs of
zero bytes, which will be very common, can be ignored, as an exclusive or
of any byte value to a byte of zero will not alter the original byte value.

The general procedure, for all compression techniques, is to first decode
the initial ILBM picture into the hidden buffer and double- buffer it into
view.  Then this picture is copied to the other (now hidden) buffer.  At
this point each frame is displayed with the same procedure.  The next
frame is formed in the hidden buffer by applying the DLTA data (or the XOR
data from the BODY chunk in the case of the first XOR method) and the new
frame is double-buffered into view.  This process continues to the end of
the file.

A master colormap should be kept for the entire ANIM which would be
initially set from the CMAP chunk in the initial ILBM.  This colormap
should be used for each frame.  If a CMAP chunk appears in one of the
frames, then this master colormap is updated and the new colormap applies
to all frames until the occurrance of another CMAP chunk.

Looping ANIMs may be constructed by simply making the last two frames
identical to the first two.  Since the first two frames are special cases
(the first being a normal ILBM and the second being a delta from the
first) one can continually loop the anim by repeating from frame three.
In this case the delta for creating frame three will modify the next to
the last frame which is in the hidden buffer (which is identical to the
first frame), and the delta for creating frame four will modify the last
frame which is identical to the second frame.

Multi-File ANIMs are also supported so long as the first two frames of a
subsequent file are identical to the last two frames of the preceeding
file.  Upon reading subsequent files, the ILBMs for the first two frames
are simply ignored, and the remaining frames are simply appended to the
preceeding frames.  This permits splitting ANIMs across multiple floppies
and also permits playing each section independently and/or editing it
independent of the rest of the ANIM.

Timing of ANIM playback is easily achieved using the vertical blank
interrupt of the Amiga.  There is an example of setting up such a timer in
the ROM Kernel Manual.  Be sure to remember the timer value when a frame
is flipped up, so the next frame can be flipped up relative to that time.
This will make the playback independent of how long it takes to decompress
a frame (so long as there is enough time between frames to accomplish this
decompression).

