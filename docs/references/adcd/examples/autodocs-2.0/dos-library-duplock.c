/* Source: ADCD 2.1
 * Section: dos-library-duplock
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-duplock.md
 */

    DupLock() is passed a shared filing system lock.  This is the ONLY
    way to obtain a duplicate of a lock... simply copying is not
    allowed.

    Another lock to the same object is then returned.  It is not
    possible to create a copy of a exclusive lock.

    A zero return indicates failure.
