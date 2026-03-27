# keyboard.device/KBD_READEVENT



NAME

    KBD_READEVENT -- Return the next keyboard event.
FUNCTION

    Read raw keyboard events from the keyboard and put them in the
    data area of the iORequest.  If there are no pending keyboard
    events, this command will not be satisfied, but if there are
    some events, but not as many as can fill IO_LENGTH, the
    request will be satisfied with those currently available.
IO REQUEST

```c
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
```
RESULTS

```c
    This function sets the error field in the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19), and fills
    the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) with the next keyboard events (but not partial
    events).
```
