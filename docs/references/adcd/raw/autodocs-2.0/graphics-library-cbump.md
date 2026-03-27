# graphics.library/CBump


NAME

```c
    CBump -- increment user copper list pointer (bump to next position
             in list).
```
SYNOPSIS

```c
    CBump( c )
          a1

    void CBump( struct [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) * );
```
FUNCTION

    Increment pointer to space for next instruction in user copper list.
INPUTS

```c
    c - pointer to [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure
```
RESULTS

```c
    User copper list pointer is incremented to next position.
    Pointer is repositioned to next user copperlist instruction block
    if the current block is full.

        Note: CBump is usually invoked for the programmer as part of the
              macro definitions [CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) or [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html).
```
BUGS

SEE ALSO

```c
    [CINIT](../Includes_and_Autodocs_2._guide/node0428.html) [CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) [CEND](../Includes_and_Autodocs_2._guide/node0426.html) [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
