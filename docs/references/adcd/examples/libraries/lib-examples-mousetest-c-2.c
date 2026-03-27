/* Source: ADCD 2.1
 * Section: lib-examples-mousetest-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mousetest-c.md
 */

    {
    Wait((1L<<win->UserPort->mp_SigBit));

    while ((!done) &&
           (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        switch (msg->Class)
            {
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;
            /* NOTE NOTE NOTE:  If the mouse queue backs up a lot, Intuition
            ** will start dropping MOUSEMOVE messages off the end until the
            ** queue is serviced.  This may cause the program to lose some
            ** of the MOUSEMOVE events at the end of the stream.
            **
            ** Look in the window structure if you need the true position
            ** of the mouse pointer at any given time.  Look in the
            ** MOUSEBUTTONS message if you need position when it clicked.
            ** An alternate to this processing would be to set a flag that
            ** a mousemove event arrived, then print the position of the
            ** mouse outside of the "while (GetMsg())" loop.  This allows
            ** a single processing call for many mouse events, which speeds
            ** up processing A LOT!  Something like:
            **
            ** while (GetMsg())
            **    {
            **    if (class == IDCMP_MOUSEMOVE)
            **        mouse_flag = TRUE;
            **    ReplyMsg();   NOTE: copy out all needed fields first !
            **    }
            ** if (mouse_flag)
            **    {
            **    process_mouse_event();
            **    mouse_flag = FALSE;
            **    }
            **
            ** You can also use IDCMP_INTUITICKS for slower paced messages
            ** (all messages have mouse coordinates.)
            */
            case IDCMP_MOUSEMOVE:
                /* Show the current position of the mouse relative to the
                ** upper left hand corner of our window
                */
                Move(win->RPort,xText,yText);
                sprintf(prt_buff, "X%5d Y%5d", msg->MouseX, msg->MouseY);
                Text(win->RPort,prt_buff,13);
                break;
            case IDCMP_MOUSEBUTTONS:
                doButtons(msg,&tv);
                break;
            }
        ReplyMsg((struct Message *)msg);
        }
    }
