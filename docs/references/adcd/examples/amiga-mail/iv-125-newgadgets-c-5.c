/* Source: ADCD 2.1
 * Section: iv-125-newgadgets-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-125-newgadgets-c.md
 */

    if (Gadscreen = OpenScreenTags (NULL,
                                    SA_Left, 0,
                                    SA_Top, 0,
                                    SA_LikeWorkbench, TRUE,
                                    SA_Font, &nicefont,
                                    SA_Title, "Some New GadTools Features",
                                    TAG_DONE))
    {
      if ((vi = GetVisualInfo (Gadscreen, TAG_END)) != NULL)
      {
        if (CreateGads (Gadscreen, vi, &nicefont) != NULL)
        {
          if (menuptr = CreateDaMenu (Gadmenu, vi))
          {
            if (Gadwindow = OpenWindowTags (NULL,
                                            WA_Left, Gadscreen->LeftEdge,
                                    WA_Top, Gadscreen->TopEdge + Gadscreen->BarHeight,
                                  WA_Height, Gadscreen->Height - Gadscreen->BarHeight,
                                            WA_Width, Gadscreen->Width,
                                WA_MinWidth, Gadscreen->Height - Gadscreen->BarHeight,
                                            WA_MinHeight, Gadscreen->Width,
                                            WA_Gadgets, glist,
                                            WA_Title, "Lots of Gadgets",
                                            WA_CustomScreen, Gadscreen,
                                    WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_ACTIVEWINDOW |
                                            IDCMP_GADGETDOWN | IDCMP_MENUPICK |
                                      IDCMP_GADGETHELP | IDCMP_GADGETUP | SLIDERIDCMP,
                                       WA_Flags, WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                                            WFLG_ACTIVATE,
                                            WA_NewLookMenus, TRUE,
                                            WA_DragBar, TRUE,
                                            WA_CloseGadget, TRUE,
                                            TAG_DONE))
            {
              if (SetMenuStrip (Gadwindow, menuptr))
              {
                GT_RefreshWindow (Gadwindow, NULL);

                ProcessEvents (Gadwindow, menuptr, vi);

                ClearMenuStrip (Gadwindow);

                FreeMenus (menuptr);

                CloseWindow (Gadwindow);
              }
            }
          }
        }
        else
          printf ("Could not create gadgets\n");

        if (DaList)
          FreeDaMemory ();

        FreeGadgets (glist);

        FreeVisualInfo (vi);
      }

      else
        printf ("Could not get visual info\n");

      CloseScreen (Gadscreen);
    }
    else
      printf ("Could not open screen\n");

    CloseFont (Appfont);
