/* Source: ADCD 2.1
 * Section: lib-examples-eventloop-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-eventloop-c.md
 */

    {
    if (win = OpenWindowTags(NULL,
                        WA_Title,       "Press Keys and Mouse in this Window",
                        WA_Width,       500,
                        WA_Height,      50,
                        WA_Activate,    TRUE,
                        WA_CloseGadget, TRUE,
                        WA_RMBTrap,     TRUE,
                        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_VANILLAKEY |
                            IDCMP_RAWKEY | IDCMP_DISKINSERTED |
                            IDCMP_DISKREMOVED | IDCMP_MOUSEBUTTONS,
                        TAG_END))
        {
        done = FALSE;

        /* perform this loop until the message handling routine signals
        ** that we are done.
        **
        ** When the Wait() returns, check which signal hit and process
        ** the correct port.  There is only one port here, so the test
        ** could be eliminated.  If multiple ports were being watched,
        ** the test would become:
        **
        **    signals = Wait( (1L << win1->UserPort->mp_SigBit) |
        **                    (1L << win2->UserPort->mp_SigBit) |
        **                    (1L << win3->UserPort->mp_SigBit))
        **    if (signals & (1L << win1->UserPort->mp_SigBit))
        **        done = handleWin1IDCMP(win1,done);
        **    else if (signals & (1L << win2->UserPort->mp_SigBit))
        **        done = handleWin2IDCMP(win2,done);
        **    else if (signals & (1L << win3->UserPort->mp_SigBit))
        **        done = handleWin3IDCMP(win3,done);
        **
        ** Note that these could all call the same routine with different
        ** window pointers (if the handling was identical).
        **
        ** handleIDCMP() should remove all of the messages from the port.
        */
        while (!done)
            {
            signals = Wait(1L << win->UserPort->mp_SigBit);
            if (signals & (1L << win->UserPort->mp_SigBit))
                done = handleIDCMP(win,done);
            };
        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
