/* Source: ADCD 2.1
 * Section: 28-using-bobs-using-bob-flags
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-using-bob-flags.md
 */

    This is a system status flag that indicates to the system whether or
    not this Bob has already been drawn.  Therefore, in the process of
    examining the various [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html) flags, the drawing routines
    can determine the drawing sequence.  The system clears this flag on
    return from each call to [DrawGList()](../Libraries_Manual_guide/node038C.html).
