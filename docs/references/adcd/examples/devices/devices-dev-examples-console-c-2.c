/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    struct IntuiMessage *winmsg;
    ULONG signals, conreadsig, windowsig;
    LONG lch;
    SHORT InControl = 0;
    BOOL Done = FALSE;
    UBYTE ch, ibuf;
    UBYTE obuf[200];
    BYTE error;

    FromWb = (argc==0L) ? TRUE : FALSE;

    if(!(IntuitionBase=OpenLibrary("intuition.library",0)))
         cleanexit("Can't open intuition\n",RETURN_FAIL);

    /* Create reply port and io block for writing to console */
    if(!(writePort = CreatePort("RKM.console.write",0)))
         cleanexit("Can't create write port\n",RETURN_FAIL);

    if(!(writeReq = (struct IOStdReq *)
                    CreateExtIO(writePort,(LONG)sizeof(struct IOStdReq))))
         cleanexit("Can't create write request\n",RETURN_FAIL);

    /* Create reply port and io block for reading from console */
    if(!(readPort = CreatePort("RKM.console.read",0)))
         cleanexit("Can't create read port\n",RETURN_FAIL);

    if(!(readReq = (struct IOStdReq *)
                   CreateExtIO(readPort,(LONG)sizeof(struct IOStdReq))))
         cleanexit("Can't create read request\n",RETURN_FAIL);

    /* Open a window */
    if(!(win = OpenWindow(&nw)))
         cleanexit("Can't open window\n",RETURN_FAIL);

    /* Now, attach a console to the window */
    if(error = OpenConsole(writeReq,readReq,win))
         cleanexit("Can't open console.device\n",RETURN_FAIL);
    else OpenedConsole = TRUE;

    /* Demonstrate some console escape sequences */
    ConPuts(writeReq,"Here's some normal text\n");
    sprintf(obuf,"%s%sHere's text in color 3 & italics\n",COLOR03,ITALICS);
    ConPuts(writeReq,obuf);
    ConPuts(writeReq,NORMAL);
    Delay(50);      /* Delay for dramatic demo effect */
    ConPuts(writeReq,"We will now delete this asterisk =*=");
    Delay(50);
    ConPuts(writeReq,"\b\b");  /* backspace twice */
    Delay(50);
    ConPuts(writeReq,DELCHAR); /* delete the character */
    Delay(50);

    QueueRead(readReq,&ibuf); /* send the first console read request */

    ConPuts(writeReq,"\n\nNow reading console\n");
    ConPuts(writeReq,"Type some keys.  Close window when done.\n\n");

    conreadsig = 1 << readPort->mp_SigBit;
    windowsig = 1 << win->UserPort->mp_SigBit;

    while(!Done)
        {
        /* A character, or an IDCMP msg, or both could wake us up */
        signals = Wait(conreadsig|windowsig);

        /* If a console signal was received, get the character */
        if (signals & conreadsig)
            {
            if((lch = ConMayGetChar(readPort,&ibuf)) != -1)
                {
                ch = lch;
                /* Show hex and ascii (if printable) for char we got.
                 * If you want to parse received control sequences, such as
                 * function or Help keys,you would buffer control sequences
                 * as you receive them, starting to buffer whenever you
                 * receive 0x9B (or 0x1B[ for user-typed sequences) and
                 * ending when you receive a valid terminating character
                 * for the type of control sequence you are receiving.
                 * For CSI sequences, valid terminating characters
                 * are generally 0x40 through 0x7E.
                 * In our example, InControl has the following values:
                 * 0 = no, 1 = have 0x1B, 2 = have 0x9B OR 0x1B and [,
                 * 3 = now inside control sequence, -1 = normal end esc,
                 * -2 = non-CSI(no [) 0x1B end esc
                 * NOTE - a more complex parser is required to recognize
                 *  other types of control sequences.
                 */

                /* 0x1B ESC not followed by '[', is not CSI seq */
                if (InControl==1)
                    {
                    if(ch=='[') InControl = 2;
                    else InControl = -2;
                    }

                if ((ch==0x9B)||(ch==0x1B))  /* Control seq starting */
                    {
                    InControl = (ch==0x1B) ? 1 : 2;
                    ConPuts(writeReq,"=== Control Seq ===\n");
                    }

                /* We'll show value of this char we received */
                if (((ch >= 0x1F)&&(ch <= 0x7E))||(ch >= 0xA0))
                   sprintf(obuf,"Received: hex %02x = %c\n",ch,ch);
                else sprintf(obuf,"Received: hex %02x\n",ch);
                ConPuts(writeReq,obuf);

                /* Valid ESC sequence terminator ends an ESC seq */
                if ((InControl==3)&&((ch >= 0x40) && (ch <= 0x7E)))
                    {
                    InControl = -1;
                    }
                if (InControl==2) InControl = 3;
                /* ESC sequence finished (-1 if OK, -2 if bogus) */
                if (InControl < 0)
                    {
                    InControl = 0;
                    ConPuts(writeReq,"=== End Control ===\n");
                    }
                }
            }

        /* If IDCMP messages received, handle them */
        if (signals & windowsig)
            {
            /* We have to ReplyMsg these when done with them */
            while (winmsg = (struct IntuiMessage *)GetMsg(win->UserPort))
                {
                switch(winmsg->Class)
                    {
                    case CLOSEWINDOW:
                      Done = TRUE;
                      break;
                    default:
                      break;
                     }
                ReplyMsg((struct Message *)winmsg);
                }
            }
        }

    /* We always have an outstanding queued read request
     * so we must abort it if it hasn't completed,
     * and we must remove it.
     */
    if(!(CheckIO(readReq)))  AbortIO(readReq);
    WaitIO(readReq);     /* clear it from our replyport */

    cleanup();
    exit(RETURN_OK);
    }
