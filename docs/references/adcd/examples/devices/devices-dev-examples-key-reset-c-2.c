/* Source: ADCD 2.1
 * Section: devices-dev-examples-key-reset-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-key-reset-c.md
 */

    {
    MyDataStuff.MyTask=FindTask(NULL);
    MyDataStuff.MySignal=1L << MySignal;

    if (KeyMP=CreatePort(NULL,NULL))
        {
        if (keyHandler =
                AllocMem(sizeof(struct Interrupt),MEMF_PUBLIC|MEMF_CLEAR))
            {
            if (KeyIO=(struct IOStdReq *)
                      CreateExtIO(KeyMP,sizeof(struct IOStdReq)))
                {
                if (!OpenDevice("keyboard.device",NULL,(struct IORequest *)
                                                        KeyIO,NULL))
                    {
                    keyHandler->is_Code=ResetHandler;
                    keyHandler->is_Data=(APTR)&MyDataStuff;

                    /*
                     * Note that only software interrupt priorities
                     * can be used for the .ln_Pri on the reset
                     * handler...
                     */
                    keyHandler->is_Node.ln_Pri=16;

                    keyHandler->is_Node.ln_Name=NameString;
                    KeyIO->io_Data=(APTR)keyHandler;
                    KeyIO->io_Command=KBD_ADDRESETHANDLER;
                    DoIO((struct IORequest *)KeyIO);

                    if (WaitForUser(MyDataStuff.MySignal))
                        {
                        if (argc) /* Check for CLI */
                            {
                            printf("System going down\n");
                            printf("Cleaning up...\n");
                            /* Show a delay, like cleanup... */
                            Delay(20);
                            printf("*Poof*\n");
                            }
                        /* We are done with our cleanup */

                        KeyIO->io_Data=(APTR)keyHandler;
                        KeyIO->io_Command=KBD_RESETHANDLERDONE;
                        DoIO((struct IORequest *)KeyIO);
                        /*
                         * Note that since the above call
                         * tells the system it is safe to reboot
                         * and will cause the reboot if this
                         * task was the last to say so, the call
                         * never really returns...  The system
                         * just reboots...
                         */
                        }

                    KeyIO->io_Data=(APTR)keyHandler;
                    KeyIO->io_Command=KBD_REMRESETHANDLER;
                    DoIO((struct IORequest *)KeyIO);

                    CloseDevice((struct IORequest *)KeyIO);
                    }
                else
                    printf("Error: Could not open keyboard.device\n");

                DeleteExtIO((struct IORequest *)KeyIO);
                }
            else
                printf("Error: Could not create I/O request\n");

            FreeMem(keyHandler,sizeof(struct Interrupt));
            }
        else
            printf("Error: Could not allocate memory for interrupt\n");

        DeletePort(KeyMP);
        }
    else
        printf("Error: Could not create message port\n");

    FreeSignal(MySignal);
    }
