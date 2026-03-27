---
title: References/Structure.offs
manual: autodocs-2.0
chapter: autodocs-2.0
section: references-structure-offs
functions: []
libraries: []
---

# References/Structure.offs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AChain:
  $0112   274  sizeof(AChain)
  $0000     0  an_Child
  $0004     4  an_Parent
  $0008     8  an_Lock
  $000c    12  an_Info
  $0110   272  an_Flags
  $0111   273  an_String[0]
AnalogSignalInterval:
  $0004     4  sizeof(
	AnalogSignalInterval)
  $0000     0  asi_Start
  $0002     2  asi_Stop
AnchorPath:
  $011a   282  sizeof(AnchorPath)
  $0000     0  ap_Base
  $0004     4  ap_Last
  $0008     8  ap_BreakBits
  $000c    12  ap_FoundBreak
  $0010    16  ap_Flags
  $0011    17  ap_Reserved
  $0012    18  ap_Strlen
  $0014    20  ap_Info
  $0118   280  ap_Buf[0]
AnimComp:
  $0026    38  sizeof(AnimComp)
  $0000     0  Flags
  $0002     2  Timer
  $0004     4  TimeSet
! $0006     6  NextComp
! $000a    10  PrevComp
! $000e    14  NextSeq
! $0012    18  PrevSeq
! $0016    22  AnimCRoutine
  $001a    26  YTrans
  $001c    28  XTrans
! $001e    30  HeadOb
! $0022    34  AnimBob
AnimOb:
  $002a    42  sizeof(AnimOb)
  $0000     0  NextOb
  $0004     4  PrevOb
  $0008     8  Clock
  $000c    12  AnOldY
  $000e    14  AnOldX
  $0010    16  AnY
  $0012    18  AnX
  $0014    20  YVel
  $0016    22  XVel
  $0018    24  YAccel
  $001a    26  XAccel
  $001c    28  RingYTrans
  $001e    30  RingXTrans
  $0020    32  AnimORoutine
  $0024    36  HeadComp
  $0028    40  AUserExt
AppIcon:
  $0020    32  sizeof(AppIcon)
  $0000     0  ai_Node
! $000e    14  ai_Ptr
! $0012    18  ai_MsgPort
! $0016    22  ai_UserData
! $001a    26  ai_ID
  $001e    30  ai_Version
AppMenuItem:
  $0020    32  sizeof(AppMenuItem)
  $0000     0  ami_Node
! $000e    14  ami_Ptr
! $0012    18  ami_MsgPort
! $0016    22  ami_UserData
! $001a    26  ami_ID
  $001e    30  ami_Version
AppMessage:
  $0056    86  sizeof(AppMessage)
  $0000     0  am_Message
  $0014    20  am_Type
! $0016    22  am_UserData
! $001a    26  am_ID
! $001e    30  am_NumArgs
! $0022    34  am_ArgList
  $0026    38  am_Version
  $0028    40  am_Class
  $002a    42  am_MouseX
  $002c    44  am_MouseY
! $002e    46  am_Seconds
! $0032    50  am_Micros
! $0036    54  am_Reserved[0]
AppWindow:
  $0020    32  sizeof(AppWindow)
  $0000     0  aw_Node
! $000e    14  aw_Ptr
! $0012    18  aw_MsgPort
! $0016    22  aw_UserData
! $001a    26  aw_ID
  $001e    30  aw_Version
AreaInfo:
  $0018    24  sizeof(AreaInfo)
  $0000     0  VctrTbl
  $0004     4  VctrPtr
  $0008     8  FlagTbl
  $000c    12  FlagPtr
  $0010    16  Count
  $0012    18  MaxCount
  $0014    20  FirstX
  $0016    22  FirstY
AssignList:
  $0008     8  sizeof(AssignList)
  $0000     0  al_Next
  $0004     4  al_Lock
AudChannel:
  $0010    16  sizeof(AudChannel)
  $0000     0  ac_ptr
  $0004     4  ac_len
  $0006     6  ac_per
  $0008     8  ac_vol
  $000a    10  ac_dat
  $000c    12  ac_pad[0]
AvailFonts:
  $000a    10  sizeof(AvailFonts)
  $0000     0  af_Type
! $0002     2  af_Attr
AvailFontsHeader:
  $0002     2  sizeof(AvailFontsHeader)
  $0000     0  afh_NumEntries
BadBlockBlock:
  $0200   512  sizeof(BadBlockBlock)
  $0000     0  bbb_ID
  $0004     4  bbb_SummedLongs
  $0008     8  bbb_ChkSum
  $000c    12  bbb_HostID
  $0010    16  bbb_Next
  $0014    20  bbb_Reserved
  $0018    24  bbb_BlockPairs[0]
BadBlockEntry:
  $0008     8  sizeof(BadBlockEntry)
  $0000     0  bbe_BadBlock
  $0004     4  bbe_GoodBlock
BitMap:
  $0028    40  sizeof(BitMap)
  $0000     0  BytesPerRow
  $0002     2  Rows
  $0004     4  Flags
  $0005     5  Depth
  $0006     6  pad
  $0008     8  Planes[0]
BitScaleArgs:
  $0030    48  sizeof(BitScaleArgs)
  $0000     0  bsa_SrcX
  $0002     2  bsa_SrcY
  $0004     4  bsa_SrcWidth
  $0006     6  bsa_SrcHeight
  $0008     8  bsa_XSrcFactor
  $000a    10  bsa_YSrcFactor
  $000c    12  bsa_DestX
  $000e    14  bsa_DestY
  $0010    16  bsa_DestWidth
  $0012    18  bsa_DestHeight
  $0014    20  bsa_XDestFactor
  $0016    22  bsa_YDestFactor
  $0018    24  bsa_SrcBitMap
  $001c    28  bsa_DestBitMap
  $0020    32  bsa_Flags
  $0024    36  bsa_XDDA
  $0026    38  bsa_YDDA
  $0028    40  bsa_Reserved1
  $002c    44  bsa_Reserved2
Bob:
  $0020    32  sizeof(Bob)
  $0000     0  Flags
! $0002     2  SaveBuffer
! $0006     6  ImageShadow
! $000a    10  Before
! $000e    14  After
! $0012    18  BobVSprite
! $0016    22  BobComp
! $001a    26  DBuffer
  $001e    30  BUserExt
BoolInfo:
  $000a    10  sizeof(BoolInfo)
  $0000     0  Flags
! $0002     2  Mask
! $0006     6  Reserved
BootBlock:
  $000c    12  sizeof(BootBlock)
  $0000     0  bb_id[0]
  $0004     4  bb_chksum
  $0008     8  bb_dosblock
BootNode:
  $0014    20  sizeof(BootNode)
  $0000     0  bn_Node
  $000e    14  bn_Flags
  $0010    16  bn_DeviceNode
Border:
  $0010    16  sizeof(Border)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  FrontPen
  $0005     5  BackPen
  $0006     6  DrawMode
  $0007     7  Count
  $0008     8  XY
  $000c    12  NextBorder
CIA:
  $0f02  3842  sizeof(CIA)
  $0000     0  ciapra
! $0001     1  pad0[0]
  $0100   256  ciaprb
! $0101   257  pad1[0]
  $0200   512  ciaddra
! $0201   513  pad2[0]
  $0300   768  ciaddrb
! $0301   769  pad3[0]
  $0400  1024  ciatalo
! $0401  1025  pad4[0]
  $0500  1280  ciatahi
! $0501  1281  pad5[0]
  $0600  1536  ciatblo
! $0601  1537  pad6[0]
  $0700  1792  ciatbhi
! $0701  1793  pad7[0]
  $0800  2048  ciatodlow
! $0801  2049  pad8[0]
  $0900  2304  ciatodmid
! $0901  2305  pad9[0]
  $0a00  2560  ciatodhi
! $0a01  2561  pad10[0]
  $0b00  2816  unusedreg
! $0b01  2817  pad11[0]
  $0c00  3072  ciasdr
! $0c01  3073  pad12[0]
  $0d00  3328  ciaicr
! $0d01  3329  pad13[0]
  $0e00  3584  ciacra
! $0e01  3585  pad14[0]
  $0f00  3840  ciacrb
CSource:
  $000c    12  sizeof(CSource)
  $0000     0  CS_Buffer
  $0004     4  CS_Length
  $0008     8  CS_CurChr
CliProcList:
  $0010    16  sizeof(CliProcList)
  $0000     0  cpl_Node
  $0008     8  cpl_First
  $000c    12  cpl_Array
ClipHookMsg:
  $000c    12  sizeof(ClipHookMsg)
  $0000     0  chm_Type
  $0004     4  chm_ChangeCmd
  $0008     8  chm_ClipID
ClipRect:
  $0024    36  sizeof(ClipRect)
  $0000     0  Next
  $0004     4  prev
  $0008     8  lobs
  $000c    12  BitMap
  $0010    16  bounds
  $0018    24  _p1
  $001c    28  _p2
  $0020    32  reserved
ClipboardHandle:
  $0078   120  sizeof(ClipboardHandle)
  $0000     0  cbh_Req
  $0034    52  cbh_CBport
! $0056    86  cbh_SatisfyPort
ClipboardUnitPartial:
  $0012    18  sizeof(
	ClipboardUnitPartial)
  $0000     0  cu_Node
! $000e    14  cu_UnitNum
ClockData:
  $000e    14  sizeof(ClockData)
  $0000     0  sec
  $0002     2  min
  $0004     4  hour
  $0006     6  mday
  $0008     8  month
  $000a    10  year
  $000c    12  wday
CollectionItem:
  $000c    12  sizeof(CollectionItem)
  $0000     0  ci_Next
  $0004     4  ci_Size
  $0008     8  ci_Data
ColorFontColors:
  $0008     8  sizeof(ColorFontColors)
  $0000     0  cfc_Reserved
  $0002     2  cfc_Count
  $0004     4  cfc_ColorTable
ColorMap:
  $0028    40  sizeof(ColorMap)
  $0000     0  Flags
  $0001     1  Type
  $0002     2  Count
  $0004     4  ColorTable
  $0008     8  cm_vpe
  $000c    12  TransparencyBits
  $0010    16  TransparencyPlane
  $0011    17  reserved1
  $0012    18  reserved2
  $0014    20  cm_vp
  $0018    24  NormalDisplayInfo
  $001c    28  CoerceDisplayInfo
  $0020    32  cm_batch_items
  $0024    36  VPModeID
ColorSpec:
  $0008     8  sizeof(ColorSpec)
  $0000     0  ColorIndex
  $0002     2  Red
  $0004     4  Green
  $0006     6  Blue
ColorTextFont:
  $0060    96  sizeof(ColorTextFont)
  $0000     0  ctf_TF
  $0034    52  ctf_Flags
  $0036    54  ctf_Depth
  $0037    55  ctf_FgColor
  $0038    56  ctf_Low
  $0039    57  ctf_High
  $003a    58  ctf_PlanePick
  $003b    59  ctf_PlaneOnOff
  $003c    60  ctf_ColorFontColors
  $0040    64  ctf_CharData[0]
CommandLineInterface:
  $0040    64  sizeof(
	CommandLineInterface)
  $0000     0  cli_Result2
  $0004     4  cli_SetName
  $0008     8  cli_CommandDir
  $000c    12  cli_ReturnCode
  $0010    16  cli_CommandName
  $0014    20  cli_FailLevel
  $0018    24  cli_Prompt
  $001c    28  cli_StandardInput
  $0020    32  cli_CurrentInput
  $0024    36  cli_CommandFile
  $0028    40  cli_Interactive
  $002c    44  cli_Background
  $0030    48  cli_CurrentOutput
  $0034    52  cli_DefaultStack
  $0038    56  cli_StandardOutput
  $003c    60  cli_Module
ConUnit:
  $0128   296  sizeof(ConUnit)
  $0000     0  cu_MP
! $0022    34  cu_Window
  $0026    38  cu_XCP
  $0028    40  cu_YCP
  $002a    42  cu_XMax
  $002c    44  cu_YMax
  $002e    46  cu_XRSize
  $0030    48  cu_YRSize
  $0032    50  cu_XROrigin
  $0034    52  cu_YROrigin
  $0036    54  cu_XRExtant
  $0038    56  cu_YRExtant
  $003a    58  cu_XMinShrink
  $003c    60  cu_YMinShrink
  $003e    62  cu_XCCP
  $0040    64  cu_YCCP
