/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    if (ymove == 1) printf("DOWN\n");
    /* note that 0,0 can be a timeout, or a direction release. */
    else if (ymove == 0)
        {
        if (game_event->ie_TimeStamp.tv_secs >=
                        (UWORD)(SysBase->VBlankFrequency)*TIMEOUT_SECONDS)
            {
            printf("TIMEOUT\n");
            timeout=TRUE;
            }
        else printf("RELEASE\n");
        }
    else if (ymove ==-1) printf("UP\n");
    else printf("UNKNOWN Y\n");
    }
