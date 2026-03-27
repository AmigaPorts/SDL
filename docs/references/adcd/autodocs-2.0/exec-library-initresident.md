---
title: exec.library/InitResident
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-initresident
functions: [InitResident]
libraries: [exec.library]
---

# exec.library/InitResident

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    InitResident - initialize resident module
SYNOPSIS

```c
    object = InitResident(resident, segList)
    D0                     A1        D1

    APTR InitResident(struct [Resident](autodocs-2.0/includes-exec-resident-h.md) *,ULONG);
```
FUNCTION

```c
    Initialize a ROMTag.  ROMTags are used to link system modules
    together.  Each disk based device or library must contain a
    ROMTag structure in the first code hunk.

    Once the validity of the ROMTag is verified, the RT_INIT pointer
    is jumped to  with the following registers:
            D0 = 0
            A0 = segList
            A6 = [ExecBase](autodocs-2.0/includes-exec-execbase-h.md)
```
INPUTS

    resident - Pointer to a ROMTag
    segList  - SegList of the loaded object, if loaded from disk.
               Libraries & Devices will cache this value for later
               return at close or expunge time.  Pass NULL for ROM
               modules.
RESULTS

    object  - Return value from the init code, usually the library
              or device base.  NULL for failure.
AUTOINIT FEATURE

```c
    An automatic method of library/device base and vector table
    initialization is also provided by InitResident().  The initial code
    hunk of the library or device should contain "MOVEQ #-1,d0; RTS;".
    Following that must be an initialized [Resident](autodocs-2.0/includes-exec-resident-h.md) structure with
    RTF_AUTOINIT set in rt_Flags, and an rt_Init pointer which points
    to four longwords.  These four longwords will be used in a call
    to MakeLibrary();

        - The size of your library/device base structure including initial
          [Library](autodocs-2.0/includes-exec-libraries-h.md) or [Device](autodocs-2.0/includes-exec-devices-h.md) structure.

        - A pointer to a longword table of standard, then library
          specific function offsets, terminated with -1L.
          (short format offsets are also acceptable)

        - Pointer to data table in [exec/InitStruct](autodocs-2.0/exec-library-initstruct.md) format for
          initialization of [Library](autodocs-2.0/includes-exec-libraries-h.md) or [Device](autodocs-2.0/includes-exec-devices-h.md) structure.

        - Pointer to library initialization function, or NULL.
            Calling sequence:
                    D0 = library base
                    A0 = segList
                    A6 = [ExecBase](autodocs-2.0/includes-exec-execbase-h.md)
          This function must return in D0 the library/device base to be
          linked into the library/device list.  If the initialization
          function fails, the device memory must be manually deallocated,
          then NULL returned in D0.
```
SEE ALSO

```c
    exec/resident.i, [FindResident](autodocs-2.0/exec-library-findresident.md)
```

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
