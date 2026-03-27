/*
 * SDL2 Timer -- AmigaOS 3.x (timer.device / ReadEClock)
 *
 * Phase 0: Stub.
 * Phase 5: ReadEClock-based high-resolution timing.
 */

unsigned long OS3_GetTicks(void)
{
    /* TODO Phase 5: ReadEClock() */
    return 0;
}

void OS3_Delay(unsigned long ms)
{
    (void)ms;
    /* TODO Phase 5: timer.device TR_ADDREQUEST */
}
