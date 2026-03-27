/* Source: ADCD 2.1
 * Section: intuition-library-openscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openscreen.md
 */

    Opens an Intuition screen according to the specified parameters
    found in the [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure.

    Does all the allocations, sets up the screen structure and all
    substructures completely, and links this screen's viewport into
    Intuition's [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure.

    Before you call OpenScreen(), you must initialize an instance of
    a [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure.  [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) is a structure that contains
    all of the arguments needed to open a screen.  The [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309)
    structure may be discarded immediately after OpenScreen() returns.

    The SHOWTITLE flag is set to TRUE by default when a screen is opened.
    To change this, you must call the routine [ShowTitle()](../Includes_and_Autodocs_2._guide/node0259.html).
