/* Source: ADCD 2.1
 * Section: 5-gameport-events-setting-gameport-event-trigger-conditions
 * Library: devices
 * ADCD reference: devices/5-gameport-events-setting-gameport-event-trigger-conditions.md
 */

    struct GamePortTrigger
    {
        UWORD    gpt_Keys;      /* key transition triggers */
        UWORD    gpt_Timeout;   /* time trigger (vertical blank units) */
        UWORD    gpt_XDelta;    /* X distance trigger */
        UWORD    gpt_YDelta;    /* Y distance trigger */
    }
