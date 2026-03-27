/* Source: ADCD 2.1
 * Section: dos-library-parentdir
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-parentdir.md
 */

    The argument 'lock' is associated with a given file or directory.
    ParentDir() returns 'newlock' which is associated the parent
    directory of 'lock'.

    Taking the ParentDir() of the root of the current filing system
    returns a NULL (0) lock.  Note this 0 lock represents the root of
    file system that you booted from (which is, in effect, the parent
    of all other file system roots.)
