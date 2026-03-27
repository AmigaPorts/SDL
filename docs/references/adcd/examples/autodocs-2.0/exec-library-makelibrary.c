/* Source: ADCD 2.1
 * Section: exec-library-makelibrary
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-makelibrary.md
 */

    vectors - pointer to an array of function pointers or function
            displacements.  If the first word of the array is -1, then
            the array contains relative word displacements (based off
            of vectors); otherwise, the array contains absolute
            function pointers. The vector list is terminated by a -1
            (of the same size as the pointers).

    structure - points to an "InitStruct" data region.  If NULL,
            then it will not be used.

    init -  If non-NULL, an entry point that will be called before adding
            the library to the system.  Registers are as follows:
                    d0 = libAddr    ;Your [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) Address
                    a0 = segList    ;Your AmigaDOS segment list
                    a6 = [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line35)  ;Address of exec.library
            The result of the init function must be the library address,
            or NULL for failure.   If NULL, the init point must manually
            deallocate the library base memory (based on the sizes stored
            in lib_PosSize and lib_NegSize).

    dSize - the size of the library data area, including the
            standard library node data.  This must be at leas
            sizeof(struct Library).
