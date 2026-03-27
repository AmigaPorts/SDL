# graphics.library/SetCollision



NAME

    SetCollision -- Set a pointer to a user collision routine.
SYNOPSIS

```c
    SetCollision(num, routine, GInfo)
                 D0   A0       A1

    void SetCollision(ULONG, VOID (*)(), struct [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40) *);
```
FUNCTION

```c
    Sets a specified entry (num) in the user's collision vectors table
    equal to the address of the specified collision routine.
```
INPUTS

```c
    num     = collision vector number
    routine = pointer to the user's collision routine
    GInfo   = pointer to a [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
