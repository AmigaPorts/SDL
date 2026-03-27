---
title: GadTools Index
manual: libraries
chapter: libraries
section: gadtools-index
functions: [CreateContext, CreateMenusA, DrawBevelBoxA, FreeGadgets, FreeMenus, GT_BeginRefresh, GT_EndRefresh, GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_RefreshWindow, GT_ReplyIMsg, GT_SetGadgetAttrsA, GetVisualInfoA, LayoutMenuItemsA, LayoutMenusA]
libraries: [gadtools.library]
---

# GadTools Index

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GadTools, [192](libraries/6-intuition-menus-a-menu-example.md), [367](libraries/15-gadtools-library.md)
  BUTTON_KIND
```c
    GA_Disabled, [386](libraries/15-the-kinds-of-gadtools-gadgets-button-gadgets.md), [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    GA_TabCycle, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    GTIN_MaxChars, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    GTIN_Number, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    GTST_MaxChars, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    GTST_String, [386](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    STRINGA_ExitHelp, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    STRINGA_Justification, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    STRINGA_ReplaceMode, [387](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
```
  caveats
```c
    GadTools enforces Intuition limits, [375](libraries/15-functions-for-gadtools-menus-creating-menus.md)
    GT_SetGadgetAttrs() and GT_BeginRefresh(), [386](libraries/15-gadtools-gadgets-modifying-gadgets.md)
    PLACETEXT with GENERIC_KIND gadgets, [398](libraries/15-the-kinds-of-gadtools-gadgets-generic-gadgets.md)
    post-processing, [368](libraries/15-gadtools-library-elements-of-gadtools.md)
    preserve bits set by CreatsGadget(), [398](libraries/15-the-kinds-of-gadtools-gadgets-generic-gadgets.md)
    refreshing the display, [382](libraries/15-gadtools-gadgets-idcmp-flags.md)
    restrictions on gadgets, [411](libraries/15-gadtools-gadgets-restrictions-on-gadtools-gadgets.md)
    side effects, [412](libraries/15-gadtools-gadgets-documented-side-effects.md)
```
  CHECKBOX_KIND
```c
    GA_Disabled, [389](libraries/15-the-kinds-of-gadtools-gadgets-checkbox-gadgets.md)
    GTCB_Checked, [389](libraries/15-the-kinds-of-gadtools-gadgets-checkbox-gadgets.md)
```
  controlling gadgets from the keyboard, [404](libraries/15-gadtools-gadgets-gadget-keyboard-equivalents.md)
  CreateContext(), [399](libraries/15-setting-up-gadtools-menus-and-gadgets-createcontext.md)
  CreateGadget(), [380](libraries/15-gadtools-gadgets-creating-gadgets.md)
  CreateMenus(), [374](libraries/15-functions-for-gadtools-menus-creating-menus.md)
  CreateMenusA(), [374](libraries/15-functions-for-gadtools-menus-creating-menus.md)
  creating gadgets, [380](libraries/15-gadtools-gadgets-creating-gadgets.md)
  CYCLE_KIND
```c
    GA_Disabled, [390](libraries/15-the-kinds-of-gadtools-gadgets-cycle-gadgets.md)
    GTCY_Active, [390](libraries/15-the-kinds-of-gadtools-gadgets-cycle-gadgets.md)
    GTCY_Labels, [390](libraries/15-the-kinds-of-gadtools-gadgets-cycle-gadgets.md)
```
  DrawBevelBox(), [403](libraries/15-other-gadtools-functions-drawbevelbox.md)
  DrawBevelBoxA(), [403](libraries/15-other-gadtools-functions-drawbevelbox.md)
  examples
```c
    complete GadTools example, [406](libraries/lib-examples-gadtoolsgadgets-c.md)
    gadget message filtering, [403](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md)
    NewMenu structure, [369](libraries/15-gadtools-library-gadtools-menus.md)
    slider gadget setup, [393](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    using CreateContext(), [400](libraries/15-gadtools-gadgets-creating-gadget-lists.md)
    using gadgets, [383](libraries/lib-examples-simplegtgadget-c.md)
    using the menu system, [372](libraries/lib-examples-gadtoolsmenu-c.md)
    using VisualInfo functions, [399](libraries/15-getvisualinfo-and-freevisualinfo.md)
```
  features of, [368](libraries/15-gadtools-library-gadtools-menus.md)
  FreeGadgets(), [382](libraries/15-gadtools-gadgets-freeing-gadgets.md)
  FreeMenus(), [377](libraries/15-functions-for-gadtools-menus-freeing-menus.md)
  function descriptions, [413](libraries/15-gadtools-library-function-reference.md)
  gadget types, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [386](libraries/15-gadtools-gadgets-the-kinds-of-gadtools-gadgets.md)
