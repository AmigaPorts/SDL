# The DOS Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.4 The DOS Library

The DOS Library is completely new and expanded for Kickstart Version
2.0. The DOS Library was written in the compiler language BCPL for the 

old 1.x versions. This slow-executing language was replaced with faster
C code, but in order to maintain compatibility, the BCPL variable 

management had to be kept for the most part. BCPL manages addresses in numbers of longwords (32 bits =  4 bytes), so the address 40 would be assigned the number 10 in BCPL. This is why every address must be divisible by 4. An important change came with the transition to C. Starting with OS 2.0,
DOS expects the base address of the DOS Library to be passed in register 

A6. This prevents the use of faster code by placing the base address in 

A5. Programs that utilize this will crash under Kickstart 2.0. 

Functions of the DOS Library 

1. DOS Structures UnLockDosList 

AllocDosObject

DupLock 

DupLockFromFH 

FreeDosEntry 

FreeDosObject 

MakeDosEntry 

2. Logical Devices 

AddDosEntry 

AssignAdd 

AssignLate 

AssignLock 

AssignPath 

AttemptLockDosList 

FindDosEntry 

LockDosList 

NextDosEntry 

RemDosEntry 

3. Handlers and Filesystems 

AddBuffers 

DeviceProc 

DoPkt 

EndNotify 

Format

FreeDeviceProc 

GetConsoleTask 

GetDeviceProc 

GetFileSysTask 

Inhibit 

IsFileSystem 

Relabel 

ReplyPkt 

SendPkt 

SetConsoleTask 

SetFileSysTask 

StartNotify 

WaitPkt 

Readltem 

Selectlnput 

4. Directories 

SelectOutput 

SetArgStr 

CreateDir 

SetCurrentDirName 

CurrentDir 

SetProgramDir 

ExAll 

SetProgramName 

Examine 

SetPrompt 

ExNext 

SystemTagList 

GetProgramDir 

VPrintf 

Info 

MatchEnd 

7. Files 

MatchFirst 

MatchNext 

ChangeMode 

ParentDir 

Close 

ParentOfFH 

DeleteFile 

ExamineFH 

5. Programs 

FGetC 

Flush 

AddSegment 

FPutC 

CreateNewProc 

FRead 

CreateProc 

FWrite 

Exit 

Islnteractive 

FindSegment 

Lock 

InternalLoadSeg 

LockRecord 

InternalUnLoadSeg 

LockRecords 

LoadSeg 

Open 

NewLoadSeg 

OpenFromLock 

RemSegment 

Read 

RunCommand 

Rename 

UnLoadSeg 

SameLock 

Seek 

6.CU 

SetComment 

CheckSignal 

Cli 

SetFileDate 

SetFileSize 

Execute 

SetProtection 

FindCliProc 

UnGetC 

Input 

UnLock 

MaxCli 

UnLockRecord 

Output 

UnLockRecords 

Pao/1 Arno 

VFPrintf 

## 3.1 The Libraries and their Functions

VFWritef 

Write 

5. Strings 

AddPart 

DateToStr 

Fault 

FGets 

FilePart 

FindArg 

FPuts 

GetArgStr 

GetCurrentDirName 

GetProgramName 

GetPrompt 

MatchPattern 

NameFromFH 

NameFromLock 

ParsePattern 

PathPart 

SplitName 

Description of Functions 

1. DOS Structures 

StrToDate 

StrToLong 

9. Time 

CompareDates 

DateStamp 

Delay 

WaitForChar 

10. Environment Variables 

DeleteVar 

FindVar 

GetVar 

SetVar 

11. Errors and Requesters 

ErrorReport 

IoErr 

PrintFault 

PutStr 

SetloErr 

lAllocDosObject

Create DOS data structure 

Call: ptr =  AllocDosObject (type, tags) 

DO -228 (A6) Dl D2 

APTR ptr 

ULONG type 

STRUCT Tagltem *tags 

Function: Creates one of several possible DOS structures. 

Parameters: type Structure type 

tags TagList address

Result: Data structure address or 0. 

See also: FreeDosObject(), dos/dostags.h, dos/dos.h 

Example: Creating a  control structure for calling the new ExAll() 

function: movea . 1 _DosBase , a 6 moveq #DOS_EXALLCONTROL,dl move . 1 #_Dummy,d2 save it jsr _LVOAllocDosObject (a6) move.l dO,_ExAHControl beq _Error

_Dummy dc . 1 TAG_DONE 

empty Tagltem field

|DupLock 

Copy lock] 

Call: newlock =  DupLock( lock ) 

DO -96 (A6) Dl 

BPTR newlock 

BPTR lock 

Function: Copy a  Filesystem SHAREDJLOCK. 

Parameters: lock Lock to be copied. 

Result: Copy of the lock or 0. 

See also: LockQ, UnLockQ 

IDupLockFromFH 

Copy a  FileHandle lock| 

Call: 

lock =  DupLockFromFH(fh)
DO -372 (A6) Dl 

BPTR lock 

BPTR fh 

Function: 

Returns a  copy of a  FileHandle lock. The file must be open 

and accessible to other programs.

Parameters: fh FileHandle that owns the lock to be copied. 

Result: Lock or 0, in the case of an error. 

IFreeDosEntry Free a  structure created with MakeDosEntryQl 

Call: FreeDosEntry (dlist) 

-702 (A6) Dl 

STRUCT DosList *dlist 

Function: Frees the result of a  MakeDosEntryO call. This routine 

should not be used. Instead, use FreeDosObject() with the corresponding value.

Parameters: dlist DosList structure to be freed. 

FreeDosObject Free a  DOS structure] 

Call: FreeDosObject (type, ptr) 

-234 (A6) Dl D2 

ULONG type 

APTR ptr 

Function: Frees a  structure created with AllocDosObject(). 

Parameters: type Type as specified with AllocDosObject(). 

ptr Result of AllocDosObject().

See also: AllocDosObject(), dos/dos.h 

Example: Free an ExAU() control structure: 

movea . 1 _DosBase , a 6 moveq #DOS_EXALLCONTROL,dl move . 1 _ExAl IControl , d2 jsr _LVOFreeDosObject (a6)

| MakeDosEntry Create a  DosList structure | 

Call: newdlist =  MakeDosEntry (name, type) 

DO -696 (A6) Dl D2 

STRUCT DosList *newdlist 

APTR name 

LONG type 

Function: Creates a  DosList structure with BSTR dol_Name and 

dol_Type. This function should not be used. Instead, use
AUocDosObject(). 

Parameters: name Name of the device/volume/assign node. 

type Entry type

Result: DosList structure or 0. 

Type for AllocDosObject(): 

DOS_FILEHANDLE 

= 0 

FileHandle 

DOS_EXALLCONTROL 

= 1 

ExAllControl 

DOS_FIB 

= 2 

FileInfoBlock 

DOS_STDPKT 

= 3 

 Standard Packet 

DOS_CLI 

= 4 

CommandLineInterface 

DOS_RDARGS 

= 5 

in case arguments were entered

Tags for AllocDosObject(): 

ADO_Dummy =  TAG_USER+2000 

ADO_FH_Mode =  ADO_Dummy+l  f or FileHandle only 

ADO_DirLen =  ADO_Dummy+2 size of CurrentDir buffer 

ADO_CommNameLen =  ADO_Dummy+3 size of CommandName buffer 

ADO_CommFileLen =  ADO_Dummy+4 size of BatchFile buffer 

ADO_PromptLen =  ADO_Dummy+5 size of Prompt buffer 

2. Logical Devices 

| AddDosEntry Add an entry to the list of logical devices | 

Call: success =  AddDosEntry (dlist) 

DO -678 (A6) Dl 

BOOL success 

STRUCT DosList *dlist 

Function: Adds a  device, volume, or assign node to the DOS list of 

logical devices. If a  logical device of the same name already exists, the function will fail. Exceptions to this are volumes nodes with different dates and DeviceNode names. This function can be called without a  lock on the device list.

Parameters: dlist 

Result: 0 

Entry for the device list. 

Error 

| Assign Add 

Add a  path to a  directory with many paths! 

Call: success =  AssignAdd (name, lock) 

DO -630 (A6) Dl D2 

BOOL success 

APTR name 

BPTR lock 

Function: Sets a  lock on a  directory in an assign list. The assign 

structure must be created with AssignLock() or
AssignLate(), and the lock may not be used again after this. 

If you need it, you can create another copy with
DupLockQ. 

Parameters: name 

Result: 

See also: 

Example: 

lock

DeviceName without ':' 

Lock indicated by the name. 

Error, then the lock must be freed with 

UnLockQ. 

AssignLock(), AssignLate(), Lock(), UnLock() 

This allows you to define a  logical device, such as 'C:' or
'DEVS:' that consists of several physical directories. 

Consider the following two directories: 

Strings: (DIR) 

GibsonGuitar . 8SVX 

RichGuitar.8SVX 

WarwickBass . 8SVX 

WashburnGuitar . 8SVX 

Drumkit: (DIR) 

PaisteCymbal . 8SVX 

PaisteGong.8SVX 

PearlDrum.8SVX 

PremierDrum . 8SVX 

We can assign these two directories to the logical device 'Samples:' as 

follows:

.MultiPath 

movea . 1

_DosBase, a6 

move . 1

#_BasePath,dl 

moveq

#SHARED_L0CK,d2 

jsr

_LV0Lock(a6) 

Lock( "Strings: " , -2) 

move . 1 d0,d2 beq. s

. Error 

move . 1

#_Samples,dl 

jsr

_LVOAss ignLock ( a6 ) 

AssignLock( "Samples 

' , Lock) 

tst.l dO beq.s

. Error2 

move . 1

#_AddPath,dl 

moveq

#SHARED_LOCK, d2 

jsr

_LV0Lock(a6) 

Lock( "Drumkit : " , -2) 

move . 1 d0,d2 beq.s

. Error3 

move . 1

jsr

_LV0AssignAdd(a6) 

AssignAdd( "Samples

Lock) 

tst.l dO beq.s

. Error4 

moveq

#0,d0 

rts

Error4 

Error2 

move . 1 d2,dl jsr

_LV0Unlock(a6) 

Errorl 

moveq

#-l,dO 

Error3 

rts

_BasePath dc.b 'Strings: ',0 

_AddPath dc .b '  Drurnkit : '  , 0 

_Samples dc . b ' Samples • , 0 

If no errors occurred (result=0), you can access these files as follows:

" Samples :WarwickBass . 8SVX
"Samples : PaisteCymbal . 8SVX

If you were to store a  file in the logical device 'Samples', it would go to the physical directory set with AssignLock(). In this case, this is
"Strings:". 

lAssignLate Pre-define an AssignLock]

Call: success =  AssignLate (name, path) 

DO -618 (A6) Dl D2 

BOOL success 

APTR name 

APTR path 

Function: Defines an AssignLock that is only created after the first 

access on the given path. This is very helpful in cases where a  device hasn't been activated yet.

Parameters: name DeviceName without ':' 

path Name used to address the device.

Result: 0  Error 

See also: AssignLock 

| AssignLock Assign a  name to a  lock| 

Call: success =  AssignLock (name, lock) 

DO -612 (A6) Dl D2 

BOOL success 

APTR name 

BPTR lock 

Function: Assigns a  name to a  lock. A  value of 0  for lock will delete 

the entry with the given name. If an entry with the same name exists, it's replaced with the new lock. After this function, the lock may not be used again. If necessary, make a  copy with DupLock().

Parameters: name Device name (without ':') to which the lock is 

assigned. lock Lock for the name.

Result: 0  Error, lock must then be freed with UnLock(). 

See also: Lock(), DupLock(), UnLock() 

| AssignPath Assign a  name to a  path | 

Call: success =  AssignPath (name, path) 

DO -624 (A6) Dl D2 

BOOL success 

APTR name 

APTR path 

Function: Assigns a  name to a  path. Also works with disks (volumes) 

that are not yet known.

Parameters: name Device name without ':' 

path Path name replaced by 'name'.

Result: 0  Error 

See also: AssignLock(), AssignLate() 

| AttemptLockDosList Lock a  directory list| 

Call: dlist =  AttemptLockDosList (flags) 

DO -666 (A6) Dl 

STRUCT DosList *dlist 

ULONG flags 

Function: Prevents certain access from other programs to the list of 

logical devices.

Parameters: flags Flags that indicate the nodes to be locked. 

Result: dlist Start of the list or 0  (no node address). 

See also: LockDosListQ, UnLockDosListQ 

IFindDosEntry 

Call: newdlist =  FindDosEntry (dlist, name, flags) 

DO -684 (A6) Dl D2 D3 

STRUCT DosList *newdlist, *dlist 

APTR name 

ULONG flags 

Function: Returns an entry from the list of logical devices. 

Parameters: dlist Starting entry for the search. 

name Device name without ':'. flags Flags previously passed to LockDosList().

Result: Address of the entry or 0. 

ILockDosList Allow access to list of logical devices | 

Call: dlist =  LockDosList (flags) 

DO -654 (A6) Dl 

STRUCT DosList *dlist 

ULONG flags 

Function: This function allows exclusive access to the list of logical 

devices. If another task has the access rights, the program waits until the list is freed with UnLockDosList(). You can use nested calls of this function.

Parameters: flags Entries to be accessed. 

Result: Pointer to the list header, not an entry. 

INextDosEntry Next entry in the logical device list| 

Call: newdlist =  NextDosEntry (dlist, flags) 

DO -690 (A6) Dl D2 

STRUCT DosList *newdlist , *dlist 

ULONG flags 

Function: Finds the next entry of the desired type in the logical 

device list.

Parameters: dlist Current entry. 

flags Type, see FindDosEntry().

Result: Next DosList structure or 0. 

| RemDosEntry Remove a  DosList structure from the list | 

Call: success =  RemDosEntry (dlist) 

DO -672 (A6) Dl 

bool success
STRUCT DosList *dlist 

Function: This function can be used to remove an entry from the 

logical device list. LockDosList() must be called first. The memory block used is not freed with this function.

Parameters: dlist DosList structure. 

Result: 0  Error 

|UnLockDosList Free logical device list! 

Call: UnLockDosList ( flags) 

-660 (A6) Dl 

ULONG flags 

Function: Frees a   logical device list that was locked with 

LockDosList(). 

Parameters: flags Flags that were specified with LockDosListQ. 

Dec 

Hex 

STRUCTU 

RE DosList, 0 

$0 

BPTR 

dol_Next next entry

$4 

LONG 

dol_Type type (see below)

$8 

APTR 

dol_Task

 Handler task 

$c 

BPTR 

dol_Lock

Lock 

$10 

LABEL 

dol_VolumeDate creation date

$10 

LABEL 

do l_As s i gnName path name

$10 

BSTR 

dol_Handler filename (if SegList=0)

$14 

LABEL 

dol_List

.•directory list (Assign) 

$14 

LONG 

dol_StackSize stack size for the process

$18 

LONG 

dol_Priority

,-priority of the process 

$1C 

LABEL 

dol_LockList available Locks

$1C 

ULONG 

dol_Startup

 FileSysStartupMsg 

$20 

LABEL 

dol_DiskType

 ' DOS ' , etc . 

$20 

BPTR 

dol_SegList

SegList for the process 

$24 

BPTR 

dol_GlobVec

BCPL global vector 

$28 

BSTR 

dol_Name name

$2C 

LABEL 

DosList_SIZEOF 

Values for dlType: 

DLT_DEVICE 

= 

logical device

DLT_DIRECTORY 

= 

As sign Node

DLT_VOLUME 

= 

/diskette 

DLT_LATE 

= 

late assignment

DLT_NONBINDING 

= 

free Assign (AssignPath)

DLT_PRIVATE 

= 

-1 

for DOS only

Flags for LockDosList() etc.: 

LDB_READ 

LDB_WRITE 

LDB_DEVICES 

LDB_VOLUMES 

LDB_ASSIGNS 

LDB_ENTRY 

LDB_DELETE 

= 0, LDF_READ 

= 1 

1, LDF_WRITE =   2 

