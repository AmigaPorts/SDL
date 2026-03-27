# 33 / / FORM ILBM / Interpreting ILBMs


[ILBM](../Libraries_Manual_guide/node045D.html#line8) is a fairly simple [IFF FORM](../Libraries_Manual_guide/node042A.html#line7).  All you really need to deal with to
extract the image are the following chunks:

[BMHD](../Libraries_Manual_guide/node045F.html)

```c
    Information about the size, depth, compaction method (see interpreted
    [hex dump](../Libraries_Manual_guide/node0460.html) above).
```
CAMG

```c
    Optional Amiga ViewModes chunk.  Most HAM and HALFBRITE [ILBM](../Libraries_Manual_guide/node045D.html#line8)s should
    have this chunk.  If no CAMG chunk is present, and image is 6 planes
    deep, assume HAM and you'll probably be right.  Some Amiga ViewModes
    flags are HIRES=0x8000, LACE=0x4, HAM=0x800, HALFBRITE=0x80.  2.0
    ILBM writers should write a full 32-bit mode ID in the CAMG.  See the
    [IFF Manual](../Devices_Manual_guide/node0129.html) for more information on writing and interpreting 32-bit
    CAMG values.
```
CMAP

    RGB values for color registers 0 to N.  Previously, 4-bit RGB
    components each left justified in a byte.  These should now be stored
    as a full 8-bit RGB values by duplicating 4-bit values in the high
    and low nibble of the byte.
[BODY](../Libraries_Manual_guide/node0462.html)

```c
    The pixel data, stored in an interleaved fashion as follows (each
    line individually compacted if BMHD Compression = 1):

                plane 0 scan line 0
                plane 1 scan line 0
                plane 2 scan line 0
                ...
                plane n scan line 0
                plane 0 scan line 1
                plane 1 scan line 1
                etc.
```
Optional Chunks

```c
    Also watch for AUTH Author chunks and (c) copyright chunks and
    preserve any copyright information if you rewrite the [ILBM](../Libraries_Manual_guide/node045D.html#line8).
```
