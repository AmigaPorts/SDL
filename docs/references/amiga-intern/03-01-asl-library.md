# The ASL Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

The basic concept of the operating system has been changed considerably from the old 1.x versions. In just about every area, the programmer is given opportunities to query, influence, or completely determine system processes. The operating system has become much more open, and offers good potential for multi-user systems. Many system routines were re-programmed with new capabilities. In order to maintain compatibility with old software, many of the calling conventions from the 1.x versions were implemented, and sometimes the function results were partially modified. New libraries, resources, and devices were added. The familiar system modules were expanded to the point that they can hardly be recognized anymore. All in all, AmigaOS
2.x is a  completely new operating system that is compatible with the old 

versions.

Normal versions of AmigaOS 2.x can only work on a  machine that has 

the same hardware configuration as the Amiga 3000 (68030, FPU,
Commodore clock chip, HR chip set, etc.). This is because the reset 

routine starts out with 68030 commands without even querying the CPU type. Some test versions can also be installed on the 16 bit machines, but there is a  lot less room in the 512K ROM, so many features are only partially functional or are missing altogether.

## 3.1 The Libraries and their Functions

A lot of information is required to produce a  good program. All the data on AmigaOS 2.x would fill thousands of pages and extend far beyond what we could hope to effectively cover in this book. Therefore, we had to limit ourselves to a  selected portion. We chose to focus on the library functions in this book. Library routines provide the building blocks and hand tools for creating more complex application programs, such as a word processor. Because there are so many functions to cover, we also chose to do without an introductory overview for beginners. For example, there are many other good books with this kind of information, such as "The Amiga System Programmers Guide". A brief glance at the system routines will reveal the existence of two new structures =  Tagltem fields and Hooks. Tagltem fields are variable in size and structure. They are primarily used to pass parameters. A  Tag field can belong to several memory blocks. It consists of several Tagltems. A
Tagltem consists of two 32 bit values (Longs). The first value is a  code 

for interpreting the meaning of the second value, which is the data Long.
Depending on the code, the data can be an address, a  BCPL pointer, 

Words, Bytes, Flags, or combinations thereof. Tagltems are most often 

used to change system routine default settings. This could be for a  small change, such as setting the ECS presentation mode for a  new screen, or for changes to the basic system configuration that require large numbers of parameters. Tagltem fields are required in order to use certain OS-2.04 features.

Another important new structure is the Hook. Hooks give the 

programmer deep access into the system. In general, Hooks are structures with addresses to routines of their own. These private routines are associated with certain events or results. When a  certain event or result is encountered, the system jumps to the corresponding routine. Hooks can be used to expand upon or entirely replace system functions. And now, the description of each library in alphabetical order.

### 3.1.1 The ASL Library

The ASL library provides the easiest way for a  programmer to create file requester boxes. Special functions can be applied to customize each requester box. This library is found under the name "asl.library". All functions of this library, expect the base address _AslBase, is a  parameter in the A6 register.

Functions of the ASL Library 

1. Standard File Requester Box 2. Complex File Requester Boxes 

AllocFileRequest AllocAslRequest

FreeFileRequest FreeAslRequest 

RequestFile AslRequest 

Description of Functions 

1. Standard File Requester Box 

