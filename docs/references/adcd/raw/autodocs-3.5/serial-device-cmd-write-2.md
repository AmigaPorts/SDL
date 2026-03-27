# serial.device/CMD_WRITE



   NAME

```c
       [Write](../Includes_and_Autodocs_3._guide/node01D1.html) -- send output to serial port
```
   FUNCTION

```c
       This command causes a stream of characters to be written out
       the serial port. The number of characters is specified in
       io_Length, unless -1 is used, in which case output is sent until
       a null(0x00) is encountered.
```
   IO REQUEST

```c
       io_Message      must have mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      CMD_WRITE
       io_Flags        Set IOF_QUICK to try quick I/O
       io_Length       number of characters to transmit, or if set
                       to -1 transmit until null encountered in buffer
       io_Data         pointer to block of data to transmit
```
   RESULTS

```c
       Error -- if the [Write](../Includes_and_Autodocs_3._guide/node01D1.html) succeded, then io_Error will be null.
           If the [Write](../Includes_and_Autodocs_3._guide/node01D1.html) failed, then the io_Error will be non-zero.
```
   SEE ALSO
	[serial.device/SDCMD_SETPARAMS](../Includes_and_Autodocs_3._guide/node0563.html)

