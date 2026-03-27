/* Source: ADCD 2.1
 * Section: lib-examples-measuretext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-measuretext-c.md
 */

    if (myrp->cp_y > (w->Height - (w->BorderBottom + 2))) /* If we reached page bottom, clear the */
    {                                                     /* rastport and move back to the top.   */
        Delay(25);

        SetAPen(myrp, 0);
        RectFill(myrp, (LONG)w->BorderLeft, (LONG)w->BorderTop, w->Width - (w->BorderRight + 1),
                 w->Height - (w->BorderBottom + 1) );
        SetAPen(myrp, 1);
        Move(myrp, w->BorderLeft + 1, wtbarheight);
        SetAPen(myrp, fr->fo_FrontPen);
    }
