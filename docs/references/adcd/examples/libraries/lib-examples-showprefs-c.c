/* Source: ADCD 2.1
 * Section: lib-examples-showprefs-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-showprefs-c.md
 */

    if (IFFParseBase = OpenLibrary ("iffparse.library", 37)) {

      readargs = ReadArgs("FILE/A", rargs, NULL);
      if( (readargs) && (rargs[0]) ) {

        filename = (UBYTE *)rargs[0];

        /* allocate an IFF handle */
        if (iffhandle = AllocIFF()) {
          /* Open the file for reading */
          if (iffhandle->iff_Stream = (LONG)Open(filename, MODE_OLDFILE)) {
            /* initialize the iff handle */
            InitIFFasDOS (iffhandle);
            if ((ifferror = OpenIFF (iffhandle, IFFF_READ)) == 0) {
              PropChunk(iffhandle, ID_PREF, ID_PRHD);

              PropChunk(iffhandle, ID_PREF, ID_FONT);
              PropChunk(iffhandle, ID_PREF, ID_ICTL);
              PropChunk(iffhandle, ID_PREF, ID_INPT);
              PropChunk(iffhandle, ID_PREF, ID_OSCN);
              PropChunk(iffhandle, ID_PREF, ID_PGFX);
              PropChunk(iffhandle, ID_PREF, ID_PTXT);
              PropChunk(iffhandle, ID_PREF, ID_SCRM);
              PropChunk(iffhandle, ID_PREF, ID_SERL);

              for (;;) {
                ifferror = ParseIFF(iffhandle, IFFPARSE_STEP);

                 if (ifferror == IFFERR_EOC)
                   continue;
                else if (ifferror)
                  break;

                /* Do nothing is this is a PrefHeader chunk,
                 * we'll pop it later when there is a pref
                 * chunk.
                 */
                if (cnode = CurrentChunk(iffhandle))
                  if (cnode->cn_ID == ID_PRHD || cnode->cn_ID == ID_FORM)
                    continue;

                /* Get the preferences header, stored previously */
                hdrsp = FindProp(iffhandle, ID_PREF, ID_PRHD);

                if (sp = FindProp(iffhandle, ID_PREF, ID_FONT)) {
                  Printf("FrontPen:  %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_FrontPen);
                  Printf("BackPen:   %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_BackPen);
                  Printf("DrawMode:  %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_DrawMode);
                  Printf("Font:      %s\n",
                        (LONG)((struct FontPrefs *)sp->sp_Data)->fp_Name);
                  Printf("ta_YSize:  %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_TextAttr.ta_YSize);
                  Printf("ta_Style:  %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_TextAttr.ta_Style);
                  Printf("ta_Flags:  %ld\n",
                        ((struct FontPrefs *)sp->sp_Data)->fp_TextAttr.ta_Flags);
                } else   if (sp = FindProp(iffhandle, ID_PREF, ID_ICTL)) {
                  Printf("TimeOut:   %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_TimeOut);
                  Printf("MetaDrag:  %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_MetaDrag);
                  Printf("WBtoFront: %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_WBtoFront);
                  Printf("FrontToBack: %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_FrontToBack);
                  Printf("ReqTrue:    %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_ReqTrue);
                  Printf("ReqFalse:    %ld\n",
                        ((struct IControlPrefs *)sp->sp_Data)->ic_ReqFalse);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_INPT)) {
                  Printf("PointerTicks:      %ld\n",
                        ((struct InputPrefs *)sp->sp_Data)->ip_PointerTicks);
                  Printf("DoubleClick/Secs:  %ld\n",
                        ((struct InputPrefs *)sp->sp_Data)->ip_DoubleClick.tv_secs);
                  Printf("DoubleClick/Micro: %ld\n",
                        ((struct InputPrefs *)sp->sp_Data)->ip_DoubleClick.tv_micro);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_OSCN)) {
                  Printf("DisplayID:  0x%lx\n",
                        ((struct OverscanPrefs *)sp->sp_Data)->os_DisplayID);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_PGFX)) {
                  Printf("Aspect:     %ld\n",
                        ((struct PrinterGfxPrefs *)sp->sp_Data)->pg_Aspect);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_PTXT)) {
                  Printf("Driver:     %s\n",
                        (LONG)((struct PrinterTxtPrefs *)sp->sp_Data)->pt_Driver);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_SCRM)) {
                  Printf("DisplayID:  0x%lx\n",
                        ((struct ScreenModePrefs *)sp->sp_Data)->sm_DisplayID);
                  /* etc */
                } else if (sp = FindProp(iffhandle, ID_PREF, ID_SERL)) {
                  Printf("BaudRate:   %ld\n",
                        ((struct SerialPrefs *)sp->sp_Data)->sp_BaudRate);
                  /* etc */
                }
              }

              CloseIFF(iffhandle);
            }

            if (ifferror != IFFERR_EOF) {
              rargs[1] = (LONG)IFFErrTxt[-ifferror - 1];
              VFPrintf(Output(), "%s: %s\n", rargs);
              rc = RETURN_FAIL;
            }

            Close(iffhandle->iff_Stream);
          } else
            error = IoErr();

          FreeIFF(iffhandle);
        } else {
          VFPrintf(Output(), "Can't allocate IFF handle\n", NULL);
          rc = RETURN_FAIL;
        }
      } else
        error = IoErr();
      CloseLibrary(IFFParseBase);


      SetIoErr(error);
      if (error) {
        rc = RETURN_FAIL;
        PrintFault(error, filename ? filename : "");
      }
    }

    if(readargs) FreeArgs(readargs);
    CloseLibrary(DOSBase);
