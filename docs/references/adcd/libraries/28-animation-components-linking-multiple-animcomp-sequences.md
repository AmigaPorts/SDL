---
title: 28 / / Animation Components / Linking Multiple AnimComp Sequences
manual: libraries
chapter: libraries
section: 28-animation-components-linking-multiple-animcomp-sequences
functions: []
libraries: []
---

# 28 / / Animation Components / Linking Multiple AnimComp Sequences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When an [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) is built from multiple [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) sequences, the sequences
are linked together by the the [PrevComp](autodocs-2.0/includes-graphics-gels-h.md) and [NextComp](autodocs-2.0/includes-graphics-gels-h.md) fields of the
AnimComps.  These pointers must be initialized only in the initial
AnimComp of each sequence.  The other components that are not initially
active should have their PrevComp and NextComp pointers set to NULL.


```c
    Do Not Use Empty Fields.
    ------------------------
    You cannot store data in the empty [PrevComp](autodocs-2.0/includes-graphics-gels-h.md) and [NextComp](autodocs-2.0/includes-graphics-gels-h.md) fields.  As
    the system cycles through the [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s, the NextComp and PrevComp
    fields are set to NULL when an old AnimComps is replaced by a new
    AnimComp.  The new AnimComp is then linked in to the list of
    sequences in place of the old one.
```
