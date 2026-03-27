# The Disk Controller

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

four) microseconds, WORDEQUAL is also set only during this time span. An interrupt is also generated at the same time WORDEQUAL goes to 1:

Bit 12 in the INTREQ and INTEN registers is the DSKSYN interrupt bit. 

It is set when the data from the disk matches DSKSYNC.

Setting the operating parameters 

The data cannot be written to the disk in the same format as found in memory. It must be specially coded. Normally the Amiga works with
MFM coding. However, it is also possible to use GCR coding. Two steps 

are necessary for selecting the desired coding:

1. An appropriate routine must encode the data before it is written to 

disk and decode the data as it is read from disk.

2. The disk controller must be set for the appropriate coding. This is 

done with certain bits in the ADKCON register.

ADKCON $09E (write) ADKCONR $010 (read) DISK 

Bit no. 

Name 

Function 

SET/CLR 

Set (SET/CLR=1 ) or clear bits 

14-13 

PRECOMP 

These bits contain the precompensation value:
Bit 14 Bit 13 PRECOMP time 

0 0           Zero 

0 1            140 ns 

1 0           280 ns 

1 560 ns 

MFMPREC 

0 =  GCR, 1  = MFM 

UARTBRK 

Not a  disk controller bit, see UART 

WORDSYNC 

WORDSYNC =  1 turns on synchronization of the 

disk controller according to the word in the
DSKSYNC register. 

MSBSYNC 

MSBSYNC =  1 enables GCR synchronization 

FAST 

Disk controller clock rate: 

FAST=1 : 2 microseconds/bit (MFM) 

FAST=0: 4 microseconds/bit (GCR) 

7-0 

AUDIO 

These bits do not belong to the disk controller. The disk controller data registers As usual the DMA controller transfers data in memory to and from the appropriate data registers. The disk controller has one data register for data read from the disk and one for data that is to be written to the disk.

DSKDAT$026 (write-only) 

Contains the data to be written to the disk. 

DSKDAT $008 (read-only) 

Contains the data read from the disk. This is an early-read register and 

cannot be read by the processor.

Bibliography 

Bibliography 

O'Hara, R.P. and Gomberg, D.R.: Modern Programming Using REXX, 

Prentice-Hall London, 1985 

Hawes, William S.: ARexx User's Reference Manual, Maynard MA, 1987 

The design of the REXX language, IBM Systems Journal, Volume 23,
No.4, 1984 

Motorola: Motorola MC68030 Users Manual, Prentice-Hall London, 

Commodore: AMIGA Reference Manuals (Series), Addison- Wesley, 1990 

Index 

Index 

A 

$00000004 10 

SimpleRefresh 11 

ABBREVO 524 

AbortIO 207 

ABS() 538 

Acceleration 18 

Accrued Exception Byte 690 

accubuffered truetime clock 12

ActivateCxObj 39 

ActivateGadget 398 

ActivateWindow 366 

AddAnimOb 317 

AddAppIconA 461 

AddAppMenuItemA 462 

AddAppWindowA 464 

AddBob 317 

AddBootNode 225 

AddBuffers 74 

AddClass 414 

AddClipNode() 614 

AddConfigDev 226 

AddDevice 208 

AddDosEntry 66 

AddDosNode 226 

AddFont 307 

AddFreeList 327 

AddGadget 3 98 

AddGList 399 

AddHead 182 

AddlEvents 5 1 

AddlntServer 166 

Addition (+) 489 

ADDLIB() 544 

AddLibrary 203 

AddMemList 175 

AddPart 128 

AddPort 194 

AddResource 213 

ADDRESS 480, 507 

Address bits and mask 672 

ADDRESS0 544 

AddRsrcNode() 614 

AddSegment 95 

AddSemaphore 214 

AddTail 182 

AddTask 186 

AddVSprite 3 1 8 

Alert 194 

aliasing distortion 919 All Files 16 AllocAbs 176 AllocAslRequest 28 Allocate 176 AllocateTagltems 454 AllocConfigDev 228 AllocDosObject 63 AllocEntry 177 AllocExpansionMem 228 AllocFileRequest 27 AllocIFF 332 AllocLocalltem 347 AllocMem 1 77

ALLOCMEM() 574 

AllocRaster 287 AllocRemember 414 AllocSignal 1 86 AllocTrap 187 AllocVec 178 alternate gadget 13

Amiga Operating System 5 

AmigaOS 5 

AndRectRegion 283 

AndRegionRegion 283 

Animate 3 1 8 

AreaDraw 294 

Index 

AreaEllipse 295 

AreaEnd 295 

AreaMove 296 

ARexx: 

Function calls 584 

Parameter conversion 584 

ARG 477, 496 

ARG() 545 

arp.library 11

AskFont 308 

AskSoftStyle 308 

ASL library 26 

AslRequest 30 

Aspect 20 

AssignAdd 67 

AssignLate 69 

AssignLock 69 

assignment clause 492

AssignPath 70 

ATC (Address Translation Cache) 670 

AttachCxObj 42 

AttemptLockDosList 70 

AttemptLockLayerRom 287 

AttemptSemaphore ..214 

Audio device 12 

Audio interrupts 916 

ATJL 887 

Autopoint 21 

AutoRequest 388 

AvailFonts 55 

AvailMem 178 

B 

B2C() 541 

back/front gadget 13

BADDR() 581 

barrel shifter 875 baud rate 942

BCPL-pointers 11 

BEGIN...END 477 

BeginRefresh 366 

BeginUpdate 434 

BehindLayer 434 

BFD (Blitter Finish Disable) 801 

bit-plane 786 bit-map graphic 684

BITAND() 535 

BITCHG0 535 

BITCLRO 535 

BITCOMPO 536 

BitMapScale 273 

BITORO 536 

BITSETO 536 

BITTSTO 537 

BITXORO 537 

Blanker 21 

Blitter .684,865 

Blitter control registers 877 

Blitter DMA 879 

Blitter DMA cycles 893 

