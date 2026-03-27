# The Intuition Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.11 The Intuition Library

The "intuition.library" handles global management of the display and input from the keyboard and mouse. The base address must be given in
A6. 

Functions of the Intuition Library 

1. Screens 

CloseScreen 

CloseWorkBench 

FreeScreenDrawInfo 

GetDefaultPubScreen 

GetScreenData 

GetScreenDrawInfo 

LockPubScreen 

LockPubScreenList 

MakeScreen 

MoveScreen 

NextPubScreen 

OpenScreen 

OpenScreenTagList 

OpenWorkBench 

PubScreenStatus 

QueryOverscan 

RemakeDisplay 

RethinkDisplay 

ScreenToBack 

ScreenToFront 

SetDefaultPubScreen 

SetPubScreenModes 

ShowTitle 

UnlockPubScreen 

UnlockPubScreenList 

ViewAddress 

WBenchToBack 

WBenchToFront 

2. Windows 

ActivateWindow 

BeginRefresh 

ChangeWindo wB ox 

ClearMenuStrip 

ClearPointer 

CloseWindow 

EndRefresh 

ItemAddress 

ModifylDCMP 

## 3.1 The Libraries and their Functions

MoveWindow 

MoveWindowInFrontOf 

OffMenu 

OnMenu 

Open Window 

OpenWindowTagList 

RefreshWindowFrame 

ResetMenuStrip 

SetMenuStrip 

SetMouseQueue 

SetPointer 

SetWindowTitles 

SizeWindow 

ViewPortAddress 

WindowLimits 

WindowToBack 

WindowToFront 

ZipWindow 

3. Requesters 

AutoRequest 

BuildEasyRequestArgs 

BuildSysRequest 

ClearDMRequest 

DisplayAlert 

EasyRequestArgs 

EndRequest 

FreeSysRequest 

InitRequester 

Request 

SetDMRequest 

SysReqHandler 

4. Gadgets 

ActivateGadget 

AddGadget 

AddGList 

GadgetMouse 

ModifyProp 

NewModifyProp 

ObtainGIRPort 

OffGadget 

OnGadget 

RefreshGadgets 

RefreshGList 

ReleaseGIRPort 

RemoveGadget 

RemoveGList 

ReportMouse 

SetEditHook 

SetGadgetAttrsA 

5. Output Functions 

DisplayBeep 

DrawB order 

Drawlmage 

DrawImageState 

Eraselmage 

IntuiTextLength 

PrintlText 

6. Other Functions 

AddClass 

AllocRemember

CurrentTime 

DisposeObject 

Doubleclick 

FreeClass 

FreeRemember 

GetAttr 

GetDefPrefs 

GetPrefs 

LocklBase 

MakeClass 

NewObjectA 

NextObject 

Pointlnlmage 

RemoveClass 

SetAttrsA 

SetPrefs 

UnlocklBase 

Description of the Functions 

1. Screens 

