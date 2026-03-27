# graphics.library/InitVPort



NAME

```c
    InitVPort - Initialize [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure.
```
SYNOPSIS

```c
    InitVPort( vp )
               a0

    void InitVPort( struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) * );
```
FUNCTION

```c
    Initialize [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure to default values.
```
INPUTS

```c
    vp - pointer to a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure
```
RESULT

```c
    [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure set to all 0's. (1.0,1.1)
    New field added SpritePriorities, initialized to 0x24 (1.2)
```
BUGS

SEE ALSO

```c
    [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