! $0042    66  cu_KeyMapStruct
! $0062    98  cu_TabStops[0]
  $0102   258  cu_Mask
  $0103   259  cu_FgPen
  $0104   260  cu_BgPen
  $0105   261  cu_AOLPen
  $0106   262  cu_DrawMode
  $0107   263  cu_Obsolete1
  $0108   264  cu_Obsolete2
  $010c   268  cu_Minterms[0]
  $0114   276  cu_Font
  $0118   280  cu_AlgoStyle
  $0119   281  cu_TxFlags
  $011a   282  cu_TxHeight
  $011c   284  cu_TxWidth
  $011e   286  cu_TxBaseline
  $0120   288  cu_TxSpacing
  $0122   290  cu_Modes[0]
  $0125   293  cu_RawEvents[0]
ConfigDev:
  $0044    68  sizeof(ConfigDev)
  $0000     0  cd_Node
  $000e    14  cd_Flags
  $000f    15  cd_Pad
  $0010    16  cd_Rom
  $0020    32  cd_BoardAddr
  $0024    36  cd_BoardSize
  $0028    40  cd_SlotAddr
  $002a    42  cd_SlotSize
  $002c    44  cd_Driver
  $0030    48  cd_NextCD
  $0034    52  cd_Unused[0]
ContextNode:
  $0018    24  sizeof(ContextNode)
  $0000     0  cn_Node
  $0008     8  cn_ID
  $000c    12  cn_Type
  $0010    16  cn_Size
  $0014    20  cn_Scan
CopIns:
  $0006     6  sizeof(CopIns)
  $0000     0  OpCode
  $0002     2  u3
  $0002     2  u3.nxtlist
  $0002     2  u3.u4
  $0002     2  u3.u4.u1
  $0002     2  u3.u4.u1.VWaitPos
  $0002     2  u3.u4.u1.DestAddr
  $0004     4  u3.u4.u2
  $0004     4  u3.u4.u2.HWaitPos
  $0004     4  u3.u4.u2.DestData
CopList:
  $0022    34  sizeof(CopList)
  $0000     0  Next
  $0004     4  _CopList
  $0008     8  _ViewPort
  $000c    12  CopIns
  $0010    16  CopPtr
  $0014    20  CopLStart
  $0018    24  CopSStart
  $001c    28  Count
  $001e    30  MaxCount
  $0020    32  DyOffset
CurrentBinding:
  $0010    16  sizeof(CurrentBinding)
  $0000     0  cb_ConfigDev
  $0004     4  cb_FileName
  $0008     8  cb_ProductString
  $000c    12  cb_ToolTypes
Custom:
  $01e6   486  sizeof(Custom)
  $0000     0  bltddat
  $0002     2  dmaconr
  $0004     4  vposr
  $0006     6  vhposr
  $0008     8  dskdatr
  $000a    10  joy0dat
  $000c    12  joy1dat
  $000e    14  clxdat
  $0010    16  adkconr
  $0012    18  pot0dat
  $0014    20  pot1dat
  $0016    22  potinp
  $0018    24  serdatr
  $001a    26  dskbytr
  $001c    28  intenar
  $001e    30  intreqr
  $0020    32  dskpt
  $0024    36  dsklen
  $0026    38  dskdat
  $0028    40  refptr
  $002a    42  vposw
  $002c    44  vhposw
  $002e    46  copcon
  $0030    48  serdat
  $0032    50  serper
  $0034    52  potgo
  $0036    54  joytest
  $0038    56  strequ
  $003a    58  strvbl
  $003c    60  strhor
  $003e    62  strlong
  $0040    64  bltcon0
  $0042    66  bltcon1
  $0044    68  bltafwm
  $0046    70  bltalwm
  $0048    72  bltcpt
  $004c    76  bltbpt
  $0050    80  bltapt
  $0054    84  bltdpt
  $0058    88  bltsize
  $005a    90  pad2d
  $005b    91  bltcon0l
  $005c    92  bltsizv
  $005e    94  bltsizh
  $0060    96  bltcmod
  $0062    98  bltbmod
  $0064   100  bltamod
  $0066   102  bltdmod
  $0068   104  pad34[0]
  $0070   112  bltcdat
  $0072   114  bltbdat
  $0074   116  bltadat
! $0076   118  pad3b[0]
  $007c   124  deniseid
  $007e   126  dsksync
  $0080   128  cop1lc
  $0084   132  cop2lc
  $0088   136  copjmp1
  $008a   138  copjmp2
  $008c   140  copins
  $008e   142  diwstrt
  $0090   144  diwstop
  $0092   146  ddfstrt
  $0094   148  ddfstop
  $0096   150  dmacon
  $0098   152  clxcon
  $009a   154  intena
  $009c   156  intreq
  $009e   158  adkcon
  $0000     0  ac_ptr
  $0004     4  ac_len
  $0006     6  ac_per
  $0008     8  ac_vol
  $000a    10  ac_dat
  $000c    12  ac_pad[0]
  $00a0   160  aud[0]
  $00e0   224  bplpt[0]
  $0100   256  bplcon0
  $0102   258  bplcon1
  $0104   260  bplcon2
  $0106   262  bplcon3
  $0108   264  bpl1mod
  $010a   266  bpl2mod
  $010c   268  bplhmod
  $010e   270  pad86[0]
  $0110   272  bpldat[0]
  $0120   288  sprpt[0]
  $0000     0  pos
  $0002     2  ctl
  $0004     4  dataa
! $0006     6  datab
  $0140   320  spr[0]
  $0180   384  color[0]
  $01c0   448  htotal
  $01c2   450  hsstop
  $01c4   452  hbstrt
  $01c6   454  hbstop
  $01c8   456  vtotal
  $01ca   458  vsstop
  $01cc   460  vbstrt
  $01ce   462  vbstop
  $01d0   464  sprhstrt
  $01d2   466  sprhstop
  $01d4   468  bplhstrt
  $01d6   470  bplhstop
  $01d8   472  hhposw
  $01da   474  hhposr
  $01dc   476  beamcon0
  $01de   478  hsstrt
  $01e0   480  vsstrt
  $01e2   482  hcenter
  $01e4   484  diwhigh
DBufPacket:
  $000c    12  sizeof(DBufPacket)
  $0000     0  BufY
  $0002     2  BufX
  $0004     4  BufPath
  $0008     8  BufBuffer
DateStamp:
  $000c    12  sizeof(DateStamp)
  $0000     0  ds_Days
  $0004     4  ds_Minute
  $0008     8  ds_Tick
DateTime:
  $001a    26  sizeof(DateTime)
  $0000     0  dat_Stamp
  $000c    12  dat_Format
  $000d    13  dat_Flags
! $000e    14  dat_StrDay
! $0012    18  dat_StrDate
! $0016    22  dat_StrTime
DevInfo:
  $002c    44  sizeof(DevInfo)
  $0000     0  dvi_Next
  $0004     4  dvi_Type
  $0008     8  dvi_Task
  $000c    12  dvi_Lock
  $0010    16  dvi_Handler
  $0014    20  dvi_StackSize
  $0018    24  dvi_Priority
  $001c    28  dvi_Startup
  $0020    32  dvi_SegList
  $0024    36  dvi_GlobVec
  $0028    40  dvi_Name
DevProc:
  $0010    16  sizeof(DevProc)
  $0000     0  dvp_Port
  $0004     4  dvp_Lock
  $0008     8  dvp_Flags
  $000c    12  dvp_DevNode
Device:
  $0022    34  sizeof(Device)
  $0000     0  dd_Library
DeviceData:
  $0034    52  sizeof(DeviceData)
  $0000     0  dd_Device
! $0022    34  dd_Segment
! $0026    38  dd_ExecBase
! $002a    42  dd_CmdVectors
! $002e    46  dd_CmdBytes
  $0032    50  dd_NumCommands
DeviceList:
  $002c    44  sizeof(DeviceList)
  $0000     0  dl_Next
  $0004     4  dl_Type
  $0008     8  dl_Task
  $000c    12  dl_Lock
  $0010    16  dl_VolumeDate
  $001c    28  dl_LockList
  $0020    32  dl_DiskType
  $0024    36  dl_unused
  $0028    40  dl_Name
DeviceNode:
  $002c    44  sizeof(DeviceNode)
  $0000     0  dn_Next
  $0004     4  dn_Type
  $0008     8  dn_Task
  $000c    12  dn_Lock
  $0010    16  dn_Handler
  $0014    20  dn_StackSize
  $0018    24  dn_Priority
  $001c    28  dn_Startup
  $0020    32  dn_SegList
  $0024    36  dn_GlobalVec
  $0028    40  dn_Name
DiagArea:
  $000e    14  sizeof(DiagArea)
  $0000     0  da_Config
  $0001     1  da_Flags
  $0002     2  da_Size
  $0004     4  da_DiagPoint
  $0006     6  da_BootPoint
  $0008     8  da_Name
  $000a    10  da_Reserved01
  $000c    12  da_Reserved02
DimensionInfo:
  $0058    88  sizeof(DimensionInfo)
  $0000     0  Header
  $0010    16  MaxDepth
  $0012    18  MinRasterWidth
  $0014    20  MinRasterHeight
  $0016    22  MaxRasterWidth
  $0018    24  MaxRasterHeight
! $001a    26  Nominal
! $0022    34  MaxOScan
! $002a    42  VideoOScan
! $0032    50  TxtOScan
! $003a    58  StdOScan
! $0042    66  pad[0]
  $0050    80  reserved[0]
DiscResource:
  $0094   148  sizeof(DiscResource)
  $0000     0  dr_Library
! $0022    34  dr_Current
  $0026    38  dr_Flags
  $0027    39  dr_pad
  $0028    40  dr_SysLib
  $002c    44  dr_CiaResource
  $0030    48  dr_UnitID[0]
  $0040    64  dr_Waiting
! $004e    78  dr_DiscBlock
  $0064   100  dr_DiscSync
! $007a   122  dr_Index
  $0090   144  dr_CurrTask
DiscResourceUnit:
  $0056    86  sizeof(DiscResourceUnit)
  $0000     0  dru_Message
  $0014    20  dru_DiscBlock
! $002a    42  dru_DiscSync
  $0040    64  dru_Index
DiskFontHeader:
  $006a   106  sizeof(DiskFontHeader)
  $0000     0  dfh_DF
  $000e    14  dfh_FileID
  $0010    16  dfh_Revision
! $0012    18  dfh_Segment
! $0016    22  dfh_Name[0]
! $0036    54  dfh_TF
DiskObject:
  $004e    78  sizeof(DiskObject)
  $0000     0  do_Magic
  $0002     2  do_Version
  $0004     4  do_Gadget
  $0030    48  do_Type
! $0032    50  do_DefaultTool
! $0036    54  do_ToolTypes
! $003a    58  do_CurrentX
! $003e    62  do_CurrentY
! $0042    66  do_DrawerData
! $0046    70  do_ToolWindow
! $004a    74  do_StackSize
DisplayInfo:
  $0030    48  sizeof(DisplayInfo)
  $0000     0  Header
  $0010    16  NotAvailable
! $0012    18  PropertyFlags
! $0016    22  Resolution
  $001a    26  PixelSpeed
  $001c    28  NumStdSprites
  $001e    30  PaletteRange
  $0020    32  SpriteResolution
  $0024    36  pad[0]
  $0028    40  reserved[0]
DosEnvec:
  $0050    80  sizeof(DosEnvec)
  $0000     0  de_TableSize
  $0004     4  de_SizeBlock
  $0008     8  de_SecOrg
  $000c    12  de_Surfaces
  $0010    16  de_SectorPerBlock
  $0014    20  de_BlocksPerTrack
  $0018    24  de_Reserved
  $001c    28  de_PreAlloc
  $0020    32  de_Interleave
  $0024    36  de_LowCyl
  $0028    40  de_HighCyl
  $002c    44  de_NumBuffers
  $0030    48  de_BufMemType
  $0034    52  de_MaxTransfer
  $0038    56  de_Mask
  $003c    60  de_BootPri
  $0040    64  de_DosType
  $0044    68  de_Baud
  $0048    72  de_Control
  $004c    76  de_BootBlocks
DosInfo:
  $0070   112  sizeof(DosInfo)
  $0000     0  di_McName
  $0004     4  di_DevInfo
  $0008     8  di_Devices
  $000c    12  di_Handlers
  $0010    16  di_NetHand
  $0014    20  di_DevLock