[CloseScreen Attempt to close a  screen | 

Call: Success =  CloseScreen (Screen) 

DO -66 (A6) AO 

BOOL Success 

STRUCT Screen *Screen 

Function: Attempts to close a  screen. If successful and the screen was 

the last screen, then an attempt is made to open the
Workbench. 

Parameters: Screen Screen to be closed. 

Result: 0  Screen could not be closed because it still 

contains windows.

[Close WorkBench Attempt to close Workbench | 

Call: Success =  CloseWorkBench ( ) 

DO -78 (A6) 

BOOL Success 

Function: Attempts to close the Workbench. 

Result: 0  Workbench still open because there are still 

windows from other programs on screen.

[FreeScreenDrawInfo Free Drawlnfol 

Call: FreeScreenDrawInf o (   Screen, Drlnfo ) 

-696 (A6) AO Al 

STRUCT Screen *Screen 

STRUCT Drawlnfo *DrInfo 

Function: Frees the screen's Drawlnfo structure (important for future 

operating system versions).

Parameters: Screen Screen with the Drawlnfo structure. 

Drlnfo Drawlnfo from GetScreenDrawInfo(). 

I GetDefaultPubScreen Get default PublicScreen | 

Call: GetDef aultPubScreen (  Namebuff ) 

-582 (A6) AO 

APTR Namebuff 

Function: Gets the name of the default PublicScreen. 

Parameters: Namebuff Buffer of size MAXPUBSCREENNAME bytes, 

orO.

Result: None. Will provide the string "Workbench" in Namebuff if 

there is no current default public screen.

IGetScreenData Copy Screen structure | 

Call: Success =  GetScreenData (Buffer, Size, Type, Screen ) 

DO -426 (A6) AO DO Dl Al 

BOOL Success 

STRUCT Screen *Screen 

UWORD Size, Type 

APTR Buffer 

Function: With CUSTOMSCREEN, copies the given Screen structure 

to a  buffer. If you specify a  different screen type, the data structure of the given screen type is copied. This will open the Workbench if it was closed at the time the call was made.

Parameters: Buffer Buffer for the Screen structure. 

Size Buffer size 

Type Screen type (such as WBENCHSCREEN) 

Screen Screen address of a  CUSTOMSCREEN. 

Result: 0  Error ('Type' Screen could not be opened) 

| GetScreenDrawInf o Get Drawlnfo for a  screen | 

Call: Drlnf o =  GetScreenDrawInf o (   Screen ) 

DO -690 (A6) A0 

STRUCT Drawlnfo *DrInfo 

STRUCT Screen *Screen 

Function: Gets a  Drawlnfo structure for the given screen. 

Parameters: Screen Address of a  Screen structure. 

Result: Drawlnfo structure 

ILockPubScreen Lock a  PublicScreenl 

Call: screen =  LockPubScreen (  Name ) 

DO -510 (A6) A0 

STRUCT Screen * screen 

APTR Name 

Function: Prevents a  PublicScreen from being closed while data is 

being read. This is needed to open a  window according to the screen dimensions. If a  value of 0  is given, the default public screen is addressed -  usually the Workbench screen. If this is closed at the time, it is opened again
(OpenWorkBench()). 

Parameters: Name Screen name, *"Workbench" or 0 

Result: Screen address or 0 

ILockPubScreenList Lock PublicScreen list| 

Call: List =  LockPubScreenList ( ) 

DO -522 (A6) 

STRUCT List *List 

Function: Prevents the PublicScreen list from being changed and gets 

a user copy of this system list (PubScreenNodes).

Result: Address of the PublicScreen list. 

IMakeScreen MakeVPortQ for Intuition screens | 

Call: MakeScreen (Screen) 

-378 (A6) AO 

STRUCT Screen *Screen 

Function: Allows changes to the screen display in a  compatible way. 

RethinkDisplayO should be called afterwards. 

Parameters: Screen Address of the changed screen. 

IMoveScreen Move screen | 

Call: MoveScreen (Screen, DeltaX, DeltaY) 

-162 (A6) AO DO Dl 

STRUCT Screen *Screen 

WORD DeltaX, DeltaY 

Function: Moves the given screen according to the given delta value. 

Starting with AmigaOS2, the screen may also be moved 

horizontally and scrolled up to the left and out of the display (negative positions).

Parameters: Screen Screen to be moved. 

DeltaX Horizontal interval in (screen) pixels. 

DeltaY Vertical interval in (screen) pixels. 

| NextPubScreen Get name of the next PublicScreen | 

Call: Name =  NextPubScreen (   Screen, NameBuff) 

DO -534 (A6) AO Al 

STRUCT Screen *Screen 

APTR NameBuff, Name 

Function: Gets the name of the next PublicScreen. 

Parameters: Screen Screen or 0 

NameBuff Buffer consisting of MAXPUBSCREENNAME 

bytes.

Result: Address of buffer or 0  (not a  PublicScreen). 

[OpenScreen Open screen | 

Call: Screen =  OpenScreen (NewScreen) 

DO -198 (A6) AO 

STRUCT Screen *Screen 

STRUCT (Ext) NewScreen *NewScreen 

Function: Opens a  screen that's given the definition of a  NewScreen 

or ExtNewScreen structure.

Parameters: NewScreen 

Initialized NewScreen or ExtNewScreen 

structure.

Tags (ExtNS): 

Old function (see NS): SA_Left, SAJTop, SA.Width, 

SA_Height, SA_Depth, SA_DetailPen, SA.BlockPen, 

SA_Title, SA_Font, SAJType, SA_BitMap, SA_ShowTitle, 

SA_Behind, SA_Quiet. 

SA_DisplayID: 32 bit display mode. 

SA_Overscan: OSCAN_TEXT, OSCAN_STANDARD, 

OSCAN_MAX or OSCAN.VTOEO. 

SA_DClip: DisplayClip region, see 

QueryOverscan(). 

SA_AutoScroll: Bool 

For oversized screens.

SA_PubName: Screen becomes a  PublicScreen. 

SA_Pens: Field for DrawInfo.dri_Pens which 

allows all OS 2.0 options.

SA_PubTask: Task that is informed of the last "Visitor
window to leave the PubScreen.

SA_PubSig: Signal bit for SA_PubTask. 

SA_Colors: Colors, ending with -1. 

SA_FullPalette: Take over all 32 Preferences colors 

(BOOL). 

SA_ErrorCode: Address for error codes. 

SA_SysFont: Use Preferences font (0 =  old font, 

l=Workbench font)

Result: Address of the Screen structure or 0  (see SA_ErrorCode). 

IQpenScreenTagList Openscreenl 

Call: Screen =  OpenScreenTagList (  NewScreen, Tagltems ) 

DO -612 (A6) A0 Al 

STRUCT Screen *Screen 

STRUCT NewScreen *NewScreen 

STRUCT Tagltem *TagItems 

Function: Same as OpenScreen() ExtNewScreen data structure, but 

the Tagltem field is passed as a  parameter in place of the old
ExtNewScreen method (test versions). 

Functions, Tags: 

See OpenScreen() 

Parameters: NewScreen 

Optional NewScreen structure 

Tagltems Optional Tagltem field, ending with TAG_END. 

Result: Address of the Screen structure or 0. 

| Open WorkBench Get Workbench address | 

Call: WBScreen =  OpenWorkBench ( ) 

DO -210 (A6) 

STRUCT Screen *WBScreen 

Function: Searches for the Workbench screen and tries to open it if it 

is not already open.

Result: Screen structure or 0 

| PubScreenStatus Change status of a  PublicScreen | 

Call: ResultFlags =  PubScreenStatus (  Screen, StatusFlags ) 

DO -552 (A6) AO DO 

UWORD ResultFlags , StatusFlags 

STRUCT Screen *Screen 

Function: Change status flags of own PublicScreen. 

Parameters: Screen Own PublicScreen 

StatusFlags 

Current flags 

Result: Bit 0  0: Screen was not public or could not be made 

private.

IQueryOverscan (Juery overscan area| 

Call: QueryOverscan ( DisplaylD, Rect, OScanType ) 

-474 (A6) AO Al DO 

ULONG DisplaylD 

STRUCT Rectangle *Rect 

WORD OScanType 

Function: Fills a  Rectangle structure with the dimensions of an 

overscan type corresponding to the 32 bit display mode.

Parameters: DisplaylD 32 bit display mode 

Rect Rectangle structure to be filled. 

OScanType 

OSCAN_... 

Result: 0  MonitorSpec for the ID does not exist. 

| RemakeDisplay Recalculate the display | 

Call: RemakeDisplay ( ) 

-384 (A6) 

Function: Complete recalculation of all screens (ViewPorts) and the 

ViewLord (Intuition View). This function should be 

avoided (MakeScreen()+RethinkDisplay() will usually do the job).

IRethinkDisplay Global display reconstructurel 

Call: RethinkDisplay ( ) 

-390(A6) 

Function: Global reconstruction of the display. MakeVPort() should 

be called first.

| ScreenToBack Move screen to the background | 

Call: ScreenToBack (Screen) 

-246 (A6) AO 

STRUCT Screen *Screen 

Function: Moves the given screen to the back of the display. 

Parameters: Screen Screen structure 

IScreenToFront Move screen to the foreground! 

Call: ScreenToFront (Screen) 

-252 (A6) AO 

STRUCT Screen *Screen 

Function: Moves the given screen to the foreground. 

Parameters: Screen Screen structure 

ISetDefaultPubScreen Set standard PublicScreenl 

Call: SetDefaultPubScreen( Name ) 

-540 (A6) AO 

APTR Name 

Function: Sets the default PublicScreen. 

Parameters: Name Name of the PubScreen or 0  (=Workbench). 

ISetPubScreenModes Set global mode for PublicScreenl 

Call: OldModes =  SetPubScreenModes (  Modes ) 

DO -546 (A6) DO 

UWORD OldModes, Modes 

Function: Sets the global mode for PublicScreen. 

Parameters: Modes New flags: SHANGHAI -  Workbench windows 

are opened with the default PublicScreen
POPPUBSCREEN -  PublicScreen moves to the 

foreground when opened.

Result: Old global flags. 

IShowTitle Activate (or deactivate) a  screen's title barl 

Call: ShowTitle (Screen, Showlt) 

-282 (A6) AO DO 

STRUCT Screen *Screen 

BOOL Showlt 

Function: Manipulates the SHOWTITLE flag of a  screen and 

refreshes the display.

Parameters: Screen Screen structure 

Showlt Boolean: TRUE (title bar visible) or 0 

lUnlockPubScreen Free a  PublicScreen!

Call: UnlockPubScreen ( Name, Screen ) 

-516 (A6) AO Al 

APTR Name 

STRUCT Screen *Screen 

Function: Undo a  LockPubScreen() call. 

Parameters: Name Name of PublicScreen or 0. 

Screen Screen address if Name=0. 

lUnlockPubScreenList Free PublicScreen list|

Call: unlockPubScreenList ( ) 

-528 (A6) 

Function: Undo a  LockPubScreenList() call. 

IViewAddress 

Get the address of the ViewLordl 

Call: ViewLord =  ViewAddress ( ) 

DO -294 (A6) 

STRUCT View *ViewLord 

Function: Gets the address of the Intuition View structure ViewLord. 

Result: View structure 

WBenchToBack 

Move Workbench to the background! 

Call: Success =  WBenchToBack ( ) 

DO -336(A6) 

BOOL Success 

Function: Moves the Workbench screen behind all other screens. 

Result: 0  Workbench was not open. 

IWBenchToFront 

Move Workbench to foreground] 

Call: Success =  WBenchToFront ( ) 

DO -342 (A6) 

BOOL Success 

Function: Move the Workbench screen in front of all other screens. 

Result: 

Workbench was not open. 

Dec Hex STRUCTURE IntuitionBase, 0 

0 $0 STRUCT ib_LibNode,LIB_SIZE 

34 $22 STRUCT ib_ViewLord, v_SIZEOF  Intuition View 

52 $34 APTR ib_ActiveWindow ,-active window 

56 $38 APTR ib_ActiveScreen 

60 $3C APTR ib_FirstScreen 

64 $40 ULONG ib_Flags 

68 $44 WORD ib_MouseY 

70 $46 WORD ib_MouseX 

72 $48 ULONG ib_Seconds time 

that window ' s screen first screen

/private 

 INCOMPATIBLE! 

76 $4C ULONG ib_>licros 

DRI_VERSION =  1 

Dec 

Hex STRUCT! 

JRE Drawlnfo, 0 

$0 UWORD 

dri_Version

•structure version 

$2 UWORD 

dri_NumPens

•>= numDrlPens 

$4 APTR 

dri_Pens

• PenArray 

$8 APTR 

dri_Font

 ScreenDef aultFont 

$C UWORD 

dri_Depth

 (initial) BitMap depth 

$E UWORD 

dri_ResolutionX l/velocity

$10 UWORD 

dri_ResolutionY

' 

$12 ULONG 

dri_Flags

$16 STRUCT 

dri_longreserved

,28 

DRIF_NEWLOOK =  1, DRIB_NEWLOOK =  0 

PenArray 

Indices: 

deta ilPen

= 0 

= 1 

= 2 

old draw color

DlOCiirtsu 

text Pen text on background (0) shinePen

= 3 

bright 3D edges shadowPen

= 4 

dark 3D edges hifi

UPer 

= 5 

fill color for current window hifi lltextPen

= 6 

text in current window border backgroundPen

= 7 

background color (0) hilighttextPen

= 8 

highlighted text numDrlPens

= 9 

Dec 

Hex 

STRUCTURE 

Screen, 0 

$0 

APTR 

sc_

.NextScreen , 

next screen

$4 

APTR 

sc.

.FirstWindow , 

first window

$8 

WORD 

sc_

.LeftEdge , 

position

$A WORD 

sc.

.TopEdge , 

$c 

WORD 

sc.

.Width 

size

$E 

WORD 

sc.

.Height 

$10 

WORD 

sc.

.MouseY 

mouse position

$12 

WORD 

sc_>touseX

$14 

WORD 

sc.

.Flags 

$16 

APTR 

sc.

.Title 

current title

$1A 

APTR 

sc.

.DefaultTitle 

•title 

$1E 

BYTE 

sc.

.BarHeight 

•size of title bar 

$1F 

BYTE 

sc.

.BarVBorder 

$20 

BYTE 

sc.

.BarHBorder 

$21 

BYTE 

sc_MenuVBorder

•size of menu bord 

$22 

BYTE 

sc

_MenuHBorder 

$23 

BYTE 

sc

_WBorTop 

size of window bo

$24 

BYTE 

sc

_WBorLeft 

37 $25 BYTE sc_WBorRight 

38 $26 BYTE sc_WBorBottom 

39 $27 BYTE sc_KludgeFillOO 

40 $28 APTR sc_Font 

44 $2C STRUCT sc_ViewPort, vp_SIZEOF 

84 $54 STRUCT sc_RastPort, rp_SIZEOF 

184 $B8 STRUCT sc_BitMap,bm_SIZEOF 

224 $E0 STRUCT sc_LayerInfo, li_SIZEOF 

326 $146 APTR sc_FirstGadget 

330 $14A BYTE sc_DetailPen 

331 $14B BYTE sc_BlockPen 

332 $14C WORD sc_SaveColorO 

334 $14E APTR sc_BarLayer 

338 $152 APTR sc_ExtData 

342 $156 APTR sc_UserData 

346 $15A LABEL sc_SIZEOF 

font
/Viewport 

RastPort 

 BitMap 

 Layer Info 

gadgets for gadgets for Beeping title Layer
.•extended data 

not necessarily end of structure!

SCREENTYPE =    $F /mask 

WBENCHSCREEN =     1  Workbench screen 

PUBLICSCREEN =     2  PublicScreen 

CUSTOMSCREEN =    $F  other screens 

SHOWTITLE =    $10 /show title bar 

BEEPING =    $20 /beep the screen 

CUSTOMBITMAP =    $40 /User BitMap 

SCREENBEHIND =   $80 /open screen behind 

SCREENQUIET =   $100 /forbid drawing 

SCREENHIRES =   $200 /HiRes gadgets 

NS_EXTENDED =  $1000 /extended screen structure 

AUTOSCROLL =  $4000 /for oversized screens 

STDSCREENHEIGHT =  -1 

STDSCREENWIDTH =  -1 

/ NewScreen . Height 

/ NewScreen . Width 

SA_Left 

SA^Top 

SA_Width 

SA_Height 

SA_Depth 

SA_DetailPen 

SA^BlockPen 

SA_Title 

SA_Colors 

SA_ErrorCode 

SA_Font 

SA_SysFont 

SA_Type 

SA_BitMap 

SA_PubName 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG. 

TAG_ 

.USER+33 

.USER+34 

USER+35 

.USER+36 

.USER+37 

.USER+38 

.USER+39 

.USER+40 

USER+41 

USER+42 

.USER+43 

.USER+44 

USER+45 

USER+46 

.USER+47 

SA_PubSig 

= 

TAG_USER+48 

SA_PubTask 

= 

TAG_USER+49 

SA_DisplayID 

= 

TAG_USER+50 

SA_DClip 

= 

TAG_USER+51 

SA_Overscan 

= 

TAG_USER+52 

SA_Obsoletel 

= 

TAG_USER+53 

SA_ShowTitle 

= 

TAG_USER+54 

SA_Behind 

= 

TAG_USER+55 

SA_Quiet 

= 

TAG_USER+56 

SA_AutoScrol 1 

= 

TAG_USER+57 

SA_Pens 

= 

TAG_USER+58 

SA_FullPalette 

= 

TAG_USER+59 

OSERR_NOMONITOR 

0SERR_NOCHIPS 

OSERR_NOMEM 

0SERR_NOCHIPMEM 

OSERR_PUBNOTUNIQUE 

OSERR_UNKNOWNMODE 

= 1   monitor not available 

= 2  old CustomChips 

= 3   not enough memory 

= 4  not enough ChipMem 

= 5  PublicScreen already exists 

= 6   unknown display mode 

Dec Hex STRUCTURE NewScreen , 0 

0 $0 WORD ns_LeftEdge 

2 $2 WORD nsJTopEdge 

4 $4 WORD ns_Width 

6 $6 WORD ns_Height 

8 $8 WORD ns_Depth 

10 $A BYTE ns_DetailPen 

11 $B BYTE ns_BlockPen 

12 $C WORD ns_ViewModes 

14 $E WORD ns_Type 

16 $10 APTR ns_Font 

20 $14 APTR ns_DefaultTitle 

24 $18 APTR ns_Gadgets 

28 $1C APTR ns_CustomBitMap 

32 $20 LABEL ns_SIZEOF 

STRUCTURE ExtNewScreen, 

32 $20 APTR ens_Extension 

36 $24 LABEL ens_SIZEOF 

position preset color display mode (old) screen type font TextAttr screen title own BitMap ns_SIZEOF
TagItem field 

OSCAN_TEXT 

OSCAN_STANDARD 

OSCAN_MAX 

OSCAN_VIDEO 

= 1  /everything visible 

= 2   right up to the edge of the screen 

= 3   large as possible 

= 4  more than is possible 

Dec Hex STRUCTURE PubScreenNode,LN_SIZE 

14 $E APTR psn_Screen  screen 

18 $12 UWORD psn_Flags ,-private? 

20 $14 WORD £sn_Size  structure size+name 

22 $16 WORD psn_VisitorCount  number of VisitorWindows 

24 $18 APTR psn_SigTask  control task 

28 $1C UBYTE psn_SigBit  signal bit 

29 $1D UBYTE psn_Padl 

30 $1E LABEL psn_SIZEOF 

PSNF_PRIVATE =  1 

MAXPUBSCREENNAME =  139 max. name length 

SHANGHAI =  1  Workbench window on PubScreen 

POPPUBSCREEN =  2  PubScreen to front 

2. Windows 

| Activate Window Activate a  window | 

Call: success =  Ac tivateWindow (Window) 

dO -450 (A6) A0

STRUCT Window *Window 

Function: Activates a  window (for input). 

Parameters: Window Window structure 

Result: 0  Okay 

j BeginRefresh Prepare window for a  refresh |

Call: BeginRefresh (Window) 

-354 (A6) A0 

STRUCT Window *Window 

Function: The window's layer is locked for other programs (such as 

"input.device"->Intuition()). During this time, only 

functions that don't handle other tasks may be called
(never Intuition). 

Parameters: Window Window to be refreshed 

Example: Refresh several regions in a  window: 

move.l im_Class(aO) ,d0  IntuiMessage class cmpi.l #IDCMP_REFRESHWINDOW,dO  refresh window? beq _WindowRefresh

_WindowRefresh 

movea . 1 im_IDCMPWindow (aO ) , a2 movea . 1 wd_WScreen ( a2 ) , aO lea sc_LayerInfo(aO) ,a0 movea .1 aO , a3 movea. 1 _LayersBase,a6 jsr _LVOLockLayerInfo(a6) get window screen address get Layer Info and save

 Layers library 

lock access movea .1 a2 , aO movea . 1 wd_WLayer ( aO ) , aO movea. 1 _Regionl,al jsr _LVOInstallClipRegion(a6) move .1 dO , d2 movea. 1 _IntuiBase,a6 movea. 1 a2,a0 jsr _LVOBeginRefresh(a6) movea . 1 _IntuiBase , a6 movea. 1 a2,a0 moveq #0,d0 jsr _LVOEndRefresh(a6)

 Window 

 Layer 

 1 . Region 

new Clipping save old Region

 Intuition 

 Window 

start refresh refresh first Region

 Intuition 

 Window 

NOT DONE 

end movea. 1 _LayersBase,a6 movea. 1 a2,a0 movea . 1 wd_WLay er ( aO ) , aO movea. 1 _Region2,al jsr _LV0InstallClipRegion(a6) movea. 1 _IntuiBase,a6 movea .1 a2 , aO jsr _LV0BeginRefresh(a6) movea. 1 _IntuiBase,a6 movea. 1 a2,a0 moveq #0,d0 jsr _LV0EndRefresh(a6)

LayersBase 

 Window 

 Layer 

2nd Region 

,-new Clipping 

 Intuition 

 Window 

start refresh

/refresh second Region 

 Intuition 

 Window 

•NOT DONE 

end

/refresh additional Regions 

movea. 1 _LayersBase,a6 movea. 1 a2,a0 movea . 1 wd_WLayer (aO ) , aO movea. 1 _RegionN,al

LayersBase 

/Window 

/Layer 

/nth Region 

jsr _LV0InstallClipRegion(a6) new Clipping movea.l _IntuiBase,a6 /Intuition movea .1 a2,a0  Window jsr _LV0BeginRefresh(a6)  start refresh

.•refresh nth Region 

movea.l _IntuiBase,a6 /Intuition movea.l a2,a0  Window moveq #-l,dO DONE jsr _LV0EndRefresh(a6) /process Damagelist movea . 1 _LayersBase , a6  LayersBase movea.l a2,a0 /Window movea.l wd_WLayer (aO) ,a0 /Layer movea.l d2,al /old Region jsr _LV0InstallClipRegion(a6) /restore Clipping movea.l a3,a0 /Layer Info jsr _LV0UnlockLayerInfo(a6) /unlock

| Change WindowBox Change position and size of a  window! 

Call: ChangeWindowBox( Window, Left, Top, Width, Height) 

-486 (A6) AO DO Dl D2 D3 

STRUCT Window *Window 

WORD Left, Top, Width, Height 

Function: Changes the position and size of a  window simultaneously 

(MoveWindow() and SizeWindow() combined). 

Parameters: Window Window to be changed 

Left, Top, Width, Height 

New position and size 

| ClearMenuStrip Remove menus from a  windowl 

Call: ClearMenuStrip (window) 

-54 (A6) AO 

STRUCT Window *Window 

Function: Removes the MenuStrip from the given menu (waits if the 

menu is active).

Parameters: Window Window with menu 

IClearPointer Reset appearance of mouse pointer | 

Call: ClearPointer (Window) 

-60 (A6) A0 

STRUCT Window *Window 

Function: If you have defined a  custom mouse pointer for a  window, 

this function will reset it to the standard mouse pointer.

Parameters: Window Window 

| CloseWindow Close a  window] 

Call: CloseWindow (Window) 

-72 (A6) A0 

STRUCT Window *Window 

Function: Closes a  window. If there are messages in the UserPort, 

these are also set free. If there is a  MenuStrip, it must first be deleted with ClearMenuStrip(). If it is a  "Visitor Window", the PublicScreen's counter is decremented.

Parameters: Window Window to be closed. 

Example: Close a  window with a  UserPort not created by Intuition. 

You can, for example, assign one UserPort to 10 windows, 

since the window that is to receive the IntuitionMessage is visible from the imJDCMPWindow. When such a  window is opened, a  value of 0  must be given as the IDCMPFlag. After entering the common MsgPort, the desired value can be set with ModifyIDCMP(). Closing such a  window is somewhat more complicated: movea . 1

_SysBase,a6 

 ExecBase 

addq . b

#l,TDNestCnt(a6) 

Multitasking off 

movea . 1

_Window, a2 

get window movea . 1 wd_UserPort (a2 ) , aO

UserPort 

clr.l wd_UserPort(a2) delete entry move . 1

MP_MSGLIST+LH_HEAD (aO ) , d2  ListNode 

Loop 

movea . 1 d2,al message move . 1

(al),d2 

LN_SUCC 

beq.s

. StopMsgs 

LH_TAIL reached? 

cmpa . 1 im_IDCMPWindow (al ) , a2

Msg for this window? 

bne.s

.Loop 

if not move . 1 al,d3 save Msg jsr

_LVORemove (a6 ) 

remove Msg movea . 1 d3,al get Msg jsr

_LV0ReplyMsg(a6) 

send back bra.s

.Loop 

.•continue 

StopMsgs 

movea . 1

_IntuiBase,a6 

/Intuition 

movea . 1 a2,a0

/window 

moveq

#0,d0 

no Flags jsr

_LV0ModifyIDCMP(a6) 

.•prevent further Msgs 

movea . 1

_SysBase,aO 

Exec 

subq.b

.-Multitasking on 

movea . 1 a2,a0

/window 

jsr

_LVOCloseWindow ( a6 ) 

close

|EndRefresh~ 

End screen refresh] 

Call: EndRefresh (Window, Complete) 

-366 (A6) AO DO 

STRUCT Window *Window 

BOOL Complete 

Function: Unlocks a  window that was locked by BeginRefresh() (if 

Complete=TRUE). If you program a  routine that continues 

when Complete=0, the system may easily crash.

Parameters: Window Window 

Complete Boolean, indicates if refresh has ended. 

| ItemAddress Get address of a  Menultem] 

Call: Item =  ItemAddress (MenuStrip, MenuNumber) 

DO -144 (A6) AO DO 

STRUCT Menultem *ItemAddress 

STRUCT Menu *MenuStrip 

UWORD MenuNumber 

Function: Gets the Menultem or Subltem belonging to the given 

menu code.

Parameters: MenuStrip Address of the first menu in a  MenuStrip. 

MenuNumber 

Bit-packed menu code 

Result: Menultem address or 0  (MenuNumber =  MENUNULL) 

IModifylDCMP Change IDCMP flags] 

Call: success Modify IDCMP (Window, IDCMPFlags) 

DO -150 (A6) AO DO 

STRUCT Window *Window 

ULONG IDCMPFlags 

BOOL success 

Function: Changes the status of the IDCMP (Intuition Direct 

Communication Message Port). Warning: the MsgPort is 

freed whenever the flags are set to 0  (FreeMem()).

Parameters: Window Window address 

IDCMPFlags =  MsgPort status 

| Move Window Move a  window] 

Call: MoveWindow (Window, DeltaX, DeltaY) 

-168 (A6) AO DO Dl 

STRUCT Window *Window 

WORD DeltaX, DeltaY 

Function: Moves a  window within a  screen after first checking the 

coordinates.

Parameters: Window Window to be moved 

DeltaX Horizontal delta value 

DeltaY Vertical delta value 

| MoveWindowInFrontOf Change order of windows 1 

Call: MoveWindowInFrontOf ( Window, Behindwindow) 

-480 (A6) A0 Al 

STRUCT Window *Window, * Behindwindow 

Function: Moves a  window in front of the other windows. 

Parameters: Window Window to be placed in front of 

'Behindwindow'. 

BehindWindow 

Window that will end up behind 'Window'. 

