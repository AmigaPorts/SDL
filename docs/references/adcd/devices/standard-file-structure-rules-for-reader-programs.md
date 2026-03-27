---
title: Standard File Structure / Rules for Reader Programs
manual: devices
chapter: devices
section: standard-file-structure-rules-for-reader-programs
functions: []
libraries: []
---

# Standard File Structure / Rules for Reader Programs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here are some notes on building programs that read IFF files.  For [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)
and [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md) work, you should also read up on recursive descent parsers. [See,
for example, Compiler Construction, An Advanced Course.]

  o The standard is very flexible so many programs can exchange data.

     This implies a program has to scan the file and react to what's
     actually there in whatever order it appears.  An IFF reader program
     is a parser.
  o For interchange to really work, programs must be willing to do some

     conversion during read-in.  If the data isn't exactly what you expect,
     say, the raster is smaller than those created by your program, then
     adjust it.  Similarly, your program could crop a large picture, add
     or drop bitplanes, or create/discard a mask plane.  The program
     should give up gracefully on data that it can't convert.
  o If it doesn't start with "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)", "[LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)", or "[CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) ", it's not an IFF-85

     file.
  o For any [chunk](devices/primitive-data-types-chunks.md) you encounter, you must recognize its type ID to

     understand its contents.
  o For any [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) [chunk](devices/primitive-data-types-chunks.md) you encounter, you must recognize its FORM type ID

```c
     to understand the contained "local chunks".  Even if you don't
     recognize the FORM type, you can still scan it for nested FORMs,
     [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s, and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s of interest.
```
  o Don't forget to skip the implied pad byte after every odd-length [chunk](devices/primitive-data-types-chunks.md),

     this is not  included in the chunk count!
  o [Chunk](devices/primitive-data-types-chunks.md) types [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md), [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md), and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  are generic groups.  They always

     contain a subtype ID followed by chunks.
  o Readers ought to handle a [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md)  of [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s in a file.  You may treat the

     FORMs like document pages to sequence through, or just use the first
     FORM.
  o Many  IFF readers completely skip [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s.  "Fully IFF-conforming"

```c
     readers are those that handle LISTs, even if just to read the first
     [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) from a file.  If you do look into a LIST, you must process
     shared properties (in [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md) [chunk](devices/primitive-data-types-chunks.md)s) properly.  The idea is to get the
     correct data or none at all.
```
  o The nicest readers are willing to look into unrecognized [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s for

     nested FORM types that they do recognize.  For example, a musical
     score may contain nested instrument descriptions and animation or
     desktop publishing files may contain still pictures.   This extra
     step is highly recommended.
Note to programmers: Processing PROP [chunk](devices/primitive-data-types-chunks.md)s is not simple! You'll need
some background in interpreters with stack frames.  If this is foreign to
you, build programs that read/write only one [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) per file.  For the more
intrepid programmers, the next paragraph summarizes how to process [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s
and [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s.

Allocate a stack frame for every [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) and [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) you encounter and
initialize it by copying the stack frame of the parent LIST or FORM.  At
the top level, you'll need a stack frame initialized to your program's
global defaults. While reading each LIST or FORM, store all encountered
properties into the current stack frame.  In the example ShowILBM, each
stack frame has a place for a bitmap header property ILBM.[BMHD](devices/standard-properties-bmhd.md) and a color
map property ILBM.[CMAP](devices/standard-properties-cmap.md). When you finally get to the ILBM's [BODY](devices/standard-body-data-chunk-body.md) [chunk](devices/primitive-data-types-chunks.md), use
the property settings accumulated in the current stack frame.

An alternate implementation would just remember [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s encountered,
forgetting each on reaching the end of its scope (the end of the
containing [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)).  When a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) XXXX is encountered, scan the [chunk](devices/primitive-data-types-chunks.md)s in all
remembered [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md)s XXXX, in order, as if they appeared before the chunks
actually in the FORM XXXX.  This gets trickier if you read FORMs inside of
FORMs.

