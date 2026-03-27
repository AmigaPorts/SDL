/* Source: ADCD 2.1
 * Section: dos-library-findsegment
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-findsegment.md
 */

    Finds a segment on the Dos resident list by name and type, starting
    at the segment AFTER 'start', or at the beginning if start is NULL.
    If system is zero, it will only return nodes with a seg_UC of 0
    or more.  It does NOT increment the seg_UC, and it does NOT do any
    locking of the list.  You must [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html) lock the list to use this
    call.

    To use an entry you have found, you must: if the seg_UC is 0 or more,
    increment it, and decrement it (under Forbid()!) when you're done
    the the seglist.

    The other values for seg_UC are:
            -1   - system module, such as a filesystem or shell
            -2   - resident shell command
            -999 - disabled internal command, ignore
    Negative values should never be modified.  All other negative
    values between 0 and -32767 are reserved to AmigaDos and should not
    be used.
