/* Source: ADCD 2.1
 * Section: lib-examples-availfonts-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-availfonts-c.md
 */

    if (IntuitionBase = OpenLibrary("intuition.library", 37L))
    {
      if (GfxBase = OpenLibrary("graphics.library", 37L))
      {
        if (LayersBase = OpenLibrary("layers.library", 37L))
        {
          if (UtilityBase = OpenLibrary("utility.library", 37L))
          {
            if (mywin = OpenWindowTags(NULL,                              /* Open that window. */
                                    WA_SmartRefresh,TRUE,
                                    WA_SizeGadget,  FALSE,
                                    WA_CloseGadget, TRUE,
                                    WA_IDCMP,       IDCMP_CLOSEWINDOW,
                                    WA_DragBar,     TRUE,
                                    WA_DepthGadget, TRUE,
                                    WA_Title,       (ULONG)"AvailFonts() example",
                                    TAG_END))
            {
              myrp = *(mywin->RPort);       /* A structure assign: clone my window's Rastport. */
                                            /* RastPort.  This RastPort will be used to render */
                                            /* the font specs, not the actual font sample.     */
              if (mydrawinfo = GetScreenDrawInfo(mywin->WScreen))
              {
                SetFont(&myrp, mydrawinfo->dri_Font);

                myrect.MinX = mywin->BorderLeft;                          /* LAYOUT THE WINDOW */
                myrect.MinY = mywin->BorderTop;
                myrect.MaxX = mywin->Width - (mywin->BorderRight + 1);
                myrect.MaxY = mywin->Height - (mywin->BorderBottom + 1);

                cliprectside = (myrect.MaxX - myrect.MinX) / 20;

                fname.charcount    = StrLen(fname.string);
                fheight.charcount  = StrLen(fheight.string);
                XDPI.charcount     = StrLen(XDPI.string);
                YDPI.charcount     = StrLen(YDPI.string);
                entrynum.charcount = StrLen(entrynum.string);
                alphabetcharcount  = StrLen(alphabetstring);

                fontheight = (myrp.Font->tf_YSize) + 2;

                if (fontheight > ((myrect.MaxY - myrect.MinY) / 6))  /* If the default screen  */
                {                                                    /* font is more than one- */
                  defaultfont = OpenFont(&defaultfontattr);          /* sixth the size of the  */
                  SetFont(&myrp, defaultfont);                       /* window, use topaz-9.   */
                  fontheight = (myrp.Font->tf_YSize) + 2;
                }

                fname.stringwidth   = TextLength(&myrp, (STRPTR)fname.string, fname.charcount);
                fheight.stringwidth = TextLength(&myrp, (STRPTR)fheight.string, fheight.charcount);
                XDPI.stringwidth    = TextLength(&myrp, (STRPTR)XDPI.string, XDPI.charcount);
                YDPI.stringwidth    = TextLength(&myrp, (STRPTR)YDPI.string, YDPI.charcount);
                entrynum.stringwidth =
                    TextLength(&myrp, (STRPTR)entrynum.string, entrynum.charcount);

                stringwidth = fname.stringwidth;         /* What is the largest string length? */
                stringwidth =
                    (fheight.stringwidth > stringwidth) ? fheight.stringwidth : stringwidth;
                stringwidth = (XDPI.stringwidth > stringwidth) ? XDPI.stringwidth : stringwidth;
                stringwidth = (YDPI.stringwidth > stringwidth) ? YDPI.stringwidth : stringwidth;
                stringwidth =
                    (entrynum.stringwidth > stringwidth) ? entrynum.stringwidth : stringwidth;
                stringwidth += mywin->BorderLeft;

                if (stringwidth < ((myrect.MaxX - myrect.MinX) >> 1)) /* If the stringwidth is */
                {                                                 /* more than half the viewing*/
                  SetAPen(&myrp, mydrawinfo->dri_Pens[TEXTPEN]);  /* area, quit because the    */
                  SetDrMd(&myrp, JAM2);                           /* font is just too big.     */

                  Move(&myrp, myrect.MinX + 8 + stringwidth - fname.stringwidth,
                               myrect.MinY + 4 + (myrp.Font->tf_Baseline));
                  Text(&myrp, fname.string, fname.charcount);

                  Move(&myrp, myrect.MinX + 8 + stringwidth - fheight.stringwidth,
                              myrp.cp_y + fontheight);
                  Text(&myrp, fheight.string, fheight.charcount);

                  Move(&myrp, myrect.MinX + 8 + stringwidth - XDPI.stringwidth,
                              myrp.cp_y + fontheight);
                  Text(&myrp, XDPI.string, XDPI.charcount);

                  Move(&myrp, myrect.MinX + 8 + stringwidth - YDPI.stringwidth,
                              myrp.cp_y + fontheight);
                  Text(&myrp, YDPI.string, YDPI.charcount);

                  Move(&myrp, myrect.MinX + 8 + stringwidth - entrynum.stringwidth,
                              myrp.cp_y + fontheight);
                  Text(&myrp, entrynum.string, entrynum.charcount);

                  myrect.MinX = myrect.MinX + cliprectside;
                  myrect.MaxX = myrect.MaxX - cliprectside;
                  myrect.MinY = myrect.MinY + (5 * fontheight) + 8;
                  myrect.MaxY = myrect.MaxY - 8;

                  SetAPen(&myrp, mydrawinfo->dri_Pens[SHINEPEN]);         /* Draw a box around */
                  Move(&myrp, myrect.MinX - 1, myrect.MaxY + 1);          /* the cliprect.     */
                  Draw(&myrp, myrect.MaxX + 1, myrect.MaxY + 1);
                  Draw(&myrp, myrect.MaxX + 1, myrect.MinY - 1);

                  SetAPen(&myrp, mydrawinfo->dri_Pens[SHADOWPEN]);
                  Draw(&myrp, myrect.MinX - 1, myrect.MinY - 1);
                  Draw(&myrp, myrect.MinX - 1, myrect.MaxY);

                  SetAPen(&myrp, mydrawinfo->dri_Pens[TEXTPEN]);
                                          /* Fill up a buffer with a list of the available fonts */
                  afsize = AvailFonts((STRPTR)afh, 0L, AFF_MEMORY|AFF_DISK|AFF_SCALED|AFF_TAGGED);
                  do
                  {
                    afh = (struct AvailFontsHeader *) AllocMem(afsize, 0);
                    if (afh)
                    {
                      afshortage = AvailFonts((STRPTR)afh, afsize,
                                              AFF_MEMORY|AFF_DISK|AFF_SCALED|AFF_TAGGED);
                      if (afshortage)
                      {
                        FreeMem(afh, afsize);
                        afsize += afshortage;
                        afh = (struct AvailFontsHeader *)(-1L);
                      }
                    }
                  } while (afshortage && afh);

                  if (afh)
                  {
                    /* This is for the layers.library clipping region that gets attached to */
                    /* the window.  This prevents the application from unnecessarily        */
                    /* rendering beyond the bounds of the inner part of the window. For     */
                    /* more information on clipping, see the Layers chapter of this manual. */

                    if (new_region = NewRegion())                 /* More layers stuff */
                    {
                      if (OrRectRegion(new_region, &myrect));/* Even more layers stuff */
                      {
                         /* Obtain a pointer to the window's rastport and set up some of    */
                         /* the rastport attributes.  This example obtains the text pen     */
                         /* for the window's screen using the GetScreenDrawInfo() function. */
                         mycliprp = mywin->RPort;
                         SetAPen(mycliprp, mydrawinfo->dri_Pens[TEXTPEN]);

                         MainLoop();
                      }
                      DisposeRegion(new_region);
                    }
                    FreeMem(afh, afsize);
                  }
                }
                FreeScreenDrawInfo(mywin->WScreen, mydrawinfo);
              }
              CloseWindow(mywin);
            }
            CloseLibrary(UtilityBase);
          }
          CloseLibrary(LayersBase);
        }
        CloseLibrary(GfxBase);
      }
      CloseLibrary(IntuitionBase);
    }
    CloseLibrary(DiskfontBase);
