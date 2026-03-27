---
title: 2.0 IncludeXREF: G
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-g
functions: []
libraries: []
---

# 2.0 IncludeXREF: G

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

gelHead          pointer to struct VSprite in struct GelsInfo
```c
         +0x0002 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *46
```
gelTail          pointer to struct VSprite in struct GelsInfo
```c
         +0x0006 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *46
```
genloc           array [4] of unsigned short int in struct copinit
```c
         +0x005c [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *100
```
gi_Domain        struct IBox(size 0x0008 bytes) in struct GadgetInfo
```c
         +0x0014 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *49
```
gi_DrInfo        pointer to struct DrawInfo in struct GadgetInfo
```c
         +0x001e [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *61
```
gi_Layer         pointer to struct Layer in struct GadgetInfo
```c
         +0x0010 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *38
```
gi_Pens          struct (no tag) (size 0x0002 bytes) in struct GadgetInfo
```c
         +0x001c [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *55
```
gi_RastPort      pointer to struct RastPort in struct GadgetInfo
```c
         +0x000c [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *37
```
gi_Requester     pointer to struct Requester in struct GadgetInfo
```c
         +0x0008 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *31
```
gi_Reserved      array [6] of unsigned long int in struct GadgetInfo
```c
         +0x0022 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *66
```
gi_Screen        pointer to struct Screen in struct GadgetInfo
```c
         +0x0000 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *29
```
gi_Window        pointer to struct Window in struct GadgetInfo
```c
         +0x0004 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *30
```
gpGoInactive     structure tag size 0x000c [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *231
gpHitTest        structure tag size 0x000c [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *176
gpInput          structure tag size 0x0014 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *201
gpRender         structure tag size 0x0010 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *188
gpgi_Abort       unsigned long int in struct gpGoInactive
```c
         +0x0008 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *236
```
gpgi_GInfo       pointer to struct GadgetInfo in struct gpGoInactive
```c
         +0x0004 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *233
```
gpht_GInfo       pointer to struct GadgetInfo in struct gpHitTest
```c
         +0x0004 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *178
```
gpht_Mouse       struct (no tag) (size 0x0004 bytes) in struct gpHitTest
```c
         +0x0008 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *182
```
gpi_GInfo        pointer to struct GadgetInfo in struct gpInput
```c
         +0x0004 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *203
```
gpi_IEvent       pointer to struct InputEvent in struct gpInput
```c
         +0x0008 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *204
```
gpi_Mouse        struct (no tag) (size 0x0004 bytes) in struct gpInput
```c
         +0x0010 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *209
```
gpi_Termination pointer to long int in struct gpInput
```c
         +0x000c [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *205
```
gpr_GInfo        pointer to struct GadgetInfo in struct gpRender
```c
         +0x0004 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *190
```
gpr_RPort        pointer to struct RastPort in struct gpRender
```c
         +0x0008 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *191
```
gpr_Redraw       long int in struct gpRender
```c
         +0x000c [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *192
```
gpt_Keys         unsigned short int in struct GamePortTrigger
```c
         +0x0000 [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *39
```
gpt_Timeout      unsigned short int in struct GamePortTrigger
```c
         +0x0002 [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *40
```
gpt_XDelta       unsigned short int in struct GamePortTrigger
```c
         +0x0004 [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *41
```
gpt_YDelta       unsigned short int in struct GamePortTrigger
```c
         +0x0006 [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *42
```
gs_Head          struct List(size 0x000e bytes) in struct Layer_Info
```c
         +0x0046 [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): *41
```
GACT_ACTIVEGADGET #define 0x4000 = 0x00004000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *385
GACT_ALTKEYMAP   #define 0x1000 = 0x00001000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *372
GACT_BOOLEXTEND  #define 0x2000 = 0x00002000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *365
GACT_BORDERSNIFF #define 0x8000 = 0x00008000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *362
GACT_BOTTOMBORDER #define 0x0080 = 0x00000080  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *361
GACT_ENDGADGET   #define 0x0004 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *342
GACT_FOLLOWMOUSE #define 0x0008 = 0x00000008  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *352
GACT_IMMEDIATE   #define 0x0002 = 0x00000002  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *336
GACT_LEFTBORDER  #define 0x0020 = 0x00000020  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *359
GACT_LONGINT     #define 0x0800 = 0x00000800  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *371
GACT_RELVERIFY   #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *330
GACT_RIGHTBORDER #define 0x0010 = 0x00000010  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *358
GACT_STRINGCENTER #define 0x0200 = 0x00000200  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *369
GACT_STRINGEXTEND #define 0x2000 = 0x00002000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *373
GACT_STRINGLEFT  #define 0x0000 = 0x00000000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *368
GACT_STRINGRIGHT #define 0x0400 = 0x00000400  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *370
GACT_TOGGLESELECT #define 0x0100 = 0x00000100  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *364
GACT_TOPBORDER   #define 0x0040 = 0x00000040  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *360
GADGBACKFILL     #define 0x0001 = 0x00000001  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *111
GADGDISABLED     #define GFLG_DISABLED = 0x00000100
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *60
```
GADGET0002       #define GTYP_GADGET0002 = 0x00000002
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *105
```
GADGETCLASS      #define "gadgetclass"  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *47
GADGETCOUNT      #define 8 = 0x00000008  [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *46
GADGETDOWN       #define IDCMP_GADGETDOWN = 0x00000020
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *119
```
GADGETTYPE       #define GTYP_GADGETTYPE = 0x0000fc00
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *91
```
GADGETUP         #define IDCMP_GADGETUP = 0x00000040
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *120
```
GADGET_BOX       macro (1 argument)   [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *28
GADGHBOX         #define GFLG_GADGHBOX = 0x00000001
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *51
```
GADGHCOMP        #define GFLG_GADGHCOMP = 0x00000000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *50
```
GADGHIGHBITS     #define GFLG_GADGHIGHBITS = 0x00000003
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *49
```
GADGHIMAGE       #define GFLG_GADGHIMAGE = 0x00000002
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *52
```
GADGHNONE        #define GFLG_GADGHNONE = 0x00000003
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *53
```
GADGIMAGE        #define GFLG_GADGIMAGE = 0x00000004
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *54
```
GADGIMMEDIATE    #define GACT_IMMEDIATE = 0x00000002
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *70
```
GADTOOLBIT       #define (0x8000) = 0x00008000  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *55
GADTOOLMASK      #define (~GADTOOLBIT) = 0xffff7fff  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *57
GA_BORDER        #define GA_Border = 0x8003000b  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *190
GA_BOTTOMBORDER  #define GA_BottomBorder = 0x8003001b
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *205
```
GA_Border        #define (GA_Dummy + 0x000B) = 0x8003000b
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *44
```
GA_BottomBorder  #define (GA_Dummy + 0x001B) = 0x8003001b
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *60
```
GA_DISABLED      #define GA_Disabled = 0x8003000e  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *193
GA_DRAWINFO      #define GA_DrawInfo = 0x80030021  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *211
GA_Disabled      #define (GA_Dummy + 0x000E) = 0x8003000e
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *47
```
GA_DrawInfo      #define (GA_Dummy + 0x0021) = 0x80030021
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *79
```
GA_Dummy         #define (TAG_USER +0x30000) = 0x80030000
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *33
```
GA_ENDGADGET     #define GA_EndGadget = 0x80030014
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *198
```
GA_EndGadget     #define (GA_Dummy + 0x0014) = 0x80030014
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *53
```
GA_FOLLOWMOUSE   #define GA_FollowMouse = 0x80030017
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *201
```
GA_FollowMouse   #define (GA_Dummy + 0x0017) = 0x80030017
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *56
```
GA_GZZGADGET     #define GA_GZZGadget = 0x8003000f
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *194
```
GA_GZZGadget     #define (GA_Dummy + 0x000F) = 0x8003000f
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *48
```
GA_HEIGHT        #define GA_Height = 0x80030007  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *186
GA_HIGHLIGHT     #define GA_Highlight = 0x8003000d
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *192
```
GA_Height        #define (GA_Dummy + 0x0007) = 0x80030007
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *40
```
GA_Highlight     #define (GA_Dummy + 0x000D) = 0x8003000d
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *46
```
GA_ID            #define (GA_Dummy + 0x0010) = 0x80030010
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *49
```
GA_IMAGE         #define GA_Image = 0x8003000a  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *189
GA_IMMEDIATE     #define GA_Immediate = 0x80030015
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *199
```
GA_INTUITEXT     #define GA_IntuiText = 0x80030022
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *212
```
GA_Image         #define (GA_Dummy + 0x000A) = 0x8003000a
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *43
```
GA_Immediate     #define (GA_Dummy + 0x0015) = 0x80030015
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *54
```
GA_IntuiText     #define (GA_Dummy + 0x0022) = 0x80030022
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *85
```
GA_LABELIMAGE    #define GA_LabelImage = 0x80030023
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *213
```
GA_LEFT          #define GA_Left = 0x80030001  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *180
GA_LEFTBORDER    #define GA_LeftBorder = 0x80030019
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *203
```
GA_LabelImage    #define (GA_Dummy + 0x0023) = 0x80030023
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *88
```
GA_Left          #define (GA_Dummy + 0x0001) = 0x80030001
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *34
```
GA_LeftBorder    #define (GA_Dummy + 0x0019) = 0x80030019
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *58
```
GA_NEXT          #define GA_Next = 0x80030020  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *210
GA_Next          #define (GA_Dummy + 0x0020) = 0x80030020
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *76
```
GA_PREVIOUS      #define GA_Previous = 0x8003001f  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *209
GA_Previous      #define (GA_Dummy + 0x001F) = 0x8003001f
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *69
```
GA_RELBOTTOM     #define GA_RelBottom = 0x80030004
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *183
```
GA_RELHEIGHT     #define GA_RelHeight = 0x80030008
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *187
```
GA_RELRIGHT      #define GA_RelRight = 0x80030002  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *181
GA_RELVERIFY     #define GA_RelVerify = 0x80030016
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *200
```
GA_RELWIDTH      #define GA_RelWidth = 0x80030006  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *185
GA_RIGHTBORDER   #define GA_RightBorder = 0x80030018
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *202
```
GA_RelBottom     #define (GA_Dummy + 0x0004) = 0x80030004
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *37
```
GA_RelHeight     #define (GA_Dummy + 0x0008) = 0x80030008
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *41
```
GA_RelRight      #define (GA_Dummy + 0x0002) = 0x80030002
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *35
```
GA_RelVerify     #define (GA_Dummy + 0x0016) = 0x80030016
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *55
```
GA_RelWidth      #define (GA_Dummy + 0x0006) = 0x80030006
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *39
```
GA_RightBorder   #define (GA_Dummy + 0x0018) = 0x80030018
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *57
```
GA_SELECTED      #define GA_Selected = 0x80030013  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *197
GA_SELECTRENDER  #define GA_SelectRender = 0x8003000c
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *191
```
GA_SPECIALINFO   #define GA_SpecialInfo = 0x80030012
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *196
```
GA_SYSGADGET     #define GA_SysGadget = 0x8003001d
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *207
```
GA_SYSGTYPE      #define GA_SysGType = 0x8003001e  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *208
GA_SelectRender  #define (GA_Dummy + 0x000C) = 0x8003000c
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *45
```
GA_Selected      #define (GA_Dummy + 0x0013) = 0x80030013
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *52
```
GA_SpecialInfo   #define (GA_Dummy + 0x0012) = 0x80030012
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *51
```
GA_SysGType      #define (GA_Dummy + 0x001E) = 0x8003001e
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *66
```
GA_SysGadget     #define (GA_Dummy + 0x001D) = 0x8003001d
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *64
```
GA_TEXT          #define GA_Text = 0x80030009  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *188
GA_TOGGLESELECT  #define GA_ToggleSelect = 0x8003001c
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *206
```
GA_TOP           #define GA_Top = 0x80030003  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *182
GA_TOPBORDER     #define GA_TopBorder = 0x8003001a
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *204
```
GA_TabCycle      #define (GA_Dummy + 0x0024) = 0x80030024
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *93
```
GA_Text          #define (GA_Dummy + 0x0009) = 0x80030009
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *42
```
GA_ToggleSelect  #define (GA_Dummy + 0x001C) = 0x8003001c
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *61
```
GA_Top           #define (GA_Dummy + 0x0003) = 0x80030003
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *36
```
GA_TopBorder     #define (GA_Dummy + 0x001A) = 0x8003001a
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *59
```
GA_USERDATA      #define GA_UserData = 0x80030011  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *195
GA_UserData      #define (GA_Dummy + 0x0011) = 0x80030011
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *50
```
GA_WIDTH         #define GA_Width = 0x80030005  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *184
GA_Width         #define (GA_Dummy + 0x0005) = 0x80030005
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *38
```
GELGONE          #define 0x0400 = 0x00000400  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *29
GENERIC_KIND     #define 0 = 0x00000000  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *34
GENLOC           #define 2 = 0x00000002  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *96
GENLOCK_AUDIO    #define 0x0100 = 0x00000100  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *95
GENLOCK_VIDEO    #define 0x0002 = 0x00000002  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *90
GFLG_DISABLED    #define 0x0100 = 0x00000100  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *297
GFLG_GADGHBOX    #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *269
GFLG_GADGHCOMP   #define 0x0000 = 0x00000000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *268
GFLG_GADGHIGHBITS #define 0x0003 = 0x00000003  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *267
GFLG_GADGHIMAGE  #define 0x0002 = 0x00000002  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *270
GFLG_GADGHNONE   #define 0x0003 = 0x00000003  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *271
GFLG_GADGIMAGE   #define 0x0004 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *276
GFLG_LABELIMAGE  #define 0x2000 = 0x00002000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *310
GFLG_LABELITEXT  #define 0x0000 = 0x00000000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *308
GFLG_LABELMASK   #define 0x3000 = 0x00003000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *307
GFLG_LABELSTRING #define 0x1000 = 0x00001000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *309
GFLG_RELBOTTOM   #define 0x0008 = 0x00000008  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *286
GFLG_RELHEIGHT   #define 0x0040 = 0x00000040  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *289
GFLG_RELRIGHT    #define 0x0010 = 0x00000010  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *287
GFLG_RELWIDTH    #define 0x0020 = 0x00000020  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *288
GFLG_SELECTED    #define 0x0080 = 0x00000080  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *291
GFLG_STRINGEXTEND #define 0x0400 = 0x00000400  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *323
GFLG_TABCYCLE    #define 0x0200 = 0x00000200  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *315
GFXB_BIG_BLITS   #define 0 = 0x00000000  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *103
GFXB_HR_AGNUS    #define 0 = 0x00000000  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *104
GFXB_HR_DENISE   #define 1 = 0x00000001  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *105
GFXF_BIG_BLITS   #define 1 = 0x00000001  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *107
GFXF_HR_AGNUS    #define 1 = 0x00000001  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *108
GFXF_HR_DENISE   #define 2 = 0x00000002  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *109
GIMMEZEROZERO    #define WFLG_GIMMEZEROZERO = 0x00000400
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *158
```
GLOBAL           #define extern  [exec/types.h](autodocs-2.0/includes-exec-types-h.md): *20
GLOBALSZ         #define 200 = 0x000000c8  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *185, 188
GMR_GADGETHIT    #define (0x00000004) = 0x00000004
```c
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *185
```
GMR_MEACTIVE     #define (0) = 0x00000000  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *217
GMR_NEXTACTIVE   #define (1 << 4) = 0x00000010  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *227
GMR_NOREUSE      #define (1 << 1) = 0x00000002  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *218
GMR_PREVACTIVE   #define (1 << 5) = 0x00000020  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *228
GMR_REUSE        #define (1 << 2) = 0x00000004  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *219
GMR_VERIFY       #define (1 << 3) = 0x00000008  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *220
GM_Dummy         #define (-1) = 0xffffffff  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *164
GM_GOACTIVE      #define (2) = 0x00000002  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *169
GM_GOINACTIVE    #define (4) = 0x00000004  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *171
GM_HANDLEINPUT   #define (3) = 0x00000003  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *170
GM_HITTEST       #define (0) = 0x00000000  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *167
GM_RENDER        #define (1) = 0x00000001  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *168
GPCT_ABSJOYSTICK #define 3 = 0x00000003  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *51
GPCT_ALLOCATED   #define -1 = 0xffffffff  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *46
GPCT_MOUSE       #define 1 = 0x00000001  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *49
GPCT_NOCONTROLLER #define 0 = 0x00000000  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *47
GPCT_RELJOYSTICK #define 2 = 0x00000002  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *50
GPDERR_SETCTYPE  #define 1 = 0x00000001  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *55
GPD_ASKCTYPE     #define (CMD_NONSTD+1) = 0x0000000a  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *25
GPD_ASKTRIGGER   #define (CMD_NONSTD+3) = 0x0000000c  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *27
GPD_READEVENT    #define (CMD_NONSTD+0) = 0x00000009  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *24
GPD_SETCTYPE     #define (CMD_NONSTD+2) = 0x0000000b  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *26
GPD_SETTRIGGER   #define (CMD_NONSTD+4) = 0x0000000d  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *28
GPTB_DOWNKEYS    #define 0 = 0x00000000  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *33
GPTB_UPKEYS      #define 1 = 0x00000001  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *35
GPTF_DOWNKEYS    #define (1<<0) = 0x00000001  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *34
GPTF_UPKEYS      #define (1<<1) = 0x00000002  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *36
GRAPHICSNAME     #define "graphics.library"  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *111
GRAPHICS_CLIP_H  #define  [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *2, 1
```c
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 23
```
GRAPHICS_COLLIDE_H #define  [graphics/collide.h](autodocs-2.0/includes-graphics-collide-h.md): *2
GRAPHICS_COPPER_H #define  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *2, 1
GRAPHICS_DISPLAYINFO_H #define  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *2
GRAPHICS_DISPLAY_H #define  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *2
GRAPHICS_GELS_H  #define  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *2
GRAPHICS_GFXBASE_H #define  [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *2
GRAPHICS_GFXMACROS_H #define  [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *2
GRAPHICS_GFXNODES_H #define  [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md): *2, 1
```c
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): 19
```
GRAPHICS_GFX_H   #define  [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *2, 1
```c
                 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): 19
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 21
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): 23
                 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): 19
                 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): 19
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 19
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): 19
                 [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md): 19
```
GRAPHICS_GRAPHINT_H #define  [graphics/graphint.h](autodocs-2.0/includes-graphics-graphint-h.md): *2
GRAPHICS_LAYERS_H #define  [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): *2, 1
```c
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 35
```
GRAPHICS_MONITOR_H #define  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *2, 1
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): 23
```
GRAPHICS_RASTPORT_H #define  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *2, 1
```c
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 31
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): 19
```
GRAPHICS_REGIONS_H #define  [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md): *2
GRAPHICS_SCALE_H #define  [graphics/scale.h](autodocs-2.0/includes-graphics-scale-h.md): *2
GRAPHICS_SPRITE_H #define  [graphics/sprite.h](autodocs-2.0/includes-graphics-sprite-h.md): *2
GRAPHICS_TEXT_H  #define  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *2, 1
```c
                 [libraries/asl.h](autodocs-2.0/includes-libraries-asl-h.md): 40
                 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): 24
