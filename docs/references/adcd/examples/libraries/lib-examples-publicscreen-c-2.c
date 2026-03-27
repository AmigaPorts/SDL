/* Source: ADCD 2.1
 * Section: lib-examples-publicscreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-publicscreen-c.md
 */

    {
    /* get the DrawInfo structure from the locked screen */
    screen_drawinfo = GetScreenDrawInfo(pub_screen);
    if ( screen_drawinfo != NULL)
        {
        /* the pens are copied in the OpenScreenTagList() call,
        ** so we can simply use a pointer to the pens in the tag list.
        **
        ** This works better if the depth and colors of the new screen
        ** matches that of the public screen.  Here we are forcing the
        ** workbench screen pens on a monochrome screen (which may not
        ** be a good idea).  You could add the tag:
        **      (SA_Depth, screen_drawinfo->dri_Depth)
        */
        screen_tags[0].ti_Tag  = SA_Pens;
        screen_tags[0].ti_Data = (ULONG)(screen_drawinfo->dri_Pens);
        screen_tags[0].ti_Tag  = TAG_END;
        screen_tags[0].ti_Data = NULL;

        my_screen = OpenScreenTagList(NULL, screen_tags);
        if (my_screen != NULL)
            {
            /* We no longer need to hold the lock on the public screen
            ** or a copy of its DrawInfo structure as we now have our
            ** own screen.  Release the screen.
            */
            FreeScreenDrawInfo(pub_screen,screen_drawinfo);
            screen_drawinfo = NULL;
            UnlockPubScreen(pubScreenName,pub_screen);
            pub_screen = NULL;

            Delay(90);   /* should be rest_of_program */

            CloseScreen(my_screen);
            }
        }
    }
