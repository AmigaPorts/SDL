# 5 / Gameport Events / Reading Gameport Events


You read gameport events by passing an I/O request to the device with
[GPD_READEVENT](../Includes_and_Autodocs_2._guide/node04BC.html) set in io_Command, the address of the [InputEvent](../Devices_Manual_guide/node00B4.html#line18) structure
to store events set in io_Data and the size of the structure set in
io_Length.

   struct InputEvent  GameEV;
   struct IOStdRequest *GameIO;  /* Must be initialized prior to using */

   void send_read_request()
   {
   GameIO->io_Command = GPD_READEVENT;  /* Read events */
   GameIO->io_Length = sizeof (struct InputEvent);
   GameIO->io_Data = (APTR)&GameEV;     /* put events in GameEV*/
   SendIO(GameIO);                      /* Asynchronous */
   }

