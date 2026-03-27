/* Source: ADCD 2.1
 * Section: devices-dev-examples-absolute-joystick-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-absolute-joystick-c.md
 */

    {
    /* Create message block for device IO */
    if (game_io_msg = (struct IOStdReq *)
                      CreateExtIO(game_msg_port,sizeof(*game_io_msg)))
        {
        game_io_msg->io_Message.mn_Node.ln_Type = NT_UNKNOWN;

        /* Open the right/back (unit 1, number 2) gameport.device unit */
        if (!OpenDevice("gameport.device",1,game_io_msg,0))
            {
            /* Set controller type to joystick */
            if (set_controller_type(GPCT_ABSJOYSTICK,game_io_msg))
                {
                /* Specify the trigger conditions */
                set_trigger_conditions(&joytrigger,game_io_msg);

                printInstructions();

                /* Clear device buffer to start from a known state.
                ** There might still be events left
                */
                flush_buffer(game_io_msg);

                processEvents(game_io_msg,game_msg_port);

                /* Free gameport unit so other applications can use it ! */
                free_gp_unit(game_io_msg);
                }
            CloseDevice(game_io_msg);
            }
        DeleteExtIO(game_io_msg);
        }
    DeletePort(game_msg_port);
    }
