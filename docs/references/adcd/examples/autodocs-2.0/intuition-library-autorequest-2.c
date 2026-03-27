/* Source: ADCD 2.1
 * Section: intuition-library-autorequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-autorequest.md
 */

    This procedure automatically builds a requester for you and then
    waits for a response from the user, or for the system to satisfy your
    request.  If the response is positive, this procedure returns TRUE.
    If the response is negative, this procedure returns FALSE.

    An IDCMPFlag specification is created by bitwise "or'ing" your
    PosFlags, NegFlags, and the IDCMP classes IDCMP_GADGETUP and
    IDCMP_RAWKEY.  You may specify zero flags for either the PosFlags
    or NegFlags arguments.

    The [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) arguments, and the width and height values, are
    passed directly to the [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) procedure along with
    your window pointer and the IDCMP flags.  Please refer to
    [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) for a description of the [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) that you are
    expected to supply when calling this routine.  It's an important
    but long-winded description that need not be duplicated here.

    If the [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) procedure does not return a pointer
    to a window, it will return TRUE or FALSE (not valid structure
    pointers) instead, and these BOOL values will be returned to
    you immediately.

    On the other hand, if a valid window pointer is returned, that
    window will have had its IDCMP ports and flags initialized according
    to your specifications.  AutoRequest() then waits for IDCMP messages
    on the UserPort, which satisfies one of four requirements:
    -   either the message is of a class that matches
        one of your PosFlags arguments (if you've supplied
        any), in which case this routine returns TRUE.  Or
    -   the message class matches one of your NegFlags
        arguments (if you've supplied any), in which case
        this routine returns FALSE.  Or
    -   the IDCMP message is of class IDCMP_GADGETUP, which means that
        one of the two gadgets, as provided with the PosText and NegText
        arguments, was selected by the user.  If the TRUE gadget
        was selected, TRUE is returned.  If the FALSE gadget was
        selected, FALSE is returned.
    -   Lastly, two IDCMP_RAWKEY messages may satisfy the request: those
        for the V and B keys with the left Amiga key depressed.
        These keys, satisfy the gadgets on the left or right side of
        the requester--TRUE or FALSE--, respectively.

        NOTE: For V36, these two keys left-Amiga-B and V are processed
        through the default keymap.

    When the dust has settled, this routine calls [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html) if
    necessary to clean up the requester and any other allocated memory.

    NOTE: For V36, this function now switches the processor stack
    to ensure sufficient stack space for the function to succeed.
