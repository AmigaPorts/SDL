# 33 / Parsing / Putting It Together


With just [StopChunk()](../Libraries_Manual_guide/node0433.html), [PropChunk()](../Libraries_Manual_guide/node0434.html), and [ParseIFF()](../Libraries_Manual_guide/node0432.html), you can write a viable
[ILBM](../Libraries_Manual_guide/node045D.html#line8) display program.  Since IFFParse knows all about [IFF](../Libraries_Manual_guide/node0428.html) structure and
scoping, such a display program would have the added ability to parse
complex [FORM](../Libraries_Manual_guide/node042A.html#line7)s, [LIST](../Libraries_Manual_guide/node042A.html#line7)s, and [CAT](../Libraries_Manual_guide/node042A.html#line7)s and attempt to find imagery buried within.

Such an [ILBM](../Libraries_Manual_guide/node045D.html#line8) reader might appear as follows:


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
