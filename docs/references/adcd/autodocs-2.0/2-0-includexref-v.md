---
title: 2.0 IncludeXREF: V
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-v
functions: []
libraries: []
---

# 2.0 IncludeXREF: V

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

_ViewPort        pointer to struct ViewPort in struct CopList
```c
         +0x0008 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *67
```
vblank           struct AnalogSignalInterval(size 0x0004 bytes) in struct
```c
                 SpecialMonitor
         +0x002e [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *151
```
vbsrv            struct Interrupt(size 0x0016 bytes) in struct GfxBase
```c
         +0x004a [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *36
```
vbstop           unsigned short int in struct Custom
```c
         +0x01ce [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *130
```
vbstrt           unsigned short int in struct Custom
```c
         +0x01cc [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *129
```
vhposr           unsigned short int in struct Custom
```c
         +0x0006 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *31
```
vhposw           unsigned short int in struct Custom
```c
         +0x002c [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *49
```
voice            struct narrator_rb(size 0x0058 bytes) in struct mouth_rb
```c
         +0x0000 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *129
```
volume           unsigned short int in struct narrator_rb
```c
         +0x003e [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *101
```
vposr            unsigned short int in struct Custom
```c
         +0x0004 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *30
```
vposw            unsigned short int in struct Custom
```c
         +0x002a [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *48
```
vsstop           unsigned short int in struct Custom
```c
         +0x01ca [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *128
```
vsstrt           unsigned short int in struct Custom
```c
         +0x01e0 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *139
```
vsync            struct AnalogSignalInterval(size 0x0004 bytes) in struct
```c
                 SpecialMonitor
         +0x0036 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *153
```
vsync_hblank     array [2] of unsigned short int in struct copinit
```c
         +0x0000 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *94
```
vtotal           unsigned short int in struct Custom
```c
         +0x01c8 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *127
```
VANILLAKEY       #define IDCMP_VANILLAKEY = 0x00200000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *135
```
VARBEAM          #define 0x0080 = 0x00000080  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *152
VARCSYNC         #define 0x0010 = 0x00000010  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *155
VARHSYNC         #define 0x0100 = 0x00000100  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *151
VARVBLANK        #define 0x1000 = 0x00001000  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *147
VARVSYNC         #define 0x0200 = 0x00000200  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *150
VBlank           char in struct GfxBase +0x00a0 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *40
VBlankFrequency unsigned char in struct ExecBase +0x0212 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *111
VGA70_BEAMCON    #define (SPECIAL_BEAMCON ^ VSYNCTRUE) = 0x00001a8a
```c
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *121
```
VGA70_COLORCLOCKS #define (STANDARD_COLORCLOCKS/2) = 0x00000071
```c
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *108
```
VGA70_DENISE_MIN #define 59 = 0x0000003b  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *110
VGA70_HBSTOP     #define 0x1E = 0x0000001e  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *115
VGA70_HBSTRT     #define 0x08 = 0x00000008  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *112
VGA70_HSSTOP     #define 0x1C = 0x0000001c  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *114
VGA70_HSSTRT     #define 0x0E = 0x0000000e  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *113
VGA70_MONITOR_NAME #define "vga70.monitor"  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *122
VGA70_TOTAL_ROWS #define 449 = 0x000001c1  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *109
VGA70_VBSTOP     #define 0x0F73 = 0x00000f73  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *119
VGA70_VBSTRT     #define 0x0000 = 0x00000000  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *116
VGA70_VSSTOP     #define 0x0388 = 0x00000388  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *118
VGA70_VSSTRT     #define 0x02A6 = 0x000002a6  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *117
VGAEXTRAHALFBRITELACE_KEY #define 0x00031085 = 0x00031085
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *203
```
VGAEXTRAHALFBRITE_KEY #define 0x00031084 = 0x00031084
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *202
```
VGAEXTRALORESDPF2_KEY #define 0x00031444 = 0x00031444
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *196
```
VGAEXTRALORESDPF_KEY #define 0x00031404 = 0x00031404
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *190
```
VGAEXTRALORESLACEDPF2_KEY #define 0x00031445 = 0x00031445
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *199
```
VGAEXTRALORESLACEDPF_KEY #define 0x00031405 = 0x00031405
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *193
```
VGAEXTRALORESLACE_KEY #define 0x00031005 = 0x00031005
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *186
```
VGAEXTRALORES_KEY #define 0x00031004 = 0x00031004
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *182
```
VGAHAMLACE_KEY   #define 0x00031805 = 0x00031805  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *189
VGAHAM_KEY       #define 0x00031804 = 0x00031804  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *185
VGALORESDPF2_KEY #define 0x00039444 = 0x00039444  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *197
VGALORESDPF_KEY  #define 0x00039404 = 0x00039404  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *191
VGALORESLACEDPF2_KEY #define 0x00039445 = 0x00039445
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *200
```
VGALORESLACEDPF_KEY #define 0x00039405 = 0x00039405
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *194
```
VGALORESLACE_KEY #define 0x00039005 = 0x00039005  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *187
VGALORES_KEY     #define 0x00039004 = 0x00039004  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *183
VGAPRODUCTDPF2_KEY #define 0x00039464 = 0x00039464
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *198
```
VGAPRODUCTDPF_KEY #define 0x00039424 = 0x00039424
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *192
```
VGAPRODUCTLACEDPF2_KEY #define 0x00039465 = 0x00039465
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *201
```
VGAPRODUCTLACEDPF_KEY #define 0x00039425 = 0x00039425
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *195
```
VGAPRODUCTLACE_KEY #define 0x00039025 = 0x00039025
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *188
```
VGAPRODUCT_KEY   #define 0x00039024 = 0x00039024  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *184
VGA_COLORCLOCKS  #define (STANDARD_COLORCLOCKS/2) = 0x00000071
```c
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *93
```
VGA_DENISE_MIN   #define 59 = 0x0000003b  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *95
VGA_HBSTOP       #define 0x1E = 0x0000001e  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *100
VGA_HBSTRT       #define 0x08 = 0x00000008  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *97
VGA_HSSTOP       #define 0x1C = 0x0000001c  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *99
VGA_HSSTRT       #define 0x0E = 0x0000000e  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *98
VGA_MONITOR_ID   #define 0x00031000 = 0x00031000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *180
VGA_MONITOR_NAME #define "vga.monitor"  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *106
VGA_TOTAL_ROWS   #define (STANDARD_NTSC_ROWS*2) = 0x0000020c
```c
                 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *94
```
VGA_VBSTOP       #define 0x0CCD = 0x00000ccd  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *104
VGA_VBSTRT       #define 0x0000 = 0x00000000  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *101
VGA_VSSTOP       #define 0x0235 = 0x00000235  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *103
VGA_VSSTRT       #define 0x0153 = 0x00000153  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *102
VIDEOCONTROL_BATCH #define 0x10 = 0x00000010  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *144
VIEWPORT_EXTRA_TYPE #define 2 = 0x00000002  [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md): *34
VIEW_EXTRA_TYPE  #define 1 = 0x00000001  [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md): *33
VISITOR          #define WFLG_VISITOR = 0x08000000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *170
```
VOID             #define void  [exec/types.h](autodocs-2.0/includes-exec-types-h.md): *27
VPF_A2024        #define 0x40 = 0x00000040  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *103
VPF_AGNUS        #define 0x20 = 0x00000020  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *104
VPF_TENHZ        #define 0x20 = 0x00000020  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *105
VPModeID         unsigned long int in struct ColorMap
```c
         +0x0024 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *129
