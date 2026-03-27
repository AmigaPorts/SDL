/* Source: ADCD 2.1
 * Section: dos-library-open
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-open.md
 */

    The named file is opened and a file handle returned.  If the
    accessMode is MODE_OLDFILE, an existing file is opened for reading
    or writing. If the value is MODE_NEWFILE, a new file is created for
    writing. MODE_READWRITE opens a file with an shared lock, but
    creates it if it didn't exist.  Open types are documented in the
    [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html) or [<libraries/dos.h>](../Includes_and_Autodocs_2._guide/node0108.html) include file.

    The 'name' can be a filename (optionally prefaced by a device
    name), a simple device such as NIL:, a window specification such as
    CON: or RAW: followed by window parameters, or "*", representing the
    current window.  Note that as of V36, "*" is obsolete, and CONSOLE:
    should be used instead.

    If the file cannot be opened for any reason, the value returned
    will be zero, and a secondary error code will be available by
    calling the routine [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).
