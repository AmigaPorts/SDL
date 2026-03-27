# graphics.library/Draw



   NAME

       Draw -- Draw a line between the current pen position
                       and the new x,y position.
   SYNOPSIS

```c
       Draw( rp,   x,     y)
             a1  d0:16  d1:16
```
	void Draw( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

   FUNCTION

```c
       Draw a line from the current pen position to (x,y).
```
   INPUTS

	rp - pointer to the destination [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	x,y - coordinates of where in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to end the line.

   BUGS

   SEE ALSO
	[Move()](../Includes_and_Autodocs_3._guide/node0301.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

