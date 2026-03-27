# graphics.library/CMOVE



NAME

    CMOVE -- append copper move instruction to user copper list.
SYNOPSIS

```c
    CMOVE( c , a , v )

    CMove( c , a , v )
          a1  d0  d1
    CBump( c )
          a1

    void CMove( struct [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) *, void *, WORD );
```
FUNCTION

    Add instruction to move value v to hardware register a.
INPUTS

```c
    c - pointer to [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure
    a - hardware register
    v - 16 bit value to be written
```
RESULTS

```c
    This is actually a macro that calls CMove(c,&a,v)
    and then calls CBump(c) to bump the local pointer
    to the next instruction. Watch out for macro side affects.
```
BUGS

SEE ALSO

```c
    [CINIT](../Includes_and_Autodocs_2._guide/node0428.html) [CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) [CEND](../Includes_and_Autodocs_2._guide/node0426.html) [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
