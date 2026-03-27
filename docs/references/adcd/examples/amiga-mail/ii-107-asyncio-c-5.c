/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    if (file->af_BytesLeft)
    {
        /* if there is at least a byte left in the current buffer, get it
         * directly. Also update all counters
         */

        ch = *(char *)file->af_Offset;
        file->af_BytesLeft--;
        file->af_Offset = (APTR)((ULONG)file->af_Offset + 1);

        return((LONG)ch);
    }

    /* there were no characters in the current buffer, so call the main read
     * routine. This has the effect of sending a request to the file system to
     * have the current buffer refilled. After that request is done, the
     * character is extracted for the alternate buffer, which at that point
     * becomes the "current" buffer
     */

    if (ReadAsync(file,&ch,1) > 0)
        return((LONG)ch);

    /* We couldn't read above, so fail */

    return(-1);
