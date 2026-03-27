/* Source: ADCD 2.1
 * Section: dos-library-currentdir
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-currentdir.md
 */

    CurrentDir() causes a directory associated with a lock to be made
    the current directory.  The old current directory lock is returned.

    A value of zero is a valid result here, this 0 lock represents the
    root of file system that you booted from.

    Any call that has to [Open()](../Includes_and_Autodocs_2._guide/node02D6.html) or [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html) files (etc) requires that
    the current directory be a valid lock or 0.
