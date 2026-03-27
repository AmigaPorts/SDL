/* Source: ADCD 2.1
 * Section: intuition-library-buildsysrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildsysrequest.md
 */

    This procedure builds a system requester based on the supplied
    information.  If all goes well and the requester is constructed,
    this procedure returns a pointer to the window in which the requester
    appears.  That window will have its IDCMP initialized to reflect the
    flags found in the IDCMPFlags argument.  You may then wait on those
    ports to detect the user's response to your requester, which response
    may include either selecting one of the gadgets or causing some other
    event to be noticed by Intuition (like IDCMP_DISKINSERTED, for
    instance).  After the requester is satisfied, you should call the
    [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html) procedure to remove the requester and free up
    any allocated memory.

    See the autodoc for [SysReqHandler()](../Includes_and_Autodocs_2._guide/node025B.html) for more information on the
    how to handle the IntuiMessages this window will receive.

    The requester used by this function has the NOISYREQ flag bit set,
    which means that the set of IDCMPFlags that may be used here
    include IDCMP_RAWKEY, IDCMP_MOUSEBUTTONS, and others.

    In release previous to V36, if the requester could not be built,
    this function would try to call [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html) with the same
    information, with more or less favorable results.  In V36,
    the requesters themselves require less memory (SIMPLEREQ), but
    there is no alert attempt.

    The function may return TRUE (1) or FALSE if it cannot post
    the requester.  (V36 will always return FALSE, but be sure to
    test for TRUE in case somebody reinstates the fallback alert.)

    If the window argument you supply is equal to NULL, a new window will
    be created for you in the Workbench screen, or the default
    public screen, for V36.  If you want the requester
    created by this routine to be bound to a particular window (i.e.,
    to appear in the same screen as the window), you should
    not supply a window argument of NULL.

    New for V36: if you pass a NULL window pointer, the system requester
    will appear on the default public screen, which is not always
    the Workbench.

    The text arguments are used to construct the display.  Each is a
    pointer to an instance of the structure [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572).

    The BodyText argument should be used to describe the nature of
    the requester.  As usual with [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) data, you may link several
    lines of text together, and the text may be placed in various
    locations in the requester.  This [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) pointer will be stored
    in the ReqText variable of the new requester.

    The PosText argument describes the text that you want associated
    with the user choice of "Yes,  TRUE,  Retry,  Good."  If the requester
    is successfully opened, this text will be rendered in a gadget in
    the lower-left of the requester, which gadget will have the
    GadgetID field set to TRUE.  If the requester cannot be opened and
    the [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html) mechanism is used, this text will be rendered in
    the lower-left corner of the alert display with additional text
    specifying that the left mouse button will select this choice.  This
    pointer can be set to NULL, which specifies that there is no TRUE
    choice that can be made.

    The NegText argument describes the text that you want associated
    with the user choice of "No,  FALSE,  Cancel,  Bad."  If the requester
    is successfully opened, this text will be rendered in a gadget in
    the lower-right of the requester, which gadget will have the
    GadgetID field set to FALSE.  If the requester cannot be opened and
    the [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html) mechanism is used, this text will be rendered in
    the lower-right corner of the alert display with additional text
    specifying that the right mouse button will select this choice.  This
    pointer cannot be set to NULL.  There must always be a way for the
    user to cancel this requester.

    The Positive and Negative Gadgets created by this routine have
    the following features:
      - GTYP_BOOLGADGET
      - GACT_RELVERIFY
      - GTYP_REQGADGET
      - GACT_TOGGLESELECT

    When defining the text for your gadgets, you may find it convenient
    to use the special constants used by Intuition for the construction
    of the gadgets.  These include defines like AUTODRAWMODE, AUTOLEFTEDGE,
    AUTOTOPEDGE and AUTOFRONTPEN.  You can find these in your local
    intuition.h (or intuition.i) file.

    These hard-coded constants are not very resolution or font
    sensitive, but V36 will override them to provide more modern
    layout.

    New for V36, linked lists of [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) are not correctly supported
    for gadget labels.

    The width and height values describe the size of the requester.  All
    of your BodyText must fit within the width and height of your
    requester.  The gadgets will be created to conform to your sizes.

    VERY IMPORTANT NOTE:  for this release of this procedure, a new window
    is opened in the same screen as the one containing your window.
    Future alternatives may be provided as a function distinct from this
    one.

    NOTE: This function will pop the screen the requester and its
    window appears in to the front of all screens.  New for V36,
    if the user doesn't perform any other screen arrangement before
    finishing with the requester, a popped screen will be pushed
    back behind.
