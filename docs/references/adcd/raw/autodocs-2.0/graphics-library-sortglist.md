# graphics.library/SortGList



NAME

    SortGList -- Sort the current gel list, ordering its y,x coordinates.
SYNOPSIS

```c
    SortGList(rp)
              A1

    void SortGList(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Sorts the current gel list according to the gels' y,x coordinates.
    This sorting is essential before calls to [DrawGList](../Includes_and_Autodocs_2._guide/node0438.html) or [DoCollision](../Includes_and_Autodocs_2._guide/node0435.html).
```
INPUTS

```c
    rp = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure containing the [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40)
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [DoCollision()](../Includes_and_Autodocs_2._guide/node0435.html)  [DrawGList()](../Includes_and_Autodocs_2._guide/node0438.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
