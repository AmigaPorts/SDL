---
title: A Quick Introduction to IFF / File extensibility
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-file-extensibility
functions: []
libraries: []
---

# A Quick Introduction to IFF / File extensibility

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IFF files are extensible and forward/backward compatible:

  o Chunk contents should be designed for compatibility across

```c
     environments and for longevity.  Every chunk should have a path for
     future expansion; at minimum this will be an unused bit or two.
```
  o The standards team for a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type can extend one of the chunks that

     contains a structure by appending new, optional structure fields.
  o Anyone can define new [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) types as well as new chunk types within a

     FORM type.  Storing private chunks within a FORM is OK, but be sure
     to register your activities with Commodore Applications and Technical
     Support.
  o A chunk can be superseded by a new chunk type, e.g., to store more

```c
     bits per RGB color register. New programs can output the old chunk
     (for backward compatibility) along with the new chunk.
```
  o If you must change data in an incompatible way, change the chunk ID or

```c
     the [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type ID.
```
