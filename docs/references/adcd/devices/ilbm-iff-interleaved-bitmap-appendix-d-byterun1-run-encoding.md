---
title: ILBM IFF Interleaved Bitmap / Appendix D. ByteRun1 Run Encoding
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-appendix-d-byterun1-run-encoding
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / Appendix D. ByteRun1 Run Encoding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The run encoding scheme byteRun1 is best described by pseudo code for the
decoder Unpacker (called UnPackBits in the Macintosh(tm) toolbox):

  UnPacker:

```c
    LOOP until produced the desired number of bytes
        Read the next source byte into n
        SELECT n FROM
            [0..127]   => copy the next n+1 bytes literally
            [-1..-127] => replicate the next byte -n+1 times
            -128       => no operation
            ENDCASE;
        ENDLOOP;
```
In the inverse routine Packer, it's best to encode a 2 byte repeat run as
a replicate run except when preceded and followed by a literal run, in
which case it's best to merge the three into one literal run.  Always
encode 3 byte repeats as replicate runs.

Remember that each row of each scan line of a raster is separately packed.

