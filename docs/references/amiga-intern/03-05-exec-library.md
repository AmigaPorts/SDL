# The Exec Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.5 The Exec Library

Exec is the base library of the operating system. It manages all other 

libraries, devices, resources, interrupts, programs, and the system memory.
Exec is often called 'Sys', so you may find ExecBase and SysBase used 

interchangeably. The routines for library management are also integrated into Exec. The base address of the Exec library is stored in the longword at $4. This address must be loaded to the A6 register for every function call.

Exec Library Functions 

1. System Module 

ColdReboot 

FindResident 

InitCode 

InitResident 

InitS tract 

MakeFunctions 

MakeLibrary 

SumKickData 

2. Interrupts 

AddlntServer 

Cause 

Disable 

Enable 

Forbid

GetCC 

Permit 

RemlntServer 

SetlntVector 

SetSR 

Superstate 

Supervisor 

UserState 

3. Memory Management 

AddMemList 

AllocAbs Allocate AllocEntry AllocMem AllocVec

AvailMem 

CopyMem 

CopyMemQuick 

Deallocate 

FreeEntry 

FreeMem 

FreeVec 

TypeOfMem 

4. Structure Management 

AddHead 

AddTail 

Enqueue 

FindName 

Insert 

RemHead 

Remove 

RemTail 

5. Programs 

8. Devices 

AddTask 

AbortIO 

AllocSignal

AddDevice 

AllocTrap

ChecklO 

CacheClearE 

CloseDevice 

CacheClearU 

CreatelORequest 

CacheControl 

DeletelORequest 

FindTask 

DoIO 

FreeSignal 

OpenDevice 

FreeTrap 

RemDevice 

RemTask 

SendIO 

SetExcept 

WaitIO 

SetSignal 

SetTaskPri 

9. Resources 

Signal 

Wait 

AddResource 

OpenResource 

6. Communications 

RemResource 

AddPort 

10. Semaphores 

Alert 

CreateMsgPort 

AddSemaphore 

Debug 

AttemptSemaphore 

DeleteMsgPort 

FindSemaphore 

FindPort 

InitSemaphore 

GetMsg 

ObtainSemaphore 

PutMsg 

ObtainSemaphoreList 

RawDoFmt 

ObtainSemaphoreShared 

RemPort 

Procure 

ReplyMsg 

ReleaseSemaphore 

WaitPort 

ReleaseSemaphoreList 

RemSemaphore 

7. Libraries 

Vacate 

AddLibrary 

CloseLibrary 

OldOpenLibrary 

OpenLibrary 

RemLibrary 

SetFunction 

SumLibrary 

## 3.1 The Libraries and their Functions

Description of Functions 

1. System Module 

[ColdReboot Cold system reboot! 

Call: ColdReboot ( ) 

-726(A6) 

Function: Resets the Amiga and all connected devices. This function 

corresponds to pressing the (Ictrll -Amiga-Amiga) keys simultaneously.

[FindResident Find a  system module] 

Call: resident =  FindResident (name) 

DO -96 (A6) Al 

STRUCT Resident *resident 

APTR name 

Function: Looks for a  resident tag for the given name. 

Parameters: name Address of the name (RT_NAME). 

Result: Address of the resident structure or 0. 

flnitCode Initialize resident code module |

Call: lnitCode(startClass, version) 

-72 (A6) DO Dl 

Function: Initializes all resident modules of the given type. 

RTF_AFTERDOS modules should have a  priority of less 

than -100. Modules without a  startClass value should have a priority of -120.

Parameters: startClass Hags for module type: RTF_COLDSTART, 

RTFJSDMGLETASK or RTF_AFTERDOS. 

version Version number

UnitResidenT 

Initialize resident module | 

Call: initResident (resident, segList) 

-102 (A6) Al Dl 

STRUCT Resident *resident 

ULONG segList 

Function: Initializes a  ROMTag. Normally jumps to the function 

stored in RTJNIT (A6=ExecBase, A0=segList, D0=0). However, if RTF_AUTOINIT is set, then RTJNIT points to four consecutive longwords for calling MakeLibrary(). These longwords contain the size of the base structure, table of library functions, table for InitStruct(), and the
RTJNIT function). 

llnitStruct

Initialize a  data structure | 

Call: InitStruct (initTable, memory, size) 

-78 (A6) Al A2 DO 

STRUCT InitStruct *initTable 

APTR memory 

ULONG size 

Function: Deletes a  data structure and initializes it with the values in 

the given table. The table can be created with the
MACROs from "exec/initializers.i". 

Parameters: initTable Table containing structure data (must end in 0). 

memory Address (even) of the data structure. size Structure size (even count of bytes) (0=do not delete first)

I MakeFunctions 

Generate library vector table! 

Call: 

tableSize =  MakeFunctions (target, functlonArray, funcDispBase)
DO -90 (A6) A0 Al A2 

ULONG tableSize 

APTR target, f unct ionArray , funcDispBase 

Function: Function for MakeLibrary(). Used to create a  vector table 

(negative base offsets). 

Parameters: target Base address of library/device. 

functionArray

Table with function addresses (ending in -1) or 

a table 'beginning with the Word -1 containing relative 16 bit offsets (ending in -1). funcDispBase

Address to be added to the relative 16 bit 

values, or 0.

Result: tableSize Vector table size (for LIB_NEGSIZE) 

IMakeLibrary Create a  library | 

Call: library =  MakeLibrary (vectors, structure, init, dSize, segList) 

DO -84 (A6) AO Al A2 DO Dl 

STRUCT Library 'library 

APTR vectors, init 

STRUCT InitStruct 'structure 

ULONG dSize 

BPTR segList 

Function: Initializes a  library structure. 

Parameters: vectors Function addresses for MakeFunctions(). 

structure Data for InitStruct() or 0. init Library RTJNIT routine or 0. dSize Size of base structure. segList Segment list (see dos/LoadSegO)
Result: Library base address or 0. 

ISumKickData 

Call: 

Calculate check sum across resident modules | 

checksum

DO 

SumKickData ( ) 

-612 (A6) 

ULONG checksum 

Function: Builds a  check sum across the linked list of resident 

modules (KickTagPtr) and MemEntry structures
(KickMemPtr). The check sum is stored in KickCheckSum, 

as long as "reset-proof" changes to the system will allow it.

Result: checksum Value for ExecBase->KickCheckSum 

Dec 

Hex 

$0 

$2 

$6 

$A 

$B 

$c 

$D 

$E 

$12 

$16 

$1A 

STRUCTURE RT, 0 

UWORD RTJ1ATCHWORD 

APTR RT_MATCHTAG 

APTR RT_ENDSKIP 

UBYTE RT_FLAGS 

UBYTE RT_VERSION 

UBYTE RT_TYPE 

BYTE RT_PRI 

APTR RT_NAME 

APTR RT_IDSTRING 

APTR RT_INIT 

LABEL RTSIZE 

residentTag/ROMTag

 ILLEGAL command 

start of structure (RT_MATCHWORD)

RT allowed starting with this address 

 Flags 

version module type (NT_...)

.•initialization priority 

,• module name 

identification string initialization routine/data

RTC_MATCHWORD =  $4 AFC 

RTB_COLDSTART 

RTB_SINGLETASK 

RTB_AFTERDOS 

RTB_AUTOINIT 

0, RTF_COLDSTART =    1 Init from reset 

1, RTF_SINGLETASK =   2 task 

2, RTF_AFTERDOS =   4 Init after DOS 

7, RTF_AUTOINIT =  $80 RT_INIT =  data 

RTW_NEVER 

do not initialize

2. Interrupts 

lAddlntServer

Insert an interrupt in a  server list| 

Call: AddlntServer (intNum, interrupt) 

-168 (A6) DO Al 

ULONG intNum 

STRUCT IS * interrupt 

Function: Links an IS structure in a  server list of an interrupt server. 

The given interrupt number is the number of an Amiga interrupt source, not that of a  processor interrupt. The interrupt routines must end with RTS and must set the processor's Z  flag if other interrupt routines are to be processed. The function is called with IS_DATA in Al.

Parameters: intNum 

Interrupt source with a  server (PORTS, COPER, 

VERTB, EXTER or NM). 

interrupt IS structure

Warning: Not suitable for high-level languages. For VERTB, the 

value $DFF000 must remain in the AO register if the 

interrupt has a  priority of 10 or greater.

See also: RemIntServer(), SetIntVector(), hardware/intbits.i 

Example: Linking an interrupt that is executed with every vertical 

blank of the monitor.

_Interrupt_link 

movea.l $4.w,a6 lea _VertBIS(pc),al moveq # INTB_VERTB , dO jsr _LVOAddIntServer (a6)

_Interrupt_remove 

movea.l $4.w,a6 lea _VertBIS(pc),al moveq # INTB_VERTB , dO jsr _LVORemIntServer (a6)

JVertBIS 

dc . 1 0,0  LN_SUCC , LN_PRED dc.b NT_INTERRUPT, 127 LN_TYPE,LN_PRI del _VertBName LN_NAME dc . 1 _Data , .Interrupt  IS_DATA, IS_CODE

** Interrupt Routine ** 

** tir 

** Input: aO =  _Custom ($dff000) ** 

** al =  _Data (IS_DATA) ** 

** Output:d0,cc =  0,Z ** 

**===========================================- . ** 

_Interrupt 

movem.l d2-d6/a0-a6, -(a7) movem.l (a7)+,d2-d6/a0-a6 moveq #0,d0 rts

_Data data block for the interrupt routine 

