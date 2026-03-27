# The Utility Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.16 The Utility Library

The "utility.library" contains helpful routines designed to make programming easier. One of the most important things you can do with these routines is construct Tagltem fields from high level languages.

Functions of the Utility Library 

AllocateTagltems

CloneTagltems 

FilterTagChanges 

FilterTagltems 

FindTagltem 

FreeTagltems 

GetTagData 

MapTags 

NextTagltem 

PackBoolTags 

RefreshTagltemClones 

TaglnArray 

Description of the functions 

| AllocateTagltems Allocate a  Tagltem field | 

Call: TagList =  AllocateTagltems (  Numltems ) 

DO -66 (A6) DO 

STRUCT Tagltem *TagList 

ULONG Numltems 

Function: Allocates a  Tagltem field for storing size, etc. Access to the 

tags is only available via NextTagItem().

Parameters: Numltems Number of usable slots. 

Result: TagList or 0 

| CloneTagltems Copy a  Tagltem field | 

Call: NewTagList =  CloneTagltems (  TagList ) 

DO -72 (A6) AO 

STRUCT Tagltem *NewTagList, *TagList 

Function: Copies a  complete Tagltem list. 

Parameters: TagList Tagltem list to be copied. 

Result: Tagltem list or 0 

| FilterTagChanges Filter out changes to a  Tagltem field | 

Call: FilterTagChanges ( ChangeList, OldValues, Apply) 

-54 (A6) AO Al DO 

STRUCT Tagltem *ChangeList, *01dValues 

LONG Apply 

Function: Replaces all unchanged Tagltems in a  change list with 

TAG IGNORE. 

## 3.1 The Libraries and their Functions

Parameters: ChangeList 

New Tagltems 

OldValues Old Tagltem list 

Apply Boolean, indicates whether the old list should 

be used.

I FilterTagltems Remove certain Tagltenis] 

Call: nvalid FilterTagltems (TagList, TagArray, Logic) 

DO -96 (A6) AO Al DO 

STRUCT Tagltem *TagList 

APTR TagArray 

LONG Logic 

ULONG nvalid 

Function: Replaces with TAGJGNORE the Tagltems whose ti_Tag 

entry is in the given field.

Parameters: TagList Tagltem field 

TagArray Field with the tags to be deleted, ends with 

TAG_END. 

Logic TAGFILTER_AND (delete items not given in 

the field) or TAGFILTER_NOT (delete items given in the field).

Result: Number of valid items remaining in the list. 

I FindTagltem Find a  Tagltiin] 

Call: Tagltem =  FindTagltem (  TagVal, TagList ) 

DO -30 (A6) DO AO 

STRUCT Tagltem *TagItem, *TagList 

LONG TagVal 

Function: Finds an item in a  Tagltem list with the given tag value. 

Parameters: TagVal Tag to be found 

TagList Tagltem list 

Result: Tagltem or 0 

| FreeTagltems Free a  Tagltem field | 

Call: FreeTagltems (  TagList ) 

-78 (A6) AO 

STRUCT Tagltem *TagList 

Function: Frees a  Tagltem field allocated with AllocateTagItems() or 

CloneTagItems(). 

Parameters: TagList Field to be set free. 

I UetTagData Get data on a  Tagltem | 

Call: TagData =  GetTagData( TagVal, Default, TagList ) 

DO -3 6 (A6) DO Dl AO 

ULONG TagData , TagVal , Default 

STRUCT Tagltem *TagList 

Function: Returns the ti_Data entry of the given tag or the default 

value if no Tagltem of this type could be found.

Parameters: TagVal Tag to be found 

Default Default value 

TagList List to be searched 

Result: ti_Data or 'Default' 

IMapTags Change tags] 

Call: MapTags (TagList, MapList, IncludeMiss) 

-60 (A6) AO Al DO 

STRUCT Tagltem *TagList, *MapList 

BOOL IncludeMiss 

Function: Tags that are to be replaced by the ti_Tag of the given list 

are given in a  'MapList' as ti_Data entries.

Parameters: TagList List with tags to be changed. 

MapList List with changes 

IncludeMiss 

Boolean, whether items not in the MapList 

should remain unchanged (otherwise they are replaced with TAGJGNORE).

I NextTagltem Find the next normal Tagltem | 

Call: Tagltem =  NextTagltem (  TagltemPtr ) 

DO -48 (A6) AO 

STRUCT Tagltem *TagItem, **TagItemPtr 

Function: Returns the next Tagltem, skipping over all system tags. 

Parameters: TagltemPtr Address of a  longword with the address of the 

first Tagltem.

Result: Tagltem or 0 

| PackBoolTags Combine BoolTags into a  Hag longword | 

Call: Flags =  PackBoolTags (  InitialFlags, TagList, BoolMap ) 

DO -42 (A6) DO AO Al 

ULONG Flags, InitialFlags 

STRUCT Tagltem "TagList, *BoolMap 

Function: BoolTags are entered as bit flags in a  longword. The tag 

flags are given as tiJData in a  Tagltem field.

Parameters: InitialFlags Default result 

TagList Tagltem field with BoolTags 

BoolMap Tagltem field with flag longwords 

Result: Changed flag longword 

Example: Assume that we are managing the IDCMP Flags in a 

