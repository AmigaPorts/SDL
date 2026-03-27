# 2 / Device Interface / Scope Of Audio Commands


Most audio commands can operate on multiple channels.  The exceptions are
[ADCMD_WAITCYCLE](../Devices_Manual_guide/node0038.html), [CMD_WRITE](../Includes_and_Autodocs_2._guide/node04B6.html) and [CMD_READ](../Includes_and_Autodocs_2._guide/node04B1.html), which can only operate on one
channel at a time.  You specify the channel(s) that you want to use by
setting the appropriate bits in the [ioa_Request.io_Unit](../Devices_Manual_guide/node001E.html#line11) field of the
IOAudio block.  If you send a command for a channel that you do not own,
your command will be ignored.  For more details, see the section on
"[Allocation and Arbitration](../Devices_Manual_guide/node0029.html)" below.

