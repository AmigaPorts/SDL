---
title: Background for Designers / Data Abstraction
manual: devices
chapter: devices
section: background-for-designers-data-abstraction
functions: []
libraries: []
---

# Background for Designers / Data Abstraction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The basic problem is how to represent information  in a way that's
program- independent, compiler- independent, machine-independent, and
device-independent.

The computer science approach is "data abstraction", also known as
"objects", "actors", and "abstract data types".  A data abstraction has a
"concrete representation" (its storage format), an "abstract
representation" (its capabilities and uses), and access procedures that
isolate all the calling software from the concrete representation.  Only
the access procedures touch the data storage.  Hiding mutable details
behind an interface is called "information hiding".  What is hidden are
the non-portable details of implementing the object, namely the selected
storage representation and algorithms for manipulating it.

The power of this approach is modularity.  By adjusting the access
procedures we can extend and restructure the data without impacting the
interface or its callers.  Conversely, we can extend and restructure the
interface and callers without making existing data obsolete.  It's great
for interchange!

But we seem to need the opposite: fixed file formats for all programs to
access.  Actually, we could file data abstractions ("filed objects") by
storing the data and access procedures together.  We'd have to encode the
access procedures in a standard machine-independent programming language á
la PostScript.  Even with this, the interface can't evolve freely since we
can't update all copies of the access procedures.  So we'll have to design
our abstract representations for limited evolution and occasional
revolution (conversion).

In any case, today's microcomputers can't practically store true data
abstractions.  They can do the next best thing: store arbitrary types of
data in "data chunks", each with a type identifier and a length count.
The type identifier is a reference by name to the access procedures (any
local implementation).  The length count enables storage-level object
operations like "copy" and "skip to next" independent of object type or
contents.

Chunk writing is straightforward.  Chunk reading requires a trivial parser
to scan each chunk and dispatch to the proper access/conversion procedure.
Reading chunks nested inside other chunks may require recursion, but no
look ahead or backup.

That's the main idea of IFF.  There are, of course, a few other
details....

