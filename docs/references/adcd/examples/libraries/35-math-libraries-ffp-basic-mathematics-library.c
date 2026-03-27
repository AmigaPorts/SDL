/* Source: ADCD 2.1
 * Section: 35-math-libraries-ffp-basic-mathematics-library
 * Library: libraries
 * ADCD reference: libraries/35-math-libraries-ffp-basic-mathematics-library.md
 */

    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    if (MathBase = OpenLibrary("mathffp.library", 0))
        {
               . . .

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
