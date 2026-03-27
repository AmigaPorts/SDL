/* Source: ADCD 2.1
 * Section: keyboard-device-kbd-readevent
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/keyboard-device-kbd-readevent.md
 */

    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      KBD_READEVENT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       the size of the io_Data area in bytes: there
                    are sizeof(inputEvent) bytes per input event.
    io_Data         a buffer area to fill with input events.  The
                    fields of the input event are:
        ie_NextEvent
                    links the events returned
        ie_Class
                    is IECLASS_RAWKEY
        ie_Code
                    contains the next key up/down reports
        ie_Qualifier
                    only the shift and numeric pad bits are set
        ie_SubClass, ie_X, ie_Y, ie_TimeStamp
                    are not used, and set to zero
