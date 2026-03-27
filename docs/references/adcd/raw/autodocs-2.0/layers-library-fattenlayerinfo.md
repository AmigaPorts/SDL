# layers.library/FattenLayerInfo



NAME

    FattenLayerInfo -- convert 1.0 LayerInfo to 1.1 LayerInfo
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    FattenLayerInfo( li )
                     a0

    LONG FattenLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    V1.1 software and any later releases need to have more info in the
    [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure. To do this in a 1.0 supportable manner requires
    allocation and deallocation of the memory whenever most
    layer library functions are called.  To prevent unnecessary
    allocation/deallocation FattenLayerInfo will preallocate the
    necessary data structures and fake out the layer library into
    thinking it has a LayerInfo gotten from [NewLayerInfo](../Includes_and_Autodocs_2._guide/node03A1.html).
    [NewLayerInfo](../Includes_and_Autodocs_2._guide/node03A1.html) is the approved method for getting this structure.
    When a program needs to give up the LayerInfo structure it
    must call [ThinLayerInfo](../Includes_and_Autodocs_2._guide/node03A5.html) before freeing the memory. [ThinLayerInfo](../Includes_and_Autodocs_2._guide/node03A5.html)
    is not necessary if [New/DisposeLayerInfo](../Includes_and_Autodocs_2._guide/node0395.html) are used however.
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO


```c
    [NewLayerInfo](../Includes_and_Autodocs_2._guide/node03A1.html), [ThinLayerInfo](../Includes_and_Autodocs_2._guide/node03A5.html), [DisposeLayerInfo](../Includes_and_Autodocs_2._guide/node0395.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
