---
title: ILBM.CLUT.doc / Design Notes
manual: devices
chapter: devices
section: ilbm-clut-doc-design-notes
functions: []
libraries: []
---

# ILBM.CLUT.doc / Design Notes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

I have deliberately kept this chunk simple (KISS) to facilitate
implementation.  In particular, no provision is made for expansion to
16-bit or 32-bit tables.  My reasoning is that a 16-bit table can have 64K
entries, and thus would benefit from data compression.  My suggestion
would be to propose another chunk or FORM type better suited for large
tables rather than small ones like CLUT.

