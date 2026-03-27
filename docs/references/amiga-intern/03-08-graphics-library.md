# The Graphics Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.8 The Graphics Library

Programmers often refer to "graphics.library" (its proper name for the 

OpenDevice() function) as the Gfx library. Gfx is responsible for all 

display and graphics operations. This library is used to program the blitter and the copper which control the video hardware. These routines are used for such operations as drawing, text output, and displaying movable objects. The base address must always be passed in A6.

Functions of the Gfx Library 

1. The Video Hardware 

CBump 

CloseMonitor 

CMove 

CWait 

FindDisplaylnfo 

FreeCopList 

FreeCprList 

FreeVPortCopLists 

GetDisplaylnfoData 

GetVPModelD 

LoadRGB4 

LoadView 

MakeVPort 

ModeNotAvailable 

MrgCop 

NextDisplaylnfo 

OpenMonitor 

ScrollVPort 

SetRGB4 

VBeamPos 

VideoControl 

WaitBOVP 

WaitTOF 

2. General Blitter Control 

BitMapScale 

BltBitMap 

BltBitMapRastPort 

BltClear 

BltMaskBitMapRast 

Port 

BltPattern 

BltTemplate 

QipBlit 

CopySBitMap 

DisOwnBlitter 

OwnBlitter 

QBlit 

QBSBlit 

ScalerDiv 

ScrollRaster 

SyncSBitMap 

WaitBlit 

3. Refresh Functions 

AndRectRegion 

AndRegionRegion 

ClearRectRegion 

ClearRegion 

DisposeRegion 

NewRegion 

OrRectRegion 

OrRegionRegion 

XorRectRegion 

XorRegionRegion 

4. Data Structures 

AllocRaster

AttemptLockLayerRom 

FreeColorMap 

FreeRaster 

GetColorMap 

GetRGB4 

InitBitMap 

InitRastPort 

InitTmpRas 

InitView 

InitVPort 

LockLayerRom 

## 3.1 The Libraries and their Functions

SetRGB4CM 

UnlockLayerRom 

5. Draw Functions 

AreaDraw 

AreaEllipse 

AreaEnd 

AreaMove 

Draw 

DrawEllipse 

EraseRect 

Flood 

InitArea 

Move 

PolyDraw 

ReadPixel 

ReadPixelArray8 

ReadPixelLine8 

RectFill 

SetAPen 

SetBPen 

SetDrMd 

SetRast 

WritePixel 

WritePixelArray8 

WritePixelLine8 

6. Text Output 

AddFont 

AskFont 

AskSoftStyle 

ClearEOL 

ClearScreen 

CloseFont 

ExtendFont 

FontExtent 

OpenFont 

RemFont 

SetFont 

SetSoftStyle 

StripFont 

Text 

TextExtent 

TextFit 

TextLength 

WeighTAMatch 

7. Movable Objects 

AddAnimOb 

AddBob 

AddVSprite 

Animate 

ChangeSprite 

DoCollision 

DrawGList 

FreeGBuffers 

FreeSprite 

GetGBuffers 

GetSprite 

InitGels 

InitGMasks 

InitMasks 

MoveSprite 

RemlBob 

RemVSprite 

SetCollision 

SortGList 

Description of Functions 

1. The Video Hardware 

[CBump UCopList pointer to the next instruction | 

Call: CBump (  c ) 

-366 (A6) al 

STRUCT UCopList *C 

Function: Sets the command pointer of a  user Copper list to the next 

command.

Parameters: c  Address of a  UCopList structure. 

[CloseMonitor Close Monitor Spec | 

Call: error =  CloseMonitor (  monitor_spec ) 

dO -720 (A6) aO

LONG error 

STRUCT MonitorSpec *monitor_spec 

Function: Closes the given MonitorSpec. 

Parameters: monitor_spec 

MonitorSpec address from OpenMonitorQ. 

Result: 0  MonitorSpec closed 

[CMove Write a  Copper move instruction to the UCopList \ 

Call: CMove (  c ,   a ,   v ) 

-372(A6)al dO dl 

STRUCT UCopList *C 

SHORT a,v 

Function: Writes a  Copper move command to a  user Copper list 

without changing the edit pointer.

Parameters: c  UCopList structure 

a Hardware register offset from $DFF000. 

v Word to which the register will be written.

I C Wait Enter Copper wait in UCopList | 

Call: cwait( c  , v  , h  ) 

-378 (A6) al dO dl 

STRUCT UCopList *C 

SHORT v,h 

Function: Writes a  Copper wait command to the user Copper list 

without changing the edit position.

Parameters: c  UCopList structure 

v Vertical wait position (end =  10000). h Horizontal wait position (end =  255).

| FindDisplaylnfo Get info on the display model 

Call: handle =  FindDisplaylnfo (   ID ) 

dO -726 (A6) dO

ULONG ID 

LONG handle 

Function: Finds the information structure for a  given display mode. 

Parameters: ID 32 bit display mode (monitor specific 

ViewMode). 

Result: Handle to DisplaylnfoRecord or 0. 

| FreeCopList Free Copper list buffer] 

Call: FreeCopList (coplist) 

-546 (A6) aO 

struct CopList *coplist

Function: Frees the memory used by a  Copper list. 

Parameters: coplist CopList structure 

IFreeCprList Free a  hardware Copper listj 

Call: FreeCprList (cprlist) 

-564 (A6) aO 

STRUCT cprlist *cprlist 

Function: Frees the memory of a  hardware Copper list. 

Parameters: cprlist cprlist structure 

| Free VPortCopLists Free ViewPort Copper lists | 

Call: FreeVPortCopLists (vp) 

-540 (A6) aO 

STRUCT ViewPort *vp 

Function: Frees the memory for all Copper lists of a  ViewPort. 

Parameters: vp ViewPort 

1 GetDisplaylnfoData Get data associated with a  display mode | 

Call: result =  GetDisplaylnfoData (handle, buf, size, tagID, ID) 

dO -756 (A6) aO al dO dl d2

LONG handle 

APTR buf 

ULONG size, tagID, ID, result 

Function: Fills a  buffer with data associated with a  display mode. 

Parameters: handle Displaylnfo handle of the display mode. 

buf

Buffer to be filled 

size

Buffer size 

tagID

Desired data type: 

DTAG_DISP 

DTAG_DMS 

DTAG_MNTR 

DTAG_NAME 

Displaylnfo structure 

Dimensionlnfo structure 

Monitorlnfo structure 

Display mode name 

ID 32 bit display mode (if handle=0). 

Result: Number of bytes in buffer, 0  (unknown mode or error). 

IGetVPModelD Get a  monitor specific display model 

Call: modelD =  GetVPModelD (  vp ) 

dO -792 (A6) aO

STRUCT Viewport *vp 

ULONG modelD 

Function: Retrieves the monitor specific 32 bit display mode of a 

ViewPort. 

Parameters: vp ViewPort structure 

Result: ModelD or INVALIDJD 

|LoadRGB4 Set color table | 

Call: LoadRGB4 (  vp, colors ,    count ) 

-192 (A6) aO al d0:16 

STRUCT ViewPort *vp 

APTR colors 

SHORT count 

Function: Loads the 3x4 bit RGB color values from a  table to the 

ColorMap of the ViewPort, recalculates the Copper lists, 

and controls the video hardware.

Parameters: vp ViewPort whose colors are to be changed. 

colors Word array with color values ($ORGB). count Number of colors (including 0).
| Load View Activate a  Copper list | 

Call: Loadview( View ) 

-222 (A6) Al 

STRUCT View *View 

Function: Activates the Copper list of a  view (available after 

MakeView(), MrgCopO) until the next call. Many 

programs, handlers (Intuition, Workbench...) and operating system routines call this function, so a  good knowledge of the system is required for error-free programming.

Parameters: View View structure with Copper lists or 0  (screen 

off but DMA still running, as, for example, with the sprite DMA).

| Make VPort Assemble the Copper lists of a  ViewPort | 

Call: MakeVPort (  view, viewport ) 

-216 (A6) aO al 

STRUCT View *view 

STRUCT ViewPort *viewport 

Function: Derives the Copper lists of a  ViewPort. 

Parameters: view View structure of the ViewPorts. 

viewport ViewPort structure with Raslnfo.

| ModeNot Available Checks on availability of a  display model 

Call: error =  ModeNotAvailable (  modelD ) 

dO -798 (A6) dO

ULONG modelD, error 

Function: Checks for the availability of a  monitor specific 32 bit 

display mode.

Parameters: modelD 32 bit display mode 

Result: Error code that describes why the mode is not available, or 

0 if the system does not have a  reason why this mode can't 

be used.

I MrgCop Merge Copper lists \ 

Call: MrgCop (  view ) 

-210 (A6) Al 

STRUCT View *View 

Function: Merges all partial Copper lists into a  proper Copper list. 

Parameters: View View structure with partial Copper lists. 

| NextDisplay Info Read through list of display modes | 

Call: next_lD =  NextDisplay Inf o (   last_lD ) 

dO -732 (A6) dO

ULONG last_ID,next_ID 

Function: Gets the next available monitor specific display mode. 

Parameters: lastJD Result of the last call or INVALIDJD for the 

start of the list.

Result: 32 bit display mode or INVALID_ID (no more modes). 

IQpenMonitor Open Monitor Spec! 

Call: mspc =  OpenMonitor( monitor_name ,  display_id) 

dO -714 (A6) al dO

APTR monitor_name 

ULONG display_id 

STRUCT MonitorSpec *mspc 

Function: Opens a  MonitorSpec which is given the monitor name or 

the 32 bit ID. If both parameters are 0, then the default monitor is returned.

Parameters: monitor_name 

Monitor name or 0. 

displayed 32 bit display mode or 0.

Result: MonitorSpec structure or 0. 

| Scroll VPort Scroti ViewPort contents] 

Call: ScrollVPort( vp ) 

-588 (A6) aO 

STRUCT Viewport *vp 

Function: Called after changing the Raslnfo offsets and BitMap 

pointer to recalculate the Copper lists. Warning: high level languages are too slow.

Parameters: vp Visible ViewPort 

|SetRGB4 Change colors I 

Call: SetRGB4 (  vp, n, r, g, b) 

-288 (A6) aO dO dl:4 d2 : 4 d3:4 

STRUCT ViewPort *vp 

SHORT n 

UBYTE r,g,b 

Function: Sets the color intensity of a  color register, recalculates the 

Copper list, which controls the hardware. 

Parameters: vp ViewPort 

n Color number (0...3 1 ) g b

IVBeamPos

Call: pos =  VBeamPos ( ) 

dO -384 (A6)

Red intensity (0...15) 

Green intensity (0...15) 

Blue intensity (0...15) 

Get the vertical beam position] 

LONG pos 

Function: Gets the position of the monitor's vertical beam. 

Result: Vertical beam position (0...511). The uncertainty is 

extremely high and is only acceptable for a  task with the highest priority.

IVideoControl 

Change the color operations of a  ViewPort] 

Call: error =  VideoControl (   cm ,    tags ) 

dO -708 (A6) aO al

LONG error 

STRUCT ColorMap *cm 

STRUCT Tagltem *tags 

Function: Change the operation of a  ViewPort's ColorMap according 

to the commands in a  Tagltem field.

Parameters: cm 

tags
Tags: 

ColorMap, result of GetColorMap(). 

Tagltem field 

VTAG_ATTACH_CM_.. get the ViewPort of the ColorMap 

(..GET), set (..SET). 

VTAG_VIEWPORTEXTRA_.. get vp_extra (..GET), set 

(..SET). 

VTAG_NORMAL_DISP_.. get DisplaylnfoHandle in 

normal mode (..GET), set (..SET).

VTAG_COERCE_DISP_.. same for coerced mode (..GET, 

..SET). 

VTAG_BORDERBLANK_.. Genlock: set border blanking 

(..SET), clear (..CLR), get (..GET). 

VTAG_BORDERNOTRANS_.. set no-transparency in the 

border region (..SET), clear (..CLR), get (..GET).

VTAG_CHROMAKEY_.. set Chroma mode (..SET), clear 

(..CLR), get (..GET). 

VTAG_BITPLANEKEY_.. set BitPlane mode (..SET), clear 

(..CLR), get (..GET). 

VTAG_CHROMA_PEN_.. set Chroma color number 

(..SET), clear (..CLR), get (..GET). 

VTAG_CHROMA_PLANE_.. set BitPlane number (..SET), 

get (..GET).

VTAG_NEXTBUF_CM next command list. 

VTAG_END_CM last command. 

Result: 0  Okay, followed by adding the next 

MakeVPort(). 

| WaitBO VP Wait until a  ViewPort is scanned | 

Call: waitBOVP( vp ) 

-402 (A6) aO 

STRUCT ViewPort *vp 

Function: Waits until the monitor beam has displayed the last visible 

line of the given ViewPort.

Parameters: vp 

IWaitTGF 

ViewPort 

Wait for vertical scan interrupts! 

COPPER_MOVE 

COPPER_WAIT 

CPRNXTBUF 

CPR_NT_LOF 

CPR_NT_SHT 

CPR_NT_SYS 

Call: waitTOF ( ) 

-270 (A6) 

Function: Waits for the monitor's next vertical scan and for all VertB 

interrupt routines to be processed (turning off tasks, signal through VertB handler).

Pseudo Opcodes for lists: 

= 0   Pseudo Opcode for MOVE #...,... 

= 1   Pseudo Opcode for WAIT ....... 

= 2  end of buffer 

= $8000  command for Shortframes 

= $4000 .-command for Longframes (2. Interlace) 

