/* Source: ADCD 2.1
 * Section: 1-introduction-to-amiga-system-libraries-about-the-examples
 * Library: libraries
 * ADCD reference: libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md
 */

    /* Add this near the top */
            #include <functions.h>

    /* Add this before main() */
            extern int Enable_Abort;   /* reference abort enable */

    /* Add this after main(), as the first active line in the program */
            Enable_Abort=0;         /* turn off CTRL-C */
