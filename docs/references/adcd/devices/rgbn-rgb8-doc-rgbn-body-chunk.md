---
title: RGBN-RGB8.doc / RGBN BODY Chunk
manual: devices
chapter: devices
section: rgbn-rgb8-doc-rgbn-body-chunk
functions: []
libraries: []
---

# RGBN-RGB8.doc / RGBN BODY Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each RGB value, a WORD (16-bits) is written: with the 12 RGB bits in
the MSB (most significant bit) positions; the "genlock" bit next; and then
a 3 bit repeat count. If the repeat count is greater than 7, the 3-bit
count is zero, and a BYTE repeat count follows.  If the repeat count is
greater than 255, the BYTE count is zero, and a WORD repeat count follows.
Repeat counts greater than 65536 are not supported.

