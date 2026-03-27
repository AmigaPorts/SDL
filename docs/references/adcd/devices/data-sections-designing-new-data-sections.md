---
title: Data Sections / Designing New Data Sections
manual: devices
chapter: devices
section: data-sections-designing-new-data-sections
functions: []
libraries: []
---

# Data Sections / Designing New Data Sections

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Supplemental documents will define additional object types.  A supplement
needs to specify the object's purpose, its [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type ID, the IDs and
formats of standard local [chunk](devices/primitive-data-types-chunks.md)s, and rules for generating and
interpreting the data. It's a good idea to supply typedefs and an example
source program that accesses the new object.  See "[ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)" IFF Interleaved
Bitmap for such an example.

Anyone can pick a new [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type ID but should reserve it with Commodore
Applications and Technical Support ([CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ) at their earliest convenience.
While decentralized  format definitions and extensions are possible in
IFF, our preference is to get design consensus by committee, implement a
program to read and write it, perhaps tune the format before it becomes
locked in stone, and then publish the format with example code.  Some
organization should remain in charge of answering questions and
coordinating extensions to the format.

If it becomes necessary to incompatibly revise the design of some data
section, its [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type ID will serve as a version number (Cf. Type IDs).
E.g., a revised "VDEO" data section could be called "VDE1".  But try to
get by with compatible revisions within the existing FORM type.

In a new [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type, the rules for primitive data types and word-alignment
(Cf. Primitive Data Types) may be overridden for the contents of its local
[chunk](devices/primitive-data-types-chunks.md)s - but not for the chunk structure itself - if your documentation
spells out the deviations.  If machine-specific type variants are needed,
e.g., to store vast numbers of integers in reverse bit order, then outline
the conversion algorithm and indicate the variant inside each file,
perhaps via different FORM types.  Needless to say, variations should be
minimized.

In designing a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type, encapsulate all the data that other programs
will need to interpret your files.  E.g., a raster graphics image should
specify the image size even if your program always uses 320 x 200 pixels x
3 bitplanes. Receiving programs are then empowered to append or clip the
image rectangle, to add or drop bitplanes, etc.  This enables a lot more
compatibility.

Separate the central data (like musical notes) from more specialized
information (like note beams) so simpler programs can extract the central
parts during read-in.  Leave room for expansion so other programs can
squeeze in new kinds of information (like lyrics).  And remember to keep
the property [chunk](devices/primitive-data-types-chunks.md)s manageably short - let's say <= 256 bytes.

When designing a data object, try to strike a good tradeoff between a
super- general format and a highly-specialized one.  Fit the details to at
least one particular need, for example a raster image might as well store
pixels in the current machine's scan order.  But add the kind of
generality that makes the format usable with foreseeable hardware and
software.  E.g., use a whole byte for each red, green, and blue color
value even if this year's computer has only 4-bit video DACs.  Think ahead
and help other programs so long as the overhead is acceptable.  E.g., run
compress a raster by scan line rather than as a unit so future programs
can swap images by scan line to and from secondary storage.

Try to design a general purpose "least common multiple" format that
encompasses the needs of many programs without getting too complicated.
Be sure to leave provisions for future expansion.  Let's coalesce our uses
around a few such formats widely separated in the vast design space.  Two
factors make this flexibility and simplicity practical.  First, file
storage space is getting very plentiful, so compaction is not always a
priority.  Second, nearly any locally-performed data conversion work
during file reading and writing will be cheap compared to the I/O time.

It must be OK to copy a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) or [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) or [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  intact, e.g., to incorporate
it into a composite FORM.  So any kind of internal references within a
FORM must be relative references.  They could be relative to the start of
the containing FORM, relative from the referencing [chunk](devices/primitive-data-types-chunks.md), or a sequence
number into a collection.

With composite [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s, you leverage on existing programs that create and
edit the components.  If you write a program that creates composite
objects, please provide a facility for users to import and export the
nested FORMs.

Finally, don't forget to specify all implied rules in detail.