```c
    button, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [386](libraries/15-the-kinds-of-gadtools-gadgets-button-gadgets.md)
    checkboxes, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [389](libraries/15-the-kinds-of-gadtools-gadgets-checkbox-gadgets.md)
    cycle, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [390](libraries/15-the-kinds-of-gadtools-gadgets-cycle-gadgets.md)
    generic gadget, [398](libraries/15-the-kinds-of-gadtools-gadgets-generic-gadgets.md)
    integer, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [386](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    listviews, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [394](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    mutually exclusive, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [389](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md)
    numeric-display, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
    palette, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    scrollers, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [393](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    sliders, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    string, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [386](libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md)
    text-display, [378](libraries/15-gadtools-library-gadtools-gadgets.md), [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
```
  gadgets, [378](libraries/15-gadtools-library-gadtools-gadgets.md)
  GetVisualInfo(), [398](libraries/15-getvisualinfo-and-freevisualinfo.md)
  GetVisualInfoA(), [398](libraries/15-getvisualinfo-and-freevisualinfo.md)
  GTMENUITEM_USERDATA(), [372](libraries/15-gadtools-menus-the-newmenu-structure.md)
  GTMENU_USERDATA(), [372](libraries/15-gadtools-menus-the-newmenu-structure.md)
  GTMN_FrontPen(), [374](libraries/15-functions-for-gadtools-menus-creating-menus.md)
  GTMN_TextAttr, [375](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md)
  GT_BeginRefresh(), [402](libraries/15-gadtools-gadgets-gadget-refresh-functions.md)
  GT_EndRefresh(), [402](libraries/15-gadtools-gadgets-gadget-refresh-functions.md)
  GT_FilterIMsg(), [402](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md)
  GT_GetIMsg(), [381](libraries/15-gadtools-gadgets-handling-gadget-messages.md)
  GT_PostFilterIMsg(), [402](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md)
  GT_RefreshWindow(), [401](libraries/15-gadtools-gadgets-gadget-refresh-functions.md)
  GT_ReplyIMsg(), [381](libraries/15-gadtools-gadgets-handling-gadget-messages.md)
  GT_SetGadgetAttrs(), [385](libraries/15-gadtools-gadgets-modifying-gadgets.md)
  GT_SetGadgetAttrsA(), [385](libraries/15-gadtools-gadgets-modifying-gadgets.md)
  handling gadget messages, [381](libraries/15-gadtools-gadgets-handling-gadget-messages.md)
  IDCMP flags, [382](libraries/15-gadtools-gadgets-idcmp-flags.md)
  implementing gadget keyboard equivalents, [404](libraries/15-implementing-a-gadget-s-keyboard-equivalent-behavior.md)
  language-sensitive menus, [378](libraries/15-gadtools-menus-language-sensitive-menus.md)
  LayoutMenuItems(), [376](libraries/15-functions-for-gadtools-menus-layout-for-individual-menus.md)
  LayoutMenuItemsA(), [376](libraries/15-functions-for-gadtools-menus-layout-for-individual-menus.md)
  LayoutMenus(), [375](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md)
  LayoutMenusA(), [375](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md)
  LISTVIEW_KIND
```c
    GTLV_Labels, [394](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    GTLV_ReadOnly, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    GTLV_ScrollWidth, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    GTLV_Selected, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    GTLV_ShowSelected, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    GTLV_Top, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
    LAYOUTA_Spacing, [395](libraries/15-the-kinds-of-gadtools-gadgets-listview-gadgets.md)
```
  menu layout, [180](libraries/6-setting-up-menus-menu-layout.md)
  menus, [368](libraries/15-gadtools-library-gadtools-menus.md)
  menus and intuimessages, [377](libraries/15-gadtools-menus-gadtools-menus-and-intuimessages.md)
  minimal IDCMP_REFRESHWINDOW processing, [402](libraries/15-gadtools-gadgets-gadget-refresh-functions.md)
  modifying gadgets - struct, [385](libraries/15-gadtools-gadgets-modifying-gadgets.md)
  MX_KIND
```c
    GTMX_Active, [389](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md)
    GTMX_Labels, [389](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md)
    GTMX_Spacing, [390](libraries/15-the-kinds-of-gadtools-gadgets-mutually-exclusive-gadgets.md)
```
  NUMBER_KIND
```c
    GTNM_Border, [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
    GTNM_Number, [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
```
  PALETTE_KIND
```c
    GA_Disabled, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    GTPA_Color, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    GTPA_ColorOffset, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    GTPA_Depth, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    GTPA_IndicatorHeight, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
    GTPA_IndicatorWidth, [396](libraries/15-the-kinds-of-gadtools-gadgets-palette-gadgets.md)
```
  programming gadgets, [378](libraries/15-gadtools-library-gadtools-gadgets.md)
  restrictions on menus, [377](libraries/15-gadtools-menus-restrictions-on-gadtools-menus.md)
  reusing a NewGadget structure, [401](libraries/15-gadtools-gadgets-creating-gadget-lists.md)
  SCROLLER_KIND
```c
    GA_Disabled, [394](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GA_Immediate, [394](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GA_RelVerify, [394](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GTSC_Arrows, [394](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GTSC_Top, [393](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GTSC_Total, [393](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    GTSC_Visible, [393](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
    PGA_Freedom, [394](libraries/15-the-kinds-of-gadtools-gadgets-scroller-gadgets.md)
```
  SLIDER_KIND
```c
    GA_Disabled, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GA_Immediate, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GA_RelVerify, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_DispFunc, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_Level, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_LevelFormat, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_LevelPlace, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_Max, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_MaxLevelLen, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    GTSL_Min, [391](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    PGA_Freedom, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
    processing IntuiMessages, [392](libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md)
```
  struct NewGadget, [379](libraries/15-gadtools-gadgets-the-newgadget-structure.md)
  struct NewMenu, [370](libraries/15-gadtools-menus-the-newmenu-structure.md)
  TEXT_KIND

```c
    GTTX_Border, [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
    GTTX_CopyText, [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
    GTTX_Text, [397](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md)
```

---

## See Also

- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [DrawBevelBoxA — gadtools.library](../autodocs/gadtools.library.md#drawbevelboxa)
- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
- [FreeMenus — gadtools.library](../autodocs/gadtools.library.md#freemenus)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_RefreshWindow — gadtools.library](../autodocs/gadtools.library.md#gt_refreshwindow)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GT_SetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_setgadgetattrsa)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
