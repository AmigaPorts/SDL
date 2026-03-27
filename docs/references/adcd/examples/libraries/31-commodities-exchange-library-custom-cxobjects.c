/* Source: ADCD 2.1
 * Section: 31-commodities-exchange-library-custom-cxobjects
 * Library: libraries
 * ADCD reference: libraries/31-commodities-exchange-library-custom-cxobjects.md
 */

    struct InputEvent *ie;
    UWORD mousequals = 0x0000;

    /* Get the struct InputEvent associated with this CxMsg.  Unlike
     * the InputEvent extracted from a CxSender's CxMsg, this is a
     *  *REAL* input event, be careful with it.
     */
    ie = (struct InputEvent *)CxMsgData(cxm);

    /* Check to see if this input event is a left or right mouse button
     * by itself (a mouse button can also be a qualifier).  If it is,
     * flip the low order bit to switch leftbutton <--> rightbutton.
     */
    if (ie->ie_Class == IECLASS_RAWMOUSE)
        if ((ie->ie_Code & CODEMASK) == CODEMASK)  ie->ie_Code ^= 0x0001;

    /* Check the qualifiers. If a mouse button was down when this */
    /* input event occurred, set the other mouse button bit.      */
    if (ie->ie_Qualifier & IEQUALIFIER_RBUTTON)  mousequals |=
                                                   IEQUALIFIER_LEFTBUTTON;
    if (ie->ie_Qualifier & IEQUALIFIER_LEFTBUTTON)  mousequals |=
                                                      IEQUALIFIER_RBUTTON;

    /* clear the RBUTTON and LEFTBUTTON qualifier bits */
    ie->ie_Qualifier &= ~(IEQUALIFIER_LEFTBUTTON | IEQUALIFIER_RBUTTON);

    /* set the mouse button qualifier bits to their new values */
    ie->ie_Qualifier |= mousequals;
