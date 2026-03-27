/* Source: ADCD 2.1
 * Section: iv-17-extscreen-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-17-extscreen-c.md
 */

    struct ExtNewScreen xnewscreen;
    struct ExtNewWindow xnewwindow;
    struct Screen  *screen;
    struct Window  *window;
    struct IntuiMessage *msg;
    struct DisplayInfo displayinfo;
    struct TagItem  taglist[3];
    BOOL OpenA2024 = FALSE;
    BOOL IsV36 = FALSE;
    BOOL IsPAL;

    if (IntuitionBase = OpenLibrary("intuition.library", 33))
    {
        if (GfxBase = (struct GfxBase *) OpenLibrary("graphics.library", 33))
        {

            /* V36 check if a 10 Hz A2024 screen can be opened. If this has to be
             * done in V35 (Jumpstart), start by checking the library version
             * ofcourse. Next simply open the screen with A2024 parameters. If this
             * fails there are a couple of possibilities. The system may have run
             * out of memory or even though the user is running V35 s/he hasn't set
             * up Hedley mode. Logical step in case of failure is to try again with
             * regular parameters. Depending on the nature of the program, this could
             * be done everytime the program starts, or according to some kind of
             * user preferences setting.
             */


            /* Check for V36>. If present check Hedley (A2024) availability */
            if (GfxBase->LibNode.lib_Version >= 36)
            {
                IsV36 = TRUE;
                /* Use GetDisplayInfoData() with the DTAG_DISP to get the display info,
                 * containing availability. Note that availability means that the user
                 * admonitor'ed A2024, not necessarily that there is a physical A2024
                 * out there.
                 */
                if(GetDisplayInfoData(NULL, (UBYTE *)&displayinfo,
                    sizeof(struct DisplayInfo), DTAG_DISP, A2024TENHERTZ_KEY))
                    if (displayinfo.NotAvailable == 0)
                        OpenA2024 = TRUE;
            }
            else
            {
                /* Check if V35. If it is indicate I want the  tags added to open a
                 * A2024 screen. Note that this still doesn't mean I can actually open
                 * in Hedley mode.
                 */
                if (GfxBase->LibNode.lib_Version == 35)
                    OpenA2024 = TRUE;
            }

            /* Use a separate CheckPAL() function to see if how the use has set up
             * the system.
             */
            IsPAL = CheckPAL("Workbench");

            /* Build taglist, this is completely ignored in V33/V34 and V35 doesn't
             * recognize tags other than those A2024 ones.
             */

            /* Pass the A2024 tags. Note that with V36 it is easy to pass the
             * displaymodeid as a tag (SA_DisplayID) that that is not V35 compatible.
             * Also for V35 compatability this must be the first tag. */

            if (OpenA2024)
            {
                taglist[0].ti_Tag = NSTAG_EXT_VPMODE;
                taglist[0].ti_Data = VPF_A2024 | VPF_TENHZ;
            }
            else
            {
                /* With V36 Intuition fully supports overscan. We'll pass the
                 * Overscantype used by Workbench as a tag, and specify
                 * STDSCREENWIDTH/HEIGHT in the Width and Height fields of
                 * the ExtNewScreen structure.
                 */
                taglist[0].ti_Tag = SA_Overscan;
                taglist[0].ti_Data = OSCAN_TEXT;
            }

            /* Indicate we want the New Look if this system is running V36 by
             * specifying the SA_Pens tag and passing the pen array as data.
             */
            taglist[1].ti_Tag = SA_Pens;
            taglist[1].ti_Data = (ULONG) dri_Pens;


            /* End the taglist with TAG_DONE */
            taglist[2].ti_Tag = TAG_DONE;



            /* If V36, the overscan mode will give us the right offsets */
            xnewscreen.LeftEdge = 0;
            xnewscreen.TopEdge = 0;

            /* Width = 1008 if A2024, 640 if < V35, STDSCREENWIDTH if V36> */
            xnewscreen.Width = (OpenA2024) ? 1008 : (IsV36) ? STDSCREENWIDTH : 640;

            /* Height=1024 if A2024 & PAL, 800 if A2024 & NTSC, else STDSCREENHEIGHT */
            xnewscreen.Height = (OpenA2024) ? ((IsPAL) ? 1024 : 800) : STDSCREENHEIGHT;


            xnewscreen.Depth = 2;
            xnewscreen.DetailPen = 0;
            xnewscreen.BlockPen = 1;

            /* Set viewmodes to 0 if going to attempt to open in Hedley mode */
            xnewscreen.ViewModes = (OpenA2024) ? 0 : HIRES | LACE;

            /* Use NS_EXTENDED to tell V35 tags are on their way */
            xnewscreen.Type = CUSTOMSCREEN | NS_EXTENDED;

            /* Default font */
            xnewscreen.Font = NULL;

            xnewscreen.DefaultTitle =
                     (OpenA2024) ? "VPF_A2024|VPF_TENHZ" : "HIRES|LACE";
            xnewscreen.Gadgets = NULL;

            /* Pass the taglist as a V35 compatible extension. V34 will ignore this */
            xnewscreen.Extension = taglist;

            if ((screen = OpenScreen(&xnewscreen)) == NULL)
            {
                /* Can't open screen. Might be V35 A2024 failure. Try with something
                 * simpler.
                 */
                xnewscreen.Width = (IsV36) ? STDSCREENWIDTH : 640;
                xnewscreen.Height = STDSCREENHEIGHT;
                xnewscreen.ViewModes = HIRES | LACE;
                xnewscreen.DefaultTitle = "HIRES|LACE";
                /* Get rid of A2024 tags, keep the others. */
                taglist[0].ti_Tag = SA_Overscan;
                taglist[0].ti_Data = OSCAN_TEXT;
                OpenA2024 = FALSE;
                screen = OpenScreen(&xnewscreen);
                /* If it still fails, give up */
            }

            /* If screen opened, open a simple ExtNewWindow on it and wait */
            if (screen)
            {
                /* Give me a zoom gadget on my window. */
                taglist[0].ti_Tag = WA_Zoom,
                taglist[0].ti_Data = (ULONG) zoomdata;
                taglist[1].ti_Tag = TAG_DONE;

                xnewwindow.LeftEdge = 0;
                xnewwindow.TopEdge = screen->BarHeight + 1;
                xnewwindow.Width = screen->Width;
                xnewwindow.Height = screen->Height - xnewwindow.TopEdge;
                xnewwindow.DetailPen = 0;
                xnewwindow.BlockPen = 1;
                xnewwindow.IDCMPFlags = CLOSEWINDOW;
                xnewwindow.Flags =
                    WINDOWSIZING | WINDOWDRAG | WINDOWDEPTH | WINDOWCLOSE |
                      NW_EXTENDED | SMART_REFRESH | NOCAREREFRESH | ACTIVATE;
                xnewwindow.FirstGadget = NULL;
                xnewwindow.CheckMark = NULL;
                xnewwindow.Title = "Close to exit.";
                xnewwindow.Screen = screen;
                xnewwindow.BitMap = NULL;
                xnewwindow.MinWidth = 100;
                xnewwindow.MinHeight = 50;
                xnewwindow.MaxWidth = ~0;
                xnewwindow.MaxHeight = ~0;
                xnewwindow.Type = CUSTOMSCREEN;
                /* The window extension is completely ignored if not V36 */
                xnewwindow.Extension = taglist;

                if (window = OpenWindow(&xnewwindow))
                {
                    WaitPort(window->UserPort);
                    while (msg = (struct IntuiMessage *)GetMsg(window->UserPort))
                        ReplyMsg((struct Message *)msg);
                    CloseWindow(window);
                }


                else
                {
                    reqtext[0].IText = "Can't open window";
                    AutoRequest(NULL, &reqtext[0], NULL, &reqtext[1],
                                NULL, GADGETUP, 320, 60);
                }
                CloseScreen(screen);
            }
            else
            {
                reqtext[0].IText = "Can't open screen";
                AutoRequest(NULL, &reqtext[0], NULL, &reqtext[1],
                            NULL, GADGETUP, 320, 60);
            }
            CloseLibrary((struct Library *) GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
