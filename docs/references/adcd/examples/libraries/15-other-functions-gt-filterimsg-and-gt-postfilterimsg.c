/* Source: ADCD 2.1
 * Section: 15-other-functions-gt-filterimsg-and-gt-postfilterimsg
 * Library: libraries
 * ADCD reference: libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md
 */

    Warning:
    --------
    These functions are for specialized use only and will not be used by
    the majority of applications.  See [GT_GetIMsg()](../Libraries_Manual_guide/node025B.html) and
    [GT_ReplyIMsg()](../Libraries_Manual_guide/node025B.html) for standard message handling.


    struct IntuiMessage *GT_FilterIMsg( struct IntuiMessage *imsg );
    struct IntuiMessage *GT_PostFilterIMsg( struct IntuiMessage *imsg );
