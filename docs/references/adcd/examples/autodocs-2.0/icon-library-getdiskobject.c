/* Source: ADCD 2.1
 * Section: icon-library-getdiskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-getdiskobject.md
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
