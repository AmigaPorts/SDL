/* Source: ADCD 2.1
 * Section: vii-17-camg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-camg-c.md
 */

    /*
     * BEFORE USING A CAMG YOU HAVE READ, YOU MUST SCREEN OUT JUNK CAMGs AND
     * INAPPROPRIATE BITS IN OLD 16-BIT CAMGs. YOU MAY WANT TO PLACE THESE
     * FIRST TWO TESTS WITH YOUR CAMG-READING CODE TO SCREEN OUT BAD CAMGs
     * IMMEDIATELY.
     */

    /*
     * Knock bad bits out of old-style CAMG modes before checking availability.
     * (some ILBM CAMG's have these bits set in old 1.3 modes, and should not)
     * If not an extended monitor ID, or if marked as extended but missing
     * upper 16 bits, screen out inappropriate bits now.
     */
    if ((!(modeid & MONITOR_ID_MASK)) ||
        ((modeid & EXTENDED_MODE) && (!(modeid & 0xFFFF0000))))
        modeid &=
            (~(EXTENDED_MODE | SPRITES | GENLOCK_AUDIO | GENLOCK_VIDEO | VP_HIDE));

    /*
     * Check for bogus CAMG like some brushes have, with junk in upper word and
     * extended bit NOT set not set in lower word.
     */
    if ((modeid & 0xFFFF0000) && (!(modeid & EXTENDED_MODE)))
    {
        /*
         * Bad CAMG, so ignore CAMG and determine a mode based on based on
         * pagesize or aspect
         */
        modeid = NULL;
        if (wide >= 640)
            modeid |= HIRES;
        if (high >= 400)
            modeid |= LACE;
    }
