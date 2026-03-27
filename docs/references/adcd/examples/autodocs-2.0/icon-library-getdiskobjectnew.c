/* Source: ADCD 2.1
 * Section: icon-library-getdiskobjectnew
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-getdiskobjectnew.md
 */

    This routine reads in a Workbench disk object in from disk.  The
    name parameter will have a ".info" postpended to it, and the
    info file of that name will be read.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    Using this routine protects you from any future changes to
    the way icons are stored within the system.

    A [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) structure is allocated just after the [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61)
    structure; [FreeDiskObject](../Includes_and_Autodocs_2._guide/node0187.html) makes use of this to get rid of the
    memory that was allocated.

    This call is functionally identical to [GetDiskObject](../Includes_and_Autodocs_2._guide/node018A.html) with one
    exception.  If its call to [GetDiskObject](../Includes_and_Autodocs_2._guide/node018A.html) fails, this function calls
    [GetDefDiskObject](../Includes_and_Autodocs_2._guide/node0189.html).  This is useful when there is no .info file for the
    icon you are trying to get a disk object for.  Applications that use
    workbench application windows MUST use this call if they want to
    handle the user dropping an icon (that doesn't have a .info file) on
    their window.  The V2.0 icon editor program is an example of a
    workbench application window that uses this call.
