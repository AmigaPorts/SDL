# graphics.library/Move



NAME

    Move -- Move graphics pen position.
SYNOPSIS

```c
    Move( rp,   x,    y)
          a1  d0:16 d1:16

    void Move( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT );
```
FUNCTION

```c
    Move graphics pen position to (x,y) relative to upper left (0,0)
    of [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). This sets the starting point for subsequent [Draw()](../Includes_and_Autodocs_2._guide/node0436.html)
    and [Text()](../Includes_and_Autodocs_2._guide/node0482.html) calls.
```
INPUTS

```c
    rp - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    x,y - point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULTS

BUGS

SEE ALSO

```c
    Draw [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