[Cause Calls a  software interrupt I 

Call: Cause ( interrupt ) 

-180 (A6) Al 

STRUCT IS * interrupt 

Function: Executes a  software interrupt. 

Parameters: interrupt IS structure of the interrupt. 

[Disable Turn off interrupts | 

Call: Disable ( ) 

-120(A6) 

Function: Turns off all interrupts along with multitasking. This can be 

a nested call.

Warning: Essential operating system functions can be destroyed by 

turning the interrupts off for more than 0.00025 seconds.
It's best to let these calls go through other operating system 

functions.

Wait() calls within a   Disable()/Enable() call turn 

multitasking back on until signaled.

[Enable 

Allow interrupts!

Call: Enable ( ) 

-126 (A6) 

Function: Reverses the effect of Disable(). Interrupt processing is 

restored as long as the number of Enable() calls correspond to the number of preceding DisableQ calls.

| Forbid 

Turn off multitasking] 

Call: Forbid ( ) 

-132 (A6) 

Function: Turns off multitasking capabilities. Forbid() calls can be 

nested.

Warning: Wait() calls within a  Forbid()/Permit() call turn multitasking 

back on until signaled.

See also: PermitO 

IGetCC 

Retrieve CCR in CPU-compatible format! 

Call: conditions =  GetCCO 

DO -528 (A6) 

UWORD conditions 

Function: "MOVE SR,<ea>" is only allowed on the 68000 in user 

mode. This function replaces that command so that all processors can read the status register.

Result: The 680x0 ConditionCodes 

| Permit 

Turn multitasking back on| 

Call: 

Permit ( ) 

-138 (A6) 

Function: Allows multitasking again. Multitasking is restored as long 

as the number of Permit() calls correspond to the number of preceding Forbid() calls.

See also: Forbid() 

| RemlntServer Remove IS from a  server list | 

Call: RemlntServer (intNum, interrupt) 

-174 (A6) DO Al 

ULONG intNum 

STRUCT IS * interrupt 

Function : Opposite of AddIntServer(). 

Parameters: intNum Interrupt source, as with AddIntServer(). 

interrupt IS structure, as with AddIntServer().

| Setlnt Vector Set interrupt handler | 

Call: oldlnterrupt =  Set Int Vector (intNumber, interrupt) 

DO -162 (A6) DO Al 

STRUCT IS "oldlnterrupt, * interrupt 

ULONG intNumber 

Function: Assigns a  handler to an interrupt source. The previous 

handler for this source is removed and returned to its IS structure. The routine, which must end with RTS, contains an AND combination of intenar and intreqr in Dl, the address of the custom chip in AO, and IS_DATA in Al.

Parameters: intNum Interrupt source with no server. 

interrupt IS structure of the handler.

Result: IS structure of the previous handler. 

See also: AddIntServer(),exec/interrupts.i,exec/hardware.i 

jSetSR Read and change status register |

Call: oldSR =  SetSR(newSR, mask) 

DO -144 (A6) DO Dl 

ULONG oldSR,newSR,mask 

Function: Reads the SR according to the installed processor and sets 

the bits in a  given bit mask according to the passed values.

Parameters: newSR Condition to which the bits will be changed. 

mask Bit mask containing the bits to be changed.

Result: The complete status register prior to the change. 

** Read status register ** 

movea.l $4.w,a6 moveq #0,d0 moveq #0,dl jsr _LVOSetSR(a6) move . w  dO , . . .

** Set interrupt level 4  ** 

**_ 

_*• 

movea.l $4.w, a6
move.w #$400, dO 

move.w #$700, dl 

jsr _LVOSetSR(a6) move.w dO, . . .

I Superstate C  hange processor to supervisor mode | 

Call: oldSysStack =  Superstate ( ) 

DO -150 (A6) 

APTR oldSysStack 

Function: Switches the processor to supervisor mode. Keeps the user 

stack, which contains all interrupt data.

Result: Address of the system stack or 0  (called from supervisor 

mode).

See also: UserState(), Supervisor() 

| Supervisor 

Call: result =  Supervisor (userFunc) 

Rx -30 (A6) A5 

Execute routine in supervisor model 

Function: Executes an Assembler routine ending with RTE in 

supervisor mode. The registers are not changed.

Parameters: userFunc Address of the Assembler routine (RTE). 

Result: All register changes during the execution of the routine (up 

to 15 changes).

See also: SuperState(), UserState() 

Example: Get the location of the exception vector table for higher 

processors: movea.l $4.w,a6 moveq #AFF_68010 !AFF_68020 !AFF_68030 !AFF_68040,d7 and.w AttnFlags(a6) ,d7 beq . s _TableFound lea _Exception(pc) ,a5 jsr _LVOSupervisor(a6)
JTableFound 

.Exception 

moved vbr,d7 VBR nach d7 rte lUserState

Return processor to user mode] 

Call: Userstate(sysstack) 

-156 (A6) DO 

APTR sysStack 

Function: Switches the processor back to user mode. 

Parameters: sysStack Supervisor stack from SuperState(). 

See also: SuperStateQ, SupervisorQ 

Dec 

Hex 

STRUCTURE ExecBase,LIB_SIZE 

$22 

UWORD 

SoftVer 

$24 

WORD 

LowMemChkSum 

$26 

ULONG 

ChkBase 

$2A 

APTR 

ColdCapture 

$2E APTR 

CoolCapture 

$32 

APTR 

WarmCapture 

$36 

APTR 

SysStkUpper 

$3A 

APTR 

SysStkLower 

$3E 

ULONG 

MaxLocMem 

$42 

APTR 

DebugEntry 

$46 

APTR 

DebugData 

$4A 

APTR 

AlertData 

$4E 

APTR 

MaxExtMem 

$52 

WORD 

ChkSum 

$54 

LABEL 

IntVects 

$54 

STRUCT 

IVTBE, IV_SIZE 

$60 

STRUCT 

IVDSKBLK, IV_SIZE 

$6C 

STRUCT 

IVSOFTINT, IV_SIZE 

$78 

STRUCT 

IVPORTS,IV_SIZE 

$84 

STRUCT 

IVCOPER, IV_SIZE 

$90 

STRUCT 

IWERTB, IV_SIZE 

$9C 

STRUCT 

IVBLIT, IV_SIZE 

$A8 

STRUCT 

IVAUD0,IV_SIZE 

$B4 

STRUCT 

IVAUD1,IV_SIZE 

$C0 

STRUCT 

IVAUD2,IV_SIZE 

$CC 

STRUCT 

IVAUD3,IV_SIZE 

$D8 

STRUCT 

IVRBF, IV_SIZE 

$E4 

STRUCT 

IVDSKSYNC, IV_SIZE 

$F0 

STRUCT 

IVEXTER, IV_SIZE 

$FC 

STRUCT 

IVINTEN, IV_SIZE 

$108 

STRUCT 

IVNMI,IV_SIZE 

$114 

APTR 

ThisTask

$118 

ULONG 

IdleCount 

$11C 

ULONG 

DispCount 

$120 

UWORD 

Quantum 

$122 

UWORD 

Elapsed 

Exec base structure 

Kickstart version 

trap vector check sum inverted base address cold boot vector reset vector warm boot vector system stack upper limit system stack lower limit size of chip memory global debugger debugger data alarm data

FastRAM 

check sum up to this point interrupt vectors serial output

DiskDMA finished 

software interrupt

CIA interrupts 

copper interrupt vertical blank blitter finished start of sound channel 0 start of sound channel 1 start of sound channel 2 start of sound channel 3 serial input

DiskDMA synchronized 

external interrupt level 6  interrupt level 7  interrupt currently running program wait counter dispatch counter time period elapsed time

292 $124 UWORD SysFlags 

294 $126 BYTE IDNestCnt 

295 $127 BYTE TDNestCnt 

296 $128 UWORD AttnFlags 

298 $12A UWORD AttnResched 

3 00 $12C APTR ResModules 

304 $130 APTR TaskTrapCode 

308 $134 APTR TaskExceptCode 

312 $138 APTR TaskExitCode 

316 $13C ULONG TaskSigAlloc 

320 $140 UWORD TaskTrapAlloc 

322 $142 STRUCT MemList, LH_SIZE 

336 $150 STRUCT ResourceList,LH_SIZE 

350 $15E STRUCT DeviceList,LH_SIZE 

364 $16C STRUCT IntrList,LH_SIZE 

378 $17A STRUCT LibList,LH_SIZE 

392 $188 STRUCT PortList, LH_SIZE 

406 $196 STRUCT TaskReady, LH_SIZE 

420 $1A4 STRUCT TaskWait, LH_SIZE 

434 $1B2 STRUCT Sof tints, SH_SIZE*5 

514 $202 STRUCT LastAlert, 4*4 

530 $212 UBYTE VBlankFrequency 

531 $213 UBYTE PowerSupplyFrequency 

532 $214 STRUCT SemaphoreList,LH_SIZE 

546 $222 APTR KickMemPtr 

550 $226 APTR KickTagPtr 

554 $22A APTR KickCheckSum 

558 $22E UWORD ex_Pad0 

560 $230 ULONG ex_Reserved0 

564 $234 APTR ex_RamLibPrivate 

568 $238 ULONG ex_EClockFrequency 

572 $23C ULONG ex_CacheControl 

576 $240 ULONG ex_TaskID 

580 $244 ULONG ex_PuddleSize 

584 $248 ULONG ex_PoolThreshold 

588 $24C STRUCT ex_PublicPool,MLN_SIZE 

596 $254 APTR ex_MMULock 

600 $258 STRUCT ex_Reserved, 12 

612 $264 LABEL SYSBASESIZE 

internal Flags interrupt forbid counter multitask forbid counter special system Flags execution Flags

ROMTags 

standard trap handler standard exception handler standard return address system signal mask system trap task free memory PRIVATE!

Resources PRIVATE ! 

Devices PRIVATE ! 

Interrupts PRIVATE! 

Libraries PRIVATE! 

MsgPorts PRIVATE! 

programs PRIVATE ! waiting tasks PRIVATE!

Softwarelnts PRIVATE! 

last system error vertical blank frequency power supply frequency signal Semaphores reset -protected memory blocks reset -protected user module check sum across Mem and Tags

RAM library PRIVATE! 

CPU E  pin frequency 

CACR 

next possible Task

AFB_68010 

AFB_68020 

AFB_68030 

AFB_68040 

AFB_68881 

AFB_68882 

0, AFF_68010 

1, AFF_68020 

2, AFF_6803 0 

3, AFF_68040 

4, AFF_68881 

5, AFF_68882 

1 also with 68020 

2 also with 68030 

4 also with 68040 

8 CPU 68040 

16 also with 68882 

32 FPU 68882 

CACRB_EnableI 

= 

0, 

CACRF_EnableI 

CACRB_FreezeI 

= 

1, 

CACRF_FreezeI 

CACRB_ClearI 

= 

3, 

CACRF_ClearI 

CACRB_IBE 

= 

4, 

CACRF_IBE 

= 16 

CACRB_EnableD 

= 

8, 

CACRF_EnableD 

= 256 

CACRB_Fr ee z  eD 

= 

9, 

CACRF_FreezeD 

= 512 

CACRB_ClearD 

= 

11, 

CACRF_ClearD 

=2048 

CACRB_DBE 

= 

12, 

CACRF_DBE 

=4096 

/command cache 

freeze command cache clear command cache

/burst mode commands 

data cache freeze data cache clear data cache data burst

CACRB_WriteAllocate =  13, CACRF_WriteAllocate =  8192 always 

Dec Hex STRUCTURE IS,LN_SIZE  Interrupt Structure 

14 $E APTR IS_DATA data for IS_CODE 

18 $12 APTR IS_CODE  interrupt routine 

22 $16 LABEL IS_SIZE 

Dec Hex STRUCTURE IV, 0  Execs Interrupt Vectors 

0 $0 APTR IV_DATA data for IS_CODE 

4 $4 APTR IV_CODE  interrupt Handler/Server 

8 $8 APTR IV_NODE  IS structure/ 0 

12 $C LABEL IV_SIZE 

SB_SAR =  15, SF_SAR =  $8000 ,-execution plan 

SB_TQE =  14, SF_TQE =  $4000 time exceeded 

SB_SINT =  13, SF_SINT =  $2000 SoftInt 

Dec Hex STRUCTURE SH,LH_SIZE SoftInt Header 

14 $E UWORD SH_PAD 

16 $10 LABEL SH_SIZE 

SIH_PRIMASK =  $F0  priority mask 

SIH_QUEUES =5  5 Softlnt queues 

3. Memory Management 

[AddMemList 

Add memory to the free memory list| 

Call: AddMemList (  size, attributes, pri, base, name ) 

-618 (A6) DO Dl D2 A0 Al 

ULONG size, attributes 

LONG pri 

APTR base, name 

Function: Adds a  memory block to the list of free memory. A 

MemHeader structure is created at the beginning of the 

block.

Parameters: size Size of memory block, 

attributes Memory type pri Allocation priority base Address name Name for memory or 0

Attempt to allocate a  certain memory block | 

| Alloc Abs~ 

Call: memoryBlock =  AllocAbs (byteSize, location) 

DO -204 (A6) DO Al 

APTR memoryBlock, location 

ULONG byteSize 

Function: Allocates a  memory block at a  set address. Normally, this 

routine is only used by reset-protected programs to protect themselves from being overwritten.

Parameters: byteSize Size 

location Address

Result: Address of the memory block (divisible by 8) or 0. 

I Allocate 

Allocate private memory block]

Call: memoryBlock=Allocate(memHeader, byteSize) 

DO -186 (a6) A0 DO 

APTR memoryBlock 

STRUCT MemHeader *memHeader 

ULONG byteSize 

Function: Assign a  private MemHeader to a  memory block. 

Parameters: memHeader 

Private MemHeader 

byteSize Size of the desired block.

Result: Address of the reserved memory block or 0. 

See also: Deallocate, exec/memory .h 

jAllocEntry Allocate several memory blocks]

