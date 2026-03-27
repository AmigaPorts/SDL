# printer.device/PRD_PRTCOMMAND



   NAME

       PRD_PRTCOMMAND -- send a command to the printer
   FUNCTION

```c
      This function sends a command to either the parallel or serial
      device.  The printer device maps this command to the control
      code set of the current printer.  The commands supported can
      be found with the [printer.device/Write](../Includes_and_Autodocs_3._guide/node01D1.html) command.  All printers
      may not support all functions.
```
   IO REQUEST IOPrtCmdReq

```c
       io_Message      mn_ReplyPort set
       io_Device       preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      PRD_PRTCOMMAND
       io_PrtCommand   the actual command number
       io_Parm0        parameter for the command
       io_Parm1        parameter for the command
       io_Parm2        parameter for the command
       io_Parm3        parameter for the command
```
   RESULTS

```c
       Errors: if the PRD_PRTCOMMAND succeeded, then io_Error will be zero.
       Otherwise io_Error will be non-zero.  An error of -1 indicates that
       the command is not supported by the current printer driver.  This
       could be used to check if the connected printer supports a particular
       command (italics for example).
```
   SEE ALSO

```c
       [printer.device/PWrite()](../Includes_and_Autodocs_3._guide/node0517.html) printer.h, parallel.device, [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57)
```
