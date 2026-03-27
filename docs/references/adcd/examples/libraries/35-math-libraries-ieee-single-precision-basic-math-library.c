/* Source: ADCD 2.1
 * Section: 35-math-libraries-ieee-single-precision-basic-math-library
 * Library: libraries
 * ADCD reference: libraries/35-math-libraries-ieee-single-precision-basic-math-library.md
 */

    #include <exec/types.h>
    #include <libraries/mathieeesp.h>

    #include <clib/mathsingbas_protos.h>

    struct Library *MathIeeeSingBasBase;

    VOID main()
    {
        /* do not share base pointer between tasks. */
    if (MathIeeeSingBasBase = OpenLibrary("mathieeesingbas.library", 37))
        {
               .
               .
               .
        CloseLibrary(MathIeeeSingBasBase);
        }
    else
        printf("Can't open mathieeesingbas.library\n");
    }
