# The GadTools Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

## 3.1 .7 The GadTools Library

The GadTools library, which uses the name "gadtools.library" for
OpenLibraryO, is used to simplify the programming of gadgets, menus, 

and Intuition events. Previous operating system versions required many data structures to be created by hand. Now, an application can be made more user-friendly with just a  few calls to the functions of the GadTools library.

GadTools Library Functions 

CreateContext 

CreateGadgetA 

CreateMenusA 

DrawBevelBoxA 

FreeGadgets 

FreeMenus 

FreeVisuallnfo 

GetVisuallnfoA 

GTJBeginRefresh 

GT_EndRefresh 

GTFilterlMsg 

GT_GetIMsg 

GT_PostFilterIMsg 

GT_RefreshWindow 

GT_ReplyIMsg 

GT_SetGadgetAttrsA 

LayoutMenuItemsA 

LayoutMenusA 

Description of the Functions 

ICreateContext Reserve a  data blockl 

Call: gad =  CreateContext (glistpointer) 

DO -114 (A6) AO 

STRUCT Gadget *gad, **glistpointer 

Function: Reserves room for the context data. This function must be 

called before creating gadgets with the GadTools library.

Parameters: glistptr Address of a  longword ending in 0  where 

GadTools will store the address of the gadget 

being generated. The gadget address can then be given to Intuition later (AddGList() etc.).

Result: Address of a  context gadget or 0. 

ICreateGadgetA Create a  GadTools gadget I 

Call: gad =  CreateGadgetA(kind, previous, newgad, taglist) 

DO -30 (A6) DO AO Al A2 

STRUCT Gadget *gad, *previous 

ULONG kind 

STRUCT NewGadget *newgad 

STRUCT Tagltem *taglist 

Function: Gets a  gadget of the given type, initializes it as indicated by 

the tags and the NewGadget structure, and adds it to an existing gadget.

Parameters: kind Gadget type 

previous Gadget to which the new GG will be added. newgad NewGadget structure that describes the gadget. taglist Tagltem field with special instructions.

## 3.1 The Libraries and their Functions

Tags: GTJJnderscore (Char (starting with version 37)) defines 

the character for which the following character will be underlined in the gadget text (for example, to indicate the
"hotkey" that will activate the gadget). If the "_" character 

is selected and the gadget text reads "_Color", then the gadget text will appear on screen with the "C" underlined.

GA_Disabled (BOOL) is used to turn off the gadget 

(TRUE). By default, the gadget is active. 

GTCB_Checked (BOOL) is used to display a  check mark 

(TRUE) in a  Checkbox gadget. The default is no check 

mark.

GTCY_Labels (STRPTR *) sets the O-terminated string 

address field for Cycle gadgets.

GTCY_Active (UWORD) sets the number (0...) of the 

active text for a  Cycle gadget. The default string is 0.

GTIN_Number (ULONG) sets the contents (value) of an 

Integer gadget. The default value is 0. 

GTIN_MaxChars (UWORD) sets the maximum number of 

decimal places for an Integer gadget. The default is 10.

STRINGA_ExitHelp (BOOL) (V37 and up) If TRUE, an 

Integer gadget can be ended by pressing the Help key. 

You will then get a  GADGETUP with the RawKey code of 

the Help key ($5F).

GA_TabCycle (BOOL) (V37 and up) If TRUE, pressing 

(Tab) or 1  shin H Tab) will activate the next or the previous 

gadget. The default is TRUE.

GTLV_Top (UWORD) sets the number of the first visible 

entry in a  ListView gadget (scrollable list). The default is
Entry 0. 

GTLV_Labels (STRUCT List *) passes a  list whose 

LN_NAME entries will appear in the ListView gadget (box 

with scrollable list).

GTLV_ReadOnly (BOOL) sets the read-only attribute for a 

ListView gadget (TRUE). 

GTLV_ScrollWidth (UWORD) sets the width of the scroll 

