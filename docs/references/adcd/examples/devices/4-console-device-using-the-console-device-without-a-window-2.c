/* Source: ADCD 2.1
 * Section: 4-console-device-using-the-console-device-without-a-window
 * Library: devices
 * ADCD reference: devices/4-console-device-using-the-console-device-without-a-window.md
 */

       {
           /* Create the I/O request */
       if (ConsoleIO = CreateIORequest(ConsoleMP,sizeof(struct IOStdReq)))
           {
               /* Open the Console device */
           if (OpenDevice("console.device",CONU_LIBRARY,
                         (struct IORequest *)ConsoleIO,0L))

               /* Inform user that it could not be opened */
               printf("Error: console.device did not open\n");
           else
               {
                  /* Allocate memory for the keymap */
               if (keymap = (struct KeyMap *)
                  AllocMem(sizeof(struct KeyMap),MEMF_PUBLIC | MEMF_CLEAR))
                  {
                  /* device opened, send CD_ASKKEYMAP command to it */
                  ConsoleIO->io_Length = sizeof(struct KeyMap);
                  ConsoleIO->io_Data = (APTR)keymap; /* where to put it */
                  ConsoleIO->io_Command = CD_ASKKEYMAP;
                  DoIO((struct IORequest *)ConsoleIO))
                  }

               CloseDevice(ConsIO);
               }
