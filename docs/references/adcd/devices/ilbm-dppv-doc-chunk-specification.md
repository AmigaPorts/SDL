---
title: ILBM.DPPV.doc / Chunk Specification
manual: devices
chapter: devices
section: ilbm-dppv-doc-chunk-specification
functions: []
libraries: []
---

# ILBM.DPPV.doc / Chunk Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* The chunk identifier DPPV */

#define ID_DPPV    MakeID('D','P','P','V')

typedef LONG LongFrac;
typedef struct ( LongFrac x,y,z; )  LFPoint;
typedef LongFrac  APoint[3];

typedef union {
   LFPoint l;
   APoint  a;
   } UPoint;

/* values taken by variable rotType */
#define ROT_EULER  0
#define ROT_INCR   1

/* Disk record describing Perspective state */

typedef struct {
   WORD     rotType;           /* rotation type */
   WORD     iA, iB, iC;        /* rotation angles (in degrees) */
   LongFrac Depth;             /* perspective depth */
   WORD     uCenter, vCenter;  /* coords of center perspective,
                                * relative to backing bitmap,
                                * in Virtual coords
                                */
   WORD     fixCoord;          /* which coordinate is fixed */
   WORD     angleStep;         /* large angle stepping amount */
   UPoint   grid;              /* gridding spacing in X,Y,Z */
   UPoint   gridReset;         /* where the grid goes on Reset */
   UPoint   gridBrCenter;      /* Brush center when grid was last on,
                                * as reference point
                                */
   UPoint   permBrCenter;      /* Brush center the last time the mouse
                                * button was clicked, a rotation performed,
                                * or motion along "fixed" axis
                                */
   LongFrac rot[3][3];         /* rotation matrix */
   } PerspState;