= $2000 User command 

Dec Hex STRUCTURE CopIns.O 

0 $0 WORD ci_OpCode 

$2 STRUCT ci_nxtlist,0 

$2 STRUCT ci_VWaitPos,0 

 Copper Pseudo Opcode 

0 =  move, 1  = wait 

address of the next buffer or wait position

$2 STRUCT ci_DestAddr,2 or destination address 

$4 STRUCT ci_HWaitPos,0 2. partial wait position 

$4 STRUCT ci_DestData, 2 or value 

$6 LABEL ci_SIZEOF 

Dec Hex STRUCTURE cprlist.O 

0 $0 APTR crl_Next 

4 $4 APTR crl_start 

8 $8 WORD crl_MaxCount 

10 $A LABEL crl_SIZEOF 

.-management of true Copper lists 

address
,- start 

length

Dec Hex STRUCTURE CopList,0 

0 $0 APTR cl_Next 

4 $4 APTR cl CopList 

8 $8 APTR cl ViewPort 

12 $C APTR cl_CopIns 

16 $10 APTR cl_CopPtr 

20 $14 APTR cl_CopLStart 

24 $18 APTR cl_CopSStart 

28 $1C WORD cl_Count 

30 $1E WORD cl_MaxCount 

32 $20 WORD cl_DyOffset 

management of temporary lists next structure private private start of block command address

LongFrame address from MrgCopO 

ShortFrame address fromMrgCopO 

counter block length in Pseudo Opcodes vertical start position

MODE_640 = 

$8000 

PLNCNTMSK = 

PLNCNTSHFT = 

PF2PRI 

$40 

COLORON 

$200 

DBLPF 

$400 

HOLDNMODIFY= 

$800 

INTERLACE = 

34 $22 LABEL cl_SIZEOF 

Dec Hex STRUCTURE UCopList.O User Copper list 

0 $0 APTR ucl_Next next list 

4 $4 APTR ucl_FirstCopList /first node 

8 $8 APTR ucl_CopList /current node 

12 $C LABEL ucl_SIZEOF 

HiRes 

bplcon0 bit plane mask bplcon0 bit plane bit
Playfield 2  priority 

/suppress Color Burst 

DualPlay field mode 

Hold-And-Modify mode 

 Interlace mode 

PFA_FINE_SCROLL =   15 ,-Softscrolling planes 0,2,4 

PFB_FINE_SCROLL_SHIFT =    4 bit position for planes 1,3,5 

PF_FINE_SCROLL_MASK =   15 Softscrolling planes 1,3,5 

DIW_HORIZ_POS =  $7F /horizontal mask 

DIW_VRTCL_POS =  $1FF ,-vertical mask 

DIW_VRTCL_POS_SHIFT =     7 bit position 

DFTCH_MASK =   $FF data fetching mask 

VPOSRLOF =$8000 LongFrame Flag vpos 

DTAG_DISP =  $80000000 ,-Display Tags 

DTAG_DIMS =  $80001000 

DTAG^MNTR =  $80002000 

DTAG_NAME =  $80003000 

Dec Hex STRUCTURE QueryHeader , 0 

0 $0 ULONG qh_StructID ,-Display Tag ID 

4 $4 ULONG qh_DisplayID 32 bit mode 

8 $8 ULONG qh_SkipID TAG_SKIP 

12 $C ULONG qh_Length  length in 8  byte segments 

16 $10 LABEL qh_SIZE0F 

Dec Hex STRUCTURE Display Info,qh_SIZEOF 

16 $10 UWORD dis_NotAvailable Flag: 0=available 

18 $12 ULONG dis_PropertyFlags  characteristics 

22 $16 STRUCT dis_Resolution, tpt_SIZEOF pixel resolution X/Y 

26 $1A UWORD dis_PixelSpeed  nanoseconds per pixel 

28 $1C UWORD dis_NumStdSprites /number of sprites 

30 $1E UWORD dis_PaletteRange ,-available colors 

32 $20 STRUCT dis_SpriteResolution, tpt_SIZEOF  sprite resolution 

36 $24 STRUCT dis_pad, 4 

40 $28 STRUCT dis_reserved, 8 

48 $30 LABEL dis_SIZEOF 

DI_AVAIL_NOCHIPS =  1 

DI_AVAIL_NOMONITOR =  2 

DI_AVAIL_NOTWITHGENLOCK =  4 

DIPF_IS_LACE =  $00000001 

DIPF_IS_DUALPF =  $00000002 

DIPF_IS_PF2PRI =  $00000004 

DIPF_IS_HAM =  $00000008 

DIPF_IS_ECS =  $00000010 

DIPF_IS_PAL =  $00000020 

DIPF_IS_SPRITES =  $00000040 

DIPF_IS_GENLOCK =  $00000080 

DIPF_IS_WB =  $00000100 

DIPF_IS_DRAGGABLE =  $00000200 

DIPF_IS_PANELLED =  $00000400 

DIPF_IS_BEAMSYNC =  $00000800 

DIPF_IS_EXTRAHALFBRITE =  $00001000 

Dec Hex STRUCTURE DimensionInfo,qh_SIZEOF 

16 $10 UWORD dim_JfaxDepth .-number of bit planes 

18 $12 UWORD dim_MinRasterWidth .-minimum width 

20 $14 UWORD dim_MinRasterHeight .-minimum height 

22 $16 UWORD dim_MaxRasterWidth .-maximum width 

24 $18 UWORD dim_MaxRasterHeight .-maximum height 

26 $1A STRUCT dim_Nominal, ra_SIZEOF .-standard dimensions 

34 $22 STRUCT dim_MaxOScan , ra_SIZEOF .-maximum Overscan 

42 $2A STRUCT dim_VideoOScan,ra_SIZEOF ,-video Overscan 

50 $32 STRUCT dim_TxtOScan , ra_SIZEOF ,-text Overscan Prefs 

58 $3A STRUCT dim_StdOScan, ra_SIZEOF  standard Overscan Prefs 

66 $42 STRUCT dim_pad, 14 

80 $50 STRUCT dim_reserved, 8 

88 $58 LABEL dim_SIZEOF 

Dec Hex STRUCTURE Monitor Inf o, qh_SIZEOF 

16 $10 APTR mtr_Mspc ,-MonitorSpec 

20 $14 STRUCT mtr_ViewPosition,tpt_SIZEOF  Prefs 

24 $18 STRUCT mtr_ViewResolution, tpt_SIZEOF .-resolution 

28 $1C STRUCT mtr_ViewPositionRange, ra_SIZEOF .-range 

36 $24 UWORD mtr_TotalRows ,-number of rows 

38 $26 UWORD mtr_TotalColorClocks ,-width in l/280ns 

40 $28 UWORD mtr_MinRow .-minimum height 

42 $2A WORD mtr_Compatibility  compatibility 

44 $2C STRUCT mtr_pad,36 

80 $50 STRUCT mtr_reserved, 8 

88 $58 LABEL mtr_SIZEOF 

MCOMPAT_MIXED = 

MCOMPAT_SELF 

MCOMPAT_NOBODY = 

DISPLAYNAMELEN = 

0 mixed display allowed 

1 with this monitor type only 

-1 only on Viewport allowed 

32  length of display name 

Dec Hex STRUCTURE NameInfo,qh_SIZEOF 

16 $10 STRUCT nif_Name, DISPLAYNAMELEN name 

48 $30 STRUCT nif_reserved, 8 

56 $38 LABEL nif_SIZEOF 

INVALID_ID 

MONITOR_ID_MASK 

DEFAULT_MONITOR_ID 

NTSC_MONITOR_ID 

PAL_MONITOR ID 

-1 

$FFFF1000 

$00000000 

$00011000 

$00021000 

LORES_KEY =  $00000000 

HIRES_KEY =  $00008000 

SUPER_KEY =  $00008020 

HAM_KEY =  $00000800 

LORESLACE_KEY =  $00000004 

HIRESLACE_KEY =  $00008004 

SUPERLACE_KEY =  $00008024 

HAMLACE_KEY =  $00000804 

LORESDPF_KEY =  $00000400 

HIRESDPF_KEY =  $00008400 

SUPERDPF_KEY =  $00008420 

LORESLACEDPF_KEY =  $00000404 

HIRESLACEDPF_KEY =  $00008404 

SUPERLACEDPF_KEY =  $00008424 

LORESDPF2_KEY =  $00000440 

HIRESDPF2_KEY =  $00008440 

SUPERDPF2_KEY =  $00008460 

LORESLACEDPF2_KEY =  $00000444 

HIRESLACEDPF2_KEY =  $00008444 

SUPERLACEDPF2_KEY =  $00008464 

EXTRAHALFBRITE_KEY =  $00000080 

EXTRAHALFBRITELACE_KEY =  $00000084 

LoRes 

HiRes 

SuperHiRes 

HoldAndModify 

Interlace 

HiRes -Interlace 

SuperHiRes- Interlace 

HAM-Interlace 

DualPlayfield 

HiRes-DblPf 

SuperHiRes-DblPf 

Inter lace-DblPf 

HiRes -Inter lace-DblPf 

SuperHiRes- ILace-DblPf 

DualPlayfield2 

HiRes-DblPf2 

SuperHiRes-DblPf2 

Inter lace-DblPf2 

HiRes- Inter lace-DblPf 2 

SuperHRes- ILace-DblPf 2 

ExtraHalfbrite 

ExtraHalfbrite-ILace 

VGA_MONITOR_ID =  $00031000 

VGAEXTRALORES_KEY =  $00031004 

VGALORES_KEY =  $00039004 

VGAPRODUCT_KEY =  $00039024 

VGAHAM_KEY =  $00031804 

VGAEXTRALORESLACE_KEY =  $00031005 

VGALORESLACE_KEY =  $00039005 

VGAPRODUCTLACE_KEY =  $00039025 

VGAHAMLACE_KEY =  $00031805 

VGA monitor 

ExtraLoRes 

 LoRes 

/Productivity 

HAM 

ExtraLoRes-ILace 

 Interlace 

 Productivity-ILace 

 HAM-Interlace 

VGAEXTRALORESDPF_KEY =  $00031404 

VGALORESDPF_KEY =  $00039404 

VGAPRODUCTDPF_KEY =  $00039424 

VGAEXTRALORESLACEDPF_KEY= $00031405 

VGALORESLACEDPF_KEY =  $00039405 

VGAPRODUCTLACEDPF_KEY =  $00039425 

VGAEXTRALORESDPF2_KEY =  $00031444 

VGALORESDPF2_KEY =  $00039444 

VGAPRODUCTDPF2_KEY =  $00039464 

VGAEXTRALORESLACEDPF2_KEY=$00031445 

VGALORESLACEDPF2_KEY =  $00039445 

VGAPRODUCTLACEDPF2_KEY =  $00039465 

VGAEXTRAHALFBRITE_KEY =  $00031084 

VGAEXTRAHALFBRITELACE_KEY =$00031085 

 ExtraLoRes-DblPf 

DualPlayf ield 

 Productivity-DblPf 

XLoRes-ILace-DblPf 

 Interlace-DblPf 

 Prod-ILace-DblPf 

XLoRes-DblPf2 

DualPlayfield2 

 Productivity-DblPf 2 

XLoRes-ILace-DblPf2 

 Interlace-DblPf 2 

 Prod-ILace-DblPf 2 

 ExtraHalf brite 

EHB-Interlace 

A2024_MONITOR_ID 

A2 0  2 4TENHERTZ_KEY 

A2 0 2 4 F I FTEENHERTZ_KEY 

$00041000 /monochrome monitor 

$00041000 10 Hz mode 

$00049000 15 Hz mode 

PROTO_MONITOR_ID 

= $00051000 /prototype 

Dec Hex STRUCTURE tPoint 

0 $0 WORD tpt_x 

2 $2 WORD tpt_y 

4 $4 LABEL tpt_SIZEOF 

0  resolution per point 

Dec Hex STRUCTURE AnalogSignallnterval, 0 

0 $0 UWORD asi_Start 

2 $2 UWORD asi_Stop 

4 $4 LABEL asi_SIZEOF 

Dec Hex STRUCTURE SpecialMonitor, XLN_SIZE 

24 $18 UWORD spm_Flags 

26 $1A APTR spm_do_monitor 

3 0  $1E APTR spm_reservedl 

34 $22 APTR spm_reserved2 

38 $26 APTR spm_reserved3 

42 $2A STRUCT spmjiblank, asi_SIZEOF 

46 $2E STRUCT spm_vblank, asi_SIZEOF 

50 $32 STRUCT spm_hsync, asi_SIZEOF 

54 $36 STRUCT spm_vsync, asi_SIZEOF 

58 $3A LABEL spm_SIZEOF 

Dec Hex STRUCTURE MonitorSpec, XLN_SIZE 

24 $18 UWORD ms_Flags 

26 $1A LONG ms_ratioh 

3 0  $1E LONG ms_ratiov 

34 $22 UWORD ms_total_rows 

3 6  $24 UWORD 

ms_total_colorclocks

38 $26 UWORD 

ms_DeniseMaxDisplayColumn

40 $28 UWORD 

ms_BeamCon0

42 $2A UWORD 

ms_min_row

44 $2C APTR 

ms_Special

48 $30 UWORD 

ms_OpenCount

50 $32 APTR 

ms_trans form

54 $36 APTR 

ms_translate

58 $3A APTR 

ms_scale

62 $3E UWORD 

ms_xoffset

64 $40 UWORD 

ms_yoffset

66 $42 STRUCT 

ms_LegalView, ra_SIZEOF

74 $4A APTR 

