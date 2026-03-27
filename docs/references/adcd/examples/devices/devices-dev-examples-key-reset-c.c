/* Source: ADCD 2.1
 * Section: devices-dev-examples-key-reset-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-key-reset-c.md
 */

                   OpenLibrary("intuition.library",0L))
    {
    if (win=(struct Window *)OpenWindow(&mywin))
        {
        ret=(MySignal==Wait(MySignal | (1L << win->UserPort->mp_SigBit)));
        CloseWindow(win);
        }
    else
        printf("Error: Could not open window\n");
    CloseLibrary((struct Library *)IntuitionBase);
    }
