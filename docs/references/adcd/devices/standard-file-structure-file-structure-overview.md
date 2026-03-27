---
title: Standard File Structure / File Structure Overview
manual: devices
chapter: devices
section: standard-file-structure-file-structure-overview
functions: []
libraries: []
---

# Standard File Structure / File Structure Overview

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An IFF file is just a single [chunk](devices/primitive-data-types-chunks.md) of type [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md), or [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) .  Therefore
an IFF file can be recognized by its first 4 bytes: "FORM", "LIST", or
"[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ". Any file contents after the chunk's end are to be ignored.  (Some
file transfer programs add garbage to the end of transferred files.  This
specification protects against such common damage).

The simplest IFF file would be one that does no more than encapsulate some
binary data (perhaps even an old-fashioned single-purpose binary file).
Here is a binary dump of such a minimal IFF example:

	0000: 464F524D 0000001A 534E4150 43524143    FORM....SNAPCRAC
	0010: 0000000D 68656C6C 6F2C776F 726C6421    ....hello,world!
	0020: 0A00                                   ..

The first 4 bytes indicate this is a "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)"; the most common IFF top level
structure.  The following 4 bytes indicate that the contents totals 26
bytes. The form type is listed as "SNAP".

Our form "SNAP" contains only one [chunk](devices/primitive-data-types-chunks.md) at the moment; a chunk of type
"CRAC". From the size ($0000000D) the amount of data must be 13 bytes.  In
this case, the data happens to correspond to the ASCII string "hello,
world!<lf>". Since the number 13 is odd, a zero pad byte is added to the
file.  At any time new chunks could be added to form SNAP without
affecting any other aspect of the file (other than the form size).  It's
that simple.

Since an IFF file can be a group of objects, programs that read/write
single objects can communicate to an extent with programs that read/write
groups. You're encouraged to write programs that handle all the objects in
a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) or [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) .  A graphics editor, for example, could process a list of
pictures as a multiple page document, one page at a time.

Programs should enforce IFF's syntactic rules when reading and writing
files. Users should be told when a file is corrupt.  This ensures robust
data transfer.  For minor damage, you may wish to give the user the option
of using the suspect data, or cancelling.  Presumably a user could read in
a damaged file, then save whatever was salvaged to a valid file.  The
public domain IFF reader/writer subroutine package does some syntatic
checks for you.  A utility program"IFFCheck" is available that scans an
IFF file and checks it for conformance to IFF's syntactic rules.  IFFCheck
also prints an outline of the [chunk](devices/primitive-data-types-chunks.md)s in the file, showing the ckID and
ckSize of each.  This is quite handy when building IFF programs.  Example
programs are also available to show details of reading and writing IFF
files.

A merge program "IFFJoin" will be available that logically appends IFF
files into a single [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  group.  It "unwraps" each input file that is a CAT
so that the combined file isn't nested CATs.

If we need to revise the IFF standard, the three anchoring IDs will be
used as "version numbers".  That's why IDs "FOR1" through "FOR9", "LIS1"
through "LIS9", and "CAT1" through "CAT9" are reserved.

IFF formats are designed for reasonable performance with floppy disks.  We
achieve considerable simplicity in the formats and programs by relying on
the host file system rather than defining universal grouping structures
like directories for [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) contents.  On huge storage systems, IFF files
could be leaf nodes in a file structure like a B-tree.  Let's hope the
host file system implements that for us!

There are two kinds of IFF files: single purpose files and scrap files.
They differ in the interpretation of multiple data objects and in the
file's external type.