bar. The default is 16 pixels.

GTLV_ShowSelected (STRUCT Gadget *) passes a  String 

gadget, in which the selected entry can be edited, to a
ListView gadget. If the value 0  is passed, the selected item 

is displayed below the ListView gadget.

GTLV_Selected (UWORD) sets the number of the pre- 

selected item in a  ListView gadget. The default is -1, which means no item is pre-selected.

LAYOUTA_Spacing sets the number of lines between two 

items in a  ListView gadget. The default is 0.

GTMXLabels (STRPTR *) is a  0-terminated string address 

field containing the texts that will be displayed next to the selection buttons in a  mutually exclusive selection table
(MutualXclusive gadget). 

GTMX_Active (UWORD) sets the active button number 

for an MX gadget. The default button is 0.

GTMX_Spacing (UWORD) sets the distance between two 

items in an MX gadget. The default is one line (1).

GTNM_Number (LONG) sets the value to be displayed as a 

decimal string in a  non-revisable gadget (default: 0).

GTNM_Border (BOOL) displays a  border (TRUE). 

GTPA_Depth (UWORD) sets the number of bit-planes for a 

Palette gadget. The default is one bit-plane (2A1 colors). 

GTPA_Color (UBYTE) sets the default for the selected 

color of a  Palette gadget (otherwise 1  is used).

GTPA_ColorOffset (UBYTE) determines the number of the 

first color to be queried in a  Palette gadget. The default is color 0.

GTPAJndicatorWidth (UWORD) sets the width of the 

palette's color indicator if it is used.

GTPAJndicatorHeight (UWORD) is the same for the 

height of the color indicator.

GTSCJTop (WORD) sets the start of a  ScrollGadget (similar 

to the old PropGadget). The default is 0.

GTSC_Total (WORD) sets the number of available units 

(ScrollGadget, default: 0  units). 

GTSCJVisible (WORD) sets how many units will be visible 

at once (ScrollGadget, default: 2  units from GTSC_Total).

GTSC_Arrows (UWORD) equips the ScrollGadget with 

arrow symbols. The value defines the height of the arrow and ScrollGadget for a  horizontal gadget and the width of the arrow and Scroll Gadget for a  vertical gadget.

PGA_Freedom is used to define a  vertical ScrollGadget 

(LORIENTJVERT). The default is a  horizontal 

ScrollGadget (LORffiNTHORIZ). 

GA_Immediate (BOOL) causes every 

IDCMP_GADGETDOWN event to be passed (TRUE). 

GA_RelVerify (BOOL) same for IDCMP_GADGETUP 

events.

GTSL_Min (WORD) sets the minimum value for a 

SliderGadget (default: 0). 

GTSL_Max (WORD) is the same for the maximum value 

(default: 15). 

GTSL_Level (WORD) sets a  SliderGadget to a  specified 

location (default 0).

GTSL_MaxLevelLen (UWORD) sets the maximum length 

of the string containing the location for the SliderGadget.

GTSL_LevelFormat (STRPTR) determines a  format string 

for the 32 bit value indicating the location for the
SliderGadget. The format string is formatted with the Exec 

routine RawDoFmt().

GTSL_LevelPlace determines where the position value will 

be output (PLACETEXT_LEFT (default),
PLACETEXT_RIGHT, PLACETEXT_ABOVE, or 

PLACETEXT.BELOW). 

GTSL_DispFunc (FPTR) associates a  function with a 

SliderGadget. The function is passed the gadget address 

and position value on the stack. The slider position is calculated from this information and passed back as a longword in DO.

GTSTJString (STRPTR) sets the string used to initialize the 

contents of a  StringGadget (default: empty =  0).

GTST_MaxChars (UWORD) sets the maximum number of 

characters in a  StringGadget buffer.

GTTXJText (STRPTR) sets the contents of a  TextGadget 

(default: empty=0). 

GTTX_CopyText (BOOL) causes the TextGadget to make 

