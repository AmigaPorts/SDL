# graphics.library/CEND



NAME

    CEND -- Terminate user copper list.
SYNOPSIS

```c
    CEND( c )

    struct [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) *c;
```
FUNCTION

    Add instruction to terminate user copper list.
INPUTS

```c
    c - pointer to [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure
```
RESULTS

```c
    This is actually a macro that calls the macro CWAIT(c,10000,255)
    10000 is a magical number that the graphics.library uses.
    I hope display technology doesn't catch up too fast!
```
BUGS

SEE ALSO

```c
    [CINIT](../Includes_and_Autodocs_2._guide/node0428.html) [CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
