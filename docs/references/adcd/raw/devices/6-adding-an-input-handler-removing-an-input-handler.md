# 6 / Adding an Input Handler / Removing An Input Handler


You remove a handler from the handler chain by passing an [IOStdReq](../Devices_Manual_guide/node00CC.html#line12) to the
device [IND_REMHANDLER](../Includes_and_Autodocs_2._guide/node04E2.html) set in io_Command and a pointer to the Interrupt
structure used to add the handler.

   struct Interrupt *InputHandler;
   struct IOStdReq  *InputIO;

   InputIO->io_Data=(APTR)InputHandler;   /* Which handler to REM */
   InputIO->io_Command=IND_REMHANDLER;    /* The REM command */
   DoIO((struct IORequest *)InputIO);     /* Send the command */

