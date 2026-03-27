/* Source: ADCD 2.1
 * Section: amiga-lib-printf
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-printf.md
 */

    The global "_stdout" must be defined, and contain a pointer to
    a legal AmigaDOS file handle. Using the standard Amiga startup
    module sets this up. In other cases you will need to define
    stdout, and assign it to some reasonable value (like what the
    [dos.library/Output()](../Includes_and_Autodocs_2._guide/node02D8.html) call returns). This code would set it up:

            ULONG stdout;
            stdout=Output();
