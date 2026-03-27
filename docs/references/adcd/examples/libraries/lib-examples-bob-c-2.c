/* Source: ADCD 2.1
 * Section: lib-examples-bob-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-bob-c.md
 */

        Wait(1L << win->UserPort->mp_SigBit);
        while (NULL != (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
                {
                /* only CLOSEWINDOW and INTUITICKS are active */
                if (msg->Class == CLOSEWINDOW)
                        {
                        ReplyMsg((struct Message *)msg);
                        return;
                        }
                /* Must be INTUITICKS:  change x and y values on the fly.  Note:
                ** do not have to add window offset, Bob is relative to the
                ** window (sprite relative to screen).
                */
                myBob->BobVSprite->X = msg->MouseX + 20;
                myBob->BobVSprite->Y = msg->MouseY + 1;
                ReplyMsg((struct Message *)msg);
                }
        /* after getting a message, change image data on the fly */
        myBob->BobVSprite->ImageData =
                (myBob->BobVSprite->ImageData == bob_data1) ? bob_data2 : bob_data1;
        InitMasks(myBob->BobVSprite); /* set up masks for new image */
        bobDrawGList(win->RPort, ViewPortAddress(win));
        }
