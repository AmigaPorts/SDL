/* Source: ADCD 2.1
 * Section: lib-examples-maprawkey-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-maprawkey-c.md
 */

    struct IntuiMessage *imsg;
    APTR                *eventptr;
    struct InputEvent   inputevent = {0};
    LONG                windowsignal;
    UBYTE               buffer[8];
    COUNT               i;
    BOOL                Done = FALSE;

    openall();

    window = OpenWindowTags(NULL,
                            WA_Width,  500,
                            WA_Height, 60,
                            WA_Title, "MapRawKey - Press Keys",
                            WA_Flags, WFLG_CLOSEGADGET | WFLG_ACTIVATE,
                            WA_IDCMP, IDCMP_RAWKEY | IDCMP_CLOSEWINDOW,
                            TAG_DONE);
    if(window == NULL)   closeout("Can't open window",RETURN_FAIL);

    windowsignal = 1L << window->UserPort->mp_SigBit;

    /* Initialize InputEvent structure (already cleared to 0) */
    inputevent.ie_Class = IECLASS_RAWKEY;

    while(!Done)
       {
       Wait(windowsignal);

       while (imsg = (struct IntuiMessage *)GetMsg(window->UserPort))
           {
           switch(imsg->Class)
               {
                case IDCMP_CLOSEWINDOW:
                    Done = TRUE;
                    break;

                case IDCMP_RAWKEY:
                    inputevent.ie_Code = imsg->Code;
                    inputevent.ie_Qualifier = imsg->Qualifier;

                    printf("RAWKEY: Code=$%04x  Qualifier=$%04lx\n",
                             imsg->Code, imsg->Qualifier);

                    /* Make sure deadkeys and qualifiers are taken
                     * into account.
                     */
                    eventptr = imsg->IAddress;
                    inputevent.ie_EventAddress = *eventptr;

                    /* Map RAWKEY to ANSI */
                    i = MapRawKey(&inputevent, buffer, 8, NULL);

                    if (i == -1) Write(Output(),"*Overflow*",10);
                    else if (i)
                        {
                        /* This key or key combination mapped to something */
                        printf("MAPS TO: ");
                        Write(Output(),buffer,i);
                        printf("\n");
                        }
                    break;
                }
            ReplyMsg((struct Message *)imsg);
            }
        }
    CloseWindow(window);
    closeall();
    exit(RETURN_OK);
