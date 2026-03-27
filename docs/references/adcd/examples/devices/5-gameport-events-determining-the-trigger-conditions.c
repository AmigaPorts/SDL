/* Source: ADCD 2.1
 * Section: 5-gameport-events-determining-the-trigger-conditions
 * Library: devices
 * ADCD reference: devices/5-gameport-events-determining-the-trigger-conditions.md
 */

    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    struct GamePortTrigger GameTR;

    void get_trigger_conditions(struct GamePortTrigger *GameTR)
    {
    GameIO->io_Command = GPD_ASKTRIGGER;    /* get type of triggers */
    GameIO->io_Data = (APTR)GameTR;         /* place data here */
    GameIO->io_Length= sizeof(GameTR);
    DoIO(GameIO);
    }
