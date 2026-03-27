/* Source: ADCD 2.1
 * Section: amiga-lib-hookentry
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-hookentry.md
 */

    If your hook dispatcher is this:

    dispatch( struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *hookPtr, Object *obj, APTR msg )
    {
        ...
    }

    Then when you initialize your hook, you would say:

    myhook.h_Entry = HookEntry;     /* amiga.lib stub */
    myhook.h_SubEntry = dispatch;   /* HLL entry */