Call: memList =  AllocEntry (memList) 

DO -222 (A6) AO 

STRUCT MemList *memList 

Function: Allocates all of the blocks stored in a  MemList structure. 

Parameters: memList Structure containing MemEntry structures. 

Result: New MemList structure with the results (not identical to 

the structure passed as a  parameter). If a  block could not be allocated, then the memory type with a  matching bit 31 is passed back (negative value).

|AllocMem Allocate memory [ 

Call: memoryBlock =  AllocMem (byteSize, attributes) 

DO -198 (A6) DO Dl 

APTR memoryBlock 

ULONG byteSize, attributes 

Function: Allocates the requested type and amount of memory. 

Parameters: byteSize Size of block 

attributes Memory type (MEMF_„.)

Result: Address of the memory block or 0. 

Warning: Memory that cannot be freed must be MEMF_PUBLIC. 

See also: FreeMem() 

|AllocVec Allocate memory and store the size| 

Call: memoryBlock =  AllocVec(byteSize, attributes) 

DO -684 (A6) DO Dl 

Functions, Parameters, Results: 

Same as AllocMem(), except that Exec stores the block size 

for FreeVec().

See also: FreeVec(), AllocMem() 

| A vailMem Query free memory | 

Call: size =  AvailMem (attributes) 

DO -216 (A6) Dl 

ULONG size, attributes 

Function: Query the amount of free system memory. 

Parameters: requirements 

Memory type (MEMF_„.) 

Result: Number of free bytes of the desired type. This number may 

not be correct because of multitasking.

| Copy Mem Copy a  memory block | 

Call: CopyMem( source, dest, size ) 

-624 (A6) AO Al DO 

APTR source , dest 

ULONG size 

Function: Super-fast copying of a  memory block. 

Parameters: source Source address 

dest Destination address size Block size (0 allowed)

See also: CopyMemQuick() 

ICopyMemQuick Optimized memory copy| 

Call: CopyMemQuick ( source, dest, size ) 

-630 (A6) A0 Al DO 

Function: Highly optimized memory copying function. 

Parameters: source Source address (divisible by 4) 

dest Destination address (divisible by 4) size Block size (divisible by 4, 0 allowed)

See also: CopyMem() 

| Deallocate Free memory block allocated with Allocated 

Call: Deallocate (memHeader, memoryBlock, byteSize) 

-192 (A6) A0 Al DO 

STRUCT MemHeader *memHeader 

APTR memoryBlock 

ULONG byteSize 

Function: Frees a  memory block that was allocated with the 

Allocate() command.

Parameters: memHeader 

Own MemHeader 

memoryBlock

Address of memory block 

byteSize Block size, 0  allowed

See also: AllocateQ, exec/memory .h 

IFreeEntry Free several memory blocks | 

Call: FreeEntry (memList) 

-228 (A6) AO 

STRUCT MemList *memList 

Function: Frees all memory blocks in a  MemList structure (result of 

AllocEntry).

Parameters: memList MemList structure 

See also: AllocEntryO 

IFreeMem Free memory block | 

Call: FreeMem(memoryBlock, byteSize) 

-210 (A6) Al DO 

APTR memoryBlock 

ULONG byteSize 

Function: Frees a  memory block. 

Parameters: memoryBlock 

Block address 

byteSize Block size

See also: AllocMem(),AllocAbs() 

IFreeVec Free memory allocated with Alloc Vec()| 

Call: FreeVec (memoryBlock) 

-690(a6) Al 

APTR memoryBlock 

Function: Frees a  memory block allocated with Alloc Vec(). 

Parameters: memoryBlock 

Result of Alloc Vec() or 0 

See also: AllocVec() 

ITypeOfMem ~ 

Get memory typej 

Call: attributes =  TypeOfMem( address) 

DO -534 (A6) Al 

ULONG attributes 

APTR address 

Function: Queries the memory type of the memory block at the given 

address (MEMF_...).

Parameters: address Memory address 

Result: Memory type or 0  (ROM, not linked, or does not exist). 

Dec Hex STRUCTURE ML,LN_SIZE MemList 

14 $E UWORD ML_NUMENTRIES number of ME structures to follow 

16 $10 LABEL ML_ME  start of the ME structures 

16 $10 LABEL ML_SIZE =      size excluding ME structures 

Dec Hex STRUCTURE ME, 0 

0 $0 LABEL 

0 $0 APTR 

4 $4 ULONG 

8 $8 LABEL 

ME_REQS = 

ME_ADDR 

ME_LENGTH 

ME_SIZE 

MemEntry 

/memory type for AllocMemO 

memory address follows block size

MEMF_ANY =  0 any memory type (do not use!) 

MEMB_PUBLIC =  0, MEMF_PUBLIC =     1  usable memory 

MEMB_CHIP =   1, MEMF_CHIP =      2 ChipRAM 

MEMB_FAST =   2, MEMF_FAST =      4 FastRAM 

MEMB_LOCAL =   8, MEMF_LOCAL =   $100 UserRAM 

MEMB_24BITDMA =   9, MEMF_24BITDMA =   $200 ,-DMA capable, 24 bit 

MEMB_CLEAR =  16, MEMF_CLEAR =  $10000 ,-delete beforehand 

MEMB_LARGEST =  17, MEMF_LARGEST =  $20000 /largest block 

MEMB_REVERSE =  18, MEMF_REVERSE =  $40000  inverted 

MEMB_TOTAL =  19, MEMF_TOTAL =  $80000  total size 

MEM_BLOCKSIZE =  8  smallest available memory block 

Dec Hex STRUCTURE MH,LN_SIZE  start of memory 

14 $E UWORD MH_ATTRIBUTES  memory type 

16 $10 APTR MH_FIRST  first free block 

20 $14 APTR MH_LOWER   start of block 

24 $18 APTR MH_UPPER end of block 

28 $1C ULONG MH_FREE  f ree bytes 

32 $20 LABEL MH_SIZE 

Dec Hex STRUCTURE MC,0  start of a  free block 

0 $0 APTR MC_NEXT next free block 

4 $4 ULONG MC_BYTES block size 

8 $8 LABEL MC_SIZE 

4. Structure Management 

| Add Head Insert a  node at the start of a  list | 

Call: AddHeaddist, node) 

-240 (A6) A0 Al 

STRUCT LH *list 

STRUCT LN *node 

Function: Inserts a  node at the start of a  double linked list. 

Parameters: list LH structure of the double linked list. 

node LN structure of the list entry.

| AddTail Insert node at the end of a  list| 

Call: AddTail (list, node) 

-246 (A6) A0 Al 

STRUCT LH *list 

STRUCT LN *node 

Function: Like AddHead(), but the node is added to the end of the 

double linked list.

Parameters: list LH structure of the double linked list. 

node LN structure of the list entry.

I Enqueue Adds a  node to a  list | 

Call: Enqueue (list, node ) 

-270 (A6) A0 Al 

STRUCT LH *list 

STRUCT LN *node 

Function: Adds an LN structure to a  double linked list using the 

given priority (LN_PRI).

Parameters: list LH structure of the double linked list. 

node LN structure of the list entry.

I FindName Find a  node in a  list | 

Call: node =  FindName (start, name) 

D0,CC -276 (A6) A0 Al 

STRUCT LN *node 

STRUCT LH *start 

APTR name 

Function: Finds a  node with the given name (LN_NAME) in a  double 

linked list. In order to find multiple nodes with the same name, the next call must use the node structure returned from the previous call instead of the ListHeader structure.

Parameters: start ListHeader or ListNode 

name String ending in 0, containing node name.

Result: Node address or 0. 

| Insert Insert a  node into a  list after another node | 

Call: Insert (list, node, listNode) 

-234 (A6) AO Al A2 

STRUCT LH *list 

STRUCT LN *node,*listNode 

Function: Inserts a  node after another node in a  double linked list. 

Parameters: list ListHeader (if listNode=0) 

node ListNode to be inserted. listNode Node after which the new node will be inserted orO.

| RemHead Remove the first node in a  list] 

Call: node =  RemHead (list) 

DO -258 (A6) AO 

STRUCT LN *node 

STRUCT LH *list 

Function: Gets the address of the first node in a  double linked list and 

removes the node from the list.

Parameters: list ListHeader structure 

Result: Address of the ListNode or 0  (list was empty). 

| Remove Remove a  node from a  list] 

Call: Remove ( node ) 

-252 (A6) Al 

STRUCT LN *node 

Function: Takes the given ListNode out of the list. 

Parameters: node ListNode to be removed. 

| RemTail Remove last node from a  list | 

Call: node =  RemTail (list) 

DO -264 (A6) AO 

STRUCT LN *node 

