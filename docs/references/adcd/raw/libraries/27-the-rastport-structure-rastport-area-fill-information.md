# 27 / / The RastPort Structure / RastPort Area-fill Information


Two structures in the [RastPort](../Libraries_Manual_guide/node034A.html) -- [AreaInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line22) and [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33) -- define certain
information for area filling operations.  The AreaInfo pointer is
initialized by a call to the routine [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html).


```c
    #define AREA_SIZE 200

    register USHORT i;
    WORD areaBuffer[AREA_SIZE];
    struct AreaInfo areaInfo = {0};

    /*  Clear areaBuffer before calling InitArea().  */
    for (i=0; i<AREA_SIZE; i++)
        areaBuffer[i] = 0;

    InitArea(&areaInfo, areaBuffer, (AREA_SIZE*2)/5);
```
The area buffer must start on a word boundary.  That is why the sample
declaration shows areaBuffer as composed of unsigned words (200), rather
than unsigned bytes (400).  It still reserves the same amount of space,
but aligns the data space correctly.

To use area fill, you must first provide a work space in memory for the
system to store the list of points that define your area. You must allow a
storage space of 5 bytes per vertex.  To create the areas in the work
space, you use the functions [AreaMove()](../Libraries_Manual_guide/node035C.html#line4), [AreaDraw()](../Libraries_Manual_guide/node035C.html#line12), and [AreaEnd()](../Libraries_Manual_guide/node035C.html#line26).

Typically, you prepare the [RastPort](../Libraries_Manual_guide/node034A.html) for area-filling by following the
steps in the code fragment above and then linking your [AreaInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line22) into the
RastPort like so:


```c
    rastPort->AreaInfo = &areaInfo;
```
In addition to the [AreaInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line22) structure in the [RastPort](../Libraries_Manual_guide/node034A.html), you must also
provide the system with some work space to build the object whose vertices
you are going to define.  This requires that you initialize a [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33)
structure, then point to that structure for your RastPort to use. First
the TmpRas structure is initialized (via [InitTmpRas()](../Includes_and_Autodocs_2._guide/node0455.html)) then it is linked
into the RastPort structure.


```c
    Allocate Enough Space.
    ----------------------
    The area to which [TmpRas.RasPtr](../Includes_and_Autodocs_2._guide/node00AF.html#line33) points must be at least as large
    as the area (width times height) of the largest rectangular region
    you plan to fill. Typically, you allocate a space as large as a
    single bitplane (usually 320 by 200 bits for Lores mode, 640 by 200
    for Hires, and 1280 by 200 for SuperHires).
```
When you use functions that dynamically allocate memory from the system,
you must remember to return these memory blocks to the system before your
program exits.  See the description of [FreeRaster()](../Includes_and_Autodocs_2._guide/node0442.html) in the Amiga ROM
Kernel Reference Manual: Includes and Autodocs.

