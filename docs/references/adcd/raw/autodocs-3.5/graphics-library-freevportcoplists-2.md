# graphics.library/FreeVPortCopLists



   NAME

       FreeVPortCopLists -- deallocate all intermediate copper lists and
       their headers from a viewport
   SYNOPSIS

```c
       FreeVPortCopLists(vp)
                         a0
```
	void FreeVPortCopLists(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION

```c
       Search display, color, sprite, and user copper
       lists and call [FreeMem()](../Includes_and_Autodocs_3._guide/node020E.html) to deallocate them from memory
```
   INPUTS

```c
       vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure
```
   RESULTS
       The memory allocated to the various copper lists will be returned
	to the system's free memory pool, and the following fields in
	the viewport structure will be set to NULL:

		DspIns, Sprins, ClrIns, UCopIns

   BUGS

       none known
   SEE ALSO
	[graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

