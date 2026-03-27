/* Source: ADCD 2.1
 * Section: lib-examples-pubscreenbeep-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-pubscreenbeep-c.md
 */

      {
      /* OK, we have the right version of the OS so we can use
      ** the new public screen functions of Release 2 (V36)
      */
      if(NULL!=(my_wbscreen_ptr=LockPubScreen("Workbench")))
          {
          /* OK found the Workbench screen.                      */
          /* Normally the program would be here.  A window could */
          /* be opened or the attributes of the screen copied    */
          DisplayBeep(my_wbscreen_ptr);

          UnlockPubScreen(NULL,my_wbscreen_ptr);
          }
      }