ms_maxoscan

78 $4E APTR 

ms_videoscan

82 $52 UWORD 

ms_DeniseMinDisplayColumn

84 $54 UWORD 

ms_DisplayCompat ible

86 $56 STRUCT 

ms_DisplayInfoDataBase, LH_SIZE

100 $64 STRUCT 

ms_DIDBSemaphore , SS_SIZE

146 $92 ULONG 

ms_reserved0 0

150 $96 ULONG 

ms_reserved0 1

154 $9A LABEL 

ms_SIZEOF

MSB_REQUEST_NTSC =  0, 

MSB_REQUEST_PAL =  1, 

MSB_REQUEST_SPECIAL =  2, 

MSB_REQUEST_A2024 =  3, 

MSF_REQUEST_NTSC =  1 

MSF_REOUEST_PAL =  2 

MSF_REQUEST_SPECIAL =  4 

MSF_REQUEST_A2024 =  8 

STANDARD_VIEW_X 

STANDARD_VIEW_Y 

Dec 

Hex STRUCT! 

$22 APTR 

$26 APTR 

$2A APTR 

$2E APTR 

$32 APTR 

$36 APTR 

$3A APTR 

$3E APTR 

$42 APTR 

$46 APTR 

$4A STRUCT 

$60 STRUCT 

$76 STRUCT 

$8C STRUCT 

$9A APTR 

$9E UWORD 

$A0 BYTE 

$81 

$2C 

RE GfxBase,LIB_SIZE 

gb_ActiView gb_copinit gb_cia gb_blitter gb_LOFlist gb_SHFlist gb_blthd gb_blttl gb_bsblthd gb_bsblttl gb_vbsrv, IS_SIZE gb_timsrv, IS_SIZE gb_bltsrv, IS_SIZE gb_TextFonts , LH_SIZE gb_DefaultFont gb_Modes bltcon0 gb_VBlank base structure

.•active View 

Copper start list 

CIA 

Blitter 

current Copper list

/current Copper list 

bltnode

SA1 BYTE 

$A2 UWORD 

$A4 WORD 

$A6 BYTE 

$A7 BYTE 

$A8 WORD 

$AA WORD 

$AC WORD 

$AE STRUCT 

SBC APTR 

$C0 STRUCT 

$CE WORD 

$D0 APTR 

$D4 WORD 

$D6 WORD 

$D8 WORD 

$DA WORD 

$DC WORD 

$DE WORD 

$E0 APTR 

$E4 APTR 

$E8 WORD 

$EA WORD 

$EC UBYTE 

$ED STRUCT 

$F2 STRUCT 

$F4 STRUCT 

27 6 

$114 STRUCT 

$134 STRUCT 

$154 WORD 

$156 WORD 

$158 WORD 

$15A APTR 

$15E UWORD 

$160 UWORD 

$162 UBYTE 

$163 UBYTE 

$164 STRUCT 

$174 APTR 

$178 WORD 

$17 A WORD 

$17C APTR 

$180 STRUCT 

$18E APTR 

$192 APTR 

$196 APTR 

$19A APTR 

$19E APTR 

gb_Debug gb_BeamSync gb_sy s t em_bp 1 conO gb_SpriteReserved gb_bytereserved gb_Flags gb_BlitLock gb_BlitNest gb_BlitWaitQ, LH_SIZE gb_BlitOwner gb_TOF_WaitQ, LH_SIZE gb_DisplayFlags gb_SimpleSprites gb_MaxDi splayRow gb_MaxDisplayColumn gb_NormalDisplayRows gb_NormalDisplayColumns gb_Norma 1 DPMX gb_NormalDPMY gb_LastChanceMemory gb_LCMptr gb_MicrosPerLine /microseconds times 256 gb_MinDisplayColumn gb_ChipRevBitsO new Agnus/Denise gb_crb_reserved, 5 gb_monitor_id, 2 gb_hedley , 4*8 gb_hedley_sprites, 4*8 gb_hedley_spritesl, 4*8 gb_hedley_count gb_hedley_f lags gb_hedley_tmp gb_hash_table gb_current_tot_rows gb_current_tot_cclks gb_hedley_hint gb_hedley_hint2 gb_nreserved, 4*4 gb_a2024_sync_raster gb_control_delta_pal gb_control_delta_ntsc gb_current_monitor gb_MonitorList,LH_SIZE gb_default_monitor gb_MonitorListSemaphore gb_DisplayInfoDataBase gb_Ac t  iVi ewCpr Semaphore gb_UtilityBase

418 $1A2 APTR gb_ExecBase 

422 $1A6 LABEL gb_SIZE 

OWNBLITTERn =  0 Blitter occupied 

QBOWNERn =  1 Blitter occupied by queue 

GFXB_BIG_BLITS =  0 ChipRevBitsO 

GFXB_HR_AGNUS =  0 HiRes Agnus 

GFXB_HR_DENISE =  1 HiRes Denise 

NTSCn =  0 /display bits 

GENLOCn =  1 

PALn =  2 

TODA_SAFEn =  3 

BLITMSG_FAULTn =  2 

Dec Hex STRUCTURE XLN, 0  graphics node 

$0 APTR 

XLN_SUCC 

$4 APTR 

XLN_PRED 

$8 UBYTE 

XLN_TYPE 

$9 BYTE 

XLN_PRI 

$A APTR 

XLN_NAME 

$E UBYTE 

XLN_SUBSYSTEM 

$F UBYTE 

XLN_SUBTYPE 

$10 LONG 

XLN_LIBRARY 

$14 LONG 

XLN_INIT 

$18 LABEL 

XLN_SIZE 

SS_GRAPHICS =  $02 GfxSemaphore 

VIEW_EXTRA_TYPE =  1 

VIEWPORT_EXTRA_TYPE =  2 

SPECIAL_MONITOR_TYPE =  3 

MONITOR_SPEC_TYPE =  4 

VTAG_END_CM =  $00000000 

VTAG_CHROMAKEY_CLR =  $80000000 

VTAG_CHROMAKEY_SET =  $80000001 

VTAG_BITPLANEKEY_CLR =  $80000002 

VTAG_BITPLANEKEY_SET =  $80000003 

VTAG_BORDERBLANK_CLR =  $80000004 

VTAG_BORDERBLANK_SET =  $80000005 

VTAG_BORDERNOTRANS_CLR =  $80000006 

VTAG_BORDERNOTRANS_SET =  $80000007 

VTAG_CHROMA_PEN_CLR =  $80000008 

VTAG_CHROMA_PEN_SET =  $80000009 

VTAG_CHROMA_PLANE_SET =  $8000000A 

VTAG_ATTACH_CM_SET 

= 

$8000000B 

VTAG_NEXTBUF_CM 

= 

$8000000C 

VTAG_BATCH_CM_CLR 

= 

$8000000D 

VTAG_BATCH_CM_SET 

= 

$8000000E 

VTAG_NORMAL_DISP_GET 

= 

$8000000F 

VTAG_NORMAL_DISP_SET 

= 

$80000010 

VTAG_COERCE_DISP_GET 

= 

$80000011 

VTAG_COERCE_DISP_SET 

= 

$80000012 

VTAG_VIEWPORTEXTRA_GET = 

$80000013 

VTAG_VIEWPORTEXTRA_SET = 

$80000014 

VTAG_CHROMAKEY_GET 

= 

$80000015 

VTAG_BITPLANEKEY_GET 

= 

$80000016 

VTAG_BORDERBLANK_GET 

= 

$80000017 

VTAG_BORDERNOTRANS_GET = 

$80000018 

VTAG_CHROMA_PEN_GET 

= 

$80000019 

VTAG_CHROMA_PLANE_GET = 

$8000001A 

VTAG_ATTACH_CM_GET 

= 

$8000001B 

VTAG_BATCH_CM_GET 

= 

$8000001C 

VTAG_BATCH_ITEMS_GET 

= 

$8000001D 

VTAG_BATCH_ITEMS_SET 

= 

$8000001E 

VTAG_BATCH_ITEMS_ADD 

= 

$8000001F 

VTAG_VPMODEID_GET 

= 

$80000020 

VTAG_VPMODEID_SET 

= 

$80000021 

VTAG_VPMODEID_CLR 

= 

$80000022 

VTAG_USERCLI P_GET 

= 

$80000023 

VTAG_USERCLI P_SET 

= 

$80000024 

VTAG_USERCLI P_CLR 

= 

$80000025 

GENLOCK_VIDEO 

s:

.•composite video signal 

V_LACE 

$' 

 Interlace 

V_SUPERHIRES 

$2C 

SuperHiRes 

V_PFBA 

$4C 

switch Playfields

V_EXTRA_HALFBRITE = 

$8( 

Halfbrite 

GENLOCK_AUDIO 

$10( 

audio signal

V.DUALPF 

$400 DualPlayfield 

V_HAM = 

$800 Hold And Modify 

V_EXTENDED_MODE 

$1000  extended structure 

V_VP_HIDE 

52000 hide Viewport 

V_SPRITES 

54000 /Sprite DMA activated 

V_HIRES 

58000 HiRes 

EXTENDJVSTRUCT 

$1000 

VPF_DENISE 

VPF_A2024 

VPF_AGNUS 

VPF_TENH

VPF_ILACE 

$80 

$40 

$20 

$20 

$10 

Dec Hex 

STRUCTURE ColorMap, 0 

0 $0 

BYTE 

cm_Flags

1 $1 

BYTE 

cm_Type

2 $2 

WORD 

cm_Count

4 $4 

APTR 

cm_ColorTable

8 $8 

APTR 

cm_vpe

12 $C 

APTR 

cm_Tr anspar ency B its

16 $10 

BYTE 

cm_TransparencyPlane

17 $11 

BYTE 

cm_reservedl

18 $12 

WORD 

cm_reserved2

20 $14 

APTR 

cm_vp

24 $18 

APTR 

cm_NormalDisplayInfo

28 $1C 

APTR 

cm_CoerceDisplayInfo

32 $20 

APTR 

cm_batch_items

36 $24 

LONG 

cm_VPModeID

40 $28 

LABEL 

cm_SIZEOF

COLORMAPJTYPE. 

_V1_2 =  0 old ColorMap 

COLORMAPJTYPE. 

_V36 =  1 new ColorMap 

COLORMAPJTRANSPARENCY =  $01 

COLORPLANE_TRANSPARENCY =  $02 

BORDER_BLANKING =  $04 

BORDER_NOTRANSPARENCY =  $08 

VIDEOCONTROL_BATCH =  $10 

USER_COPPER_CLIP =  $20 

Dec Hex 

STRUCTURE ViewPort.O 

0 $0 

LONG 

vp_Next

4 $4 

LONG 

vp_ColorMap

8 $8 

LONG 

vp_DspIns

12 $C 

LONG 

vp_SprIns

16 $10 

LONG 

vp_ClrIns

20 $14 

LONG 

vp_UCopIns

24 $18 

WORD 

vp_DWidth

26 $1A WORD 

vp_DHeight

28 $1C 

WORD 

vp_DxOffset

30 $1E WORD 

vp_DyOf fset

32 $20 

WORD 

vp_Modes

34 $22 

BYTE 

vp_SpritePriorities

35 $23 

BYTE 

vp_Ext endedMode s

36 $24 

APTR 

vp_RasInfo

40 $28 

LABEL 

vp_SIZEOF

Dec Hex STRUCTURE View, 0 

0 $0 LONG v_ViewPort 

4 $4 LONG v_LOFCprList 

8 $8 LONG 

v_SHFCprList

12 $C WORD v_DyOffset 

14 $E WORD v_DxOffset 

16 $10 WORD v_Modes 

18 $12 LABEL v_SIZEOF 

Dec Hex STRUCTURE ViewExtra,XLN_SIZE 

24 $18 APTR ve_View 

28 $1C APTR ve_Monitor 

32 $20 LABEL ve_SIZEOF 

Dec Hex STRUCTURE ViewPortExtra,XLN_SIZE 

24 $18 APTR vpe_ViewPort 

28 $1C STRUCT vpe_DisplayClip,ra_SIZEOF 

36 $24 LABEL vpe_SIZEOF 

Dec Hex STRUCTURE collTable, 0 

0 $0 LONG cp_collPtrs,16 

64 $40 LABEL cp_SIZEOF 

Dec Hex STRUCTURE Raslnfo, 0 

0 $0 APTR 

4 $4 LONG 

8 $8 WORD 

10 $A WORD 

12 $C LABEL 

ri_Next ri_BitMap ri_RxOf fset ri_RyOf fset riSIZEOF

2. General Blitter Control 

IBitMapScalT 

Change the size of bit-map contents | 

Call: BitMapScale (  bitScaleArgs ) 

-678 (A6) a0 

STRUCT BitScaleArgs *bitScaleArgs 

Function: Copies a  portion of a  bit-map to another bit-map, changing 

the size to correspond to the size of the destination bit- map.

Parameters: bitScaleArgs 

Structure with the following parameters: 

bsa_srcX, bsa_srcY Upper left corner of the source bit-map. bsa_srcWidth, bsa_srcHeight

Size of source bit-map. 

bsa_destX, bsa_destY

Position in the destination bit- 

map. bsa_destWidth, bsa_destHeight

New size (result) 

bsa_xSrcFactor:bsa_xDestFactor

Scaling factor, corresponds with 

bsa_srcWidth:bsa_destWidth
Range: 1..16383. 

bsa_ySrcFactor:bsa_yDestFactor
Same for 

bsa_srcHeight:bsa_destHeight. bsa_srcBitMap

Source bit-map 

bsa_destBitMap

Destination bit-map (may not 

overlap with srcBitMap). bsa_flags 0  (not yet supported)

Result: destWidth and destHeight are filled with the new size. 

Example: Double the size of an image. A  LoRes bit-map in 320*256 

pixel format is copied to fill a  bit-map in 640*512 HiRes
Interlace format. The size change is accomplished as 

follows: bsa_DestWidth=bsa_SrcWidth*bsa_XDestFactor/bsa_XSrcFactor bsa_DestHeight=bsa_SrcHeight*bsa_YDestFactor/bsa_YSrcFactor In our example: bsa_DestWidth =  320 *  2 /  1 =  640 bsa_DestHeight =  256 *  2 /  1 =  512

Here is the simple demo routine: movea . 1 _Gf xBase , a6 lea _BitScaleArgs(pc) ,a0 jsr _BitMapScale(a6)

_BitScaleArgs 

dew 0,0 bsa_SrcX, bsa_SrcY dew 320,256 bsa_SrcWidth, bsa_SrcHeight dew 1,1 bsa_XSrcFactor, bsa_YSrcFactor dew 0,0 bsa_DestX, bsa_DestY dew 0,0 bsa_DestWidth, bsa_DestHeight dew 2,2 bsa_XDestFactor,bsa_YDestFactor del _LoResBitMap bsa_SrcBitMap del _HiResILaceBitMap bsa_DestBitMap del 0  bsa_Flags dew 0,0 bsa_XDDA, bsa_YDDA del 0,0 bsa_Reservedl, bsa_Reserved2

IBItBitMap

Copy a  portion of a  bit-map | 

Call: 

planecnt =  BltBitMaplSrcBitMap, SrcX, SrcY, DstBitMap,
DO -30(A6) AO D0:16 Dl:16 Al 

DstX, DstY, SizeX, SizeY, Minterm, Mask, TempA) 

D2:16 D3:16 D4:16 D5:16 D6 : 8 D7 : 8 A2 

ULONG planecnt 

STRUCT BitMap *SrcBitMap, DstBitMap 

WORD SrcX , SrcY , DstX, DstY, SizeX, SizeY 

UBYTE Minterm,Mask 

APTR TempA 

Copies part of a  bit-map to the given position in another 

bit-map. Both bit-maps can be the same and the ranges may overlap. If a  bit-plane address is set to 0, it is handled like an empty bit-plane. If the bit-plane address is -1, it is handled like a  filled bit-plane.

Parameters: SrcBitMap Source bit-map 

Function: 

DstBitMap 

Destination bit-map 

SrcX, SicY Coordinates in the source bit-map. 

DstX,DstY 

Coordinates in the destination bit-map. 

SizeX,SizeY 

Size of the region to be copied. 

Minterm Logical combination of source and destination: 

Blitter source A  is filled within the region. 

Blitter source B  is the source. 

Blitter sources C  and D  are the destination. 

$C0 copies, $30 copies the inverted source, 

$50 inverts only the destination, etc. 

Mask Bit mask for destination bit-plane. 

TempA Buffer for one line (source A) that must be 

scrolled horizontally if the regions overlap.

Result: Number of affected bit-planes. 

IBltBitMapRastPort Copy a  bit-map range to a  RastPortl 

Call: BltBitMapRastPort 

(srcbm,srcx,srcy,destrp,destX,destY,sizeX,sizeY, minterm) 

-606 (A6) aO dO dl al d2 d3 d4 d5 d6 

STRUCT BitMap *srcbm 

WORD srcx, srcy , destx, destY, sizeX, sizeY 

STRUCT RastPort *destrp 

UBYTE minterm 

Function: Similar to BltBitMapO, except that the destination is the 

given RastPort and a  mask cannot be used.

Parameters: srcbm Source bit-map 

srcx,srcy Position in the source bit-map.

destrp

Destination RastPort 

destX,destY

Position in RastPort 

sizeX,sizeY

Size of range 

minterm Logical combination

IBItClear 

Clear memory block (ChipR AM) | 

Call: 

BltClearf memBlock, bytecount, flags ) 

