/* Source: ADCD 2.1
 * Section: lib-examples-rawkey-c
 * Library: devices
 * ADCD reference: devices/lib-examples-rawkey-c.md
 */

    Wait((1L<<win->UserPort->mp_SigBit));
    while ((done == FALSE) && (msg = (struct IntuiMessage *)GetMsg(win->UserPort))) {
        switch (msg->Class) {     /* handle our events */
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;
            case IDCMP_RAWKEY:
                if (FALSE == doKeys(msg,ievent,buffer,bufsize))
                    done = TRUE;
                break;
            }
        ReplyMsg((struct Message *)msg);
        }
    }