2, LDF_DEVICES =   4 

3, LDF_VOLUMES =   8 

4, LDF_ASSIGNS =16 

5, LDF_ENTRY =32 

6, LDF_DELETE =64 

specify either LDF_READ or LDF_WRITE for internal purposes

LDF_ALL =  (LDF_DEVICES!LDF_VOLUMES!LDF_ASSIGNS) 

3. Handlers and Filesy stems 

| AddBuffers Add to the number of buffers for a  device | 

Call: success =  AddBuffers (filesystem, number) 

DO -732 (A6) Dl D2 

BOOL success 

APTR filesystem 

LONG number 

Function: Adds the given number of buffers to the existing number of 

buffers for a  filesystem, then sets the number of buffers to the new number. You may also use negative values. If the call was successful, you can query the current number of buffers with IoErr().

Parameters: filesystem *String with the device name, including ':'. 

number Number of buffers to add (may be positive or negative).

Result: 0  Error 

See also: IoErr() 

[DeviceProc Return the MsgPort for the handler of a  device I 

Call: process =  DeviceProc (  name ) 

DO -174 (A6) Dl 

STRUCT MsgPort *process 

APTR name 

Function: Returns the MessagePort that controls the given device. 

This is required for packet routines.

Parameters: name Device name 

Result: MsgPort of the handler process or 0. 

Warning: If you specify something that is only addressable as a 

device via ASSIGN, use the IoErr() function to get the lock associated with this name. You may only work with a  copy of the lock that was created with DupLock().

See also: DoPkt(), IoErr(), DupLock() 

1 DoPkt Send a  DOS packet and wait for the reply] 

Call: resultl (/result2) =  DoPkt(port,action,argl,arg2,arg3,arg4,arg5) 

DO (Dl) -240(A6) Dl D2 D3 D4 D5 D6 D7 

LONG resultl, result2 

STRUCT MsgPort *port 

LONG action, argl , arg2 , arg3 , arg4 , arg5 

Function: PutMsgO sends a  packet to the ProcessPort of the handler 

and waits for the handler to process it. Then resultl and result2 are taken from the returned packet. Since C programmers cannot use routines with two results, result2 is set up as an error code that can be queried with IoErr().

DoPkt() can also be called by an Exec task, but it will be 

slower and more prone to error.

Parameters: port pr_MsgPort of the handler. 

action Command for the handler or filesystem. argl, arg2, arg3, arg4,arg5

Arguments for the command. 

Result: 0  in DO =  error 

See also: DeviceProc(), IoErr(), PutMsgO, WaitPort(), GetMsgO 

lEndNotity End file notification!

Call: EndNotify (notifystructure) 

-894 (A6) Dl 

STRUCT NotifyRequest *notifystructure 

Function: Ends notification started with StartNotify(). 

Parameters: NotifyRequest that was passed to StartNotify(). 

Result: None 

See also: StartNotifyO 

| Format Format a  device | 

Call: success =  Format (filesystem, volumename, dostype) 

DO -714 (A6) Dl D2 D3 

BOOL success 

APTR filesystem, volumename 

ULONG dostype 

Function: Format a  device, such as a  diskette or a  hard disk. 

Parameters: filesystem Device name including ':'. 

volumename

Name, such as the diskette name. 

dostype Format type: OFS or FFS

Result: 0  Error 

FreeDeviceProc Free a  structure obtained with GetDeviceProcQI 

Call: FreeDeviceProc (devproc) 

-648 (A6) Dl 

STRUCT DevProc *devproc 

Function: Frees a  structure created with GetDeviceProc() and 

decrements the process counter.

Parameters: devproc DevProc structure from GetDeviceProcQ. 

IGetConsoleTask 

Get the MsgPort of the console handler 

Call: port =  GetConsoleTaskO 

DO -510 (A6) 

STRUCT MsgPort *port 

Function: Returns its own console task port (pr_ConsoleTask). 

Result: pr_MsgPort of the console handler or 0. 

| GetDeviceProc Get the handler for a  path | 

Call: devproc =  GetDeviceProc (name, devproc) 

DO -642 (A6) Dl D2 

STRUCT DevProc *devproc 

APTR name 

Function: Returns the handler or filesystem for a  path. You must 

supply the path name, which may be given relative to the current path, and a  value of 0  as the DevProc structure. The result is a  DevProc structure from which the data can be read. Kickstart 2.0 supports the division of a  directory into several devices, so more than one handler/filesystem may be responsible for the path. To get all of the data for a  path, GetDeviceProc() must be called several times, and the first structure returned must be passed with each subsequent call. If you receive an
ERROR_OBJECT_NOT_FOUND and if DVPF.ASSIGN is 

set in dvp_Flags, you must still call this function again. You will receive the DevProc structure with other values or with the value 0  and an ERROR_NO_MORE_ENTRIES from
IoErr(). The function must continue to be called until 0  is 

returned. Then the handler/filesystem will automatically be locked. The structure returned with the first call can be freed with FreeDeviceProc. At this point, all of the data retrieved becomes invalid and must not be used anymore.

Parameters: name 

Path name to be accessed. 

Result: 

IGetFileSysTasit 

devproc DevProc structure from previous call, or 0.
DevProc structure or null 

Get MsgPort of own filesystem] 

Call: port =  GetFileSysTaskO 

DO -522 (A6) 

STRUCT MsgPort *port 

Function: Reads the MsgPort of the filesystem from the process 

structure responsible for the program (pr_FileSystemTask).

Result: pr_MsgPort of the filesystem or 0. 

Send the DOS packet ACTION INHIBIT to a  handler] 

| Inhibit 

Call: 

success =  Inhibit (filesystem, flag)
DO -72 6 (A6) Dl D2 

BOOL success 

APTR name 

LONG flag 

Function: Simultaneous access to a  filesystem device must be locked 

before direct access is allowed (Workbench: DFx:BUSY).
Programmers who simply jump in and access the trackdisk 

device or the hard disk already had many system crashes and instances of destroyed data. Normally, you would use
DeviceProcO to get the handler port and then turn the 

filesystem off with an ACTIONJNHIBIT packet. This function was implemented to give programmers a  way to accomplish this.

Parameters: filesystem Device name including ':' 

flag Argument for the StdPacket:

DOSTRUE Inhibit (lock filesystem) 

Null Uninhibit (unlock filesystem) 

Result: 

Error 

lIsFileSystem

Determine if a  handler is a  filesystem| 

Call: result =  IsFileSystem(name) 

DO -708 (A6) Dl 

BOOL Result: APTR name 

Function: Returns a  boolean argument that indicates whether a 

handler is a  filesystem.

Parameters: name Device name including ':'. 

Result: 0  Handler is not a  filesystem. 

| Relabel 

Change name of a  storage device | 

Call: 

Function: 

Parameters: 

Result: 

success =  Relabel (volumename, name)
DO -720 (A6) Dl D2 

BOOL success 

APTR volumename, name 

Changes the name of a  storage device, such as a  diskette. 

volumename Device name including ':'. newname New name without ':'.

Error 

IReplyPkt 

Reply to a  DosPacket| 

Call: ReplyPkt (packet, resultl, result2) 

-258 (A6) Dl D2 D3 

STRUCT DosPacket *packet 

LONG resultl, result2 

Function: Places results in a  packet and returns it to the sender. 

Parameters: packet DosPacket structure. 

resultl ,result2

Results 

| SendPkt Send a  DosPacket to a  handler I 

Call: SendPkt (port, packet, replyport) 

-246 (A6) Dl D2 D3 

STRUCT MsgPort *port, *replyport 

STRUCT DosPacket *packet 

Function: Sends a  packet to a  handler without waiting for the reply. 

The reply is sent to the specified ReplyPort. This is the pr_MsgPort of its own process structure.

Parameters: port pr_MsgPort of the handler (see DeviceProcO). 

packet DosPacket structure to be sent. replyport pr_MsgPort of its own process.

ISetConsoleTask Set console handler port| 

Call: oldPort =  SetConsoleTask(port) 

DO -516 (A6) Dl 

STRUCT MsgPort *port, *OldPort 

Function: Sets the port for the standard console tasks of the 

processor (pr_ConsoleTask).

Parameters: port pr_MsgPort of the console handler. 

Result: Pointer to previous console task. 

| SetFileSysTask Set filesystem port | 

Call: oldPort =  SetFileSysTask (port) 

DO -528 (A6) Dl 

STRUCT MsgPort *port, *OldPort 

Function: Sets the port for the filesystem tasks of the process 

(prJFileSystemTask). 

Parameters: port pr_MsgPort of the filesystem. 

Result: Previous FileSysTask 

| StartNotify Start file notification | 

Call: success =  StartNotify (notifystructure) 

DO -888 (A6) Dl 

BOOL success 

STRUCT NotifyRequest *notifystructure 

Function: Begin notification for a  file or directory. You are then 

notified if a  change is made, as long as the filesystem supports this.

Parameters: notifystructure 

Initialized NotifyRequest structure. 

Result: 0  Error 

| WaitPkt Wait for a  DosPacket | 

Call: packet =  WaitPktO 

DO -252 (A6) 

STRUCT DosPacket *packet 

Function: Waits for a  DosPacket to appear in its own pr_MsgPort and 

picks up the StdPkt with GetMsg().

Result: packet DosPacket (LN_NAME of the message 

structure)

DosPacket Structure: 

Dec 

Hex 

STRUCTURE DosPacket, 0 

$0 

APTR 

dp_Link

-Exec message 

$4 

APTR 

dp_Port

•Reply Port 

$8 

LABEL 

dp_Action s. ACTION... .  .

$8 

LONG 

dp_Type

'R', 'W 

$C 

LABEL 

dp_Status

1st result: 

$c 

LONG 

dp_Resl

1st result 

$10 

LABEL 

dp_Status2

2nd result 

$10 

LONG 

dp_Res2

2nd result 

$14 

LABEL 

dp_BufAddr buffer address

$14 

LONG 

dp_Argl

1st argument 

$18 

LONG 

dp_Arg2

2nd argument 

$1C 

LONG 

dp_Arg3

3rd argument 

$20 

LONG 

dp_Arg4

4th argument 

$24 

LONG 

dp_Arg5

5th argument 

$28 

LONG 

dp_Arg6

6th argument 

$2C 

LONG 

dp_Arg7

7th argument 

$30 

LABEL 

dp_SIZEOF

Structure for sending Packets: 

Dec Hex STRUCTURE StandardPacket , 0 

0 $0 STRUCT sp_Msg,MN_SIZE Exec message 

20 $14 STRUCT sp_Pkt, dp_SIZEOF  Packet 

68 $44 LABEL sp_SIZEOF 

Packet Types: 

ACTION_NIL 

= 

no message

ACTION_STARTUP 

= 

 Handler startup 

ACTION_GET_BLOCK 

= 

DO NOT USE! 

ACTION_SET_MAP 

= 

set map

ACTION_DIE 

= 

end process

ACTION_EVENT 

= 

event

ACTION_CURRENT_VOLUME 

= 

current disk

ACTION_LOCATE_OBJECT 

= 

find object

ACTION_RENAME_DISK 

= 

rename disk

ACTION_WRITE 

= 

■w 

write

ACTION_READ 

= 

'R' 

read

ACTION_FREE_LOCK 

= 

free Lock

ACTION_DELETE_OBJECT 

= 

delete object

ACTION_RENAME_OBJECT 

= 

/rename object 

ACTION_MORE_CACHE 

= 

ACTION_COPY_DIR 

= 

ACTION_WAIT_CHAR 

= 

ACTION_SET_PROTECT 

= 

ACTION_CREATE_DIR 

= 

ACTION_EXAMINE_OBJECT 

= 

ACTION_EXAMINE_NEXT 

= 

ACTION_DISK_INFO 

= 

ACTION_INFO 

= 

ACTION_FLUSH 

= 

ACTION_SET_COMMENT 

= 

ACTION_PARENT 

= 

ACTION_TIMER 

= 

ACTION_INHIBIT 

= 

ACTION_DISK_TYPE 

= 

ACTION_DISK_CHANGE 

= 

ACTION_SET_DATE 

= 

ACTION_SAME_LOCK 

= 

ACTION_SCREEN_MODE 

= 

ACTION_READ_RETURN 

= 

ACTION_WRITE_RETURN 

= 

ACTION_SEEK 

= 

ACTION_FINDUPDATE 

= 

ACTION_FIND INPUT 

= 

ACTION_FINDOUTPUT 

= 

ACTION_END 

= 

ACTION_FORMAT 

= 

ACTION_MAKE_LINK 

= 

ACTION_SET_FILE_SIZE 

= 

ACTION_WRITE_PROTECT 

= 

ACTION_READ_LINK 

= 

ACTION_FH_FROM_LOCK 

= 

ACTION_IS_FILESYSTEM 

= 

ACTION_CHANGE_MODE 

= 

ACTION_COPY_DIR_FH 

= 

ACTION_PARENT_FH 

= 

ACTION_EXAMINE_ALL 

= 

ACTION_EXAMINE_FH 

= 

ACTION_LOCK_RECORD 

= 

ACTION_FREE_RECORD 

= 

ACTION_ADD_NOTIFY 

= 

ACTION_REMOVE_NOTIFY 

= 

add buffer copy directory wait for a  character set protection create directory examine object examine next entry info on the disk information invalid buffers set comment parent directory

Timer event 

Handler on/off 

diskette type diskette change set date compare Locks screen mode read write position open old file new file end format create a  link set file size write protect read link get FileHandle get Handler type change access mode copy directory get parent directory examine directory tree structure examine file lock record free record start notification end notification

Packet types from runlnewclil execute! system to the Shell: 

RUN_EXECUTE =  -1 

RUN_SYSTEM =  -2 

RUN_SYSTEM_ASYNCH =  -3 

Results of GetDeviceProc(): 

Dec Hex STRUCTURE DevProc , 0 

0 $0 APTR dvp_Port MsgPort 

4 $4 BPTR dvp_Lock Lock 

8 $8 ULONG dvp_Flags  Flags (s.u.) 

12 $C APTR dvp_DevNode DosList (DO NOT USE!) 

16 $10 LABEL dvp_SIZEOF 

Values for dvp_Flags 

DVPB_UNLOCK 

DVPB_ASSIGN 

0, DVPF_UNLOCK =  1 

1, DVPF_ASSIGN =  2 

Storage device description: 

)ec 

Hex 

$0 

$4 

$8 

$c 

$10 

$14 

$18 

$1C 

$20 

$24 

$28 

$2C 

$30 

$34 

$38 

$3C 

$40 

$44 

$48 

$4C 

80 $50 

STRUCTURE DosEnvec.O 

ULONG deJTableSize 

ULONG de_SizeBlock 

ULONG de_SecOrg 

ULONG de_Surfaces 

ULONG de_SectorPerBlock 

ULONG de_BlocksPerTrack 

ULONG de_Re served 

ULONG de_PreAlloc 

ULONG de_Interleave 

ULONG de_LowCyl 

ULONG de_HighCyl 

ULONG de_NumBuffers 

ULONG de_BufMemType 

ULONG de_MaxTransfer 

ULONG de_Mask 

LONG de_BootPri 

ULONG de_DosType 

ULONG de_Baud 

ULONG de_Control 

ULONG de_BootBlocks 

LABEL DosEnvec_SIZEOF 

table size block size in Longs sector organization (0) number of heads sectors per block (1) blocks per track reserved blocks at the beginning reserved blocks at the end interleave mode (0) first cylinder (starting with 0) last cylinder normal buffer count memory type of buffer maximum speed address mask boot priority

DOS type 

baud rate for serial Handlers control Word for Handler number of boot blocks

Filesystem startup message: 

Dec Hex STRUCTURE FileSysStartupMsg, 0 

0 $0 ULONG fssm_Unit unit number for OpenDeviceO 

4 $4 BSTR fssm_Device DeviceName ending in 0 

8 $8 BPTR fssm_Environ  structure of data storage device 

12 $C ULONG fssm_Flags  Flags for OpenDeviceO 

16 $10 LABEL FileSysStartupMsg_SIZEOF 

