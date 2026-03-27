---
title: 33 / The Structure of IFF Files / Composite Data Types
manual: libraries
chapter: libraries
section: 33-the-structure-of-iff-files-composite-data-types
functions: []
libraries: []
---

# 33 / The Structure of IFF Files / Composite Data Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Standard [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) files generally contain a variable number of [chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) within
one of the standard IFF composite data types (which may be thought of as
chunks which contain other chunks).  The IFF specification defines three
basic composite data types, `FORM', `CAT ', and `LIST'.  A special
composite data type, the `PROP', is found only inside a LIST.




```c
              Table 33-1: Usage of Composite [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) Types

        [FORM](libraries/33-iffparse-library-iff-form-specifications.md)  A grouping of [chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) which describe one set of data
        LIST  A grouping of the same type of FORMs with shared
              properties in a PROP
        PROP  May appear in a LIST to define chunks shared by
              several FORMs
        CAT   A concatenation of related FORMs or LISTs
```
The special [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) composite data types, like simple [chunks,](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) start with a
4-character identifier (such as `FORM'), followed by a 32-bit length.  But
their data begins with a second 4-character identifier that tells you what
type of data is in the composite.  For example, a [FORM ILBM](libraries/33-iffparse-library-iff-form-specifications.md) contains
chunks describing a bitmap image, and a [FORM FTXT](libraries/33-iffparse-library-iff-form-specifications.md) contains chunks
describing formatted text.

It may help to think of each composite data type as a box containing
[chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md), the [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) building blocks.  Figure 33-2 shows a diagram of a
typical composite.




        Figure 33-2: The FORM - The Most Common IFF File Type
                        ____________________
                       |                    |
                       | `FORM' Size `NAME' |
                       |  ________________  |
                       | |                | |
                       | | `CKID' Size    | |
                       | | data data data | |
                       | | data data ...  | |
                       | |________________| |
                       |  ________________  |
                       | |                | |
                       | | `CKID' Size    | |
                       | | data data data | |
                       | | data data ...  | |
                       | |________________| |
                       |  ________________  |
                       | |                | |
                       | | `CKID' Size    | |
                       | | data data data | |
                       | | data data ...  | |
                       | |________________| |
                       |____________________|
The example FORM in figure 33-2 is outlined below showing the size of
[chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) within the FORM.  Notice that the size of a composite includes its
second 4-character identifier (shown below as `NAME').


 .FORM 72 NAME  (72 is the size of the FORM starting with the "N" of NAME)
 ..CKID 22     (then 22 bytes of data, so chunk header + chunk size is 30)
 ..CKID 10     (then 10 bytes of data, so chunk header + chunk size is 18)
 ..CKID 12     (then 12 bytes of data, so chunk header + chunk size is 20)



```c
    Note
    ----
    In the example above, indentation represents the nesting of the
    [chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) within the FORM.  Real FORMs and chunks would have different
    four-character identifiers rather than `NAME' and `CKID':
```
Any odd-length [chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) must have a pad byte of zero at the end of the
chunk.  As shown below, this pad byte is not counted in the size of the
chunk but is counted in the size of any composite types (such as FORM)
that contain an odd-length chunk.  Warning: some [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) readers and writers
do not deal with this properly.


 .FORM 72 NAME  (72 is the size of the FORM starting with the "N" of NAME)
 ..CKID 21     (then 21 bytes of data, so chunk header + chunk size is 29)
 ..0           (pad byte of zero, size 1)
 ..CKID 10     (then 10 bytes of data, so chunk header + chunk size is 18)
 ..CKID 12     (then 12 bytes of data, so chunk header + chunk size is 20)


Most [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) files are of the composite type FORM.  Generally, a FORM is a
simple grouping of [chunks](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) that provide information about some data, and
the data itself.  Although some standard chunks have common usage within
different FORMS, the identity and format of most chunks within a FORM are
relative to the definition and specification of the FORM.  For example, a
CRNG chunk in a [FORM ILBM](libraries/33-iffparse-library-iff-form-specifications.md) may have a totally different format and contents
than a chunk named CRNG in a different type of FORM.

One of the most popular IFF FORMs that has been defined is the [ILBM](libraries/33-iffparse-library-iff-form-specifications.md)
standard.  This is how most Amiga bitmap imagery is stored.  Since this is
the most common [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file, it is used frequently as an example.

Here is the output of a program called Sift.c that displays a text
description of the contents of an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file ([Sift.c](libraries/lib-examples-sift-c.md) is listed at the end of
this chapter).  The file shown below is a fairly simple [ILBM](libraries/33-iffparse-library-iff-form-specifications.md).



```c
                .FORM 11068 ILBM
                ..BMHD 20
                ..CAMG 4
                ..CMAP 12
                ..BODY 10995


    Computing the Size of a FORM.
    -----------------------------
    The size of the FORM (11068 bytes) is equal to the sum of the sizes
    stated in each [chunk](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md) contained within the FORM, plus 8 bytes for the
    overhead of each chunk header (4 bytes for the 4-character chunk ID,
    and 4 bytes for the 32-bit chunk size), plus 4 bytes for the FORM's
    own 4-character ID (`ILBM'), plus 1 byte more for each pad byte that
    follow any odd-length chunks.
```