a copy of GTTXJText (TRUE).

GTTX_Border (BOOL) makes a  border for the TextGadget 

(TRUE). 

Result: Address of a  new gadget or 0. 

| CreateMenus A Create a  GadTools menu | 

Call: menu =  CreateMenusA(newmenu, taglist) 

DO -48 (A6) AO Al 

STRUCT Menu *menu 

STRUCT NewMenu *newmenu 

STRUCT Tagltem *taglist 

Function: Creates a  complete MenuStrip according to the information 

in the NewMenu structure and the tags.

Parameters: newmenu List with initialized NewMenu structure. 

taglist Tagltem field

Tags: GTMN_FrontPen (UBYTE) text color (or else 0). 

GTMN_FullMenu (BOOL (Version 37 and up)) indicates 

that the menu description of the NewMenu structure pertains to a  complete MenuStrip (TRUE).

GTMN_SecondaryError (ULONG *  (Version 37 and up)) 

passes the address of a  long initialized to 0, to which an error code can be written:

GTMENUJNVALID 

Invalid NewMenu structure (result 0). 

GTMENU_TRIMMED 

Too many items (some are trimmed). 

GTMENU.NOMEM 

Not enough memory. 

Result: MenuStrip address, might not be complete 

(GTMENUJTRIMMED) or 0. MenuStrips are created 

without locations. Therefore, LayoutMenusA() or
LayoutMenuItemsA() must be called before they are 

added.

| DrawBevelBox A Draw a  box | 

Coll: DrawBevelBoxA(rport, left, top, width, height, taglist) 

-120 (A6) A0 DO Dl D2 D3 A3 

STRUCT RastPort *rport 

WORD left, top, width, height 

STRUCT Tagltem *taglist 

Function: Draws a  box in a  RastPort. 

Parameters: rport 

RastPort 

left

Left edge of box 

top

Top edge of box 

width

Width of box 

height

Height of box 

taglist

Tagltem field 

Tags: GTBB_Recessed (BOOL) is used to draw a  new box 

otherwise the box is removed.

GT_VisualInfo (APTR) must be given with the result of a 

GetVisuallnfoAO call. 

IFreeGadgets Free gadgets | 

Call: FreeGadgets(glist) 

-36 (A6) A0 

STRUCT Gadget *glist 

Function: Frees all memory for a  gadget list whose components were 

allocated with CreateGadgetA().

Parameters: glist One or more linked gadget structures. 

I FreeMenus Free menus I 

Call: FreeMenus (menu) 

-54 (A6) A0 

STRUCT Menu *menu 

Function: Free all memory for menus created with CreateMenusA(). 

Parameters: menu Menu or Menultem from CreateMenusA(). 

IFreeVisuallnfo Free Visuallnfol 

Call: FreeVisuallnf o  ( vi ) 

-132 (A6) AO 

APTR vi 

Function: Frees memory and resources allocated with 

GetVisualInfoA(). This function may only be called after 

gadgets are used, for example, after a  window is closed. It must be called before closing or unlocking a  screen.

Parameters: vi Result from GetVisualInfoA() 

| Get Visuallnfo A Get information on the screen display | 

Call: vi =  GetVisuallnfoA( screen, taglist) 

DO -126 (A6) AO Al 

APTR vi 

STRUCT Screen * screen 

STRUCT Tagltera *taglist 

Function: Gets the information that the GadTools library needs to 

create the best possible gadgets or menus. After a  window is closed for the last time, the result must be freed with
FreeVisuallnf o(). 

Parameters: screen Screen where the window is to be opened. 

taglist Tagltems field

Result: Address of a  private data field. 

|GT BeginRefresh BeginRefresh for GadTools windows] 

Call: GT_BeginRefresh(win) 

-90 (A6) AO 

STRUCT Window *win 

Function: Executes the BeginRefresh() (known from Intuition) for 

windows with GadTools structures (GadTools works with
NOCAREREFRESH windows). 

