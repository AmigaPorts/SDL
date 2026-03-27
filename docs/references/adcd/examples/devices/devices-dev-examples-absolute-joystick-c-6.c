/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    /* Send the read request */
    send_read_request(&game_event,game_io_msg);

    /* Wait for joystick action */
    Wait(1L << game_msg_port->mp_SigBit);
    while (NULL != GetMsg(game_msg_port))
        {
        timeout=FALSE;
        switch(game_event.ie_Code)
            {
            case IECODE_LBUTTON:
                printf(" FIRE BUTTON PRESSED \n");
                break;

            case (IECODE_LBUTTON | IECODE_UP_PREFIX):
                printf(" FIRE BUTTON RELEASED \n");
                if (3 == ++button_count)
                    not_finished = FALSE;
                break;

            case IECODE_RBUTTON:
                printf(" ALT BUTTON PRESSED \n");
                button_count = 0;
                break;

            case (IECODE_RBUTTON | IECODE_UP_PREFIX):
                printf(" ALT BUTTON RELEASED \n");
                button_count = 0;
                break;

            case IECODE_NOBUTTON:
                /* Check for change in position */
                timeout = check_move(&game_event);
                button_count = 0;
                break;

            default:
                break;
            }

        if (timeout)
            timeouts++;
        else
            timeouts=0;
        }
    }
