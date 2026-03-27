/* Source: ADCD 2.1
 * Section: devices-dev-examples-swap-buttons-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-swap-buttons-c.md
 */

                                OpenLibrary("intuition.library",33L))
    {
    if (win=OpenWindow(&mywin))
        {
        WaitPort(win->UserPort);
        ReplyMsg(GetMsg(win->UserPort));

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
