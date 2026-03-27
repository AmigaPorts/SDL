# graphics.library/FreeColorMap



   NAME
```c
       FreeColorMap -- Free the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) structure and return memory
```
						to free memory pool.

   SYNOPSIS

```c
       FreeColorMap( colormap )
                       a0
```
	void FreeColorMap(struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *);

   FUNCTION
	Return the memory to the free memory pool that was allocated
	with [GetColorMap](../Includes_and_Autodocs_3._guide/node02E3.html).

   INPUTS
	colormap - pointer to [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) allocated with [GetColorMap](../Includes_and_Autodocs_3._guide/node02E3.html).

		  Passing a NULL pointer (meaning "do nothing") is
		  acceptable (V39).

   RESULT
	The space is made available for others to use.

   BUGS

   SEE ALSO

```c
       [SetRGB4()](../Includes_and_Autodocs_3._guide/node032A.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