Parameters: win Window that receives an 

IDCMP_REFRESHWINDOW message. 

|GT EndRefresh End refresh] 

Call: GT_EndRefresh(win, complete) 

-96 (A6) AO DO 

STRUCT Window *win 

BOOL complete 

Function: Ends a  window refresh that was started with 

GT_BeginRefresh(). 

Parameters: win Window structure 

complete Flag: TRUE=refresh completed

|GT FilterlMsg Pass Intuition message to GadTools | 

Call: modimsg =  GT_FilterlMsg(imsg) 

DO -102 (A6) Al 

STRUCT IntuiMessage *modimsg, *imsg 

Function: Passes an Intuition message to the GadTools library to 

assure proper control of GadTools gadgets.

Parameters: imsg Normal IntuiMessage from a  window UserPort. 

Result: 0  if GadTools was not interested in the message otherwise 

an IntuiMessage modified with information from GadTools.

|GT GetlMsg Get and process an IntuiMessage| 

Call: imsg =  GT_GetIMsg(intuiport) 

DO -72 (A6) AO 

STRUCT IntuiMessage *imsg 

STRUCT MsgPort *intuiport 

Functions, Results: 

Similar to GT_FilterIMsg(), except that the message is first 

retrieved from the given port with GetMsg().

Parameters: intuiport UserPort for a  window. 

|GT PostFilterlMsg Restore an IntuiMessage | 

Call: imsg =  GT_PostFilterIMsg(modimsg) 

DO -108 (A6) Al 

STRUCT IntuiMessage *imsg, *modimsg 

Function: Messages modified by GadTools must not be answered 

with ReplyMsg(). This function returns the original message and frees the memory used by the modified message.

Parameters: modimsg A  GadTools message from GT_GetIMsg() or 

GT_FilterIMsg(). 

Result: The original IntuiMessage. 

|GT Refresh Window Refresh all GadTools gadgets | 

Call: GT_RefreshWindow(win, req) 

-84 (A6) AO Al 

STRUCT Window *win 

STRUCT Requester *req 

Function: Calling intuition/RefreshGList() after intuition/AddGList() 

is not enough to properly display GadTools gadgets. This function must also be called. Afterwards, it is no longer needed.

Parameters: win Window with GadTools gadgets. 

req Requester address (not yet supported: 0)

|GT ReplylMsg Reply to a  GadTools message | 

Call: GT_Reply iMsg ( imsg ) 

-78 (A6) Al 

STRUCT IntuiMessage *imsg 

Function: Replies to a  message obtained with GT_GetIMsg(). 

Parameters: imsg A  modified IntuiMessage from GT_GetIMsg(). 

|GT SetGadgetAttrsA Change attributes of a  GadTools gadget! 

Call: GT_SetGadgetAttrsA(gad, win, req, taglist) 

-42 (A6) AO Al A2 A3 

STRUCT Gadget *gad 

STRUCT Window *win 

STRUCT Requester *req 

STRUCT Tagltem *taglist 

Function: Changes the attributes of a  GadTools gadget according to 

the information in a  Tagltem field.

Parameters: gad GadTools gadget 

win Window containing the gadget. req Requester for the gadget (not yet supported:

0). 

taglist Tagltem field

Tags: BUTTON-Gadget: GA_Disabled. 

CHECKBOX-Gadget: GTCB_Checked, GA_Disabled. 

CYCLE-Gadget: GTCY_Active, GTCY.Labels, 

GA_Disabled. 

INTEGER-Gadget: GTIN_Number, GA_Disabled. 

LISTVIEW-Gadget: GTLV_Top, GTLVLabels, 

GTLV_Selected. 

MX-Gadget: GTMX_Active. 

NUMBER-Gadget: GTNM_Number. 

PALETTE-Gadget: GTPA_Color, GA_Disabled. 

SCROLLER-Gadget: GTSCTop, GTSC_Total, 

