/* Source: ADCD 2.1
 * Section: 5-gameport-events-setting-gameport-event-trigger-conditions
 * Library: devices
 * ADCD reference: devices/5-gameport-events-setting-gameport-event-trigger-conditions.md
 */

    struct IOStdReq *GameIO;

    void set_trigger_conditions(struct GamePortTrigger *GameTR)
    {
    GameIO->io_Command = GPD_SETTRIGGER;    /* set trigger conditions */
    GameIO->io_Data = (APTR)GameTR;         /* from GameTR */
    GameIO->io_Length = sizeof(struct GamePortTrigger);
    DoIO(GameIO);
    }
