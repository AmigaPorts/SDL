---
title: exec.library/MakeLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-makelibrary-2
functions: [InitResident, InitStruct]
libraries: [exec.library]
---

# exec.library/MakeLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MakeLibrary -- construct a library

   SYNOPSIS
	library = MakeLibrary(vectors, structure, init, dSize, segList)
	D0		      A0       A1	  A2	D0     D1

	struct [Library](autodocs-3.5/include-exec-libraries-h.md) *MakeLibrary
			      (APTR,struct [InitStruct](autodocs-3.5/exec-library-initstruct-2.md) *,[APTR](autodocs-3.5/include-exec-types-h.md),ULONG,BPTR);

   FUNCTION
	This function is used for constructing a library vector and data
	area.  The same call is used to make devices.  Space for the library
	is allocated from the system's free memory pool.  The data portion of
	the library is initialized.  init may point to a library specific
	entry point.

   NOTE
	Starting with V36, the library base is longword adjusted.  The
	lib_PosSize and lib_NegSize fields of the library structure are
	adjusted to match.

   INPUTS
	vectors - pointer to an array of function pointers or function
		displacements.	If the first word of the array is -1, then
		the array contains relative word displacements (based off
		of vectors); otherwise, the array contains absolute
		function pointers. The vector list is terminated by a -1
		(of the same size as the pointers).

	structure - points to an "InitStruct" data region.  If NULL,
		then it will not be used.

	init -	If non-NULL, an entry point that will be called before adding
		the library to the system.  Registers are as follows:
			d0 = libAddr 	;Your [Library](autodocs-3.5/include-exec-libraries-h.md) Address
			a0 = segList	;Your AmigaDOS segment list
			a6 = [ExecBase](autodocs-3.5/include-exec-execbase-h.md)	;Address of exec.library
		The result of the init function must be the library address,
		or NULL for failure.   If NULL, the init point must manually
		deallocate the library base memory (based on the sizes stored
		in lib_PosSize and lib_NegSize).

	dSize - the size of the library data area, including the
		standard library node data.  This must be at leas
		sizeof(struct Library).

```c
       segList - pointer to an AmigaDOS SegList (segment list).
```
		 This is passed to a library's init code, and is used later
		 for removing the library from memory.

   RESULT
	library - the reference address of the library.  This is the
		  address used in references to the library, not the
		  beginning of the memory area allocated.  If the library
		  vector table require more system memory than is
		  available, this function will return NULL.

   SEE ALSO
	[InitStruct()](autodocs-3.5/exec-library-initstruct-2.md), [InitResident()](autodocs-3.5/exec-library-initresident-2.md), exec/initializers.i

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
- [InitStruct — exec.library](../autodocs/exec.library.md#initstruct)
