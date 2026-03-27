/* Source: ADCD 2.1
 * Section: misc-resource-allocmiscresource
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/misc-resource-allocmiscresource.md
 */

    This routine attempts to allocate one of the miscellaneous resources
    If the resource had already been allocated, an error is returned. If
    you do get it, your name is associated with the resource (so a user
    can see who has it allocated).

    This function may not be called from interrupt code
