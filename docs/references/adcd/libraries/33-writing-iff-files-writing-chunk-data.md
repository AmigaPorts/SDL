---
title: 33 / Writing IFF Files / Writing Chunk Data
manual: libraries
chapter: libraries
section: 33-writing-iff-files-writing-chunk-data
functions: [PushChunk, WriteChunkBytes, WriteChunkRecords]
libraries: [iffparse.library]
---

# 33 / Writing IFF Files / Writing Chunk Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Writing the [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) chunk data is done with either the [WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md) or
[WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md) functions.


```c
    error = WriteChunkBytes (iff, buf, size);
    error = WriteChunkRecords (iff, buf, recsize, numrec);
```
If you specified a valid chunk size when you called [PushChunk()](libraries/33-creating-chunks-in-a-file-pushchunk.md),
[WriteChunkBytes()](autodocs-2.0/iffparse-library-writechunkbytes.md) and [WriteChunkRecords()](autodocs-2.0/iffparse-library-writechunkrecords.md) will truncate attempts to write
past the end of the chunk.

Code to write an [ILBM](libraries/33-iffparse-library-iff-form-specifications.md) file might take the following form:


```c
    iff = AllocIFF ();
    iff->iff_Stream = Open ("foo", MODE_NEWFILE);
    InitIFFasDOS (iff);
    OpenIFF (iff, IFFF_WRITE);

    PushChunk (iff, ID_ILBM, ID_FORM, IFFSIZE_UNKNOWN);

    PushChunk (iff, ID_ILBM, ID_BMHD, sizeof (struct BitMapHeader));
    WriteChunkBytes (iff, &bmhd, sizeof (bmhd));
    PopChunk (iff);

    PushChunk (iff, ID_ILBM, ID_CMAP, cmapsize);
    WriteChunkBytes (iff, cmapdata, cmapsize);
    PopChunk (iff);

    PushChunk (iff, ID_ILBM, ID_BODY, IFFSIZE_UNKNOWN);
    packwritebody (iff);
    PopChunk (iff);

    PopChunk (iff);

    CloseIFF (iff);
    Close (iff->iff_Stream);
    FreeIFF (iff);
```
Again, error checking is not present for clarity. See the example code
[ClipFTXT.c](libraries/lib-examples-clipftxt-c.md) which writes a simple [FTXT](libraries/33-iffparse-library-iff-form-specifications.md) clip to the clipboard.

---

## See Also

- [PushChunk — iffparse.library](../autodocs/iffparse.library.md#pushchunk)
- [WriteChunkBytes — iffparse.library](../autodocs/iffparse.library.md#writechunkbytes)
- [WriteChunkRecords — iffparse.library](../autodocs/iffparse.library.md#writechunkrecords)