| OffMenu Turn menu off | 

Call: Of fMenu (Window, MenuNumber) 

-180 (A6) A0 DO 

STRUCT Window *Window 

UWORD MenuNumber 

Function: Turn off Subltem, Menultem, or an entire menu. Whatever 

is turned off may not be selected.

Parameters: Window Window with MenuStrip 

MenuNumber 

Bit-packed menu code 

lOnMenu

Turn on menu, item, or subiteml 

Call: OnMenu (Window, MenuNumber) 

-192 (A6) AO DO 

STRUCT Window *Window 

UWORD MenuNumber 

Functions, Parameters: 

Opposite of OffMenu(). Allows selection again. 

| Open Window 

Open a  window | 

Call: window =  OpenWindow(NewWindow) 

DO -204 (A6) AO 

STRUCT Window *Window 

STRUCT ( Ext ) NewWindow 

*NewWindow 

Function: Opens a  window given a  NewWindow or ExtNewWindow 

structure. If WBENCHSCREEN is given as the screen type, the window is opened on the Workbench screen or a
SHANGHAI screen. 

Parameters: NewWindow 

NewWindow or ExtNewWindow 

Tags: 

New IDCMP flags: IDCMPJDCMPUPDATE 

for custom and BoopsiGadgets
IDCMP_CHANGEWINDOW for changes to 

the window (position, size)
IDCMP_MENUHELP for printing menu HELP. 

New type: PUBLICSCREEN (preset 

PublicScreen) 

Old functions (s. NW): WA.Left, WA_Top, WA_Width, 

WA_Height, WAJDetailPen, WA_BlockPen, WAJDCMP, 

WA_Flags, WA_Gadgets, WA_Checkmark, WA_Title, 

WA_CustomScreen, WA_SuperBitMap, WA_MinWidth, 

WA_MinHeight, WA_MaxWidth, WA_MaxHeight. 

Result: 

Example: 

Bool tags for flags: WA_SizeGadget, WA_DragBar, 

WA_DepthGadget, WA_CloseGadget, WA_Backdrop, 

WA_ReportMouse. 

WA_ScreenTitle: screen tide. 

WA_AutoAdjust: (BOOL) adjust to screen dimensions. 

WA_InnerWidth, WAJtanerHeight: dimensions of the 

region.

WA_PubScreenName: name of PublicScreens for the 

window.

WA_PubScreen: Screen structure of the PublicScreen. 

WA_PubScreenFallBack: default PublicScreen if the one 

requested is not available (BOOL).

WA_WindowName: not yet implemented. 

WA_Colors: palette for the window. 

WA_Zoom: field with alternative size (ZoomGadget). 

WA_MouseQueue, WA_RptQueue: limits for 

IntuiMessages of the types IDCMP_MOUSEMOVE and 

repeated IDCMP.RAWKEY.

WA_BackFiU: LayerHook for backfill. 

Window address or 0 

Display AmigaDOS requesters in the window entered in the 

Process structure of the currently running program. This is 

normally a  Workbench window. Programs that open a custom screen should change this pointer to a  window that is in the custom screen. Otherwise, the Workbench screen will brought to the foreground with every return query.

jsr _JjV00penWindow(a6) open window move.l dO,_Window save address beq _Zerror in case of error movea.l $4.w,a0 ,-ExecBase movea.l ThisTask(aO) ,a0 /Process structure move.l pr_WindowPtr (aO) ,_SavedWindowPtr save old value move.l dO,pr_WindowPtr(aO)  enter custom window

...  Program code 

movea.l $4.w, aO ExecBase movea.l ThisTask(aO) ,al  Process structure movea.l pr_WindowPtr (al) ,a0 our window move.l _SavedWindowPtr,pr_WindowPtr (al)  restore old value movea.l _IntuiBase,a6  Intuition jsr _LV0CloseWindow(a6) /close window

Proceed as follows to open a  window on a  PublicScreen: 

LockPubScreen ( ) -  lock PubScreen 

Get information and modify window 

OpenWindowO -  open window 

UnlockPubScreen ( ) -  free PublicScreen 

CloseWindowO -  close window 

IQpenWindowTagList Open window | 

Call: Window =  OpenWindowTagList (  NewWindow, Tagltems) 

DO -606 (A6) AO Al 

STRUCT Window *Window 

STRUCT NewWindow *NewWindow 

STRUCT Tagltem *TagItems 

Function: Like OpenWindow() with ExtNewWindow, except the 

Tagltem field is passed as a  parameter. 

Parameters: NewWindow 

Optional NewWindow structure 

Tagltems Optional Tagltem field 

Result: Window address or 0 

| Refresh WindowFrame Refresh the window frame] 

Call: Ref reshWindowFrame (Window) 

-456 (A6) AO 

STRUCT Window *Window 

Function: Refreshes the window frame of the given window. 

Parameters: Window Window 

| ResetMenuStr ip Super-fast SetM enuStripQ | 

Call: Success =  ResetMenuStrip (window, Menu) 

DO -702 (A6) AO Al 

BOOL Success 

STRUCT Window *Window 

STRUCT Menu *Menu 

Function: If a  MenuStrip has been removed from a  window and not 

changed in the meantime, it can be activated again with this function without having to recalculate JazzX, JazzY,
BeatX, and BeatY. 

Parameters: Window Window 

Menu First menu of the MenuStrip. 

Result: TRUE 

Example: Turn off MenuStrip while a  program is executing: 

movea.l _IntuiBase,a6 must happen first movea . 1 _Window, aO lea _MenuStrip,al jsr _LVOSetMenuStrip(a6)

jumps to '_Routine' possible from here movea.l _IntuiBase,a6  Intuition movea.l _Window,aO  window jsr _LV0ClearMenuStrip(a6) turn off menu

_Routine 

... save registers, etc. 

movea.l _IntuiBase,a6  Intuition movea.l _Window,aO  window jsr _LV0ClearMenuStrip(a6) turn off menu now Flags such as

 CHECKED or ITEMENABLED can be changed 

 Routine 

movea.l _IntuiBase,a6 ,-Intuition movea.l _Window,aO  window lea _MenuStrip,al old menu jsr _LV0ResetMenuStrip(a6) reactivate

