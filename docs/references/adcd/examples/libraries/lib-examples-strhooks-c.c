/* Source: ADCD 2.1
 * Section: lib-examples-strhooks-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-strhooks-c.md
 */

    {
    if (UtilityBase = OpenLibrary("utility.library", 37L))
        {
        /* get the correct pens for the screen. */
        if (screen = LockPubScreen(NULL))
            {
            if (drawinfo = GetScreenDrawInfo(screen))
                {
                vars = (struct Vars *)AllocMem(sizeof(struct Vars),MEMF_CLEAR);
                if (vars != NULL)
                    {
                    vars->sgg_Extend.Pens[0] = drawinfo->dri_Pens[FILLTEXTPEN];
                    vars->sgg_Extend.Pens[1] = drawinfo->dri_Pens[FILLPEN];
                    vars->sgg_Extend.ActivePens[0] = drawinfo->dri_Pens[FILLTEXTPEN];
                    vars->sgg_Extend.ActivePens[1] = drawinfo->dri_Pens[FILLPEN];
                    vars->sgg_Extend.EditHook = &(vars->sgg_Hook);
                    vars->sgg_Extend.WorkBuffer = vars->sgg_WBuff;

                    vars->sgg_StrInfo.Buffer = vars->sgg_Buff;
                    vars->sgg_StrInfo.UndoBuffer = vars->sgg_UBuff;
                    vars->sgg_StrInfo.MaxChars = SG_STRLEN;
                    vars->sgg_StrInfo.Extension = &(vars->sgg_Extend);

                    /* There should probably be a border around the string gadget.
                    ** As is, it is hard to locate when disabled.
                    */
                    vars->sgg_Gadget.LeftEdge = 20;
                    vars->sgg_Gadget.TopEdge = 30;
                    vars->sgg_Gadget.Width = MYSTRGADWIDTH;
                    vars->sgg_Gadget.Height = screen->RastPort.TxHeight;
                    vars->sgg_Gadget.Flags = GFLG_GADGHCOMP | GFLG_STRINGEXTEND;
                    vars->sgg_Gadget.Activation = GACT_RELVERIFY;
                    vars->sgg_Gadget.GadgetType = GTYP_STRGADGET;
                    vars->sgg_Gadget.SpecialInfo = &(vars->sgg_StrInfo);
                    vars->sgg_Gadget.GadgetRender = (APTR)&strBorder;
                    strBorderData[5] = strBorderData[7] =
                          screen->RastPort.TxHeight + 3;

                    initHook(&(vars->sgg_Hook), str_hookRoutine);

                    if (vars->sgg_Window = OpenWindowTags(NULL,
                            WA_PubScreen,       screen,
                            WA_Left,      21,   WA_Top,       20,
                            WA_Width,    500,   WA_Height,   150,
                            WA_MinWidth,  50,   WA_MaxWidth,  ~0,
                            WA_MinHeight, 30,   WA_MaxHeight, ~0,
                            WA_SimpleRefresh, TRUE,
                            WA_NoCareRefresh, TRUE,
                            WA_RMBTrap,       TRUE,
                            WA_IDCMP,         IDCMP_GADGETUP | IDCMP_CLOSEWINDOW,
                            WA_Flags,         WFLG_CLOSEGADGET | WFLG_NOCAREREFRESH |
                                              WFLG_DRAGBAR | WFLG_DEPTHGADGET |
                                              WFLG_SIMPLE_REFRESH,
                            WA_Title,         "String Hook Accepts HEX Digits Only",
                            WA_Gadgets,       &(vars->sgg_Gadget),
                            TAG_DONE))
                        {
                        handleWindow(vars);

                        CloseWindow(vars->sgg_Window);
                        }
                    FreeMem(vars,sizeof(struct Vars));
                    }
                FreeScreenDrawInfo(screen, drawinfo);
                }
            UnlockPubScreen(NULL, screen);
            }
        CloseLibrary(UtilityBase);
        }
    CloseLibrary(IntuitionBase);
    }
