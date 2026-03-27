/* Source: ADCD 2.1
 * Section: devices-apps-ilbmdemo-ilbmdemo-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmdemo-ilbmdemo-c.md
 */

    {
    LONG  error;
    ULONG class;
    UWORD code;
    WORD  mousex, mousey;

    while(msg = (struct IntuiMessage *)GetMsg(win->UserPort))