NOTIFY_CLASS =  $40000000 

NOTIFY_CODE =  $1234 

this will change. this too

Dec Hex STRUCTURE NotifyMessage, 0 

0 $0 STRUCT nm_ExecMessage,MN_SIZE message 

20 $14 ULONG nm_Class s.o. 

$18 

UWORD 

nm_Code s.o.

$1A 

APTR 

nm_NReq

 Notify request (do 

$1E 

ULONG 

nm_DoNotTouch

$22 

ULONG 

nm_DoNotTouch2

$26 

LABEL 

NotifyMessage_SIZEOF 

Dec 

Hex 

STRUCTURE NotifyRequest 

$0 

CPTR 

nr_Name

 Name 

$4 

CPTR 

nr_FullName complete DOS path

$8 

ULONG 

nr_UserData own data

$C 

ULONG 

nr_Flags

 Flags 

$10 

LABEL 

nr_Task task for SEND_SIGNAL or

$10 

APTR 

nr_Port

MsgPqrt for SEND_MESSAGE 

$14 

UBYTE 

nr_S igna INum for SEND_SIGNAL

$15 

STRUCT 

nr_pad, 3

$18 

STRUCT 

nr_Reserved, 4*4

$28 

ULONG 

nr_MsgCount number of Msgs sent

$2C 

APTR 

nr_Handler

 Handler for EndNotifyO 

$30 

LABEL 

NotifyRequest_SIZEOF 

Values for nr_Flags: 

NRB_SEND_MESSAGE =   0 , 

NRB_SEND_SIGNAL =   1, 

NRB_WAIT_REPLY =   3 , 

NRB_NOTIFY_INITIAL =   4, 

NRB_MAGIC =31, 

NRF_SEND_MESSAGE 

NRF_SEND_SIGNAL 

NRF_WAIT_REPLY 

NRF_NOTIFY_INITIAL 

NRF_MAGIC 

NR_HANDLER_FLAGS 

$80000000 

$ffff0000 

4. Directories 

CreateDir 

Create a  new directory | 

Call: lock =  CreateDir (  name ) 

DO -120 (A6) Dl 

BPTR lock 

APTR name 

Function: Creates a  new directory and returns a  lock for it. 

Parameters: name String containing directory name. 

Result: BCPL pointer to a  lock or 0. 

See also: UnLockQ 

ICurrentDir 

Set the current directory | 

Call: oldLock =  CurrentDir (  lock ) 

DO -126 (A6) Dl 

BPTR oldLock 

BPTR lock 

Function: 

CurrentDirO sets the directory that all path specifications 

will use as a  starting point. You are required to pass a  lock for the desired directory. As a  result, you receive the lock to the directory that was formerly current.

Parameters: 

Result: 

See also: 

|ExAH 

lock

BCPL pointer to a  lock. 

BCPL pointer to the previous current directory. A  value of 

0 represents the boot directory that is set by a  reboot. 

Lock(), UnLock() 

Examine an entire directory 1 

Call: continue =  ExAll(lock, buffer, size, type, control) 

DO -432 (A6) Dl D2 D3 D4 D5 

Function: 

BOOL continue 

BPTR lock 

APTR buffer 

LONG size, type 

STRUCT ExAllControl *control 

Examines a  directory and fills a  buffer with ExAllData 

structures.

Parameters: lock 

buffer size type control

Result: 

Directory lock 

Buffer address 

Buffer size 

The amount of data that will be stored in each file (ED_.„). Higher values contains smaller values. The order is name, type, size, protection bits, date, comment.

ExAllControl structure, must be created with 

AllocDosObject(). The LastKey entry must be deleted before the call. If several calls are required, this entry may not be changed.

Entries Number of entries in buffer. 

LastKey Delete prior to call. 

MatchString Optional pattern string. 

MatchFunc Hook address of a  pattern 

matching routine.

Cancel (delete LastKey): 

IoErrQ 

ERROR_NO_MORE_ENTRIES: 

ExAll is finished otherwise 

IoErr()=error code. In any other 

case* save the buffer contents and call ExAllQ again.

See also: IoErrQ, AllocDosObject(), FreeDosObject 

I Examine 

Examine directory or file| 

Call: success =  Examine (   lock, infoBlock ) 

DO -102 (A6) Dl D2 

BOOL success 

BPTR lock 

STRUCT FilelnfoBlock *infoBlock 

Function: ExamineQ fills a  FilelnfoBlock with all available 

information. This data structure can only be read if it's passed as a  parameter later (e.g., to ExNextO).

Parameters: lock Lock for the file/directory to be examined. 

infoBlock Address of FilelnfoBlock structure.

Result: 0  Error 

|ExNext 

Examine next directory entry 

Call: success =  ExNext (    lock, infoBlock ) 

DO -108 (A6) Dl D2 

BOOL success 

BPTR lock 

STRUCT FilelnfoBlock *infoBlock) 

Function: This function examines the next directory entry and fills the 

fields of the given FilelnfoBlock with the values that were obtained. Prior to the first call, the FilelnfoBlock must be initialized with the Examine() function.

Parameters: lock 

Lock for the directory being examined. This 

lock must correspond with the lock from the
Examine() call. File locks do not work. 

infoBlock Address of FilelnfoBlock structure that was initialized by Examine().

Result: 

If IoErr()=ERROR_NO_MORE_ENTRIES, then no more entries are available. Otherwise,
IoErrQ returns the error number. 

Warning: Recursive reading of the directory tree structure will only 

work if you use a  new FilelnfoBlock for each directory found.

IGetProgramDir Get directory lock for the program | 

Call: lock =  GetProgramDir ( ) 

DO -600 (A6) 

BPTR lock 

Function: Returns a  lock for the directory from which the program is 

started. You can make a  working copy of this lock with
DupLock(). 

Result: Lock or 0  (for example, in the case of a  resident program) 

I Info Get information about a  disk | 

Call: success =  lnfo( lock, parameterBlock ) 

DO -114 (A6) Dl D2 

BOOL success 

BPTR lock 

STRUCT InfoData *parameterBlock 

Function: Fills the InfoData structure with information on the disk 

that corresponds to a  given lock.

Parameters: lock A  filesystem lock 

parameterBlock

InfoData structure 

Result: 0  Error 

MatchEnd Free MatchFirstQ/MatchNextQ memory | 

Call: MatchEnd (AnchorPath) 

-834 (A6) Dl 

STRUCT AnchorPath *AnchorPath 

Function: Free pattern matching memory. 

Parameters: AnchorPath 

Structure of MatchFirst()/MatchNext(). 

| MatchFirst Find a  file that matches the pattern] 

Call: error =  MatchFirst (pat, AnchorPath) 

DO -822 (A6) Dl D2 

BOOL error 

APTR pat 

STRUCT AnchorPath *AnchorPath 

Function: Finds the first file or directory that matches the given 

pattern. Initializes the AnchorPath structure. Possible characters in the pattern string are:

? Individual character 

# 0  or more characters 

(alb) Individually check components separated by I 

~ Exclude the following expression 

[abc] One of the specified characters 

[a-z] Range of characters, such as "[0-9a-zA-Z]

% No character (useful with "(albl%)") 

* Can optionally be used for "#?

Parameters: pat Pattern string 

AnchorPath 

Structure for the search. 

Result: 0  Okay, otherwise error code. 

| MatchNext Find next file that matches the pattern | 

Call: error =  MatchNext (AnchorPath) 

DO -828 (A6) Dl 

BOOL error 

STRUCT AnchorPath *AnchorPath 

Function: Finds the next file or directory to match the given pattern 

(see MatchFirst()). 

Parameters: AnchorPath 

MatchFirst() structure 

Result: 0  Okay, otherwise error code. 

ParentDir Get parent directory lock| 

Call: newlock =  ParentDir (    lock ) 

DO -210 (A6) Dl 

BPTR newlock, lock 

Function: Returns a  lock for the parent directory of a  file or directory. 

Parameters: lock BCPL pointer to a  lock structure. 

Result: Lock or 0  (= boot directory, parent directory of all root 

directories)

[ParentOfFH Get lock for a  file's parent directory | 

Call: lock =  ParentOfFH (fh) 

DO -384 (A6) Dl 

BPTR lock.fh 

Function: Returns a  lock for the parent directory when given a 

FileHandle. 

Parameters: fh FileHandle 

Result: Lock or 0  (error) 

Structure ofExamine() and ExNextf): 

Dec Hex STRUCTURE FilelnfoBlock, 0 

0 $0 LONG fib_DiskKey  block number for operating system 

4 $4 LONG fib_DirEntryType type of entry (<0:file, >0 :directory) 

8 $8 STRUCT fib_FileName,108  filename ending in 0 

116 $74 LONG fib_Protection ,-protection status 

120 $78 LONG fib_EntryType  f or the operating system 

124 $7C LONG fib_Size file size in bytes 

128 $80 LONG f ib_NumBlocks file size in blocks 

132 $84 STRUCT f ib_DateStamp, ds_SIZEOF  revision date 

144 $90 STRUCT f ib_Comment, 80  comment ending in 0 

224 $E0 STRUCT f ib_Reserved, 3 6   reserved 

260 $104 LABEL fib_SIZEOF 

Normal values for fib_DirEntryType: 

ST_BOOT 

= 

boot directory

ST_ROOT 

= 

main directory

ST_USERDIR 

= 

/directory 

ST_SOFTLINK 

= 

soft link

ST_LINKDIR 

= 

HardLink to directory 

ST_FILE 

= 

-3 

file

ST_LINKFILE 

= 

-4 

HardLink to file 

FIBB. 

FIBF. 

FIBB. 

FIBF. 

FIBB. 

FIBF. 

FIBB. 

FIBF. 

FIBB. 

FIBF. 

FIBB. 

FIBF. 

FIBB. 

FIBF 

SCRIPT = 

SCRIPT = 

PURE 

PURE 

.ARCHIVE = 

.ARCHIVE = 

.READ = 

READ 

.WRITE 

.WRITE 

.EXECUTE = 

.EXECUTE = 

DELETE = 

DELETE = 

Protection status bits: 

batch file program code is re-entrable

(=RESIDENT-capable) 

deleted when file is changed disable read access disable write access disable program start disable delete

Values for ExAll(): 

ED_NAME 

ED_TYPE 

ED_SIZE 

ED_PROTECTION 

ED_DATE 

ED_COMMENT 

name name+type name+type+length name+type+length+protection name+type+length+protection+date name+type+length+protection+date+comment

ExAll() result structure: 

Dec Hex STRUCTURE ExAllData.O 

0 $0 APTR ed_Next next ExAllData structure 

4 $4 APTR ed_Name name 

8 $8 LONG ed_Type typ or end of structure 

12 $C ULONG 

16 $10 ULONG 

20 $14 ULONG 

24 $18 ULONG 

28 $1C ULONG 

32 $20 APTR 

ed_Size ed_Prot ed_Days ed_Mins ed_Ticks ed_Comment size or end of structure
/protection or end of structure 

date stamp or end of structure

/comment or end of structure 

? ?  LABEL ed_Strings /strings at end of structure 

Control structure for ExAll(): 

Dec Hex STRUCTURE ExAllControl, 0 

0 $0 ULONG eac_Entries /number of buffer entries 

4 $4 ULONG eac_LastKey /disk block (do not change) 

8 $8 APTR eac_MatchString /pattern string or 0 

12 $C APTR eac_MatchFunc /pattern match Hook or 0 

16 $10 LABEL ExAllControl_SIZEOF 

Structure oflnfoQ: 

Dec 

Hex 

$0 

$4 

$8 

$c 

$10 

$14 

$18 

$1C 

$20 

36 $24 

STRUCTURE InfoData, 0 

LONG id_NumSoftErrors 

LONG id_UnitNumber 

LONG id_DiskState 

LONG id_NumBlocks 

LONG id_NumBlocksUsed 

LONG id_BytesPerBlock 

LONG id_DiskType 

BPTR id_VolumeNode 

LONG id_InUse 

LABEL id_SIZEOF 

number of errors on disk number for OpenDevice diskette status (see below) number of blocks on disk number of blocks used bytes per block disk type

BPTR to DosList structure 

Flag, 0=not active 

ID_WRITE_PROTECTED 

ID_VALIDATING 

ID_VALIDATED 

Diskette status: 

80 /write protection on 

81 /disk being checked 

82 /disk is okay 

Diskette type: 

ID_NO_DISK_PRESENT 

= 

-1 

ID_UNREADABLE_DISK 

= 

•BAD'«8 

ID_NOT_REALLY_DOS 

= 

'NDOS' 

ID_DOS_DISK 

= 

' DOS •  «8 

ID_FFS_DISK 

= 

' DOS ' «8 

ID_KICKSTART_DISK 

= 

' KICK ' 

ID_MSDOS_DISK 

= 

'MSD'«8 

/no disk in drive 

/unreadable format or error 

/unreadable format 

,-OFS disk 

/FFS disk 

/operating system diskette 

/MS-DOS diskette 

Pattern matching structure: 

Dec 

Hex 

$0 

$0 

$4 

$4 

$8 

$C 

$10 

$10 

$11 

$12 

$14 

$118 

$118 

STRUCTURE Anchor Path, 0 

LABEL ap_First 

CPTR ap_Base 

LABEL ap_Current 

CPTR ap_Last 

LONG ap_BreakBits 

LONG ap_FoundBreak 

LABEL ap_Length 

BYTE ap_Flags 

BYTE ap_Reserved 

WORD ap_Strlen 

STRUCT ap_Info,fib_SIZEOF 

LABEL ap_Buf 

LABEL ap_SIZEOF 

first Anchor last Anchor break bits found bits

 Flags 

/string length 

FileInfoBlock 

.•buffer for path 

APB_DOWILD =   0 OPT ALL 

APF_DOWILD =   1 

APB_1TSWILD =   1 Flag from MatchFirstO for MatchNext ( 

APF_ITSWILD =   2 

APB_DODIR =  2  directory must also be checked 

APF_DODIR =   4 

APB_DIDDIR =   3 /directory being checked 

APF_DIDDIR =   8 

APB_NOMEMERR =  4 not enough memory 

APF_NOMEMERR =16 

APB_DODOT =  5  conversion of ■ . ' in CurrentDir 

APF_DODOT =32 

APB_DirChanged =   6  directory has changed since 

APF_DirChanged =  64 last MatchNext call 

Anchor structure: 

Dec 

Hex 

STRUCTURE AChain, 0 

$0 

CPTR 

an_Child

$4 

CPTR 

an_Parent

$8 

LONG 

an_Lock

$c 

STRUCT 

an_Info, f ib_SIZEOF

$110 

BYTE 

an_Flags

$111 

LABEL 

an_string

$111 

LABEL 

an_SIZEOF

FilelnfoBlock 

DDB_PatternBit =  0, 

DDB_ExaminedBit =  1, 

DDB_Completed =  2, 

DDB_AllBit =  3, 

DDB_S INGLE =  4, 

DDF_PatternBit =  1 

DDF_ExaminedBit =  2 

DDF_Completed =  4 

DDF_AllBit =  8 

DDF_SINGLE =16 

Tokens for Token strings: 

P_ANY 

= 

$80 

Token for '*' or '#? 

P_S INGLE 

= 

$81 

Token for ' ? ' 

P_ORSTART 

= 

$82 

Token for ' ( ' 

P_ORNEXT 

= 

$83 

Token for ' 1 ' 

P_OREND 

= 

$84 

Token for ' ) ' 

P_NOT 

= 

$85 

Token for ' - ' 

p_NOTEND

= 

$86 

end of expression after '-'

PJTOTCLASS 

= 

$87 

Token for ' A ' 

P_CLASS 

= 

$88 

Token for ' ( ) ' 

P_REPBEG 

= 

$89 

• Token for ' [ ' 

P_REPEND 

= 

$8A 

• Token for ' ] ' 

P_STOP 

= 

$8B 

• cancel evaluation 

COMPLEX_BIT 

EXAMINE_BIT 

Values for an_Status: 

1   pattern parsing 

2   search in directory 

5. Programs 

lAddSegment

Insert program in resident list] 