BltBitMap 275 

BltBitMapRastPort 276 

BltClear 277 

BltMaskBitMapRastPort 277 

BltPattern 278 

BltTemplate 278 

boolean algebra 872 boolean equation .872

Boot Menu 6 

BREAK 501 

BrokerCommand 51 

BuildEasyRequestArgs 388 

BuildSysRequest 389 

BumpRevision 327 

burst-fill 703 bus cycles 788

BY 477 

c

C2B() 541 

C2D() 541 

C2X() 542 

Index 

Cache Address Register (CAAR) 704 

Cache Control Register (CACR) 704 

Cache inhibit (CI) 672 

Cache Row Layout 703 

cache-hit 703 cache-miss 703

CacheClearE 187 

CacheClearU 188 

CacheControl 188 

CALL 507 

Cause 168 

CBump 254 

CENTER() 524 

CENTREO 524 

ChangeMode 113 

ChangeSprite 318 

ChangeWindowBox 368 

ChecklO 208 

CheckSignal 103 

chip RAM 770

CIAs 772 

Clauses 492 

ClearCxObjError 41 

ClearDMRequest 390 

ClearEOL .. 308 

ClearMem() 615 

ClearMenuStrip 368 

ClearPointer 369 

ClearRectRegion 284 

ClearRegion 284 

ClearRexxMsg() 615 

ClearScreen 309 

CLI 22,104 

ClipBlit 279 

clockcycle-optimized programs 12

CloneTagltems 454 

Close 1 13 

CLOSE() 520 

CloseClipboard 332 

CloseDevice 208 

CloseFO 604 

CloseFont 309 

CloselFF 332 

CloseLibrary 204 

CloseMonitor 254 

CLOSEPORT0 575 

ClosePublicPortO 615 

CloseScreen 352 

CloseWindow 369 

CloseWorkBench .....352 

CMove 254 

CmpStringO 609 

ColdCapture 10 

ColdReboot 163 

CollectionChunk 342 

Color Correct 20 

color palette 808

ColorMap 11 

COMMAND 480 

Command >NEL parameter 14 

command clause 493

Command Keys 19 

Command Line Interface 6 

command lines .".22

Comments 492 

Commodities Library 36 

COMPARE0 525 

CompareDates 138 

COMPRESS0 524 

Condition Code Byte 688 

Control Register (FPCR) 685 

Control Registers 688, 825 

COPIES0 525 

Copper 797 

Copper DMA 802 

Copper interrupt 801 

Copper list 11, 797 

CopyBrokerList 51 

CopyMem 178 

CopyMemQuick 179 

CopySBitMap 279 

CreateArgStringO 615 

Index 

CreateBehindHookLayer 434 

CreateBehindLayer 435 

CreateContext 234 

CreateCxObj 37 

CreateDir 85 

CreateDOSPkt () 604 

CreateGadgetA 234 

CreatelORequest 209 

CreateMenusA 239 

CreateMsgPort 194 

CreateNewProc 96 

CreateProc 96 

CreateRexxMessage() 616 

CreateUpfrontHookLayer 436 

CreateUpfrontLayer 436 

CurrentChunk 339 

CurrentDir 86 

CurrentEnv() 616 

CuirentTime 416 

custom chips 772

CVa2i() 61 1 

CVc2x() 612 

CVi2a() 612 

CVi2arg() 612 

CVi2az() 613 

CVs2i() 613 

CVx2c() 613 

CWait 255 

Cx library 36 

CxBroker 37 

CxMsgData 47 

CxMsgID 48 

CxMsgType 47 

CxObjError 41 

CxObjType 40 

D 

D2C() 542 

D2X() 542 

data fetch start 790 data fetch stop 790

DATATYPE() 525 

DATE0 545 

DateStamp 138 

DateToStr 1 29 

DDFSTRT 816 

Deallocate 179 

Debug 195 

deciBels 906

Delay 139 

DELAY0 575 

DELETEX) 58 1 

DeleteArgstringO 617 

DeleteCxObj 39 

DeleteCxObjAll 40 

DeleteDOSPktO 605 

DeleteFile 1 14 

DeletelORequest 209 

DeleteLayer 437 

DeleteMsgPort 1 95 

DeleteRexxMsg() 617 

DeleteVar 140 

DELSTR() 526 

DELWORDO 526 

descriptors 675

DeviceProc 74 

Devices 7 

DFFSTOP 816 

DIG1TS0 538 

Disable 168 

DisownBlitter 280 

DisplayAlert 390 

DisplayBeep 410 

DisposeCxMsg 50 

DisposeFontContents 57 

DisposeLayerlnfo 437 

DisposeObject 416 

DisposeRegion 284 

Dithering 20 

DivertCxMsg 48 

Division (J) 489 

DIWSTOP 814 

Index 

DIWSTRT 814 

DMA access 781 

DMA controller 781 

DO 501 

DO ...END 477 

DoCollision 319 

DoIO 209 

DoPkt 75 

dos.library 11

DOSRead() 605 

DOSWriteO 605 

double real 686

Double-Oick 18, 416 

Draw 296 

DrawBevelBoxA 240 

DrawBorder 410 

DrawEllipse 296 

DrawGList 319 

Drawlmage 41 1 

DrawImageState 41 1 

DROP 508 

dual playfield mode 811

DupLock 64 

DupLockFromFH 64 

Dyadic Operations 693 

E 

Early Termination (ET) 680 

Easy error trapping 474 

Easy string manipulation 474 

EasyRequestArgs 391 

ECHO 496 

ECS 5 

Edit Standard Overscan 20 

Edit Text Overscan 20 

Elementary bit-map 684 

ELSE 502 

Enable 1 69 

Enable bit (E) 672 

END 503 

EndNotify 75 

EndRefresh 370 

EndRequest 393 

EndUpdate 438 

Enhanced Chip Set 5 

Enhanced Chip Set (ECS) 860 

Enqueue 183 

EnqueueCxObj 43 

EntryHandler 343 

