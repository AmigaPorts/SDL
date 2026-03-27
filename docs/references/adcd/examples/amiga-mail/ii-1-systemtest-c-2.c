/* Source: ADCD 2.1
 * Section: ii-1-systemtest-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-1-systemtest-c.md
 */

     */
    if(scr = OpenScreenTags(NULL,
                SA_Width, 640,
                SA_Height, 200,
                SA_Depth, 3,
                SA_DisplayID, HIRES_KEY,
                SA_Pens, &penspecterm,  /* Give us New Look */
                TAG_DONE))
        {
        if(win = OpenWindowTags(NULL,
                WA_CustomScreen, scr,
                WA_Flags, WINDOWDRAG|WINDOWCLOSE|ACTIVATE,
                WA_IDCMP, CLOSEWINDOW,
                WA_Top, 20,
                WA_Height, scr->Height - 20,
                WA_Title, "Custom Window",
                WA_ScreenTitle, "Custom Screen",
                TAG_DONE))
            {
            sprintf(buf,"CON://///WINDOW0x%lx", win); /* adds window pointer */
            if(file = Open(buf, MODE_OLDFILE))
                {
                command = "echo \"CLI commands on a custom screen!\"";
                result = doCommand(command,file);
                command = "dir libs:";
                result = doCommand(command,file);
                command = "echo \"( Click CLOSE gadget, or type CTRL-C )\"";
                result = doCommand(command,file);
                Wait(1 << win->UserPort->mp_SigBit | SIGBREAKF_CTRL_C);
                Close(file);    /* Closes the window too */
                }
            else CloseWindow(win);
            }
        CloseScreen(scr);
        }

    printf("\n*** SystemTest: Synchronous System call 'ask \"...Answer y now\"':\n");
    command = "ask \"Ready for Asynchronous demo? Answer y now (should return 5):\"";
    result = doCommand(command,NULL);
    checkResult(command,result);


    /* ASYNCHRONOUS SYSTEM() WITH ON-DEMAND AUTO/WAIT CON:
     */
    printf("\n*** SystemTest: Asynchronous startup of 'Sys:Utilities/Clock':\n");
    command = "SYS:Utilities/Clock";
    result = beginCommand(command);
    checkResult(command,result);

    printf("\n*** SystemTest: Asynchronous startup of 'avail':\n");
    command = "avail";
    result = beginCommand(command);
    checkResult(command,result);

    printf("\nSystemTest exiting. Close Clock and Autocon window when you wish.\n");

    CloseLibrary(IntuitionBase);
    exit(RETURN_OK);
    }
