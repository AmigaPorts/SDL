---
title: 28 / / Specifying Animation Components / Sequencing AnimComps
manual: libraries
chapter: libraries
section: 28-specifying-animation-components-sequencing-animcomps
functions: []
libraries: []
---

# 28 / / Specifying Animation Components / Sequencing AnimComps

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To specify the sequencing of [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) images, the pointers called [PrevSeq](autodocs-2.0/includes-graphics-gels-h.md)
and [NextSeq](autodocs-2.0/includes-graphics-gels-h.md) are used to build a doubly-linked list.  The sequence can be
made circular (and usually is) by linking the first and last AnimComps in
the sequence: the NextSeq of the last AnimComp must point back to the
first AnimComp, and the PrevSeq of the first AnimComp must point to the
last AnimComp.  If the list is a loop, then the system will continue to
cycle through the list until it is stopped.  If the list is not a loop,
then the program must act to restart the sequence after the last item is
displayed.  The AnimCRoutine field of the last AnimComp can be used to do
this.

