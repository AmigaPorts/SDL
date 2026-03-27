/* Source: ADCD 2.1
 * Section: 5-setting-controller-type-three-step-protocol-for-using
 * Library: devices
 * ADCD reference: devices/5-setting-controller-type-three-step-protocol-for-using.md
 */

    The program must set the controller type back to GPCT_NOCONTROLLER
    upon exiting your program:

    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    void free_gp_unit()
    {
    BYTE type = GPCT_NOCONTROLLER;
    GameIO->io_Command = GPD_SETCTYPE;  /* set controller type */
    GameIO->io_Length = 1;
    GameIO->io_Data = (APTR)&type;      /* set to unused */
    DoIO( GameIO);
    }
