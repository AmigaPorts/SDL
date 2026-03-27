# 30 / / / Allocating and Deallocating Layer_Info


Use [NewLayerInfo()](../Includes_and_Autodocs_2._guide/node03A1.html) to allocate and initialize a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure and
associated sub-structures.


```c
    struct Layer_Info *NewLayerInfo( void );
```
You must call this function before attempting to use any of the other
layers functions described below.  When you have finished with a
[Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure, use [DisposeLayerInfo()](../Includes_and_Autodocs_2._guide/node0395.html) to deallocate it.


```c
    void DisposeLayerInfo( struct Layer_Info *li );
```
This function deallocates a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) and associated structures
previously allocated with [NewLayerInfo()](../Includes_and_Autodocs_2._guide/node03A1.html).

