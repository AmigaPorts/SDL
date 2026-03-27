/* Source: ADCD 2.1
 * Section: 22-the-signal-system-waiting-for-a-signal
 * Library: libraries
 * ADCD reference: libraries/22-the-signal-system-waiting-for-a-signal.md
 */

    consoleSignal = 1L << ConsolePort->mp_SigBit;
    timerSignal   = 1L << TimerPort->mp_SigBit;
    userSignal    = SIGBREAKF_CTRL_C;         /* Defined in <dos/dos.h> */

    signals = Wait(consoleSignal | timerSignal | userSignal);

    if (signals & consoleSignal)
        printf("new character\n");

    if (signals & timeOutSignal)
        printf("timeout\n");

    if (signals & userSignal)
        printf("User Ctrl-C Abort\n");
