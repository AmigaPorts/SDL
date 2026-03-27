/* Source: ADCD 2.1
 * Section: 35-math-libraries-ffp-mathematics-conversion-library
 * Library: libraries
 * ADCD reference: libraries/35-math-libraries-ffp-mathematics-conversion-library.md
 */

    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    if (MathBase = OpenLibrary("mathffp.library", 33))
        {
               . . .

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