! $0042    66  di_EntryLock
DosLibrary:
  $0042    66  sizeof(DosLibrary)
  $0000     0  dl_lib
! $0022    34  dl_Root
! $0026    38  dl_GV
! $002a    42  dl_A2
! $002e    46  dl_A5
! $0032    50  dl_A6
! $0036    54  dl_Errors
! $003a    58  dl_TimeReq
! $003e    62  dl_UtilityBase
DosList:
  $002c    44  sizeof(DosList)
  $0000     0  dol_Next
  $0004     4  dol_Type
  $0008     8  dol_Task
  $000c    12  dol_Lock
  $0010    16  dol_misc
  $0010    16  dol_misc.dol_handler
  $0010    16
      dol_misc.dol_handler.dol_Handler
  $0014    20
      dol_misc.dol_handler.dol_StackSize
  $0018    24
      dol_misc.dol_handler.dol_Priority
  $001c    28
      dol_misc.dol_handler.dol_Startup
  $0020    32
      dol_misc.dol_handler.dol_SegList
  $0024    36
      dol_misc.dol_handler.dol_GlobVec
  $0010    16  dol_misc.dol_volume
  $0010    16
      dol_misc.dol_volume.dol_VolumeDate
  $001c    28
      dol_misc.dol_volume.dol_LockList
  $0020    32
      dol_misc.dol_volume.dol_DiskType
  $0010    16  dol_misc.dol_assign
  $0010    16
      dol_misc.dol_assign.dol_AssignName
  $0014    20
      dol_misc.dol_assign.dol_List
  $0028    40  dol_Name
DosPacket:
  $0030    48  sizeof(DosPacket)
  $0000     0  dp_Link
  $0004     4  dp_Port
  $0008     8  dp_Type
  $000c    12  dp_Res1
  $0010    16  dp_Res2
  $0014    20  dp_Arg1
  $0018    24  dp_Arg2
  $001c    28  dp_Arg3
  $0020    32  dp_Arg4
  $0024    36  dp_Arg5
  $0028    40  dp_Arg6
  $002c    44  dp_Arg7
DrawInfo:
  $0032    50  sizeof(DrawInfo)
  $0000     0  dri_Version
  $0002     2  dri_NumPens
  $0004     4  dri_Pens
  $0008     8  dri_Font
  $000c    12  dri_Depth
  $000e    14  dri_Resolution
  $000e    14  dri_Resolution.X
  $0010    16  dri_Resolution.Y
! $0012    18  dri_Flags
! $0016    22  dri_Reserved[0]
DrawerData:
  $003e    62  sizeof(DrawerData)
  $0000     0  dd_NewWindow
  $0030    48  dd_CurrentX
  $0034    52  dd_CurrentY
  $0038    56  dd_Flags
  $003c    60  dd_ViewModes
DriveGeometry:
  $0020    32  sizeof(DriveGeometry)
  $0000     0  dg_SectorSize
  $0004     4  dg_TotalSectors
  $0008     8  dg_Cylinders
  $000c    12  dg_CylSectors
  $0010    16  dg_Heads
  $0014    20  dg_TrackSectors
  $0018    24  dg_BufMemType
  $001c    28  dg_DeviceType
  $001d    29  dg_Flags
  $001e    30  dg_Reserved
EClockVal:
  $0008     8  sizeof(EClockVal)
  $0000     0  ev_hi
  $0004     4  ev_lo
EasyStruct:
  $0014    20  sizeof(EasyStruct)
  $0000     0  es_StructSize
  $0004     4  es_Flags
  $0008     8  es_Title
  $000c    12  es_TextFormat
  $0010    16  es_GadgetFormat
ErrorString:
  $0008     8  sizeof(ErrorString)
  $0000     0  estr_Nums
  $0004     4  estr_Strings
ExAllControl:
  $0010    16  sizeof(ExAllControl)
  $0000     0  eac_Entries
  $0004     4  eac_LastKey
  $0008     8  eac_MatchString
  $000c    12  eac_MatchFunc
ExAllData:
  $0024    36  sizeof(ExAllData)
  $0000     0  ed_Next
  $0004     4  ed_Name
  $0008     8  ed_Type
  $000c    12  ed_Size
  $0010    16  ed_Prot
  $0014    20  ed_Days
  $0018    24  ed_Mins
  $001c    28  ed_Ticks
  $0020    32  ed_Comment
ExecBase:
  $0268   616  sizeof(ExecBase)
  $0000     0  LibNode
  $0022    34  SoftVer
  $0024    36  LowMemChkSum
! $0026    38  ChkBase
! $002a    42  ColdCapture
! $002e    46  CoolCapture
! $0032    50  WarmCapture
! $0036    54  SysStkUpper
! $003a    58  SysStkLower
! $003e    62  MaxLocMem
! $0042    66  DebugEntry
! $0046    70  DebugData
! $004a    74  AlertData
! $004e    78  MaxExtMem
  $0052    82  ChkSum
  $0054    84  IntVects[0]
  $0114   276  ThisTask
  $0118   280  IdleCount
  $011c   284  DispCount
  $0120   288  Quantum
  $0122   290  Elapsed
  $0124   292  SysFlags
  $0126   294  IDNestCnt
  $0127   295  TDNestCnt
  $0128   296  AttnFlags
  $012a   298  AttnResched
  $012c   300  ResModules
  $0130   304  TaskTrapCode
  $0134   308  TaskExceptCode
  $0138   312  TaskExitCode
  $013c   316  TaskSigAlloc
  $0140   320  TaskTrapAlloc
! $0142   322  MemList
  $0150   336  ResourceList
! $015e   350  DeviceList
  $016c   364  IntrList
! $017a   378  LibList
  $0188   392  PortList
! $0196   406  TaskReady
  $01a4   420  TaskWait
! $01b2   434  SoftInts[0]
! $0202   514  LastAlert[0]
  $0212   530  VBlankFrequency
  $0213   531  PowerSupplyFrequency
  $0214   532  SemaphoreList
! $0222   546  KickMemPtr
! $0226   550  KickTagPtr
! $022a   554  KickCheckSum
  $022e   558  ex_Pad0
  $0230   560  ex_Reserved0
  $0234   564  ex_RamLibPrivate
  $0238   568  ex_EClockFrequency
  $023c   572  ex_CacheControl
  $0240   576  ex_TaskID
  $0244   580  ex_PuddleSize
  $0248   584  ex_PoolThreshold
  $024c   588  ex_PublicPool
  $0258   600  ex_MMULock
  $025c   604  ex_Reserved[0]
ExpansionBase:
  $0058    88  sizeof(ExpansionBase)
  $0000     0  LibNode
  $0022    34  Flags
  $0023    35  eb_Private01
  $0024    36  eb_Private02
  $0028    40  eb_Private03
  $002c    44  eb_Private04
  $003c    60  eb_Private05
! $004a    74  MountList
ExpansionControl:
  $0010    16  sizeof(ExpansionControl)
  $0000     0  ec_Interrupt
  $0001     1  ec_Z3_HighBase
  $0002     2  ec_BaseAddress
  $0003     3  ec_Shutup
  $0004     4  ec_Reserved14
  $0005     5  ec_Reserved15
  $0006     6  ec_Reserved16
  $0007     7  ec_Reserved17
  $0008     8  ec_Reserved18
  $0009     9  ec_Reserved19
  $000a    10  ec_Reserved1a
  $000b    11  ec_Reserved1b
  $000c    12  ec_Reserved1c
  $000d    13  ec_Reserved1d
  $000e    14  ec_Reserved1e
  $000f    15  ec_Reserved1f
ExpansionRom:
  $0010    16  sizeof(ExpansionRom)
  $0000     0  er_Type
  $0001     1  er_Product
  $0002     2  er_Flags
  $0003     3  er_Reserved03
  $0004     4  er_Manufacturer
! $0006     6  er_SerialNumber
  $000a    10  er_InitDiagVec
  $000c    12  er_Reserved0c
  $000d    13  er_Reserved0d
  $000e    14  er_Reserved0e
  $000f    15  er_Reserved0f
ExtNewScreen:
  $0024    36  sizeof(ExtNewScreen)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  Width
  $0006     6  Height
  $0008     8  Depth
  $000a    10  DetailPen
  $000b    11  BlockPen
  $000c    12  ViewModes
  $000e    14  Type
  $0010    16  Font
  $0014    20  DefaultTitle
  $0018    24  Gadgets
  $001c    28  CustomBitMap
  $0020    32  Extension
ExtNewWindow:
  $0034    52  sizeof(ExtNewWindow)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  Width
  $0006     6  Height
  $0008     8  DetailPen
  $0009     9  BlockPen
! $000a    10  IDCMPFlags
! $000e    14  Flags
! $0012    18  FirstGadget
! $0016    22  CheckMark
! $001a    26  Title
! $001e    30  Screen
! $0022    34  BitMap
  $0026    38  MinWidth
  $0028    40  MinHeight
  $002a    42  MaxWidth
  $002c    44  MaxHeight
  $002e    46  Type
  $0030    48  Extension
ExtendedNode:
  $0018    24  sizeof(ExtendedNode)
  $0000     0  xln_Succ
  $0004     4  xln_Pred
  $0008     8  xln_Type
  $0009     9  xln_Pri
! $000a    10  xln_Name
  $000e    14  xln_Subsystem
  $000f    15  xln_Subtype
  $0010    16  xln_Library
  $0014    20  xln_Init
FileHandle:
  $002c    44  sizeof(FileHandle)
  $0000     0  fh_Link
  $0004     4  fh_Port
  $0008     8  fh_Type
  $000c    12  fh_Buf
  $0010    16  fh_Pos
  $0014    20  fh_End
  $0018    24  fh_Funcs
  $001c    28  fh_Func2
  $0020    32  fh_Func3
  $0024    36  fh_Args
  $0028    40  fh_Arg2
FileInfoBlock:
  $0104   260  sizeof(FileInfoBlock)
  $0000     0  fib_DiskKey
  $0004     4  fib_DirEntryType
  $0008     8  fib_FileName[0]
  $0074   116  fib_Protection
  $0078   120  fib_EntryType
  $007c   124  fib_Size
  $0080   128  fib_NumBlocks
  $0084   132  fib_Date
  $0090   144  fib_Comment[0]
  $00e0   224  fib_Reserved[0]
FileLock:
  $0014    20  sizeof(FileLock)
  $0000     0  fl_Link
  $0004     4  fl_Key
  $0008     8  fl_Access
  $000c    12  fl_Task
  $0010    16  fl_Volume
FileRequester:
  $002c    44  sizeof(FileRequester)
  $0000     0  rf_Reserved1
  $0004     4  rf_File
  $0008     8  rf_Dir
  $000c    12  rf_Reserved2[0]
  $0016    22  rf_LeftEdge
  $0018    24  rf_TopEdge
  $001a    26  rf_Width
  $001c    28  rf_Height
  $001e    30  rf_Reserved3
  $0020    32  rf_NumArgs
  $0024    36  rf_ArgList
  $0028    40  rf_UserData
FileSysEntry:
  $003e    62  sizeof(FileSysEntry)
  $0000     0  fse_Node
! $000e    14  fse_DosType
! $0012    18  fse_Version
! $0016    22  fse_PatchFlags
! $001a    26  fse_Type
! $001e    30  fse_Task
! $0022    34  fse_Lock
! $0026    38  fse_Handler
! $002a    42  fse_StackSize
! $002e    46  fse_Priority
! $0032    50  fse_Startup
! $0036    54  fse_SegList
! $003a    58  fse_GlobalVec
FileSysHeaderBlock:
  $0100   256  sizeof(FileSysHeaderBlock)
  $0000     0  fhb_ID
  $0004     4  fhb_SummedLongs
  $0008     8  fhb_ChkSum
  $000c    12  fhb_HostID
  $0010    16  fhb_Next
  $0014    20  fhb_Flags
  $0018    24  fhb_Reserved1[0]
  $0020    32  fhb_DosType
  $0024    36  fhb_Version
  $0028    40  fhb_PatchFlags
  $002c    44  fhb_Type
  $0030    48  fhb_Task
  $0034    52  fhb_Lock
  $0038    56  fhb_Handler
  $003c    60  fhb_StackSize
  $0040    64  fhb_Priority
  $0044    68  fhb_Startup
  $0048    72  fhb_SegListBlocks
  $004c    76  fhb_GlobalVec
  $0050    80  fhb_Reserved2[0]
  $00ac   172  fhb_Reserved3[0]
