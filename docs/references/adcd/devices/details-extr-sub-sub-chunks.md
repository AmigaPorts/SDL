---
title: Details /  EXTR sub-sub-chunks
manual: devices
chapter: devices
section: details-extr-sub-sub-chunks
functions: []
libraries: []
---

# Details /  EXTR sub-sub-chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

MTRX - size 60


```c
    VECTOR  Translate;      ; translation vector
    VECTOR  Scale;          ; X,Y and Z scaling factors
    MATRIX  Rotate;         ; rotation matrix

    The translation vector is i world coordinates.
    The scaling factors are with respect to local axes.
    The rotation matrix is with respect to the world axes,
    and it should be a "unit matrix".
    The rotation is such that a rotated axis's X,Y, and Z
    components are the dot products of the MATRIX's I,J,
    and K vectors with the un-rotated axis vector.
```
LOAD - size 80


```c
    BYTE    Filename[80];   ; the name of the external file

    This chunk contains the name of an external object file.
    The external file should be a FORM TDDD file.  It may contain
    an any number of objects possibly grouped into heirarchy(ies).
```
Both of these chunks are required.

