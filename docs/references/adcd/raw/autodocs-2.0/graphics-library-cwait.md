# graphics.library/CWAIT



NAME

    CWAIT -- Append copper wait instruction to user copper list.
SYNOPSIS

```c
    CWAIT( c , v , h )

    CWait( c , v , h )
           a1  d0  d1
    CBump( c )
          a1

    void CWait( struct [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) *, WORD, WORD)
```
FUNCTION

    Add instruction to wait for vertical beam position v and
    horizontal position h to this intermediate copper list.
INPUTS

```c
    c - pointer to [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure
    v - vertical beam position (relative to top of viewport)
    h - horizontal beam position
```
RESULTS

```c
    this is actually a macro that calls CWait(c,v,h)
    and then calls CBump(c) to bump the local pointer
    to the next instruction.
```
BUGS

    User waiting for horizontal values of greater than 222 decimal
    is illegal.
SEE ALSO

```c
    [CINIT](../Includes_and_Autodocs_2._guide/node0428.html) [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) [CEND](../Includes_and_Autodocs_2._guide/node0426.html) [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
