---
title: 2.0 IncludeXREF: O
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-o
functions: []
libraries: []
---

# 2.0 IncludeXREF: O

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

_OBJ             macro (1 argument)   [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *74
_OBJECT          macro (1 argument)   [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *80
_Object          structure tag size 0x000c [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *68
o_Class          pointer to struct IClass in struct _Object
```c
         +0x0008 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *70
```
o_Node           struct MinNode(size 0x0008 bytes) in struct _Object
```c
         +0x0000 [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *69
```
obs              pointer to struct ClipRect in struct Layer_Info
```c
         +0x0008 [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md): *38
```
opAddMember      #define opMember  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *123
opAddTail        structure tag size 0x0008 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *117
opGet            structure tag size 0x000c [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *108
opMember         structure tag size 0x0008 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *124
opSet            structure tag size 0x000c [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *78
opUpdate         structure tag size 0x0010 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *88
opam_Object      pointer to unsigned long int in struct opMember
```c
         +0x0004 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *126
```
opat_List        pointer to struct List in struct opAddTail
```c
         +0x0004 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *119
```
opg_AttrID       unsigned long int in struct opGet
```c
         +0x0004 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *110
```
opg_Storage      pointer to unsigned long int in struct opGet
```c
         +0x0008 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *111
```
ops_AttrList     pointer to struct TagItem in struct opSet
```c
         +0x0004 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *80
```
ops_GInfo        pointer to struct GadgetInfo in struct opSet
```c
         +0x0008 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *81
```
opu_AttrList     pointer to struct TagItem in struct opUpdate
```c
         +0x0004 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *90
```
opu_Flags        unsigned long int in struct opUpdate
```c
         +0x000c [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *95
```
opu_GInfo        pointer to struct GadgetInfo in struct opUpdate
```c
         +0x0008 [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *91
```
OCLASS           macro (1 argument)   [intuition/classes.h](autodocs-2.0/includes-intuition-classes-h.md): *83
OCTANT1          #define 16 = 0x00000010  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *87
OCTANT2          #define 0 = 0x00000000  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *86
OCTANT3          #define 8 = 0x00000008  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *85
OCTANT4          #define 20 = 0x00000014  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *84
OCTANT5          #define 28 = 0x0000001c  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *83
OCTANT6          #define 12 = 0x0000000c  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *82
OCTANT7          #define 4 = 0x00000004  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *81
OCTANT8          #define 24 = 0x00000018  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *80
OFFSET           macro (2 arguments)   [exec/initializers.h](autodocs-2.0/includes-exec-initializers-h.md): *16
OFFSET_BEGINING  #define OFFSET_BEGINNING = 0xffffffff  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *40
OFFSET_BEGINNING #define -1 = 0xffffffff  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *36
OFFSET_CURRENT   #define 0 = 0x00000000  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *37
OFFSET_END       #define 1 = 0x00000001  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *38
OFF_DISPLAY      #define custom.dmacon = BITCLR|DMAF_RASTER;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *24
```
OFF_SPRITE       #define custom.dmacon = BITCLR|DMAF_SPRITE;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *26
```
OFF_VBLANK       #define custom.intena = BITCLR|INTF_VERTB;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *29
```
OKABORT          #define 0x0004 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *774
OKCANCEL         #define MENUCANCEL = 0x00000002  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *775
OKIMATE_20       #define 0x09 = 0x00000009  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *201
OKOK             #define MENUHOT = 0x00000001  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *773
OLDDRAWERDATAFILESIZE #define (sizeof(struct OldDrawerData)) = 0x00000038
```c
                 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *50
```
OM_ADDMEMBER     #define (0x109) = 0x00000109  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *72
OM_ADDTAIL       #define (0x105) = 0x00000105  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *68
OM_DISPOSE       #define (0x102) = 0x00000102  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *65
OM_Dummy         #define (0x100) = 0x00000100  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *63
OM_GET           #define (0x104) = 0x00000104  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *67
OM_NEW           #define (0x101) = 0x00000101  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *64
OM_NOTIFY        #define (0x107) = 0x00000107  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *70
OM_REMMEMBER     #define (0x10A) = 0x0000010a  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *73
OM_REMOVE        #define (0x106) = 0x00000106  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *69
OM_SET           #define (0x103) = 0x00000103  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *66
OM_UPDATE        #define (0x108) = 0x00000108  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *71
ONEDOT           #define 0x2 = 0x00000002  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *71
ONE_DOT          #define 0x02 = 0x00000002  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *101
ON_DISPLAY       #define custom.dmacon = BITSET|DMAF_RASTER;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *23
```
ON_SPRITE        #define custom.dmacon = BITSET|DMAF_SPRITE;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *25
```
ON_VBLANK        #define custom.intena = BITSET|INTF_VERTB;
```c
                 [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *28
```
OPUF_INTERIM     #define (1<<0) = 0x00000001  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *105
ORDERED_DITHERING #define 0x0000 = 0x00000000  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *255
OSCAN_MAX        #define (3) = 0x00000003  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *366
OSCAN_STANDARD   #define (2) = 0x00000002  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *365
OSCAN_TEXT       #define (1) = 0x00000001  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *364
OSCAN_VIDEO      #define (4) = 0x00000004  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *367
OSERR_NOCHIPMEM  #define (4) = 0x00000004  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *300
OSERR_NOCHIPS    #define (2) = 0x00000002  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *298
OSERR_NOMEM      #define (3) = 0x00000003  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *299
OSERR_NOMONITOR  #define (1) = 0x00000001  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *297
OSERR_PUBNOTUNIQUE #define (5) = 0x00000005  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *301
OSERR_UNKNOWNMODE #define (6) = 0x00000006  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *302
OTHER_REFRESH    #define WFLG_OTHER_REFRESH = 0x000000c0
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *155
```
OUTSTEP          #define 0x2000 = 0x00002000  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *43
OVERLAY          #define 0x0004 = 0x00000004  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *24
OVFLAG           #define 0x20 = 0x00000020  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *72
Object           typedef ULONG  [intuition/classusr.h](autodocs-2.0/includes-intuition-classusr-h.md): *21, 126
OldDrawerData    structure tag size 0x0038 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *44
OldX             short int in struct VSprite +0x0012 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *87
OldY             short int in struct VSprite +0x0010 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *87
OlderRequest     pointer to struct Requester in struct Requester
```c
         +0x0000 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *148
```
OpCode           short int in struct CopIns +0x0000 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *28

