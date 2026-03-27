/* Source: ADCD 2.1
 * Section: intuition-library-openwindow
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openwindow.md
 */

    Opens an Intuition window of the given dimensions and position,
    with the properties specified in the [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) structure.
    Allocates everything you need to get going.

    New for V36: there is an extensive discussion of public Screens
    and visitor windows at the end of this section.  Also,
    you can provide extensions to the [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) parameters using
    and array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures.  See the discussion below,
    and the documentation for the function [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html).

    Before you call OpenWindow(), you must initialize an instance of
    a [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) structure.  [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) is a structure that contains
    all of the arguments needed to open a window.  The [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976)
    structure may be discarded immediately after it is used to open
    the window.

    If Type == CUSTOMSCREEN, you must have opened your own screen
    already via a call to [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html).  Then Intuition uses your screen
    argument for the pertinent information needed to get your window
    going.  On the other hand, if type == one of the Intuition's standard
    screens, your screen argument is ignored.  Instead,
    Intuition will check to see whether or not that screen
    already exists:  if it doesn't, it will be opened first before
    Intuition opens your window in the standard screen.

    New for V36: If you specify Type == WBENCHSCREEN, then your
    window will appear on the Workbench screen, unless the global
    public screen mode SHANGHAI is set, in which case your window
    will be "hijacked" to the default public screen.  See also
    [SetPubScreenModes()](../Includes_and_Autodocs_2._guide/node0257.html).

    New for V36: If the WFLG_NW_EXTENDED flag is set, it means that the
    field 'ExtNewWindow->Extension' points to an array of TagItems, as
    defined in intuition/tagitem.h.  This provides an extensible means
    of providing extra parameters to OpenWindow.  For compatibility
    reasons, we could not add the 'Extension' field to the [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976)
    structure, so we have define a new structure [ExtNewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line1046), which
    is identical to [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) with the addition of the Extension field.

    We recommend that rather than using ExtNewWindow.Extension, you
    use the new Intuition function [OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html) and its
    varargs equivalent OpenWindowTags().  We document the window
    attribute tag ID's (ti_Tag values) here, rather than in
    [OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html), so that you can find all the parameters
    for a new window defined in one place.

    If the WFLG_SUPER_BITMAP flag is set, the bitmap variable must point
    to your own bitmap.

    The DetailPen and the BlockPen are used for system rendering; for
    instance, the title bar is first filled using the BlockPen, and then
    the gadgets and text are rendered using DetailPen.  You can either
    choose to supply special pens for your window, or, by setting either
    of these arguments to -1, the screen's pens will be used instead.

    Note for V36: The DetailPen and BlockPen no longer determine
    what colors will be used for window borders, if your window
    opens on a "full-blown new look screen."
