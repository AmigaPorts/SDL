# serial.device/SDCMD_QUERY



NAME

    Query -- query serial port/line status
FUNCTION

```c
    This command return the status of the serial port lines and
    registers. The number of unread bytes in the serial device's
    read buffer is shown in io_Actual.

    The break send & received flags are cleared by a query, and
    whenever a read [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) is returned with a error
    in io_Error.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Command      SDCMD_QUERY
```
RESULTS

```c
    io_Status        BIT  ACTIVE  FUNCTION

           LSB       0    ---    reserved
                     1    ---    reserved
                     2    high   parallel "sel" on the A1000
                                 On the A500 & A2000, "sel" is also
                                 connected to the serial port's
                                 "Ring Indicator".  Be cautious when
                                 making cables.
                     3    low    Data Set Ready
                     4    low    Clear To Send
                     5    low    Carrier Detect
                     6    low    Ready To Send
                     7    low    Data Terminal Ready
           MSB       8    high   hardware overrun
                     9    high   break sent (most recent output)
                    10    high   break received (as latest input)
                    11    high   transmit x-OFFed
                    12    high   receive x-OFFed
                 13-15    ---    reserved

    io_Actual       set to count of unread input characters

    io_Error -- Query will always succeded.
```
