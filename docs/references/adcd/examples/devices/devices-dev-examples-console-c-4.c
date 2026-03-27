/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    if(OpenedConsole) CloseConsole(writeReq);
    if(readReq)       DeleteExtIO(readReq);
    if(readPort)      DeletePort(readPort);
    if(writeReq)      DeleteExtIO(writeReq);
    if(writePort)     DeletePort(writePort);
    if(win)           CloseWindow(win);
    if(IntuitionBase) CloseLibrary(IntuitionBase);
    }
