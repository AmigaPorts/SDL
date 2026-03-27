/* Source: ADCD 2.1
 * Section: lib-examples-usercopperexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-usercopperexample-c.md
 */

        WORD ret_val = RETURN_OK;

        /*  Prepare to explicitly request Topaz 60 as the screen font.  */
        struct TextAttr topaz60 =
        {
                (STRPTR)"topaz.font",
                (UWORD)TOPAZ_SIXTY, (UBYTE)0, (UBYTE)0
        };

        GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 37L);
        if (GfxBase == NULL)
                ret_val = ERROR_INVALID_RESIDENT_LIBRARY;
        else
        {
                IntuitionBase = (struct IntuitionBase *)
                        OpenLibrary("intuition.library", 37L);

                if (IntuitionBase == NULL)
                        ret_val = ERROR_INVALID_RESIDENT_LIBRARY;
                else
                {
                        screen = OpenScreenTags( NULL,
                                 SA_Overscan, OSCAN_STANDARD,
                                 SA_Title,    "User Copper List Example",
                                 SA_Font,     (ULONG)&topaz60,
                                 TAG_DONE);

                        if (NULL == screen)
                                ret_val = ERROR_NO_FREE_STORE;
                        else
                        {
                                window = OpenWindowTags( NULL,
                                         WA_CustomScreen, screen,
                                         WA_Title,        "<- Click here to quit.",
                                         WA_IDCMP,        CLOSEWINDOW,
                                         WA_Flags,        WINDOWDRAG|WINDOWCLOSE|INACTIVEWINDOW,
                                         WA_Left,         (screen->Width-MY_WA_WIDTH)/2,
                                         WA_Top,          screen->Height/2,
                                         WA_Height,       screen->Font->ta_YSize + 3,
                                         WA_Width,        MY_WA_WIDTH,
                                         TAG_DONE);

                                if (NULL == window)
                                        ret_val = ERROR_NO_FREE_STORE;
                        }
                }
        }

        return(ret_val);
