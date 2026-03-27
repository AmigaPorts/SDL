/* Source: ADCD 2.1
 * Section: intuition-library-unlockpubscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-unlockpubscreen.md
 */

    Name = pointer to name of public screen.  If Name is NULL,
        then argument 'Screen' is used as a direct pointer to
        a public screen.
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = pointer to a public screen.  Used only if Name
        is NULL.  This pointer MUST have been returned
        by [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).
        It is safe to call UnlockPubScreen() with NULL Name
        and [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) (the function will have no effect).
