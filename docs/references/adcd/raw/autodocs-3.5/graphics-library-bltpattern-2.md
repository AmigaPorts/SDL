# graphics.library/BltPattern



   NAME
	BltPattern --  Using standard drawing rules for areafill,
					 blit through a mask.

   SYNOPSIS

```c
       BltPattern(rp, mask, xl, yl, maxx, maxy, bytecnt)
                  a1,  a0   d0  d1   d2   d3     d4
```
	void BltPattern
	   (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, void *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), SHORT);

   FUNCTION

```c
       Blit using drawmode,areafill pattern, and mask
       at position rectangle (xl,yl) (maxx,maxy).
```
   INPUTS

```c
       rp    -  points to the destination [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) for the blit.
       mask  -  points to 2 dimensional mask if needed
                if mask == NULL then use a rectangle.
       xl,yl -  coordinates of upper left of rectangular region in [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
       maxx,maxy - points to lower right of rectangular region in [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
       bytecnt - BytesPerRow for mask
```
   RESULT

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html)

