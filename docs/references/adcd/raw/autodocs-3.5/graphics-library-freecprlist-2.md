# graphics.library/FreeCprList



   NAME

       FreeCprList -- deallocate hardware copper list
   SYNOPSIS
```c
       FreeCprList(cprlist)
```
		      a0

	void FreeCprList(struct [cprlist](../Includes_and_Autodocs_3._guide/node05F3.html#line54) *);

   FUNCTION

```c
       return [cprlist](../Includes_and_Autodocs_3._guide/node05F3.html#line54) to free memory pool
```
   INPUTS

```c
       [cprlist](../Includes_and_Autodocs_3._guide/node05F3.html#line54) - pointer to [cprlist](../Includes_and_Autodocs_3._guide/node05F3.html#line54) structure
```
   RESULTS
	memory returned and made available to other tasks

   BUGS

   SEE ALSO
	[graphics/copper.h](../Includes_and_Autodocs_3._guide/node05F3.html)

