# serial.device/CMD_FLUSH



   NAME

```c
       [Flush](../Includes_and_Autodocs_3._guide/node016A.html) -- clear all queued I/O requests for the serial port
```
   FUNCTION

```c
       This command purges the read and write request queues for the
       serial device. [Flush](../Includes_and_Autodocs_3._guide/node016A.html) will not affect active requests.
```
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      CMD_FLUSH
```
   RESULTS

```c
       Error -- if the [Flush](../Includes_and_Autodocs_3._guide/node016A.html) succeded, then io_Error will be null.
           	 If the [Flush](../Includes_and_Autodocs_3._guide/node016A.html) failed, then the io_Error will be non-zero.
```
