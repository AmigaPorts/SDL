---
title: 2.0 IncludeXREF: C
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-c
functions: []
libraries: []
---

# 2.0 IncludeXREF: C

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

_cliprects       pointer to struct ClipRect in struct Layer
```c
         +0x0040 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *50
```
_CopList         pointer to struct CopList in struct CopList
```c
         +0x0004 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *66
```
cb_ConfigDev     pointer to struct ConfigDev in struct CurrentBinding
```c
         +0x0000 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *59
```
cb_FileName      pointer to unsigned char in struct CurrentBinding
```c
         +0x0004 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *60
```
cb_ProductString pointer to unsigned char in struct CurrentBinding
```c
         +0x0008 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *61
```
cb_ToolTypes     pointer to pointer to unsigned char in struct CurrentBinding
```c
         +0x000c [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *62
```
cbh_CBport       struct MsgPort(size 0x0022 bytes) in struct ClipboardHandle
```c
         +0x0034 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *118
```
cbh_Req          struct IOClipReq(size 0x0034 bytes) in struct ClipboardHandle
```c
         +0x0000 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *117
```
cbh_SatisfyPort struct MsgPort(size 0x0022 bytes) in struct ClipboardHandle
```c
         +0x0056 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *119
```
ccode            pointer to function returning int in struct Isrvstr
```c
         +0x0016 [graphics/graphint.h](autodocs-2.0/includes-graphics-graphint-h.md): *25
```
cd_BoardAddr     pointer to void in struct ConfigDev
```c
         +0x0020 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *37
```
cd_BoardSize     unsigned long int in struct ConfigDev
```c
         +0x0024 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *38
```
cd_Driver        pointer to void in struct ConfigDev
```c
         +0x002c [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *41
```
cd_Flags         unsigned char in struct ConfigDev
```c
         +0x000e [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *34
```
cd_NextCD        pointer to struct ConfigDev in struct ConfigDev
```c
         +0x0030 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *42
```
cd_Node          struct Node(size 0x000e bytes) in struct ConfigDev
```c
         +0x0000 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *33
```
cd_Pad           unsigned char in struct ConfigDev
```c
         +0x000f [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *35
```
cd_Rom           struct ExpansionRom(size 0x0010 bytes) in struct ConfigDev
```c
         +0x0010 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *36
```
cd_SlotAddr      unsigned short int in struct ConfigDev
```c
         +0x0028 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *39
```
cd_SlotSize      unsigned short int in struct ConfigDev
```c
         +0x002a [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *40
```
cd_Unused        array [4] of unsigned long int in struct ConfigDev
```c
         +0x0034 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *43
```
ceil             #define IEEEDPCeil  [libraries/mathffp.h](autodocs-2.0/includes-libraries-mathffp-h.md): *37
```c
                 [libraries/mathieeedp.h](autodocs-2.0/includes-libraries-mathieeedp-h.md): *37
```
centphon         pointer to char in struct narrator_rb
```c
         +0x0050 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *117
```
centralize       unsigned char in struct narrator_rb
```c
         +0x004f [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *116
```
cfc_ColorTable   pointer to unsigned short int in struct ColorFontColors
```c
         +0x0004 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *148
```
cfc_Count        unsigned short int in struct ColorFontColors
```c
         +0x0002 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *147
```
cfc_Reserved     unsigned short int in struct ColorFontColors
```c
         +0x0000 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *146
```
ch_masks         pointer to unsigned char in struct narrator_rb
```c
         +0x0038 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *99
```
chanmask         unsigned char in struct narrator_rb
```c
         +0x0043 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *104
```
check_lp         pointer to struct Layer in struct Layer_Info
```c
         +0x0004 [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): *37
```
chm_ChangeCmd    long int in struct ClipHookMsg
```c
         +0x0004 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *67
```
chm_ClipID       long int in struct ClipHookMsg
```c
         +0x0008 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *69
```
chm_Type         unsigned long int in struct ClipHookMsg
```c
         +0x0000 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *66
```
ci_Data          pointer to unsigned char in struct CollectionItem
```c
         +0x0008 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *108
```
ci_Next          pointer to struct CollectionItem in struct CollectionItem
```c
         +0x0000 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *106
```
ci_Size          long int in struct CollectionItem
```c
         +0x0004 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *107
```
cia              pointer to long int in struct GfxBase
```c
         +0x002a [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *30
```
ciacra           unsigned char in struct CIA +0x0e00 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *60
ciacrb           unsigned char in struct CIA +0x0f00 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *62
ciaddra          unsigned char in struct CIA +0x0200 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *36
ciaddrb          unsigned char in struct CIA +0x0300 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *38
ciaicr           unsigned char in struct CIA +0x0d00 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *58
ciapra           unsigned char in struct CIA +0x0000 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *32
ciaprb           unsigned char in struct CIA +0x0100 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *34
ciasdr           unsigned char in struct CIA +0x0c00 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *56
ciatahi          unsigned char in struct CIA +0x0500 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *42
ciatalo          unsigned char in struct CIA +0x0400 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *40
ciatbhi          unsigned char in struct CIA +0x0700 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *46
ciatblo          unsigned char in struct CIA +0x0600 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *44
ciatodhi         unsigned char in struct CIA +0x0a00 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *52
ciatodlow        unsigned char in struct CIA +0x0800 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *48
ciatodmid        unsigned char in struct CIA +0x0900 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *50
cl_Dispatcher    struct Hook(size 0x0014 bytes) in struct IClass
```c
         +0x0000 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *29
```
cl_Flags         unsigned long int in struct IClass
```c
         +0x0030 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *43
```
cl_ID            pointer to unsigned char in struct IClass
```c
         +0x001c [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *32
```
cl_InstOffset    unsigned short int in struct IClass
```c
         +0x0020 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *35
```
cl_InstSize      unsigned short int in struct IClass
```c
         +0x0022 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *36
```
cl_ObjectCount   unsigned long int in struct IClass
```c
         +0x002c [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *41
```
cl_Reserved      unsigned long int in struct IClass
```c
         +0x0014 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *30
```
cl_SubclassCount unsigned long int in struct IClass
```c
         +0x0028 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *39
```
cl_Super         pointer to struct IClass in struct IClass
```c
         +0x0018 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *31
```
cl_UserData      unsigned long int in struct IClass
```c
         +0x0024 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *38
```
cleanup          pointer to function returning int in struct bltnode
```c
         +0x000e [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *97
```
cli_Background   long int in struct CommandLineInterface
```c
         +0x002c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *315
```
cli_CommandDir   long int in struct CommandLineInterface
```c
         +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *306
```
cli_CommandFile long int in struct CommandLineInterface
```c
         +0x0024 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *313
```
cli_CommandName long int in struct CommandLineInterface
```c
         +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *308
```
cli_CurrentInput long int in struct CommandLineInterface
```c
         +0x0020 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *312
```
cli_CurrentOutput long int in struct CommandLineInterface
```c
         +0x0030 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *316
```
cli_DefaultStack long int in struct CommandLineInterface
```c
         +0x0034 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *317
```
cli_FailLevel    long int in struct CommandLineInterface
```c
         +0x0014 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *309
```
cli_Interactive long int in struct CommandLineInterface
```c
         +0x0028 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *314
```
cli_Module       long int in struct CommandLineInterface
```c
         +0x003c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *319
```
cli_Prompt       long int in struct CommandLineInterface
```c
         +0x0018 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *310
```
cli_Result2      long int in struct CommandLineInterface
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *304
```
cli_ReturnCode   long int in struct CommandLineInterface
```c
         +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *307
