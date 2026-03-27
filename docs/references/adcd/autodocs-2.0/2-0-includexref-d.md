---
title: 2.0 IncludeXREF: D
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-d
functions: []
libraries: []
---

# 2.0 IncludeXREF: D

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

da_BootPoint     unsigned short int in struct DiagArea
```c
         +0x0006 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *242
```
da_Config        unsigned char in struct DiagArea
```c
         +0x0000 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *238
```
da_DiagPoint     unsigned short int in struct DiagArea
```c
         +0x0004 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *241
```
da_Flags         unsigned char in struct DiagArea
```c
         +0x0001 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *239
```
da_Name          unsigned short int in struct DiagArea
```c
         +0x0008 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *243
```
da_Reserved01    unsigned short int in struct DiagArea
```c
         +0x000a [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *247
```
da_Reserved02    unsigned short int in struct DiagArea
```c
         +0x000c [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *248
```
da_Size          unsigned short int in struct DiagArea
```c
         +0x0002 [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *240
```
dat_Flags        unsigned char in struct DateTime +0x000d [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *30
dat_Format       unsigned char in struct DateTime +0x000c [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *29
dat_Stamp        struct DateStamp(size 0x000c bytes) in struct DateTime
```c
         +0x0000 [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *28
```
dat_StrDate      pointer to unsigned char in struct DateTime
```c
         +0x0012 [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *32
```
dat_StrDay       pointer to unsigned char in struct DateTime
```c
         +0x000e [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *31
```
dat_StrTime      pointer to unsigned char in struct DateTime
```c
         +0x0016 [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *33
```
dataa            unsigned short int in struct SpriteDef
```c
         +0x0004 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *119
```
datab            unsigned short int in struct SpriteDef
```c
         +0x0006 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *120
```
dbf              function returning "LONG"   [libraries/mathffp.h](autodocs-2.0/includes-libraries-mathffp-h.md): *78
dd_CmdBytes      pointer to void in struct DeviceData
```c
         +0x002e [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *56
```
dd_CmdVectors    pointer to void in struct DeviceData
```c
         +0x002a [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *55
```
dd_CurrentX      long int in struct OldDrawerData
```c
         +0x0030 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *46
```
dd_CurrentX      long int in struct DrawerData
```c
         +0x0030 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *54
```
dd_CurrentY      long int in struct OldDrawerData
```c
         +0x0034 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *47
```
dd_CurrentY      long int in struct DrawerData
```c
         +0x0034 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *55
```
dd_Device        struct Library(size 0x0022 bytes) in struct DeviceData
```c
         +0x0000 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *52
```
dd_ExecBase      pointer to void in struct DeviceData
```c
         +0x0026 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *54
```
dd_Flags         unsigned long int in struct DrawerData
```c
         +0x0038 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *56
```
dd_Library       struct Library(size 0x0022 bytes) in struct Device
```c
         +0x0000 [exec/devices.h](autodocs-2.0/includes-exec-devices-h.md): *27
```
dd_NewWindow     struct NewWindow(size 0x0030 bytes) in struct OldDrawerData
```c
         +0x0000 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *45
```
dd_NewWindow     struct NewWindow(size 0x0030 bytes) in struct DrawerData
```c
         +0x0000 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *53
```
dd_NumCommands   unsigned short int in struct DeviceData
```c
         +0x0032 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *57
```
dd_Segment       pointer to void in struct DeviceData
```c
         +0x0022 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *53
```
dd_ViewModes     unsigned short int in struct DrawerData
```c
         +0x003c [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *57
```
ddfstop          unsigned short int in struct Custom
```c
         +0x0094 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *91
```
ddfstrt          unsigned short int in struct Custom
```c
         +0x0092 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *90
```
de_Baud          unsigned long int in struct DosEnvec
```c
         +0x0044 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *49
```
de_BlocksPerTrack unsigned long int in struct DosEnvec
```c
         +0x0014 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *35
```
de_BootBlocks    unsigned long int in struct DosEnvec
```c
         +0x004c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *51
```
de_BootPri       long int in struct DosEnvec +0x003c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *45
de_BufMemType    unsigned long int in struct DosEnvec
```c
         +0x0030 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *42
```
de_Control       unsigned long int in struct DosEnvec
```c
         +0x0048 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *50
```
de_DosType       unsigned long int in struct DosEnvec
```c
         +0x0040 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *46
```
de_HighCyl       unsigned long int in struct DosEnvec
```c
         +0x0028 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *40
```
de_Interleave    unsigned long int in struct DosEnvec
```c
         +0x0020 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *38
```
de_LowCyl        unsigned long int in struct DosEnvec
```c
         +0x0024 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *39
```
de_Mask          unsigned long int in struct DosEnvec
```c
         +0x0038 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *44
```
de_MaxTransfer   unsigned long int in struct DosEnvec
```c
         +0x0034 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *43
```
de_NumBuffers    unsigned long int in struct DosEnvec
```c
         +0x002c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *41
```
de_PreAlloc      unsigned long int in struct DosEnvec
```c
         +0x001c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *37
```
de_Reserved      unsigned long int in struct DosEnvec
```c
         +0x0018 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *36
```
de_SecOrg        unsigned long int in struct DosEnvec
```c
         +0x0008 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *32
```
de_SectorPerBlock unsigned long int in struct DosEnvec
```c
         +0x0010 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *34
```
de_SizeBlock     unsigned long int in struct DosEnvec
```c
         +0x0004 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *31
```
de_Surfaces      unsigned long int in struct DosEnvec
```c
         +0x000c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *33
```
de_TableSize     unsigned long int in struct DosEnvec
```c
         +0x0000 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *30
```
default_monitor pointer to struct MonitorSpec in struct GfxBase
```c
         +0x018e [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *87
```
deniseid         unsigned short int in struct Custom
```c
         +0x007c [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *81
```
detailPen        #define DETAILPEN = 0x00000000  [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *261
dfh_DF           struct Node(size 0x000e bytes) in struct DiskFontHeader
```c
         +0x0000 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *72
```
dfh_FileID       unsigned short int in struct DiskFontHeader
```c
         +0x000e [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *73
```
dfh_Name         array [32] of char in struct DiskFontHeader
```c
         +0x0016 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *76
```
dfh_Revision     unsigned short int in struct DiskFontHeader
```c
         +0x0010 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *74
```
dfh_Segment      long int in struct DiskFontHeader
```c
         +0x0012 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *75
```
dfh_TF           struct TextFont(size 0x0034 bytes) in struct DiskFontHeader
```c
         +0x0036 [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *77
```
dfh_TagList      #define dfh_Segment  [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *82
dg_BufMemType    unsigned long int in struct DriveGeometry
```c
         +0x0018 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *144
```
dg_CylSectors    unsigned long int in struct DriveGeometry
```c
         +0x000c [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *141
```
dg_Cylinders     unsigned long int in struct DriveGeometry
```c
         +0x0008 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *140
```
dg_DeviceType    unsigned char in struct DriveGeometry
```c
         +0x001c [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *146
```
dg_Flags         unsigned char in struct DriveGeometry
```c
         +0x001d [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *147
```
dg_Heads         unsigned long int in struct DriveGeometry
```c
         +0x0010 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *142
```
dg_Reserved      unsigned short int in struct DriveGeometry
```c
         +0x001e [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *148
```
dg_SectorSize    unsigned long int in struct DriveGeometry
```c
         +0x0000 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *138
```
dg_TotalSectors unsigned long int in struct DriveGeometry
```c
         +0x0004 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *139
```
dg_TrackSectors unsigned long int in struct DriveGeometry
```c
         +0x0014 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *143
```
di_DevInfo       long int in struct DosInfo +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *277
di_DevLock       struct SignalSemaphore(size 0x002e bytes) in struct DosInfo
```c
         +0x0014 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *281
```
di_Devices       long int in struct DosInfo +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *278
di_EntryLock     struct SignalSemaphore(size 0x002e bytes) in struct DosInfo
```c
         +0x0042 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *282
```
di_Handlers      long int in struct DosInfo +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *279
di_McName        long int in struct DosInfo +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *275
di_NetHand       pointer to void in struct DosInfo
```c
         +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *280
```
di_ResList       #define di_McName  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *276
diagstrt         array [4] of unsigned short int in struct copinit
```c
         +0x000c [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *96
```
diwhigh          unsigned short int in struct Custom
```c
         +0x01e4 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *141
```
diwstart         array [4] of unsigned short int in struct copinit
```c
         +0x0004 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *95
```
diwstop          unsigned short int in struct Custom
```c
         +0x0090 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *89
```
diwstrt          unsigned short int in struct Custom
```c
         +0x008e [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *88
```
dl_A2            long int in struct DosLibrary +0x002a [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *232
dl_A5            long int in struct DosLibrary +0x002e [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *233
dl_A6            long int in struct DosLibrary +0x0032 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *234
dl_DiskType      long int in struct DeviceList +0x0020 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *338
dl_Errors        pointer to struct ErrorString in struct DosLibrary
```c
         +0x0036 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *235
```
dl_GV            pointer to void in struct DosLibrary
```c
         +0x0026 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *231
```
dl_Lock          long int in struct DeviceList +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *335
dl_LockList      long int in struct DeviceList +0x001c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *337
dl_Name          long int in struct DeviceList +0x0028 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *340
dl_Next          long int in struct DeviceList +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *332
dl_Root          pointer to struct RootNode in struct DosLibrary
```c
         +0x0022 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *230
```
dl_Task          pointer to struct MsgPort in struct DeviceList
```c
         +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *334
```
dl_TimeReq       pointer to struct timerequest in struct DosLibrary
```c
         +0x003a [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *236
```
dl_Type          long int in struct DeviceList +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *333
dl_UtilityBase   pointer to struct Library in struct DosLibrary
```c
         +0x003e [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *237
```
dl_VolumeDate    struct DateStamp(size 0x000c bytes) in struct DeviceList
```c
         +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *336
```
dl_lib           struct Library(size 0x0022 bytes) in struct DosLibrary
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *229
```
dl_unused        long int in struct DeviceList +0x0024 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *339
dmacon           unsigned short int in struct Custom
```c
         +0x0096 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *92
```
dmaconr          unsigned short int in struct Custom
```c
         +0x0002 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *29
```
dn_GlobalVec     long int in struct DeviceNode +0x0024 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *114
dn_Handler       long int in struct DeviceNode +0x0010 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *108
dn_Lock          long int in struct DeviceNode +0x000c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *107
dn_Name          long int in struct DeviceNode +0x0028 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *122
dn_Next          long int in struct DeviceNode +0x0000 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *102
dn_Priority      long int in struct DeviceNode +0x0018 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *110
dn_SegList       long int in struct DeviceNode +0x0020 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *112
dn_StackSize     unsigned long int in struct DeviceNode
```c
         +0x0014 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *109
```
dn_Startup       long int in struct DeviceNode +0x001c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *111
dn_Task          pointer to struct MsgPort in struct DeviceNode
```c
         +0x0008 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *104
```
dn_Type          unsigned long int in struct DeviceNode
```c
         +0x0004 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *103
```
do_CurrentX      long int in struct DiskObject
```c
         +0x003a [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *69
```
do_CurrentY      long int in struct DiskObject
```c
         +0x003e [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *70
```
do_DefaultTool   pointer to char in struct DiskObject
```c
         +0x0032 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *67
```
do_DrawerData    pointer to struct DrawerData in struct DiskObject
```c
         +0x0042 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *71
```
do_Gadget        struct Gadget(size 0x002c bytes) in struct DiskObject
```c
         +0x0004 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *65
```
do_Magic         unsigned short int in struct DiskObject
```c
         +0x0000 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *63
```
do_StackSize     long int in struct DiskObject
```c
         +0x004a [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *73
```
do_ToolTypes     pointer to pointer to char in struct DiskObject
```c
         +0x0036 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *68
```
do_ToolWindow    pointer to char in struct DiskObject
```c
         +0x0046 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *72
```
do_Type          unsigned char in struct DiskObject
```c
         +0x0030 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *66
```
do_Version       unsigned short int in struct DiskObject
```c
         +0x0002 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *64
```
do_monitor       pointer to function returning int in struct SpecialMonitor
```c
         +0x001a [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *146
```
dol_AssignName   pointer to unsigned char in struct (no tag)
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *385
```
dol_DiskType     long int in struct (no tag)  +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *381
dol_GlobVec      long int in struct (no tag)  +0x0014 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *373
dol_Handler      long int in struct (no tag)  +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *368
dol_List         pointer to struct AssignList in struct (no tag)
```c
         +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *386
```
dol_Lock         long int in struct DosList +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *365
dol_LockList     long int in struct (no tag)  +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *380
dol_Name         long int in struct DosList +0x0028 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *391
dol_Next         long int in struct DosList +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *362
dol_Priority     long int in struct (no tag)  +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *370
dol_SegList      long int in struct (no tag)  +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *372
dol_StackSize    long int in struct (no tag)  +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *369
dol_Startup      unsigned long int in struct (no tag)
```c
         +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *371
```
dol_Task         pointer to struct MsgPort in struct DosList
```c
         +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *364
```
dol_Type         long int in struct DosList +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *363
dol_VolumeDate   struct DateStamp(size 0x000c bytes) in struct (no tag)
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *379
```
dol_assign       struct (no tag) (size 0x0008 bytes) in union (no tag)
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *387
```
dol_handler      struct (no tag) (size 0x0018 bytes) in union (no tag)
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *376
```
dol_misc         union (no tag) (size 0x0018 bytes) in struct DosList
```c
         +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *389
```
dol_volume       struct (no tag) (size 0x0014 bytes) in union (no tag)
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *382
```
dp_Action        #define dp_Type  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *124
dp_Arg1          long int in struct DosPacket +0x0014 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *128
dp_Arg2          long int in struct DosPacket +0x0018 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *129
dp_Arg3          long int in struct DosPacket +0x001c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *130
dp_Arg4          long int in struct DosPacket +0x0020 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *131
dp_Arg5          long int in struct DosPacket +0x0024 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *132
dp_Arg6          long int in struct DosPacket +0x0028 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *133
dp_Arg7          long int in struct DosPacket +0x002c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *134
dp_BufAddr       #define dp_Arg1  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *127
dp_Link          pointer to struct Message in struct DosPacket
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *111
```
dp_Port          pointer to struct MsgPort in struct DosPacket
```c
         +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *112
```
dp_Res1          long int in struct DosPacket +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *117
dp_Res2          long int in struct DosPacket +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *121
dp_Status        #define dp_Res1  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *125
dp_Status2       #define dp_Res2  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *126
dp_Type          long int in struct DosPacket +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *114
dr_CiaResource   pointer to struct Library in struct DiscResource
```c
         +0x002c [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *56
```
dr_CurrTask      pointer to struct Task in struct DiscResource
```c
         +0x0090 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *62
```
dr_Current       pointer to struct DiscResourceUnit in struct DiscResource
```c
         +0x0022 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *52
```
dr_DiscBlock     struct Interrupt(size 0x0016 bytes) in struct DiscResource
```c
         +0x004e [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *59
```
dr_DiscSync      struct Interrupt(size 0x0016 bytes) in struct DiscResource
```c
         +0x0064 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *60
```
dr_Flags         unsigned char in struct DiscResource
```c
         +0x0026 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *53
```
dr_Index         struct Interrupt(size 0x0016 bytes) in struct DiscResource
```c
         +0x007a [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *61
```
dr_Library       struct Library(size 0x0022 bytes) in struct DiscResource
```c
         +0x0000 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *51
```
dr_SysLib        pointer to struct Library in struct DiscResource
```c
         +0x0028 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *55
```
dr_UnitID        array [4] of unsigned long int in struct DiscResource
```c
         +0x0030 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *57
```
dr_Waiting       struct List(size 0x000e bytes) in struct DiscResource
```c
         +0x0040 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *58
```
dr_pad           unsigned char in struct DiscResource
```c
         +0x0027 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *54
```
dri_Depth        unsigned short int in struct DrawInfo
```c
         +0x000c [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *68
```
dri_Flags        unsigned long int in struct DrawInfo
```c
         +0x0012 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *75
```
dri_Font         pointer to struct TextFont in struct DrawInfo
```c
         +0x0008 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *67
```
dri_NumPens      unsigned short int in struct DrawInfo
```c
         +0x0002 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *64
```
dri_Pens         pointer to unsigned short int in struct DrawInfo
```c
         +0x0004 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *65
```
dri_Reserved     array [7] of unsigned long int in struct DrawInfo
```c
         +0x0016 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *76
```
dri_Resolution   struct (no tag) (size 0x0004 bytes) in struct DrawInfo
```c
         +0x000e [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *73
```
dri_Version      unsigned short int in struct DrawInfo
```c
         +0x0000 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *63
```
dru_DiscBlock    struct Interrupt(size 0x0016 bytes) in struct
```c
                 DiscResourceUnit
         +0x0014 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *45
```
dru_DiscSync     struct Interrupt(size 0x0016 bytes) in struct
```c
                 DiscResourceUnit
         +0x002a [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *46
```
dru_Index        struct Interrupt(size 0x0016 bytes) in struct
```c
                 DiscResourceUnit
         +0x0040 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *47
```
dru_Message      struct Message(size 0x0014 bytes) in struct DiscResourceUnit
```c
         +0x0000 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *44
```
ds_Days          long int in struct DateStamp +0x0000 [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *55
ds_Minute        long int in struct DateStamp +0x0004 [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *56
ds_Tick          long int in struct DateStamp +0x0008 [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *57
dskbytr          unsigned short int in struct Custom
```c
         +0x001a [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *41
```
dskdat           unsigned short int in struct Custom
```c
         +0x0026 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *46
```
dskdatr          unsigned short int in struct Custom
```c
         +0x0008 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *32
```
dsklen           unsigned short int in struct Custom
```c
         +0x0024 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *45
```
dskpt            pointer to void in struct Custom
```c
         +0x0020 [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *44
```
dsksync          unsigned short int in struct Custom
```c
         +0x007e [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *82
```
dummy            char in struct RastPort +0x001f [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *71
dvi_GlobVec      long int in struct DevInfo +0x0024 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *355
dvi_Handler      long int in struct DevInfo +0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *350
dvi_Lock         long int in struct DevInfo +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *349
dvi_Name         long int in struct DevInfo +0x0028 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *356
dvi_Next         long int in struct DevInfo +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *346
dvi_Priority     long int in struct DevInfo +0x0018 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *352
dvi_SegList      long int in struct DevInfo +0x0020 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *354
dvi_StackSize    long int in struct DevInfo +0x0014 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *351
dvi_Startup      long int in struct DevInfo +0x001c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *353
dvi_Task         pointer to void in struct DevInfo
```c
         +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *348
```
dvi_Type         long int in struct DevInfo +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *347
dvp_DevNode      pointer to struct DosList in struct DevProc
```c
         +0x000c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *414
```
dvp_Flags        unsigned long int in struct DevProc
```c
         +0x0008 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *413
```
dvp_Lock         long int in struct DevProc +0x0004 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *412
dvp_Port         pointer to struct MsgPort in struct DevProc
```c
         +0x0000 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *411
```
DAC_BINDTIME     #define 0x20 = 0x00000020  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *264
DAC_BOOTTIME     #define 0x30 = 0x00000030  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *260
DAC_BUSWIDTH     #define 0xC0 = 0x000000c0  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *255
DAC_BYTEWIDE     #define 0x40 = 0x00000040  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *257
DAC_CONFIGTIME   #define 0x10 = 0x00000010  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *262
DAC_NEVER        #define 0x00 = 0x00000000  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *261
DAC_NIBBLEWIDE   #define 0x00 = 0x00000000  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *256
DAC_WORDWIDE     #define 0x80 = 0x00000080  [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *258
DBLPF            #define 0x400 = 0x00000400  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *22
DBUFFER          #define 0x04 = 0x00000004  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *103
DBufPacket       structure tag size 0x000c [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *160, 230
DBuffer          pointer to struct DBufPacket in struct Bob
```c
         +0x001a [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *160
```
DDB_AllBit       #define 3 = 0x00000003  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *113
DDB_Completed    #define 2 = 0x00000002  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *111
DDB_ExaminedBit  #define 1 = 0x00000001  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *109
DDB_PatternBit   #define 0 = 0x00000000  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *107
DDB_Single       #define 4 = 0x00000004  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *115
DDF_AllBit       #define 8 = 0x00000008  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *114
DDF_Completed    #define 4 = 0x00000004  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *112
DDF_ExaminedBit  #define 2 = 0x00000002  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *110
DDF_PatternBit   #define 1 = 0x00000001  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *108
DDF_Single       #define 16 = 0x00000010  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *116
DEADEND_ALERT    #define 0x80000000 = 0x80000000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1312
DEFARTIC         #define 100 = 0x00000064  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *70
DEFAULTMOUSEQUEUE #define (5) = 0x00000005  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *960
DEFAULT_MONITOR_ID #define 0x00000000 = 0x00000000
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *147
```
DEFAULT_MONITOR_NAME #define "default.monitor"  [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *65
DEFCENTRAL       #define 0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *71
DEFERREFRESH     #define 0x8000 = 0x00008000  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *206
DEFF0ENTHUS      #define 32 = 0x00000020  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *73
DEFF0PERT        #define 0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *72
DEFFREQ          #define 22200 = 0x000056b8  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *62
DEFMODE          #define NATURALF0 = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *69
DEFPITCH         #define 110 = 0x0000006e  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *59
DEFPRIORITY      #define 100 = 0x00000064  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *74
DEFRATE          #define 150 = 0x00000096  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *60
DEFSEX           #define MALE = 0x00000000  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *68
DEFVOL           #define 64 = 0x00000040  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *61
DELTAMOVE        #define IDCMP_DELTAMOVE = 0x00100000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *134
```
DEPTHIMAGE       #define (0x00L) = 0x00000000  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *101
DEST             #define 0x100 = 0x00000100  [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md): *58
DESTADDR         #define u3.u4.u1.DestAddr  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *50
DESTDATA         #define u3.u4.u2.DestData  [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *52
DETAILPEN        #define (0x0000) = 0x00000000  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *82
DEVICES_AUDIO_H  #define  [devices/audio.h](autodocs-2.0/includes-devices-audio-h.md): *2
DEVICES_BOOTBLOCK_H #define  [devices/bootblock.h](autodocs-2.0/includes-devices-bootblock-h.md): *2
DEVICES_CIA_H    #define 1 = 0x00000001  [resources/cia.h](autodocs-2.0/includes-resources-cia-h.md): *2
DEVICES_CLIPBOARD_H #define  [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): *2
```c
                 [libraries/iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md): 25
```
DEVICES_CONSOLE_H #define  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *2
```c
                 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): 23
```
DEVICES_CONUNIT_H #define  [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): *2
DEVICES_GAMEPORT_H #define  [devices/gameport.h](autodocs-2.0/includes-devices-gameport-h.md): *2
DEVICES_HARDBLOCKS_H #define  [devices/hardblocks.h](autodocs-2.0/includes-devices-hardblocks-h.md): *2
DEVICES_INPUTEVENT_H #define  [devices/inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md): *2, 1
```c
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): 47
```
DEVICES_INPUT_H  #define  [devices/input.h](autodocs-2.0/includes-devices-input-h.md): *2
DEVICES_KEYBOARD_H #define  [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *2
DEVICES_KEYMAP_H #define  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *2, 1
DEVICES_NARRATOR_H #define  [devices/narrator.h](autodocs-2.0/includes-devices-narrator-h.md): *2
DEVICES_PARALLEL_H #define  [devices/parallel.h](autodocs-2.0/includes-devices-parallel-h.md): *2
```c
                 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): 34
```
DEVICES_PRINTER_H #define  [devices/printer.h](autodocs-2.0/includes-devices-printer-h.md): *2
DEVICES_PRTBASE_H #define  [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *2
DEVICES_PRTGFX_H #define  [devices/prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md): *2
DEVICES_SCSIDISK_H #define  [devices/scsidisk.h](autodocs-2.0/includes-devices-scsidisk-h.md): *2
DEVICES_SERIAL_H #define  [devices/serial.h](autodocs-2.0/includes-devices-serial-h.md): *2, 1
DEVICES_TIMER_H  #define 1 = 0x00000001  [devices/timer.h](autodocs-2.0/includes-devices-timer-h.md): *2, 1
```c
                 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): 40
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 27
                 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): 19
```
DEVICES_TRACKDISK_H #define  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *2
DEV_ABORTIO      #define (-36) = 0xffffffdc  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *44
DEV_BEGINIO      #define (-30) = 0xffffffe2  [exec/io.h](autodocs-2.0/includes-exec-io-h.md): *43
DE_BAUD          #define 17 = 0x00000011  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *78
DE_BLKSPERTRACK  #define 5 = 0x00000005  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *62
DE_BOOTBLOCKS    #define 19 = 0x00000013  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *80
DE_BOOTPRI       #define 15 = 0x0000000f  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *74
DE_BUFMEMTYPE    #define 12 = 0x0000000c  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *71
DE_CONTROL       #define 18 = 0x00000012  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *79
DE_DOSTYPE       #define 16 = 0x00000010  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *77
DE_INTERLEAVE    #define 8 = 0x00000008  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *65
DE_LOWCYL        #define 9 = 0x00000009  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *66
DE_MASK          #define 14 = 0x0000000e  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *73
DE_MAXTRANSFER   #define 13 = 0x0000000d  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *72
DE_MEMBUFTYPE    #define 12 = 0x0000000c  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *69
DE_NUMBUFFERS    #define 11 = 0x0000000b  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *68
DE_NUMHEADS      #define 3 = 0x00000003  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *60
DE_PREFAC        #define 7 = 0x00000007  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *64
DE_RESERVEDBLKS  #define 6 = 0x00000006  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *63
DE_SECORG        #define 2 = 0x00000002  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *59
DE_SECSPERBLK    #define 4 = 0x00000004  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *61
DE_SIZEBLOCK     #define 1 = 0x00000001  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *58
DE_TABLESIZE     #define 0 = 0x00000000  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *57
DE_UPPERCYL      #define 10 = 0x0000000a  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *67
DFH_ID           #define 0x0f80 = 0x00000f80  [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *61
DFTCH_MASK       #define 0xFF = 0x000000ff  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *37
DGB_REMOVABLE    #define 0 = 0x00000000  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *165
DGF_REMOVABLE    #define 1 = 0x00000001  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *166
DG_CDROM         #define 5 = 0x00000005  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *157
DG_COMMUNICATION #define 9 = 0x00000009  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *161
DG_DIRECT_ACCESS #define 0 = 0x00000000  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *152
DG_MEDIUM_CHANGER #define 8 = 0x00000008  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *160
DG_OPTICAL_DISK  #define 7 = 0x00000007  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *159
DG_PRINTER       #define 2 = 0x00000002  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *154
DG_PROCESSOR     #define 3 = 0x00000003  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *155
DG_SCANNER       #define 6 = 0x00000006  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *158
DG_SEQUENTIAL_ACCESS #define 1 = 0x00000001  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *153
DG_UNKNOWN       #define 31 = 0x0000001f  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *162
DG_WORM          #define 4 = 0x00000004  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *156
DHeight          short int in struct ViewPort +0x001a [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *50
DIAB_630         #define 0x04 = 0x00000004  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *196
DIAB_ADV_D25     #define 0x05 = 0x00000005  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *197
DIAB_C_150       #define 0x06 = 0x00000006  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *198
DIMENSIONS_MASK  #define (BOUNDED_DIMENSIONS|ABSOLUTE_DIMENSIONS|
```c
                         PIXEL_DIMENSIONS|MULTIPLY_DIMENSIONS) = 0x000000f0
                 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *265
```
DIPF_IS_BEAMSYNC #define 0x00000800 = 0x00000800  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *88
DIPF_IS_DRAGGABLE #define 0x00000200 = 0x00000200  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *86
DIPF_IS_DUALPF   #define 0x00000002 = 0x00000002  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *73
DIPF_IS_ECS      #define 0x00000010 = 0x00000010  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *80
DIPF_IS_EXTRAHALFBRITE #define 0x00001000 = 0x00001000
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *90
```
DIPF_IS_GENLOCK  #define 0x00000080 = 0x00000080  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *83
DIPF_IS_HAM      #define 0x00000008 = 0x00000008  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *75
DIPF_IS_LACE     #define 0x00000001 = 0x00000001  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *72
DIPF_IS_PAL      #define 0x00000020 = 0x00000020  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *81
DIPF_IS_PANELLED #define 0x00000400 = 0x00000400  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *87
DIPF_IS_PF2PRI   #define 0x00000004 = 0x00000004  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *74
DIPF_IS_SPRITES  #define 0x00000040 = 0x00000040  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *82
DIPF_IS_WB       #define 0x00000100 = 0x00000100  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *85
DISKINSERTED     #define IDCMP_DISKINSERTED = 0x00008000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *129
```
DISKNAME         #define "disk.resource"  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *102
DISKREMOVED      #define IDCMP_DISKREMOVED = 0x00010000
```c
                 [intuition/iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md): *130
```
DISPLAYDUAL      #define 0x0040 = 0x00000040  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *153
DISPLAYNAMELEN   #define 32 = 0x00000020  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *130, 135
DISPLAYPAL       #define 0x0020 = 0x00000020  [hardware/custom.h](autodocs-2.0/includes-hardware-custom-h.md): *154
DITHERING_MASK   #define (HALFTONE_DITHERING|FLOYD_DITHERING) = 0x00000600
```c
                 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *266
```
DIW_HORIZ_POS    #define 0x7F = 0x0000007f  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *32
DIW_VRTCL_POS    #define 0x1FF = 0x000001ff  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *33
DIW_VRTCL_POS_SHIFT #define 7 = 0x00000007  [graphics/display.h](autodocs-2.0/includes-graphics-display-h.md): *34
DI_AVAIL_NOCHIPS #define 0x0001 = 0x00000001  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *66
DI_AVAIL_NOMONITOR #define 0x0002 = 0x00000002  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *67
DI_AVAIL_NOTWITHGENLOCK #define 0x0004 = 0x00000004
```c
                 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *68
```
DLT_DEVICE       #define 0 = 0x00000000  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *402
DLT_DIRECTORY    #define 1 = 0x00000001  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *403
DLT_LATE         #define 3 = 0x00000003  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *405
DLT_NONBINDING   #define 4 = 0x00000004  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *406
DLT_PRIVATE      #define -1 = 0xffffffff  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *407
DLT_VOLUME       #define 2 = 0x00000002  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *404
DMAB_AUD0        #define 0 = 0x00000000  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *37
DMAB_AUD1        #define 1 = 0x00000001  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *38
DMAB_AUD2        #define 2 = 0x00000002  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *39
DMAB_AUD3        #define 3 = 0x00000003  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *40
DMAB_BLITHOG     #define 10 = 0x0000000a  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *47
DMAB_BLITTER     #define 6 = 0x00000006  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *43
DMAB_BLTDONE     #define 14 = 0x0000000e  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *48
DMAB_BLTNZERO    #define 13 = 0x0000000d  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *49
DMAB_COPPER      #define 7 = 0x00000007  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *44
DMAB_DISK        #define 4 = 0x00000004  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *41
DMAB_MASTER      #define 9 = 0x00000009  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *46
DMAB_RASTER      #define 8 = 0x00000008  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *45
DMAB_SETCLR      #define 15 = 0x0000000f  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *36
DMAB_SPRITE      #define 5 = 0x00000005  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *42
DMAF_ALL         #define 0x01FF = 0x000001ff  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *29
DMAF_AUD0        #define 0x0001 = 0x00000001  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *18
DMAF_AUD1        #define 0x0002 = 0x00000002  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *19
DMAF_AUD2        #define 0x0004 = 0x00000004  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *20
DMAF_AUD3        #define 0x0008 = 0x00000008  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *21
DMAF_AUDIO       #define 0x000F = 0x0000000f  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *17
DMAF_BLITHOG     #define 0x0400 = 0x00000400  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *28
DMAF_BLITTER     #define 0x0040 = 0x00000040  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *24
DMAF_BLTDONE     #define 0x4000 = 0x00004000  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *33
DMAF_BLTNZERO    #define 0x2000 = 0x00002000  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *34
DMAF_COPPER      #define 0x0080 = 0x00000080  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *25
DMAF_DISK        #define 0x0010 = 0x00000010  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *22
DMAF_MASTER      #define 0x0200 = 0x00000200  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *27
DMAF_RASTER      #define 0x0100 = 0x00000100  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *26
DMAF_SETCLR      #define 0x8000 = 0x00008000  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *16
DMAF_SPRITE      #define 0x0020 = 0x00000020  [hardware/dmabits.h](autodocs-2.0/includes-hardware-dmabits-h.md): *23
DMODECOUNT       #define 0x0002 = 0x00000002  [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *35
DMRequest        pointer to struct Requester in struct Window
```c
         +0x0028 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *815
```
DOSFALSE         #define (0L) = 0x00000000  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *25
DOSNAME          #define "dos.library"  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *20
DOSTRUE          #define (-1L) = 0xffffffff  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *24
DOS_CLI          #define 4 = 0x00000004  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *241
DOS_DATETIME_H   #define  [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *2
DOS_DOSASL_H     #define  [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): *2
DOS_DOSEXTENS_H  #define  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *2, 1
DOS_DOSHUNKS_H   #define  [dos/doshunks.h](autodocs-2.0/includes-dos-doshunks-h.md): *2
DOS_DOSTAGS_H    #define  [dos/dostags.h](autodocs-2.0/includes-dos-dostags-h.md): *2
DOS_DOS_H        #define  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *2, 1
```c
                 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): 19
                 [dos/record.h](autodocs-2.0/includes-dos-record-h.md): 17
                 [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): 17
                 [dos/dosasl.h](autodocs-2.0/includes-dos-dosasl-h.md): 25
                 [libraries/dos.h](autodocs-2.0/includes-libraries-dos-h.md): 15
                 [resources/filesysres.h](autodocs-2.0/includes-resources-filesysres-h.md): 21
```
DOS_EXALLCONTROL #define 1 = 0x00000001  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *238
DOS_EXALL_H      #define  [dos/exall.h](autodocs-2.0/includes-dos-exall-h.md): *2
DOS_FIB          #define 2 = 0x00000002  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *239
DOS_FILEHANDLE   #define 0 = 0x00000000  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *237
DOS_FILEHANDLER_H #define  [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *2
```c
                 [libraries/filehandler.h](autodocs-2.0/includes-libraries-filehandler-h.md): 15
```
DOS_NOTIFY_H     #define  [dos/notify.h](autodocs-2.0/includes-dos-notify-h.md): *2
DOS_RDARGS       #define 5 = 0x00000005  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *242
DOS_RDARGS_H     #define  [dos/rdargs.h](autodocs-2.0/includes-dos-rdargs-h.md): *2
DOS_RECORD_H     #define  [dos/record.h](autodocs-2.0/includes-dos-record-h.md): *2
DOS_STDIO_H      #define  [dos/stdio.h](autodocs-2.0/includes-dos-stdio-h.md): *2
DOS_STDPKT       #define 3 = 0x00000003  [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *240
DOS_VAR_H        #define  [dos/var.h](autodocs-2.0/includes-dos-var-h.md): *2
DOUBLE           typedef double  [exec/types.h](autodocs-2.0/includes-exec-types-h.md): *65
DOWNBACKGADGET   #define 1 = 0x00000001  [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *48
DOWNIMAGE        #define (0x0DL) = 0x0000000d  [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): *109
DPB_DEAD         #define 3 = 0x00000003  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *70
DPB_MOD          #define 0 = 0x00000000  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *68
DPF_DEAD         #define 0x08 = 0x00000008  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *71
DPF_MOD          #define 0x01 = 0x00000001  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *69
DP_2DFACSHIFT    #define 4 = 0x00000004  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *74
DP_2DINDEXMASK   #define 0x0f = 0x0000000f  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *73
DRAFT            #define 0x000 = 0x00000000  [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *164
DRAGGADGET       #define 4 = 0x00000004  [intuition/intuitionbase.h](autodocs-2.0/includes-intuition-intuitionbase-h.md): *51
DRAWERDATAFILESIZE #define (sizeof(struct DrawerData)) = 0x0000003e
```c
                 [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *60
```
DRB_ACTIVE       #define 7 = 0x00000007  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *70
DRB_ALLOC0       #define 0 = 0x00000000  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *66
DRB_ALLOC1       #define 1 = 0x00000001  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *67
DRB_ALLOC2       #define 2 = 0x00000002  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *68
DRB_ALLOC3       #define 3 = 0x00000003  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *69
DRF_ACTIVE       #define (1<<7) = 0x00000080  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *76
DRF_ALLOC0       #define (1<<0) = 0x00000001  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *72
DRF_ALLOC1       #define (1<<1) = 0x00000002  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *73
DRF_ALLOC2       #define (1<<2) = 0x00000004  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *74
DRF_ALLOC3       #define (1<<3) = 0x00000008  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *75
DRIF_NEWLOOK     #define 0x00000001 = 0x00000001  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *79
DRIVE3_5         #define 1 = 0x00000001  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *203
DRIVE3_5_150RPM  #define 3 = 0x00000003  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *205
DRIVE5_25        #define 2 = 0x00000002  [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *204
DRI_VERSION      #define (1) = 0x00000001  [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *59
DRT_150RPM       #define (0xAAAAAAAA) = 0xaaaaaaaa  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *123
DRT_37422D2S     #define (0x55555555) = 0x55555555  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *121
DRT_AMIGA        #define (0x00000000) = 0x00000000  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *120
DRT_EMPTY        #define (0xFFFFFFFF) = 0xffffffff  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *122
DR_ALLOCUNIT     #define (LIB_BASE - 0*LIB_VECTSIZE) = 0xfffffffa
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *105
```
DR_FREEUNIT      #define (LIB_BASE - 1*LIB_VECTSIZE) = 0xfffffff4
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *106
```
DR_GETUNIT       #define (LIB_BASE - 2*LIB_VECTSIZE) = 0xffffffee
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *107
```
DR_GETUNITID     #define (LIB_BASE - 4*LIB_VECTSIZE) = 0xffffffe2
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *109
```
DR_GIVEUNIT      #define (LIB_BASE - 3*LIB_VECTSIZE) = 0xffffffe8
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *108
```
DR_LASTCOMM      #define (DR_READUNITID) = 0xffffffdc  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *112
DR_READUNITID    #define (LIB_BASE - 5*LIB_VECTSIZE) = 0xffffffdc
```c
                 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *110
```
DSKDMAOFF        #define 0x4000 = 0x00004000  [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *87
DSR_CPR          #define 6 = 0x00000006  [devices/console.h](autodocs-2.0/includes-devices-console-h.md): *86
DTAG_DIMS        #define 0x80001000 = 0x80001000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *38
DTAG_DISP        #define 0x80000000 = 0x80000000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *37
DTAG_MNTR        #define 0x80002000 = 0x80002000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *39
DTAG_NAME        #define 0x80003000 = 0x80003000  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *40
DTB_FUTURE       #define 1 = 0x00000001  [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *43
DTB_SUBST        #define 0 = 0x00000000  [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *41
DTF_FUTURE       #define 2 = 0x00000002  [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *44
DTF_SUBST        #define 1 = 0x00000001  [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *42
DT_DEV           #define 0L = 0x00000000  [rexx/rexxio.h](autodocs-2.0/includes-rexx-rexxio-h.md): *73
DT_DIR           #define 1L = 0x00000001  [rexx/rexxio.h](autodocs-2.0/includes-rexx-rexxio-h.md): *74
DT_VOL           #define 2L = 0x00000002  [rexx/rexxio.h](autodocs-2.0/includes-rexx-rexxio-h.md): *75
DUALPF           #define 0x0400 = 0x00000400  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *96
DVPB_ASSIGN      #define 1 = 0x00000001  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *420
DVPB_UNLOCK      #define 0 = 0x00000000  [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *418
DVPF_ASSIGN      #define (1L << DVPB_ASSIGN) = 0x00000002
```c
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *421
```
DVPF_UNLOCK      #define (1L << DVPB_UNLOCK) = 0x00000001
```c
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *419
```
DWidth           short int in struct ViewPort +0x0018 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *50
DamageList       pointer to struct Region in struct Layer
```c
         +0x009c [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md): *60
```
DateStamp        structure tag size 0x000c [dos/dos.h](autodocs-2.0/includes-dos-dos-h.md): *54, 72
```c
                 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): 247, 336, 379
                 [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): 28
```
DateTime         structure tag size 0x001a [dos/datetime.h](autodocs-2.0/includes-dos-datetime-h.md): *27
Debug            char in struct GfxBase +0x00a1 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *41
DebugData        pointer to void in struct ExecBase
```c
         +0x0046 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *51
```
DebugEntry       pointer to void in struct ExecBase
```c
         +0x0042 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *50
```
DefaultFont      pointer to struct TextFont in struct GfxBase
```c
         +0x009a [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *38
```
DefaultTitle     pointer to unsigned char in struct Screen
```c
         +0x001a [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *111
```
DefaultTitle     pointer to unsigned char in struct NewScreen
```c
         +0x0014 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *322
```
DefaultTitle     pointer to unsigned char in struct ExtNewScreen
```c
         +0x0014 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *353
```
DeniseMaxDisplayColumn unsigned short int in struct MonitorSpec
```c
         +0x0026 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *35
```
DeniseMinDisplayColumn unsigned short int in struct MonitorSpec
```c
         +0x0052 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *48
```
Depth            unsigned char in struct BitMap +0x0005 [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md): *53
Depth            short int in struct Image +0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *625
Depth            short int in struct NewScreen
```c
         +0x0008 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *312
```
Depth            short int in struct ExtNewScreen
```c
         +0x0008 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *348
```
Depth            short int in struct VSprite +0x001e [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *100
Descendant       pointer to struct Window in struct Window
```c
         +0x0046 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *844
```
DestAddr         short int in union (no tag)  +0x0000 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *37
DestData         short int in union (no tag)  +0x0000 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *42
DetailPen        unsigned char in struct Window
```c
         +0x0062 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *859
```
DetailPen        unsigned char in struct NewWindow
```c
         +0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *979
```
DetailPen        unsigned char in struct ExtNewWindow
```c
         +0x0008 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1049
```
DetailPen        unsigned char in struct Screen
```c
         +0x014a [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *137
```
DetailPen        unsigned char in struct NewScreen
```c
         +0x000a [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *314
```
DetailPen        unsigned char in struct ExtNewScreen
```c
         +0x000a [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *349
```
DetailPen        unsigned char in struct (no tag)
```c
         +0x0000 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): *53
```
DevInfo          structure tag size 0x002c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *345
DevProc          structure tag size 0x0010 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *410
Device           structure tag size 0x0022 [exec/devices.h](autodocs-2.0/includes-exec-devices-h.md): *26
```c
                 [exec/io.h](autodocs-2.0/includes-exec-io-h.md): 22, 31
                 [devices/clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md): 45
                 [devices/printer.h](autodocs-2.0/includes-devices-printer-h.md): 144, 158
```
DeviceData       structure tag size 0x0034 [devices/prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md): *51, 66
DeviceList       struct List(size 0x000e bytes) in struct ExecBase
```c
         +0x015e [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *88
```
DeviceList       structure tag size 0x002c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *331
DeviceNode       structure tag size 0x002c [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *101
DiagArea         structure tag size 0x000e [libraries/configregs.h](autodocs-2.0/includes-libraries-configregs-h.md): *237
DimensionInfo    structure tag size 0x0058 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *92
DiscResource     structure tag size 0x0094 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *50
DiscResourceUnit structure tag size 0x0056 [resources/disk.h](autodocs-2.0/includes-resources-disk-h.md): *43, 52
DiskFontHeader   structure tag size 0x006a [libraries/diskfont.h](autodocs-2.0/includes-libraries-diskfont-h.md): *64
DiskObject       structure tag size 0x004e [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *62
DispCount        unsigned long int in struct ExecBase
```c
         +0x011c [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *66
```
DispCount        short int in struct StringInfo
```c
         +0x0012 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *536
```
DispPos          short int in struct StringInfo
```c
         +0x000c [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *531
```
DisplayClip      struct Rectangle(size 0x0008 bytes) in struct ViewPortExtra
```c
         +0x001c [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *83
```
DisplayCompatible unsigned long int in struct MonitorSpec
```c
         +0x0054 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *49
```
DisplayFlags     unsigned short int in struct GfxBase
```c
         +0x00ce [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *53
```
DisplayID        unsigned long int in struct QueryHeader
```c
         +0x0004 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *45
```
DisplayInfo      structure tag size 0x0030 [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *50
DisplayInfoDataBase struct List(size 0x000e bytes) in struct MonitorSpec
```c
         +0x0058 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *50
```
DisplayInfoDataBase pointer to void in struct GfxBase
```c
         +0x0196 [graphics/gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md): *89
```
DisplayInfoDataBaseSemaphore struct SignalSemaphore(size 0x002e bytes) in
```c
                 struct MonitorSpec
         +0x0066 [graphics/monitor.h](autodocs-2.0/includes-graphics-monitor-h.md): *51
```
DisplayInfoHandle "APTR"  [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md): *33
DosEnvec         structure tag size 0x0050 [dos/filehandler.h](autodocs-2.0/includes-dos-filehandler-h.md): *29
DosInfo          structure tag size 0x0070 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *274
DosLibrary       structure tag size 0x0042 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *228
DosList          structure tag size 0x002c [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *361, 414
DosPacket        structure tag size 0x0030 [dos/dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md): *110, 143
DoubleClick      struct timeval(size 0x0008 bytes) in struct Preferences
```c
         +0x0014 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *58
```
DrawCircle       macro (4 arguments)   [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md): *43
DrawInfo         structure tag (size 0x0032 bytes)in struct impDraw
```c
                 [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md): *61
                 [intuition/cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md): 61
                 [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md): 143, 161
```
DrawMode         char in struct RastPort +0x001c [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md): *68
DrawMode         unsigned char in struct IntuiText
```c
         +0x0002 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *573
```
DrawMode         unsigned char in struct Border
```c
         +0x0006 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *602
```
DrawPath         pointer to struct VSprite in struct VSprite
```c
         +0x0008 [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md): *81
```
DrawerData       structure tag size 0x003e [workbench/workbench.h](autodocs-2.0/includes-workbench-workbench-h.md): *52, 71
DriveGeometry    structure tag size 0x0020 [devices/trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md): *137
DspIns           pointer to struct CopList in struct ViewPort
```c
         +0x0008 [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *46
```
DxOffset         short int in struct ViewPort +0x001c [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *51
DxOffset         short int in struct View +0x000e [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *63
DyOffset         short int in struct CopList +0x0020 [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md): *74
DyOffset         short int in struct ViewPort +0x001e [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *51
DyOffset         short int in struct View +0x000c [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md): *63