GTSC_Visible, GA_Disabled. 

SLroER-Gadget: GTSL_Min, GTSL_Max, 

GTSLLevel, GA_Disabled. 

STRING-Gadget: GTSTJString, GA_Disabled. 

TEXT-Gadget: GTTX_Text. 

| LayoutMenuItemsA Enter positions for Mcnultems | 

Call: success =  LayoutMenuItemsA (menuitem, vi, taglist) 

DO -60 (A6) A0 Al A2 

BOOL success 

STRUCT Menuitem *menuitem 

APTR vi 

STRUCT Tagltem *taglist 

Function: Enters the positions of Menultems and Subltems. 

Parameters: menuitem First Menuitem 

vi Result of GetVisualInfoA(). taglist Description of the items.

Tags: GTMN_TextAttr (STRUCT TextAttr *) defines the font for 

Menultems and Subltems. The font must be accessible with 

graphics/OpenFontO .

GTMN_Menu (STRUCT Menu *) gives GadTools the 

address of the Menu structure of the given items (needed for calculations).

Result: 

Error 

ILayoutMenusA 

Enter position in MenuStrip| 

Call: success =  LayoutMenusA(menu, vi, taglist) 

DO -66 (A6) AO Al A2 

BOOL success 

STRUCT Menu *menu 

APTR vi 

STRUCT Tagltem *taglist 

Function: Enters positions for an entire MenuStrip. 

Parameters: menu MenuStrip address from CreateMenusA(). 

vi Result from GetVisualInfoA(). taglist Tagltem field

Tags: GTMN_TextAttr (STRUCT TextAttr *) see 

LayoutMenuItemsA(). 

Result: 

Error 

GENERIC_KIND 

= 

standard gadget

BUTTON_KIND 

= 

CHECKBOX_KIND 

= 

INTEGER_KIND 

= 

LISTVIEW_KIND 

= 

MX_KIND 

= 

NUMBER_KIND 

= 

CYCLE_KIND 

= 

PALETTE_KIND 

= 

SCROLLER_KIND 

= 

SLIDER_KIND 

= 

STRING_KIND 

= 

TEXT_KIND 

= 

NUM_KINDS 

= 

/number of new gadg 

GADTOOLBIT 

= 

$8000 GadTools gadget 

GADTOOLMASK 

= 

$7FFF user bits 

Required 1DCMP Flags: 

ARROWIDCMP 

BUTTONIDCMP 

CHECKBOXIDCMP 

INTEGERIDCMP 

LISTVIEWIDCMP 

MXIDCMP 

NUMBERIDCMP 

CYCLEIDCMP 

PALETTEIDCMP 

SCROLLERIDCMP 

SLIDERIDCMP 

STRINGIDCMP 

TEXTIDCMP 

GADGETUP ! GADGETDOWN ! INTUITICKS ! MOUSEBUTTONS 

GADGETUP 

GADGETUP 

GADGETUP 

GADGETUP !  GADGETDOWN ! MOUSEMOVE !  ARROWIDCMP 

GADGETDOWN 

GADGETUP 

GADGETUP 

GADGETUP ! GADGETDOWN ! MOUSEMOVE  wi t hout arrows ! 

GADGETUP ! GADGETDOWN ! MOUSEMOVE 

GADGETUP 

Spacing: 

INTERWIDTH 

= 8 

INTERHEIGHT 

= 4 

Dec Hex 

STRUCTURE NewGadget.O 

0 $0 

WORD 

gng_Lef tEdge gadget position

2 $2 

WORD 

gng_TopEdge

4 $4 

WORD 

gng_Width

,- gadget size 

6 $6 

WORD 

gng_Height

8 $8 

APTR 

gng_GadgetText text

12 $C 

APTR 

gng_TextAttr font for the text

16 $10 

UWORD 

gng_GadgetID

ID 

18 $12 

ULONG 

gng_Flags

 Flags 

22 $16 

APTR 

