/* Source: ADCD 2.1
 * Section: gameport-device-gpd-readevent
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gameport-device-gpd-readevent.md
 */

    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      GPD_READEVENT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       the size of the io_Data area in bytes: there
                    are sizeof(inputEvent) bytes per input event.
    io_Data         a buffer area to fill with input events.  The
                    fields of the input event are:
        ie_NextEvent
                    links the events returned
        ie_Class
                    is IECLASS_RAWMOUSE
        ie_SubClass
                    is 0 for the left, 1 for the right game port
        ie_Code
                    contains any gameport button reports.  No
                    report is indicated by the value 0xff.
        ie_Qualifier
                    only the relative and button bits are set
        ie_X, ie_Y
                    the x and y values for this report, in either
                    relative or absolute device dependent units.
        ie_TimeStamp
                    the delta time since the last report, given
                    not as a standard timestamp, but as the frame
                    count in the TV_SECS field.