Call: success =  Adds egment (name, seglist, type) 

DO -774 (A6) Dl D2 D3 

BOOL success 

APTR name 

BPTR seglist 

LONG type 

Function: Inserts a  program in the resident list (to hold it in memory). 

Parameters: name Program name 

seglist BPTR (APTR/4) to program's segment list type Call counter for linking, normal value: 0.

Result: 0  Error 

| CreateNewProc Generate a  new process | 

Call: process =  CreateNewProc (tags) 

DO -498 (A6) Dl 

STRUCT Process *process 

STRUCT Tagltem *tags 

Function: Generates a  new process according to the values in the tag 

array. NP_Seglist or NP_Entry must be included.
NP_Seglist passes a  BPTR to a  segment list and NP_Entry 

passes the address of the program. Input and output are routed to NIL: and the stack is set to 4000 bytes.

CreateNewProc can be called from a  simple task, but in this 

case the DOS I/O will not work.

Parameters: tags Address of a  Tagltems field. 

Result: Process or 0 

ICreateProc Generate a  new process (old) | 

Call: process =  CreateProc( name, pri, seglist, stackSize ) 

DO -138 (A6) Dl D2 D3 D4 

STRUCT MsgPort "process 

APTR name 

LONG pri 

BPTR seglist 

LONG stackSize 

Function: CreateProc starts a  new process with the given name. 

Parameters: name Address of the string with the process name, 

pri Priority of the process (-128 to 127) seglist BPTR to a  SegList (see LoadSegO) stackSize Stack size (multiple of 4)

Result: Process or 0  (error) 

See also: LoadSegO, CreateNewProc() 

| Exit End BCPL program | 

Call: Exit (  returnCode ) 

-144 (A6) Dl 

LONG returnCode 

Function: Exit() is used to properly end BCPL programs only. This 

routine must never be called by other programs.

Parameters: returnCode 

Return value for CLI. 

Result: None. 

Warning: C  programmers must be careful not to confuse the C 

function exit() with the DOS function Exit().

IFindSegment Retrieve a  segment from the resident listj 

Call: segment =  FindSegment (name, start, system) 

DO -780 (A6) Dl D2 D3 

STRUCT Segment *segment, *start 

APTR name 

LONG system 

Function: Finds the segment of the given name in the list of resident 

programs. You can also specify the name of the segment from which to begin the search. If the system flag is set, then only one system segment is searched.

Parameters: name Segment name 

start 0  or starting segment for the search system 0  or - 1 for system segment

Result: Segment address or 0 

Warning : Turn off multitasking before calling. 

llnternalLoadSeg

Load program from FileHandle| 

Call: 

seglist =  InternalLoadSeg(fh, table, functionarray, stack)
DO -756 (A6) DO AO Al A2 

BPTR seglist, fh, table 

APTR functionarray, stack 

Function: Loads the program represented by a  FileHandle. If no 

overlay is loaded, then table must be set to 0. If the stack size is integrated into the program, then it's written to the address given in stack. There may already be a  value stored at this address. In this case, it's overwritten by the loaded value.

Parameters: fh FileHandle of the program. 

table Overlay table or 0 functionarray

Field containing addresses of three functions: 

Actual ReadFunc (readhandle, buf f er , length) , DOSBase 

DO Dl AO DO A6 

> read function, normally Read() 

Memory =  AllocFunc (size, flags) , Execbase 

DO DO Dl A6 

> allocate memory, normally AllocMem() 

FreeFunc (memory, size) , Execbase 

Al DO A6 

> free memory, normally FreeMemO 

stack Variable address (LONG) to which the stack size is written.

Result: SegList or -(SegList) for overlays or 0. 

llnternalUnLoadSeg Free a  SegListl

Call: success =  lnternalUnLoadSeg(seglist,FreeFunc) 

DO -7 62 (A6) Dl Al 

BOOL success 

BPTR seglist 

FPTR FreeFunc 

Function: Frees the segments of a  SegList and closes the program file 

for overlays.

Parameters: seglist SegList of a  program. 

FreeFunc Free function (see InternalLoadSegO) 

Result: 0  Error 

ILoadSeg Load program| 

Call: seglist =  LoadSeg( name ) 

DO -150 (A6) Dl 

BPTR seglist 

APTR name 

Function: Loads a  file consisting of DOS hunks into memory. The 

memory blocks are linked with BPTRs in the first longword. The size of the memory block precedes the
BPTR. 

Parameters: name Filename (including path) 

Result: BPTR to the first segment or 0. 

INewLoadSeg Expanded LoadSegQ routine | 

Call: seglist =  NewLoadSeg(file, tags) 

DO -768 (A6) Dl D2 

BPTR seglist 

APTR file 

STRUCT Tagltem *tags 

Function: Loads a  file consisting of hunks, depending on the tags in a 

given Tagltem field.

Parameters: file Filename 

tags Address of a  Tagltem field.

Result: Seglist or 0 

[ RemSegment Remove a  program from the resident list| 

Call: success =  RemSegment (segment) 

DO -786 (A6) Dl 

BOOL success 

STRUCT Segment *segment 

Function: Removes a  resident segment from the system list and frees 

the allocated memory.

Parameters: segment Segment structure 

Result: 0  Error (usually because Usecount is not 0) 

| RunCommand Start a  program with its own process | 

Call: re =  RunCommand (seglist, stacksize, argptr, argsize) 

DO -504 (A6) Dl D2 D3 D4 

LONG re 

BPTR seglist 

ULONG argsize, stacksize 

APTR argptr 

Function: Starts a  program using its own process structure. 

Parameters: seglist SegList of the program, 

stacksize Stack size

argptr Argument string argsize Length of argument string

Result: Return value of the program or -1 if the stack could not be 

loaded. lUnLoadSeg

Free SegList| 

Call: success =  unLoadSeg (   seglist ) 

DO -156 (A6) Dl 

NP_Dummy 

NP_Seglist 

NP_FreeSeglist 

NP_Entry 

NP_Input 

NP_Output 

NP_CloseInput 

NP_CloseOutput 

NP_Error 

NP_CloseError 

NP_CurrentDir 

NP_StackSize 

NP_Name 

NP_Priority 

NP_ConsoleTask 

NP_WindowPtr 

NP_HomeDir 

NP_CopyVars 

NP_Cli 

NP_Path 

NP_CommandName 

NP_Arguments 

BOOL success 

BPTR seglist 

Function: Free the SegList of a  file loaded with LoadSeg(). 

Parameters: seglist BCPL to a  SegList 

Result: 0  SegList was 0  or an error occurred. 

CreateNewProc() Tags: 

TAG_USER+100 

NP_Dummy+l 

NP_Dummy+2 

NP_Dummy+3 

NP_Dummy+4 

NP_Dummy + 5 

NP_Dummy+6 

NP_Dummy+7 

NP_Dummy+8 

NP_Dummy+9 

NP_Dummy+10 

NP_Dummy + 1 1 

NP_Dummy+12 

NP_Dummy+13 

NP_Dummy+14 

NP_Dummy+15 

NP_Dummy+16 

NP_Dummy+17 

NP_Dummy+18 

NP_Dummy+19 

NP_Dummy+20 

NP_Dummy+21 

SegList of the program 

free SegList at end? program address input handle output handle close (Inputhandle) at end? close (Outputhandle) at end? error handle close (Errorhandle) at end? current directory stack size in bytes process name process priority

Console Handler 

window for Requester, etc. start directory copy local variables? create CLI structure? path for CLI program name for CLI arguments for CLI

NP_NotifyOnDeath =  NP_Dummy+22 /message at end? 

NP_Synchronous =  NP_Dummy+23 wait until process end? 

NP_ExitCode =  NP_Dummy+24  routine to be ended 

NP_ExitData =  NP_Dummy+25 data for NP_EndCode 

Structure of a  process (expanded Task structure): 

Dec 

Hex 

STRUCT! 

$0 

STRUCT 

$5C 

STRUCT 

$7E WORD 

$80 

BPTR 

$84 

LONG 

$88 

APTR 

$8C 

LONG 

$90 

BPTR 

$94 

LONG 

$98 

BPTR 

$9C 

BPTR 

$A0 

BPTR 

$A4 

APTR 

$A8 

APTR 

$AC 

BPTR 

$B0 

APTR 

$B4 

APTR 

$B8 

APTR 

$BC 

BPTR 

$C0 

LONG 

$C4 

APTR 

$C8 

LONG 

$CC APTR 

$D0 

STRUCT 

$DC APTR 

$E0 

BPTR 

$E4 

LABEL 

pr_Task, TC_SIZE pr_MsgPort , MP_SIZE pr_Pad pr_SegList pr_StackSize pr_GlobVec pr_TaskNum pr_StackBase pr_Result2 pr_CurrentDir pr_CIS pr_COS pr_ConsoleTask pr_FileSystemTask pr_CLI pr_ReturnAddr pr_PktWait pr_WindowPtr pr_HomeDir pr_Flags pr_ExitCode pr_ExitData pr_Argument s pr_LocalVars , MLH_SIZE pr_ShellPrivate pr_CES pr_SIZEOF pr_Flags flags:

Task structure 

process port

SegList of the program 

stack size global vector (BCPL)

CLI process number 

end of stack return value

Lock for current directory 

input channel output channel pr_MsgPort of the window Handler pr_MsgPort of the drive

CLI structure 

old stack

WaitPktO function 

Requester window 

start directory

Flags 

end function data for the function argument string local ENV variables for Shell only error channel, in case pr_COS=0

PRB_FREESEGLIST =  0, 

PRB_FREECURRDIR =  1, 

PRB_FREECLI =  2, 

PRB_CLOSEINPUT =  3, 

PRB_CLOSEOUTPUT =  4, 

PRB_FREEARGS =  5, 

PRF_FREESEGLIST =  1 

PRF_FREECURRDIR =  2 

PRF_FREECLI =  4 

PRF_CLOSEINPUT =  8 

PRF_CLOSEOUTPUT =16 

PRF_FREEARGS =32 

Hunk types: 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

HUNK. 

.UNIT 

.NAME 

.CODE 

.DATA 

.BSS 

.RELOC32 

.RELOC16 

.RELOC8 

.EXT 

EXT_SYMB 

EXT_DEF 

EXT_ABS 

EXT_REF32 

EXT_COMMON 

EXT_REF16 

EXT_REF8 

EXT_DEXT32 

EXT_DEXT16 

EXT_DEXT8 

.SYMBOL 

.DEBUG 

_END 

.HEADER 

..OVERLAY 

_BREAK 

_DREL32 

DREL16 

DREL8 

LIB 

INDEX 

 1014 

: 1015 

: 1016 

: 1017 

: 1018 

: 1019 

part of an object code file segment name program segment data segment memory block (+MEMF_CLEAR) table for absolute addressing offset table offset table linker data symbol table external label absolute value

32 bit symbol reference 

32 bit reference to global data 

16 bit symbol reference 

8 bit symbol reference 

32 bit relative data reference 

16 bit relative data reference 

8 bit relative data reference 

name of a  Long value special info for a  debugger end of main segment info on the following Hunks overlay Hunks end of Overlay relative data 32 bit relative data 16 bit relative data 8  bit library table

6.CU 

ICheckSignal 

Check for Cancel signal | 

Call: signals =  CheckSignal(mask) 

DO -792 (a6) Dl 

ULONG signals 

ULONG mask 

Function: Tests the given signal bits. The signal bits are masked and 

passed back. All bits set in the mask are reset in the process structure.

Parameters: mask 

Result: signals 

Bit mask for signal bits. 

Logical AND combination of the mask and the 

signal bits.

See also: exec.library/Signal 

fell

(Jet the address of the calling CLII 

Call: cli_ptr =  Cli() 

DO -492 (A6) 

STRUCT CommandLinelnterface *cli_ptr 

Function: Returns the address of the CLI from which the program 

was started.

Parameters: None. 

Result: Address of the CLI or 0  (Workbench). 

| Execute 

Execute CLI command] 

Call: success =  Execute ( commandstring, input, output ) 

DO -222 (A6) Dl D2 D3 

BOOL success 

APTR commandStringExecute 

BPTR input, output 

Function: 

Attempts to execute a  CLI command. The string that 

contains the command and the parameters is constructed exactly as it would be if entered from the CLI entry line. It can contain any special characters available to CLI. If an input channel is specified, then Execute() will read further instructions from this channel after the execution and change the process in the case of an interactive channel or a re-routing to NIL:. The default output is the current window, but this can be changed by specifying a  different output channel.

Processes are started using the RUN command. 

Parameters: commandString 

Address of a  CLI command line. 

input FileHandle output FileHandle

Result: 0  Error 

Warning: Programs started from the Workbench normally do not 

have a  current output window. iFindCliProc Find a  CLI process!

Call: proc =  FindCliProc(num) 

DO -546 (A6) Dl 

STRUCT Process *proc 

LONG num 

Function: Returns the CLI process with the given number. 

Parameters: num Task number of the CLI process. 

Result: Address of the Process structure or 0  if not found. 

Warning: To be safe, this routine should only be called when 

multitasking is turned off.

| Input Get the FileHandle for the default input file] 

Call: file =   Input 0 

DO -54 (A6) 

BPTR file 

Function: Returns the FileHandle that was set as the input channel 

when the program was started. This FileHandle may not be closed.

Result: Input FileHandle or 0 

See also: 

IMaxCii 

Output() 

tiet the highest CLI number |

Call: number =  MaxCli ( ) 

DO -552 (A6) 

LONG number 

Function: Returns the highest process number of all the CLI 

processes running.

Result: Highest CLI process number. 

Warning: The highest process number does not necessarily equal the 

number of processes currently running, since processes with lower numbers may already have been ended.

| Output 

Call: file =  Output () 

DO -60 (A6) 

BPTR file 

Get the FileHandle for the default output filel 

Function: 

Result: 

See also: 

|ReadArgs

Returns the FileHandle that was set as the output channel 

when the program was started. This FileHandle may not be closed.

Output FileHandle or 0 

InputQ 

Interpret CLI argument string! 

Call: result =  ReadArgs (template, array, rdargs) 

DO -798 (A6) Dl D2 D3 

STRUCT RDArgs *result , *rdargs 

APTR template , array 

Function: Interprets an argument string using a  pattern string, which 

can contain options such as "Q=Quick". Options are separated by commas in the pattern string. A  result for each option is expected to be passed in the longword field.
Options can be defined with 'f: 

/S Switch, BOOL, 0  = not given. 

/K Keyword, this entry is only filled in if the 

keyword was found.
/N Number, a  number in decimal format. 

/T Switch, similar to /S. 

/A Required keyword. 

/F Remainder of the line. 

/M Multiple strings (array address with last 

string address=0). The RDArgs structure is required for FreeArgs(). Such a structure is normally created with ReadArgs() (parameter =
0). 

Parameters: template Input format 

array Longword array for results rdargs Optional RDArgs structure

Result: RDArgs structure or 0 

| Readltem Read an argument from an argument string | 

Call: value =  Readltem (buffer, maxchars, input) 

DO -810 (A6) Dl D2 D3 

LONG value , maxchars 

APTR buffer 

STRUCT CHSource * input 

Function: Reads a  word or a  character string enclosed in quotes from 

Input() or a  CHSource (if given). 

Parameters: buffer Result buffer 

maxchars Buffer size input CHSource structure or 0  (FGetC(Input()))

Result: See data structures. 

| Selectlnput Set FileHandle for default input channel] 

Call: old_fh =  Selectlnput (fh) 

DO -294 (A6) Dl 

BPTR old_fh,fh 

Function: Sets the value that Input() returns for its own CLI process. 

Parameters: fh New InputHandle 

Result: FileHandle previously returned via Input(). 

| SelectOutput Set FileHandle for default output channel | 

Call: old_fh =  SelectOutput (fh) 

DO -300 (A6) Dl 

BPTR old_fh,fh 

Function: Sets the value that Output() returns for its own CLI 

process.

Parameters: fh New OutputHandle 

