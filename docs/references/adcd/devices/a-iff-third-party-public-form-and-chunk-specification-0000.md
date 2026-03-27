---
title: A / IFF Third Party Public Form and Chunk Specification / 0000.CSET.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-0000
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / 0000.CSET.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Chunk for specifying character set

Registered by Martin Taillefer.

A chunk for use in any FORM, to specify character set used for text in
FORM.

   struct CSet {

```c
           LONG    CodeSet;       /* 0=ECMA Latin 1 (std Amiga charset) */
           LONG    Reserved[7];   /* CBM will define additional values  */
           }
```
