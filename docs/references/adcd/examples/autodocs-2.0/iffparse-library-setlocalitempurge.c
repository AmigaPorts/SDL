/* Source: ADCD 2.1
 * Section: iffparse-library-setlocalitempurge
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-setlocalitempurge.md
 */

    Sets a local context item to use a client-supplied cleanup (purge)
    vector for disposal when its context is popped.  The purge vector
    will be called when the [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) containing this local item is
    popped off the context stack and is about to be deleted itself.  If
    the purge vector has not been set, the parser will use [FreeLocalItem](../Includes_and_Autodocs_2._guide/node01C6.html)
    to delete the item, but if this function is used to set the purge
    vector, the supplied vector will be called with the following
    arguments:

            A0:     pointer to purgehook.
            A2:     pointer to [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) to be freed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_PURGELCI.

    The user purge vector is then responsible for calling [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html)
    as part of its own cleanup.  Although the purge vector can return a
    value, it will be ignored -- purge vectors must always work (best to
    return 0, though).
