/* Source: ADCD 2.1
 * Section: 33-writing-iff-files-writing-chunk-data
 * Library: libraries
 * ADCD reference: libraries/33-writing-iff-files-writing-chunk-data.md
 */

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
