/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

    struct Screen *screen;
    struct Window *window;
    struct Gadget *glist, *gadget, *hitgadget;
    struct DrawInfo *drawinfo;
    struct TextFont *defaultfont;
    struct TextAttr *textattr;
    struct IntuiMessage *imsg;
    struct NewGadget *ng;
    struct Menu *menu;
    struct MenuItem *item;
    void *vi;
    ULONG iclass, icode, code;
    struct DisplayNode *dnode;
    struct DimensionInfo *dimensioninfo;
    ULONG overscantype = OSCAN_TEXT;
    ULONG curmode = 0;
    BOOL ABORT = TRUE, OK;
    int i;


    if (ng = AllocMem(sizeof(struct NewGadget), MEMF_CLEAR)) {
        if (textattr = AllocMem(sizeof(struct TextAttr), MEMF_CLEAR)) {
            if (textattr->ta_Name = AllocMem(48, MEMF_CLEAR)) {

                dnode = (struct DisplayNode *) dlist->lh_Head;

                if (menu = CreateMenus(sdm_menu, TAG_DONE)) {
                    do {
                        dimensioninfo = &(dnode->dn_Dimensioninfo);
                        OK = FALSE;
                        if (screen = OpenAScreen(dimensioninfo,
