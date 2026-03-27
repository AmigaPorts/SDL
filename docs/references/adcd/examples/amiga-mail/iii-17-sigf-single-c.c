/* Source: ADCD 2.1
 * Section: iii-17-sigf-single-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-17-sigf-single-c.md
 */

    if (output = Open("*", MODE_OLDFILE))       /* Open the console for the  */
                                                /*            child process. */
    {
        mainprocess = (struct Process *)FindTask(NULL);/* childprocess can   */
                                                       /* access this global.*/

        if (childprocess = CreateNewProcTags(
                    NP_Entry,       childprocesscode,  /* The child process  */
                    NP_StackSize,   2000L,             /*              code. */
                    NP_Name,        childprocessname,
                    NP_Output,      output,
                    NP_FreeSeglist, FALSE,
                    NP_CloseOutput, TRUE,
                    TAG_DONE,       0L))

        {                                   /* I split the PutStr() into two */
            PutStr("Main Process: Created a child process"); /* to fit code  */
            PutStr(" and waiting on SIGF_SINGLE.\n");        /* on an 8.5 by */
                                                             /* 11 page.     */

            Flush(Output());    /* Make sure the PutStr() above appears      */
                                /* in the console window before the child    */
                                /* process start PutStr()ing to the console. */


            SetSignal(0L, SIGF_SINGLE);        /* Use SIGF_SINGLE only after */
                                               /* clearing it.               */

            /* Wake up the child. */
            Signal((struct Task *)childprocess,SIGBREAKF_CTRL_F);

            Wait(SIGF_SINGLE);     /* Only use SIGF_SINGLE for Wait()ing and */
                                   /* Wait on that signal alone!             */

            PutStr("Main Process: Received signal from child.\n");
        }
        else
            PutStr("Main Process: Can't create child process. Exiting.\n");
    }
    else
        PutStr("Main Process: Can't open CON:.  Exiting.\n");
