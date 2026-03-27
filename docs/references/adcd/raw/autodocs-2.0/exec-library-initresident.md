# exec.library/InitResident



NAME

    InitResident - initialize resident module
SYNOPSIS

```c
    object = InitResident(resident, segList)
    D0                     A1        D1

    APTR InitResident(struct [Resident](../Includes_and_Autodocs_2._guide/node00A0.html#line19) *,ULONG);
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
            A6 = [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line35)
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
    Following that must be an initialized [Resident](../Includes_and_Autodocs_2._guide/node00A0.html#line19) structure with
    RTF_AUTOINIT set in rt_Flags, and an rt_Init pointer which points
    to four longwords.  These four longwords will be used in a call
    to MakeLibrary();

        - The size of your library/device base structure including initial
          [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) or [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) structure.

        - A pointer to a longword table of standard, then library
          specific function offsets, terminated with -1L.
          (short format offsets are also acceptable)

        - Pointer to data table in [exec/InitStruct](../Includes_and_Autodocs_2._guide/node035E.html) format for
          initialization of [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) or [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) structure.

        - Pointer to library initialization function, or NULL.
            Calling sequence:
                    D0 = library base
                    A0 = segList
                    A6 = [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line35)
          This function must return in D0 the library/device base to be
          linked into the library/device list.  If the initialization
          function fails, the device memory must be manually deallocated,
          then NULL returned in D0.
```
SEE ALSO

```c
    exec/resident.i, [FindResident](../Includes_and_Autodocs_2._guide/node0350.html)
```