FileSysResource:
  $0020    32  sizeof(FileSysResource)
  $0000     0  fsr_Node
! $000e    14  fsr_Creator
! $0012    18  fsr_FileSysEntries
FileSysStartupMsg:
  $0010    16  sizeof(FileSysStartupMsg)
  $0000     0  fssm_Unit
  $0004     4  fssm_Device
  $0008     8  fssm_Environ
  $000c    12  fssm_Flags
FontContents:
  $0104   260  sizeof(FontContents)
  $0000     0  fc_FileName[0]
  $0100   256  fc_YSize
  $0102   258  fc_Style
  $0103   259  fc_Flags
FontContentsHeader:
  $0004     4  sizeof(FontContentsHeader)
  $0000     0  fch_FileID
  $0002     2  fch_NumEntries
FontRequester:
  $0018    24  sizeof(FontRequester)
  $0000     0  fo_Reserved1[0]
  $0008     8  fo_Attr
  $0010    16  fo_FrontPen
  $0011    17  fo_BackPen
  $0012    18  fo_DrawMode
  $0014    20  fo_UserData
FreeList:
  $0010    16  sizeof(FreeList)
  $0000     0  fl_NumFree
! $0002     2  fl_MemList
Gadget:
  $002c    44  sizeof(Gadget)
  $0000     0  NextGadget
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  Width
  $000a    10  Height
  $000c    12  Flags
  $000e    14  Activation
  $0010    16  GadgetType
! $0012    18  GadgetRender
! $0016    22  SelectRender
! $001a    26  GadgetText
! $001e    30  MutualExclude
! $0022    34  SpecialInfo
  $0026    38  GadgetID
  $0028    40  UserData
GadgetInfo:
  $003a    58  sizeof(GadgetInfo)
  $0000     0  gi_Screen
  $0004     4  gi_Window
  $0008     8  gi_Requester
  $000c    12  gi_RastPort
  $0010    16  gi_Layer
  $0014    20  gi_Domain
  $001c    28  gi_Pens
  $001c    28  gi_Pens.DetailPen
  $001d    29  gi_Pens.BlockPen
! $001e    30  gi_DrInfo
! $0022    34  gi_Reserved[0]
GamePortTrigger:
  $0008     8  sizeof(GamePortTrigger)
  $0000     0  gpt_Keys
  $0002     2  gpt_Timeout
  $0004     4  gpt_XDelta
  $0006     6  gpt_YDelta
GelsInfo:
  $0026    38  sizeof(GelsInfo)
  $0000     0  sprRsrvd
  $0001     1  Flags
! $0002     2  gelHead
! $0006     6  gelTail
! $000a    10  nextLine
! $000e    14  lastColor
! $0012    18  collHandler
  $0016    22  leftmost
  $0018    24  rightmost
  $001a    26  topmost
  $001c    28  bottommost
! $001e    30  firstBlissObj
! $0022    34  lastBlissObj
GfxBase:
  $01a6   422  sizeof(GfxBase)
  $0000     0  LibNode
! $0022    34  ActiView
! $0026    38  copinit
! $002a    42  cia
! $002e    46  blitter
! $0032    50  LOFlist
! $0036    54  SHFlist
! $003a    58  blthd
! $003e    62  blttl
! $0042    66  bsblthd
! $0046    70  bsblttl
! $004a    74  vbsrv
  $0060    96  timsrv
! $0076   118  bltsrv
  $008c   140  TextFonts
! $009a   154  DefaultFont
  $009e   158  Modes
  $00a0   160  VBlank
  $00a1   161  Debug
  $00a2   162  BeamSync
  $00a4   164  system_bplcon0
  $00a6   166  SpriteReserved
  $00a7   167  bytereserved
  $00a8   168  Flags
  $00aa   170  BlitLock
  $00ac   172  BlitNest
! $00ae   174  BlitWaitQ
  $00bc   188  BlitOwner
  $00c0   192  TOF_WaitQ
  $00ce   206  DisplayFlags
  $00d0   208  SimpleSprites
  $00d4   212  MaxDisplayRow
  $00d6   214  MaxDisplayColumn
  $00d8   216  NormalDisplayRows
  $00da   218  NormalDisplayColumns
  $00dc   220  NormalDPMX
  $00de   222  NormalDPMY
  $00e0   224  LastChanceMemory
  $00e4   228  LCMptr
  $00e8   232  MicrosPerLine
  $00ea   234  MinDisplayColumn
  $00ec   236  ChipRevBits0
! $00ed   237  crb_reserved[0]
  $00f2   242  monitor_id
  $00f4   244  hedley[0]
  $0114   276  hedley_sprites[0]
  $0134   308  hedley_sprites1[0]
  $0154   340  hedley_count
  $0156   342  hedley_flags
  $0158   344  hedley_tmp
! $015a   346  hash_table
  $015e   350  current_tot_rows
  $0160   352  current_tot_cclks
  $0162   354  hedley_hint
  $0163   355  hedley_hint2
  $0164   356  nreserved[0]
  $0174   372  a2024_sync_raster
  $0178   376  control_delta_pal
  $017a   378  control_delta_ntsc
  $017c   380  current_monitor
  $0180   384  MonitorList
! $018e   398  default_monitor
! $0192   402  MonitorListSemaphore
! $0196   406  DisplayInfoDataBase
! $019a   410  ActiViewCprSemaphore
! $019e   414  UtilityBase
! $01a2   418  ExecBase
Hook:
  $0014    20  sizeof(Hook)
  $0000     0  h_MinNode
  $0008     8  h_Entry
  $000c    12  h_SubEntry
  $0010    16  h_Data
IBox:
  $0008     8  sizeof(IBox)
  $0000     0  Left
  $0002     2  Top
  $0004     4  Width
  $0006     6  Height
IEPointerPixel:
  $0008     8  sizeof(IEPointerPixel)
  $0000     0  iepp_Screen
  $0004     4  iepp_Position
  $0004     4  iepp_Position.X
  $0006     6  iepp_Position.Y
IEPointerTablet:
  $000a    10  sizeof(IEPointerTablet)
  $0000     0  iept_Range
  $0000     0  iept_Range.X
  $0002     2  iept_Range.Y
  $0004     4  iept_Value
  $0004     4  iept_Value.X
  $0006     6  iept_Value.Y
  $0008     8  iept_Pressure
IFFHandle:
  $000c    12  sizeof(IFFHandle)
  $0000     0  iff_Stream
  $0004     4  iff_Flags
  $0008     8  iff_Depth
IFFStreamCmd:
  $000c    12  sizeof(IFFStreamCmd)
  $0000     0  sc_Command
  $0004     4  sc_Buf
  $0008     8  sc_NBytes
IOAudio:
  $0044    68  sizeof(IOAudio)
  $0000     0  ioa_Request
  $0020    32  ioa_AllocKey
! $0022    34  ioa_Data
! $0026    38  ioa_Length
  $002a    42  ioa_Period
  $002c    44  ioa_Volume
  $002e    46  ioa_Cycles
  $0030    48  ioa_WriteMsg
IOClipReq:
  $0034    52  sizeof(IOClipReq)
  $0000     0  io_Message
  $0014    20  io_Device
  $0018    24  io_Unit
  $001c    28  io_Command
  $001e    30  io_Flags
  $001f    31  io_Error
  $0020    32  io_Actual
  $0024    36  io_Length
  $0028    40  io_Data
  $002c    44  io_Offset
  $0030    48  io_ClipID
IODRPReq:
  $003e    62  sizeof(IODRPReq)
  $0000     0  io_Message
  $0014    20  io_Device
  $0018    24  io_Unit
  $001c    28  io_Command
  $001e    30  io_Flags
  $001f    31  io_Error
  $0020    32  io_RastPort
  $0024    36  io_ColorMap
  $0028    40  io_Modes
  $002c    44  io_SrcX
  $002e    46  io_SrcY
  $0030    48  io_SrcWidth
  $0032    50  io_SrcHeight
  $0034    52  io_DestCols
  $0038    56  io_DestRows
  $003c    60  io_Special
IOExtPar:
  $003e    62  sizeof(IOExtPar)
  $0000     0  IOPar
  $0030    48  io_PExtFlags
  $0034    52  io_Status
  $0035    53  io_ParFlags
! $0036    54  io_PTermArray
IOExtSer:
  $0052    82  sizeof(IOExtSer)
  $0000     0  IOSer
  $0030    48  io_CtlChar
  $0034    52  io_RBufLen
  $0038    56  io_ExtFlags
  $003c    60  io_Baud
  $0040    64  io_BrkTime
  $0044    68  io_TermArray
  $004c    76  io_ReadLen
  $004d    77  io_WriteLen
  $004e    78  io_StopBits
  $004f    79  io_SerFlags
  $0050    80  io_Status
IOExtTD:
  $0038    56  sizeof(IOExtTD)
  $0000     0  iotd_Req
  $0030    48  iotd_Count
  $0034    52  iotd_SecLabel
IOPArray:
  $0008     8  sizeof(IOPArray)
  $0000     0  PTermArray0
  $0004     4  PTermArray1
IOPrtCmdReq:
  $0026    38  sizeof(IOPrtCmdReq)
  $0000     0  io_Message
  $0014    20  io_Device
  $0018    24  io_Unit
  $001c    28  io_Command
  $001e    30  io_Flags
  $001f    31  io_Error
  $0020    32  io_PrtCommand
  $0022    34  io_Parm0
  $0023    35  io_Parm1
  $0024    36  io_Parm2
  $0025    37  io_Parm3
IORequest:
  $0020    32  sizeof(IORequest)
  $0000     0  io_Message
  $0014    20  io_Device
  $0018    24  io_Unit
  $001c    28  io_Command
  $001e    30  io_Flags
  $001f    31  io_Error
IOStdReq:
  $0030    48  sizeof(IOStdReq)
  $0000     0  io_Message
  $0014    20  io_Device
  $0018    24  io_Unit
  $001c    28  io_Command
  $001e    30  io_Flags
  $001f    31  io_Error
  $0020    32  io_Actual
  $0024    36  io_Length
  $0028    40  io_Data
  $002c    44  io_Offset
IOTArray:
  $0008     8  sizeof(IOTArray)
  $0000     0  TermArray0
  $0004     4  TermArray1
Image:
  $0014    20  sizeof(Image)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  Width
  $0006     6  Height
  $0008     8  Depth
! $000a    10  ImageData
  $000e    14  PlanePick
  $000f    15  PlaneOnOff
  $0010    16  NextImage
InfoData:
  $0024    36  sizeof(InfoData)
  $0000     0  id_NumSoftErrors
  $0004     4  id_UnitNumber
  $0008     8  id_DiskState
  $000c    12  id_NumBlocks
  $0010    16  id_NumBlocksUsed
  $0014    20  id_BytesPerBlock
  $0018    24  id_DiskType
  $001c    28  id_VolumeNode
  $0020    32  id_InUse
InputEvent:
  $0016    22  sizeof(InputEvent)
  $0000     0  ie_NextEvent
  $0004     4  ie_Class
  $0005     5  ie_SubClass
  $0006     6  ie_Code
  $0008     8  ie_Qualifier
  $000a    10  ie_position
  $000a    10  ie_position.ie_xy
  $000a    10  ie_position.ie_xy.ie_x
  $000c    12  ie_position.ie_xy.ie_y
  $000a    10  ie_position.ie_addr
  $000a    10  ie_position.ie_dead
  $000a    10
     ie_position.ie_dead.ie_prev1DownCode
  $000b    11
     ie_position.ie_dead.ie_prev1DownQual
  $000c    12
     ie_position.ie_dead.ie_prev2DownCode
  $000d    13
     ie_position.ie_dead.ie_prev2DownQual
! $000e    14  ie_TimeStamp
InputXpression:
  $000c    12  sizeof(InputXpression)
  $0000     0  ix_Version
  $0001     1  ix_Class
  $0002     2  ix_Code
  $0004     4  ix_CodeMask
  $0006     6  ix_Qualifier
  $0008     8  ix_QualMask
  $000a    10  ix_QualSame
