/* Source: ADCD 2.1
 * Section: intuition-library-closescreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-closescreen.md
 */

    Unlinks the screen, unlinks the viewport, deallocates everything that
    Intuition allocated when the screen was opened (using [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html)).
    Doesn't care whether or not there are still any windows attached to the
    screen.  Doesn't try to close any attached windows; in fact, ignores
    them altogether (but see below for changes in V36).

    If this is the last screen to go, attempts to reopen Workbench.

    New for V36: this function will refuse to close the screen
    if there are windows open on the screen when CloseScreen() is
    called.  This avoids the almost certain crash when a screen
    is closed out from under a window.
