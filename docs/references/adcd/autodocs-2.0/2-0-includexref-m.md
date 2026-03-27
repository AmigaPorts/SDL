---
title: 2.0 IncludeXREF: M
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-m
functions: []
libraries: []
---

# 2.0 IncludeXREF: M

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

mc_Bytes         unsigned long int in struct MemChunk
```c
         +0x0004 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *24
```
mc_Next          pointer to struct MemChunk in struct MemChunk
```c
         +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *23
```
mday             unsigned short int in struct ClockData
```c
         +0x0006 [utility/date.h](autodocs-2.0/includes-utility-date-h.md): *23
```
me_Addr          #define me_Un.meu_Addr  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *52
me_Length        unsigned long int in struct MemEntry
```c
         +0x0004 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *47
```
me_Reqs          #define me_Un.meu_Reqs  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *51
me_Un            union (no tag) (size 0x0004 bytes) in struct MemEntry
```c
         +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *46
```
me_un            #define me_Un  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *50
message          struct IOStdReq(size 0x0030 bytes) in struct narrator_rb
```c
         +0x0000 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *94
```
meu_Addr         pointer to void in union (no tag)  +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *45
meu_Reqs         unsigned long int in union (no tag)
```c
         +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *44
```
mh_Attributes    unsigned short int in struct MemHeader
```c
         +0x000e [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *32
```
mh_First         pointer to struct MemChunk in struct MemHeader
```c
         +0x0010 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *33
```
mh_Free          unsigned long int in struct MemHeader
```c
         +0x001c [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *36
```
mh_Lower         pointer to void in struct MemHeader +0x0014 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *34
mh_Node          struct Node(size 0x000e bytes) in struct MemHeader
```c
         +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *31
```
mh_Upper         pointer to void in struct MemHeader +0x0018 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *35
min              unsigned short int in struct ClockData
```c
         +0x0002 [utility/date.h](autodocs-2.0/includes-utility-date-h.md): *21
```
min_row          unsigned short int in struct MonitorSpec
```c
         +0x002a [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *37
```
minterms         array [8] of unsigned char in struct RastPort
```c
         +0x0028 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *75
```
ml_ME            array [1] of struct MemEntry(size 0x0008 bytes) in struct
```c
                 MemList
         +0x0010 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *61
```
ml_Node          struct Node(size 0x000e bytes) in struct MemList
```c
         +0x0000 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *59
```
ml_NumEntries    unsigned short int in struct MemList
```c
         +0x000e [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *60
```
ml_me            #define ml_ME  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *64
mlh_Head         pointer to struct MinNode in struct MinList
```c
         +0x0000 [exec/lists.h](autodocs-2.0/includes-exec-lists-h.md): *34
```
mlh_Tail         pointer to struct MinNode in struct MinList
```c
         +0x0004 [exec/lists.h](autodocs-2.0/includes-exec-lists-h.md): *35
```
mlh_TailPred     pointer to struct MinNode in struct MinList
```c
         +0x0008 [exec/lists.h](autodocs-2.0/includes-exec-lists-h.md): *36
```
mln_Pred         pointer to struct MinNode in struct MinNode
```c
         +0x0004 [exec/nodes.h](autodocs-2.0/includes-exec-nodes-h.md): *35
```
mln_Succ         pointer to struct MinNode in struct MinNode
```c
         +0x0000 [exec/nodes.h](autodocs-2.0/includes-exec-nodes-h.md): *34
```
mn_Length        unsigned short int in struct Message +0x0012 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *52
mn_Node          struct Node(size 0x000e bytes) in struct Message
```c
         +0x0000 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *50
```
mn_ReplyPort     pointer to struct MsgPort in struct Message
```c
         +0x000e [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *51
```
mode             unsigned short int in struct narrator_rb
```c
         +0x0034 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *97
```
monitor_id       unsigned short int in struct GfxBase
```c
         +0x00f2 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *69
```
month            unsigned short int in struct ClockData
```c
         +0x0008 [utility/date.h](autodocs-2.0/includes-utility-date-h.md): *24
```
mouth_rb         structure tag size 0x005c [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *128
mouths           unsigned char in struct narrator_rb
```c
         +0x0042 [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *103
```
mp_Flags         unsigned char in struct MsgPort +0x000e [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *32
mp_MsgList       struct List(size 0x000e bytes) in struct MsgPort
```c
         +0x0014 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *35
```
mp_Node          struct Node(size 0x000e bytes) in struct MsgPort
```c
         +0x0000 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *31
```
mp_SigBit        unsigned char in struct MsgPort +0x000f [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *33
mp_SigTask       pointer to void in struct MsgPort +0x0010 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *34
mp_SoftInt       #define mp_SigTask  [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *38
ms_Flags         unsigned short int in struct MonitorSpec
```c
         +0x0018 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *30
```
ms_LegalView     struct Rectangle(size 0x0008 bytes) in struct MonitorSpec
```c
         +0x0042 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *45
```
ms_Node          struct ExtendedNode(size 0x0018 bytes) in struct MonitorSpec
```c
         +0x0000 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *29
```
ms_OpenCount     unsigned short int in struct MonitorSpec
```c
         +0x0030 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *39
```
ms_Special       pointer to struct SpecialMonitor in struct MonitorSpec
```c
         +0x002c [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *38
```
ms_maxoscan      pointer to function returning long int in struct MonitorSpec
```c
         +0x004a [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *46
```
ms_reserved00    unsigned long int in struct MonitorSpec
```c
         +0x0094 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *52
```
ms_reserved01    unsigned long int in struct MonitorSpec
```c
         +0x0098 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *53
```
ms_scale         pointer to function returning long int in struct MonitorSpec
```c
         +0x003a [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *42
```
ms_transform     pointer to function returning long int in struct MonitorSpec
```c
         +0x0032 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *40
```
ms_translate     pointer to function returning long int in struct MonitorSpec
```c
         +0x0036 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *41
```
ms_videoscan     pointer to function returning long int in struct MonitorSpec
```c
         +0x004e [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *47
```
ms_xoffset       unsigned short int in struct MonitorSpec
```c
         +0x003e [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *43
```
ms_yoffset       unsigned short int in struct MonitorSpec
```c
         +0x0040 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *44
```
MAKE_ID          macro (4 arguments)   [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): *143
MALE             #define 0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *63
MANUALF0         #define 2 = 0x00000002  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *67
MATHIEEERESOURCEF_DBLBAS #define (1<<0) = 0x00000001
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *49
```
MATHIEEERESOURCEF_DBLTRANS #define (1<<1) = 0x00000002
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *50
```
MATHIEEERESOURCEF_EXTBAS #define (1<<4) = 0x00000010
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *53
```
MATHIEEERESOURCEF_EXTTRANS #define (1<<5) = 0x00000020
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *54
```
MATHIEEERESOURCEF_SGLBAS #define (1<<2) = 0x00000004
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *51
```
MATHIEEERESOURCEF_SGLTRANS #define (1<<3) = 0x00000008
```c
                 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *52
```
MAX              macro (2 arguments)   [clib/macros.h](autodocs-2.0/includes-clib-macros-h.md): *15
MAXBODY          #define 0xFFFF = 0x0000ffff  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *514
MAXBYTESPERROW   #define 4096 = 0x00001000  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *25
MAXCENT          #define 100 = 0x00000064  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *88
MAXFONTMATCHWEIGHT #define 32767 = 0x00007fff  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): *87
MAXFONTNAME      #define 32 = 0x00000020  [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *62, 76
MAXFONTPATH      #define 256 = 0x00000100  [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *28, 31, 38
MAXFREQ          #define 28000 = 0x00006d60  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *84
MAXINT           #define 0x7FFFFFFF = 0x7fffffff  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *45
MAXPITCH         #define 320 = 0x00000140  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *82
MAXPOT           #define 0xFFFF = 0x0000ffff  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *515
MAXPUBSCREENNAME #define (139) = 0x0000008b  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *394
MAXRATE          #define 400 = 0x00000190  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *80
MAXRMARG         #define 15 = 0x0000000f  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *121
MAXTABS          #define 80 = 0x00000050  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *52, 78
MAXVOL           #define 64 = 0x00000040  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *86
MAX_MULTIARGS    #define 128 = 0x00000080  [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *124
MAX_TEMPLATE_ITEMS #define 100 = 0x00000064  [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *117
MCOMPAT_MIXED    #define 0 = 0x00000000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *126
MCOMPAT_NOBODY   #define -1 = 0xffffffff  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *128
MCOMPAT_SELF     #define 1 = 0x00000001  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *127
MEMCLEAR         #define (1L << 16) = 0x00010000  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *221
MEMF_24BITDMA    #define (1L<<9) = 0x00000200  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *75
MEMF_ANY         #define (0L) = 0x00000000  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *70
MEMF_CHIP        #define (1L<<1) = 0x00000002  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *72
MEMF_CLEAR       #define (1L<<16) = 0x00010000  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *77
MEMF_FAST        #define (1L<<2) = 0x00000004  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *73
MEMF_LARGEST     #define (1L<<17) = 0x00020000  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *78
MEMF_LOCAL       #define (1L<<8) = 0x00000100  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *74
MEMF_PUBLIC      #define (1L<<0) = 0x00000001  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *71
MEMF_REVERSE     #define (1L<<18) = 0x00040000  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *79
MEMF_TOTAL       #define (1L<<19) = 0x00080000  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *80
MEMMASK          #define 0xFFFFFFF0 = 0xfffffff0  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *218
MEMQUANT         #define 16L = 0x00000010  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *217
MEMQUICK         #define (1L << 0 ) = 0x00000001  [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *220
MEM_BLOCKMASK    #define (MEM_BLOCKSIZE-1) = 0x00000007  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *83
MEM_BLOCKSIZE    #define 8L = 0x00000008  [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *82
MENUCANCEL       #define 0x0002 = 0x00000002  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *767
MENUDOWN         #define (IECODE_RBUTTON) = 0x00000069
```c
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1333
```
MENUENABLED      #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *77
MENUHELP         #define IDCMP_MENUHELP = 0x01000000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *138
```
MENUHOT          #define 0x0001 = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *766
MENUNULL         #define 0xFFFF = 0x0000ffff  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1288
MENUNUM          macro (1 argument)   [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1266
MENUPICK         #define IDCMP_MENUPICK = 0x00000100
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *122
```
MENUSTATE        #define WFLG_MENUSTATE = 0x00008000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *163
```
MENUTOGGLE       #define 0x0008 = 0x00000008  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *121
MENUTOGGLED      #define 0x4000 = 0x00004000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *137
MENUUP           #define (IECODE_RBUTTON | IECODE_UP_PREFIX) = 0x000000e9
```c
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1332
```
MENUVERIFY       #define IDCMP_MENUVERIFY = 0x00002000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *127
```
MENUWAITING      #define 0x0003 = 0x00000003  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *768
MENU_IMAGE       #define 128 = 0x00000080  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *139
MENU_USERDATA    macro (1 argument)   [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *176
MIDDLEDOWN       #define (IECODE_MBUTTON) = 0x0000006a
```c
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1334
```
MIDDLEUP         #define (IECODE_MBUTTON | IECODE_UP_PREFIX) = 0x000000ea
```c
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1335
```
MIDRAWN          #define 0x0100 = 0x00000100  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *80
MIN              macro (2 arguments)   [clib/macros.h](autodocs-2.0/includes-clib-macros-h.md): *16
MINBYTESPERROW   #define 128 = 0x00000080  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *24
MINCENT          #define 0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *87
MINFREQ          #define 5000 = 0x00001388  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *83
MININT           #define 0x80000000 = 0x80000000  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *46
MINPITCH         #define 65 = 0x00000041  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *81
MINRATE          #define 40 = 0x00000028  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *79
MINVOL           #define 0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *85
MIN_NTSC_ROW     #define 21 = 0x00000015  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *80
MIN_PAL_ROW      #define 29 = 0x0000001d  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *81
MIN_VGA70_ROW    #define 35 = 0x00000023  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *111
MIN_VGA_ROW      #define 29 = 0x0000001d  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *96
MISCNAME         #define "misc.resource"  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *43
MKBADDR          macro (1 argument)   [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *113
MODELCLASS       #define "modelclass"  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *54
MODE_640         #define 0x8000 = 0x00008000  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *16
MODE_NEWFILE     #define 1006 = 0x000003ee  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *31
MODE_OLDFILE     #define 1005 = 0x000003ed  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *29
MODE_READWRITE   #define 1004 = 0x000003ec  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *33
MONITOR_ID_MASK  #define 0xFFFF1000 = 0xffff1000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *145
MONITOR_SPEC_TYPE #define 4 = 0x00000004  [graphics/gfxnodes.h](autodocs-2.0/includes-graphics-gfxnodes-h.md): *36
MOUSEBUTTONS     #define IDCMP_MOUSEBUTTONS = 0x00000008
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *117
```
MOUSEMOVE        #define IDCMP_MOUSEMOVE = 0x00000010
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *118
```
MOUSE_ACCEL      #define (1<<15) = 0x00008000  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *138
MR_ALLOCMISCRESOURCE #define (LIB_BASE) = 0xfffffffa  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *40
MR_FREEMISCRESOURCE #define (LIB_BASE-LIB_VECTSIZE) = 0xfffffff4
```c
                 [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *41
```
MR_PARALLELBITS  #define 3 = 0x00000003  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *35
MR_PARALLELPORT  #define 2 = 0x00000002  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *33
MR_SERIALBITS    #define 1 = 0x00000001  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *31
MR_SERIALPORT    #define 0 = 0x00000000  [resources/misc.h](autodocs-2.0/includes-resources-misc-h.md): *30
MTYPE_APPICON    #define 8 = 0x00000008  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *99
MTYPE_APPMENUITEM #define 9 = 0x00000009  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *100
MTYPE_APPWINDOW  #define 7 = 0x00000007  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *98
MTYPE_CLOSEDOWN  #define 5 = 0x00000005  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *96
MTYPE_COPYEXIT   #define 10 = 0x0000000a  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *101
MTYPE_DISKCHANGE #define 3 = 0x00000003  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *94
MTYPE_ICONPUT    #define 11 = 0x0000000b  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *102
MTYPE_IOPROC     #define 6 = 0x00000006  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *97
MTYPE_PSTD       #define 1 = 0x00000001  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *92
MTYPE_TIMER      #define 4 = 0x00000004  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *95
MTYPE_TOOLEXIT   #define 2 = 0x00000002  [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *93
MULTIPLY_DIMENSIONS #define 0x0080 = 0x00000080  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *251
MUSTDRAW         #define 0x0008 = 0x00000008  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *25
MXIDCMP          #define (IDCMP_GADGETDOWN) = 0x00000020
```c
                 [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *72
```
MXIMAGE          #define (0x0FL) = 0x0000000f  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *111
MX_KIND          #define 5 = 0x00000005  [libraries/gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md): *39
M_ASM            #define ">1"  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *99
M_AWM            #define "?7"  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *100
M_LNM            #define 20 = 0x00000014  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *98
```c
                 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): 98
```
Mask             unsigned char in struct RastPort
```c
         +0x0018 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *64
```
Mask             pointer to unsigned short int in struct BoolInfo
```c
         +0x0002 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *431
```
MathIEEEBase     structure tag size 0x003c [libraries/mathlibrary.h](autodocs-2.0/includes-libraries-mathlibrary-h.md): *21
MathIEEEBase_LibNode struct Library(size 0x0022 bytes) in struct MathIEEEBase
```c
         +0x0000 [libraries/mathlibrary.h](autodocs-2.0/includes-libraries-mathlibrary-h.md): *23
```
MathIEEEBase_TaskCloseLib pointer to function returning int in struct
```c
                 MathIEEEBase
         +0x0038 [libraries/mathlibrary.h](autodocs-2.0/includes-libraries-mathlibrary-h.md): *26
```
MathIEEEBase_TaskOpenLib pointer to function returning int in struct
```c
                 MathIEEEBase
         +0x0034 [libraries/mathlibrary.h](autodocs-2.0/includes-libraries-mathlibrary-h.md): *25
```
MathIEEEBase_reserved array [18] of unsigned char in struct MathIEEEBase
```c
         +0x0022 [libraries/mathlibrary.h](autodocs-2.0/includes-libraries-mathlibrary-h.md): *24
```
MathIEEEResource structure tag size 0x002c [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *35
MathIEEEResource_BaseAddr pointer to unsigned short int in struct
```c
                 MathIEEEResource
         +0x0010 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *39
```
MathIEEEResource_DblBasInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x0014 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *40
```
MathIEEEResource_DblTransInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x0018 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *41
```
MathIEEEResource_ExtBasInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x0024 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *44
```
MathIEEEResource_ExtTransInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x0028 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *45
```
MathIEEEResource_Flags unsigned short int in struct MathIEEEResource
```c
         +0x000e [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *38
```
MathIEEEResource_Node struct Node(size 0x000e bytes) in struct
```c
                 MathIEEEResource
         +0x0000 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *37
```
MathIEEEResource_SglBasInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x001c [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *42
```
MathIEEEResource_SglTransInit pointer to function returning void in struct
```c
                 MathIEEEResource
         +0x0020 [libraries/mathresource.h](autodocs-2.0/includes-libraries-mathresource-h.md): *43
```
MaxChars         short int in struct StringInfo
```c
         +0x000a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *530
```
MaxCount         short int in struct cprlist +0x0008 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *60
MaxCount         short int in struct CopList +0x001e [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *73
MaxCount         short int in struct AreaInfo +0x0012 [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *30
MaxDepth         unsigned short int in struct DimensionInfo
```c
         +0x0010 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *95
```
MaxDisplayColumn unsigned short int in struct GfxBase
```c
         +0x00d6 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *57
```
MaxDisplayRow    unsigned short int in struct GfxBase
```c
         +0x00d4 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *56
```
MaxExtMem        pointer to void in struct ExecBase
```c
         +0x004e [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *53
```
MaxHeight        unsigned short int in struct Window
```c
         +0x0016 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *805
```
MaxHeight        unsigned short int in struct NewWindow
```c
         +0x002c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1026
```
MaxHeight        unsigned short int in struct ExtNewWindow
```c
         +0x002c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1061
```
MaxLocMem        unsigned long int in struct ExecBase
```c
         +0x003e [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *49
```
MaxOScan         struct Rectangle(size 0x0008 bytes) in struct DimensionInfo
```c
         +0x0022 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *101
```
MaxRasterHeight unsigned short int in struct DimensionInfo
```c
         +0x0018 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *99
```
MaxRasterWidth   unsigned short int in struct DimensionInfo
```c
         +0x0016 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *98
```
MaxWidth         unsigned short int in struct Window
```c
         +0x0014 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *805
```
MaxWidth         unsigned short int in struct NewWindow
```c
         +0x002a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1026
```
MaxWidth         unsigned short int in struct ExtNewWindow
```c
         +0x002a [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1061
```
MaxX             short int in struct Rectangle +0x0004 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *32
MaxX             long int in struct Rect32 +0x0008 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *38
MaxY             short int in struct Rectangle +0x0006 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *32
MaxY             long int in struct Rect32 +0x000c [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *38
MeMask           short int in struct VSprite +0x0020 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *102
MemChunk         structure tag size 0x0008 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *22, 23, 33
MemEntry         structure tag size 0x0008 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *42, 61
MemHeader        structure tag size 0x0020 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *30
MemList          structure tag size 0x0018 [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md): *58
MemList          struct List(size 0x000e bytes) in struct ExecBase
```c
         +0x0142 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *86
```
Memory           pointer to unsigned char in struct Remember
```c
         +0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1235
```
Menu             structure tag size 0x001e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *62, 64, 809
MenuHBorder      char in struct Screen +0x0022 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *121
MenuItem         structure tag
```c
     size 0x0022 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *69, 90, 92, 108
```
MenuName         pointer to char in struct Menu
```c
         +0x000e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *68
```
MenuStrip        pointer to struct Menu in struct Window
```c
         +0x001c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *809
```
MenuVBorder      char in struct Screen +0x0021 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *121
Message          structure tag size 0x0014 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *49
```c
                 [exec/io.h](autodocs-2.0/includes-exec-io-h.md): 21, 30
                 [devices/audio.h](autodocs-2.0/includes-devices-audio-h.md): 55
                 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): 44, 60
                 [devices/printer.h](autodocs-2.0/includes-devices-printer-h.md): 143, 157
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 92, 111, 142
                 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): 92
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): 679
                 [dos/notify.h](autodocs-2.0/includes-dos-notify-h.md): 42
                 [workbench/startup.h](autodocs-2.0/includes-workbench-startup-h.md): 28
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): 44
                 [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): 100
                 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): 127
```
MessageKey       pointer to struct IntuiMessage in struct Window
```c
         +0x005e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *857
```
MethodID         unsigned long int in struct (no tag)
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *32
```
MethodID         unsigned long int in struct opSet
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *79
```
MethodID         unsigned long int in struct opUpdate
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *89
```
MethodID         unsigned long int in struct opGet
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *109
```
MethodID         unsigned long int in struct opAddTail
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *118
```
MethodID         unsigned long int in struct opMember
```c
         +0x0000 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *125
```
MethodID         unsigned long int in struct gpHitTest
```c
         +0x0000 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *177
```
MethodID         unsigned long int in struct gpRender
```c
         +0x0000 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *189
```
MethodID         unsigned long int in struct gpInput
```c
         +0x0000 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *202
```
MethodID         unsigned long int in struct gpGoInactive
```c
         +0x0000 [intuition/gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md): *232
```
MethodID         unsigned long int in struct impFrameBox
```c
         +0x0000 [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *140
```
MethodID         unsigned long int in struct impDraw
```c
         +0x0000 [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *153
```
MethodID         unsigned long int in struct impErase
```c
         +0x0000 [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *173
```
MethodID         unsigned long int in struct impHitTest
```c
         +0x0000 [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *189
```
Micros           unsigned long int in struct IntuiMessage
```c
         +0x0028 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *708
```
Micros           unsigned long int in struct IntuitionBase
```c
         +0x004c [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *87
```
MicrosPerLine    unsigned short int in struct GfxBase
```c
         +0x00e8 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *65
```
MinDisplayColumn unsigned short int in struct GfxBase
```c
         +0x00ea [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *66
```
MinHeight        short int in struct Window +0x0012 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *804
MinHeight        short int in struct NewWindow
```c
         +0x0028 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1025
```
MinHeight        short int in struct ExtNewWindow
```c
         +0x0028 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1060
```
MinList          structure tag size 0x000c [exec/lists.h](autodocs-2.0/includes-exec-lists-h.md): *33
```c
                 [exec/semaphores.h](autodocs-2.0/includes-exec-semaphores-h.md): 44
                 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): 142
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 65, 251
                 [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): 39
```
MinNode          structure tag size 0x0008 [exec/nodes.h](autodocs-2.0/includes-exec-nodes-h.md): *33, 34, 35
```c
                 [exec/lists.h](autodocs-2.0/includes-exec-lists-h.md): 34, 35, 36
                 [exec/semaphores.h](autodocs-2.0/includes-exec-semaphores-h.md): 36
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 265
                 [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md): 25
                 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): 69
                 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): 70, 84
```
MinRasterHeight unsigned short int in struct DimensionInfo
```c
         +0x0014 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *97
```
MinRasterWidth   unsigned short int in struct DimensionInfo
```c
         +0x0012 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *96
```
MinRow           unsigned short int in struct MonitorInfo
```c
         +0x0028 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *118
```
MinWidth         short int in struct Window +0x0010 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *804
MinWidth         short int in struct NewWindow
```c
         +0x0026 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1025
```
MinWidth         short int in struct ExtNewWindow
```c
         +0x0026 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1060
```
MinX             short int in struct Rectangle +0x0000 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *31
MinX             long int in struct Rect32 +0x0000 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *37
MinY             short int in struct Rectangle +0x0002 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *31
MinY             long int in struct Rect32 +0x0004 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *37
Modes            unsigned short int in struct ViewPort
```c
         +0x0020 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *52
```
Modes            unsigned short int in struct View +0x0010 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *65
Modes            unsigned short int in struct GfxBase
```c
         +0x009e [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *39
```
Modes            unsigned long int in struct SGWork
```c
         +0x0010 [intuition/sghooks.h](autodocs-2.0/includes-intuition-sghooks-h.md): *39
```
Monitor          pointer to struct MonitorSpec in struct ViewExtra
```c
         +0x001c [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *74
```
MonitorInfo      structure tag size 0x0058 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *109
MonitorList      struct List(size 0x000e bytes) in struct GfxBase
```c
         +0x0180 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *86
```
MonitorListSemaphore pointer to struct SignalSemaphore in struct GfxBase
```c
         +0x0192 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *88
```
MonitorSpec      structure tag size 0x009c [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *27
```c
                 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): 74
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): 112
                 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): 85, 87
```
MoreFlags        unsigned long int in struct Window
```c
         +0x0084 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *901
```
MountList        struct List(size 0x000e bytes) in struct ExpansionBase
```c
         +0x004a [libraries/expansionbase.h](autodocs-2.0/includes-libraries-expansionbase-h.md): *55
```
MouseX           short int in struct IntuiMessage
```c
         +0x0020 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *703
```
MouseX           short int in struct Window +0x000e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *802
MouseX           short int in struct Screen +0x0012 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *106
MouseX           short int in struct IntuitionBase
```c
         +0x0046 [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *83
```
MouseY           short int in struct IntuiMessage
```c
         +0x0022 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *703
```
MouseY           short int in struct Window +0x000c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *802
MouseY           short int in struct Screen +0x0010 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *106
MouseY           short int in struct IntuitionBase
```c
         +0x0044 [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *83
```
Msg              pointer to "UBYTE"  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *34
MsgPort          structure tag size 0x0022 [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md): *30, 51
```c
                 [exec/devices.h](autodocs-2.0/includes-exec-devices-h.md): 34
                 [exec/semaphores.h](autodocs-2.0/includes-exec-semaphores-h.md): 55
                 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): 56
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 41, 93, 94, 112, 253, 267, 334,
                             364, 411, 447
                 [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md): 126
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): 856
                 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): 67, 92
                 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): 104
                 [dos/notify.h](autodocs-2.0/includes-dos-notify-h.md): 62, 76
                 [workbench/startup.h](autodocs-2.0/includes-workbench-startup-h.md): 29
                 [libraries/commodities.h](autodocs-2.0/includes-libraries-commodities-h.md): 57
                 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): 118, 119
                 [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): 108, 189
                 [rexx/rexxio.h](autodocs-2.0/includes-rexx-rexxio-h.md): 66
                 [rexx/rxslib.h](autodocs-2.0/includes-rexx-rxslib-h.md): 55
```
Mspc             pointer to struct MonitorSpec in struct MonitorInfo
```c
         +0x0010 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *112
```
MutualExclude    long int in struct MenuItem +0x000e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *97
MutualExclude    long int in struct Gadget +0x001e [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *253

