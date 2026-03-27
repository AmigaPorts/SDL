/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

    struct List *dlist;
    struct DisplayNode *dnode;
    struct DisplayNode *wnode, *nnode;

    ULONG modeID;
    ULONG skipID;

    ULONG result;
    struct DisplayInfo displayinfo;
    struct NameInfo nameinfo;

    /* Fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (GfxBase = OpenLibrary("graphics.library", 36)) {
            if (GadToolsBase = OpenLibrary("gadtools.library", 36)) {
                if (dlist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
                    NewList(dlist);

                    /*
                     * Don't want duplicate entries in the list for the
                     * 'default monitor', so we'll skip the the videomode
                     * for which default.monitor is the alias.
                     */

                    /* INVALID_ID indicates the beginning and the end
