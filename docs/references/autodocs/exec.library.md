# exec.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 112
**Obsolete:** 2

## Function Index

- **AbortIO** — 
- **AddDevice** — add a device to the system
- **AddHead** — insert node at the head of a list
- **AddIntServer** — add an interrupt server to a system server chain
- **AddLibrary** — add a library to the system
- **AddMemhandler** (V39) — 
- **AddMemList** — 
- **AddPort** — add a public message port to the system
- **AddResource** — add a resource to the system
- **AddSemaphore** — initialize then add a signal semaphore to the system
- **AddTail** — append node to tail of a list
- **Alert** — Alert the user of an error
- **AllocAbs** — allocate at a given location
- **Allocate** — 
- **AllocMem** — allocate memory given certain requirements
- **AllocPooled** (V39) — Allocate memory with the pool manager
- **AllocSignal** — allocate a signal bit
- **AllocTrap** — allocate a processor trap vector (Obsolete)
- **AllocVec** (V36) — allocate memory and keep track of the size
- **AttemptSemaphore** — try to obtain without blocking
- **AttemptSemaphoreShared** (V37) — try to obtain without blocking
- **AvailMem** — memory available given certain requirements
- **CacheClearE** (V37) — 
- **CacheClearU** (V37) — 
- **CacheControl** — 
- **CachePostDMA** (V37) — 
- **CachePreDMA** (V37) — 
- **Cause** — cause a software interrupt
- **CheckIO** — get the status of an IORequest
- **CloseDevice** — conclude access to a device
- **CloseLibrary** — conclude access to a library
- **ColdReboot** (V36) — 
- **CopyMem** — 
- **CopyMemQuick** — 
- **CreateIORequest** (V36) — create an IORequest structure
- **CreateMsgPort** (V36) — 
- **CreatePool** (V39) — Generate a private memory pool header
- **DeleteIORequest** (V36) — 
- **DeleteMsgPort** (V36) — 
- **DeletePool** (V39) — Drain an entire memory pool
- **Dellocate** — deallocate a block of memory
- **Disable** — disable interrupt processing.
- **DoIO** — perform an I/O command and wait for completion
- **Enable** — permit system interrupts to resume.
- **Enqueue** — insert or append node to a system queue
- **FindName** — find a system list node with a given name
- **FindPort** — find a given system message port
- **FindResident** — 
- **FindSemaphore** — find a given system signal semaphore
- **FindTask** — find a task with the given name or find oneself
- **Forbid** — forbid task rescheduling.
- **FreeEntry** — free many regions of memory.
- **FreeMem** — deallocate memory
- **FreePooled** (V39) — Free pooled memory
- **FreeSignal** — free a signal bit
- **FreeTrap** — free a processor trap (Obsolete)
- **FreeVec** (V36) — return AllocVec() memory to the system
- **GetCC** — get condition codes in a 68010 compatible way. (Obsolete)
- **GetMsg** — get next message from a message port
- **IceColdReboot** — Reboot to power-on state
- **InitCode** — 
- **InitResident** — 
- **InitSemaphore** — initialize a signal semaphore
- **InitStruct** — 
- **Insert** — insert a node into a list
- **MakeFunctions** — construct a function jump table
- **NewStackRun** — Run a function with its own stack frame.    (V52.6)
- **ObtainQuickVector** (V39) — 
- **ObtainSemaphore** — gain exclusive access to a semaphore
- **ObtainSemaphoreList** — get a list of semaphores.
- **ObtainSemaphoreShared** (V36) — gain shared access to a semaphore
- **OpenDevice** — gain access to a device
- **OpenLibrary** — gain access to a library
- **OpenResource** — gain access to a resource
- **Permit** — permit task rescheduling.
- **Procure** (V39) — bid for a semaphore
- **PutMsg** — put a message to a message port
- **RawDoFmt** — format data into a character stream.
- **ReleaseSemaphore** — make signal semaphore available to others
- **ReleaseSemaphoreList** — make a list of semaphores available
- **RemDevice** — remove a device from the system
- **RemHead** — remove the head node from a list
- **RemIntServer** — remove an interrupt server from a server chain
- **RemLibrary** — remove a library from the system
- **RemMemHandler** (V39) — 
- **Remove** — remove a node from a list
- **RemPort** — remove a message port from the system
- **RemResource** — remove a resource from the system
- **RemSemaphore** — remove a signal semaphore from the system
- **RemTail** — remove the tail node from a list
- **RemTask** — remove a task from the system
- **ReplyMsg** — put a message to its reply port
- **SendIO** — initiate an I/O command
- **SetExcept** — define certain signals to cause exceptions
- **SetFunction** — change a function vector in a library
- **SetIntVector** — set a new handler for a system interrupt vector
- **SetMethod** — Modify a method in an interface
- **SetSignal** — define the state of this task's signals
- **SetSR** — get and/or set processor status register (Obsolete)
- **SetTaskPri** — get and set the priority of a task
- **Signal** — signal a task
- **StackSwap** (V37) — 
- **SumKickData** — compute the checksum for the Kickstart delta list
- **SumLibrary** — compute and check the checksum on a library
- **SuperState** — enter supervisor state with user stack
- **Supervisor** — trap to a short supervisor mode function
- **TypeOfMem** — determine attributes of a given memory address
- **UserState** — return to user state with user stack
- **Vacate** (V39) — release a bitMessage from Procure()
- **Wait** — wait for one or more signals
- **WaitIO** — wait for completion of an I/O request
- **WaitPort** — wait for a given port to be non-empty

## Functions

### exec.library/AbortIO

**Synopsis:**
```c
AbortIO(iORequest)

VOID AbortIO(struct IORequest *);
```

**Description:**
Ask a device to abort a previously started IORequest.  This is done
by calling the device's ABORTIO vector, with your given IORequest.

AbortIO is a command that the device may or may not grant.  If
successful, the device will stop processing the IORequest, and
reply to it earlier than it would otherwise have done.

**Inputs:**
iORequest - pointer to an I/O request block (must have been used
        at least once.  May be active or finished).

**Example:**
```c
AbortIO(timer_request);
WaitIO(timer_request);
/* Message is free to be reused */
```

**Notes:**
AbortIO() does NOT Remove() the IORequest from your reply port, OR
wait for it to complete.  After an AbortIO() you must wait normally
for the reply message before actually reusing the request.  AbortIO()
MUST be followed either by a call to WaitIO() or an equivalent
GetMsg() call (see WaitIO() for an example).

If a request has already completed when AbortIO() is called, no
action is taken.

You must not call AbortIO() on an IORequest that has never been
successfully used with OpenDevice() and that is not a duplicate of
an IORequest which was successfully used with OpenDevice(). If you
use it on an IORequest that was just created with CreateIORequest()
or which was just used with the CloseDevice() function, you will
either cause your task to hang, or you may crash the operating
system.

**See also:** WaitIO(), DoIO(), SendIO(), CheckIO()

---

### exec.library/AddDevice

**add a device to the system**

**Synopsis:**
```c
AddDevice(device)

void AddDevice(struct Device *);
```

**Description:**
This function adds a new device to the system device list, making
it available to other programs.  The device must be ready to be
opened at this time.

**Inputs:**
device - pointer to a properly initialized device node

**See also:** RemDevice, OpenDevice, CloseDevice, MakeLibrary

---

### exec.library/AddHead

**insert node at the head of a list**

**Synopsis:**
```c
AddHead(list, node)

 void AddHead(struct List *, struct Node *)
```

**Description:**
Add a node to the head of a doubly linked list.

**Inputs:**
list - a pointer to the target list header
 node - the node to insert at head

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddTail, Enqueue, Insert, Remove, RemHead, RemTail

---

### exec.library/AddIntServer

**add an interrupt server to a system server chain**

**Synopsis:**
```c
success = AddIntServer(intNum, interrupt)

BOOL AddIntServer(ULONG, struct Interrupt *);
```

**Description:**
This function adds a new interrupt server to a given server chain.
The node is located on the chain in a priority dependent position.
If this is the first server on a particular chain, interrupts will
be enabled for that chain.

Each link in the chain will be called in priority order until the
chain ends or one of the servers returns with a non-zero return value.

Interrupts number 0 to 15 are "legacy" interrupts, corresponding to 
the Amiga's original Paula interrupt levels. However, starting in V50,
other interrupts might exist. This function can also be used to add
global trap handlers. See exec/interrupts.h

	Starting with V50, the interrupt handler function will look like this:

ULONG handler(struct ExceptionContext *Context, struct ExecBase *SysBase,
                APTR userData);

