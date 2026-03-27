/* Source: ADCD 2.1
 * Section: 35-ffp-basic-mathematics-library-ffp-basic-functions
 * Library: libraries
 * ADCD reference: libraries/35-ffp-basic-mathematics-library-ffp-basic-functions.md
 */

    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    FLOAT f1, f2, f3;
    LONG   i1;

    if (MathBase = OpenLibrary("mathffp.library", 0))
        {
        i1 = SPFix(f1);            /* Call SPFix entry */
        f1 = SPFlt(i1);            /* Call SPFlt entry */

        if (SPCmp(f1,f2)) {};      /* Call SPCmp entry */
        if (!(SPTst(f1))) {};      /* Call SPTst entry */

        f1 = SPAbs(f2);            /* Call SPAbs entry */
        f1 = SPNeg(f2);            /* Call SPNeg entry */
        f1 = SPAdd(f2, f3);        /* Call SPAdd entry */
        f1 = SPSub(f2, f3);        /* Call SPSub entry */
        f1 = SPMul(f2, f3);        /* Call SPMul entry */
        f1 = SPDiv(f2, f3);        /* Call SPDiv entry */
        f1 = SPCeil(f2);           /* Call SPCeil entry */
        f1 = SPFloor(f2);          /* Call SPFloor entry */

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
