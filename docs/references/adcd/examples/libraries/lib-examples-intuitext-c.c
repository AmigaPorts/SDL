/* Source: ADCD 2.1
 * Section: lib-examples-intuitext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-intuitext-c.md
 */

    {
    if (screen = LockPubScreen(NULL))
        {
        if (drawinfo = GetScreenDrawInfo(screen))
            {
            /* Get a copy of the correct pens for the screen.
            ** This is very important in case the user or the
            ** application has the pens set in a unusual way.
            */
            myTEXTPEN = drawinfo->dri_Pens[TEXTPEN];
            myBACKGROUNDPEN  = drawinfo->dri_Pens[BACKGROUNDPEN];

            /* create a TextAttr that matches the specified font. */
            myTextAttr.ta_Name  = drawinfo->dri_Font->tf_Message.mn_Node.ln_Name;
            myTextAttr.ta_YSize = drawinfo->dri_Font->tf_YSize;
            myTextAttr.ta_Style = drawinfo->dri_Font->tf_Style;
            myTextAttr.ta_Flags = drawinfo->dri_Font->tf_Flags;

            /* open a simple window on the workbench screen for displaying
            ** a text string.  An application would probably never use such a
            ** window, but it is useful for demonstrating graphics...
            */
            if (win = OpenWindowTags(NULL,
                                WA_PubScreen,    screen,
                                WA_RMBTrap,      TRUE,
                                TAG_END))
                {
                myIText.FrontPen    = myTEXTPEN;
                myIText.BackPen     = myBACKGROUNDPEN;
                myIText.DrawMode    = JAM2;
                myIText.LeftEdge    = MYTEXT_LEFT;
                myIText.TopEdge     = MYTEXT_TOP;
                myIText.ITextFont   = &myTextAttr;
                myIText.IText       = "Hello, World.  ;-)";
                myIText.NextText    = NULL;

                /* Draw the text string at 10,10 */
                PrintIText(win->RPort,&myIText,10,10);

                /* Wait a bit, then quit.
                ** In a real application, this would be an event loop,
                ** like the one described in the Intuition Input and
                ** Output Methods chapter.
                */
                Delay(200);

                CloseWindow(win);
                }
            FreeScreenDrawInfo(screen,drawinfo);
            }
        UnlockPubScreen(NULL,screen);
        }
    CloseLibrary(IntuitionBase);
    }