... (restore registers, etc. 

rts

| SetMenuStrip Set MenuStrip in a  window | 

Call: Success =  SetMenuStrip (Window, Menu) 

DO -264 (A6) AO Al 

BOOL Success 

STRUCT Window *Window 

STRUCT Menu *Menu 

Function: Installs a  MenuStrip in a  window and calculates the menu 

boxes (JazzX/.Y, BeatX/.Y).

Parameters: Window Window 

Menu First Menu structure 

Result: TRUE 

SetMouseQueue 

Set maximum number of mouse movement messages 

Call: old =  SetMouseQueue (  Window, QueueLength ) 

DO -498 (A6) AO DO 

STRUCT Window *Window 

UWORD QueueLength 

LONG Old 

Function: Sets the maximum number of mouse movement messages 

that may lie unanswered in the window's MessagePort
(only meaningful with slow languages such as C, BASIC, 

etc.).

Parameters: Window Window 

QueueLength 

Number of MouseMove messages. 

Result: Old queue length or -1 (unknown window). 

| SetPointer Set the mouse pointer 1 

Call: SetPointer (Window, Pointer, Height, Width, XOffset, YOffset) 

-270 (A6) AO Al DO Dl D2 D3 

STRUCT Window 'Window 

APTR Pointer 

WORD Height, Width, XOffset, YOffset 

Function: Sets the mouse pointer for a  window. 

Parameters: Window Window 

Pointer Sprite data 

Height Sprite height 

Width Width (1...16) 

XOffset, YOff set 

Offset from selection point. 

| Set Window litles Set title bar text | 

Call: SetWindowTitles (Window, WindowTitle, ScreenTitle) 

-276 (A6) AO Al A2 

STRUCT Window *Window 

APTR WindowTitle, ScreenTitle 

Function: Defines the text displayed in the title bar of the active 

window and screen.

Parameters: Window Window 

WindowTitle 

Window tide, 0  (empty), or -1 (do not change) 

ScreenTitle 

Screen title, 0  (empty) or -1 (do not change) 

| SizeWindow Change window size| 

Call: SizeWindow (Window, DeltaX, DeltaY) 

-288 (A6) AO DO Dl 

STRUCT Window *Window 

WORD DeltaX, DeltaY 

Function: Change the size of a  window (only within the limits of 

MinWidth-MinHeight, MaxWidth-MaxHeight, and if the 

window has a  Size gadget).

Parameters: Window Window 

DeltaX Delta value for width 

DeltaY Delta value for height 

IViewPortAddress Get a  ViewPortl 

Call: viewport =  viewport Address (Window) 

DO -300 (A6) A0 

STRUCT Window *Window 

STRUCT Viewport *ViewPort 

Function: Returns the address of the ViewPort containing the given 

window.

Parameters: Window Window 

Result: Screen ViewPort of the window. 

| WindowLimits Define limits for window size | 

Call: Success -  WindowLimits (Window, MinWidth, HinHeight, MaxWidth, MaxHeight) 

DO -318 (A6) A0 DO Dl D2 D3 

BOOL Success 

STRUCT Window *Window 

WORD MinWidth, MinHeight 

UWORD MaxWidth, MaxHeight 

Function: Sets minimum and maximum values for window size. 

Parameters: Window Window 

MinWidth, MinHeight, MaxWidth, MaxHeight 

New size limits, 0  (do not change) or -1 (full 

screen)

Result: 0  Error 

| WindowToBack Move window behind all other windows | 

Call: WindowToBack (Window) 

-306 (A6) A0 

STRUCT Window *Window 

Function: Moves a  window to the back. 

Parameters: Window Window 

IWindowToFront 

Moves a  window in front of all others! 

Call: WindowToFront (Window) 

-312 (A6) AO 

STRUCT Window *Window 

Function: Move window to the front. 

Parameters: Window Window 

| Zip Window 

Activate alternative window size and position | 

Call: ZipWindow( Window) 

-504 (A6) AO 

STRUCT Window *Window 

Function: Like ZoomGadget: the window is moved to the alternative 

position with the alternative size.

Parameters: Window Window 

Dec 

Hex STRUCTURE Window, 0 

$0 APTR 

wd_Next Wi ndow next window

$4 WORD 

wd_LeftEdge position

$6 WORD 

wd_TopEdge

$8 WORD 

wd_Width size

$A WORD 

wd_Height

$C WORD 

wd_MouseY relative mouse positi

$E WORD 

wd_MouseX

$10 WORD 

wd_MinWidth minimum size

$12 WORD 

wd_MinHeight

$14 WORD 

wd_MaxWidth maximum size

$16 WORD 

wd_MaxHe ight

$18 LONG 

wd_Flags

Flags see below 

$1C APTR 

wd_MenuStrip first menu

$20 APTR 

wd_Title title string

$24 APTR 

wd_FirstRequest active Requester

$28 APTR 

wd_DMRequest double-menu Requester

44 $2C 

WORD 

wd_ReqCount number of Requesters

46 $2E 

APTR 

wd_WScreen

Screen 

50 $32 

APTR 

wd_RPort

RastPort 

54 $36 

BYTE 

wd_BorderLeft , border size

55 $37 

BYTE 

wd_BorderTop ,

56 $38 

BYTE 

wd_BorderRight ,

57 $39 

BYTE 

wd_BorderBottom ,

58 $3A APTR 

wd_BorderRPort , border RastPort

62 $3E 

APTR 

wd_FirstGadget first Gadget

66 $42 

APTR 

wd_Parent window (activation)

70 $46 

APTR 

wd_De s  c endant

74 $4A 

APTR 

wd_Pointer mouse data

78 $4E 

BYTE 

wd_PtrHeight

79 $4F 

BYTE 

wd_PtrWidth

80 $50 

BYTE 

wd_XOffset

81 $51 

BYTE 

wd_YOffset

82 $52 

ULONG 

wd_IDCMPFlags

IDCMP Flags 

86 $56 

APTR 

wd_UserPort

IDCMP 

90 $5A 

APTR 

wd_WindowPort

ReplyPort (Intuition) 

94 $5E 

APTR 

wd_MessageKey

Msg 

98 $62 

BYTE 

wd_DetailPen no longer meaningful

99 $63 

BYTE 

wd_BlockPen

100 $64 

APTR 

wd_CheckMark

Image with new check mark 

104 $68 

APTR 

wd_ScreenTit le

•screen title 

108 $6C 

WORD 

wd_GZZMouseX mouse position within screen

110 $6E WORD 

wd_GZZMouseY

112 $70 

WORD 

wd_GZZWidth

■size of region 

114 $72 

WORD 

wd_GZZHeight

116 $74 

APTR 

wd_ExtData

•extension structure 

120 $78 

APTR 

wd_UserData

•NOT available 

124 $7C 

APTR 

wd_WLayer

•Layer 

128 $80 

APTR 

wd_IFont

•Text Font 

132 $84 

ULONG 

wd_MoreFlags

•new system Flags 

136 $88 

LABEL 

wd_Size

•size definition 

136 $88 

LABEL 

wd_SIZEOF not necessarily end of structure!

WINDOWSING 

= 1  Siz 

a gadget available

WINDOWDRAG 

= 2  mov< 

ible window

WINDOWDEPTH 

= 4  win< 

3ow overlapping gadget 

WINDOWCLOSE 

= 8  clo 

se gadget

SIZEBRIGHT 

= $10 Siz 

5 gadget on the right 

SIZEBBOTTOM 

$20 bot 

com Size gadget

REFRESHBITS 

= $C0 ref- 

resh type

SMART_REFRESH 

= 0   inc 

cemental save

SIMPLE_REFRESH 

= $40 maro 

jal refresh

SUPER_BITMAP 

= $80 buf 

:er everything 

OTHER_REFRESH 

$C0 oth< 

sr methods

BACKDROP 

$100 bacl 

tground window

REPORTMOUSE =  $200  report mouse movements 

GIMMEZEROZERO =  $400 ,-window with border 

BORDERLESS =  $800 ,-window without border 

ACTIVATE =  $1000 ,-activate upon opening 

WINDOWACTIVE =  $2000 /currently active window 

INREQUEST =  $4000 ,-Requesters available 

MENUSTATE =  $8000 ,-menus displayed 

RMBTRAP =  $10000 no menu with right mouse button 

NOCAREREFRESH =  $20000 no refresh messages 

NW_EXTENDED =  $40000 ,-extended NewWindow structure 

WINDOWREFRESH =  $1000000 ,-window being refreshed 

WBENCHWINDOW =  $2000000  Workbench window 

WINDOWTICKED =  $4000000 ,-window received time impulse 

VISITOR =  $8000000 ,-Visitor window 

ZOOMED =  $10000000  zoomed window 

HASZOOM =  $20000000 ,-window with Zoom gadget 

SUPER_UNUSED =  $C0F80000  unused bits 

DEFAULTMOUSEQUEUE 

= 5 

,- number of unanswered Msgs 

Dec Hex 

STRUCTURE NewWindow, 0 

0 $0 

WORD 

nw_LeftEdge position

2 $2 

WORD 

nw_TopEdge

4 $4 

WORD 

nw_Width size

6 $6 

WORD 

nw_Height

8 $8 

BYTE 

nw_Detai 1 Pen meaningless

9 $9 

BYTE 

nw_BlockPen

10 $A 

LONG 

nw_IDCMPFlags

IDCMP Flags 

14 $E 

LONG 

nw_Flags

Flags (see window) 

18 $12 

APTR 

nw_FirstGadget

Gadgets 

22 $16 

APTR 

nw_CheckMark menu check mark

25 $1A APTR 

nw_Title title

30 $1E APTR 

nw_Screen screen

34 $22 

APTR 

nw_BitMap

SuperBitMap 

38 $26 

WORD 

nw_MinWidth min. size

40 $28 

WORD 

nw_MinHeight

42 $2A WORD 

nw_MaxWidth max. size

44 $2C 

WORD 

nw_MaxHeight

46 $2E WORD 

nw_Type screen type

48 $30 

LABEL 

nw_SIZE

48 $30 

LABEL 

nw_SIZEOF

STRUCTURE ExtNewWindow 

nw_SIZE

48 $30 

APTR 

enw_Extension

Tagltem field 

52 $34 

LABEL 

enw_SIZEOF

Tags: 

WA_Left 

= TAG_USEI 

* +  100 

WA_Top 

= TAG_USE1 

* +  101 

WA_Width 

= 

TAG_USER 

+ 

WA_Height 

= 

TAG_USER 

+ 

WA_DetailPen 

= 

TAG_USER 

+ 

WA_BlockPen 

= 

TAG_USER 

+ 

WA_IDCMP 

= 

TAG_USER 

+ 

WA_Flags 

= 

TAG_USER 

+ 

WA_Gadgets 

= 

TAG_USER 

+ 

WA_Checkmark 

= 

TAG_USER 

+ 

WA_Title 

= 

TAG_USER 

+ 

WA_ScreenTitle 

= 

TAG_USER 

+ 

WA_CustomScreen 

= 

TAG_USER 

+ 

WA_Supe r  B i  tMap 

= 

TAG_USER 

+ 

WA_MinWidth 

= 

TAG_USER 

+ 

WA_MinHeight 

= 

TAG_USER 

+ 

WA_MaxWidth 

= 

TAG_USER 

+ 

WA_MaxHeight 

= 

TAG_USER 

+ 

WA_InnerWidth 

= 

TAG_USER 

+ 

WA_InnerHeight 

= 

TAG_USER 

+ 

WA_PubScreenName 

= 

TAG_USER 

+ 

WA_PubScreen 

= 

TAG_USER 

+ 

WA_PubScreenFallBack 

= 

TAG_USER 

+ 

WA_WindowName 

= 

TAG_USER 

+ 

WA_Colors 

= 

TAG_USER 

+ 

WA_Zoom 

= 

TAG_USER 

+ 

WA_MouseQueue 

= 

TAGJUSER 

+ 

WA_BackFill 

= 

TAG_USER 

+ 

WA_RptQueue 

= 

TAG_USER 

+ 

WA_SizeGadget 

= 

TAG_USER 

+ 

WA_DragBar 

= 

TAG_USER 

+ 

WA_DepthGadget 

= 

TAG_USER 

+ 

WA_CloseGadget 

= 

TAG_USER 

+ 

WA_Backdrop 

= 

TAG_USER 

+ 

WA_ReportMouse 

= 

TAG_USER 

+ 

WA_NoCareRe fresh 

= 

TAG_USER 

+ 

WA_Borderless 

= 

TAG_USER 

+ 

WA_Activate 

= 

TAG_USER 

+ 

WA_RMBTrap 

= 

TAG_USER 

+ 

WA_WBenchWindow 

= 

TAG_USER 

+ 

WA_SimpleRefresh 

= 

TAG_USER 

+ 

WA_SmartRefresh 

= 

TAG_USER 

+ 

WA_SizeBRight 

= 

TAG_USER 

+ 

WA_SizeBBottom 

= 

TAG_USER 

+ 

WA_AutoAd j ust 

= 

TAG_USER 

+ 

WA_GimmeZeroZero 

= 

TAG_USER 

+ 

Dec Hex STRUCTURE ColorSpec , 0 

0 $0 WORD cs_Color Index 

2 $2 UWORD cs_Red 

18 bit color value (2.0) 

index or -1

4 $4 UWORD cs_Green 

6 $6 UWORD cs_Blue 

8 $8 LABEL cs_SIZEOF 

Dec 

Hex STRUCTURE Menu, 0 

menu

$0 APTR 

mu_NextMenu next menu

$4 WORD 

mu_LeftEdge position

$6 WORD 

mu_TopEdge

$8 WORD 

mu_Width box size

$A WORD 

mu_Height

$C WORD 

mu_Flags see below

$E APTR 

mu_MenuName menu text

$12 APTR 

mu_FirstItem first Menultem

$16 WORD 

mu_JazzX box with all Menu I terns

$18 WORD 

mu_JazzY

$1A WORD 

mu_BeatX

$1C WORD 

mu_BeatY

$1E LABEL 

mu_SIZEOF

MENUENABLED =  1 

MIDRAWN =   $100 

menu can be selected
 Items are drawn 

Dec Hex STRUCTURE Menultem, 0 

0 $0 APTR mi_NextItem 

4 $4 WORD mi_LeftEdge 

6 $6 WORD mi_TopEdge 

8 $8 WORD mi_Width 

10 $A WORD mi_Height 

12 $C WORD mi_Flags 

14 $E LONG mi_MutualExclude 

18 $12 APTR mi_ItemFill 

22 $16 APTR mi_SelectFill 

26 $1A BYTE mi_Command 

27 $1B BYTE mi_KludgeFi 1 1 0 0 

28 $1C APTR mi_SubItem 

32 $20 WORD mi_NextSelect 

34 $22 LABEL mi_SIZEOF 

 Menultem, Subltem 

next Menultem position size see below exclude

 Image, IntuiText or 0 

 Image, IntuiText or 0 

key code

 Subltem (only with Menultems) 

/when selected 

CHECKIT =     1  check when selected 

ITEMTEXT =     2  . . .Fill points to IntuiText 

COMMSEQ =     4 with Amiga key code 

MENUTOGGLE =     8 /toggle when selected 

ITEMENABLED =  $10 /selection possible 

HIGHFLAGS =  $C0 /display mode for Flags 

HIGHIMAGE =     0 /mi_SelectFill when activated 

HIGHCOMP =  $40 /compliment Item region 

HIGHBOX =  $80 /draw border around item 

HIGHNONE =  $C0 /do not react 

CHECKED =   $100 if CHECKIT: Item is checked 

ISDRAWN =  $1000 ,-SubItems are drawn 

HIGHITEM =  $2000  Item is activated 

MENUTOGGLED =  $4000  Item has been toggled 

NOMENU 

= 

$1F 

NOITEM 

= 

$3F 

NOSUB 

= 

$1F 

MENUNULL 

= 

$FFFF 

CHECKWIDTH =  19 

COMMWIDTH =  27 

LOWCHECKWIDTH =13 

LOWCOMMWIDTH =16 

0 $0 STRUCT 

im_

.ExecMessage, MN_SIZE 

20 $14 LONG 

im_Class

IDCMP event 

24 $18 WORD 

im.

.Code 

.•associated data (key 

26 $1A WORD 

im.

.Qualifier 

copy of InputEvent

28 $1C APTR 

im.

.1 Address 

object address

32 $20 WORD 

im.

.MouseX 

mouse coordinates

34 $22 WORD 

im.

.MouseY 

36 $24 LONG 

im.

.Seconds 

time

40 $28 LONG 

im.

.Micros 

* 

44 $2C APTR 

im.

.IDCMPWindow  window 

48 $30 APTR 

im.

.SpecialLink  internal link 

52 $34 LABEL 

im.

.SIZEOF 

SIZEVERIFY 

= 

before change in size

NEWSIZE 

= 

new window size

REFRESHWINDOW 

= 

.•refresh window 

MOUSEBUTTONS 

= 

mouse buttons

MOUSEMOVE 

= 

$10 

mouse movements

GADGETDOWN 

= 

$20 

/gadget selected 

GADGETUP 

= 

$40 

gadget released

REQSET 

= 

$80 

/Requester appeared 

MENUPICK 

= 

$100 

menu selection

CLOSEWINDOW 

= 

$200 

close window

RAWKEY 

= 

$400 

raw key code

REQVERIFY 

= 

$800 

/before Requester 

REQCLEAR 

= 

$1000 

/Requester cleared 

MENUVERIFY 

= 

$2000 

/prior to menu display 

NEWPREFS 

= 

$4000 

/preferences changed 

DISKINSERTED 

= 

$8000 

/disk inserted 

DISKREMOVED 

= 

$10000 

/disk removed 

WBENCHMESSAGE 

= 

$20000 

j for Open/CloseWorkbench

ACTIVEWINDOW 

= 

$40000 

/active window 

code, etc.)

INACTIVEWINDOW 

DELTAMOVE 

VANILLAKEY 

INTUITICKS 

IDCMPUPDATE 

MENUHELP 

CHANGEWINDOW 

LONELYMESSAGE 

$80000 .-window deactivated 

$100000 /relative mouse movement 

$200000 ASCII characters and strings 

$400000 l/50 second impulse 

$800000 for BOOPSI Gadgets 

$1000000 HELP with menu selection 

$2000000 window position/size changed 

$80000000  invalid message (internal) 

MENUHOT =  1  check MENUCANCEL (MENUVERIFY) 

MENUCANCEL =  2  cancel menu operation? (MENUVERIFY) 

MENUWAITING =  3 ,-waiting for ReplyMsgO 

OKOK =  MENUHOT does not matter 

OKABORT =  4 aha, draw the window 

OKCANCEL =  MENUCANCEL aha, cancel 

WBENCHOPEN 

WBENCHCLOSE 

1 for WBENCHMESSAGE 

SELECTUP =  (IECODE_LBUTTON+IECODE_UP_PREFIX) 

SELECTDOWN =  (IECODE_LBUTTON) 

MENUUP =  (IECODE_RBUTTON+IECODE_UP_PREFIX) 

MENUDOWN =  ( IECODE_RBUTTON) 

ALTLEFT =  (IEQUALIFIER_LALT) 

ALTRIGHT =  (IEQUALIFIER_RALT) 

AMIGALEFT =  (IEQUALIFIER_LCOMMAND) 

AMIGARIGHT =  (IEQUALIFIER_RCOMMAND) 

AMIGAKEYS =  ( AMIGALEFT+AMIGARIGHT) 

CURSORUP =  $4C 

CURSORLEFT =  $4F 

CURSORRIGHT =  $4E 

CURSORDOWN =  $4D 

KEYCODE_Q =  $10 

KEYCODE_X =  $32 

KEYCODE_N =  $3 6 

KEYCODE_M =  $37 

KEYCODE_V =  $34 

KEYCODE_B =  $35 

KEYCODE_LESS =  $38 

KEYCODE_GREATER =  $39 

3. Requesters 

lAutoRequest Display and query requester | Cfl/l.' Response =  AutoReguest (Window, BodyText, PosText, NegText, PosFlags, NegFlags)
DO -348(A6) AO Al A2 A3 DO Dl 

BOOL Response 

STRUCT Window 'Window 

STRUCT IntuiTexc *BodyText, *PosText, *NegText 

ULONG PosFlags, NegFlags 

Function: Opens a  window and displays the Okay-Cancel requester. 

Both gadgets can be activated by clicking or by incoming 

IDCMP events. Warning: prior to AmigaOS 2.0, the size of 

the requester window must be given -  WORD width (D2), height (D3).

Parameters: Window Window structure of the window to be locked. 

BodyText IntuiText structure(s) of the requester. 

PosText IntuiText structure for 'Okay' or 0. 

NegText IntuiText structure for 'Cancel'. 

PosFlags IDCMP flags for 'Okay'. 

NegFlags IDCMP flags for 'Cancel'. 

Result: 0  'Cancel' 

| BuildEasyRequest Args Create system requester | 

Cfl//.' ReqWindow BuildEasyRequestArgs( RefWindow, easystruct, IDCMP, Args ) 

DO -594 (A6) AO Al DO A3 

STRUCT Window *ReqWindow, *Refwindow 

STRUCT Easystruct *easystruct 

ULONG IDCMP 

APTR Args 

Function: Displays a  requester in a  new window. 

Parameters: Window Window locked by the requester. 

easyStruct EasyStruct of the requesters.

IDCMP Flags of the requester window. 

Args See EasyRequest() 

Result: The address of the requester window or 0  (error, cancel) or 

1 (error, continue). 

IBuildSysRequest Create system requester (old) | 

K^all: Reqwindow =  BuildSysRequest (Window, BodyText, PosText, NegText, IDCMPFlags)

DO -360IA6) AO Al A2 A3 DO 

STRUCT Window 'Reqwindow, -window 

STRUCT IntuiText *BodyText, *PosText, *NegText 

ULONG IDCMPFlags 

Function: Displays a  system requester. Warning: prior to AmigaOS 2.0 

the window size must be given (WORD Width.Height
D2/D3). 

Parameters: Window Window to be locked 

BodyText Requester text 

PosText Positive gadget text 

NegText Negative gadget text 

IDCMPFlags 

Flags for the requester window. 

Result: Window of the requesters or 0  (error) or 1  (pre-OS 2.0). 

1 ClearDMRequest Clear double menu requester | 

Call: Response =  ClearDMRequest (Window) 

DO -48 (A6) AO 

BOOL Response 

STRUCT Window *Window 

Function: Attempts to remove the requester that appears when the 

right mouse button is double-clicked.

Parameters: Window Window with DMRequest 

Result: 0  Requester is active and could not be removed. 

| Display Alert Display and query alert message | 

Call: Response =  DisplayAlert (AlertNumber, String, Height) 

DO -90 (A6) DO AO Dl 

BOOL Response 

ULONG AlertNumber 

APTR String 

WORD Height 

Function: Displays the text defined in the alarm string on a  black 

display using the Topaz/8 font. DeadEnds are in red and
Recoverables are in amber. The alarm string is constructed 

as follows:

• 16 bit X  coordinate 

• 8  bit Y  coordinate 

• String ending with 0 

• Byte flag for another string (1 or 0  (=end)) 

Parameters: AlertNumber 

Exec alert code (only bit 31 is important) 

String Alarm string address 

Height Required display height 

Result: 

DeadEnd or right mouse button, TRUE =  left 

mouse button.

Example : Display a  multi-line alarm message: 

movea.l _IntuiBase,a6 moveq #0,d0  Recoverable Alert lea

_Meldung 

(pc) 

,a0 

special string moveq

#38, dl 

height jsr

_LVODisplayAlert(a6) .-display 

tst.l dO bne

_Okay 

_>feldung 

dc.b

1,40 

x coordinate: 1*256+40 dc.b

7+10 

y coordinate dc.b

'Hallo!

,0 

text dc.b not ended yet dc.b

0,20 

dc.b

7+20 

dc.b

'Links 

HALLO ! ' ,  0 

dc.b dc.b

1,248 

dc.b

7+20 

dc.b

■ Rechts 

?# 

IS '.0 

dc.b end

I Easy Request Args 

Query with requester] 

Call: 

GGNum =  EasyRe<juestArgs( Window, easyStruct, IDCMP_ptr, ArgList ) 

DO -588 <A6) A0 Al A2 A3 

STRUCT Window *window 

APTR IDCMP_pcr,Args 

STRUCT EasyStruct *easyStruct 

LONG GGNum 

Function: Display system requester with desired gadgets and 

formattable text in such a  way that the requester is optimized with respect to the screen resolution and the font size.

Parameters: Window Parent window or 0  (default PublicScreen, 

usually Workbench)

IDCMP_ptr 

Address of IDCMP flags for ending. 

easyStruct EasyStruct structure: es_StructSize: EasyStructJSIZEOF es_Flags: 0 es_Tide:

Result: 

es_TextFormat:

Window title or 0  (title of 

AO) 

RawDoFmtO format for 

query (also W)

Args 

es_GadgetFormat: Format string for gadgets gadgets are separated by

Arguments for TextFormat, then for 

GadgetFormat. 

