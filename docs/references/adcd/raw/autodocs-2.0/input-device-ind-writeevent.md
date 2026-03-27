# input.device/IND_WRITEEVENT



NAME

    IND_WRITEEVENT -- Propagate an input event to all handlers
FUNCTION

IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      IND_WRITEEVENT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       should be sizeof(struct InputEvent)
    io_Data         a pointer to the struct InputEvent:
        ie_NextEvent
                    will be ignored.
        ie_Class
        ie_SubClass
        ie_Code
        ie_Qualifier
        ie_X, ie_Y
                    as desired
        ie_TimeStamp
                    will be set by this call (V36)
```
NOTES

    The contents of the input event are destroyed.

    This function was documented in V34 and earlier to allow
    chaining of events via ie_NextEvent.  The implementation
    never allowed that.  The documentation now reflects this.

    ie_TimeStamp is set only in V36 and later.  Software written
    to run on earlier versions should set this field to the
    current time.
