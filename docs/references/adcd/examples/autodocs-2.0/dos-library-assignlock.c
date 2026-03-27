/* Source: ADCD 2.1
 * Section: dos-library-assignlock
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-assignlock.md
 */

    Sets up an assign of a name to a given lock.  Passing NULL for a lock
    cancels any outstanding assign to that name.  If an assign entry of
    that name is already on the list, this routine replaces that entry.  If
    an entry is on the list that conflicts with the new assign, then a
    failure code is returned.

    NOTE: you should not use the lock in any way after making this call
    successfully.  It becomes the assign, and will be unlocked by the
    system when the assign is removed.  If you need to keep the lock,
    pass a lock from [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html) to AssignLock().
