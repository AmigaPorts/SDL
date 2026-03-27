# graphics.library/AddVSprite



NAME

```c
    AddVSprite -- Add a [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) to the current gel list.
```
SYNOPSIS

```c
    AddVSprite(vs, rp)
               A0  A1

    void AddVSprite(struct [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Sets up the system [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) flags
    Links this [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) into the current gel list using its Y,X
```
INPUTS

```c
    vs = pointer to the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) structure to be added to the gel list
    rp = pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