STRUCT LH *list 

Function: Gets the address of the last node in a  double linked list and 

removes the node from the list.

Parameters: list 

ListHeader structure 

Result: Address of the ListNode or 0  (list was empty). 

Dec Hex STRUCTURE LH, 0 

0 $0 APTR LH_HEAD 

4 $4 APTR LH_TAIL 

8 $8 APTR LH_TAILPRED 

12 $C UBYTE LH_TYPE 

13 $D UBYTE LH_pad 

14 $E LABEL LH_SIZE 

list, ListHeader
/first node 

0 (end marker) 

last node list type

Dec Hex STRUCTURE MLH, 0 

0 $0 APTR MLH_HEAD 

4 $4 APTR MLH_TAIL 

8 $8 APTR MLH_TAILPRED 

12 $C LABEL MLH_SIZE 

same structure, minimal configuration first node

0 

last node

Dec Hex STRUCTURE LN, 0   ListNode 

0 $0 APTR LN_SUCC 

4 $4 APTR LN_PRED 

8 $8 UBYTE LN_TYPE 

9 $9 BYTE LN_PRI 

10 $A APTR LN_NAME 

14 $E LABEL LN_SIZE 

next node previous node node type node priority node name data begins here

Dec Hex STRUCTURE MLN, 0 same structure 

0 $0 APTR MLN_SUCC next node 

4 $4 APTR MLN_PRED  previous node 

8 $8 LABEL MLN_SIZE data starts here 

minimal configuration

NT_UNKNOWN 

= 

not defined

NT_TASK 

= 

 Exec task 

NT_INTERRUPT 

= 

interrupt

NT_DEVICE 

= 

device

NT_MSGPORT 

= 

,-MP structure 

NT^MESSAGE 

= 

/message sent 

NT_FREEMSG 

= 

message without ReplyPort

NT_REPLYMSG 

= 

/reply message 

NT_RESOURCE 

= 

/ resource 

NT_LIBRARY 

= 

/library 

NT_MEMORY 

= 

memory

NT_SOFTINT 

= 

/software interrupt 

NT_FONT 

= 

/ font 

NT_PROCESS 

NT_SEMAPHORE 

NT_SIGNALSEM 

NT_BOOTNODE 

NT_KICKMEM 

NT_GRAPHICS 

NT_DEATHMESSAGE 

NT_USER 

NT_EXTENDED 

= 13 AmigaDOS process 

= 14 /message semaphore 

= 15 SignalSemaphore 

=16 boot node 

= 17 /operating system memory 

= 18  graphics data 

= 19 end message 

=254 maximum user definition 

=255  extended node 

5. Programs 

|AddTask 

Start a  program | 

Call: AddTask(task, initialPC, finalPC) 

-282 (A6) Al A2 A3 

STRUCT TC *task 

APTR initialPC, finalPC 

Function: Adds a  task to the system, redistributes the processor time, 

and starts the task with the highest priority. Most of the parameters are taken from the initialized Task structure that is passed to this routine. A  stack larger than 256 bytes is needed for calling Exec functions. The minimum for other operating system functions is 4096 bytes. The TC_FLAGS are cleared.

Parameters: task Initialized TC structure 

initialPC Program start address finalPC Return address or 0  (normal)

Warning: Exec tasks cannot use DOS routines, since these require a 

greatly expanded Task structure (process). lAUocSignal Allocate a  signal bit]

Call: signalNum =  AllocSignal (signalNum) 

DO -330 (A6) DO 

BYTE signalNum 

Function: Allocates a  free signal bit from its own task. You can 

specify a  certain bit or the value -1 if any bit will do (this is the normal procedure). Up to 16 different bits can be reserved per task. The other bits are used by the operating system, for example, bit 8  signals an incoming DOS packet.

Parameters: signalNum Bit number (0-31) or -1 (any bit) 

Result: Bit number or - 1 (bit not free or not bit free) 

lAllocTrap Allocate a  CPU trap vector

Call: trapNum =  AllocTrap(trapNum) 

DO -342 (A6) DO 

LONG trapNum 

Function: Gets the number of a  free CPU trap vector (TRAP #). A 

certain trap vector can be specified, or -1 can be passed to get the next free vector. Traps are sent to the trap handler in the following format, which is entered in tc_TrapCode: the number of the exception vector is on the stack (32-47 correspond to TRAP #1-#15) followed by the 680x0 exception frame.

Parameters: trapNum Trap number (0-15) or -1 

Result: trapNum Number of the allocated trap vector (0-15) or- 1 

(no free vector). 

ICacheClearE

Clear cache memory] 

Call: CacheClearE (address, length, caches) 

-642 (A6) AO DO Dl 

ULONG length, caches 

APTR address 

Function: Clears the internal command and data cache memory of the 

CPU. 

Parameters: address Start address 

length Size of block to be cleared, or -1 to clear all addresses. caches The following bits are supported at this time:

CACRF_ClearI 

CACRF ClearD 

Clear instruction cache 

Clear data cache 

ICacheClearU 

Clear cache memory [ 

Call: 

CacheClearU 

-636 (A6) 

Function: Clears all internal command and data cache memory of the 

CPU. 

ICacheControl 

Cache control in user model 

Call: oldBits =  CacheControl(cacheBits,cacheMask) 

DO -648 (A6) DO Dl 

ULONG oldBits, cachBits, cacheMask 

Function: Global control via the CACR register of the 68030. All 

changes to the cache pertain to the entire system. This allows the programmer to turn off the caches of programs not normally executable (self -modifying code, construction of private vector tables, etc.) and run them with extremely reduced processor expenditures.

Parameters: cacheBits New bit values for the bits to be changed. 

cacheMask

Bit mask for the bits to be changed. 

Result: The complete CACR register prior to the manipulation. 

IFindTask 

Find the address of a  Task structure | 

Call: task =  FindTask(name) 

DO -294 (A6) Al 

STRUCT TC *task 

APTR name 

Function: Gets the Task structure of the program with the given 

name. If no name is given, the routine reads ThisTask from the ExecBase. Since tasks can also remove themselves, it is usually necessary to turn off multitasking.

Parameters: name String ending in 0  containing the program 

name.

Result: Task control block, process, or 0 

IFreeSignal Free a  signal bit| 

Call: FreeSignal (signalNum) 

-336 (A6) DO 

BYTE signalNum 

Function: Free a  signal bit that was allocated with AllocSignal(). 

Parameters: signalNum Bit number (0-31) from AllocSignal() 

IFreeTrap Free a  CPU trap vector | 

Call: FreeTrap ( trapNum) 

-348 (A6) DO 

ULONG trapNum 

Function: Frees a  vector allocated with AllocTrap(). 

Parameters: trapNum Vector number from AllocTrap(). 

IRemTask Remove a  program | 

Call: RemTask(task) 

-288 (A6) Al 

STRUCT TC *task 

Function: Remove a  task from the system. All linked MemList 

structures in TQMEMENTRY are freed (see AllocEntryO,
FreeEntryO). 

Parameters: task 

Address of a  task control block or 0  (task 

removes itself).

ISetExcept 

Define exception signal bits] 

Call: oldsignals =  SetExcept (newSignals, signalMask) 

DO -312 (A6) DO Dl 

ULONG oldsignals, newSignals, signalMask 

Function: Sets the signal bits produced by an exception processed by 

the task exception handler in tc_ExceptionCode. The handler is passed the ExecBase in A6, the contents of tc_ExceptCode in Al, and the signal bits in dO. It returns a bit mask in which all of the signal bits to be reset are set.

Parameters: newSignals 

New bit values for the bits to be changed. 

signalMask

Mask with the bits to be changed. 

Status of the signal bits prior to the reset. 

Result: 

ISetSignal 

Define task signal status | 

Call: 

Function: 

Parameters: 

Result: 

oldsignals =  SetSignal (newSignals, signalMask)
DO -306 (A6) DO Dl 

ULONG oldsignals, newSignals, signalMask 

Queries and resets received signals. 

newSignals

New bit values for the bits to be changed. 

signalMask

Mask with the bits to be changed. 

Signal bits prior to the change. 

Example: 

**„-,_________________________ ___________________________** 

** Read signal bits ** 

**. , ** 

movea.l $4.w,a6 moveq #0,d0 moveq #0,dl jsr _LVOSetSignal (a6) move .1 dO , . . .

** Clear signal bits ** 

** ** 

movea.l $4.w,a6 moveq #0,d0 moveq #-l,dl jsr _LVOSetSignal(a6) move .1 dO , . . .

**_________________ ======= ============================== ** 

** Clear signal bit for CONTROL-C ** 

**======================================================** 

movea.l $4.w,a6 moveq #0,d0 move . 1 #SIGBREAKF_CTRL_C , dl jsr _LV0SetSignal(a6) move .1 dO , . . .

| SetTaskPri Change priority of a  task | 

Call: oldPriority =  SetTaskPri (task, priority) 

DO -300 (A6) Al DO 

BYTE oldPriority 

LONG priority 

STRUCT TC *task 

Function: Changes the priority of a  program and updates the 

distribution of processor time throughout the system.

Parameters: task Task control block 

Result: 

| Signal 

priority New priority (127 to -128)
Previous priority 

Sends a  signal to a  program] 

Call: Signal (task, signals) 

-324 (A6) Al DO 

STRUCT TC *task 

ULONG signals 

Function: Sends the signal bits in the given signal mask to a  task. If 

the task was waiting for one of the signals, it is re-activated and the processor time distribution is recalculated.

Parameters: task 

Task control block 

signals Signal mask rWait

Wait for a  signal | 

Call: signals =  Wait (signalSet) 

DO -318(A6) DO 

ULONG signals, signalSet 

Function: Turns off own task and waits for one of the given signal 

bits.

Parameters: signalSet Signal bit mask 

Result: The received signal. 

Dec Hex STRUCTURE TC_Struct, LN_SIZE 

14 $E UBYTE TC_FLAGS 

TC_STATE 

TC_IDNESTCNT 

TCJTDNESTCNT 

TC_SIGALLOC 

TC_SIGWAIT 

TC_SIGRECVD 

TC_SIGEXCEPT 

15 $F UBYTE 

16 $10 BYTE 

17 $11 BYTE 

18 $12 ULONG 

22 $16 ULONG 

26 $1A ULONG 

30 $1E ULONG 

/previously TC 

 Flags 

 Status 

/saved IDNestCnt 

/saved TDNestCnt 

/allocated Signalbits 

/expected Signalbits 

/received Signalbits 

/signal for Exception Handler 

$22 

APTR 

tc_ETask extension structure

$26 

APTR 

TC_EXCEPTDATA 

data for Exception Handle:

$2A 

APTR 

TC_EXCEPTCODE 

/Exception Handler 

