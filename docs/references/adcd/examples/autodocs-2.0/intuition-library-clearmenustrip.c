/* Source: ADCD 2.1
 * Section: intuition-library-clearmenustrip
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-clearmenustrip.md
 */

    Detaches the current menu strip from the window; menu strips
    are attached to windows using the [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html) function
    (or, for V36, [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html) ).

    If the menu is in use (for that matter if any menu is in use)
    this function will block (Wait()) until the user has finished.

    Call this function before you make any changes to the data
    in a [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) or [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) structure which is part of a menu
    strip linked into a window.
