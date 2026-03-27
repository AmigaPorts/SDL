# GadTools Index


GadTools, [192](../Libraries_Manual_guide/node019C.html#line6), [367](../Libraries_Manual_guide/node024B.html)
  BUTTON_KIND
```c
    GA_Disabled, [386](../Libraries_Manual_guide/node0260.html#line9), [387](../Libraries_Manual_guide/node0261.html#line44)
    GA_TabCycle, [387](../Libraries_Manual_guide/node0261.html#line59)
    GTIN_MaxChars, [387](../Libraries_Manual_guide/node0261.html#line25)
    GTIN_Number, [387](../Libraries_Manual_guide/node0261.html#line21)
    GTST_MaxChars, [387](../Libraries_Manual_guide/node0261.html#line12)
    GTST_String, [386](../Libraries_Manual_guide/node0261.html#line6)
    STRINGA_ExitHelp, [387](../Libraries_Manual_guide/node0261.html#line48)
    STRINGA_Justification, [387](../Libraries_Manual_guide/node0261.html#line35)
    STRINGA_ReplaceMode, [387](../Libraries_Manual_guide/node0261.html#line40)
```
  caveats
```c
    GadTools enforces Intuition limits, [375](../Libraries_Manual_guide/node0251.html#line57)
    GT_SetGadgetAttrs() and GT_BeginRefresh(), [386](../Libraries_Manual_guide/node025E.html#line60)
    PLACETEXT with GENERIC_KIND gadgets, [398](../Libraries_Manual_guide/node026A.html#line9)
    post-processing, [368](../Libraries_Manual_guide/node024C.html#line19)
    preserve bits set by CreatsGadget(), [398](../Libraries_Manual_guide/node026A.html#line18)
    refreshing the display, [382](../Libraries_Manual_guide/node025C.html#line25)
    restrictions on gadgets, [411](../Libraries_Manual_guide/node0276.html)
    side effects, [412](../Libraries_Manual_guide/node0277.html)
```
  CHECKBOX_KIND
```c
    GA_Disabled, [389](../Libraries_Manual_guide/node0262.html#line18)
    GTCB_Checked, [389](../Libraries_Manual_guide/node0262.html#line13)
```
  controlling gadgets from the keyboard, [404](../Libraries_Manual_guide/node0273.html)
  CreateContext(), [399](../Libraries_Manual_guide/node026D.html)
  CreateGadget(), [380](../Libraries_Manual_guide/node025A.html)
  CreateMenus(), [374](../Libraries_Manual_guide/node0251.html)
  CreateMenusA(), [374](../Libraries_Manual_guide/node0251.html)
  creating gadgets, [380](../Libraries_Manual_guide/node025A.html)
  CYCLE_KIND
```c
    GA_Disabled, [390](../Libraries_Manual_guide/node0264.html#line31)
    GTCY_Active, [390](../Libraries_Manual_guide/node0264.html#line27)
    GTCY_Labels, [390](../Libraries_Manual_guide/node0264.html#line19)
```
  DrawBevelBox(), [403](../Libraries_Manual_guide/node0272.html)
  DrawBevelBoxA(), [403](../Libraries_Manual_guide/node0272.html)
  examples
```c
    complete GadTools example, [406](../Libraries_Manual_guide/node0598.html)
    gadget message filtering, [403](../Libraries_Manual_guide/node0271.html#line45)
    NewMenu structure, [369](../Libraries_Manual_guide/node024E.html#line39)
    slider gadget setup, [393](../Libraries_Manual_guide/node0265.html#line111)
    using CreateContext(), [400](../Libraries_Manual_guide/node026E.html)
    using gadgets, [383](../Libraries_Manual_guide/node0599.html)
    using the menu system, [372](../Libraries_Manual_guide/node059A.html)
    using VisualInfo functions, [399](../Libraries_Manual_guide/node026C.html#line37)
```
  features of, [368](../Libraries_Manual_guide/node024E.html#line16)
  FreeGadgets(), [382](../Libraries_Manual_guide/node025D.html)
  FreeMenus(), [377](../Libraries_Manual_guide/node0254.html)
  function descriptions, [413](../Libraries_Manual_guide/node0278.html#line6)
  gadget types, [378](../Libraries_Manual_guide/node0258.html#line5), [386](../Libraries_Manual_guide/node025F.html)
```c
    button, [378](../Libraries_Manual_guide/node0258.html#line5), [386](../Libraries_Manual_guide/node0260.html)
    checkboxes, [378](../Libraries_Manual_guide/node0258.html#line5), [389](../Libraries_Manual_guide/node0262.html)
    cycle, [378](../Libraries_Manual_guide/node0258.html#line5), [390](../Libraries_Manual_guide/node0264.html)
    generic gadget, [398](../Libraries_Manual_guide/node026A.html)
    integer, [378](../Libraries_Manual_guide/node0258.html#line5), [386](../Libraries_Manual_guide/node0261.html)
    listviews, [378](../Libraries_Manual_guide/node0258.html#line5), [394](../Libraries_Manual_guide/node0267.html)
    mutually exclusive, [378](../Libraries_Manual_guide/node0258.html#line5), [389](../Libraries_Manual_guide/node0263.html)
    numeric-display, [378](../Libraries_Manual_guide/node0258.html#line5), [397](../Libraries_Manual_guide/node0269.html)
    palette, [378](../Libraries_Manual_guide/node0258.html#line5), [396](../Libraries_Manual_guide/node0268.html)
    scrollers, [378](../Libraries_Manual_guide/node0258.html#line5), [393](../Libraries_Manual_guide/node0266.html)
    sliders, [378](../Libraries_Manual_guide/node0258.html#line5), [391](../Libraries_Manual_guide/node0265.html)
    string, [378](../Libraries_Manual_guide/node0258.html#line5), [386](../Libraries_Manual_guide/node0261.html)
    text-display, [378](../Libraries_Manual_guide/node0258.html#line5), [397](../Libraries_Manual_guide/node0269.html)
```
  gadgets, [378](../Libraries_Manual_guide/node0258.html)
  GetVisualInfo(), [398](../Libraries_Manual_guide/node026C.html)
  GetVisualInfoA(), [398](../Libraries_Manual_guide/node026C.html)
  GTMENUITEM_USERDATA(), [372](../Libraries_Manual_guide/node024F.html#line118)
  GTMENU_USERDATA(), [372](../Libraries_Manual_guide/node024F.html#line118)
  GTMN_FrontPen(), [374](../Libraries_Manual_guide/node0251.html#line15)
  GTMN_TextAttr, [375](../Libraries_Manual_guide/node0252.html#line15)
  GT_BeginRefresh(), [402](../Libraries_Manual_guide/node026F.html#line19)
  GT_EndRefresh(), [402](../Libraries_Manual_guide/node026F.html#line19)
  GT_FilterIMsg(), [402](../Libraries_Manual_guide/node0271.html#line7)
  GT_GetIMsg(), [381](../Libraries_Manual_guide/node025B.html)
  GT_PostFilterIMsg(), [402](../Libraries_Manual_guide/node0271.html#line7)
  GT_RefreshWindow(), [401](../Libraries_Manual_guide/node026F.html#line5)
  GT_ReplyIMsg(), [381](../Libraries_Manual_guide/node025B.html)
  GT_SetGadgetAttrs(), [385](../Libraries_Manual_guide/node025E.html)
  GT_SetGadgetAttrsA(), [385](../Libraries_Manual_guide/node025E.html)
  handling gadget messages, [381](../Libraries_Manual_guide/node025B.html)
  IDCMP flags, [382](../Libraries_Manual_guide/node025C.html)
  implementing gadget keyboard equivalents, [404](../Libraries_Manual_guide/node0275.html)
  language-sensitive menus, [378](../Libraries_Manual_guide/node0257.html)
  LayoutMenuItems(), [376](../Libraries_Manual_guide/node0253.html)
  LayoutMenuItemsA(), [376](../Libraries_Manual_guide/node0253.html#line15)
  LayoutMenus(), [375](../Libraries_Manual_guide/node0252.html)
  LayoutMenusA(), [375](../Libraries_Manual_guide/node0252.html)
  LISTVIEW_KIND
```c
    GTLV_Labels, [394](../Libraries_Manual_guide/node0267.html#line8)
    GTLV_ReadOnly, [395](../Libraries_Manual_guide/node0267.html#line19)
    GTLV_ScrollWidth, [395](../Libraries_Manual_guide/node0267.html#line25)
    GTLV_Selected, [395](../Libraries_Manual_guide/node0267.html#line38)
    GTLV_ShowSelected, [395](../Libraries_Manual_guide/node0267.html#line30)
    GTLV_Top, [395](../Libraries_Manual_guide/node0267.html#line15)
    LAYOUTA_Spacing, [395](../Libraries_Manual_guide/node0267.html#line44)
```
  menu layout, [180](../Libraries_Manual_guide/node018B.html#line25)
  menus, [368](../Libraries_Manual_guide/node024E.html)
  menus and intuimessages, [377](../Libraries_Manual_guide/node0255.html)
  minimal IDCMP_REFRESHWINDOW processing, [402](../Libraries_Manual_guide/node026F.html#line38)
  modifying gadgets - struct, [385](../Libraries_Manual_guide/node025E.html)
  MX_KIND
```c
    GTMX_Active, [389](../Libraries_Manual_guide/node0263.html#line23)
    GTMX_Labels, [389](../Libraries_Manual_guide/node0263.html#line15)
    GTMX_Spacing, [390](../Libraries_Manual_guide/node0263.html#line28)
```
  NUMBER_KIND
```c
    GTNM_Border, [397](../Libraries_Manual_guide/node0269.html#line38)
    GTNM_Number, [397](../Libraries_Manual_guide/node0269.html#line35)
```
  PALETTE_KIND
```c
    GA_Disabled, [396](../Libraries_Manual_guide/node0268.html#line37)
    GTPA_Color, [396](../Libraries_Manual_guide/node0268.html#line14)
    GTPA_ColorOffset, [396](../Libraries_Manual_guide/node0268.html#line18)
    GTPA_Depth, [396](../Libraries_Manual_guide/node0268.html#line9)
    GTPA_IndicatorHeight, [396](../Libraries_Manual_guide/node0268.html#line31)
    GTPA_IndicatorWidth, [396](../Libraries_Manual_guide/node0268.html#line24)
```
  programming gadgets, [378](../Libraries_Manual_guide/node0258.html#line24)
  restrictions on menus, [377](../Libraries_Manual_guide/node0256.html)
  reusing a NewGadget structure, [401](../Libraries_Manual_guide/node026E.html#line88)
  SCROLLER_KIND
```c
    GA_Disabled, [394](../Libraries_Manual_guide/node0266.html#line62)
    GA_Immediate, [394](../Libraries_Manual_guide/node0266.html#line47)
    GA_RelVerify, [394](../Libraries_Manual_guide/node0266.html#line52)
    GTSC_Arrows, [394](../Libraries_Manual_guide/node0266.html#line39)
    GTSC_Top, [393](../Libraries_Manual_guide/node0266.html#line27)
    GTSC_Total, [393](../Libraries_Manual_guide/node0266.html#line31)
    GTSC_Visible, [393](../Libraries_Manual_guide/node0266.html#line35)
    PGA_Freedom, [394](../Libraries_Manual_guide/node0266.html#line57)
```
  SLIDER_KIND
```c
    GA_Disabled, [392](../Libraries_Manual_guide/node0265.html#line78)
    GA_Immediate, [392](../Libraries_Manual_guide/node0265.html#line63)
    GA_RelVerify, [392](../Libraries_Manual_guide/node0265.html#line68)
    GTSL_DispFunc, [392](../Libraries_Manual_guide/node0265.html#line53)
    GTSL_Level, [391](../Libraries_Manual_guide/node0265.html#line14)
    GTSL_LevelFormat, [391](../Libraries_Manual_guide/node0265.html#line21)
    GTSL_LevelPlace, [391](../Libraries_Manual_guide/node0265.html#line44)
    GTSL_Max, [391](../Libraries_Manual_guide/node0265.html#line11)
    GTSL_MaxLevelLen, [391](../Libraries_Manual_guide/node0265.html#line38)
    GTSL_Min, [391](../Libraries_Manual_guide/node0265.html#line7)
    PGA_Freedom, [392](../Libraries_Manual_guide/node0265.html#line73)
    processing IntuiMessages, [392](../Libraries_Manual_guide/node0265.html#line82)
```
  struct NewGadget, [379](../Libraries_Manual_guide/node0259.html#line5)
  struct NewMenu, [370](../Libraries_Manual_guide/node024F.html)
  TEXT_KIND

```c
    GTTX_Border, [397](../Libraries_Manual_guide/node0269.html#line20)
    GTTX_CopyText, [397](../Libraries_Manual_guide/node0269.html#line24)
    GTTX_Text, [397](../Libraries_Manual_guide/node0269.html#line16)
```