Result: FileHandle previously returned by Output(). 

| Set ArgStr Set argument string | 

Call: Oldptr =  SetArgStr (ptr) 

DO -540 (A6) Dl 

APTR ptr, Oldptr 

Function: Sets the argument string for the running process. The old 

string must be restored before the program is ended.

Parameters: ptr Address of new argument string. 

Result: Oldptr Address of old string. 

SetCurrentDirName 

Sets name of the current directory in the process 

Call: success =  SetCurrentDirName (name) 

DO -558 (A6) Dl 

BOOL success 

APTR name 

Function: Manipulates the name of the current directory within the 

CLI structure. 

Parameters: name New directory name 

Result: 0  Error 

|SetProgramDir Sets program directory | 

Call: Oldlock =  SetProgramDir (lock) 

DO -594 (A6) Dl 

BPTR lock, Oldlock 

Function: Sets the value returned by GetProgramDir(). 

Parameters: lock Directory lock 

Result: Oldlock Lock on previous directory. 

| SetProgramName Set program name | 

Call: success =  SetProgramName (name) 

DO -570 (A6) Dl 

BOOL success 

APTR name 

Function: Changes the program name in the CLI structure. 

Parameters: name 

Result: 0 

Program name 

Error 

SetPrompt 

Set prompt for CLI/Sheli] 

Call: success =  SetPrompt (name) 

DO -582 (A6) Dl 

BOOL success 

APTR name 

Function: Sets prompt text in the CLI structure. 

Parameters: name Prompt string 

Result: 0  Error 

ISystemTagLlsT 

Execute command from Shell! 

Call: error =   SystemTagList (command, tags) 

DO -606 (A6) Dl D2 

LONG error 

APTR command 

STRUCT Tagltem *tags 

Function: Similar to Execute(), but does not read additional 

instructions from input FileHandle.

Parameters: command Shell command line 

tags Tagltem field for changes.

Result: Return value of command or -1 (error). 

Output a  formatted string] 

IVPrintf 

Call: count =  VPrintf (fmt, argv) 

DO -954 (A6) Dl D2 

LONG count 

APTR f mt , argv [ ] 

Function: Similar to VFPtrintf, but output occurs after Output(). 

Parameters: fmt Format string for exec/RawDoFmt(). 

argv Field containing parameters.

Result: Number of output bytes or -1 (error). 

Return values in CLI: 

RETURN_OK =  0  everything okay 

RETURN_WARN =   5   warning 

RETURN_ERROR =  10  error occurred 

RETURN_FAIL =  20 /complete failure, nothing accomplished 

CU Cancel bits (CONTROL +  CIDIEIF) 

SIGBREAKB_CTRL_C =  12, SIGBREAKF_CTRL_C =  $1000 

SIGBREAKB_CTRL_D =  13, SIGBREAKF_CTRL_D =  $2000 

SIGBREAKB_CTRL_E =  14, SIGBREAKF_CTRL_E =  $4000 

SIGBREAKB_CTRL_F =  15, SIGBREAKF_CTRL_F =  $8000 

ReadltemO values: 

ITEM_EQUAL =  -2 "=■ Symbol 

ITEM_ERROR =  -1  error 

ITEM_NOTHING =   0 "*N", ■  " , end 

ITEM_UNQUOTED =   1   no quotes 

ITEM_QUOTED =   2 with quotes 

Readltem() structure: 

Dec Hex STRUCTURE CSource.O 

0 $0 APTR CS_Buffer buffer 

4 $4 LONG CS_Length buffer size 

8 $8 LONG CS_CurChr  current character 

12 $C LABEL CS_SIZEOF 

ReadArgs() structure: 

Dec Hex STRUCTURE RDArgs,0 

0 $0 STRUCT RDA_Source,CS_SIZEOF  source string 

12 $C APTR RDA_DAList  PRIVATE 

16 $10 APTR RDA_Buffer .-buffer (optional) 

Ul 

20 $14 LONG RDA_BufSiz 

24 $18 APTR RDA_ExtHelp 

28 $1C LONG RDA_Flags 

32 $20 LABEL RDA_SIZEOF 

buffer size optional help
 Flags 

RDA_Flags values: 

RDAB_STDIN =  0, RDAF_STDIN =  1 use Stdln 

RDAB_NOALLOC =  1, RDAF_NOALLOC =2 no extra buffer 

RDAB_NOPROMPT =  2, RDAF_NOPROMPT =  4 no input 

MAX_TEMPLATE_1TEMS =  100 max. number of arguments (must be divisible by 4!!!) 

MAX_MULTIARGS =  128 max. number of multiple strings 

CLI structure: 

Dec 

Hex 

STRUC 

$0 

LONG 

$4 

BSTR 

$8 

BPTR 

$C 

LONG 

$10 

BSTR 

$14 

LONG 

$18 

BSTR 

$1C 

BPTR 

$20 

BPTR 

$24 

BSTR 

$28 

LONG 

$2C 

LONG 

$3 0 

BPTR 

$34 

LONG 

$38 

BPTR 

$3C 

BPTR 

$40 

LABEL 

STRUCTURE CommandLinelnterface, 0 

cli_Result2 cli_SetName c 1 i_CommandD i r c 1 i_ReturnCode c 1 i_CommandName cli_FailLevel cli_Prompt cli_StandardInput c 1 i_Cur r ent Input c 1 i_CommandF i 1 e cli_Interactive cli_Background cli_CurrentOutput cli_DefaultStack cli_StandardOutput cli_Module cli_SIZEOF

SystemO Tags: 

IoErr ( ) value 

current directory command directory return value program name error level prompt string default input current input batch filename
BOOL if terminal 

BOOL if RUN command 

current output stack size in Longs default output program's SegList

SYS_Dummy 

SYS_Input 

SYS_Output 

SYS_Asynch 

SYS_UserShell 

SYS_CustomShell 

SYS_Error 

TAG_USER+32 

SYS_Dummy+l 

SYS_Dummy+2 

SYS_Dummy+3 

SYS_Dummy+4 

SYS_Dummy+5 

SYS_Dummy+? 

set input FileHandle set output FileHandle close input/output not to boot Shell specific Shell (name)
.•anything else =  error 

7. Files 

[ChangeMode Change access to lock or FileHandle | 

Call: success =  ChangeMode ( type , object, newmode) 

DO -450 (A6) Dl D2 D3 

BOOL success 

ULONG type 

bptr object
ULONG newmode 

Function: Changes the access mode for a  lock or FileHandle. 

Parameters: type Data structure type: CHANGE_FH or 

CHANGEJLOCK 

object Lock or FileHandle (according to type) newmode New access mode
Result: 0  Change not allowed 

Warning: Invalid values can lead to a  system crash. 

See also: Lock(), Open() 

ICiose Close file| 

Call: success =  Close (   file ) 

DO -36 (A6) Dl 

BOOL success 

BPTR file 

Function: Close a  file opened by the program itself. 

Parameters: file BCPL address of the file's FileHandle. 

Result: 0  if the file could not be closed, for example, because a 

buffered output is still in process.

See also: OpenQ 

DeleteFile 

Delete a  file] 

Call: success =  DeleteFile (   name ) 

DO -72 (A6) Dl 

BOOL success 

APTR name 

Function: Attempts to delete a  file or directory. 

Parameters: name String containing file or directory name. 

Result: 0  Could not be deleted. 

See also: IoErrQ 

lExamineFH

Retrieve information on a  file 

Call: success =  ExamineFH(fh, fib) 

DO -390 (A6) Dl D2 

BOOL success 

BPTR fh 

STRUCT FilelnfoBlock *fib 

Function: Examines a  FileHandle and fills out a  FilelnfoBlock. Be 

careful, because fib_Size can contain invalid values.

Parameters: fh 

fib
Result: 0 

FileHandle 

Address of a  FilelnfoBlock structure. 

Error 

IFGetC 

Read characters from a  filel 

Call: char =  FGetC(fh) 

DO -306 (A6) Dl 

LONG char 

Function: 

Parameters. 

Result: 

| Flush 

BPTR fh 

Reads a  byte from the given file (buffered). 

fh FileHandle

Byte (value 0-255) or -1 if end-of-file or error. 

Clears the buffer used for a  buffered I/Q| 

Call: 

Function: 

Parameters. 

Result: 

success =  Flush (fh)
DO -360 (A6) Dl 

BOOL success 

BPTR fh 

Deletes all buffers for a  file. When reading from a  file, Seek() 

is used to locate the old position. fh FileHandle

0 Error 

IFPutC 

Output a  character] 

Call: 

Function: 

Parameters: 

Result: 

char =  FPutC(fh, char)
DO -312 (A6) Dl D2 

LONG char 

BPTR fh 

UBYTE char 

Buffered output of an individual character. 

fh FUeHandle char Output byte The printed character or EOF in the case of an error.

|FRead Read data blocks from a  file | 

Call: count =  FRead(fh, buf, blocklen, blocks) 

DO -324 (A6) Dl D2 D3 D4 

LONG count 

BPTR fh 

APTR buf 

ULONG blocklen, blocks 

Function: Attempts a  buffered read of the given number of blocks 

from a  file.

Parameters: fh FileHandle to use for buffered I/O. 

buf Buffer for writing the blocks that are read. blocklen Block length blocks Number of blocks to read.

Result: Number of blocks actually read (EOF or read error aborts 

the read operation).

Warning: You must first use SetIoErr() to delete the error code if a 

query is necessary.

I FWrite Write data blocks to a  file | 

Call: count =  FWrite (fh, buf, blocklen, blocks) 

DO -330 (A6) Dl D2 D3 D4 

LONG count 

BPTR fh 

APTR buf 

ULONG blocklen, blocks 

Function: Attempts a  buffered write of the given number of data 

blocks to a  file.

Parameters: fh FileHandle 

Result: 

buf Buffer containing the data to be written. blocklen Block length blocks Number of blocks to write.

Number of blocks actually written (aborted in the case of 

an error).

Warning: Use SetloErr to delete the error code before using IoErrQ. 

Ilslnteractive 

Is a  file a  virtual terminal?! 

Call: status =  Islnteractive (  file ) 

DO -216 (A6) Dl 

BOOL status 

BPTR file 

Function: Checks a  file to see if it's a  virtual terminal (for example, a 

console window).

Parameters: file 

Result: 0 

FileHandle of the file. 

Normal file, not a  terminal. 

I Lock 

Obtain access to a  file or directory | 

Call: lock =  Lock( name, accessMode ) 

DO -84 (A6) Dl D2 

BPTR lock 

APTR name 

LONG accessMode 

Function: Attempts to secure access to a  file or directory. This can be 

exclusive access (ACCESS_WRITE), which prevents other programs from accessing the file, or shared access
(ACCESS_READ). 

Parameters: name Filename and/or path name 

Result: 

accessMode

Access mode 

BPTR to a  lock structure or 0. 

ILockRecord 

Obtain access to part of a  file | 

Call: success =  LockRecord(fh, offset, length, mode, timeout) 

DO -270 (A6) Dl D2 D3 D4 D5 

ULONG success, off set, length, mode, timeout 

BPTR fh 

Function: Grants access to part of a  file. A  specific timeout period can 

be set.

Parameters: fh 

FileHandle for the file. 

offset

Start of record 

length

End of record 

mode

Access mode: 

REC_EXCLUSIVE 

Exclusive access 

REC_EXCLUSIVE_IMMED 

Exclusive access, ignore 

timeout

Result: 

REC_SHARED Shared access 

REC_SHARED_IMMED 

Shared access, ignore 

timeout timeout Timeout period in l/50th seconds (0 allowed).

0 Error or access not possible. 

ILockRecords 

Secure access to several parts of a  file | 

Call: success =  LockRecords(record_array, timeout) 

DO -276 (A6) Dl D2 

BOOL success 

STRUCT RecordLock *record_array 

ULONG timeout 

Function: This function locks several parts of the file at once. A 

specific timeout period can be set.

Parameters: record_array 

List of RecordLock structures. 

timeout Timeout period (0 allowed)

Result: 0  Error or one or more of the records not free. 

I Open Open a  file | 

Call: file =  Open( name, accessMode ) 

DO -30 (A6) Dl D2 

BPTR file 

APTR name 

LONG accessMode 

Function: Attempts to open an existing file (MODE_OLDFILE) or 

create a  new file (MODE_NEWFILE). If
MODE_READWRITE is specified, a  file is opened and 

created, if it doesn't already exist.

Parameters: name Filename 

accessMode

Access mode 

Result: BPTR to a  FileHandle structure or 0. 

IQpenFromLock Open file associated with a  lock| 

Call: fh =  OpenFromLock(lock) 

DO -378 (A6) Dl 

BPTR fh.lock 

Function: Opens a  file associated with a  given lock. The access mode 

is determined by the lock.

Parameters: lock Lock structure of a  file. 

Result: FileHandle or 0 

| Read Read data from a  file | 

Call: actualLength =  Read( file, buffer, length ) 

DO -42 (A6) Dl D2 D3 

LONG actualLength, length 

BPTR file 

APTR buffer 

Function: Read data from a  given file to a  buffer. 

Parameters: file FileHandle 

buffer Read buffer length Number of bytes to read

Result: Number of bytes actually read (0 indicates end-of-file) or -1 

(error). 

| Rename Rename a  file or directory | 

Call: success =  Rename (   oldName, newName ) 

DO -78 (A6) Dl D2 

BOOL success 

APTR oldName , newName 

Function: Assigns a  new name to a  file or directory. If a  new path is 

also given, the renamed object is moved to the new directory.

Parameters: oldName Old name 

newName New name

Result: 0  Error 

SameLock Compare two locks | 

Call: value =   SameLock (lockl, lock2) 

DO -420 (A6) Dl D2 

LONG value 

BPTR lockl, lock2 

Function: Compare two locks. Returns a  value of LOCKJSAME if 

the same object is found, LOCK_SAME_HANDLER for different objects that belong to the same handler, or
LOCK_DIFFERENT if the handlers are different. 

Parameters: lockl, lock2 

The locks to be compared.

Result: See function. 

I Seek Change read/write position in a  file] 

Call: oldPosition =  Seek( file, position, mode ) 

DO -66 (A6) Dl D2 D3 

LONG oldPosition, position, mode 

BPTR file 

Function: Seek() sets the read/write position within a  file relative to 

the start of the file, the current position, or the end of the file. The old position is returned as the result.

Parameters: file FileHandle for the file. 

position Relative value mode Start, relative, or end

Result: Old position relative to the start of the file. 

| SetComment Set file comments] 

Call: success =  SetComment (   name, comment ) 

DO -180 (A6) Dl D2 

BOOL success 

APTR name , comment 

Function: Sets new comments for the given file. 

Parameters: name Filename 

comment Comment string (max. 80 characters)

Result: DO 0  in case of error 

| SetFileDate Set revision date for a  file| 

Call: success =  SetFileDate (name, date) 

DO -396 (A6) Dl D2 

BOOL success 

aptr name

STRUCT Dates tamp *date 

Function: Sets the revision date for a  file or directory, as long as it's 

allowed by the filesystem.

Parameters: name Object name 

date DateStamp structure with new date.

Result: 0  Error 

ISctFileSize

Set the size of a  file I 

Call: newsize =  SetFileSize(fh, offset, mode) 

DO -456 (A6) Dl D2 D3 

LONG newsize, off set, mode 

BPTR fh 

Function: Sets the file size for the given file, as long as this is allowed 

by the filesystem. The position is specified the same as with
Seek(). 

Parameters: fh 

offset mode

FileHandle for the file. 

Relative value 

OFFSET_BEGINNING, OFFSET_CURRENT 

or OFFSET END.

Result: 

File length or -1 (error). 

ISetProtection 

Set protection status for a  filel 

Call: success =  SetProtection( name, mask ) 

DO -186 Dl D2 

Function: 

BOOL success 

APTR name 

LONG mask 

Sets the protection status for a  file or directory. The status 

consists of an OR combination of various flags:

Bit 4: A  1 

Bit 3: R  1 

Bit2:Wl 

Bit 1: El 

BitO:Dl 

