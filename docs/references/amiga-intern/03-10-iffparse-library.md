# The IFFParse Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.10 The IFFParse Library

The IFF file format became an Amiga standard very quickly. Today, all sound and graphics programs use it. A  standard file format makes it simple to transfer data from one program to another. The "iffparsclibrary offers you the easiest way to introduce this standard to your own programs. All functions are called with the base address in A6.

Functions of the IFFParse Library 

1. Base Functions 

AllocIFF

CloseClipboard 

CloselFF 

FreelFF 

GoodID 

GoodType 

IDtoStr 

InitlFF 

InitTFFasDOS 

InitlFFasClip 

OpenClipboard 

OpenlFF 

ParselFF 

ReadChunkBytes 

ReadChunkRecords 

WriteChunkBytes 

WriteChunkRecords 

2. Context 

CurrentChunk 

FindCollection 

FindProp 

FindPropContext 

ParentChunk 

PopChunk 

PushChunk 

3. Handlers 

CollectionChunk 

CollectionChunks 

Entry Handler 

ExitHandler 

PropChunk 

PropChunks 

StopChunk 

StopChunks 

StopOnExit 

4. Local Contextltems 

AllocLocalltem

FindLocalltem 

FreeLocalltem 

LocalltemData StoreltemlnContext 

SetLocalltemPurge StoreLocalltem 

Description of the Functions 

1. Base Functions 

[AiiocIKF Allocate an IFFHandlel 

Call: iff =  AllociFF () 

dO -30 (A6)

STRUCT IFFHandle *iff 

Function: Allocates and initializes an IFFHandle structure. 

Result: IFFHandle or 0 

[CloseClipboard Close ClipboardHandlel 

Call: CloseClipboard (clip) 

-252 (A6) aO 

STRUCT ClipboardHandle *clip 

Function: Closes the "clipboard. device" and frees the 

ClipboardHandle structure. 

Parameters: clip ClipboardHandle structure from 

OpenClipboard(). 

IClosett* Close IFFl 

Call: closeiFF (iff) 

-48 (A6) aO 

STRUCT IFFHandle *iff 

Function: Closes an IFF file, leaving the IFFHandle structure intact for 

a new OpenIFF() call.

Parameters: iff IFFHandle structure from OpenIFF(). 

## 3.1 The Libraries and their Functions

IFreelFF Free IFFHandlel 

Call: FreelFF (iff) 

-54 (A6) aO 

STRUCT IFFHandle *iff 

Function: Frees an IFFHandle that was closed with CloseIFF(). 

Parameters: iff IFFHandle structure 

iGoodID Check IFF ID |

Call: isok =  GoodlD (id) 

dO -258 (A6) dO

LONG isok, id 

Function: Checks to see if a  chunk ID conforms with the Electronic 

Arts IFF 85 standard. 

Parameters: id 32 bit ChunkID 

Result: 0  ID not valid 

I GoodType Check FORM type] 

Call: isok =  GoodType (type) 

dO -264 (A6) dO

LONG isok, type 

Function: Checks to see if the ID is a  type of FORM chunk (EA IFF 

85). 

Parameters: type 32 bit FORMat chunk ID 

Result: 0  Not a  FORM type 

lIDtoStr

Store ID as a  string! 

Call: str =  iDtoStr (id, buf) 

dO -270 (A6) dO aO

APTR str, buf 

LONG id 

Function: Writes the ID (longword) to the given buffer and deletes 

the following byte.

Parameters: id 

buf
Result: Buffer 

Longword 

5 byte buffer 

llnitlFF

Initialize IFFHandle as UserStream| 

Call: initlFF (iff, flags, streamhook) 

-228 (A6) aO dO al 

STRUCT IFFHandle *iff 

LONG flags 

STRUCT Hook * streamhook 

Function: Initializes IFFHandle with the user routines for positioning, 

reading, and writing. The hook routines are passed to the
Hook, IFFStreamCmd, and IFFHandle structures in registers 

A0-A2. 

Parameters: iff 

flags hook llnitlFFasClip

IFFHandle structure 

I/O flags 

Hook with stream routine. 

Call: initlFFasClip (iff) 

-240 (A6) aO 

Initialize IFFHandle as ClipboardStreaml 

STRUCT iFFHandle *iff 

Function: Initializes an IFFHandle for the "clipboarddevice". Another 

ClipboardHandle from OpenClipboard() must be entered in 

iff_Stream.

Parameters: iff IFFHandle 

InitlFFasDOS Initialize IFFHandle as DOSStream | 

Call: InitlFFasDOS (iff) 

-234 (A6) aO 

STRUCT IFFHandle *iff 

Function: Initializes an IFFHandle for DOS. Another FileHandle from 

Open() must be entered in iffJStream (BPTR). 

Parameters: iff IFFHandle structure 

IQpenClipboard Get ClipboardHandle | 

Call: ch =  OpenClipboard (unit) 

dO -246 (A6) dO

STRUCT ClipboardHandle *ch 

LONG unit 

Function: Opens the given unit of the "clipboard.device" (normally 

PRIMARY_CLIP) and returns a  structure for 

InitlFFasClipO. 

Parameters: unit "clipboard.device" unit 

Result: ClipboardHandle or 0 

IQpenlFF Prepare IFFHandle for I/O | 

Call: error =  OpenlFF (iff, rwmode) 

dO -36 (A6) aO dO

LONG error , rwmode 

STRUCT IFFHandle *iff 

Function: Initializes an IFFHandle structure for reading or writing 

(IFFF_READ or IFFF_WRITE). 

Parameters: iff IFFHandle 

rwmode IFFF_READ or IFFF_WRITE

Result: Error code or 0 

IParselFF Analyze IFF] 

