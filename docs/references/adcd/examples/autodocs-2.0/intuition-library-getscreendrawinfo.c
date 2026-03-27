/* Source: ADCD 2.1
 * Section: intuition-library-getscreendrawinfo
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-getscreendrawinfo.md
 */

    Some information in the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure may in the future
    be calculated the first time this function is called for a
    particular screen.

    You must call [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html) when you are done using the
    returned pointer.

    This function does not prevent a screen from closing.  Apply it
    only to the screens you opened yourself, or apply a protocol
    such as [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).

    WARNING: Until further notice, the pointer returned does not
    remain valid after the screen is closed.

    This function and [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html) don't really do much now,
    but they provide an upward compatibility path.  That means that
    if you misuse them today, they probably won't cause a problem,
    although they may someday later.  So, please be very careful
    only to use the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure between calls to
    GetScreenDrawInfo() and [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html), and be sure
    that you don't forget [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html).
