/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    /* lock the window's layer so its size will not change */
    LockLayer(NULL,window->WLayer);

    /* determine various values based on the current size of the window */
    viewWidth      = window->Width - window->BorderLeft - window->BorderRight;
    fontWidth      = window->RPort->Font->tf_XSize;
    columnsVisible = viewWidth / fontWidth;

    viewHeight     = window->Height - window->BorderTop - window->BorderBottom;
    fontHeight     = window->RPort->Font->tf_YSize;
    linesVisible   = viewHeight / fontHeight;

    usefulWidth = columnsVisible * fontWidth;

    if (linesVisible > numLines)
    {
        usefulHeight = numLines * fontHeight;
        topLine      = 0;
    }
    else if (topLine + linesVisible > numLines)
    {
        topLine      = (numLines - linesVisible);
        usefulHeight = (numLines - topLine) * fontHeight;
    }
    else
    {
        usefulHeight = linesVisible * fontHeight;
    }

    /* if we were called because of damage, we must erase any left over
     * garbage
     */
    if (damage)
    {
        /* erase anything left over on the right side of the window */
        if ((window->BorderLeft + usefulWidth < window->Width - window->BorderRight)
        &&   usefulHeight)
        {
            RectFill(&clear,window->BorderLeft + usefulWidth,
                            window->BorderTop,
                            window->Width - window->BorderRight - 1,
                            window->BorderTop + usefulHeight - 1);
        }

        /* erase anything left over on the bottom of the window */
        if ((window->BorderLeft < window->Width - window->BorderRight)
        &&  (window->BorderTop + usefulHeight < window->Height - window->BorderBottom))
        {
            RectFill(&clear,window->BorderLeft,
                            window->BorderTop + usefulHeight,
                            window->Width - window->BorderRight - 1,
                            window->Height - window->BorderBottom - 1);
        }
    }

    /* if we have at least one line and one column to render... */
    if (usefulHeight && usefulWidth)
    {
        /* get a pointer to the first line currently visible */
        line = (struct Line *)document.mlh_Head;
        i    = topLine;
        while (line->ln_Link.mln_Succ && i--)
            line = (struct Line *)line->ln_Link.mln_Succ;

        if (damage
        || (topLine >= oldTopLine + linesVisible - 1)
        || ((oldTopLine > linesVisible)
        && (topLine <= oldTopLine - linesVisible + 1)))
        {
            /* the whole display must be redrawn */
            x = window->BorderLeft;
            y = window->BorderTop + window->RPort->Font->tf_Baseline;
            i = linesVisible;
        }
        else if (topLine < oldTopLine)
        {
            /* we just need to scroll the text */
            ScrollRaster(&render,0,-(LONG)((oldTopLine - topLine) * fontHeight),
                         window->BorderLeft,
                         window->BorderTop,
                         window->BorderLeft+usefulWidth-1,
                         window->BorderTop+usefulHeight-1);

            /* indicates what section needs to be redrawn */
            x = window->BorderLeft;
            y = window->BorderTop + window->RPort->Font->tf_Baseline;
            i = oldTopLine - topLine;
        }
        else if (topLine > oldTopLine)
        {
            /* we just need to scroll the text */
            ScrollRaster(&render,0,(topLine - oldTopLine) * fontHeight,
                         window->BorderLeft,
                         window->BorderTop,
                         window->BorderLeft+usefulWidth-1,
                         window->BorderTop+usefulHeight-1);

            /* indicates what section needs to be redrawn */
            i = linesVisible - (topLine - oldTopLine);
            while (line->ln_Link.mln_Succ && i--)
                line = (struct Line *)line->ln_Link.mln_Succ;

            x = window->BorderLeft;
            y = window->BorderTop + window->RPort->Font->tf_Baseline
                + (fontHeight * (linesVisible - (topLine - oldTopLine)));
            i = topLine - oldTopLine;
        }
        else
        {
            /* we don't need to render anything */
            i = 0;
        }

        /* render all the lines we need */
        while (i-- && line->ln_Link.mln_Succ)
        {
            RenderLine(x,y,usefulWidth,line->ln_Text,line->ln_TextLen);
            y    += fontHeight;
            line  = (struct Line *)line->ln_Link.mln_Succ;
        }
    }

    /* unlock the layer so normal operations can resume */
    UnlockLayer(window->WLayer);

    /* keep track of what the current top line is. That way, when we
     * come back in this routine later, and "topLine" has changed, we
     * can tell how many lines we need to scroll in order to sync up the
     * display
     */
    oldTopLine = topLine;
