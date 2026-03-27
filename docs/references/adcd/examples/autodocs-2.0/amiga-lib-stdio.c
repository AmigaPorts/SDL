/* Source: ADCD 2.1
 * Section: amiga-lib-stdio
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-stdio.md
 */

    These functions work much like the standard C functions of the same
    names. The file I/O functions all use non-buffered AmigaDOS
    files, and must not be mixed with the file I/O of any C
    compiler. The names of these functions match those found in many
    standard C libraries, when a name conflict occurs, the function is
    generally taken from the FIRST library that was specified on the
    linker's command line.  Thus to use these functions, specify
    the amiga.lib library first.

    To get a suitable AmigaDOS [FileHandle](../Includes_and_Autodocs_2._guide/node0078.html#line90), the [dos.library/Open()](../Includes_and_Autodocs_2._guide/node02D6.html) or
    [dos.library/Output()](../Includes_and_Autodocs_2._guide/node02D8.html) functions must be used.

    All of the functions that write to stdout expect an appropriate
    [FileHandle](../Includes_and_Autodocs_2._guide/node0078.html#line90) to have been set up ahead of time. Depending on
    your C compiler and options, this may have been done by the
    startup code.  Or it can be done manually

    From C:
            extern ULONG stdout;
            /* Remove the extern if startup code did not define stdout */
            stdout=Output();

    From assembly:
            XDEF    _stdout
            DC.L    _stdout ;<- Place result of [dos.library/Output()](../Includes_and_Autodocs_2._guide/node02D8.html) here.
