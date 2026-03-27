---
title: LISTs, CATs, and Shared Properties (Advanced topics) / Group LIST
manual: devices
chapter: devices
section: lists-cats-and-shared-properties-advanced-topics-group-list
functions: []
libraries: []
---

# LISTs, CATs, and Shared Properties (Advanced topics) / Group LIST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) defines a group very much like [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  but it also gives a scope for
[PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s (see below).  And unlike CATs, LISTs should not be merged without
understanding their contents.

Structurally, a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) is a [chunk](devices/primitive-data-types-chunks.md) with ckID "LIST" containing a "contents
type" ID, optional shared properties, and the nested contents ([FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s,
LISTs, and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s), in that order.  The ckSize of each contained [chunk](devices/primitive-data-types-chunks.md) is a
relative pointer to the next one.  A LIST is not an arbitrary linked
list - the cells are simply concatenated.


```c
    LIST         ::= "LIST" #{ ContentsType PROP* (FORM | LIST | CAT)* }
    ContentsType ::= ID
```
