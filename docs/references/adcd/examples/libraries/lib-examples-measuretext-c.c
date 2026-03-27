/* Source: ADCD 2.1
 * Section: lib-examples-measuretext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-measuretext-c.md
 */

    if (myfile = Open(argv[1], MODE_OLDFILE))                 /* Open the file to print out. */
    {
      if (DiskfontBase = OpenLibrary("diskfont.library", 37L))        /* Open the libraries. */
      {
        if (IntuitionBase = OpenLibrary("intuition.library", 37L))
        {
          if (GfxBase = OpenLibrary("graphics.library", 37L))
          {
            if (AslBase = OpenLibrary("asl.library", 37L))
            {
              if (fr = (struct FontRequester *)                /* Open an ASL font requester */
                       AllocAslRequestTags(ASL_FontRequest,
                                    /* Supply initial values for requester */
                                    ASL_FontName, (ULONG)"topaz.font",
                                    ASL_FontHeight, 11L,
                                    ASL_FontStyles, FSF_BOLD | FSF_ITALIC,
                                    ASL_FrontPen,  0x01L,
                                    ASL_BackPen,   0x00L,

                                     /* Give us all the gadgetry */
                                    ASL_FuncFlags, FONF_FRONTCOLOR | FONF_BACKCOLOR |
                                                   FONF_DRAWMODE | FONF_STYLES,
                                    TAG_DONE))




              {
                /* Pop up the requester */
                if (AslRequest(fr, 0L))
                {
                  myta.ta_Name       = fr->fo_Attr.ta_Name;         /* extract the font and */
                  myta.ta_YSize      = fr->fo_Attr.ta_YSize;        /* display attributes   */
                  myta.ta_Style      = fr->fo_Attr.ta_Style;        /* from the FontRequest */
                  myta.ta_Flags      = fr->fo_Attr.ta_Flags;        /* structure.           */

                  if (myfont = OpenDiskFont(&myta))
                  {
                    if (w = OpenWindowTags(NULL,WA_SizeGadget,  TRUE,
                                                WA_MinWidth,    200,
                                                WA_MinHeight,   200,
                                                WA_DragBar,     TRUE,
                                                WA_DepthGadget, TRUE,
                                                WA_Title,       (ULONG)argv[1],
                                                TAG_DONE))
                    {
                      myrp = w->RPort;
                      /* figure out where the baseline of the uppermost line should be. */
                      wtbarheight = w->WScreen->BarHeight + myfont->tf_Baseline + 2;

                      /* Set the font and add software styling to the text if I asked for it */
                      /* in OpenFont() and didn't get it.  Because most Amiga fonts do not   */
                      /* have styling built into them (with the exception of the CG outline  */
                      /* fonts), if the user selected some kind of styling for the text, it  */
                      /* will to be added algorithmically by calling SetSoftStyle().         */

                      SetFont(myrp, myfont);
                      SetSoftStyle(myrp,   myta.ta_Style ^ myfont->tf_Style,
                                    (FSF_BOLD | FSF_UNDERLINED | FSF_ITALIC));
                      SetDrMd(myrp, fr->fo_DrawMode);
                      SetAPen(myrp, fr->fo_FrontPen);
                      SetBPen(myrp, fr->fo_BackPen);
                      Move(myrp, w->WScreen->WBorLeft, wtbarheight);
                      mytask = FindTask(NULL);

                      MainLoop();

                      Delay(25);                    /* short delay to give user a chance to */
                      CloseWindow(w);               /* see the text before it goes away.    */
                    }
                    CloseFont(myfont);
                  }
                }
                else
                  VPrintf("Request Cancelled\n", NULL);
                FreeAslRequest(fr);
              }
              CloseLibrary(AslBase);
            }
            CloseLibrary(GfxBase);
          }
          CloseLibrary(IntuitionBase);
        }
        CloseLibrary(DiskfontBase);
      }
      Close(myfile);
    }
