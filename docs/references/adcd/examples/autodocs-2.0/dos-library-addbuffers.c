/* Source: ADCD 2.1
 * Section: dos-library-addbuffers
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-addbuffers.md
 */

    Adds buffers to a filesystem.  If it succeeds, the number of current
    buffers is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  Note that "number" may be negative.
    The amount of memory used per buffer, and any limits on the number of
    buffers, are dependant on the filesystem in question.
    If the call succeeds, the number of buffers in use on the filesystem
    will be returned by [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).
