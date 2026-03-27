---
title: 33 / / FORM ILBM / Sample Hex Dump of an ILBM
manual: libraries
chapter: libraries
section: 33-form-ilbm-sample-hex-dump-of-an-ilbm
functions: []
libraries: []
---

# 33 / / FORM ILBM / Sample Hex Dump of an ILBM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    WARNING:
    --------
    This hex dump is shown only to help the reader understand how [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md)
    chunks appear in a file.  You cannot ever depend on any particular
    [ILBM](libraries/33-iffparse-library-iff-form-specifications.md) chunk being at any particular offset into the file.  IFF files
    are composed, in their simplest form, of chunks within a [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md).  Each
    chunk starts with a 4-letter chunkID, followed by a 32-bit length of
    the rest of the chunk.  You must parse IFF files, skipping past
    unneeded or unknown chunks by seeking their length (+1 if odd length)
    to the next 4-letter chunk ID.  In a real ILBM file, you are likely
    to encounter additional optional chunks.  See the IFF Specification
    listed in the Amiga ROM Kernel Reference Manual: [Devices](devices/appendix-a-iff-interchange-file-format.md) for
    additional information on such chunks.
```
0000: 464F524D 00016418 494C424D 424D4844    FORM..d.ILBMBMHD
0010: 00000014 01400190 00000000 06000100    .....@..........
0020: 00000A0B 01400190 43414D47 00000004    .....@..CAMG....
0030: 00000804 434D4150 00000030 001000E0    ....CMAP...0....
0040: E0E00000 20000050 30303050 50500030    .... ..P000PPP.0
0050: 90805040 70707010 60E02060 E06080D0    ..P@ppp.`. `.`..
0060: A0A0A0A0 90E0C0C0 C0D0A0E0 424F4459    ............BODY
0070: 000163AC F8000F80 148A5544 2ABDEFFF    ..c.......UD*...  etc.

Interpretation:

      'F O R M' length  'I L B M"B M H D' <- start of BitMapHeader chunk
0000: 464F524D 00016418 494C424D 424D4844    FORM..d.ILBMBMHD

                                             Planes Mask
       length  WideHigh XorgYorg PlMkCoRe <- Compression Reserved
0010: 00000014 01400190 00000000 06000100    .....@..........

                                             start of C-AMiGa
      TranAspt PagwPagh 'C A M G' length  <- View modes chunk
0020: 00000A0B 01400190 43414D47 00000004    .....@..CAMG....

dir include:

```c
      ViewMode 'C M A P' length   R g b R <- ViewMode 800=HAM | 4=LACE
```
0030: 00000804 434D4150 00000030 001000E0    ....CMAP...0....

       g b R g  b R g b  R g b R  g b R g <- Rgb's are for reg0 thru regN
0040: E0E00000 20000050 30303050 50500030    .... ..P000PPP.0

       b R g b  R g b R  g b R g  b R g b
0050: 90805040 70707010 60E02060 E06080D0    ..P@ppp.`. `.`..

       R g b R  g b R g  b R g b 'B O D Y'
0060: A0A0A0A0 90E0C0C0 C0D0A000 424F4459    ............BODY

```c
                                             Compacted
       length   start of body data        <- (Compression=1 above)
```
0070: 000163AC F8000F80 148A5544 2ABDEFFF    ..c.......UD*...
0080: FFBFF800 0F7FF7FC FF04F85A 77AD5DFE    ...........Zw.].  etc.

Simple CAMG ViewModes:  HIRES=0x8000  LACE=0x4  HAM=0x800  HALFBRITE=0x80

( Release 2 ILBMs may contain a LONGWORD ViewPort ModeID in CAMG )