gng_VisualInfo see GetVisualInfo( )

26 $1A APTR 

gng_UserData

,-user data 

30 $1E 

LABEL 

gng_SIZEOF

PLACETEXT_LEFT =  $0001 next to slider, left 

PLACETEXTJRIGHT =  $0002  right next to slider, right 

PLACETEXT_ABOVE =  $0004  above slider 

PLACETEXT_BELOW =  $0008 ,-below slider 

PLACETEXT_IN =  $0010  in the gadget 

NG_HIGHLABEL =  $0020  highlight 

Dec Hex STRUCTURE NewMenu , 0 

0 $0 UBYTE gnm_Type 

1 $1 UBYTE gnm_Pad 

2 $2 APTR gnm_Label 

6 $6 APTR gnm_CommKey 

10 $A UWORD gnm_Flags 

type text character structure

12 $C LONG gnm_Mutual Exclude  exclude 

16 $10 APTR gnm_UserData 

20 $14 LABEL gnm_SIZEOF 

user data

UserData always comes after the normal structure, for example, as with 

mu_SIZEOF(Menu).

NMJTITLE =  1 Menu 

NM_ITEM =  2 MenuItem 

MM_SUB =  3 SubItem 

NM_END =  0 end of field 

MENU IMAGE =  128 

 Image flag 

IM_ITEM =  NM_ITEM!MENU_IMAGE  item with image 

IM_SUB =  NM_SUB!MENU_IMAGE SubItem with image 

NM_BARLABEL 

-1  dividing line 

NM_MENUDISABLED =  MENUENABLED 

NM_ITEMDISABLED =  ITEMENABLED 

NM_FLAGMASK =  - (COMMSEQ! ITEMTEXTIHIGHFLAGS) 

GT_TagBase 

GTVI_NewWindow 

GTVI_NWTags 

GT_PrivateO 

GTCB_Checked 

GTLV_Top 

GTLV_Labels 

GTLV_ReadOnly 

GTLV_Scrol lWidth 

GTMX_Labels 

GTMX_Active 

GTTX_Text 

GTTX_CopyText 

GTNM^Number 

GTCY_Labels 

GTCY_Active 

GTPA_Depth 

GTPA_Color 

GTPAColorOffset 

= TAG_USER+$80000 

= GT_TagBase+$01 

= GT_TagBase+$02 

= GT_TagBase+$03 

= GT_TagBase+$04 

= GT_TagBase+$05 

= GT_TagBase+$06 

= GT_TagBase+$07 

GT_TagBase+$08 

= GT_TagBase+$09 

= GT_TagBase+$0A 

= GT_TagBase+$0B 

= GT_TagBase+$0C 

= GT_TagBase+$0D 

= GT_TagBase+$0E 

= GT_TagBase+$0F 

= GT_TagBase+$10 • 

= GT_TagBase+$ll 

GT_TagBase+$12 

GTPA_IndicatorWidth =GT_TagBase+$13 

GTPA_IndicatorHeight=GT_TagBase+$14 

GTSC_Top =  GT_TagBase+$15 

GTSC_Total =  GT_TagBase+$16 

GTSC_Visible =  GT_TagBase+$17 

GTSC_Overlap =  GT_TagBase+$18 

first Tag

NewWindow for Visual Info 

NewWindow Tags 

private checkbox status top of ListView

ListView contents 

ListView type 

ListView scroller width 

MX contents 

MX prefix 

text copy text number value cycle contents cycle prefix palette bit planes palette prefix palette start palette indicator width palette indicator height top of scroller total contents of scroller scroller contents not used

GTSL_Min 

GTSL^Max 

GTSL_Level = 

GTSL_MaxLevelLen= 

GTSL_LevelFormat= 

GTSL_LevelPlace = 

GTSL_DispFunc = 

GTST_String = 

GTST_MaxChars = 

GTIN_Number = 

GTIN_MaxChars = 

GTMN_TextAttr = 

