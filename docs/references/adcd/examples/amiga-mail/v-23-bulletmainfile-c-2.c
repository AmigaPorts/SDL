/* Source: ADCD 2.1
 * Section: v-23-bulletmainfile-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-bulletmainfile-c.md
 */

          {
            if ( (*(ULONG *)xydpi & 0xFFFF0000) && (*(ULONG *)xydpi & 0x0000FFFF) )
            {          /* Make sure the environment variable is OK to use by making */
                       /* sure that neither X or YDPI is zero. If XYDPI is OK, use  */
              defxdpi = ((*(ULONG *)xydpi) & 0xFFFF0000) >> 16; /* it as a default. */
              defydpi = (*(ULONG *)xydpi) & 0x0000FFFF;
            }
          }
        }
        if (!(args[SIZE]))
          args[SIZE] = (LONG) &defpointheight;
        if (!(args[FONT_NAME]))
          args[FONT_NAME] = (LONG) fontstring;
                                           /* Open the ".font" file which contains  */
                                           /* the FontContentsHeader for this font. */

        if (fontfile = Open((STRPTR) args[FONT_NAME], MODE_OLDFILE))
        {
          if (Read(fontfile, &fchid, sizeof(UWORD)))
          {
            if (fchid == OTAG_ID)            /* Does this font have an .otag file? */
            {
              strcpy(buf, (STRPTR) args[FONT_NAME]);   /* Put together the .otag   */
              if (otagname = &(buf[strlen(buf) - 4]))  /* file name from the .font */
              {                                        /* file name.               */
                strcpy(otagname, "otag");
                if (UtilityBase = OpenLibrary("utility.library", 37L))
                {
                  if (ti = AllocOtag(buf))      /* open the otag file and copy its */
                  {                             /* tags into memory.               */
                    if (BulletBase = OpenScalingLibrary(ti)) /* Pass the function  */
                    {                                  /* the OTAG tag list which  */
                      if (ge = GetGlyphEngine(ti, buf))/* it needs to open the     */
                      {                              /* scaling library.  Open the */
                                                     /* library's scaling engine.  */
                        if (w = OpenWindowTags(NULL,
                                               WA_Width,         640,
                                               WA_Height,        200,
                                               WA_SmartRefresh,  TRUE,
                                               WA_SizeGadget,    FALSE,
                                               WA_CloseGadget,   TRUE,
                                               WA_IDCMP,         NULL,
                                               WA_DragBar,       TRUE,
                                               WA_DepthGadget,   TRUE,
                                               WA_Title,         (ULONG)argv[0],
                                               TAG_END))
                        {
                          rp = *(w->RPort);    /* Clone window's RastPort.  The    */
                                               /* second Rastport is for rendering */
                                               /* with the background color.       */
                          if (drawinfo = GetScreenDrawInfo(w->WScreen)) /* Get the */
                          {            /* screen's DrawInfo to get its pen colors. */
                            SetAPen(w->RPort, drawinfo->dri_Pens[TEXTPEN]);
                            SetAPen(&rp, drawinfo->dri_Pens[BACKGROUNDPEN]);
                            FreeScreenDrawInfo(w->WScreen, drawinfo);
                          }

                          BulletExample(ge, w, &rp, *(ULONG *) args[SIZE],
                                        *(ULONG *) args[XDPI],
                                        *(ULONG *) args[YDPI],
                                        (STRPTR) args[VIEW_FILE]);
                          CloseWindow(w);
                        }
                        ReleaseGlyphEngine(ge);
                      }
                      CloseScalingLibrary(BulletBase);
                    }
                    FreeOtag(ti);
                  }
                  CloseLibrary(UtilityBase);
                }
              }
            }
          }
          Close(fontfile);
        }
        FreeArgs(myrda);
      }
      CloseLibrary(IntuitionBase);
    }
    CloseLibrary(GfxBase);
