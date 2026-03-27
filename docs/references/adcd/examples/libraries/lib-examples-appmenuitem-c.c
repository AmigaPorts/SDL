/* Source: ADCD 2.1
 * Section: lib-examples-appmenuitem-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-appmenuitem-c.md
 */

    {
    /* Add our own AppMenuItem to the Workbench Tools Menu */
    appitem=AddAppMenuItemA(0L,                   /* Our ID# for item */
                    (ULONG)"SYS:Utilities/More",  /* Our UserData     */
                           "Browse Files",        /* MenuItem Text    */
                            myport,NULL);         /* MsgPort, no tags */
    if(appitem)
      {
      printf("Select Workbench Tools demo menuitem 'Browse Files'\n");

      /* For this example, we allow the AppMenuItem to be selected */
      /* only once, then we remove it and exit                     */
      WaitPort(myport);
      while((appmsg=(struct AppMessage *)GetMsg(myport)) && (count<1))
        {
        /* Handle messages from the AppMenuItem - we have only one  */
        /* item so we don't have to check its appmsg->am_ID number. */
        /* We'll System() the command string that we passed as      */
        /* userdata when we added the menu item.                    */
        /* We find our userdata pointer in appmsg->am_UserData      */

        printf("User picked AppMenuItem with %ld icons selected\n",
                                                appmsg->am_NumArgs);
        for(x=0;x<appmsg->am_NumArgs;x++)
           printf("  #%ld name='%s'\n",x+1,appmsg->am_ArgList[x].wa_Name);

        count++;
        if( file=Open("CON:0/40/640/150/AppMenu Example/auto/close/wait",
                         MODE_OLDFILE)  )     /* for any stdio output */
          {
          result=SystemTags((UBYTE *)appmsg->am_UserData,SYS_Input,file,
                                                         SYS_Output,NULL,
                                                         SYS_Asynch,TRUE,
                                                         TAG_DONE);
          /* If Asynch System() itself fails, we must close file */
          if(result == -1) Close(file);
          }
        ReplyMsg((struct Message *)appmsg);
        }
      success=RemoveAppMenuItem(appitem);
      }

    /* Clear away any messages that arrived at the last moment */
    /* and let Workbench know we're done with the messages     */
    while(appmsg=(struct AppMessage *)GetMsg(myport))
      {
      ReplyMsg((struct Message *)appmsg);
      }
    DeleteMsgPort(myport);
    }
