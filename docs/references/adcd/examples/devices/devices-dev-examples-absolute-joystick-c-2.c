/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    if (ymove == 1) printf("RIGHT DOWN\n");
    else if (ymove == 0) printf("RIGHT\n");
    else if (ymove ==-1) printf("RIGHT UP\n");
    else printf("UNKNOWN Y\n");
    }