Parameters: name 

mask file unchanged 0 read not allowed 0 write not allowed 0 not executable 0 delete not allowed 0

Filename 

Protection status 

file changed read allowed write allowed executable delete allowed

Result: 

Error 

lUnGetC

Returns a  byte to the buffer! 

Call: value =  UnGetC(fh, character) 

DO -318 (A6) Dl D2 

LONG value, character 

BPTR fh 

Function: Returns a  byte to the input buffer. If the value -1 is passed, 

the last character read from the buffer is put back.

Parameters: fh FileHandle for buffered I/O. 

character Character or - 1

Result: Returned character or 0  (error). 

|UnLock

Remove lockl 

Call: UnLock( lock ) 

-90 (A6) Dl 

BPTR lock 

Function: Removes a  lock and frees the allocated memory. 

Parameters: lock BCPL pointer to a  lock structure. 

|UnLockRecord 

Free part of a  filej 

Call: success =  UnLockRecord(fh,off set, length) 

DO -282 (A6) Dl D2 D3 

BOOL success 

BPTR fh 

ULONG offset, length 

Function: Frees part of a  file that was locked with LockRecord(). 

Parameters: fh FileHandle given with LockRecordQ. 

Result: 

offset Start of record length Length of record
0 Error 

UnLockRecords 

Free several parts of a  file| 

Call: success =  UnLockRecords (record_array) 

DO -288 (A6) Dl 

BOOL success 

STRUCT RecordLock *record_array 

Function: Frees multiple records locked with LockRecords(). 

Parameters: record_array 

List of records to free 

Result: 

Error 

IVFPrintf 

Write formatted string to a  fiie| 

Call: count =  VFPrintf(fh, fmt, argv) 

DO -354 (A6) Dl D2 D3 

LONG count 

BPTR fh 

APTR fmt, argv [] 

Function: Formats a  string and does a  buffered write of the result to a 

file.

Parameters: fh FileHandle for the file. 

fmt Format string for exec/RawDoFmt(). argv Address of data array.

Result: Number of bytes written or - 1 (error). 

[VFWritef VFPrintf for BCPL strings | 

Call: count =  VFWritef(fh, fmt, argv) 

DO -348 (A6) Dl D2 D3 

LONG count 

BPTR fh 

APTR fmt, argv [] 

Functions, Parameters, and Results: 

Same as VFPrintf, except the strings are BSTR or BCPL. 

rWrite Write to a  filel

Call: returnedLength =  Write (  file, buffer, length ) 

DO -48 (A6) Dl D2 D3 

LONG returnedLength, length 

BPTR file 

APTR buffer 

Function: Writes a  specified number of bytes to a  file. 

Parameters: file FileHandle 

buffer Address of the bytes. length Number of bytes to write.
Result: Number of bytes actually written. 

Open() modes: 

MODE_OLDFILE =  1005 ,-open existing file 

MODE_NEWFILE =  1006  create new file 

MODE_READWRITE =  1004 open file (1005 (->1006)) 

FileHandle structure: 

Dec Hex STRUCTURE FileHandle, 0 

0 $0 APTR fh_Link Exec message 

4 $4 APTR fh_Port   answer port for Packet 

8 $8 APTR fh_Type port for PutMsgO 

$c 

LONG 

fh_Buf

$10 

LONG 

fh_Pos

$14 

LONG 

fh_End

$18 

LABEL 

fh_Funcl

$18 

LONG 

fh_Funcs

$1C 

LONG 

fh_Func2

$20 

LONG 

fh_Func3

$24 

LABEL 

fh_Argl

$24 

LONG 

fh_Args

$28 

LONG 

fh_Arg2

$2C 

LABEL 

fh_SIZEOF

Points of reference for Seek(): 

OFFSET_BEGINNING =  -1  start of file 

OFFSET_CURRENT =   0 /current position 

OFFSET_END =   1 end of file 

OFFSETBEGINING =  OFFSET_BEGINNING 

Structure ofLock(), etc.: 

Dec Hex STRUCTURE FileLock.O 

$0 BPTR 

$4 LONG 

$8 LONG 

$C APTR 

$10 BPTR 

fl_Link next Lock fl_Key  block number on disk fl_Access  access mode fl_Task  Handler port fl_Volume .-Volume Node (DosList)

20 $14 LABEL fl_SIZEOF 

SHARED_LOCK 

EXCLUSIVE_LOCK 

ACCESS_READ 

ACCESS WRITE 

Locki) modes: 

= -2  shared access 

= -1  exclusive access 

= SHARED_LOCK 

= EXCLUSIVE_LOCK 

SameLockO values: 

LOCK_SAME =  0 ,- objects identical 

LOCK_SAME_HANDLER =   1  objects have same Handler 

LOCK_DIFFERENT =  -1  completely different Locks 

ChangeMode() types: 

CHANGE_LOCK =  0 Lock structure 

CHANGE_FH =  1 FileHandle structure 

LINK_HARD =  0 

LINK_SOFT =  1 

REC_EXCLUSIVE 

REC_EXCLUS IVE_IMMED 

REC_SHARED 

REC_SHARED_IMMED 

MakeLink() values: 

LockRecord()ILockRecords() modes: 

= 0  /exclusive access 

1  exclusive with no waiting 

= 2   shared access 

= 3   shared with no waiting 

LockRecords()/UnLockRecords() structure: 

Dec Hex STRUCTURE RecordLock, 0 

0 $0 BPTR 

4 $4 ULONG 

8 $8 ULONG 

12 $C ULONG 

16 $10 LABEL 

rec_FH rec_Offset rec_Length recMode

FileHandle 

start (offset) record length
Lock type 

RecordLock_S I ZEOF 

8. Strings 

lAddPart

Add filename to path string | 

Call: success =  AddPart (   dirname, filename, size ) 

DO -882 (A6) Dl D2 D3 

BOOL success 

APTR dirname 

APTR filename 

ULONG size 

Function: Adds a  filename to a  path name according to DOS 

conventions. The filename may also contain path information. If the filename is a  complete path, then the old path is replaced.

Parameters: dirname Path name 

filename (path +)filename, 7  or ':' allowed size Size of buffer that contains dirname.

Result: 0  Error (buffer too small) 

See also: Filepart(), PathPart() 

iDateToStr Generate string from DateStampI

Call: success =  DateToStr( datetime ) 

DO -744 (A6) Dl 

BOOL success 

STRUCT DateTime *datetime 

Function: Generates a  string for a  DateStamp structure according to 

the given DateTime structure.

Parameters: datetime Address of a  DateTime structure, which must be 

initialized as follows: dat_Stamp Copy of the DateStamp. dat_Format String format (FORMAT_DOS dd-mmm-yy, FORMATJNT yy- mmm-dd, FORMATUSA mm- dd-yy or FORMAT_CDN dd- mm-yy). dat_Flags DTF_SUBST generates the day of the week (Monday, Today...). dat_StrDay Address of the day buffer or 0  if not used. dat_StrDate Address of the date buffer or 0 if not used. dat_StrTime Address of the time buffer or 0  if not used.

Result: 0  DateStamp error 

See also: DateStampO, StrToDateQ 

I Fault 

Generate error message! 

Call: success =  Fault (code, header, buffer, len) 

DO -468 (A6) Dl D2 D3 D4 

BOOL success 

LONG code, len 

APTR header, buffer 

Function: Converts an error code into a  string for the console 

window, printer, or a  text file (with line feed). This is preceded by the given header text. Error messages should not be more than 80 characters, and headers should not be more than 60. If a  certain code has no message text, the string "Error code <number>" is used.

Parameters: code Error code from IoErr(). 

header Header text buffer Buffer for the complete error message. len Buffer length

Result: 0  Buffer too small or some other error. 

IFGets 

Read a  line from a  file | 

Call: buffer =  FGets(fh, buf, len) 

DO -33 6 (A6) Dl D2 D3 

APTR buffer, buf 

BPTR fh 

ULONG len 

Function: Reads a  line from a  file into a  buffer. One character less 

than the length of the buffer can be read, because the last character in the buffer must always be set to 0. If the entire line fits in the buffer, the character before the null byte is an end-of-line code (LF or CR). The I/O is buffered.

Parameters: fh 

FileHandle 

buf len

Buffer address 

Buffer length 

Result: 

IFilePart 

Address of the buffer or 0  if no characters could be read. If 

the end of the file is reached before the call, IoErr()=0. If an error occurs, IoErr()oO.

Extract the filename from a  path specification 

Call: fileptr =  FilePart( path ) 

DO -870 (A6) Dl 

APTR fileptr, path 

Function: Returns the start address for the file in a  given path 

specification.

Parameters: path Path string according to DOS conventions. 

Result: Start address for the file. 

See also: PathNameQ 

|FindArg~ 

Find a  keyword in an argument string | 

Call: index =  FindArg( template, keyword) 

DO -804 (A6) Dl D2 

LONG index 

APTR keyword, template 

Function: Returns the argument number for a  given keyword. 

Parameters: keyword Keyword to search for. 

template Argument string

Result: Argument number of the given keyword or -1 if the 

keyword was not found.

IFPuts 

Write a  string to a  file| 

Call: error =  FPuts(fh, str) 

DO -342 (A6) Dl D2 

LONG error 

BPTR fh 

APTR str 

Function: Buffered write of a  string to a  file. 

Parameters: fh FileHandle 

str String ending in 0.

Result: Negative Error 

IGetArgStr 

Retrieves an argument string from CLl| 

Call: 

ptr =  GetArgStrO
DO -534(A6) 

APTR ptr 

Function: Returns the argument address found in the A0 register 

when the program is started. This is only useful for high level languages that do not use an argument parser.

Result: Address of the argument string from CLI or 0. 

| GetCurrentDirName Retrieve the name of the current directory 

Call: success =  GetCurrentDirName (buf, len) 

DO -564 (A6) Dl D2 

BOOL success 

APTR buf 

LONG len 

Function: Gets the name of the current directory from the CLI 

structure of its own process.

Parameters: buf Buffer for the name. 

len Buffer length

Result: 0  No CLI structure or no directory. 

| GetProgramName Returns the program's own name | 

Call: success =  GetProgramName (buf , len) 

DO -576 (A6) Dl D2 

BOOL success 

APTR buf 

LONG len 

Function: Copies the program name from the CLI structure to a 

buffer.

Parameters: buf Buffer address 

len Buffer length

Result: 0       Buffer too small or CLI structure not found. 

GetPrompt Retrieve the prompt string for a  process | 

Call: success =  GetPrompt (buf , len) 

DO -588 (A6) Dl D2 

BOOL success 

APTR buf 

LONG len 

Function: Copies the prompt string from the CLI structure to a  buffer. 

Parameters: buf Buffer address 

len Buffer length

Result : 0  Buffer too small or CLI structure not found. 

IMatchPattern 

Test a  string against a  pattern | 

Call: match =  MatchPattern (pat , str) 

DO -846 (A6) Dl D2 

BOOL match 

APTR pat, str 

Function: Checks to see if the given string matches a  given pattern. 

Parameters: pat Pattern string from ParsePattern(). 

str String to be checked.

Result: 0  String does not match pattern. 

INameFromFH

Get the filename from the FileHandlel 

Call: success =  NameFromFH(fh, buffer, len) 

DO -408 (A6) Dl D2 D3 

BOOL success 

BPTR fh 

APTR buffer 

LONG len 

Function: Writes the file and path name of the given FileHandle to a 

buffer.

Parameters: fh 

buffer len
Result: 0 

INameFromLock 

FileHandle 

Buffer for result string. 

Buffer length 

Error or buffer too small. 

Retrieve the name and path of a  lock | 

Call: success =  NameFromLockdock, buffer, len) 

DO -402 (A6) Dl D2 D3 

BOOL success 

BPTR lock 

APTR buffer 

LONG len 

Function: Writes the name and path of the given lock to a  buffer. 

Parameters: lock Lock 

buffer Buffer len Buffer length

Result: 0  Error (IoErr()=ERROR_LINE_TOO_LONG) 

IParsePattern 

Call: 

Generate token string for MatchPatternQ] 

Iswild =  ParsePattern (Source, Dest,DestLength) 

dO -840 (A6) Dl D2 D3

LONG IsWild,DestLength 

APTR Source, Dest 

Function: Creates a  token string for the MatchPattern() function. 

Parameters: source Pattern string 

dest Buffer for token string.

DestLength 

Buffer length (min. 2*Source+2). 