EOF() 5 20 

Eraselmage 412 

EraseRect 297 

ErrorMsgO 613 

ErrorReport 143 

ERRORTEXTO 546 

even cycles 788

ExAll 86 

Examine 87 

ExamineFH 1 14 

Exception Byte 689 

Exception Enable 689 

Exception/Interrupt Table 10 

exec.library 10

Execute 104 

ExistF() 605 

EXISTS0 520 

Exit 97,503 

ExitHandler 344 

ExNext 88 

expansion cards 12

Expansion-library 11 

Exponentiation (**) 488 

EXPORT() 546 

Expressions 487 

extended real 686

ExtendFont 309 

external commands 493 extra half-bright mode 809

F 

fast RAM 770

FattenLayerlnfo 11 

Index 

Fault 1 30 

FGetC 1 14 

FGets 130 

File Extension 596 

FilePart 131 

FillRexxMsgO 617 

FilterTagChanges 454 

FilterTagltems 455 

FIND() 527 

FindArg 131 

FindBroker 45 

FindCliProc 105 

FindCollection 339 

FindConfigDev 228 

FindDevice() 606 

FindDisplaylnfo 255 

FindDosEntry 71 

FindLocalltem 347 

FindName 183 

FindPort 195 

FindProp 340 

FindPropContext 340 

FindResident 163 

FindRsrcNode() 617 

FindSegment 97 

FindSemaphore 214 

FindTagltem 455 

FindTask 188 

FindToolType 328 

FindVar 140 

FKey 21 

flickering 785

Floating-point format 685 

floating-point numbers 684 floating-point representation 685

Flood 297 

Flush 1 15 

FontExtent 310 

FOR 477 

Forbid 169

FORBIDQ 576 

FOREVER 477 

FORM() 538 

Format 76

FORWARD0 576 

FPIAR Register 701 

FPU exceptions: 

BSUN 699 

CopProt 699 

DZ 699 

F-Line 699 

FTRAPcc 699 

INEX 699 

INEX2 699 

OPERR 700 

OVFL 700 

SNAN 700 

UNFL 700 

FPutC 1 15 

FPuts 132 

frames 785

FRead 1 16 

FreeAslRequest 29 

FreeBrokerList 51 

FreeClass 417 

FreeColorMap 288 

FreeConfigDev 229 

FreeCopList 255 

FreeCprList 256 

FreeDeviceProc 76 

FreeDiskObject 328 

FreeDosEntry 65 

FreeDosObject 65 

FreeEntry 180 

FreeExpansionMem 229 

FreeFileRequest 27 

FreeFreeList 328 

FreeGadgets 240 

FreeGBuffers 319 

FreelFF 333 

FreeLocalltem 348 

FreeMem 180 

Index 

FREEMEM() 576 

FreeMenus 240 

FreePortQ 618 

FreeRaster 288 

FreeRemember 417 

FreeScreenDrawInfo 352 

FreeSignal 1 89 

FREESPACE() 547, 618 

FreeSprite 320 

FreeSysRequest 393 

FreeTagltems 456 

FreeTrap 189 

FreeVec 1 80 

FreeVisuallnfo 241 

FreeVPortCopLists 256 

frequency 906

FRESTORE 697 

FSAVE 697 

FUZZ() 538 

FWrite 1 16 

G 

GadgetMouse 399 

gadgets 11

GETARGO 577 

GetArgStr 132 

GetAttr 419 

GetCC 1 69 

GETCLIP() 547 

GetColorMap 288 

GetColorMapO 11 

GetConsoleTask 77 

GetCurrentBinding 229 

GetCurrentDirName 132 

GetDefaultPubScreen 353 

GetDefDiskObject 329 

GetDefPrefs 419 

GetDeviceProc 77 

GetDiskObject 329 

GetDiskObjectNew 329 

GetDisplaylnfoData 256 

GetFileSysTask 78 

GetGBuffers 320 

GetMsg 196 

GETPKTO 577 

GetPrefs 419 

GetProgramDir 89 

GetProgramName 133 

GetPrompt 133 

GetRGB4 289 

GetScreenData 353 

GetScreenDrawInfo 354 

GETSPACE() 548, 618 

GetSprite 321 

GetTagData 456 

GetVar 141 

GetVisuallnfoA 241 

GetVPModelD 257 

GfxBase: 

Row/cols 11 

GoodID 333 

GoodType 333 

GT_BeginRefresh 241 

GT_EndRefresh 242 

GT_GetIMsg 243 

GTJPostFilterlMsg 243 

GT_RefreshWindow 243 

GT_ReplyIMsg 244 

GT_SetGadgetAttrsA 244 

H 

HAM 810 

handshake lines 941 harmonic 907

HASHO 548 

Hertz 906 

HI 569 

hold-and-modify mode 810

Hook 25-26 

horizontal blanking gap 784

Horizontal Pulse 934 

Horizontal Quadrature Pulse 934 

Index 

Host address 595 

Human Logic 474 

I/O Functions 602 

Icon 16, 17 

Copy 17 

Delete 17 

Empty Trash 18 

Format Disk 18

Information 17 

Leave Out 17 

Open 17 

Put Away 17 

Rename 17 

Snapshot 17 

Unsnapshot 17 

IDtoStr 334 

IF 503 

1F...THEN..JELSE 477 

IFF file format 33 1 

iffparsclibrary 331

IHelp 21 

Image 20 

IMPORT() 548 

ESIDEXO 527 

Indirect Descriptors 681 

Info 89 

Inhibit 78 

InitArea 298 

InitBitMap 290 

InitCode 163 

InitGels 321 

InitGMasks 321 

InitlFF 334 

InitlFFasClip 334 

InitlFFasDOS 335 

InitLayers 11 

InitListO 619 

InitMasks 322 

InitPortO 619 

InitRastPort 290 

InitRequester 394 

InitResident 164 

InitSemaphore 215 

InitStruct 1 64 

InitTmpRas 291 

InitView 291 

InitVPort 291 

