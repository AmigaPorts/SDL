/* Source: ADCD 2.1
 * Section: iv-111-boopsi-in-release-3
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-111-boopsi-in-release-3.md
 */

    ULONG	              MethodID;
    struct GadgetInfo  *gpl_GInfo;
    ULONG               gpl_Initial; /* This field is non-zero if this method was invoked
                                      * during AddGList() or OpenWindow().  zero if this
                                      * method was invoked during window resizing.
                                      */