-300 (A6) al 

dO dl

APTR memBlock 

ULONG bytecount , flags 

Function: Clears a  memory block in ChipRAM. 

Parameters: memBloc Address of block 

flags Bit 0:1 Call WaitBlit()

Bit 1:0 bytecount =  size of range 

1 bytecount =  lines 

« 1 6+B y  tesPerLine 

Bit 2: 1 bytecount =  full value«16+size 

of range

| BltMaskBitMap RastPort Copy bit-map to a  RastPort with a  mask | 

Call: 

BltMaskBitMapRastPort 

(srcbm, srcx, srcy, destrp, destX,destY,sizeX, si2eY,minterm,bltmask) 

-636 (A6) aO do dl al d2 d3 d4 d5 d6 a2 

Functions, Parameters: 

Same as BltBitMapRastPort(), with the addition of the 

address of a  single bit-plane (bltmask) in which the affected bits are set.

| BltPattern Blit using a  mask j 

Coll: BltPattern (rp, mask, xl, yl, maxx, maxy, bytecnt) 

-312 (A6) al aO dO dl d2 d3 d4 

STRUCT RastPort *rp 

APTR mask 

SHORT xl,yl, maxx, maxy, bytecnt 

Function: Blits a  rectangular region at a  given position via a  mask, 

using the Drawmode and Areafill pattern entries from the
RastPort. 

Parameters: rp RastPort 

mask MaskBitPlane or 0  (rectangle) xl,yl Position in RastPort maxx,maxy

Size of range 

bytecnt Bytes per line in the mask

| BUT em plate Copy a  rectangular region to the RastPort | 

Call: BlcTemplatelSrcTemplate, SroX, SrcMod, rp, DstX, DsCY, SizeX, sizoV) 

-36 (A6) AO DO Dl Al D2 D3 D4 D5 

APTR SrcTemplate 

WORD SroX, SrcMod, DstX, DstY, SlzeX, SlzeY 

STRUCT RastPort *rp 

Function: Copies a  rectangular portion of a  bit-plane with the 

selected color and Drawmode to a  given position in a
RastPort. 

Parameters: SrcTemplate 

Address of the first word in the Bitlmage. 

SrcX X  bit offset from SrcTemplate (0..15). 

SrcMod Bytes per line in the Bitlmage. 

rp Destination RastPort.

DstX, DstY 

Coordinates in RastPort. 

SizeX, SizeY 

Size of range. 

IClipBlit BltBitMapQ, with layers] 

Call.' ClipBlit(Src, SrcX, SrcV, Dest, DestX, DestY, XSize, YSize, Minterm) 

-552 (A6) aO dO dl al d2 d3 d4 d5 d6 

STRUCT RastPort *Src,*Dest 

WORD SrcX.SrcY, DestX, DestY.XSize, YSize 

UBYTE Minterm 

Function: Same as BltBitMapO, except that the ClipRects are 

considered here. With windows, this function must be called instead of BltBitMapO.

Parameters: Src Source RastPort 

SrcX,SrcY Position in source RastPort. 

Dest Destination RastPort 

DestX,DestY 

Position in destination RastPort. 

XSize.YSize 

Size of range 

Minterm Logical combination (B=source, 

C=destination) 

ICopySBitMap Copy SuperBitMap range to a  layer | 

Call: CopySBitMap( layer ) 

-450 (A6) aO 

STRUCT Layer * layer 

Function: Opposite of SyncSBitMapO -  copies the current excerpt of 

a SuperBitMap to the given SuperBitMap layer.

Parameters: layer SuperBitMap layer (must be allocated with 

LockLayerROMO) 

IDisownBlitter Free Blitterl 

Call: DisownBlitter () 

-462 (A6) 

Function: Frees the Blitter for use by other programs. 

| OwnBlitter Obtain use of Blitter | 

Call: OwnBlitter () 

-456(A6) 

Function: Prevents other programs from using the Blitter. The Blitter 

becomes available only after it finishes its current operation
(seeWaitBlitO). 

IQBlit Enter BltNode in the Blitter list | 

Call: QBlit( bp ) 

-276 (A6) al 

STRUCT bltnode *bp 

Function: Enters a  BltNode in the wait queue of the Blitter. If the 

indicated routine is called, the Blitter stops work and becomes available, meaning it can be directly programmed. The routine must be executable in both supervisor and user modes.

Parameters: bp Initialized BltNode 

IQBSBlit QBlit with raster synchronization 

Call: QBSBlit( bsp ) 

-294 (A6) al 

STRUCT bltnode *bsp 

Function: Same as QBlit(), except that the routine is only called when 

the monitor beam reaches a  certain position. BltNodes entered with QBSBlit() take priority over QBlit() BltNodes.
Access by several tasks can lead to synchronization errors 

or true timing problems.

Parameters: bsp Initialized BltNode 

IScalerDiv Calculate scaling | 

Call: result =  ScalerDiv( factor, numerator, denominator) 

dO -684 (A6) dO dl d2

UWORD result , factor, numerator , denominator 

Function: Calculates factor*numerator/denominator just like 

BitMapScale(). For example, the new width can be 

calculated as width*XDestFactor/XSrcFactor.

Parameters: factor Width or height from BitMapScale(). 

numerator ?DestFactor denominator

?SrcFactor 

Result: factor*numerator/denominator 

IScrollRaster Scroll a  rectangular range | 

Call: ScrollRaster( rp, dx, dy, xmin, ymin, xmax, ymax) 

-396 (A6) al dO dl d2 d3 d4 d5 

STRUCT RastPort *rp 

WORD dx,dy, xmin, ymin, xmax, ymax 

Function: Moves the contents of a  rectangular range by the given 

delta value in the direction of coordinates (0,0). The bug that occurred in Kick 1.x, if the TmpRas structure was missing, has been fixed.

Parameters: rp RastPort 

dx.dy Delta value (right and down NEGATIVE) xmin.ymin Upper left comer xmax,ymax

Lower right corner 

ISyncSBitMap Copy layer contents to a  Super BitMapl 

Call: SyncSBitMap( layer ) 

-444 (A6) aO 

STRUCT Layer * layer 

Function: Copies the contents of a  SuperBitMap layer to the current 

position of the SuperBitMap.

Parameters: layer SuperBitMap layer (locked) 

[WaltBlit Wait for the Blitterj 

Call: WaitBlitO 

-228 (A6) 

Function: Waits until the Blitter finished its current work. This 

function is normally used after OwnBlitter() and/or before
DisownBlitter(). 

Dec Hex STRUCTURE BitMap.O BitMap 

0 $0 WORD bm_BytesPerRow  bytes per row 

2 $2 WORD bm_Rows rows 

4 $4 BYTE bm_Flags  Flags 

5 $5 BYTE bm_Depth  number of BitPlanes 

6 $6 WORD bm_Pad 

8 $8 STRUCT bm_Planes,8*4  PlanePointer 

40 $28 LABEL bm_SIZEOF 

Dec Hex STRUCTURE BitScaleArgs, 0 BitMapScale () argument 

2 $2 UWORD bsa_SrcX /source position 

4 $4 UWORD bsa_SrcY 

6 $6 UWORD bsa_SrcWidth ,- source size 

8 $8 UWORD bsa_SrcHeight 

$A UWORD 

bsa_XSrcFactor denominators

$C UWORD 

bsa_YSrcFactor

$E. UWORD 

bsa_DestX destination position

$10 UWORD 

bsa_DestY

$12 UWORD 

bsa_DestWidth result

$14 UWORD 

bsa_DestHeight

$16 UWORD 

bsa_XDestFactor numerators

$18 UWORD 

bsa_YDestFactor

$1A APTR 

bsa_SrcBitMap source BitMap

$1E APTR 

bsa_DestBitMap destination BitMap

$22 ULONG 

bsa_Flags

0! 

$26 UWORD 

bsa_XDDA

$28 UWORD 

bsa_YDDA

$2A LONG 

bsa_Reservedl

$2E LONG 

bsa_Reserved2

$32 LABEL 

bsa_SIZEOF

3. Refresh Functions 

|AndRectRegion 

Preserve contents of a  rectangle] 

Call: AndRectRegion (region, rectangle) 

-504 (A6) aO al 

STRUCT Region *region 

STRUCT Rectangle *rectangle 

Function: Deletes everything in the region outside of the given 

rectangle.

Parameters: region Region structure 

rectangle Rectangle structure

AndRegionRegion 

Trim a  region | 

Call: status AndRegionRegion (regionl,region2) 

dO -624 (A6) aO al

BOOL status 

STRUCT Region *regionl, *region2 

Function: Cut off surfaces from region2 that are not part of region 1 . 

Parameters: regionl Mask region 

region2 Destination region

Result: 0  Error (no memory) 

IClearRectRegion Clear a  rectangle within a  regionl 

Call: status =  ClearRectRegion (region, rectangle) 

dO -522 (A6) aO al

BOOL error 

STRUCT Region *region 

STRUCT Rectangle *rectangle 

Function: Cuts a  rectangle out of a  region. 

Parameters: region Region containing the rectangle. 

rectangle Rectangle to be deleted.

Result: 0  Error (no memory) 

IClearRegion Clear all rectangles within a  regionl 

Call: ClearRegion (region) 

-528 (A6) aO 

STRUCT Region *region 

Function: Clears an entire region. 

Parameters: region Region to be cleared 

fDisposeRegion Free regionl

Call: DisposeRegion (region) 

-534 (A6) aO 

STRUCT Region *region 

Function: Frees the memory of a  region. 

Parameters: region Region structure 

|NewRegion Get a  Region structure | 

Call: region NewRegion ( ) 

dO -516 (A6)

