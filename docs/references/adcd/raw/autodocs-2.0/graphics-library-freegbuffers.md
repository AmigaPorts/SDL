# graphics.library/FreeGBuffers



NAME

    FreeGBuffers -- Deallocate memory obtained by GetGBufers.
SYNOPSIS

```c
    FreeGBuffers(anOb, rp, db)
                 A0    A1  D0

    void FreeGBuffers(struct [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, BOOL);
```
FUNCTION

```c
    For each sequence of each component of the [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204),
    deallocate memory for:
        SaveBuffer
        BorderLine
        CollMask and ImageShadow (point to same buffer)
        if db is set (user had used double-buffering) deallocate:
            [DBufPacket](../Includes_and_Autodocs_2._guide/node00C3.html#line234)
            BufBuffer
```
INPUTS

```c
    anOb = pointer to the [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) structure
    rp   = pointer to the current [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    db   = double-buffer indicator (set TRUE for double-buffering)
```
RESULT

BUGS

SEE ALSO

```c
    [GetGBuffers()](../Includes_and_Autodocs_2._guide/node0447.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
