/* Source: ADCD 2.1
 * Section: 35-math-libraries-ieee-double-precision-basic-math-library
 * Library: libraries
 * ADCD reference: libraries/35-math-libraries-ieee-double-precision-basic-math-library.md
 */

    #include <exec/types.h>
    #include <libraries/mathieeedp.h>

    #include <clib/mathdoubbas_protos.h>

    struct Library *MathIeeeDoubBasBase;

    VOID main()
    {
        /* do not share base pointer between tasks. */
    if (MathIeeeDoubBasBase = OpenLibrary("mathieeedoubbas.library", 34))
        {
               . . .

        CloseLibrary(MathIeeeDoubBasBase);
        }
    else printf("Can't open mathieeedoubbas.library\n");
    }
