/* Source: ADCD 2.1
 * Section: icon-library-deletediskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-deletediskobject.md
 */

    This routine will try to delete a Workbench disk object from disk.
    The name parameter will have a ".info" postpended to it, and the
    info file of that name will be deleted.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    This call also updates the Workbench screen if needed.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
