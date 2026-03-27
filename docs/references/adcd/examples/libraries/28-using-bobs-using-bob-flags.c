/* Source: ADCD 2.1
 * Section: 28-using-bobs-using-bob-flags
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-using-bob-flags.md
 */

    This flag is used solely by the system, and should be left alone.
    When a Bob is waiting to be drawn, the system sets the BWAITING flag
    in the [Bob](../Libraries_Manual_guide/node0398.html) structure to 1.  This occurs only if the system has found
    a [Before](../Libraries_Manual_guide/node03A4.html) pointer in this Bob's structure that points to another Bob.
    Thus, the system flag BWAITING provides current draw-status to the
    system.  Currently, the system clears this flag on return from each
    call to [DrawGList()](../Libraries_Manual_guide/node038C.html).
