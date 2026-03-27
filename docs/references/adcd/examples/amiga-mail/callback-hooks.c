/* Source: ADCD 2.1
 * Section: callback-hooks
 * Library: amiga-mail
 * ADCD reference: amiga-mail/callback-hooks.md
 */

    /* new standard hook structure */
    struct Hook
    {
        struct MinNode  h_MinNode;
        ULONG       (*h_Entry)();   /* stub function entry point */
        ULONG       (*h_SubEntry)();/* the custom function entry point */
        VOID        *h_Data;        /* owner specific */
    };
