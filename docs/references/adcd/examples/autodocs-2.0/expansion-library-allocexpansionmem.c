/* Source: ADCD 2.1
 * Section: expansion-library-allocexpansionmem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-allocexpansionmem.md
 */

    (Not typically called by user code)

    This function allocates numslots of expansion space (each slot
    is E_SLOTSIZE bytes).  It returns the slot number of the
    start of the expansion memory.  The EC_MEMADDR macro may be
    used to convert this to a memory address.

    Boards that fit the expansion architecture have alignment
    rules.  Normally a board must be on a binary boundary of its
    size.  Four and Eight megabyte boards have special rules.
    User defined boards might have other special rules.

    If AllocExpansionMem() succeeds, the startSlot will satisfy
    the following equation:

            (startSlot - slotOffset) MOD slotAlign = 0
