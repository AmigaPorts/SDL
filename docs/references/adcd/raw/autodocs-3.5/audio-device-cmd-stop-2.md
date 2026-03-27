# audio.device/CMD_STOP



   NAME

```c
       CMD_STOP -- stop device processing (like ^S)
```
   FUNCTION

```c
       CMD_STOP is a standard command for multiple audio channels.  For each
       selected channel (io_Unit), if the allocation key (ioa_AllocKey) is
       correct, CMD_STOP immediately stops any writes (CMD_WRITE) in
       progress; otherwise, CMD_STOP returns an error (ADIOERR_NOALLOCATION).
       [CMD_WRITE](../Includes_and_Autodocs_3._guide/node0071.html) queues up writes to a stopped channel until [CMD_START](../Includes_and_Autodocs_3._guide/node006E.html) starts
       the channel or [CMD_RESET](../Includes_and_Autodocs_3._guide/node006D.html) resets the channel. CMD_STOP is synchronous
       and only replies (mn_ReplyPort) if the quick flag (IOF_QUICK) is
       clear.  Do not use CMD_STOP in interrupt code at interrupt level 5 or
       higher.
```
   INPUTS

```c
       mn_ReplyPort- pointer to message port that receives I/O request after
                     if the quick flag (IOF_QUICK) is clear
       io_Device   - pointer to device node, must be set by (or copied from
                     I/O block set by) [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) function
       io_Unit     - bit map of channels to stop (bits 0 thru 3 correspond to
                     channels 0 thru 3)
       io_Command  - command number for CMD_STOP
       io_Flags    - flags, must be cleared if not used:
                     IOF_QUICK - (CLEAR) reply I/O request
       ioa_AllocKey- allocation key, must be set by (or copied from I/O block
                     set by) [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html) function or [ADCMD_ALLOCATE](../Includes_and_Autodocs_3._guide/node0061.html) command
```
   OUTPUTS

```c
       io_Unit     - bit map of channels successfully stopped (bits 0 thru 3
                     correspond to channels 0 thru 3)
       io_Error    - error number:
                     0                    - no error
                     ADIOERR_NOALLOCATION - allocation key (ioa_AllocKey)
                                            does not match key for channel
```
