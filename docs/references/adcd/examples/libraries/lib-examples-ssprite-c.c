/* Source: ADCD 2.1
 * Section: lib-examples-ssprite-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-ssprite-c.md
 */

    {
    if (NULL == (IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",37L)))
        return_code = RETURN_FAIL;
    else
        {
        /* opened library, need a viewport to render a sprite over. */
        if (NULL == (screen = OpenScreenTagList(NULL, NULL)))
            return_code = RETURN_FAIL;
        else
            {
            viewport = &screen->ViewPort;
            if (-1 == (sprite_num = GetSprite(&sprite, 2)))
                return_code = RETURN_WARN;
            else
                {
                /* Calculate the correct base color register number, */
                /* set up the color registers.                       */
                color_reg = 16 + ((sprite_num & 0x06) << 1);
                printf("color_reg=%d\n", color_reg);
                SetRGB4(viewport, color_reg + 1, 12,  3,  8);
                SetRGB4(viewport, color_reg + 2, 13, 13, 13);
                SetRGB4(viewport, color_reg + 3,  4,  4, 15);

                sprite.x = 0;       /* initialize position and size info    */
                sprite.y = 0;       /* to match that shown in sprite_data   */
                sprite.height = 9;  /* so system knows layout of data later */

                /* install sprite data and move sprite to start position. */
                ChangeSprite(NULL, &sprite, (APTR)sprite_data);
                MoveSprite(NULL, &sprite, 30, 0);

                /* move the sprite back and forth. */
                for ( ktr1 = 0, delta_move = 1;
                      ktr1 < 6; ktr1++, delta_move = -delta_move)
                    {
                    for ( ktr2 = 0; ktr2 < 100; ktr2++)
                        {
                        MoveSprite( NULL, &sprite, (LONG)(sprite.x + delta_move),
                                    (LONG)(sprite.y + delta_move) );
                        WaitTOF(); /* one move per video frame */

                        /* Show the effect of turning off sprite DMA. */
                        if (ktr2 == 40) OFF_SPRITE ;
                        if (ktr2 == 60) ON_SPRITE ;
                        }
                    }
                /* NOTE:  if you turn off the sprite at the wrong time (when it
                ** is being displayed), the sprite will appear as a vertical bar
                ** on the screen.  To really get rid of the sprite, you must
                ** OFF_SPRITE while it is not displayed.  This is hard in a
                ** multi-tasking system (the solution is not addressed in
                ** this program).
                */
                ON_SPRITE ; /* just to be sure */
                FreeSprite((WORD)sprite_num);
                }
            (VOID) CloseScreen(screen);
            }
        CloseLibrary((struct Library *)IntuitionBase);
        }
    CloseLibrary((struct Library *)GfxBase);
    }
