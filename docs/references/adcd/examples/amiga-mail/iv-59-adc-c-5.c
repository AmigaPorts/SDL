/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    short height, i;

    if (win)
    {
        SetRast(win->RPort, 0);
        SetAPen(win->RPort, 1);
        SetDrMd(win->RPort, JAM1);
        height = win->RPort->Font->tf_YSize + 2;

        for (i = 1; i < amicount; ++i)
        {
            Move(win->RPort, 0, height * i);
            Text(win->RPort, appName[i], strlen(appName[i]));
        }

        /* update newwindow structure with new size/location    */
        newwin.LeftEdge = win->LeftEdge;
        newwin.TopEdge  = win->TopEdge;
        newwin.Width    = win->Width;
        newwin.Height   = win->Height;
    }