Call: error =  ParselFF (iff, control) 

dO -42 (A6) aO dO

LONG error , control 

STRUCT IFFHandle *iff 

Function: Reads an IFF file, puts the chunks on the context stack, 

and retrieves them in the correct order. The corresponding chunk type handler is called.

Parameters: iff IFFHandle structure 

control IFFPARSE_SCAN, IFFPARSE_STEP, or
IFFPARSE_RAWSTEP 

Result: Error code or 0 

| ReadChunkBytes Read bytes of the current chunk | 

Call: actual =  ReadChunkBytes (iff, buf, size) 

dO -60 (A6) aO al dO

LONG actual, size 

STRUCT IFFHandle *iff 

APTR buf 

Function: Reads the given number of bytes from IFFHandle to the 

buffer.

Parameters: iff 

IFFHandle 

buf

Read buffer 

size

Number of bytes 

Result: Number of bytes read or negative (-error code). 

1 ReadChunkRecords Read structures of the current chunk | 

Call: actual =  ReadChunkRecords (iff, buf, recsize, numrec) 

dO -72 (A6) aO al dO dl

LONG actual, recsize, numrec 

STRUCT IFFHandle *iff 

APTR buf 

Function: Reads numrec structures of length recsize to the buffer. 

Parameters: iff IFFHandle 

buf Read buffer recsize Size of structure numrec Number of structures

Result: Number or negative (-error code) 

I WriteChunkBy tes Write to the current chunk | 

Call: error =  WriteChunkBytes (iff, buf, size) 

dO -66 (A6) aO al dO

Function: Writes size bytes to the current chunk. 

Parameters: iff IFFHandle 

buf Write buffer size Buffer size

Result: Number of written bytes or negative (-error code). 

| WriteChunkRecords Write data structures to chunk | 

COll: error =  WriteChunkRecords (iff, buf, recsize, numrec) 

dO -78 (A6) aO al dO dl

LONG error, recsize, numrec 

STRUCT IFFHandle *iff 

APTR buf 

Function: Writes numrec structures of size recsize to the current 

chunk.

Parameters: iff IFFHandle 

buf Buffer recsize Structure size numrec Number of structures
Result: Number or negative (-error code) 

Deo Hex STRUCTURE IFFHandle, 0 

0 $0 ULONG iff_Stream 

4 $4 ULONG iff_Flags 

8 $8 LONG iff_Depth  stack depth 

12 $C LABEL iff_SIZEOF not end of structure!!! 

if f_Flags :

IFFF_READ =  0 read 

IFFF_WRITE =  1  write 

IFFF_FSEEK =  2 /forward only 

IFFF_RSEEK =  4 any direction 

IFFF_RESERVED =  $FFFF0000  important system bits 

Dec Hex STRUCTURE ClipboardHandle, iocr_SIZEOF   cbh_Reg 

52 $34 STRUCT cbh_CBport,MP_SIZE 

86 $56 STRUCT cbh_SatisfyPort,MP_SIZE 

120 $78 LABEL cbh_SIZEOF 