$2E 

APTR 

TC_TRAPDATA 

data for Trap Handler

$32 

APTR 

TC_TRAPCODE 

Trap Handler 

$36 

APTR 

TC_SPREG 

/StackPointer 

$3A 

APTR 

TC_SPLOWER 

lower limit of stack

$3E 

APTR 

TC_SPUPPER 

upper limit of stack

$42 

FPTR 

TC_SWITCH 

/routine task switch 

$46 

FPTR 

TC_LAUNCH 

/routine task start 

$4A 

STRUCT 

TC_MEMENTRY , LH_S I ZE 

/memory for task 

$58 

APTR 

TC_Userdata 

/data for task 

$5C 

LABEL 

TC_SIZE 

Dec 

Hex 

STRUCTURE ETask,MN_SIZE 

/task extension 

$14 

APTR 

et_Parent

/TC_Struct 

$18 

ULONG 

et_UniqueID

/task ID 

$1C 

STRUCT 

et_Children, MLH_SIZE

/ sub-tasks 

$28 

UWORD 

et_TRAPALLOC

/allocated Traps 

$2A 

UWORD 

et_TRAPABLE

/possible Traps 

$2C 

ULONG 

et_Resultl

/ 1 . result 

$30 

APTR 

et_Result2

/result address (AllocVec 

$34 

STRUCT 

et_TaskMsgPort , MP_SIZE

1 /TaskPort 

$56 

LABEL 

ETask_SIZEOF 

/not the true size! ! ! 

CHILD_NOTNEW 

CHILD_NOTFOUND 

CHILD_EXITED 

CHILD_ACTIVE 

= 1  /call to old task (TC) 

= 2  / sub-task not found 

= 3  /sub-task ended 

= 4  /sub-task active 

TB_PROCTIME 

= 

0, 

TF_PROCTIME = 

TB_ETASK 

= 

3, 

TF_ETASK 

TB_STACKCHK 

= 

4, 

TF_STACKCHK = 

$10 

TB_EXCEPT 

= 

5, 

TF_EXCEPT 

$20 

TB_SWITCH 

= 

6, 

TF_SWITCH 

$40 

TB_LAUNCH 

= 

7, 

TF_LAUNCH 

$80 

TS_INVALID 

= 

TS_ADDED 

= 

TS_INVALID+1 

TS_RUN 

= 

TS_ADDED+1 

TS_READY 

= 

TS_RUN+1 

TS_WAIT 

= 

TS_READY+1 

TS_EXCEPT 

= 

TS_WAIT+1 

TS_REMOVED 

= 

TS_EXCEPT+1 

SIGB_ABORT 

= 

0, SIGF_ABORT 

= 

SIGB_CHILD 

= 

1, SIGF_CHILD 

= 

SIGB_BLIT 

= 

4, SIGF_BLIT 

= 

$10 

SIGB_S INGLE =  4, SIGF_S INGLE =  $10 

SIGB_INTUITION =  5, SIGF_INTUITION =  $20 

SIGB_DOS =  8, SIGF_DOS =  $100 

SYS_SIGALLOC =  $FFFF  system signal bits 

SYS_TRAPALLOC =  $8000  system traps (TRAP #15) 

6. Communications 

| AddPort Make MsgPort available to other tasks | 

Call: AddPort (port ) 

-354 (A6) Al 

STRUCT MsgPort *port 

Function: Adds the given MsgPort to the system list so that other 

programs can access it with FindPort() and address it.

Parameters: port MessagePort structure (LN_NAME <> 0  if the 

port must be found with FindPort.).

I Alert Indicates an error | 

Call: Alert (alertNum) 

-108 (A6) D7 

ULONG alertNum 

Function: Indicates a  catastrophic error (Guru Meditation). 

Debugging with a  second computer attached via the serial 

port is usually possible (9600 baud, 8  bits, n  parity).

Parameters: alertNum Error code 

See also: exec/alerts.h 

| CreateMsgPort Create MP structure | 

Call: port =  CreateMsgPort ( ) 

dO -666 (A6)

STRUCT MsgPort *port 

Function: Allocates the memory required for a  MsgPort and initializes 

it. The message queue list is created, a  signal bit is allocated, the task is entered, and the port is set to PA_SIGNAL (for
WaitPortO). The port can only be freed with 

DeleteMsgPort(). 

Result: MsgPort or 0 

| Debug 

Starts system debugger | 

Call: Debug ( f lags ) 

-114 (A6) DO 

ULONG flags 

Function: Calls the system debugger. Normally, this is the "ROM- 

WACK", but you can also patch the DebugO function with 

SetFunction(). 

Parameters: flags 0  at this time 

Free MP created with CreateMsgPortQI 

IDeleteMsgPort 

Call: DeleteMsgPort (msgPort) 

-672 (A6) aO 

STRUCT MsgPort *msgPort 

Function: Frees a  MessagePort created with CreateMsgPort(). 

Parameters: msgPort MP structure from CreateMsgPort() orO. 

Find MsgPort| 

fFlndPort

Call: 

port =  FindPort (name)
DO -390 (A6) Al 

STRUCT MP *port 

APTR name 

Function: Finds port in the system list with the given name 

(LN_NAME). 

Parameters: name Port name string ending in 0. 

Result: MsgPort address or 0 

IGetMsg Get next MessageNode from the port| 

Call: message =  GetMsg(port) 

DO -372 (A6) AO 

STRUCT MN *message 

STRUCT MP *port 

Function: Gets the next message from the port's queue. WaitPort() or 

Wait() are used to wait for messages. Messages must be 

answered with ReplyMsg(). A  signal does not always indicate a  message has arrived, it may also indicate several messages have arrived (security prompt).

Parameters: port MessagePort 

Result: MessageNode or 0  if no message has arrived at the port. 

| PutMsg Send a  MessageNode to a  port) 

Call: PutMsg (port, message) 

-366 (A6) AO Al 

STRUCT MP *port 

STRUCT MN *message 

Function: Sends a  message to a  port. Depending on MP_FLAGS, the 

port program is also notified.

Parameters: port MP structure of the destination port. 

message MessageNode to be sent.

| RawDoFmt Format a  string | 

Call: RawDoFmt (FormatString, DataStream, PutChProc, PutChData) 

-522 (A6) aO al a2 a3 

APTR FormatString,DataStream,PutChData 

FPTR PutChProc 

Function: A  format string is loaded with the given arguments (this is 

the basis of C  routines such as PrintF(), etc.). The arguments are in word or longword widths. The prefix code for an argument is the %  character. To get a  % character in the result string, the format string must contain %%. The output is sent to the result buffer one character at a  time using the given Assembler routine.

Parameters: FormatString 

String with arguments in the following format: 

%[flag] [width. limit] [length] type 

flag'-' Left justify width Width of argument. If the first character is '0', the given width to the left is filled with zeros. limit Maximum width, if the argument is a  string. length T         Longword, otherwise word (only with numbers). type Argument type (in DataStream): b BSTR(BPTRtoaBCPL string) d Decimal number x Hexadecimal number
(characters 0-F only) 

s String address c Individual character

DataStream 

Memory block containing the values and/or 

addresses of the arguments one after another.

PutChProc 

Address of an Assembler routine that writes a 

character to PutChData. This routine receives the character in dO and PutChData in a3. This routine normally looks like this: 'MOVE.B
D0,(A3)+ :RTS'. The last character is a  0 byte. 

PutChData 

Buffer for storing the result string. 

Example: Format text and output to a  RastPort: 

* * 

Example (Result: "reading cyl 1, 78 to go") 

movea.l _RastPort,a2 lea _Format,aO lea _Parameter,al bsr _Print

_Format 

dc.b '%s cyl %d, %d to go',0 cnop 0 , 2

_Parameter 

del _Action dew 1 dew 78

_Action 

dc.b ' reading' , 0 dc.b 'writing' , 0 dc.b "ver'ing",0

_Print 

movem.l a2-a3/a6, - (a7) lea . PutChar (pc) ,a2 move.l a7,-4(a2) lea -100(a7),a7

movea . 1 a7,a3 moves . 1

$4 .w,a6 

jsr

_LVORawDoFmt ( a 6 ) 

movea . 1

100(a7) ,al 

movea . 1 a7,a0

.Loop 

tst.b

(a3) + 

bne.s

.Loop 

subq . 1

#2,a3 

move . 1 a3,d0 sub. 1 a7,d0 movea . 1

_Gf xBase, a6 

jsr

_LV0Text(a6) 

lea

100 (a7) ,a7 

movem . 1

(a7)+,a2-a3/a6 

rts

.BufferEnd 

del

. PutChar 

empa . 1

. Buf ferEnd(pc) ,a3 

beq.s

.Overflow 

move . b dO, (a3)+ rts

.Overflow 

clr.b

-Ka3) 

IRemPort 

Call: RemPort (port! 

-360(A6) Al 

Remove a  MessagePort from the system list] 

STRUCT MP *port 

Function: Removes a  port added with AddPort() from the list. 

Parameters: port MessagePort 

|ReplyMsg~ 

Reply to a  message) 

Call: ReplyMsg (message) 

-378(a6) Al 

STRUCT MN *message 

Function: After processing a  message, this routine sends a 

MessageNode back to the sender or its port 

(MN.REPLYPORT). 

Parameters: message Address of the MessageNode. 

I WaitPort Wait for a  messagel 

Call: 

message
DO 

WaitPort (port) 

-384 (A6) AO 

STRUCT MN *message 

STRUCT MP *port 

Function: Turns off own task and waits for the receipt of one or more 

messages at the given port. MP_SIGTASK and
MP_SIGBIT must be initialized and MP_FLAGS must be 

settoPA.SIGNAL.

Parameters: port 

MsgPort 

Result: Address of the first MessageNode (not removed from the 

port. Use GetMsgQ).

Alarm Types: 

AT_DeadEnd =  $80000000  reset after display 

AT_Recovery =  $00000000 /recovery possible 

Alarm Groups: 

AG_NoMemory =  $00010000 no memory 

AG_MakeLib =  $00020000  create library 

AG_OpenLib =  $00030000 open library 

AG_OpenDev =  $00040000 open device 

AG_OpenRes =  $00050000 open resource 

AG_IOError =  $00060000 I/0 error 

AG_NoSignal =  $00070000 no signal 

AG_BadParm =  $00080000 bad parameter 

AG_CloseLib =  $00090000 ,-closed too many times 

AG_CloseDev =  $000A0000 ,-closed too many times 

AG_ProcCreate =  $000BQ000  create process 

Alarm Objects: 

AO_ExecLib 

AO_GraphlcsLib 

AO_LayersLib 

AO_Intuition 

AO_MathLib 

AO_DOSLib 

AO_RAMLib 

