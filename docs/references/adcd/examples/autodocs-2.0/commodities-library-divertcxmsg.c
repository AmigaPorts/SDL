/* Source: ADCD 2.1
 * Section: commodities-library-divertcxmsg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-divertcxmsg.md
 */

    This function sends the commodity message 'cxm' down the list of
    objects attached to 'headObj'. The pointer 'returnObj' is first
    pushed onto the routing stack of 'cxm' so that when the end of the
    list of 'headObj' is reached the SUCCESSOR of 'returnObj' is the
    next destination.

    For example, when a filter finds a match with a message, the
    message is diverted down the filter's list like this:

            DivertCxMsg(cxm,filter,filter);