[AllocFileRequest Get FileRequester structure | 

Call: request =  AllocFileRequest ( ) 

DO -30 (a6) 

STRUCT FileRequester *request 

Function: Obtains and initializes all data structures required for a 

RequestFile() function call. 

Arguments: None. The initialization is automatically executed for the 

standard file requester. If you want to use special functions, you must obtain the data structures with AllocAslRequest().

Result: Address of a  FileRequester structure which is passed to the 

RequestFile() function. You can read any data from the 

normally accessible parts of the FileRequester structure. In the case of a  system error, such as no memory, the value 0  is returned.

Warning: FileRequester structures passed to RequestFile() or 

AslRequest must be obtained either with 

AllocFileRequest() or AllocAslRequest(). Reserving memory yourself or directly manipulating the entries in the structure will crash the system.

See also: RequestFile(), FreeFileRequest(), FreeAslRequest(), 

AslRequest() 

[FreeFileRequest Free file requesterl 

Call: FreeFileRequest (   request ) 

-36 (a6) A0 

STRUCT FileRequester *request 

Function: This function is identical to Free AslRequest(). It's used to 

free a  data structure allocated with AllocFileRequest.

Arguments: request Address of a  FileRequester structure that was 

obtained with AllocFileRequest().

Result: None. 

See also: FreeAslRequest() 

[RequestFile Display file requester and evaluate user input | 

Call: result =  RequestFile (   request ) 

DO -42 (a6) AO 

BOOL result  

STRUCT FileRequester *request 

Function: A  file requester box is displayed, the user's input is 

processed, and the requested file is returned.

Arguments: request FileRequester structure with address obtained 

via AllocFileRequest().

Result: result 0  means Cancel was selected or a  system error 

occurred. The exact input data can be read from the FileRequester structure.

See also: AllocFileRequest(), FreeFileRequest(), AslRequest() 

2. Complex Requester Boxes 

[Alloc Asl Request Obtain structures for a  requester box| 

Call: request =  AllocAslRequest (   type, ptags ) 

DO -48 (a6) DO AO 

APTR request 

ulong type

STRUCT Tagltem *ptags 

Function: Obtains and initializes the data structures for a  requester 

box.

Arguments: type Type of requester box, ASL_FileRequest for a 

file requester or ASL"FontRequest for a  font requester. The type of requester box is determined by AllocAslRequest function on the basis of the following values:

ASL_FileRequest =  0 

ASL_FontRequest =  1 

ptags Address of a  Tagltem field used to pass special functions and parameters.

Result: Address of an initialized data structure (FileRequester or 

FontRequester). A  value of 0  is returned in case of an error. 

The address of the data structure is passed to the function
AslRequest() and freed with FreeAslRequest(). 

See also: AslRequest(), FreeAslRequest() 

|FreeAslRequest Free requester box data structures! 

Call: FreeAslRequest (   request ) 

-54 (a6) AO 

APTR request 

Function: Frees the memory occupied by a  FileRequester or 

FontRequester structure. The address must have been 

previously obtained with AllocAslRequest() or AllocFileRequest().

Arguments: request Address of a  data structure obtained via 

AllocAslRequestO or AllocFileRequest().

Result: None. 

See also: AllocAslRequestO, AslRequestQ, AllocFileRequest() 

[AslRequest 

Display and query requester box| 

Call: result =  AslRequest (   request, ptags ) 

DO -60 (a6) AO Al 

BOOL result 

APTR request 

STRUCT Tagltem *ptags 

Function: Displays a  requester box and evaluates the input of the 

user. The type of box, special functions, and results are dependent upon the data structure and definitions passed to the Tagltem field.

Tag Items 

ASLJHail (STRPTR) 

Title text of the requester. 

ASL Window (struct Window * 

Window in which the requester will appear. 

ASL LeftEdge (WORD) 

Left edge of the query window. 

ASL TopEdge (WORD) 

Top edge of the query window. 

ASL Width (WORD) 

Width of the query window. 

ASL Height (WORD) 

Height of the query window. 

ASL HookFunc (APTR) 

Address of an implemented function. 

ASL File (STRPTR) 

Default filename of a  FileRequester. 

ASL Dir (STRPTR) 

Default path of a  FileRequester. 

ASL FontName (STRPTR) 

Default font name of a  FontRequester. 

ASL FontHeight (UWORD) 

Default font height. 

ASL FontStyles (UBYTE) 

Default font style. 

ASL FontFlags (UBYTE) 

Special flags for a  FontRequester. 

ASL FrontPen (BYTE) 

Foreground color of a  FontRequester.

ASL BackPen (BYTE) 

Background color of a  FontRequester. 

ASL MinHeight (UWORD) 

Minimum height of font. 

ASL MaxHeight (UWORD) 

Maximum height of font. 

ASL OKText (STRPTR) 

New text for the OK button (up to 6  char.). 

ASL CancelText (STRPTR) 

Same for the CANCEL button. 

ASL FuncFlags (ULONG) 

Function Flags for the requester. 

ASL ExtFlagsl (ULONG) 

Additional Flags. 

Arguments: request 

ptags

Data structure obtained with AllocAslRequest() 

or AllocFileRequest().

Address of a  Tagltem field containing changes 

to the default values.

Warning: The only valid way to change the data structure entries is 

with Tagltems.

Result: A  result of 0  indicates CANCEL was pressed or a  system 

error occurred. The exact user input can be taken from the readable parts of the data structure.

See also: Alloc AslRequest(), FreeAslRequest() 

Data Structures And Values: 

Dec Hex 

STRUCTURE FileRequestr, 0 

0 $00 

CPTR 

rf_Reservedl

4 $04 

CPTR 

rf_File

 *filename (PCHARS+1) 

8 $08 

CPTR 

rf_Dir

 *directory (DSIZE+1) 

12 $0C 

CPTR 

r f  _Re s  e r  ved2

16 $10 

UBYTE 

rf_Reserved3

17 $11 

UBYTE 

rf_Reserved4

18 $12 

APTR 

rf_Reserved5

22 $16 

WORD 

rf_LeftEdge

24 $18 

WORD 

rf_TopEdge

26 $1A 

WORD 

rf_Width

28 $1C 

WORD 

rf_Height

30 $1E 

WORD 

rf_Reserved6

32 $20 

LONG 

rf_NumArgs

36 $24 

APTR 

rf_ArgList

40 $28 

APTR 

rf_UserData

44 $2C 

APTR 

rf_Reserved7

48 $30 

APTR 

rf_Reserved8

52 $34 

CPTR 

rf_Pad

Interactive functions associated with a  requester must look like this: 

rf_Function( Mask, Object , AslRequester)

4(A7) 8(A7) 12 (A7) 

ULONG Mask 

CPTR *Object 

CPTR *Request 

The value of Mask is determined by passing a  copy of
ASL_FunctionFlags, which is generated for every requester. Object 

contains the address of data. The following bits (or Flags) are defined for a FileRequester:

RFB_DOWILDFUNC =   7 call with AnchorPath and a  name, 

RFF_DOWILDFUNC =  $80  (FileRequester) 

RFB_DOMSGFUNC =   6  transmit all IDCMP events 

RFF_DOMSGFUNC =  $40 

RFB_DOCOLOR =  5 

RFF_DOCOLOR =  $20 

RFB_NEWIDCMP =  4 

RFF_NEWIDCMP =  $10 

RFB_MULTISELECT =  3 

RFF_MULTISELECT =  $8 

RFB_PATGAD =  0 

RFF_PATGAD =   $1 

that are not for the FileRequester bit for SAVE operations use own IDCMP port

,-notify of multiple selection 

query a  Pattern gadget

Dec Hex 

STRUCTURE FontRequester , 0 

0 $00 CPTR fo_Reservedl 

4 $04 CPTR fo_Reserved2 

8 $08 APTR fo_Name 

12 $0C USHORT fo_YSize 

14 $0E UBYTE fo_Style 

15 $0F UBYTE fo_Flags 

16 $10 UBYTE fo_FrontPen 

17 $11 UBYTE fo_BackPen 

18 $12 UBYTE fo_DrawMode 

19 $13 UBYTE fo_Reserved3 

20 $14 APTR fo_UserData 

24 $18 SHORT fo_LeftEdge 

26 $1A SHORT fo_TopEdge 

28 $1C SHORT fo_Width 

30 $1E SHORT fo_Height 

result string

FONB_FrontColor 

= 

FONF_FrontCo lor 

= 

$1 

FONB_BackColor 

= 

FONF_BackColor 

= 

$2 

FONB_Styles 

= 

FONF_Styles 

= 

$4 

FONB_DrawMode 

= 

FONF_DrawMode 

= 

$8 

FONB_FixedWidth 

= 

FONF_FixedWidth 

= 

$10 

FONB_NewIDCMP 

= 

FONF_NewIDCMP 

= 

$20 

FONB_DoMs gFunc 

= 

FONF_DoMsgFunc 

= 

$40 

FONB_DoWildFunc 

= 

F0NF_DoWi ldFunc 

= 

$80 

ASL_FuncFlags for FontRequester: 

query foreground color query background color query font style query draw mode allow only fixed width fonts use own IDCM port capture only events for the requester call with every TextAttr structure

Values for the Tagltem field used with AslRequest(): 

ASL_Duirany 

= 

TAG_USER+$80000 

ASL_Hail 

= 

ASL_Dummy+l 

ASL_Window 

= 

ASL_Dumnty+ 2 

ASL_LeftEdge 

= 

ASL_Dummy+3 

ASL_TopEdge 

= 

ASL_Dummy+4 

ASL_Width 

= 

ASL_Dummy+5 

ASL_Height 

= 

ASL_Dumrny+6 

ASL_HookFunc 

= 

ASL_Dummy+7 

ASL_File 

= 

ASL_Dummy+8 

ASL_Dir 

= 

ASL_Dummy+9 

ASL_Pattem 

= 

ASL_Dummy+10 FileRequester 

only

ASL_FontName 

= 

ASL_Dummy+ 1 0  FontRequester 

only

ASL_FontHeight 

= 

ASL_Dummy + 1 1 

ASL_FontStyles 

= 

ASL_Dummy + 1 2 

ASL_FontFlags 

= 

ASL_Dummy + 1 3 

ASL_FontPen 

= 

ASL_Dummy + 1 4 

ASL_BackPen 

= 

ASL_Dummy + 1 5 

ASL_MinHeight 

= 

ASL_Dummy + 1 6 

ASLJMaxHeight 

= 

ASL_Dummy+ 17 

ASL_OKText 

= 

ASL_Dummy+18 

ASL_CancelText 

= 

ASL_Dummy+19 

ASL_FuncFlags 

= 

ASL_Dummy+20 

ASL_ModeList 

= 

ASL_Dummy+21 

Example 

Let's take a  look at the creation of a  simple FileRequester and how to 

query its result. It's rather curious that a  simple routine like this does not already exist as a  function:

** 

File selection 

** 

Input : 

A6=_AslBase 

** 

A0=Buffer (FCHARS+DSIZE+1) 

** 

Output : 

D0=Buffer r  NULL 

** 

A6=_AslBase 

** 

A0=Buffer 

** 

** 

** 

_File selection 

clr.b (aO) movem.l d0/a0,-(a7) jsr _LVOAllocFileRequest(a6) move.l dO, (a7)

0 bytes in buffer 

result+buf f er get FileRequestr save result beq. s

. Error 

on error -> movea . 1 dO,aO move FileRequestr to aO jsr

_LV0RequestFile(a6) 

display movem . 1

(a7),a0-al 

,-FileRequestr+buf fer 

move . 1 aO.dl save FileRequestr move . 1 dO, (a7) test Okay/Cancel beq.s

.Cancel 

,-on error -> 

move . 1 al, (a7) result=buf fer movea . 1 rf_Dir (aO) ,a0 directory string

CopyDir 

move . b

(a0)+, (al) + 

copy bne.s

.CopyDir 

subq . 1

#l,al 

return empty byte cmpi .b

#' : • ,-l(al) 

check ending beq.s

.Okay 

if drive -> cmpi .b

#'/',-l(al) 

,- check ending 

beq . s

.Okay 

if dir -> move . b

#V, (al) + 

insert separator byte

Okay 

movea . 1 dl,aO

,- FileRequestr 

movea . 1 rf_File(aO) , aO filename

CopyFili 

move . b

(a0)+, (al)+ 

append bne.s

.CopyFile 

Cancel 

movea . 1 dl,aO jsr

_LV0FreeFile 

(Request (a6) 

free FileRequestr

Error 

movem . 1

(a7)+,d0/a0 

clear stack tst .1 dO set CCR rts This routine can be easily modified to create requesters to serve your own needs.

* * 

** _. 

File selection with a  modified requester 

* * 

* * 

Input : 

A6=_AslBase 

* * 

* * 

Al=Buf fer (FCHARS+DSIZE+1) 

* * 

* • 

AO=TagItems 

* * 

* * 

Output : 

D0=Buffer or NULL 

* * 

** 

A6=_AslBase 

* * 

* * 

A0=Buf fer 

* * 

* * 

....___. „ _  _ 

.File selection 

clr.b

(al) 

 0 bytes in buffer 

movent . 1 d0/al,-(a7) result+buf f er moveq

#ASL_FileRequest 

dO

Tags in aO 

jsr

_LVOAllocAslRequest (a6) 

get FileRequestr move . 1 dO, (a7) save result beq. s

.Error 

on error -> movea . 1 dO,aO move FileRequestr to aO jsr

_LV0RequestFile(a6) 

,- display 

movem . 1

(a7) ,aO-al 

FileRequestr+buf fer 

move . 1 aO,dl save FileRequestr move . 1 dO, (a7) test Okay /Cancel beq.s

.Cancel 

on error -> move . 1 al, (a7) result=buf fer movea . 1 rf_Dir (aO) ,a0 directory string

CopyDir 

move . b

(a0)+, (al)+ 

copy bne . s

.CopyDir 

subq . 1

return empty byte cmpi .b

#' :  ' , -l(al) 

check ending beq.s

.Okay 

if drive -> cmpi .b

check ending beq. s

.Okay 

if dir -> move . b

#'/', (al) + 

else insert separator b

Okay 

movea . 1 dl,aO

,- FileRequestr 

movea . 1 rf_File(aO) ,a0 filename

.CopyFil 

move . b

(a0)+, (al)+ 

append bne.s

.CopyFile 

.Cancel 

movea . 1 dl,aO jsr

_LVOFreeFi leRequ 

est (a6) f ree FileRequestr

.Error 

movem . 1

(a7)+,dO/aO 

clear stack tst.l dO set CCR rts The address of a  Tagltem field is expected as an additional parameter. Here is an example of how this can look:

.FileReqTags 

del ASL_Hail,_Titletext del ASL_Dir,_DirName del ASL_OKText , _Okay del ASL_CancelText,_Cancel del TAG_DONE title text for the requester. path

OK button 

CANCEL button. 

end of field

_Titletext dc.b 'Load file',0 

_Okay dc . b  ' Load ■ , 0 

_Cancel dc.b ' Return ',0 

_DirName dc.b 'Work:',0 

