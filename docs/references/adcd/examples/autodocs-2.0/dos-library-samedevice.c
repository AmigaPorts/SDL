/* Source: ADCD 2.1
 * Section: dos-library-samedevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-samedevice.md
 */

    SameDevice() returns whether two locks refer to partitions that
    are on the same physical device (if it can figure it out).  This
    may be useful in writing copy routines to take advantage of
    asynchronous multi-device copies.

    Entry existed in V36 and always returned 0.
