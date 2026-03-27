---
title: lib_examples/sample_rev.i
manual: libraries
chapter: libraries
section: lib-examples-sample-rev-i
functions: []
libraries: []
---

# lib_examples/sample_rev.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* sample_rev.i version file (generated with the ``bumprev'' command)

VERSION         EQU     37
REVISION        EQU     1
DATE    MACRO
                dc.b    '2.3.92'
        ENDM
VERS    MACRO
                dc.b    'sample 37.1'
        ENDM
VSTRING MACRO
```c
                dc.b    'sample 37.1 (2.3.92)',13,10,0
        ENDM
```
VERSTAG MACRO

```c
                dc.b    0,'$VER: sample 37.1 (2.3.92)',0
        ENDM
```
