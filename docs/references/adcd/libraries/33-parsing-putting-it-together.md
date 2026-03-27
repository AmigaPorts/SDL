---
title: 33 / Parsing / Putting It Together
manual: libraries
chapter: libraries
section: 33-parsing-putting-it-together
functions: [AllocIFF, ParseIFF, PropChunk, StopChunk]
libraries: [iffparse.library]
---

# 33 / Parsing / Putting It Together

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

With just [StopChunk()](libraries/33-controlling-parsing-stopchunk.md), [PropChunk()](libraries/33-controlling-parsing-propchunk-findprop.md), and [ParseIFF()](libraries/33-parsing-controlling-parsing.md), you can write a viable
[ILBM](libraries/33-iffparse-library-iff-form-specifications.md) display program.  Since IFFParse knows all about [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) structure and
scoping, such a display program would have the added ability to parse
complex [FORM](libraries/33-the-structure-of-iff-files-composite-data-types.md)s, [LIST](libraries/33-the-structure-of-iff-files-composite-data-types.md)s, and [CAT](libraries/33-the-structure-of-iff-files-composite-data-types.md)s and attempt to find imagery buried within.

Such an [ILBM](libraries/33-iffparse-library-iff-form-specifications.md) reader might appear as follows:


iff = AllocIFF();
iff->iff_Stream = Open ("shuttle dog", MODE_OLDFILE);
InitIFFasDOS (iff);
OpenIFF (iff, IFFF_READ);

PropChunk (iff, ID_ILBM, ID_BMHD);
PropChunk (iff, ID_ILBM, ID_CMAP);
PropChunk (iff, ID_ILBM, ID_CAMG);
StopChunk (iff, ID_ILBM, ID_BODY);
ParseIFF (iff, IFFPARSE_SCAN);


if (bmhdprop = FindProp (iff, ID_ILBM, ID_BMHD))
```c
    configurescreen (bmhdprop);
```
else


```c
    bye ("No BMHD, no picture.");
```
if (cmapprop = FindProp (iff, ID_ILBM, ID_CMAP))
```c
    setcolors (cmapprop);
```
else


```c
    usedefaultcolors ();
```
if (camgprop = FindProp (iff, ID_ILBM, ID_CAMG))


```c
    setdisplaymodes (camgprop);
```
decodebody (iff);
showpicture ();
CloseIFF (iff);
Close (iff->iff_Stream);
FreeIFF (iff);



    Open the Library.
    -----------------
    Application programs must always open iffparse.library before using
    the functions outlined above.

    Only Example Programs Skip Error Checking.
    ------------------------------------------
    Error checking is not used in the example above for the sake of
    clarity.  A real application should always check for errors.

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
