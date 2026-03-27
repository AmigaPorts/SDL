---
title: ANIM.brush.doc / DPAN chunk Format
manual: devices
chapter: devices
section: anim-brush-doc-dpan-chunk-format
functions: []
libraries: []
---

# ANIM.brush.doc / DPAN chunk Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   typedef struct {

```c
    UWORD version;   /* current version=4 */
    UWORD nframes;   /* number of frames in the animation.*/
    ULONG flags;   /* Not used */
    } DPAnimChunk;
```
The version number was necessary during development. At present all I look
at is "nframes".

