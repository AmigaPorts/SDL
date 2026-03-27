# The Diskfont Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.3 The Diskfont Library

The Diskfont Library manages fonts and font styles, lists the available fonts, or loads a  font in memory (if it is not already loaded). This library is opened under the name "diskfont.library". The base address _DiskfontBase must be supplied in the A6 register with all function calls.

Functions of the Diskfont Library 

OpenDiskFont 

AvailFonts 

NewFontContents 

DisposeFontContents 

## 3.1 The Libraries and their Functions

NewScaledDiskFont 

Description of the Functions 

| OpenDiskFont Load or scale a  Diskfontl 

Call: font =  OpenDiskFont (text Attr) 

DO -30 (A6) A0 

STRUCT TextFont *font 

STRUCT TextAttr *textAttr 

Function: The font described in the TextAttr structure is loaded in 

memory and its address is returned. If desired, the font is scaled to the requested size.

Parameters: textAttr TextAttr structure or TTextAttr structure that 

describes the font.

Result: Address of the font (TextFont structure) or 0  if the font was 

not found. If only the desired font size was not found and the DESIGNED flag in the TextAttr structure is not set, then the font of the desired size is created from a  different size.

Warning: This routine will only work with font names up to 30 

characters long.

See also: AvailFonts(), graphics.library/OpenFont() 

| AvailFonts Retrieve a  list of all available fonts| 

Call: error =  AvailFonts (buffer, bufBytes, flags) 

DO -36 (A6) A0 DO Dl 

LONG error 

STRUCT AFH *buffer 

LONG bufBytes 

ULONG flags 

Function: AvailFonts() fills a  memory block of the specified size and 

address with font data structures. This gives the user a  list of all available fonts. Certain flags can be set to indicate where to look for fonts, which fonts are stored in this memory block, and which data structures to use.

Parameters: buffer Address of the memory block that will contain 

the font list. bufbytes Size of the memory block. flags Flags for setting the AvailFonts() options.

AFF_MEMORY Look for fonts in memory. 

AFF DISK 

AFF SCALED 

Look for fonts in current 

FONTS directory. 

Include constructed fonts 

in the list.

AFF TAGGED 

Fill memory with TAF 

(TaggedAvailFonts) 

structures rather than AF structures.

Result: If the buffer is too small, the number of bytes missing will be 

returned in error otherwise a  value of 0  is returned. If 0  is returned, the buffer is filled with an AFH structure, followed by AF or TAF structures. Memory resident fonts must be opened with OpenFont() and Diskfonts must be opened with OpenDiskFont().

Warning: If a  certain font is located both in memory as well as on 

disk, its name will appear in the list twice.

See also: OpenDiskFontQ, graphics.library/OpenFontQ 

| NewFontContents Recalculate xxx.font file 1 

Cfl//.' fontContentsHeader =  NewFontContents (fontsLock, fontName) 

DO -42 (A6) AO Al 

STRUCT FontContentsHeader *fontContentsHeader 

BPTR fontsLock 

APTR fontName 

Function: Recalculates an array with FontContents. This array begins 

with an FCH structure, followed by an FC structure for each size of the font with the given name. This structure corresponds to the file 'xxx.font' in the FONTS directory.

Parameters: fontsLock BPTR to a  lock structure of the DOS Library. 

This lock must be obtained for the directory that contains the font (normally the "FONTS: directory). fontName Address of the font name (including the suffix
".font") which points to a  FontContents file. 

Result: Address of the FCH structure (FontContentsHeader) or 0, 

in the case of an error.

See also: DisposeFontContents(), dos.library/Lock() 

| DisposeFontContents Free xxx.font buffer | 

Call: DisposeFontContents (fontContentsHeader) 

-48 (A6) Al 

STRUCT FontContentsHeader * fontContentsHeader 

Function: Frees the buffer returned with the function 

NewFontContents(). 

Parameters: fontContentsHeader 

Structure obtained with NewFontContents(). 

Result: None. 

Warning: The system will crash if you pass an address not obtained 

with NewFontContentsQ.

See also: NewFontContentsQ 

INewScaledDiskFont 

Create scaled (constructed) font| 

Call: header =  NewScaledDiskFont (srcFont, destTextAttr) 

DO -54 (A6) AO Al 

STRUCT DiskFontHeader *header 

STRUCT TextFont *srcFont 

STRUCT TTextAttr *destTextAttr 

Function: Calculates a  new font size based on an existing size for the 

given font.

Parameters: srcFont Font for which the new size will be calculated. 

destTextAttr

Attributes of the new font. This can be the 

address of a  TextAttr structure or the address of a TTextAttr structure. The new font can be freed with StripFont() followed by
UnloadSeg(). TextFont and Segment Address 

are components of the returned
DiskFontHeader. UnloadSegO frees all memory 

blocks.

Result: 

