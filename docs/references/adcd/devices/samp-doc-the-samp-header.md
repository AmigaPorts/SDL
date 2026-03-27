---
title: SAMP.doc / The SAMP Header
manual: devices
chapter: devices
section: samp-doc-the-samp-header
functions: []
libraries: []
---

# SAMP.doc / The SAMP Header

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

At the very beginning of a sound file is the "SAMP" header. This is used
to determine if the disk file is indeed a SAMP sound file. It's attributes
are as follows:


```c
    #define ID_SAMP MakeID('S','A','M','P')
```
In assembly, this looks like:


```c
    CNOP 0,2  ;word-align
```
SAMP         dc.b  'SAMP'
sizeOfChunks dc.l  [sizes of all subsequent chunks summed]

