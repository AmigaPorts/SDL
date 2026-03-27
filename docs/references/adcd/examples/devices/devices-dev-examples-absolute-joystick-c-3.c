/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    if (ymove == 1) printf("LEFT DOWN\n");
    else if (ymove == 0) printf("LEFT\n");
    else if (ymove ==-1) printf("LEFT UP\n");
    else printf("UNKNOWN Y\n");
    }
