---
title: Data Sections / Group FORM
manual: devices
chapter: devices
section: data-sections-group-form
functions: []
libraries: []
---

# Data Sections / Group FORM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A data section is a [chunk](devices/primitive-data-types-chunks.md) with ckID "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" and this arrangement:


```c
    FORM       ::= "FORM" #{ FormType (LocalChunk | FORM | LIST | CAT)* }
    FormType   ::= ID
    LocalChunk ::= Property | Chunk
```
The ID "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" is a syntactic keyword like "struct" in C.  Think of a
"struct [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)" containing a field "[CMAP](devices/standard-properties-cmap.md)".  If you see "FORM" you will know
to expect a FORM type ID (the structure name, "[ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)" in this example) and
a particular contents arrangement or "syntax" (local [chunk](devices/primitive-data-types-chunks.md), FORMs, [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s,
and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ).  A "FORM ILBM", in particular, might contain a local chunk
"CMAP", an "ILBM.CMAP" (to use a qualified name).

So the [chunk](devices/primitive-data-types-chunks.md) ID "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" indicates a data section.  It implies that the
[chunk](devices/primitive-data-types-chunks.md) contains an ID and some number of nested chunks.  In reading a FORM,
like any other chunk, programs must respect its ckSize as a virtual
end-of-file for reading its contents, even if they're truncated.

The [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type is a restricted ID that may not contain lower case letters
or punctuation characters.  (Cf. Type IDs.  Cf. Single Purpose Files.)

The type-specific information in a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) is composed of its "local [chunk](devices/primitive-data-types-chunks.md)s":
data properties and other [chunk](devices/primitive-data-types-chunks.md)s.  Each FORM type is a local name space
for local [chunk](devices/primitive-data-types-chunks.md) IDs.  So "[CMAP](devices/standard-properties-cmap.md)" local [chunk](devices/primitive-data-types-chunks.md)s in other FORM types may be
unrelated to "ILBM.CMA"".  More than that, each FORM type defines semantic
scope.  If you know what a FORM [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) is, you will know what an ILBM.[CMAP](devices/standard-properties-cmap.md)
is.

Local [chunk](devices/primitive-data-types-chunks.md)s defined when the [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type is designed (and therefore known
to all clients of this type) are called "standard" while specialized ones
added later are "nonstandard".

Among the local [chunk](devices/primitive-data-types-chunks.md)s, property chunks give settings for various details
like text font while the other chunks supply the essential information.
This distinction is not clear cut.  A property setting can be cancelled by
a later setting of the same property.  E.g., in the sequence:

	prop1 = x  (Data A)  prop1 = z  prop1 = y (Data B)

prop1 is = x for Data A, and y for Data B.  The setting prop1 = z has no
effect.

For clarity, the universally reserved [chunk](devices/primitive-data-types-chunks.md) IDs "[LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)", "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)", "[PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)",
"[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ", "    ", "LIS1" through "LIS9", "FOR1" through "FOR9", and "CAT1"
through "CAT9" may not be FORM type IDs.

Part 5, below, talks about grouping [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s into [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s.  They let
you group a bunch of FORMs but don't impose any particular meaning or
constraints on the grouping.  Read on.

