/* Source: ADCD 2.1
 * Section: amiga-lib-argstring
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-argstring.md
 */

    This function looks in the ToolTypes array 'tt' returned
    by [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html) for 'entry' and returns the value associated
    with it. 'tt' is in standard ToolTypes format such as:

            ENTRY=Value

    This function returns a pointer to the Value string.

    If 'entry' is not found, 'defaultstring' is returned.