complex program using Tagltems, and now we want to assemble the IDCMPFlag longword:

** Definition of the 

** 

Tags 

TAG_NEWSIZE 

= 

TAG_USER+1 

TAG_REFRESHWINDOW 

= 

TAG_USER+2 

TAG_MOUSEBUTTONS 

= 

TAG_USER+3 

TAGJKOUSEMOVE 

= 

TAG_USER+4 

TAG_GADGETDOWN 

= 

TAG_USER+5 

TAG_GADGETUP 

= 

TAG_USER+6 

TAG_REQSET 

= 

TAG_USER+7 

TAG_MENUPICK 

= 

TAG_USER+8 

TAG_CLOSEWINDOW 

= 

TAG_USER+9 

TAG_RAWKEY 

= 

TAG_USER+10 

TAG_REQCLEAR 

= 

TAG_USER+11 

TAG_NEWPREFS 

= 

TAG_USER+12 

TAG_DISKINSERTED 

= 

TAG_USER+13 

TAG_DISKREMOVED 

= 

TAG_USER+14 

TAG_ACTIVEWINDOW 

= 

TAG_USER+15 

TAG_INACTIVEWINDOW 

= 

TAG_USER+16 

TAG_DELTAMOVE 

= 

TAG_USER+17 

TAG_VANILLAKEY 

= 

TAG_USER+18 

TAG_INTUITICKS 

= 

TAG_USER+19 

TAG_MENUHELP 

= 

TAG_USER+20 

TAG_CHANGEWINDOW 

= 

TAG_USER+21 

** 

** Example 

** 

movea.l _MainWindow,al lea ..Changes (pc) , aO bsr _Set IDCMP

..Changes 

dc . 1 TAG_MOUSEMOVE , 0 dc . 1 TAG_GADGETDOWN , 0 turn off turn off

dc.

,1 

TAG_DELTAMOVE, 0 

turn off dc.

,1 

TAG_VANILLAKEY, -1 

turn on dc.

.1 

TAG_USER+40,-l 

no meaning dc.

,1 

TAG_RAWKEY,0 

turn off dc.

.1 

TAG_MOUSEBUTTONS, -1 

turn on dc

.1 

TAG_USER+35,0 

no meaning dc

.1 

TAG_DONE 

** Change IDCMPFlags 

** 

** Input: al=Window, aO=TagItems 

** 

_SetIDCMP 

movem.l al/a6,-(a7) movea.l _UtilityBase,a6 move . 1 wd_IDCMPFlags (al ) , dO lea _BoolMap(pc) ,al j sr _LVOPackBoolTags ( a6 ) movea.l (a7)+,a0 movea.l _IntuiBase,a6 jsr _LVOModifyIDCMP(a6) movea.l (a7)+,a6 rts

_BoolMap 

del TAG_NEWSIZE,2 dc . 1 TAG_REFRESHWINDOW , 4 dc . 1 TAG_MOUSEBUTTONS , 8 dc . 1 TAG_MOUSEMOVE ,$10 del TAG_GADGETDOWN ,$20 del TAG_GADGETUP, $40 del TAG_REQSET, $80
del TAG_MENUPICK, $100 

dc . 1 TAG_CLOSEWINDOW, $200 

del TAG_RAWKEY,$400 

del TAG_REQCLEAR, $1000 

dc . 1 TAG_NEWPREFS ,$4000 

del TAG_DISKINSERTED,$8000 

dc . 1 TAG_DISKREMOVED, $10000 

dc . 1 TAG_ACTIVEWINDOW, $40000 

dc . 1 TAG_INACTIVEWINDOW ,$80000 

del TAG_DELTAMOVE ,$100000 

dc . 1 TAG_VANILLAKEY ,$200000 

del TAG_INTUITICKS, $400000 

dc . 1 TAG_MENUHELP, $1000000 

del TAG_CHANGEWINDOW, $2000000 

del TAG_D0NE

I RefreshTagltemClones Reset a  copied Tagltem field I 

Call: Ref reshTagltemClones ( CloneTagltems, OriginalTagltems ) 

-84 (A6) AO Al 

STRUCT Tagltem "CloneTagltems, *OriginalTagItems 

Function: Restores a  list obtained with CloneTagItems() to the values 

of the original list.

Parameters: CloneTagltems 

Result from CloneTagltems (original Tagltems). 

OriginalTagltems 

Unchanged original list 

I Tagln Array check if a  tag is present! 

Call: Bool =  TagInArray( Tag, TagArray ) 

DO -90 (A6) DO AO 

ULONG Tag 

APTR TagArray 

Function: Checks for a  certain value in a  tag value field ending with 

TAG_END. 

Parameters: Tag Tag value to search for. 

TagArray Field with tag values, ends with TAG_END. 

Result: 0  Value not found. 

Dec Hex STRUCTURE Tagltem, 0 

0 $0 ULONG ti_Tag ID (TAG_...) 

4 $4 ULONG ti_Data  ID-specific data 

8 $8 LABEL ti_SIZEOF 

TAG_DONE =         0 end of a  Tagltem field 

TAG_IGNORE =         1 skip Tagltem 

TAG_MORE =         2 next Tagltem field 

TAG_USER =  $80000000 

