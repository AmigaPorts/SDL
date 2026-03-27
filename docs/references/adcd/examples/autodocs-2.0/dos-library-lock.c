/* Source: ADCD 2.1
 * Section: dos-library-lock
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-lock.md
 */

    A filing system lock on the file or directory 'name' is returned if
    possible.

    If the accessMode is ACCESS_READ, the lock is a shared read lock;
    if the accessMode is ACCESS_WRITE then it is an exclusive write
    lock.  Do not use random values for mode.

    If Lock() fails (that is, if it cannot obtain a filing system lock
    on the file or directory) it returns a zero.

    Tricky assumptions about the internal format of a lock are unwise,
    as are any attempts to use the fl_Link or fl_Access fields.
