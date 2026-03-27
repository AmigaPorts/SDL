---
title: Standard Data and Property Chunks / Data Chunk CHRS
manual: devices
chapter: devices
section: standard-data-and-property-chunks-data-chunk-chrs
functions: []
libraries: []
---

# Standard Data and Property Chunks / Data Chunk CHRS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A CHRS chunk contains a sequence of 8-bit characters abiding by the
ISO/ANSI standards cited at the start of this document.  This includes the
character set and control sequences as described above and summarized in
[Appendix A](devices/ftxt-iff-formatted-appendix-a-character-code-table.md) and [Appendix C](devices/ftxt-iff-formatted-appendix-c-iso-ansi-control-sequences.md).

A [FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md) may contain any number of CHRS chunks.  Taken together, they
represent a single stream of textual information.  That is, the contents
of CHRS chunks are effectively concatenated except that (1) each control
sequence must be completely within a single CHRS chunk, and (2) any
formatting property chunks appearing between two CHRS chunks affects the
formatting of the latter chunk's text.  Any formatting settings set by
control sequences inside a CHRS carry over to the next CHRS in the same
[FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md).  All formatting properties stop at the end of the [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) since
IFF specifies that adjacent FORMs are independent of each other (although
not independent of any properties inherited from an enclosing [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) or
FORM).

