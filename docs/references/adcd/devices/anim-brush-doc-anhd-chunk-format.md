---
title: ANIM.brush.doc / ANHD chunk format
manual: devices
chapter: devices
section: anim-brush-doc-anhd-chunk-format
functions: []
libraries: []
---

# ANIM.brush.doc / ANHD chunk format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

typedef struct {
 UBYTE operation;  /* =0  set directly
```c
       =1  XOR ILBM mode,
       =2 Long Delta mode,
       =3 Short Delta mode
       =4 Generalize short/long Delta mode,
       =5 Byte Vertical Delta (riff)
       =74 (Eric Grahams compression mode)
```
   */
 UBYTE mask;      /* XOR ILBM only: plane mask where data is*/
 UWORD w,h;
 WORD x,y;
 ULONG abstime;
 ULONG reltime;
 UBYTE interleave; /* 0 defaults to 2 */
 UBYTE pad0;   /* not used */
 ULONG bits;   /* meaning of bits:
```c
    bit# =0                 =1
    0    short data         long data
    1    store              XOR
    2    separate info      one info for
         for each plane     for all planes
    3    not RLC            RLC (run length encoded)
    4    horizontal         vertical
    5    short info offsets long info offsets
```
   */
 UBYTE pad[16];
 } AnimHdr;


for Anim Brushes, set:

 animHdr.operation = 5;  /* RIFF encoding */
 animHdr.interleave = 1;
 animHdr.w = curAnimBr.bmob.pict.box.w;
 animHdr.h = curAnimBr.bmob.pict.box.h;
 animHdr.reltime = 1;
 animHdr.abstime = 0;
 animHdr.bits = 4; /* indicating XOR */

- everything else is set to 0.

NOTE: the "bits" field was actually intended ( by the original creator of
the ANIM format, Gary Bonham of SPARTA, Inc.) for use with only with
compression method 4. I am using bit 2 of the bits field to indicate the
Exclusive OR operation in the context of method 5, which seems like a
reasonable generalization.

For an Anim Brush with 10 frames, there will be an initial frame followed
by 10 Delta's (i.e ILBMS containing ANHD and DLTA chunks).  Applying the
first Delta to the initial frame generates the second frame, applying the
second Delta to the second frame generates the third frame, etc.  Applying
the last Delta thus brings back the first frame.

The DLTA chunk begins with 16 LONG plane offets, of which DPaint only uses
the first 6 (at most).  These plane offsets are either the offset (in
bytes) from the beginning of the DLTA chunk to the data for the
corresponding plane, or Zero, if there was no change in that plane.  Thus
the first plane offset is either 0 or 64.

