/* Source: ADCD 2.1
 * Section: lib-examples-cliptext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-cliptext-c.md
 */

    LONG count, actual, position;
    BOOL aok = TRUE, waitfornewsize = FALSE;
    struct Task *mytask;

    mytask = FindTask(NULL);
    Move(myrp, mywin->BorderLeft + 1, mywin->BorderTop + myfont->tf_YSize + 1);

    while (((actual = Read(myfile, buffer, BUFSIZE)) > 0) && aok) /* While there's something   */
    {                                                             /* to read, fill the buffer. */
        position = 0;
        count = 0;

        while (position <= actual)
        {
           if (!(waitfornewsize))
           {
               while ( ((buffer[count] >= myfont->tf_LoChar) &&
                       (buffer[count] <= myfont->tf_HiChar)) && (count <= actual) )
                   count++;

               Text(myrp, &(buffer[position]), (count)-position);

               while ( ((buffer[count] < myfont->tf_LoChar) ||
                       (buffer[count] > myfont->tf_HiChar)) && (count <= actual) )
               {
                   if (buffer[count] == 0x0A)
                       Move(myrp, mywin->BorderLeft, myrp->cp_y + myfont->tf_YSize + 1);
                   count++;
               }
               position = count;
           }
           else WaitPort(mywin->UserPort);

           while (mymsg = (struct IntuiMessage *)GetMsg(mywin->UserPort))
           {
               if (mymsg->Class == IDCMP_CLOSEWINDOW)     /* The user clicked the close gadget */
               {
                   aok = FALSE;
                   position = actual + 1;
                   ReplyMsg((struct Message *)mymsg);
               }                                                     /* The user picked up the */
               else if (mymsg->Class == IDCMP_SIZEVERIFY)            /* window's sizing gadget */
               {
                  /* When the user has picked up the window's sizing gadget when the           */
                  /* IDCMP_SIZEVERIFY flag is set, the application has to reply to this message*/
                  /* to tell Intuition to allow the user to move the sizing gadget and resize  */
                  /* the window.  The reason for using this here is because the user can resize*/
                  /* the window while cliptext.c is rendering text to the window. Cliptext.c   */
                  /* has to stop rendering text when it receives an IDCMP_SIZEVERIFY message.  */
                  /*                                                                           */
                  /* if this example had instead asked to hear about IDCMP events that could   */
                  /* take place between SIZEVERIFY and NEWSIZE events (especially INTUITICKS), */
                  /* it should turn off those events here using ModifyIDCMP().                 */
                  /*                                                                           */
                  /* After we allow the user to resize the window, we cannot write into the    */
                  /* window until the user has finished resizing it because we need the        */
                  /* window's new size to adjust the clipping area.  Specifically, we have     */
                  /* to wait for an IDCMP_NEWSIZE message which Intuition will send when the   */
                  /* user lets go of the resize gadget.  For now, we set the waitfornewsize    */
                  /* flag to stop rendering until we get that NEWSIZE message.                 */

                   waitfornewsize = TRUE;
                   WaitBlit();

                   ReplyMsg((struct Message *)mymsg);            /* The blitter is done, let the */
               }                                                 /* user resize the window.      */
               else
               {
                   ReplyMsg((struct Message *)mymsg);
                   waitfornewsize = FALSE;
                          /* The user has resized the window, so get the new window dimensions */
                   myrectangle.MinX = mywin->BorderLeft;      /* and readjust the layers       */
                   myrectangle.MinY = mywin->BorderTop;       /* clipping region accordingly.  */
                   myrectangle.MaxX = mywin->Width - (mywin->BorderRight + 1);
                   myrectangle.MaxY = mywin->Height - (mywin->BorderBottom + 1);
                   InstallClipRegion(mywin->WLayer, NULL);
                   ClearRegion(new_region);
                   if (OrRectRegion(new_region, &myrectangle))
                       InstallClipRegion(mywin->WLayer, new_region);
                   else
                   {
                       aok = FALSE;
                       position = actual + 1;
                   }
               }
           }
           if (mytask->tc_SigRecvd & SIGBREAKF_CTRL_C)              /* Check for user break.   */
           {
               aok = FALSE;
               position = actual + 1;
           }

           if (myrp->cp_y > (mywin->Height - (mywin->BorderBottom + 2))) /* if we reached the  */
           {                                               /* bottom of the page, clear the    */
               Delay(25);                                  /* rastport and move back to the top*/

               SetRast(myrp, 0);      /* Set the entire rastport to color zero.  This will not */
               Move(myrp,             /* the window borders because of the layers clipping.    */
               mywin->BorderLeft + 1,
               mywin->BorderTop + myfont->tf_YSize + 1);
            }
        }
    }
    if (actual < 0) VPrintf("Error while reading\n", NULL);
