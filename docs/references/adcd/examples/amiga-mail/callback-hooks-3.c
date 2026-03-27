/* Source: ADCD 2.1
 * Section: callback-hooks
 * Library: amiga-mail
 * ADCD reference: amiga-mail/callback-hooks.md
 */

    /* This function converts register-parameter hook calling
     * convention into standard C conventions.  It requires a C
     * compiler that supports registerized parameters, such as
     * SAS/C 5.xx or greater.
     */
    ULONG __asm hookEntry(
        register __a0 struct Hook *h,
        register __a2 VOID *o,
        register __a1 VOID *msg)
    {
        return ((*h->h_SubEntry)(h, o, msg));
    }
