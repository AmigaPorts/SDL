---
title: exec.library/InitResident
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-initresident-2
functions: [FindResident, InitResident]
libraries: [exec.library]
---

# exec.library/InitResident

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitResident - initialize resident module

   SYNOPSIS
	object = InitResident(resident, segList)
	D0	               A1        D1

	[APTR](autodocs-3.5/include-exec-types-h.md) InitResident(struct [Resident](autodocs-3.5/include-exec-resident-h.md) *,ULONG);

   FUNCTION
	Initialize a ROMTag.  ROMTags are used to link system modules
	together.  Each disk based device or library must contain a
	ROMTag structure in the first code hunk.

	Once the validity of the ROMTag is verified, the RT_INIT pointer
	is jumped to  with the following registers:
		D0 = 0
		A0 = segList
	 	A6 = [ExecBase](autodocs-3.5/include-exec-execbase-h.md)

   INPUTS
	resident - Pointer to a ROMTag
	segList  - SegList of the loaded object, if loaded from disk.
		   Libraries & Devices will cache this value for later
		   return at close or expunge time.  Pass NULL for ROM
		   modules.

   RESULTS
	object	- Return value from the init code, usually the library
		  or device base.  NULL for failure.

   AUTOINIT FEATURE
	An automatic method of library/device base and vector table
	initialization is also provided by InitResident().  The initial code
	hunk of the library or device should contain "MOVEQ #-1,d0; RTS;".
	Following that must be an initialized [Resident](autodocs-3.5/include-exec-resident-h.md) structure with
	RTF_AUTOINIT set in rt_Flags, and an rt_Init pointer which points
	to four longwords.  These four longwords will be used in a call
	to MakeLibrary();

	    - The size of your library/device base structure including initial
	      [Library](autodocs-3.5/include-exec-libraries-h.md) or [Device](autodocs-3.5/include-exec-devices-h.md) structure.

	    - A pointer to a longword table of standard, then library
	      specific function offsets, terminated with -1L.
	      (short format offsets are also acceptable)

	    - Pointer to data table in [exec/InitStruct](autodocs-3.5/exec-library-initstruct-2.md) format for
	      initialization of [Library](autodocs-3.5/include-exec-libraries-h.md) or [Device](autodocs-3.5/include-exec-devices-h.md) structure.

	    - Pointer to library initialization function, or NULL.
		Calling sequence:
			D0 = library base
			A0 = segList
			A6 = [ExecBase](autodocs-3.5/include-exec-execbase-h.md)
	      This function must return in D0 the library/device base to be
	      linked into the library/device list.  If the initialization
	      function fails, the device memory must be manually deallocated,
	      then NULL returned in D0.

   SEE ALSO
	exec/resident.i, [FindResident()](autodocs-3.5/exec-library-findresident-2.md)

---

## See Also

- [FindResident — exec.library](../autodocs/exec.library.md#findresident)
- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
