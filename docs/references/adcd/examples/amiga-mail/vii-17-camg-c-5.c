/* Source: ADCD 2.1
 * Section: vii-17-camg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-camg-c.md
 */

    extern struct Library *GfxBase;
    ULONG           newmodeid;

    /*
     * Here you should either be asking the user what mode they want OR
     * searching the display database and choosing an appropriate replacement
     * mode based on what you or the user deem important (colors, or aspect, or
     * size, etc.).  You could also use a built in table for modes you know
     * about, and substitute mode you wish to use when the desired mode is not
     * available.
     *
     * This simple routine simply masks out everything but old modes. This is a
     * way to get some kind of display open but not necessarily a suitable or
     * compatible display.
     */

    newmodeid = modeid & (HIRES | LACE | HAM | EXTRA_HALFBRITE);