AO_IconLib 

AO_Expans ionLib 

AO_DiskfontLib 

AO_UtilityLib 

AO_AudioDev 

AO_ConsoleDev 

AO_GamePortDev 

AO_KeyboardDev 

AO_TrackDi skDev 

AO_TimerDev 

AO_CIARsrc 

AO_DiskRsrc 

AO_MiscRsrc 

AO_BootStrap 

AO_Workbench 

AO_DiskCopy 

AO_GadTools 

AO_Unknown 

$00008001 

$00008002 

$00008003 

$00008004 

$00008005 

$00008007 

$00008008 

$00008009 

$0000800A 

$0000800B 

$0000800C 

$00008010 

$00008011 

$00008012 

$00008013 

$00008014 

$00008015 

$00008020 

$00008021 

$00008022 

$00008030 

$00008031 

$00008032 

: $00008033 

: $00008035 

Exec Library 

Gfx Library 

 Layers Library 

.•Intuition Library 

Math Library 

DOS Library 

RAM Library 

Icon Library 

/Expansion Library 

Diskfont Library 

,-Utility Library 

 Audio Device 

 Console Device 

Gameport Device 

 Keyboard Device 

Trackdisk Device 

 Timer Device 

CIAx Resource 

Disk Resource 

Misc. Resource 

 Strap 

/Workbench Library 

Diskcopy 

GadTools Library 

unknown object

Dec Hex STRUCTURE MP,LN_SIZE 

MsgPort 

14 $E UBYTE MP_FLAGS  signal type 

15 $F UBYTE MP_SIGBIT  signal bit number 

16 $10 APTR MP_SIGTASK task or interrupt 

20 $14 STRUCT MP_MSGLIST,LH_SIZE ,-message queue 

34 $22 LABEL MP_SIZE 

MP_SOFTINT =  MP_SIGTASK  f or PA_SOFTINT 

PF_ACTION =  3 mask 

PA_SIGNAL =  0  signal to task MP_SIGTASK 

PA_SOFTINT =  1  execute software interrupt MP_SOFTINT 

PA_IGN0RE =  2  ignore 

Dec Hex STRUCTURE MN,LN_SIZE ,-message 

14 $E APTR MN_REPLYPORT MsgPort for reply 

18 $12 UWORD MN_LENGTH  total structure size 

20 $14 LABEL MN_SIZE data begins here 

Example: 

RawKeyMapping : 

movea.l _SysBase,a6 movea . 1 _Window, a3 movea . 1 wd_UserPort (a3 ) , dl beq . s _ErrorNoUserPort movea.l dl,a3 bra . s   _GetMessage

_WaitMsg 

moveq #-l,dO jsr _LV0AllocSignal(a6) tst.b dO bmi . s _GetMessage move.b dl,MP_SIGBIT(a3) move.l ThisTask(a6) ,MP_SIGTASK(a3) clr.b MP_FLAGS(a3) movea .1 a3 , aO jsr _LV0WaitPort(a6) addq . b #  PA_IGNORE , MP_FLAGS ( a3 ) move . b MP_SIGBIT ( a3 ) , dO jsr _LVOFreeSignal(a6)

_GetMessage 

movea .1 a3 , aO jsr _LVOGetMsg(a6) tst.l dO beq.s _WaitMsg movea .1 dO , a4 move.l im_Class(a4) ,d0 cmpi.l #RAWKEY,dO beq _RawKey

_ErrorNoUserPort 

_RawKey 

movea.l _KeymapBase,a6

lea -ie_SIZEOF(a7),a7 movea . 1 a7,a0 clr.l

(aO) 

move . b

#IECLASS_RAWKEY, ie_Class (aO) 

clr.b ie_SubClass (aO ) move . w im_Code (a4 ) , ie_Code (aO ) move.w im_Qualifier(a4) , ie_Qualif ier (aO) move . 1 im_lAddress (a4) , ie_EventAddress (aO) lea

_Buf fer (pc) ,al 

moveq

#79, dl 

lea

$0.w,a2 

jsr

_LVOMapRawKey (a6 ) 

move . 1 dO , _CharsInBuf f er lea ie_SIZEOF(a7),a7 movea. 1 a4,al movea . 1 _Sy sBase , a6 jsr _LVOReplyMsg ( a6 )

_CharsInBuffer 

del 0

.Buffer 

ds.b 80

7. Libraries 

