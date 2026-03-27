/* Source: ADCD 2.1
 * Section: 35-math-libraries-ffp-transcendental-mathematics-library
 * Library: libraries
 * ADCD reference: libraries/35-math-libraries-ffp-transcendental-mathematics-library.md
 */

    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>
    #include <clib/mathtrans_protos.h>

    struct Library *MathTransBase;

    VOID main()
    {
    if (MathTransBase = OpenLibrary("mathtrans.library",0))
        {
                .
                .
                .
        CloseLibrary(MathTransBase);
        }
    else
        printf("Can't open mathtrans.library\n");
    }
