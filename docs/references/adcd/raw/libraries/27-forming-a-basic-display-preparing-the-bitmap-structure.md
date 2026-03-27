# 27 / / Forming a Basic Display / Preparing the BitMap Structure


The [BitMap](../Libraries_Manual_guide/node032B.html#line74) structure tells the system where to find the display and
drawing memory and how this memory space is organized. The following code
section prepares a BitMap structure, including allocation of memory for
the bitmap.  This is done with two functions, [InitBitMap()](../Includes_and_Autodocs_2._guide/node0450.html) and
[AllocRaster()](../Includes_and_Autodocs_2._guide/node0412.html).  InitBitMap() takes four arguments--a pointer to a BitMap
and the depth, width, and height of the desired bitmap.  Once the bitmap
is initialized, memory for its bitplanes must be allocated.  AllocRaster()
takes two arguments--width and height.  Here is a code section to
initialize a bitmap:


```c
    /*  Init BitMap for RasInfo.  */
    InitBitMap(&bitMap, DEPTH, WIDTH, HEIGHT);

    /* Set the plane pointers to NULL so the cleanup routine will know */
    /* if they were used. */
    for(depth=0; depth<DEPTH; depth++)
        bitMap.Planes[depth] = NULL;

    /*  Allocate space for BitMap.  */
    for(depth=0; depth<DEPTH; depth++)
        {
        bitMap.Planes[depth] = (PLANEPTR)AllocRaster(WIDTH, HEIGHT);
        if (bitMap.Planes[depth] == NULL)
            cleanExit(RETURN_WARN);
        }
```
This code allocates enough memory to handle the display area for as many
bitplanes as the depth you have defined.

