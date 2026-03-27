/* Source: ADCD 2.1
 * Section: v-23-rotate-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-rotate-c.md
 */

    rectangle.MinX = w->BorderLeft;                    /* a clipping            */
    rectangle.MinY = w->BorderTop;                     /* region to the         */
    rectangle.MaxX = w->Width  - w->BorderRight - 1;   /* window to keep        */
    rectangle.MaxY = w->Height - w->BorderBottom - 1;  /* the glyph within      */
                                                       /* window bounds.        */
    if (region = NewRegion())                          /* For more information, */
    {                                                  /* see the "Layers"      */
      if (OrRectRegion(region, &rectangle))            /* chapter of the        */
      {                                                /* RKRM: Libraries       */
        InstallClipRegion(w->WLayer, region);          /* Manual.               */

        if (SetInfo(ge,
                    OT_GlyphCode, unicode,                      /* Set the glyph to */
                    OT_PointHeight, (ULONG) pointheight << 16,  /* rotate and its   */
                    TAG_END) == OTERR_Success)                  /* pointsize.       */
        {
          SetDrMd(w->RPort, JAM1);
          if (tempbitmap = AllocRaster(640, 200))
          {
            if (ModifyIDCMP(w, IDCMP_CLOSEWINDOW)) /* Turn on close window reports  */
            {                                      /* so the example can quit.      */
              for (i = 0; done == FALSE; i++)
              {
                if (i == TABLE_ENTRIES)
                  i = 0;

                sin = table[i][SINE_INDEX];   /* Step through the sine/cosine array */
                cos = table[i][COSINE_INDEX]; /* 360 degrees @ 15 degree increments */

                if (SetInfo(ge,                  /* Set the current rotation angle. */
                            OT_RotateSin, sin,
                            OT_RotateCos, cos,
                            TAG_END) == OTERR_Success)
                {
                  if ((ObtainInfo(ge, OT_GlyphMap, &gm, TAG_END)) == OTERR_Success)
                  {
                    oldx = x;               /* Calculate the dimension and position */
                    oldy = y;               /* of the new glyph's bitmap and save   */
                    olddx = dx;             /* the old values so we can erase the   */
                    olddy = dy;             /* glyph that is still on the screen.   */
                    x = centerx - gm->glm_X0;
                    y = centery - gm->glm_Y0;
                    dx = gm->glm_BMModulo * 8;
                    dy = gm->glm_BMRows;

                    CopyMem(gm->glm_BitMap,/* Copy the glyph's bitmap into Chip RAM */
                            tempbitmap,    /* so we can blit it into a RastPort.    */
                            gm->glm_BMModulo * gm->glm_BMRows);

                                                            /* Erase the old glyph. */
                    RectFill(rp, oldx, oldy, oldx + olddx, oldy + olddy);

                    WaitBlit();                 /* Wait for the old glyph to erase. */

                    BltTemplate(                   /* Blit the new glyph into the   */
                                 tempbitmap,       /* window's RastPort.            */
                                 0,
                                 gm->glm_BMModulo,
                                 w->RPort,
                                 x,
                                 y,
                                 dx,
                                 dy);          /* Running several instances of this */
                                               /* example simultaneously can really */
                                               /* slow the system, so we give other */
                    TimeDelay(UNIT_VBLANK, 0, 250000);  /*   tasks a chance to run. */
                    ReleaseInfo(ge, OT_GlyphMap, gm, TAG_END);
                  }
                }                               /* Check for a CLOSEWINDOW message. */
                while (mymsg = (struct IntuiMessage *) GetMsg(w->UserPort))
                {
                  ReplyMsg((struct Message *) mymsg);
                  done = TRUE;
                }
              }
            }
            FreeRaster(tempbitmap, 640, 200);
          }
        }
      }
      DisposeRegion(region);
    }
    CloseLibrary(LayersBase);
