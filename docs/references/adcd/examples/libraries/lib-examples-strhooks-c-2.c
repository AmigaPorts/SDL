/* Source: ADCD 2.1
 * Section: lib-examples-strhooks-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-strhooks-c.md
 */

    {
    /* key hit -- could be any key (Shift, repeat, character, etc.) */

    /* allow only upper case characters to be entered.
    ** act only on modes that add or update characters in the buffer.
    */
    if ((sgw->EditOp == EO_REPLACECHAR) ||
        (sgw->EditOp == EO_INSERTCHAR))
        {
        /* Code contains the ASCII representation of the character
        ** entered, if it maps to a single byte.  We could also look
        ** into the work buffer to find the new character.
        **
        **     sgw->Code == sgw->WorkBuffer[sgw->BufferPos - 1]
        **
        ** If the character is not a legal hex digit, don't use
        ** the work buffer and beep the screen.
        */
        if (!IsHexDigit(sgw->Code))
            {
            sgw->Actions |= SGA_BEEP;
            sgw->Actions &= ~SGA_USE;
            }
        else
            {
            /* And make it upper-case, for nicety */
            sgw->WorkBuffer[sgw->BufferPos - 1] = ToUpper(sgw->Code);
            }
        }
    }
