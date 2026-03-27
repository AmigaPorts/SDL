/* Source: ADCD 2.1
 * Section: lib-examples-appwindow-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-appwindow-c.md
 */

        /* Make sure there are no more outstanding messages */
        while(amsg = (struct AppMessage *)GetMsg(awport))
              ReplyMsg((struct Message *)amsg);
        DeleteMsgPort(awport);
        }
      CloseLibrary(WorkbenchBase);
      }
    CloseLibrary(IntuitionBase);
    }