STRUCT Region *region 

Function: Allocates memory for a  Regions structure and initializes it. 

Result: Region structure or 0. 

IQrRectRegion Insert rectangle into a  region! 

Call: status =  OrRectRegion (region, rectangle) 

dO -510 (A6) aO al

BOOL status 

STRUCT Region *region 

STRUCT Rectangle *rectangle 

Function: Inserts the given rectangle (not contained in the region) 

into the given region.

Parameters: region Region structure 

rectangle Rectangle structure

Result: 0  Error 

IQrRegionRegion Join Region structures! 

Call: status OrRegionRegion(regionl,region2) 

dO -612 (A6) aO al

BOOL status 

STRUCT Region *regionl, *region2 

Function: Adds region 1  to region2. 

Parameters: region 1  ,region2 

Region structures 

Result: 0  Error 

IXorRect Region Exclusive OR combination of two areas | 

Call: status =  XorRectRegion (region, rectangle) 

dO -558 (A6) aO al

BOOL status 

STRUCT Region *region 

STRUCT Rectangle *rectangle 

Function: Adds the given rectangle (not contained in the region) to 

the given region, and deletes the part of the region common to both.

Parameters: region Region structure 

rectangle Rectangle structure

Result: 0  Error 

IXorRegionRegion Exclusive OR combination of two regions] 

Call: status =  XorRegionRegion(regionl,region2) 

dO -618 (A6) aO al

BOOL status 

STRUCT Region *regionl, *region2 

Function: Adds one region to the other and deletes the overlapping 

area.

Parameters: regionl,region2 

Regions to be combined 

Result: 0  Error 

Dec Hex STRUCTURE Rectangle, 0  rectangle 

0 $0 WORD ra_MinX  dimens ions 

2 $2 WORD ra_JlinY 

4 $4 WORD ra_MaxX 

6 $6 WORD ra_MaxY 

8 $8 LABEL ra_SIZEOF 

Dec Hex STRUCTURE Rect32,0 32 bit rectangle 

0 $0 LONG r32_MinX  dimensions 

4 $4 LONG r32_MinY 

8 $8 LONG r32_MaxX 

12 $C LONG r32_MaxY 

16 $10 LABEL r32_SIZEOF 

Dec Hex STRUCTURE Region, 0 

0 $0 STRUCT rg_bounds,ra_SIZEOF 

8 $8 APTR rg_RegionRectangle 

12 $C LABEL rg_SIZEOF 

Dec Hex STRUCTURE RegionRectangle, 0 

0 $0 APTR rr_Next 

4 $4 APTR rr_Prev 

8 $8 STRUCT rr_bounds,ra_SIZEOF 

16 $10 LABEL rr_SIZEOF 

4. Data Structures 

jAllocRaster Allocate memory for a  bit-plane 1

Call: planeptr =  AllocRaster( width, height ) 

dO -492(A6) d0:16 dl:16

APTR planeptr 

USHORT width, height 

Function: Allocates the ChipRAM required for a  bit-plane of the 

given size.

Parameters: width Bit-plane width in pixels. 

height Bit-plane height in pixels.

Result: Address of memory block or 0. 

| AttemptLockLayerRom Attempt to lock a  layer | 

Call: gotit =  AttemptLockLayerRom (   layer ) 

dO -654 (A6) a5

BOOLEAN gotit 

STRUCT Layer * layer 

Function: Attempts to lock a  layer with exclusive access rights. 

Parameters: layer Layer structure 

Result: 0  No access to layer. 

IFreeColorMap Free a  ColorMap! 

Call: FreeColorMap (   colormap ) 

-576 (A6) aO 

STRUCT ColorMap *colormap 

Function: Frees the memory used by a  structure allocated with 

GetColorMap(). 

Parameters: colormap Address of the ColorMap. 

|FreeRaster Free a  bit-plane 

Call: FreeRaster( p, width, height) 

-498 (A6) aO d0:16 dl:16 

APTR p 

USHORT width, height 

Function: Frees the memory used for a  bit-plane. 

Parameters: p  PlaneAddress 

width Width in bits height Height of bit-plane
IGetColorMap Allocate a  ColorMap | 

Call: cm =  GetColorMap( entries ) 

dO -570 (A6) dO

STRUCT ColorMap *cm 

LONG entries 

Function: Allocates memory for a  ColorMap and initializes the 

structure.

Parameters: entries Number of colors 

Result: ColorMap or 0. 

GetRGB4 

Allocate a  3x4 bit color value]

Call: value =  GetRGB4 (   colormap, entry ) 

dO -582 (A6) aO dO

ULONG value 

STRUCT ColorMap *colormap 

LONG entry 

Function: Reads the color value of a  color number from the given 

ColorMap. 

Parameters: colormap ColorMap structure 

entry Color number (0...)

Result: red value«8+green value«4+blue value (4 bits each: 

0...15) or -1 (entry not available, error) 

Example: Get the color values for the background color of a 

ViewPort and set them in a  second ViewPort (Warning: 

doing this by hand could cause problems with the new 24 bit ColorMaps): movea .

_Gf xBase, a6 

movea .

_ViewPortl,aO 

movea . vp_ColorMap (aO ) , aO moveq

#0,d0 

jsr

_LVOGetRGB4(a6) 

tst .w dO bmi

_Zerror 

moveq

#15, d3 

mask for blue value and.w d0,d3 blue value lsr.w

#4,d0 

moveq

#15, d2 

green value mask and.w d0,d2 green value lsr.w

moveq

#15, dl 

red value mask and.w dO.dl red value moveq

color number movea . 1 _ViewPort2 aO

2nd Viewport 

jsr

_LVOSetRGB4(a6) 

Unit Bit Map

Initialize a  BitMap structure 

Call: InitBitMap ( bm, depth, width, height ) 

-390 (A6) aO dO dl d2 

STRUCT BitMap *bm 

BYTE depth 

UWORD width , height 

Function: Initializes a  BitMap structure. The bit-plane addresses are 

excluded in order to keep the size of the structure variable.

Parameters: bm 

depth width

BitMap structure to be initialized. 

Number of bit-planes 

Width in bits 

height Height of bit-plane llnitRastPorT

Initialize a  RastPortl 

Call: initRastPort (  rp ) 

-198 (A6) al 

STRUCT RastPort *rp 

Function: Initializes a  RastPort structure with the standard values 

(Mask=-1, FgPen=-l, AOLPen=-l, LinePtrn=-l, 

DrawMode=JAM2, Font=Systemfont). 

Parameters: rp 

RastPort structure 

llnitTmpRas Initialize TmpRas]

Call: InitTmpRas (tmpras, buffer, size) 

-468 (A6) aO al dO 

STRUCT TmpRas *tmpras 

APTR buffer 

LONG size 

Function: Initializes a  TmpRas structure with a  buffer for intensive 

graphics operations (AreaEnd(), Flood(), Text()).

Parameters: tmpras TmpRas structure 

buffer ChipRAM buffer size Buffer size

|InitView Initialize View structure | 

Call: InitView( view ) 

-360(A6) al 

STRUCT View *view 

Function: Initializes a  View structure with the standard values. 

Parameters: view View structure 

InitVPort Initialize ViewPort structure] 

Call: InitVPort (  vp ) 

-204 (A6) aO 

STRUCT Viewport *vp 

Function: Initializes a  ViewPort structure with the standard values. 

Parameters: vp ViewPort structure 

|LockLayerRom Obtain access to a  layer | 

Call: LockLayerRom (   layer ) 

-432 (A6) a5 

STRUCT Layer * layer 

Function: Obtains exclusive access to a  layer. No Intuition functions 

may be called during this time, since most of the work is done by the input Handler Intuition(), which also must use locking to obtain exclusive access. There is no problem calling LockLayerRom() with libraries that are not based on a  single task, since this function first checks to see if the active task already has access to the layer.

Parameters: layer Layer structure 

|SetRGB4CM Enter a  color] 

Call: SetRGB4CM(cm, n, r, g, b) 

-630 (A6) aO dO dl:4 d2:4 d3:4 

STRUCT ColorMap *cm 

SHORT n 

UBYTE r,g,b 

Function: Enters the intensity values for a  color in a  ColorMap. This 

function is used to create color tables before entering in a
ViewPort. 

Parameters: cm ColorMap 

n Color number (0.. .31) r,g,b 4  bit intensity value (0...15) lUnlockLayerRom Free a  layer |

Call: UnlockLayerRom (   layer ) 

-438 (A6) a5 

Function: Frees exclusive access rights to a  layer. 

Parameters: layer 

Locked layer 

NEWLOCKE 

= 1  new Layer lock 

Dec Hex 

STRUCTURE Layer, 0 

range for clipping

0 $0 

LONG 

lr_front , foreground Layer

4 $4 

LONG 

lr_back , background Layer

8 $8 

LONG 

lr_ClipRect ,

ClipRect 

12 $C 

LONG 

lr_rp ,

RastPort 

16 $10 

WORD 

lr_MinX range

18 $12 

WORD 

lr_MinY

20 $14 

WORD 

lr_MaxX

22 $16 

WORD 

lr_MaxY

24 $18 

STRUCT 

lr_reserved, 4 reserved

28 $1C 

WORD 

lr_priority priority

30 $1E 

WORD 

lr_Flags

Flags 

32 $20 

LONG 

lr_SuperBitMap

BitMap 

36 $24 

LONG 

lr_SuperClipRect

ClipRect 

40 $28 

APTR 

lr_Window window

44 $2C 

WORD 

lr_Scroll_X

BitMap offsets 

46 $2E WORD 

lr_Scroll_Y

48 $30 

APTR 

lr_cr

ClipRect 

52 $34 

APTR 

lr_cr2

ClipRect 

56 $38 

APTR 

lr_crnew

ClipRect 

60 $3C 

APTR 

lr_SuperSaverClipRects

ClipRects 

64 $40 

APTR 

lr cliprects

ClipRects 

68 $44 

APTR 

lr_LayerInfo

•Layer Info 

72 $48 

STRUCT 

lr_Lock,SS_SIZE

• SignalSemaphore 

118 $76 

APTR 

lr_BackFill

•backfill Hook 

122 $7A ULONG 

lr_reservedl reserved

126 $7E 

APTR 

lr_ClipRegion region

130 $82 

APTR 

lr_saveClipRects

ClipRects 

134 $86 

STRUCT 

lr_reserved2 , 22 reserved (SS_SIZE)

156 $9C 

APTR 

lr_DamageList damage list

160 $A0 

LABEL 

lr_SIZEOP

Dec Hex 

STRUCTURE CI ipRect , 0 

0 $0 

LONG 

cr_Next next ClipRe zt

4 $4 

LONG 

cr_prev  previous CI ipRect

8 $8 

LONG 

cr_lobs

12 $C 

LONG 

cr_BitMap

BitMap 

16 $10 

WORD 

cr_MinX range

18 $12 

WORD 

cr_MinY

20 $14 

WORD 

cr_MaxX

22 $16 

WORD 

cr_MaxY

24 $18 

APTR 

cr pi

28 $1C 

APTR 

cr p2

32 $20 LONG cr_reserved 

3 6  $24 LONG cr_Flags  Flags 

40 $28 LABEL cr_SIZEOF 

CR_NEEDS_NO_CONCEALED_RASTERS =  1  internal Flag 

CR_NEEDS_NO_LAYERBLIT_DAMAGE =  2 

ISLESSX =  1  Flags for clipping 

ISLESSY =  2 

ISGRTRX =  4 

ISGRTRY =  8 

LAYERS IMPLE =  1 

LAYERSMART =  2 

LAYERSUPER =  4 

LAYERUPDATING =  $10 

LAYERBACKDROP =  $40 

LAYERREFRESH =  $80 

LAYER_CLIPRECTS_LOST =  $100 

LMN_REGION =  -1 

Dec Hex STRUCTURE Layer_Info, 0 

0 $0 APTR li_top_layer top Layer 

4 $4 APTR li_check_lp 

8 $8 APTR li_obs 

12 $C STRUCT li_FreeClipRects,MLH_SIZE 

24 $18 STRUCT li_Lock, SS_SIZE 

70 $46 STRUCT li_gs_Head, LH_SIZE 

84 $54 LONG li_long_reserved 

88 $58 WORD li_Flags 

90 $5A BYTE li_fatten_count 

91 $5B BYTE li_LockLayersCount 

92 $5C WORD li_LayerInfo_extra_size 

94 $5E APTR li_blitbuff 

98 $62 APTR li_LayerInf o_extra 

102 $66 LABEL li_SIZEOF 

NEWLAYERINFO_CALLED =  1 

5. Draw Functions 

| AreaDraw Define corner point for AreaFillj 

Call: error =  AreaDraw (    rp, x, y) 

dO -258 (A6) Al D0,D1

LONG error 

STRUCT RastPort *rp 

SHORT x,y 

Function: Inserts a  point in the vector list for AreaFill. 

Parameters: rp RastPort with Arealnfo 

x,y Point coordinates

Result : 0  No error 

lAreaEllipse

Insert an ellipse for AreaFill in Arealnfo | 

Call: 

error =  AreaEllipse( rp, ex, cy, a, b) dO -186 (A6) al dO dl d2 d3

LONG error 

STRUCT RastPort *rp 

SHORT cx,cy,a,b 

Function: Stores an ellipse in the vector buffer. 

Parameters: rp RastPort with Arealnfo 

cx.cy a b

Result: 

Center of ellipse 

Horizontal radius (a>0) 

Vertical radius (b>0) 

No error 

lAreaEnd Execute AreaFill according to vector table contents!

Call: 