```
VPOSRLOF         #define 0x8000 = 0x00008000  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *40
VP_HIDE          #define 0x2000 = 0x00002000  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *99
VPotRes          unsigned short int in struct PropInfo
```c
         +0x0010 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *490
```
VSBob            pointer to struct Bob in struct VSprite
```c
         +0x0034 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *116
```
VSIZEBITS        #define 16-HSIZEBITS = 0x0000000a  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *16
VSIZEMASK        #define 0x3FF = 0x000003ff  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *18
VSOVERFLOW       #define 0x0800 = 0x00000800  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *30
VSPRITE          #define 0x0001 = 0x00000001  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *22
VSYNCTRUE        #define 0x0002 = 0x00000002  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *158
VSprite          structure tag size 0x003c [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *46
```c
                 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): 70, 74, 75, 81, 82, 156, 233
```
VTAG_ATTACH_CM_GET #define 0x8000001B = 0x8000001b
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *51
```
VTAG_ATTACH_CM_SET #define 0x8000000B = 0x8000000b
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *35
```
VTAG_BATCH_CM_CLR #define 0x8000000D = 0x8000000d
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *37
```
VTAG_BATCH_CM_GET #define 0x8000001C = 0x8000001c
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *52
```
VTAG_BATCH_CM_SET #define 0x8000000E = 0x8000000e
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *38
```
VTAG_BATCH_ITEMS_ADD #define 0x8000001F = 0x8000001f
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *55
```
VTAG_BATCH_ITEMS_GET #define 0x8000001D = 0x8000001d
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *53
```
VTAG_BATCH_ITEMS_SET #define 0x8000001E = 0x8000001e
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *54
```
VTAG_BITPLANEKEY_CLR #define 0x80000002 = 0x80000002
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *26
```
VTAG_BITPLANEKEY_GET #define 0x80000016 = 0x80000016
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *46
```
VTAG_BITPLANEKEY_SET #define 0x80000003 = 0x80000003
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *27
```
VTAG_BORDERBLANK_CLR #define 0x80000004 = 0x80000004
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *28
```
VTAG_BORDERBLANK_GET #define 0x80000017 = 0x80000017
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *47
```
VTAG_BORDERBLANK_SET #define 0x80000005 = 0x80000005
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *29
```
VTAG_BORDERNOTRANS_CLR #define 0x80000006 = 0x80000006
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *30
```
VTAG_BORDERNOTRANS_GET #define 0x80000018 = 0x80000018
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *48
```
VTAG_BORDERNOTRANS_SET #define 0x80000007 = 0x80000007
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *31
```
VTAG_CHROMAKEY_CLR #define 0x80000000 = 0x80000000
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *24
```
VTAG_CHROMAKEY_GET #define 0x80000015 = 0x80000015
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *45
```
VTAG_CHROMAKEY_SET #define 0x80000001 = 0x80000001
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *25
```
VTAG_CHROMA_PEN_CLR #define 0x80000008 = 0x80000008
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *32
```
VTAG_CHROMA_PEN_GET #define 0x80000019 = 0x80000019
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *49
```
VTAG_CHROMA_PEN_SET #define 0x80000009 = 0x80000009
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *33
```
VTAG_CHROMA_PLANE_GET #define 0x8000001A = 0x8000001a
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *50
```
VTAG_CHROMA_PLANE_SET #define 0x8000000A = 0x8000000a
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *34
```
VTAG_COERCE_DISP_GET #define 0x80000011 = 0x80000011
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *41
```
VTAG_COERCE_DISP_SET #define 0x80000012 = 0x80000012
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *42
```
VTAG_END_CM      #define 0x00000000 = 0x00000000  [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *23
VTAG_NEXTBUF_CM  #define 0x8000000C = 0x8000000c  [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *36
VTAG_NORMAL_DISP_GET #define 0x8000000F = 0x8000000f
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *39
```
VTAG_NORMAL_DISP_SET #define 0x80000010 = 0x80000010
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *40
```
VTAG_USERCLIP_CLR #define 0x80000025 = 0x80000025
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *61
```
VTAG_USERCLIP_GET #define 0x80000023 = 0x80000023
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *59
```
VTAG_USERCLIP_SET #define 0x80000024 = 0x80000024
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *60
```
VTAG_VIEWPORTEXTRA_GET #define 0x80000013 = 0x80000013
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *43
```
VTAG_VIEWPORTEXTRA_SET #define 0x80000014 = 0x80000014
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *44
```
VTAG_VPMODEID_CLR #define 0x80000022 = 0x80000022
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *58
```
VTAG_VPMODEID_GET #define 0x80000020 = 0x80000020
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *56
```
VTAG_VPMODEID_SET #define 0x80000021 = 0x80000021
```c
                 [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md): *57
