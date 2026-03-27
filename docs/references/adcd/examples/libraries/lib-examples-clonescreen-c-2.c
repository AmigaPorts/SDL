/* Source: ADCD 2.1
 * Section: lib-examples-clonescreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-clonescreen-c.md
 */

    {
    /* Get the DrawInfo structure from the locked screen
    ** This returns pen, depth and font info.
    */
    screen_drawinfo = GetScreenDrawInfo(pub_screen);
    if (screen_drawinfo != NULL)
        {
        screen_modeID = GetVPModeID(&(pub_screen->ViewPort));
        if( screen_modeID != INVALID_ID )
            {
            /* Get a copy of the font
            ** The name of the font must be copied as the public screen may
            ** go away at any time after we unlock it.
            ** Allocate enough memory to copy the font name, create a
            ** TextAttr that matches the font, and open the font.
            */
            pub_scr_font_name = screen_drawinfo->dri_Font->tf_Message.mn_Node.ln_Name;
            font_name_size = 1 + strlen(pub_scr_font_name);
            font_name = AllocMem(font_name_size, MEMF_CLEAR);
            if (font_name != NULL)
                {
                strcpy(font_name, pub_scr_font_name);
                pub_screen_font.ta_Name  = font_name;
                pub_screen_font.ta_YSize = screen_drawinfo->dri_Font->tf_YSize;
                pub_screen_font.ta_Style = screen_drawinfo->dri_Font->tf_Style;
                pub_screen_font.ta_Flags = screen_drawinfo->dri_Font->tf_Flags;

                opened_font = OpenFont(&pub_screen_font);
                if (opened_font != NULL)
                    {
                    /* screen_modeID may now be used in a call to
                    ** OpenScreenTagList() with the tag SA_DisplayID.
                    */
                    my_screen = OpenScreenTags(NULL,
                        SA_Width,      pub_screen->Width,
                        SA_Height,     pub_screen->Height,
                        SA_Depth,      screen_drawinfo->dri_Depth,
                        SA_Overscan,   OSCAN_TEXT,
                        SA_AutoScroll, TRUE,
                        SA_Pens,       (ULONG)(screen_drawinfo->dri_Pens),
                        SA_Font,       (ULONG)&pub_screen_font,
                        SA_DisplayID,  screen_modeID,
                        SA_Title,      "Cloned Screen",
                        TAG_END);
                    if (my_screen != NULL)
                        {
                        /* Free the drawinfo and public screen as we don't
                        ** need them any more.  We now have our own screen.
                        */
                        FreeScreenDrawInfo(pub_screen,screen_drawinfo);
                        screen_drawinfo = NULL;
                        UnlockPubScreen(pub_screen_name,pub_screen);
                        pub_screen = NULL;

                        Delay(300);   /* should be rest_of_program */

                        CloseScreen(my_screen);
                        }
                    CloseFont(opened_font);
                    }
                FreeMem(font_name, font_name_size);
                }
            }
        }
    }
