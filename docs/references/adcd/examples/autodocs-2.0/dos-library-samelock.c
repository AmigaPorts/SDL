/* Source: ADCD 2.1
 * Section: dos-library-samelock
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-samelock.md
 */

    Should do more extensive checks for NULL against a real lock, checking
    to see if the real lock is a lock on the root of the boot volume.

    In V36, it would return LOCK_SAME_VOLUME for different volumes on the
    same handler.  Also, LOCK_SAME_VOLUME was LOCK_SAME_HANDLER (now
    an obsolete define, see [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html)).
