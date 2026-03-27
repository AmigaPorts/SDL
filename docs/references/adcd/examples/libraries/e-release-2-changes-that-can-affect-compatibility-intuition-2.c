/* Source: ADCD 2.1
 * Section: e-release-2-changes-that-can-affect-compatibility-intuition
 * Library: libraries
 * ADCD reference: libraries/e-release-2-changes-that-can-affect-compatibility-intuition.md
 */

    the border dimensions are unchanged from 1.x (Look at
    [Window->BorderLeft/Top/Right/Bottom](../Libraries_Manual_guide/node0121.html#line71) if you don't believe us!).  If
    your gadget intersects the border area, although it may have looked
    OK under 1.3, a visual conflict may occur under 2.0.  If Intuition
    notices a gadget which is substantially in the border but not
    declared as such, it treats it as though it were (this is called
    "bordersniffing").  Never rely on Intuition to sniff these out for
    you; always declare them explicitly (see the Gadget Activation flags
    [GACT_RIGHTBORDER](../Libraries_Manual_guide/node014B.html#line56), etc.).  See "[Intuition Gadgets and Window Borders](../Libraries_Manual_guide/node0575.html)"
    in the "Additional Information" section below.
