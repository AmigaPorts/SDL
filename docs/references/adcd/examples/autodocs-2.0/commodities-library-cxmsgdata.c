/* Source: ADCD 2.1
 * Section: commodities-library-cxmsgdata
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-cxmsgdata.md
 */

    Most commodity messages contain meaningful data, such as an [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198)
    structure. This function returns a pointer to this data.

    You may get a commodity message from a synchronous (custom object) or
    asynchronous (sender object) source. In the second case, 'data' is
    not valid after you have replied to the message.
