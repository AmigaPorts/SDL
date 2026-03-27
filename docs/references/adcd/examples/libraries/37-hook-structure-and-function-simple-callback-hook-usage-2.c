/* Source: ADCD 2.1
 * Section: 37-hook-structure-and-function-simple-callback-hook-usage
 * Library: libraries
 * ADCD reference: libraries/37-hook-structure-and-function-simple-callback-hook-usage.md
 */

    #include <exec/types.h>
    #include <utility/hooks.h>

    #define     ASM     __asm
    #define     REG(x)  register __ ## x

    /* This function converts register-parameter hook calling
     * convention into standard C conventions.  It requires a C
     * compiler that supports registerized parameters, such as
     * SAS/C 5.xx or greater.
     */
    ULONG ASM
    hookEntry(REG(a0) struct Hook *h, REG(a2) VOID *o, REG(a1) VOID *msg)
    {
        return ((*h->h_SubEntry)(h, o, msg));
    }
