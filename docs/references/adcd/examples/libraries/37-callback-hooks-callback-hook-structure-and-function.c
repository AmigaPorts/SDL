/* Source: ADCD 2.1
 * Section: 37-callback-hooks-callback-hook-structure-and-function
 * Library: libraries
 * ADCD reference: libraries/37-callback-hooks-callback-hook-structure-and-function.md
 */

    struct Hook
    {
        struct MinNode h_MinNode;
        ULONG (*h_Entry)();     /* stub function entry point */
        ULONG (*h_SubEntry)();  /* the custom function entry point */
        VOID *h_Data;           /* owner specific */
    };