Input 105 

Input and output data flow 596 

input device buttons 940

Input task 5 

Insert 1 83 

DSfSERTO 527 

InsertCxObj 43 

InstallClipRegion ,. 438 

InstallLayerHook < 438 

Instruction Address Register (FPIAR) ... 685 

Instruction Cache Design 702 

Instructions 495 

INT2, INT3, INT6 737 

Integer division (%) 489 

intensity 906 interlace mode 823 interlacing 785

InternalLoadSeg 98 

InternalUnLoadSeg 99 

INTERPRET 481, 508 

interrupt mask register 795 interrupt request register 795

IntuiTextLength 412 

Intuition tasks 5 

InvertKeyMap 50 

IoErr 144 

IsFileSystem 79 

Islnteractive 1 17 

IsRexxMsgO 619 

IsSymbolO 620 

ItemAddress 371 

ITERATE 504 

Index 

J-L 

joysticks 937

Key Repeat Delay 18, 19 

Key Repeat Rate 19 

Key Repeat Test 19 

kilohertz 906 label marker 492

LASTPOS0 528 

Layer 11 

LayoutMenuItemsA 245 

LayoutMenusA 246 

LEAVE 504 

LEFTO 528 

LENGTHO 528 

lengthargstringO 609, 620

Libraries 7 

LINES() 520 

ListNamesO 620 

LoadRGB4 257 

LoadSeg 99 

LoadView 258 

LoadWB 14 

LocalltemData 348 

Lock 1 17 

LockDosList 71 

LocklBase 420 

LockLayer 439 

LockLayerlnfo 439 

LockLayerRom 292 

LockLayers 439 

LockPubScreen 354 

LockPubScreenList 355 

LockRecord 118 

LockRexxBase() 620 

Logical AND (&) 491 

Logical exclusive OR (A or &&) 491 

Logical inclusive OR (I) 491 

Logical NOT (~) 491 

long frame 785 low-pass filter 920

M 

MakeClass 420 

MAKEDIR0 582 

MakeDosEntry 66 

MakeDosNode 230 

MakeFunctions 1 64 

MakeLibrary 165 

MakeScreen 355 

MakeVPort 258 

mantissa 685

MapTags 456 

Masking 876 

MatchEnd 89 

MatchFirst 90 

MatchNext 90 

MatohPattern 134 

MatchToolValue 330 

mathffp.library 8

MAX() 538 

MaxCli 106 

MemHeader 11 

Message Packets 588 

MIN() 539 

minterm 873

Mode RM 691 

Mode RN 691 

Mode RZ 691 

ModeNotAvailable 258 

ModifylDCMP 371 

ModifyProp 400 

modules 7 modulo values 865

Monadic Operations 694 

mouse 934

Mouse Screen Drag keys 19 

Mouse Speed slider 18 

Move 298, 797, 799 

MoveLayer 439 

MoveLayerlnFrontOf 440 

MoveScreen 355 

MoveSizeLayer 440 

Index 

MoveSprite 322 

MoveWindow 371 

MoveWindowInFrontOf 372 

MrgCop 259 

Multiplication (*) 488 

N 

NameFromFH 134 

NameFromLock 134 

NewFontContents 57 

NewLayerlnfo 11,441 

NewLoadSeg 99 

NewModifyProp 400 

NewObjectA 421 

NewRegion 285 

NewScaledDiskFont 58 

NEXT() 578 

NextDisplaylnfo 259 

NextDosEntry 72 

NextObject 421 

NextPubScreen 356 

NextTagltem 457 

No declarations 474 

NoCapsLock 21 

NOP 504 

null clauses 492

NULLO 578 

NUMERIC 476, 509 

NUMERIC DIGITS 490 

NUMERIC FUZZ 490 

o

ObtainConfigBinding 231 

ObtainGIRPort 401 

ObtainSemaphore 215 

ObtainSemaphoreList '?. 215 

ObtainSemaphoreShared 215 

odd cycles 788

OffGadget 401 

OffMenu 372 

OFFSETO 578 

OldOpenLibrary 204 

OnGadget 402 

Only Icons , 16 

OnMenu 373 

Open 1 19 

OPEN() 521 

OpenClipboard ,335 

OpenDevice 210 

OpenDiskFont 5 5 

OpenF() 606 

OpenFont 310 

OpenFromLock 120 

OpenlFF 335 

OpenLibrary 204 

OpenMonitor 259 

OPENPORT() 578 

OpenPublicPort() 621 

OpenResource 213 

OpenScreen 356 

OpenScreenTagList 357 

Open Window 373 

OpenWindowTagList 375 

OpenWorkBench 358 

Operating System Menu 6 

Operators 485 

OPTIONS 480, 510 

OrRectRegion 285 

OrRegionRegion 285 

OTHERWISE 504 

Output 106 

OVERLAY0 528 

OwnBlitter 280 

P 

PackBoolTags 457 

Packed decimal real 686 

paddles 938

Paged Memory Management Unit 668 

ParentChunk 341 

ParentDir 91 

ParentOfFH 91 

Index 

PARSE 481, 496 

ParselFF 336 

ParselX 47 

PARSE PULL 481 

ParsePattem 135 

parsing data 555

PassPort 595 

PathPart 135 

Permit 169 

PERMITO 579 

Pipelining 894 

playfields 807

Pointlnlmage 422 

PolyDraw 299 

PopChunk 341 

POS() 529 

potentiometers 938

PRAGMA() 549 

Prefix conversion (+) 488 

Prefix negation (-) 488 

Prefs 18 

Font 20 

IControl 19 

Input 18 

Overscan 20 

Palette 19 

Pointer 20 

Printer 20 

PrinterGfx 20 

ScreenMode 20 

Serial 21 

Time 21 

WBpattern 19 

Preserve colors 19 

PrintFault 144 

PrintlText 413 

PROCEDURE 478, 510 

Procure 216 

Program Control Instructions 695 

PropChunk 344 

PubScreenStatus 358 

