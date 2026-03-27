/* Source: ADCD 2.1
 * Section: devices-modules-screen-c
 * Library: libraries
 * ADCD reference: libraries/devices-modules-screen-c.md
 */

    {
    struct NewScreen ns;			/* for old style OpenScreen */
    struct Rectangle spos, dclip, txto, stdo, maxo, uclip;  /* display rectangles */
    struct Rectangle *uclipp;
    struct Screen   *scr = NULL;
    LONG   error, trynew;
    ULONG  bitmaptag, passedtags;
    BOOL   vctl;

    if (trynew = ((((struct Library *)GfxBase)->lib_Version >= 36)&&
          (((struct Library *)IntuitionBase)->lib_Version >= 36)))
