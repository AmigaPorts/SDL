/* Source: ADCD 2.1
 * Section: lib-examples-divert-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-divert-c.md
 */

    struct InputEvent *ie;
    static ULONG time = 0L;

    /* Get the struct InputEvent associated with this CxMsg. Unlike the InputEvent                */
    /* extracted from a CxSender's CxMsg, this is a *REAL* input event, be careful with it.       */
    ie = (struct InputEvent *)CxMsgData(cxm);

    /* This custom function counts the number of timer events that go by while no other input     */
    /* events occur.  If it counts more than a certain amount of timer events, it clears the      */
    /* count and diverts the timer event CxMsg to the custom object's personal                    */
    /* list.  If an event besides a timer event passes by, the timer event count is reset.        */
    if (ie->ie_Class == IECLASS_TIMER)
    {
        time++;
        if (time >= TIMER_CLICKS)
        {
            time = 0L;
            DivertCxMsg(cxm, co, co);
        }
    }
    else
        time = 0L;
