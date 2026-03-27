# 33 / The Structure of IFF Files / Composite Data Types


Standard [IFF](../Libraries_Manual_guide/node0428.html) files generally contain a variable number of [chunks](../Libraries_Manual_guide/node0429.html) within
one of the standard IFF composite data types (which may be thought of as
chunks which contain other chunks).  The IFF specification defines three
basic composite data types, `FORM', `CAT ', and `LIST'.  A special
composite data type, the `PROP', is found only inside a LIST.




```c
              Table 33-1: Usage of Composite [IFF](../Libraries_Manual_guide/node0428.html) Types

        [FORM](../Libraries_Manual_guide/node045D.html)  A grouping of [chunks](../Libraries_Manual_guide/node0429.html) which describe one set of data
        LIST  A grouping of the same type of FORMs with shared
              properties in a PROP
        PROP  May appear in a LIST to define chunks shared by
              several FORMs
        CAT   A concatenation of related FORMs or LISTs
```
The special [IFF](../Libraries_Manual_guide/node0428.html) composite data types, like simple [chunks,](../Libraries_Manual_guide/node0429.html) start with a
4-character identifier (such as `FORM'), followed by a 32-bit length.  But
their data begins with a second 4-character identifier that tells you what
type of data is in the composite.  For example, a [FORM ILBM](../Libraries_Manual_guide/node045D.html#line8) contains
chunks describing a bitmap image, and a [FORM FTXT](../Libraries_Manual_guide/node045D.html#line8) contains chunks
describing formatted text.

It may help to think of each composite data type as a box containing
[chunks](../Libraries_Manual_guide/node0429.html), the [IFF](../Libraries_Manual_guide/node0428.html) building blocks.  Figure 33-2 shows a diagram of a
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
[chunks](../Libraries_Manual_guide/node0429.html) within the FORM.  Notice that the size of a composite includes its
second 4-character identifier (shown below as `NAME').


 .FORM 72 NAME  (72 is the size of the FORM starting with the "N" of NAME)
 ..CKID 22     (then 22 bytes of data, so chunk header + chunk size is 30)
 ..CKID 10     (then 10 bytes of data, so chunk header + chunk size is 18)
 ..CKID 12     (then 12 bytes of data, so chunk header + chunk size is 20)



```c
    Note
    ----
    In the example above, indentation represents the nesting of the
    [chunks](../Libraries_Manual_guide/node0429.html) within the FORM.  Real FORMs and chunks would have different
    four-character identifiers rather than `NAME' and `CKID':
```
Any odd-length [chunks](../Libraries_Manual_guide/node0429.html) must have a pad byte of zero at the end of the
chunk.  As shown below, this pad byte is not counted in the size of the
chunk but is counted in the size of any composite types (such as FORM)
that contain an odd-length chunk.  Warning: some [IFF](../Libraries_Manual_guide/node0428.html) readers and writers
do not deal with this properly.


 .FORM 72 NAME  (72 is the size of the FORM starting with the "N" of NAME)
 ..CKID 21     (then 21 bytes of data, so chunk header + chunk size is 29)
 ..0           (pad byte of zero, size 1)
 ..CKID 10     (then 10 bytes of data, so chunk header + chunk size is 18)
 ..CKID 12     (then 12 bytes of data, so chunk header + chunk size is 20)


Most [IFF](../Libraries_Manual_guide/node0428.html) files are of the composite type FORM.  Generally, a FORM is a
simple grouping of [chunks](../Libraries_Manual_guide/node0429.html) that provide information about some data, and
the data itself.  Although some standard chunks have common usage within
different FORMS, the identity and format of most chunks within a FORM are
relative to the definition and specification of the FORM.  For example, a
CRNG chunk in a [FORM ILBM](../Libraries_Manual_guide/node045D.html#line8) may have a totally different format and contents
than a chunk named CRNG in a different type of FORM.

One of the most popular IFF FORMs that has been defined is the [ILBM](../Libraries_Manual_guide/node045D.html#line8)
standard.  This is how most Amiga bitmap imagery is stored.  Since this is
the most common [IFF](../Libraries_Manual_guide/node0428.html) file, it is used frequently as an example.

Here is the output of a program called Sift.c that displays a text
description of the contents of an [IFF](../Libraries_Manual_guide/node0428.html) file ([Sift.c](../Libraries_Manual_guide/node05A0.html) is listed at the end of
this chapter).  The file shown below is a fairly simple [ILBM](../Libraries_Manual_guide/node045D.html#line8).



```c
                .FORM 11068 ILBM
                ..BMHD 20
                ..CAMG 4
                ..CMAP 12
                ..BODY 10995


    Computing the Size of a FORM.
    -----------------------------
    The size of the FORM (11068 bytes) is equal to the sum of the sizes
    stated in each [chunk](../Libraries_Manual_guide/node0429.html) contained within the FORM, plus 8 bytes for the
    overhead of each chunk header (4 bytes for the 4-character chunk ID,
    and 4 bytes for the 32-bit chunk size), plus 4 bytes for the FORM's
    own 4-character ID (`ILBM'), plus 1 byte more for each pad byte that
    follow any odd-length chunks.
```