Function: 

error =  AreaEnd(rp) dO -264 (A6) Al

LONG error 

STRUCT RastPort *rp 

Processes the vector buffer of the Area routines and fills the 

calculated area. Re-initializes for new AreaMoveQ calls.

Parameters: rp RastPort 

Result: 0  No error 

|AreaMove Define starting point for AreaFill| 

Call: error =     AreaMove (   rp, x, y) 

dO -252 (A6) al dO dl

LONG error 

STRUCT RastPort *rp 

SHORT x,y 

Function: Closes the last polygon and begins a  new one. 

Parameters: rp RastPort with Arealnfo 

x,y Position of the starting point

Result: 0  No error 

lUraw Draw a  linel

Call: Draw( rp, x, y) 

-246 (A6) al dO dl 

STRUCT RastPort *rp 

SHORT x,y * 

Function: Draws a  line from the current position to the given 

coordinates.

Parameters: rp RastPort 

x,y Destination coordinates

| DrawEllipse Uraw an ellipse] 

Call: DrawEllipse ( rp, ex, cy, a, b   ) 

-180 (A6) al dO dl d2 d3 

STRUCT RastPort *rp 

SHORT cx,cy,a,b 

Function: Draws an ellipse in RastPort. 

Parameters: rp RastPort 

cx,cy Center of ellipse a Horizontal radius (a>0) b Vertical radius (b>0)

I EraseRect Fi» a  rectangle using the Back* ill hook | 

Call: EraseRect (   rp, xmin, ymin, xmax, ymax) 

-810 (A6) al d0:16 dl:16 d2:16 d3:16 

STRUCT RastPort *rp 

SHORT xmin, ymin, xmax, ymax 

Function: Fills a  rectangular area in a  RastPort. If the RastPort layer is 

showing, then the BackFill hook is used. Otherwise, the rectangle is deleted.

Parameters: rp RastPort 

xmin,ymin Upper left corner of rectangle xmax,ymax

Lower right corner of rectangle 

iFlood Fill an areal

Call: error =  Flood ( rp, mode, x, y) 

dO -330 (A6) al d2 dO dl

BOOL error 

STRUCT RastPort rp 

ULONG mode 

SHORT x,y 

Function: 

Fills an area of any complexity with the color or pattern set 

in the current draw mode.

Parameters: 

Result: 

llnitArea rp

*.y 

mode

RastPort with TmpRas 

Starting point for fill 

Fill mode (0: through AOLPen, 1: only points 

with the color at x-y)

Okay 

Initialize Arealnfo vector matrix 

Call: lnitArea( areainfo, buffer, maxvectors ) 

-282 (A6) aO al d0 

STRUCT Areainfo *areainfo 

APTR buffer 

SHORT maxvectors 

Function: Initializes the vector table for Area commands. The given 

buffer must have at least five bytes per vector. Remember that AreaEllipseO needs two vectors, and AreaEnd() needs one.

Parameters: areainfo Areainfo structure 

buffer Vector buffer (5*maxvectors+5) maxvectors

Maximum vectors 

| Move 

Set coordinates for graphics output | 

Call: Move( rp, x, y) 

-240 (A6) al dO dl 

STRUCT RastPort *rp 

SHORT x,y 

Function: Sets the coordinates for graphics output in the RastPort. 

Parameters: rp 

x,y
| Poly Draw 

RastPort 

Coordinates 

Draw a  line according to coordinates in a  table 

Call: PolyDraw( rp, count ,   array ) 

-336 (A6) al dO aO 

STRUCT RastPort *rp 

WORD count 

APTR array 

Function: Draws from point to point according to the values in a 

coordinate table. This function is the same as a  Move() call to the first coordinates followed by subsequent Draw() calls.

Parameters: rp RastPort 

count Number of coordinate points. array Array with two words per entry (x and y).

IReadPixel 

Read the color number of a  pixel | 

Call: penno =  ReadPixel (   rp, x, y   ) 

dO -318 (A6) al dO dl

LONG penno 

STRUCT RastPort *rp 

SHORT x,y 

Function: Gets the color number of the pixel at the given coordinates 

in a  RastPort.

Parameters: rp 

x,y

RastPort 

Coordinates 

Result: Color number (0..255) or -1 (coordinates outside of 

RastPort) 

I Read Pixel Array8 

Call: 

Read the color numbers of a  rectangle I 

count =  ReadPixelArray8(rp,xstart,ystart,xstop,ystop,array,t<anprp) dO -780(A6) aO dOsU dl:16 d2:16 d3:16 a2 al

UJNG count 

STRUCT RastPort *rp,*temprp 

UWORD xstart,ystart,xstop,ystop 

APTR array 

Function: ReadPixel() for each point within a  rectangular area of a 

RastPort. The results are written as bytes to the given 

buffer.

Parameters: rp 

RastPort structure 

xstart,ystart

Starting point in RastPort. 

Result: ] 

Example: 

movea . I l _Gf xBase, a6 movea.l _RastPort,aO moveq

#8,d0 

moveq

#16, dl 

moveq

#24, d2 

moveq

#32, d3 

lea

_Array,a2 

lea

_TtapRp,al 

jsr

_LVOReadPixelArray8 (a6) 

xstop,ystop

End point in RastPort. 

array Results buffer, at least

((((width+15)»4)«4)*(ystop-ystart+l)) 

bytes. temprp Temporary RastPort (copy with layer=0 and a bit-map that can store one row of the rectangular area).

Number of pixels read. 

Read a  16*16 pixel area: 

_Array 

ds.b 16*16

_TmpRp .-previously initialized 

| Read PixelLine8 Read color numbers of a  horizontal line | 

Call: count =  ReadPixelLine8(rp,xstart,ystart, width, array, temprp) 

dO -768 (A6) aO d0:16 dlsl6 d2 a2 al

LONG count 

STRUCT RastPort *rp, "temprp 

WORD xstart,y start, width 

APTR array 

Function: Like ReadPixelArray8(), but for only one line. 

Parameters: rp RastPort 

x,y Starting point width Line width (in pixels) array Results buffer, at least (((width+15)»4)«4) bytes. temprp Same as with ReadPixelArray8().

I ReciFill Fill a  rectangle | 

Call: RectFilK rp, xmin, ymin, xmax, ymax) 

-306(A6) al d0:16 dl:16 62:16 63:16 

STRUCT RastPort *rp 

SHORT xmin, ymin, xmax, ymax 

Function: Fills a  rectangle in a  RastPort with the set color or pattern. 

Parameters: rp RastPort 

xmin,ymin Upper left corner of rectangle xmax.ymax

Lower right corner of rectangle 

ISetAPen Set color for drawing! 

Call: SetAPen( rp, pen ) 

-342 (A6) al dO 

STRUCT RastPort *rp 

UBYTE pen 

Function: Sets the foreground color for graphics operations. 

Parameters: rp RastPort 

pen Color number (0...255)

ISetBPen Set the background color | 

Call: SetBPen( rp, pen ) 

-348 (A6) al dO 

STRUCT RastPort *rp 

UBYTE pen 

Function: Sets the second color for graphics operations. 

Parameters: rp RastPort 

pen Color number (0...255)

| SetDrMd Set draw mode] 

Call: SetDrMd (  rp, mode ) 

-354(A6) al d0:8 

STRUCT RastPort *rp 

UBYTE mode 

Function: Sets the draw mode for drawing, text output, and filling 

areas.

Parameters: rp RastPort 

mode JAM1 , JAM2, etc.

Example: Output shaded text: 

**_ 

** 

**_ 

** 

** 

** 

** 

** 

** 

**_ 

Shadow print 

* * 

* * 

* * 

* * 

* * 

Input: al =  RastPort 

aO =  Text dO =  Text color dl =  Shadow color d2 =  xPos d3 =  yPos

_ShadowPrint 

movem.l d0-d4/a0-al/a6, ■ movea.l _Gf xBase, a6 moveq #RP_JAM1 , dO jsr _LVOSetDrMd(a6)

(a7) 

foreground color only

StrLen 

moveq

#-l,dO 

sub. 1 aO.dO

StrLenLoop 

tst.b

(a0) + 

bne.s

.StrLenLoop 

add.l aO.dO move . 1 d0,d4 move . 1

4(a7),d0 

addq.w

#l,d2 

addq.w

#l,d3 

bsr .s

.GiveOut 

move . 1

(a7),d0 

subq.w

subq.w

bsr .s

.GiveOut 

movent . 1

(a7 ) +, d0-d4/a0-al/a6 

rts

.GiveOut 

movea.l 28(a7),al jsr _LVOSetAPen(a6) movea.l 28(a7),al move.l d2,d0 move .1 d3 , dl jsr _LVOMo ve ( a 6 ) movem.l 24(a7),a0-al move .1 d4 , dO jmp _LVOText(a6)

ISetRast 

Fill an area with a  color | 

Call: SetRast (  rp, pen ) 

-234 (A6) al dO 

STRUCT RastPort *rp 

UBYTE pen 

Function: Fills the RastPort with the given color. 

Parameters: rp RastPort 

pen Color number (0...255)

IWritePixel 

Draw a  pixel | 

Call: error =  WritePixel (   rp, x, y) 

dO -324 (A6) al DO Dl

LONG error 

STRUCT RastPort *rp 

SHORT x,y 

Function: Places a  pixel at the given coordinates in the RastPort 

using the foreground color.

Parameters: rp 

x,y
Result: 0 

RastPort 

Pixel coordinates 

Okay, -1 coordinates outside of RastPort. 

fWritePixelArray8 Draw a  multi-colored rectangle!

CO.ll: count c  WritePixelArray8(rp,xstart,ystart,xstop,ystop, array, temprp) 

dO -786IA6) aO d0:16 dl:16 d2:16 d3:16 a2 al

LONG count 

STRUCT RastPort *rp,*temprp 

UWORD xstart,ystart,xstop,ystop 

APTR *array 

Function: Fills a  rectangle with pixels. The color numbers are given in 

a byte field.

Parameters: See ReadPixelArray8(). 

Result: Number of pixels drawn. 

Example : Write a  1 6* 1 6 pixel area: 

movea . 1 _Gf xBase , a6 movea.l _RastPort,aO moveq #8,d0 moveq #16, dl moveq #24, 62 moveq #32, d3 lea _Array,a2 lea _TmpRp,al jsr _LVOWritePixelArray8(a6)

.Array 

ds.b 16*16 previously read, manipulated, etc.

_TmpRp already initialized 

| WritePixelLine8 Draw a  multi-colored horizontal line| 

Call: count =  WritePixelLine8 (rp,xstart,ystart, width, array, temprp) 

dO -774(A6) aO d0:16 dl:16 d2 a2 al

LONG count 

STRUCT RastPort *rp, * temprp 

UWORD xstart,ystart, width 

APTR array 

Function: Draws a  horizontal line with the color numbers given in a 

byte field.

Parameters: See ReadPixelLine8(). 

Result: Number of pixels drawn. 

Dec Hex STRUCTURE TmpRas , 0 

0 $0 APTR tr_RasPtr 

4 $4 LONG tr_Size 

8 $8 LABEL tr_SIZEOF 

temporary raster buffer
/buffer size 

RPB_FRST_DOT =  0, 

RPB_ONE_DOT =  1, 

RPB_DBUFFER =  2, 

RPB_AREAOUTLINE =  3, 

RPB_NOCROSSFILL =  5, 

RPF_FRST_DOT = 

RPF_ONE_DOT 

RPF_DBUFFER = 

RPF_AREAOUTLINE = 

RPF_NOCROSSFILL = 

1  first pixel also 

2 pixel line 

4  double buffering 

8 /outline mode 

16 AreaFill mode 

RP_JAM1 

= 0  /without background 

RP_JAM2 

= 1  with background 

RP_COMPLEMENT 

= 2   complement 

RP_INVERSVID 

= 4   invert 

RPB_TXSCALE = 

0, RPFJTXSCALE =  1 

Dec Hex 

STRUCTURE RastPort,0 

0 $0 

LONG 

rp_Layer

4 $4 

LONG 

rp_BitMap

8 $8 

LONG 

rp_AreaPtrn

12 $C 

LONG 

rp_TmpRas

16 $10 

LONG 

rp_AreaInfo

20 $14 

LONG 

rp_GelsInfo

24 $18 

BYTE 

rp_Mask

25 $19 

BYTE 

rp_FgPen

26 $1A BYTE 

rp_BgPen

27 $1B 

BYTE 

rp_AOLPen

28 $1C 

BYTE 

rp_DrawMode

29 $1D 

BYTE 

rp_AreaPtSz

30 $1E 

BYTE 

rp_linpatcnt

31 $1F 

BYTE 

rp_Dummy

32 $20 

WORD 

rp_Flags

34 $22 

WORD 

rp_LinePtrn

36 $24 

WORD 

rp_cp_x

$26 

WORD 

rp_cp_y

$28 

STRUCT 

rp_minterms , 8

$30 

WORD 

rp_PenWidth

$32 

WORD 

rp_PenHeight

$34 

LONG 

rp_Font

$38 

BYTE 

rp_AlgoStyle

$39 

BYTE 

rp_TxFlags

$3A 

WORD 

rp_TxHeight

$3C WORD 

rp_TxWidth

$3E 

WORD 

rp_ TxBaseline

$40 

WORD 

rp_TxSpacing

$42 

APTR 

rp_RP_User

$46 

STRUCT 

rp_longreserved, 8

$4E 

STRUCT 

rp_wordreserved, 1

$5C 

STRUCT 

rp_reserved, 8

$64 

LABEL 

rp_SIZEOF

