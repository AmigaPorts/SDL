/* Source: ADCD 2.1
 * Section: gadtools-library-gt-beginrefresh
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-gt-beginrefresh.md
 */

    The nature of GadTools precludes the use of the IDCMP flag
    WFLG_NOCAREREFRESH.  You must handle IDCMP_REFRESHWINDOW events
    in at least the minimal way, namely:

            case IDCMP_REFRESHWINDOW:
                GT_BeginRefresh(win);
                GT_EndRefresh(win, TRUE);
                break;
