/* Source: ADCD 2.1
 * Section: input-device-ind-setmtrig
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/input-device-ind-setmtrig.md
 */

    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      IND_SETMTRIG
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       sizeof(gameportTrigger)
    io_Data         a structure of type GameportTrigger, which
                    has the following elements
        gpt_Keys -
                GPTB_DOWNKEYS set if button down transitions
                trigger a report, and GPTB_UPKEYS set if button up
                transitions trigger a report
        gpt_Timeout -
                a time which, if exceeded, triggers a report;
                measured in vertical blank units (60/sec)
        gpt_XDelta  -
                a distance in x which, if exceeded, triggers a
                report
        gpt_YDelta  -
                a distance in x which, if exceeded, triggers a
                report