Dec 

Hex 

STRUCTURE Arealnfo, 0 

$0 

LONG 

ai_VctrTbl

$4 

LONG 

ai_VctrPtr

$8 

LONG 

ai_FlagTbl

$c 

LONG 

ai_FlagPtr

$10 

WORD 

ai_Count

$12 

WORD 

ai_MaxCount

$14 

WORD 

ai_FirstX

$16 

WORD 

ai_FirstY

$18 

LABEL 

ai_SIZEOF

Example: 

6. Text Output 

A routine could calculate the color values for an apple man
(fractal, Mandelbrot set) and store them in byte arrays, 

which can then be output at the end of a  line with
WritePixelLine8(). 

I Add Font 

Add a  font to the system list | 

Call: AddFont( text Font) 

-480 (A6) al 

STRUCT TextFont *textFont 

Function: Adds the given font to the system list. 

Parameters: textFont TextFont structure 

| AskFont Get the attributes of the current font | 

Call: AskFont (rp, textAttr) 

-474 (A6) al aO 

STRUCT RastPort *rp 

STRUCT TextAttr *textAttr 

Function: Fills the given TextAttr structure with information on the 

RastPort font. 

Parameters: rp RastPort 

textAttr TextAttr structure lAskSoftStyle Get the current stylel

Call: enable =  AskSoftStyle(rp) 

dO -84 (A6) al

ULONG enable 

STRUCT RastPort *rp 

Function: For the given RastPort, it returns the style currently being 

generated by the software.

Parameters: rp RastPort 

Result: Style (bit mask, undefined bits are set) 

I Clear EOL Delete the rest of the line | 

Call: ClearEOM rp ) 

-42 (A6) al 

STRUCT RastPort *rp 

Function: Deletes the rest of a  text line starting from the current 

position.

Parameters: rp RastPort 

| ClearScreen Deletes the RastPort from the current position | 

Call: ClearScreen (   rp ) 

-48 (A6) al 

STRUCT RastPort *rp 

Function: Deletes the rest of the RastPort starting from the current 

text position (ClearEOL(), then continue down to the bottom edge).

Parameters: rp RastPort 

ICloseFont Free a  font 

Call: closeFont ( font ) 

-78 (A6) al 

STRUCT TextFont *font 

Function: Notifies the system that the given font is no longer being 

used.

Parameters: font Result from OpenFont()/OpenDiskFont() 

|ExtendFont Create tf Extension | 

Call: success =  ExtendFont (font, fontTags) 

DO -816 (A6) AO Al 

ULONG success 

STRUCT TextFont *font 

STRUCT Tagltem *fontTags 

Function: Assure that tfJExtension is available. 

Parameters: font TextFont structure 

fontTags Tagltem field

Result: 0  Error 

| FontExtent Get font attributes | 

Call: FontExtent (font, fontExtent) 

-762 (A6) aO al 

STRUCT TextFont *font 

STRUCT TextExtent * fontExtent 

Function: Fills the given FontExtent structure with information on 

the given font.

Parameters: font TextFont 

fontExtent FontExtent structure to be filled.

I OpenFont Open a  font | 

Call: font =  OpenFont (textAttr) 

dO -72 (A6) aO

STRUCT TextFont *font 

STRUCT TextAttr *textAttr 

Function: Searches the GfxLibrary list to find the font that most 

closely matches the data given in the TextAttr structure, and opens it.

Parameters: textAttr TextAttr or XTextAttr structure 

Result: TextFont address if a  font with the given name was found, 

or 0. Warning: the attributes of the returned font may not exactly match the requested attributes (different height, etc.).

| RemFont Remove a  font from the system list I 

Call: RemFont (textFont) 

-486 (A6) al 

STRUCT TextFont * textFont 

Function: Removes a  font from the system list (as long as it is no 

longer required).

Parameters: textFont TextFont structure for the font. 

ISetFont Set font] 

Call: SetFont(rp, font) 

-66 (A6) al aO 

STRUCT RastPort *rp 

STRUCT TextFont *font 

Function: Sets the font to be used by a  RastPort. If the font does not 

conform with the standards, then an attempt is made to convert it to a  usable format.

Parameters: rp RastPort 

font Result from OpenFont() or OpenDiskFont().

[ SetSoftSty le Set software style | 

Call: newStyle =  SetSoftStyle(rp, style, enable) 

dO -90 (A6) al dO dl

ULONG newStyle , style , enable 

STRUCT RastPort *rp 

Function: Changes the software style of the current font. 

Parameters: rp RastPort 

style New values for the bits. enable Bit mask with bits to be changed.
Result: Value with the new style. 

IStripFont Remove tf Extension | 

Call: StripFont ( font ) 

-822 (A6) AO 

STRUCT TextFont *font 

Function: Converts a  2.x font into a  1 .x font. 

Parameters: font TextFont structure for the font. 

| Text Output a  string | 

Call: Text( rp, string, length) 

-60 (A6) al aO dO 

STRUCT RastPort *rp 

APTR string 

WORD length 

Function: Outputs text to the current position in the RastPort. 

Parameters: rp RastPort 

string Address of first character of the output string. length Number of characters.

| TextExtent Calculate dimensions of a  text output | 

Call: TextExtent (rp, string, count, textExtent) 

-690 (A6) al aO d0:16 a2 

STRUCT RastPort *rp 

APTR string 

WORD count 

STRUCT TextExtent *textExtent 

Function: Fills a  TextExtent structure with the calculated dimensions 

of an output string.

Parameters: rp 

string count

RastPort 

Address of first character 

Number of characters 

Result: 

textExtent Data structure for result
Filled TextExtent structure 

ITextFit 

Calculate proper text length] 

Call: chars =  TextFit(rp, s, sL, tE, cE, sD, cBW, cBH) 

dO -696 (A6) al aO dO a2 a3 dl d2 d3

ULONG chars 

STRUCT RastPort *rp 

APTR s 

OWORD sL, sD, cBW, cBH 

STRUCT TextExtent *tE,cE 

Function: Checks how many characters and returns a  TextExtent 

structure of the proper length.

Parameters: rp 

s sL tE cE sD cBW cBH

RastPort 

String 

String length 

TextExtent structure for the result. 

Given TextExtent structure of 0. 

Offset from one character of the string to the 

next.

Bit width (alternative to cE) 

Bit height (alternative to cE) 

Result: Number of characters that will fit in the area (0 is possible). 

| TextLength Length of a  text output in a  RastPort I 

Call: length =  TextLength (rp, string, count) 

dO -54 (A6) al aO d0:16

WORD length, count 

STRUCT RastPort *rp 

APTR string 

Function: Returns the length of a  text output in pixels. 

Parameters: rp RastPort 

string String address count String length

Result: Text length in pixels. 

WeighTAMatch Compare fonts | 

Call: weight =  WeighTAMatch (reqTextAttr, targetTextAttr, targetTags) 

dO -804 (A6) aO al a2

WORD weight 

STRUCT TTextAttr 'reqTextAttr 

STRUCT TextAttr 'targetTextAttr 

STRUCT Tagltem *targetTags 

Function: Compares two TextAttr structures and returns a  value that 

describes how well they match. The best result is
MAXFONTMATCHWEIGHT (perfect match), the worst 

case is 0. The names are not compared.

Parameters: reqTextAttr 

Desired TextAttribute 

targetTextAttr

Potential TextAttribute 

Result: 

targetTags Extended attributes for targetTextAttr or 0.
Match value (0...MAXFONTMATCHWEIGHT) 

FS_NORMAL =  0  normal style 

FSB_UNDERLINED =  0, 

FSB_BOLD =  1, 

FSB_ITALIC =  2, 

FSB_EXTENDED =  3, 

FSB_COLORFONT =  6, 

FSB_TAGGED =  7, 

FSF_UNDERLINED =  1 

FSF_BOLD =  2 

FSF_ITALIC =  4 

FSF_EXTENDED =  8 

FSF_COLORFONT =  $40 

underline bold italics extended colored

FSF_TAGGED 

= $80 TTextAttr 

FPB_ROMFONT =  0, 

FPB_DISKFONT =  1, 

FPB_REVPATH =  2, 

FPB_TALLDOT =  3, 

FPB_WIDEDOT =  4, 

FPB_PROPORTIONAL =  5, 

FPB_DESIGNED =  6, 

FPB_REMOVED =  7, 

FPF_ROMFONT 

FPF_DISKFONT 

FPF_REVPATH 

FPF_TALLDOT 

FPF_WIDEDOT 

FPF_PROPORTIONAL 

FPF_DESIGNED 

FPF_REMOVED 

$10 

$20 

$40 

$80 

font from ROM font from disk change output direction

HiRes font 

LoRes Interlace font 

.•proportional font 

/designed (not derived) 

not available

Dec Hex STRUCTURE TextAttr,0 

0 $0 APTR ta_Name font name 

4 $4 UWORD ta_YSize  height 

6 $6 UBYTE ta_Style  style 

7 $7 UBYTE ta_Flags ,-preference Flags 

8 $8 LABEL ta_SIZEOF 

Dec Hex STRUCTURE TTextAttr, 0 

0 $0 APTR tta_Name  font name 

4 $4 UWORD tta_YSize  height 

6 $6 UBYTE tta_Style  style 

7 $7 UBYTE tta_Flags ,-preference Flags 

8 $8 APTR tta_Tags TagItem field 

12 $C LABEL tta_SIZEOF 

TA_DeviceDPI =  TAG_USER!1 XDPI«16 IYDPI 

MAXFONTMATCHWEIGHT 

32767 .-perfect match 

Dec Hex STRUCTURE TextFont,MN_SIZE ,-font 

20 $14 UWORD tf_YSize 

22 $16 UBYTE tf_Style 

23 $17 UBYTE tf_Flags 

24 $18 UWORD tf_XSize 

26 $1A UWORD tf_Baseline 

28 $1C UWORD tf_BoldSmear 

,- height 

style preference Flags

/normal width 

,-base line 

bold value

S1E 

UWORD 

tf_Accessors

$20 

OBYTE 

tf_LoChar

$21 

UBYTE 

tf_HiChar

$22 

APTR 

tf_CharData

$26 

UWORD 

tf_Modulo

$28 

APTR 

tf_CharLoc

$2C 

APTR 

t f_Char Space

$30 

APTR 

tf_CharKern

$34 

LABEL 

tf_SIZEOF

/number of users 

first character last character packed Bit Images bytes per line of CharData offsets and character widths

.•proportional spaces 

image offsets tf_Extension =  MN_REPLYPORT

TE0B_NOREMFONT =  0, TE0F_NOREMFONT =  1 not removable 

Dec 

Hex 

STRUCT 

$0 

UWORD 

$2 

UBYTE 

$3 

UBYTE 

$4 

APTR 

$8 

APTR 

$c 

APTR 

$10 

APTR 

$14 

APTR 

$18 

LABEL 

STRUCTURE TextFontExtension, 0 read only! 

tfe_MatchWord tfe_Flags0 tfe_Flagsl tfe_BackPtr tfe_OrigReplyPort tfe_Tags tfe_OFontPatchS tfe_OFontPatchK tfe_SIZEOF

ID for compatibility 

system Flags (TEC.) check address old contents of tf_Extension

TagItem field 

private

/private 

CT_COLORFONT =  1  color values are set 

CT_GREYFONT =  2 grey scale only (dark to light) 

CT_ANTIALIAS =  4 AntiAliasing 

CTB_MAPCOLOR =  0, CTF_MAPCOLOR =  1 set rp_FgPen first 

Dec Hex STRUCTURE ColorFontColors , 0 

0 $0 UWORD cfc_Reserved 0!! 

2 $2 UWORD cfc_Count  number of color values 

4 $4 APTR cfc_ColorTable  color table $xRGB 

8 $8 LABEL cfc_SIZEOF 

Dec Hex STRUCTURE ColorTextFont 

,tf_SIZEOF 

52 $34 UWORD 

ctf_Flags additional Flags

54 $36 UBYTE 

ctf_Depth number of BitPlanes

55 $37 UBYTE 

ctf_FgColor rp_FgPen

56 $38 UBYTE 

ctf_Low lowest color

57 $39 UBYTE 

ctf_High

.•highest color 

58 $3A UBYTE 

ctf_PlanePick

 ImagePlanes 

59 $3B UBYTE 

ctf_PlaneOnOff

BitMap mask 

60 $3C APTR 

ct f_Color Fontcolor s colors

64 $40 STRUCT 

ctf_CharData, 8*

 BitPlanePointer 

96 $60 LABEL 

ctf_SIZEOF

Dec Hex STRUCTURE TextExtent, 0 

0 $0 UWORD te_Width TextLength 

2 $2 UWORD te_Height tf_YSize 

4 $4 STRUCT te_Extent>8 MinX,MinY,MaxX,MaxY (relative) 

12 $C LABEL te_SIZEOF 

7. Movable Objects 

[AddAnimOb 

Add AnimOb to RastPort list! 

Call: AddAnimOb (anOb, anKey, rp) 

-156 (A6) a0 al a2 

STRUCT AnimOb *anOb, **anKey 

STRUCT RastPort *rp 

Function: Adds an AnimOb structure to the given list and initializes 

the Timer values of the structure. Gelslnfo for the RastPort must be initialized.

Parameters: anOb 

anKey rp

AnimOb structure 

Address of the address of the first AnimOb. 

RastPort of the AnimOb. 

|AddBob 

Add a  bob structure to the GEL list) 

Call: AddBob(Bob, rp) 

-96 (A6) aO al 

STRUCT Bob *Bob 

