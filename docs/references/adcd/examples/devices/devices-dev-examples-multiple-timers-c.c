/* Source: ADCD 2.1
 * Section: devices-dev-examples-multiple-timers-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-multiple-timers-c.md
 */

    {
    if (TimerIO[0] = (struct timerequest *)
                      CreateExtIO(TimerMP,sizeof(struct timerequest)) )
        {
            /* Open the device once */
        if (!(error=OpenDevice( TIMERNAME, UNIT_VBLANK,(struct IORequest *) TimerIO[0], 0L)))
            {
            /* Set command to TR_ADDREQUEST */
            TimerIO[0]->tr_node.io_Command = TR_ADDREQUEST;

            if (TimerIO[1]=(struct timerequest *)
                    AllocMem(sizeof(struct timerequest),MEMF_PUBLIC | MEMF_CLEAR))
                {
                if (TimerIO[2]=(struct timerequest *)
                       AllocMem(sizeof(struct timerequest),MEMF_PUBLIC | MEMF_CLEAR))
                    {
                    /* Copy fields from the request used to open the timer device */
                    *TimerIO[1] = *TimerIO[0];
                    *TimerIO[2] = *TimerIO[0];

                    /* Initialize other fields */
                    for (x=0;x<3;x++)
                        {
                        TimerIO[x]->tr_time.tv_secs   = seconds[x];
                        TimerIO[x]->tr_time.tv_micro  = microseconds[x];
                        printf("\nInitializing TimerIO[%d]",x);
                        }

                    printf("\n\nSending multiple requests\n\n");

                    /* Send multiple requests asynchronously */
                    /* Do not got to sleep yet...            */
                    SendIO((struct IORequest *)TimerIO[0]);
                    SendIO((struct IORequest *)TimerIO[1]);
                    SendIO((struct IORequest *)TimerIO[2]);

                    /* There might be other processing done here */

                    /* Now go to sleep with WaitPort() waiting for the requests */
                    while (allin)
                          {
                          WaitPort(TimerMP);
                          /* Get the reply message */
                          TimerMSG=GetMsg(TimerMP);
                          for (x=0;x<3;x++)
                              if (TimerMSG==(struct Message *)TimerIO[x])
                                  printf("Request %ld finished %s\n",x,position[--allin]);
                          }

                    FreeMem(TimerIO[2],sizeof(struct timerequest));
                    }

                else
                    printf("Error: could not allocate TimerIO[2] memory\n");

                FreeMem(TimerIO[1],sizeof(struct timerequest));
                }

            else
                printf("Error could not allocate TimerIO[1] memory\n");

            CloseDevice((struct IORequest *) TimerIO[0]);
            }

        else
            printf("\nError: Could not OpenDevice\n");

        DeleteExtIO((struct IORequest *) TimerIO[0]);
        }

    else
        printf("Error: could not create IORequest\n");

    DeletePort(TimerMP);
    }
