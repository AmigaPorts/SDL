---
title: App.A EA IFF/ Primitive Data Types
manual: devices
chapter: devices
section: app-a-ea-iff-primitive-data-types
functions: []
libraries: []
---

# App.A EA IFF/ Primitive Data Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Atomic components such as integers and characters that are interpretable
directly by the CPU are specified in one format for all processors.  We
chose a format that's the same as used by the Motorola MC68000 processor
[M68000 16/32-Bit Microprocessor Programmer's Reference Manual].  The high
byte and high word of a number are stored first.

N.B.: Part 3 dictates the format for "primitive" data types where-and
only where-used in the overall file structure.  The number of such
occurrences of dictated formats will be small enough that the costs of
conversion, storage, and management of processor-specific files would far
exceed the costs of conversion during I/O by "foreign" programs.  A
particular data chunk may be specified with a different format for its
internal primitive types or with processor or environment specific
variants if necessary to optimize local usage.  Since that hurts data
interchange, it's not recommended.  (Cf. Designing New Data Sections, in
Part 4.)

 [Alignment](devices/primitive-data-types-alignment.md)   [Characters](devices/primitive-data-types-characters.md)   [Type IDs](devices/primitive-data-types-type-ids.md)   [Strings](devices/primitive-data-types-strings-string-chunks-and-string.md)           [Links](devices/primitive-data-types-links.md) 
 [Numbers](devices/primitive-data-types-numbers.md)     [Dates](devices/primitive-data-types-dates.md)        [Chunks](devices/primitive-data-types-chunks.md)     [Data Properties](devices/primitive-data-types-data-properties-advanced-topic.md)   [File References](devices/primitive-data-types-file-references.md) 

