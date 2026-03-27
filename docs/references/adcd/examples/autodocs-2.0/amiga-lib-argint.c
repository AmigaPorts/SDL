/* Source: ADCD 2.1
 * Section: amiga-lib-argint
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-argint.md
 */

    This function looks in the ToolTypes array 'tt' returned
    by [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html) for 'entry' and returns the value associated
    with it. 'tt' is in standard ToolTypes format such as:

            ENTRY=Value

    The Value string is passed to atoi() and the result is returned by
    this function.

    If 'entry' is not found, the integer 'defaultval' is returned.