Selected gadget number (numbering: l,2,...,x,0) or -1 

(IDCMP: event in *IDCMP_ptr). 

tst.b _FileName beq _LoadIt movea.l _IntuiBase,a6 movea.l _Window,aO lea _EasyStruct (pc) , al lea _IDCMP(pc) ,a2 lea _FileName,a3 j sr _LVOEasyRequestArgs ( a6 ) tst.l dO bne _LoadIt

Example: Security prompt for a  word processor when the '  LOAD 

TEXT menu item is selected: 

load file?

Loadlt 

_IDCMP 

del 0

_EasyStruct 

del es_SIZEOF, 0,_Title,_Fmt,_Buttons

JTitle 

dc.b "load text' ,0
_Fmt 

dc.b 'the file %s has not yet been saved. ',0
_Buttons 

dc.b ' Load I  Return ', 0

_FileName 

ds.b 256  contains current file name lEndRequest Remove requester]

Call: EndRequest (Requester, window) 

-120 (A6) A0 Al 

STRUCT Requester *Requester 

STRUCT Window *Window 

Function: Removes the currently active requester (makes it inactive). 

Parameters: Requester Requester to be removed 

Window Locked window 

I FreeSysRequest Free a  system requester 1 

Call: FreeSysRequest (Window) 

-372 (A6) A0 

STRUCT Window *Window 

Function: Frees a    system requester that was created with 

BuildSysRequestQ or BuildEasyRequestQ. 

Parameters: Window Window of the requester (result of the 

Build...Request() functions). The values 0  and 1 

have no effect.

1 InitRequester Initialize requester structure | 

Call: InitRequester (Requester) 

-138 (A6) AO 

STRUCT Requester *Requester 

Function: Initializes a  requester structure. After the call, the structure 

must be loaded with user data. This is a  C routine, which is seldom or never used because of the speed of execution.

Parameters: Requester Requester structure 

| Request Display requester | 

Call: Success =  Request (Requester, window) 

DO -240 (A6) AO Al 

BOOL Success 

STRUCT Requester *Requester 

STRUCT window *Window 

Function: Displays a  requester in a  window (POINTREL now works). 

Parameters: Requester Requester to be displayed 

Window Window 

Result: 0  Error 

ISetDMRequest Define double menu requesterl 

Call: success =  SetDMRequest (Window, DMRequester) 

DO -258 (A6) AO Al 

BOOL success 

STRUCT Window *Window 

STRUCT Requester *DMRequester 

Function: Attempts to define the DMRequester. This will not work if 

another DMRequester is active. POINTREL works.

Parameters: Window Window 

DMRequester 

Requester for menu key double-click. 

Result: 0  Error, DMRequest now active. 

[SysReqHandler Query system requester | 

Call: num SysReqHandler ( Window, IDCMPFlagsPtr, Waitlnput ) 

DO -600 A0 Al DO 

STRUCT Window *Window 

CPTR IDCMPFlagsPtr 

BOOL Waitlnput 

Function: Queries a  system requester. 

Parameters: Window Result from Build...Request(). 

IDCMPFlagsPtr 

Address of the IDCMP flags. 

Waitlnput Boolean: wait for input. 

Result: Like EasyRequest(), -2 also possible (no input). 

Dec Hex STRUCTURE EasyStruct , 0 

0 $0 ULONG es_StructSize es_SIZEOF 

4 $4 ULONG es_Flags 0 

8 $8 APTR es_Title  Requester title 

12 $C APTR es_TextFormat  format string for BodyText 

16 $10 APTR es_GadgetFormat  format string for Gadgets 

20 $14 LABEL es_SIZEOF size of structure 

Dec Hex STRUCTURE Requester, 0 

0 $0 APTR rq_01derRequest  older Requester 

4 $4 WORD rq_LeftEdge  position 

6 $6 WORD rq_TopEdge 

8 $8 WORD rq_Width 

10 $A WORD rq_Height 

12 $C WORD rq_RelLeft 

14 $E WORD rq_RelTop 

16 $10 APTR rq_ReqGadget 

20 $14 APTR rq_ReqBorder 

24 $18 APTR rq_ReqText 

28 $1C WORD rq_Flags 

30 $1E UBYTE rq_BackFill 

31 $1F BYTE rq_KludgeFill00 

32 $20 APTR rq_ReqLayer 

36 $24 STRUCT rq_ReqPadl, 32 

68 $44 APTR rq_ImageBMap 

72 $48 APTR rq_RWindow 

76 $4C APTR rq_ReqImage 

80 $50 STRUCT rq_ReqPad2,32 

112 $70 LABEL rq_SIZEOF 

position relative to mouse

Gadgets 

border
IntuiTexts 

see below
Requester color 

 Layer 

BitMap with complete Requester 

/window 

v2.0: Images after Backfill

POINTREL =     1 ,-display relative to mouse or center of window 

PREDRAWN =     2   graphic from ImageBMap 

NOISYREQ =     4 do not filter input 

SIMPLEREQ =    $10 with SIMPLEREFRESH Layer (2.0) 

USEREQIMAGE =    $20 with Images after Backfill, before GGs 

NOREQBACKFILL =   $40 do not fill background 

REQOFFWINDOW =  $1000 ,-Gadget component outside Requester 

REQACTIVE =  $2000 ,-Requester is active 

SYSREQUEST =  $4000 ,-Requester generated by system 

DEFERREFRESH =  $8000 ,-Requester stops Refresh 

ALERT_TYPE =  $80000000 mask 

RECOVERY_ALERT =  0 

DEADEND_ALERT =  $80000000  crash 

Example: Display and query EasyRequest. The requester that follows 

indicates insufficient ChipMem until enough can be reserved after a  'Retry' or 'Cancel' is selected. The result is the memory block allocated with Alloc Vec():

_AskForHelp 

movem.l a2-a4/a6, -(a7) movea.l _IntuiBase,a6 movea.l _Window,a0 lea _EasyReque s  t ( pc ) , a 1 lea _IDCMP(pc),a2 lea _NeededMem(pc) ,a3

jsr _LV0BuildEasyRequestArgs(a6) subq.l #l,dO ble.s _Failure addq.l #l,dO movea .1 dO , a4

_Loop 

movea .1 a4 , aO lea _IDCMP(pc) ,al moveq #-l,dO jsr _LVOSysReqHandler (a6) tst.l dO beq . s _Break bpl.s _Retry addq.l #2,d0 beq . s _Loop bra . s _Break

_Retry 

movea . 1 _Sy sBase , a6 move.l (a3),d0 move.l #MEMF_CLEAR!MEMF_CHIP,dl j sr _LVOAllocVec (a6 ) movea . 1 _IntuiBase , a6 tst.l dO beq . s  _Loop

_Break 

movea .1 dO , a3 movea .1 a4 , aO j sr _LVOFreeSysRequest (a6 ) move .1 a3 , dO bra.s _Exit

_Failure 

moveq #0,d0

_Exit 

movem.l (a7)+, a2-a4/a6 rts

_NeededMem 

del 256000

_IDCMP 

del 0

_EasyRequest 

del es_SIZEOF,0,_Title,_Fmt,_Buttons

_Title 

dc.b "Not enough memory' ,0
_Fmt 

dc.b 'I need %ld byte chipmem!',0
.Buttons 

dc.b ' Retry I  Cancel' ,0

4. Gadgets 

lActivateGadget Activate string or GadTools gadget!

Call: Success =  ActivateGadget (Gadget, Window, Request) 

DO -462 (A6) A0 Al A2 

BOOL Success 

STRUCT Gadget *Gadget 

STRUCT Window *Window 

STRUCT Requester *Request 

Function: Activates a  string or CustomGadget. 

Parameters: Gadget String or CustomGadget 

Window Active window with the gadget 

Requester Requester if GTYP_REQGADGET 

Result: 0  Gadget not activated 

| AddGadget Add gadget to the window list I 

Call: RealPosition =  AddGadget (Window, Gadget, Position) 

DO -42 (A6) A0 Al DO 

UWORD RealPosition, Position 

STRUCT Window *Window 

STRUCT Gadget *Gadget 

Function: Adds a  gadget to a  window list. 

Parameters: Window Window structure of the window. 

Gadget Gadget structure 

Position Position in the list (0...65535). 

Result: Position at which the gadget was inserted in the list 

(0...65535). 

| AddGList Add gadgets to the window list | 

Call: RealPosition =  AddGList (Window, Gadget, Position, Numgad, Requester) 

DO -438 (A6) AO Al DO Dl A2 

UWORD RealPosition, Position, Numgad 

STRUCT Window *window 

STRUCT Gadget *Gadget 

STRUCT Requester *Requester 

Function: Adds liked gadgets to a  window list. 

Parameters: Window Window structure of the window. 

Gadget First gadget to insert. 

Position Position in the list (0...65536 NumGads). 

Numgad Number of gadgets or -1 (all). 

Requester Requester, if GTYP_REQGADGET. 

Result: Position at which the gadgets were inserted in the list 

(0...65535). 

IGadgetMouse Gadget-relative mouse position | 

Call: GadgetMouse( Gadget, GInfo, MousePoint ) 

-570 (A6) AO Al A2 

STRUCT Gadget *Gadget 

STRUCT Gadget Info *GInfo 

STRUCT Point *MousePoint 

Function: Calculates the gadget-relative mouse position (completely 

meaningless, since this information is always available).

Parameters: GInfo Gadgetlnfo structure for the hook routine. 

MousePoint 

Address of two words for the position. 

Gadget Desired gadget 

| Modify Prop Modify proportional gadget | 

Cfl//.' Modi fyProp( Gadget, Window, Requester, Flags, HorizPot, VertPot, 

HorizBody, VertBody) 

-156 (A6) AO Al A2 DO Dl D2 D3 

D4 

STRUCT Gadget *Gadget 

STRUCT Window *Window 

STRUCT Requester "Requester 

UWORD Flags, HorizPot, VertPot, HorizBody, VertBody 

Function: Changes the contents of a  PropGadget and executes a 

complete refresh of the gadget and all following gadgets.

Parameters: Gadget PropGadget 

Window Window of the gadgets 

Requester Requester or 0 

Rags,...Pot,...Body 

Values for Proplnfo 

INewModifyProp Change proportional gadget I 

Call: 

NewModi f yProp ( Gadget, window. Requester, Flags, HorizPot, VertPot, HorizBody,
VertBody, NumGad) 

-468 (A6) AO Al A2 DO Dl D2 D3 

D4 DS 

STRUCT Gadget 'Gadget 

STRUCT Window *Window 

STRUCT Requester *Requester 

UWORD Flags, HorizPot,VertPot,HorizBody,VertBody 

WORD NumGad 

Function: Like ModifyPropO, but this function allows you to specify 

how many gadgets should be refreshed. A  value of 1  will cause only the knob to be refreshed.

Parameters: NumGad Number of gadgets to refresh, -1 (all), or 1  (knob 

only).

See ModifyPropO 

IQbtainGIRPort Allocate RastPort for a  CustomGadgetl 

Call: RPort =  ObtainGIRPort (   GInfo ) 

DO -558 (A6) AO 

STRUCT RastPort *RPort 

STRUCT Gadgetlnfo *GInfo 

Function: Allocates the RastPort of a  CustomGadget and initializes it 

for a  hook routine.

Parameters: GInfo Gadgetlnfo structure of the CustomGadget. 

Result: RastPort or 0 

IQffGadget Turn gadget offl 

Call: Off Gadget (Gadget, window, Requester) 

-174 (A6) AO Al A2 

STRUCT Gadget *Gadget 

STRUCT Window *Window 

struct Requester *Requester

Function: Turns a  gadget off. The gadget is displayed as a  ghost and 

cannot be selected. Also refreshes all gadgets.

Parameters: Gadget Gadget to turn off 

Window Gadget window 

Requester Requester if GTYP_REQGADGET 

| OnGadget Turn gadget on | 

Call: OnGadget (Gadget, Window, Requester) 

-186 (A6) AO Al A2 

STRUCT Gadget *Gadget 

STRUCT Window *Window 

STRUCT Requester * Requester 

Functions, Parameters: 

Opposite of OffGadget(). Allows selection of the gadget 

again.

IRefreshGadgets Refresh gadgets | 

Call: RefreshGadgets (Gadgets, Window, Requester) 

-222 (A6) AO Al A2 

STRUCT Gadget *Gadgets 

STRUCT Window *Window 

STRUCT Requester *Requester 

Function: Refreshes all GGs starting with the given gadget. 

Parameters: Gadgets Address of the first gadget. 

Window Gadget window 

Requester Requester or 0 

IRefreshGList RefreshGListl 

Call: RefreshGList (Gadgets, Window, Requester, NumGad) 

-432 (A6) AO Al A2 DO 

STRUCT Gadget *Gadgets 

STRUCT Window *Window 

STRUCT Requester *Requester 

WORD NumGad 

Function: Similar to RefreshGadgets(), but only allows you to specify 

the number of gadgets to refresh.

Parameters: NumGad Number of gadgets, -1 (all) or -2 (all requester 

gadgets).

See RefreshGadgets() 

I ReleaseGIRPort Free CustomGadget RastPort] 

Call: ReleaseGIRPort (  RPort ) 

-564 (A6) AO 

STRUCT RastPort *RPort 

Function: Free a  RastPort allocated with ObtainGIRPort(). 

Parameters: RPort Result of ObtainGIRPort() or 0. 

| RemoveGadget Remove a  gadget from the window list| 

Call: Position =  RemoveGadget (Window, Gadget) 

DO -228 (A6) AO Al 

UWORD Position 

STRUCT Window *Window 

STRUCT Gadget *Gadget 

Function: Removes a  gadget from the window list. If it's active, it is 

first deactivated.

Parameters: Window Gadget window 

Gadget Gadget to be removed 

