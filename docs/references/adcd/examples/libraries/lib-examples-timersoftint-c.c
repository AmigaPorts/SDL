/* Source: ADCD 2.1
 * Section: lib-examples-timersoftint-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-timersoftint-c.md
 */

    struct MsgPort *port;
    struct Interrupt *softint;
    struct timerequest *tr;

    ULONG endcount;

    /* Allocate message port, data & interrupt structures. Don't use CreatePort() */
    /* or CreateMsgPort() since they allocate a signal (don't need that) for a    */
    /* PA_SIGNAL type port. We need PA_SOFTINT.                                   */
    if (tsidata = AllocMem(sizeof(struct TSIData), MEMF_PUBLIC|MEMF_CLEAR))
    {
        if(port = AllocMem(sizeof(struct MsgPort), MEMF_PUBLIC|MEMF_CLEAR))
        {
            NewList(&(port->mp_MsgList));                             /* Initialize message list */
            if (softint = AllocMem(sizeof(struct Interrupt), MEMF_PUBLIC|MEMF_CLEAR))
            {
                /* Set up the (software)interrupt structure. Note that this task runs at  */
                /* priority 0. Software interrupts may only be priority -32, -16, 0, +16, */
                /* +32. Also not that the correct node type for a software interrupt is   */
                /* NT_INTERRUPT. (NT_SOFTINT is an internal Exec flag). This is the same  */
                /* setup as that for a software interrupt which you Cause(). If our       */
                /* interrupt code was in assembler, you could initialize is_Data here to  */
                /* contain a pointer to shared data structures. An assembler software     */
                /* interrupt routine would receive the is_Data in A1.                     */

                softint->is_Code = tsoftcode;    /* The software interrupt routine */
                softint->is_Data = tsidata;
                softint->is_Node.ln_Pri = 0;

                port->mp_Node.ln_Type = NT_MSGPORT;       /* Set up the PA_SOFTINT message port  */
                port->mp_Flags = PA_SOFTINT;              /* (no need to make this port public). */
                port->mp_SigTask = (struct Task *)softint;     /* pointer to interrupt structure */

                /* Allocate timerequest */
                if (tr = (struct timerequest *) CreateExtIO(port, sizeof(struct timerequest)))
                {
                    /* Open timer.device. NULL is success. */
                    if (!(OpenDevice("timer.device", UNIT_MICROHZ, (struct IORequest *)tr, 0)))
                    {
                        tsidata->tsi_Flag = ON;        /* Init data structure to share globally. */
                        tsidata->tsi_Port = port;

                        /* Send of the first timerequest to start. IMPORTANT: Do NOT   */
                        /* BeginIO() to any device other than audio or timer from      */
                        /* within a software or hardware interrupt. The BeginIO() code */
                        /* may allocate memory, wait or perform other functions which  */
                        /* are illegal or dangerous during interrupts.                 */
                        printf("starting softint. CTRL-C to break...\n");


                        tr->tr_node.io_Command = TR_ADDREQUEST;    /* Initial iorequest to start */
                        tr->tr_time.tv_micro = MICRO_DELAY;        /* software interrupt.        */
                        BeginIO((struct IORequest *)tr);

                        Wait(SIGBREAKF_CTRL_C);
                        endcount = tsidata->tsi_Counter;
                        printf("timer softint counted %ld milliseconds.\n", endcount);

                        printf("Stopping timer...\n");
                        tsidata->tsi_Flag = OFF;

                        while (tsidata->tsi_Flag != STOPPED) Delay(10);

                        CloseDevice((struct IORequest *)tr);
                    }
                    else printf("couldn't open timer.device\n");
                    DeleteExtIO(tr);
                }
                else printf("couldn't create timerequest\n");
                FreeMem(softint, sizeof(struct Interrupt));
            }
            FreeMem(port, sizeof(struct MsgPort));
        }
        FreeMem(tsidata, sizeof(struct TSIData));
    }