```
VUserExt         short int in struct VSprite +0x003a [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *133
VUserStuff       #define WORD  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *56, 133
VWAITPOS         #define u3.u4.u1.VWaitPos  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *49
VWaitPos         short int in union (no tag)  +0x0000 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *36
VWritef          macro (2 arguments)   [dos/stdio.h](autodocs-2.0/includes-dos-stdio-h.md): *24
VctrPtr          pointer to short int in struct AreaInfo
```c
         +0x0004 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *26
```
VctrTbl          pointer to short int in struct AreaInfo
```c
         +0x0000 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *25
```
VertBody         unsigned short int in struct PropInfo
```c
         +0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *485
```
VertPot          unsigned short int in struct PropInfo
```c
         +0x0004 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *465
```
VideoOScan       struct Rectangle(size 0x0008 bytes) in struct DimensionInfo
```c
         +0x002a [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *102
```
View             structure tag size 0x0012 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *58, 73
```c
                 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): 28
                 [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): 72
```
View             pointer to struct View in struct ViewExtra
```c
         +0x0018 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *73
```
ViewExtra        structure tag size 0x0020 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *70
ViewInitX        short int in struct Preferences
```c
         +0x0078 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *78
```
ViewInitY        short int in struct Preferences
```c
         +0x007a [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *78
```
ViewLord         struct View(size 0x0012 bytes) in struct IntuitionBase
```c
         +0x0022 [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *72
```
ViewModes        unsigned short int in struct NewScreen
```c
         +0x000c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *316
```
ViewModes        unsigned short int in struct ExtNewScreen
```c
         +0x000c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *350
```
ViewPort         structure tag size 0x0028 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *67
```c
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 41, 43, 60, 82, 125
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): 127
```
ViewPort         pointer to struct ViewPort in struct View
```c
         +0x0000 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *60
```
ViewPort         pointer to struct ViewPort in struct ViewPortExtra
```c
         +0x0018 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *82
```
ViewPort         struct ViewPort(size 0x0028 bytes) in struct Screen
```c
         +0x002c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *127
```
ViewPortExtra    structure tag size 0x0024 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *79, 120
ViewPosition     struct tPoint(size 0x0004 bytes) in struct MonitorInfo
```c
         +0x0014 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *113
```
ViewPositionRange struct Rectangle(size 0x0008 bytes) in struct MonitorInfo
```c
         +0x001c [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *115
```
ViewResolution   struct tPoint(size 0x0004 bytes) in struct MonitorInfo
```c
         +0x0018 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *114
```
ViewXOffset      char in struct Preferences
```c
         +0x0076 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *76
```
ViewYOffset      char in struct Preferences

```c
         +0x0077 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *77
```