IntVector:
  $000c    12  sizeof(IntVector)
  $0000     0  iv_Data
  $0004     4  iv_Code
  $0008     8  iv_Node
Interrupt:
  $0016    22  sizeof(Interrupt)
  $0000     0  is_Node
! $000e    14  is_Data
! $0012    18  is_Code
IntuiMessage:
  $0034    52  sizeof(IntuiMessage)
  $0000     0  ExecMessage
  $0014    20  Class
  $0018    24  Code
  $001a    26  Qualifier
  $001c    28  IAddress
  $0020    32  MouseX
  $0022    34  MouseY
  $0024    36  Seconds
  $0028    40  Micros
  $002c    44  IDCMPWindow
  $0030    48  SpecialLink
IntuiText:
  $0014    20  sizeof(IntuiText)
  $0000     0  FrontPen
  $0001     1  BackPen
  $0002     2  DrawMode
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  ITextFont
  $000c    12  IText
  $0010    16  NextText
IntuitionBase:
  $0050    80  sizeof(IntuitionBase)
  $0000     0  LibNode
! $0022    34  ViewLord
  $0034    52  ActiveWindow
  $0038    56  ActiveScreen
  $003c    60  FirstScreen
  $0040    64  Flags
  $0044    68  MouseY
  $0046    70  MouseX
  $0048    72  Seconds
  $004c    76  Micros
IoBuff:
  $0100   256  sizeof(IoBuff)
  $0000     0  iobNode
  $0020    32  iobRpt
  $0024    36  iobRct
  $0028    40  iobDFH
  $002c    44  iobLock
  $0030    48  iobBct
  $0034    52  iobArea[0]
Isrvstr:
  $001e    30  sizeof(Isrvstr)
  $0000     0  is_Node
! $000e    14  Iptr
! $0012    18  code
! $0016    22  ccode
! $001a    26  Carg
KeyMap:
  $0020    32  sizeof(KeyMap)
  $0000     0  km_LoKeyMapTypes
  $0004     4  km_LoKeyMap
  $0008     8  km_LoCapsable
  $000c    12  km_LoRepeatable
  $0010    16  km_HiKeyMapTypes
  $0014    20  km_HiKeyMap
  $0018    24  km_HiCapsable
  $001c    28  km_HiRepeatable
KeyMapNode:
  $002e    46  sizeof(KeyMapNode)
  $0000     0  kn_Node
! $000e    14  kn_KeyMap
KeyMapResource:
  $001c    28  sizeof(KeyMapResource)
  $0000     0  kr_Node
! $000e    14  kr_List
Layer:
  $00a0   160  sizeof(Layer)
  $0000     0  front
  $0004     4  back
  $0008     8  ClipRect
  $000c    12  rp
  $0010    16  bounds
  $0018    24  reserved[0]
  $001c    28  priority
  $001e    30  Flags
  $0020    32  SuperBitMap
  $0024    36  SuperClipRect
  $0028    40  Window
  $002c    44  Scroll_X
  $002e    46  Scroll_Y
  $0030    48  cr
  $0034    52  cr2
  $0038    56  crnew
  $003c    60  SuperSaveClipRects
  $0040    64  _cliprects
  $0044    68  LayerInfo
  $0048    72  Lock
! $0076   118  BackFill
! $007a   122  reserved1
! $007e   126  ClipRegion
! $0082   130  saveClipRects
  $0086   134  Width
  $0088   136  Height
! $008a   138  reserved2[0]
  $009c   156  DamageList
Layer_Info:
  $0066   102  sizeof(Layer_Info)
  $0000     0  top_layer
  $0004     4  check_lp
  $0008     8  obs
  $000c    12  FreeClipRects
  $0018    24  Lock
! $0046    70  gs_Head
  $0054    84  longreserved
  $0058    88  Flags
  $005a    90  fatten_count
  $005b    91  LockLayersCount
  $005c    92  LayerInfo_extra_size
! $005e    94  blitbuff
! $0062    98  LayerInfo_extra
Library:
  $0022    34  sizeof(Library)
  $0000     0  lib_Node
  $000e    14  lib_Flags
  $000f    15  lib_pad
  $0010    16  lib_NegSize
  $0012    18  lib_PosSize
  $0014    20  lib_Version
  $0016    22  lib_Revision
  $0018    24  lib_IdString
  $001c    28  lib_Sum
  $0020    32  lib_OpenCnt
List:
  $000e    14  sizeof(List)
  $0000     0  lh_Head
  $0004     4  lh_Tail
  $0008     8  lh_TailPred
  $000c    12  lh_Type
  $000d    13  l_pad
LoadSegBlock:
  $0200   512  sizeof(LoadSegBlock)
  $0000     0  lsb_ID
  $0004     4  lsb_SummedLongs
  $0008     8  lsb_ChkSum
  $000c    12  lsb_HostID
  $0010    16  lsb_Next
  $0014    20  lsb_LoadData[0]
LocalContextItem:
  $0014    20  sizeof(LocalContextItem)
  $0000     0  lci_Node
  $0008     8  lci_ID
  $000c    12  lci_Type
  $0010    16  lci_Ident
LocalVar:
  $0018    24  sizeof(LocalVar)
  $0000     0  lv_Node
  $000e    14  lv_Flags
  $0010    16  lv_Value
  $0014    20  lv_Len
MathIEEEBase:
  $003c    60  sizeof(MathIEEEBase)
  $0000     0  MathIEEEBase_LibNode
! $0022    34  MathIEEEBase_reserved[0]
  $0034    52  MathIEEEBase_TaskOpenLib
  $0038    56  MathIEEEBase_TaskCloseLib
MathIEEEResource:
  $002c    44  sizeof(MathIEEEResource)
  $0000     0  MathIEEEResource_Node
  $000e    14  MathIEEEResource_Flags
  $0010    16  MathIEEEResource_BaseAddr
  $0014    20
       MathIEEEResource_DblBasInit
  $0018    24
       MathIEEEResource_DblTransInit
  $001c    28
       MathIEEEResource_SglBasInit
  $0020    32
       MathIEEEResource_SglTransInit
  $0024    36
       MathIEEEResource_ExtBasInit
  $0028    40
       MathIEEEResource_ExtTransInit
MemChunk:
  $0008     8  sizeof(MemChunk)
  $0000     0  mc_Next
  $0004     4  mc_Bytes
MemEntry:
  $0008     8  sizeof(MemEntry)
  $0000     0  me_Un
  $0000     0  me_Un.meu_Reqs
  $0000     0  me_Un.meu_Addr
  $0004     4  me_Length
MemHeader:
  $0020    32  sizeof(MemHeader)
  $0000     0  mh_Node
  $000e    14  mh_Attributes
  $0010    16  mh_First
  $0014    20  mh_Lower
  $0018    24  mh_Upper
  $001c    28  mh_Free
MemList:
  $0018    24  sizeof(MemList)
  $0000     0  ml_Node
  $000e    14  ml_NumEntries
  $0010    16  ml_ME[0]
Menu:
  $001e    30  sizeof(Menu)
  $0000     0  NextMenu
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  Width
  $000a    10  Height
  $000c    12  Flags
! $000e    14  MenuName
! $0012    18  FirstItem
  $0016    22  JazzX
  $0018    24  JazzY
  $001a    26  BeatX
  $001c    28  BeatY
MenuItem:
  $0022    34  sizeof(MenuItem)
  $0000     0  NextItem
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  Width
  $000a    10  Height
  $000c    12  Flags
! $000e    14  MutualExclude
! $0012    18  ItemFill
! $0016    22  SelectFill
  $001a    26  Command
  $001c    28  SubItem
  $0020    32  NextSelect
Message:
  $0014    20  sizeof(Message)
  $0000     0  mn_Node
! $000e    14  mn_ReplyPort
  $0012    18  mn_Length
MinList:
  $000c    12  sizeof(MinList)
  $0000     0  mlh_Head
  $0004     4  mlh_Tail
  $0008     8  mlh_TailPred
MinNode:
  $0008     8  sizeof(MinNode)
  $0000     0  mln_Succ
  $0004     4  mln_Pred
MonitorInfo:
  $0058    88  sizeof(MonitorInfo)
  $0000     0  Header
  $0010    16  Mspc
  $0014    20  ViewPosition
  $0018    24  ViewResolution
  $001c    28  ViewPositionRange
  $0024    36  TotalRows
  $0026    38  TotalColorClocks
  $0028    40  MinRow
  $002a    42  Compatibility
  $002c    44  pad[0]
  $0050    80  reserved[0]
MonitorSpec:
  $009c   156  sizeof(MonitorSpec)
  $0000     0  ms_Node
  $0018    24  ms_Flags
! $001a    26  ratioh
! $001e    30  ratiov
  $0022    34  total_rows
  $0024    36  total_colorclocks
  $0026    38  DeniseMaxDisplayColumn
  $0028    40  BeamCon0
  $002a    42  min_row
  $002c    44  ms_Special
  $0030    48  ms_OpenCount
! $0032    50  ms_transform
! $0036    54  ms_translate
! $003a    58  ms_scale
  $003e    62  ms_xoffset
  $0040    64  ms_yoffset
! $0042    66  ms_LegalView
! $004a    74  ms_maxoscan
! $004e    78  ms_videoscan
  $0052    82  DeniseMinDisplayColumn
  $0054    84  DisplayCompatible
  $0058    88  DisplayInfoDataBase
! $0066   102
      DisplayInfoDataBaseSemaphore
  $0094   148  ms_reserved00
  $0098   152  ms_reserved01
MsgPort:
  $0022    34  sizeof(MsgPort)
  $0000     0  mp_Node
  $000e    14  mp_Flags
  $000f    15  mp_SigBit
  $0010    16  mp_SigTask
  $0014    20  mp_MsgList
NameInfo:
  $0038    56  sizeof(NameInfo)
  $0000     0  Header
  $0010    16  Name[0]
  $0030    48  reserved[0]
NewBroker:
  $001a    26  sizeof(NewBroker)
  $0000     0  nb_Version
! $0002     2  nb_Name
! $0006     6  nb_Title
! $000a    10  nb_Descr
  $000e    14  nb_Unique
  $0010    16  nb_Flags
  $0012    18  nb_Pri
  $0014    20  nb_Port
  $0018    24  nb_ReservedChannel
NewGadget:
  $001e    30  sizeof(NewGadget)
  $0000     0  ng_LeftEdge
  $0002     2  ng_TopEdge
  $0004     4  ng_Width
  $0006     6  ng_Height
  $0008     8  ng_GadgetText
  $000c    12  ng_TextAttr
  $0010    16  ng_GadgetID
! $0012    18  ng_Flags
! $0016    22  ng_VisualInfo
! $001a    26  ng_UserData
NewMenu:
  $0014    20  sizeof(NewMenu)
  $0000     0  nm_Type
! $0002     2  nm_Label
! $0006     6  nm_CommKey
  $000a    10  nm_Flags
  $000c    12  nm_MutualExclude
  $0010    16  nm_UserData
NewScreen:
  $0020    32  sizeof(NewScreen)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  Width
  $0006     6  Height
  $0008     8  Depth
  $000a    10  DetailPen
  $000b    11  BlockPen
  $000c    12  ViewModes
  $000e    14  Type
  $0010    16  Font
  $0014    20  DefaultTitle
  $0018    24  Gadgets
  $001c    28  CustomBitMap
NewWindow:
  $0030    48  sizeof(NewWindow)
  $0000     0  LeftEdge
  $0002     2  TopEdge
  $0004     4  Width
  $0006     6  Height
  $0008     8  DetailPen
  $0009     9  BlockPen
! $000a    10  IDCMPFlags
! $000e    14  Flags
! $0012    18  FirstGadget
! $0016    22  CheckMark
! $001a    26  Title
! $001e    30  Screen
! $0022    34  BitMap
  $0026    38  MinWidth
  $0028    40  MinHeight
  $002a    42  MaxWidth
  $002c    44  MaxHeight
  $002e    46  Type
NexxStr:
  $0010    16  sizeof(NexxStr)
  $0000     0  ns_Ivalue
  $0004     4  ns_Length
  $0006     6  ns_Flags
  $0007     7  ns_Hash
  $0008     8  ns_Buff[0]
Node:
  $000e    14  sizeof(Node)
  $0000     0  ln_Succ
  $0004     4  ln_Pred
  $0008     8  ln_Type
  $0009     9  ln_Pri
