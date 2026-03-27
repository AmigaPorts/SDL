# 5 / Gameport Events / Determining The Trigger Conditions


You determine the conditions required for triggering gameport events by
passing an I/O request to the device with [GPD_ASKTRIGGER](../Includes_and_Autodocs_2._guide/node04BB.html) set in
io_Command, the length of the [GamePortTrigger](../Devices_Manual_guide/node00B6.html#line8) structure set in io_Length
and the address of the structure set in io_Data.  The gameport device will
respond with the event trigger conditions currently set.


```c
    struct IOStdReq *GameIO;  /* Must be initialized prior to using */

    struct GamePortTrigger GameTR;

    void get_trigger_conditions(struct GamePortTrigger *GameTR)
    {
    GameIO->io_Command = GPD_ASKTRIGGER;    /* get type of triggers */
    GameIO->io_Data = (APTR)GameTR;         /* place data here */
    GameIO->io_Length= sizeof(GameTR);
    DoIO(GameIO);
    }
```
