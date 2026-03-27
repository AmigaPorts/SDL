/* Source: ADCD 2.1
 * Section: intuition-library-windowlimits
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-windowlimits.md
 */

    Sets the minimum and maximum limits of the window's size.  Until this
    routine is called, the window's size limits are equal to the initial
    values established in the [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) function.

    After a call to this routine, the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) will be able to be sized
    to any dimensions within the specified limits.

    If you don't want to change any one of the dimensions, set the limit
    argument for that dimension to zero.  If any of the limit arguments
    is equal to zero, that argument is ignored and the initial setting
    of that parameter remains undisturbed.

    If any of the arguments is out of range (minimums greater than the
    current size, maximums less than the current size), that limit
    will be ignored, though the others will still take effect if they
    are in range.  If any are out of range, the return value from this
    procedure will be FALSE.  If all arguments are valid, the return
    value will be TRUE.

    If you want your window to be able to become "as large as possible"
    you may put -1 (i.e. ~0) in either or both Max arguments.  But
    please note: screen sizes may vary for several reasons, and you
    must be able to handle any possible size of window you might end
    up with if you use this method.  Note that you can use the function
    [GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html) to find out how big the screen your window appears in
    is.  That function is particularly useful if your window is in
    the Workbench screen.  You may also refer to the WScreen field
    in your window structure, providing that your window remains open,
    which will ensure that the screen remains open, and thus the
    pointer remains valid.

    If the user is currently sizing this window, the new limits will
    not take effect until after the sizing is completed.
