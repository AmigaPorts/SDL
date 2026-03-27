/* Source: ADCD 2.1
 * Section: 11-intuition-special-functions-locking-intuitionbase
 * Library: libraries
 * ADCD reference: libraries/11-intuition-special-functions-locking-intuitionbase.md
 */

    About LockIBase().
    ------------------
    This function should not be called while holding any other system
    locks such as [Layer](../Libraries_Manual_guide/node03E4.html) and [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) locks.  Between calls to
    [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) and [UnlockIBase()](../Includes_and_Autodocs_2._guide/node025C.html), you may not call any Intuition
    or other high-level system functions so it is best to copy the
    information you need and release the lock as quickly as possible.

    About IntuitionBase.
    --------------------
    Never, ever, modify any of the fields in [IntuitionBase](../Includes_and_Autodocs_2._guide/node00DC.html#line59) directly.
    Also, there are fields in IntuitionBase that are considered system
    private that should not be accessed, even for reading.  (Refer to the
    <intuition/[intuitionbase](../Includes_and_Autodocs_2._guide/node00DC.html)> include file.) Application programs
    cannot depend on (and should not use) the contents of these fields;
    their usage is subject to change in future revisions of Intuition.
