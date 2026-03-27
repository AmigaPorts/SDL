# 10 Printer Device / Sending Printer Commands to a Printer


As mentioned before, it is possible to include printer commands (escape
sequences) in the character stream and send them to the printer using the
[CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) device I/O command. It is also possible to use the printer
command names using the device I/O command [PRD_PRTCOMMAND](../Includes_and_Autodocs_2._guide/node051A.html) with the
[IOPrtCmdReq](../Devices_Manual_guide/node0044.html#line43) data structure. This gives you a mnemonic way of setting the
printer to your program needs.

You send printer commands to the device by passing an [IOPrtCmdReq](../Devices_Manual_guide/node0044.html#line43) to the
device with [PRD_PRTCOMMAND](../Includes_and_Autodocs_2._guide/node051A.html) set in io_Command, the printer command set in
io_PrtCommand and up to four parameters set in Parm0 through Parm3.

   #include <devices/printer.h>

   PrintIO->iopc.io_PrtCommand = aSLRM;  /* Set left & right margins */
   PrintIO->iopc.io_Parm0 = 1;           /* Set left margin = 1 */
   PrintIO->iopc.io_Parm1 = 79;          /* Set right margin = 79 */
   PrintIO->iopc.io_Parm2 = 0;
   PrintIO->iopc.io_Parm3 = 0;
   PrintIO->iopc.io_Command = PRD_PRTCOMMAND;
   DoIO((struct IORequest *)PrintIO);

Consult the command function table listed below for other printer commands.

 [Printer Command Definitions](../Devices_Manual_guide/node004A.html) 

