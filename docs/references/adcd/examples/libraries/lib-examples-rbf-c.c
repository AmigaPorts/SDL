/* Source: ADCD 2.1
 * Section: lib-examples-rbf-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rbf-c.md
 */

    struct RBFData *rbfdata;
    UBYTE *currentuser;
    BYTE signr;
    struct Device *serdevice;
    struct Interrupt *rbfint, *priorint;
    BOOL priorenable;
    ULONG signal;

    if (MiscBase = OpenResource("misc.resource"))
    {
        currentuser = AllocMiscResource(MR_SERIALPORT, allocname);        /* Allocate the serial */
        if (currentuser)                                                  /* port registers.     */
        {
            printf("serial hardware allocated by %s. Trying to remove it\n",
                   currentuser);                                         /* Hey! someone got it! */
            Forbid();
            if (serdevice = (struct Device *)FindName(&SysBase->DeviceList, currentuser))
                RemDevice(serdevice);
            Permit();

            currentuser = AllocMiscResource(MR_SERIALPORT, allocname);          /* and try again */
        }
        if (currentuser == NULL)
        {                                                                      /* Get the serial */
            currentuser = AllocMiscResource(MR_SERIALBITS, allocname);         /* control bits.  */
            if (currentuser)
            {
                printf("serial control allocated by %s\n", currentuser);            /* Give up. */
                FreeMiscResource(MR_SERIALPORT);
            }
            else
            {                                                                  /* Got them both. */
                printf("serial hardware allocated\n");
                if ((signr = AllocSignal(-1)) != -1)          /* Allocate a signal bit for the   */
                {                                             /* interrupt handler to signal us. */
                    if (rbfint = AllocMem(sizeof(struct Interrupt), MEMF_PUBLIC|MEMF_CLEAR))
                    {
                        if (rbfdata = AllocMem(sizeof(struct RBFData), MEMF_PUBLIC|MEMF_CLEAR))
                        {
                            rbfdata->rd_Task = FindTask(NULL);        /* Init rfbdata structure. */
                            rbfdata->rd_Signal = 1L << signr;

                            rbfint->is_Node.ln_Type = NT_INTERRUPT;      /* Init interrupt node. */
                            strcpy(rbfdata->rd_Name, allocname);
                            rbfint->is_Node.ln_Name = rbfdata->rd_Name;
                            rbfint->is_Data = (APTR)rbfdata;
                            rbfint->is_Code = RBFHandler;
                                                                        /* Save state of RBF and */
                            priorenable = custom.intenar & INTF_RBF ? TRUE : FALSE; /* interrupt */
                            custom.intena = INTF_RBF;                             /* disable it. */
                            priorint = SetIntVector(INTB_RBF, rbfint);

                            if (priorint) printf("replaced the %s RBF interrupt handler\n",
                                                 priorint->is_Node.ln_Name);
                            printf("enabling RBF interrupt\n");
                            custom.intena = INTF_SETCLR | INTF_RBF;

                            printf("waiting for buffer to fill up. Use CTRL-C to break\n");
                            signal = Wait(1L << signr | SIGBREAKF_CTRL_C);

                            if (signal & SIGBREAKF_CTRL_C) printf(">break<\n");
                            printf("Character buffer contains:\n%s\n", rbfdata->rd_CharBuffer);

                            custom.intena = INTF_RBF;               /* Restore previous handler. */
                            SetIntVector(INTB_RBF, priorint);
                                                                  /* Enable it if it was enabled */
                            if (priorenable) custom.intena = INTF_SETCLR|INTF_RBF;    /* before. */

                            FreeMem(rbfdata, sizeof(struct RBFData));
                        }
                        else  printf("can't allocate memory for rbf data\n");
                        FreeMem(rbfint, sizeof(struct Interrupt));
                    }
                    else printf("can't allocate memory for interrupt structure\n");
                    FreeSignal(signr);
                }
                else printf("can't allocate signal\n");

                FreeMiscResource(MR_SERIALBITS);   /* release serial hardware */
                FreeMiscResource(MR_SERIALPORT);
            }
        }
    } /* There is no 'CloseResource()' function */