Result: 1  string contains wildcards (#, ?  etc.) 

0 string contains no wildcards. 

-1 buffer too small or error. 

[PathPart 

Call: fileptr =  PathPart (  path ) 

DO -876 (A6) Dl 

APTR fileptr, path 

Retrieve the end of a  path specification | 

ns

3. Programming with AmigaOS 2a 

Function: Returns the address of the end of a  path specification. 

Parameters: path Filename (with path) according to DOS 

standards.

Result: Address of the part of the path that disappears when 

another file is selected in a  file selection box.

See also: FilePart() 

| SplitName Retrieve part of a  path specification | 

Cfl//.' newpos =  SplitName (name, separator, buf, oldpos, size) 

DO -414 (A6) Dl D2 D3 D4 D5 

WORD newpos, oldpos 

APTR name, buf 

UBYTE separator 

LONG size 

Function: Copies the next part of a  complete file/path name to a 

separate buffer.

Parameters: name Filename with path. 

separator ASCII code of the separation character. buf Buffer oldpos Old position in string. size Buffer size in bytes.

Result: New start position for the next call (newpos->oldpos) or - 1 . 

| StrToDate Convert a  string to a  DateStamp [ 

Call: success =  StrToDate (  datetime ) 

. DO -750 (A6) Dl 

BOOL success 

STRUCT DateTime *datetime 

Function: Fills in a  DateStamp structure using the information from a 

string.

Parameters: datetime Initialized (!) DateTime structure. 

Result: 0  Error 

See also: DateToStr(), ubraries/datetime.h 

IStrToLong Convert a  decimal string to a  longwordl 

Call: characters =  StrToLong( string, value) 

DO -816 (A6) Dl D2 

LONG characters 

APTR string, value 

Function: Converts a  string containing a  decimal value into a 

longword.

Parameters: string Decimal string 

value Address of the resulting longword.

Result: Number of decimal places found or -1 (longword is then set 

toO).

StrToDate()/DateToStr() structure: 

Dec Hex STRUCTURE DateTime , 0 

0 $0 STRUCT dat_Stamp,ds_SIZEOF  DateStamp structure 

12 $C UBYTE dat_Format  dat_StrDate format 

13 $D UBYTE dat_Flags  Flags (see below) 

14 $E CPTR dat_StrDay day of the week string 

18 $12 CPTR dat_StrDate ,-date string 

22 $16 CPTR dat_StrTime time string 

26 $1A LABEL dat_SIZEOF 

LEN_DATSTRING =  16  length of a  date string 

Flags, Bits: 

DTB_SUBST =  0, DTF_SUBST =  1 create "Today" , "Tomorrow" .. . 

DTB_FUTURE= 1, DTF_FUTURE= 2  a future day 

Date formats: 

FORMAT_DOS =  0 dd-mmm-yy DOS format 

FORMAT_INT =  1 yy-mm-dd international format 

FORMAT_USA =  2 mm-dd-yy USA format 

FORMAT_CDN =  3 dd-mm-yy Canadian format 

FORMAT_MAX =  FORMAT_CDN 

9. Time 

[CompareDates Compare two UateStamps I 

Call: result =  CompareDates (datel,date2) 

DO -73 8 (A6) Dl D2 

LONG result 

STRUCT DateStamp *datel 

STRUCT DateStamp *date2 

Function: Compares the dates given in two DateStamp structures. 

Parameters: datel/date2 

DateStamp structures 

Result: negative: datel later than date2 

0: datel equals date2 

positive: date2 later than datel

See also: DateStampO 

[DateStamp Retrieves the current time| 

Call: DateStamp (  ds ) 

-192 (A6) Dl 

STRUCT DateStamp *ds 

Function: Fills the given DateStamp structure with the current time. 

Parameters: ds Address of a  DateStamp structure. 

Result: The structure is filled. 

| Delay Suspend own process for a  certain time period | 

Call: Delay (   ticks ) 

-198 (A6) Dl 

ULONG ticks 

Function: Own process is suspended for the given time period. 

Parameters: ticks Time period in l/50th second. 

IWaitForChar Wait for inputj 

Call: status =  WaitForChar( file, timeout ) 

DO -204 (A6) Dl D2 

BOOL status 

BPTR file 

LONG timeout 

Function: Waits a  specified number of microseconds (1/1000000) to 

see if a  character can be successfully read from the given file. This is very important for working with ports and terminals.

Parameters: file FileHandle for the file. 

timeout Time period in microseconds.

Result: 0  No character received during the wait period. 

Dec Hex STRUCTURE DateStamp.O 

0 $0 LONG ds_Days days since Jan. 1, 1978 

4 $4 LONG ds_Minute minutes since midnight 

8 $8 LONG ds_Tick  ticks since last minute 

12 $C LABEL ds_SIZEOF 

TICKS_PER_SECOND =  50  number of ticks per second 

10. Environment Variables 

I Delete Var 

Delete local environment variable | 

Call: 

success =  DeleteVar( name, flags )
DO -912 (A6) Dl D2 

BOOL success 

APTR name 

ULONG flags 

Function: Delete a  local ENV variable. 

Parameters: name 

flags

Result: 

String address with variable name (structured 

like a  filename).

Flags for variable type and function. 

GVF_LOCAL_ONLY 

Local variable (default) 

GVF_GLOBAL_ONLY 

Global variable 

Error. 

See also: GetVarO, SetVar() 

| Find Var 

Find local variable] 

Call: var =  FindVar( name, type ) 

DO -918 (A6) Dl D2 

STRUCT LocalVar *var 

APTR name 

ULONG type 

Function: Retrieves a  local variable. 

Parameters: name Variable name (structured like a  path name) 

type Variable type

Result: LocalVar structure or 0 

See also: GetVarQ, SetVar(), DeleteVar(), dos/var.h 

IGetVar 

Retrieve the value of a  variable! 

Call: len =  GetVar( name, buffer, size, flags ) 

DO -906 (A6) Dl D2 D3 D4 

LONG len, size 

APTR name , bu f  f er 

ULONG flags 

Function: Returns the value of an environment variable. If 

GVF_BINARY_VAR is not set, the function is interrupted 

when an LF character is encountered.

Parameters: name 

buffer size flags

Result: 

Variable name (AmigaDOS path) 

Buffer for the variable contents. 

Buffer size 

Variable type 

GVF_GLOBAL_ONLY 

Global ENV variable 

GVFLOCAL.ONLY 

Process-specific ENV 

variable

GVF_BINARY_VAR 

With control character

Total length of the variable (may be different from the 

buffer contents if the buffer terminates with 0) or -1 in the case of an error (variable not found).

See also: SetVar(), DeleteVarQ, dos/var.h 

ISetVar 

Create or set the value of a  variable | 

Call: success =  SetVar( name, buffer, size, flags ) 

DO -900 (A6) Dl D2 D3 D4 

BOOL success 

APTR name , bu f  f er 

LONG size 

ULONG flags 

Function: Sets a  local or environment variable. ASCII strings are only 

recommended.

Parameters. 

name

Filename of the variable. 

buffer

Contents of variable. 

size

Variable size (-1 =  string ending in 0) 

flags

Variable type 

Result: 

Eiror 

See also: 

GetVarO 

, Delete VarQ, dos/var.h 

Structure of prLocalVars list: 

Dec Hex STRUCTURE LocalVar, 0 

0 $0 STRUCT lv_Node,LN_SIZE node 

14 $E UWORD lv_Flags type 

16 $10 APTR lv_Value buffer 

20 $14 ULONG lv_Len ,-buffer length 

24 $18 LABEL LocalVar_SIZEOF 

LNJYPE bits in Ivjfode: 

LV_VAR =0 a variable 

LV_ALIAS =1 an ALIAS definition 

LVB_IGNORE =   7, LVF_IGNORE =   $80 

Values for variable functions: 

GVB_GLOBAL_ONLY =  8, GVF_GLOBAL_ONLY =  $100 

GVB_LOCAL_ONLY =  9, GVF_LOCAL_ONLY =  $200 

GVB_BINARY_VAR =  10, GVF_BINARY_VAR =  $400 

//. Errors and Requesters 

| Err or Report Display Retry/Cancel error requester | 

Call: status =  ErrorReport(code, type, argl, device) 

DO -480 (A6) Dl D2 D3 A0 

BOOL status 

LONG code, type 

ULONG argl 

STRUCT MsgPort *device 

Function: Displays the appropriate error requester. 

Parameters: code Error code (ERROR_..., ABORT....) 

type Requester type:

REPORTLOCK argl is a  lock (BPTR). 

REPORTJH argl is a    FileHandle 

(BPTR). 

REPORT.VOLUME 

argl is a  volume node
(CPTR). 

argl Parameter (according to type) device (optional) HandlerPort address (only needed for REPORT_LOCK with argl =0)

Result: DOS_TRUE 'Cancel' or error 

0 'Retry' or DISKINSERTED (for certain errors) 

IoErr 

Retrieve additional system error information] 

Call: 

Function: 

Result: 

See also: 

error =  IoErr ( )
DO -132 (A6) 

LONG error 

For functions that return a  value of 0  when errors occur.
IoErr() is used to retrieve more information on the cause of 

the error. Other functions use IoErr() to return a  second result to accommodate programming in C.

Error code or second result. 

OpenQ, DoPktQ 

IPrintFault 

Send error message to the output channel] 

Call: success =   PrintFault (code, header) 

DO -474 (A6) Dl D2 

BOOL success 

LONG code 

APTR header 

Function: The given header string is combined with the error message 

associated with the given error code and sent in a  buffered output to the default output channel.

Parameters: code Error code (see IoErr()) 

header Header text to precede the error message text.

Result: 0  Error 

IPutStr 

Send a  string to the default output channel] 

Call: 

error

■ =  PutStr( 

3tr) 

DO 

-948(A6) 

Dl 

LONG 

error

APTR 

str

Function: Buffered output of a  given string to the default output 

channel.

Parameters: str Output string 

Result: 0  in the case of an error. 

ISetloErr 

Set error codel 

Call: oldcode =  SetloErr (code) 

DO -462 (A6) Dl 

LONG code 

Function: Sets a  new value for the result of the IoErr() function 

(pr_Result2). 

Parameters: code 

Error code for IoErrQ. 

Result: oldcode Previous value of pr_Result2. 

IoErr() error codes: 

ERROR_NO_FREE_STORE =  103 

ERROR_TASK_TABLE_FULL =  105 

ERROR_BAD_TEMPLATE =  114 

ERROR_BAD_NUMBER =  115 

ERROR_REQUIRED_ARG_MISSING =  116 

ERROR_KEY_NEEDS_ARG =  117 

ERROR_TOO_MANY_ARGS =  118 

ERROR_UNMATCHED_QUOTES =  119 

ERROR_LINE_TOO_LONG =  120 

ERROR_FILE_NOT_OBJECT =  121 

ERROR_INVALID_RESIDENT_LIBRARY= 122 

ERROR_NO_DEFAULT_DIR =201 

ERROR_OBJECT_IN_USE =  202 

ERROR_OBJECT_EXISTS =20 3 

ERROR_DIR_NOT_FOUND =  204 

ERROR_OBJECT_NOT_FOUND =205 

ERROR_BAD_STREAM_NAME =20 6 

ERROR_OBJECT_TOO_LARGE =  207 

ERROR_ACTION_NOT_KNOWN =209 

ERROR_INVALID_COMPONENT_NAME =210 

ERROR_INVALID_LOCK =211 

ERROR_OBJECT_WRONG_TYPE =212 

not enough storage space too many Tasks command format error invalid value missing a  required argument keyword with no argument too many arguments quotes missing line too long not a  normal file error in header Hunk no default directory object being used object already exists unknown directory object could not be found invalid name object is too big unknown Packet invalid component name invalid Lock structure wrong object type

ERROR_DISK_NOT_VALIDATED =213 

ERROR_DISK_WRITE_PROTECTED =  214 

ERROR_RENAME_ACROSS_DEVICES =  215 

ERROR_DIRECTORY_NOT_EMPTY =216 

ERROR_TOO_MANY_LEVELS =217 

ERROR_DEVICE_NOT_MOUNTED =  218 

ERROR_SEEK_ERROR =219 

ERROR_COMMENT_TOO_BIG =220 

ERROR_DISK_FULL =221 

ERROR_DELETE_PROTECTED =222 

ERROR_WRITE_PROTECTED =223 

ERROR_READ_PROTECTED =  224 

ERROR_NOT_A_DOS_DISK =  225 

ERROR_NO_DISK =  226 

ERROR_NO_MORE_ENTRIES =  2 32 

ERROR_IS_SOFT_LINK =23 3 

ERROR_OBJECT_LINKED =234 

ERROR_BAD_HUNK =235 

ERROR_NOT_IMPLEMENTED =23 6 

ERROR_RECORD_NOT_LOCKED =  240 

ERROR_LOCK_COLLISION =  241 

ERROR_LOCK_TIMEOUT =  242 

ERROR_UNLOCK_ERROR =  243 

ERROR_BUFFER_OVERFLOW =  3 03 

ERROR_BREAK =  3 04 

ERROR_NOT_EXECUTABLE =3 05 

disk is not validated disk is write-protected rename error directory is not empty too many levels unknown device

Seek() error 

comment too long disk is full delete protected write protected read protected not a  DOS disk no disk found end was reached software link object linked invalid Hunk type not implemented

(see LockRecord( ) ) 

Lock collision 

Lock timeout period expired 

Unlock error 

buffer too small break character not executable

FAULT_MAX =  82 max. length of an error string 

Error message structure: 

Dec Hex STRUCTURE ErrorString, 0 

0 $0 APTR estr_Nums 

4 $4 APTR estr_Strings 

8 $8 LABEL ErrorString_SIZEOF 

ErrorReport() types: 

REPORT_STREAM =  0 

REPORT_TASK =  1 

REP0RT_L0CK =  2 

REP0RT_V0LUME =  3 

REPORT_INSERT =  4 

"please insert volume. 

ErrorReport() error codes: 

ABORT_DISK_ERROR =296  read/write error 

ABORT_BUSY =  288  "You MUST replace...* 

DOS boolean values: 

DOSTRUE 

DOSFALSE 

-1 true 

0  false 

General values: 

BITSPERBYTE 

BYTESPERLONG 

BITSPERLONG 

MAXINT 

MININT 

8   8 bits =  1 byte 

= 4  4 bytes =  1 long 

= 32 32 bits =  1 long 

= $7FFFFFFF  maximum LONG value 

= $80000000 .-minimum LONG value 

Basis structure: 

Dec 

Hex 

STRUCTURE DosLibrary,0 

$0 

STRUCT 

dl_lib,LIB_SIZE

Library node 

$22 

APTR 

dl_Root

RootNode 

$26 

APTR 

dl_GV

BCPL 

global vector

$2A LONG 

dl_A2

PRIVATE 

$2E LONG 

dl_A5

PRIVATE 

$32 

LONG 

dl_A6

PRIVATE 

$36 

APTR 

dl_Errors array with error messages

$3A APTR 

dl_TimeReq

PRIVATE: timer request 

$3E 

APTR 

dl_UtilityBase

PRIVATE: utility library 

$42 

LABEL 

dl_SIZEOF

Dec 

Hex 

STRUCTURE RootNode.O 

$0 

BPTR 

rn_TaskArray

 CLI Process Array [ 0 ] =number 

$4 

BPTR 

rn_ConsoleSegmenl

CLI SegList 

$8 

STRUCT 

rn_Time, ds_SIZE01

? 

current time

$14 

LONG 

rn_RestartSeg

D\disk validator SegList 

$18 

BPTR 

rn_Info

 Info structure 

$1C 

BPTR 

rn_FileHandlerSe< jment

FileHandler 

$20 

STRUCT 

rn_CliList,MLH_S tZE

CLI processes 

$2C 

APTR 

rn_BootProc

 PRIVATE: pr_MsgPort 

$30 

BPTR 

rn_She 1 lSegment

Shell SegList 

$34 

LONG 

rn_Flags

 Flags 

$38 

LABEL 

rn_SIZEOF

RNB_WILDSTAR =  24, RNF_WILDSTAR =  $1000000 

Dec Hex STRUCTURE CliProcList, 0 

0 $0 STRUCT cpl_Node,MLN_SIZE for linking 

8 $8 LONG cpl_First  first CLI number 

12 $C APTR cpl_Array CLI Process Array 

16 $10 LABEL cpl_SIZEOF 

Dec 

Hex STRUCT!. 

IRE Doslnfo, 0 

$0 BPTR 

di_McName network name of device

$4 BPTR 

di_DevInfo list of logical devices

$8 BPTR 

di_Devices devices

$C BPTR 

di_Handlers

/Handlers 

$10 APTR 

di_NetHand current network

Handler 

$14 STRUCT 

di_DevLock, SS_SIZE

 PRIVATE ! ! ! 

$42 STRUCT 

di_EntryLock, ss.

.SIZE 

 PRIVATE ! ! ! 

$70 STRUCT 

di_DeleteLock, ss.

.SIZE 

 PRIVATE ! ! ! 

$9E LABEL 

di_SIZEOF

Example 

The volume of these new functions is overwhelming. It's difficult to update existing programs by replacing the old functions with new ones.
Assembler programmers should prepare for some big changes to their 

programs, because the query of arguments has been simplified and automated. This is a  completely different approach to programming. As a result, programming that conforms to the operating system is easier to achieve in Assembler than in higher level languages. Since the main routines of all CLI commands are now located in the operating system, extremely short programs are possible. As an introduction to OS 2  programming, it is recommended to try a  few CLI commands first, and then gradually work up to larger programs. A disadvantage with Assembler used to be the complicated argument queries this has been eliminated with OS 2. We will use a  simple CLI command to help you through the programming procedure. For this exercise we want to emphasize the basic structure and argument queries, so we will construct a  command that is executed using a  new DOS function: AddBuffers.

We are not referring to the long, slow CLI command (written in C) of the 

same name. Instead, we are creating a  completely new command that has the same function. We will also have to mention some of the dangers of using your own custom routines.

The AddBuffers functions receives a  device name and a  delta value, which may also be negative. This number represents the number of buffers to be added. The function result will be the current number of available buffers. This command will be able to simply query the number of available buffers or change it by passing a  delta value. The first parameter is the device name, and this parameter is required with the function call. If a  second parameter is given, it must be a  number. This number will be taken as the delta value. We will call our new command
'Buffer'. The following is the program header: 

************************ *<par t -1>* *********************** * 

**_______________________________________.________________** 

** CLI command structure under OS 2  (v37) ** 

** example of a  new AddBuffers command ** 

** ** 

** Call: Buffer DRIVE/A, BUFFERS/N ** 

** DRIVE -  drive letter ** 

** BUFFERS -  optional, number of buffers to add (+)** 

** or subtract (-) ** 

** ** 

** written (w) 1991 by Stefan Maelger ** 

** _______ ______________ _________ ________________________** 

INCLUDE_VERS_ON =    3 6 

RETURN_OKAY =     0 

RETURN_FAIL =    20 

ERROR_INVALID_RESIDENT_LIBRARY =   122 

ThisTask =27 6 pr_Result2 =   148

_LVOOpenLibrary =  -552 

_LVOCloseLibrary =  -414 

_LVOIoErr =  -132 

_LVOPrintFault =  -474 

_LVOAddBuffers =  -732 

_LVOReadArgs =  -798 

_LVOFreeArgs =  -858 

_LVOVPrintf =  -954 

**************** *******<part-2>* ****************** ******** 

Here we have defined the purpose of the program. All of the required system values have been set and the Include files have been linked. Our program should be re-entrable, meaning it can be kept in memory via
RESIDENT after setting the PURE flag. In order to do this, we must save 

all registers from number 2  on up before we use them. The longword at address 4  contains the address of the operating system base structure. This can vary, depending on the operating system and the available memory. This same address is also the base address of the main library
EXEC, which can then be used to get the base address of the DOS 

library.

***********************<par£_2>***** ************** ******** 

SECTION Program, CODE 

_Start 

movem.l d2-d6/a6, -(a7) save registers

** 

** Open the DOS-Library 

** 

movea.l $4.w,a6  load ExecBase lea _DOSName(pc) , al  Library name moveq #INCLUDE_VERSION,dO OS 2, v36 and up jsr _LVOOpenLibrary(a6)  OpenLibrary (al,dO) moveq #RETURN_FAlL,d4  error for DOS move . 1 dO , d5  save DosBase beq.s _NotDOS => if DosBase=0

*********************** 

< Par t - 3 >************************** * 

All of the functions required for this command are available, starting with version 36 (first version of OS 2). This version number must be specified. The D4 register saves the value returned from CLI, which we immediately set to an error. This is only changed to 'no error' after successful initialization. This saves us a  lot of writing. If DOS could not be opened, which should only occur with older OS versions, then we branch to the appropriate error handling routine.

Some of you will have noticed that we made no efforts to save the value 

returned from CLI (A0=ArgBuf, D0=ArgLen). With OS 2, this is no longer necessary. We can get the arguments with the DOS function
ReadArgs, which handles all the work of passing arguments from the 

user.

******************* ****<part-3>** **************** ********* 

** 

** Get CLI arguments 

** 

exg d5,a6

 Store 

argument field in clr.l

-<a7) 

