/* Source: ADCD 2.1
 * Section: lib-examples-appwindow-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-appwindow-c.md
 */

    {
    if (WorkbenchBase = OpenLibrary("workbench.library", 37))
      {
      /* The CreateMsgPort() function is in Exec version 37 and later only */
      if (awport = CreateMsgPort())
         {
         if (win = OpenWindowTags(NULL,
                                  WA_Width, 200,        WA_Height, 50,
                                  WA_IDCMP, CLOSEWINDOW,
                                  WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                  WA_Title, "AppWindow",
                                  TAG_DONE))
          {
          if (appwin = AddAppWindow(id, userdata, win, awport, NULL))
            {
            printf("AppWindow added... Drag files into AppWindow\n");
            winsig    = 1L << win->UserPort->mp_SigBit;
            appwinsig = 1L << awport->mp_SigBit;

            while (! done)
              {
              /* Wait for IDCMP messages and AppMessages */
              signals = Wait( winsig | appwinsig );

              if(signals & winsig)      /* Got an IDCMP message */
                {
                while (imsg = (struct IntuiMessage *) GetMsg(win->UserPort))
                  {
                  if (imsg->Class = CLOSEWINDOW)   done = TRUE;
                  ReplyMsg((struct Message *) imsg);
                  }
                }
              if(signals & appwinsig)   /* Got an AppMessage */
                {
                while (amsg = (struct AppMessage *) GetMsg(awport))
                  {
                  printf("AppMsg: Type=%ld, ID=%ld, NumArgs=%ld\n",
                           amsg->am_Type, amsg->am_ID, amsg->am_NumArgs);
                  argptr = amsg->am_ArgList;
                  for (i = 0; i < amsg->am_NumArgs; i++)
                    {
                    printf("   arg(%ld): Name='%s', Lock=%lx\n",
                             i, argptr->wa_Name, argptr->wa_Lock);
                    argptr++;
                    }
                  ReplyMsg((struct Message *) amsg);
                  }
                }
              }     /* done */
            RemoveAppWindow(appwin);
            }
          CloseWindow(win);
