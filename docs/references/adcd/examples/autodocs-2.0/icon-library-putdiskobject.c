/* Source: ADCD 2.1
 * Section: icon-library-putdiskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-putdiskobject.md
 */

    This routine writes out a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure, and its
    associated information.  The file name of the info
    file will be the name parameter with a
    ".info" postpended to it.  If the call fails, a zero will
    be returned.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    As of release V2.0, PutDiskObject (if sucessful) notifies workbench
    han an icon has been created/modified.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