GTMN_FrontPen = 

GTBB_Recessed = 

GT_VisualInfo = 

GTLV_ShowSelected 

GTLV_Selected = 

GT_ReservedO = 

GT_Reservedl = 

GTTX_Border = 

GTNM_Border = 

GTSC_Arrows = 

GTMN_Menu = 

GTMX_Spacing = 

GT_TagBase+ $2 6 

GT_TagBase+$27 

GT_TagBase+$28 

GT_TagBase+$29 

GT_TagBase+ $2A 

GT_TagBase+$2B 

GT_TagBase+$2C 

GT_TagBase+ $2D 

GT_TagBase+$2E 

GT_TagBase+$2F 

GT_TagBase+$3 0 

GT_TagBase+$31 

GT_TagBase+$32 

GT_TagBase+$33 

GT_TagBase+ $3 4 

=GT_TagBase+$35 

GT_TagBase+$36 

GT_TagBase+$37 

GT_TagBase+$38 

GT_TagBase+$39 

GT_TagBase+$3A 

GT_TagBase+$3B 

GT_TagBase+$3C 

GT_TagBase+$3D 

Example 

slider minimum slider maximum slider position slider text length slider format string slider text position slider function string contents string text length integer value integer text length
Menultem font 

Menultem text color 

BevelBox recessed 

Visuallnfo 

ListView display 

ListView prefix 

reserved reserved text border number border scroller arrows menu address
MX spacing 

Create gadgets. In some cases, using GadTools can be more difficult than 

creating the gadgets yourself. But your efforts will be rewarded with gadgets that have the new, professional-looking standard appearance. Also, you won't have to program the query routines for the new gadget types yourself. bsr

_CreateGadgets 

beq

_NoGadgets 

movea . 1

_Window,aO 

movea . 1

_GadgetListe(pc) ,al 

moveq

#-l,dO 

moveq

#-l,dl 

lea

$0.w,a2 

movea . 1

_IntuiBase,a6 

jsr

_LVOAddGList(a6) 

movea. 1 _GadgetListe(pc) ,a0 movea . 1 _Window, al moveq #-l,dO jsr _LVORefreshGList (a6) movea . 1 _Window , aO movea.l a2,al movea. 1 _GadToolsBase, a6 jsr _LVOGT_RefreshWindow(a6)

_CreateGadgets 

movea.l _GadToolsBase, a6 movea.l _MyScreen,aO lea _DummyTags , al jsr _LVOGetVisualInfoA(a6) move . 1 dO,_VisualInfo beq _Zerrorl lea _Gadgetliste(pc) ,a0 jsr _LVOCreateContext (a6) tst.l dO beq _Zerror2 movea

1 dO,aO 

moveq

#CYCLE_KIND,dO 

lea

_NewGadget (pc) , al 

lea

_TagList (pc) ,a2 

jsr

_LVOCreateGadgetA ( a6 ) 

tst.l dO beq

_Zerror3 

rts

_Zerror3 

movea.l _GadgetListe (pc) , aO jsr _LVOFreeGadgets(a6)

_Zerror2 

movea.l _VisualInf o, aO jsr _FreeVisualInfo(a6)

_Zerrorl 

moveq #0,d0 rts

_DummyTags 

del TAG_DONE

_Gadgetliste 

del 0

_NewGadget 

dew 10,10,80,12 del 0,_Topaz8 dew 1 del 0
_VisualInfo 

de 1   0,0

_Topaz8 

dc . 1 _TopazName dew 8 dc . b 0,0

_TagList 

del GTCY_Labels,_Strings del TAG_DONE

_Strings 

del _TextO,_Textl,_Text2,_Text3, 0

_TopazName 

deb •  topaz .  font ', 0

_Text0 

deb 'DFO: '  ,0

_Textl 

deb 'DF1: '  ,0

_Text2 

de b    ' DF2 :  ' ,  0

_Text3 

deb 'DF3: '  ,0
