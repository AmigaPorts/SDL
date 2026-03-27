---
title: TDDD.doc / Now, on with the details
manual: devices
chapter: devices
section: tddd-doc-now-on-with-the-details
functions: []
libraries: []
---

# TDDD.doc / Now, on with the details

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

First, there are several numerical fields appearing in the data,
describing object positions, rotation angles, scaling factors, etc. They
are stored as "32-bit fractional" numbers, such that the true number is
the 32-bit number divided by 65536.  So as an example, the number 3.14159
is stored as (hexadecimal) $0003243F.  This allows the data to be
independant of any particular floating point format. And it (actually) is
the internal format used in the "integer" version of Turbo Silver.
Numbers stored in this format are called as "FRACT"s below.

Second, there are several color (or RGB) fields in the data. They are
always stored as three UBYTEs representing the red, green and blue
components of the color.  Red is always first, followed by green, and then
blue.  For some of the data chunks, Turbo Silver reads the color field
into the 24 LSB's of a LONGword.  In such cases, the 3 RGB bytes are
preceded by a zero byte in the file.

The following "typedef"s are used below:


```c
    typedef LONG    FRACT;                /* 4 bytes */
    typedef UBYTE   COLOR[3];             /* 3 bytes */

    typedef struct vectors {
        FRACT X;          /* 4 bytes */
        FRACT Y;          /* 4 bytes */
        FRACT Z;          /* 4 bytes */
    } VECTOR;             /* 12 bytes total */

    typedef struct matrices {
        VECTOR I;         /* 12 bytes */
        VECTOR J;         /* 12 bytes */
        VECTOR K;         /* 12 bytes */
    } MATRIX;             /* 36 bytes total */

    typedef struct _tform {
        VECTOR r;         /* 12 bytes - position */
        VECTOR a;         /* 12 bytes - x axis */
        VECTOR b;         /* 12 bytes - y axis */
        VECTOR c;         /* 12 bytes - z axis */
        VECTOR s;         /* 12 bytes - size */
    } TFORM;              /*  60 bytes total */
```
The following structure is used in generating animated cells from a single
cell.  It can be attached to an object or to the camera.  It is also used
for Turbo Silver's "extrude along a path" feature.  (It is ignored and
forgotten by Imagine.)


```c
    typedef struct story {
        UBYTE  Path[18];  /* 18 bytes */
        VECTOR Translate; /* 12 bytes */
        VECTOR Rotate;    /* 12 bytes */
        VECTOR Scale;     /* 12 bytes */
        UWORD  info;      /*  2 bytes */
    } STORY;              /* 56 bytes total */
```
The Path[] name refers to a named object in the cell data. The path object
should be a sequence of points connected with edges.  The object moves
from the first point of the first edge, to the last point of the last
edge.  The edge ordering is important.  The path is interpolated so that
the object always moves an equal distance in each frame of the animation.
If there is no path the Path[] field should be set to zeros. The Translate
vector is not currently used. The Rotate "vector" specifies rotation
angles about the X, Y, and Z axes. The Scale vector specfies X,Y, and Z
scale factors. The "info" word is a bunch of bit flags:


```c
    ABS_TRA    0x0001    - translate in world coorinates (not used)
    ABS_ROT    0x0002    - rotation in world coorinates
    ABS_SCL    0x0004    - scaling in world coorinates
    LOC_TRA    0x0010    - translate in local coorinates (not used)
    LOC_ROT    0x0020    - rotation in local coorinates
    LOC_SCL    0x0040    - scaling in local coorinates
    X_ALIGN    0x0100    - (not used)
    Y_ALIGN    0x0200    - align Y axis to path's direction
    Z_ALIGN    0x0400    - (not used)
    FOLLOW_ME  0x1000    - children follow parent on path
```
 [DESC sub-sub-chunks](devices/details-desc-sub-sub-chunks.md) 
 [DESC notes](devices/details-desc-notes.md) 
 [INFO sub-chunks](devices/details-info-sub-chunks.md) 
 [EXTR sub-sub-chunks](devices/details-extr-sub-sub-chunks.md) 

