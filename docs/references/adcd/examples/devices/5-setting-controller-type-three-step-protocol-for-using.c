/* Source: ADCD 2.1
 * Section: 5-setting-controller-type-three-step-protocol-for-using
 * Library: devices
 * ADCD reference: devices/5-setting-controller-type-three-step-protocol-for-using.md
 */

    If GPCT_NOCONTROLLER is returned, you have access to the gameport.
    Set the allocation flag to GPCT_MOUSE, GPCT_ABSJOYSTICK or
    GPCT_RELJOYSTICK if you use a system supported controller, or
    GPCT_ALLOCATED if you use a custom controller.

    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    BOOL set_controller_type(type)
    BYTE type;
    {

    BOOL success = FALSE;
    BYTE controller_type = 0;

    Forbid();                           /*critical section start */
    GameIO->io_Command = GPD_ASKCTYPE;  /* inquire current status */
    GameIO->io_Length = 1;
    GameIO->io_Flags = IOF_QUICK;
    GameIO->io_Data = (APTR)&controller_type; /* put answer in here */
    DoIO(GameIO);

    /* No one is using this device unit, let's claim it */
    if (controller_type == GPCT_NOCONTROLLER)
        {
        GameIO->io_Command = GPD_SETCTYPE;/* set controller type */
        GameIO->io_Length = 1;
        GameIO->io_Data = (APTR)&type;  /* set to input param */
        DoIO( GameIO);
        success = TRUE;
        UnitOpened = TRUE;
        }
    Permit(); /* critical section end */

    /* success can be TRUE or FALSE, see above */
    return(success);
    }
