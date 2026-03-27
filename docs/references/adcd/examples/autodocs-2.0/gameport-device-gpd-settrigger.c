/* Source: ADCD 2.1
 * Section: gameport-device-gpd-settrigger
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gameport-device-gpd-settrigger.md
 */

    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      GPD_SETTRIGGER
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       sizeof(gamePortTrigger)
    io_Data         a structure of type [GamePortTrigger](../Includes_and_Autodocs_2._guide/node0039.html#line37), which
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
