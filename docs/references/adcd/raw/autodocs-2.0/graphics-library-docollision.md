# graphics.library/DoCollision



NAME

    DoCollision -- Test every gel in gel list for collisions.
SYNOPSIS

```c
    DoCollision(rp)
                A1

    void DoCollision(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Tests each gel in gel list for boundary and gel-to-gel collisions.
    On detecting one of these collisions, the appropriate collision-
    handling routine is called. See the documentation for a thorough
    description of which collision routine is called. This routine
    expects to find the gel list correctly sorted in Y,X order.
    The system routine [SortGList](../Includes_and_Autodocs_2._guide/node047F.html) performs this function for the user.
```
INPUTS

```c
    rp = pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [SortGList()](../Includes_and_Autodocs_2._guide/node047F.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
