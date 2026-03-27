# 33 / Writing IFF Files / Writing Chunk Data


Writing the [IFF](../Libraries_Manual_guide/node0428.html) chunk data is done with either the [WriteChunkBytes()](../Includes_and_Autodocs_2._guide/node01DE.html) or
[WriteChunkRecords()](../Includes_and_Autodocs_2._guide/node01DF.html) functions.


```c
    error = WriteChunkBytes (iff, buf, size);
    error = WriteChunkRecords (iff, buf, recsize, numrec);
```
If you specified a valid chunk size when you called [PushChunk()](../Libraries_Manual_guide/node0441.html),
[WriteChunkBytes()](../Includes_and_Autodocs_2._guide/node01DE.html) and [WriteChunkRecords()](../Includes_and_Autodocs_2._guide/node01DF.html) will truncate attempts to write
past the end of the chunk.

Code to write an [ILBM](../Libraries_Manual_guide/node045D.html#line8) file might take the following form:


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
[ClipFTXT.c](../Libraries_Manual_guide/node059F.html) which writes a simple [FTXT](../Libraries_Manual_guide/node045D.html#line8) clip to the clipboard.

