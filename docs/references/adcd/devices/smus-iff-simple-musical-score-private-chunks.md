---
title: SMUS IFF Simple Musical Score / Private Chunks
manual: devices
chapter: devices
section: smus-iff-simple-musical-score-private-chunks
functions: []
libraries: []
---

# SMUS IFF Simple Musical Score / Private Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As in any IFF [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), there can be private chunks in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) that are
designed for one particular program to store its private information.  All
IFF reader programs skip over unrecognized chunks, so the presense of
private chunks can't hurt.

Instant Music stores some global score information in a chunk of ID "IRev"
and some other information in a chunk of ID "BIAS".

