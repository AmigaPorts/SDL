/* Source: ADCD 2.1
 * Section: 22-the-signal-system-signal-allocation
 * Library: libraries
 * ADCD reference: libraries/22-the-signal-system-signal-allocation.md
 */

    if (-1 == (signal = AllocSignal(-1)))
        printf("no signal bits available\n");
    else
        {
        printf("allocated signal number %ld\n", signal);
        /* Other code could go here */
        FreeSignal(signal)
        }
