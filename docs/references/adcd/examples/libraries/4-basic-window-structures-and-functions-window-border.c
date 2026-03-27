/* Source: ADCD 2.1
 * Section: 4-basic-window-structures-and-functions-window-border
 * Library: libraries
 * ADCD reference: libraries/4-basic-window-structures-and-functions-window-border.md
 */

    {
    top_border    = screen->WBorTop + screen->Font->ta_YSize + 1;
    left_border   = screen->WBorLeft;
    right_border  = screen->WBorRight;
    bottom_border = screen->WBorBottom;

    UnlockPubScreen(NULL,screen);
    }
