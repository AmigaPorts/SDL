---
title: gadtools.library (basename: _GadToolsBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: gadtools-library-basename-gadtoolsbase-v36
functions: [CreateMenusA, GT_GetIMsg]
libraries: [gadtools.library]
---

# gadtools.library (basename: _GadToolsBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CreateContext(glistptr)(a0)             - Create a place for GadTools
```c
                                          context data. (V36)
```
CreateGadgetA(kind,gad,ng,taglist)(d0/a0/a1/a2)
```c
                                        - Allocate and initialize a
                                          gadtools gadget. (V36)
```
CreateMenusA(newmenu,taglist)(a0/a1)    - Allocate and fill out a menu
```c
                                          structure. (V36)
```
DrawBevelBoxA(rport,left,top,width,height,taglist)(a0,d0/d1/d2/d3/a1)
```c
                                        - Draws a bevelled box. (V36)
```
FreeGadgets(gad)(a0)                    - Free a linked list of gadgets.
```c
                                          (V36)
```
FreeMenus(menu)(a0)                     - Frees memory allocated by
```c
                                          CreateMenusA(). (V36)
```
FreeVisualInfo(vi)(a0)                  - Return any resources taken by
```c
                                          GetVisualInfo. (V36)
```
GetVisualInfoA(screen,taglist)(a0/a1)   - Get information GadTools needs
```c
                                          for visuals. (V36)
```
GT_BeginRefresh(win)(a0)                - Begin refreshing friendly to
```c
                                          GadTools. (V36)
```
GT_EndRefresh(win,complete)(a0,d0)      - End refreshing friendly to
```c
                                          GadTools. (V36)
```
GT_FilterIMsg(imsg)(a1)                 - Filter an IntuiMessage through
```c
                                          GadTools. (V36)
```
GT_GetIMsg(iport)(a0)                   - Get an IntuiMessage, with
```c
                                          GadTools processing. (V36)
```
GT_PostFilterIMsg(imsg)(a1)             - Return the unfiltered message
                                          after
GT_RefreshWindow(win,req)(a0/a1)        - Refresh all the GadTools
```c
                                          gadgets. (V36)
```
GT_ReplyIMsg(imsg)(a1)                  - Reply a message obtained with
```c
                                          GT_GetIMsg(). (V36)
```
GT_SetGadgetAttrsA(gad,win,req,taglist)(a0/a1/a2/a3)
```c
                                        - Change the attributes of a
                                          GadTools gadget. (V36)
```
LayoutMenuItemsA(firstitem,vi,taglist)(a0/a1/a2)
```c
                                        - Position all the menu items.
                                          (V36)
```
LayoutMenusA(firstmenu,vi,taglist)(a0/a1/a2)

```c
                                        - Position all the menus and menu
                                          items. (V36)
```

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