[AddLibrary Adds a  library to the system list| 

Call: AddLibrary ( 1 ibrary ) 

-396 (A6) Al 

STRUCT Library *library 

Function: Makes a  complete, initialized library available to other 

programs. Also, calculates the check sum for the library.

Parameters: library Base address of the library. 

ICloseLibrary Close a  library | 

Call: CloseLibrary (library) 

-414 (A6) Al 

STRUCT Library *library 

Function: Closes a  library. This is necessary in order to free the 

memory occupied by unused libraries.

Parameters: library Base address of the library or 0. 

I OldOpenLibrary For Kickstart 1.0 compatibility I 

Call: library =   OldOpenLibrary (libName) 

DO -408 (A6) Al 

STRUCT Library * library 

APTR libname 

Function: This function exists only to maintain compatibility with 

operating system Version 1.0. It corresponds to
OpenLibrary(libName,0) and should no longer be used. 

IQpenLibrary Open a  library! 

Call: library =  OpenLibrary (libName, version) 

DO -552 (A6) Al DO 

STRUCT Library * library 

APTR libName 

ULONG version 

Function: Opens a  library, gets the base address, and prevents the 

library from being removed from memory. This function also checks to make sure that the library has the given minimum version number. A  value of 0  will accept any version, but this should never be used. Since there is no documentation on which operating system version contains which library versions, here is a  list:

(no longer supported! ! ! ) 

(no longer supported! ! ! ) 

(no longer supported! ! ! ) 

(no longer supported! ! ! ) 

Kick ?.? =  LibVersion 0 

Kick 1.0 =  LibVersion 30 

Kick 1.1 (NTSC) =  V. 31 

Kick 1.1 (+PAL) =   V. 32 

Kick 1.2 =  LibVersion 33 

Kick 1.3 =  LibVersion 34 

Kick 1.3 (+A2024) =   34/35 

Kick 2.0 =  LibVersion 36 (described in this book) 

If the library is not in the list, DOS loads it from disk (the default directory is LIBS:). Because of this, only DOS processes can call this function for non-resident libraries. A complete path can also be given instead of a  name.

Parameters: libName 

Library name (+path if desired). Upper and 

lowercase letters are also distinguished in paths. version Minimum version number
Result: Base address of the library or 0. 

1 RemLibrary Attempt to delete a  library | 

Call: RemLibrary ( library) 

-402 (A6) Al 

STRUCT Library *library 

Function: Calls the LIB_EXPUNGE routine of the given library. This 

sets the automatic removal feature for extra libraries. The library will automatically be removed when it is no longer needed.

Parameters: library Base address of the library. 

Example : Attempt to remove a  library from memory: 

** Input: al=LibName 

** 

movea.l $4.w,a6 addq.b #l,TDNestCnt (a6) lea LibList (a6) ,aO j sr _LVOFindName (a6 ) tst.l dO beq . s . not found movea .1 dO , al jsr _LVORemLibrary(a6)

.not found 

subq.b #l,TDNestCnt(a6)

| SetFunction Divert a  library function | 

Coll: oldFunc =  SetFunction (library, funcOffset, funcEntry) 

DO -420(A6) Al AO.W DO 

APTR oldFunc, funcEntry 

STRUCT Library * library 

LONG funcOffset 

Function: Routine for patching operating system functions. 

Parameters: library Base address of the library. 

funcOffset Offset of the routine (LVO). funcEntry Address of the new function.
Result: Address of the old function. 

ISumLibrary Calculate check sum for a  library | 

Call: SumL ibr ary ( 1 ibrary ) 

-426 (A6) Al 

STRUCT Library *library 

Function: Recalculates the check sum of a  library. If the results does 

not agree with the given check sum and the CHANGED flag is not set, then the Alert() function is called.

Parameters: library Base address of the library. 

LIB_OPEN =   -6 LVO open library 

LIB_CLOSE =  -12 LVO close library 

LIB_EXPUNGE =  -18 ,-LVO remove library 

LIB_EXTFUNC =  -24 LVO future extension 

Dec Hex STRUCTURE LIB,LN_SIZE 

14 $E UBYTE LIB_FLAGS 

15 $F UBYTE LIB_pad 

16 $10 UWORD LIB_NEGSIZE 

18 $12 UWORD LIB_POSSIZE 

20 $14 UWORD LIB_VERSION 

22 $16 UWORD LIB_REVISION 

24 $18 APTR LIB_IDSTRING 

28 $1C ULONG LIB_SUM 

32 $20 UWORD LIB_OPENCNT 

34 $22 LABEL LIB_SIZE 

library base structure
 Flags 

vector table size size of base structure vers ion number
.•revision number 

identification string
/check sum 

/number of opens 

LIB _F lags values: 

LIBB_SUMMING =  0, LIBF_SUMMING = 

LIBB_CHANGED =  1, LIBF_CHANGED = 

LIBB_SUMUSED =  2, LIBF_SUMUSED = 

LIBB_DELEXP =  3, LIBF_DELEXP = 

1 /check sum calculation 

2 / library changed 

4 /calculate check sum 

8 /self -removal 

LIBB_EXP0CNT =  4, LIBF_EXP0CNT =  16 /same for system 

8. Devices 

lAbortlO

Abort I/O process! 

Call: AbortlO(iORequest) 

-480 (A6) Al 

STRUCT IORequest *iORequest 

Function: Attempts to abort a  currently running I/O process. 

Regardless of whether or not this is successful, it must use 

WaitIO() to wait for the official end of the process. 

Parameters: iORequest IO structure of any size (active or complete). 

lAddPevice Make a  device available to other programs |

Call: AddDevice (device) 

-432 (A6) Al 

STRUCT Device *device 

Function: Enters a  fully initialized Device structure into the system 

list.

Parameters: device Base address of the device. 

| ChecklO Check to see if an I/O process is completed | 

Call: result =  ChecklO (iORequest) 

DO -468 (A6) Al 

BOOL result 

STRUCT IORequest *iORequest 

Function: This function checks to see if an I/O process started with 

SendIO() is still running or is finished. Even if the process 

has finished, WaitIO() must be used to wait for the official process end.

Parameters: iORequest 10 structure of any size (active or complete). 

Result: 0  if the process is still running otherwise the address of the 

10 structure is returned. 

ICloseDevice Close a  devicel 

Call: CloseDevice ( iORequest ) 

-450 (A6) Al 

STRUCT IORequest * iORequest 

Function: Closes access to a  device and the sub-objects of the device. 

Parameters: iORequest 10 structure from OpenDeviceQ. 

| CreatelORequest Create IO structure 1 

Call: ioReq =  CreatelORequest ( ioReplyPort, size ) 

DO -654 (A6) AO DO 

STRUCT IORequest *ioReq 

STRUCT MsgPort *ioReplyPort 

ULONG size 

Function: Creates and initializes an 10 structure of any size. 

Parameters: ioReplyPort 

Address of a  fully initialized MsgPort (see 

CreateMsgPortO). 

size Size of the 10 structure.

Result: IO structure or 0  (error). 

DeletelORequest 

Free an 10 structure created with CreatelORequestQ 

Call: DeletelORequest (   ioReq ) 

-660 (A6) aO 

STRUCT IORequest *ioReq 

Function: Frees a  structure created with CreateIORequest(). 

Parameters: ioReq Result form CreateIORequest() or 0. 

|DoIO Execute I/O process | 

Call: error =  DoIO(iORequest) 

DO -456 (A6) Al 

BYTE error 

STRUCT IORequest *iORequest 

Function: Transfers an 10 structure containing the required data to a 

device which extracts the command and executes it. This function returns at the end of the process.

Parameters: iORequest Initialized 10 structure from OpenDevice() 

which was manually loaded with device- specific data.

Result: 0  or a  device-specific error code. 

IQpenDevice Register access to a  device | 

Call: error =  OpenDevice (devName, unitNumber, iORequest, flags) 

DO -444 (A6) AO DO Al Dl 

BYTE error 

APTR devName 

ULONG unitNumber, flags 

STRUCT IORequest * iORequest 

Function: Attempts to obtain access to a  device. The passed 10 

structure is supplied the necessary data if it's successful. If the device is not in memory, it attempts to load it from
(hard) disk. Possible to specify a  complete path. 

Parameters: devName Name of the device (distinguishes uppercase 

and lowercase notation). unitNumber

Number of a  subunit (e.g., 1-DF1 :) or null. 

iORequest I/O structure flags Special information

Result: Null or error code. 

Example: Attempt to remove a  device from memory: 

** Input: al=DevName 

*• 

movea.l $4.w,a6 addq.b #l,TDNestCnt (a6) lea DeviceList (a6) ,aO j sr _LVOFindName (a6 )

tst.l dO beq.s .not found movea.l dO,al jsr _LVORemDevice(a6)

.not found 

subq.b #l,TDNestCnt(a6)

I RemDevice 

Remove device! 

Call: RemDevice (device) 

-438 (A6) Al 

STRUCT Device *device 

Function: Attempts to initiate a  device removing itself from memory. 

Parameters: device Base address of the device. 

ISendIO 

Start I/O process | 

Call: SendlO(iORequest) 

-462 (A6) Al 

STRUCT IORequest *iORequest 

Function: Starts an I/O process without waiting for the end. 

Parameters: iORequest I/O structure 

IWaitIO 

Wait for the end of an I/O process | 

Call: error =  WaitIO( iORequest) 

DO -474 (A6) Al 

BYTE error 

STRUCT IORequest * iORequest 

Function: Waits for the end of an I/O process started with SendlOQ. 

Parameters: iORequest I/O structure (active or completed) 

Result: Null or error code. 

Dec Hex STRUCTURE 

34 $22 LABEL 

DD,LIB_SIZE 

DDSIZE 

 Device structure 

Dec Hex STRUCTURE UNIT,MP_SIZE 

34 $22 UBYTE UNIT_FLAGS 

35 $23 UBYTE UNIT_pad 

3 6  $24 UWORD UNIT_OPENCNT 

38 $26 LABEL UNIT_SIZE 

Unit structure 

 Flags 

 Number of openings 

UNITB_ACTIVE =  0, UNITF_ACTIVE =  1  working now 

UNITB_INTASK =  1, UNITF_INTASK =2  in the device task 

IOERR_OPENFAIL 

= 

-1  Error opening 

IOERR_ABORTED 

= 

-2 /Process 

aborted

IOERR_NOCMD 

= 

-3 /Unknown 

command

IOERR_BADLENGTH 

= 

-4  Length 

not okay

IOERR_BADADDRESS = 

-5 /Address 

not okay

IOERR_UNITBUSY 

= 

-6 Unit st 

ill working

IOERR_SELFTEST 

= 

-7 /Hardware error 

ERR_OPENDEVICE 

= 

IOERR_OPENFAIL 

Dec Hex 

STRUCTURE 

I0,MN_SIZE 

I/0 structure 

20 $14 

APTR 

IO. 

.DEVICE 

/Device base address 

24 $18 

APTR 

IO. 

.UNIT 

/Unit structure 

28 $1C 

UWORD 

10. 

.COMMAND 

/ Command 

30 $1E 

UBYTE 

IO. 

.FLAGS 

/Flags 

31 $1F 

BYTE 

IO. 

.ERROR 

/Error code 

32 $20 

LABEL 

IO. 

.SIZE 

32 $20 

ULONG 

IO. 

.ACTUAL 

/Moved bytes etc. 

36 $24 

ULONG 

IO. 

.LENGTH 

/Length 

40 $28 

APTR 

IO. 

.DATA 

/Data address 

44 $2C 

ULONG 

IO. 

.OFFSET 

/Offset for positioning 

48 $30 

LABEL 

IOSTD_SIZE 

IOB_QUICK =  0, I  OF. 

.QUICK .= 1 

/execute immediately 

CMD_INVALID =  0 

No command 

CMD_RESET =  1 

.•reset device 

CMD_READ =  2 

 Read 

CMD_WRITE =  3 

/Write 

CMD_UPDATE =  4 

Write buffer 

CMD_CLEAR =  5 

C1 

ear buffer

CMD_STOJ 

= 6 

Stop 

CMD_START =  7  Continue 

CMD_FLUSH =  8  Delete commands 

CMD_NONSTD =  9   1 . Device specific command 

9. Resources 

Add Resource Make a  resource accessible to other programs | 

Call: AddResource ( resource ) 

-486 (A6) Al 

APTR resource 

Function: Adds a  completely initialized resource to the system list. 

Parameters: resource Library node of the resource. 

IQpenResource Get the base address of a  resource | 

Call: resource =  OpenResource(resName) 

DO -498 (A6) Al 

APTR resource, resName 

Function: Retrieves the base address of a  resource. 

Parameters: resName Resource name 

Result: Base address or 0  (error). 

RemResource Attempt to remove a  resource 

Call: RemResource ( resource ) 

-492 (A6) Al 

APTR resource 

Function: Attempts to initiate self-removal of the given resource. 

Parameters: resource Base address of the resource. 

10. Semaphores 

[AddSemaphore Initialize and link semaphore | 

Call: AddSemaphore (signalSemaphore) 

-600 (A6) Al 

STRUCT SS *signalSemaphore 

Function: Initializes an SS structure containing a  name and priority 

and adds it to the system list.

Parameters: signalSemaphore 

SS structure 

[AttemptSemaphore Attempt to allocate a  semaphore | 

Call: success =  AttemptSemaphore (signalSemaphore) 

DO -576 (A6) A0 

LONG success 

STRUCT SS *signalSemaphore 

Function: Attempts to allocate a  semaphore and returns to the caller if 

this is not possible.

Parameters: signalSemaphore 

SS structure 

Result: 0  SS was not free. 

[FindSemaphore Find a  semaphore | 

Call: signalSemaphore =  FindSemaphore (name) 

DO -594 (A6) Al 

STRUCT SS * signalSemaphore 

APTR name 

Function: Attempts to find a  semaphore with the given name. 

Parameters: name Semaphore name 

Result: SS structure or 0 

|InitSemaphore Initialize signal semaphore | 

Call: InitSemaphore (signalSemaphore) 

-558 (A6) AO 

STRUCT SS * signalSemaphore 

Function: Initializes an SS structure. 

Parameters: signalSemaphore 

Deleted SS structure 

IQbtainSemaphore Obtain exclusive access to a  semaphore | 

Call: ObtainSemaphore (signalSemaphore) 

-564 (A6) AO 

STRUCT SS *signalSemaphore 

Function: Allocates an SS structure. If this is not possible, the task is 

turned off until the semaphore is freed.

Parameters: signalSemaphore 

SS structure 

IQbtainSemaphoreList Allocate semaphores in a  listj 

Call: ObtainSemaphoreList (list) 

-582 (A6) AO 

STRUCT LH *list 

Function: Allocates all semaphores in the list or waits for them to be 

freed.

Parameters: list Semaphore list 

IQbtainSemaphoreShared Shared semaphore access | 

Call: Obtains emaphoreShared (signalSemaphore) 

-678 (A6) aO 

STRUCT SS *signalSemaphore 

Function: Obtains shared access to a  semaphore or waits for it to be 

freed.

Parameters: signalSemaphore 

SS structure 

| Procure Allocate message semaphore | 

Call: result =  Procure (semaphore, bidMessage) 

DO -540 (A6) A0 Al 

BYTE result 

STRUCT Semaphore * semaphore 

STRUCT MN *bidMessage 

Function: Attempts to allocate a  semaphore. 

Parameters: semaphore A  semaphore MsgPort 

Result: 0  Semaphore was not free. 

IReleaseSemaphore Free semaphore | 

Call: ReleaseSemaphore (signalSemaphore) 

-570 (A6) A0 

STRUCT SS *signalSemaphore 

Function: Frees a  given semaphore. 

Parameters: signalSemaphore 

SS structure 

IReleaseSemaphoreList Free a  semaphore list| 

Call: ReleaseSemaphoreList (list) 

-588 (A6) A0 

STRUCT LH *list 

Function: Frees a  semaphore list. 

Parameters: list Semaphore list 

| RemSemaphore Remove a  semaphore | 

Call: RemSemaphore ( signalSemaphore ) 

-606 (A6) Al 

STRUCT SS * signalSemaphore 

Function: Removes a  semaphore from its list. 

Parameters: signalSemaphore 

SS structure 

| Vacate Free a  message semaphore | 

Call: Vacate ( semaphore ) 

-546 (A6) A0 

STRUCT Semaphore * semaphore 

Function: Frees a  semaphore. 

Parameters: semaphore Semaphore MsgPort 

Dec Hex STRUCTURE SSR,MLN_SIZE  PRIVATE! 

8 $8 APTR SSR_WAITER 

12 $C LABEL SSR_SIZE 

Dec Hex STRUCTURE SS,LN_SIZE  SignalSemaphore 

14 $E WORD SS_NESTCOUNT  number of tasks 

16 $10 STRUCT SS_WAITQUEUE,MLH_SIZE wait queue 

28 $1C STRUCT SS_MULTIPLELINK, SSR_SIZE link 

40 $28 APTR SS_OWNER Task 

44 $2C WORD SS_QUEUECOUNT  queued Tasks 

46 $2E LABEL SS_SIZE 

Dec Hex STRUCTURE SM,MP_SIZE .-Message semaphore 

34 $22 WORD SM_BIDS  number of bids 

36 $24 LABEL SM_SIZE 

SMLOCKMSG =  MP_SIGTASK 

Example for Exec Library 

Exec has several new functions that make access to devices considerably 

easier. As an example, let's take a  look at how direct access to a  disk drive can be programmed:

** Direct access to a  floppy disk drive ** 

** ** 

** Input: A6 =  ExecBase ** 

** A5 =  DosBase ** 

** DO =  Drive (0...3) ** 

** Output: DO =  IOEXTTD ** 

** :=__ -==============================================** 

_GetAccess movem.l d2-d5, 

move .1 dO , d5

•(a7) 

dr ive number jsr _LVOCreateMsgPort (a6) move .1 dO , d3 beq.s .Error get port save address movea.l dO.aO port to aO moveq #IOTD_SIZE, dO size to dO jsr _LVOCreateIORequest (a6) get IORequest move.l d0,d4 save address beq.s .Del Port lea

_TDName (pc) ,  aO 

name to aO move . 1 d5,d0 number to dO movea . 1 dO,al

 IORequest 

moveq

#0,dl 

3.5" disks 

jsr

_LVOOpenDevice 1 

a6) open tst.l dO error test bne.s

.DellOReq 

exg a5, a6

 DosBase to a6 

lsl.l

#8,d5 

number «  1 byte addi . 1 tt'DFO: ' ,d5 add string clr .w

-(a7) 

end of string move . 1 d5,-(a7) move string move . 1 a7,dl string to dl jsr

_LVODeviceProc ( 

a6)

/Handler port 

addq . 1

#6,a7 

clear stack move . 1 dO.dl port to dl beq.s

. NoDevProc 

moveq

#DOSTRUE,d2 

jsr

_LVOInhibit(a6 

exg a5,a6 tst.l dO beq.s

.CloseDev 

move . 1 d4,d0 set Flag inhibit access
Exec to a6 

error test

IORequest -> dO 

.Exit movem.l (a7)+,d2-d5 

rts

. NoDevProc exg 

. CloseDev movea . 

jsr a5, a6
1 d4,al 

_LVOCloseDevice(a6) 

clean up end

Exec to a 6 

 IOReq to al 

close Dev

.DellOReq movea. 1 d4,a0  IOReq to aO 

jsr _LVODeleteIORequest(a6)  delete IOReq

.De 

iPort movea . 1 d3,a0 port to aO jsr

_LVODeleteMsgPort (a6) 

delete port moveq

#0,d0 

no result bra.s

.Exit 

end

**— 

====== 

_________ 

========================= 

=============** 

* * 

Free drive 

* * 

** 

** 

Input : 

A6 =  ExecBase 

** 

** 

A5 =  DosBase 

** 

** 

Al =  IORequest 

* * 

** 

DO =  Drive (0. .  .3) 

* * 

** 

Output : 

DO =  Success (0=Error) 

* * 

**_ 

====== 

— — 

It-It 

_FreeDrive movem. 1 d2-d3 , - (a7 ) 

move .1 dO , d3 save drive move.l al,d2 save IOReq jsr _LVOCloseDevice (a6) close Dev movea. 1 d2,a0  IOReq to aO move.l MN_REPLYPORT(a0) ,d2  save port jsr _LVODeleteIORequest (a6) ,-delete IOReq movea. 1 d2,a0 port to aO jsr _LVODeleteMsgPort (a6) delete port exg a5,a6 lsl.l #8,d3 addi .1 # ' DFO : ' , d3

DOS to a 6 

number «  1 byte add string clr.w -(a7) move.l d3,-(a7) move .1 a7 , dl jsr _LVODeviceProc(a6) addq.l #6,a7 move .1 dO , dl beq . s . NoDevProc moveq #D0SFALSE,d2 jsr _LVOInhibit(a6)

.NoDevProc exg a5,a6 

tst.l dO movem.l (a7)+,d2-d3 rts end of string move string string to dl
 Handler port 

clear stack port to dl code to free free

Exec to a6 

set CC clean up end

_TDName 

dc.b

' trackdisk. device' , 0 

DeviceName 

OPT 0+ 

INCLUDE IncAll.i 

** NoClick 

While we are working with the trackdisk device, here is a  program that turns off the annoying clicking sound made by an empty disk drive. This program can be started from the CLI/Shell or the Workbench. It is made possible by a  new flag in the Unit structures. We will also see an example of minimum message handling for Workbench starts, especially at the end of the program, which is responsible for freeing memory when the program is segmented:

_Startup 

movea.l $4.w,a6 load ExecBase movea . 1 ThisTask (a6 ) , a5 moveq #0,d7 tst.l pr_CLI(a5) bne.s _CLIstart lea jsr lea jsr move .1 dO , d7 pr_MsgPort (a5) ,aO
JLVOWaitPort (a6) 

pr_JIsgPort (a5) , aO
_LV0GetMsg(a6) 

get process
WbStartup to 0 

,-test CLI 

->if available 

ProcessPort 

wait for message
ProcessPort 

get message save WbStartup

.CLIstart 

cmpi.w #36,LIB_VERSION(a6) blt.s _ReplyStartup test OS 2
->if not OS 2 

jsr _LVOCreateMsgPort (a6) move .1 dO , d6 beq . s _ReplyStartup create MsgPort and save
->if error 

movea .1 dO , aO moveq #IOSTD_SIZE, dO jsr _LVOCreateIORequest (a6) move .1 dO , d5 beq.s _delport

 MsgPort to aO 

structure size get IORequest and save
->if error 

moveq

#3,d4 

.NoClickLoop 

lea

_tdname(pc) ,a0 

move . 1 d4,d0 movea. 1 d5,al moveq

jsr

_LVOOpenDevice (a6 ) 

tst.l dO bne.s

_next 

 4  drives 

 DeviceName 

/drive number 

 IORequest 

3.5" only 

open error test
->if error 

movea. 1 d5,al  IORequest movea. 1 IO_UNIT(al) , aO get UnitPort ori.b #TDPF_NOCLICK,TDU_PUBFLAGS(aO) save Flag jsr _LV0CloseDevice(a6)  close device

.next 

dbra d4,_NoClickLoop all drives

_delio 

movea. 1 d5,a0 jsr _LVODeleteIORequest (a6)

 IORequest to aO 

/delete IORequest 

_delport 

movea .1 d6 , aO jsr JLVODeleteMsgPort (a6) port to aO
/delete port 

_ReplyStartup 

move .1 d7 , dO beq.s _fromCLI

WbStartup to dO 

->if not there 

movea .1 dO , al j mp _LVORep lyMsg ( a 6 )

WbStartup to al 

reply

.•Return to program would lead to a  crash. If necessary, turn 

/multitasking off first (it will activate itself again after the 

.•program ends) . 

_fromCLI 

rts end of program

_tdname 

dc . b ' trackdisk . device ' , 0  DeviceName

Cache Control 

The 68030 uses internal memory to store the last command and the last memory access during the execution of the command. This internal memory, called a  cache, can greatly speed up processing. If the values that the processor needs are found in a  cache, then no more RAM access is necessary, which with a  non-multiplexed bus in a  32 bit architecture is rather time-consuming. Normally, the processor does not access the memory block containing the program code when executing a  command. The separation of command and data caches can therefore speed things up greatly. Self-modifying code must be excluded from this, however, because the changes would be made in the data cache and not in the command cache. The Amiga's coprocessors, the DMA chips, are another problem. If one of these manipulates the memory, the contents of the caches do not change and the processor will be working with the wrong values. This could make it necessary to turn off the caches or delete them. Assembler programmers can use the CACR (CAche Control
Register) and CAAR (CAche Address Register) to delete individual 

cache entries, but this is not in conformance with the operating system.

Another way of managing the caches is needed for developing high 

speed programs. The 68030 offers the ability to "freeze" the contents of its caches. The contents of a  frozen cache cannot be changed, but they can be read. This allows you to freeze the cache of a  frequently used subroutine after you have run it. General program processing is a  little slower because of this, but the subroutine will be extremely fast the next time it is called. The Exec takes care of managing and storing the contents of the CACR in our example:

Turn off caches 

movea.l $4.w,a6  load ExecBase moveq #0,d0 new cache bits (value=0) move.l #CACRF_EnableI!CACRF_EnableD,dl mask jsr _LVOCacheControl (a6) save caches

Activate caches 

_* * 

** 

_* * 

movea.l $4.w,a6  load ExecBase move.l #CACRF_EnableI!CACRF_EnableD,dO new cache bits move.l dO,dl mask jsr _LV0CacheControl(a6) /activate caches

* *_ 

* * 

* *_ 

Turn off caches 

movea.l $4.w,a6 load ExecBase moveq #0,d0 new cache bits (value=0) move.l #CACRF_EnableI!CACRF_EnableD,dl mask jsr _LVOCacheControl (a6)  lock caches

** Delete caches (User mode) ** 

** ** 

movea.l $4.w,a6 moveq #-l,dO jsr _LV0CacheClearU(a6) load ExecBase both caches delete caches

** Store subroutine in cache ** 

** ================================** 

movea.l $4.w,a6 load ExecBase jsr _VeryWichtigHighTech  subroutine move.l #CACRF_FreezeI!CACRF_FreezeD,dO new cache bits move.l dO,dl mask jsr _LV0CacheControl(a6) /freeze caches

** Free caches ** 

** .-.---_______________________=__========** 

movea.l $4.w,a6 load ExecBase moveq #0,d0 new cache bits move.l #CACRF_FreezeI!CACRF_FreezeD,dl /mask jsr _LV0CacheControl(a6) free caches

Another problem can arise using Burst mode. If the hardware is properly 

designed, the 68030 can move 16 bytes from cache to RAM (or RAM to cache) in only 5  clock cycles (=2-1-1-1 burst). The data transfer is done in 16 byte steps and is based on modulo 16 addresses. This is a  good reason for keeping your data well-organized, as the C  structures of the operating system are. The speed in Burst mode is determined to a  large extent by which memory chips are used. Dynamic Nibble mode RAM, as used in the ChipMem region, will only allow a  4-1-1-1 burst (7 clock cycles). Also, if the memory chips have added WaitStates during the last three longword accesses, this can slow down the processor even more, since each WaitState costs two clock cycles. But regardless of the speed, problems can still occur because of DMA accesses when the data is disorganized. The solution here involves CACRF_IBE and
CACRF_DBE, which can be used to turn the Instruction burst and the 

Data burst on and off via CacheControl. 