! $000a    10  ln_Name
NotifyMessage:
  $0026    38  sizeof(NotifyMessage)
  $0000     0  nm_ExecMessage
  $0014    20  nm_Class
  $0018    24  nm_Code
! $001a    26  nm_NReq
! $001e    30  nm_DoNotTouch
! $0022    34  nm_DoNotTouch2
NotifyRequest:
  $0030    48  sizeof(NotifyRequest)
  $0000     0  nr_Name
  $0004     4  nr_FullName
  $0008     8  nr_UserData
  $000c    12  nr_Flags
  $0010    16  nr_stuff
  $0010    16  nr_stuff.nr_Msg
  $0010    16  nr_stuff.nr_Msg.nr_Port
  $0010    16  nr_stuff.nr_Signal
  $0010    16  nr_stuff.nr_Signal.nr_Task
  $0014    20
      nr_stuff.nr_Signal.nr_SignalNum
  $0015    21
      nr_stuff.nr_Signal.nr_pad[0]
  $0018    24  nr_Reserved[0]
  $0028    40  nr_MsgCount
  $002c    44  nr_Handler
OldDrawerData:
  $0038    56  sizeof(OldDrawerData)
  $0000     0  dd_NewWindow
  $0030    48  dd_CurrentX
  $0034    52  dd_CurrentY
PGX:
  $0010    16  sizeof(PGX)
  $0000     0  pgx_Container
  $0008     8  pgx_NewKnob
PartitionBlock:
  $0100   256  sizeof(PartitionBlock)
  $0000     0  pb_ID
  $0004     4  pb_SummedLongs
  $0008     8  pb_ChkSum
  $000c    12  pb_HostID
  $0010    16  pb_Next
  $0014    20  pb_Flags
  $0018    24  pb_Reserved1[0]
  $0020    32  pb_DevFlags
  $0024    36  pb_DriveName[0]
  $0044    68  pb_Reserved2[0]
  $0080   128  pb_Environment[0]
  $00c4   196  pb_EReserved[0]
Preferences:
  $00e8   232  sizeof(Preferences)
  $0000     0  FontHeight
  $0001     1  PrinterPort
  $0002     2  BaudRate
  $0004     4  KeyRptSpeed
  $000c    12  KeyRptDelay
  $0014    20  DoubleClick
  $001c    28  PointerMatrix[0]
  $0064   100  XOffset
  $0065   101  YOffset
  $0066   102  color17
  $0068   104  color18
  $006a   106  color19
  $006c   108  PointerTicks
  $006e   110  color0
  $0070   112  color1
  $0072   114  color2
  $0074   116  color3
  $0076   118  ViewXOffset
  $0077   119  ViewYOffset
  $0078   120  ViewInitX
  $007a   122  ViewInitY
  $007c   124  EnableCLI
  $007e   126  PrinterType
  $0080   128  PrinterFilename[0]
  $009e   158  PrintPitch
  $00a0   160  PrintQuality
  $00a2   162  PrintSpacing
  $00a4   164  PrintLeftMargin
  $00a6   166  PrintRightMargin
  $00a8   168  PrintImage
  $00aa   170  PrintAspect
  $00ac   172  PrintShade
  $00ae   174  PrintThreshold
  $00b0   176  PaperSize
  $00b2   178  PaperLength
  $00b4   180  PaperType
  $00b6   182  SerRWBits
  $00b7   183  SerStopBuf
  $00b8   184  SerParShk
  $00b9   185  LaceWB
! $00ba   186  WorkName[0]
  $00d8   216  RowSizeChange
  $00d9   217  ColumnSizeChange
  $00da   218  PrintFlags
  $00dc   220  PrintMaxWidth
  $00de   222  PrintMaxHeight
  $00e0   224  PrintDensity
  $00e1   225  PrintXOffset
  $00e2   226  wb_Width
  $00e4   228  wb_Height
  $00e6   230  wb_Depth
  $00e7   231  ext_size
PrinterData:
  $1aa2  6818  sizeof(PrinterData)
  $0000     0  pd_Device
  $0034    52  pd_Unit
! $0056    86  pd_PrinterSegment
  $005a    90  pd_PrinterType
  $005c    92  pd_SegmentData
  $0060    96  pd_PrintBuf
  $0064   100  pd_PWrite
  $0068   104  pd_PBothReady
  $006c   108  pd_ior0
  $006c   108  pd_ior0.pd_p0
  $006c   108  pd_ior0.pd_s0
  $00be   190  pd_ior1
  $00be   190  pd_ior1.pd_p1
! $00be   190  pd_ior1.pd_s1
  $0110   272  pd_TIOR
  $0138   312  pd_IORPort
! $015a   346  pd_TC
! $01b6   438  pd_OldStk[0]
  $09b6  2486  pd_Flags
  $09b7  2487  pd_pad
  $09b8  2488  pd_Preferences
  $0aa0  2720  pd_PWaitEnabled
  $0aa1  2721  pd_Flags1
