---
title: 23 / List Functions / List Macros for Assembly Language Programmers
manual: libraries
chapter: libraries
section: 23-list-functions-list-macros-for-assembly-language
functions: []
libraries: []
---

# 23 / List Functions / List Macros for Assembly Language Programmers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Assembly language programmers may want to optimize their code by using
assembly code list macros.  Because these macros actually embed the
specified list operation into the code, they result in slightly faster
operations.  The file <exec/[lists.i](autodocs-2.0/includes-exec-lists-i.md)> contains the recommended set of
macros. For example, the following instructions implement the [REMOVE](autodocs-2.0/includes-exec-lists-i.md) macro:


```c
    MOVE.L  LN_SUCC(A1),A0       ; get successor
    MOVE.L  LN_PRED(A1),A1       ; get predecessor
    MOVE.L  A0,LN_SUCC(A1)       ; fix up predecessor's succ pointer
    MOVE.L  A1,LN_PRED(A0)       ; fix up successor's pred pointer
```
