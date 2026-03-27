/* Source: ADCD 2.1
 * Section: 5-gadget-structure-gadget-activation-flags
 * Library: libraries
 * ADCD reference: libraries/5-gadget-structure-gadget-activation-flags.md
 */

    This is short for "release verify."  If this bit is set, the program
    will be sent an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message when the gadget is
    deactivated.  IDCMP_GADGETUP will be sent for [boolean](../Libraries_Manual_guide/node014C.html) gadgets when
    the user releases the mouse select button while the pointer is over
    the select box, for [proportional](../Libraries_Manual_guide/node0153.html) gadgets whenever the user releases
    the mouse select button (regardless of the pointer position), and for
    [string](../Libraries_Manual_guide/node0164.html) and [integer](../Libraries_Manual_guide/node0165.html) gadgets when the user completes the text entry by
    pressing return or tabbing to the next gadget (where supported).

    For [boolean](../Libraries_Manual_guide/node014C.html) gadgets, if the user releases the mouse button while the
    pointer is outside of the gadget's select box [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) will not
    be generated.  Instead, the program will receive an
    [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) event with the SELECTUP code set.  For [string](../Libraries_Manual_guide/node0164.html)
    gadgets, if the user deactivates the gadget by clicking elsewhere, it
    may not be possible to detect.