! $0aa2  2722  pd_Stk[0]
PrinterExtendedData:
  $0042    66  sizeof(
```c
      PrinterExtendedData)
```
  $0000     0  ped_PrinterName
  $0004     4  ped_Init
  $0008     8  ped_Expunge
  $000c    12  ped_Open
  $0010    16  ped_Close
  $0014    20  ped_PrinterClass
  $0015    21  ped_ColorClass
  $0016    22  ped_MaxColumns
  $0017    23  ped_NumCharSets
  $0018    24  ped_NumRows
! $001a    26  ped_MaxXDots
! $001e    30  ped_MaxYDots
  $0022    34  ped_XDotsInch
  $0024    36  ped_YDotsInch
! $0026    38  ped_Commands
! $002a    42  ped_DoSpecial
! $002e    46  ped_Render
! $0032    50  ped_TimeoutSecs
! $0036    54  ped_8BitChars
! $003a    58  ped_PrintMode
! $003e    62  ped_ConvFunc
PrinterSegment:
  $004e    78  sizeof(PrinterSegment)
  $0000     0  ps_NextSegment
  $0004     4  ps_runAlert
  $0008     8  ps_Version
  $000a    10  ps_Revision
  $000c    12  ps_PED
Process:
  $00e4   228  sizeof(Process)
  $0000     0  pr_Task
  $005c    92  pr_MsgPort
  $007e   126  pr_Pad
  $0080   128  pr_SegList
  $0084   132  pr_StackSize
  $0088   136  pr_GlobVec
  $008c   140  pr_TaskNum
  $0090   144  pr_StackBase
  $0094   148  pr_Result2
  $0098   152  pr_CurrentDir
  $009c   156  pr_CIS
  $00a0   160  pr_COS
  $00a4   164  pr_ConsoleTask
  $00a8   168  pr_FileSystemTask
  $00ac   172  pr_CLI
  $00b0   176  pr_ReturnAddr
  $00b4   180  pr_PktWait
  $00b8   184  pr_WindowPtr
  $00bc   188  pr_HomeDir
  $00c0   192  pr_Flags
  $00c4   196  pr_ExitCode
  $00c8   200  pr_ExitData
  $00cc   204  pr_Arguments
  $00d0   208  pr_LocalVars
  $00dc   220  pr_ShellPrivate
  $00e0   224  pr_CES
PropInfo:
  $0016    22  sizeof(PropInfo)
  $0000     0  Flags
  $0002     2  HorizPot
  $0004     4  VertPot
  $0006     6  HorizBody
  $0008     8  VertBody
  $000a    10  CWidth
  $000c    12  CHeight
  $000e    14  HPotRes
  $0010    16  VPotRes
  $0012    18  LeftBorder
  $0014    20  TopBorder
PrtInfo:
  $0072   114  sizeof(PrtInfo)
  $0000     0  pi_render
  $0004     4  pi_rp
  $0008     8  pi_temprp
  $000c    12  pi_RowBuf
  $0010    16  pi_HamBuf
  $0014    20  pi_ColorMap
  $0018    24  pi_ColorInt
  $001c    28  pi_HamInt
  $0020    32  pi_Dest1Int
  $0024    36  pi_Dest2Int
  $0028    40  pi_ScaleX
  $002c    44  pi_ScaleXAlt
  $0030    48  pi_dmatrix
  $0034    52  pi_TopBuf
  $0038    56  pi_BotBuf
  $003c    60  pi_RowBufSize
  $003e    62  pi_HamBufSize
  $0040    64  pi_ColorMapSize
  $0042    66  pi_ColorIntSize
  $0044    68  pi_HamIntSize
  $0046    70  pi_Dest1IntSize
  $0048    72  pi_Dest2IntSize
  $004a    74  pi_ScaleXSize
  $004c    76  pi_ScaleXAltSize
  $004e    78  pi_PrefsFlags
  $0050    80  pi_special
  $0054    84  pi_xstart
  $0056    86  pi_ystart
  $0058    88  pi_width
  $005a    90  pi_height
  $005c    92  pi_pc
  $0060    96  pi_pr
  $0064   100  pi_ymult
  $0066   102  pi_ymod
  $0068   104  pi_ety
  $006a   106  pi_xpos
  $006c   108  pi_threshold
  $006e   110  pi_tempwidth
  $0070   112  pi_flags
PubScreenNode:
  $001e    30  sizeof(PubScreenNode)
  $0000     0  psn_Node
! $000e    14  psn_Screen
  $0012    18  psn_Flags
  $0014    20  psn_Size
  $0016    22  psn_VisitorCount
  $0018    24  psn_SigTask
  $001c    28  psn_SigBit
QueryHeader:
  $0010    16  sizeof(QueryHeader)
  $0000     0  StructID
  $0004     4  DisplayID
  $0008     8  SkipID
  $000c    12  Length
RDArgs:
  $0020    32  sizeof(RDArgs)
  $0000     0  RDA_Source
  $000c    12  RDA_DAList
  $0010    16  RDA_Buffer
  $0014    20  RDA_BufSiz
  $0018    24  RDA_ExtHelp
  $001c    28  RDA_Flags
RasInfo:
  $000c    12  sizeof(RasInfo)
  $0000     0  Next
  $0004     4  BitMap
  $0008     8  RxOffset
  $000a    10  RyOffset
RastPort:
  $0064   100  sizeof(RastPort)
  $0000     0  Layer
  $0004     4  BitMap
  $0008     8  AreaPtrn
  $000c    12  TmpRas
  $0010    16  AreaInfo
  $0014    20  GelsInfo
  $0018    24  Mask
  $0019    25  FgPen
  $001a    26  BgPen
  $001b    27  AOlPen
  $001c    28  DrawMode
  $001d    29  AreaPtSz
  $001e    30  linpatcnt
  $001f    31  dummy
  $0020    32  Flags
  $0022    34  LinePtrn
  $0024    36  cp_x
  $0026    38  cp_y
  $0028    40  minterms[0]
  $0030    48  PenWidth
  $0032    50  PenHeight
  $0034    52  Font
  $0038    56  AlgoStyle
  $0039    57  TxFlags
  $003a    58  TxHeight
  $003c    60  TxWidth
  $003e    62  TxBaseline
  $0040    64  TxSpacing
! $0042    66  RP_User
! $0046    70  longreserved[0]
! $004e    78  wordreserved[0]
  $005c    92  reserved[0]
RecordLock:
  $0010    16  sizeof(RecordLock)
  $0000     0  rec_FH
  $0004     4  rec_Offset
  $0008     8  rec_Length
  $000c    12  rec_Mode
Rect32:
  $0010    16  sizeof(Rect32)
  $0000     0  MinX
  $0004     4  MinY
  $0008     8  MaxX
  $000c    12  MaxY
Rectangle:
  $0008     8  sizeof(Rectangle)
  $0000     0  MinX
  $0002     2  MinY
  $0004     4  MaxX
  $0006     6  MaxY
Region:
  $000c    12  sizeof(Region)
  $0000     0  bounds
  $0008     8  RegionRectangle
RegionRectangle:
  $0010    16  sizeof(RegionRectangle)
  $0000     0  Next
  $0004     4  Prev
  $0008     8  bounds
Remember:
  $000c    12  sizeof(Remember)
  $0000     0  NextRemember
  $0004     4  RememberSize
  $0008     8  Memory
Requester:
  $0070   112  sizeof(Requester)
  $0000     0  OlderRequest
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  Width
  $000a    10  Height
  $000c    12  RelLeft
  $000e    14  RelTop
  $0010    16  ReqGadget
  $0014    20  ReqBorder
  $0018    24  ReqText
  $001c    28  Flags
  $001e    30  BackFill
  $0020    32  ReqLayer
  $0024    36  ReqPad1[0]
  $0044    68  ImageBMap
  $0048    72  RWindow
  $004c    76  ReqImage
  $0050    80  ReqPad2[0]
Resident:
  $001a    26  sizeof(Resident)
  $0000     0  rt_MatchWord
! $0002     2  rt_MatchTag
! $0006     6  rt_EndSkip
  $000a    10  rt_Flags
  $000b    11  rt_Version
  $000c    12  rt_Type
  $000d    13  rt_Pri
! $000e    14  rt_Name
! $0012    18  rt_IdString
! $0016    22  rt_Init
RexxArg:
  $0010    16  sizeof(RexxArg)
  $0000     0  ra_Size
  $0004     4  ra_Length
  $0006     6  ra_Flags
  $0007     7  ra_Hash
  $0008     8  ra_Buff[0]
RexxMsg:
  $0080   128  sizeof(RexxMsg)
  $0000     0  rm_Node
  $0014    20  rm_TaskBlock
  $0018    24  rm_LibBase
  $001c    28  rm_Action
  $0020    32  rm_Result1
  $0024    36  rm_Result2
  $0028    40  rm_Args[0]
  $0068   104  rm_PassPort
  $006c   108  rm_CommAddr
  $0070   112  rm_FileExt
  $0074   116  rm_Stdin
  $0078   120  rm_Stdout
  $007c   124  rm_avail
RexxMsgPort:
  $0050    80  sizeof(RexxMsgPort)
  $0000     0  rmp_Node
  $0020    32  rmp_Port
! $0042    66  rmp_ReplyList
RexxRsrc:
  $0020    32  sizeof(RexxRsrc)
  $0000     0  rr_Node
  $000e    14  rr_Func
  $0010    16  rr_Base
  $0014    20  rr_Size
  $0018    24  rr_Arg1
  $001c    28  rr_Arg2
RexxTask:
  $014a   330  sizeof(RexxTask)
  $0000     0  rt_Global[0]
  $00c8   200  rt_MsgPort
  $00ea   234  rt_Flags
  $00eb   235  rt_SigBit
  $00ec   236  rt_ClientID
  $00f0   240  rt_MsgPkt
  $00f4   244  rt_TaskID
  $00f8   248  rt_RexxPort
  $00fc   252  rt_ErrTrap
  $0100   256  rt_StackPtr
  $0104   260  rt_Header1
! $0112   274  rt_Header2
  $0120   288  rt_Header3
! $012e   302  rt_Header4
  $013c   316  rt_Header5
RigidDiskBlock:
  $0100   256  sizeof(RigidDiskBlock)
  $0000     0  rdb_ID
  $0004     4  rdb_SummedLongs
  $0008     8  rdb_ChkSum
  $000c    12  rdb_HostID
  $0010    16  rdb_BlockBytes
  $0014    20  rdb_Flags
  $0018    24  rdb_BadBlockList
  $001c    28  rdb_PartitionList
  $0020    32  rdb_FileSysHeaderList
  $0024    36  rdb_DriveInit
  $0028    40  rdb_Reserved1[0]
  $0040    64  rdb_Cylinders
  $0044    68  rdb_Sectors
  $0048    72  rdb_Heads
  $004c    76  rdb_Interleave
  $0050    80  rdb_Park
  $0054    84  rdb_Reserved2[0]
  $0060    96  rdb_WritePreComp
  $0064   100  rdb_ReducedWrite
  $0068   104  rdb_StepRate
  $006c   108  rdb_Reserved3[0]
  $0080   128  rdb_RDBBlocksLo
  $0084   132  rdb_RDBBlocksHi
  $0088   136  rdb_LoCylinder
  $008c   140  rdb_HiCylinder
  $0090   144  rdb_CylBlocks
  $0094   148  rdb_AutoParkSeconds
  $0098   152  rdb_Reserved4[0]
  $00a0   160  rdb_DiskVendor[0]
  $00a8   168  rdb_DiskProduct[0]
  $00b8   184  rdb_DiskRevision[0]
  $00bc   188  rdb_ControllerVendor[0]
  $00c4   196  rdb_ControllerProduct[0]
  $00d4   212  rdb_ControllerRevision[0]
  $00d8   216  rdb_Reserved5[0]
RootNode:
  $0038    56  sizeof(RootNode)
  $0000     0  rn_TaskArray
  $0004     4  rn_ConsoleSegment
  $0008     8  rn_Time
  $0014    20  rn_RestartSeg
  $0018    24  rn_Info
  $001c    28  rn_FileHandlerSegment
  $0020    32  rn_CliList
  $002c    44  rn_BootProc
  $0030    48  rn_ShellSegment
  $0034    52  rn_Flags
RxsLib:
  $00fc   252  sizeof(RxsLib)
  $0000     0  rl_Node
  $0022    34  rl_Flags
  $0023    35  rl_Shadow
  $0024    36  rl_SysBase
  $0028    40  rl_DOSBase
  $002c    44  rl_IeeeDPBase
  $0030    48  rl_SegList
  $0034    52  rl_NIL
  $0038    56  rl_Chunk
  $003c    60  rl_MaxNest
  $0040    64  rl_NULL
  $0044    68  rl_FALSE
  $0048    72  rl_TRUE
  $004c    76  rl_REXX
  $0050    80  rl_COMMAND
  $0054    84  rl_STDIN
  $0058    88  rl_STDOUT
  $005c    92  rl_STDERR
  $0060    96  rl_Version
  $0064   100  rl_TaskName
  $0068   104  rl_TaskPri
  $006c   108  rl_TaskSeg
  $0070   112  rl_StackSize
  $0074   116  rl_RexxDir
  $0078   120  rl_CTABLE
  $007c   124  rl_Notice
  $0080   128  rl_RexxPort
  $00a2   162  rl_ReadLock
  $00a4   164  rl_TraceFH
  $00a8   168  rl_TaskList
  $00b6   182  rl_NumTask
  $00b8   184  rl_LibList
  $00c6   198  rl_NumLib
  $00c8   200  rl_ClipList
  $00d6   214  rl_NumClip
  $00d8   216  rl_MsgList
  $00e6   230  rl_NumMsg
  $00e8   232  rl_PgmList
  $00f6   246  rl_NumPgm
  $00f8   248  rl_TraceCnt
  $00fa   250  rl_avail
SCSICmd:
  $001e    30  sizeof(SCSICmd)
  $0000     0  scsi_Data
  $0004     4  scsi_Length
  $0008     8  scsi_Actual
  $000c    12  scsi_Command
  $0010    16  scsi_CmdLength
  $0012    18  scsi_CmdActual
  $0014    20  scsi_Flags
  $0015    21  scsi_Status
! $0016    22  scsi_SenseData
  $001a    26  scsi_SenseLength
  $001c    28  scsi_SenseActual
SGWork:
  $002c    44  sizeof(SGWork)
  $0000     0  Gadget
  $0004     4  StringInfo
  $0008     8  WorkBuffer
  $000c    12  PrevBuffer
  $0010    16  Modes
  $0014    20  IEvent
  $0018    24  Code
  $001a    26  BufferPos
  $001c    28  NumChars
! $001e    30  Actions
! $0022    34  LongInt
! $0026    38  GadgetInfo
  $002a    42  EditOp
SatisfyMsg:
  $001a    26  sizeof(SatisfyMsg)
  $0000     0  sm_Msg
  $0014    20  sm_Unit
! $0016    22  sm_ClipID
Screen:
  $015a   346  sizeof(Screen)
  $0000     0  NextScreen
  $0004     4  FirstWindow
  $0008     8  LeftEdge
  $000a    10  TopEdge
  $000c    12  Width
  $000e    14  Height
  $0010    16  MouseY
  $0012    18  MouseX
  $0014    20  Flags
! $0016    22  Title
! $001a    26  DefaultTitle
  $001e    30  BarHeight
  $001f    31  BarVBorder
  $0020    32  BarHBorder
  $0021    33  MenuVBorder
  $0022    34  MenuHBorder
  $0023    35  WBorTop
  $0024    36  WBorLeft
  $0025    37  WBorRight
  $0026    38  WBorBottom
  $0028    40  Font
  $002c    44  ViewPort
  $0054    84  RastPort
  $00b8   184  BitMap
  $00e0   224  LayerInfo
! $0146   326  FirstGadget
  $014a   330  DetailPen
  $014b   331  BlockPen
  $014c   332  SaveColor0
! $014e   334  BarLayer
! $0152   338  ExtData
! $0156   342  UserData
Semaphore:
  $0024    36  sizeof(Semaphore)
  $0000     0  sm_MsgPort
  $0022    34  sm_Bids
SemaphoreRequest:
  $000c    12  sizeof(SemaphoreRequest)
  $0000     0  sr_Link
  $0008     8  sr_Waiter
SignalSemaphore:
  $002e    46  sizeof(SignalSemaphore)
  $0000     0  ss_Link
  $000e    14  ss_NestCount
  $0010    16  ss_WaitQueue
  $001c    28  ss_MultipleLink
  $0028    40  ss_Owner
  $002c    44  ss_QueueCount
SimpleSprite:
  $000c    12  sizeof(SimpleSprite)
  $0000     0  posctldata
  $0004     4  height
  $0006     6  x
  $0008     8  y
  $000a    10  num
SoftIntList:
  $0010    16  sizeof(SoftIntList)
  $0000     0  sh_List
  $000e    14  sh_Pad
SpecialMonitor:
  $003a    58  sizeof(SpecialMonitor)
  $0000     0  spm_Node
  $0018    24  spm_Flags
! $001a    26  do_monitor
! $001e    30  reserved1
! $0022    34  reserved2
! $0026    38  reserved3
! $002a    42  hblank
! $002e    46  vblank
! $0032    50  hsync
! $0036    54  vsync
SpriteDef:
  $0008     8  sizeof(SpriteDef)
  $0000     0  pos
  $0002     2  ctl
  $0004     4  dataa
  $0006     6  datab
SrcNode:
  $0010    16  sizeof(SrcNode)
  $0000     0  sn_Succ
  $0004     4  sn_Pred
  $0008     8  sn_Ptr
  $000c    12  sn_Size
StandardPacket:
  $0044    68  sizeof(StandardPacket)
  $0000     0  sp_Msg
  $0014    20  sp_Pkt
StoredProperty:
  $0008     8  sizeof(StoredProperty)
  $0000     0  sp_Size
  $0004     4  sp_Data
StringExtend:
  $0024    36  sizeof(StringExtend)
  $0000     0  Font
  $0004     4  Pens[0]
  $0006     6  ActivePens[0]
  $0008     8  InitialModes
  $000c    12  EditHook
  $0010    16  WorkBuffer
  $0014    20  Reserved[0]
StringInfo:
  $0024    36  sizeof(StringInfo)
  $0000     0  Buffer
  $0004     4  UndoBuffer
  $0008     8  BufferPos
  $000a    10  MaxChars
  $000c    12  DispPos
  $000e    14  UndoPos
  $0010    16  NumChars
  $0012    18  DispCount
  $0014    20  CLeft
  $0016    22  CTop
  $0018    24  Extension
  $001c    28  LongInt
  $0020    32  AltKeyMap
TAvailFonts:
  $000e    14  sizeof(TAvailFonts)
  $0000     0  taf_Type
! $0002     2  taf_Attr
TDU_PublicUnit:
  $0040    64  sizeof(TDU_PublicUnit)
  $0000     0  tdu_Unit
  $0026    38  tdu_Comp01Track
  $0028    40  tdu_Comp10Track
  $002a    42  tdu_Comp11Track
  $002c    44  tdu_StepDelay
  $0030    48  tdu_SettleDelay
  $0034    52  tdu_RetryCnt
  $0035    53  tdu_PubFlags
  $0036    54  tdu_CurrTrk
  $0038    56  tdu_CalibrateDelay
  $003c    60  tdu_Counter
TFontContents:
  $0104   260  sizeof(TFontContents)
  $0000     0  tfc_FileName[0]
  $00fe   254  tfc_TagCount
  $0100   256  tfc_YSize
  $0102   258  tfc_Style
  $0103   259  tfc_Flags
TTextAttr:
  $000c    12  sizeof(TTextAttr)
  $0000     0  tta_Name
  $0004     4  tta_YSize
  $0006     6  tta_Style
  $0007     7  tta_Flags
  $0008     8  tta_Tags
TagItem:
  $0008     8  sizeof(TagItem)
  $0000     0  ti_Tag
  $0004     4  ti_Data
Task:
  $005c    92  sizeof(Task)
  $0000     0  tc_Node
  $000e    14  tc_Flags
  $000f    15  tc_State
  $0010    16  tc_IDNestCnt
  $0011    17  tc_TDNestCnt
! $0012    18  tc_SigAlloc
! $0016    22  tc_SigWait
! $001a    26  tc_SigRecvd
! $001e    30  tc_SigExcept
  $0022    34  tc_TrapAlloc
  $0024    36  tc_TrapAble
! $0026    38  tc_ExceptData
! $002a    42  tc_ExceptCode
! $002e    46  tc_TrapData
! $0032    50  tc_TrapCode
! $0036    54  tc_SPReg
! $003a    58  tc_SPLower
! $003e    62  tc_SPUpper
! $0042    66  tc_Switch
! $0046    70  tc_Launch
! $004a    74  tc_MemEntry
  $0058    88  tc_UserData
TextAttr:
  $0008     8  sizeof(TextAttr)
  $0000     0  ta_Name
  $0004     4  ta_YSize
  $0006     6  ta_Style
  $0007     7  ta_Flags
TextExtent:
  $000c    12  sizeof(TextExtent)
  $0000     0  te_Width
  $0002     2  te_Height
  $0004     4  te_Extent
TextFont:
  $0034    52  sizeof(TextFont)
  $0000     0  tf_Message
  $0014    20  tf_YSize
  $0016    22  tf_Style
  $0017    23  tf_Flags
  $0018    24  tf_XSize
  $001a    26  tf_Baseline
  $001c    28  tf_BoldSmear
  $001e    30  tf_Accessors
  $0020    32  tf_LoChar
  $0021    33  tf_HiChar
! $0022    34  tf_CharData
  $0026    38  tf_Modulo
  $0028    40  tf_CharLoc
  $002c    44  tf_CharSpace
  $0030    48  tf_CharKern
TextFontExtension:
  $0018    24  sizeof(TextFontExtension)
  $0000     0  tfe_MatchWord
  $0002     2  tfe_Flags0
  $0003     3  tfe_Flags1
  $0004     4  tfe_BackPtr
  $0008     8  tfe_OrigReplyPort
  $000c    12  tfe_Tags
  $0010    16  tfe_OFontPatchS
  $0014    20  tfe_OFontPatchK
TmpRas:
  $0008     8  sizeof(TmpRas)
  $0000     0  RasPtr
  $0004     4  Size
UCopList:
  $000c    12  sizeof(UCopList)
  $0000     0  Next
  $0004     4  FirstCopList
  $0008     8  CopList
Unit:
  $0026    38  sizeof(Unit)
  $0000     0  unit_MsgPort
  $0022    34  unit_flags
  $0023    35  unit_pad
  $0024    36  unit_OpenCnt
VSprite:
  $003c    60  sizeof(VSprite)
  $0000     0  NextVSprite
  $0004     4  PrevVSprite
  $0008     8  DrawPath
  $000c    12  ClearPath
  $0010    16  OldY
  $0012    18  OldX
  $0014    20  Flags
  $0016    22  Y
  $0018    24  X
  $001a    26  Height
  $001c    28  Width
  $001e    30  Depth
  $0020    32  MeMask
  $0022    34  HitMask
  $0024    36  ImageData
  $0028    40  BorderLine
  $002c    44  CollMask
  $0030    48  SprColors
  $0034    52  VSBob
  $0038    56  PlanePick
  $0039    57  PlaneOnOff
  $003a    58  VUserExt
View:
  $0012    18  sizeof(View)
  $0000     0  ViewPort
  $0004     4  LOFCprList
  $0008     8  SHFCprList
  $000c    12  DyOffset
  $000e    14  DxOffset
  $0010    16  Modes
ViewExtra:
  $0020    32  sizeof(ViewExtra)
  $0000     0  n
  $0018    24  View
  $001c    28  Monitor
ViewPort:
  $0028    40  sizeof(ViewPort)
  $0000     0  Next
  $0004     4  ColorMap
  $0008     8  DspIns
  $000c    12  SprIns
  $0010    16  ClrIns
  $0014    20  UCopIns
  $0018    24  DWidth
  $001a    26  DHeight
  $001c    28  DxOffset
  $001e    30  DyOffset
  $0020    32  Modes
  $0022    34  SpritePriorities
  $0023    35  ExtendedModes
  $0024    36  RasInfo
ViewPortExtra:
  $0024    36  sizeof(ViewPortExtra)
  $0000     0  n
  $0018    24  ViewPort
  $001c    28  DisplayClip
WBArg:
  $0008     8  sizeof(WBArg)
  $0000     0  wa_Lock
  $0004     4  wa_Name
WBStartup:
  $0028    40  sizeof(WBStartup)
  $0000     0  sm_Message
  $0014    20  sm_Process
  $0018    24  sm_Segment
  $001c    28  sm_NumArgs
  $0020    32  sm_ToolWindow
  $0024    36  sm_ArgList
Window:
  $0088   136  sizeof(Window)
  $0000     0  NextWindow
  $0004     4  LeftEdge
  $0006     6  TopEdge
  $0008     8  Width
  $000a    10  Height
  $000c    12  MouseY
  $000e    14  MouseX
  $0010    16  MinWidth
  $0012    18  MinHeight
  $0014    20  MaxWidth
  $0016    22  MaxHeight
  $0018    24  Flags
  $001c    28  MenuStrip
  $0020    32  Title
  $0024    36  FirstRequest
  $0028    40  DMRequest
  $002c    44  ReqCount
! $002e    46  WScreen
! $0032    50  RPort
  $0036    54  BorderLeft
  $0037    55  BorderTop
  $0038    56  BorderRight
  $0039    57  BorderBottom
! $003a    58  BorderRPort
! $003e    62  FirstGadget
! $0042    66  Parent
! $0046    70  Descendant
! $004a    74  Pointer
  $004e    78  PtrHeight
  $004f    79  PtrWidth
  $0050    80  XOffset
  $0051    81  YOffset
! $0052    82  IDCMPFlags
! $0056    86  UserPort
! $005a    90  WindowPort
! $005e    94  MessageKey
  $0062    98  DetailPen
  $0063    99  BlockPen
  $0064   100  CheckMark
  $0068   104  ScreenTitle
  $006c   108  GZZMouseX
  $006e   110  GZZMouseY
  $0070   112  GZZWidth
  $0072   114  GZZHeight
  $0074   116  ExtData
  $0078   120  UserData
  $007c   124  WLayer
  $0080   128  IFont
  $0084   132  MoreFlags
_Object:
  $000c    12  sizeof(_Object)
  $0000     0  o_Node
  $0008     8  o_Class
bltnode:
  $0012    18  sizeof(bltnode)
  $0000     0  n
  $0004     4  function
  $0008     8  stat
  $000a    10  blitsize
  $000c    12  beamsync
! $000e    14  cleanup
collTable:
  $0040    64  sizeof(collTable)
  $0000     0  collPtrs[0]
copinit:
  $0078   120  sizeof(copinit)
  $0000     0  vsync_hblank[0]
  $0004     4  diwstart[0]
  $000c    12  diagstrt[0]
  $0014    20  sprstrtup[0]
  $0054    84  wait14[0]
  $0058    88  norm_hblank[0]
  $005c    92  genloc[0]
  $0064   100  jump[0]
  $006c   108  wait_forever[0]
  $0070   112  sprstop[0]
cprlist:
  $000a    10  sizeof(cprlist)
  $0000     0  Next
  $0004     4  start
  $0008     8  MaxCount
gpGoInactive:
  $0008     8  sizeof(gpGoInactive)
  $0000     0  MethodID
  $0004     4  gpgi_GInfo
gpHitTest:
  $000c    12  sizeof(gpHitTest)
  $0000     0  MethodID
  $0004     4  gpht_GInfo
  $0008     8  gpht_Mouse
  $0008     8  gpht_Mouse.X
  $000a    10  gpht_Mouse.Y
gpInput:
  $0014    20  sizeof(gpInput)
  $0000     0  MethodID
  $0004     4  gpi_GInfo
  $0008     8  gpi_IEvent
  $000c    12  gpi_Termination
  $0010    16  gpi_Mouse
  $0010    16  gpi_Mouse.X
  $0012    18  gpi_Mouse.Y
gpRender:
  $0010    16  sizeof(gpRender)
  $0000     0  MethodID
  $0004     4  gpr_GInfo
  $0008     8  gpr_RPort
  $000c    12  gpr_Redraw
impDraw:
  $0018    24  sizeof(impDraw)
  $0000     0  MethodID
  $0004     4  imp_RPort
  $0008     8  imp_Offset
  $0008     8  imp_Offset.X
  $000a    10  imp_Offset.Y
  $000c    12  imp_State
  $0010    16  imp_DrInfo
  $0014    20  imp_Dimensions
  $0014    20  imp_Dimensions.Width
  $0016    22  imp_Dimensions.Height
impErase:
  $0010    16  sizeof(impErase)
  $0000     0  MethodID
  $0004     4  imp_RPort
  $0008     8  imp_Offset
  $0008     8  imp_Offset.X
  $000a    10  imp_Offset.Y
  $000c    12  imp_Dimensions
  $000c    12  imp_Dimensions.Width
  $000e    14  imp_Dimensions.Height
impFrameBox:
  $0014    20  sizeof(impFrameBox)
  $0000     0  MethodID
  $0004     4  imp_ContentsBox
  $0008     8  imp_FrameBox
  $000c    12  imp_DrInfo
  $0010    16  imp_FrameFlags
impHitTest:
  $000c    12  sizeof(impHitTest)
  $0000     0  MethodID
  $0004     4  imp_Point
  $0004     4  imp_Point.X
  $0006     6  imp_Point.Y
  $0008     8  imp_Dimensions
  $0008     8  imp_Dimensions.Width
  $000a    10  imp_Dimensions.Height
mouth_rb:
  $005c    92  sizeof(mouth_rb)
  $0000     0  voice
  $0058    88  width
  $0059    89  height
  $005a    90  shape
  $005b    91  sync
narrator_rb:
  $0058    88  sizeof(narrator_rb)
  $0000     0  message
  $0030    48  rate
  $0032    50  pitch
  $0034    52  mode
  $0036    54  sex
  $0038    56  ch_masks
  $003c    60  nm_masks
  $003e    62  volume
  $0040    64  sampfreq
  $0042    66  mouths
  $0043    67  chanmask
  $0044    68  numchan
  $0045    69  flags
  $0046    70  F0enthusiasm
  $0047    71  F0perturb
  $0048    72  F1adj
  $0049    73  F2adj
  $004a    74  F3adj
  $004b    75  A1adj
  $004c    76  A2adj
  $004d    77  A3adj
  $004e    78  articulate
  $004f    79  centralize
  $0050    80  centphon
  $0054    84  AVbias
  $0055    85  AFbias
  $0056    86  priority
  $0057    87  pad1
opAddTail:
  $0008     8  sizeof(opAddTail)
  $0000     0  MethodID
  $0004     4  opat_List
opGet:
  $000c    12  sizeof(opGet)
  $0000     0  MethodID
  $0004     4  opg_AttrID
  $0008     8  opg_Storage
opMember:
  $0008     8  sizeof(opMember)
  $0000     0  MethodID
  $0004     4  opam_Object
opSet:
  $000c    12  sizeof(opSet)
  $0000     0  MethodID
  $0004     4  ops_AttrList
  $0008     8  ops_GInfo
opUpdate:
  $0010    16  sizeof(opUpdate)
  $0000     0  MethodID
  $0004     4  opu_AttrList
  $0008     8  opu_GInfo
  $000c    12  opu_Flags
timerequest:
  $0028    40  sizeof(timerequest)
  $0000     0  tr_node
  $0020    32  tr_time
timeval:
  $0008     8  sizeof(timeval)
  $0000     0  tv_secs
  $0004     4  tv_micro
colorEntry:
  $0004     4  sizeof(colorEntry)
  $0000     0  colorLong
  $0000     0  colorByte[0]
  $0000     0  colorSByte[0]