PULL 476, 499 

PUSH 499 

PushChunk 341 

PutDefDiskObject 330 

PutDiskObject 330 

PutMsg 1 96 

PutStr 144 

Q-R 

QBlit 280 

QBSBlit 280 

quantization 911

QueryOverscan 359 

QUEUE 499 

QueueFO 607 

Quotient Byte 688 

R/W andRWM 672 

RAM 770 

RANDOM0 539 

RANDU() 539 

RawDoFmt 196 

Read 120 

ReadArgs 106 

READCH0 522 

ReadChunkBytes 336 

ReadChunkRecords 337 

ReadF() 607 

Readltem 107 

READLN0 522 

ReadPixel 299 

ReadPixelArray8 300 

ReadPixelLine8 301 

ReadStr() 607 

RectFill 301 

refresh cycles 790

RefreshGadgets 402 

RerreshGList 402 

RefreshTagltemClones 460 

RefreshWindowFrame 376 

Relabel — 79 

ReleaseConfigBinding 23 1 

Index 

ReleaseGIRPort 403 

ReleaseSemaphore 216 

ReleaseSemaphoreList 216 

Remainder (//) 489 

RemakeDisplay 359 

RemClipNodeO 621 

RemConfigDev 231 

RemDevice 21 1 

RemDosEntry 72 

RemFont 310 

RemHead 1 84 

RemlBob 322 

RemlntServer 170 

REMLIB() 550 

RemLibraiy 205 

Remove 1 84 

RemoveAppIcon 464 

RemoveAppMenuItem 465 

RemoveAppWindow 465 

RemoveClass 422 

RemoveCxObj 44 

RemoveGadget 403 

RemoveGList 404 

RemPort 199 

RemResource 213 

RemRsrcListO 622 

RemRsrcNodeO 622 

RemSegment 100 

RemSemaphore 217 

RemTail 1 84 

RemTask 1 89 

RemVSprite 323 

Rename 120 

RENAME() 5 82 

REPLY() 579 

ReplyMsg 199 

ReplyPkt 79 

ReportMouse 404 

Request 394 

RequestFile 28 

reset vector 779

ResetMenuStrip 376 

ResetWindows 11 

Resource Nodes 589 

Resources 7 

RethinkDisplay 359 

RETURN 504 

REVERSE0 529 

RIGHTO 529 

ROM .779 

rombootlibrary 10 rounding errors 911

RouteCxMsg 49 

RunCommand 100 

RX 570 

RXADDCON [RXFB_NONRET] 598 

RXADDFH [RXFB_NONRET] 598 

RXADDLIB [RXFBJSTONRET] 599 

RXC 571 

RXCOMM [RXFB.TOKEN] 

[RXFB_STRING] [RXFB_RESULT] 

[RXFB_NOIO] 599 

RXFB_NOIO 600 

RXFB_NONRET 601 

RXFB_RESULT 601 

RXFB_STRING 601 

RXFB_TOKEN 601 

RXFUNC [RXFB_RESULT] 

[RXFB_STRING] [RXFB_NOIO] 599 

RXREMCON [RXFB_NONRET] 600 

RXREMLIB [RXFB_NONRET] 600 

RXSET 570 

RXTCCLS [RXFB_NONRET] 600 

RXTCOPN [RXFB_NONRET] 600 

S 

SameLock 121 

sample period 914 samples 911 sampling rate 914

SAS C-compiler 11 

SAY 476,500 

Index 

ScalerDiv 281 

Scaling 20 

Screen menu snap 19 

Screens 11 

ScreenToBack 360 

ScreenToFront 360 

ScrollLayer 441 

ScrollRaster 281 

ScrollVPort 260 

Seek , 121 

SEEKO 522 

SeekF() 608 

SELECT 505 

SELECT...WHEN...OTHERWISE...END 

Selectlnput 108 

SelectOutput 108 

SendIO 21 1 

SendPkt 80 

serial data lines 941 serial interface 12

SetAPen 302 

SetArgStr 108 

SetAttrsA 422 

SetBPen 302 

SETCLIP() 550 

SetCollision 323 

SetComment 122 

SetConsoleTask 80 

SetCurrentBinding 232 

SetCurrentDirName 109 

SetCxObjPri 42 

SetDefaultPubScreen 360 

SetDMRequest 394 

SetDrMd 302 

SetEditHook 404 

SetExcept 190 

SetFileDate 122 

SetFileSize 123 

SetFileSysTask 81 

SetFilter 46 

SetFilterK 46 

SetFont 311 

SetFunction 206 

SetGadgetAttrsA 405 

SetlntVector 170 

SetloErr 145 

SetLocalltemPurge 348 

SetMenuStrip 377 

SetMouseQueue 378 

SetPointer 378 

SetPrefs 423 

SetProgramDir 109 

SetProgramName 109 

SetPrompt 1 10 

SetProtection 123 

SetPubScreenModes 360 

SetRast 304 

SetRGB4 260 

SetRGB4CM 292 

SetSignal 190 

SetSoftStyle 311 

SetSR 171 

SetTaskPri 191 

SetTranslate 45 

SetVar 142 

SetWindowTitles 379 

Shade 20 

SHELL 511 

short frame 785

Show 17, 18 

SHOW() 551 

SHOWDIR() 582 

SHOWLIST0 579 

ShowTitle 361 

SIGN() 540 

Signal 192, 477, 505 

SIGNAL ON 481 

Single real 686 

SizeLayer 441 

SizeWindow 379 

SKIP 797, 801 

Index 

Smoothing 20 

SortGList 323 

sound pressure 906

SOURCELINE0 551 

SPAbs/EEESPAbs/IEEEDPAbs 444 

SPACE() 530 

SPAcos/IEEESPAcos/ffiEEDPAcos 448 

SPAdd/IEEESPAdd/IEEEDPAdd 445 

SPAsin/IEEESPAsin/IEEEDPAsin 448 

SPAtan/IEEESPAtan/ffiEEDPAtan 449 

SPCeil/IEEESPCeil/IEEEDPCeil 445 

SPCmp/IEEESPCmp/IEEEDPCmp 445 

SPCos/EEESPCos/ffiEEDPCos 449 

SPCosh/ffiEESPCosh/IEEEDPCosh 449 

SPDiv/EEESPDiv/IEEEDPDiv 445 

Special 7 

SPExp/IEEESPExp/IEEEDPExp 449 

SPFieee/DEEESPFieee/IEEEDPFieee 450 

SPFix/EEESPFix/IEEEDPFix 446 

SPFloor/IEEESPFloor/IEEEDPFloor 446 

SPFlt/IEEESPFlt/IEEEDPFlt 446 

SplitName 136 

SPLog/IEEESPLog/IEEEDPLog 450 

SPLoglO/BEEESPLoglO/IEEEDPLoglO 

SPMul/EEESPMul/IEEEDPMul 446 

SPNeg/IEEESPNeg/DEEEDPNeg 447 

SPPow/IEEESPPow/IEEEDPPow 450 

sprite data list 840 sprite DMA 840 sprites 807,838

SPSin/EEEESPSin/IEEEDPSin 451 

SPSincos/EEEESPSincos/IEEEDPSincos 

SPSinh/IEEESPSinh/IEEEDPSinh 45 1 

SPSprt/IEEESPSqit/IEEEDPSqit 45 1 

SPSub/IEEESPSub/IEEEDPSub 447 

SPTan/IEEESPTan/IEEEDPTan 452 

SPTanh/IEEESPTanh/IEEEDPTanh 452 

SPTieee/IEEESPTieee/IEEEDPTieee 452 

SPTst/IEEESPTst/IEEEDPTst 447 

StackF() 608 

StartNotify 81 

startup Copper list 806

Status Register 688 

Accrued Exception Byte 688 

Condition Code Byte 688 

Exception Byte 688 

Quotient Byte 688 

Status Register (FPSR) 685 

StcToken() 609 

StopChunk 345 

StopOnExit 346 

STORAGE0 552 

StoreltemlnContext 349 

StoreLocalltem 349 

StrcmpN() 610 

StrcpyAO 610 

StrcpyN() 610 

StrcpyUO 611 

StrflipNO 611 

Strings 485 

STREPO 530 

StripFont 312 

Strlen() 611 

StrToDate 136 

StrToLong 137 

SUBSTR() 530 

Subtraction (-) 489 

SUBWORDO 53 1 

SUD 887 

SUL 887 

SumKickData 166 

SumLibrary 206 

Super-HiRes mode 860 

SuperBitmap Console 12 

Superstate 171 

Supervisor 172 

SwapBitsRastPortClipRect 442 

SYMBOL() 552 

Symbols 483 

SYS 6 

Index 

SysReqHandler 395 

System 21 

FixFonts 21 

NoFastMem 21 

SetMap 21 

system directory 6

SystemTagList 110 

T 

tag-entry 702 tag-field 703

TaglnArray 460 

Tagltem fields 25 

Tagltems 26 

TCC 571 

TCO 57 1 

IE 571 

template 555

Test 18 

Text 312 

Text gadget filter 19 

TextExtent 312 

TextFit 313 

TextLength 314 

THEN 506 

ThinLayerlnfo 11 

timbre 907

TBVE0 552 

Tokens 483 

tone color 907

ToolManager 18 

Tools 18 

ResetWB 18 

ToUpper() 614 

TRACE 474, 511 

TRACE() 553 

tracing programs 555

Trackdisk 12 

Translate 452 

TRANSLATEO 53 1 

Translation Control Register (TC) 673 

translation tree 670 tremolo 907

TRIM() 532 

TRUNCO 540 

TS 571 

Type-less data 473 

TypeOfMem 181 

TYPEPKTQ 580 

u

UART 942 

UnGetC 124 

Universal applicability 473 

Universal Asynchronous Receiver/ 

Transmitter 942 

UnLoadSeg 101 

UnLock 124 

UnLockDosList 72 

UnlocklBase 423 

UnlockLayer 442 

UnlockLayerlnfo 442 

UnlockLayerRom 292 

UnlockLayers 443 

UnlockPubScreen 361 

UnlockPubScreenList 361 

UnLockRecord 124 

UnLockRecords 125 

UnlockRexxbase() 622 

UNTIL 477 

UpfrontLayer 443 

UPPER 512 

UPPER() 532 

UserState 172 

Utilities 21 

Clock 21 

Display 21 

Exchange and Commodities 21 

More 21 

Say 21 

Index 

v-z

Vacate 217 

VALUEO 554 

VBeamPos 261 

Vector Base Register (VBR) 10 

Verify Timeout 19 

VERIFYO 532 

vertical blanking gap 785

Vertical Pulse ,. 934 

Vertical Quadrature Pulse 934 

VFPrintf 125 

VFWritef , 126 

vibrato 906

VideoControl 261 

View Address 362 

ViewPortAddress 3 80 

volume 906

Volume modulation 922 

VPrintf 1 10 

Wait 192, 797, 800 

WaitBOVP 262 

WaitForChar 139 

WAITFORPORT 572 

WaitIO 21 1 

WaitPkt 81 

WATTPKTO 581 

WaitPort 200 

WaitTOF 263 

WBenchToBack 362 

WBenchToFront 362 

WeighTAMatch 314 

WHEN 506 

WHILE 477 

white noise 909

Window 16 

Clean Up 16 

Close 16 

New Drawer 16 

Open Parent 16 

Select Contents 16 

Show 16 

Snapshot 16 

Update 16 

View By 16 

Window frames 11 

WindowLimits 3 80 

WindowToBack 380 

WindowToFront 38 1 

WORD() 533 

WORDINDEX() 533 

WORDLENGTH0 533 

WORDS() 533 

Workbench 11, 13, 15 

About 15 

Backdrop 15 

Execute Command 15 

Last Message 15 

Quit 15 

Redraw All 15 

Update All 15 

workbench-task 8 workbench.library 14

Write 126 

write-through cache 704

WRITECHO 523 

WriteChunkBytes 337 

WriteChunkRecords 338 

WriteF() "„ 608 

WRTTELNO 523 

WritePixel 304 

WritePixelArray8 305 

WritePixelLine8 305 

X2C0 543 

X2D() 543 

XorRectRegion 286 

XorRegionRegion 286 

XRANGEO 533 

ZipWindow 331 

Amiga Desktop Video Power 

Amiga desktop Video Power is the most complete and useful guide 

desktop video on the Amiga.
Amiga Desktop Video Power 

covers all the basics- defining video terms, selecting genlocks, digitizers, scanners, VCRs, camera and connecting them to the Amiga.

Justafewofthe topics described 

in this excellent book:

• Now includes DCTV, Video 

Toaster info 

• The basics of video 

• Genlocks 

• Digitizers and scanners 

• Frame Grabbers/ 

Frame Buffers 

• How to connect VCRs, 

VTRs, and cameras to the Amiga 

• Using the Amiga to add or incorporate Special Effects to a  video 

• Paint, Ray Tracing, and 3D rendering in commercial applications 

• Animation 

• Video Titling 

• Music and videos 

• Home videos 

• Advanced techniques 

to

Item #B122 ISBN 1-55755-122-7 

Suggested retail price: $29.95 

- 

... 

■"■■■. 

\> •  -. -■■• 

Includes 

companion diskette

■: 

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

AmigaDOS: Inside &  Out Revised 

AmigaDOS: Inside &  Out covers the insides of AmigaDOS, everything 

from the internal design to practical applications.

AmigaDOS Inside &  Out will 

show you how to manage
Amiga's multitasking cap- 

abilities more effectively. There is also a  detailed reference section which helps you find information in a  flash, both alphabetically and in command groups. Topics include getting the most from the AmigaDOS
Shell (wildcards and command 

abbreviations) script (batch) files -  what they are and how to write them.

More topics include: 

• AmigaDOS -  Tasks and handling 

• Detailed explanations of CLI commands and their functions 

• In-depth guide to ED and EDIT 

• Amiga devices and how the AmigaDOS Shell uses them 

• Customizing your own startup-sequence 

• AmigaDOS and multitasking 

• Writing your own AmigaDOS Shell 

commands in C

• Reference for 1 .2, 1 .3 and 2.0 commands 

• Companion diskette included 

Item #B125 ISBN 1-55755-125-1. 

Suggested retail price: $24.95 

liSketux-w

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada I 

Using ARexx on the Amiga 

Using ARexx on the Amiga is the most authoritative guide to using the 

popular ARexx programming language on the Amiga. It's filled with tutorials, examples, programming code and a complete reference section that you will use over and over again.

Using ARexx on the Amiga is 

written for new users and advanced programmers of

ARexx by noted Amiga experts 

Chris Zamara and NickSullivan. 

Topics include: 

• What is Rexx/ARexx - 

a short history

• Thorough overview of all 

ARexx commands - 

with examples

• Useful ARexx macros for controlling software and devices 

• How to access other Amiga applications with ARexx 

• Detailed ARexx programming examples for beginners and 

advanced users

• Multitasking and inter-program communications 

• Companion diskette included 

• And much, much more! 

Item #B114 ISBN 1-55755-114-6. 

Suggested retail price: $34.95 

* 

■ 

— , 

: inbludesi{9| 

companion diskette

"fa. -                               t 

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

Amiga Machine Language 

Amiga Machine Language introduces you to 68000 machine language 

programming presented in clear, easy to understand terms. If you're a   beginner, the introduction eases you into programming right away. If you're an advanced programmer, you'll discover the hidden powers of your Amiga.

Learn how to access the 

hardware registers, use the

Amiga libraries, create gadgets, 

work with Intuition and more.

• 68000 microprocessor 

architecture

• 68000 address modes and 

instruction set

• Accessing RAM, operating 

system and multitasking capabilities

• Details the powerful Amiga libraries for access to AmigaDOS 

• Simple number base conversions 

• Menu programming explained 

• Speech utility for remarkable human voice synthesis 

• Complete Intuition demonstration program including 

Proportional, Boolean and String gadgets 

Item #B025 ISBN 1-55755-025-5. Suggested retail price: $19.95 

Companion Diskette available: Contains every program listed in the 

book- complete, error free and ready to run! Saves you hours of typing in program listings. Available only from Abacus. Item #S025. $14.95

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

Amiga C  for Beginners 

Amiga C  for Beginners is an introduction to learning the popular C 

language. Explains the language elements using examples specifically geared to the Amiga.

Describes C  library routines, how 

the compiler works and more.

Topics include: 

• Beginner's overview of C 

• Particulars of C 

• Writing your first program 

• The scope of the language 

(loops, conditions, functions, 

structures)

• Special features of the 

C language 

• Input/Output using C 

• Tricks and Tips for 

finding errors

• Introduction to direct 

programming of the operating system (windows, screens, direct text output, DOS functions)

• Using the LATTICE and AZTEC C  compilers 

Item #B045 ISBN 1-55755-045-X. Suggested retail price: $19.95 

Companion Diskette available: Contains every program listed in the 

book- complete, error free and ready to run! Saves you hours of typing in program listings. Available only from Abacus. Item #S045. $14.95

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

Amiga Graphics: Inside &  Out 

Amiga Graphics: Inside &  Out will show you the super graphic features 

and functions of the Amiga in detail. Learn thegraphicfeatures that can be accessed from

AmigaBASIC or C. The 

advanced user will learn how to call the graphic routines from the Amiga's built-in graphic libraries. Learn graphic programming in C  with examples of points, lines, rectangles, polygons, colors and more.

Complete description of the 

Amiga graphic system- View, 

ViewPort, RastPort, bitmap 

mapping, screens and windows.

Topics include: 

• Accessing fonts and type 

styles in AmigaBASIC

• Loading and saving IFF graphics 

• CAD on a  1024 x  1024 super bitmap, using graphic 

library routines

• Access libraries and chips from BASIC- 4096 colors at once, 

color patterns, screen and window dumps to printer

• Amiga animation explained including sprites, bobs 

and AnimObs, Copper and blitter programming

Item #B052 ISBN 1-55755-052-2. Suggested retail price: $34.95 

Companion Diskette available: Contains every program listed in the 

book- complete, error free and ready to run! Saves you hours of typing in program listings. Available only from Abacus. Item #S052. $14.95

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada I 

The Best Amiga Tricks &  Tips The Best Amiga Tricks &  Tips is a  great collection of Workbench, CLI and BASIC programming
"quick-hitters", hints and 

application programs. You'll be able to make your programs more user-friendly with pull- down menus, sliders and tables.
BASIC programmers will learn 

all about gadgets, windows, graphic fades, HAM mode, 3D graphics and more. The Best Amiga Tricks &  Tips includes a  complete list of BASIC tokens and multitasking input and a  fast and easy print routine. If you're an advanced programmer, you'll discover the hidden powers of your Amiga.

• Using the new AmigaDOS, Workbench and Preferences 1 .3 

and Release 2.0

• Tips on using the new utilities on Extras 1 .3 

• Customizing Kickstart for Amiga 1000 users 

• Enhancing BASIC using ColorCycle and mouse sleeper 

• Disabling FastRAM and disk drives 

• Using the mount command 

• Writing an Amiga virus killer program 

• Disk drive operations and disk commands 

• Learn machine language calls. 

Item #  B107 ISBN 1-55755-107-3. 

Suggested retail price $29.95 

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

Amiga BASIC: Inside and Out 

Amiga BASIC: Inside and Out is the definitive step-by-step guide to 

programming the Amiga in

BASIC. This huge volume 

should be within every Amiga user's reach. Every Amiga

BASIC command is fully 

described and detailed. In addition, Amiga BASIC: Inside and Out is loaded with real working programs.

Topics include: 

Video titling for high quality 

object animation

Bar and pie charts 

Windows 

Pull down menus 

Mouse commands 

Statistics 

Sequential and relative files 

Speech and sound synthesis 

item #B87X ISBN 0-916439-87-9. Suggested retail price: $24.95

Companion Diskette available: Contains every program listed in the 

book complete, error free and ready to run! Saves you hours of typing in program listings. Available only from Abacus. Item #S87X. $14.95

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 1 

Amiga for Beginners 

A perfect introductory book if you're a  new or prospective Amiga owner.

Amiga for Beginners 

introduces you to Intuition (the

Amiga's graphic interface), the 

mouse, windows and the versatile CLI. This first volume in our Amiga series explains every practical aspect of the

Amiga in plain English with 

clear, step-by-step instructions for common Amiga tasks.

Amiga for Beginners is all the 

info you need to get up and running.

Topics include: 

• Unpacking and connecting 

the Amiga components

• Starting up your Amiga 

• Exploring the Extras disk 

• Taking your first step in AmigaBASIC programming language 

• AmigaDOS functions 

• Customizing the Workbench 

• Using the CLI to perform "housekeeping" chores 

• First Aid, Keyword, Technical appendixes 

• Glossary 

Item #B021 ISBN 1-55755-021-2. Suggested retail price: $16.95 

Companion Diskette not available for this book. 

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

l

AssemPro 

Assembly Language Development System for the Amiga 

AssemPro has the professional features that advanced programmers 

lookfor. Like syntax error search/ replace functions to speed program alterations and de- bugging. And you can compile to memory for lightning speed. The comprehensive tutorial and manual have the detailed information you need for fast, effective programming.

AssemPro 

Amiga 

> The Professional 

Assembly Language 

s| Development, System

AbacusHI 

A Data Becker Product

Features include: 

• Integrated editor, debugger, 

disassembler and reassembler

• Runs under CLI 

and Workbench

• Produces either PC- 

relocatable or absolute code

• Create custom macros for nearly any parameter 

• Error search and replace functions 

• Menu-controlled conditional and repeated assembly 

• Full 32-bit arithmetic 

• Advanced debugger with 68020 single-step emulation 

• Fast assembly to either memory or disk 

• Written entirely in machine language 

• Runs on any Amiga with 51 2K or more 

Item #S030 ISBN 1-55755-030-1. Suggested retail price: $99.95 

Machine language programming requires a  solid understanding of the Amiga 's hardware and operating system. We do not recommend this package to beginning Amiga programmers.

See your local dealer or order TOLL FREE 1-800-451-4319 in US &  Canada 

] 

reference library in one guide for all
Amiga 500, 1 000, 2000, 2500 and 

3000 users. Amiga Intern will explain 

the internals of the Amiga 3000,
Release 2.0 (Workbench 2.0) of the 

operating system and Kickstart 2.0.
Amiga Intern teaches you important 

information about the ARexx programming language that is bundled with all Amiga 3000s.
Amiga intern is divided into three 

easy-to-use sections for hardware, operating system and ARexx programming. If you are interested in the Amiga hardware you'll learn all the essentials of the 68030 processor and its environment.
Amiga Intern also contains an 

extensive reference section on
Kickstart 2.0 and much more. 

US $39.95/ CDN $49.95 

The definitive reference book for all Amiga computers A short overview of the contents:

Hardware: 

68030 and 68881/82 specifications 

MMU, FPU and ECS 

Zorro II bus system 

SCSI I  controller 

FlickerFixer 

System Software: 

Kickstart 2.0 innovations 

Workbench 2.0 innovations 

Overview of library functions 

Program samples 

ARexx: 

' History of development 

Syntax oriented command lists 

Basic elements 

Special language elements 

Function libraries 

Program samples 

Computer Book Categor 

Computer: Amiga 

vel: Intermediate/Advanced

Abacus 

mmn\ llffiiffll

5370 52nd Street SE •  Grand Rapids, Ml 49512 

