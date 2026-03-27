/* Source: ADCD 2.1
 * Section: amiga-lib-cxsignal
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-cxsignal.md
 */

    This function creates a Commodities signal object. The action
    of this object on receiving a Commodities message is to
    send the 'signal' to the 'task'. The caller is responsible
    for allocating the signal and determining the proper task ID.

    Note that 'signal' is the signal value as returned by [AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html),
    not the mask made from that value.

    This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), defined
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).