Result: Position of the gadget or -1 if it was not in the list (or 

gadget #65535).

IRemoveGList 

Remove gadgets from the window list| 

Call: Position =  RemoveGList (Window, Gadget, Numgad) 

DO -444 (A6) AO Al DO 

UWORD Position 

STRUCT Window *Window 

STRUCT Gadget *Gadget 

WORD Numgad 

Function: Removes several gadgets from the window list and clears 

gg_NextGadget for the last gadget removed. If the active gadget is included, it is first deactivated.

Parameters, Result: 

Numgad Number of gadgets or - 1 (all) 

See RemoveGadgetQ 

IReportMouse 

Change ReportMouse flag| 

Call: ReportMouse (Window, Boolean) 

-234 (A6) AO DO 

BOOL Boolean 

STRUCT Window *Window 

Function: Changes the ReportMouse flag of the window and the 

FollowMouse flag of the active gadget. If a  gadget is active 

when the call is made, the change is only good at the time of gadget activation. C  compilers often make errors with this function because the order of the two parameters is often switched.

Parameters: Window Window 

Boolean TRUE or 0  (bit status) 

ISetEditHook 

Call: OldHook =  SetEditHook (  Hook) 

DO -492 (A6) AO 

Set StringGadget hook | 

STRUCT Hook *OldHook,*Hook 

Function: Defines the global editor hook for StringGadgets. This does 

not just include its own gadgets this should be used only in highly optimized Assembler code.

Parameters: Hook Hook with editor routine for ALL 

StringGadgets. 

Result: Hook of the previous editor routine. 

Warning: Since this routine has not been tested by Commodore yet, 

you should not use it.

ISetGadgetAttrsA Set gadget attributes of a  BoopsiGadgetl 

Call: Result =  SetGadgetAttrsA( Gadget, Window, Requester, TagList ) 

DO -660 (A6) A0 Al A2 A3 

STRUCT Gadget *Gadget 

STRUCT Window *Window 

STRUCT Requester *Requester 

STRUCT Tagltem *TagList 

LONG Result 

Function: Like SetAttrs(), with context information for 

CustomGadgets. 

Parameters: Gadget Boopsi object 

Window Object's window 

Requester For REQGADGETs 

TagList Tagltem field 

Result: Not 0: Gadget must be refreshed to display the new 

attributes.

Dec Hex STRUCTURE Gadgetlnfo, 0 

0 $0 APTR ggi_Screen 

4 $4 APTR ggi_Window 

8 $8 APTR ggi_Requester 

12 $C APTR ggi_RastPort 

16 $10 APTR ggi_Layer 

20 $14 STRUCT ggi_Domain, ibox_SIZEOF 

28 $1C STRUCT ggi_Pens,2 

3 0  $20 APTR ggi_DrInfo 

Dec Hex STRUCTURE I Box, 0 

0 $0 WORD 

2 $2 WORD 

4 $4 WORD 

6 $6 WORD 

ibox_Left ibox_Top ibox_Width ibox_Height

8 $8 LABEL ibox_SIZEOF 

Dec Hex 

0 $0 

STRUCTURE 

APTR gg. 

$4 

$6 

$8 

$A 

$C 

$E 

16 $10 

18 $12 

22 $16 

26 $1A 

30 $1E 

34 $22 

38 $26 

40 $28 

44 $2C 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

APTR 

APTR 

APTR 

LONG 

APTR 

WORD 

APTR 

LABEL 

gg. gg. gg. gg. gg. gg. gg. gg. gg. gg. gg. gg. gg. gg. gg.

Gadget , 0 

.NextGadget 

.LeftEdge 

.TopEdge 

.Width 

.Height 

_Flags 

.Activation 

.GadgetType 

.GadgetRender 

.SelectRender 

.GadgetText 

.Mutua 1  Exc lude 

.Speciallnfo 

.Gadget ID 

.UserData 

.SIZEOF 

next Gadget position size see below see below see below

Border, Image or Null 

Border, Image or Null 

IntuiText or Null 

CustomGadget Hook 

according to GadgetType

User ID 

User data 

GADGHIGHBITS =  3   selection Flags 

GADGHCOMP =  0  complement 

GADGHBOX =  1 box 

GADGHIMAGE =  2 use SelectRender 

GADGHNONE =  3 no reaction 

GADGIMAGE =  4 ... Render is Image structure 

GRELBOTTOM =  8  coordinates relative to bottom 

GRELRIGHT =  $10  coordinates relative to right edge 

GRELWIDTH =  $20  width relative to window width 

GRELHEIGHT =  $40  height relative to window height 

SELECTED =  $80 Gadget is in selected mode 

GADGDISABLED =  $100 ,-Gadget is disabled 

LABELMASK =  $3000 .-meaning of gg_GadgetText 

LABELITEXT =      0 GadgetText is IntuiText 

LABELSTRING =  $1000 GadgetText is string 

LABELIMAGE =  $2000 GadgetText is Boopsi Image 

RELVERIFY 

GADGIMMEDIATE 

ENDGADGET 

FOLLOWMOUSE 

RIGHTBORDER 

LEFTBORDER 

TOPBORDER 

BOTTOMBORDER 

BORDERSNIFF 

TOGGLESELECT 

BOOLEXTEND 

STRINGC ENTER 

STRINGRIGHT 

LONGINT 

ALTKEYMAP 

STRINGEXTEND 

ACTIVEGADGET 

$10 

$20 

$40 

$80 

$8000 

$100 

$2000 

$200 

$400 

$800 

$1000 

$2000 

$4000 

activation: only within Box activate immediately ends Requester

ReportMouse during selection 

right border left border title bar bottom border private toggle when selected

Boollnfo in gg_SpecialInfo 

center StringGG contents right justify StringGG contents

StringGadget for integer values 

StringGadget with another KeyMap 

StringGadget extended 

Gadget is active 

GADGETTYPE 

SYSGADGET 

SCRGADGET 

GZZGADGET 

REQGADGET 

SING 

WDRAGGING 

SDRAGGING 

WUPFRONT 

SUPFRONT 

WDOWNBACK 

SDOWNBACK 

CLOSE 

BOOLGADGET 

GADGET0002 

PROPGADGET 

STRGADGET 

CUSTOMGADGET 

$FC00 

$8000 

$4000 

$2000 

$1000 

$10 

$20 

$30 

$40 

$50 

$60 

$70 

$80 

,-global GadgetTypes 

operating system Gadget screen Gadget

/Gadget for window borders 

.•Requester Gadget 

.•sizing Gadget 

,-movable title bar 

same for Screens

.•window to front 

screen to front close Gadget
BoolGadget 

r PropGadget
 StringGadget 

 CustomGadget 

Dec Hex STRUCTURE Boollnfo, 0 

0 $0 WORD 

2 $2 APTR 

6 $6 LONG 

10 $A LABEL 

bi_Flags bi_Mask bi_Reserved bi_SIZEOF

 BOOLMASK 

bit mask,
0 

image

BOOLMASK 

1 mask 

Dec Hex 

0 $0 

STRUCTURE 

WORD pi. 

$2 

$4 

$6 

8 $8 

10 $A 

$C 

$E 

16 $10 

18 $12 

20 $14 

22 $16 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

LABEL 

PL 

Pi. 

Pi. 

Pi. 

pi.
Pi. 

pi. pi. pi
Pi 

Pi 

Prcplnfo, 0 

.Flags 

.HorizPot 

.VertPot 

.HorizBody 

.VertBody 

.CWidth 

.CHeight 

.HPotRes 

_VPotRes 

_LeftBorder 

.TopBorder 

.SIZEOF 

Flags s.u. 

position slider size container size slider resolution border size

AUTOKNOB 

FREEHORI

FREEVERT 

PROPBORDERLESS 

KNOBHIT 

1 old AutoKnob 

2 /horizontally movable 

4 /vertically movable 

8 no border 

$100 /selected Knob 

KNOBHMIN =     6 /minimal horizontal size 

KNOBVMIN =     4 /minimal vertical size 

MAXBODY =  $FFFF /maximum Knob size 

MAXPOT =  $FFFF /maximum position 

Dec Hex 

0 $0 

$4 

$8 

$A 

$C 

$E 

16 $10 

18 $12 

20 $14 

22 $16 

24 $18 

28 $1C 

32 $20 

36 $22 

STRUCTURE 

APTR si. 

APTR 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

WORD 

APTR 

LONG 

APTR 

LABEL 

si. si. si. si. si. si. si. si. si. si. si. si. si.

Stringlnfo, 

.Buffer 

.UndoBuf fer 

_Buf ferPos 

.MaxChars 

.DispPos 

.UndoPos 

.NumChars 

.DispCount 

.CLeft 

.CTop 

.Extension 

.Longlnt 

.AltKeyMap 

.SIZEOF 

buffer for the contents buffer for the Undo function character position in buffer buffer size including 0  byte offset of the first displayed character position in Undo buffer length of string in buffer number of visible characters offset in Gadget extension structure (2.0) value for integer Gadgets custom key map

Dec Hex STRUCTURE StringExtend, 0 

0 $0 APTR sex_Font /TextFont (open) 

4 $4 STRUCT sex_Pens,2 /colors: text, background 

6 $6 STRUCT sex_ActivePens,2 /colors when activated 

8 $8 ULONG sex_InitialModes /Flags 

12 $C APTR sex_EditHook /edit Hook 

16 $10 APTR sex_WorkBuffer 

20 $14 STRUCT sex_Reserved, 16 

3 6  $24 LABEL sex_SIZEOF 

StringInfo. buffer length 

0 

Dec Hex 

0 $0 

$4 

$8 

$C 

16 $10 

20 $14 

24 $18 

26 $1A 

28 $1C 

30 $1E 

34 $22 

38 $26 

42 $2A 

44 $2C 

STRUCTURE SGWork, 0 

APTR sgw_Gadget 

APTR sgw_StringInfo 

APTR sgw_WorkBuf fer 

APTR sgw_PrevBuf fer 

ULONG sgw_Modes 

APTR sgw_IEvent 

UWORD sgw_Code 

WORD sgw_BufferPos 

WORD sgw_NumChars 

ULONG sgw_Actions 

LONG sgw_LongInt 

APTR sgw_GadgetInfo 

UWORD sgw_EditOp 

LABEL sgw_SIZEOF 

Gadget 

Stringlnfo 

Intuition's result 

previous contents current Flags

InputEvent 

character

CursorPosition 

number of characters what Intuition wants to do value for integer Gadget

Gadget Info 

editor operation current structure size

EditOps: 

EO_NOOP =   1 

EO_DELBACKWARD =   2 

EO_DELFORWARD =   3 

E0310VECURSOR =   4 

EO_ENTER =   5 

EO_RESET =   6 

EO_REPLACECHAR =   7 

EO_INSERTCHAR =   8 

EO_BADFORMAT =   9 

EO_BIGCHANGE =  10 

EO_UNDO =11 

EO_CLEAR =  12 

EO_SPECIAL =  13 

nothing number of characters to delete (0 allowed) number of characters under/before cursor to delete move cursor

ENTER or LF 

undo replace character insert character bad input (IntegerGadget) text completely changed other Undo operations clear string special functions

SGH_REPLACE 

SGMB_REPLACE 

SGMF_REPLACE 

1  modes 

SGM_FIXEDFIELD =  2 

SGMB_FIXEDFIELD =  1 

SGMF_FIXEDFIELD =  2 

SGNL.NOFILTER 

SGMB_NOFILTER 

SGMF_NOFILTER 

=4 do not filter control 

= 2 

= 4 

SGA_USE =  1 take contents from SGWork 

SGAB_USE =  0 

SGAF_USE =  1 

SGA_END =  2 end 

SGAB_END =  1 

SGAF END =  2 

SGA_BEEP 

= 4 

DisplayBeep ( ) 

SGAB_BEEP 

= 2 

SGAF_BEEP 

= 4 

SGA_REUSE 

= 8 

reuse InputEv

SGAB_REUSE 

= 3 

SGAF_REUSE 

= 8 

SGA_REDISPLAY =  $10 Gadget appearance changed 

SGAB_REDISPLAY =    4 

SGAF_REDISPLAY =  $10 

SGH_KEY =  1  process keystroke 

SGH_CLICK =  2 ,-process mouse click 

5. Output Functions 

| Display Beep Cause display to blink] 

Call: DisplayBeept Screen) 

-96 (A6) A0 

STRUCT Screen *Screen 

Function: Causes the entire display or a  given screen to blink. This 

function may be patched.

Parameters: Screen Screen to blink or 0 

|DrawBorder Draw a  border! 

Call: DrawBorder (RastPort, Border, LeftOffset, TopOffset) 

-108 (A6) A0 Al DO Dl 

STRUCT RastPort *RastPort 

STRUCT Border * Border 

WORD LeftOffset, TopOffset 

Function: Draws the border(s) defined in the given Border 

structure^).

Parameters: RastPort RastPort 

Border Border structure 

...Offset Position added to the border vectors. 

| Drawlmage ~ 

Draw an image | 

Call: Drawlmage (RastPort, Image, LeftOffset, TopOffset) 

-114 (A6) AO Al DO Dl 

STRUCT RastPort *RastPort 

STRUCT Image * Image 

WORD LeftOffset, TopOffset 

Function: Copies one or more bit Bitlmages to the given RastPort. 

Parameters: RastPort RastPort 

Image Image structure 

...Offset Position added to the image position. 

Draw extended image | 

I DrawImageState 

Call: 

DrawImageState (RPort , Image, LeftOffset, TopOffset, State, Drawlnfo) 

-618 (A6) AO Al DO Dl D2 A2 

STRUCT RastPort *RPort 

STRUCT Image *  Image 

WORD LeftOffset, TopOffset 

ULONG State 

STRUCT Drawlnfo *DrawInfo 

Function: Draws a  bit image of the desired type: 

IDS_NORMAL =  as with Drawlmage ( ) 

IDS_SELECTED =  as in the selected Gadget 

IDS_DISABLED =  as with disabled Gadgets 

3. Programming withAmigaOS 2jc 

IDS_BUSY =  not yet supported 

IDS_INDETERMINANT =  not yet supported 

IDS_INACTIVENORMAL =  for Gadgets in window borders 

IDS_INACTIVESELECTED =  for Gadgets in window borders 

IDS_INACTIVEDISABLED =  for Gadgets in window borders 

Parameters: RPort RastPort 

Image Image, Customlmage, etc. 

...Offset Position (offset) 

State IDS_... 

Drawlnfo Information on how to display the image. 

[Eraselmage Erase an image 1 

Call: Eraselmage! RPort, Image, Leftoffset, TopOffset ) 

-630 (A6) A0 Al DO Dl 

STRUCT RastPort *RPort 

STRUCT Image * Image 

WORD Lef tOff set, TopOffset 

Function: Removes an image, usually using graphics/EraseRect(). For 

custom images, it depends on the image type.

Parameters: RPort RastPort 

Image Image or Customlmage 

LeftOffset,RightOffset 

Image position offset 

