/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    int ret = (int) win;

    if ((BOOL) win != 0 && (BOOL) win != 1)
    {
        while ((ret = SysReqHandler(win, NULL, TRUE)) == -2)
            ;
        FreeSysRequest(win);
    }
    return ret;
