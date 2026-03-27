---
title: Primitive Data Types / Type IDs
manual: devices
chapter: devices
section: primitive-data-types-type-ids
functions: []
libraries: []
---

# Primitive Data Types / Type IDs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A "type ID", "property name", "FORM type", or any other IFF identifier is
a 32-bit value: the concatenation of four ASCII characters in the range
" " (SP, hex 20) through '~' (hex 7E).  Spaces (hex 20) should not precede
printing characters; trailing spaces are OK.  Control characters are
forbidden.

	typedef CHAR ID[4];

IDs are compared using a simple 32-bit case-dependent equality test.  [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)
type IDs are restricted.  Since they may be stored in filename extensions
lower case letters and punctuation marks are forbidden.  Trailing spaces
are OK.

Carefully choose those four characters when you pick a new ID.  Make them
mnemonic so programmers can look at an interchange format file and figure
out what kind of data it contains.  The name space makes it possible for
developers scattered around the globe to generate ID values with minimal
collisions so long as they choose specific names like "MUS4" instead of
general ones like "TYPE" and "FILE".

Commodore Applications and Technical Support has undertaken the task of
maintaining the registry of FORM type IDs and format descriptions.  See
the [IFF Registry](devices/a-iff-form-and-chunk-registry.md) document for more information.

Sometimes it's necessary to make data format changes that aren't backward
compatible.  As much as we work for compatibility, unintended interactions
can develop.  Since IDs are used to denote data formats in IFF, new IDs
are chosen to denote revised formats.  Since programs won't read chunks
whose IDs they don't recognize (see [Chunks](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), below), the new IDs keep old
programs from stumbling over new data.  The conventional way to chose a
"revision" ID is to increment the last character if it's a digit or else
change the last character to a digit.  E.g., first and second revisions of
the ID "XY" would be "XY1" and "XY2".  Revisions of "[CMAP](devices/standard-properties-cmap.md)" would be "CMA1"
and "CMA2".