[SituiTextLength TextLength for IntuiText structure | 

Call: length =  IntuiTextLength(IText) 

DO -330 (A6) A0 

LONG length 

STRUCT IntuiText *IText 

Function: Gets the output width of an IntuiText structure in pixels. 

Parameters: IText IntuiText structure 

Result: Output width 

IPrintlText 

Output IntuiText | 

Call: PrintIText(RastPort, IText, LeftOffset, TopOffset) 

-216 (A6) AO Al DO Dl 

STRUCT RastPort *RastPort 

STRUCT IntuiText * IText 

WORD LeftOffset,,, TopOffset 

Function: Outputs the text(s) defined in the given IntuiText 

structure(s) at the given position (offset).

Parameters: RastPort RastPort structure 

IText IntuiText structure(s) 

LeftOffset, TopOffset 

Position 

Dec Hex 

STRUCT 

URE IntuiText, 0 

0 $0 

BYTE 

it_FrontPen foreground color

1 $1 

BYTE 

it_BackPen background color

2 $2 

BYTE 

it_DrawMode draw mode

3 $3 

BYTE 

it_KludgeFill00

4 $4 

WORD 

it_LeftEdge relative position

6 $6 

WORD 

it_TopEdge

8 $8 

APTR 

it_ITextFont

TextAttr structure 

12 $C 

APTR 

it_IText string

16 $10 

APTR 

it_NextText next IntuiText structure

20 $14 

LABEL 

it_SIZEOF

AUTOFRONTPEN 

= 0 

AUTOBACKPEN 

= 1 

AUTODRAWMODE 

= RP_JAM2 

AUTOLEFTEDGE 

= 6 

AUTOTOPEDGE 

= 3 

AUTOITEXTFONT 

= 0 

AUTONEXTTEXT 

= 0 

Dec 

Hex 

STRUCTURE Border, 0 

SO 

WORD 

bd_LeftEdge

$2 

WORD 

bd_TopEdge

$4 

BYTE 

bd_FrontPen

$5 

BYTE 

bd_BackPen

$6 

BYTE 

bd_DrawMode

$7 

BYTE 

bd_Count

$8 

APTR 

bd_XY

$c 

APTR 

bd_Next Bor de r

$10 

LABEL 

bd_SIZEOF

Dec 

Hex 

STRUCTURE Image, 0 

$0 

WORD 

ig_LeftEdge

$2 

WORD 

ig_TopEdge

$4 

WORD 

ig_Width

$6 

WORD 

ig_Height

$8 

WORD 

ig_Depth

$A 

APTR 

ig_ImageData

$E 

BYTE 

ig_PlanePick

$F 

BYTE 

ig_PlaneOnOf f

$10 

APTR 

ig_Next Image

$14 

LABEL 

ig_SIZEOF

/relative position 

foreground color background color draw mode number of vectors

/vector table (2 Words each) 

next Border structure relative position

Bitplanes 

destination plane to be used what happens with the others next Image structure

6. Other Functions 

lAddClass

Add IClass I 

Call: AddClass( Class ) 

-684 (A6) A0 

STRUCT IClass *Class 

Function: Adds an IClass from MakeClass() to the system list. 

Parameters: Class Result from MakeClassQ 

|AUocRemember 

Allocate and remember memory block

Call: MemBlock =  Al locRemember ( RememberKey , Size, Flags) 

DO -396 (A6) A0 DO Dl 

APTR MemBlock 

STRUCT Remember **RememberKey 

ULONG Size, Flags 

Function: Uses AllocMem() to allocate a  memory block. The position 

and size of the reserved block is held in a  RememberNode which is added to a  list so that all blocks can be freed with
FreeRememberO later. 

Parameters: RememberKey 

Address of a  longword that contains the 

address of the first RememberNode. The first time the function is called, this longword must be initialized with the value 0.

Size,Flags Arguments for exec/AllocMem(Size,Flags). 

Result: Address of the allocated memory block or 0. 

Example: Allocate and free memory block(s): 

movea.l _IntuiBase,a6 clr.l -(a7)

 RememberKey =Null 

movea . 1 a7 , aO  RememberKey moveq #rp_SIZEOF,dO  buffer size move.l #MEMF_CLEAR!MEMF_PUBLIC  memory type jsr _LVOAllocRemember (a6) .-allocate tst.l dO test beq _Zerror if error use the memory movea . 1 a7 , aO  RememberKey moveq #bm_SIZEOF,dO buffer size move.l #MEMF_CLEAR!MEMF_PUBLIC  memory type jsr _LVOAllocRemember (a6) /allocate tst.l dO test beq _Zerror if error use memory

_Zerror 

movea.l a7,a0 moveq #-l,dO jsr _LVOFr eeRemember ( a 6 ) addq.l #4,a7

 RememberKey 

clear all free restore stack

| CurrentTime Get the current time | 

Call: CurrentTime (Seconds, Micros) 

-84 (A6) AO Al 

APTR Seconds, Micros 

Function: Writes the current time to the longword at the given 

address. The microsecond value is not exact.

Parameters: Seconds Address of longword for seconds. 

Micros Address of longword for microseconds. 

IDisposeObject Delete an object! 

Call: DisposeObject (  Object ) 

-642 (A6) AO 

APTR Object 

Function: Deletes the given object including its data and subobjects. 

Parameters: Object Result of NewObject() 

| DoubleClick Compare two mouse clicks to the double click period | 

\~>all: IsDouble =  Doubled ick(StartSecs, StartMicros, CurrentSecs, CurrentMicros)

DO -102 (A6) DO Dl D2 D3 

BOOL IsDouble 

ULONG StartSecs, StartMicros, CurrentSecs. CurrentMicros 

Function: Compares the time difference between two mouse clicks to 

the length of the double-click period.

Parameters: Start... Time of the first mouse click. 

Current... Time point of the second mouse click. 

Result: 0  Time points too far apart for a  double-click. 

Example: Evaluate mouse click for IDCMP messages of type 

MOUSEBUTTONS: 

** IntuiMessage in al 

* * 

** Result: dO >< 0  for double-click 

_MouseButtons 

movem . 1 d2-d3/al/a6,-(a7) movea . 1

_IntuiBase,a6 

movem . 1 im_Seconds (al) ,  d2-d3 lea

_01dValues (pc) , aO 

movem . 1

(aO),dO-dl 

movem . 1 d2-d3, (aO) jsr

JLVODoubl eClick(a6) 

tst.l dO movem . 1

(a7)+,d2-d3/al/a6 

OldValues 

ds.l

IFreeClass 

Free ICIassI 

Call: success =  FreeClass (  ClassPtr ) 

DO -714 (A6) AO 

STRUCT IClass *ClassPtr 

Function: Attempts to free the result of a  MakeClass() call. 

Parameters: ClassPtr IClass structure 

Result: 0  IClass could not be freed. 

| FreeRemember Free memory and/or Remember structures | 

Call: FreeRemember (RememberKey, ReallyForget) 

-408 (A6) AO DO 

STRUCT Remember **RememberKey 

BOOL Really Forget 

Function: Frees only the Remember structures (ReallyForget =  0) or 

the associated memory blocks.

Parameters: RememberKey 

Address of the longword containing the 

address of the first Remember structure.

ReallyForget 

Flag that indicates whether memory blocks 

should also be set free.

Example: Allocate several memory blocks that can only be used if no 

errors occur, bit-planes are not much good without bit- maps, and bit-maps can't be used without RastPorts: movea.l _IntuiBase,a6 clr.l -(a7) moveq #-l,d2

 RememberKey =  0 

error, free everything movea .1 a7 , aO moveq #rp_SIZEOF,d0 move . 1 #MEMF_CLEAR ! MEMF_PUBLIC , dl jsr _LVOAllocRemember (a6) move .1 dO , d3 beq . s . Zerror

 RememberKey 

RastPort size 

memory type allocate save result if error movea.l a7,a0  RememberKey moveq #bm_SIZEOF,d0 BitMap size move.l #MEMF_CLEAR!MEMF_PUBLIC,dl memory type jsr _LVOAllocRemember (a6) /allocate move . 1 dO , d4  save result beq.s .Zerror if error moveq #0,d2 no errors, just free Remember structures

. Zerror 

movea.l a7,a0 move .1 d2 , dO jsr _LVOFreeRemember(a6) move .1 d2 , dO

 RememberKey 

/Remember structures or everything 

free

.•return error code 

| Get Attr Get object attributes | 

Call: GetAttr( AttrlD, Object, storagePtr ) 

-654 (A6) DO AO Al 

ULONG result, AttrlD 

APTR Obj ect , StoragePtr 

Function: Returns the attribute values for the given object. 

Parameters: AttrlD Attribute ID 

Object Object address 

StoragePtr Address of longword for result. 

IGetDefPrefs ~~ ~  Get default Preferences! 

Call: Prefs =  GetDefPrefs(Pref Buffer, Size) 

DO -126 (A6) AO DO 

STRUCT Preferences *Prefs, * Pre f Buffer 

WORD Size 

Function: Copies the default Preferences structure to a  buffer. 

Parameters: PrefBuffer Buffer for the Preferences structure. 

Size Buffer size 

Result: Buffer address 

1 GetPrefs Get the current Preferences I 

Call: Prefs =  GetPrefs (PrefBuffer, Size) 

DO -132 (A6) AO DO 

STRUCT Preferences *Prefs, *Pref Buffer 

WORD Size 

Function: Copies the current Preferences structure to a  buffer. 

Parameters: PrefBuffer Buffer for the Preferences structure. 

Size Buffer size 

Result: Buffer address 

ILocklBase Lock IntuitionBasel 

Call: Lock =  LocklBase(LockNumber) 

DO -414 (A6) DO 

ULONG Lock,LockNumber 

Function: Locks one or more Intuition functions. This is required for 

operations such as dynamic entries in the IntuiBase structure.

Parameters: LockNumber 

Number of the internal SignalSemaphore or 0 

(almost all SSs). 

Result: Number of the allocated SignalSemaphore or 0  (almost all). 

IMakeClass Define object class | 

Call: IClass n   MakeClassI ClassID, SuperClassID, SuperClassPtr, Instances! ze, Flags)

DO -678 (A6) AO M  A2 DO Dl 

STRUCT IClass *IClass,*SuperClassPtr 

APTR ClassID, SuperClassID 

uword Instances! ze
ULONG Flags 

Function: Defines a  new object class. The object class must be 

registered with Commodore.

Parameters: ClassID PublicClass name or 0  (PrivateClass) 

SuperClassID 

Superclass name or 0  (PrivateClass) 

SuperClassPtr 

Private Superclass address 

InstanceSize 

Object data structure size 

Flags 0 

Result: IClass or 0 

INewObjectA Create a  new object) 

Call: Object =  NewObjectA( class, classID, tagList ) 

DO -636 (A6) AO Al A2 

APTR Object, classID 

STRUCT IClass *class 

STRUCT Tagltem *tagList 

Function: Create a  Boopsi class object (Boopsi =  Basic object- 

oriented Programming System for Intuition).

Parameters: class BoopsiClass from MakeClass() 

classID Name if class=0 tagList Tagltems for the object

Result: Object that may be used, for example, as a  gadget or image. 

| Next Object Get the next object! 

Call: Object =  NextObject (   objectPtrPtr ) 

DO -666 (A6) AO 

APTR Object, objectPtrPtr 

Function: Gets the next object entered in a    list by 

OM_ADDMEMBER. 

Parameters: objectPtrPtr Address of the list or an object. 

Result: Object or 0 

| Pointlnlmage Checks to see if a  point is in an Image | 

Call: DoesContain =  Pointlnlmage ( Point, Image ) 

DO -624 (A6) DO AO 

BOOL DoesContain 

STRUCT Point Point (LONG) 

STRUCT Image * Image 

Function: Checks to see if a  point at the given coordinates in the 

Image is set (for BOOLMASK, etc.). 

Parameters: Point X«16!Y (packed coordinates) 

Image Image or Customlmage 

Result: 0  Point not set 

| RemoveClass Remove Boopsi class from system list I 

Call: RemoveClass (   classPtr ) 

-708 (A6) AO 

STRUCT iciass *classPtr 

Function: Removes an IClass from the system list. 

Parameters: ClassPtr Result from MakeClass() 

| SetAttrsA Set object attributes! 

Call: result =  SetAttrsA ( object, TagList ) 

DO -648 (A6) AO Al 

APTR Object 

STRUCT Tagltem *TagList 

ULONG result 

Function: Defines a  set of attributes for a  Boopsi object. 

Parameters: Object Object 

TagList Tagltem field 

Result: Not 0  if the object is a  gadget and should be refreshed in 

order for the new attributes to be displayed.

| SetPrefs Change the Preferences settings | 

Call: Prefs =  SetPrefs (PrefBuffer, Size, Inform) 

DO -324 (A6) AO DO Dl 

STRUCT Preferences *Prefs, *Pref Buffer 

LONG Size 

BOOL Inform 

Function: Changes the default Preference settings and informs 

(optional) all windows. The Preferences structure no longer 

contains all the defaults. This routine should never be used.

Parameters: PrefBuffer Custom settings 

Size Size of custom structure 

Inform Boolean -  Inform windows 

Result: PrefBuffer 

lUnlocklBase Free IntuitionBasej

Call: unlocklBase(Lock) 

-420 (A6) AO 

ULONG Lock 

Function: Frees the SignalSemaphore(s) locked with LockIBase(). 

Parameters: Lock SignalSemaphore number or 0  (almost all). 

Dec Hex STRUCTURE Remember, 0 

0 $0 APTR rm_NextRemember 

4 $4 LONG rm_RememberSize 

8 $8 APTR rm_Memory 

12 $C LABEL rm_SIZEOF 

FILENAME_SIZE =30 file name size 

POINTERSIZE =  (1+16+1) *2 mouse pointer size 

TOPAZ_EIGHTY =  8 

TOPAZ_SIXTY =  9 

Dec Hex STRUCTURE Preferences, 0  Anachronism! 

0 $0 BYTE pf_FontHeight 

1 $1 BYTE pf_PrinterPort 

2 $2 WORD pf_BaudRate 

4 $4 STRUCT pf_KeyRptSpeed,TV_SIZE 

12 $C STRUCT pf_KeyRptDelay,TV_SIZE 

STRUCT pf_DoubleClick,TV_SIZE 

STRUCT pf_PointerMatrix, POINTERSIZE*2 

BYTE pf_XOffset 

BYTE pf_YOffset 

WORD pf_colorl7 

WORD pf_colorl8 

WORD pf_colorl9 

WORD pf_PointerTicks 

WORD pf_color0 

WORD pf_colorl 

WORD pf_color2 

WORD pf_color3 

BYTE pf_ViewXOffset 

BYTE pf_ViewYOffset 

WORD pf_ViewInitX 

WORD pf_ViewInitY 

BOOL EnableCLI 

WORD pf_PrinterType 

20 $14 

28 $1C 

64 $40 

65 $41 

66 $42 

68 $44 

70 $46 

72 $48 

74 $4A 

76 $4C 

78 $4E 

80 $50 

82 $52 

83 $53 

84 $54 

86 $56 

88 $58 

90 $5A 

92 $5C 

122 $7A 

124 $7C 

126 $7E 

128 $80 

130 $82 

132 $84 

134 $86 

136 $88 

138 $8A 

140 $8C 

142 $8E 

144 $90 

146 $92 

147 $93 

148 $94 

STRUCT pf_PrinterFilename, FILENAME_SIZE 

WORD pf_PrintPitch 

WORD pf_PrintQuality 

WORD pf_PrintSpacing 

WORD pf_PrintLeftMargin 

WORD pf_PrintRightMargin 

WORD pf_PrintImage 

WORD pf_PrintAspect 

WORD pf_PrintShade 

WORD pf_PrintThreshold 

WORD pf_PaperSize 

WORD pf_PaperLength 

WORD pf_PaperType 

BYTE pf_SerRWBits 

BYTE pf_SerStopBuf 

BYTE pf_SerParShk 

$95 

BYTE 

$96 

STRUCT 

$B4 

BYTE 

$B5 

BYTE 

$B6 

UWORD 

$B8 

WORD 

$BA 

UWORD 

$BC 

UBYTE 

$BD 

UBYTE 

$BE 

UWORD 

$C0 

UWORD 

$C2 

UBYTE 

$C3 

UBYTE 

$C4 

LABEL 

pf_LaceWB pf_WorkName, FILENAME_SIZE pf _RowS i  zeChange pf_ColumnSizeChange pf_PrintFlags pf_PrintMaxWidth pf _Pr intMaxHe ight pf_PrintDensity pf_PrintXOffset pf_wb_Width pf_wb_Height pf_wb_Depth pf_ext_size pf_SIZEOF

LACEWB 

PARALLEL_PRINTER 

= 

SERIAL_PRINTER 

= 

BAUD_110 

= 

BAUD_300 

= 

BAUD_1200 

= 

BAUD_2400 

= 

BAUD_4800 

= 

BAUD_9600 

= 

BAUD_19200 

= 

BAUD_MIDI 

= 

FANFOLD 

= 

SINGLE 

= 

$80 

PICA 

= 

ELITE 

= 

$400 

FINE 

= 

$800 

DRAFT 

= 

LETTER 

= 

$100 

SIX_LPI 

= 

EIGHT_LPI 

= 

$200 

IMAGE_POSITIVE 

= 

IMAGE_NEGATIVE 

= 

ASPECT_HORI

= 

ASPECT_VERT 

= 

SHADE_BW 

= 

SHADE_GREYSCALE 

= 

SHADE_COLOR 

= 

US_LETTER 

= 

US_LEGAL 

= 

$10 

N_TRACTOR 

= 

$20 

W_TRACTOR 

= 

$30 

CUSTOM 

= 

$40 

CUSTOM_NAME 

= 

ALPHA_P_101 

= 

BROTHER_15XL 

= 

CBM_MPS10 00 

= 

DIAB_630 

= 

DIAB_ADV_D25 

= 

DIAB_C_150 

= 

EPSON 

= 

EPSON_JX_80 

= 

OKIMATE_20 

= 

QUME_LP_20 

= 

$A 

HP_LASERJET 

= 

$B 

HP_LASERJET_PLUS = 

$c 

SBUF_512 

= 

SBUF_1024 

= 

SBUF_2048 

= 

SBUF_4096 

