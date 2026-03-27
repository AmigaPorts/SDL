/* Source: ADCD 2.1
 * Section: expansion-library-getcurrentbinding
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-getcurrentbinding.md
 */

    This function writes the contents of the "currentBinding"
    structure out of a private place.  It may be set via
    [SetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03BE.html).  This is really a kludge, but it is
    the only way to pass extra arguments to a newly configured
    device.

    A [CurrentBinding](../Includes_and_Autodocs_2._guide/node00FC.html#line62) structure has the name of the currently
    loaded file, the product string that was associated with
    this driver, and a pointer to the head of a singly linked
    list of [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures (linked through the cd_NextCD
    field).

    Many devices may not need this information; they have hard
    coded into themselves their manufacture number.  It is
    recommended that you at least check that you can deal with
    the product code in the linked [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures.
