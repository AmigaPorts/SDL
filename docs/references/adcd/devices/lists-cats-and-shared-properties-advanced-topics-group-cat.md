---
title: LISTs, CATs, and Shared Properties (Advanced topics) / Group CAT
manual: devices
chapter: devices
section: lists-cats-and-shared-properties-advanced-topics-group-cat
functions: []
libraries: []
---

# LISTs, CATs, and Shared Properties (Advanced topics) / Group CAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  is just an untyped group of data objects.

Structurally, a [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  is a [chunk](devices/primitive-data-types-chunks.md) with [chunk](devices/primitive-data-types-chunks.md) ID "CAT " containing a "contents
type" ID followed by the nested objects.  The ckSize of each contained
chunk is essentially a relative pointer to the next one.

	CAT		::= "CAT " #{ ContentsType (FORM | LIST | CAT)* }
	ContentsType    ::= ID	- a hint or an "abstract data type" ID

In reading a [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) , like any other [chunk](devices/primitive-data-types-chunks.md), programs must respect its ckSize
as a virtual end-of-file for reading the nested objects even if they're
malformed or truncated.

The "contents type" following the [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) 's ckSize indicates what kind of
[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s are inside.  So a CAT of [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)s would store "ILBM" there.  It's just
a hint. It may be used to store an "abstract data type".  A CAT could just
have blank contents ID ("    ") if it contains more than one kind of [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md).

[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  defines only the format of the group.  The group's meaning is open to
interpretation.  This is like a list in LISP: the structure of cells is
predefined but the meaning of the contents as, say, an association list
depends on use.  If you need a group with an enforced meaning (an
"abstract datatype" or Smalltalk "subclass"), some consistency
constraints, or additional data [chunk](devices/primitive-data-types-chunks.md)s, use a composite [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) instead (Cf.
Composite FORMs).

Since a [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  just means a concatenation of objects, CATs are rarely nested.
Programs should really merge CATs rather than nest them.

