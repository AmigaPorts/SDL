/* Source: ADCD 2.1
 * Section: intuition-library-unlockpubscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-unlockpubscreen.md
 */

    Releases lock gotten by [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).
    It is best to identify the locked public screen by
    the pointer returned from [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).  To do this,
    supply a NULL 'Name' pointer and the screen pointer.

    In rare circumstances where it would be more convenient to pass
    a non-NULL pointer to the public screen name string, the
    'Screen' parameter is ignored.
