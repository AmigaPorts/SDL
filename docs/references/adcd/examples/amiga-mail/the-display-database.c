/* Source: ADCD 2.1
 * Section: the-display-database
 * Library: amiga-mail
 * ADCD reference: amiga-mail/the-display-database.md
 */

    ULONG modeID;
    ULONG skipID;

    ULONG error, result;
    struct DisplayInfoHandle displayhandle;
    struct DisplayInfo displayinfo;
    struct NameInfo nameinfo;

    /* graphics.library must be opened */

    /* Don't want duplicate entries in the list for the
     * 'default monitor', so we'll skip the the videomode
     * for which default.monitor is the alias.
     */

    /* INVALID_ID indicates both the start and the end of the list of
       available keys */
    modeID = INVALID_ID;

    GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
            sizeof(struct DisplayInfo), DTAG_DISP, LORES_KEY);
    if (displayinfo.PropertyFlags & DIPF_IS_PAL)
        skipID = PAL_MONITOR_ID;
    else
        skipID = NTSC_MONITOR_ID;


    /* Given a ModeID, NextDisplayInfo
                        returns the next ModeID in the list */
    while((modeID = NextDisplayInfo(modeID)) != INVALID_ID) {

        /* Skip it? */
        if (modeID & MONITOR_ID_MASK != skipID) {

            /* ModeNotAvailable returns NULL if a displaymode,
               specified by the modeID, is available, or an error
               indicating why it is not available.
            */
            if ((error = ModeNotAvailable(modeID)) == NULL) {

                /* This displaymode is available, get the naming
                   information. GetDisplayInfoData, can either be
                   called with a handle to a displaymode record, or
                   the display modeID. Never use the handle directly.
                */

                /* returns NULL if not found */
                if (displayhandle = FindDisplayInfo(modeID)) {
                    result = GetDisplayInfoData(displayhandle,
                            (UBYTE *)&nameinfo, sizeof(struct NameInfo),
                            DTAG_NAME, NULL);
                    if (result)     /* 'result' indicates the number
                                        of bytes placed in the buffer */
                        printf("%s is available.\n", nameinfo.Name);
                }
            }
        }
    }
