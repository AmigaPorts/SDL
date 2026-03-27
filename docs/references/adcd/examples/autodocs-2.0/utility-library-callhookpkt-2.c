/* Source: ADCD 2.1
 * Section: utility-library-callhookpkt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-callhookpkt.md
 */

    [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23)           - pointer to [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure as defined in
                      [utility/hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)
    Object          - useful data structure in the particular context the
                      hook is being used for.
    ParamPkt        - pointer to a parameter packet (often built on the
                      stack); by convention this packet should start off
                      with a longword command code, and the remaining
                      data in the packet depends on that command.
