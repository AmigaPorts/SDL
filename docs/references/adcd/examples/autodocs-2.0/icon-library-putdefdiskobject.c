/* Source: ADCD 2.1
 * Section: icon-library-putdefdiskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-putdefdiskobject.md
 */

    This routine writes out a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure, and its
    associated information.  If the call fails, a zero will
    be returned.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    Note that this function calls [PutDiskObject](../Includes_and_Autodocs_2._guide/node018E.html) internally which means
    that this call (if sucessful) notifies workbench than an icon has
    been created/modified.

    Using this routine protects you from any future changes to
    the way default icons are stored within the system.
