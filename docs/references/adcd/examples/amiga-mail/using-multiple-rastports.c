/* Source: ADCD 2.1
 * Section: using-multiple-rastports
 * Library: amiga-mail
 * ADCD reference: amiga-mail/using-multiple-rastports.md
 */

    struct RastPort dataRP;
    struct RastPort clrRP;

    dataRP = *window->RPort;
    SetAPen(&dataRP,1);
    SetBPen(&dataRP,0);

    clrRP = *window->RPort;
    SetAPen(&clrRP,0);

    /* renders to the window's RastPort in color 1 */
    Text(&dataRP,"hello",5);

    /* clears a section of the window's RastPort in color 0 */
    RectFill(&clrRPort,0,0,10,10);
