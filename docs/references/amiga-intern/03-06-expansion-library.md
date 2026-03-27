# The Expansion Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.6 The Expansion Library

The Expansion library, called "expansion.library" with the OpenLibraryO function, manages hardware and software expansions and the configuration of the strap routines (for booting). As always, the base address must be passed in A6.

Functions of the Expansion Library 

AddBootNode 

AddConfigDev 

AddDosNode 

AllocConfigDev AllocExpansionMem

FindConfigDev 

FreeConfigDev 

FreeExpansionMem 

GetCurrentBinding 

MakeDosNode 

ObtainConfigBinding 

ReleaseConfigBinding 

RemConfigDev 

SetCurrentBinding 

Description of the Routines 

|AddBootNode Add a  bootable device | 

Call: ok =  AddBootNode (  bootPri, flags, deviceNode, configDev ) 

DO -36 (A6) DO Dl AO Al 

BOOL ok 

BYTE bootPri 

ULONG flags 

STRUCT DeviceNode *deviceNode 

STRUCT ConfigDev *configDev 

Function: A  logical AutoBoot device is added to the DOS list. If DOS 

does not exist yet, the data is stored in a  buffer.

Parameters, Results: 

See AddDosNode(), the only difference is that an 

AutoBoot requires a  ConfigDev structure. 

| AddConfigDev Adda ConfigDev structure | 

Call: AddConfigDev (   configDev ) 

-30 (A6) A0 

STRUCT ConfigDev *configDev 

Function: Adds the given ConfigDev structure to the system list. 

Parameters: configDev Initialized ConfigDev structure 

See also: RemConfigDev() 

|AddDosNode Mounts a  data storage device | 

Call: ok =  AddDosNode( bootPri, flags, deviceNode ) 

DO -150 (A6) DO Dl A0 

BOOL ok 

BYTE bootPri 

ULONG flags 

STRUCT DeviceNode *deviceNode 

Function: Adds a  filesystem device to the system list. If DOS is not 

active yet, the information is stored in a  buffer. If no handler is given, the new filesystem automatically takes over the management.

Parameters: bootPri AutoBoot priority (127 to -128). Only works if 

the corresponding ConfigDev structure is in the system list. flags ADNF_STARTPROC (bit 0) start handler immediately. deviceNode

Initialized DOS device node. 

## 3.1 The Libraries and their Functions

Result: 0  Error 

See also: MakeDosNode(), AddBootNode() 

Example: Add a  bootable drive to the system and activate a 

FileHandler: 

movea.l _ExpansionBase,a6 lea _Parms(pc) ,a0 jsr _LVOMakeDosNode(a6) tst.l dO beq _Error movea .1 dO , aO moveq #0 , dO moveq #ADNF_STARTPROC , dl j sr _LVOAddDosNode ( a6 )

.DosNode 

del

.Parms 

del

_DOSname , _E: 

del

1,0 

del del del

0,2 

del

1,11 

del

2,0,0 

del

0,79 

del

5,MEMF_CHIP 

del

$7fffffff 

del

$fffffffe 

del deb

1 DOS ' , 0 

.DOSname 

deb

■dfl',0 

Unit, Flags 

Tablesize 

Longwords per block 

/sector location, heads 

sectors per block, blocks per track boot blocks, unused, interleave first and last cylinders number of buffers, memory type maximum transfer rate mask boot priority

FileSystem type 

_ExecName 

deb ' trackdisk. device' ,  0

1 AHocConfigDev Allocate a  ConfigDev structure | 

Call: configDev =  AHocConfigDev () 

DO -48 (A6) 

Function: Allocates a  deleted ConfigDev structure. 

Result: ConfigDev structure or 0. 

See also: FreeConfigDev() 

|AllocExpansionMem Allocate expansion memory | 

Call: startSlot =  AllocExpansionMem( numSlots, slotOffset ) 

DO -54 (A6) DO Dl 

Function: Allocates the given number of slots. 

Parameters: numSlots Number of slots required. 

slotOffset Memory location
Result: First slot number or - 1 . 

See also: FreeExpansionMemQ 

IFindConfigDev Find appropriate ConfigDev 

LsClil* configDev =  FindConfigDev{ oldConfigDev, manufacturer, product ) 

DO -72 (A6) A0 DO Dl 

STRUCT ConfigDev *configDev, 'oldConfigDev 

LONG manufacturer , product 

Function: Finds a  ConfigDev structure that fits the given description. 

In order to be able to test several ConfigDev structures, the previously retrieved ConfigDev can be specified. Values of
-1 will accept every manufacturer code and every product 

ID. 

Parameters: oldConfigDev 

Last result or 0  (start of list) 

manufacturer

Manufacturer's code or -1 

product Product ID or - 1

Result: The next appropriate ConfigDev structure or 0. 

IFreeConfigDev Free a  ConfigDev structure] 

Call: FreeConfigDev( configDev ) 

-84 (A6) A0 

STRUCT ConfigDev *configDev 

Function: Frees a  structure allocated with AllocConfigDev(). 

Parameters: configDev ConfigDev structure 

See also: AllocConfigDevQ 

IFreeExpansionMem Free memory 

