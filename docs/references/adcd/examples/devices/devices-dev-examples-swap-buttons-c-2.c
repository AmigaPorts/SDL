/* Source: ADCD 2.1
 * Section: devices-dev-examples-swap-buttons-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-swap-buttons-c.md
 */

    {
    if (inputHandler=AllocMem(sizeof(struct Interrupt),
                               MEMF_PUBLIC|MEMF_CLEAR))
        {
        if (inputReqBlk=(struct IOStdReq *)CreateExtIO(inputPort,
                                                 sizeof(struct IOStdReq)))
            {
            if (!OpenDevice("input.device",NULL,
                             (struct IORequest *)inputReqBlk,NULL))
                {
                inputHandler->is_Code=ButtonSwap;
                inputHandler->is_Data=NULL;
                inputHandler->is_Node.ln_Pri=100;
                inputHandler->is_Node.ln_Name=NameString;
                inputReqBlk->io_Data=(APTR)inputHandler;
                inputReqBlk->io_Command=IND_ADDHANDLER;
                DoIO((struct IORequest *)inputReqBlk);

                WaitForUser();

                inputReqBlk->io_Data=(APTR)inputHandler;
                inputReqBlk->io_Command=IND_REMHANDLER;
                DoIO((struct IORequest *)inputReqBlk);

                CloseDevice((struct IORequest *)inputReqBlk);
                }
            else
                printf("Error: Could not open input.device\n");

            DeleteExtIO((struct IORequest *)inputReqBlk);
            }
        else
            printf("Error: Could not create I/O request\n");

        FreeMem(inputHandler,sizeof(struct Interrupt));
        }
    else
        printf("Error: Could not allocate interrupt struct memory\n");

    DeletePort(inputPort);
    }