STRUCT RastPort *rp 

Function: Adds the given Blitter object to the RastPort's list. 

Parameters: Bob Blitter object 

rp RastPort of the bob

| AddVSprite Add a  virtual sprite to the GEL list| 

Call: AddVSprite (vs, rp) 

-102 (A6) aO al 

STRUCT VSprite *vs 

STRUCT RastPort *rp 

Function: Adds a  VSprite structure to the RastPort's list. 

Parameters: vs VSprite 

rp RastPort

| Animate Move AnimObsl 

Call: Animate (anKey, rp) 

-162 (A6) aO al 

STRUCT AnimOb **anKey 

STRUCT RastPort *rp 

Function: Animates all AminObs and their components. 

Parameters: anKey Address of the pointer to the first AnimOb. 

rp RastPort of the AnimOb.

IChangeSprite Change a  sprite | 

Call: ChangeSprite (  vp, s, newdata) 

-420 (A6) aO al a2 

STRUCT viewport *vp 

STRUCT SimpleSprite *s 

APTR newdata 

Function: Changes the appearance of a  sprite. 

Parameters: vp ViewPort of the sprite or 0  (=relative to start of 

display).

s Address of the SimpleSprite structure. newdata Address (ChipRAM) of the new hardware sprite data list.

1 DoCollision Check elements of the GEL list for collisions | 

Call: DoCollision (rp) 

-108 (A6) al 

STRUCT RastPort *rp 

Function: Checks every movable object for border and object 

collisions and calls the GEL collision routine if one is found.

Parameters: rp RastPort with sorted GEL list (see SortGList()). 

IDrawGList Display movable objects | 

Call: DrawGList (rp, vp) 

-114 (A6) al aO 

STRUCT RastPort *rp 

STRUCT Viewport *vp 

Function: Calculates a  new Copper list for sprites and draws bobs. 

Parameters: rp RastPort of the bob. 

v p  ViewPort of the VSprite.

| FreeG Buffers Free the AminOb component buffers | 

Call: FreeGBuf f  ers (anOb, rp, db) 

-600 (A6) aO al dO 

STRUCT AnimOb *anOb 

STRUCT RastPort *rp 

BOOL db 

Function: Frees all buffers of all AnimOb components (SaveBuffer, 

Borderline, CollMask=ImageShadow). If desired, double 

buffering memory (DBufPacket, BufBuffer) is also set free.

Parameters: anOb 

db

AnimOb 

RastPort 

Flag for double buffering (TRUE). 

IFreeSprite' 

Free hardware sprite] 

Call: FreeSprite( pick ) 

-414 (A6) dO 

WORD pick 

Function: Frees a  hardware sprite for use by other programs. 

Parameters: pick Sprite number (0...7) 

I Getli Buffers

Allocate all buffers for an AnimOb |

Call: status =  GetGBuffers(anOb, rp, db) 

dO -168 (A6) aO al dO

BOOL status, db 

STRUCT AnimOb *anOb 

STRUCT RastPort *rp 

Function: Attempts to allocate all memory for the components of an 

AnimOb (SaveBuffer, BorderLine, 

CollMask=ImageShadow). Memory for double buffering 

(DBufPacket, BufBuffer) is also allocated if indicated. If an 

error occurs, memory already allocated is not set free.

Parameters: anOb 

rp db

AnimOb structure 

RastPort of the AnimOb. 

Flag for double buffering (TRUE). 

Result: 

Error 

IGetSprite 

Allocate a  hardware sprite |

Call: Sprite_Number =  GetSprite( sprite, pick ) 

dO -408 (A6) aO dO

SHORT Sprite_Number,pick 

STRUCT SimpleSprite *sprite 

Function: Attempts to allocate one of the 8  hardware sprites. 

Parameters: sprite SimpleSprite structure for the sprite. 

pick Sprite number (0...7) or -1 (any Sprite).

Result: Sprite number of the allocated sprite or -1 (already in 

use/none free). llnitGels

Initialize GELsl 

Call: lnitGels(head, tail, GInfo) 

-120 (A6) aO al a2 

STRUCT VSprite *head,*tail 

STRUCT Gelslnfo *GInfo 

Function: Links the VSprite structures to the GfxBase. 

Parameters: head Start of list 

tail End of list

GInfo Gelslnfo structure to be initialized. 

llnitGMasks

Initialize AnimOb mask| 

Call: initGMasks (anOb) 

-174 (A6) aO 

STRUCT AnimOb *anOb 

Function: Calculate and enter the mask values for an AnimOb. 

Parameters: anOb AnimOb 

| InitMasks Initialize VSprite mask | 

Call: InitMasks ( vs ) 

-126 (A6) aO 

STRUCT VSprite *vs 

Function: Calculates Borderline and CollMask for a  VSprite/bob. 

Parameters: vs VSprite structure of the object. 

| MoveSprite Move a  hardware sprite | 

Call: MoveSprite (   vp, sprite, x, y   ) 

-426 (A6) aO al dO dl 

STRUCT Viewport *vp 

STRUCT SimpleSprite *sprite 

SHORT x,y 

Function: Positions a  hardware sprite relative to the ViewPort. 

Parameters: vp ViewPort of the sprite or 0  (relative to View). 

sprite SimpleSprite structure x,y Position (x-coordinate +1)

| RemlBob Remove a  bob from the RastPort listl 

Call: RemlBob(bob, rp, vp) 

-132 (A6) aO al a2 

STRUCT Bob *bob 

STRUCT RastPort *rp 

STRUCT ViewPort *vp 

Function: Removes a  bob from the RastPort's GEL list. 

Parameters: bob Blitter object to remove. 

rp RastPort vp ViewPort for raster synchronization.

I RemVSprite Remove a  VSprite from the RastPort list| 

Call: RemVSprite (vs) 

-138(A6) aO 

STRUCT VSprite *vs 

Function: Removes a  VSprite from the GEL list of the RastPort. 

Parameters: vs VSprite 

ISetCollision Set the collision routine | 

Call: SetCollision(num, routine, GInfo) 

-144 (A6) dO aO al 

ULONG num 

APTR routine 

STRUCT Gelslnfo *GInfo 

Function: Sets the collision routine for an entry. 

Parameters: num Number of entries 

routine Collision routine

GInfo Gelslnfo 

| SortGList Sort list of movable objects | 

Call: SortGList (rp) 

-150 (A6) al 

Function: Sorts the objects list by y-x coordinates. 

Parameters: rp RastPort with Gelslnfo 

SUSERFLAGS = 

$O0FF 

VSB_VSPRITE 

= o. 

VSB_SAVEBACK 

= 1, 

VSB_OVERLAY 

= 2, 

VSB_MUSTDRAW 

= 3, 

VSB_BACKSAVED 

= 8, 

VSB_BOBUPDATE 

= 9, 

VSB_GELGONE 

= 10, 

VSB_VSOVERFLOW =  11, 

BUSERFLAGS = 

$00FF 

BB_SAVEBOB 

= o. 

BB_BOBISCOMP 

= 1, 

BB_BWAITING 

= 8, 

BB_BDRAWN 

= 9, 

BB_BOBSAWAY 

= 10, 

BB_BOBNIX 

= 11, 

BB_SAVEPRESERVE= 12, 

BB_OUTSTEP 

= 13, 

/mask for User VSprite 

VSF_VSPRITE =  1 

VSF_SAVEBACK =  2 

VSF_OVERLAY =  4 

VSF_MUSTDRAW =  8 

VSF_BACKSAVED =  $100 

VSF_BOBUPDATE =  $200 

VSF_GELGONE =  $400 

VSF_VSOVERFLOW =  $800 

Flags 

VSprite, -BOb 

save background mask draw background update BOb outside of View overf low raask for User BOb Flags

BF_SAVEBOB =     1 

BF_BOBISCOMP =     2 

BF_BWAITING =  $100 

BF_BDRAWN =  $200 

BF_BOBSAWAY =  $400 

BF_BOBNIX =  $800 

BF_SAVEPRESERVE=$1000 

BF_OUTSTEP =$2000 

do not delete

/AnimOb component 

BOb waiting 

BOb drawn 

remove BOb

BOb gone 

background from Dbuf clear Dbuf

ANFRACSIZE =     6 /animation Flags 

ANIMHALF =  $0020 

RINGTRIGGER =  $0001 

Dec 

Hex 

STRUCTURE VS, 0 vSprite 

$0 

APTR 

vs_NextVSprite next structure

$4 

APTR 

vs_PrevVSprite previous structure

$8 

APTR 

vs_DrawPath overlay vSprite

$c 

APTR 

vs_ClearPath delete vSprite

$10 

WORD 

vs_01dy old position

$12 

WORD 

vs_01dx

$14 

WORD 

vs_VSFlags

/vSprite Flags 

$16 

WORD 

vs_Y

.•position 

$18 

WORD 

vs_X

$1A WORD 

vs_Height height

$1C 

WORD 

vs_Width width in Words

$1E 

WORD 

vs_Depth

/number of BitPlanes 

$20 

WORD 

vs_MeMask

/collision mask 

$22 

WORD 

vs_HitMask

/collision mask 

$24 

APTR 

vs_ImageData

/ image 

$28 

APTR 

vs_BorderLine

/mask of all bits 

$2C 

APTR 

vs_CollMask

/collision image 

$30 

APTR 

vs_SprColors

/Sprite colors 

$34 

APTR 

vs_VSBob

,-BOb 

$38 

BYTE 

vs_PlanePick

/BitPlane mask image 

$39 

BYTE 

vs_PlaneOnOf f

/same for other planes 

$3A 

LABEL 

vs_SUserExt

/start of user extension 

$3A 

LABEL 

vs_SIZEOF

Dec 

Hex 

STRUCTURE BOB, 0 Blitter object 

$0 

WORD 

bob_BobFlags  Flags

$2 

APTR 

bob_SaveBuffer /background buffer

$6 

APTR 

bob_ImageShadow  Image mask

$A 

APTR 

bob_Before  previous Bob

$E 

APTR 

bob_After next Bob

$12 

APTR 

bob_BobVSprite vSprite structure

$16 

APTR 

bob_BobComp AnimComp

$1A 

APTR 

bob_DBuf f er  dBuf Packet

$1E 

LABEL 

bob_BUserExt

$1E 

LABEL 

bob_SIZEOF

Dec 

Hex 

STRUCTURE AC,0 /AnimComp 

$0 

WORD 

ac_CompFlags  Flags

$2 

WORD 

ac_Timer /activation time

$4 

WORD 

ac_TimeSet  start time

$6 

APTR 

ac_NextComp next component

$A 

APTR 

ac_PrevComp /previous component

$E 

APTR 

ac_NextSeq /next sequence

$12 

APTR 

ac_PrevSeq /previous sequence

$16 

APTR 

ac_AnimCRoutine /animation routine

$1A WORD 

ac_YTrans /y translation

$1C 

WORD 

ac_XTrans /x translation

$1E 

APTR 

ac_HeadOb /AnimOb

$22 

APTR 

ac_AnimBob / BOB

$26 

LABEL 

ac_SIZE

Dec 

Hex 

STRUCTURE AO, 0 

AnimOb 

$0 

APTR 

ao_NextOb , next AnimOb

$4 

APTR 

ao_PrevOb , previous AnimOb

$8 

LONG 

ao_Clock number of Animate ( )

$C 

WORD 

ao_An01dY old position

$E 

WORD 

ao_An01dX

$10 

WORD 

ao_AnY position

$12 

WORD 

ao_AnX

$14 

WORD 

ao_YVel velocity

$16 

WORD 

ao_XVel

$18 

WORD 

ao_XAccel acceleration

$1A 

WORD 

ao_YAccel

$1C 

WORD 

ao_RingYTrans

•ring translation 

$1E 

WORD 

ao_RingXTrans

$20 

APTR 

ao_An imORout ine

•animation routine 

$24 

APTR 

ao_HeadComp

/AnimComp 

$28 

LABEL 

ao_AUserExt

$28 

LABEL 

ao_SIZEOF

Dec Hex 

STRUCTURE DBP, 0 

dBuf Packet

0 $0 

WORD 

dbp_BufY screen position

2 $2 

WORD 

dbp_BufX

4 $4 

APTR 

dbp_BufPath vSprite

8 $8 

APTR 

dbp_Buf Buffer buffer

12 $C 

APTR 

dbp_BufPlanes background PlanePointer

16 $10 

LABEL 

dbp_SIZEOF

Dec Hex 

STRUCTURE GelsInfo.O 

0 $0 

BYTE 

gi_sprRsrvd

 Sprite numbers 

1 $1 

BYTE 

gi_Flags

 Flags 

2 $2 

APTR 

gi_gelHead start of list

6 $6 

APTR 

gi_gelTail end of list

10 $A APTR 

gi_nextLine

/Sprite lines 

14 $E 

APTR 

gi_lastColor color field

18 $12 

APTR 

gi_collHandler

.•collision routine 

22 $16 

WORD 

gi_leftmost

24 $18 

WORD 

gi_rightmost

26 $1A WORD 

gi_topmost

28 $1C 

WORD 

gi_bottoinmost

30 $1E 

APTR 

gi_firstBlissObj

34 $22 

APTR 

gi_lastBlissObj

38 $26 

LABEL 

gi_SIZEOF

Dec Hex 

STRUCTURE SimpleSprite 

,0 

0 $0 

APTR 

ss_posctldata

4 $4 

WORD 

ss_height

6 $6 

WORD 

ss_x

8 $8 

WORD 

ss_y

10 $A WORD 

ss_num

12 $C 

LABEL 

ss_SIZEOF
