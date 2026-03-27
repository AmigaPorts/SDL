/* Source: ADCD 2.1
 * Section: exec-library-openlibrary
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-openlibrary.md
 */

    This function returns a pointer to a library that was previously
    installed into the system.  If the requested library is exists, and
    if the library version is greater than or equal to the requested
    version, then the open will succeed.

    The device may exist in memory, or on disk; this is transparent to
    the [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html) caller.  Only Processes are allowed to call
    OpenLibrary (since OpenLibrary may in turn call dos.library).

    A full path name for the library name is legitimate.  For example
    "wp:libs/wp.library".  This allows the use of custom libraries
    without requiring the user to copy the library into the system's
    LIBS: directory.
