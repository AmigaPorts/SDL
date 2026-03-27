---
title: A / IFF Third Party Public Form and Chunk Specification / PRSP.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-prsp
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / PRSP.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

DPaint IV perspective move form (EA)

Submitted by Lee Taran

/* --------------------------------------------------------------------
   IFF Information:
```c
       PRSP ::= "FORM" # {"PSRP" MOVE }
       MOVE ::= "MOVE" # { MoveState  }
```
 * -------------------------------------------------------------------- */


```c
    typedef struct {
       BYTE reserved;        /* initialize to 0 */
       BYTE moveDir;         /* 0 = from point  1 = to point  */
       BYTE recordDir;       /* 0 = FORWARD,    1 = STILL, 2 = BACKWARD */
       BYTE rotationType;    /* 0 = SCREEN_RELATIVE, 1 = BRUSH_RELATIVE */
       BYTE translationType; /* 0 = SCREEN_RELATIVE, 1 = BRUSH_RELATIVE */
       BYTE cyclic;          /* 0 = NO, 1 = YES */
       SHORT distance[3];    /* x,y,z distance displacement */
       SHORT angle[3];       /* x,y,z rotation angles */
       SHORT nframes;        /* number of frames to move */
       SHORT easeout;        /* number of frames to ease out */
       SHORT easein;         /* number of frames to ease in */
       } MoveState;
```