```
GRAPHICS_VIDEOCONTROL_H #define  [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *2
GRAPHICS_VIEW_H  #define  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *2, 1
```c
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 27
```
GREDRAW_REDRAW   #define (1) = 0x00000001  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *197
GREDRAW_TOGGLE   #define (0) = 0x00000000  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *198
GREDRAW_UPDATE   #define (2) = 0x00000002  [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *196
GRELBOTTOM       #define GFLG_RELBOTTOM = 0x00000008
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *55
```
GRELHEIGHT       #define GFLG_RELHEIGHT = 0x00000040
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *58
```
GRELRIGHT        #define GFLG_RELRIGHT = 0x00000010
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *56
```
GRELWIDTH        #define GFLG_RELWIDTH = 0x00000020
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *57
```
GREY_SCALE2      #define 0x1000 = 0x00001000  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *260
GROUPGCLASS      #define "groupgclass"  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *52
GTBB_Recessed    #define GT_TagBase+51 = 0x80080033
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *246
```
GTCB_Checked     #define GT_TagBase+4 = 0x80080004  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *195
GTCY_Active      #define GT_TagBase+15 = 0x8008000f
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *213
```
GTCY_Labels      #define GT_TagBase+14 = 0x8008000e
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *212
```
GTIN_MaxChars    #define GT_TagBase+48 = 0x80080030
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *241
```
GTIN_Number      #define GT_TagBase+47 = 0x8008002f
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *240
```
GTLV_Labels      #define GT_TagBase+6 = 0x80080006  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *198
GTLV_ReadOnly    #define GT_TagBase+7 = 0x80080007  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *200
GTLV_ScrollWidth #define GT_TagBase+8 = 0x80080008  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *201
GTLV_Selected    #define GT_TagBase+54 = 0x80080036
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *254
```
GTLV_ShowSelected #define GT_TagBase+53 = 0x80080035
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *252
```
GTLV_Top         #define GT_TagBase+5 = 0x80080005  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *197
GTMENUITEM_USERDATA macro (1 argument)   [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *173
GTMENU_INVALID   #define 0x00000002 = 0x00000002  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *181
GTMENU_NOMEM     #define 0x00000003 = 0x00000003  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *182
GTMENU_TRIMMED   #define 0x00000001 = 0x00000001  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *180
GTMENU_USERDATA macro (1 argument)   [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *172
GTMN_FrontPen    #define GT_TagBase+50 = 0x80080032
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *244
```
GTMN_FullMenu    #define GT_TagBase+62 = 0x8008003e
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *274
```
GTMN_Menu        #define GT_TagBase+60 = 0x8008003c
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *267
```
GTMN_SecondaryError #define GT_TagBase+63 = 0x8008003f
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *276
```
GTMN_TextAttr    #define GT_TagBase+49 = 0x80080031
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *243
```
GTMX_Active      #define GT_TagBase+10 = 0x8008000a
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *204
```
GTMX_Labels      #define GT_TagBase+9 = 0x80080009  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *203
GTMX_Spacing     #define GT_TagBase+61 = 0x8008003d
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *270
```
GTNM_Border      #define GT_TagBase+58 = 0x8008003a
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *261
```
GTNM_Number      #define GT_TagBase+13 = 0x8008000d
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *210
```
GTNW_Active      #define GTCY_Active = 0x8008000f  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *289
GTNW_Labels      #define GTCY_Labels = 0x8008000e  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *288
GTPA_Color       #define GT_TagBase+17 = 0x80080011
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *216
```
GTPA_ColorOffset #define GT_TagBase+18 = 0x80080012
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *217
```
GTPA_Depth       #define GT_TagBase+16 = 0x80080010
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *215
```
GTPA_IndicatorHeight #define GT_TagBase+20 = 0x80080014
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *219
```
GTPA_IndicatorWidth #define GT_TagBase+19 = 0x80080013
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *218
```
GTSC_Arrows      #define GT_TagBase+59 = 0x8008003b
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *264
```
GTSC_Overlap     #define GT_TagBase+24 = 0x80080018
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *224
```
GTSC_Top         #define GT_TagBase+21 = 0x80080015
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *221
```
GTSC_Total       #define GT_TagBase+22 = 0x80080016
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *222
```
GTSC_Visible     #define GT_TagBase+23 = 0x80080017
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *223
```
GTSL_DispFunc    #define GT_TagBase+44 = 0x8008002c
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *235
```
GTSL_Level       #define GT_TagBase+40 = 0x80080028
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *230
```
GTSL_LevelFormat #define GT_TagBase+42 = 0x8008002a
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *232
```
GTSL_LevelPlace  #define GT_TagBase+43 = 0x8008002b
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *233
```
GTSL_Max         #define GT_TagBase+39 = 0x80080027
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *229
```
GTSL_MaxLevelLen #define GT_TagBase+41 = 0x80080029
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *231
```
GTSL_Min         #define GT_TagBase+38 = 0x80080026
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *228
```
GTST_MaxChars    #define GT_TagBase+46 = 0x8008002e
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *238
```
GTST_String      #define GT_TagBase+45 = 0x8008002d
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *237
```
GTTX_Border      #define GT_TagBase+57 = 0x80080039
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *259
```
GTTX_CopyText    #define GT_TagBase+12 = 0x8008000c
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *208
```
GTTX_Text        #define GT_TagBase+11 = 0x8008000b
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *206
```
GTVI_NWTags      #define GT_TagBase+2 = 0x80080002  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *191
GTVI_NewWindow   #define GT_TagBase+1 = 0x80080001  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *190
GTYPEMASK        #define GTYP_GTYPEMASK = 0x00000007
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *109
```
GTYP_BOOLGADGET  #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *410
GTYP_CLOSE       #define 0x0080 = 0x00000080  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *408
GTYP_CUSTOMGADGET #define 0x0005 = 0x00000005  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *414
GTYP_GADGET0002  #define 0x0002 = 0x00000002  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *411
GTYP_GADGETTYPE  #define 0xFC00 = 0x0000fc00  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *395
GTYP_GTYPEMASK   #define 0x0007 = 0x00000007  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *415
GTYP_GZZGADGET   #define 0x2000 = 0x00002000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *398
GTYP_PROPGADGET  #define 0x0003 = 0x00000003  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *412
GTYP_REQGADGET   #define 0x1000 = 0x00001000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *399
GTYP_SCRGADGET   #define 0x4000 = 0x00004000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *397
GTYP_SDOWNBACK   #define 0x0070 = 0x00000070  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *407
GTYP_SDRAGGING   #define 0x0030 = 0x00000030  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *403
GTYP_SIZING      #define 0x0010 = 0x00000010  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *401
GTYP_STRGADGET   #define 0x0004 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *413
GTYP_SUPFRONT    #define 0x0050 = 0x00000050  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *405
GTYP_SYSGADGET   #define 0x8000 = 0x00008000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *396
GTYP_WDOWNBACK   #define 0x0060 = 0x00000060  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *406
GTYP_WDRAGGING   #define 0x0020 = 0x00000020  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *402
GTYP_WUPFRONT    #define 0x0040 = 0x00000040  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *404
GT_Private0      #define GT_TagBase+3 = 0x80080003  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *193
GT_Reserved0     #define GT_TagBase+55 = 0x80080037
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *255
```
GT_Reserved1     #define GT_TagBase+56 = 0x80080038
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *256
```
GT_TagBase       #define TAG_USER + 0x80000 = 0x80080000
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *188
```
GT_Underscore    #define GT_TagBase+64 = 0x80080040
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *279
```
GT_VisualInfo    #define GT_TagBase+52 = 0x80080034
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *248
```
GVB_BINARY_VAR   #define 10 = 0x0000000a  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *53
GVB_GLOBAL_ONLY  #define 8 = 0x00000008  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *49
GVB_LOCAL_ONLY   #define 9 = 0x00000009  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *51
GVF_BINARY_VAR   #define 0x400 = 0x00000400  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *54
GVF_GLOBAL_ONLY  #define 0x100 = 0x00000100  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *50
GVF_LOCAL_ONLY   #define 0x200 = 0x00000200  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *52
GZZGADGET        #define GTYP_GZZGADGET = 0x00002000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *94
```
GZZHeight        short int in struct Window +0x0072 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *881
GZZMouseX        short int in struct Window +0x006c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *875
GZZMouseY        short int in struct Window +0x006e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *876
GZZWidth         short int in struct Window +0x0070 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *880
Gadget           structure tag
```c
     size 0x002c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *153, 216, 218, 841, 990,
                             1052
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 135, 324, 354
                 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): 35
                 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): 65
```
Gadget           pointer to struct Gadget in struct SGWork
```c
         +0x0000 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): *35
```
GadgetID         unsigned short int in struct Gadget
```c
         +0x0026 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *260
```
GadgetInfo       structure tag size 0x003a [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *27
```c
                 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): 81, 91
                 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): 178, 190, 203, 233
                 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): 49
```
GadgetInfo       pointer to struct GadgetInfo in struct SGWork
```c
         +0x0026 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): *49
```
GadgetRender     pointer to void in struct Gadget
```c
         +0x0012 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *233
```
GadgetText       pointer to struct IntuiText in struct Gadget
```c
         +0x001a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *240
```
GadgetType       unsigned short int in struct Gadget
```c
         +0x0010 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *227
```
Gadgets          pointer to struct Gadget in struct NewScreen
```c
         +0x0018 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *324
```
Gadgets          pointer to struct Gadget in struct ExtNewScreen
```c
         +0x0018 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *354
```
GamePortTrigger structure tag size 0x0008 [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *38
GelsInfo         structure tag size 0x0026 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *41, 63
GelsInfo         pointer to struct GelsInfo in struct RastPort
```c
         +0x0014 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *63
```
GfxBase          structure tag size 0x01a6 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *25
Green            unsigned short int in struct ColorSpec

```c
         +0x0004 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1244
```
