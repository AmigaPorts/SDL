# graphics.library/GetGBuffers



NAME

```c
    GetGBuffers -- Attempt to allocate ALL buffers of an entire [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204).
```
SYNOPSIS

```c
    status = GetGBuffers(anOb, rp, db)
    D0                   A0    A1  D0

    BOOL GetGBuffers(struct [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, BOOL);
```
FUNCTION

```c
    For each sequence of each component of the [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204), allocate memory for:
        SaveBuffer
        BorderLine
        CollMask and ImageShadow (point to same buffer)
        if db is set TRUE (user wants double-buffering) allocate:
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

```c
    status = TRUE if the memory allocations were all successful, else FALSE
```
BUGS

    If any of the memory allocations fail it does not free the partial
    allocations that did succeed.
SEE ALSO

```c
    [FreeGBuffers()](../Includes_and_Autodocs_2._guide/node0441.html) [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
