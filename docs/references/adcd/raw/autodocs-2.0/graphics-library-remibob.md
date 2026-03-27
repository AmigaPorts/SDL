# graphics.library/RemIBob



NAME

```c
    RemIBob -- Immediately remove a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) from the gel list and the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    RemIBob(bob, rp, vp)
            A0   A1  A2

    void RemIBob(struct [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *);
```
FUNCTION

```c
    Removes a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) immediately by uncoupling it from the gel list and
    erases it from the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
INPUTS

```c
    bob = pointer to the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) to be removed
    rp  = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) if the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) is to be erased
    vp  = pointer to the [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) for beam-synchronizing
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [RemVSprite()](../Includes_and_Autodocs_2._guide/node0471.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
