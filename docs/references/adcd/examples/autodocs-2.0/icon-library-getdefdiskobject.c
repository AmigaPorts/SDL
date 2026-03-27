/* Source: ADCD 2.1
 * Section: icon-library-getdefdiskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-getdefdiskobject.md
 */

    This routine reads in a default Workbench disk object from disk.
    The valid def_types can be found in [workbench/workbench.h](../Includes_and_Autodocs_2._guide/node0135.html) and
    currently include WBDISK thru WBGARBAGE.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    Using this routine protects you from any future changes to
    the way default icons are stored within the system.
