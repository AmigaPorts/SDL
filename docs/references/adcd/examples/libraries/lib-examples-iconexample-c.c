/* Source: ADCD 2.1
 * Section: lib-examples-iconexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-iconexample-c.md
 */

    {
    struct WBStartup *WBenchMsg;
    struct WBArg *wbarg;
    FILE  *file;
    LONG  wLen;
    SHORT i;

    FromWb = (argc==0) ? TRUE : FALSE;

    /* Open icon.library */
    if(!(IconBase = OpenLibrary("icon.library",33)))
         cleanexit("Can't open icon.library\n",RETURN_FAIL);

    /* If started from CLI, this example will create a small text
     * file RAM:Example_Project, and create an icon for the file
     * which points to this program as its default tool.
     */
    if(!FromWb)
        {
        /* Make a sample project (data) file */
        wLen = -1;
        if(file=fopen(projname,"w"))
            {
            wLen = fprintf(file,"Have a nice day\n");
            fclose(file);
            }
        if(wLen < 0) cleanexit("Error writing data file\n",RETURN_FAIL);

        /* Now save/update icon for this data file */
        if(makeIcon(projname, toolTypes, deftoolname))
             {
             printf("%s data file and icon saved.\n",projname);
             printf("Use Workbench menu Icon Information to examine the icon.\n");
             printf("Then copy this example (iconexample) to RAM:\n");
             printf("and double-click the %s project icon\n",projname);
             }
        else cleanexit("Error writing icon\n",RETURN_FAIL);
        }

    else  /* Else we are FromWb - ie. we were either
           * started by a tool icon, or as in this case,
           * by being the default tool of a project icon.
           */
        {
        if(!(conwin = fopen(conwinname,"r+")))
             cleanexit("Can't open output window\n",RETURN_FAIL);

        WBenchMsg = (struct WBStartup *)argv;

        /* Note wbarg++ at end of FOR statement steps through wbargs.
         * First arg is our executable (tool).  Any additional args
         * are projects/icons passed to us via either extend select
         * or default tool method.
         */
        for(i=0, wbarg=WBenchMsg->sm_ArgList;
            i < WBenchMsg->sm_NumArgs;
            i++, wbarg++)
            {
            /* if there's a directory lock for this wbarg, CD there */
            olddir = -1;
            if((wbarg->wa_Lock)&&(*wbarg->wa_Name))
                olddir = CurrentDir(wbarg->wa_Lock);

            showToolTypes(wbarg);

            if((i>0)&&(*wbarg->wa_Name))
                fprintf(conwin,"In Main. We could open the %s file here\n",
                                 wbarg->wa_Name);
            if(olddir != -1)  CurrentDir(olddir); /* CD back where we were */
            }
        Delay(500);
        }
    cleanup();
    exit(RETURN_OK);
    }
