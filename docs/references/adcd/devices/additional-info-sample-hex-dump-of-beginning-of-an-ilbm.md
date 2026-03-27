---
title: Additional Info / Sample hex dump of beginning of an ILBM
manual: devices
chapter: devices
section: additional-info-sample-hex-dump-of-beginning-of-an-ilbm
functions: []
libraries: []
---

# Additional Info / Sample hex dump of beginning of an ILBM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Important note!  You can NOT ever depend on any particular ILBM chunk
being at any particular offset into the file!  IFF files are composed, in
their simplest form, of chunks within a FORM.  Each chunk starts starts
with a 4-letter chunkID, followed by a 32-bit length of the rest of the
chunk.  You PARSE IFF files, skipping past unneeded or unknown chunks by
seeking their length (+1 if odd length) to the next 4-letter chunkID.

0000: 464F524D 00016418 494C424D 424D4844    FORM..d.ILBMBMHD
0010: 00000014 01400190 00000000 06000100    .....@..........
0020: 00000A0B 01400190 43414D47 00000004    .....@..CAMG....
0030: 00000804 434D4150 00000030 001100EE    ....CMAP...0....
0040: EEEE0000 22000055 33333355 55550033    .... ..P000PPP.0
0050: 99885544 77777711 66EE2266 EE6688DD    ..P@ppp.`. `.`..
0060: AAAAAAAA 99EECCCC CCDDAAEE 424F4459    ............BODY
0070: 000163AC F8000F80 148A5544 2ABDEFFF    ..c.......UD*...  etc.

Interpretation:

      'F O R M' length  'I L B M''B M H D'<-start of BitMapHeader chunk
0000: 464F524D 00016418 494C424D 424D4844    FORM..d.ILBMBMHD

       length  WideHigh XorgYorg PlMkCoPd <- Planes Mask Compression Pad
0010: 00000014 01400190 00000000 06000100    .....@..........

                                             start of C-AMiGa
      TranAspt PagwPagh 'C A M G' length  <- View modes chunk
0020: 00000A0B 01400190 43414D47 00000004    .....@..CAMG....

```c
      Viewmode 'C M A P' length  R g b R  <- Viewmode 800=HAM | 4=LACE
```
0030: 00000804 434D4150 00000030 001100EE    ....CMAP...0....

      g b R g  b R g b  R g b R  g b R g  <- Rgb's are for reg0 thru regN
0040: EEEE0000 22000055 33333355 55550033    .... ..P000PPP.0

      b R g b  R g b R  g b R g  b R g b
0050: 99885544 77777711 66EE2266 EE6688DD    ..P@ppp.`. `.`..

      R g b R  g b R g  b R g b 'B O D Y'
0060: AAAAAAAA 99EECCCC CCDDAAEE 424F4459    ............BODY

```c
                                             Compacted
       length   start of body data        <- (Compression=1 above)
```
0070: 000163AC F8000F80 148A5544 2ABDEFFF    ..c.......UD*...
0080: FFBFF800 0F7FF7FC FF04F85A 77AD5DFE    ...........Zw.].  etc.

Notes on CAMG Viewmodes:  HIRES=0x8000  LACE=0x4  HAM=0x800  HALFBRITE=0x80

