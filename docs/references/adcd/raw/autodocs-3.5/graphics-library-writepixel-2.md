# graphics.library/WritePixel



   NAME

```c
       WritePixel -- Change the pen num of one specific pixel in a
                     specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).
```
   SYNOPSIS

```c
       error = WritePixel(  rp, x,  y)
         d0                 a1 D0  D1
```
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WritePixel( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63) );

   FUNCTION

```c
       Changes the pen number of the selected pixel in the specified
       [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to that currently specified by PenA, the primary
       drawing pen. Obeys minterms in [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).
```
   INPUTS

```c
       rp - a pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
       (x,y) - point within the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) at which the selected
           pixel is located.
```
   RESULT
```c
       error = 0 if pixel succesfully changed
```
	      = -1 if (x,y) is outside the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   BUGS

   SEE ALSO

```c
       [ReadPixel()](../Includes_and_Autodocs_3._guide/node0310.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)
```
