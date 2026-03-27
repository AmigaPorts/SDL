# graphics.library/InitGels



NAME

```c
    InitGels -- initialize a gel list; must be called before using gels.
```
SYNOPSIS

```c
    InitGels(head, tail, GInfo)
             A0    A1    A2

    void InitGels(struct [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) *, struct [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) *, struct [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40) *);
```
FUNCTION

```c
    Assigns the VSprites as the head and tail of the gel list in [GfxBase](../Includes_and_Autodocs_2._guide/node00AE.html#line24).
    Links these two gels together as the keystones of the list.
    If the collHandler vector points to some memory array, sets
    the BORDERHIT vector to NULL.
```
INPUTS

```c
    head  = pointer to the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) structure to be used as the
            gel list head
    tail  = pointer to the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) structure to be used as the
            gel list tail
    GInfo = pointer to the [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40) structure to be initialized
```
RESULT

BUGS

SEE ALSO

```c
    [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
