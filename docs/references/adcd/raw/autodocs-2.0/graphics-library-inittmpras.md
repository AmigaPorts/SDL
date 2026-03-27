# graphics.library/InitTmpRas



NAME

    InitTmpRas -- Initialize area of local memory for usage by
                    areafill, floodfill, text.
SYNOPSIS

```c
    InitTmpRas(tmpras, buffer, size)
                a0       a1     d0

    void InitTmpRas( struct [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33) *, void *, ULONG );
```
FUNCTION

```c
    The area of memory pointed to by buffer is set up to be used
    by [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) routines that may need to get some memory for
    intermediate operations in preparation to putting the graphics
    into the final [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47).
    Tmpras is used to control the usage of buffer.
```
INPUTS

```c
    tmpras - pointer to a [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33) structure to be linked into
            a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    buffer - pointer to a contguous piece of chip memory.
    size - size in bytes of buffer
```
RESULT

```c
    makes buffer available for users of [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
BUGS

```c
    Would be nice if RastPorts could share one [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33).
```
SEE ALSO

```c
    [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) [Flood()](../Includes_and_Autodocs_2._guide/node043C.html) [Text()](../Includes_and_Autodocs_2._guide/node0482.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
