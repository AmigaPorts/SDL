/* Source: ADCD 2.1
 * Section: amigaguide-library-closeamigaguide
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-closeamigaguide.md
 */

    NAME
        CloseAmigaGuide - [Close](../Includes_and_Autodocs_3._guide/node0149.html) a AmigaGuide client.            (V34)

    SYNOPSIS
        CloseAmigaGuide (handle);
                          a0

        VOID CloseAmigaGuide (AMIGAGUIDECONTEXT);

    FUNCTION
        Closes a synchronous, or asynchronous, AmigaGuide client.

        This function will also close all windows that were opened for
        the client.

    INPUTS
        handle - Handle to an AmigaGuide client.

    SEE ALSO
        [OpenAmigaGuideA()](../Includes_and_Autodocs_3._guide/node000E.html), [OpenAmigaGuideAsyncA()](../Includes_and_Autodocs_3._guide/node000F.html)