Address of a  DiskFontHeader structure. 

Warning: This function can use the blitter. Fonts with characters 

drawn completely outside of the normal character region cannot be processed.

See also: graphics.library/StripFont(), dos.library/UnloadSeg() 

MAXFONTPATH =  256 maximum length of the font path including null byte 

Dec Hex 

STRUCTURE FC,0 

0 $0 STRUCT fc_FileName, MAXFONTPATH font name 

256 $100 UWORD fc_YSize  f ont height 

258 $102 UBYTE fc_Style  style 

259 $103 UBYTE fc_Flags font type 

260 $104 LABEL fc_SIZEOF 

STRUCTURE TFC, 0 

$0 STRUCT tfc_FileNarne,MAXFONTPATH-2   f ont name 

if the following Word contains a  non-zero value, then the Tagltems will be found at the end of tfc_FileName that is, at MAXFONTPATH-tfc_TagCount*TagItem_SIZEOF
$FE UWORD tfc_TagCount  number of tags including TAG_DONE 

tfc_YSize font height tfc_Style  style tfc_Flags font type tfc_SIZEOF

256 $100 UWORD 

258 $102 UBYTE 

259 $103 UBYTE 

260 $104 LABEL 

FCH_ID =  $f00 FontContentsHeader, then FontContents 

TFCH_ID =  $f02 FontContentsHeader, then TFontContents 

Dec Hex 

STRUCTURE FCH, 0 

0 $0 UWORD fch_FileID 

2 $2 UWORD fch_NumEntries 

4 $4 LABEL fch_FC 

 FontContentsHeader 

FCH_ID or TFCH_ID 

.-number of (T) FontContents 

starting here, [T] FontContents

DFH_ID =  $f80 

MAXFONTNAME =  32  f ont name including ".font" and null byte 

Dec Hex 

STRUCTURE DiskFontHeader, 0 

the following Longs are not part of the structure, but they precede it directly:
-8 -$8 ULONG dfh_NextSegment 

dfh_ReturnCode dfh_DF,LN_SIZE dfh_FileID dfh_Revision dfh_Segment

-4 -$4 ULONG 

0 $0 STRUCT 

14 $E UWORD 

16 $10 UWORD 

18 $12 LONG 

22 $16 STRUCT 

54 $36 STRUCT 

LABEL 

dfh_Name, MAXFONTNAME the name dfh_TF,tf_SIZEOF TextFont dfh_SIZEOF

BPTR to the next segment 

actually MOVEQ #0,D0 :  RTS node
 DFH_ID 

revision number segment address If the FSB_TAGGED bit is set in dfh_TF.tf_Style: dfh_TagList =  dfh_Segment  overwritten during loading

Bits and Flags of the AvailFonts structure: 

AFB_MEMORY =  0  memory font 

AFF_MEMORY =  1 

AFB_DISK =  1 disk font 

AFF_DISK =  2 

AFB_SCALED =  2  constructed font (not DESIGNED!) 

AFF_SCALED =  4 

Bits and Flags of the TaggedAvailFonts structure: 

AFB_TTATTR =15 /INVALID VALUE IN INCLUDES!!! 

AFF_TTATTR =  $8000 

Dec Hex 

STRUCTURE AF, 0   AvailFonts 

0 $0 UWORD af_Type   MEMORY, DISK, or SCALED 

2 $2 STRUCT af_Attr,ta_SIZEOF   TextAttr 

10 $A LABEL af_SIZEOF 

STRUCTURE TAF, 0   TAvailFonts 

0 $0 UWORD taf_Type   MEMORY, DISK, or SCALED 

2 $2 STRUCT taf_Attr,tta_SIZEOF   TTextAttr 

10 $A LABEL taf_SIZEOF 

STRUCTURE AFH, 0   AvailFontsHeader 

0 $0 UWORD afh_NumEntries   number of elements 

2 $2 LABEL afh_AF   starting here, [T] AvailFonts 

Example 

You can make it difficult on yourself and create a  special font for each 

application, or you can handle it quite easily. We will now create a  font similar to the Diamond font, but with a  character height of only 10 pixels. movea.l _DiskfontBase,a6 lea _TextAttr(pc) ,a0 jsr _LVOOpenDiskFont(a6) Font=OpenDiskFont (TextAttr) move .1 dO , _Diamondl 0 beq _Fehler movea.l _Gf xBase, a6 movea.l _Diamondl0,al jsr _LVOCloseFont (a6) CloseFont (Font)

_TextAttr dc . 1 _FontName  ta_Name 

dew 10 ta_Size ta_Sty le , ta_Flags dc . b FS_NORMAL , FPF_PROPORTIONAL ! FPF_DISKFONT

_FontName dc . b ' diamond . font ' , 0 

Simple, isn't it? The change in size takes only a  fraction of a  second, so it 

does not add any appreciable time to the process.
