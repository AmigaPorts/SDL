/* Source: ADCD 2.1
 * Section: exec-library-findresident
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-findresident.md
 */

    Search the system resident tag list for a resident tag ("ROMTag") with
    the given name.  If found return a pointer to the resident tag
    structure, else return zero.

    [Resident](../Includes_and_Autodocs_2._guide/node00A0.html#line19) modules are used by the system to pull all its parts
    together at startup.  [Resident](../Includes_and_Autodocs_2._guide/node00A0.html#line19) tags are also found in disk based
    devices and libraries.
