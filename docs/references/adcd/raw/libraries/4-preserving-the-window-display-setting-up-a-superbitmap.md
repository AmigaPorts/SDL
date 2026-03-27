# 4 / Preserving the Window Display / Setting Up A SuperBitMap Window


SuperBitMap windows are created by setting the WFLG_SUPER_BITMAP flag, or
by specifying the [WA_SuperBitMap](../Libraries_Manual_guide/node0125.html#line126) tag in the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.  A
pointer to an allocated and initialized [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure must be provided.

A SuperBitMap window requires the application to allocate and initialize
its own bitmap.  This entails allocating a [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure, initializing
the structure and allocating memory for the bit planes.

Allocate a [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure with the Exec [AllocMem()](../Libraries_Manual_guide/node02A7.html) function.  Then use
the graphics function [InitBitMap()](../Libraries_Manual_guide/node032E.html) to initialize the BitMap structure:


```c
    void InitBitMap( struct BitMap *bitMap, long depth,
                     long width, long height );
```
[InitBitMap()](../Libraries_Manual_guide/node032E.html) fills in fields in the [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure describing how a
linear memory area is organized as a series of one or more rectangular
bit-planes.

Once you have allocated and initialized the [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure, use the
graphics library function [AllocRaster()](../Libraries_Manual_guide/node032E.html) to allocate the memory space for
all the bit planes.


```c
    PLANEPTR AllocRaster( unsigned long width, unsigned long height );
```
The [example](../Libraries_Manual_guide/node05BD.html) listed in the next section shows how to allocate a [BitMap](../Libraries_Manual_guide/node00F1.html#line4)
structure, initialize it with [InitBitMap()](../Libraries_Manual_guide/node032E.html) and use [AllocRaster()](../Libraries_Manual_guide/node032E.html) function
to set up memory for the bitplanes.

 [Graphics and Layers Functions for SuperBitMap Windows](../Libraries_Manual_guide/node0120.html) 
 [SuperBitMap Window Example](../Libraries_Manual_guide/node05BD.html) 