```
cli_SetName      long int in struct CommandLineInterface
```c
         +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *305
```
cli_StandardInput long int in struct CommandLineInterface
```c
         +0x001c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *311
```
cli_StandardOutput long int in struct CommandLineInterface
```c
         +0x0038 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *318
```
clxcon           unsigned short int in struct Custom
```c
         +0x0098 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *93
```
clxdat           unsigned short int in struct Custom
```c
         +0x000e [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *35
```
cm_batch_items   pointer to struct TagItem in struct ColorMap
```c
         +0x0020 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *128
```
cm_vp            pointer to struct ViewPort in struct ColorMap
```c
         +0x0014 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *125
```
cm_vpe           pointer to struct ViewPortExtra in struct ColorMap
```c
         +0x0008 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *120
```
cn_ID            long int in struct ContextNode
```c
         +0x0008 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *71
```
cn_Node          struct MinNode(size 0x0008 bytes) in struct ContextNode
```c
         +0x0000 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *70
```
cn_Scan          long int in struct ContextNode
```c
         +0x0014 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *74
```
cn_Size          long int in struct ContextNode
```c
         +0x0010 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *73
```
cn_Type          long int in struct ContextNode
```c
         +0x000c [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *72
```
code             pointer to function returning int in struct Isrvstr
```c
         +0x0012 [graphics/graphint.h](autodocs-2.0/includes-graphics-graphint-h.md): *24
```
collHandler      pointer to struct collTable in struct GelsInfo
```c
         +0x0012 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *51
```
collPtrs         array [16] of pointer to function returning int in struct
```c
                 collTable
         +0x0000 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *260
```
collTable        structure tag size 0x0040 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *51
```c
                 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): 258
```
color            array [32] of unsigned short int in struct Custom
```c
         +0x0180 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *122
```
color0           unsigned short int in struct Preferences
```c
         +0x006e [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *70
```
color1           unsigned short int in struct Preferences
```c
         +0x0070 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *71
```
color17          unsigned short int in struct Preferences
```c
         +0x0066 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *64
```
color18          unsigned short int in struct Preferences
```c
         +0x0068 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *65
```
color19          unsigned short int in struct Preferences
```c
         +0x006a [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *66
```
color2           unsigned short int in struct Preferences
```c
         +0x0072 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *72
```
color3           unsigned short int in struct Preferences
```c
         +0x0074 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *73
```
colorByte        array [4] of unsigned char in union colorEntry
```c
         +0x0000 [devices/prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md): *30
```
colorEntry       union tag
```c
     size 0x0004 [devices/prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md): *28, 40, 41, 42, 43, 44
```
colorLong        unsigned long int in union colorEntry
```c
         +0x0000 [devices/prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md): *29
```
colorSByte       array [4] of char in union colorEntry
```c
         +0x0000 [devices/prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md): *31
```
control_delta_ntsc short int in struct GfxBase +0x017a [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *84
control_delta_pal short int in struct GfxBase +0x0178 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *83
cop1lc           unsigned long int in struct Custom
```c
         +0x0080 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *83
```
cop2lc           unsigned long int in struct Custom
```c
         +0x0084 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *84
```
copcon           unsigned short int in struct Custom
```c
         +0x002e [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *50
```
copinit          structure tag size 0x0078 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *92
```c
                 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): 29
```
copinit          pointer to struct copinit in struct GfxBase
```c
         +0x0026 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *29
```
copins           unsigned short int in struct Custom
```c
         +0x008c [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *87
```
copjmp1          unsigned short int in struct Custom
```c
         +0x0088 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *85
```
copjmp2          unsigned short int in struct Custom
```c
         +0x008a [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *86
```
cos              #define IEEEDPCos  [libraries/mathffp.h](autodocs-2.0/includes-libraries-mathffp-h.md): *41
```c
                 [libraries/mathieeedp.h](autodocs-2.0/includes-libraries-mathieeedp-h.md): *41
```
cosh             #define IEEEDPCosh  [libraries/mathffp.h](autodocs-2.0/includes-libraries-mathffp-h.md): *52
```c
                 [libraries/mathieeedp.h](autodocs-2.0/includes-libraries-mathieeedp-h.md): *52
```
cp_x             short int in struct RastPort +0x0024 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *74
cp_y             short int in struct RastPort +0x0026 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *74
cpl_Array        pointer to pointer to struct MsgPort in struct CliProcList
```c
         +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *267
```
cpl_First        long int in struct CliProcList +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *266
cpl_Node         struct MinNode(size 0x0008 bytes) in struct CliProcList
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *265
```
cprlist          structure tag size 0x000a [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *56, 58
```c
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 61, 62
```
cr               pointer to struct ClipRect in struct Layer
```c
         +0x0030 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *48
```
cr2              pointer to struct ClipRect in struct Layer
```c
         +0x0034 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *48
```
crb_reserved     array [5] of unsigned char in struct GfxBase
```c
         +0x00ed [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *68
```
crnew            pointer to struct ClipRect in struct Layer
```c
         +0x0038 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *48
```
ctf_CharData     array [8] of pointer to void in struct ColorTextFont
```c
         +0x0040 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *162
```
ctf_ColorFontColors pointer to struct ColorFontColors in struct ColorTextFont
```c
         +0x003c [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *161
```
ctf_Depth        unsigned char in struct ColorTextFont
```c
         +0x0036 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *155
```
ctf_FgColor      unsigned char in struct ColorTextFont
```c
         +0x0037 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *156
```
ctf_Flags        unsigned short int in struct ColorTextFont
```c
         +0x0034 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *154
```
ctf_High         unsigned char in struct ColorTextFont
```c
         +0x0039 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *158
```
ctf_Low          unsigned char in struct ColorTextFont
```c
         +0x0038 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *157
```
ctf_PlaneOnOff   unsigned char in struct ColorTextFont
```c
         +0x003b [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *160
```
ctf_PlanePick    unsigned char in struct ColorTextFont
```c
         +0x003a [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *159
```
ctf_TF           struct TextFont(size 0x0034 bytes) in struct ColorTextFont
```c
         +0x0000 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *153
```
ctl              unsigned short int in struct SpriteDef
```c
         +0x0002 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *118
```
cu_AOLPen        char in struct ConUnit +0x0105 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *84
cu_AlgoStyle     unsigned char in struct ConUnit +0x0118 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *90
cu_BgPen         char in struct ConUnit +0x0104 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *83
cu_DrawMode      char in struct ConUnit +0x0106 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *85
cu_FgPen         char in struct ConUnit +0x0103 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *82
cu_Font          pointer to struct TextFont in struct ConUnit
```c
         +0x0114 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *89
```
cu_KeyMapStruct struct KeyMap(size 0x0020 bytes) in struct ConUnit
```c
         +0x0042 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *76
```
cu_MP            struct MsgPort(size 0x0022 bytes) in struct ConUnit
```c
         +0x0000 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *56
```
cu_Mask          char in struct ConUnit +0x0102 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *81
cu_Minterms      array [8] of unsigned char in struct ConUnit
```c
         +0x010c [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *88
```
cu_Modes         array [3] of unsigned char in struct ConUnit
```c
         +0x0122 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *98
```
cu_Node          struct Node(size 0x000e bytes) in struct ClipboardUnitPartial
```c
         +0x0000 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *37
```
cu_Obsolete1     char in struct ConUnit +0x0107 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *86
cu_Obsolete2     pointer to void in struct ConUnit
```c
         +0x0108 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *87
```
cu_RawEvents     array [3] of unsigned char in struct ConUnit
```c
         +0x0125 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *99
```
cu_TabStops      array [80] of unsigned short int in struct ConUnit
```c
         +0x0062 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *78
```
cu_TxBaseline    unsigned short int in struct ConUnit
```c
         +0x011e [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *94
```
cu_TxFlags       unsigned char in struct ConUnit +0x0119 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *91
cu_TxHeight      unsigned short int in struct ConUnit
```c
         +0x011a [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *92
```
cu_TxSpacing     short int in struct ConUnit +0x0120 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *95
cu_TxWidth       unsigned short int in struct ConUnit
```c
         +0x011c [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *93
```
cu_UnitNum       unsigned long int in struct ClipboardUnitPartial
```c
         +0x000e [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *38
```
cu_Window        pointer to struct Window in struct ConUnit
```c
         +0x0022 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *58
```
cu_XCCP          short int in struct ConUnit +0x003e [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *71
cu_XCP           short int in struct ConUnit +0x0026 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *59
cu_XMax          short int in struct ConUnit +0x002a [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *61
cu_XMinShrink    short int in struct ConUnit +0x003a [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *69
cu_XRExtant      short int in struct ConUnit +0x0036 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *67
cu_XROrigin      short int in struct ConUnit +0x0032 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *65
cu_XRSize        short int in struct ConUnit +0x002e [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *63
cu_YCCP          short int in struct ConUnit +0x0040 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *72
cu_YCP           short int in struct ConUnit +0x0028 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *60
cu_YMax          short int in struct ConUnit +0x002c [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *62
cu_YMinShrink    short int in struct ConUnit +0x003c [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *70
cu_YRExtant      short int in struct ConUnit +0x0038 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *68
cu_YROrigin      short int in struct ConUnit +0x0034 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *66
cu_YRSize        short int in struct ConUnit +0x0030 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *64
current_monitor pointer to struct MonitorSpec in struct GfxBase
```c
         +0x017c [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *85
```
current_tot_cclks unsigned short int in struct GfxBase
```c
         +0x0160 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *78
```
current_tot_rows unsigned short int in struct GfxBase
```c
         +0x015e [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *77
```
CACRF_ClearD     #define (1L<<11) = 0x00000800  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *179
CACRF_ClearI     #define (1L<<3) = 0x00000008  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *175
CACRF_CopyBack   #define (1L<<31) = 0x80000000  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *183
CACRF_DBE        #define (1L<<12) = 0x00001000  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *180
CACRF_EnableD    #define (1L<<8) = 0x00000100  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *177
CACRF_EnableI    #define (1L<<0) = 0x00000001  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *173
CACRF_FreezeD    #define (1L<<9) = 0x00000200  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *178
CACRF_FreezeI    #define (1L<<1) = 0x00000002  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *174
CACRF_IBE        #define (1L<<4) = 0x00000010  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *176
CACRF_WriteAllocate #define (1L<<13) = 0x00002000  [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *182
CBD_CHANGEHOOK   #define (CMD_NONSTD+3) = 0x0000000c  [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *31
CBD_CURRENTREADID #define (CMD_NONSTD+1) = 0x0000000a
```c
                 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *29
```
CBD_CURRENTWRITEID #define (CMD_NONSTD+2) = 0x0000000b
```c
                 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *30
```
CBD_DESCRLEN     #define 40 = 0x00000028  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *38
CBD_NAMELEN      #define 24 = 0x00000018  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *36
CBD_POST         #define (CMD_NONSTD+0) = 0x00000009  [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *28
CBD_TITLELEN     #define 40 = 0x00000028  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *37
CBERR_DUP        #define 2 = 0x00000002  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *43
CBERR_OBSOLETEID #define 1 = 0x00000001  [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *33
CBERR_OK         #define 0 = 0x00000000  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *41
CBERR_SYSERR     #define 1 = 0x00000001  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *42
CBERR_VERSION    #define 3 = 0x00000003  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *44
CBM_MPS1000      #define 0x03 = 0x00000003  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *195
CDB_BADMEMORY    #define 2 = 0x00000002  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *49
CDB_CONFIGME     #define 1 = 0x00000001  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *48
CDB_SHUTUP       #define 0 = 0x00000000  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *47
CDF_BADMEMORY    #define 0x04 = 0x00000004  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *53
CDF_CONFIGME     #define 0x02 = 0x00000002  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *52
CDF_SHUTUP       #define 0x01 = 0x00000001  [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *51
CD_ASKDEFAULTKEYMAP #define (CMD_NONSTD+2) = 0x0000000b
```c
                 [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *26
```
CD_ASKKEYMAP     #define (CMD_NONSTD+0) = 0x00000009  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *24
CD_SETDEFAULTKEYMAP #define (CMD_NONSTD+3) = 0x0000000c
```c
                 [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *27
```
CD_SETKEYMAP     #define (CMD_NONSTD+1) = 0x0000000a  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *25
CEND             macro (1 argument)   [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *41
CENTER_IMAGE     #define 0x0008 = 0x00000008  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *245
CHANGEWINDOW     #define IDCMP_CHANGEWINDOW = 0x02000000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *139
```
CHANGE_FH        #define 1 = 0x00000001  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *223
CHANGE_LOCK      #define 0 = 0x00000000  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *222
CHECKBOXIDCMP    #define (IDCMP_GADGETUP) = 0x00000040
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *67
```
CHECKBOX_KIND    #define 2 = 0x00000002  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *36
CHECKED          #define 0x0100 = 0x00000100  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *132
CHECKIMAGE       #define (0x0EL) = 0x0000000e  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *110
CHECKIT          #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *118
CHECKWIDTH       #define 19 = 0x00000013  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1300
CHeight          unsigned short int in struct PropInfo
```c
         +0x000c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *489
```
CIA              structure tag size 0x0f01 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *31
CIAANAME         #define "ciaa.resource"  [resources/cia.h](autodocs-2.0/includes-resources-cia-h.md): *15
CIABNAME         #define "ciab.resource"  [resources/cia.h](autodocs-2.0/includes-resources-cia-h.md): *16
CIAB_COMCD       #define (5) = 0x00000005  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *149
CIAB_COMCTS      #define (4) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *150
CIAB_COMDSR      #define (3) = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *151
CIAB_COMDTR      #define (7) = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *147
CIAB_COMRTS      #define (6) = 0x00000006  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *148
CIAB_DSKCHANGE   #define (2) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *140
CIAB_DSKDIREC    #define (1) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *163
CIAB_DSKMOTOR    #define (7) = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *157
CIAB_DSKPROT     #define (3) = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *139
CIAB_DSKRDY      #define (5) = 0x00000005  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *137
CIAB_DSKSEL0     #define (3) = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *161
CIAB_DSKSEL1     #define (4) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *160
CIAB_DSKSEL2     #define (5) = 0x00000005  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *159
CIAB_DSKSEL3     #define (6) = 0x00000006  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *158
CIAB_DSKSIDE     #define (2) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *162
CIAB_DSKSTEP     #define (0) = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *164
CIAB_DSKTRACK0   #define (4) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *138
CIAB_GAMEPORT0   #define (6) = 0x00000006  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *136
CIAB_GAMEPORT1   #define (7) = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *135
CIAB_LED         #define (1) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *141
CIAB_OVERLAY     #define (0) = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *142
CIAB_PRTRBUSY    #define (0) = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *154
CIAB_PRTRPOUT    #define (1) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *153
CIAB_PRTRSEL     #define (2) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *152
CIACRAB_INMODE   #define 5 = 0x00000005  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *81
CIACRAB_LOAD     #define 4 = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *80
CIACRAB_OUTMODE  #define 2 = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *78
CIACRAB_PBON     #define 1 = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *77
CIACRAB_RUNMODE  #define 3 = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *79
CIACRAB_SPMODE   #define 6 = 0x00000006  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *82
CIACRAB_START    #define 0 = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *76
CIACRAB_TODIN    #define 7 = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *83
CIACRAF_INMODE   #define (1<<CIACRAB_INMODE) = 0x00000020
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *110
```
CIACRAF_LOAD     #define (1<<CIACRAB_LOAD) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *109
CIACRAF_OUTMODE  #define (1<<CIACRAB_OUTMODE) = 0x00000004
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *107
```
CIACRAF_PBON     #define (1<<CIACRAB_PBON) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *106
CIACRAF_RUNMODE  #define (1<<CIACRAB_RUNMODE) = 0x00000008
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *108
```
CIACRAF_SPMODE   #define (1<<CIACRAB_SPMODE) = 0x00000040
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *111
```
CIACRAF_START    #define (1<<CIACRAB_START) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *105
CIACRAF_TODIN    #define (1<<CIACRAB_TODIN) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *112
CIACRBB_ALARM    #define 7 = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *93
CIACRBB_INMODE0  #define 5 = 0x00000005  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *91
CIACRBB_INMODE1  #define 6 = 0x00000006  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *92
CIACRBB_LOAD     #define 4 = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *90
CIACRBB_OUTMODE  #define 2 = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *88
CIACRBB_PBON     #define 1 = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *87
CIACRBB_RUNMODE  #define 3 = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *89
CIACRBB_START    #define 0 = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *86
CIACRBF_ALARM    #define (1<<CIACRBB_ALARM) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *122
CIACRBF_INMODE0  #define (1<<CIACRBB_INMODE0) = 0x00000020
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *120
```
CIACRBF_INMODE1  #define (1<<CIACRBB_INMODE1) = 0x00000040
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *121
```
CIACRBF_IN_CNT   #define (CIACRBF_INMODE0) = 0x00000020  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *126
CIACRBF_IN_CNT_TA #define (CIACRBF_INMODE0|CIACRBF_INMODE1) = 0x00000060
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *128
```
CIACRBF_IN_PHI2  #define 0 = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *125
CIACRBF_IN_TA    #define (CIACRBF_INMODE1) = 0x00000040  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *127
CIACRBF_LOAD     #define (1<<CIACRBB_LOAD) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *119
CIACRBF_OUTMODE  #define (1<<CIACRBB_OUTMODE) = 0x00000004
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *117
```
CIACRBF_PBON     #define (1<<CIACRBB_PBON) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *116
CIACRBF_RUNMODE  #define (1<<CIACRBB_RUNMODE) = 0x00000008
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *118
```
CIACRBF_START    #define (1<<CIACRBB_START) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *115
CIAF_COMCD       #define (1<<5) = 0x00000020  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *181
CIAF_COMCTS      #define (1<<4) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *182
CIAF_COMDSR      #define (1<<3) = 0x00000008  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *183
CIAF_COMDTR      #define (1<<7) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *179
CIAF_COMRTS      #define (1<<6) = 0x00000040  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *180
CIAF_DSKCHANGE   #define (1<<2) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *172
CIAF_DSKDIREC    #define (1<<1) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *195
CIAF_DSKMOTOR    #define (1<<7) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *189
CIAF_DSKPROT     #define (1<<3) = 0x00000008  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *171
CIAF_DSKRDY      #define (1<<5) = 0x00000020  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *169
CIAF_DSKSEL0     #define (1<<3) = 0x00000008  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *193
CIAF_DSKSEL1     #define (1<<4) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *192
CIAF_DSKSEL2     #define (1<<5) = 0x00000020  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *191
CIAF_DSKSEL3     #define (1<<6) = 0x00000040  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *190
CIAF_DSKSIDE     #define (1<<2) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *194
CIAF_DSKSTEP     #define (1<<0) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *196
CIAF_DSKTRACK0   #define (1<<4) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *170
CIAF_GAMEPORT0   #define (1<<6) = 0x00000040  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *168
CIAF_GAMEPORT1   #define (1<<7) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *167
CIAF_LED         #define (1<<1) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *173
CIAF_OVERLAY     #define (1<<0) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *174
CIAF_PRTRBUSY    #define (1<<0) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *186
CIAF_PRTRPOUT    #define (1<<1) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *185
CIAF_PRTRSEL     #define (1<<2) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *184
CIAICRB_ALRM     #define 2 = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *69
CIAICRB_FLG      #define 4 = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *71
CIAICRB_IR       #define 7 = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *72
CIAICRB_SETCLR   #define 7 = 0x00000007  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *73
CIAICRB_SP       #define 3 = 0x00000003  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *70
CIAICRB_TA       #define 0 = 0x00000000  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *67
CIAICRB_TB       #define 1 = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *68
CIAICRF_ALRM     #define (1<<CIAICRB_ALRM) = 0x00000004  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *98
CIAICRF_FLG      #define (1<<CIAICRB_FLG) = 0x00000010  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *100
CIAICRF_IR       #define (1<<CIAICRB_IR) = 0x00000080  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *101
CIAICRF_SETCLR   #define (1<<CIAICRB_SETCLR) = 0x00000080
```c
                 [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *102
```
CIAICRF_SP       #define (1<<CIAICRB_SP) = 0x00000008  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *99
CIAICRF_TA       #define (1<<CIAICRB_TA) = 0x00000001  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *96
CIAICRF_TB       #define (1<<CIAICRB_TB) = 0x00000002  [hardware/cia.h](autodocs-2.0/includes-hardware-cia-h.md): *97
CINIT            macro (2 arguments)   [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *38
CLEANME          #define CLEANUP = 0x00000040  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *102
CLEANUP          #define 0x40 = 0x00000040  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *101
CLF_INLIST       #define 0x00000001 = 0x00000001  [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *44
CLIB_MACROS_H    #define  [clib/macros.h](autodocs-2.0/includes-clib-macros-h.md): *2
CLOSE            #define GTYP_CLOSE = 0x00000080  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *103
CLOSEGADGET      #define 3 = 0x00000003  [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *50
CLOSEIMAGE       #define (0x03L) = 0x00000003  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *104
CLOSEWINDOW      #define IDCMP_CLOSEWINDOW = 0x00000200
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *123
```
CLVALUE          macro (1 argument)   [rexx/rexxio.h](autodocs-2.0/includes-rexx-rexxio-h.md): *58
CLeft            short int in struct StringInfo
```c
         +0x0014 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *537
```
CMDE_NOBROKER    #define (-1) = 0xffffffff  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *137
CMDE_NOMEM       #define (-3) = 0xfffffffd  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *139
CMDE_NOPORT      #define (-2) = 0xfffffffe  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *138
CMDE_OK          #define (0) = 0x00000000  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *136
CMD_CLEAR        #define 5 = 0x00000005  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *56
CMD_DISABLED     #define -999 = 0xfffffc19  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *297
CMD_FLUSH        #define 8 = 0x00000008  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *59
CMD_INTERNAL     #define -2 = 0xfffffffe  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *296
CMD_INVALID      #define 0 = 0x00000000  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *51
CMD_NONSTD       #define 9 = 0x00000009  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *61
CMD_READ         #define 2 = 0x00000002  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *53
CMD_RESET        #define 1 = 0x00000001  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *52
CMD_START        #define 7 = 0x00000007  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *58
CMD_STOP         #define 6 = 0x00000006  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *57
CMD_SYSTEM       #define -1 = 0xffffffff  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *295
CMD_UPDATE       #define 4 = 0x00000004  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *55
CMD_WRITE        #define 3 = 0x00000003  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *54
CMOVE            macro (3 arguments)   [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *39
COERR_BADFILTER  #define 4 = 0x00000004  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *163
COERR_BADTYPE    #define 8 = 0x00000008  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *164
COERR_ISNULL     #define 1 = 0x00000001  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *161
COERR_NULLATTACH #define 2 = 0x00000002  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *162
COF_SHOW_HIDE    #define 4 = 0x00000004  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *67
COLORMAP_TRANSPARENCY #define 0x01 = 0x00000001  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *140
COLORMAP_TYPE_V1_2 #define 0x00 = 0x00000000  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *135
COLORMAP_TYPE_V1_4 #define 0x01 = 0x00000001  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *136
COLORMAP_TYPE_V36 #define COLORMAP_TYPE_V1_4 = 0x00000001
```c
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *137
```
COLORON          #define 0x0200 = 0x00000200  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *21
COLORPLANE_TRANSPARENCY #define 0x02 = 0x00000002  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *141
COMMSEQ          #define 0x0004 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *120
COMMWIDTH        #define 27 = 0x0000001b  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1301
COMPLEMENT       #define 2 = 0x00000002  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *96
COMPLEX_BIT      #define 1 = 0x00000001  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *139
CONFLAG_DEFAULT  #define 0 = 0x00000000  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *46
CONFLAG_NODRAW_ON_NEWSIZE #define 1 = 0x00000001  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *47
CONU_CHARMAP     #define 1 = 0x00000001  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *41
CONU_LIBRARY     #define -1 = 0xffffffff  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *36
CONU_SNIPMAP     #define 3 = 0x00000003  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *42
CONU_STANDARD    #define 0 = 0x00000000  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *37
COPPER_MOVE      #define 0 = 0x00000000  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *19
COPPER_WAIT      #define 1 = 0x00000001  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *20
CORRECT_BLUE     #define 0x0004 = 0x00000004  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *243
CORRECT_GREEN    #define 0x0002 = 0x00000002  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *242
CORRECT_RED      #define 0x0001 = 0x00000001  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *241
CORRECT_RGB_MASK #define (CORRECT_RED|CORRECT_GREEN|CORRECT_BLUE) = 0x00000007
```c
                 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *264
```
COUNT            short int  [exec/types.h](autodocs-2.0/includes-exec-types-h.md): *58
CPRNXTBUF        #define 2 = 0x00000002  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *21
CPR_NT_LOF       #define 0x8000 = 0x00008000  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *22
CPR_NT_SHT       #define 0x4000 = 0x00004000  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *23
CPR_NT_SYS       #define 0x2000 = 0x00002000  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *24
CPTR             typedef ULONG  [exec/types.h](autodocs-2.0/includes-exec-types-h.md): *60
CR_NEEDS_NO_CONCEALED_RASTERS #define 1 = 0x00000001  [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *79
CR_NEEDS_NO_LAYERBLIT_DAMAGE #define 2 = 0x00000002  [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *80
CSBLANK          #define 0x0008 = 0x00000008  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *156
CSCBLANKEN       #define 0x0400 = 0x00000400  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *149
CSYNCTRUE        #define 0x0004 = 0x00000004  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *157
CS_Buffer        pointer to unsigned char in struct CSource
```c
         +0x0000 [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *64
```
CS_CurChr        long int in struct CSource +0x0008 [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *66
CS_Length        long int in struct CSource +0x0004 [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *65
CSource          structure tag size 0x000c [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *63, 98
CTB_ALPHA        #define 2 = 0x00000002  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *91
CTB_DIGIT        #define 1 = 0x00000001  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *90
CTB_LOWER        #define 7 = 0x00000007  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *96
CTB_MAPCOLOR     #define 0 = 0x00000000  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *141
CTB_REXXOPR      #define 4 = 0x00000004  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *93
CTB_REXXSPC      #define 5 = 0x00000005  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *94
CTB_REXXSYM      #define 3 = 0x00000003  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *92
CTB_SPACE        #define 0 = 0x00000000  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *89
CTB_UPPER        #define 6 = 0x00000006  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *95
CTC_HCLRTAB      #define 2 = 0x00000002  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *90
CTC_HCLRTABSALL  #define 5 = 0x00000005  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *91
CTC_HSETTAB      #define 0 = 0x00000000  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *89
CTF_ALPHA        #define (1 << CTB_ALPHA) = 0x00000004  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *101
CTF_DIGIT        #define (1 << CTB_DIGIT) = 0x00000002  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *100
CTF_LOWER        #define (1 << CTB_LOWER) = 0x00000080  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *106
CTF_MAPCOLOR     #define 0x0001 = 0x00000001  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *142
CTF_REXXOPR      #define (1 << CTB_REXXOPR) = 0x00000010  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *103
CTF_REXXSPC      #define (1 << CTB_REXXSPC) = 0x00000020  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *104
CTF_REXXSYM      #define (1 << CTB_REXXSYM) = 0x00000008  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *102
CTF_SPACE        #define (1 << CTB_SPACE) = 0x00000001  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *99
CTF_UPPER        #define (1 << CTB_UPPER) = 0x00000040  [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): *105
CT_ANTIALIAS     #define 0x0004 = 0x00000004  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *139
CT_COLORFONT     #define 0x0001 = 0x00000001  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *136
CT_COLORMASK     #define 0x000F = 0x0000000f  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *135
CT_GREYFONT      #define 0x0002 = 0x00000002  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *137
CTop             short int in struct StringInfo
```c
         +0x0016 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *537
```
CURSORDOWN       #define 0x4D = 0x0000004d  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1345
CURSORLEFT       #define 0x4F = 0x0000004f  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1343
CURSORRIGHT      #define 0x4E = 0x0000004e  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1344
CURSORUP         #define 0x4C = 0x0000004c  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1342
CUSTOM           #define 0x40 = 0x00000040  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *189
CUSTOMBITMAP     #define 0x0040 = 0x00000040  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *169
CUSTOMGADGET     #define GTYP_CUSTOMGADGET = 0x00000005
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *108
```
CUSTOMIMAGEDEPTH #define (-1) = 0xffffffff  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *24
CUSTOMSCREEN     #define 0x000F = 0x0000000f  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *163
CUSTOM_HOOK      macro (1 argument)   [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *79
CUSTOM_NAME      #define 0x00 = 0x00000000  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *192
CWAIT            macro (3 arguments)   [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *40
CWidth           unsigned short int in struct PropInfo
```c
         +0x000a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *488
```
CXCMD_APPEAR     #define (19) = 0x00000013  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *126
CXCMD_DISABLE    #define (15) = 0x0000000f  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *124
CXCMD_DISAPPEAR  #define (21) = 0x00000015  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *127
CXCMD_ENABLE     #define (17) = 0x00000011  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *125
CXCMD_KILL       #define (23) = 0x00000017  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *128
CXCMD_LIST_CHG   #define (27) = 0x0000001b  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *132
CXCMD_UNIQUE     #define (25) = 0x00000019  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *131
CXM_COMMAND      #define (1 << 6) = 0x00000040  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *121
CXM_IEVENT       #define (1 << 5) = 0x00000020  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *113
CXM_UNIQUE       #define (1 << 4) = 0x00000010  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *99
CX_BROKER        #define 6 = 0x00000006  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *91
CX_CUSTOM        #define 8 = 0x00000008  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *93
CX_DEBUG         #define 7 = 0x00000007  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *92
CX_FILTER        #define 1 = 0x00000001  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *86
CX_INVALID       #define 0 = 0x00000000  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *85
CX_SEND          #define 3 = 0x00000003  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *88
CX_SIGNAL        #define 4 = 0x00000004  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *89
CX_TRANSLATE     #define 5 = 0x00000005  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *90
CX_TYPEFILTER    #define 2 = 0x00000002  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *87
CX_ZERO          #define 9 = 0x00000009  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *94
CYCLEIDCMP       #define (IDCMP_GADGETUP) = 0x00000040
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *74
```
CYCLE_KIND       #define 7 = 0x00000007  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *41
Carg             int in struct Isrvstr +0x001a [graphics/graphint.h](autodocs-2.0/includes-graphics-graphint-h.md): *26
CheckMark        pointer to struct Image in struct Window
```c
         +0x0064 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *865
```
CheckMark        pointer to struct Image in struct NewWindow
```c
         +0x0016 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *996
```
CheckMark        pointer to struct Image in struct ExtNewWindow
```c
         +0x0016 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1054
```
ChipRevBits0     unsigned char in struct GfxBase
```c
         +0x00ec [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *67
```
ChkBase          unsigned long int in struct ExecBase
```c
         +0x0026 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *43
```
ChkSum           unsigned short int in struct ExecBase
```c
         +0x0052 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *55
```
Class            unsigned long int in struct IntuiMessage
```c
         +0x0014 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *684
```
Class            "UBYTE"  [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *45
ClassID          pointer to "UBYTE"  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *23
```c
                 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): 32
```
ClearPath        pointer to struct VSprite in struct VSprite
```c
         +0x000c [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *82
```
CliProcList      structure tag size 0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *264
ClipHookMsg      structure tag size 0x000c [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *65
ClipRect         structure tag
```c
     size 0x0024 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *37, 44, 48, 49, 50, 64, 66, 67,
                             71
                 [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): 38
```
ClipRect         pointer to struct ClipRect in struct Layer
```c
         +0x0008 [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *37
```
ClipRegion       pointer to struct Region in struct Layer
```c
         +0x007e [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *55
```
ClipboardHandle structure tag size 0x0078 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *116
ClipboardUnitPartial structure tag size 0x0012 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *36, 46
Clock            long int in struct AnimOb +0x0008 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *206
ClockData        structure tag size 0x000e [utility/date.h](autodocs-2.0/includes-utility-date-h.md): *18
ClrIns           pointer to struct CopList in struct ViewPort
```c
         +0x0010 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *48
```
Code             unsigned short int in struct IntuiMessage
```c
         +0x0018 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *687
```
Code             unsigned short int in struct SGWork
```c
         +0x0018 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): *43
```
CoerceDisplayInfo pointer to void in struct ColorMap
```c
         +0x001c [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *127
```
ColdCapture      pointer to void in struct ExecBase
```c
         +0x002a [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *44
```
CollMask         pointer to short int in struct VSprite
```c
         +0x002c [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *111
```
CollectionItem   structure tag size 0x000c [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *105, 106
ColorFontColors structure tag size 0x0008 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *145, 161
ColorIndex       short int in struct ColorSpec
```c
         +0x0000 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1242
```
ColorMap         structure tag size 0x0028 [devices/printer.h](autodocs-2.0/includes-devices-printer-h.md): *164
```c
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 44, 114
```
ColorMap         pointer to struct ColorMap in struct ViewPort
```c
         +0x0004 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *44
```
ColorSpec        structure tag size 0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1241
ColorTable       pointer to void in struct ColorMap
```c
         +0x0004 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *119
```
ColorTextFont    structure tag size 0x0060 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *152
ColumnSizeChange char in struct Preferences
```c
         +0x00d9 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *115
```
Command          char in struct MenuItem +0x001a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *106
CommandLineInterface structure tag size 0x0040 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *303
Compatibility    short int in struct MonitorInfo
```c
         +0x002a [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *119
```
ConUnit          structure tag size 0x0128 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *55
ConfigDev        structure tag size 0x0044 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *32, 42, 59
ContextNode      structure tag size 0x0018 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *69
CoolCapture      pointer to void in struct ExecBase
```c
         +0x002e [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *45
```
CopIns           structure tag size 0x0006 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *26, 68, 69
CopIns           pointer to struct CopIns in struct CopList
```c
         +0x000c [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *68
```
CopLStart        pointer to unsigned short int in struct CopList
```c
         +0x0014 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *70
```
CopList          structure tag
```c
     size 0x0022 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *31, 63, 65, 66, 86, 87
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 46, 47, 48
```
CopList          pointer to struct CopList in struct UCopList
```c
         +0x0008 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *87
```
CopPtr           pointer to struct CopIns in struct CopList
```c
         +0x0010 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *69
```
CopSStart        pointer to unsigned short int in struct CopList
```c
         +0x0018 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *71
```
Count            short int in struct CopList +0x001c [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *72
Count            unsigned short int in struct ColorMap
```c
         +0x0002 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *118
```
Count            short int in struct AreaInfo +0x0010 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *29
Count            char in struct Border +0x0007 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *603
CurrentBinding   structure tag size 0x0010 [libraries/configvars.h](autodocs-2.0/includes-libraries-configvars-h.md): *58
```c
                 [libraries/expansionbase.h](autodocs-2.0/includes-libraries-expansionbase-h.md): 53
```
Custom           structure tag size 0x01e6 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *27
CustomBitMap     pointer to struct BitMap in struct NewScreen
```c
         +0x001c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *332
```
CustomBitMap     pointer to struct BitMap in struct ExtNewScreen
```c
         +0x001c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *355
```
CxCustom         macro (2 arguments)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *29
CxDebug          macro (1 argument)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *28
CxFilter         macro (1 argument)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *23
CxMsg            "LONG"  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *76
CxObj            "LONG"  [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *75
CxSender         macro (2 arguments)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *25
CxSignal         macro (2 arguments)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *26
CxTranslate      macro (1 argument)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *27
CxTypeFilter     macro (1 argument)   [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): *24

