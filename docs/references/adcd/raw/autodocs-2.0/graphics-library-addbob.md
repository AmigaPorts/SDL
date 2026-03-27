# graphics.library/AddBob



NAME

```c
    AddBob -- Adds a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) to current gel list.
```
SYNOPSIS

```c
    AddBob(Bob, rp)
           A0   A1

    void AddBob(struct [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Sets up the system [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) flags, then links this gel into the list
    via [AddVSprite](../Includes_and_Autodocs_2._guide/node0411.html).
```
INPUTS

```c
    [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) = pointer to the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) structure to be added to the gel list
    rp  = pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [AddVSprite()](../Includes_and_Autodocs_2._guide/node0411.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