= 

SBUF_8000 

= 

SBUF_16000 

= 

SREAD_BITS 

= $F0 

 Pf. 

.SerRWBits 

SWRITE_BITS 

= $F 

SSTOP_BITS =  $F0   pf_SerStopBuf 

SBUFSIZE_BITS =   $F 

SPARITY_BITS 

SHSHAKE_BITS 

$F0   pf_SerParShk 

$F 

SPARITY_NONE 

SPARITY_EVEN 

SPARITY_ODD 

SHSHAKE_XON 

SHSHAKE_RTS 

SHSHAKE_NONE 

CORRECT_RED 

CORRECT_GREEN 

CORRECT_BLUE 

CENTER_IMAGE 

IGNORE_DIMENSIONS =  0 

BOUNDED_DIMENSIONS =  $10 

ABSOLUTE_DIMENSIONS =  $20 

PIXEL_DIMENSIONS 

MULTI PLY_DIMENS IONS 

$40 

$80 

INTEGER_SCALING 

= $100 

ORDERED_DITHERING =  0 

HALFTONE_DITHERING =  $200 

FLOYD_DITHERING =  $400 

ANTI_ALIAS 

GREY_SCALE2 

= $800 

=$1000 for A2024 monitor 

CORRECT_RGB_MASK =  ( CORRECT_RED+CORRECT_GREEN+CORRECT_BLUE ) 

DIMENSIONS_MASK 

(BOUNDED_DIMENSIONS+ABSOLUTE_DIMENSIONS+PIXEL_DIMENSIONS+MULTIPLY_DIMENSIONS) 

DITHERING_MASK =  (HALFTONE_DITHERING+FLOYD_DITHERING) 

Dec Hex STRUCTURE ICLASS,0 

0 $0 STRUCT cl_Dispatcher,h_SIZEOF 

$14 ULONG 

cl_Reserved

$18 APTR 

cl_Super

$1C APTR 

cl_ID

$20 UWORD 

cl_InstOf fset

$22 UWORD 

cl_InstSize

$24 ULONG 

cl_UserData

$28 ULONG 

c l_Subclas sCount

$2C ULONG 

cl_ObjectCount

$30 ULONG 

cl_Flags

 Hook 

0 

string

User data for the Class 

number of subclasses number of objects

CLB_INLIST =  0, CLF_INLIST =  1 Class in PublicClassList 

Dec Hex STRUCTURE _Object,0 

0 $0 STRUCT o_Node,MLN_SIZE 

8 $8 APTR o_Class 

12 $C LABEL _object_SIZEOF 

Dec Hex STRUCTURE Msg,0 

0 $0 ULONG msg_MethodID data to follow 

4 $4 . . .  according to ID (see below) 

OM_NEW =  $101 /parameter is really a  Class 

OM_DISPOSE =  $102  self -deleting (no parameters) 

OM_SET =  $103 set attributes (list) 

OM_GET =  $104 read attributes 

OM_ADDTAIL =  $105 add self to list 

OM_REMOVE =  $106 .-remove self from list (no parameters) 

OM_NOTIFY =  $107  notify self 

OM_UPDATE =  $108 NotifyMsg 

OM_ADDMEMBER =  $109  

OM_REMMEMBER =  $10A  

Dec Hex STRUCTURE opSet,4 OM_NEW, OM_SET 

4 $4 APTR ops_AttrList new attributes 

8 $8 APTR ops_GInfo 0 for 0M_NEW 

Dec Hex STRUCTURE opUpdate,4 0M_UPDATE 

4 $4 APTR opu_AttrList /attributes 

8 $8 APTR opu_GInfo 

12 $C ULONG opu_Flags 

OPUB_INTERIM =  0, OPUF_INTERIM =  1 

Dec Hex STRUCTURE opGet , 4  OM_GET 

$4 ULONG 

$8 APTR 

°Pg_AttrID 

opg_Storage

Dec Hex STRUCTURE opAddTail,4 OM_ADDTAIL 

4 $4 APTR opat_List 

Dec Hex STRUCTURE opMember,4 OM_. . .MEMBER 

4 $4 APTR opam_Object 

GA_Dummy 

GA_LEFT 

GA_RELRIGHT 

GA_TOP 

GA_RELBOTTOM 

GA_WIDTH 

GA_RELWIDTH 

GA_HEIGHT 

GA_RELHEIGHT 

GA_TEXT 

GA_IMAGE 

GA_BORDER 

GA_SELECTRENDER 

GA_H1GHLIGHT 

GA_DISABLED 

GA_GZZGADGET 

GA_ID 

GA_USERDATA 

GA_SPECIALINFO 

= TAG_USER+$30000 

= TAG_USER+$30001 

= TAG_USER+$30002 

= TAG_USER+$30003 

= TAG_USER+$30004 

= TAG_USER+$30005 

= TAG_USER+$30006 

= TAG_USER+$30007 

= TAG_USER+$30008 

= TAG_USER+$30009 

= TAG_USER+$3000A 

= TAG_USER+$3000B 

= TAG_USER+$3000C 

= TAG_USER+$3000D 

= TAG_USER+$3000E 

= TAG_USER+$3000F 

= TAG_USER+$30010 

= TAG_USER+$30011 

= TAG_USER+$30012 

Gadget attributes 

GA_SELECTED 

GA_ENDGADGET 

GA_IMMEDIATE 

GA_RELVERIFY 

GA_FOLLOWMOUSE 

GA_RIGHTBORDER 

GA_LEFTBORDER 

GA_TOPBORDER 

GA_BOTTOMBORDER 

GAJTOGGLESELECT 

GA_SYSGADGET 

GA_SYSGTYPE 

GA_PREVIOUS 

GA_NEXT 

GA_DRAWINFO 

GA_INTUITEXT 

GA_LABELIMAGE 

= TAG_USER+$30013 

= TAG_USER+$30014 

= TAG_USER+$3 0015 

= TAG_USER+$30016 

= TAG_USER+$30017 

= TAG_USER+$30018 

= TAG_USER+$30019 

= TAG_USER+$3001A 

= TAG_USER+$3001B 

= TAG_USER+$3001C 

= TAG_USER+$3001D 

= TAG_USER+$3001E 

= TAG_USER+$3001F 

= TAG_USER+$30020 

= TAG_USER+$30021 

= TAG_USER+$30022 

= TAG_USER+$30023 

PGA_Dummy 

PGA_FREEDOM 

PGA_BORDERLESS 

PGA_HORIZPOT 

PGA_HORIZBODY 

PGA_VERTPOT 

PGA_VERTBODY 

PGA_TOTAL 

PGA_VISIBLE 

PGA_TOP 

= TAG_USER+$31000 PropGadget attributes 

= TAG_USER+$31001 

= TAG_USER+$31002 

= TAG_USER+$31003 

= TAG_USER+$31004 

= TAG_USER+$31005 

= TAG_USER+$31006 

= TAG_USER+$31007 

= TAG_USER+$31008 

= TAG_USER+$31009 

STRINGA_Dummy 

STRINGA_MaxChars 

STRINGA_Buffer 

STRINGA_UndoBuffer 

STRINGA_WorkBuffer 

STRINGAJBufferPos 

STRINGA_DispPos 

STRINGA_AltKeyMap 

STRINGA_Font 

STRINGA_Pens 

STRINGA_Act ivePens 

STRINGA_EditHook 

STRINGA_EditModes 

STRINGA_ReplaceMode 

STRINGA_FixedFieldMode 

STRINGA_NoFilterMode 

STRINGA_Just i  f icat ion 

STRINGA_LongVal 

STRINGAJTextVal 

TAG_USER+$32000 

TAG_USER+$32001 

TAG_USER+$32002 

TAG_USER+$32003 

TAG_USER+$32004 

TAG_USER+$32005 

TAG_USER+$32006 

TAG_USER+$32007 

TAG_USER+$32008 

TAG_USER+$32009 

TAG_USER+$3200A 

TAG_USER+$3200B 

TAG_USER+$3200C 

TAG_USER+$3200D 

TAG_USER+$3200E 

TAG_USER+$3200F 

TAG_USER+ $32010 

TAG_USER+$32011 

TAG_USER+$32012 

StringGadget attributes 

SG_DEFAULTMAXCHARS =  128  default buffer length 

LAYOUTA_Dummy =  TAG_USER+$38000 /Layout 

LAYOUTA_LAYOUTOBJ =  $38001 

LAYOUTA_SPACING =  $38002 

LAYOUTA_ORIENTATION =  $38003 

LORIENT_NONE =  0 ,-orientation 

LORIENT_HORIZ =  1 

LORIENT_VERT =  2 

GM_HITTEST =  0  send Hook commands to GMR_GADGETHIT 

GM_RENDER =  1 draw self 

GM_GOACTIVE =  2 ,-Gadget activated 

GM_HANDLEINPUT =  3 /process input 

GM_GOINACTIVE =  4 ,-Gadget inactivated 

Dec Hex STRUCTURE MsgHeader, 0  ,- again for structures 

4 $4 ULONG MethodID 

8 $8 LABEL methodid_SIZEOF 

Dec Hex STRUCTURE gpHitTest,methodid_SIZEOF 

4 $4 APTR gpht_GInfo 

8 $8 WORD gpht_MouseX 

10 $A WORD gpht_MouseY 

GMR_GADGETHIT =  4 not hit =  0 

Dec Hex STRUCTURE gpRender,methodid_SIZEOF 

4 $4 APTR gpr_GInfo GadgetContext 

8 $8 APTR gpr_RPort 

12 $C LONG gpr_Redraw 

GREDRAW_UPDATE =  2 ,- update with new attributes 

GREDRAW_REDRAW =  1  refresh 

GREDRAW_TOGGLE =  0  toggle 

Dec Hex STRUCTURE gpInput,methodid_SIZEOF also GM_GOACTIVE 

4 $4 APTR gpi_GInfo 

gpi_IEvent gpi_Termination gpi_MouseX gpi_MouseY

Dec Hex STRUCTURE gpGoInactive,methodid_SIZEOF 

4 $4 APTR gpgi_GInfo 

8 $8 ULONG gpgi_Abort V37 and up! 

$8 

APTR 

$c 

APTR 

$10 

WORD 

$12 

WORD 

GMR_MEACTIVE =  0 

GMR_NOREUSE =  2 

GMR_REUSE =  4 

GMRVERIFY =  8 

GMRB_NOREUSE =  1, 

GMRF_NOREUSE =  2 

GMRB_REUSE =  2, 

GMRF_REUSE =  4 

GMRB_VERIFY =  3, 

GMRF_VERIFY =  8 

ICM_SETLOOP =  $402 

ICM_CLEARLOOP =  $403 

ICM_CHECKLOOP =  $404 

ICA_Dummy 

ICA_TARGET 

ICA_MAP 

ICSPECIAL_CODE 

$40000 

ICA_Dummy+l 

ICA_Dummy+2 

ICA_Dummy+3 

ICTARGET_IDCMP =  -1 $ffffffff 

CUSTOMIMAGEDEPTH =  -1  depth for CustomGadgets 

IMAGE_ATTRIBUTES 

IA_LEFT 

IA_TOP 

IA_WIDTH 

IA_HEIGHT 

IA_FGPEN 

IA_BGPEN 

IA_DATA 

IA_LINEWIDTH 

IA_PENS 

IA_RESOLUTION 

IA_APATTERN 

IA_APATSIZE 

IA_MODE 

IA_FONT 

IA_OUTLINE 

IA_RECESSED 

IA_DOUBLEEMBOSS 

IA_EDGESONLY 

TAG_USER+$20000 

IMAGE_ATTRIBUTES+ $  0 1 

IMAGE_ATTRIBUTES+$02 

IMAGE_ATTRIBUTES+ $0 3 

IMAGE_ATTRI BUTES+ $ 0  4 

IMAGE_ATTRIBUTES+$05 

IMAGE_ATTRIBUTES+$06 

IMAGE_ATTRIBUTES+ $  0 7 

IMAGE_ATTRIBUTES+ $  0 8 

IMAGE_ATTRIBUTES+ $  0E 

IMAGE_ATTRIBUTES+ $ OF 

IMAGE_ATTRIBUTES+ $  0 1 0 

IMAGE_ATTRIBUTES+ $  0 1 1 

IMAGE_ATTR I BUTES + $ 0 1 2 

IMAGE_ATTRIBUTES+$013 

IMAGE_ATTRIBUTES+ $  0 1 4 

IMAGE_ATTRIBUTES+ $  0 1 5 

IMAGE_ATTRIBUTES+ $ 0 1 6 

IMAGE_ATTRI BUTES+ $ 0 17 

SYSIA_Size =  IMAGE_ATTRIBUTES+$0B  system IClass 

SYSIA_Depth =  IMAGE_ATTRIBUTES+$0C 

SYSIA_Which =  IMAGE_ATTRIBOTES+$0D 

SYSIA_DrawInfo =  IMAGE_ATTRIBUTES+$018 

SYSIA_Pens 

IA_SHADOWPEN 

IAHIGHLIGHTPEN 

IA_PENS 

IMAGE_ATTRIBUTES+ $ 0  9 

IMAGE_ATTRIBUTES+$OA 

SYSISIZE_MEDRES =  0 

SYSISIZE_LOWRES =  1 

SYSISIZEHIRES =  2 

DEPTHIMAGE = 

0  SYSIA_Witch values 

ZOOMIMAGE 

SIZEIMAGE 

CLOSEIMAGE = 

SDEPTHIMAGE = 

LEFTIMAGE 

$A 

UPIMAGE 

$B 

RIGHTIMAGE = 

$c 

DOWNIMAGE 

$D 

CHECKIMAGE = 

$E 

MXIMAGE 

$F 

IM_DRAW 

= $202 

draw self

IM_HITTEST 

= $203 

 TRUE=hit 

IM_ERASE 

= $204 

delete self

IM_MOVE 

= $205 

redraw

IM_DRAWFRAME 

= $206 

draw within Box

IM_FRAMEBOX 

= $207 

IM_HITFRAME 

= $208 

IM_ERASEFRAME 

= $209 

IDS_NORMAL 

= 0 

IDS_SELECTED 

= 1   active 

IDS_DISABLED 

= 2   cannot be selected 

IDS_BUSY 

= 3 

IDS_INDETERMINATE 

= 4 

IDS_INACTIVENORMAL 

= 5   within window bord< 

IDS_INACTIVESELECTED 

= 6   

IDS_INACTIVEDISABLED 

= 7   

IDS_INDETERMINANT 

= IDS_INDETERMINATE 

Dec Hex STRUCTURE impFrameBox, 4 

$4 APTR 

imp f  _Cont en t  s Box

$8 APTR 

impf_FrameBox

$C APTR 

impf_DrInfo

$10 LONG 

impf_FrameFlags

FRAMEB_SPECIFY 

0, FRAMEF_SPECIFY =  1 

Dec Hex STRUCTURE impDraw, 4 

$4 APTR 

impd_RPort

$8 WORD 

impd_OffsetX

$A WORD 

impd_OffsetY

$C ULONG 

impd_State

$10 APTR 

impd_DrInfo

$14 WORD 

impd_DimensionsWidth

$16 WORD 

impd_DimensionsHeight tec

Hex STRUCTURE impErase , 4 

$4 APTR 

impe_RPort

$8 WORD 

impe_Of fsetX

$A WORD 

impe_Of fsetY

$C WORD 

impe_DimensionsWidth

$E WORD 

impe_DimensionsHeight tec

Hex STRUCTURE impHitTest,4 

$4 WORD 

imph_PointX

$6 WORD 

imph_PointY

$8 WORD 

imph_Dimens ionsWidth

$A WORD 

imph_Dimens ionsHe ight
