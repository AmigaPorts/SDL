---
title: Primitive Data Types / Data Properties (advanced topic)
manual: devices
chapter: devices
section: primitive-data-types-data-properties-advanced-topic
functions: []
libraries: []
---

# Primitive Data Types / Data Properties (advanced topic)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Data properties specify attributes for following (non-property) [chunk](devices/primitive-data-types-chunks.md).  A
data property essentially says "identifier = value", for example "XY =
(10, 200)", telling something about following chunks.  Properties may only
appear inside data sections ("[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" chunks, cf. Data Sections) and
property sections ("[PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)" chunks, cf. Group PROP).

The form of a data property is a type of [Chunk](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md).  The ckID is a property
name as well as a property type.  The ckSize should be small since data
properties are intended to be accumulated in RAM when reading a file.
(256 bytes is a reasonable upper bound.)  Syntactically:

	Property	::= Chunk

When designing a data object, use properties to describe context
information like the size of an image, even if they don't vary in your
program.  Other programs will need this information.

Think of property settings as assignments to variables in a programming
language.  Multiple assignments are redundant and local assignments
temporarily override global assignments.  The order of assignments doesn't
matter as long as they precede the affected [chunk](devices/primitive-data-types-chunks.md).  (Cf. [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s, CATs, and
Shared Properties.)

Each object type ([FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type) is a local name space for property IDs.
Think of a "[CMAP](devices/standard-properties-cmap.md)" property in a "FORM [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)" as the qualified ID
"ILBM.[CMAP](devices/standard-properties-cmap.md)".  A "CMAP" inside some other type of [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) may not have the
same meaning.  Property IDs specified when an object type is designed (and
therefore known to all clients) are called "standard" while specialized
ones added later are "nonstandard".

