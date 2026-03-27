# graphics.library/SetRast



   NAME

       SetRast - Set an entire drawing area to a specified color.
   SYNOPSIS

```c
       SetRast( rp, pen )
                a1  d0
```
	void SetRast( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION

```c
       Set the entire contents of the specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to the
       specified pen.
```
   INPUTS

```c
       rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
       pen - the pen number (0-255) to jam into bitmap
```
   RESULT
       All pixels within the drawing area are set to the
	selected pen number.

   BUGS

   SEE ALSO
	[RectFill()](../Includes_and_Autodocs_3._guide/node0313.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

