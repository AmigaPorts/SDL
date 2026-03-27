/* Source: ADCD 2.1
 * Section: dos-library-exall
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exall.md
 */

        Contains a pointer to a hook for a routine to decide if the entry
        will be included in the returned list of entries.  The entry is
        filled out first, and then passed to the hook.  If no MatchFunc is
        to be called then this entry should be NULL.  The hook is
        called with the following parameters (as is standard for hooks):

        BOOL = MatchFunc( hookptr, data, typeptr )
                            a0      a1      a2
        (a0 = ptr to hook, a1 = ptr to filled in [ExAllData](../Includes_and_Autodocs_2._guide/node0079.html#line39), a2 = ptr
         to longword of type).

        MatchFunc should return FALSE if the entry is not to be
        accepted, otherwise return TRUE.

    Note that Dos will emulate ExAll() using [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) and [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html)
    if the handler in question doesn't support the ExAll() packet.