IFFERR_EOF =   -1 end of file 

IFFERR_EOC =   -2 end of context 

IFFERR_NOSCOPE 

= 

-3 

.•invalid values for PROPs 

IFFERR_NOMEM 

= 

-4 

no free memory

IFFERR_READ 

= 

-5 

read error

IFFERR_WRITE 

= 

-6 

write error

IFFERR_SEEK 

= 

-7 

seek error

IFFERR_MANGLED 

= 

-8 

/defective data in file 

IFFERR_SYNTAX 

= 

-9 

 IFF syntax error 

IFFERR_NOTIFF 

= 

-10 

not an IFF file

IFFERR_NOHOOK 

= 

-11 

no Hook

IFF_RETURN2CLIENT 

= 

-12 

return to program

ID_FORM =  "FORM' 

ID_LIST =  "LIST' 

ID_CAT =  "CAT * 

ID_PROP =  'PROP' 

ID_NULL =  ' 

IFFPARSE_SCAN =  0 

IFFPARSE_STEP =  1 

IFFPARSE_RAWSTEP =  2 

2. Context 

[CurrentChunk ContextNode of the current chunk! 

Call: top =  CurrentChunk (iff) 

dO -174 (A6) aO

STRUCT ContextNode *top 

STRUCT IFFHandle *iff 

Function: Returns the current ContextNode of the IFFHandle. 

Parameters: iff IFFHandle 

Result: ContextNode or 0 

[FindCollection Get Collectionltem list] 

Call: ci =  FindCollection (iff, type, id) 

dO -162 (A6) aO dO dl

STRUCT Collectionltem *ci 

STRUCT IFFHandle *iff 

LONG type , id 

Function: Gets the address of a  list of Collectionltem structures of the 

given chunk type.

Parameters: iff 

type id

IFFHandle 

Type 

ID 

Result: 

Address of the last collection chunk. 

IFindProp 

Find StoredProperty for a  context | 

Call: 

sp =  FindProp (iff, type, id) dO -156 (A6) aO dO dl

STRUCT StoredProperty *sp 

STRUCT IFFHandle *iff 

LONG type, id 

Function: Finds the StoredProperty structure set with PropChunk() or 

PropChunks(), which was automatically created by 

ParseIFF(). 

Parameters: iff 

type id

IFFHandle 

FORM type (for example "ILBM") 

ChunkID (for example "CMAP") 

Result: StoredProperty or 0 

IFindPropContext 

Find ContextNode of the Stored Property | 

Call: en =  FindPropContext (iff) 

dO -168 (A6) aO

STRUCT ContextNode *cn 

STRUCT IFFHandle *iff 

Function: Retrieves the ContextNode, which is contained as the 

highest level of the current position, for example "FORM".

Parameters: iff IFFHandle 

Result: ContextNode 

| ParentChunk Get the ContextNode of the next higher level I 

Call: parent =  ParentChunk (en) 

dO -180 (A6) aO

STRUCT ContextNode *parent, *cn 

Function: Gets the ContextNode of the next highest level, for 

example "FORM", from the ContextNode of a  chunk.

Parameters: en ContextNode for which parent node is sought. 

Result: ContextNode or 0 

| PopChunk Get ContextNode from context stack | 

Call: error =  PopChunk (iff) 

dO -90 (A6) aO

LONG error 

STRUCT IFFHandle *iff 

Function: Gets the next context chunk from the stack and frees all 

Localltems. 

Parameters: iff IFFHandle 

Result: 0  or error code 

| PushChunk Move ContextNode to the context stack | 

Call: error =  PushChunk (iff, type, id, size) 

dO -84 (A6) aO dO dl d2

LONG error 

STRUCT IFFHandle *iff 

LONG type, id, size 

Function: Places a  new ContextNode from DFFStream on the context 

stack.

Parameters. 

iff

IFFHandle 

type

Type (e.g. "ILBM") 

id

ID (e.g. "CMAP") 

size

Chunk size or IFFSIZE_UNKNOWN 

Result: 

0 or error 

code

Dec Hex STRUCTURE ContextNode, MLN_SIZE cn_Node 

8 $8 LONG cn_ID ChunkID 

12 $C LONG cnJType FORM type 

16 $10 LONG cn_Size Chunk size 

20 $14 LONG cn_Scan byte offset 

24 $18 LABEL cn_SIZEOF not end of structure!!! 

3. Handlers 

[CoIlectionChunk Declare a  CollectionChunkl 

Call: error =  CoIlectionChunk (iff, type, id) 

dO -138 (A6) aO dO dl

LONG error , type , id 

STRUCT IFFHandle *iff 

Function: Declares a  chunk to be a  collection chunk and installs a 

handler that is activated when the chunk is accessed.

Parameters: iff IFFHandle (must not be open) 

type Type (such as "ILBM") id ID (such as "CRNG")

Result: 0  or error code 

| CollectionChunks Declare CollectionChunksl 

Call: error =  CollectionChunks (iff, list, n) 

dO -144 (A6) aO al dO

LONG error , n 

STRUCT IFFHandle *iff 

APTR list 

Function: CollectionChunk() for several chunk types. The list is a 

field of two longwords: type, ID.

Parameters: iff IFFHandle 

list Field with types and IDs n Number of list entries

Result: 0  or error code 

lEntryHandler Link handler to context |

Call: error =  EntryHandler (iff, type, id, position, hook, object) 

dO -102 (A6) aO dO dl d2 al a2

LONG error, type, id, posit ion 

STRUCT IFFHandle *iff 

STRUCT Hook *hook 

APTR ob j ect 

Function: Installs hook for a  chunk type. The hook routine is called 

for every new chunk of the given type.

Parameters: iff IFFHandle 

type Typ (such as "ILBM") id ID(suchas"CMAP") position IFFSLI_... hook Hook structure with handler routine object User data (hook routine: A2)
Result: 0  or error code 

|ExitHandler Install chunk exit handler! 

Call: error =  ExitHandler (iff, type, id, position, hook, object) 

dO -10B(A6) aO dO dl d2 al a2

Functions, Parameters, Results: 

Same as EntryHandler(), except that this routine is called 

prior to removing a  chunk.

IPropChunk Declare a  Stored Property chunk | 

Call: error =  PropChunk (iff, type, id) 

dO -114 (A6) aO dO dl

LONG error , type , id 

STRUCT IFFHandle *iff 

Function: Installs a  handler for chunks of the given type. 

Parameters: iff IFFHandle (does not have to be open) 

type Type (such as "ILBM") id ID (such as "CMAP")

Result: 0  or error code 

IPropChunks Declare chunks as PropChunks| 

Call: error =  PropChunks (iff, list, n) 

dO -120 (A6) aO al dO

LONG error.n 

STRUCT IFFHandle *iff 

APTR list 

Function: PropChunk() for several chunks. The list parameter is a  field 

with two longwords: type and ID.

Parameters: iff IFFHandle 

list List with type, ID n Number of chunks

Result: 0  or error code 

I StopChunk Declare StopChunk I 

Call: error =  StopChunk (iff, type, id) 

dO -126 (A6) aO dO dl

LONG error , type , id 

STRUCT IFFHandle *iff 

Function: Declares a  chunk to be a  StopChunk, which stops 

ParseIFF() when encountered (IFFPARSE_SCAN-Modus). 

Parameters: iff IFFHandle 

type Type (such as "ILBM") id ID (such as "BODY")

Result: 0  or error code 

IStopChunks Declare StopChunksl 

Call: error =  StopChunks (iff, list, n) 

dO -132 (A6) aO al dO

LONG error , n 

STRUCT IFFHandle *iff 

APTR list 

Function: Several StopChunk() calls (like PropChunks() etc.). 

Parameters: iff IFFHandle 

list Field with type, ID n Number of chunks

Result: 0  or error code 

IStopOnExit Stop after chunk] 

Call: error =  StopOnExit (iff, type, id) 

dO -150 (A6) aO dO dl

LONG error , type , id 

STRUCT IFFHandle *iff 

Function: Stops ParseIFF() in scan mode after the given chunk is 

processed.

Parameters: iff IFFHandle 

type Type (such as "BLBM") id ID (such as "BODY")

Result: 0  or error code 

Dec Hex STRUCTURE IFFStreamCmd, 0 

0 $0 LONG isc_Command IFFCMD_... 

4 $4 APTR isc_Buf data buffer 

8 $8 LONG isc_NBytes  number of bytes 

12 $C LABEL isc_SIZEOF 

Dec Hex STRUCTURE StoredProperty, 0 

0 $0 LONG spr_Size 

4 $4 APTR spr_Data 

8 $8 LABEL spr_SIZEOF 

Dec Hex STRUCTURE Collectionltem, 0 

0 $0 APTR cit_Next 

4 $4 LONG cit_Size 

8 $8 APTR cit_Data 

12 $C LABEL cit_SIZEOF 

IFFCMD_INIT =  0  initialization 

IFFCMD_CLEANUP =  1 end 

IFFCMD_READ =  2 ,-read 

IFFCMD_WRITE =  3  write 

IFFCMD_SEEK =  4 seek 

IFFCMD_ENTRY =  5 new Context 

IFFCMD_EXIT =  6 exit Context 

IFFCMD_PURGELCI =  7  f ree LocalContextltem 

4. Local Contextltems 

[AllocLocalltem Allocate a  LocalContextltem | 

Call: item =  AllocLocalltem (type, id, ident, usize) 

dO -186 (A6) dO dl d2 d3

STRUCT LocalContextltem *item 

LONG type, id, ident, usize 

Function: Allocates and initializes a  LocalContextltem structure for 

the given amount of user data.

Parameters: type,id Type, ID 

ident Contextltem type usize Size of user data buffer

Result: LocalContextltem or 0 

FindLocalltem Get LocalContextltem from the context stack | 

Call: lei =  FindLocalltem (iff, type, id, ident) 

dO -210 (A6) aO dO dl d2

STRUCT LocalContextltem *lci 

STRUCT IFFHandle *iff 

LONG type, id, ident 

Function: Searches the context stack for the given 

LocalContextltem. 

Parameters: iff 

IFFHandle 

type

Type 

id

ID 

ident Item type (such as "exhd" =  ExitHandler)

Result: LocalContextltem or 0 

| FreeLocalltem Free a  LocalContextltem | 

Call: FreeLocalltem (lei) 

-204 (A6) aO 

STRUCT LocalContextltem *lci 

Function: Frees the memory of a  LocalContextltem allocated with 

AllocLocalItem().

Parameters: lei LocalContextltem from AllocLocalItem(). 

| LocalltemData Get address of the user data | 

Call: data =  LocalltemData (lei) 

dO -192 (A6) aO

APTR data 

STRUCT LocalContextltem *lci 

Function: Returns the address of the user buffer of an LCI. 

Parameters: lei LocalContextltem or 0 

Result: Data address or 0 

| SetLocalltemPurge Install purge handler | 

Call: SetLocalltemPurge (item, purgehook) 

-198 (A6) aO al 

STRUCT LocalContextltem *item 

STRUCT Hook *purgehook 

Function: Installs a   purge handler in an LCI (A0=Hook, 

A1=*IFFCMD_PURGELCI, A2=LCI). 

Parameters: item LocalContextltem 

purgehook

Hook with purge routine. 

[StoreltemlnContext Store LCI in ContextNodel 

Call: StoreltemlnContext (iff, item, en) 

-222 (A6) aO al a2 

STRUCT IFFHandle *iff 

STRUCT LocalCohtextltem *item 

STRUCT ContextNode *cn 

Function: Adds a  LocalContextltem to a  ContextNode's list. 

Parameters: iff IFFHandle 

item LocalContextltem en ContextNode

| StoreLocalltem Store LCI on the context stack! 

Call: error =  StoreLocalltem (iff, item, position) 

dO -216 (A6) aO al dO

LONG error, position 

STRUCT IFFHandle *iff 

STRUCT LocalContextltem *item 

Function: Add LCI to a  ContextNode's list. 

Parameters: iff IFFHandle 

item LocalContextltem position IFFSLI_ROOT, EFFSLIJTOP, or IFFSLI_PROP
Result: 0  or error code 

Dec Hex STRUCTURE LocalContextltem, MLN_SIZE   lci_Node 

8 $8 ULONG lci_ID 

12 $C ULONG lci_Type 

16 $10 ULONG lci_Ident 

20 $14 LABEL lci_SIZEOF not end of structure!!! 

IFFLCI_PROP =  'prop' 

IFFLCI_COLLECTION =  'coll' 

IFFLCI_ENTRYHANDLER =  'enhd' 

IFFLCI_EXITHANDLER =  'exhd' 

IFFSLI_ROOT =  1 LCI in previously set Context 

IFFSLIJTOP =  2 LCI in current Context 

IFFSLI_PROP =  3 LCI in FORM or LIST 

IFFSIZE_UNKNOWN =  -1 

