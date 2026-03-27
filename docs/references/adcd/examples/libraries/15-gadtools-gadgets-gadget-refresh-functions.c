/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-gadget-refresh-functions
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-gadget-refresh-functions.md
 */

    case IDCMP_REFRESHWINDOW:
        GT_BeginRefresh(win);
        /* custom rendering, if any, goes here */
        GT_EndRefresh(win, TRUE);
        break;
