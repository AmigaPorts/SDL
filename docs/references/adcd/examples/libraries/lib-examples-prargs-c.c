/* Source: ADCD 2.1
 * Section: lib-examples-prargs-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-prargs-c.md
 */

    {
    /* AmigaDOS has a special facility that  allows a window  */
    /* with a console and a file handle to be easily created. */
    /* CON: windows allow you to use fprintf() with no hassle */
    if (NULL != (outFile = fopen("CON:0/0/640/200/PrArgs","r+")))
        {
        /* in SAS/Lattice, argv is a pointer to the WBStartup message
        ** when argc is zero.  (run under the Workbench.)
        */
        argmsg = (struct WBStartup *)argv ;
        wb_arg = argmsg->sm_ArgList ;         /* head of the arg list */

        fprintf(outFile, "Run from the workbench, %ld args.\n",
                         argmsg->sm_NumArgs);

        for (ktr = 0; ktr < argmsg->sm_NumArgs; ktr++, wb_arg++)
            {
            if (NULL != wb_arg->wa_Lock)
                {
                /* locks supported, change to the proper directory */
                olddir = CurrentDir(wb_arg->wa_Lock) ;

                /* process the file.
                ** If you have done the CurrentDir() above, then you can
                ** access the file by its name.  Otherwise, you have to
                ** examine the lock to get a complete path to the file.
                */
                fprintf(outFile, "\tArg %2.2ld (w/ lock): '%s'.\n",
                                 ktr, wb_arg->wa_Name);

                /* change back to the original directory when done.
                ** be sure to change back before you exit.
                */
                CurrentDir(olddir) ;
                }
            else
                {
                /* something that does not support locks */
                fprintf(outFile, "\tArg %2.2ld (no lock): '%s'.\n",
                                 ktr, wb_arg->wa_Name);
                }
            }
        /* wait before closing down */
        Delay(500L);
        fclose(outFile);
        }
    }
