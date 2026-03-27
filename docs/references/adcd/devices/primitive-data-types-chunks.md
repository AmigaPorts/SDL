---
title: Primitive Data Types / Chunks
manual: devices
chapter: devices
section: primitive-data-types-chunks
functions: []
libraries: []
---

# Primitive Data Types / Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Chunks are the building blocks in the IFF structure.  The form expressed
as a C typedef is:

```c
    typedef struct {
```
	ID	ckID;			/* 4 character ID */
	LONG	ckSize;			/* sizeof(ckData) */
	UBYTE	ckData[/* ckSize */];
	} Chunk;


We can diagram an example chunk - a "[CMAP](devices/standard-properties-cmap.md)" chunk containing 12 data bytes
- like this:



                        +------------------+   -
        ckID:           | "CMAP"           |   |
                        |------------------+   |
        ckSize:         |  12              |   |
                    -   |------------------+   |
        ckData:     |   |  0, 0, 0, 32     |  20 bytes
                   12   |------------------+   |
                  bytes |  0, 0, 64, 0     |   |
                    |   |------------------+   |
                    |   |  0, 0, 64, 0     |   |
                    -   +------------------+   -
That's 4 bytes of ckID, 4 bytes of ckSize and 12 data bytes.  The total
space used is 20 bytes.

The ckID identifies the format and purpose of the chunk.  As a rule, a
program must recognize ckID to interpret ckData.  It should skip over all
unrecognized chunks.  The ckID also serves as a format version number as
long as we pick new IDs to identify new formats of ckData (see above).

The following ckIDs are universally reserved to identify chunks with
particular IFF meanings: [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md), [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md), [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) , and "    ".  The
special ID "    " (4 spaces) is a ckID for "filler" chunks, that is,
chunks that fill space but have no meaningful contents.  The IDs "LIS1"
through "LIS9", "FOR1" through "FOR9", and "CAT1" through "CAT9" are
reserved for future "version number" variations.  All IFF-compatible
software must account for these chunk IDs.

The ckSize is a logical block size - how many data bytes are in ckData.  If
ckData is an odd number of bytes long, a 0 pad byte follows which is not
included in ckSize.  (Cf. Alignment.)  A chunk's total physical size is
ckSize rounded up to an even number plus the size of the header.  So the
smallest chunk is 8 bytes long with ckSize = 0.  For the sake of following
chunks, programs must respect every chunk's ckSize as a virtual
end-of-file for reading its ckData even if that data is malformed, e.g.,
if nested contents are truncated.

We can describe the syntax of a chunk as a regular expression with "#"
representing the ckSize, the length of the following {braced} bytes.  The
"[0]" represents a sometimes needed pad byte.  (The regular expressions in
this document are collected in [Appendix A](devices/app-a-ea-iff-appendix-a-reference.md) along with an explanation of
notation.)

	Chunk	::= ID #{ UBYTE* } [0]

One chunk output technique is to stream write a chunk header, stream write
the chunk contents, then random access back to the header to fill in the
size. Another technique is to make a preliminary pass over the data to
compute the size, then write it out all at once.

