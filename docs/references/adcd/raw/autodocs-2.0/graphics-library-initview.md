# graphics.library/InitView



NAME
InitView - Initialize [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure.

SYNOPSIS

```c
    InitView( view )
               a1

    void InitView( struct [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) * );
```
FUNCTION

```c
    Initialize [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure to default values.
```
INPUTS

```c
    view - pointer to a [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure
```
RESULT

```c
    [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure set to all 0's. (1.0,1.1.1.2)
    Then values are put in DxOffset,DyOffset to properly position
    default display about .5 inches from top and left on monitor.
    InitView pays no attention to previous contents of view.
```
BUGS

SEE ALSO

```c
    [MakeVPort](../Includes_and_Autodocs_2._guide/node045B.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
