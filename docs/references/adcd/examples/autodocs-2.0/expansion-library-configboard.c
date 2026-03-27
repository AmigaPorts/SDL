/* Source: ADCD 2.1
 * Section: expansion-library-configboard
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-configboard.md
 */

    This routine configures an expansion board.  The board
    will generally live at E_EXPANSIONBASE, but the base is
    passed as a parameter to allow future compatibility.
    The configDev parameter must be a valid configDev that
    has already had [ReadExpansionRom()](../Includes_and_Autodocs_2._guide/node03BB.html) called on it.

    ConfigBoard will allocate expansion memory and place
    the board at its new address.  It will update configDev
    accordingly.  If there is not enough expansion memory
    for this board then an error will be returned.
