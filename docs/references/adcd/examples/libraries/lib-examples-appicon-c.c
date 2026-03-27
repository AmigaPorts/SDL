/* Source: ADCD 2.1
 * Section: lib-examples-appicon-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-appicon-c.md
 */

    {
    /* This is the easy way to get some icon imagery */
    /* Real applications should use custom imagery   */
    dobj=GetDefDiskObject(WBDISK);
    if(dobj!=0)
      {
      /* The type must be set to NULL for a WBAPPICON */
      dobj->do_Type=NULL;

      /* The CreateMsgPort() function is in Exec version 37 and later only */
      myport=CreateMsgPort();
      if(myport)
        {
        /* Put the AppIcon up on the Workbench window */
        appicon=AddAppIconA(0L,0L,"TestAppIcon",myport,NULL,dobj,NULL);
        if(appicon)
          {
          /* For the sake of this example, we allow the AppIcon */
          /* to be activated only five times.                   */
          printf("Drop files on the Workbench AppIcon\n");
          printf("Example exits after 5 drops\n");

          while(dropcount<5)
            {
            /* Here's the main event loop where we wait for */
            /* messages to show up from the AppIcon         */
            WaitPort(myport);

            /* Might be more than one message at the port... */
            while(appmsg=(struct AppMessage *)GetMsg(myport))
              {
              if(appmsg->am_NumArgs==0L)
                {
                /* If NumArgs is 0 the AppIcon was activated directly */
                printf("User activated the AppIcon.\n");
                printf("A Help window for the user would be good here\n");
                }
              else if(appmsg->am_NumArgs>0L)
                {
                /* If NumArgs is >0 the AppIcon was activated by */
                /* having one or more icons dropped on top of it */
                printf("User dropped %ld icons on the AppIcon\n",
                                              appmsg->am_NumArgs);
                for(x=0;x<appmsg->am_NumArgs;x++)
                  {
                  printf("#%ld name='%s'\n",x+1,appmsg->am_ArgList[x].wa_Name);
                  }
                }
              /* Let Workbench know we're done with the message */
              ReplyMsg((struct Message *)appmsg);
              }
            dropcount++;
            }
          success=RemoveAppIcon(appicon);
          }
        /* Clear away any messages that arrived at the last moment */
        while(appmsg=(struct AppMessage *)GetMsg(myport))
            ReplyMsg((struct Message *)appmsg);
        DeleteMsgPort(myport);
        }
      FreeDiskObject(dobj);
      }
    CloseLibrary(WorkbenchBase);
    }
