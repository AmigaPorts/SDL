# graphics.library/FreeRaster



NAME


    FreeRaster -- Release an allocated area to the system free memory pool.
SYNOPSIS

```c
    FreeRaster( p, width, height)
               a0   d0:16  d1:16

    void FreeRaster( PLANEPTR, USHORT, USHORT);
```
FUNCTION

    Return the memory associated with this PLANEPTR of size
    width and height to the MEMF_CHIP memory pool.
INPUTS

```c
    p  =  a pointer to a memory space  returned  as  a
          result of a call to [AllocRaster](../Includes_and_Autodocs_2._guide/node0412.html).

    width - the width in bits of the bitplane.
    height - number of rows in bitplane.
```
BUGS

NOTES

```c
    Width and height should be the same values with which you
    called [AllocRaster](../Includes_and_Autodocs_2._guide/node0412.html) in the first place.
```
SEE ALSO

```c
    [AllocRaster()](../Includes_and_Autodocs_2._guide/node0412.html) [graphics/gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html)
```
