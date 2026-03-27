---
title: Standard Properties / DEST
manual: devices
chapter: devices
section: standard-properties-dest
functions: []
libraries: []
---

# Standard Properties / DEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional property "DEST" is a way to say how to scatter zero or more
source bitplanes into a deeper destination image.  Some readers may ignore
DEST.

The contents of a DEST chunk is DestMerge structure:


typedef struct {
  UBYTE depth;      /* # bitplanes in the original source               */
  UBYTE pad1;       /* unused; for consistency put 0 here               */
  UWORD planePick;  /* how to scatter source bitplanes into destination */
  UWORD planeOnOff; /* default bitplane data for planePick              */
  UWORD planeMask;  /* selects which bitplanes to store into            */
  } DestMerge;


The low order depth number of bits in planePick, planeOnOff, and planeMask
correspond one-to-one with destination bitplanes.  Bit 0 with bitplane 0,
etc. (Any higher order bits should be ignored.)  "1" bits in planePick
mean "put the next source bitplane into this bitplane", so the number of
"1" bits should equal nPlanes.  "0" bits mean "put the corresponding bit
from planeOnOff into this bitplane".  Bits in planeMask gate writing to
the destination bitplane: "1" bits mean "write to this bitplane" while "0"
bits mean "leave this bitplane alone".  The normal case (with no DEST
property) is equivalent to planePick = planeMask = 2^(nPlanes) - 1.

Remember that color numbers are formed by pixels in the destination bitmap
(depth planes deep) not in the source bitmap (nPlanes planes deep).

