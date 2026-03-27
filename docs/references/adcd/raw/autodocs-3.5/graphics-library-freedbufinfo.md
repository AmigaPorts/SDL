# graphics.library/FreeDBufInfo



   NAME

```c
       FreeDBufInfo -- free information for multi-buffered animation (V39)
```
   SYNOPSIS
```c
       FreeDBufInfo(db)
```
	             a1

	void FreeDBufInfo(struct [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) *)

   FUNCTION
	Frees a structure obtained from [AllocDBufInfo](../Includes_and_Autodocs_3._guide/node02A1.html)

   INPUTS

```c
       db  =  A pointer to a [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278).
```
   BUGS

   NOTES
	FreeDBufInfo(NULL) is a no-op.

   SEE ALSO
	[AllocDBufInfo()](../Includes_and_Autodocs_3._guide/node02A1.html) [ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)

