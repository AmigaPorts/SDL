/* Source: ADCD 2.1
 * Section: lib-examples-mapansi-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mapansi-c.md
 */

    KeymapBase = OpenLibrary("keymap.library", 37);
    if (KeymapBase == NULL)  closeout("Kickstart 2.0 required", RETURN_FAIL);

    CxBase = OpenLibrary("commodities.library", 37);
    if (CxBase == NULL)  closeout("Kickstart 2.0 required", RETURN_FAIL);

    InputEvent = AllocMem(sizeof(struct InputEvent), MEMF_CLEAR);
    if (InputEvent == NULL)  closeout("Can't allocate input event",RETURN_FAIL);
