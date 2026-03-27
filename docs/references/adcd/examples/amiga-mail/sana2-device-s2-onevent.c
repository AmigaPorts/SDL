/* Source: ADCD 2.1
 * Section: sana2-device-s2-onevent
 * Library: amiga-mail
 * ADCD reference: amiga-mail/sana2-device-s2-onevent.md
 */

    If this device driver does not understand the specified event
    condition(s) then the command returns immediately with
    ios2_Req.io_Error set to S2_ERR_NOT_SUPPORTED and ios2_WireError
    S2WERR_BAD_EVENT.  A successful return will have ios2_Error set to
    zero ios2_WireError set to the event number.

    All pending requests for a particular event will be returned when
    that event occurs.

    All event types that cover a particular condition are returned when
    that condition occures. For instance, if an error is returned by
    a buffer management function during receive processing, events of
    types S2EVENT_ERROR, S2EVENT_RX and S2EVENT_BUFF would be returned if
    pending.

    Types ONLINE and OFFLINE return immediately if the device is
    already in the state to be waited for.
