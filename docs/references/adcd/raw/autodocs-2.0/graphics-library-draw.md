# graphics.library/Draw



NAME

    Draw -- Draw a line between the current pen position
                   and the new x,y position.
SYNOPSIS

```c
    Draw( rp,   x,     y)
         a1  d0:16  d1:16

    void Draw( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT);
```
FUNCTION

```c
    Draw a line from the current pen position to (x,y).
```
INPUTS


```c
    rp - pointer to the destination [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    x,y - coordinates of where in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to end the line.
```
BUGS

SEE ALSO

```c
    [Move()](../Includes_and_Autodocs_2._guide/node045D.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
