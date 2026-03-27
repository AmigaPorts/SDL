# 4 / Basic Window Structures and Functions / Window Border Dimensions


Intuition automatically draws a border around a window unless directed
otherwise, such as by setting the [WFLG_BORDERLESS](../Libraries_Manual_guide/node0125.html#line68) flag.  [Borderless](../Libraries_Manual_guide/node0115.html)
windows may not have a window title or gadgets in the border (this
includes the standard system gadgets).  Otherwise they won't come out
properly borderless.

The size of the border of an open window is available in the [Window](../Libraries_Manual_guide/node0102.html#line8)
structure variables [BorderLeft, BorderTop, BorderRight and BorderBottom](../Libraries_Manual_guide/node0121.html#line71).
Intuition fills these in when the window is opened.  To calculate the
window border sizes before the window is opened you use information in the
[Screen](../Libraries_Manual_guide/node00DE.html#line6) structure as shown in the next listing.



    Gadgets Can Change Border Sizes.
    --------------------------------
    The following calculations do not take application border gadgets
    into account. If the program adds gadgets into the window's borders,
    Intuition will expand the borders to hold the gadgets.
if (NULL != (screen = LockPubScreen(NULL)))

```c
    {
    top_border    = screen->WBorTop + screen->Font->ta_YSize + 1;
    left_border   = screen->WBorLeft;
    right_border  = screen->WBorRight;
    bottom_border = screen->WBorBottom;

    UnlockPubScreen(NULL,screen);
    }
```
/* if the sizing gadget is specified, then the border size must
** be adjusted for the border containing the gadget.  This may
** be the right border, the bottom border or both.
**
** We are using fixed values.  There is currently no system-approved
** method of finding this information before the window is opened.
** If you need to know these sizes BEFORE your window is opened,
** use the fixed values below.  Otherwise, use Window->BorderRight,
** etc. AFTER you have opened your window.
*/

/* values for non-lo-res screen */
right_border  = 18;  /* if sizing gadget in right border  */
bottom_border = 10;  /* if sizing gadget in bottom border */

/* values for lo-res screen */
right_border  = 13;  /* if sizing gadget in right border  */
bottom_border = 11;  /* if sizing gadget in bottom border */


Use the border sizes to position visual elements within the window.
Coordinates may be offset into the window by the size of the top and left
borders, for instance (x, y) becomes (x + [BorderLeft](../Libraries_Manual_guide/node0121.html#line71), y + [BorderTop](../Libraries_Manual_guide/node0121.html#line71)).
This may look clumsy, but it offers a way of avoiding a [GimmeZeroZero](../Libraries_Manual_guide/node0116.html)
window, which, although much more convenient to use, requires extra memory
and degrades performance.

The right and bottom border values specify the width of these borders.
The area within the borders of a window is defined as ([BorderLeft](../Libraries_Manual_guide/node0121.html#line71),
[BorderTop](../Libraries_Manual_guide/node0121.html#line71)) to ([Width](../Libraries_Manual_guide/node0121.html#line42) - 1 - [BorderRight](../Libraries_Manual_guide/node0121.html#line71), [Height](../Libraries_Manual_guide/node0121.html#line42) - 1 - [BorderBottom](../Libraries_Manual_guide/node0121.html#line71)).  The
calculations subtract one from the height and width of the windows as
positions count from zero, but dimensions count from one.

The window title bar is only available if one or more of the following is
specified:  window title, window drag gadget, window depth gadget, window
close gadget or window zoom gadget.  If none of these are specified, the
top border will be much narrower.

Application gadgets may be added to the window border by setting a flag in
the [Gadget](../Libraries_Manual_guide/node0149.html) structure.  A special flag must additionally be set to place
gadgets into the borders of [GimmeZeroZero](../Libraries_Manual_guide/node0116.html) windows.  See the chapter
"[Intuition Gadgets](../Libraries_Manual_guide/node013D.html)," for more information about gadgets and their
positioning.  ([Borderless](../Libraries_Manual_guide/node0115.html) windows have no visible border outlines and
gadgets should not be placed in their borders.)

