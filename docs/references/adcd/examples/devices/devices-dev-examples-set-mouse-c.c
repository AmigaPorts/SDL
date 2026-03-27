/* Source: ADCD 2.1
 * Section: devices-dev-examples-set-mouse-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-set-mouse-c.md
 */

    {
    if (FakeEvent = AllocMem(sizeof(struct InputEvent),MEMF_PUBLIC))
        {
        if (NeoPix  = AllocMem(sizeof(struct IEPointerPixel),MEMF_PUBLIC))
            {
            if (InputIO = CreateIORequest(InputMP,sizeof(struct IOStdReq)))
                {
                if (!OpenDevice("input.device",NULL,
                               (struct IORequest *)InputIO,NULL))
                    {
                        /* Open Intuition library */
                    if (IntuitionBase=(struct IntuitionBase *)
                                      OpenLibrary("intuition.library",36L))
                        {
                        /* Get pointer to screen and lock screen */
                        if (PubScreen=(struct Screen *)LockPubScreen(NULL))
                            {
                            /* Set up IEPointerPixel fields */
                            /* WB screen */
                            NeoPix->iepp_Screen=(struct Screen *)PubScreen;
                            /* put pointer at x = 100 */
                            NeoPix->iepp_Position.X = 100;
                            /* put pointer at y = 200 */
                            NeoPix->iepp_Position.Y = 200;

                            /* Set up InputEvent fields */
                            /* IEPointerPixel */
                            FakeEvent->ie_EventAddress = (APTR)NeoPix;
                            FakeEvent->ie_NextEvent = NULL;
                            /* new mouse pos */
                            FakeEvent->ie_Class = IECLASS_NEWPOINTERPOS;
                            /* on pixel */
                            FakeEvent->ie_SubClass = IESUBCLASS_PIXEL;
                            FakeEvent->ie_Code = IECODE_NOBUTTON;
                            /* absolute positioning */
                            FakeEvent->ie_Qualifier = NULL;

                            /* InputEvent */
                            InputIO->io_Data = (APTR)FakeEvent;
                            InputIO->io_Length = sizeof(struct InputEvent);
                            InputIO->io_Command = IND_WRITEEVENT;
                            DoIO((struct IORequest *)InputIO);
                            /* Unlock screen */
                            UnlockPubScreen(NULL,PubScreen);
                            }
                        else
                            printf("Could not get pointer to screen\n");
                        /* Close intuition library */
                        CloseLibrary(IntuitionBase);
                        }
                    else
                        /* Can't open V36 (or higher) intuition.library */
                        printf("Error:Can't open V36 intuition.library\n");

                    CloseDevice((struct IORequest *)InputIO);
                    }
                else
                    printf("Error: Could not open input.device\n");

                DeleteIORequest(InputIO);
                }
            else
                printf("Error: Could not create IORequest\n");

            FreeMem(NeoPix,sizeof(struct IEPointerPixel));
            }
        else
            printf("Error: Could not allocate memory for NeoPix\n");

        FreeMem(FakeEvent,sizeof(struct InputEvent));
        }
    else
        printf("Error: Could not allocate memory for FakeEvent\n");

    DeleteMsgPort(InputMP);
    }
