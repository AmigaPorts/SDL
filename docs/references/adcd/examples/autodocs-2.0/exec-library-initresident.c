/* Source: ADCD 2.1
 * Section: exec-library-initresident
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-initresident.md
 */

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
