---
title: RGBN-RGB8.doc / RGB8 Body Chunk
manual: devices
chapter: devices
section: rgbn-rgb8-doc-rgb8-body-chunk
functions: []
libraries: []
---

# RGBN-RGB8.doc / RGB8 Body Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each RGB value, a LONG-word (32 bits) is written: with the 24 RGB bits
in the MSB positions; the "genlock" bit next, and then a 7 bit repeat
count.

In a previous version of this document, there appeared the following line:

"If the repeat count is greater than 127, the same rules apply as in the
RGBN BODY."

But Impulse has never written more than a 7 bit repeat count, and when
Imagine and Light24 were written, they didn't support reading anything but
7 bit counts.

