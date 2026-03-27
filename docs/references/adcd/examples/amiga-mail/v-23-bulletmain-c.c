/* Source: ADCD 2.1
 * Section: v-23-bulletmain-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-bulletmain-c.md
 */

    if (IntuitionBase = OpenLibrary("intuition.library", 37L))
    {
      if (myrda = ReadArgs(readargsstring, args, NULL))
      {
        if (args[XDPI] && args[YDPI]) /* If the user sets the DPI from the command  */
        {            /* line, make sure the environment variable also gets changed. */
          *(ULONG *)xydpi = ( (*(LONG *) args[XDPI]) << 16 | (*(ULONG *) args[YDPI]) );
          SetVar(dpivarname, xydpi, 5,
              GVF_GLOBAL_ONLY | GVF_BINARY_VAR | GVF_DONT_NULL_TERM);
        }
        else                            /* If the user did NOT set the X OR Y DPI...*/
        {
          args[XDPI] = (LONG) &defxdpi; /* ...set to default values and look for    */
          args[YDPI] = (LONG) &defydpi; /* an environment variable called "XYDPI".  */
                                                  /* Read the environment variable, */
          if ((GetVar(dpivarname, xydpi, 5,        /* XYDPI, if it exists.          */
              GVF_GLOBAL_ONLY | GVF_BINARY_VAR | GVF_DONT_NULL_TERM)) != -1)

     /* BUG!: In the original publication of this code, the line above erroneously  */
     /* tested for the wrong return value.  It caused unexpected results when using */
     /* the default X and Y DPI values.  This bug was also present in BulletMain.c. */

          {
            if ( (*(ULONG *)xydpi & 0xFFFF0000) && (*(ULONG *)xydpi & 0x0000FFFF) )
            {     /* Make sure the environment variable is OK to use by making sure */
                  /* that neither X or YDPI is zero. If XYDPI is OK, use it as the  */
              defxdpi = ((*(ULONG *)xydpi) & 0xFFFF0000) >> 16;        /* default.  */
              defydpi = (*(ULONG *)xydpi) & 0x0000FFFF;
            }
          }
        }
        if (!(args[SIZE]))
          args[SIZE] = (LONG) &defpointheight;
        if (!(args[CODE]))
          args[CODE] = (LONG) &defcode;
        if (!(args[CODE2]))
          args[CODE2] = (LONG) &defcode2;
        if (!(args[FONT_NAME]))
          args[FONT_NAME] = (LONG) fontstring;
                                           /* Open the ".font" file which contains  */
                                           /* the FontContentsHeader for this font. */
        if (fontfile = Open((STRPTR) args[FONT_NAME], MODE_OLDFILE))
        {
          if (Read(fontfile, &fchid, sizeof(UWORD)))
          {
            if (fchid == OTAG_ID)             /* Does this font have an .otag file? */
            {
              strcpy(buf, (STRPTR) args[FONT_NAME]); /* Put together the otag file  */
              if (otagname = &(buf[strlen(buf) - 4]))/* name from the .font file.   */
              {
                strcpy(otagname, "otag");
                if (UtilityBase = OpenLibrary("utility.library", 37L))
                {
                  if (ti = AllocOtag(buf))      /* open the otag file and copy its  */
                  {                             /* tags into memory.                */
                    if (BulletBase = OpenScalingLibrary(ti)) /* Pass the function   */
                    {                                  /* the OTAG tag list which it*/
                                                       /* needs to open the scaling */
                      if (ge = GetGlyphEngine(ti, buf))/* library.  Open the        */
                      {                                /* library's scaling engine. */
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
                          rp = *(w->RPort); /* Clone window's RastPort.  The second */
                                            /* Rastport is for rendering with the   */
                                            /* background color.                    */

                          if (drawinfo = GetScreenDrawInfo(w->WScreen)) /* Get the  */
                          {             /* Screen's DrawInfo to get its pen colors. */
                            SetAPen(w->RPort, drawinfo->dri_Pens[TEXTPEN]);
                            SetAPen(&rp, drawinfo->dri_Pens[BACKGROUNDPEN]);
                            FreeScreenDrawInfo(w->WScreen, drawinfo);

                            BulletExample(ge, w, &rp, *(ULONG *) args[SIZE],
                                          *(ULONG *) args[XDPI],
                                          *(ULONG *) args[YDPI],
                                          *(ULONG *) args[CODE],
                                          *(ULONG *) args[CODE2]);
                          }
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
