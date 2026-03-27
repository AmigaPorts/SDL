# The Icon Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.9 The Icon Library

The "icoiUibrary" is used to process '.info' files. So, the base address must be given in A6 with the function calls.

Functions of the Icon Library 

AddFreeList 

BumpRevision 

FindToolType 

FreeDiskObject 

FreeFreeList 

GetDefDiskObject 

## 3.1 The Libraries and their Functions

GetDiskObject 

GetDiskObjectNew 

MatchToolValue 

PutDefDiskObject 

PutDiskObject 

Description of Functions 

| AddFreeList Add memory to FreeList | 

Call: status =  AddFreeList (free, mem, len) 

DO -72 (A6) AO Al A2 

BOOL status 

STRUCT FreeList *free 

APTR mem 

ULONG len 

Function: Adds the given memory block to a  FreeList. 

Parameters: free FreeList 

mem Memory address len Size of block

Result: 0  Error 

1 BumpRevision Create a  filename for a  copy | 

Call: result =  BumpRevision (newbuf, oldname) 

DO -108 (A6) AO Al 

APTR result, newbuf .oldname 

Function: Creates a  filename with "copy_of_" etc. 

Parameters: newbuf New name (copy_of_...), min. 31 bytes 

oldname Original filename
Result: Address of the new name or 0. 

IFindToolType Find the value of a  ToolType variable | 

Call: value =  FindToolType(toolTypeArray, typeName) 

DO -96 (A6) AO Al 

APTR value, toolTypeArray, typeName 

Function: Finds a  ToolType field according to the contents of the 

given variable.

Parameters: toolTypeArray 

String field (APTRs) 

typeName Variable name

Result: Address in ToolType string after the typeName equals sign 

orO.

IFreeDiskObject Free an icon's memory | 

Call: FreeDiskObject (diskobj ) 

-90 (A6) AO 

STRUCT Diskobj ect *diskobj 

Function: Frees the memory used by an icon allocated with 

GetDiskObject(). 

Parameters: diskobj DiskObject structure 

IFreeFreeList Free the FreeList 

Call: FreeFreeList (free) 

-54 (A6) AO 

STRUCT FreeList *free 

Function: Frees the memory entered in an icon's FreeList, including 

the memory for the FreeList structure.

Parameters: free FreeList 

I GetPefPiskObject Get default DiskUb,ject| 

Call: diskobj =  GetDefDiskObject (def_type) 

DO -120 (A6) DO 

STRUCT DiskObj ect *diskobj 

LONG def_type 

Function: Reads the default Workbench icon for an object of the 

given type.

Parameters: def_type Icon type 

Result: DiskObject or 0 

IGetDiskObject Get an icon file| 

Call: diskobj =  GetDiskObj ect (name) 

DO -78 (A6) A0 

STRUCT DiskObject *diskobj 

APTR name 

Function: Reads the icon of the given object. 

Parameters: name Object name or 0  (empty structure). 

Result: DiskObject or 0 

GetPiskObjectNew Get a  new icon file| 

Call: diskobj =  GetDiskObjectNew(name) 

DO -132 (A6) A0 

STRUCT DiskObject *diskobj 

APTR name 

Functions, Parameters, Results: 

Same as GetDiskObject(), except that if no ".info" file is 

available, an attempt is made to get the default settings with
GetDefDiskObjectQ. 

| MatchTool Value Compare ToolType variable I 

Call: result =  MatchToolValue(typeString, value) 

DO -102 (A6) A0 Al 

BOOL result 

APTR typeStr ing , value 

Function: Compares a  string with a  ToolType variable value (may be 

several values separated with T).

Parameters: typeString ToolType values as from FindToolType(). 

value Comparison string

Result: 0  Value was not in typeString. 

| PutPefPiskObject Set a  Workbench icon | 

Call: status =  PutDefDiskObject (diskobj ) 

DO -126 (A6) A0 

BOOL status 

STRUCT DiskObj ect *diskobj 

Function: Changes the standard Workbench icon for the given 

DiskObject type. 

Parameters: diskobj DiskObject 

Result: 0  Error 

IPutDiskObject 1 

Call: status =  PutDiskObj ect (name, diskobj) 

DO -84 (A6) A0 Al 

BOOL status 

APTR name 

STRUCT DiskObject *diskobj 

Function: Writes an icon file to disk. 

Parameters: name 

Filename 

Result: 

diskobj DiskObject
0 Error 

Structures: See Workbench Library. 