Call: FreeExpansionMem( startSlot, numSlots ) 

-90 (A6) DO Dl 

Function: Frees memory allocated with AllocExpansionMem(). 

Parameters: Same as with AllocExpansionMem(). 

See also: AllocExpansionMem() 

| GetCurrentBinding Gets a  copy of CurrentBinding | 

Call: actual =  GetCurrentBinding (  CurrentBinding, size ) 

DO -138 (A6) A0 DO: 16 

Function: Copies the contents of the CurrentBinding structure to the 

given buffer.

Parameters: CurrentBinding 

CurrentBinding structure 

size Structure size

Result: The true size of the CurrentBinding structure 

See also: SetCurrentBindingO 

IMakeDosNode 

Create a  DosList entry | 

Call: 

Function: 

deviceNode =  MakeDosNode ( parameter Pkt )
DO -144 (A6) AO 

STRUCT DeviceNode *deviceNode 

APTR parameterPkt 

Creates all of the data structures required to add a  device 

with AddDosNodeQ.

Parameters: parameterPkt 

Longword field with all the required 

information:

Device name (DOS, for example "dfl"), device 

name (Exec, for example "trackdisk.device"), unit number, flags for OpenDevice(), number of following longwords, environment table for the
FileHandler. 

Result: 

See also: 

Example: 

movea.l _ExpansionBase,a6 lea _Parms (pc) , aO j sr _LVOMakeDosNode ( a 6 ) move . 1  dO , _DosNode

Initialized structure or 0. 

AddDosNodeO 

Create a  DosNode for a  3.5" drive as "DF1:": 

_DosNode 

del 0

_Parms 

dc . 1 _DOSname , _ExecName del 1,0 Unit, Flags

del 16 Table size del 128 Longwords per block del 0,2  sector location, heads del 1,11  sectors per block, blocks per track del 2,0,0 boot blocks, unused, interleave del 0,79  first and last cylinders del 5,MEMF_CHIP  number of buffers, memory type

del $7fffffff .-maximum transfer rate 

del $fffffffe mask 

del 0  boot priority deb 'DOS',0 FileSystem type

_D0Sname 

deb 'dfl',0

_ExecName 

deb '  trackdisk. device1 ,  0

[ObtainConfigBinding Enable configuration binding | 

Call: ObtainConfigBinding ( ) 

-120 (A6) 

Function: Obtains the approval to add drivers to ConfigDev 

structures.

See also: ReleaseConfigBindingO 

[ReleaseConfigBinding Release configuration binding | 

Call: ReleaseConfigBindingO 

-126(A6) 

Function: Allows access by other programs. 

See also: ObtainConfigBindingO 

| RemConfigDev Remove a  ConfigDev from the system list | 

Call: RemConfigDev ( configDev ) 

-108 (A6) A0 

Function: Removes the given ConfigDev structure from the system 

list.

Parameters: configDev ConfigDev structure 

See also: AddConfigDev() 

| SetCurrentBinding 

Set CurrentBinding] 

Call: SetCurrentBinding) currentBinding, size ) 

-132 (A6) AO D0:16 

Function: Copies the contents of the given buffer to the system's 

CurrentBinding structure. 

Parameters: currentBinding 

Buffer with the new contents for the 

CurrentBinding structure. 

size

Buffer size 

See also: GetCurrentBindingO 

ADNB_STARTPROC=0, ADNF_STARTPROC=l /start Handler immediately 

Dec Hex STRUCTURE BootNode, LN_SIZE boot node 

14 $E UWORD bn_Flags  Flags 

16 $10 APTR bn_DeviceNode DosList 

20 $14 LABEL BootNode_SIZEOF 

Dec Hex STRUCTURE ExpansionBase, LIB_SIZE  library 

34 $22 UBYTE eb_Flags 

35 $23 UBYTE eb_Private01 

36 $24 ULONG eb_Private02 

40 $28 ULONG eb_Private03 

44 $2C STRUCT eb_Private04, CurrentBinding_SIZEOF 

60 $3C STRUCT eb_Private05, LH_SIZE 

74 $3A STRUCT eb_MountList, LH_SIZE  BootNodes 

. . . more private data. . . 

readable private private
/private 

/private 

/private 

private

EE_OK 

EE_LASTBOARD 

EE_NOEXPANSION 

EE_NOMEMORY 

EE_NOBOARD 

EE_BADMEM 

= 0  /no errors 

=40 /cannot be closed 

=41 /not enough memory 

= 42 /no normal memory free 

= 43 /no board available 

= 44 /defective memory 

EBB_CLOGGED 

0, 

EBF_CLOGGED 

= 1 

close error

EBB_SHORTMEM 

= 

1, 

EBF_SHORTMEM 

= 2 

less memory

EBB_BADMEM 

= 

2, 

EBF_BADMEM 

= 4 

.•defective memory 

EBB_DOSFLAG 

= 

3, 

EBF_DOSFLAG 

= 8 

,-for AmigaDOS 

EBB_KICKBACK33 

= 

4, 

EBF_KICKBACK33 

= 16 

OS change (DOS) 

EBB_KICKBACK36 

= 

5, 

EBF_KICKBACK3 6 

= 32 

OS change (DOS) 