clr.l

-(a7) 

clr.l

-(a7) 

clr.l

-(a7) 

 Query 

arguments lea

_Template (pc) , aO 

move . 1 aO,dl move . 1 a7,d2 moveq

#0,d3 

jsr

_LV0ReadArgs(a6) 

move . 1 d0,d6 bne.s

_parseArgs 

Exec<->Dos 

Dummy (size divisible by 16!) 

Dummy (size divisible by 16!) 

Arg[2] 

Arg[l] 

argument description to dl for call
.•argument field to d2 

no RDArgs structure
 ReadArgs (dl, d2 , d3 ) 

save RDArgs structure if RDArgsoO (okay)

*********************** 

<Part-4>*************************** 

ReadArgs expects a  string ending with a  null byte. This string describes 

all of the arguments involved. In it, each argument name is given followed by the argument type. The description of each argument is separated by a  comma. In our case, this string will contain
'DRIVE/A,BUFFERS/N'. Since we have described two arguments in the 

string, we need at least two longwords in the argument field to pass them. In order to avoid a  system crash, you should always make the field size in bytes divisible by 16. There's no need to get extra memory because there is sufficient space in the stack for four longwords. A  value of 0  is passed as the last parameter. An RDArgs structure obtained with
ReadArgs would be passed to this location, but is not necessary in our 

case.

WARNING: The argument field must be filled with null bytes before the 

call. The returned RDArgs structure is saved because this must be freed later.
We test the result for errors or for user interrupt. If everything is okay, we 

continue to evaluate the arguments otherwise an error handling routine is needed. Normally, CLI commands report the cause of an error using a readable message. This is handled by the PrintFault function, which uses the result of IoErr as a  parameter.

********* **************<part_4> *********** **************** 

  ReadArgs error: set return address 

pea _FreeStack(pc) ,-for following routine

** 

** Subroutine 

** Get DOS error and output cause as message text 

** 

_Zerror 

jsr _LV0IoErr(a6) ,- IoErr ( ) move.l dO,dl  error code to dl moveq #0,d2 no header text jmp _LV0PrintFault(a6)  ->PrintFault (dl, d2)

************ ******** ***<part-5>*** ***************** ******* 

In the 'Zerror' routine, we assume that the DosBase is stored in A6 and the D2 register can be changed at any time. Therefore, we don't need to save any of the registers and can jump to the PrintFault routine with a
JMP command. This corresponds to a  JSR followed by an RTS. This part 

of the program is structured as a  subroutine so that it doesn't have to be repeated for every error. In the case of a  ReadArgs error, we jump directly into this routine. Therefore, we must first store a  return address on the stack with PEA. Now we come to the part of the program where the arguments are evaluated.

WARNING: Freeing RDArgs is forbidden at this point, since this could 

cause the entries of the argument field to point to undefined memory blocks. As long as we are working with the argument field, RDArgs must not be manipulated.

***********************<P££.£_5> ********************* ****** 

** 

** Evaluate arguments 

** 

_parseArgs 

moveq #RETURN_OK,d4 save return code

test if two arguments were given move . 1

4(a7),d0 

get Arg[2] (buffer) beq.s

_AvailBuf fer 

if Arg[2]=0 execut e 'Buffers xxx yyy' command movea . 1 dO,aO

Arg[2] is address of value! 

move . 1

(a7),dl 

Argtl] to dl (DRIVE) 

move . 1

(a0),d2 

get value from address jsr

_LVOAddBuf fers (a6) 

AddBuffers(dl,d2) 

tst.l dO test result (error=0) bne.s

_AvailBuf fer 

if no error

 Error 

handling for RDArgs structure

_OutputError 

bsr.s _Zerror  output message bra . s _RDArgsFree  FreeArgs . . .

***********************<par^_g>*************************** 

Once the initialization is complete, we can be sure that no serious errors 

have occurred. Therefore, the return value (which was stored in D4) can be set to 'no error'. Next, we check to see if the number of buffers must be changed before we retrieve the number. The first argument is the address of the drive name, which can be placed directly to Dl. Since this argument is required (/A), we don't have to check for its presence.

WARNING: To distinguish between a  value of 0  and a  missing argument, 

numerical values (/N) require the address of a  longword in the argument field rather than the value itself. The longword then contains the actual parameter value. This address is moved to a  data register (DO). If the parameter is not present, the Z  flag would have been set. Then the address is moved to an address register (AO) in order to obtain the actual value relative to the address register (D2). If all of this is successful or if the buffer count was not asked to be changed, then the number of buffers are displayed. Otherwise, an error message is output and we jump to free RDArgs.

***********************<part_§>* ************* ************* 

Output number of available buffers 

_AvailBuf fer 

move.l (a7),dl Arg[l] to dl (DRIVE) moveq #0,d2 no change jsr _LVOAddBuffers(a6) AddBuf fers (dl,d2) move.l d0,4(a7) Arg[2]=Buffers bmi.s _OutputError if Buffers=-1 beq.s _RDArgsFree  FreeArgs . . . Format and output string lea _FormatString(pc) ,a0  format string move.l aO,dl to dl for call move.l a7,d2  field with arguments jsr _LVOVPrintf (a6) VPrintf (dl,d2)

***********************<par(-_7>*** ****************** ****** 

We go to 'AvailBuffer' if no change was made to the buffer count or after 

the buffer count has been changed. We only need the drive name for
AddBuffers, since the change in indicated by 0. The result is stored as the 

second argument in our argument field. In case of an error, a  message is displayed or the program is ended. VPrintf is used to output a  string to
CLI. The control codes of this string have been replaced by the entries of 

the field we want to pass. This field is simply our argument field the second entry of which we have changed to conform to our format string. Now we still have to restore the system changes that were made when the program was started. The first thing to do is free RDArgs with
FreeArgs. Then we restore the stack, which contains our longword field, 

and close the DOS library.

****************** *****<part-7>** ****************** ******* 

** Free RDArgs structure 

** 

_RDArgsFree 

move.l d6,dl  saved RDArgs jsr _LVOFreeArgs(a6)  FreeArgs (dl)

? 

 Restore stack 

_FreeStack 

addq.l #8,a7 addq.l #8,a7
** 

** Close DOS library 

restore a7

 (all 16 bytes) 

movea.l a6,al DosBase to al movea.l d5,a6 load ExecBase jsr _LVOCloseLibrary(a6) CloseLibrary (al) bra.s _Programend ->end program

********************** *<part -8>* ***************** * * * ** * * * * 

The error code that describes the error of a  program ended with
RETURN_FAIL is entered in the process structure for the program. Since 

every process begins with a  task structure, we can access this structure via ExecBase, which always has a  pointer to the currently running task. In the following section, which is used in the case of an OpenLibrary error, the error cause is sent to CLI. Then the program is ended. The return value is placed in DO and the registers are restored. After this are the strings you no longer have to worry about even or odd addresses since no more code follows.

***********************<part_g>**,**,****»*****4t*1.tittt4<. 

** Error opening DOS library: 

** Send error cause to DOS 

** 

_NotDOS 

moveq #ERROR_INVALID_RESIDENT_LIBRARY,dO DOS error code movea.l ThisTask(a6) ,a0 /Process structure for our program move.l dO , pr_Result2 (aO)  enter error cause

** End of program 

** 

_Programend 

move .1 d4 , dO movem.l (a7)+,d2-d6/a6 rts

** 

** Strings 

** 

return code for CLI
/restore registers 

return

_DOSName dc.b 'dos. library' , 0  library name 

.Template dc.b 'DRIVE/A, BUFFERS/N' , 0  f or ReadArgs 

_FormatString dc.b 'Drive %s has %ld buffers' , 10, 0 

************************<gjjp>*************** ****** ******* 

When you combine the individual pieces of this program, you will see that things are now much simpler than they once were. Once assembled, a program such as this is less than a  half a  block long. Each program requires at least a  FileHeader block in addition to this. So, you could store up to 439 programs of this type on a  normal diskette. In order to be able to use all mounted devices that may contain files, you first must obtain information about these 'Drives'. All such devices are included as DosEntries in the DosList. Since this list is constantly updated, it used to be necessary to turn off multitasking before searching for a  certain entry. Now, you can obtain access privileges with
LockDosList in order to prevent an update to the list while you are using 

it. Let's take a  look at how OS 2  retrieves information from this list:

**______________========================================** 

** Retrieve info on all FileSystem devices ** 

** ** 

** Input: A6 =  ExecBase ** 

** A5 =  DosBase ** 

** Output: DO =  simple linked list of the following ** 

** structures, which can be freed ** 

** with exec/FreeVec: ** 

STRUCTURE FileSysDev, 0 

APTR fsd_Next next structure 

STRUCT f sd_InfoData, id_SIZEOF  Inf oData structure 

STRUCT fsd_Name,36 name buffer 

LABEL fsd_SIZEOF  structure size 

Register contents in the routine: 

a6,a5 ExecBase and DosBase (these are often confused) a4 DosList structure a3 InfoData structure a2 last FileSysDev structure a0,al continuously changed d3 d6 arg4 for DosPacket: 0 d5 arg3 for DosPacket: 0

d4 arg2 for DosPacket : 0 d3 argl for DosPacket: BPTR to InfoData structure d0-d2 continuously changed

.GetFSDevs 

moveq #0,d0 movem.l d0/d2-d6/a2-a4,

-(a7) 

movea .1 a7 , a2 moveq #0,d4 moveq #0,d5 moveq #0,d6

InfoData =  AllocVec ( id_SIZEOF,MEMF_PUBLIC) 

moveq

#id_SIZEOF,dO 

moveq

#MEMF_PUBLIC,dl 

jsr

_LV0AllocVec(a6) 

tst.l dO beq.s

. Error 

movea . 1 d0,a3 asr .1

#2,d0 

move . 1 d0,d3 exg a5, a6 dlist =  LockDosList(LDF_DEVICES!LDF_READ) moveq #LDF_DEVICES!LDF_READ,dl jsr _LVOLockDosList (a6) movea .1 dO , a4
.Loop 

dlist =  NextDosEntry (dlist, LDF_DEVICES!LDF_READ) move.l a4,dl moveq #LDF_DEVICES ! LDF_READ , d2 jsr _LVONextDosEntry (a6) tst.l dO beq.s .NoMoreEntries movea .1 dO , a4 resl =  DoPkt(dol_Task,ACTI0N_DISK_INF0,InfoData»2, 0,0,0) move . 1 dol_Task (a4 ) , dl beq.s .Loop moveq #ACTION_DISK_INFO,d2 jsr _LVODoPkt(a6) tst.l dO beq . s . Loop

FileSysDev =  AllocVec ( f sd_SIZEOF, 

moveq

#fsd_SIZEOF,dO 

move . 1

#MEMF_CLEAR !MEMF_PUBLIC, dl 

exg a5,a6 jsr

_LV0AllocVec(a6) 

exg a5,a6 move . 1 dO, (a2) beq.s

.NoMoreEntries 

movea . 1 d0,a2 lea fsd_InfoData(a2) ,al movea . 1 a3,a0 moveq

#8,d0 

CopylD 

move . 1

(a0)+, (al) + 

dbra dO, .Copy ID movea . 1 dol_Name (a4 ) ,  aO adda . 1 aO,aO adda . 1 aO,aO move . b

(aO)+,dO 

moveq

#34, dl 

CopyBSt 

r move . b

(a0)+, (al)+ 

subq.b

#l,dO 

dble dl, . CopyBSt r move . b

#' :', (al) 

bra.s

.Loop 

NoMoreEntries 

UnLockDosList (LDF_DEVICES ! LDF_READ) 

moveq #LDF_DEVICES ! LDF_READ, dl jsr _LVOUnLockDosList (a6) exg a5,a6

FreeVec (InfoData) 

movea. 1 a3,al jsr _LVOFreeVec (a6)
.Error 

move.l (a7)+,d0 movem.l (a7) +,d2-d6/a2-a4 rts

Notice that the drive names are used here without the colon. 

About the program flow: 

1. Get memory for an InfoData structure. 

The memory block may not be moved, it must be allocated as
PUBLIC. The length and contents do not matter. The size must 

correspond to that of an InfoData structure. We use the new Exec function Alloc Vec() here, which stores the amount of memory. If a value of 0  is returned, the memory could not be allocated and we jump to step 6.

Note: The error cause can be output with PrintFault(IoErr(),0). 

2. Obtain access to DosList (if necessary, include LDF_VOLUMES 

and/or LDF.ASSIGNS).

WARNING 1: Don't forget LDF.READ. 

WARNING 2: The UnLockDosList function must be called with the 

same value.

WARNING 3: With a  reserved DosList, do not call functions that 

must change the DosList.

WARNING 4: The returned value is not a  DosList structure that can 

be processed.

3. Loop 

3a. Get next DosList structure of the desired type. To do this, either the 

last DosList structure or the value returned from LockDosList is passed as the DosList structure. If a  value of 0  is returned, then no more entries of the requested type are available and we jump to step
4. 

3b. The dol__Task entry contains the address of the MsgPort of the 

FileHandler process in question (pr_MsgPort). If a  value of 0  is 

found, then this is not a  data storage device and we jump to step 3.

3c. We can get the desired information from the FileHandler. In order to 

do this, we must first create a  StandardPacket structure, load it with the proper information, send it to the MsgPort of the FileHandler, and wait for an answer. The new DoPkt functions handle this for a simple StandardPacket. dol_Task, which is the desired action
(ACTION_DISK_INFO), and a  BPTR (address/4) to our InfoData 

structure, which is the only packet parameter, are passed to the
DoPkt function. If the handler does not understand our command, 

then we are not dealing with a  data storage device, so we jump to step 3.

3d. We use AllocVec() to reserve enough memory to hold the drive 

name, the complete InfoData structure, and pointers for linking the memory blocks. If this is unsuccessful, we jump to step 4.

3e. This memory block is linked to the last memory block allocated in 

this way. We copy the drive name and the InfoData structure. Since
DOS does not use colons with drive names, we add it to complete 

the string. Then we jump back to the start of the loop (step 3).

4. The DosList is set free. 

WARNING: You must give the same value used with LockDosList. 

5. The InfoData structure is set free. The FreeVec() function requires 

only the start address of its memory block.

6. End the program and return the list of linked memory blocks, that 

must be set free, with FreeVec():

.loop 

movea.l dO,al  first structure movea.l (al) ,a2 jsr _LVOFreeVec(a6) move .1 a2 , dO bne . s . loop

