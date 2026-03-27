/* Source: ADCD 2.1
 * Section: devices-dev-examples-keyboard-events-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-keyboard-events-c.md
 */

          (struct IOStdReq *)CreateExtIO(keyPort,sizeof(struct IOStdReq)))
      {
      if (!OpenDevice("keyboard.device",NULL,
                        (struct IORequest *)keyRequest,NULL))
          {
          if (keyEvent=AllocMem(sizeof(struct InputEvent),MEMF_PUBLIC))
              {
              for (loop=0;loop<4;loop++)
                   {
                   keyRequest->io_Command=KBD_READEVENT;
                   keyRequest->io_Data=(APTR)keyEvent;

                   /*
                    * We want 1 event, so we just set the
                    * length field to the size, in bytes
                    * of the event.  For multiple events,
                    * set this to a multiple of that size.
                    * The keyboard device NEVER fills partial
                    * events...
                    */

                   keyRequest->io_Length=sizeof(struct InputEvent);
                   DoIO((struct IORequest *)keyRequest);

                       /* Check for CLI startup... */
                   if (argc)
                       Display_Event(keyEvent);
                   }

              FreeMem(keyEvent,sizeof(struct InputEvent));
              }
          else
              printf("Error:Could not allocate memory for InputEvent\n");

          CloseDevice((struct IORequest *)keyRequest);
          }
      else
          printf("Error: Could not open keyboard.device\n");

      DeleteExtIO((struct IORequest *)keyRequest);
      }
