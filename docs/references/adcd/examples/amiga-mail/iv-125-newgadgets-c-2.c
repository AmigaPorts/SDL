/* Source: ADCD 2.1
 * Section: iv-125-newgadgets-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-125-newgadgets-c.md
 */

    /* create an MX gadget */
    ng.ng_TextAttr = gadfont;
    ng.ng_VisualInfo = vi;
    ng.ng_LeftEdge = 80 + scr->WBorLeft;
    ng.ng_TopEdge = 30 + scr->WBorTop + (scr->Font->ta_YSize + 1);
    ng.ng_Width = 50;
    ng.ng_Height = 30;
    ng.ng_GadgetText = "Bass Lines";
    ng.ng_GadgetID = MYGAD_MX;
    ng.ng_Flags = 0;
    mxgad = gad = CreateGadget (MX_KIND, gad, &ng,
                                GTMX_TitlePlace, PLACETEXT_ABOVE,
                                GTMX_Labels, BassLines, GTMX_Scaled, TRUE,
                                GTMX_Spacing, gadfont->ta_YSize + 1, TAG_END);
    /* create a slider gadget */
    ng.ng_TopEdge = scr->Height - 170;
    ng.ng_Height = 10;
    ng.ng_Width = 100;
    ng.ng_GadgetText = "Left Justified";
    ng.ng_GadgetID = MYGAD_SLIDERLEFT;
    ng.ng_Flags = PLACETEXT_ABOVE;
    slid1gad = gad = CreateGadget (SLIDER_KIND, gad, &ng,
                                   GTSL_MaxLevelLen, 6,
                                   GTSL_MaxPixelLen, 64,
                                   GTSL_Max, 512,
                                   GTSL_Justification, GTJ_LEFT,
                                   GTSL_LevelFormat, "%lx",
                                   GTSL_LevelPlace, PLACETEXT_BELOW,
                                   TAG_END);

    /* create a slider gadget */
    ng.ng_TopEdge = ng.ng_TopEdge + 55;
    ng.ng_GadgetText = "Centered";
    ng.ng_GadgetID = MYGAD_SLIDERCENTER;
    slid2gad = gad = CreateGadget (SLIDER_KIND, gad, &ng,
                                   GTSL_MaxLevelLen, 6,
                                   GTSL_MaxPixelLen, 64,
                                   GTSL_Max, 512,
                                   GTSL_LevelFormat, "%lx",
                                   GTSL_Justification, GTJ_CENTER,
                                   GTSL_LevelPlace, PLACETEXT_BELOW,
                                   TAG_END);

    /* create a slider gadget */
    ng.ng_TopEdge = ng.ng_TopEdge + 55;
    ng.ng_GadgetText = "Right Justified";
    ng.ng_GadgetID = MYGAD_SLIDERRIGHT;
    slid3gad = gad = CreateGadget (SLIDER_KIND, gad, &ng,
                                   GTSL_MaxLevelLen, 6,
                                   GTSL_MaxPixelLen, 64,
                                   GTSL_Max, 512,
                                   GTSL_LevelFormat, "%lx",
                                   GTSL_Justification, GTJ_RIGHT,
                                   GTSL_LevelPlace, PLACETEXT_BELOW,
                                   TAG_END);

    /* Set these in case the listview cannot be created */
    ng.ng_LeftEdge = 240 + scr->WBorLeft;
    ng.ng_TopEdge = 30 + scr->WBorTop + (scr->Font->ta_YSize + 1);

    if (CreateDaList (BassSpaces))
    {
      /* create a listview gadget */
      ng.ng_LeftEdge = 240 + scr->WBorLeft;
      ng.ng_TopEdge = 30 + scr->WBorTop + (scr->Font->ta_YSize + 1);
      ng.ng_Width = 100;
      ng.ng_Height = 30 + gadfont->ta_YSize + 14;
      ng.ng_GadgetText = "Bass Spaces";
      ng.ng_GadgetID = MYGAD_LIST;
      listgad = gad = CreateGadget (LISTVIEW_KIND, gad, &ng,
                                    GTLV_ShowSelected, NULL,
                                    GTLV_Selected, 2,
                                    GTLV_MakeVisible, 2,
                                    GTLV_Labels, DaList,
                                    TAG_END);
    }

    /* create a checkbox gadget */
    ng.ng_LeftEdge = ng.ng_LeftEdge + 30;
    ng.ng_TopEdge = ng.ng_TopEdge + 130;
    ng.ng_Width = 50;
    ng.ng_Height = 30;
    ng.ng_GadgetText = "BigCheck";
    ng.ng_GadgetID = MYGAD_TEXT;
    ng.ng_Flags = PLACETEXT_ABOVE;
    checkgad = gad = CreateGadget (CHECKBOX_KIND, gad, &ng,
                                   GTCB_Scaled, TRUE, TAG_END);


    /* create a string gadget */
    ng.ng_LeftEdge = scr->Width - scr->WBorRight - 190;
    ng.ng_TopEdge = ng.ng_TopEdge - 130;
    ng.ng_Width = 150;
    ng.ng_Height = gadfont->ta_YSize + 14;
    ng.ng_GadgetText = "String Immediate";
    ng.ng_GadgetID = MYGAD_STRING;
    stringgad = gad = CreateGadget (STRING_KIND, gad, &ng,
                                    GA_Immediate, TRUE, TAG_END);

    /* create a text gadget */
    ng.ng_TopEdge = ng.ng_TopEdge + 55;
    ng.ng_Height = gadfont->ta_YSize + 2;
    ng.ng_GadgetText = "Echo After Click";
    ng.ng_GadgetID = MYGAD_TEXT;
    textgad = gad = CreateGadget (TEXT_KIND, gad, &ng,
                                  GTTX_Border, TRUE,
                                  GTTX_FrontPen, 3,
                                  GTTX_BackPen, 2,
                                  GTTX_Clipped, TRUE,
                                  TAG_END);

    /* create a palette gadget */
    ng.ng_TopEdge = ng.ng_TopEdge + 80;
    ng.ng_Width = 100;
    ng.ng_Height = 30;
    ng.ng_GadgetText = "Odd Colors";
    ng.ng_GadgetID = MYGAD_PAL;
    palgad = gad = CreateGadget (PALETTE_KIND, gad, &ng,
                                 GTPA_ColorTable, colors,
                                 GTPA_NumColors, 7,
                                 GTPA_Color, 2,
                                 GTPA_IndicatorWidth, 21,
                                 TAG_END);

    /* create an integer gadget */
    ng.ng_Width = 150;
    ng.ng_LeftEdge = scr->Width + scr->WBorRight - 190;
    ng.ng_TopEdge = scr->Height - 170;
    ng.ng_Height = gadfont->ta_YSize + 14;
    ng.ng_GadgetText = "Number, please";
    ng.ng_GadgetID = MYGAD_INT;
    intgad = gad = CreateGadget (INTEGER_KIND, gad, &ng,
                                 GTIN_MaxChars, 14,
                                 TAG_END);

    /* create a number gadget */
    ng.ng_TopEdge = ng.ng_TopEdge + 60;
    ng.ng_Width = 100;
    ng.ng_Height = gadfont->ta_YSize + 2;
    ng.ng_GadgetText = "Echo Number";
    ng.ng_GadgetID = MYGAD_NUM;
    numgad = gad = CreateGadget (NUMBER_KIND, gad, &ng,
                                 GTNM_FrontPen, 3,
                                 GTNM_Format, "%04ld",
                                 GTNM_Clipped, TRUE,
                                 GTNM_Number, 0xffff1,
                                 TAG_END);
