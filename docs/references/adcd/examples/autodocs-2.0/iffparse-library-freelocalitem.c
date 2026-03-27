/* Source: ADCD 2.1
 * Section: iffparse-library-freelocalitem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-freelocalitem.md
 */

    Frees the memory for the local context item and any associated user
    memory as allocated with [AllocLocalItem](../Includes_and_Autodocs_2._guide/node01B9.html).  User purge vectors should
    call this function after they have freed any other resources
    associated with this item.

    Note that FreeLocalItem() does NOT call the custom purge vector set
    up through SetLocalItemPurge(); all it does is free the local context
    item.  (This implies that your custom purge vector would want to call
    this to ultimately free the LocalContextItem.)  (This description
    still seems muddy; how to clear it up?)
