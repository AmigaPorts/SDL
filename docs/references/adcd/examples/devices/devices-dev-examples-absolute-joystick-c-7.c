/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    game_io_msg->io_Command = GPD_SETCTYPE;
    game_io_msg->io_Flags   = IOF_QUICK;
    game_io_msg->io_Data    = (APTR)&type;
    game_io_msg->io_Length  = 1;
    DoIO( game_io_msg);
    success = TRUE;
    }