Context is a pointer to the register storage area. Under normal conditions,
only volatile register will have been saved, and the appropriate flag will
be clear to reflect this. Note, though, that you have to be prepared to handle
all cases (if you need access to the interrupted task's registers, anyway).
Additionally, userData is the pointer to the user data field taken from the
Interrupt's data structure.

**Inputs:**
intNum - The interrupt number.
         
interrupt - pointer to an Interrupt structure.
         By convention, the LN_NAME of the interrupt structure must
         point a descriptive string so that other users may
         identify who currently has control of the interrupt.

**Result:**
If the interrupt could be added, a result of TRUE is returned, 
otherwise, FALSE is returned. FALSE might indicate that the
appropriate interrupt does not exist.

**See also:** RemIntServer, SetIntVector, hardware/intbits.i, exec/interrupts.i

---

### exec.library/AddLibrary

**add a library to the system**

**Synopsis:**
```c
AddLibrary(library)

void AddLibrary(struct Library *);
```

**Description:**
This function adds a new library to the system, making it available
to other programs.  The library should be ready to be opened at
this time.  It will be added to the system library name list, and
the checksum on the library entries will be calculated.

**Inputs:**
library - pointer to a properly initialized library structure

**See also:** RemLibrary, CloseLibrary, OpenLibrary, MakeLibrary

---

### exec.library/AddMemhandler (V39)

**Synopsis:**
```c
AddMemHandler(memHandler)

 VOID AddMemHandler(struct Interrupt *);
```

**Description:**
This function adds a low memory handler to the system.  The handler
 is described in the Interrupt structure.  Due to multitasking
 issues, the handler must be ready to run the moment this function
 call is made.  (The handler may be called before the call returns)

**Inputs:**
memHandler - A pointer to a completely filled in Interrupt structure
              The priority field determine the position of the handler
              with respect to other handlers in the system.  The higher
              the priority, the earlier the handler is called.
              Positive priorities will have the handler called before
              any of the library expunge vectors are called.  Negative
              priority handlers will be called after the library
              expunge routines are called.
              (Note:  RAMLIB is a handler at priority 0)

 Upon exit, the handler function should return one of the
 following values:

 MEM_DID_NOTHING - The handler didn't do anything. This
                   means the next handler will be invoked,
                   without repeating the failed allocation.
 MEM_ALL_DONE    - The handler is done, and the allocation
                   will be repeated. The next handler will
                   be invoked.
 MEM_TRY_AGAIN   - The handler will be called again.

 The function's protoype looks like this:
 LONG Handler(struct ExecBase *,  struct MemHandlerData *, APTR);
 Look below for an example.

**Example:**
```c
struct Interrupt *myInt;      /* Assume it is allocated */

 myInt->is_Node.ln_Pri  = 50;  /* Very early, before RAMLIB */
 myInt->is_Node.ln_Name = "Example Handler";  /* Do give it a name ! */
 myInt->is_Node.ln_Type = NT_INTERRUPT;
 myInt->is_Data         = (APTR)mydata_pointer;
 myInt->is_Code         = (VOID (*)())myhandler_code;

 AddMemHandler(myInt);
 ... /* and so on */


 /* Be advised that the is_Node.ln_Type may be changed to either */
 /* NT_INTERRUPT or NT_EXTINTERRUPT by the AddMemHandler() call, */
 /* based on whether the is_Code field is pointing to native or  */
 /* legacy 68K code. */


 /*
  * This is the handler code.
  * We are passed a pointer to ExecBase in r3,
  * a pointer to a struct MemHandlerData in r4,
  * the value of is_Data in r5.
  * We must not break forbid!!!
  */

 LONG myhandler_code(struct ExecBase *ExecBase,
                     struct MemHandlerData *memHandlerData,
                     APTR is_Data UNUSED)
 {
    /* Assume we did nothing */
    ULONG retval = MEM_DID_NOTHING;

    if (memHandlerData->memh_RequestFlags & MEMF_CHIP)
    {
        /* Do whatever we can do to free chip ram */
        retval = MEM_ALL_DONE;
    }

    return retval;
 }
```

**Notes:**
Adding a handler from within a handler will cause undefined
 actions.  It is safe to add a handler to the list while within
 a handler but the newly added handler may or may not be called
 for the specific failure currently running.

**See also:** RemMemHandler, exec/interrupts.i

---

### exec.library/AddMemList

**Synopsis:**
```c
AddMemList( size, attributes, pri, base, name )

 void AddMemList(ULONG, ULONG, LONG, APTR, STRPTR);
```

**Description:**
Add a new region of memory to the system free pool.  The first few
 bytes will be used to hold the MemHeader structure.  The remainder
 will be made available to the rest of the world.

**Inputs:**
size - the size (in bytes) of the memory area
 attributes - the attributes word that the memory pool will have
 pri  - the priority for this memory.  CHIP memory has a pri of -10,
        16 bit expansion memory has a priority of 0.  The higher the
        priority, the closer to the head of the memory list it will
        be placed.
 base - the base of the new memory area
 name - the name that will be used in the memory header, or NULL
        if no name is to be provided.  This name is not copied, so it
        must remain valid for as long as the memory header is in the
        system.

**Notes:**
*DO NOT* add memory to the system with the attribute of MEMF_KICK.
 EXEC will mark your memory as such if it is of the right type.

**See also:** AllocMem, exec/memory.h

---

### exec.library/AddPort

**add a public message port to the system**

**Synopsis:**
```c
AddPort(port)

void AddPort(struct MsgPort *);
```

**Description:**
This function attaches a message port structure to the system's
public message port list, where it can be found by the FindPort()
function.  The name and priority fields of the port structure must
be initialized prior to calling this function.  If the user does
not require the priority field, it should be initialized to zero.

Only ports that will be searched for with FindPort() need to
be added to the system list.  In addition, adding ports is often
useful during debugging.  If the port will be searched for,
the priority field should be at least 1 (to avoid the large number
of inactive ports at priority zero).  If the port will be searched
for often, set the priority in the 50-100 range (so it will be
before other less used ports).

Once a port has been added to the naming list, you must be careful
to remove the port from the list (via RemPort) before deallocating
its memory.

**Inputs:**
port - pointer to a message port

**Notes:**
A point of confusion is that clearing a MsgPort structure to all
zeros is not enough to prepare it for use.  As mentioned in the
Exec chapter of the ROM Kernel Manual, the List for the MsgPort
must be initialized.  This is automatically handled by AddPort(),
and amiga.lib/CreatePort.  This initialization can be done manually
with amiga.lib/NewList or the assembly NEWLIST macro.

Do not AddPort an active port.

**See also:** RemPort, FindPort

---

### exec.library/AddResource

**add a resource to the system**

**Synopsis:**
```c
AddResource(resource)

void AddResource(APTR);
```

**Description:**
This function adds a new resource to the system and makes it
available to other users.  The resource must be ready to be called
at this time.

Resources currently have no system-imposed structure, however they
must start with a standard named node (LN_SIZE), and should with
a standard Library node (LIB_SIZE).

**Inputs:**
resource - pointer an initialized resource node

**See also:** RemResource, OpenResource, MakeLibrary

---

### exec.library/AddSemaphore

**initialize then add a signal semaphore to the system**

**Synopsis:**
```c
AddSemaphore(signalSemaphore)

void AddSemaphore(struct SignalSemaphore *);
```

**Description:**
This function attaches a signal semaphore structure to the system's
public signal semaphore list.  The name and priority fields of the
semaphore structure must be initialized prior to calling this
function.  If you do not want to let others rendezvous with this
semaphore, use InitSemaphore() instead.

If a semaphore has been added to the naming list, you must be
careful to remove the semaphore from the list (via RemSemaphore)
before deallocating its memory.

Semaphores that are linked together in an allocation list (which
ObtainSemaphoreList() would use) may not be added to the system
naming list, because the facilities use the link field of the
signal semaphore in incompatible ways

**Inputs:**
signalSemaphore -- an signal semaphore structure

**See also:** RemSemaphore, FindSemaphore, InitSemaphore

---

### exec.library/AddTail

**append node to tail of a list**

**Synopsis:**
```c
AddTail(list, node)

 void AddTail(struct List *, struct Node *);
```

**Description:**
Add a node to the tail of a doubly linked list.  Assembly
 programmers may prefer to use the ADDTAIL macro from
 "exec/lists.i".

**Inputs:**
list - a pointer to the target list header
 node - a pointer to the node to insert at tail of the list

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddHead, Enqueue, Insert, Remove, RemHead, RemTail

---

### exec.library/Alert

**Alert the user of an error**

**Synopsis:**
```c
void Alert(uint32 alertNum)
```

**Description:**
Alerts the user of a serious system problem. This function will
bring the system to a grinding halt, and do whatever is necessary
to present the user with a message stating what happened.

Interrupts are disabled, and an attempt to post the alert is made.
If that fails, the system is reset. When the system comes up
again, Exec notices the cause of the failure and tries again to
post the alert.

If the Alert is a recoverable type, this call MAY return.

This call may be made at any time, including interrupts.
(Well, only in interrupts if it is non-recoverable)

New, for V39:
The alert now times out based on the value in LastAlert[3]
This value is transfered across warm-reboots and thus will let
you set it once. The value is the number of frames that need to
be displayed before the alert is auto-answered. A value of
0 will thus make the alert never be displayed. Note that
it is recommended that applications *NOT* change the value in
LastAlert[] since the main reason for this is to make
unattended operation of the Amiga (in production enviroments)
possible.

   POST-MORTEM DIAGNOSIS
There are several options for determining the cause of a crash.
Descriptions of each alert number can be found in the "alerts.h"
include file.

A remote terminal can be attached to the Amiga's first built-in
serial port. Set the communication parameters to 9600 baud, 8 bits,
no parity. Before resetting the machine, the Alert function will
blink the power LED 10 times. While the power indicator is flashing,
pressing DELETE on the remote terminal will invoke the ROM debugger.

**Inputs:**
alertNum   - a number indicating the particular alert.  -1 is
             not a valid input.

**Notes:**
Much more needs to be said about this function and its implications.

**See also:** exec/alerts.h

---

### exec.library/AllocAbs

**allocate at a given location**

**Synopsis:**
```c
memoryBlock = AllocAbs(byteSize, location)

 void *AllocAbs(ULONG, APTR);
```

**Description:**
This function attempts to allocate memory at a given absolute
 memory location.  Often this is used by boot-surviving entities
 such as recoverable ram-disks.  If the memory is already being
 used, or if there is not enough memory to satisfy the request,
 AllocAbs will return NULL.

 This block may not be exactly the same as the requested block
 because of rounding, but if the return value is non-zero, the block
 is guaranteed to contain the requested range.

**Inputs:**
byteSize - the size of the desired block in bytes
            This number is rounded up to the next larger
            block size for the actual allocation.
 location - the address where the memory MUST be.

**Result:**
memoryBlock - a pointer to the newly allocated memory block, or
               NULL if failed.

**Notes:**
If the free list is corrupt, the system will panic with alert
 AN_MemCorrupt, $01000005.

 The 8 bytes past the end of an AllocAbs will be changed by Exec
 relinking the next block of memory.  Generally you can't trust
 the first 8 bytes of anything you AllocAbs.

**See also:** AllocMem, FreeMem

---

### exec.library/Allocate

**Synopsis:**
```c
memoryBlock=Allocate(memHeader, byteSize)

 void *Allocate(struct MemHeader *, ULONG);
```

**Description:**
This function is used to allocate blocks of memory from a given
 private free memory pool (as specified by a MemHeader and its
 memory chunk list).  Allocate will return the first free block that
 is greater than or equal to the requested size.

 All blocks, whether free or allocated, will be block aligned;
 hence, all allocation sizes are rounded up to the next block even
 value (e.g. the minimum allocation resolution is currently 8
 bytes.  A request for 8 bytes will use up exactly 8 bytes.  A
 request for 7 bytes will also use up exactly 8 bytes.).

 This function can be used to manage an application's internal data
 memory.  Note that no arbitration of the MemHeader and associated
 free chunk list is done.  You must be the owner before calling
 Allocate.

**Inputs:**
memHeader - points to the local memory list header.
 byteSize - the size of the desired block in bytes.

**Result:**
memoryBlock - a pointer to the just allocated free block.
        If there are no free regions large enough to satisfy the
        request, return zero.

**Example:**
```c
#include <exec/types.h>
 #include <exec/memory.h>
 void *AllocMem();
 #define BLOCKSIZE 4096L /* Or whatever you want */

 void main()
 {
 struct MemHeader *mh;
 struct MemChunk  *mc;
 APTR   block1;
 APTR   block2;

     /* Get the MemHeader needed to keep track of our new block */
     mh = (struct MemHeader *)
          AllocMem((long)sizeof(struct MemHeader), MEMF_CLEAR );
     if( !mh )
         exit(10);

     /* Get the actual block the above MemHeader will manage */
     mc = (struct MemChunk *)AllocMem( BLOCKSIZE, 0L );
     if( !mc )
         {
         FreeMem( mh, (long)sizeof(struct MemHeader) ); exit(10);
         }

     mh->mh_Node.ln_Type = NT_MEMORY;
     mh->mh_Node.ln_Name = "myname";
     mh->mh_First = mc;
     mh->mh_Lower = (APTR) mc;
     mh->mh_Upper = (APTR) ( BLOCKSIZE + (ULONG) mc );
     mh->mh_Free  = BLOCKSIZE;

     /* Set up first chunk in the freelist */
     mc->mc_Next  = NULL;
     mc->mc_Bytes = BLOCKSIZE;

     block1 = (APTR) Allocate( mh, 20L );
     block2 = (APTR) Allocate( mh, 314L );
     printf("mh=$%lx mc=$%lx\n",mh,mc);
     printf("Block1=$%lx, Block2=$%lx\n",block1,block2);

     FreeMem( mh, (long)sizeof(struct MemHeader) );
     FreeMem( mc, BLOCKSIZE );
 }
```

**Notes:**
If the free list is corrupt, the system will panic with alert
 AN_MemCorrupt, $01000005.

**See also:** Deallocate, exec/memory.h

---

### exec.library/AllocMem

**allocate memory given certain requirements**

**Synopsis:**
```c
memoryBlock = AllocMem(byteSize, attributes)

 void *AllocMem(ULONG, ULONG);
```

**Description:**
This is the memory allocator to be used by system code and
 applications.  It provides a means of specifying that the allocation
 should be made in a memory area accessible to the chips, or
 accessible to shared system code.

 Memory is allocated based on requirements and options.  Any
 "requirement" must be met by a memory allocation, any "option" will
 be applied to the block regardless.  AllocMem will try all memory
 spaces until one is found with the proper requirements and room for
 the memory request.

**Inputs:**
byteSize - the size of the desired block in bytes.  (The operating
         system will automatically round this number to a multiple of
         the system memory chunk size)

 attributes -
     requirements

         If no flags are set, the system will return the best
         available memory block.  For expanded systems, the fast
         memory pool is searched first.

         MEMF_ANY:       Any memory that is available should be used.


         MEMF_CHIP:      If the requested memory will be used by
                         the classic Amiga custom chips, this flag *must*
                         be set.

                         Only certain parts of memory are reachable
                         by the special chip sets' DMA circuitry.
                         Chip DMA includes screen memory, images that
                         are blitted, audio data, copper lists, sprites
                         and Pre-V36 trackdisk.device buffers.

                         This flag is obsolete and interpreted as
                         MEMF_SHARED in exec.library 51.34 or higher
                         when not running on a classic machine.


         MEMF_FAST:      This is non-chip memory.  If no flag is set
                         MEMF_FAST is taken as the default.

                         DO NOT SPECIFY MEMF_FAST unless you know
                         exactly what you are doing!  If MEMF_FAST is
                         set, AllocMem() will fail on machines that
                         only have chip memory!  This flag may not
                         be set when MEMF_CHIP is set.

                         This flag is obsolete and interpreted as
                         MEMF_SHARED in exec.library 51.34 or higher.


         MEMF_EXECUTABLE:This memory will have execute permission, i.e. code loaded
                         into this memory can be jumped to. Note that this basically
                         defines a new memory "type" (like MEMF_CHIP, MEMF_FAST).
                         Executable memory might be virtual (i.e. phyiscal and visible
                         addresses might differ), but is never swapped.
                         Note: 
                         - All other memory does *NOT* have execute permission.
                         - Execute permission is only necessary for native code.
                         - Code that might be shared between several tasks has
                           to be allocated with MEMF_SHARED.
                         ALLOCATING MEMF_EXECUTABLE MIGHT BREAK A FORBID.


         MEMF_PUBLIC:    Memory that is not protected, i.e. is freely accessible
                         by anyone. This includes IPC related data structures,
                         like Messages, MessagePorts, etc.

                         This memory will never be swapped out,
                         or otherwise made non-addressable. It will also
                         be guaranteed that memory allocated as MEMF_PUBLIC
                         will have equal physical and virtual addresses.
                         
                         ALL MEMORY THAT IS REFERENCED VIA INTERRUPTS
                         MUST BE PUBLIC. 

                         MEMF_PUBLIC is a stronger form of MEMF_SHARED: MEMF_SHARED
                         is automatically implied with MEMF_PUBLIC.
               
         MEMF_SHARED:    Memory of this type is shareable between tasks. This
                         means that different tasks can access it. 


         MEMF_PRIVATE:   Accesses from other tasks than the allocating tasks 
                         are not allowed. The OS may protect this memory against 
                         these accesses.


         MEMF_LOCAL:     This is memory that will not go away
                         after the CPU RESET instruction.  Normally,
                         autoconfig memory boards become unavailable
                         after RESET while motherboard memory
                         may still be available.  This flag is obsolete
                         and ignored in exec.library 51.34 or higher.


         MEMF_24BITDMA:  This is memory that is within the address
                         range of 24-bit DMA devices.  (Zorro-II)
                         This is required if you run a Zorro-II
                         DMA device on a machine that has memory
                         beyond the 24-bit addressing limit of
                         Zorro-II.  This flag is obsolete and
                         ignored in exec.library 51.34 or higher.


         MEMF_KICK:      This memory is memory that EXEC was able
                         to access during/before the KickMem and
                         KickTags are processed.  This means that
                         if you wish to use these, you should allocate
                         memory with this flag.  Also, *DO NOT*
                         ever add memory the system with this flag
                         set.  EXEC will set the flag as needed
                         if the memory matches the needs of EXEC.
                         This flag is obsolete and ignored in
                         exec.library 51.34 or higher.


     options

         MEMF_CLEAR:     The memory will be initialized to all
                         zeros.


         MEMF_REVERSE:   This allocates memory from the top of
                         the memory pool.  It searches the pools
                         in the same order, such that FAST memory
                         will be found first.  However, the
                         memory will be allocated from the highest
                         address available in the pool.  This
                         option is new as of V36.  Note that this
                         option has a bug in pre-V39 systems.

                         This flag is obsolete and ignored in
                         exec.library 51.34 or higher, except when
                         running on a classic machine and MEMF_CHIP
                         was set also.


         MEMF_NO_EXPUNGE This will prevent an expunge to happen on
                         a failed memory allocation.  This option is
                         new to V39 and will be ignored in V37.
                         If a memory allocation with this flag
                         set fails, the allocator will not cause
                         any expunge operations.  (See AddMemHandler())
  
         MEMF_HWALIGNED: To be able to set the attributes of a certain memory area, 
                         giving this flag to AllocMem will enforce a certain
                         alignment of the memory. Normally, this means that
                         the returned block will be the only memory in a hardware
                         page. The size of this page depends on the CPU. You should
                         not assume any alignemnt yourself.
                         Note: This flag might allocate much more memory than you actually
                         request. Don't use it without reason.

**Result:**
memoryBlock - a pointer to the newly allocated memory block.
         If there are no free memory regions large enough to satisfy
         the request, zero will be returned.  The pointer must be
         checked for zero before the memory block may be used!
         The memory block returned is long word aligned.

         By default, the memory block is set to MEMATTRF_SUPER_RW_USER_RW.
         If the memory is allocated with MEMF_CHIP, it's additionally
         MEMATTRF_CACHEINHIBIT.

**Example:**
```c
AllocMem(64,0L)         - Allocate the best available memory
 AllocMem(25,MEMF_CLEAR) - Allocate the best available memory, and
                           clear it before returning.
 AllocMem(128,MEMF_CHIP) - Allocate chip memory
 AllocMem(128,MEMF_CHIP|MEMF_CLEAR) - Allocate cleared chip memory
 AllocMem(821,MEMF_CHIP|MEMF_PUBLIC|MEMF_CLEAR) - Allocate cleared,
         public, chip memory.
```

**Notes:**
If the free list is corrupt, the system will panic with alert
 AN_MemCorrupt, $01000005.

 This function may not be called from interrupts.

 A DOS process will have its pr_Result2 field set to
 ERROR_NO_FREE_STORE if the memory allocation fails.

 This function is obsolete, use AllocVecTagList

**See also:** FreeMem, AllocVecTagList

---

### exec.library/AllocPooled (V39)

**Allocate memory with the pool manager**

**Synopsis:**
```c
memory = AllocPooled(poolHeader,memSize)

 void *AllocPooled(void *,ULONG);
```

**Description:**
Allocate memSize bytes of memory, and return a pointer. NULL is
 returned if the allocation fails.

 Doing a DeletePool() on the pool will free all of the puddles
 and thus all of the allocations done with AllocPooled() in that
 pool.  (No need to FreePooled() each allocation)

**Inputs:**
memSize - the number of bytes to allocate
 poolHeader - a specific private pool header.

**Result:**
A pointer to the memory, or NULL.
 The memory block returned is long word aligned.

**Notes:**
The pool function do not protect an individual pool from
 multiple accesses.  The reason is that in most cases the pools
 will be used by a single task.  If your pool is going to
 be used by more than one task you must Semaphore protect
 the pool from having more than one task trying to allocate
 within the same pool at the same time.  Warning:  Forbid()
 protection *will not work* in the future.  *Do NOT* assume
 that we will be able to make it work in the future.  AllocPooled()
 may well break a Forbid() and as such can only be protected
 by a semaphore.

**See also:** FreePooled(), CreatePool(), DeletePool(), FreeVecPooled(),
 AllocVecPooled()

---

### exec.library/AllocSignal

**allocate a signal bit**

**Synopsis:**
```c
signalNum = AllocSignal(signalNum)

BYTE AllocSignal(BYTE);
```

**Description:**
Allocate a signal bit from the current tasks' pool.  Either a
particular bit, or the next free bit may be allocated.  The signal
associated with the bit will be properly initialized (cleared).  At
least 16 user signals are available per task.  Signals should be
deallocated before the task exits.

If the signal is already in use (or no free signals are available)
a -1 is returned.

Allocated signals are only valid for use with the task that
allocated them.

**Inputs:**
signalNum - the desired signal number {of 0..31} or -1 for no
            preference.

**Result:**
signalNum - the signal bit number allocated {0..31}. If no signals
            are available, this function returns -1.

**Notes:**
Signals may not be allocated or freed from exception handling code.

**See also:** FreeSignal

---

### exec.library/AllocTrap

**allocate a processor trap vector (Obsolete)**

**Synopsis:**
```c
trapNum = AllocTrap(trapNum)

LONG AllocTrap(LONG);
```

**Description:**
Allocate a trap number from the current task's pool.  These trap
numbers are those associated with the 68000 TRAP type instructions.
Either a particular number, or the next free number may be
allocated.

If the trap is already in use (or no free traps are available) a -1
is returned.

This function only affects the currently running task.

Traps are sent to the trap handler pointed at by tc_TrapCode.
Unless changed by user code, this points to a standard trap
handler.  The stack frame of the exception handler will be:

        0(SP) = Exception vector number.  This will be in the
                range of 32 to 47 (corresponding to the
                Trap #1...Trap #15 instructions).
        4(SP) = 68000/68010/68020/68030, etc. exception frame

tc_TrapData is not used.

**Inputs:**
trapNum - the desired trap number {of 0..15} or -1
          for no preference.

**Result:**
trapNum - the trap number allocated {of 0..15}.  If no traps are
          available, this function returns -1.  Instructions of the
          form "Trap #trapNum" will be sent to the task's trap
          handler.

**Notes:**
This function is obsolete from V50 upwards.

**See also:** FreeTrap

---

### exec.library/AllocVec (V36)

**allocate memory and keep track of the size**

**Synopsis:**
```c
memoryBlock = AllocVec(byteSize, attributes)

 void *AllocVec(ULONG, ULONG);
```

**Description:**
This function works identically to AllocMem(), but tracks the size
 of the allocation.

 See the AllocMem() documentation for details.

**Notes:**
This function is obsolete, use AllocVecTagList

**See also:** FreeVec, AllocMem, AllocVecTagList

---

### exec.library/AttemptSemaphore

**try to obtain without blocking**

**Synopsis:**
```c
success = AttemptSemaphore(signalSemaphore)

LONG AttemptSemaphore(struct SignalSemaphore *);
```

**Description:**
This call is similar to ObtainSemaphore(), except that it will not
block if the semaphore could not be locked.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**Result:**
success -- TRUE if the semaphore was locked, false if some
    other task already possessed the semaphore.

**See also:** ObtainSemaphore() ObtainSemaphoreShared(), ReleaseSemaphore(),
exec/semaphores.h

---

### exec.library/AttemptSemaphoreShared (V37)

**try to obtain without blocking**

**Synopsis:**
```c
success = AttemptSemaphoreShared(signalSemaphore)

LONG AttemptSemaphoreShared(struct SignalSemaphore *);
```

**Description:**
This call is similar to ObtainSemaphoreShared(), except that it
will not block if the semaphore could not be locked.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**Result:**
success -- TRUE if the semaphore was granted, false if some
    other task already possessed the semaphore in exclusive mode.

**Notes:**
This call does NOT preserve registers.

Starting in V39 this call will grant the semaphore if the
caller is already the owner of an exclusive lock on the semaphore.
In pre-V39 systems this would not be the case.  If you need this
feature you can do the following workaround:

LONG myAttemptSempahoreShared(struct SignalSemaphore *ss)
{
LONG result;

        /* Try for a shared semaphore */
        if (!(result=AttemptSemaphoreShared(ss))) 
        {
                /* Now try for the exclusive one... */
                result=AttempSemaphore(ss);
        }
        return(result); 
}

**See also:** ObtainSemaphore() ObtainSemaphoreShared(), ReleaseSemaphore(),
exec/semaphores.h

---

### exec.library/AvailMem

**memory available given certain requirements**

**Synopsis:**
```c
size = AvailMem(attributes)

 ULONG AvailMem(ULONG);
```

**Description:**
This function returns the amount of free memory given certain
 attributes.

 To find out what the largest block of a particular type is, add
 MEMF_LARGEST into the requirements argument.  Returning the largest
 block is a slow operation.

 Note that AvailMem(MEMF_TOTAL|MEMF_FAST|MEMF_CHIP) is not the same
 as AvailMem(MEMF_TOTAL). Passing attribute flags will only consider
 memory that is flagged as such. As some memory might not be directly
 accessible (being used as backup storage for virtual memory),
 the only way to get the complete memory size of the system is
 AvailMem(MEMF_TOTAL).

**Inputs:**
requirements - a requirements mask as specified in AllocMem.
                Additionally, these flags modify the behavior of
                AvailMem:
                MEMF_LARGEST - Find the largest block matching
                     the given attribues. Note that this only
                     checks physically addressed memory.
                     Virtually addressed memory is not checked.
                MEMF_TOTAL   - Return the total amount of memory
                     matching the given attributes. Note that
                     MEMF_VIRTUAL might return more than is actually
                     physically installed in the system.
             MEMF_CORE_RESIDENT - Return the amount of memory
                  that is currently available in-core, i.e.
                  memory that is not paged out.

**Result:**
size - total free space remaining (or the largest free block).

**Example:**
```c
/* return size of largest available chip memory chunk */
 AvailMem(MEMF_CHIP|MEMF_LARGEST);

 /* return the total amount of memory in the system */
 AvailMem(MEMF_TOTAL);

 /* return the amount of virtually addressable memory */
 AvailMem(MEMF_TOTAL|MEMF_VIRTUAL);
```

**Notes:**
For V36 Exec, AvailMem(MEMF_LARGEST) does a consistency check on
 the memory list.  Alert AN_MemoryInsane will be pulled if any mismatch
 is noted.

**See also:** exec/memory.h

---

### exec.library/CacheClearE (V37)

**Synopsis:**
```c
CacheClearE(address,length,caches)

void CacheClearE(APTR,ULONG,ULONG);
```

**Description:**
Flush out the contents of the CPU instruction and/or data caches.
If dirty data cache lines are present, push them to memory first.

Motorola CPUs have separate instruction and data caches.  A data
write does not update the instruction cache.  If an instruction is
written to memory or modified, the old instruction may still exist
in the cache.  Before attempting to execute the code, a flush of
the instruction cache is required.

For most systems, the data cache is not updated by Direct Memory
Access (DMA), or if some external factor changes shared memory.

Caches must be cleared after *any* operation that could cause
invalid or stale data.  The most common cases are DMA and modifying
instructions using the processor.

Some examples:
                Self modifying code
                Building Jump tables
                Run-time code patches
                Relocating code for use at different addresses.
                Loading code from disk

**Inputs:**
address - Address to start the operation.  This may be rounded
          due to hardware granularity.
length  - Length of area to be cleared, or $FFFFFFFF to indicate all
          addresses should be cleared.
caches  - Bit flags to indicate what caches to affect.  The current
          supported flags are:
                CACRF_ClearI       Clear instruction cache
                CACRF_ClearD       Flush (write back) data cache
                CACRF_InvalidateD  Discard data cache
          All other bits are reserved for future definition.

**Notes:**
On systems with a copyback mode cache, any dirty data is pushed
to memory as a part of this operation.

Regardless of the length given, the function will determine the most
efficient way to implement the operation.  For some cache systems,
including the 68030, the overhead partially clearing a cache is often
too great.  The entire cache may be cleared.

For all current Amiga models, Chip memory is set with Instruction
caching enabled, data caching disabled.  This prevents coherency
conflicts with the blitter or other custom chip DMA.  Custom chip
registers are marked as non-cacheable by the hardware.

The system takes care of appropriately flushing the caches for normal
operations.  The instruction cache is cleared by all calls that
modify instructions, including LoadSeg(), MakeLibrary() and
SetFunction().

**See also:** exec/execbase.i, CacheControl, CacheClearU

---

### exec.library/CacheClearU (V37)

**Synopsis:**
```c
CacheClearU()

void CacheClearU(void);
```

**Description:**
Flush out the contents of any CPU instruction and data caches.
If dirty data cache lines are present, push them to memory first.

Caches must be cleared after *any* operation that could cause
invalid or stale data.  The most common cases are DMA and modifying
instructions using the processor.  See the CacheClearE() autodoc
for a more complete description.

Some examples of when the cache needs clearing:
                Self modifying code
                Building Jump tables
                Run-time code patches
                Relocating code for use at different addresses.
                Loading code from disk

**Notes:**
If possible, prefer CacheClearE with a tight bound to flush caches.
Flushing all caches will generally result in a performance loss.

**See also:** CacheControl, CacheClearE

---

### exec.library/CacheControl

**Synopsis:**
```c
oldBits = CacheControl(cacheBits,cacheMask)

ULONG CacheControl(ULONG,ULONG);
```

**Description:**
This function provides global control of any instruction or data
caches that may be connected to the system.  All settings are
global -- per task control is not provided.

The action taken by this function will depend on the type of
CPU installed.  This function may be patched to support external
caches, or different cache architectures.  In all cases the function
will attempt to best emulate the provided settings.  Use of this
function may save state specific to the caches involved.

The list of supported settings is provided in the exec/execbase.i
include file.  The bits currently defined map directly to the Motorola
68030 CPU CACR register.  Alternate cache solutions may patch into
the Exec cache functions.  Where possible, bits will be interpreted to
have the same meaning on the installed cache.

**Inputs:**
cacheBits - new values for the bits specified in cacheMask.
            CACRF_EnableI - Enable instruction cache
            CACRF_FreezeI - Freeze instruction cache
            CACRF_EnableD - Enable data cache
            CACRF_FreezeD - Freeze data cache

cacheMask - a mask with ones for all bits to be changed.

**Result:**
oldBits   - the complete prior values for all settings.

**Notes:**
As a side effect, this function clears all caches.

**See also:** exec/execbase.i, CacheClearU, CacheClearE

---

### exec.library/CachePostDMA (V37)

**Synopsis:**
```c
CachePostDMA(vaddress,&length,flags)

CachePostDMA(APTR,ULONG *,ULONG);
```

**Description:**
Take all appropriate steps after Direct Memory Access (DMA).  This
function is primarily intended for writers of DMA device drivers.  The
action will depend on the CPU type installed, caching modes, and the
state of any Memory Management Unit (MMU) activity.

**Inputs:**
address - Same as initially passed to CachePreDMA
length  - Same as initially passed to CachePreDMA
flags   - Values:
                DMA_NoModify - If the area was not modified (and
                thus there is no reason to flush the cache) set
                this bit.

                DMA_ReadFromRAM - Indicates that this DMA is a
                read from RAM to the DMA device (ie - a write
                to the hard drive)  This flag is not required
                but if used must match in both the PreDMA and
                PostDMA calls.  This flag *should* be used to
                help the system provide the best performance.
                This flag is safe in all versions of CachePostDMA()

**Notes:**
Every call to CachePreDMA must be paired with an appropriate
call to CachePostDMA.

Contrary to earlier documentation, the length parameter is 
an ULONG, not a LONG pointer.

**See also:** exec/execbase.i, CachePreDMA, CacheClearU, CacheClearE

---

### exec.library/CachePreDMA (V37)

**Synopsis:**
```c
paddress = CachePreDMA(vaddress,&length,flags)

APTR CachePreDMA(APTR,LONG *,ULONG);
```

**Description:**
Take all appropriate steps before Direct Memory Access (DMA).  This
function is primarily intended for writers of DMA device drivers.  The
action will depend on the CPU type installed, caching modes, and the
state of any Memory Management Unit (MMU) activity.

This function supports advanced cache architectures that have
"copyback" modes.  With copyback, write data may be cached, but not
actually flushed out to memory.  If the CPU has unflushed data at the
time of DMA, data may be lost.

**Inputs:**
address - Base address to start the action.
length  - Pointer to a longword with a length.
flags   - Values:
                DMA_Continue - Indicates this call is to complete
                a prior request that was broken up.

                DMA_ReadFromRAM - Indicates that this DMA is a
                read from RAM to the DMA device (ie - a write
                to the hard drive)  This flag is not required
                but if used must match in both the PreDMA and
                PostDMA calls.  This flag *should* be used to
                help the system provide the best performance.
                This flag is safe in all versions of CachePreDMA()

**Result:**
paddress- Physical address that corresponds to the input virtual
          address. Note that this value is only valid if the returned
          length is not 0...
&length - This length value will be updated to reflect the contiguous
          length of physical memory present at paddress.  This may
          be smaller than the requested length.  To get the mapping
          for the next chunk of memory, call the function again with
          a new address, length, and the DMA_Continue flag.

**Notes:**
Due to processor granularity, areas outside of the address range
may be affected by the cache flushing actions.  Care has been taken
to ensure that no harm is done outside the range, and that activities
on overlapping cache lines won't harm data.

With release 50, CachePreDMA/CachePostDMA is considered obsolete.
Instead, StartDMA/EndDMA should be used.

Due to the virtualized address space of AmigaOS 4, device drivers
doing DMA *MUST* use either CachePreDMA/CachePostDMA or 
StartDMA/EndDMA, *and* be prepared for segmented transfers.
    
Contrary to earlier documentation, the length parameter is 
an ULONG, not a LONG pointer.

**See also:** exec/execbase.i, CachePostDMA, CacheClearU, CacheClearE
StartDMA, EndDMA

---

### exec.library/Cause

**cause a software interrupt**

**Synopsis:**
```c
Cause(interrupt)

      void Cause(struct Interrupt *);
```

**Description:**
This function causes a software interrupt to occur.  If it is
called from user mode (and processor level 0), the software
interrupt will preempt the current task.  This call is often used
by high-level hardware interrupts to defer medium-length processing
down to a lower interrupt level.  Note that a software interrupt is
still a real interrupt, and must obey the same restrictions on what
system function it may call.

Currently only 5 software interrupt priorities are implemented:
-32, -16, 0, +16, and +32.  Priorities in between are truncated,
values outside the -32/+32 range are not allowed.

**Inputs:**
interrupt - pointer to a properly initialized interrupt node

**Bugs:**
Unlike other Interrupts, SoftInts must preserve the value of A6 (on
legacy interrupts)

---

### exec.library/CheckIO

**get the status of an IORequest**

**Synopsis:**
```c
result = CheckIO(iORequest)

struct IORequest *CheckIO(struct IORequest *);
```

**Description:**
This function determines the current state of an I/O request and
returns NULL if the I/O has not yet completed.  This function
effectively hides the internals of the I/O completion mechanism.

CheckIO() will NOT remove the returned IORequest from the reply port.
This is best performed with WaitIO().  If the I/O request has already
completed, WaitIO() will return quickly.  Use of the Remove()
function is dangerous, since other tasks may still be adding things
to your message port; a Disable()/Enable() pair would be required.

This function should NOT be used to busy loop (looping until I/O is
complete).  WaitIO() is provided for that purpose.

**Inputs:**
iORequest - pointer to an I/O request block

**Result:**
result - NULL if I/O is still in progress. Otherwise the result
         is a pointer to the IORequest block.

**Notes:**
CheckIO() will only produce a meaningful result if called on an
    IORequest which has been started with SendIO() or BeginIO(). If
the IORequest was not previously started with either SendIO() or
BeginIO(), CheckIO() will falsely report that I/O is still in
progress.

This means that you cannot rely only on CheckIO() to tell you if
an IORequest is still in progress.  You must also keep track of
whether the IORequest was started first.

**Bugs:**
Previously, CheckIO() used to be documented to return a BOOL
result.  This was incorrect.  It always returned either a NULL
pointer or a pointer to the IORequest in progress.

Older documentation suggested that CheckIO() could hang if the
IORequest had never been used.  This was never the case.  Under
these circumstances CheckIO() could never hang, it would "only"
falsely report that I/O was still in progress.

**See also:** DoIO(), SendIO(), WaitIO(), AbortIO()

---

### exec.library/CloseDevice

**conclude access to a device**

**Synopsis:**
```c
CloseDevice(iORequest)

void CloseDevice(struct IORequest *);
```

**Description:**
This function informs the device that access to a device/unit
previously opened has been concluded.  The device may perform
certain house-cleaning operations.

The user must ensure that all outstanding IORequests have been
returned before closing the device.  The AbortIO function can kill
any stragglers.

After a close, the I/O request structure is free to be reused.
Starting with V36 exec it is safe to CloseDevice() with an
IORequest that is either cleared to zeros, or failed to
open.

**Inputs:**
iORequest - pointer to an I/O request structure

**See also:** OpenDevice

---

### exec.library/CloseLibrary

**conclude access to a library**

**Synopsis:**
```c
CloseLibrary(library)

void CloseLibrary(struct Library *);
```

**Description:**
This function informs the system that access to the given library
has been concluded.  The user must not reference the library or any
function in the library after this close.

Starting with V36, it is safe to pass a NULL instead of
a library pointer.

**Inputs:**
library - pointer to a library node

**Notes:**
Library writers must pass a SegList pointer or NULL back from their
open point.  This value is used by the system, and not visible as
a return code from CloseLibrary.

**See also:** OpenLibrary

---

### exec.library/ColdReboot (V36)

**Synopsis:**
```c
ColdReboot()

void ColdReboot(void);
```

**Description:**
Reboot the machine.  All external memory and periperals will be
RESET, and the machine will start its power up diagnostics.

This function never returns.

**Inputs:**
A chaotic pile of disoriented bits.

**Result:**
An altogether totally integrated living system.

---

### exec.library/CopyMem

**Synopsis:**
```c
void CopyMem(APTR source, APTR dest, uint32 size);
```

**Description:**
CopyMem is a general purpose, fast memory copy function. It can
 deal with arbitrary lengths, with its pointers on arbitrary
 alignments. It attempts to optimize larger copies with more
 efficient copies, it uses byte copies for small moves, parts of
 larger copies, or the entire copy if the source and destination are
 misaligned with respect to each other.

 Arbitrary overlapping copies are not supported.

 The internal implementation of this function will change from
 system to system and may be implemented via hardware DMA.

**Inputs:**
source - a pointer to the source data region
 dest   - a pointer to the destination data region
 size   - the size (in bytes) of the memory area. Zero copies
          zero bytes

**See also:** CopyMemQuick

---

### exec.library/CopyMemQuick

**Synopsis:**
```c
void CopyMemQuick(uint32 *source, uint32 *dest, uint32 size);
```

**Description:**
CopyMemQuick is a highly optimized memory copy function, with
 restrictions on the size and alignment of its arguments. Both the
 source and destination pointers must be longword aligned.  In
 addition, the size must be an integral number of longwords (e.g.
 the size must be evenly divisible by four).

 Arbitrary overlapping copies are not supported.

 The internal implementation of this function will change from
 system to system, and may be implemented via hardware DMA.

 On 440ep/460ex systems the best performance is obtained when
 both source and destination are 32 bytes (256 bits) aligned and
 the size is at least 96 bytes (V53.40 or higher required).

**Inputs:**
source - a pointer to the source data region, long aligned
 dest   - a pointer to the destination data region, long aligned
 size   - the size (in bytes) of the memory area. Zero copies
          zero bytes.

**See also:** CopyMem

---

### exec.library/CreateIORequest (V36)

**create an IORequest structure**

**Synopsis:**
```c
ioReq = CreateIORequest( ioReplyPort, size );

struct IORequest *CreateIORequest(struct MsgPort *, ULONG);
```

**Description:**
Allocates memory for and initializes a new IO request block
of a user-specified number of bytes.  The number of bytes
must be at least as large as a "struct Message".

**Inputs:**
ioReplyPort - Pointer to a port for replies (an initialized message
        port, as created by CreateMsgPort() ).  If NULL, this
        function fails.
size - the size of the IO request to be created.

**Result:**
ioReq - A pointer to the new IORequest block, or NULL.

**See also:** DeleteIORequest, CreateMsgPort(), amiga.lib/CreateExtIO()

---

### exec.library/CreateMsgPort (V36)

**Synopsis:**
```c
CreateMsgPort()

struct MsgPort * CreateMsgPort(void);
```

**Description:**
Allocates and initializes a new message port.  The message list
of the new port will be prepared for use (via NewList).  A signal
bit will be allocated, and the port will be set to signal your
task when a message arrives (PA_SIGNAL).

You *must* use DeleteMsgPort() to delete ports created with
CreateMsgPort()!

**Result:**
MsgPort - A new MsgPort structure ready for use, or NULL if out of
          memory or signals.  If you wish to add this port to the public
          port list, fill in the ln_Name and ln_Pri fields, then call
          AddPort().  Don't forget RemPort()!

**See also:** DeleteMsgPort(), exec/AddPort(), exec/ports.h

---

### exec.library/CreatePool (V39)

**Generate a private memory pool header**

**Synopsis:**
```c
newPool=CreatePool(memFlags,puddleSize,threshSize)

 void *CreatePool(ULONG,ULONG,ULONG);
```

**Description:**
Allocate and prepare a new memory pool header.  Each pool is a
 separate tracking system for memory of a specific type.  Any number
 of pools may exist in the system.

 Pools automatically expand and shrink based on demand.  Fixed sized
 "puddles" are allocated by the pool manager when more total memory
 is needed.  Many small allocations can fit in a single puddle.
 Allocations larger than the threshSize are allocation in their own
 puddles.

 At any time individual allocations may be freed.  Or, the entire
 pool may be removed in a single step.

**Inputs:**
memFlags - a memory flags specifier, as taken by AllocMem.
 puddleSize - the size of Puddles...
 threshSize - the largest allocation that goes into normal puddles
              This *MUST* be less than or equal to puddleSize
              (CreatePool() will fail if it is not)

**Result:**
The address of a new pool header, or NULL for error.

**Notes:**
This function is somewhat obsolete. Use AllocSysObject
 for creating memory pools.

**See also:** DeletePool(), AllocPooled(), FreePooled(), AllocVecPooled(),
 FreeVecPooled(), AllocSysObject(), exec/memory.i

---

### exec.library/DeleteIORequest (V36)

**Synopsis:**
```c
DeleteIORequest( ioReq );

void DeleteIORequest(struct IORequest *);
```

**Description:**
Frees up an IO request as allocated by CreateIORequest().

**Inputs:**
ioReq - A pointer to the IORequest block to be freed, or NULL.
        This function uses the mn_Length field to determine how
        much memory to free.

**See also:** CreateIORequest(), amiga.lib/DeleteExtIO()

---

### exec.library/DeleteMsgPort (V36)

**Synopsis:**
```c
DeleteMsgPort(msgPort)

void DeleteMsgPort(struct MsgPort *);
```

**Description:**
Frees a message port created by CreateMsgPort().  All messages that
may have been attached to this port must have already been
replied to.

**Inputs:**
msgPort - A message port.  NULL for no action.

**See also:** CreateMsgPort(), amiga.lib/DeletePort()

---

### exec.library/DeletePool (V39)

**Drain an entire memory pool**

**Synopsis:**
```c
DeletePool(poolHeader)

 void DeletePool(void *);
```

**Description:**
Frees all memory in all pudles of the specified pool header, then
 deletes the pool header.  Individual free calls are not needed.

**Inputs:**
poolHeader - as returned by CreatePool().

**See also:** CreatePool(), AllocPooled(), FreePooled(), AllocVecPooled(),
 FreeVecPooled()

---

### exec.library/Dellocate

**deallocate a block of memory**

**Synopsis:**
```c
Deallocate(memHeader, memoryBlock, byteSize)

 void Deallocate(struct MemHeader *,APTR,ULONG);
```

**Description:**
This function deallocates memory by returning it to the appropriate
 private free memory pool.  This function can be used to free an
 entire block allocated with the above function.

 If memoryBlock is not on a block boundary (MEM_BLOCKSIZE) then it
 will be rounded down in a manner compatible with Allocate().  Note
 that this will work correctly with all the memory allocation
 functions, but may cause surprises if one is freeing only part of a
 region.  The size of the block will be rounded up, so the freed
 block will fill to an even memory block boundary.

**Inputs:**
memHeader - points to the memory header this block is part of.
 memoryBlock - address of memory block to free.
 byteSize - the size of the block in bytes. If NULL, nothing
            happens.

**Notes:**
Alternatively, Deallocate can be used to free a sub-block of a previously
 allocated block.  Sub-blocks must be an even multiple of the memory
 chunk size (currently 8 bytes).

 This function can even be used to add a new free region to an
 existing MemHeader, however the extent pointers in the MemHeader
 will no longer be valid.

 However, this might not be supported in future versions of the
 memory system, so use of this feature is discouraged, and only
 present for backwards compatibility.

**See also:** Allocate, exec/memory.h

---

### exec.library/Disable

**disable interrupt processing.**

**Synopsis:**
```c
Disable();

void Disable(void);
```

**Description:**
Prevents interrupts from being handled by the system, until a
matching Enable() is executed.  Disable() implies Forbid().

DO NOT USE THIS CALL WITHOUT GOOD JUSTIFICATION.  THIS CALL IS
VERY DANGEROUS!

**Result:**
All interrupt processing is deferred until the task executing makes
a call to Enable() or is placed in a wait state.  Normal task
rescheduling does not occur while interrupts are disabled.  In order
to restore normal interrupt processing, the programmer must execute
exactly one call to Enable() for every call to Disable().

IMPORTANT REMINDER:

It is important to remember that there is a danger in using
disabled sections.  Disabling interrupts for more than ~250
microseconds will prevent vital system functions (especially serial
I/0) from operating in a normal fashion.

Think twice before using Disable(), then think once more.
After all that, think again.  With enough thought, the need
for a Disable() can often be eliminated.  For the user of many
device drivers, a write to disable *only* the particular interrupt
of interest can replace a Disable().  For example:
                MOVE.W  #INTF_PORTS,_intena
Do not use a macro for Disable(), insist on the real thing.

This call may be made from interrupts, it will have the effect
of locking out all higher-level interrupts (lower-level interrupts
are automatically disabled by the CPU).

 Note: In the event of a task entering a Wait() after disabling
       interrupts, the system "breaks" the disabled state and runs
       normally until the task which called Disable() is rescheduled.

**Notes:**
This call is guaranteed to preserve all registers.

**See also:** Forbid, Permit, Enable

---

### exec.library/DoIO

**perform an I/O command and wait for completion**

**Synopsis:**
```c
error = DoIO(iORequest)

BYTE DoIO(struct IORequest *);
```

**Description:**
This function requests a device driver to perform the I/O command
specified in the I/O request.  This function will always wait until
the I/O request is fully complete.

DoIO() handles all the details, including Quick I/O, waiting for
the request, and removing the reply message, etc..

**Inputs:**
iORequest - pointer to an IORequest initialized by OpenDevice()

**Result:**
error - a sign-extended copy of the io_Error field of the
        IORequest.  Most device commands require that the error
        return be checked.

**Notes:**
This function first tries to complete the IO via the "Quick I/O"
mechanism.  The IORequest->io_Flags field is always set to
IOF_QUICK (0x01) before the internal device call.

Some device drivers require that certain bits in io_Flags are set
for proper operations and will not work correctly if an IORequest
is used with DoIO() because it sets io_Flags to IOF_QUICK before the
request is sent.  The audio.device is such a kind of device driver.
For such device drivers BeginIO() and WaitIO() must be used in place
of DoIO().

The IORequest->io_Message.mn_Node.ln_Type field is used internally
to flag I/O completion.  Active requests have type NT_MESSAGE.
IORequests that have been completed, and thus replied, have
type NT_REPLYMSG.

It is illegal to start I/O using a still active IORequest, or a request
with type NT_REPLYMSG.

You must not call DoIO() on an IORequest that has never been
successfully used with OpenDevice() and that is not a duplicate of
an IORequest which was successfully used with OpenDevice(). If you
use it on an IORequest that was just created with CreateIORequest()
or which was just used with the CloseDevice() function, you will
either cause your task to hang, or you may crash the operating
system.

**See also:** SendIO(), CheckIO(), WaitIO(), AbortIO(), BeginIO()

---

### exec.library/Enable

**permit system interrupts to resume.**

**Synopsis:**
```c
Enable();

void Enable(void);
```

**Description:**
Allow system interrupts to again occur normally, after a matching
Disable() has been executed.

**Result:**
Interrupt processing is restored to normal operation. The
programmer must execute exactly one call to Enable() for every call
to Disable().

**Notes:**
This call is guaranteed to preserve all registers.

**See also:** Forbid, Permit, Disable

---

### exec.library/Enqueue

**insert or append node to a system queue**

**Synopsis:**
```c
Enqueue(list, node)

 void Enqueue(struct List *, struct Node *);
```

**Description:**
Insert or append a node into a system queue.  The insert is
 performed based on the node priority -- it will keep the list
 properly sorted.  New nodes will be inserted in front of the first
 node with a lower priority.   Hence a FIFO queue for nodes of equal
 priority

**Inputs:**
list - a pointer to the system queue header
 node - the node to enqueue.  This must be a full featured node
        with type, priority and name fields.

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddHead, AddTail, Insert, Remove, RemHead, RemTail

---

### exec.library/FindName

**find a system list node with a given name**

**Synopsis:**
```c
node = FindName(start, name)

 struct Node *FindName(struct List *, STRPTR);
```

**Description:**
Traverse a system list until a node with the given name is found.
 To find multiple occurrences of a string, this function may be
 called with a node starting point.

 No arbitration is done for access to the list!  If multiple tasks
 access the same list, an arbitration mechanism such as
 SignalSemaphores must be used.

**Inputs:**
start - a list header or a list node to start the search
         (if node, this one is skipped)
 name - a pointer to a name string terminated with NULL

**Result:**
node - a pointer to the node with the same name else
     zero to indicate that the string was not found.

---

### exec.library/FindPort

**find a given system message port**

**Synopsis:**
```c
port = FindPort(name)

struct MsgPort *FindPort(STRPTR);
```

**Description:**
This function will search the system message port list for a port
with the given name.  The first port matching this name will be
returned.  No arbitration of the port list is done.  This function
MUST be protected with A Forbid()/Permit() pair!

**Inputs:**
name - name of the port to find

**Result:**
port - a pointer to the message port, or zero if
       not found.

**Example:**
```c
/* Pre V50 */
#include <exec/types.h>
struct MsgPort *FindPort();

ULONG SafePutToPort(message, portname)
struct Message *message;
STRPTR          portname;
{
struct MsgPort *port;

    Forbid();
        port = FindPort(portname);
        if (port)
            PutMsg(port,message);
    Permit();
    return((ULONG)port); /* If zero, the port has gone away */
}
```

---

### exec.library/FindResident

**Synopsis:**
```c
resident = FindResident(name)

struct Resident *FindResident(STRPTR);
```

**Description:**
Search the system resident tag list for a resident tag ("ROMTag") with
the given name.  If found return a pointer to the resident tag
structure, else return zero.

Resident modules are used by the system to pull all its parts
together at startup.  Resident tags are also found in disk based
devices and libraries.

**Inputs:**
name - pointer to name string

**Result:**
resident - pointer to the resident tag structure or
        zero if none found.

**See also:** exec/resident.h, InitResident

---

### exec.library/FindSemaphore

**find a given system signal semaphore**

**Synopsis:**
```c
signalSemaphore = FindSemaphore(name)

struct SignalSemaphore *FindSemaphore(STRPTR);
```

**Description:**
This function will search the system signal semaphore list for a
semaphore with the given name.  The first semaphore matching this
name will be returned.

This function does not arbitrate for access to the semaphore list,
surround the call with a Forbid()/Permit() pair.

**Inputs:**
name - name of the semaphore to find

**Result:**
semaphore - a pointer to the signal semaphore, or zero if not
            found.

---

### exec.library/FindTask

**find a task with the given name or find oneself**

**Synopsis:**
```c
task = FindTask(name)

struct Task *FindTask(STRPTR);
```

**Description:**
This function will check all task queues for a task with the given
name, and return a pointer to its task control block.  If a NULL
name pointer is given a pointer to the current task will be
returned.

Finding oneself with a NULL for the name is very quick.  Finding a
task by name is very system expensive, and will disable interrupts
for a long time.  Since a task may remove itself at any time,
a Forbid()/Permit() pair may be needed to ensure the pointer
returned by FindTask() is still valid when used.

**Inputs:**
name - pointer to a name string

**Result:**
task - pointer to the task (or Process)

---

### exec.library/Forbid

**forbid task rescheduling.**

**Synopsis:**
```c
Forbid()

 void Forbid(void);
```

**Description:**
Prevents other tasks from being scheduled to run by the dispatcher,
 until a matching Permit() is executed, or this task is scheduled to
 Wait().  Interrupts are NOT disabled.

 DO NOT USE THIS CALL WITHOUT GOOD JUSTIFICATION.  THIS CALL IS
 DANGEROUS!

**Result:**
The current task will not be rescheduled as long as it is ready to
 run.  In the event that the current task enters a wait state, other
 tasks may be scheduled.  Upon return from the wait state, the original
 task will continue to run without disturbing the Forbid().

 Calls to Forbid() nest. In order to restore normal task rescheduling,
 the programmer must execute exactly one call to Permit() for every
 call to Forbid().

**Notes:**
This call is guaranteed to preserve all registers.

**See also:** Permit, Disable, ObtainSemaphore, ObtainSemaphoreShared

---

### exec.library/FreeEntry

**free many regions of memory.**

**Synopsis:**
```c
FreeEntry(memList)

 void FreeEntry(struct MemList *);
```

**Description:**
This function takes a memList structure (as returned by AllocEntry)
 and frees all the entries.

**Inputs:**
memList -- pointer to structure filled in with MemEntry
            structures

**Example:**
```c
Free all the memory added to the current tasks memlist.

 VOID freeTaskMemEntries(void)
 {
    struct Task *me = IExec->FindTask(0);
    APTR memlist;
     
    while( (memlist = IExec->RemHead( &(task->tc_MemEntry) )))
    {
       IExec->FreeEntry(memlist);
    }
 }
```

**See also:** AllocTaskMemEntry(), exec/memory.h,  AllocEntry()[obsolete]

---

### exec.library/FreeMem

**deallocate memory**

**Synopsis:**
```c
FreeMem(memoryBlock, byteSize)

 void FreeMem(void *,ULONG);
```

**Description:**
Free a region of memory, returning it to the system pool from which
 it came.  As of V50, freeing partial blocks back into the system pool
 is prohibited.

**Inputs:**
memoryBlock - pointer to the memory block to free
 byteSize - the size of the desired block in bytes.  (The operating
         system will automatically round this number to a multiple of
         the system memory chunk size)

**Notes:**
If a block of memory is freed twice, the system will Guru. The
 Alert is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
 you will probably see AN_MemCorrupt $01000005.  Future versions may
 add more sanity checks to the memory lists.

**See also:** AllocMem

---

### exec.library/FreePooled (V39)

**Free pooled memory**

**Synopsis:**
```c
FreePooled(poolHeader,memory,memSize)

 void FreePooled(void *,void *,ULONG);
```

**Description:**
Deallocates memory allocated by AllocPooled().  The size of the
 allocation *MUST* match the size given to AllocPooled().
 The reason the pool functions do not track individual allocation
 sizes is because many of the uses of pools have small allocation
 sizes and the tracking of the size would be a large overhead.

 Only memory allocated by AllocPooled() may be freed with this
 function!

 Doing a DeletePool() on the pool will free all of the puddles
 and thus all of the allocations done with AllocPooled() in that
 pool.  (No need to FreePooled() each allocation)

**Inputs:**
memory - pointer to memory allocated by AllocPooled.
 poolHeader - a specific private pool header.

**Notes:**
The pool function do not protect an individual pool from
 multiple accesses.  The reason is that in most cases the pools
 will be used by a single task.  If your pool is going to
 be used by more than one task you must Semaphore protect
 the pool from having more than one task trying to allocate
 within the same pool at the same time.  Warning:  Forbid()
 protection *will not work* in the future.  *Do NOT* assume
 that we will be able to make it work in the future.  FreePooled()
 may well break a Forbid() and as such can only be protected
 by a semaphore.

**See also:** AllocPooled(), CreatePool(), DeletePool(), AllocVecPooled(),
 FreeVecPooled()

---

### exec.library/FreeSignal

**free a signal bit**

**Synopsis:**
```c
FreeSignal(signalNum)
 
void FreeSignal(BYTE);
```

**Description:**
This function frees a previously allocated signal bit for reuse.
This call must be performed while running in the same task in which
the signal was allocated.

**Inputs:**
signalNum - the signal number to free {0..31}.

**Notes:**
Starting with V37, an attempt to free signal -1 is harmless.

---

### exec.library/FreeTrap

**free a processor trap (Obsolete)**

**Synopsis:**
```c
FreeTrap(trapNum)

void FreeTrap(ULONG);
```

**Description:**
This function frees a previously allocated trap number for reuse.
This call must be performed while running in the same task in which
the trap was allocated.

**Inputs:**
trapNum - the trap number to free {of 0..15}

**Notes:**
This function is obsolete from V50 upwards

---

### exec.library/FreeVec (V36)

**return AllocVec() memory to the system**

**Synopsis:**
```c
FreeVec(memoryBlock)

 void FreeVec(void *);
```

**Description:**
Free an allocation made by the AllocVec() call.  The memory will
 be returned to the system pool from which it came.

**Inputs:**
memoryBlock - pointer to the memory block to free, or NULL.

**Notes:**
If a block of memory is freed twice, the system will Guru. The
 Alert is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
 you will probably see AN_MemCorrupt $01000005.  Future versions may
 add more sanity checks to the memory lists.

**See also:** AllocVec

---

### exec.library/GetCC

**get condition codes in a 68010 compatible way. (Obsolete)**

**Synopsis:**
```c
conditions = GetCC()

UWORD GetCC(void);
```

**Description:**
The 68000 processor has a "MOVE SR,<ea>" instruction which gets a
copy of the processor condition codes.

On the 68010,20 and 30 CPUs, "MOVE SR,<ea>" is privileged.  User
code will trap if it is attempted.  These processors need to use
the "MOVE CCR,<ea>" instruction instead.

This function provides a means of obtaining the CPU condition codes
in a manner that will make upgrades transparent.  This function is
VERY short and quick.

**Result:**
conditions - the 680XX condition codes

**Notes:**
This call is guaranteed to preserve all registers.  This function
may be implemented as code right in the jump table.

From V50 on, this function is considered obsolete in native programs.
It will always return 0, and alert.

---

### exec.library/GetMsg

**get next message from a message port**

**Synopsis:**
```c
message = GetMsg(port)

struct Message *GetMsg(struct MsgPort *);
```

**Description:**
This function receives a message from a given message port. It
provides a fast, non-copying message receiving mechanism. The
received message is removed from the message port.

This function will not wait.  If a message is not present this
function will return zero.  If a program must wait for a message,
it can Wait() on the signal specified for the port or use the
WaitPort() function.  There can only be one task waiting for any
given port.

Getting a message does not imply to the sender that the message is
free to be reused by the sender.  When the receiver is finished
with the message, it may ReplyMsg() it back to the sender.

Getting a signal does NOT always imply a message is ready.  More
than one message may arrive per signal, and signals may show up
without messages.  Typically you must loop to GetMsg() until it
returns zero, then Wait() or WaitPort().

**Inputs:**
port - a pointer to the receiver message port

**Result:**
message - a pointer to the first message available.  If
          there are no messages, return zero.
          Callers must be prepared for zero at any time.

**See also:** PutMsg, ReplyMsg, WaitPort, Wait, exec/ports.h

---

### exec.library/IceColdReboot

**Reboot to power-on state**

**Synopsis:**
```c
void IceColdReboot(void);
```

**Description:**
Try to reboot the machine to a state the machine would have at power-on.
Reset callbacks will also be called before reboot.

**Notes:**
This function will never return. If it does, contact your dealer.

**See also:** ColdReboot, AddResetCallback

---

### exec.library/InitCode

**Synopsis:**
```c
InitCode(startClass, version)

void InitCode(ULONG,ULONG);
```

**Description:**
(This function may be ignored by application programmers)

Call InitResident() for all resident modules in the ResModules array
with the given startClass and with versions equal or greater than
that specified.  The segList parameter is passed as zero.

Resident modules are used by the system to pull all its parts
together at startup.  Modules are initialized in a prioritized order.

Modules that do not have a startclass should be of priority -120.
RTF_AFTERDOS modules should start at -100 (working down).

**Inputs:**
startClass - the class of code to be initialized:
        BITDEF RT,COLDSTART,0
        BITDEF RT,SINGLETASK,1  ;ExecBase->ThisTask==0 (V36 only)
        BITDEF RT,AFTERDOS,2    ;(V36 only)
version - a major version number

**See also:** ResidentTag (RT) structure definition (resident.h)

---

### exec.library/InitResident

**Synopsis:**
```c
object = InitResident(resident, segList)

APTR InitResident(struct Resident *,ULONG);
```

**Description:**
Initialize a ROMTag.  ROMTags are used to link system modules
together.  Each disk based device or library must contain a
ROMTag structure in the first code hunk.

Once the validity of the ROMTag is verified, the RT_INIT pointer
is jumped to depending on the flag RTF_NATIVE.
For 68k (RTF_NATIVE cleared) resident modules, the RT_INIT pointer
is emulated with the following registers:
        D0 = 0
        A0 = segList
        A6 = ExecBase

If RTF_NATIVE is set, the call is a standard ABI-compliant call with
the following prototype:
        APTR RT_INIT(void *Base, ULONG segList, struct Library *ExecBase);

Note that Base is always 0 now.

**Inputs:**
resident - Pointer to a ROMTag
segList  - SegList of the loaded object, if loaded from disk.
           Libraries & Devices will cache this value for later
           return at close or expunge time.  Pass NULL for ROM
           modules.

**Result:**
object  - Return value from the init code, usually the library
          or device base.  NULL for failure.

   AUTOINIT FEATURE
An automatic method of library/device base and vector table
initialization is also provided by InitResident(). Depending on the
RTF_NATIVE flag, the new style or old style initialization method is
used.

   AUTOINIT FEATURE (Old style - 68K)
The initial code hunk of the library or device should contain
"MOVEQ #-1,d0; RTS;".
Following that must be an initialized Resident structure with
RTF_AUTOINIT set in rt_Flags, and an rt_Init pointer which points
to four longwords.  These four longwords will be used in a call
to MakeLibrary();

    - The size of your library/device base structure including initial
      Library or Device structure.

    - A pointer to a longword table of standard, then library
      specific function offsets, terminated with -1L.
      (short format offsets are also acceptable)

    - Pointer to data table in exec/InitStruct format for
      initialization of Library or Device structure.

    - Pointer to library initialization function, or NULL.
        Calling sequence:
                D0 = library base
                A0 = segList
                A6 = ExecBase
      This function must return in D0 the library/device base to be
      linked into the library/device list.  If the initialization
      function fails, the device memory must be manually deallocated,
      then NULL returned in D0.

   AUTOINIT FEATURE (New style)
The new style initialisation is used when the RTF_AUTOINIT flag is
combined with RTF_NATIVE. In this case, the rt_Init pointer points to
a CreateLibrary-compatible tag list. The library is created by calling
CreateLibrary with the rt_Init pointer.

If the CLT_InitFunc tag is specified and the initialization function
returns a non-NULL pointer, InitResident will add the
library/device/resource to the respective system list. Which list the
object will be appended to will be decided upon the rt_Type field in
the Resident structure.

**See also:** exec/resident.h, FindResident, CreateLibrary

---

### exec.library/InitSemaphore

**initialize a signal semaphore**

**Synopsis:**
```c
InitSemaphore(signalSemaphore)

void InitSemaphore(struct SignalSemaphore *);
```

**Description:**
This function initializes a signal semaphore and prepares it for
use.  It does not allocate anything, but does initialize list
pointers and the semaphore counters.

Semaphores are often used to protect critical data structures
or hardware that can only be accessed by one task at a time.
After initialization, the address of the SignalSemaphore may be
made available to any number of tasks.  Typically a task will
try to ObtainSemaphore(), passing this address in.  If no other
task owns the semaphore, then the call will lock and return
quickly.  If more tasks try to ObtainSemaphore(), they will
be put to sleep.  When the owner of the semaphore releases
it, the next waiter in turn will be woken up.

Semaphores are often preferable to the old-style Forbid()/Permit()
type arbitration.  With Forbid()/Permit() *all* other tasks are
prevented from running.  With semaphores, only those tasks that
need access to whatever the semaphore protects are subject
to waiting.

**Inputs:**
signalSemaphore -- a signal semaphore structure (with all fields
                   set to zero before the call)

**See also:** ObtainSemaphore, ObtainSemaphoreShared, AttemptSemaphore,
ReleaseSemaphore, Procure, Vacate, exec/semaphores.h

---

### exec.library/InitStruct

**Synopsis:**
```c
InitStruct(initTable, memory, size);

void InitStruct(APTR, APTR, ULONG);
```

**Description:**
Clear a memory area, then set up default values according to
the data and offset values in the initTable.  Typically only assembly
programs take advantage of this function, and only with the macros
defined in "exec/initializers.i".

The initialization table has byte commands to

     |a    ||byte|      |given||byte|         |once         |
load |count||word| into |next ||rptr| offset, |repetitively |
            |long|

Not all combinations are supported.  The offset, when specified, is
relative to the memory pointer provided (Memory), and is initially
zero.  The initialization data (InitTable) contains byte commands
whose 8 bits are interpreted as follows:

ddssnnnn
    dd  the destination type (and size):
        00  no offset, use next destination, nnnn is count
        01  no offset, use next destination, nnnn is repeat
        10  destination offset is in the next byte, nnnn is count
        11  destination offset is in the next 24-bits, nnnn is count
    ss  the size and location of the source:
        00  long, from the next two aligned words
        01  word, from the next aligned word
        10  byte, from the next byte
        11  ERROR - will cause an ALERT (see below)
  nnnn  the count or repeat:
     count  the (number+1) of source items to copy
    repeat  the source is copied (number+1) times.

initTable commands are always read from the next even byte. Given
destination offsets are always relative to the memory pointer (A2).

The command %00000000 ends the InitTable stream: use %00010001 if you
really want to copy one longword without a new offset.

24 bit APTR not supported for 68020 compatibility -- use long.

**Inputs:**
initTable - the beginning of the commands and data to init
        Memory with.  Must be on an even boundary unless only
        byte initialization is done.  End table with "dc.b 0"
        or "dc.w 0".
memory - the beginning of the memory to initialize.  Must be
        on an even boundary if size is specified.
size - the size of memory, which is used to clear it before
        initializing it via the initTable.  If Size is zero,
        memory is not cleared before initializing.

        size must be an even number.

**See also:** exec/initializers.i

---

### exec.library/Insert

**insert a node into a list**

**Synopsis:**
```c
Insert(list, node, listNode)

 void Insert(struct List *, struct Node *, struct Node *);
```

**Description:**
Insert a node into a doubly linked list AFTER a given node
 position.  Insertion at the head of a list is possible by passing a
 zero value for listNode, though the AddHead function is slightly
 faster for that special case.

**Inputs:**
list - a pointer to the target list header
 node - the node to insert
 listNode - the node after which to insert

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddHead, AddTail, Enqueue, RemHead, Remove, RemTail

---

### exec.library/MakeFunctions

**construct a function jump table**

**Synopsis:**
```c
tableSize = MakeFunctions(target, functionArray, funcDispBase)

ULONG MakeFunctions(APTR,APTR,APTR);
```

**Description:**
A low level function used by MakeLibrary to build jump tables of
the type used by libraries, devices and resources.  It allows the
table to be built anywhere in memory, and can be used both for
initialization and replacement. This function also supports function
pointer compression by expanding relative displacements into absolute
pointers.

The processor instruction cache is cleared after the table building.

**Inputs:**
destination - the target address for the high memory end of the
        function jump table.  Typically this will be the library
        base pointer.

functionArray - pointer to an array of function pointers or
        function displacements.  If funcDispBase is zero, the array
        is assumed to contain absolute pointers to functions. If
        funcDispBase is not zero, then the array is assumed to
        contain word displacements to functions.  In both cases,
        the array is terminated by a -1 (of the same size as the
        actual entry.

funcDispBase - pointer to the base about which all function
        displacements are relative.  If zero, then the function
        array contains absolute pointers.

**Result:**
tableSize - size of the new table in bytes (for LIB_NEGSIZE).

**See also:** exec/MakeLibrary

---

### exec.library/NewStackRun

**Run a function with its own stack frame.    (V52.6)**

**Synopsis:**
```c
int32 errorcode = NewStackRun(APTR initPC, const struct TagItem *)

int32 errorcode = NewStackRunTags(APTR initPC, uint32, ...)
```

**Description:**
This function allocates a new stack frame for the function and runs it
under the same task/process context as the caller.

The initial size of the stackframe, any required function parameters 
and other options are specified via tags.

This routine is called by various kickstart modules (including DOS) to
launch all processes or tasks with their own stack frame.
The new stack frame will be deallocated when the function returns.

**Inputs:**
initPC - (int32 (*)()) -- Address of the function to run.
    The function pointer may point to 68K or PPC executable code.
    Type determination is automatic.

tags - a pointer to a TagItem array; see below.

The following tags are defined:

NSR_StackSize (uint32) -- The chosen stack size (in bytes) that the
    function should allocate to begin running.  Incase of a memory
    shortage, this value may be adjusted down to fit the available
    memory, unless the tag; NSR_MinStackSize is specified to limit
    the amount of adjustment.  (Default; 8K bytes)

    NB: If you call this function with an NSR_StackSize of 0, a new 
    stack frame will NOT be allocated for the function call, instead,
    it will run using the stack frame of the calling process/task.

NSR_MinStackSize (uint32) -- The absolute minimum stack size allowed
    to run the function.  If there is insufficient memory available
    to comply with NSR_StackSize, this specification will be used to
    determine how far down it is permitted to adjust the request.
    (Default; system page size)
    The function will fail if this lower limit cannot be supplied, 
    the errorcode of -1 will be returned and a secondary error code
    (processes only) of; ERROR_NO_FREE_STORE will be returned by
    calling the dos/IoErr() function.  

NSR_LockStack (BOOL) -- If TRUE, the stack will be locked in memory
    thus preventing it from being swapped out.
    (Default; FALSE, allow stack to be swapped out) 

Arguments - For calling a PPC native function.
    NSR_Arg1 (int32) -- The first parameter to a native function.
    NSR_Arg2 (int32) -- The second parameter.
    NSR_Arg3 (int32) -- The third parameter.
    NSR_Arg4 (int32) -- The fourth parameter.
    NSR_Arg5 (int32) -- The fifth parameter.
    NSR_Arg6 (int32) -- The sixth parameter.

Arguments - For calling a legacy 68K function, the exec/Emulate()
    routine is called internally, therefore use the relevant tags
    for that function here, when handling 68K function calls.  
    (see; exec/emulation.h)

    ET_RegisterD0 ... ET_RegisterD7
    ET_RegisterA0 ... ET_RegisterA6
    ...

NB: Both 68K and PPC native type arguments may be specified together,
    if the type of function is unknown when invoking this routine. 
    Only the relevant tags will be used after type determination.

**Result:**
errorcode - The ERROR value returned by the function that was run.
A value of -1 can be returned by this routine on failure.
    The function being run should always return positive error codes.
    Negative error codes are reserved by the operating system.

    Returning 0 indicates "no error" therefore it was successful.

**Notes:**


**See also:** exec/Emulate(), <exec/emulation.h>

---

### exec.library/ObtainQuickVector (V39)

**Synopsis:**
```c
vector = ObtainQuickVector(interruptCode)

ULONG ObtainQuickVector(APTR);
```

**Description:**
This function will install the code pointer into the quick interrupt
vector it allocates and returns to you the interrupt vector that
your Quick Interrupt system needs to use.

This function may also return 0 if no vectors are available.  Your
hardware should be able to then fall back to using the shared
interrupt server chain should this happen.

The interrupt code is a direct connect to the physical interrupt.
This means that it is the responsibility of your code to do all
of the context saving/restoring required by interrupt code.

Also, due to the performance of the interrupt controller, you may
need to also watch for "false" interrupts.  These are interrupts
that come in just after a DISABLE.  The reason this happens is
because the interrupt may have been posted before the DISABLE
hardware access is completed.  For example:

myInt:          move.l  d0,-(sp)        ; Save d0...
                move.w  _intenar,d0     ; Get interrupt enable state
                btst.l  #INTB_INTEN,d0  ; Check if pending disable
                bne.s   realInt         ; If not, do real one...
exitInt:        move.l  (sp)+,d0        ; Restore d0
                rte                     ; Return from int...
;
realInt:        ; Now do your int code...  d0 is already saved
                ; ALL other registers need to be saved if needed
                ; This includes a0/a1/d0/d1 as this is an interrupt
                ; and not a function call...
                ;
                bra.s   exitInt         ; Exit interrupt...

If your interrupt will not play with system (OS) structures and your
own structures are safe to play with you do not need to check for
the disable.  It is only needed for when the system is in disable but
that "one last interrupt" still got through.

**Inputs:**
A pointer to your interrupt code.  This code is not an EXEC interrupt
but is dirrectly connected to the hardware interrupt.  Thus, the
interrupt code must not modify any registers and must return via
an RTE.

**Result:**
The 8-bit vector number used for Zorro-III Quick Interrupts
If it returns 0, no quick interrupt was allocatable.  The device
should at this point switch to using the shared interrupt server
method.

**Notes:**
This function was not implemented fully until V39.  Due to a mis-cue
it is not safe to call in V37 EXEC.  (Sorry)

This function will always return 0 from V50 upward.

---

### exec.library/ObtainSemaphore

**gain exclusive access to a semaphore**

**Synopsis:**
```c
ObtainSemaphore(signalSemaphore)

void ObtainSemaphore(struct SignalSemaphore *);
```

**Description:**
Signal semaphores are used to gain exclusive access to an object.
ObtainSemaphore is the call used to gain this access.  If another
user currently has the semaphore locked the call will block until
the object is available.

If the current task already has locked the semaphore and attempts to
lock it again the call will still succeed.  A "nesting count" is
incremented each time the current owning task of the semaphore calls
ObtainSemaphore().  This counter is decremented each time
ReleaseSemaphore() is called.  When the counter returns to zero the
semaphore is actually released, and the next waiting task is called.

A queue of waiting tasks is maintained on the stacks of the waiting
tasks.  Each will be called in turn as soon as the current task
releases the semaphore.

Signal Semaphores are different than Procure()/Vacate() semaphores.
The former requires less CPU time, especially if the semaphore is
not currently locked.  They require very little set up and user
thought.  The latter flavor of semaphore make no assumptions about
how they are used -- they are completely general.  Unfortunately
they are not as efficient as signal semaphores, and require the
locker to have done some setup before doing the call.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**Notes:**
This function preserves all registers (see BUGS).

**Bugs:**
Until V37, this function could destroy A0.

**See also:** ObtainSemaphoreShared(), InitSemaphore(), ReleaseSemaphore(),
AttemptSemaphore(), ObtainSemaphoreList(), Procure(), Vacate()

---

### exec.library/ObtainSemaphoreList

**get a list of semaphores.**

**Synopsis:**
```c
ObtainSemaphoreList(list)

void ObtainSemaphoreList(struct List *);
```

**Description:**
Signal semaphores may be linked together into a list. This function
takes a list of these semaphores and attempts to lock all of them at
once. This call is preferable to applying ObtainSemaphore() to each
element in the list because it attempts to lock all the elements
simultaneously, and won't deadlock if someone is attempting to lock
in some other order.

This function assumes that only one task at a time will attempt to
lock the entire list of semaphores.  In other words, there needs to
be a higher level lock (perhaps another signal semaphore...) that is
used before someone attempts to lock the semaphore list via
ObtainSemaphoreList().

Note that deadlocks may result if this call is used AND someone
attempts to use ObtainSemaphore() to lock more than one semaphore on
the list.  If you wish to lock more than semaphore (but not all of
them) then you should obtain the higher level lock (see above)

**Inputs:**
list -- a list of signal semaphores

**See also:** ObtainSemaphoreShared(), InitSemaphore(), ReleaseSemaphore(),
AttemptSemaphore(), ObtainSemaphoreShared(), Procure(), Vacate()

---

### exec.library/ObtainSemaphoreShared (V36)

**gain shared access to a semaphore**

**Synopsis:**
```c
ObtainSemaphoreShared(signalSemaphore)
 
void ObtainSemaphoreShared(struct SignalSemaphore *);
```

**Description:**
A lock on a signal semaphore may either be exclusive, or shared.
Exclusive locks are granted by the ObtainSemaphore() and
AttemptSemaphore() functions.  Shared locks are granted by
ObtainSemaphoreShared().  Calls may be nested.

Any number of tasks may simultaneously hold a shared lock on a
semaphore.  Only one task may hold an exclusive lock.  A typical
application is a list that is often read, but only occasionally
written to.

Any exlusive locker will be held off until all shared lockers
release the semaphore.  Likewise, if an exlusive lock is held,
all potential shared lockers will block until the exclusive lock
is released.  All shared lockers are restarted at the same time.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**Example:**
```c
IExec->ObtainSemaphoreShared(ss);
        /* read data */
        IExec->ReleaseSemaphore(ss);

        IExec->ObtainSemaphore(ss);
        /* modify data */
        IExec->ReleaseSemaphore(ss);
```

**Notes:**
This call is guaranteed to preserve all registers, starting with
V37 exec.

**See also:** ObtainSemaphore(), InitSemaphore(), ReleaseSemaphore(),
AttemptSemaphore(), ObtainSemaphoreList(), Procure(), Vacate()

---

### exec.library/OpenDevice

**gain access to a device**

**Synopsis:**
```c
error = OpenDevice(devName, unitNumber, iORequest, flags)

BYTE OpenDevice(STRPTR,ULONG,struct IORequest *,ULONG);
```

**Description:**
This function opens the named device/unit and initializes the given
I/O request block.  Specific documentation on opening procedures
may come with certain devices.

The device may exist in memory, or on disk; this is transparent to
the OpenDevice caller.

A full path name for the device name is legitimate.  For example
"test:devs/fred.device".  This allows the use of custom devices
without requiring the user to copy the device into the system's
DEVS: directory.

**Inputs:**
devName - requested device name

unitNumber - the unit number to open on that device.  The format of
        the unit number is device specific.  If the device does
        not have separate units, send a zero.

iORequest - the I/O request block to be returned with
        appropriate fields initialized.

flags - additional driver specific information.  This is sometimes
        used to request opening a device with exclusive access.

**Result:**
error - Returns a sign-extended copy of the io_Error field
        of the IORequest.  Zero if successful, else an error code
        is returned.

**Notes:**
All calls to OpenDevice should have matching calls to CloseDevice!

Devices on disk cannot be opened until after DOS has been
started.

As of V36 tasks can safely call OpenDevice, though DOS may open
system requesters (e.g., asking the user to insert the Workbench
disk if DEVS: is not online).  You must call this function from a
DOS Process if you want to turn off DOS requesters.

When the I/O request block was not created with a system function
like AllocSysObject, CreateIORequest or CreateExtIO, you should
initialize the io_Message.mn_Length field to the size of the
I/O request block which will allow some devices to verify the size.
New devices should always check the mn_Length field and refuse to
open when its smaller than the minimum required I/O request block
size.

When opening an unknown device, e.g. to send it an
NSCMD_DEVICEQUERY command, keep in mind that some devices need
a larger I/O request block size than a struct IORequest or a
struct IOStdReq, that they will initialize the I/O request block,
and that they dont check the io_Message.mn_Length field. To avoid
accessing unallocated memory in such situations, use an I/O request
block size of at least sizeof(struct IOStdRequest)+128 as suggested
in the NewStyleDevice documentation.

**Bugs:**
AmigaDOS file names are not case sensitive, but Exec lists are.  If
the library name is specified in a different case than it exists on
disk, unexpected results may occur.

Prior to V36, tasks could not make OpenDevice calls requiring disk
access (since tasks are not allowed to make dos.library calls).
Now OpenDevice is protected from tasks.

**See also:** CloseDevice, DoIO, SendIO, CheckIO, AbortIO, WaitIO

---

### exec.library/OpenLibrary

**gain access to a library**

**Synopsis:**
```c
library = OpenLibrary(libName, version)

struct Library *OpenLibrary(STRPTR, ULONG);
```

**Description:**
This function returns a pointer to a library that was previously
installed into the system.  If the requested library is exists, and
if the library version is greater than or equal to the requested
version, then the open will succeed.

The library may exist in memory, or on disk; this is transparent to
the OpenLibrary caller.  Only Processes are allowed to call
OpenLibrary (since OpenLibrary may in turn call dos.library).

A full path name for the library name is legitimate.  For example
"wp:libs/wp.library".  This allows the use of custom libraries
without requiring the user to copy the library into the system's
LIBS: directory.

**Inputs:**
libName - the name of the library to open

version - the version of the library required.

**Result:**
library - a library pointer for a successful open, else zero

**Notes:**
All calls to OpenLibrary should have matching calls to CloseLibrary!

Libraries on disk cannot be opened until after DOS has been
started.

As of V36 tasks can safely call OpenLibrary, though DOS may open
system requesters (e.g., asking the user to insert the Workbench
disk if LIBS: is not online).  You must call this function from a
DOS Process if you want to turn off DOS requesters.

**Bugs:**
AmigaDOS file names are not case sensitive, but Exec lists are. If
the library name is specified in a different case than it exists on
disk, unexpected results may occur.

Prior to V36, tasks could not make OpenLibrary calls requiring disk
access (since tasks are not allowed to make dos.library calls).
Now OpenLibrary is protected from tasks.

The version number of the resident tag in disk based library must
match the version number of the library, or V36 may fail to load it.

**See also:** CloseLibrary

---

### exec.library/OpenResource

**gain access to a resource**

**Synopsis:**
```c
resource = OpenResource(resName)

APTR OpenResource(STRPTR);
```

**Description:**
This function returns a pointer to a resource that was previously
installed into the system.

There is no CloseResource() function.

**Inputs:**
resName - the name of the resource requested.

**Result:**
resource - if successful, a resource pointer, else NULL

---

### exec.library/Permit

**permit task rescheduling.**

**Synopsis:**
```c
Permit()

 void Permit(void);
```

**Description:**
Allow other tasks to be scheduled to run by the dispatcher, after a
 matching Forbid() has been executed.

**Result:**
Other tasks will be rescheduled as they are ready to run. In order
 to restore normal task rescheduling, the programmer must execute
 exactly one call to Permit() for every call to Forbid().

**Notes:**
This call is guaranteed to preserve all registers.

**See also:** Forbid, Disable, Enable

---

### exec.library/Procure (V39)

**bid for a semaphore**

**Synopsis:**
```c
Procure(semaphore, bidMessage)
 
VOID Procure(struct SignalSemaphore *, struct SemaphoreMessage *);
```

**Description:**
This function is used to obtain a semaphore in an async manner.
Like ObtainSemaphore(), it will obtain a SignalSemaphore for you
but unlike ObtainSemaphore(), you will not block until you get
the semaphore.  Procure() will just post a request for the semaphore
and will return.  When the semaphore is available (which could
be at any time) the bidMessage will ReplyMsg() and you will own
the semaphore.  This lets you wait on multiple semaphores at once
and to continue processing while waiting for the semaphore.

NOTE:  Pre-V39, Procure() and Vacate() did not work correctly.
They also did not operate on SignalSemaphore semaphores.
Old (and broken) MessageSemaphore use as of V39 will no longer work.

**Inputs:**
semaphore - The SignalSemaphore that you wish to Procure()
bidMessage- The SemaphoreMessage that you wish replied when
        you obtain access to the semaphore.  The message's
        ssm_Semaphore field will point at the semaphore that
        was obtained.  If the ssm_Semaphore field is NULL,
        the Procure() was aborted via Vacate().
        The mn_ReplyPort field of the message must point to
        a valid message port.
        To obtain a shared semaphore, the ln_Name field
        must be set to 1.  For an exclusive lock, the ln_Name
        field must be 0.  No other values are valid.

**Bugs:**
Before V39, Procure() and Vacate() used a different semaphore
system that was very broken.  This new system is only available
as of V39 even though the LVOs are the same.

**See also:** ObtainSemaphoreShared(), InitSemaphore(), ReleaseSemaphore(),
AttemptSemaphore(), ObtainSemaphoreList(), Vacate(), ObtainSemaphore()

---

### exec.library/PutMsg

**put a message to a message port**

**Synopsis:**
```c
PutMsg(port, message)

void PutMsg(struct MsgPort *, struct Message *);
```

**Description:**
This function attaches a message to the end of a given message port.
It provides a fast, non-copying message sending mechanism.

Messages can be attached to only one port at a time.  The message
body can be of any size or form.  Because messages are not copied,
cooperating tasks share the same message memory.  The sender task
must not recycle the message until it has been replied by the
receiver.  Of course this depends on the message handling conventions
setup by the involved tasks.  If the ReplyPort field is non-zero,
when the message is replied by the receiver, it will be sent back to
that port.

Any one of the following actions can be set to occur when a message
is put:

        1. no special action
        2. signal a given task (specified by MP_SIGTASK)
        3. cause a software interrupt (specified by MP_SIGTASK)

The action is selected depending on the value found in the MP_FLAGS
of the destination port.

**Inputs:**
port - pointer to a message port
message - pointer to a message

**See also:** GetMsg, ReplyMsg, exec/ports.h

---

### exec.library/RawDoFmt

**format data into a character stream.**

**Synopsis:**
```c
NextData = RawDoFmt(FormatString, DataStream, PutChProc, PutChData);

 APTR RawDoFmt(STRPTR,APTR,void (*)(),APTR);
```

**Description:**
perform "C"-language-like formatting of a data stream, outputting
 the result a character at a time.  Where % formatting commands are
 found in the FormatString, they will be replaced with the
 corresponding element in the DataStream.  %% must be used in the
 string if a % is desired in the output.

**Inputs:**
FormatString - a "C"-language-like NULL terminated format string,
 with the following supported % options:

  %[flags][width.limit][length]type

 flags      - only one allowed. '-' specifies left justification.
 width      - field width.  If the first character is a '0', the
              field will be padded with leading 0's.
   .        - must follow the field width, if specified
 limit      - maximum number of characters to output from a string.
              (only valid for %s).
 length     - size of input data defaults to WORD for types d, x,
              and c, 'l' changes this to long (32-bit), while 'h' means
              short (the default, included for compatibiliy)
 type       - supported types are:
                 b - BSTR, data is 32-bit BPTR to byte count followed
                     by a byte string, or NULL terminated byte string.
                     A NULL BPTR is treated as an empty string.
                     (Added in V36 exec)
                 d - decimal
                 u - unsigned decimal (Added in V37 exec)
                 x - hexadecimal
                 s - string, a 32-bit pointer to a NULL terminated
                     byte string.  In V36, a NULL pointer is treated
                     as an empty string
                 c - character
                 p - pointer, written as if the format was 0x%08x

 DataStream - a stream of data that is interpreted according to
              the format string.  Often this is a pointer into
              the task's stack.
              Character data must be passed as shorts (or longs when %lc
              is used).
              The function will take care not to throw alignment
              exceptions, however, it is advised not to use shorts anymore.
              The ability is just retained for backward compatibility.

 PutChProc  - the procedure to call with each character to be
              output, called as:

                  PutChProc(Char,  PutChData);

              the procedure is called with a NULL Char at the end of
              the format string.
              Starting with V45.1, this pointer may be NULL. In that
              case, the default "stuffChar" procedure is used.
       This function will place any incoming character into
       a buffer pointer to by PutChData.

 PutChData  - a value that is passed through to the PutChProc
              procedure.  This is untouched by RawDoFmt, and may be
              modified by the PutChProc.

**Result:**
Under V36, RawDoFmt() returns a pointer to the end of the DataStream
 (The next argument that would have been processed).  This allows
 multiple formatting passes to be made using the same data.

**Notes:**
After locale.library is installed in the system, RawDoFmt() is in fact
 replaced by locale.library/FormatString(). Then the putChProc pointer
 will be handled as follows:

 - If it points to 68K code, this code will be called with putChData in A3
   and the character to output in D0, the code has to return the modified
   putChData pointer in A3. Simplest function is "move.b d0,(a3)+"
   followed by "rts".

 - If it points to PPC code, this code will be called with
   "(*putChProc)(character, putChData)", the code does not have to modify
   putChData (no return code).

 - If it points to NULL, a default routine will be used.

**See also:** Documentation on the C language "printf" call in any C language
 reference book.

---

### exec.library/ReleaseSemaphore

**make signal semaphore available to others**

**Synopsis:**
```c
ReleaseSemaphore(signalSemaphore)

void ReleaseSemaphore(struct SignalSemaphore *);
```

**Description:**
ReleaseSemaphore() is the inverse of ObtainSemaphore(). It makes
the semaphore lockable to other users.  If tasks are waiting for
the semaphore and this this task is done with the semaphore then
the next waiting task is signalled.

Each ObtainSemaphore() call must be balanced by exactly one
ReleaseSemaphore() call.  This is because there is a nesting count
maintained in the semaphore of the number of times that the current
task has locked the semaphore. The semaphore is not released to
other tasks until the number of releases matches the number of
obtains.

Needless to say, havoc breaks out if the task releases more times
than it has obtained.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**Notes:**
This call is guaranteed to preserve all registers.

**Bugs:**
In V39 and V40 Kickstart, there is an error condition that bumps
ss_NestCount twice, if multiple Procure() SemaphoreMessages and
a ObtainSemaphore() are pending for the same task.

**See also:** InitSemaphore(), ObtainSemaphore(), ObtainSemaphoreShared()

---

### exec.library/ReleaseSemaphoreList

**make a list of semaphores available**

**Synopsis:**
```c
ReleaseSemaphoreList(list)

void ReleaseSemaphoreList(struct List *);
```

**Description:**
ReleaseSemaphoreList() is the inverse of ObtainSemaphoreList(). It
releases each element in the semaphore list.

Needless to say, havoc breaks out if the task releases more times
than it has obtained.

**Inputs:**
list -- a list of signal semaphores

**See also:** ObtainSemaphoreList()

---

### exec.library/RemDevice

**remove a device from the system**

**Synopsis:**
```c
RemDevice(device)

void RemDevice(struct Device *);
```

**Description:**
This function calls the device's EXPUNGE vector, which requests
that a device delete itself.  The device may refuse to do this if
it is busy or currently open. This is not typically called by user
code.

There are certain, limited circumstances where it may be
appropriate to attempt to specifically flush a certain device.
Example:

 /* Attempts to flush the named device out of memory. */
 #include <exec/types.h>
 #include <exec/execbase.h>

 void FlushDevice(name)
 STRPTR name;
 {
 struct Device *result;

    Forbid();
    if(result=(struct Device *)FindName(&SysBase->DeviceList,name))
        RemDevice(result);
    Permit();
 }

**Inputs:**
device - pointer to a device node

**See also:** AddLibrary

---

### exec.library/RemHead

**remove the head node from a list**

**Synopsis:**
```c
node = RemHead(list)

 struct Node *RemHead(struct List *);
```

**Description:**
Get a pointer to the head node and remove it from the list.
 Assembly programmers may prefer to use the REMHEAD macro from
 "exec/lists.i".

**Inputs:**
list - a pointer to the target list header

**Result:**
node - the node removed or zero when empty list

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddHead, AddTail, Enqueue, Insert, Remove, RemTail

---

### exec.library/RemIntServer

**remove an interrupt server from a server chain**

**Synopsis:**
```c
RemIntServer(intNum, interrupt)

void RemIntServer(ULONG,struct Interrupt *);
```

**Description:**
This function removes an interrupt server node from the given
server chain.

If this server was the last one on this chain, interrupts for this
chain are disabled.

**Inputs:**
intNum - the Paula interrupt bit (0..14)
interrupt - pointer to an interrupt server node

**Bugs:**
Before V36 Kickstart, the feature that disables the interrupt
would not function.  For most server chains this does not
cause a problem.

**See also:** AddIntServer, hardware/intbits.h

---

### exec.library/RemLibrary

**remove a library from the system**

**Synopsis:**
```c
RemLibrary(library)

void RemLibrary(struct Library *);
```

**Description:**
This function calls the library's EXPUNGE vector, which requests
that a library delete itself.  The library may refuse to do this if
it is busy or currently open. This is not typically called by user
code.

There are certain, limited circumstances where it may be
appropriate to attempt to specifically flush a certain Library.
Example:

 /* Attempts to flush the named library out of memory. */
 #include <exec/types.h>
 #include <exec/execbase.h>

 void FlushLibrary(name)
 STRPTR name;
 {
 struct Library *result;

    Forbid();
    if(result=(struct Library *)FindName(&SysBase->LibList,name))
        RemLibrary(result);
    Permit();
 }

**Inputs:**
library - pointer to a library node structure

---

### exec.library/RemMemHandler (V39)

**Synopsis:**
```c
RemMemHandler(memHandler)

 VOID RemMemHandler(struct Interrupt *);
```

**Description:**
This function removes the low memory handler from the system.
 This function can be called from within a handler.  If removing
 oneself, it is important that the handler returns MEM_ALL_DONE.

**Inputs:**
memHandler - Pointer to a handler added with AddMemHandler()

**Notes:**
When removing a handler, the handler may be called until this
 function returns.  Thus, the handler must still be valid until
 then.

**See also:** AddMemHandler, exec/interrupts.h

---

### exec.library/Remove

**remove a node from a list**

**Synopsis:**
```c
Remove(node)

 void Remove(struct Node *);
```

**Description:**
Unlink a node from whatever list it is in.  Nodes that are not part
 of a list must not be passed to this function!  Assembly programmers
 may prefer to use the REMOVE macro from "exec/lists.i".

**Inputs:**
node - the node to remove

**Example:**
```c
/* If traversing 'list' with GetHead/GetSucc and nodes may at
 * some point be Remove()ed, it is not permitted to read any of
 * the node linkage fields after it has left the list, as removing
 * the node invalidates the list pointers, therefore, it is 
 * necessary to determine the successor before removal.
 * Note; when using these functions, don't check the 
 * currentNode->ln_Succ, just for currentNode != NULL.
 */
struct Node *currentNode, *nextNode;

for (currNode=IExec->GetHead(list);
     currentNode != NULL;
     currentNode = nextNode)
{
     nextNode = IExec->GetSucc(currentNode);

     /* Now do something with currentNode. */
     /* This may include node removal from list. EG:- */

     if( some_condition )
     {
   IExec->Remove(currentNode);
     }
}
```

**Notes:**
As of V50, this function modifies the ln_Succ and ln_Pred
 pointers to prevent disaster from Removing a node twice.

**See also:** AddHead, AddTail, Enqueue, Insert, RemHead, RemTail, 
     GetHead, GetTail, GetSucc, GetPred.

---

### exec.library/RemPort

**remove a message port from the system**

**Synopsis:**
```c
RemPort(port)

void RemPort(struct MsgPort *);
```

**Description:**
This function removes a message port structure from the system's
message port list.  Subsequent attempts to rendezvous by name with
this port will fail.

**Inputs:**
port - pointer to a message port

**See also:** AddPort, FindPort

---

### exec.library/RemResource

**remove a resource from the system**

**Synopsis:**
```c
RemResource(resource)

void RemResource(APTR);
```

**Description:**
This function removes an existing resource from the system resource
list.  There must be no outstanding users of the resource.

**Inputs:**
resource - pointer to a resource node

**See also:** AddResource

---

### exec.library/RemSemaphore

**remove a signal semaphore from the system**

**Synopsis:**
```c
RemSemaphore(signalSemaphore)

void RemSemaphore(struct SignalSemaphore *);
```

**Description:**
This function removes a signal semaphore structure from the
system's signal semaphore list.  Subsequent attempts to
rendezvous by name with this semaphore will fail.

**Inputs:**
signalSemaphore -- an initialized signal semaphore structure

**See also:** AddSemaphore, FindSemaphore

---

### exec.library/RemTail

**remove the tail node from a list**

**Synopsis:**
```c
node = RemTail(list)

 struct Node *RemTail(struct List *);
```

**Description:**
Remove the last node from a list, and return a pointer to it. If
 the list is empty, return zero. Assembly programmers may prefer to
 use the REMTAIL macro from "exec/lists.i".

**Inputs:**
list - a pointer to the target list header

**Result:**
node - the node removed or zero when empty list

**Notes:**
This function does not arbitrate for access to the list.  The
 calling task must be the owner of the involved list.

**See also:** AddHead, AddTail, Enqueue, Insert, Remove, RemHead, RemTail

---

### exec.library/RemTask

**remove a task from the system**

**Synopsis:**
```c
RemTask(task)

void RemTask(struct Task *);
```

**Description:**
This function removes a task from the system.  Deallocation of
resources should have been performed prior to calling this
function.  Removing some other task is very dangerous.  Generally
is is best to arrange for tasks to call RemTask(0L) on themselves.

RemTask will automagically free any memory lists attached to the
task's TC_MEMENTRY list.

**Inputs:**
task - pointer to the task node representing the task to be
       removed.  A zero value indicates self removal, and will
       cause the next ready task to begin execution.

**Bugs:**
Before V36 if RemTask() was called on a task other than the current
task, and that task was created with amiga.lib/CreateTask, there was
a slight chance of a crash.  The problem can be hidden by bracketing
RemTask() with Forbid()/Permit().

**See also:** AddTask, exec/AllocEntry, amiga.lib/DeleteTask

---

### exec.library/ReplyMsg

**put a message to its reply port**

**Synopsis:**
```c
ReplyMsg(message)

void ReplyMsg(struct Message *);
```

**Description:**
This function sends a message to its reply port.  This is usually
done when the receiver of a message has finished and wants to
return it to the sender (so that it can be re-used or deallocated,
whatever).

This call may be made from interrupts.

**Inputs:**
message - a pointer to the message

**See also:** GetMsg, PutMsg, exec/ports.h

---

### exec.library/SendIO

**initiate an I/O command**

**Synopsis:**
```c
SendIO(iORequest)

void SendIO(struct IORequest *);
```

**Description:**
This function requests the device driver start processing the given
I/O request.  The SendIO() function will return without waiting for
the I/O to complete.

The io_Flags field of the IORequest will be set to zero before the
request is sent.

**Inputs:**
iORequest - pointer to an I/O request, or a device specific
            extended IORequest.

**Notes:**
Some device drivers require that certain bits in io_Flags are set
for proper operations and will not work correctly if an IORequest
is used with SendIO() because it sets io_Flags to zero before the
request is sent.  The audio.device is such a kind of device driver.
For such device drivers BeginIO() must be used in place of SendIO()
or even DoIO().

You must not call SendIO() on an IORequest that has never been
successfully used with OpenDevice() and that is not a duplicate of
an IORequest which was successfully used with OpenDevice(). If you
use it on an IORequest that was just created with CreateIORequest()
or which was just used with the CloseDevice() function, you will
either cause your task to hang, or you may crash the operating
system.

**See also:** DoIO(), CheckIO(), WaitIO(), AbortIO(), BeginIO()

---

### exec.library/SetExcept

**define certain signals to cause exceptions**

**Synopsis:**
```c
oldSignals = SetExcept(newSignals, signalMask)

ULONG SetExcept(ULONG,ULONG);
```

**Description:**
This function defines which of the task's signals will cause a
private task exception.  When any of the signals occurs the task's
exception handler will be dispatched.  If the signal occurred prior
to calling SetExcept, the exception will happen immediately.

The user function pointed to by the task's tc_ExceptCode gets
called as:

    newExcptSet = <exceptCode>(SysBase, signals, exceptData)

    signals - The set of signals that caused this exception.  These
        Signals have been disabled from the current set of signals
        that can cause an exception.

    exceptData - A copy of the task structure tc_ExceptData field.

    newExcptSet - The set of signals in NewExceptSet will be re-
        enabled for exception generation.  Usually this will be the
        same as the Signals that caused the exception.

**Inputs:**
newSignals - the new values for the signals specified in
             signalMask.
signalMask - the set of signals to be effected

**Result:**
oldSignals - the prior exception signals

**Example:**
```c
Get the current state of all exception signals:
    SetExcept(0,0)
Change a few exception signals:
    SetExcept($1374,$1074)
```

**See also:** Signal, SetSignal

---

### exec.library/SetFunction

**change a function vector in a library**

**Synopsis:**
```c
oldFunc = SetFunction(library, funcOffset, funcEntry)

APTR SetFunction(struct Library *,LONG,APTR);
```

**Description:**
SetFunction is a functional way of changing where vectors in a
library point.  They are changed in such a way that the
checksumming process will never falsely declare a library to be
invalid.

**Inputs:**
library    - a pointer to the library to be changed
funcOffset - the offset of the function to be replaced
funcEntry  - pointer to new function

**Result:**
oldFunc    - pointer to the old function that was just replaced

**Notes:**
SetFunction cannot be used on non-standard libraries like pre-V36
dos.library.  Here you must manually Forbid(), preserve all 6
original bytes, set the new vector, SumLibrary(), then Permit().

---

### exec.library/SetIntVector

**set a new handler for a system interrupt vector**

**Synopsis:**
```c
oldInterrupt = SetIntVector(intNumber, interrupt)

struct Interrupt *SetIntVector(ULONG, struct Interrupt *);
```

**Description:**
This function provides a mechanism for setting the system interrupt
vectors.  These are non-sharable; setting a new interrupt handler
disconnects the old one.  Installed handlers are responsible for
processing, enabling and clearing the interrupt.  Note that interrupts
may have been left in any state by the previous code.

The IS_CODE and IS_DATA pointers of the Interrupt structure will
be copied into a private place by Exec.  A pointer to the previously
installed Interrupt structure is returned.

Interrupt handlers are called with a 'C' compatible environment, i.e.
all volatile registers are preserved. The protoype for an interrupt
vector looks like this:
  
void interruptHandler(struct ExceptionContext *Context, 
        struct ExecBase *SysBase, void *UserData);

Context is a pointer to the register storage area. Under normal conditions,
only volatile register will have been saved, and the appropriate flag will
be clear to reflect this. Note, though, that you have to be prepared to handle
all cases (if you need access to the interrupted task's registers, anyway).
Additionally, userData is the pointer to the user data field taken from the
Interrupt's data structure.

Starting with V50, and additional set of "interrupts" is availabe,
enumerated in exec/interrupts.h, enTrapNumbers.

**Inputs:**
intNum - the Paula interrupt bit number (0..14).  Only non-chained
         interrupts should be set.  Use AddIntServer() for server
         chains.
         Some additional interrupt numbers might be present. Refer
         to the documentation of expansion.library for more information.
interrupt - a pointer to an Interrupt structure containing the
         handler's entry point and data segment pointer.  A NULL
         interrupt pointer will remove the current interrupt and
         set illegal values for IS_CODE and IS_DATA.

         By convention, the LN_NAME of the interrupt structure must
         point a descriptive string so that other users may
         identify who currently has control of the interrupt.

**Result:**
A pointer to the prior interrupt structure which had control
of this interrupt.

**See also:** AddIntServer(),exec/interrupts.i,hardware/intbits.i

---

### exec.library/SetMethod

**Modify a method in an interface**

**Synopsis:**
```c
old_func = SetMethod(interface, funcOffset, newFunc);

APTR SetMethod(struct Interface *, LONG, APTR);
```

**Description:**
This function will override a method in an interface with
another method. It will fail if the interface is protected 
from SetMethod.

**Inputs:**
interface   - Pointer to the interface to be modified
funcOffset  - Offset of the method to be modified, measured 
              from the start of the interface
newFunc     - New method to be stored in this place

**Result:**
The old value of the method is returned. This might be NULL.
A value of NULL means that either the method was NULL, or
the interface was protected from modification.

**Example:**
```c
void new_foo_method(struct SomeInterface *if, ...);

IExec->SetMethod(myInterface, offsetof(struct SomeInterface, foo), 
                        new_foo_method);
```

**Notes:**
THIS FUNCTION IS DANGEROUS. Don't use it. It's main purpose 
is to provide ways for debuggers to hook into interfaces.

---

### exec.library/SetSignal

**define the state of this task's signals**

**Synopsis:**
```c
oldSignals = SetSignal(newSignals, signalMask)

ULONG SetSignal(ULONG,ULONG);
```

**Description:**
This function can query or modify the state of the current task's
received signal mask.  Setting the state of signals is considered
dangerous.  Reading the state of signals is safe.

**Inputs:**
newSignals - the new values for the signals specified in
             signalSet.
signalMask - the set of signals to be affected.

**Result:**
oldSignals - the prior values for all signals

**Example:**
```c
Get the current state of all signals:
     SetSignal(0L,0L);
Clear the CTRL-C signal:
     SetSignal(0L,SIGBREAKF_CTRL_C);


Check if the CTRL-C signal was pressed:

     #include <libraries/dos.h>

     /* Check & clear CTRL_C signal */
     if(SetSignal(0L,SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
     {
         printf("CTRL-C pressed!\n");
     }
```

**See also:** Signal, Wait

---

### exec.library/SetSR

**get and/or set processor status register (Obsolete)**

**Synopsis:**
```c
oldSR = SetSR(newSR, mask)

ULONG SetSR(ULONG, ULONG);
```

**Description:**
This function provides a means of modifying the CPU status register
in a "safe" way (well, how safe can a function like this be
anyway?).  This function will only affect the status register bits
specified in the mask parameter.  The prior content of the entire
status register is returned.

**Inputs:**
newSR - new values for bits specified in the mask.
    All other bits are not effected.
mask - bits to be changed

**Result:**
oldSR - the entire status register before new bits

**Example:**
```c
To get the current SR:
    currentSR = SetSR(0,0);
To change the processor interrupt level to 3:
    oldSR = SetSR($0300,$0700);
Set processor interrupts back to prior level:
    SetSR(oldSR,$0700);
```

**Notes:**
From V50 upward, this function will do nothing except returning 0
an generating an Alert

---

### exec.library/SetTaskPri

**get and set the priority of a task**

**Synopsis:**
```c
oldPriority = SetTaskPri(task, priority)

BYTE SetTaskPri(struct Task *, BYTE);
```

**Description:**
This function changes the priority of a task regardless of its
state.  The old priority of the task is returned.  A reschedule is
performed, and a context switch may result.

To change the priority of the currently running task, pass the
result of FindTask(0); as the task pointer.

**Inputs:**
task - task to be affected
priority - the new priority for the task

**Result:**
oldPriority - the tasks previous priority

---

### exec.library/Signal

**signal a task**

**Synopsis:**
```c
Signal(task, signals)
 
void Signal(struct Task *,ULONG);
```

**Description:**
This function signals a task with the given signals.  If the task
is currently waiting for one or more of these signals, it will be
made ready and a reschedule will occur. If the task is not waiting
for any of these signals, the signals will be posted to the task
for possible later use. A signal may be sent to a task regardless
of whether it is running, ready, or waiting.

This function is considered "low level".  Its main purpose is to
support multiple higher level functions like PutMsg.

This function is safe to call from interrupts.

**Inputs:**
task - the task to be signalled
signals - the signals to be sent

**See also:** Wait, SetSignal

---

### exec.library/StackSwap (V37)

**Synopsis:**
```c
StackSwap(newStack)

VOID StackSwap(struct StackSwapStruct *);
```

**Description:**
This function will, in an EXEC supported manner, swap the
stack of your task with the given values in StackSwap.
The StackSwapStruct structure will then contain the values
of the old stack such that the old stack can be restored.
This function is new in V37.

**Inputs:**
newStack - A structure that contains the values for the
           new upper and lower stack bounds and the new stack
           pointer.  This structure will have its values
           replaced by those in you task such that you can
           restore the stack later.

**Result:**
newStack - The structure will now contain the old stack.
           This means that StackSwap(foo); StackSwap(foo);
           will effectively do nothing.

**Notes:**
If you do a stack swap, only the new stack is set up.
This function does not copy the stack or do anything else
other than set up the new stack for the task.  It is
generally required that you restore your stack before
exiting.

**See also:** AddTask, RemTask, exec/tasks.h

---

### exec.library/SumKickData

**compute the checksum for the Kickstart delta list**

**Synopsis:**
```c
checksum = SumKickData()

ULONG SumKickData(void);
```

**Description:**
The Amiga system has some ROM (or Kickstart) resident code that
provides the basic functions for the machine.  This code is
unchangeable by the system software.  This function is part of a
support system to modify parts of the ROM.

The ROM code is linked together at run time via ROMTags (also known
as Resident structures, defined in exec/resident.h).  These tags tell
Exec's low level boot code what subsystems exist in which regions of
memory.  The current list of ROMTags is contained in the ResModules
field of ExecBase.  By default this list contains any ROMTags found
in the address ranges $F80000-$FFFFFF and $F00000-$F7FFFF.

There is also a facility to selectively add or replace modules to the
ROMTag list.  These modules can exist in RAM, and the memory they
occupy will be deleted from the memory free list during the boot
process.  SumKickData() plays an important role in this run-time
modification of the ROMTag array.

Three variables in ExecBase are used in changing the ROMTag array:
KickMemPtr, KickTagPtr, and KickCheckSum. KickMemPtr points to a
linked list of MemEntry structures. The memory that these MemEntry
structures reference will be allocated (via AllocAbs) at boot time.
The MemEntry structure itself must also be in the list.

KickTagPtr points to a long-word array of the same format as the
ResModules array.  The array has a series of pointers to ROMTag
structures.  The array is either NULL terminated, or will have an
entry with the most significant bit (bit 31) set.  The most
significant bit being set says that this is a link to another
long-word array of ROMTag entries.  This new array's address can be
found by clearing bit 31.

KickCheckSum has the result of SumKickData().  It is the checksum of
both the KickMemPtr structure and the KickTagPtr arrays.  If the
checksum does not compute correctly then both KickMemPtr and
KickTagPtr will be ignored.

If all the memory referenced by KickMemPtr can't be allocated then
KickTagPtr will be ignored.

There is one more important caveat about adding ROMTags. All this
ROMTag magic is run very early on in the system -- before expansion
memory is added to the system. Therefore any memory in this
additional ROMTag area must be addressable at this time. This means
that your ROMTag code, MemEntry structures, and resident arrays
cannot be in expansion memory.  There are two regions of memory that
are acceptable:  one is chip memory, and the other is "Ranger" memory
(memory in the range between $C00000-$D80000).

Remember that changing an existing ROMTag entry falls into the
"heavy magic" category -- be very careful when doing it.  The odd are
that you will blow yourself out of the water.

**Result:**
Value to be stuffed into ExecBase->KickCheckSum.

**Notes:**
After writing to KickCheckSum, you should push the data cache.
This prevents potential problems with large copyback style caches.
A call to CacheClearU will do fine.

**See also:** InitResident, FindResident

---

### exec.library/SumLibrary

**compute and check the checksum on a library**

**Synopsis:**
```c
SumLibrary(library)

void SumLibrary(struct Library *);
```

**Description:**
SumLibrary computes a new checksum on a library.  It can also be
used to check an old checksum.  If an old checksum does not match,
and the library has not been marked as changed, then the system
will call Alert().

This call could also be periodically made by some future
system-checking task.

**Inputs:**
library - a pointer to the library to be changed

**Notes:**
An alert will occur if the checksum fails.

**See also:** SetFunction

---

### exec.library/SuperState

**enter supervisor state with user stack**

**Synopsis:**
```c
oldSysStack = SuperState()

APTR SuperState(void);
```

**Description:**
Enter supervisor mode while running on the user's stack. The user
still has access to user stack variables.  Be careful though, the
user stack must be large enough to accommodate space for all
interrupt data -- this includes all possible nesting of interrupts.
This function does nothing when called from supervisor state.

**Result:**
oldSysStack - system stack pointer; save this.  It will come in
              handy when you return to user state.  If the system
              is already in supervisor mode, oldSysStack is zero.

**Notes:**
Starting from V50, supervisor and user mode use the same stack.

**See also:** UserState, Supervisor

---

### exec.library/Supervisor

**trap to a short supervisor mode function**

**Synopsis:**
```c
result = Supervisor(userFunc)

ULONG Supervisor(void *);
```

**Description:**
Allow a normal user-mode program to execute a short function
in the supervisor mode of the processor.

**Inputs:**
userFunc - A pointer to a short function. Normal ABI rules apply.
           The prototype for the function looks like this:
           ULONG userFunc(struct ExecIFace *);
           The Exec main interface will be passed for convenience.

**Result:**
result   - Whatever values the userFunc left in the registers.

**See also:** SuperState,UserState

---

### exec.library/TypeOfMem

**determine attributes of a given memory address**

**Synopsis:**
```c
attributes = TypeOfMem(address)

 ULONG TypeOfMem(void *);
```

**Description:**
Given a RAM memory address, search the system memory lists and
 return its memory attributes.  The memory attributes are similar to
 those specified when the memory was first allocated: (eg. MEMF_CHIP
 and MEMF_FAST).

 This function is usually used to determine if a particular block of
 memory is within CHIP space.

 If the address is not in known-space, a zero will be returned.
 (Anything that is not RAM, like the ROM or expansion area, will
 return zero.  Also the first few bytes of a memory area are used up
 by the MemHeader.)

**Inputs:**
address - a memory address

**Result:**
attributes - a long word of memory attribute flags.
 If the address is not in known RAM, zero is returned.

**See also:** AllocMem()

---

### exec.library/UserState

**return to user state with user stack**

**Synopsis:**
```c
UserState(sysStack)

void UserState(APTR);
```

**Description:**
Return to user state with user stack, from supervisor state with
user stack.  This function is normally used in conjunction with the
SuperState function above.

This function must not be called from the user state.

**Inputs:**
sysStack - supervisor stack pointer

**Bugs:**
This function is broken in V33/34 Kickstart.  Fixed in V1.31 setpatch.

**See also:** SuperState/Supervisor

---

### exec.library/Vacate (V39)

**release a bitMessage from Procure()**

**Synopsis:**
```c
Vacate(semaphore, bidMessage)

void Vacate(struct SignalSemaphore *,struct SemaphoreMessage *);
```

**Description:**
This function can be used to release a semaphore obtained via
Procure().  However, the main purpose for this call is to be
able to remove a bid for a semaphore that has not yet responded.
This is required when a Procure() was issued and the program
no longer needs to get the semaphore and wishes to cancel the
Procure() request.  The canceled request will be replied with
the ssm_Semaphore field set to NULL.  If you own the semaphore,
the message was already replied and only the ssm_Semaphore field
will be cleared.

NOTE:  Pre-V39, Procure() and Vacate() did not work correctly.
They also did not operate on SignalSemaphore semaphores.
Old (and broken) MessageSemaphore use as of V39 will no longer work.

**Inputs:**
semaphore - The SignalSemaphore that you wish to Vacate()
bidMessage- The SemaphoreMessage that you wish to abort.
        The message's ssm_Semaphore field will be cleared.
        The message will be replied if it is still on the waiting
        list.  If it is not on the waiting list, it is assumed
        that the semaphore is owned and it will be released.

**Bugs:**
Before V39, Procure() and Vacate() used a different semaphore
system that was very broken.  This new system is only available
as of V39 even though the LVOs are the same.

**See also:** ObtainSemaphoreShared(), InitSemaphore(), ReleaseSemaphore(),
AttemptSemaphore(), ObtainSemaphoreList(), Procure(), ObtainSemaphore()

---

### exec.library/Wait

**wait for one or more signals**

**Synopsis:**
```c
signals = Wait(signalSet)

ULONG Wait(ULONG);
```

**Description:**
This function will cause the current task to suspend waiting for
one or more signals.  When one or more of the specified signals
occurs, the task will return to the ready state, and those signals
will be cleared.

If a signal occurred prior to calling Wait(), the wait condition will
be immediately satisfied, and the task will continue to run without
delay.

   CAUTION
This function cannot be called while in supervisor mode or
interrupts!  This function will break the action of a Forbid() or
Disable() call.

**Inputs:**
signalSet - The set of signals for which to wait.
            Each bit represents a particular signal.

**Result:**
signals - the set of signals that were active

---

### exec.library/WaitIO

**wait for completion of an I/O request**

**Synopsis:**
```c
error = WaitIO(iORequest)

BYTE WaitIO(struct IORequest *);
```

**Description:**
This function waits for the specified I/O request to complete, then
removes it from the reply port.  If the I/O has already completed,
this function will immediately remove the I/O request from the
reply port without waiting first.

This function should be used with care, as it does not return until
the I/O request completes; if the I/O never completes, this
function will never return, and your task will hang.  If this
situation is a possibility, it is safer to use the Wait() function.
Wait() will return return when any of a specified set of signal is
received.  This is how I/O timeouts can be properly handled.

Note that WaitIO() will not work on I/O requests that haven't been
used before.  Only use WaitIO() with I/O requests which have been
started via SendIO() or BeginIO().  If you did not start the I/O
request with either SendIO() or BeginIO(), do not call WaitIO()
since it will hang.

**Inputs:**
iORequest - pointer to an I/O request block

**Result:**
error - zero if successful, else an error is returned
        (a sign extended copy of IORequest->io_Error).

**Notes:**
If this IORequest was "Quick" or otherwise finished BEFORE this
call, this function immediately removes the IORequest, with no call
to Wait().  A side effect is that the signal bit related the port
may remain set.  Expect this.  One way to work around WaitIO() not
clearing the signal bit is to clear it with SetSignal() before
SendIO() or BeginIO() is called.

When removing a known complete IORequest from a port, WaitIO() is
the required.  A simple Remove() is not enough.

**Bugs:**
Previous documentation suggested that WaitIO() immediately returned
if the I/O request had already completed, and would not even
remove the I/O request from the reply port.  This was never the case.
The documentation now clarifies the context.

**See also:** DoIO(), SendIO(), CheckIO(), AbortIO()

---

### exec.library/WaitPort

**wait for a given port to be non-empty**

**Synopsis:**
```c
message = WaitPort(port)

struct Message *WaitPort(struct MsgPort *);
```

**Description:**
This function waits for the given port to become non-empty.  If
necessary, the Wait() function will be called to wait for the port
signal.  If a message is already present at the port, this function
will return immediately.  The return value is always a pointer to
the first message queued (but it is not removed from the queue).

   CAUTION
More than one message may be at the port when this returns.  It is
proper to call the GetMsg() function in a loop until all messages
have been handled, then wait for more to arrive.

To wait for more than one port, combine the signal bits from each
port into one call to the Wait() function, then use a GetMsg() loop
to collect any and all messages.  It is possible to get a signal
for a port WITHOUT a message showing up.  Plan for this.

**Inputs:**
port - a pointer to the message port

**Result:**
message - a pointer to the first available message

**See also:** GetMsg

---

## Obsolete Functions

*These functions are deprecated and should not be used in new code.*

### exec.library/AllocEntry [OBSOLETE]

**Allocate many regions of memory. (-DEPRECATED-)
            -- Use AllocTaskMemEntry() from V51+**

**Synopsis:**
```c
struct MemList *memList = AllocEntry(struct memList *memList);
```

**Description:**
This function takes a memList structure and allocates enough memory
 to hold the required memory as well as a MemList structure to keep
 track of it.

 These MemList structures may be linked together in a task control
 block to keep track of the total memory usage of this task. (See
 the description of TC_MEMENTRY under RemTask).

**Inputs:**
memList -- A MemList structure filled in with MemEntry structures.

**Result:**
memList -- A different MemList filled in with the actual memory
     allocated in the me_Addr field, and their sizes in me_Length.
     If enough memory cannot be obtained, then the requirements of
     the allocation that failed is returned and bit 31 is set.

     WARNING: The result is unusual!  Bit 31 indicates failure.

**Notes:**
This function is deprecated because it breaks on address spaces
 past the first 2gig boundary. Use AllocTaskMemEntry() from V51+

**See also:** FreeEntry, exec/memory.h

---

### exec.library/MakeLibrary [OBSOLETE]

**construct a library                  (OBSOLETE!)**

**Synopsis:**
```c
library = MakeLibrary(vectors, structure, init, dataSize, segList)

struct Library *MakeLibrary(APTR, APTR, APTR, ULONG, APTR);
```

**Description:**
This function is used for constructing a library vector and
	data area.  Space for the library is allocated from the
	system's free memory pool. The size fields of the library
	are filled.  The data portion of the library is
	initialized.  A library specific entrypoint is called
	(init) if present.

**Inputs:**
vectors - pointer to an array of function pointers or
		function displacements.  If the first word of the
		array is -1, then the array contains relative word
		displacements (based off of vectors); otherwise,
		the array contains absolute function pointers.
		The vector list is terminated by a -1 (of the same
		size as the pointers).

	structure - points to an "InitStruct" data region.  If null,
		then it will not be called.

	init - an entry point that will be called before adding
		the library to the system.  If null, it will not be
		called.  When it is called, it will be called with:
			d0 = libAddr	;Your Library Address
			a0 = segList	;Your AmigaDOS segment list
			a6 = ExecBase	;Address of exec.library
		The result of the init function will be the result
		returned by MakeLibrary.
    MakeLibrary will always emulate this function, assuming
    it's m68k code.

	dSize - the size of the library data area, including the
		standard library node data.

	segList - pointer to a memory segment list (used by DOS)
		This is passed to a library's init code.

**Result:**
library - the reference address of the library.  This is
		the address used in references to the library, not
		the beginning of the memory area allocated.

**Notes:**
WARNING: This function is obsolete with release 50.
Only m68k libraries can still be created with it. All new
libraries *MUST* be created with CreateLibrary.

   EXCEPTION
	If the library vector table require more system memory
	than is available, this function will cause a system panic.

**See also:** InitStruct, CreateLibrary

---
