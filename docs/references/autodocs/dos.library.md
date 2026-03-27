# dos.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 183
**Obsolete:** 3

## Function Index

- **AddBuffers** (V36) — Manually changes the number of filesystem buffers.
- **AddDosEntry** (V36) — Add a Dos List entry to the lists.
- **AddPart** (V36) — Appends a file/dir to the end of a path
- **AddSegment** (V36) — 
- **AllocDosObject** (V36) — Creates a dos object
- **AssignAdd** (V36) — Adds a lock to an assign for multi-directory assigns.
- **AssignAddToList** — Adds a multi-assignment entry to an existing
- **AssignLate** (V36) — Creates a DLT_LATE type deferred assignment later.
- **AssignLock** (V36) — Creates a DLT_LOCK assignment to a locked object
- **AssignPath** (V36) — Creates a DLT_NONBINDING assignment to a path.
- **AttemptLockDosList** (V36) — Attempt to lock the Dos Lists for use
- **ChangeFilePosition** — Change the current cursor position for reading
- **ChangeFileSize** — Change the size of a file.  (V51.64)
- **ChangeMode** (V36) — 
- **CheckSignal** (V36) — Checks for break signals.
- **Cli** (V36) — Returns a pointer to the CLI structure of the process
- **CliInitNewcli** — Set up a process to be a shell from initial packet
- **CliInitRun** — Set up a process to be a shell from initial packet
- **Close** — Close an open file.  (unbuffered)
- **CompareDates** (V36) — Compares two datestamps.
- **CopyStringBSTRToC** — Copy BCPL format string to 'C' format
- **CopyStringCToBSTR** — Copy 'C' format string to NUL terminated BCPL
- **CreateDir** — Create a new directory.
- **CreateNewProc** (V36) — Create a new DOS process.
- **DateStamp** — Obtain the date and time values.
- **DateToStr** (V36) — Converts a DateStamp to a string.
- **Delay** — Delay a task or process for a specified time.
- **Delete** — Delete a file, directory or symbolic link.
- **DeleteVar** (V36) — Deletes a local or global environment variable.
- **DevNameFromFH** — Returns the device with or without path,
- **DevNameFromPort** — Get the device name of a handler by its MsgPort.
- **DismountDevice** — Dismounts a file system or handler (V51.30)
- **DoPkt** (V36) — Low level function to send a dos packet to a handler 
- **DupFileHandle** — Creates a duplicate of an open filehandle. (V51.32)
- **DupLock** — Duplicate an existing lock.
- **DupLockFromFH** (V36) — Gets a lock on an open file
- **EndNotify** (V36) — Ends a notification request.
- **ErrorReport** (V36) — Displays a Retry/Cancel requester for an error.
- **ExamineDir** — Examine a complete directory of a filesystem. (V51.104)
- **ExamineObject** — Examine a single filesystem object. (V51.104)
- **Fault** (V36) — Returns the text associated with a DOS error code.
- **FFlush** (V36) — Flushes buffers for a buffered filehandle.
- **FGetC** (V36) — Read a character from the specified input. (buffered)
- **FGets** (V36) — Reads a line from the specified input (buffered)
- **FileHandleScan** — Low level routine to scan through the DOS filehandle
- **FilePart** (V36) — Returns the last component of a path
- **FileSystemAttr** — Get and Set attributes for a filesystem (V51.46)
- **FindArg** (V36) — 
- **FindCliProc** (V36) — returns a pointer to the requested CLI process.
- **FindDosEntry** (V36) — Finds a specific Dos List entry.
- **FindSegment** (V36) — 
- **FindVar** (V36) — Finds a local variable.
- **FlushVolume** — Cause a filesystem to flush outstanding writes. (V53.58)
- **FlushVolumePort** — Cause a filesystem to flush outstanding writes. (V53.90)
- **Format** (V36) — Causes a filesystem to initialize itself
- **FormatPort** — Causes a filesystem to initialize itself (V53.88)
- **FPrintf** (V36) — format and print a string to a file. (buffered)
- **FPutC** (V36) — Write a character to the specified output. (buffered)
- **FPuts** (V36) — Writes a string to the specified output. (buffered)
- **FRead** (V36) — Reads a number of blocks from an input (buffered)
- **FReadLine** — Reads a line or until EOF with dynamic buffering. (V51.47)
- **FreeArgs** (V36) — 
- **FreeDeviceProc** (V36) — Releases data returned by GetDeviceProc[Flags]()
- **FreeDosObject** (V36) — Frees an object allocated by AllocDosObject().
- **FWrite** (V36) — Writes a number of blocks to an output. (buffered)
- **GetArgStr** (V36) — Returns the arguments for the process.
- **GetCliCurrentDirName** (V36) — returns the current directory name
- **GetCliProgramName** (V36) — Returns the current CLI program name from the
- **GetCliPrompt** (V36) — Returns the prompt from the attached CLI structure.
- **GetConsolePort** (V36) — Returns the default console for the process.
- **GetDeviceProc** (V36) — Low level function to find a DOS handler.
- **GetDiskInfo** — Returns information about a disk or handler. (51.96)
- **GetEntryData** — Obtain the entry data set by CreateNewProc() (V51.73)
- **GetFilePosition** — Return the current file cursor position. (51.64)
- **GetFileSize** — Obtain the size of a file. (V51.62)
- **GetFileSysPort** (V36) — 
- **GetFileSystemVectorPort** — Low level routine to return a pointer to a
- **GetOwnerInfo** — Get owner information for an object. (V52.18)
- **GetPID** — Low level routine to obtain the process identifier number.
- **GetProcSegList** — Obtain a seglist for a process. (V51.88)
- **GetProgramDir** (V36) — Returns a lock on the directory the program was 
- **GetVar** (V36) — Reads the value of a local or global variable.
- **Info** — Returns information about the disk.
- **Inhibit** (V36) — Inhibits access to a filesystem.
- **InhibitPort** — Inhibits access to a filesystem. (V53.88)
- **Input** — Identify the program's initial input file handle.
- **IoErr** — Return extra information from the system.
- **IsFileSystem** (V36) — Returns whether a Dos handler is a filesystem.
- **IsFileSystemPort** — Determine if a port is for a filesystem. (V53.87)
- **IsInteractive** — Discover whether a file handle is "interactive".
- **LoadSeg** — Loads a loadable file into memory. (68K or NATIVE)
- **Lock** (V36) — Lock a directory or file.
- **LockDosList** (V36) — Locks the specified Dos lists for use.
- **LockRecord** — Locks a portion of a file.
- **LockRecords** — Lock a series of records.
- **LockTagList** — Lock a directory or file, with extra features. (V53.56)
- **MakeLink** (V36) — Creates a filesystem link.
- **MatchEnd** (V36) — Free storage allocated for MatchFirst()/MatchNext()
- **MatchFirst** (V36) — Finds a file that matches a string.
- **MatchNext** (V36) — 
- **MatchPattern** (V36) — Checks for a pattern match with a string.
- **MatchPatternNoCase** (V36) — Checks for a pattern match with a string.
- **MaxCli** (V36) — 
- **NameFromFH** (V36) — Get the volume name/path of an open filehandle.
- **NameFromLock** (V36) — Returns the volume name and path of a lock.
- **NameFromPort** — Get the volume name of a handler by the MsgPort.
- **NextDosEntry** (V36) — Get the next Dos List entry.
- **NonBlockingModifyDosEntry** — Modify a DosList node without blocking.
- **NotifyDosListChange** — 
- **NotifyProcListChange** — 
- **ObtainConsoleData** — Returns data about a console window. (53.59)
- **ObtainDirContext** — Creates a context for ExamineDir().
- **Open** (V30) — Open a file for (unbuffered) input or output.
- **OpenFromLock** (V36) — Opens a file you have a lock on.
- **Output** — Identify the programs' initial output file handle.
- **ParentDir** — Obtain the parent dir for a directory or file lock.
- **ParentOfFH** (V36) — returns a lock on the parent directory of a file.
- **ParsePattern** (V36) — Create a tokenized string for MatchPattern().
- **ParsePatternNoCase** (V37) — Create a tokenized string for
- **PathPart** (V36) — Returns a pointer to the end of the next-to-last
- **Printf** (V36) — format and print string. (buffered)
- **PrintFault** (V36) — Prints the text associated for a DOS error code.
- **ProcessScan** — Low level routine to scan through the DOS process list.
- **PutStr** (V36) — Writes a string to the default output. (buffered)
- **Read** — -- Low level routine to read data from a file. (unbuffered)
- **ReadArgs** (V36) — 
- **ReadSoftLink** (V36) — Read the target string for a filesystem soft link. (V36)
- **Relabel** (V36) — Change the volume name of a mounted device.
- **ReleaseConsoleData** — Releases the data obtained by ObtainConsoleData()
- **ReleaseDirContext** — Releases a context and data for ExamineDir(),
- **RemAssignList** (V36) — Remove an entry from a multi-assign.
- **RemDosEntry** (V36) — Removes a Dos List entry from its list.
- **RemSegment** (V36) — 
- **Rename** — Rename a file, directory or symbolic link.
- **RenameDosEntry** — Renames a DosList node. (V51.13)
- **ReplyPkt** (V36) — Low level function to reply to a dospacket.
- **ResolvePath** — Internal DOS library path resolver.  (V53.137)
- **RunCommand** (V36) — Runs a program using the current process.
- **SameDevice** (V37) — Are two locks on partitions of the same device?
- **SameFH** — Returns whether two filehandles are on the same file.(V53.71
- **SameLock** (V36) — Returns whether two locks are on the same object.
- **ScanVars** — Scan through global and/or local Vars.  (V50.64)
- **SelectInput** (V36) — Select a filehandle as the default input stream.
- **SelectOutput** (V36) — Select a filehandle as the default output stream.
- **SendPkt** (V36) — Low level function to send a dospacket to a handler.
- **Serialize** — Serializes the current filesystem volume. (V53.60)
- **SerializePort** — Serializes the current filesystem volume. (V53.88)
- **SetArgStr** (V36) — Sets the argument string for the current process.
- **SetCliCurrentDirName** (V36) — Sets the directory name in the attached
- **SetCliProgramName** (V36) — Sets the name of the CLI program being run,
- **SetCliPrompt** (V36) — Sets the prompt string in the CLI structure.
- **SetComment** — Changes a comment string on a filesystem object.
- **SetConsolePort** (V36) — Sets the default console for the process.
- **SetCurrentDir** — Make a directory lock the current directory.
- **SetDate** (V36) — Sets the modification date for a file or directory.
- **SetFileHandleAttr** — Change attributes of a buffered FileHandle.
- **SetFileSysPort** (V36) — Sets the current filesystem for the process.
- **SetIoErr** (V36) — Sets the value returned by IoErr().
- **SetMode** (V36) — 
- **SetOwnerInfo** — Set owner / group information for an object. (V52.18)
- **SetProgramDir** (V36) — Sets the directory returned by GetProgramDir.
- **SetProtection** — Set protection for a file or directory
- **SetVar** (V36) — Sets a local or global environment variable.
- **SplitName** (V36) — Splits out a component of a pathname into a buffer.
- **StartNotify** (V36) — Starts notification on a file or directory.
- **StrToDate** (V36) — Converts a string to a DateStamp.
- **StrToLong** (V36) — Converts an ASCII decimal string to an int32 value.
- **SystemTagList** (V36) — Have a shell execute a command line.
- **TimedDosRequester** — EasyRequest() style function via DOS. (V51.12)
- **UnGetC** (V36) — Makes a char available for reading again. (buffered)
- **UnLoadSeg** — Unloads a SegList or PseudoSegList.
- **UnLock** — Unlock a directory or file.
- **UnLockDosList** (V36) — Unlocks the Dos List
- **UnLockRecord** — Unlock a locked record.
- **UnLockRecords** (V36) — Unlock a list of records.
- **VFPrintf** (V36) — format and print a string to a file. (buffered)
- **VPrintf** (V36) — format and print string. (buffered)
- **WaitForChar** — Determine if chars arrive within a time limit.
- **WaitPkt** (V36) — Low level function to wait for a DosPacket to arrive.
- **Write** — Low level routine to write bytes of data to a file. (unbuffe
- **WriteChars** (V36) — Writes bytes to the default output. (buffered)
- **WriteProtectVolume** — Sets write protection status of a volume (V51.100)
- **WriteProtectVolumePort** — Sets write protection status of a volume

## Functions

### dos.library/AddBuffers (V36)

**Manually changes the number of filesystem buffers.**

**Synopsis:**
```c
int32 total_number = AddBuffers(CONST_STRPTR handler, int32 number);
```

**Description:**
Adds buffers to a handler.  Note that 'number' may be negative.
The amount of memory used per buffer, and any limits on the number of
buffers, are dependant on the handler in question.

**Inputs:**
handler      - STRPTR; Pointer to a nul-terminated string.
        (See GetDeviceProcFlags() for details about this.)

number       - Number of buffers to add.  May be negative or zero.

**Result:**
total_number - Total number of buffers used by the handler,
        or 0 for failure.

**Notes:**
This function is NOT task callable.
Supplying a 'number' argument of zero allows this function to report
the current number of buffers without changing them.

**Bugs:**
The V36 ROM filesystem (FFS/OFS) doesn't return the right number of
buffers unless preceded by an AddBuffers(fs,-1) 
(in-use buffers aren't counted).  This is fixed in V37.

Practically no handler implements this feature as documented in the
older dos.library documentation, which required that the return code
would indicate success and the total number of buffers should be
returned via IoErr(). The canonical behaviour is now to return the
total number of buffers, and 0 for failure.

No newer filesystems support this function, the optimal buffer size
is now determined automatically and/or dynamically by the respective
filesystem.  Stream handlers may still use this for buffer control,
but don't depend on it.

**See also:** IoErr(), GetDeviceProcFlags().

---

### dos.library/AddDosEntry (V36)

**Add a Dos List entry to the lists.**

**Synopsis:**
```c
int32 success = AddDosEntry(struct DosList *dlist);
```

**Description:**
Adds a device, volume or assign to the Dos device list.  
This function will fail if it conflicts with any existing entry.

The canonical case-insensitive name conflict rules for adding nodes are;
    Non VOLUMES conflict with everything.
    VOLUMES will conflict with VOLUMES if datestamps are also identical.
  
WARNING: The dos list does NOT have to be locked by you to call this,
it is exclusively locked internally when 'dlist' is added,
however, do not access 'dlist' after it is added unless you have
locked the Dos device list yourself.

An additional note concerning calling this from within a handler:
in order to avoid deadlocks, your handler must either be multi-
threaded, or it must attempt to lock the list before calling this
function.  The code should look like this:

if( IDOS->AttemptLockDosList(LDF_ALL|LDF_WRITE) )
{
	rc = IDOS->AddDosEntry(...);
	IDOS->UnLockDosList(LDF_ALL|LDF_WRITE);
}

See the LockDosList() documentation for information on this
subject.

If AttemptLockDosList() fails (i.e. it's locked already), check for
messages at your filesystem port (don't wait!) and try the
AttemptLockDosList() again.

Better still, to avoid all of the above pitfalls, just use the 
new V51 function; NonBlockingModifyDosEntry().

**Inputs:**
dlist   - Device list entry to be added.

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
From V50, supplying a NULL 'dlist' will result in failure,
also, IoErr() will be set to ERROR_REQUIRED_ARG_MISSING.

**See also:** RemDosEntry(), FindDosEntry(), NextDosEntry(), LockDosList(),
MakeDosEntry(), FreeDosEntry(), AttemptLockDosList(),
NonBlockingModifyDosEntry().

---

### dos.library/AddPart (V36)

**Appends a file/dir to the end of a path**

**Synopsis:**
```c
int32 success = AddPart( STRPTR dest_dirname, 
                  CONST_STRPTR filename,
                  uint32 size );
```

**Description:**
This function adds a file, directory, or subpath name to a directory
path name taking into account any required separator characters.  
If filename is a fully-qualified path it will totally replace the 
current value of dirname.

**Inputs:**
dest_dirname - the path to add a file/directory name to. (destination)

filename - the filename or directory name to add.  May be a relative
    pathname from the current directory (example: foo/bar).
    Can deal with leading '/'(s), indicating one directory up
    per '/', or with a ':', indicating it's relative to the
    root of the appropriate volume.

size     - size in bytes of the space allocated for dirname.  
    Must be greater than 0.

**Result:**
success - non-zero for success, FALSE if buffer would have overflown.
   If an overflow would have occured, dest_dirname will not be
   changed.

**Notes:**
From V50 this is task callable.

**Bugs:**
Does not check if a subpath is legal (i.e. does not check for ':'s) 
and does not handle leading '/'s in 2.0 through 2.02 (V36).  
V37 fixes this, allowing filename to be any path, including absolute.

**See also:** Filepart(), PathPart()

---

### dos.library/AddSegment (V36)

**Synopsis:**
```c
int32 success = AddSegment(CONST_STRPTR name, BPTR seglist, int32 type);
```

**Description:**
Adds an entry to the Dos resident list, with the specified Seglist
and type (stored in seg_UC - normally should start at 0).

Do NOT build DosResidentSeg structures yourself!

   V51 LOCKING 
From V51+ this function automatically WRITE locks the list by calling
ObtainSemaphore() / ReleaseSemaphore() with the public list Semaphore.
Do NOT attempt to employ a READ (shared) semaphore lock on the list
at the same time as you call this function, otherwise it will deadlock.

Obtain the semaphore from the public semaphore list by calling;
    drsem = IExec->FindSemaphore("DosResident");
The semaphore pointer may be cached for the duration of the task.   

For all WRITE operations, call;  ObtainSemaphore(drsem);
The above call must be matched with a ReleaseSemaphore();
(Also see; FindSegment() documentation)

**Inputs:**
name    - name for the segment.
seglist - BPTR to the seglist to add.
type    - initial usecount, normally 0.

**Result:**
success - boolean; (zero or non-zero), 0 for failure.

**Notes:**
From V51, this is just a stub that calls AddSegmentTagList().

**See also:** FindSegment(), RemSegment(), LoadSeg(), AddSegmentTagList()

---

### dos.library/AllocDosObject (V36)

**Creates a dos object**

**Synopsis:**
```c
APTR ptr = AllocDosObject(uint32 obj, const struct TagItem *tags);
APTR ptr = AllocDosObjectTagList(uint32 obj,const struct TagItem *tags);

APTR ptr = AllocDosObjectTags(uint32 obj, uint32 Tag1, ...);
```

**Description:**
Create one of several dos objects in shared memory, initialises it and
returns it to you.

This function may be called by a task for all object types and tags
defined in the dostags.h include.  Any future object types or tags that
cannot be used from a task will be documented below.

**Inputs:**
GLOBAL TAGS - The following two GLOBAL tags will directly affect the
   amount of memory allocated for all types of DOS_xxxx data structures.
   These may be used in conjunction with other tags specified below.

   ADO_Size (uint32) -- This tag is used to specify the absolute size of
      any larger 'custom' style structure definition the caller may be
      using, specifying a size less than that of the public structure
      definition will be ignored, therefore you are guaranteed that the
      minimum size that can be obtained here, will be the sizeof() the
      structure type specified. (V51)

   ADO_AddedSize (uint32) -- This tag is used to specify any additional
      size you need for the structure specified, this value is always
      added to the normal amount allocated for the standard DOS struct
      definition specified.(V50)  (This is also called ADO_Strlen)

                          ----

   DOS_FREADLINEDATA - These tags are for the FReadLineData structure.

   ADO_TermChar (int32) -- This is the ascii value (0-255) used to
      specify a different line terminator character than the default
      character '\n' which will be employed if no other value is
      supplied.
      You may also specify a -1L to cause read termination to occur
      only when EOF (end of file) is reached.

   ADO_TermCharStr (STRPTR) -- This is an optional NUL-terminated ascii
      string used to specify any additional termination character/s
      to terminate on, when more than one is needed.
      For example, this can sometimes be required when reading from
      a source that uses both '\n' and '\r' to terminate lines.
      For this, you would supply the string; "\n\r" to this tag.
      (Default NULL)

   ADO_Mask (uint32) -- This tag is used to specify the signal mask to
      break on,  See: <dos/dos.h> for the flags: SIGBREAKF_xxxxx  (V51)

                          ----

   DOS_ANCHORPATH : The following tags are for the AnchorPath structure.

   ADO_Strlen (uint32) -- This is required to specify the size of,
      and initialise the AnchorPath->ap_Buffer area.
      The size of the additional buffer space is stored in the field
      AnchorPath->ap_Strlen.  The AnchorPath allocated in this manner
      is ready to be used with with MatchFirst()/MatchNext().
      You may want to initialize the AnchorPath->ap_Flags and also
      AnchorPath->ap_BreakBits fields first, though.
      Please use the following two tags:  ADO_Flags and ADO_Mask. (V50)

   ADO_Flags (uint32) -- This is used to specify the value to place in
      the an->ap_Flags field before calling MatchFirst.
      See: <dos/anchorpath.h> for the flags: APF_xxxxx  (V50)

   ADO_Mask (uint32) -- This tag is used to specify the value to place
      in the an->ap_BreakBits field before calling MatchFirst.
      See: <dos/dos.h> for the flags: SIGBREAKF_xxxxx   (V50)

                          ----

   DOS_NOTIFYREQUEST - The following are for notify requests.
   NB: From V50+, DO NOT use this for ENV/ENVARC: global variables,
it may cease to function in the near future.
The environmental variables have their own dedicated
notification function; IDOS->NotifyVar(), please use it.

   ADO_NotifyName (STRPTR) -- Name of the volume, directory or file
      to receive notifications for. This is a mandatory parameter
      for DOS_NOTIFYREQUEST.
      NB: The name buffer MUST remain persistent for the life of
   the notify request. (it is not copied.)   (V51)

   ADO_NotifyMethod (int32) -- The notification method to be used,
      which must be one of NRF_SEND_MESSAGE, NRF_SEND_SIGNAL or
      NRF_CALL_HOOK.
      This is a mandatory parameter for DOS_NOTIFYREQUEST (V51).

   ADO_DOSMethodOnly (BOOL) -- Force the notify request to be serviced
      by the DOS notification routines instead of the filesystem.
      Defaults to FALSE.  (Only works with dos.library 52.33+)

   ADO_NotifyUserData (APTR) -- The user data value to be associated
      with the NotifyRequest. This parameter is optional for
      DOS_NOTIFYREQUEST and defaults to NULL (V51).

   ADO_NotifyPort (struct MsgPort *) -- The MsgPort to send notification
      messages to. This parameter is mandatory for DOS_NOTIFYREQUEST if
      the notification method NRF_SEND_MESSAGE was selected (V51).

   ADO_NotifyTask (struct Task *) -- The Task to send notification
      signals to. This parameter is mandatory for DOS_NOTIFYREQUEST if
      the notification method NRF_SEND_SIGNAL was selected (V51).

   ADO_NotifySignalNumber (uint8) -- The signal bit number used when
      sending notifications signals. This parameter is mandatory for
      DOS_NOTIFYREQUEST if the notification method NRF_SEND_SIGNAL was
      selected (V51).

   ADO_NotifyHook (struct Hook *) -- The Hook to invoke when sending
      notifications. This parameter is mandatory for DOS_NOTIFYREQUEST
      if the notification method NRF_CALL_HOOK was selected.
      NB: The hook structure MUST remain persistent for the life of
   the notify request. (it is not copied.)   (V51)

   ADO_NotifyWaitReply (BOOL) -- Selects whether or not new notification
      messages should be sent unless the last NotifyMessage has been
      replied. This parameter is optional for DOS_NOTIFYREQUEST and
      the notification method NRF_SEND_MESSAGE. Default=FALSE (V51).

   ADO_NotifyInitial (BOOL) -- Selects whether or not a notification
      should be sent immediately after it was requested. This parameter
      is optional for DOS_NOTIFYREQUEST and defaults to FALSE (V51).

                          ----

DOS_LOCK - The following are for Lock structures currently for use
      by filesystems, application programmers should not use these
      unless used with a filesystem, these allocations use a memory
      pool for the allocations and hence also employ automatic
      semaphore locking for the memory pool. (V51.30)

   ADO_DOSType (uint32) - The filesystems DOSType to be placed in the
      new Locks field;  lock->fl_DOSType. (V51)

   ADO_Size (uint32) -- The full size of any larger 'custom' style
      struct Lock definition the caller may be using, specifying
      a size less than the size of the public structure definition will
      be ignored, therefore you are guaranteed that the minimum size
      that can be obtained here, will be sizeof(struct Lock).
      AllocDosObject() will initialise the lock->fl_StructSize field
      with the actual size of the allocation.

                          ----

DOS_EXAMINEDATA - The following are for ExamineData structures, these
      tags are currently implemented for calling by filesystems and
      DOS handlers only, application programmers should not ever need
      to call this,  although the use of FreeDosObject() is how the
      applications dispose of these structures for ExamineObject() use.
      Allocation of the structures is for use by the DOS handlers
      and filesystems, or system components requiring an initialised
      ExamineData structure for emulation purposes.
      Allocations for use with ExamineDir() use the context memory pool
      supplied by the tag; ADO_ExamineDir_Context.
      Allocations for use with ExamineObject() do not use a context.
      (V51.104)

      The following structure fields will be initialised as shown,
      make no assumptions about the contents of the remaining fields.
   edat->StructSize  = the full size of the structure allocation.
   edat->FileSize    = -1LL;
   edat->NameSize    = MAX(1,ADO_ExamineData_NameSize)
   edat->CommentSize = MAX(1,ADO_ExamineData_CommentSize)
   edat->LinkSize    = MAX(1,ADO_ExamineData_LinkSize)
   edat->Type        = FSO_TYPE_INVALID; (added V53)

   ADO_ExamineData_NameSize (uint32) -- The full buffer size for the
      examinedata structures "Name" field, the size supplied here will
      also be placed in the "NameSize" field only if it is >1
      otherwise DOS will default to a value of 1 instead. (V51.104)

   ADO_ExamineData_CommentSize (uint32) -- The full buffer size for the
      examinedata structures "Comment" field, the size supplied here
      will also be placed in the "CommentSize" field only if it is >1
      otherwise DOS will default to a value of 1 instead. (V51.104)

   ADO_ExamineData_LinkSize (uint32) -- The full buffer size for the
      examinedata structures "Link" field, the size supplied here will
      also be placed in the "LinkSize" field only if it is >1
      otherwise DOS will default to a value of 1 instead. (V51.104)

   ADO_ExamineDir_Context (APTR) -- A pointer to the private 'context'
      (PRIVATE_ExamineDirContext *) that the memory pool allocations
      and internal locks should be bound to.
      Specify this tag for ExamineDir() only, ExamineObject() must not
      use this tag.  (V51.104)

                          ----

DOS_DOSLIST - The following are for struct DosList structures, these
      structures will also have the new V52 fields initialised for you.
      This type exists only from dos.library version V52.16+

   ADO_Size (uint32) -- The full size of any larger 'custom' style
      struct DosList definition the caller may be using, specifying
      a size less than the size of the public structure definition will
      be ignored, therefore you are guaranteed that the minimum size
      that can be obtained here, will be sizeof(struct DosList)
      The entire size of the allocation will be placed by DOS in the
      new dol_StructSize field to handle future planned features.

   ADO_Type (uint32) -- This is used to specify the type value to place
      in the doslist->dol_Type field.   Eg: DLT_xxxxxx
      See; dos/dosextens.h for available type definitions.

   ADO_Name (STRPTR) -- This is used to specify the name to copy into
      the doslist->dol_Name field.  This function will allocate the
      required space, copy the name and convert it to a BSTR,
      the name is limited to 255 bytes.
      From 53.109 this string will be automatically truncated at the
      first colon character if present.
      From 53.121 it is no longer possible to create nodes with names
      that conflict with the built-in DOS pseudo devices.
      From 54.17 any slash characters will be changed to backslashes.

                          ----

   DOS_VOLUMELIST - This tag is for a struct list with attached nodes for
      the names of the current VOLUMES, DEVICES or ASSIGNS.
      This function will scan the doslist and return a snapshot of the
      names of the items specified in the ADO_Type tag, (see below).

      The nodes within this list will have the ln_Name pointing to the
      (read only) nul-terminated name string, the ln_Type field will be
      initialised with the node type, this being a DLT_xxx value which
      is the same as in the dol_Type field of a struct DosList.

      The ln_Pri field is always set to zero when allocated,
      this field can be used for list sorting and is compatible with
      the IExec->Enqueue() and other exec list handling functions.

      If a handler message port is required for your application usage,
      call the IDOS->GetDeviceProc() function with the supplied name
      and don't forget to call IDOS->FreeDeviceProc() after use.
      NB: This requires the  ADO_AddColon,TRUE  tag option set.

      This list (including all nodes) is freed with FreeDosObject().
      The ADO_Size & ADO_AddedSize tags only apply to the nodes.

   ADO_Type (uint32) -- This bitmask is used to specify what nodes
      should be allocated and attached to the list, any of these
      flags can be ORed together to specify the items required;
   LDF_VOLUMES  (Defaults to LDF_VOLUMES if none specified)
   LDF_DEVICES
   LDF_ASSIGNS

   ADO_AddColon (BOOL) - This tag causes the name to have a colon
      character appended to the end of the name buffer.
      Defaults to FALSE.

**Result:**
ptr - pointer to the object or NULL on failure.

**Example:**
```c
struct Node *nd;
      struct List *list = IDOS->AllocDosObjectTags( DOS_VOLUMELIST,
                      ADO_Type,(LDF_VOLUMES|LDF_ASSIGNS),
                      ADO_AddColon,TRUE, TAG_END);
      if( list )
      {
   for( nd = IExec->GetHead(list); nd; nd = IExec->GetSucc(nd))
   {
       IDOS->Printf("%s\n",nd->ln_Name);

       // dp = IDOS->GetDeviceProc(nd->ln_Name,NULL);
       // ...
       // IDOS->FreeDeviceProc(dp);
   }
   IDOS->FreeDosObject(DOS_VOLUMELIST,list);
      }

                          ----

   DOS_FSVECTORPORT - This tag is for a struct FileSystemVectorPort
      that new style filesystems use for dos.library function vector
      calling method instead of using the old dospacket method.

      The struct FileSystemVectorPort message port signal task will
      be set to the process calling this function, therefore it must
      be called within the contect of the filesystem handler process.

   ADO_Vectors (struct FileSystemVectors *) -- This is the mandatory
      pointer to a pre-initialised struct FileSystemVectors that will
      be copied into the struct FileSystemVectorPort, details on how
      to initialise the FileSystemVector table can be found in the
      include file; dos/filehandler.h

   ADO_Name (STRPTR) -- This is used to specify the name for the
      message port of the vector-port, this string will be copied
      into a private buffer allocated by this function, the buffer
      will be pointed to via;  FSVP->MP.mp_Node.ln_Name.
      This should be the exact same string as the device node name.
      The name length is limited to 255 characters. (Default "\0")


                          ----
```

**Notes:**
[1] DOS_STDPKT does not return a pointer to the StandardPacket[64],
it does allocate an entire StandardPacket[64] structure, but it returns
a pointer to the struct DosPacket[64] part (in sp_Pkt) which is always
automatically initialised upon allocation.  To access the sp_Msg part
of the StandardPacket, use the pointer in the dp_Link field.
From DOS 51.62+ the size of the memory allocation is actually the
sizeof(struct StandardPacket64) to cater for both types of DosPackets
currently in use.

[2] From V50, DOS_CLI now allocates all BSTR buffers with a length of
258 bytes, the cli_FailLevel is set to 10, the cli_RunBackground will
be set to DOSTRUE.

**Bugs:**
Before V39, DOS_CLI should be used with care since FreeDosObject()
can't free it.

Before 53.139 DOS_VOLUMELIST did not see the ADO_Size or ADO_AddedSize
tags which resulted in the node sizes unable to be larger.

**See also:** FreeDosObject(), <dos/dostags.h>, <dos/dos.h>

---

### dos.library/AssignAdd (V36)

**Adds a lock to an assign for multi-directory assigns.**

**Synopsis:**
```c
int32 success = AssignAdd(CONST_STRPTR name, BPTR lock);
```

**Description:**
Adds a lock to an assign, making or appending to a multi-directory
assign.  Note that this only will succeed on an assign created with
AssignLock(), or an assign created with AssignLate() which has been
resolved (converted into a AssignLock()-assign).

NOTE: you should not use the lock in any way after making this call
successfully.   It becomes the part of the assign, and will be 
unlocked by the system when the assign is removed.  If you need to 
keep the lock, pass a lock from DupLock() to AssignLock().

**Inputs:**
name - Name of device to assign lock to (without trailing ':')

lock - Lock associated with the assigned name

**Result:**
success - Success/failure indicator.

**Notes:**
From V51, this is now only a backward compatibility stub that 
simply calls;  IDOS->AssignAddToList(name, lock, -1);

**Bugs:**
In the V40 documentation, it was stated that the doslist lock is 
not unlocked upon failure, however this was not actually the case.
The doslist write lock is always unlocked and continues to be so.

**See also:** Lock(), AssignLock(), AssignPath(), AssignLate(), DupLock(),
RemAssignList(), AssignAddToList().

---

### dos.library/AssignAddToList

**Adds a multi-assignment entry to an existing
            assignment, at a specific point in the list. (V51.43)**

**Synopsis:**
```c
int32 success = AssignAddToList(CONST_STRPTR name, BPTR lock, 
                         int32 position);
```

**Description:**
Adds a multi-assign entry to an assign at a specific position.

Before V54 this would only succeed on an assign created with the
AssignLock() function or an assign created with AssignLate() which has
been resolved and converted into a normal DLT_LOCK (AssignLock) type.

From V54 onwards, if the 'name' assignment is of type DLT_NONBINDING,
created by the AssignPath() function, then the lock will be used to
add a multi-directory entry of the same type.  Before V54 this would
simply fail with IoErr() returning ERROR_OBJECT_WRONG_TYPE.

You cannot use the lock in any way after making this call successfully,
as it becomes part of the assign, and will be released when required
by the operating system. If you need to keep the lock, duplicate it
with DupLock() and use the result for this function.
If this function fails, the lock is still valid and must be unlocked.

This function is an extended version of AssignAdd() which always adds
the assignment to the end of the list.   This new V51 function allows
you to specify where in the list you wish to add the new lock.

**Inputs:**
name     - Name of assignment to add the lock to (without trailing ':')

lock     - New lock to add to the existing assignment name.

position - (0 ... n)  place the lock in the assignment at the position
    specified by this argument.

    0  will position it as the assignments primary lock.
    The old lock will be moved as the first multi-assignment.
    Existing multi-assignment will move along one position.

    1  will position it as the first multi-assignment lock.
    Existing multi-assignment will move along one position.

    2  will position it as the second multi-assignment lock.
    Existing multi-assignment will move along one position.

    3 ... n

    A position greater than the number of entries, or any
    negative value will append the lock to the end of the list.

**Result:**
success - Success/failure indicator.  FALSE on failure.

**See also:** Lock(), AssignLock(), AssignPath(), AssignLate(), DupLock(),
RemAssignList(), AssignAdd().

---

### dos.library/AssignLate (V36)

**Creates a DLT_LATE type deferred assignment later.**

**Synopsis:**
```c
int32 success = AssignLate(CONST_STRPTR name, CONST_STRPTR path);
```

**Description:**
Sets up a assignment that is expanded upon the FIRST reference to the
name.  The path (a string) would be attached to the node.  When
the name is referenced (Open("FOO:xyzzy",...)), the string will be
used to determine where to set the assign to, and if the directory
can be locked, the assign will act from that point on as if it had
been created by AssignLock().

A major advantage is assigning things to unmounted volumes, which
will be requested upon access (useful in startup sequences).

This functions creates or deletes assignments of type; DLT_LATE.

**Inputs:**
name - Name of device to be assigned (without trailing ':')

path - Name of late assignment to be resolved on the first reference.
Values of NULL or ""  will remove the existing DLT_LATE assign.

**Result:**
success - Success/failure indicator of the operation

**Notes:**
From V50, 'name' is tested for NULL and now causes 
IoErr() to return ERROR_REQUIRED_ARG_MISSING if this occurs.

**Bugs:**
Before 53.24 a NULL or nul-string 'path' failed to remove and
deallocate the doslist DLT_LATE assignment for 'name'.

**See also:** Lock(), AssignAdd(), AssignPath(), AssignLock(),

---

### dos.library/AssignLock (V36)

**Creates a DLT_LOCK assignment to a locked object**

**Synopsis:**
```c
int32 success = AssignLock(CONST_STRPTR name, BPTR lock);
```

**Description:**
Sets up an assign of a name to a given lock. Passing ZERO for a lock 
cancels any outstanding assign to that name.  If an assign entry of
that name is already on the list, this routine replaces that entry.
If an entry is on the list that conflicts with the new assign, 
then a failure code is returned.

NOTE: you should not use the lock in any way after making this call
successfully.  It becomes the assign lock, and will be unlocked by the
system when the assign is removed.  If you need to keep the lock,
pass a lock from DupLock() to AssignLock().

**Inputs:**
name - Name of device to assign lock to (without trailing ':')

lock - Lock associated with the object name for the assign.

**Result:**
success - Success/failure indicator.  
   On failure, the lock is not unlocked.

**Notes:**
From V50, 'name' is tested for NULL and now causes IoErr() to
return ERROR_REQUIRED_ARG_MISSING if this occurs.

**See also:** Lock(), AssignAdd(), AssignPath(), AssignLate(), DupLock(),
RemAssignList()

---

### dos.library/AssignPath (V36)

**Creates a DLT_NONBINDING assignment to a path.**

**Synopsis:**
```c
int32 success = AssignPath(CONST_STRPTR name, CONST_STRPTR path);
```

**Description:**
Sets up an assignment that is expanded upon EACH reference to the name.
This is implemented through a private device list type.
The path (a string) would be attached to the node.  When the name is
referenced (Open("FOO:xyzzy"...), the string will be used to determine 
where to do the open.  No permanent lock will be part of it.
For example, you could AssignPath() "c2:" to "df2:c", and references
to "c2:" would go to "df2:c", even if you change disks.

The other major advantage is assigning things to unmounted volumes,
which will be requested upon access (useful in startup sequences).

This function creates or deletes assignments of type; DLT_NONBINDING

**Inputs:**
name - Name of device to be assigned (without trailing ':')

path - Path of the late assignment to be resolved at each reference.
Values of NULL or ""  will remove the DLT_NONBINDING assign.

**Result:**
success - Success/failure indicator of the operation

**Notes:**
From V50, 'name' is tested for NULL and now causes 
IoErr() to return ERROR_REQUIRED_ARG_MISSING if this occurs.

**Bugs:**
Before 53.24 a NULL or nul-string 'path' failed to remove and
deallocate the doslist DLT_NONBINDING assignment for 'name'.

**See also:** AssignAdd(), AssignLock(), AssignLate(), Open()

---

### dos.library/AttemptLockDosList (V36)

**Attempt to lock the Dos Lists for use**

**Synopsis:**
```c
struct DosList *dlist = AttemptLockDosList(uint32 flags);
```

**Description:**
Locks the dos device list in preparation to walk the list.  If the
list is 'busy' then this routine will return NULL.  See LockDosList()
for more information.

**Inputs:**
flags - Flags stating which types of nodes you want to lock. This
    must be a combination of the following:

 LDF_DEVICES -- File system devices, such as "DF0:".

 LDF_VOLUMES -- The names storage media bears, such as
     "Workbench:".

 LDF_ASSIGNS -- Names bound to directories and volumes,
     such as "LIBS:".

    Additionally, you must specify the manner in which you want
    to access the DosList. This must be one of the following:

 LDF_READ -- You will be looking at the DosList contents,
     but will not be modifying it. This implies shared
     access to the DosList.

 LDF_WRITE -- You will be removing, modifying or adding
     new entries to the DosList. This implies exclusive
     access.

    Note that you cannot combine the LDF_READ and LDF_WRITE
    flags with one another.

**Result:**
dlist - NULL or a special pointer to the beginning of the list. 
 That pointer is NOT a valid node and can be used only
 with NextDosEntry() and FindDosEntry()!

**Notes:**
See the LockDosList() documentation for more information.
This function IS callable from exec tasks.

**Bugs:**
In V36 through V39.23 dos, this would return NULL or 0x00000001 for
failure.  Fixed in V39.24 dos (after Kickstart 39.106), which means
that the bug is present in all Kickstart versions 2.0 through 3.0
(inclusively).

**See also:** LockDosList(), UnLockDosList(), NextDosEntry(), 
NonBlockingModifyDosEntry().

---

### dos.library/ChangeFilePosition

**Change the current cursor position for reading
               and writing.            (V51.64)**

**Synopsis:**
```c
int32 success = ChangeFilePosition(BPTR file,int64 position,int32 mode);
```

**Description:**
ChangeFilePosition() sets the read/write cursor for the file 'file' 
to the position 'position'. This position is used by both Read() and
Write() as a place to start reading or writing. 

'mode' can be OFFSET_BEGINNING, OFFSET_CURRENT or OFFSET_END. 
It is used to specify the relative start position. 
For example, 20 from current is a position 20 bytes forward 
from current, -20 is 20 bytes back from current.

To find out the current position, use GetFilePosition().
ChangeFilePosition() beyond the limits of the file will cause failure
and return a seek error.

**Inputs:**
file     - (BPTR)  BCPL pointer to a file handle
position - (int64) 64 bit position.
mode     - (int32) OFFSET_BEGINNING,OFFSET_CURRENT or OFFSET_END

**Result:**
success  - boolean; non zero for success, zero on failure.

**Notes:**
This function is NOT callable via the legacy 68K jumptable.
Legacy 68K callers will only be able to call the old Seek() function.

ChangeFilePosition() will provide a working fallback to Seek() if the 
new packet is unsupported by the filesystem, providing the 'position' 
parameter falls within signed 32 bit limits, (2 gig) otherwise an error
code will be returned; ERROR_OBJECT_TOO_LARGE.

Fallback function semantics may apply for unsupporting filesystems.

This function works for both buffered and unbuffered streams.

**See also:** GetFilePosition(), ChangeFileSize(), GetFileSize().

---

### dos.library/ChangeFileSize

**Change the size of a file.  (V51.64)**

**Synopsis:**
```c
int32 success = ChangeFileSize(BPTR fh, int64 size, int32 mode);
```

**Description:**
Changes the file size, truncating or extending as needed. 
If the file is extended, no values should be assumed for the new bytes.

If the new size would be before the filehandle's current position in
the file, the filehandle's position will be adjusted to point at the 
new end-of-file.

This function will return a fail code if the required new size cannot
be achieved,  the old SetFileSize() function could return any random
size if your request could not be satisfied rather than an error code,
this function does not do that.    If the file in question could not
be changed successfully, the file will be left as it was before.

Upon any failure, check the secondary error code with IoErr() to
determine exactly what went wrong.

The file cursor position shall not be changed unless the file is made
smaller than the current cursor position.

Do NOT count on any specific values to be in any extended area.

**Inputs:**
fh    - BCPL pointer to a filehandle to be truncated/extended.
size  - 64 bit integer size from position determined by mode.
mode  - 32 bit integer OFFSET_BEGINNING,OFFSET_CURRENT,or OFFSET_END

**Result:**
success - boolean; non zero for success, zero on failure.

**Notes:**
Filesystems shall not allow the size of a file to be changed if there
is more than one filehandle open on the same file and the size change
would result in any of the other file position pointers being left
pointing past the new end-of-file.
  
Always check the failure error code with IoErr().

This function works for both buffered and unbuffered streams.

**See also:** ChangeFilePosition(), GetFilePosition(), GetFileSize().

---

### dos.library/ChangeMode (V36)

**Synopsis:**
```c
int32 success= ChangeMode(uint32 obj_type, BPTR object, uint32 newmode);
```

**Description:**
This allows you to attempt to change the mode in use by a lock or
filehandle.  For example, you could attempt to turn a shared lock
into an exclusive lock.   The handler may well reject this request
if there are already multiple users of the object.

Attempting to change a directory lock to an exclusive lock will cause
failure from V53 onwards.

Attempting to change an existing objects mode to the same mode, 
is effectively a no-op, but will not cause failure from this function.

Warning:   If 'object' does not correspond with 'obj_type, you are
    very likely to crash the machine.

**Inputs:**
obj_type - Either CHANGE_FH or CHANGE_LOCK
object   - A BCPL pointer to a lock or a filehandle. (ZERO is safe)
newmode  - The new mode you want the object to become.
    This must be either SHARED_LOCK or EXCLUSIVE_LOCK.

**Result:**
success  - boolean; (zero or non-zero),  zero for failure.
    On failure, call IoErr() for more information.

**Notes:**
The 'newmode' parameter is independent of the 'obj_type'
parameter. That is, even for CHANGE_FH you still have to
use either SHARED_LOCK or EXCLUSIVE_LOCK, regardless of the
fact that you want the access mode of a file handle to be
changed rather than the access mode of a file lock.

Passing a ZERO 'object' pointer is safe, just returns a failure code.

**Bugs:**
Did not work in 2.02 or before (V36).  Works in V37.  
In the earlier versions, it can crash the machine.

Prior to V50, it was unsafe to use ChangeMode() on a "NIL":
file handle.

Some file systems, notably the ram-handler prior to version 50,
incorrectly assumed that for CHANGE_FH you had to use MODE_OLDFILE,
MODE_NEWFILE or MODE_READWRITE rather than SHARED_LOCK or
EXCLUSIVE_LOCK. Their responses to ChangeMode() are largely
undefined.

**See also:** Lock(), Open(), DupFileHandle(), DupLock()

---

### dos.library/CheckSignal (V36)

**Checks for break signals.**

**Synopsis:**
```c
uint32 signals = CheckSignal(uint32 mask);
```

**Description:**
This function checks to see if any signals specified in the mask 
have been set and if so, returns them.  Otherwise it returns FALSE.
All signals specified in mask will be cleared.

**Inputs:**
mask    - Signals to check for. The following are defined
   in <dos/dos.h>:

   SIGBREAKF_CTRL_C
   SIGBREAKF_CTRL_D
   SIGBREAKF_CTRL_E
   SIGBREAKF_CTRL_F

**Result:**
signals - Signals specified in mask that were set, or FALSE.

**Example:**
```c
if( IDOS->CheckSignal(SIGBREAKF_CTRL_C) )
{
    goto cleanup;
}


while( ! IDOS->CheckSignal(SIGBREAKF_CTRL_C) )
{
    do_something();
}
```

**Notes:**
This function is directly equivalent to; 
   signals = mask & IExec->SetSignal(0,mask); 

This function is also callable from a task.

**See also:** <dos/dos.h>

---

### dos.library/Cli (V36)

**Returns a pointer to the CLI structure of the process**

**Synopsis:**
```c
struct CommandLineInterface *cli_ptr = Cli(void);
```

**Description:**
Returns a pointer to the CLI structure of the current process, 
or NULL if the process has no CLI structure.

**Result:**
cli_ptr - pointer to the CLI structure, or NULL.

**Notes:**
This function is NOT callable from a task.

---

### dos.library/CliInitNewcli

**Set up a process to be a shell from initial packet**

**Synopsis:**
```c
int32 flags = CliInitNewcli( struct DosPacket *packet );
```

**Description:**
This function initializes a process and CLI structure for a new
shell, from parameters in an initial packet passed by the system
(NewShell or NewCLI, etc).  The format of the data in the packet
is purposely not defined.  The setup includes all the normal fields
in the structures that are required for proper operation (current
directory, paths, input streams, etc).

It returns a set of flags containing information about what type
of shell invocation this is.

Definitions for the values of 'flags':
	Bit 31     Set to indicate flags are valid
	Bit  3     Set to indicate asynch system call
	Bit  2     Set if this is a System() call
	Bit  1     Set if user provided input stream
	Bit  0     Set if RUN provided output stream

If Bit 31 is 0, then you must check IoErr() to determine if an error
occurred.  If IoErr() returns a pointer to your process, there has
been an error, and you should clean up and exit.  The packet will
have already been returned by CliInitNewcli().  If it isn't a pointer
to your process and Bit 31 is 0, reply the packet immediately.
(Note: this is different from what you do for CliInitRun().)

This function is very similar to CliInitRun().

**Inputs:**
packet - the initial packet sent to your process MsgPort

**Result:**
fn - flags.  On failure, a pointer to thistask in IoErr().

**See also:** CliInitRun(), ReplyPkt(), WaitPkt(), IoErr()

---

### dos.library/CliInitRun

**Set up a process to be a shell from initial packet**

**Synopsis:**
```c
int32 flags = CliInitRun( struct DosPacket *packet );
```

**Description:**
This function initializes a process and CLI structure for a new
shell, from parameters in an initial packet passed by the system
(Run, System(), Execute()).  The format of the data in the packet
is purposely not defined.  The setup includes all the normal fields
in the structures that are required for proper operation (current
directory, paths, input streams, etc).

It returns a set of flags containing information about what type
of shell invocation this is.

Definitions for the values of 'flags':
	Bit 31     Set to indicate flags are valid
	Bit  3     Set to indicate asynch system call
	Bit  2     Set if this is a System() call
	Bit  1     Set if user provided input stream
	Bit  0     Set if RUN provided output stream

If Bit 31 is 0, then you must check IoErr() to determine if an error
occurred.  If IoErr() returns a pointer to your process, there has
been an error, and you should clean up and exit.  
The packet will have already been returned by CliInitNewcli().
If it isn't a pointer to your process and Bit 31 is 0, you should
wait before replying the packet until after you've loaded the first
command (or when you exit).  
This helps avoid disk "gronking" with the Run command.
(Note: this is different from what you do for CliInitNewcli().)

If Bit 31 is set, then if Bit 3 is one, ReplyPkt() the packet
immediately (Asynch System()), otherwise wait until your shell exits
(Sync System(), Execute()).
(Note: this is different from what you do for CliInitNewcli().)

This function is very similar to CliInitNewcli().

**Inputs:**
packet - the initial packet sent to your process MsgPort

**Result:**
fn - flags.  On failure, a pointer to thistask in IoErr().

**See also:** CliInitNewcli(), ReplyPkt(), WaitPkt(), System(), Execute(), IoErr()

---

### dos.library/Close

**Close an open file.  (unbuffered)**

**Synopsis:**
```c
int32 success = Close( BPTR file );
```

**Description:**
The file specified by the file handle is closed. You must close all
files you explicitly opened, but you must not close inherited file
handles that are passed to you (each filehandle must be closed once
and ONLY once).  If Close() fails, the file handle is still
deallocated and should not be used.

For closing buffered file handles from FOpen(), FOpenFromLock(),...
you should use FClose() instead of Close(), even though the basic
functionality is the same, future features may cause implementation
difficulties or unnecessary system overhead by using the wrong function.

**Inputs:**
file - BCPL pointer to a file handle. ( NULL is safe, does nothing.)

**Result:**
success - boolean; (zero or non-zero value)
   Returns zero if Close() failed.  Note that it might fail
   depending on buffering and whatever IO must be done to
   close a file being written to.  
   NOTE: this return value did not exist before V36!

**Notes:**
Re: LockRecord(), LockRecords(), FreeRecord(), FreeRecords()

Please be advised that due to dependancies and idiosyncrasies of the
various filesystems that are available, the behaviour of Close() with
regard to freeing record locking is currently indeterminant.
You are therefore advised to FreeRecord/s() of any records that may 
have been locked by the application, BEFORE calling Close().
 
From V53+ the built-in dos.library record locking (only) will always
release all locked records for a given filehandle before closing.

**See also:** FClose(), FOpen(), Open(), OpenFromLock(), FOpenFromLock()

---

### dos.library/CompareDates (V36)

**Compares two datestamps.**

**Synopsis:**
```c
int32 result = CompareDates(const struct DateStamp *date1,
                     const struct DateStamp *date2);
```

**Description:**
Compares two datestamps for relative magnitide.  
<0 is returned if 'date1' is later than 'date2', 0 if they are equal,
or >0 if 'date2' is later than 'date1'.  
NOTE: this is NOT the same ordering as strcmp!

**Inputs:**
date1, date2 - DateStamps to compare

**Result:**
result -  <0, 0, or >0 based on comparison of two date stamps.

**Example:**
```c
/* This shows which results the comparison of different dates
   will produce. This program will produce the following
   output:

CompareDates(older,newer): result > 0
CompareDates(newer,older): result < 0

   This is exactly the opposite return value of comparison
   routines such as memcmp() or strcmp(). */

struct DateStamp older;
struct DateStamp newer;
int32 result;

/* Get the current time, then make a newer date from it. */
IDOS->DateStamp(&older);
newer = older;
newer.ds_Days++;

/* Now show the results */
result = IDOS->CompareDates(&older,&newer);
if(result < 0)
    IDOS->PutStr("CompareDates(older,newer): result < 0\n");
else if (result > 0)
    IDOS->PutStr("CompareDates(older,newer): result > 0\n");
else
    IDOS->PutStr("CompareDates(older,newer): result = 0\n");

result = IDOS->CompareDates(&newer,&older);
if(result < 0)
    IDOS->PutStr("CompareDates(newer,older): result < 0\n");
else if (result > 0)
    IDOS->PutStr("CompareDates(newer,older): result > 0\n");
else
    IDOS->PutStr("CompareDates(newer,older): result = 0\n");
```

**Notes:**
This function is callable from tasks.

From 51.98 this function will return 0x80000000 if either the 'date1'
or 'date2' parameter is NULL, previously this situation was undefined
but would have caused an illegal memory access exception.

**See also:** DateStamp(), DateToStr(), StrToDate()

---

### dos.library/CopyStringBSTRToC

**Copy BCPL format string to 'C' format
              string (V51.61)**

**Synopsis:**
```c
int32 size = CopyStringBSTRToC(BSTR source, STRPTR destination, 
                uint32 destination_size);
```

**Description:**
CopyStringBSTRToC() converts the contents of a BCPL format string,
which begins with a byte containing the length of the string,
into a 'C' format string, which consists of a number of bytes
terminated by a NUL. The resulting string is always properly
NUL-terminated and no more than 'destination_size' bytes will be
stored in the 'destination' string. This size limit covers all the
number of bytes to be copied, including the final NUL terminator.

**Inputs:**
source -- BPTR to a BCPL formatted string which should be copied
    to the 'destination' string buffer. This can be ZERO in which
    case an empty string is copied.

destination -- Pointer to a string which the contents of the
    'source' string are to be copied to. The destination pointer
    can be NULL in which case no data will be written; the number
    of bytes that would have been stored is still calculated, though.

destination_size -- Size of the 'destination' buffer.

**Result:**
size -- Total length of the string that would have been created
    by copying the 'source' to the 'destination' buffer, not
    including the terminating NUL byte.
    This can be larger than the 'destination_size' parameter, 
    which means that the copied string was truncated.

**Notes:**
The use of BCPL format strings is strongly discouraged. This
function is supplied solely to ease interoperability with legacy
dos.library data structures.

This function can be called from a task.

**See also:** CopyStringCToBSTR(), utility.library/Strlcpy(),
utility.library/VSNPrintf()

---

### dos.library/CopyStringCToBSTR

**Copy 'C' format string to NUL terminated BCPL
              format string (V51.61)**

**Synopsis:**
```c
int32 size = CopyStringCToBSTR(CONST_STRPTR source, BSTR destination,
                uint32 destination_size);
```

**Description:**
CopyStringCToBSTR() converts a 'C' format string, which consists of
a number of bytes terminated by a NUL, into a NUL-terminated
BCPL string, which begins with a byte containing the length of
the string, followed by the string and terminated by a NUL. Such a
NUL-terminated BCPL string can be up to 257 bytes in size,
which counts the size byte as well as the NUL terminator byte.

**Inputs:**
source -- STRPTR to a 'C' format string which should be copied
    to the 'destination' string buffer. This can be NULL in which
    case an empty string is copied.

destination -- BCPL Pointer to a buffer which the contents of the
    'source' string are to be copied to in BCPL format. 
    The destination pointer can be ZERO in which case no data will
    be written; the number of bytes that would have been stored
    is still calculated though. 
    Note that no more than 255 bytess will be stored in addition
    to the initial length byte and the final NUL byte which 
    terminates the string for easier interoperability with C strings.

destination_size -- Size of the 'destination' buffer. This must
    be greater or equal to 2, which accounts for the initial
    length byte and the final termination byte. If the buffer
    size is shorter, nothing will be copied.

**Result:**
size -- Total length of the string that would have been created
    by copying the 'source' to the 'destination' buffer, this does
    not including the terminating NUL byte. This can be larger
    than the 'destination_size' parameter, which means that the
    copied string was truncated.

**Notes:**
The resulting string is not a simple BCPL formated string, which
would consist of the initial length byte followed by a number of
bytes. The result is also NUL terminated, which is the preferred
form for BCPL strings in AmigaDOS, because they can be used more
easily with 'C' language constructs.

The use of BCPL format strings is strongly discouraged. This
function is supplied solely to ease interoperability with legacy
dos.library data structures.

This function can be called from a task.

**See also:** CopyStringBSTRToC(), utility.library/Strlcpy(),
utility.library/VSNPrintf()

---

### dos.library/CreateDir

**Create a new directory.**

**Synopsis:**
```c
BPTR lock = CreateDir( CONST_STRPTR name );
```

**Description:**
CreateDir creates a new directory with the specified name. 
An error is returned if it fails.  
Directories can only be created on devices which support them, 
e.g. disks.  

Before V53, CreateDir() returned an exclusive lock on the new
directory if it succeeded, it is now required that this be a
a shared lock.  Exclusive directory locks have been deprecated.
Only files may actually have exclusive locks.

It is your responsibility to UnLock() this directory lock.

**Inputs:**
name - (CONST_STRPTR) Pointer to a null-terminated string for 
 the directory name.
(See GetDeviceProcFlags() for details about this.)

**Result:**
lock - (BPTR) BCPL pointer to a shared lock or zero for failure.

**Notes:**
Attempting to create a directory with a trailing '/' in 'name'
will cause failure.  This is because (for example) the path
"foo:bar/baz" refers to the object "baz",  but "foo/bar/baz/"
refers to an object called "" in directory "baz",  which will
actually work for IDOS->Lock() because it sees "" as a synonym
for CURRDIR: but please don't pass trailing slashes to other
AmigaDOS functions, some functions like CreateDir() will quite
unsurprisingly completely fail to create a directory called "".

Pre-V53 packet based filesystems may try and return an exclusive
lock instead of a shared lock, however, dos.library 53.78+ now
changes the lock mode to a SHARED_LOCK regardless of the mode
the older filesystems returned.
 
If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

**See also:** CreateDirTree(), GetDeviceProcFlags()

---

### dos.library/CreateNewProc (V36)

**Create a new DOS process.**

**Synopsis:**
```c
struct Process *proc = CreateNewProc(const struct TagItem *tags);

struct Process *proc = CreateNewProcTagList(const struct TagItem *tags);

struct Process *proc = CreateNewProcTags(uint32 Tag1, ...);
```

**Description:**
This creates a new process according to the tags passed in.
See dos/dostags.h for the tags.

NB: Before proceeding any further, it is important to first understand
    that DOS processes are NOT exec tasks, they are a superset.

    You MUST NOT call the exec task termination functions when dealing
    with DOS processes in applications.  EG: DeleteTask() / RemTask().

    Attempts to do so will probably leave various resources allocated,
    like filesystem locks and file streams open and orphaned forever.
    So DON'T DO IT in any applications code.

    To exit a DOS process, just return() from your start function with
    a suitable return code, (RETURN_xxx) these are listed in dos/dos.h
    and should always be used regardless of how a process starts up.
    Simply treat your start function like a normal C subroutine.


For this function to be able to work, you must specify one of either
the 'NP_Seglist' or 'NP_Entry' tags, (or both).
'NP_Seglist' takes a seglist (as returned by LoadSeg or AllocSegList).
'NP_Entry' takes a function pointer to the routine to call.

There are many options, as you can see by examining <dos/dostags.h>.
The defaults are for a non-CLI process, with copies of your task priority,
pr_CurrentDir (used for "CURRDIR:"), pr_ProgramDir (used for "PROGDIR:"),
pr_ConsolePort (used for "CONSOLE:"), pr_WindowPtr, and local variables.

The input and output filehandles default to opens of "NIL:" if no
tags are supplied to indicate differently.

Minimum stack of 8K or whatever you have specified in DOS prefs,
and others as shown in <dos/dostags.h>.
This is a fairly reasonable default setting for creating threads,
though you may wish to modify it (for example, to give a descriptive
name to the process.)

CreateNewProc() is callable from a task, though any actions that
require doing Dos I/O (DupLock() of pr_CurrentDir, for example)
will not work and will simply not be called from a task context.

When the new process starts, an initial minimum stack frame is created
(ATM it is 8K) for it to begin execution, at which time it builds data
structures or performs other internal function calls,
also, if any of the following tags are used, NP_EntryCode, NP_FinalCode,
or NP_ExitCode, these will always run under this initial stack frame
so be conservative with any stack usage while inside these vectors.

Once the new process is ready, the user stack specified by NP_StackSize
is allocated by passing control to internalRunCommand() where the
application code specified by NP_SegList or NP_Entry is executed.

**Inputs:**
NP_Seglist (BPTR) -- Pointer to a segment list, as like that returned
    by LoadSeg() or AllocSegList().  The segment list will not be freed
    when the process exits unless you specifically request it via the
    use of 'NP_FreeSeglist, TRUE'.
    Your code may be invoked with certain parameters; see the
    NP_Entry documentation below for a description.


NP_FreeSeglist (int32; boolean) -- Indicate whether the segment list
    supplied via 'NP_Seglist' should be freed when the process exits.
    Defaults to FALSE.


NP_Entry (int32 (*)()) -- Address of a function at which the
    child process should start execution.

    This entry() function has the same prototype as the _start()
    function, it also expects a proper DOS returncode.
    See; dos/RunCommand() and include/dos/startup.h for further
    details of starting up a new DOS process.

    Prior to V50 the tags NP_Entry and NP_Seglist were mutually
    exclusive.  Starting with V50 you can combine both and use the
    'NP_FreeSeglist, TRUE' tag with them; the process will start
    executing at the function entry you specified with NP_Entry and
    the segment list specified by NP_Seglist will be freed on exit.

    Emulated 68K programs and PPC Native code will have their entry
    function called as;

    int32 rc = _start(STRPTR args, int32 length, APTR execbase);

    The parameters are:

args     --  Pointer to a NUL-terminated string or
             NULL if no arguments are provided.
             [ 68K register A0 ]

length   --  Length of the argument string,
             or 0 if no arguments are provided.
             [ 68K register D0 ]

execbase --  Pointer to struct ExecBase.
             [ 68K register A6 ]


NP_Child (int32; boolean) (V50) -- Identify this newly created
    process as a resource dependant child of the creating process.
    Default: FALSE

    Commencing with V51.71 of dos.library, the semantics of the DOS
    process cleanup function have been adjusted when using this tag.
    When a process is about to be deleted, and that process still has
    active dependant children, the process is not deleted immediately,
    instead, it is suspended, (possibly indefinately), until all its
    child processes have finally ended, the parent process then resumes
    to finish parent process termination.
    This guarantees that no process that was created as a child process
    is orphaned, *especially* when running in shared code space.

    NEWLIB NOTES:
 For programs using 'newlib.library', you must specify this tag
 as TRUE, if your child process is to share the parent process'
 newlib context information.
 Failing to specify this true tag for child processes that do not
 open their own newlib, will cause the child process to use a
 default global fallback context for children entering at main().

 Nevertheless, you should still add this true tag in any case,
 because without it, the child process will not use the parents
 stream descriptors for; stdin/stdout/stderr, and for memory
 allocated with malloc(), calloc(), etc... can't be freed
 automatically on exit.

 Only with this tag set true, will the C library cleanup code
 execute when the parent returns from main(), frees all unfreed
 C library memory allocations and closes all still open streams.
 There are still some functions which can't work at all,
 or without some limits, and you never should rely on any
 C library functions, except for the simple <string.h> ones
 like memcpy(), strlcpy(), strlen(), strcmp(), etc.


    From V53.9 this tag also causes "baserel" CPU registers to be copied
    to the child process by exec via the internal AddTask() call.

    Use this tag from V50 onwards, where the child process is dependant
    upon the parent process, especially when using shared code space.

    Use this tag carefully, always remembering that a parent process
    CAN NEVER END until all children have done so first.

    If your child process is designed to persist after the parent exits,
    then DO NOT create persistent child processes that use this tag.


NP_UserData (int32) (V50) -- A value that is placed in the new
    process' task structure, in the field: process->pr_Task.tc_UserData.
    This may be any arbitrary user value.   Defaults to 0.


NP_Input (BPTR) -- Default input stream for the child process.
    Defaults to; Open("NIL:",MODE_OLDFILE) if you do not specify a tag.
    DO NOT specify 0 for this tag unless you really intend your new
    process to have an Input() stream that returns 0.
    Note that a zero Input() stops ReadArgs() etc.. working.
    DO NOT use this tag for anything but a FileHandle BPTR.


NP_CloseInput (int32; boolean) -- Whether the default input
    stream should be closed upon exit. Defaults to TRUE.


NP_Output (BPTR) -- Default output stream for the child process.
    Defaults to; Open("NIL:",MODE_OLDFILE) if you do not specify a tag.
    DO NOT use this tag for anything but a FileHandle BPTR.


NP_CloseOutput (int32; boolean) -- Whether the default output
    stream should be closed upon exit. Defaults to TRUE.


NP_Error (BPTR) -- Default error output stream for the child
    process. Defaults to a ZERO stream for compatibility reasons.
    DO NOT use this tag for anything but a FileHandle BPTR.


NP_CloseError (int32; boolean) -- Whether the default error
    output stream should be closed upon exit. Defaults to FALSE.
    (Note: Default is FALSE as DOS does not open this stream. )


NP_CurrentDir (BPTR) -- Current directory of the child process.
    (This is where "CURRDIR:" will point to).
    Do not pass in a tag value of zero, unless you really intend any
    access to "CURRDIR:" to fail for this new process.
    Defaults to a copy [ DupLock() ] of the parents current dir only
    if you DO NOT specify this tag, and only if parent is a process.
	DOS will always UnLock() this when the process exits, if the
    pr_Flags; PRF_FREECURRDIR is still set.  (Default)
    DO NOT use this tag for anything but a Lock BPTR.


NP_ProgramDir (BPTR) -- Identifies the 'home program directory' of the
    child process. (This is where "PROGDIR:" will point to).
    Defaults to a copy [ DupLock() ] of the parents home dir only if
    you DO NOT specify this tag, and only if the parent is a process.
    DOS will always UnLock() this when the process exits.
    Do not pass in a tag value of zero, unless you really intend any
    access relative to "PROGDIR:" to fail for this new process.
    DO NOT use this tag for anything but a Lock BPTR.


NP_StackSize (int32) -- The stack size the child process should use.
    Minimum values less that what DOS Prefs specifies are ignored (V50).
    Default; Inherit size from parent task when tag is not specified.
    Note; Please also refer to RunCommand() documentation relating to
 the use of "$STACK;" cookies in the program code seglist to
 specify a custom default minimum stack size.


NP_LockStack (int32; boolean) -- Locks the stack for the new process.
    Setting this tag to TRUE will cause exec to prevent the stack
    being swapped out by the pager.    Defaults to FALSE.  (V52.10)
    NB: Currently, all legacy 68K code that is being run will force
 stack locking on, regardless of this tag specification.


NP_Name (STRPTR) -- Name of the child process. Defaults to
    "New Process" if no tag is specified, or a NULL tag is supplied.
    There is no maximum length limit imposed on this string.
    The child process' task structure; task->tc_Node.ln_Name
    will point to the buffer to where this string is copied.
    The exec function FindTask() searches on this string.

    From V50, the internal copy of your NP_Name string is added to
    the task memory list and will therefore be freed automatically
    when the process eventually exits.


NP_Priority (int8; -128 .. 127) -- Task priority of the child process.
    Defaults to the same as the parent, if this tag is not supplied.


NP_ConsolePort (struct MsgPort *) -- Address of the console handler
    message port the child process should use. Defaults to the same
    as the parent if the parent is a process, otherwise it will be 0.
    This tag will set the handler for actions with  "CONSOLE:".


NP_WindowPtr (APTR) -- Indicate where dos.library requesters should
    be displayed for the child process (on the Workbench screen,
    a custom screen or not at all).
    Defaults to the same value as the parent process only if it is
    a value of 0 or -1, and if the parent is a process, otherwise 0.

    EG; A value of 0, indicates requesters should be displayed on
 the default public screen.  (Usually WorkBench)
 A value of -1 indicates that no requesters shall be shown.
 Otherwise, a pointer to an open intuition window that all
 requesters should be opened on.


NP_CopyVars (int32; boolean) -- Indicate whether the local
    environmental variable list associated with the parent should
    be copied for the child process. Defaults to TRUE.


NP_LocalVars (STRPTR *) -- An array of string pointers, to represent
    the content of the local environmental variable list. (V51.70)

    The array shall be arranged in pairs, to contain the name of the
    local variable to add, followed by that variables value.
    The variable name and the value are both nul-terminated strings.
    The pairing continues until you have specified all your required
    variables.  The array MUST then have at least one NULL entry
    at the end for termination.

    Copies of these LV_VAR variables will be added to the variable list
    for the new process until the mandatory NULL pointer is encountered,
    which is used to indicate the end of your array pairs.

    EG; STRPTR vars[7];

 vars[0]="Varname1", vars[1]="value1",
 vars[2]="Varname2", vars[3]="value2",
 vars[4]="Varname3", vars[5]="value3",
 vars[6]=NULL;       /* <- mandatory array terminator. */

 IDOS->CreateNewProcTags(NP_LocalVars, vars, ...);

    Variables specified with this tag are copied to the tail of the
    existing list, which may also be empty if (NP_CopyVars,FALSE) was
    specified, (or the parent was a task)  otherwise the list will
    contain a copy of the parent process' variables, with these new
    entries copied to the end of the local variable list.
    Defaults to NULL.


NP_LocalAlias (STRPTR *) -- An array of string pointers, to represent
    the content of the local alias list. (added V52.5)

    The array shall be arranged in pairs, to contain the name of the
    local alias to add, followed by that alias' value.
    The alias name and the value are both nul-terminated strings.
    The pairing continues until you have specified all your required
    aliases.  The array MUST then have at least one NULL entry
    at the end for termination.

    Copies of these LV_ALIAS entries will be added to the local list
    for the new process until the mandatory NULL pointer is encountered,
    which is used to indicate the end of your array pairs.

    EG; STRPTR alias[7];

 alias[0]="Aliasname1", alias[1]="value1",
 alias[2]="Aliasname2", alias[3]="value2",
 alias[4]="Aliasname3", alias[5]="value3",
 alias[6]=NULL;       /* <- mandatory array terminator. */

 IDOS->CreateNewProcTags(NP_LocalAlias, alias, ...);

    Aliases specified with this tag are copied to the tail of the
    existing list, which may also be empty if (NP_CopyVars,FALSE) was
    specified, (or the parent was a task)  otherwise the list will
    contain a copy of the parent process' aliases & variables, with
    these new entries copied to the end of the local list. (after vars)
    Defaults to NULL.


NP_Cli (int32; boolean) -- Indicate whether a CLI data structure
    should be allocated and attached to the child process structure.
    Defaults to FALSE.

    A new cli structure will have the following initialisations;

    1) The cli_FailLevel will inherited the parent cli value, else 10.
    2) The cli_RunBackground will be set to FALSE.
    3) The cli_Prompt will inherit a copy of the parents prompt if it
has one, otherwise it will install the default;  "\4%N> "
    4) The cli_CurrentDirName will be initialised with the name of the
directory specified by the tag; NP_CurrentDir, otherwise the
name of the parents current directory will be used, else "\0".
    5) The cli_PathList will be initialised from the tag; NP_Path
if specified, otherwise a copy of the parents pathlist will
be used if the parent has a cli, else zero if the parent was
a task or a process without a cli attached.

    Remember, a process with a CLI is not necessarily a "CLI process".
    A CLI is sometimes added to a process to prevent programs started
    from it [ See; RunCommand() ] believing they are being run from
    Workbench, the startup code of external programs check for a Cli()
    to determine whether they should WaitPort() for a Workbench startup
    message, or not.   See include/dos/startup.h for example code.


NP_CommandName (STRPTR) -- This will be set as the CLI command name
    for the child process if the 'NP_Cli, TRUE' tag has been used.


NP_Path (BPTR) -- BCPL pointer to a 'struct PathNode' which should
    be attached to the child process' CLI structure->cli_PathList.
    NB: This works only if the 'NP_Cli, TRUE' tag is set.

    Note: The supplied pathlist is used as is and not duplicated,
    it will be freed automatically when the process exits, but must be
    freed manually if the process could not be created for some reason.

    If you do NOT specify this tag, and, if the parent process has a
    CLI structure attached to it, then the new process' CLI struct
    will receive a duplicate of the parents pathlist, which will also
    be freed automatically on exit. (and if process creation fails.)


NP_Arguments (STRPTR) -- Argument string to be copied for the child
    process (string pointer in 68000 CPU register A0, string length
    in 68000 register D0). Defaults to string pointer == NULL and
    string length == 0. Note: do not use with NP_Input == NULL!
    The tag did not work prior to dos.library V37.

    The argument string copy can also be accessed from within the
    child process, by calling the GetArgStr() function or via the
    argument supplied to the _start() function of the executable.
    See; include/dos/startup.h  for more info.


NP_EntryCode (VOID (*)(int32)) --  (V51.72)
    Pointer to a function called when the child process starts up.
    The function will be called once by the new process, just before
    the actual program code execution begins, this also implies that
    the child process cannot affect the invocation of this vector.

    The function is called with the following parameter;

 VOID EntryCode(int32 entry_data);
                        D0

    The 'entry_data' comes from the value supplied with the
    'NP_EntryData,..'  tag.
    This function pointer can point to native PPC code or 68K code.
    Defaults to NULL.


NP_EntryData (int32) -- A user value to pass to the function which is
    invoked when the child process begins. (via 'NP_EntryCode' tag.

    You are not actually required to have an NP_EntryCode tag to use
    this field for any purpose you choose, it is just passed to
    the NP_EntryCode function as an argument, if you specified one.
    This value can also be obtained from within the child process
    by calling the V51 function GetEntryData().     (V51.73)
    Defaults to 0.


NP_FinalCode (VOID (*)(int32,int32)) -- Pointer to a function called
    when the child process is about to terminate, after exiting the user
    program code, but before any process unloading occurs or file and
    lock closing is performed by the DOS cleanup() function.
    This vector is very similar in functionality to NP_ExitCode(),
    but this field is for the *EXCLUSIVE* use of the spawning process to
    initialise, it cannot be permanently altered by the child process.

    The function is called with the following parameters;

   VOID FinalCode(int32 return_code, int32 final_data);
                         D0               D1

    The 'return_code' is the primary return code of the child process.
    The 'final_data' is from the value supplied by the NP_FinalData tag.
    Any secondary error code may also be retrieved with IoErr().
    This function pointer can point to native PPC code or 68K code.

    This vector gets called after NP_ExitCode if both are initialised.
    Defaults to NULL.  (V51.77)

    NOTE;  This vector is for the exclusive use of the spawning process.
    If the child process attempts to change this vector when
    the program is executing through the normal DOS program
    launching method (ie; internalRunCommand()) then the value
    will always be restored to the tag value when the child
    program code finally exits.  (See also; NP_FinalData)


NP_FinalData (int32) -- A value to pass to the function which is
    invoked when the child process exits. (via 'NP_FinalCode' tag).
    This is very similar to NP_ExitData use, but this field is for the
    *EXCLUSIVE* use of the spawning process to initialise, it cannot be
    permanently altered by the child process.  Defaults to 0. (V51.77)

    You are not actually required to use the NP_FinalCode tag to use
    this field for any purpose you require, it is simply passed to any
    NP_FinalCode function as an argument, if you have specified one.

    NOTE;  This field is for the exclusive use of the spawning process.
    If the child process attempts to change this value when
    the program is executing through the normal DOS program
    launching method (ie; internalRunCommand()) then the value
    will always be restored to the tag value when the child
    program code finally exits.  (See also; NP_FinalCode)


NP_ExitCode (VOID (*)(int32,int32)) -- Pointer to a function called
    when the child process is about to terminate after exiting from the
    user program code, but before any process unloading occurs or file
    and lock closing is performed by the DOS cleanup() function.

    The function is called with the following parameters;

    VOID ExitCode(int32 return_code, int32 exit_data);
                  D0               D1

    The 'return_code' is the primary return code of the child process.
    The 'exit_data' comes from the value supplied by NP_ExitData tag.
    Any secondary error code may be retrieved with IoErr().
    This function pointer can point to native PPC code or 68K code.

    This vector gets called before NP_FinalCode if both are initialised.
    Defaults to NULL.

    WARNING; There is no guarantee that the child process will leave
   this vector alone, unless it is YOUR code being run.
   You cannot depend on whether this tags value will persist
   up to the time the pr_ExitCode vector is invoked.
   There is known code in existance that uses this field for
   its own purposes,  so make no assumptions whether this
   value will remain constant in conjunction with unknown code.
   (See NP_FinalCode for protected function vectoring)


NP_ExitData (int32) -- A user value to pass to the function which is
    invoked when the child process exits. (via 'NP_ExitCode' tag).

    You are not actually required to have an NP_ExitCode tag to use
    this field for any purpose you choose, it is just passed to
    the NP_ExitCode function as an argument, if you specified one.
    This value can also be obtained from within the child process
    by calling the V50 function GetExitData().
    For pre-V50 callers, you can access it via; proc->pr_ExitData
    Defaults to 0.

    WARNING; There is no guarantee that the child process will leave
   this value alone, unless it is YOUR code being run.
   You cannot depend on whether this tags value will persist
   up to the time the pr_ExitCode vector is actually invoked.
   There is known code in existance that uses this field for
   its own purposes,  so make no assumptions whether this
   value will remain constant.
   (See NP_FinalData for protected function data)


NP_NotifyOnDeathMessage (struct DeathMessage *) -- (V51.55)
   Supply an initialised DeathMessage structure (as shown in example),
   for DOS to ReplyMsg() to,  upon death of this new process.
   The ReplyMsg() back to the mn_ReplyPort will occur at the last
   possible moment, just before the process is actually deleted
   and while the machine is single threading.    Defaults to NULL.

   A struct DeathMessage is defined in dos/dos.h as;
struct DeathMessage
{
   struct Message dm_Msg; /* Embedded exec message structure. */
   int32 dm_ReturnCode;   /* Primary return code, set by DOS. */
   int32 dm_Result2;      /* IoErr() value, set by DOS.       */
};

   You are required to initialise at least the following members of
   the structure;

struct DeathMessage *dmsg;
dmsg = IExec->AllocVec(sizeof(*dmsg),MEMF_SHARED);
dmsg->dm_Msg.mn_ReplyPort = messageport_to_reply_message_to;
dmsg->dm_Msg.mn_Length    = (uint16)sizeof(*dmsg);
IDOS->CreateNewProcTags(NP_NotifyOnDeathMessage, dmsg, ...);

   The dos.library will install the process' primary returncode in the;
   dmsg->dm_ReturnCode field, with the IoErr() value placed in;
   dmsg->dm_Result2, when the process is about to end.
   This will only occur if the message dmsg->dm_Msg.mn_Length field has
   been initialised to at least sizeof(struct DeathMessage), if this is
   not so, dos.library will ONLY ReplyMsg() the message (providing it
   is at least sizeof(struct Message)), without adding the return code
   and secondary result information.

   Note; The task receiving the reply is responsible for GetMsg()'ing
   the death message from the replyport and FreeVec()ing the structure.

   DOS does not touch any fields of the Message structure itself,
   so it is possible to use fields like; dmsg->dm_Msg.mn_Node.ln_Name
   to hold private data that needs to be returned to the parent process,
   or can be used to differentiate multiple deathmessages arriving at
   the same port from multiple children.

   This tag can easily be used to make a syncronous CreateNewProcTags()
   function with access to the primary and secondary result codes.

   The child process holds the pointer to the struct DeathMessage in
   the process structure field; pr_DeathMessage.

   The DeathMessage is replied to at the second last possible moment,
   before the process is actually deleted, a NP_NotifyOnDeathSigTask 
   signalling is the only thing that can occur after this.
   Defaults to NULL.


NP_NotifyOnDeathSigTask	(struct Task *) -- (V51.55)
   Specify the task (or process) to signal upon death of this process.
   Defaults to OFF, when this tag is not specified.

   You may specify this tag with a NULL value, to indicate that you
   wish to signal the parent of this new child process.
   ie;  The task/process calling the CreateNewProc() function.

   The Signal() to the task specified here will occur at the last
   possible moment, just before the process is actually deleted.


NP_NotifyOnDeathSignalBit (uint32) -- (V51.55)
   A value 0-31 being the signal bit number (SIGB_xxx or SIGBREAKB_xxx)
   (See also; exec/AllocSignal())  to send to the task/process that was
   specified by NP_NotifyOnDeathSigTask, upon death of this new process.
   Defaults to SIGB_CHILD if not specified.
   (See; exec/tasks.h)


NP_OwnerUID (uint32) -- (V52.18)
   Specify the pr_UID owner [user] value for the new process.
   Default; Inherit parent process value.  (zero if parent is a task.)


NP_OwnerGID (uint32) -- (V52.18)
   Specify the pr_GID owner [group] value for the new process.
   Default; Inherit parent process value.  (zero if parent is a task.)

**Result:**
proc  -   The pointer to the created process, or NULL on failure.
   Note that if it returns NULL, you must free any items that
   were passed in via tags, such as if you supplied your own
   current directory with NP_CurrentDir, or path with NP_Path.

   On failure, consult IoErr() to obtain more information.

   On success, and only from DOS V51.94+, IoErr() will return
   the process identifier (PID) for the new process, this value
   is obtained from; newprocess->pr_ProcessID while the single
   threading lock is still in force.

   The PID is guaranteed to be non-zero for valid processes and
   the numbers are issued incrementally. Even if the 32 bit PID
   counter ever manages to roll around, you are guaranteed that
   no two running processes can ever have the same PID number.

**Example:**
```c
These examples demonstrate several methods to arbitrate termination
of multiple sub-processes created by a parent process, so that the
parent does not exit until all the child processes have done so first,
especially important when a child is sharing resources of the parent
process, such as code space, streams, locks or interfaces, etc...

While the NP_Child tag will always protect against child code running
in freed memory (when the parent unloads), it does NOT provide any
protection from DOS (or any CLIB startup code) closing shared streams
or unlocking locks that are under the control of the parent process,
the only way to prevent that happening is to defer leaving main()
until the shared resource usage has completely finished.

The following examples intensionally share resources allocated by
the parent process and would crash instantly if the parent exits
before all the child processes have done so first.

Most importantly, if a child process happens to crash, these examples
will still allow the main process to exit after the crashed child has
been terminated by the system crash handler, therefore you are not
going to finish up with a hung parent process, as would occur if the
child had to execute any handshaking code as part of its function,
which may never get executed if the child were to crash.


                          =====
/*
 * This example uses the NP_DeathSignal feature in conjunction with
 * the DOS vectors used to execute code on start or end of a process,
 * these vectors are used here to control a child tracking counter
 * (that only executes while inside the DOS library code),
 * this is used to determine when all child processes have finished
 * executing, to know when the parent process can exit,
 * the child also shares the parents DOS interface in this example.
 */

#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#include <proto/dos.h>
#include <proto/exec.h>
#include <dos/startup.h>

/* A child process that waits for 10 seconds then exits. */
STATIC int32 childproc(STRPTR *args UNUSED, int32 arglen UNUSED,
                struct ExecBase *sysbase)
{
    struct ExecIFace *iexec =(APTR)sysbase->MainInterface;
    struct Process *me      =(APTR)iexec->FindTask(0);
    struct DOSIFace *idos   =(APTR)me->pr_ExitData; /* via parent */
    idos->Delay(TICKS_PER_SECOND * 10);
    return(RETURN_OK);
}


/* local tracking data structure */
struct Func_Tracking_Data
{
    struct  ExecIFace *Iexec;
    struct  SignalSemaphore Sem;
    int32   ChildCount;
};


/* This is called when a child process ends. */
STATIC VOID finalfunc(int32 rc UNUSED, struct Func_Tracking_Data *fd)
{
    fd->Iexec->ObtainSemaphore(&fd->Sem);
    fd->ChildCount --;
    fd->Iexec->ReleaseSemaphore(&fd->Sem);
}


/* This is called when a child process begins. */
STATIC VOID entryfunc(struct Func_Tracking_Data *fd)
{
    fd->Iexec->ObtainSemaphore(&fd->Sem);
    fd->ChildCount ++;
    fd->Iexec->ReleaseSemaphore(&fd->Sem);
}


/* -- AmigaDOS program entry point -- */
int32 _start(STRPTR args UNUSED, int32 arglen UNUSED,
                          struct ExecBase *sysbase)
{
   struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
   struct Library *dosbase;
   struct DOSIFace *idos;
   struct Process *me;
   struct WBStartup *wbmsg = NULL;
   struct Func_Tracking_Data  *fd;
   uint32 x;
   int32  result = RETURN_ERROR;

   iexec->Obtain();
   me = (struct Process *) iexec->FindTask(NULL);

   if( ! me->pr_CLI ) /* Check for workbench startup message */
   {
      iexec->WaitPort(&me->pr_MsgPort);
      wbmsg = (struct WBStartup *) iexec->GetMsg(&me->pr_MsgPort);
   }

   if(( fd = iexec->AllocVec(sizeof(*fd),MEMF_SHARED) ))
   {
      iexec->InitSemaphore(&fd->Sem); /* initialised tracking sem */
      fd->ChildCount = 0;
      fd->Iexec = iexec;

      if(( dosbase = iexec->OpenLibrary("dos.library", 50) ))
      {
  if(( idos =(APTR)iexec->GetInterface(dosbase,"main",1,0)))
  {
     result = RETURN_OK;

     for(x=1; x <= 10; x++)
     {
         if(( idos->CreateNewProcTags(
         NP_Entry, childproc,
         NP_NotifyOnDeathSigTask, me, /* SIGB_CHILD signal */

         NP_FinalCode, finalfunc, /* executes this ending */
         NP_FinalData, fd,      /* tracking data for above */

         NP_EntryCode, entryfunc, /* executes this starting */
         NP_EntryData, fd,      /* tracking data for above */

         NP_Child, TRUE,
         NP_ExitData, idos, /* share idos with children. */
         TAG_DONE) ))
         {
             idos->Printf("Started child number %lu\n", x);
         }

         idos->Delay(TICKS_PER_SECOND/4);
     }

     idos->Printf("\nWaiting for the %lu children to end.\n\n",
                     fd->ChildCount);

     while( fd->ChildCount >0 )
     {
         iexec->Wait(SIGF_CHILD);
         idos->PutStr("Child death signal received.\n");
     }

     idos->PutStr("\nAll children gone, now exiting.\n\n");
     iexec->DropInterface((struct Interface *)idos);
  }
  iexec->CloseLibrary(dosbase);
      }
      iexec->FreeVec(fd);
   }

   if( wbmsg )
   {
      /* iexec->Forbid(); <- not needed with workbench.library V52+ */
      iexec->ReplyMsg((APTR)wbmsg );
   }

   iexec->Release();
   return(result);
}


                          =====


/*
 * This example uses the NP_DeathMessage feature to determine when
 * all child processes have finished executing, before the parent
 * process can exit, the child also shares the parents DOS interface.
 */

#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#include <proto/dos.h>
#include <proto/exec.h>
#include <dos/startup.h>

/* This is the child process that waits for 10 seconds then exits. */
STATIC int32 childproc(STRPTR *args UNUSED, int32 arglen UNUSED,
                                    struct ExecBase *sysbase)
{
    struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
    struct Process *me      = (APTR)iexec->FindTask(0);
    struct DOSIFace *idos   = (APTR)me->pr_EntryData; /* via parent */

    idos->Delay(TICKS_PER_SECOND * 10);
    idos->SetIoErr((int32)me->pr_ProcessID);
    /* To make IoErr() return the childs PID number for Printf(). */

    return(RETURN_OK);
}


/* -- AmigaDOS program entry point -- */
int32 _start(STRPTR args UNUSED, int32 arglen UNUSED,
                                struct ExecBase *sysbase)
{
struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
struct Library *dosbase;
struct DOSIFace *idos;
struct Process *process;
struct WBStartup *wbmsg = NULL;
struct MsgPort *DMreplyport;
struct DeathMessage *dmsg;
uint32 x, childcount;
int32  result = RETURN_ERROR;

iexec->Obtain();
process = (struct Process *) iexec->FindTask(0);

if( ! process->pr_CLI )	/* Check for workbench startup message */
{
    iexec->WaitPort(&process->pr_MsgPort);
    wbmsg = (struct WBStartup *) iexec->GetMsg(&process->pr_MsgPort);
}

if(( dosbase = iexec->OpenLibrary("dos.library", 50) ))
{
   if(( idos = (APTR) iexec->GetInterface(dosbase,"main",1,0) ))
   {
      if(( DMreplyport = iexec->CreateMsgPort() ))
      {
   result = RETURN_OK;

   for(childcount=0, x=0; x < 10; x++)
   {
       if((dmsg =iexec->AllocVec(sizeof(*dmsg),MEMF_SHARED)))
       {
            dmsg->dm_Msg.mn_ReplyPort = DMreplyport;
            dmsg->dm_Msg.mn_Length    = (uint16)sizeof(*dmsg);

            if(( idos->CreateNewProcTags(NP_Entry,childproc,
                     NP_Child, TRUE,
                     NP_EntryData, idos, /* passed to child */
                     NP_NotifyOnDeathMessage,dmsg, TAG_DONE) ))
            {
                idos->Printf("Started child process %lu\n",
                                                idos->IoErr());
                childcount ++;
            }
            else
            {
                iexec->FreeVec(dmsg);
            }
            idos->Delay(TICKS_PER_SECOND/4);
       }
   }

   idos->Printf("\nNow waiting for the %lu children to end.\n\n",
                                                childcount);
   while( childcount >0 )
   {
      iexec->WaitPort(DMreplyport);
      if(( dmsg = (APTR)iexec->GetMsg(DMreplyport) ))
      {
         idos->Printf("Death message received for child %lu\n",
                                           dmsg->dm_Result2);
         iexec->FreeVec(dmsg);
         childcount --;
      }
   }

   idos->PutStr("\nAll children gone, parent now exiting.\n\n");
   iexec->DeleteMsgPort(DMreplyport);
      }
      iexec->DropInterface((struct Interface *)idos);
   }
   iexec->CloseLibrary(dosbase);
}

if( wbmsg )
{
   /* iexec->Forbid(); <- not needed with workbench.library V52+ */
   iexec->ReplyMsg((APTR)wbmsg );
}

iexec->Release();
return(result);
}


                          =====


/*
 * This example uses a process change signal notification in
 * conjunction with the ProcessScan() function to determine if any
 * child processes are still running, it also shares idos.
 */

#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#include <proto/dos.h>
#include <proto/exec.h>
#include <dos/startup.h>

/* This is the child process that waits for 10 seconds then exits. */
STATIC int32 childproc(STRPTR *args UNUSED, int32 arglen UNUSED,
                                    struct ExecBase *sysbase)
{
    struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
    struct Process *me      = (APTR)iexec->FindTask(0);
    struct DOSIFace *idos   = (APTR)me->pr_EntryData; /* via parent */

    idos->Delay(TICKS_PER_SECOND * 10);
    return(RETURN_OK);
}


/* Hook function for the ProcessScan() call below. */
STATIC uint32 ASM find_child( REG(a0, struct Hook *hook) UNUSED,
                       REG(a2, struct Process *parentproc ),
                       REG(a1, struct Process *proc) )
{
    if(proc->pr_ParentID == parentproc->pr_ProcessID) /* my child ? */
    {
 if(proc->pr_ExitData == (int32)parentproc) /* second tier */
 {
     return(TRUE); /* return TRUE */
 }
    }
    return(FALSE);  /* FALSE = not found - continue to scan list */
}



/* Find any child processes still running. */
STATIC uint32 Found_any_child_process(struct DOSIFace *idos,
                              struct Process *parentproc)
{
    struct Hook H;
    H.h_Entry = (APTR) find_child;
    return (uint32) idos->ProcessScan( &H, parentproc, 0);
}



/* -- AmigaDOS program entry point -- */
int32 _start(STRPTR args UNUSED, int32 arglen UNUSED,
      struct ExecBase *sysbase)
{
    struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
    struct Library *dosbase;
    struct DOSIFace *idos;
    struct Process *process;
    struct WBStartup *wbmsg = NULL;
    uint32 x;
    int32  result = RETURN_ERROR;

    iexec->Obtain();
    process = (struct Process *) iexec->FindTask(NULL);

    if( ! process->pr_CLI )	/* Check for workbench startup message */
    {
 iexec->WaitPort(&process->pr_MsgPort);
 wbmsg = (APTR) iexec->GetMsg(&process->pr_MsgPort);
    }

    if((dosbase = iexec->OpenLibrary("dos.library", 50) ))
    {
 if((idos = (APTR)iexec->GetInterface(dosbase,"main",1,0)))
 {
     if(idos->NotifyProcListChange(process,SIGBREAKB_CTRL_E,0))
     {
         result = RETURN_OK;

         for( x=0; x < 10; x++ )
         {
             idos->PutStr("Starting a child process\n");
             idos->CreateNewProcTags( NP_Entry, childproc,
                                      NP_Child, TRUE,
                                      NP_ExitData, process,
             /* pr_ExitData used as the 2nd tier child ident */
                                      NP_EntryData, idos,
             /* pr_EntryData used to share idos for children */
                                      TAG_DONE);

             idos->Delay(TICKS_PER_SECOND/3);
         }

         idos->PutStr("\nWaiting for children to exit...\n\n");
         while( Found_any_child_process(idos,process) )
         {
             iexec->Wait( SIGBREAKF_CTRL_E );
             idos->PutStr("Process list change signal !\n");
         }

         idos->NotifyProcListChange(NULL, NPLC_END, 0);
         /* Turn signal notification off */

         idos->PutStr("\nAll children have ended,");
         idos->PutStr(" main program now exiting.\n\n");
     }
     iexec->DropInterface((struct Interface *)idos);
 }
 iexec->CloseLibrary(dosbase);
    }

    if( wbmsg )
    {
      /* iexec->Forbid(); <- not needed with workbench.library V52+ */
 iexec->ReplyMsg((APTR)wbmsg );
    }
    iexec->Release();
    return(result);
}

                          =====
```

**Notes:**
It is remotely possible for this function to return a non-zero success
value, but not actually get to the point where the user code runs.
This can occur if there is insufficient memory for the user stackframe
which is allocated in the internal_RunCommand() function.
However, the NP_EntryCode, NP_FinalCode and NP_ExitCode vectors are
still always executed if this situation actually manages to occur.

For 68K legacy executables, user program code can also be denied
execution by being listed appropriately in DEVS:applications.dos.

**Bugs:**
In V36, NP_Arguments was broken in a number of ways, and probably
should be avoided (instead you should start a small piece of your
own code, which calls RunCommand() to run the actual code you wish
to run).  In V37, NP_Arguments works, though see the note above.

**See also:** LoadSeg(), CreateProc(), ReadArgs(), RunCommand(), <dos/dostags.h>
ProcessScan(), NotifyProcListChange().

---

### dos.library/DateStamp

**Obtain the date and time values.**

**Synopsis:**
```c
struct DateStamp *ds = DateStamp( struct DateStamp *ds );
```

**Description:**
Time on the Amiga is measured by the timer.device in "AmigaTime"
which is the number of seconds since 1-January-1978.

DateStamp() takes a pointer to a DateStamp structure and fills it
(if not NULL) with the values converted from the current "AmigaTime".
  
struct DateStamp 
{
   int32 ds_Days;    /* Number of days since Jan. 1, 1978 */
   int32 ds_Minute;  /* Number of minutes past midnight   */
   int32 ds_Tick;    /* Number of ticks past the minute   */
};

The first field in the structure is a count of the number of days.
The second field is the number of minutes elapsed past midnight.
The third is the number of ticks elapsed in the current minute.
A tick happens 50 times a second. (20mS)

DateStamp() ensures that the day and minute are consistent.  
All three fields are zero if the date is unset.

**Inputs:**
ds - pointer to a struct DateStamp to fill, (or NULL).

**Result:**
The structure is filled as described and the same argument pointer
supplied is always returned for pre-V36 compatability.

From V53.32 IoErr() will also return the "AmigaTime" seconds value,
this works even when a NULL 'ds' parameter is supplied, however,
this feature is only available when called from a DOS process.

**Notes:**
From V50, this function is also safely callable from an exec task,
however IoErr() will always return 0.

DateStamp structures do NOT require longword alignment.

**See also:** DateToStr(), StrToDate(), SetDate(), CompareDates(),
SecondsToDateStamp(), DateStampToSeconds()

---

### dos.library/DateToStr (V36)

**Converts a DateStamp to a string.**

**Synopsis:**
```c
int32 success = DateToStr( struct DateTime *datetime );
```

**Description:**
DatetoStr() converts an AmigaDOS DateStamp to a human
readable ASCII string as requested by your settings in the
DateTime structure.

**Inputs:**
datetime - a pointer to an initialized DateTime structure.

The DateTime structure should be initialized as follows:

dat_Stamp  - a copy of the datestamp you wish to convert to
      a nul-terminated text string.

dat_Format - a format byte which specifies the format of the
      dat_StrDate. This can be any of the following;

      FORMAT_DOS: AmigaDOS format (dd-mmm-yy).

      FORMAT_INT: International format (yy-mmm-dd).

      FORMAT_USA: American format (mm-dd-yy).

      FORMAT_CDN: Canadian format (dd-mm-yy).

      FORMAT_DEF: Default format for locale.

      FORMAT_ISO: ISO 8601 format (yyyy-mm-dd).
                  Requires locale.library V48+ 
                  or dos V50.36+ if locale not available.

      If the value used is something other than those above,
      default FORMAT_DOS is used.

dat_Flags  - a flags byte. 
      The only flags which affect this
      function are:

      DTF_SUBST:  If set, a string such as "Today",
                  "Monday", etc., will be used instead of
                  the dat_Format specification if possible.

      DTF_FUTURE: Ignored by this function.

dat_StrDay - pointer to a buffer to receive the the nul-terminated
      day of the week string. ("Monday", "Tuesday", etc.). 
      If NULL, this string will not be generated.

dat_StrDate- pointer to a buffer to receive the nul-terminated
      date string, in the format requested by dat_Format,
      subject to possible modifications by DTF_SUBST.
      If NULL, this string will not be generated.

dat_StrTime- pointer to a buffer to receive the nul-terminated 
      time of day string. 
      If NULL, this string will not be generated.

**Result:**
success    - (Boolean) a zero return indicates that the DateStamp
      was invalid, and could not be converted.
      Non-zero indicates that the call succeeded.

**Notes:**
If not NULL, dat_StrDay, dat_StrDate and dat_StrTime
must point to at least LEN_DATSTRING bytes to fill in.
Strings may be truncated after LEN_DATSTRING-1 bytes
have been written to ensure that the result is nul-terminated.

Please note that this function is always redirected to locale.library
after it has been initially opened by at least one caller.
Prior to the availablility of locale.library, the DOS version of this
function is not Locale aware and only understands the English formats.
FORMAT_DEF callers will be interpreted as the FORMAT_DOS layout and
the dat_Flags will also be ignored at this time.

**Bugs:**
dos.library and locale.library interact when filling in the
dat_StrDay, dat_StrDate and dat_StrTime buffers. 
Earlier versions did not check if the strings to be written would
overflow these buffers.

**See also:** DateStamp(), StrtoDate(), <dos/datetime.h>

---

### dos.library/Delay

**Delay a task or process for a specified time.**

**Synopsis:**
```c
VOID Delay( uint32 ticks );
```

**Description:**
The argument 'ticks' specifies how many ticks (50 ticks per second)
to wait before returning control.

The definition; TICKS_PER_SECOND can be found in dos/dos.h.
One 'tick' has a period of 20 milliseconds.

**Inputs:**
ticks - (uint32) Number of 50ths of a second, ( 20mS periods ).

**Notes:**
From V50, this function is safely callable from a task, however,
doing so will require the temporarily allocation of a message port.

**Bugs:**
Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
of zero for Delay() would cause unreliable timer & floppy disk
operation.  
This was fixed in V36 and later and just returns without waiting now.

---

### dos.library/Delete

**Delete a file, directory or symbolic link.**

**Synopsis:**
```c
int32 success = Delete( CONST_STRPTR name );
```

**Description:**
This attempts to delete the object specified by 'name'.

If the object cannot be deleted for any reason, the value returned
will be zero, and a secondary error code will be available by
calling the IoErr() function.

Note that all the objects within a directory must be deleted before
the directory itself can be deleted.

Besides MakeLink(), and conditionally Rename(), this is the only other
function that can directly affect symbolic links, all other operations
are performed on the links target object instead.

**Inputs:**
name    - (CONST_STRPTR) pointer to a null-terminated string.
   (See GetDeviceProcFlags() for details about this.)

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
Attempting to delete a directory with a trailing '/' in 'name'
will cause failure.

Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

It is safe to pass a NULL 'name' parameter, it just returns FALSE.

This function is NOT callable from tasks.

This function used to be called DeleteFile() even though it worked on
directories and symbolic links as well, it was renamed for consistency.

**See also:** GetDeviceProcFlags()

---

### dos.library/DeleteVar (V36)

**Deletes a local or global environment variable.**

**Synopsis:**
```c
int32 success = DeleteVar( CONST_STRPTR name, uint32 control );
```

**Description:**
Deletes a local or global environment variable.

Variable names follow filesystem syntax and semantics.
All variable names are always relative to the root of the device.
The current directory has no effect on this function.
If any "DEVICE:" part is specified in the variable name,
only the portion after the colon ':' will actually be used.

**Inputs:**
name    - Pointer to a variable name/path descriptor string.

control - Combination of type of var to delete (low 8 bits), 
   ie; LV_VAR or LV_ALIAS,  plus optional flags ORed with it to
   control the behavior of this routine.
   Currently defined optional flags include:

   GVF_LOCAL_ONLY  - delete only a local (your process) variable.
   GVF_GLOBAL_ONLY - delete a global variable in ENV:
   GVF_SAVE_VAR    - also delete the global variable in ENVARC:

   The default (control=LV_VAR) is to delete a local variable
   first, if one is found, otherwise delete a global variable. 
  (only for LV_VAR, LV_ALIAS will only delete a local alias).

**Result:**
success - boolean; (zero or non-zero), If non-zero, if the variable
   was sucessfully deleted, FALSE indicates failure.

**Bugs:**
LV_VAR is the only type that can be global.

**See also:** GetVar(), SetVar(), FindVar(), <dos/var.h>

---

### dos.library/DevNameFromFH

**Returns the device with or without path,
          associated with a filehandle. (V51.32)**

**Synopsis:**
```c
int32 success = DevNameFromFH( BPTR filehandle, STRPTR buffer, 
                        int32 buflen, int32 mode );
```

**Description:**
This function is similar to NameFromFH() with the difference being
that the unique device name is returned instead of the volume name,
this function also has the added feature of being able to return 
only the device name associated with a file or the full object path.

The 'mode' parameter controls the behaviour of this function.
If 'mode' is DN_FULLPATH then the entire path and object is returned,
supplying DN_DEVICEONLY for the 'mode' parameter will cause this 
function to quickly scan the DosList to find only the device name 
associated with the filehandles task, it will return only the matching
device name component plus a ':' when used in this mode.
From V54+ DN_ROOTPATH, returns the same as DN_FULLPATH except that the
first character will be a colon ':' rather than have a device name,
this will make the path relative to the root of the current device.

This is intended as a complementary function to obtain the unique
device name from a given filehandle, whereas NameFromFH() will always
try to return the full path beginning with the Volume name associated
with a filehandle, but it is possibe to have duplicate doslist names
at various times and in some cases this may be quite undesirable.

This routine is guaranteed not to write more than 'buflen' bytes into
the buffer.  The buffer will also always be null-terminated.

If the buffer is not large enough to hold the entire path, 
this function will fail and IoErr() will return ERROR_LINE_TOO_LONG.
If this occurs, use a larger buffer and try again.
Recommended minimum buffer size is 1024 bytes.

If the filehandle is zero, this function will fail.

The buffer is guaranteed to be cleared on entry, providing a non-NULL
'buffer' is supplied and the 'buflen' is >0

**Inputs:**
filehandle - Filehandle.
buffer     - Buffer for device name (and/or complete path).
buflen     - Length of buffer.
mode       - DN_FULLPATH or DN_DEVICEONLY or
      DN_ROOTPATH (added for V54)

**Result:**
success    - boolean; (zero or non-zero value)

**Notes:**
This function is NOT task callable.

**See also:** NameFromFH(), NameFromLock(), DevNameFromLock(), Lock(), IoErr(), 
SetProcWindow()

---

### dos.library/DevNameFromPort

**Get the device name of a handler by its MsgPort.
            (V53.60)**

**Synopsis:**
```c
int32 success = DevNameFromPort(struct MsgPort *port, STRPTR buffer, 
                         int32 buflen, int32 add_colon);
```

**Description:**
This function is similar to other (Dev)NameFromXXX() with the
difference being that the filesystem/handlers device name will be
returned in the buffer, with or without a colon character appended.

This is a complementary function to NameFromPort() which returns the
volume name associated with the port.

This routine is guaranteed not to write more than 'buflen' bytes into
the buffer.  The returned buffer will always be null-terminated.

If the buffer is not large enough to hold the entire string, 
this function will fail and IoErr() will return ERROR_LINE_TOO_LONG.
If this occurs, use a larger buffer and try again.
Recommended minimum buffer size is 258 bytes.

The buffer is guaranteed to be cleared on entry, providing a non-NULL
'buffer' is supplied and the 'buflen' is >0

Supplying a NULL port pointer returns "NIL" or "NIL:".

**Inputs:**
port      - Message port for the handler or filesystem.
buffer    - Buffer for device name.
buflen    - Length of buffer.
add_colon - TRUE= colon character appended to name, FALSE= no colon.

**Result:**
success   - boolean; (zero or non-zero value)

**Notes:**
This function is NOT task callable.
This function provides no locking for the 'port' of the handler.
This function performs a temporary read-lock on the DosList.

**See also:** NameFromPort(), NameFromFH(), DevNameFromFH(), NameFromLock(), 
DevNameFromLock(), Lock(), IoErr(), SetProcWindow()

---

### dos.library/DismountDevice

**Dismounts a file system or handler (V51.30)**

**Synopsis:**
```c
int32 success = DismountDevice(CONST_STRPTR devname, uint32 mode,
                        APTR reserved);
```

**Description:**
Dismounts a file system or handler, this performs a function opposite
to what the MountDevice() or the "Mount" shell command does.

**Inputs:**
devname -- Device name (ONLY) of the file system or handler.
    This name must end with a colon character, e.g. "DF0:".

mode    -- DMDF_REMOVEDEVICE  or  DMDF_KEEPDEVICE  (mutually exclusive)
    This indicates whether you want to dismount a file system
    or handler permanently, by removing the DosList device node
    entry too, or just dismount the current handler instance.

    DMDF_KEEPDEVICE
        Keeping the device node will allow it to be restarted
        upon the next access to the DOS device, with exactly the
        same media geometry it had initialised previously.

    DMDF_REMOVEDEVICE
         Removing the device entry will remove it permanently,
         this mode MUST be used if the media geometry is able
         to change, this allows for completely different media
         to be inserted with the same DOS device name, such as
         can occur with a variety of USB plug-in devices.
         Removing the device node of course implies that your
         new DOS device must be freshly "MountDevice()'ed" by
         the driver or appropriate subsystem, when needed again.

optional mode flag -- DMDF_FORCE_DISMOUNT
    This option is a LAST RESORT KLUDGE to force a dismount when
    the filesystem or handler does NOT support the new dospacket,
    this flag will only have an effect if the proper supported
    method is NOT available, which is determined by the response
    of the handler with error code ERROR_ACTION_NOT_KNOWN when
    the dismount was attempted.

    If the handler does not support the ACTION_SHUTDOWN dospacket,
    the dos.library itself will permanently inhibit the handler
    process and manually disconnect all the volumes and assigns
    refering to the 'devname', from the DosList, as well as the
    device node if the DMDF_REMOVEDEVICE mode was specified.

    NOTE; It does not free up resources; it only removes the
    name from the list and casts all nodes adrift permanently.
    There is no way to cancel this operation without rebooting.
    This option is primarily for use during software development
    or as a last resort when it is not otherwise possible to
    dismount a device via a filesystem action.
    Careless use of this option may cause a software failure.
    It will definately cause a loss of system resources.
    The functionality of this flag may be discontinued at
    some point in the future.

reserved-- Always set to NULL, this is reserved for future expansion.
    This function will fail if this parameter is not zero.

**Result:**
success -- boolean; (zero or non-zero value)  Non-zero for success.
    Zero if the filesystem or handler could not be found
    or some other sort of error occured.
    Call IoErr() to find out more about any specific error.

**See also:** MountDevice(), FileHandleScan(), DevNameFromLock(), DevNameFromFH(),
ACTION_SHUTDOWN

---

### dos.library/DoPkt (V36)

**Low level function to send a dos packet to a handler 
  and wait for a reply.**

**Synopsis:**
```c
int32 result1 = DoPkt(struct MsgPort *port, int32 action, int32 arg1,
              int32 arg2, int32 arg3, int32 arg4, int32 arg5);
```

**Description:**
Builds and sends a dospacket to a handler and waits for it to return.
Any secondary return will be available from IoErr() providing the
caller is a process.

DoPkt() will work even if the caller is an exec task and not a 
process; however it will be slower, due to the fact that from 
a task, it will need to call CreateMsgPort() and DeleteMsgPort()
for the replyport each time it's called, it may also fail for some
additional reasons, such as being unable to allocate a signal.  

If called from a process, DoPkt() uses your processes pr_MsgPort for
the reply and will call pr_PktWait (only processes), if initialised.

This function only allows 5 arguments to be specified and only works
with 32 bit DosPackets, for more arguments and for 64 bit DosPackets,
allocate a dospacket with AllocDosObject(DOS_STDPKT), fill it out and
then call SendPkt(),WaitPkt(),FreeDosObject().

**Inputs:**
port      - pr_MsgPort of the handler process to send to. (NULL safe)
action    - the action requested of the handler
arg1-arg5 - arguments, depend on the particular action, 
     some/several may not be required, use 0 for those.

**Result:**
result1   - The value returned in dp_Res1, or FALSE if there was some
     problem in sending the packet or receiving it.

result2   - Only available from IoErr() (when called from a process)

**Bugs:**
Before V51.99 if called by a task, this function would never be
able to work, as it was waiting on the wrong signal bit and may
also cause a DSI when extracting the return code from the packet.

**See also:** AllocDosObject(), FreeDosObject(), SendPkt(), WaitPkt().

---

### dos.library/DupFileHandle

**Creates a duplicate of an open filehandle. (V51.32)**

**Synopsis:**
```c
BPTR fh = DupFileHandle( BPTR ofh );
```

**Description:**
Given an open filehandle, this routine attempts to open a new shared
stream to the same object that the original filehandle referenced.

Whether the duplication succeeds or not, the original filehandle (ofh)
still remains valid and must be handled / closed as any normal stream.
You are responsible for the new duplicated filehandle closing too, 
just the same as if you had opened it yourself with Open().

It is not possible to duplicate a filehandle with an EXCLUSIVE lock,
this being any stream which was opened with MODE_NEWFILE.
If you have a choice, it's better to use MODE_READWRITE or MODE_OLDFILE
with the files you may need to duplicate, or you could change the
exclusive locking mode by using ChangeMode() on it beforehand.

It is also legal to duplicate NIL: streams.

It may not be possible to duplicate streams to some DOS device handlers
such as PAR: SER: etc.. which opens a specific unit to the underlying 
i/o device from a dos handler, and since you already have that device
unit open with your 'ofh' stream, further open attempts to the same 
device unit will fail with an 'object in use' error, therefore, make no
assumptions whether this function will succeed or not, always test the
result to be sure.

On failure, consult IoErr() for more information.

**Inputs:**
ofh  - (BPTR) - Original (open) filehandle to duplicate.

**Result:**
fh   - (BPTR) - Newly created filehandle,  or ZERO for failure.

**Notes:**
This function is NOT callable by tasks.

**See also:** Open(), Close(), NameFromFH(), DevNameFromFH(), ChangeMode().

---

### dos.library/DupLock

**Duplicate an existing lock.**

**Synopsis:**
```c
BPTR newlock = DupLock( BPTR lock );
```

**Description:**
DupLock() is passed an existing shared filing system lock.
This function will ask the handler to create a duplicate
lock of this lock.

This is the ONLY way to obtain a duplicate of a lock.
Simply copying an existing lock is not allowed.
Another lock to the same object is then returned.  
It is not possible to create a copy of a exclusive lock.

**Inputs:**
lock    - BCPL pointer to a lock.

**Result:**
newlock - BCPL pointer to a lock or ZERO for failure.

**Notes:**
You are responsible for unlocking the duplicate lock.
Passing a lock of ZERO does nothing but return ZERO.
This function is NOT task callable.

**See also:** Lock(), UnLock(), DupLockFromFH(), ParentOfFH(), SetMode()

---

### dos.library/DupLockFromFH (V36)

**Gets a lock on an open file**

**Synopsis:**
```c
BPTR lock = DupLockFromFH( BPTR fh );
```

**Description:**
Obtain a lock on the object associated with 'fh'.  
Only works if the file was opened using a non-exclusive mode,
i.e. MODE_OLDFILE or MODE_READWRITE. 
Other restrictions may be placed on success by the filesystem.

The file handle 'fh' is still perfectly usable after this call, 
(unlike the lock in the OpenFromLock() function), you must still
eventually Close() the file handle.

The resultant 'lock' remains valid even after the file is closed,
you must also make sure this lock is eventually UnLock()'ed.

**Inputs:**
fh   - BPTR; Opened filehandle for which to obtain a duplicate lock.

**Result:**
lock - BPTR; Duplicated lock or ZERO for failure.

**Notes:**
This function is NOT task callable.

**See also:** DupLock(), Lock(), UnLock()

---

### dos.library/EndNotify (V36)

**Ends a notification request.**

**Synopsis:**
```c
int32 success = EndNotify(struct NotifyRequest * notifystructure);
```

**Description:**
Removes a notification request from the active queue.

For NRF_SEND_MESSAGE requests, it also searches your port for any
messages about the object in question and removes and replies to them
before returning.

The notify request struct is not freed here, you still need to call
FreeDosObject(DOS_NOTIFYREQUEST,notifystructure) to release the memory
you allocated via the AllocDosObject().

**Inputs:**
notifystructure - pointer to the same structure passed to StartNotify()
           NULL parameter does nothing.

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
This function is NOT task callable for filesystem notifications.
This function did not have a documented return code until V51.

**Bugs:**
Even though it has been previously documented as being safe to call
if StartNotify() failed, it has since been discovered that some
filesystems did not behave correctly in this regard. 
A fix was implemented in dos.library 52.23 to protect for this case.
If operating before dos.library 52.23 it would be advisable to only
call this function if the StartNotify() actually succeeded.

**See also:** StartNotify(), <dos/notify.h>

---

### dos.library/ErrorReport (V36)

**Displays a Retry/Cancel requester for an error.**

**Synopsis:**
```c
int32 status = ErrorReport(int32 errorcode, int32 arg1type, 
                    uint32 arg1, struct MsgPort *port);
```

**Description:**
Based on the type of arguments supplied, this routine will format
and display the appropriate requester to match the error code.  

If the error code is not one of the supported values listed below,
it returns DOSTRUE immediately, it will also return DOSTRUE if the 
user selects CANCEL or if the attempt to post the requester fails, 
or if the process pr_WindowPtr is set to -1. 

Returns FALSE if the user selects Retry.

**Inputs:**
errorcode - Error code to put a requester up for.
     Currently supported error codes are:

     ERROR_DISK_NOT_VALIDATED
     ERROR_DISK_WRITE_PROTECTED
     ERROR_DISK_FULL
     ERROR_DEVICE_NOT_MOUNTED
     ERROR_NOT_A_DOS_DISK
     ERROR_NO_DISK
     ABORT_DISK_ERROR        /* read/write error */
     ABORT_BUSY              /* you MUST replace... */

arg1type  - Argument type supplied, to build the requester:

     REPORT_LOCK   - arg1 must be a Lock (BPTR).
     REPORT_STREAM - arg1 must be a FileHandle (BPTR).
     REPORT_VOLUME - arg1 must be a struct DosList * (C ptr).
     REPORT_INSERT - arg1 is the string for a volumename,
                     (string will be split on a ':').

     For error type: ERROR_DEVICE_NOT_MOUNTED it will post a
     different message based on the 'arg1type' supplied:

          For REPORT_INSERT the requester will post:
                 "Please insert volume..."
          
          Otherwise, the message will be:
                 "Please replace volume..."


arg1     - variable parameter type. (see arg1type)

port     - (Optional) The device handler message port for which
    report is to be made.  This is used only if non-NULL, 
    otherwise a message port will be extrapolated from arg1
    if possible.

**Result:**
status   - Cancel/Retry indicator (FALSE means Retry)

**Notes:**
The routine will automatically retry from IDCMP_DISKINSERTED messages
for all error codes, except when using argument type REPORT_VOLUME.

From DOS 51.02, the behaviour of REPORT_INSERT with the error code:
ERROR_DEVICE_NOT_MOUNTED is dependant on the settings of the 
'AssignMount' parameter in DosControl().

The return values are the opposite of what Auto/EasyRequest returns.

This function uses PRIVATERequester() internally to post the requester.
 
This routine always sets IoErr() to 'errorcode' before returning,
provided that the parameters are of the above recognised types,
otherwise IoErr() will not be changed.

**See also:** Fault(), IoErr()

---

### dos.library/ExamineDir

**Examine a complete directory of a filesystem. (V51.104)**

**Synopsis:**
```c
struct ExamineData *data = ExamineDir( APTR context );
```

**Description:**
Initiates and performs the examination of an entire directory level
specified by the parameters supplied to ObtainDirContext().  
Returns object data in the form of struct ExamineData nodes.

To scan an entire directory level, continue calling this function to
obtain successive entries until it returns NULL, when it does,
this normally indicates the end of the directory scan, be sure by
IoErr() returning ERROR_NO_MORE_ENTRIES for a successfull operation,
when finished, call ReleaseDirContext() to free the entire memory pool
all at once and to also release internal locks and other resources.

Linked Objects:
When performing a directory scan using this function, the link entries
in the listing will appear as hard or soft links, and optionally,
the examinedata->Link field will show the target object name/path,
if that flag option is enabled. (EXF_LINK)
The examinedata->Link string will always by default be "\0" for non
link entries, it will never be a NULL pointer. 

Softlink Type Testing:
Always set EX_DoCurrentDir,TRUE tag in the ObtainDirContext() call when
testing softlinks, this sets the current directory correctly for the
ExamineObject() call to handle link directory relative target specs.
Softlink target object type checking may also be required for targets
which are on a volume that isn't currently mounted, it is recommended
that DOS requesters be disabled during the ExamineObject() call to
prevent the standard "Please Insert Volume..." requester appearing.
See; SetProcWindow() for details.
If you got what you wanted, you might want to report the correct type
of link in the directory listing like Workbench, the ASL file requester,
the Dir and List commands, etc. do.

**Inputs:**
context - APTR; 
    A pointer to the DOS and FILESYSTEM private object context obtained
    from ObtainDirContext().  A NULL 'context' is guaranteed to be safe, 
    this will only return NULL without affecting IoErr().

**Result:**
data - struct ExamineData *;  
    A pointer to an ExamineData structure or NULL if there are no
    more entries remaining in a directory being scanned, or some other
    error occured, consult IoErr() to find out more.

    IoErr() returns ERROR_NO_MORE_ENTRIES at the end of a successfull
    directory scan, all other values indicate a failure of some sort.

    DO NOT call FreeDosObject() on the data blocks obtained from this
    function (unless you Remove() them from the internal list first),
    ReleaseDirContext() will free the entire data blocks memory pool 
    all at once for you automatically, when you are finished.

**Notes:**
You may abort a directory scan at any time, as long as you always 
eventually call ReleaseDirContext() to free the context data and
all the ExamineData blocks as well as releasing internal resources
and to restore the old current directory when EX_DoCurrentDir,TRUE,
was also specified.

You may restart a directory scan at any time with the same context,
by calling ObtainDirContext() again, using the EX_ResetContext tag.

All STRPTR fields of the ExamineData structure will never be NULL.
All string size fields will always be >= 1 to cater for "\0" strings.

Some ExamineData structure data is read-only, because the data blocks
are continually reused by subsequent calls to ExamineDir() to limit
the total amount of memory usage.

It is perfectly legal to call IExec->Remove() on an ExamineData block
immediately after the ExamineDir() call, to stop DOS or the FileSystem
from reusing it if it needs to be kept around for a while, it may even
be added to your own private list to store this data so you can avoid
slowing things down by making copies, however, the memory pool WILL
still be freed regardless of where it is when ReleaseDirContext()
is eventually called, so be aware of this situation if you decide to
use this feature in an application.
 
If you see an exd->Name string as "?", then you have likely failed to
specify the flag EXF_NAME in the ObtainDirContext() call even though
you are accessing the Name, AllocDosObject() sets this initial value
to assist in code debugging.

This function provides an automatic fallback to ExAll() if the
respective filesystem does not support this new function.
Fallback semantics and limitations will apply.

This function is NOT task callable.


                          ===== 


   EXAMPLE  (Single Level Directory Scan)

APTR context = IDOS->ObtainDirContextTags(EX_StringNameInput,"SYS:",
                EX_DataFields,(EXF_NAME|EXF_LINK|EXF_TYPE),
                TAG_END);
if( context )
{
    struct ExamineData *dat;

    while((dat = IDOS->ExamineDir(context)))  /* until no more data.*/
    {
 if( EXD_IS_LINK(dat) ) /* all links - check for these first ! */
 {
     if( EXD_IS_SOFTLINK(dat) )        /* a FFS style softlink */
     {
         IDOS->Printf("softlink=%s points to %s\n",
                                    dat->Name, dat->Link);
     }
     else                              /* hard or alt link to */
     {                                 /* a file or directory */
         IDOS->Printf("hardlink=%s points to %s\n", 
                                    dat->Name, dat->Link);
     }
 }
 else if( EXD_IS_FILE(dat) )           /* a file */
 {
     IDOS->Printf("filename=%s\n", dat->Name);
 }
 else if ( EXD_IS_DIRECTORY(dat) )     /* a directory */
 {
     IDOS->Printf("dirname=%s\n",  dat->Name); 
 }
 ....
    }
    if( ERROR_NO_MORE_ENTRIES != IDOS->IoErr() )
    {
 IDOS->PrintFault(IDOS->IoErr(),NULL); /* failure - why ? */
    }
}
else
{
    IDOS->PrintFault(IDOS->IoErr(),NULL);     /* failure - why ? */
}

IDOS->ReleaseDirContext(context);             /* NULL safe */


                          ===== 


   EXAMPLE  (Single Level Directory Scan with softlink resolution)

APTR context = IDOS->ObtainDirContextTags(EX_StringNameInput,"SYS:",
            EX_DoCurrentDir,TRUE, /* for ExamineObjectTags() */
            EX_DataFields,(EXF_NAME|EXF_LINK|EXF_TYPE), TAG_END);

if( context )
{
    struct ExamineData *dat, *target;

    while((dat = IDOS->ExamineDir(context)))  /* until no more data.*/
    {
 if( EXD_IS_LINK(dat) ) /* all links, must check these first ! */
 {
     if( EXD_IS_SOFTLINK(dat) )        /* a FFS style softlink */
     {
         CONST_STRPTR target_type = "unavailable"; /* default  */
         APTR oldwin = IDOS->SetProcWindow((APTR)-1); 
         target = IDOS->ExamineObjectTags(EX_StringNameInput,
                                            dat->Name,TAG_END);
         IDOS->SetProcWindow(oldwin);

         if( target )
         {
             if( EXD_IS_FILE(target) )
             {
                 target_type = "file";
             }
             if( EXD_IS_DIRECTORY(target) )
             {
                 target_type = "dir";
             }
             IDOS->FreeDosObject(DOS_EXAMINEDATA,target);
             /* Free target data when done */
         }
         IDOS->Printf("softlink=%s points to %s and it's a %s\n",
                          dat->Name,dat->Link,target_type);
     }
     else if( EXD_IS_FILE(dat) )       /* hardlink file */
     {
         IDOS->Printf("file hardlink=%s points to %s\n",
                          dat->Name, dat->Link);
     }
     else if( EXD_IS_DIRECTORY(dat) )  /* hardlink dir */
     {
         IDOS->Printf("dir hardlink=%s points to %s\n",
                          dat->Name, dat->Link);
     }
 }
 else if( EXD_IS_FILE(dat) )           /* a plain file */
 {
     IDOS->Printf("filename=%s\n", dat->Name);
 }
 else if ( EXD_IS_DIRECTORY(dat) )     /* a plain directory */
 {
     IDOS->Printf("dirname=%s\n",  dat->Name);
 }
    }

    if( ERROR_NO_MORE_ENTRIES != IDOS->IoErr() )
    {
 IDOS->PrintFault(IDOS->IoErr(),NULL); /* failure - why ? */
    }
}
else
{
    IDOS->PrintFault(IDOS->IoErr(),NULL);     /* failure - why ? */
}

IDOS->ReleaseDirContext(context);             /* NULL safe */


                          ===== 


   EXAMPLE  (Recursive Directory Scan)

int32 recursive_scan( CONST_STRPTR name )
{
    int32 success = FALSE;
    APTR  context = IDOS->ObtainDirContextTags( EX_StringNameInput,name,
                 EX_DoCurrentDir,TRUE, /* for recursive name cd */
                 EX_DataFields,(EXF_NAME|EXF_LINK|EXF_TYPE),
                 TAG_END);
    if( context )
    {
 struct ExamineData *dat;

 while((dat = IDOS->ExamineDir(context)))
 {
     if( EXD_IS_LINK(dat) ) /* all link types - check first ! */
     {
         if( EXD_IS_SOFTLINK(dat) ) 
         {
             IDOS->Printf("softlink=%s points to %s\n",
                                     dat->Name,dat->Link);
         }
         else   /* a hardlink or alt link */
         {
             IDOS->Printf("hardlink=%s points to %s\n",
                                  dat->Name, dat->Link);
         }
     }
     else if( EXD_IS_FILE(dat) )
     {
         IDOS->Printf("filename=%s\n", dat->Name);
     }
     else if( EXD_IS_DIRECTORY(dat) )
     {
         IDOS->Printf("dirname=%s\n",  dat->Name); 

         if( ! recursive_scan( dat->Name ) )  /* recurse */
         {
             break;
         }
     }
 }

 if( ERROR_NO_MORE_ENTRIES == IDOS->IoErr() )
 {
     success = TRUE;           /* normal exit */
 }
 else
 {
     IDOS->PrintFault(IDOS->IoErr(),NULL); /* failure - why ? */
 }
 
    }
    else
    {
 IDOS->PrintFault(IDOS->IoErr(),NULL);  /* no context - why ? */
    }

    IDOS->ReleaseDirContext(context);          /* NULL safe */
    return(success);
}

                          =====

**See also:** ObtainDirContext(),  ReleaseDirContext(), ExamineObject()

---

### dos.library/ExamineObject

**Examine a single filesystem object. (V51.104)**

**Synopsis:**
```c
struct ExamineData *data = ExamineObject(struct TagList *tags);

struct ExamineData *data = ExamineObjectTags(uint32 Tag1, ...);
```

**Description:**
Examines a single filesystem object specified by the tags.
Returns data in the form of a struct ExamineData.
The ExamineData block will be allocated for you by the filesystem,
by calling the AllocDosObject() function internally.

The filesystem will fill in the data structure members with current
information for the object.  If successfull, the returned data is 
used by the caller as needed, the caller must eventually release 
the ExamineData block by using the FreeDosObject() function;
    EG:  IDOS->FreeDosObject(DOS_EXAMINEDATA,data).

For an entire directory scan, use the new V51 function ExamineDir().

This function replaces the deprecated Examine() and ExamineFH()
functions which did not support 64 bit file sizes or long strings.

**Inputs:**
tags - a pointer to a TagItem array;
 Mandatory tag item to identify the source to examine.
 The following three tags are mutually exclusive.

 EX_LockInput (BPTR) -- BCPL pointer to a active Lock.
     Identify the filesystem object by this associated Lock.
     This lock is passed directly to the filesystem.
     The lock mode may be exclusive or shared.

 EX_FileHandleInput (BPTR) -- BCPL pointer to an open FileHandle.
     Identify the file by this associated FileHandle stream.
     This filehandle is passed directly to the filesystem.
     The file may be an exclusive or shared stream.

 EX_StringNameInput (STRPTR) -- Pointer to a nul-terminated 
     string, to specify the filesystem object required.
     This may be relative to the current directory an assignment
     or an absolute path.  DOS will internally perform a Lock()
     on the string provided, it will also Unlock() it again 
     after the filesystem call. 
     If the string name references a stream to a DOS handler
     that does not support locks, this option will then 
     attempt to call Open(old) on the name supplied, if that
     succeeds, the request will be sent to the handler,
     the internal stream will then be closed.

**Result:**
data -- (struct ExamineData *) on success, NULL on error.
     On error, consult IoErr() to find out more.
     On success, the data supplied must be released by the
     caller with; IDOS->FreeDosObject(DOS_EXAMINEDATA,data);

**Example:**
```c
dat = IDOS->ExamineObjectTags(EX_StringNameInput,"SYS:foo/bar",TAG_END);
if( dat )
{
    if( EXD_IS_FILE(dat) )
    {
 IDOS->Printf("filename=%s\n", dat->Name);
    }
    else if ( EXD_IS_DIRECTORY(dat) )
    {
 IDOS->Printf("dirname=%s\n",  dat->Name); 
    }
    //......

    IDOS->FreeDosObject(DOS_EXAMINEDATA,dat); /* Free data when done */
}
else
{
    IDOS->PrintFault(IDOS->IoErr(),NULL); /* failure - why ? */
}


                          =====
```

**Notes:**
This function provides automatic fallback to Examine() or ExamineFH()
if the respective filesystem does not support this new function.
Fallback semantics and limitations will apply.

This function is NOT task callable.


The returned data structure looks like this;

struct ExamineData
{
  struct MinNode EXDnode;      /* MinList node.                      */
  uint32         EXDinfo;      /* General purpose user data.         */
                        /*                                    */
  /* These are private members exclusively for the FS & DOS.         */
  uint32         FSPrivate;    /* FILESYSTEM ONLY - Private usage.   */
  uint32         Reserved0;    /* DOS RESERVED - Private usage.      */
  APTR           DOSPrivate;   /* DOSLIB ONLY - Private usage.       */
                        /*                                    */
  /* The following are public fields.                                */
  uint32         StructSize;   /* (RO) Full size of the structure.   */
  uint32         Type;         /* The entry descriptor value         */
  int64          FileSize;     /* Size if a file or -1LL if not.     */
  struct DateStamp Date;       /* Days, Mins, Ticks.                 */
  uint32         RefCount;     /* Object hardlink reference count.   */
  uint64         ObjectID;     /* The unique object identifier.      */
  STRPTR         Name;         /* (RO) Nul-terminated object name.   */
  uint32         NameSize;     /* (RO) Size of the name buffer.      */
  STRPTR         Comment;      /* (RO) Nul-terminated comment.       */
  uint32         CommentSize;  /* (RO) Size of the comment buffer.   */
  STRPTR         Link;         /* (RO) -- Unused by ExamineObject(). */
  uint32         LinkSize;     /* (RO) -- Unused by ExamineObject(). */
  uint32         Protection;   /* Protection status bitmask          */
  uint32         OwnerUID;     /* Owner info. Only low 16 bits used. */
  uint32         OwnerGID;     /* Group info. Only low 16 bits used. */
  uint32         Reserved2;    /* DOS reserved field.                */
  uint32         Reserved3;    /* DOS reserved field.                */
  uint32         Reserved4;    /* DOS reserved field.                */
}; 
(RO) = Read Only, these fields must not be modified by the application.
See structure definition in include/dos/dos.h for detailed information.
 
                          =====

**See also:** ObtainDirContext(), ExamineDir(), FreeDosObject(), SetProcWindow().

---

### dos.library/Fault (V36)

**Returns the text associated with a DOS error code.**

**Synopsis:**
```c
int32 len = Fault(int32 code, CONST_STRPTR header, STRPTR buffer,
           int32 buflen);
```

**Description:**
This routine obtains the error text for the given error code,
formats it and puts a null-terminated string into the buffer.
By convention, error messages should not be longer than 80 characters,
and preferably no more than 60.

If the error code is not equal to zero and there is no text for that
particular error code, the message used will be "Error code <number>".

The value returned by IoErr() will be set to the code passed in.

**Inputs:**
code   - Error code
header - header string to output before error text. (NULL for none)
buffer - Buffer to receive the formatted error message.
buflen - Length of the buffer.

**Result:**
len    - Number of characters put into the buffer, (may be 0)

**Notes:**
The number of characters put into the buffer is returned, 
which will be 0 if the code passed in was 0.

**Bugs:**
In older documentation, the return was shown as BOOLEAN success.
This was incorrect, it has always returned the length.

**See also:** IoErr(), SetIoErr(), PrintFault()

---

### dos.library/FFlush (V36)

**Flushes buffers for a buffered filehandle.**

**Synopsis:**
```c
int32 success = FFlush(BPTR fh);
```

**Description:**
Flushes any pending buffered writes to the filehandle.  All buffered
writes will also be flushed on FClose().  If the filehandle was being
used for input, it drops the buffer, and tries to change the file 
pointer back to the last read position  (so subsequent reads or writes
will occur at the expected position in the file).

**Inputs:**
fh      - Filehandle to flush.  (0 is safe - does nothing.)

**Result:**
success - boolean; (zero or non-zero value)

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

Before V51, this function was called Flush(). Renamed for consistency.

**Bugs:**
Before V37 release, FFlush() returned a random value.  As of V37,
it always returns success (this will be fixed in some future
release).

The V36 and V37 releases didn't properly flush filehandles which
have never had a buffered IO done on them.  This commonly occurs
on redirection of input of a command, or when opening a file for
input and then calling CreateNewProc() with NP_Arguments, or when
using a new filehandle with SelectInput() and then calling
RunCommand().  This is fixed in V39.  A workaround would be to
do FGetC(), then UnGetC(), then FFlush().

**See also:** FPutC(), FGetC(), FRead(), FWrite(), FClose(), FOpen() 
CreateNewProc(), SelectInput(), RunCommand(), SetFileHandleAttr()
   <dos/stdio.h>

---

### dos.library/FGetC (V36)

**Read a character from the specified input. (buffered)**

**Synopsis:**
```c
int32 character = FGetC(BPTR fh);
```

**Description:**
Reads the next character from the input stream.  
An EOF value (-1L) is returned when the EOF or an error occurs.  

This call is buffered.
Use FFlush() between buffered and unbuffered I/O on a filehandle.

**Inputs:**
fh - filehandle to use for buffered I/O

**Result:**
character - character read (0-255 in lower byte) or -1L for EOF.
     If 'fh' is NULL, this function immediately returns EOF.

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.  If you are NOT sharing this filehandle between
separate processes, this function can be sped up substantially by
disabling semaphore locking with SetFileHandleAttr().

**Bugs:**
In V36, after an EOF was read, EOF would always be returned from
FGetC() from then on.  Starting in V37, it tries to read from the
handler again each time (unless UnGetC(fh,-1) was called).

**See also:** FPutC(), UnGetC(), FFlush(), SetFileHandleAttr().

---

### dos.library/FGets (V36)

**Reads a line from the specified input (buffered)**

**Synopsis:**
```c
STRPTR buffer = FGets(BPTR fh, STRPTR buf, uint32 len);
```

**Description:**
This routine reads in a single line from the specified input stopping
at a newline, (or carriage return character for V50+), or EOF.  
In either event, UP TO the number of len specified bytes minus 1 will
be copied into the buffer.  Hence if a length of 50 is passed and the
input line is longer than 49 bytes, it will return 49 characters.
It returns the buffer pointer normally, or NULL if EOF is the first
thing read.

If terminated by a newline character ("\n"), the newline WILL be the
last character in the buffer.  This is a buffered read routine.
The string read in is always null-terminated.

**Inputs:**
fh  - filehandle to use for buffered I/O
buf - Area to read bytes into.
len - Number of bytes to read, must ALWAYS be > 0.

**Result:**
buffer - Pointer to buffer passed in, or NULL for immediate EOF or
  for an error. 

In V50, this function guarantees that 'buf' is initialised with '\0'
(providing you have supplied a valid 'len' > 0 and 'buf' != NULL)

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

From dos.library 53.19, for PPC callers, carriage return characters
('\r') are treated as if they were also newline characters ('\n'),
Emulated 68K callers will get the V40 legacy ('\n') only behaviour.

**Bugs:**
In V36 and V37, it copies one more byte than it should if it doesn't
hit an EOF or newline.  In the example above, it would copy 50 bytes
and put a null in the 51st.  This is fixed in dos V39.  Workaround
for V36/V37: pass in buffersize-1.

**See also:** FRead(), FPuts(), FGetC(), FOpen(), FClose(), SetFileHandleAttr().

---

### dos.library/FileHandleScan

**Low level routine to scan through the DOS filehandle
           list.  (V53.129)**

**Synopsis:**
```c
int32 result = FileHandleScan( const struct Hook *hook, 
                        CONST_APTR userdata, uint32 reserved);
```

**Description:**
This function will scan through the list of open filehandles and invoke
the hook function for each one, or until the scanning is discontinued
intensionally.

It is guaranteed that the DOS filehandle list will NOT be able to 
change while inside this function, as it uses shared semaphore locking.
Opening or Closing files require exclusive locking.
These events cannot complete while a shared semaphore lock is in force,
any task/process attempting to open or close a filehandle will be put
to sleep until the shared semaphore is released, so don't loiter here.

**Inputs:**
hook     -- (const struct hook *)
     The hook function will be called for every open filehandle.
     You MUST initialise the hook struct h_Entry field to the
     function address to call before invoking this routine.

     The hook will be called as follows:

     int32 result = hook_func(struct hook *hook, APTR userdata,
                              struct FileHandle *file)

     If the hook function returns 0, the scan will continue.

     If the hook function returns a non-zero value, this 
     indicates that the scan should be aborted (e.g. when the
     item in question has been found).
     This non-zero return value will also be passed on and 
     returned as the result of the FileHandleScan() function. 

userdata -- (CONST_APTR) 
     This parameter is passed to the hook function untouched.
     It may be used for any purpose.

reserved -- (uint32)
     Reserved for future functional expansion.
     This parameter MUST always be set to 0 for now.
     If it is not set to zero, this function will fail.

**Result:**
result   -- (int32) - boolean; (zero or non-zero), 

  -- Zero indicates that you never returned a non-zero result
     from your hook before running out of open filehandles.

  -- All non-zero values indicate success and will actually be
     the value that you returned from your hook function.



                      -----


   EXAMPLE 1
Count the number of open files, exclude NIL: streams.

STATIC int32 ASM hookfunc1( REG(a0, struct Hook *hook) UNUSED,
                     REG(a2, uint32 *counter), /* userdata */
                     REG(a1, struct FileHandle *afh))
{
    if( NULL != afh->fh_MsgPort )     /* exclude NIL: streams */
    {
 (*counter) ++;                /* increment counter */
    }
    return(0);                        /* 0 = continue scan */
}
   
/* This function starts the hook calls via FileHandleScan() */
uint32 Count_Open_Files(void)
{
    struct Hook H;
    uint32 count; /* we pass a pointer to this as 'userdata' */

    count =0;                         /* set initial count to zero  */
    H.h_Entry = (APTR) hookfunc1;     /* initialise the hook struct */
    IDOS->FileHandleScan(&H, &count, 0); 

    IDOS->Printf("There were %lu streams open.\n", count);
    return( count );
}
   
                      -----


   EXAMPLE 2
Count the number of open filesystem files, exclude all others.

STATIC int32 ASM hookfunc2( REG(a0, struct Hook *hook) UNUSED,
                     REG(a2, uint32 *counter), /* userdata */
                     REG(a1, struct FileHandle *afh))
{
    if( IDOS->IsFileSystemPort(afh->fh_MsgPort) )
    {
 (*counter) ++;                /* increment counter */
    }
    return(0);                        /* 0 = continue scan */
}
   
/* This function starts the hook calls via FileHandleScan() */
uint32 Count_Open_Filesystem_Files(void)
{
    struct Hook H;
    uint32 count; /* we pass a pointer to this as 'userdata' */

    count =0;                         /* set initial count to zero  */
    H.h_Entry = (APTR) hookfunc2;     /* initialise the hook struct */
    IDOS->FileHandleScan(&H, &count, 0); 

    IDOS->Printf("There were %lu filesystem files open.\n", count);
    return( count );
}

                      -----


   EXAMPLE 3
Creates a list of all open filehandles to display name and type data.

STATIC int32 ASM hookfunc3( REG(a0, struct Hook *hook) UNUSED,
                     REG(a2, struct List *list), /* userdata */
                     REG(a1, struct FileHandle *stream))
{
    struct BNode   /* A node plus buffer space in one allocation. */
    {
 struct Node Node;
 TEXT   Buffer[1];
    };
    struct BNode *bode;
    int32  namesize;
    TEXT   name[256], buff[356];

    #define YESNOSTR(x)  ((x) ? "YES" : "NO")

    BPTR  bscb  = MKBADDR(stream); /* a BPTR for dos funcs */
    int32 inter = IDOS->IsInteractive(bscb);
    int32 isfs  = IDOS->IsFileSystemPort(stream->fh_MsgPort);

    
    if( ! IDOS->NameFromFH( bscb, name, sizeof(name) ) )
    {
 IUtility->SNPrintf(name,sizeof(name),"[Stream 0x%08lx]",stream);
    }

    namesize = 1 + IUtility->SNPrintf(buff,sizeof(buff), 
"%s\nOpened by PID=%lu    Interactive=%s    IsFileSystem=%s\n\n",
    name, stream->fh_OpenerPID, YESNOSTR(inter), YESNOSTR(isfs));

    bode = IExec->AllocVecTags( namesize + sizeof(struct BNode),  
                 AVT_Type,MEMF_SHARED, AVT_Lock,FALSE, TAG_END );
    if( bode )
    {
 IUtility->Strlcpy(bode->Buffer, buff, namesize);
 bode->Node.ln_Name = bode->Buffer;  /* init node name ptr */
 IExec->AddTail(list, &bode->Node);
 return(0);  /* 0 = continue scan */
    }
    return(1);      /* !=0 = abort scan  */
}

/* This function starts the hook calls via FileHandleScan() */
void Print_File_List(void)
{
    struct Hook HOOK;
    struct List LIST;
    struct Node *node;

    IExec->NewList(&LIST);  /* init the list */
    HOOK.h_Entry = (APTR) hookfunc3; /* init the hook */

    IDOS->FileHandleScan(&HOOK, &LIST, 0);

    /* Print the list and free the memory immediately afterwards */
    while(( node = IExec->RemHead(&LIST) ))
    {
 IDOS->PutStr(node->ln_Name);
 IExec->FreeVec(node);
    }
    return;
}

                      -----

**Notes:**
A filehandle node is added to the internal list after it is actually
opened, and removed just before it is closed, so only open streams
will be found by this function.

To differentiate filehandles for a particular volume or handler,
simply compare the fh_MsgPort against the handlers message port address.
Be aware that the fh_MsgPort will be NULL for DOS "NIL:" filehandles.
Use IDOS->IsFileSystemPort() to differentiate real files from handler
streams.

Both 68K and Native callable hook constructs are shown in the example.

**See also:** Open(), Close(), IsFileSystemPort(), IsInteractive().

---

### dos.library/FilePart (V36)

**Returns the last component of a path**

**Synopsis:**
```c
CONST_STRPTR fileptr = FilePart( CONST_STRPTR path );
```

**Description:**
This function returns a pointer to the last component of the string 
path specification, which will normally be the file name.  
If there is only one component, it returns a pointer to the 
beginning of the string.

**Inputs:**
path - pointer to a path string.

**Result:**
fileptr - pointer to the last component of the path.

**Example:**
```c
FilePart("xxx:yyy/zzz/qqq") would return a pointer to the first 'q'.
FilePart("xxx:yyy") would return a pointer to the first 'y'.
FilePart("xxx:") would return a pointer to the end 0 byte.
FilePart("xxx:yyy/") would also return a pointer to the 0 byte.
FilePart("nopath") would return a pointer to the letter 'n'.
```

**Notes:**
From V50 this function is task callable.
This function will not affect IoErr().
If you pass a NULL 'path' argument, this function will return NULL.

**See also:** PathPart(), AddPart()

---

### dos.library/FileSystemAttr

**Get and Set attributes for a filesystem (V51.46)**

**Synopsis:**
```c
int32 success = FileSystemAttr(const struct TagItem *tags);

int32 success = FileSystemAttrTags(uint32 Tag1, ...);
```

**Description:**
This function allows you to access various attributes of a given
filesystem that is mounted on top of a disk driver, such as a hard 
or floppy disk.  

The FileSystemAttr() function provides a simple method for reading 
parameters or setting values for filesystems supporting this feature.
This function will only succeed if the underlying filesystem expressly
supports a particular option, otherwise, it will generally return a 
failure code, (unless dos.library can supply the required information.)

This function works by using a taglist to supply or obtain information,
the taglist items are passed through to the underlying filesystem, 
the options are defined in such a way, as to provide specific tags that
are used in either read or write mode.

**Inputs:**
tags -- Pointer to a tagitem array for the options listed below.

   SOURCE TAGS ; Mandatory tag item to enable filesystem identification.
       The following four tags are mutually exclusive and
       are not passed through to the filesystem itself.

FSA_StringNameInput (STRPTR) -- Pointer to a string identifier.
    (See GetDeviceProcFlags() for details about this.)

FSA_FileHandleInput (BPTR) -- BCPL pointer to a FileHandle.
    Identify the filesystem by the stream pointed to by a FileHandle.
    The opening mode does not affect identification.

FSA_LockInput   (BPTR) -- BCPL pointer to a Lock.
    Identify the filesystem by this associated Lock.
    The lock mode does not affect the identification.

FSA_MsgPortInput   (struct MsgPort *) -- Pointer to a message port.
    Identify the filesystem by this associated message port.
    ( NOTE: This tag was added in 51.96 )

                            ===

   READ TAGS ; The taglist options to Read filesystem information.

FSA_MaxFileNameLengthR (uint32 *) -- Pointer to a uint32 storage area.
    Obtain the maximum filename length permitted. (not including \0) 

    NOTE: The DOS library will attempt to extrapolate this value 
   if the filesystem does not support this option, the volume
   needs to be write enabled to support length extrapolation.

FSA_DOSTypeR (uint32 *) -- Pointer to a uint32 storage area.
    Obtain the dostype identifier for the filesystem. 
    EG: 0x444F5303 = 'DOS\03'   (See NOTES section below.)

FSA_VersionNumberR (uint32 *) -- Pointer to a uint32 storage area.
    Obtain the filesystem version number as; (MAJOR<<16) | MINOR)

FSA_VersionStringR (STRPTR) -- Pointer to a string buffer area.
    Obtain a copy of the version string for the filesystem.
    The version string will be the full version string in the same
    format as the 'bumprev' tools VSTRING, this being; 
  "filesystem_name VER.REV (dd.mm.yyyy)"

    NOTE: DOS library will attempt to extrapolate this value if the 
   filesystem does not support this option, by searching for a
   $VER: cookie in the device nodes seglist. Note that the 
   result buffer will have $VER: part removed, if one is found.

    You are required to specify the size of your string buffer area
    with the following sub-tag; FSA_VersionStringR_BufSize
    Failing to supply this tag will cause ERROR_REQUIRED_ARG_MISSING
    to be returned by IoErr(). 
    (Dos.library tests for this before calling the filesystem)

    FSA_VersionStringR_BufSize (uint32) -- Size of the buffer pointed
to by the FSA_VersionStringR tag. Recommended minimum; 60 bytes.
Note: You are guaranteed that no more than this number of bytes
      will be written to your buffer area, if the storage area
      is smaller than the version string, it will fail with the
      secondary error code; ERROR_LINE_TOO_LONG.

FSA_ActivityFlushTimeoutR (uint32 *) --Pointer to a uint32 storage area.
    Obtain the time in milliseconds before a flush while active occurs.
    ( 1000mS = 1 second)

FSA_InactivityFlushTimeoutR	(uint32 *) --Pointer to uint32 storage area.
    Obtain the time in milliseconds before a flush when inactive occurs.
    ( 1000mS = 1 second)

FSA_HasRecycledEntriesR	(int32 *) -- Pointer to a int32 storage area.
    Boolean test to see if the filesystem supports recycled entries.
    Note: This tag exists because the following FSA_MaxRecycledEntriesR
   tag allows for zero to indicate a valid number.

FSA_MaxRecycledEntriesR (uint32 *) -- Pointer to a uint32 storage area.
    Obtain the number of recycled entries supported by the filesystem.
    Note: This may be zero, even if recycled entries are supported.

                            ===

   TAGS ; The taglist options to Set features for the filesystem.

FSA_MaxFileNameLengthW (uint32) -- New value to set in filesystem.
    Set the maximum filename length. (not including \0)
    Note; this option may have limited support, if any.

FSA_ActivityFlushTimeoutW (uint32) -- New value to set in filesystem.
    Set the time in milliseconds before a flush while active occurs.
    ( 1000mS = 1 second)

FSA_InactivityFlushTimeoutW	(uint32) -- New value to set in filesystem.
    Set the time in milliseconds before a flush when inactive occurs.
    ( 1000mS = 1 second)

FSA_MaxRecycledEntriesW (uint32) -- New value to set in filesystem.
    Set the number of recycled entries supported by the filesystem.

**Result:**
success -- (int32; boolean), returns FALSE for failure of any option.

If the filesystem does not support a particular option, it will 
immediately return FALSE, with ERROR_NOT_IMPLEMENTED in IoErr().

**Notes:**
This function is NOT callable from a task.

This function will return FALSE if a file system option requested
could not be obtained or an option is not relevant for the specified
filesystem, or the value specified in a (W)rite operation was illegal.
Check the secondary error with IoErr() to find out more.

If a displayable ASCII representation of the result from FSA_DOSTypeR
is required for an application, we recommend the following standard
method be used to convert the dostype value into ASCII text;

    uint32 dt = ;   /* pre initialize this with the dostype value. */
    TEXT   buf[8];  /* minimum recommended buffer size */
    CONST_STRPTR format = 
   ((dt & 0xFF) > 0x20) ? "%lc%lc%lc%lc" : "%lc%lc%lc\\%02lx";

    IUtility->SNPrintf(buf,sizeof(buf), format,
   (dt>>24) & 0xFF, (dt>>16) & 0xFF, (dt>>8) & 0xFF, dt & 0xFF);

**See also:** GetDiskFileSystemData(), FreeDiskFileSystemData(), GetDeviceProcFlags().

---

### dos.library/FindArg (V36)

**Synopsis:**
```c
int32 index = FindArg(CONST_STRPTR template, CONST_STRPTR keyword);
```

**Description:**
Returns the argument number of the keyword, or -1 
if it is not a keyword in the supplied template.  
Abbreviations are also compared.

Template args are delimited by a comma, equals or slash ( , = / )

**Inputs:**
keyword  - keyword to search for in template (case insensitive)
template - template string to search

**Result:**
index - entry number in template, or -1 if not found.

**Notes:**
From V50, this function is callable from tasks.

**Bugs:**
In earlier published versions of the autodoc, keyword and template
argument positions were reversed.

**See also:** ReadArgs(), ReadLineItem(), FreeArgs()

---

### dos.library/FindCliProc (V36)

**returns a pointer to the requested CLI process.**

**Synopsis:**
```c
struct Process *proc = FindCliProc(uint32 num);
```

**Description:**
This routine returns a pointer to the CLI process associated with the
given CLI number.  
If the process isn't an active CLI process, NULL is returned.  

   V51 LOCKING 
Even though this function will always use a READ (shared) Semaphore 
lock within this function, the returned value may be invalidated at
any moment after this function returns, as processes may exit any time,
usually immediately after you thought you had found it.

From V51+ you MUST use the appropriate Semaphore locking around an
entire routine that requires that the cli process list status remains
unchanged between function calls and that the result returned here
also remains valid.  

Obtain the semaphore from the public semaphore list by calling;
     cpsem = IExec->FindSemaphore("DosCliProc");
The semaphore pointer may be cached for the duration of the task.
Note also that the name is case sensitive.

For all READ operations, call;  IExec->ObtainSemaphoreShared(cpsem);
this call must be matched with a; IExec->ReleaseSemaphore(cpsem);

**Inputs:**
num  - (uint32) CLI number of the CLI process. (range 1-n)

**Result:**
proc - (struct Process *) Pointer to given CLI process. ( or NULL )

**Notes:**
While holding a READ semaphore lock on the DOS CLI Process list,
it will not be possible for a process to start or finish terminating,
as they require that the CLI process list be exclusively WRITE locked
to add or remove their node, therefore it is advised you not loiter.

**See also:** Cli(), MaxCli(), exec/ObtainSemaphoreShared(), exec/ReleaseSemaphore()

---

### dos.library/FindDosEntry (V36)

**Finds a specific Dos List entry.**

**Synopsis:**
```c
struct DosList *newdlist = FindDosEntry(const struct DosList *dlist,
                            CONST_STRPTR name, uint32 flags);
```

**Description:**
Locates an entry on the device list.  Starts with the entry 'dlist'.

NOTE: must be called with the device list locked (via LockDosList()
or AttemptLockDosList()), no references may be made to 'dlist' after
unlocking.

**Inputs:**
dlist    - The device entry to start with.  (NULL safe)
name     - Name of device entry (without ':') to locate. (or NULL)
flags    - Search control flags.  Use the flags you passed to
    LockDosList, or a subset of them.  LDF_READ/LDF_WRITE are
    not required for this call, but harmless if included.

**Result:**
newdlist - The matching device list entry or NULL.

**Example:**
```c
When searching for multiple types, eg: LDF_VOLUMES|LDF_DEVICES,
to retrieve multiple entries, you must call NextDosEntry() after 
finding the first entry to increment 'dl' past the current node,
otherwise it will continue to be found again, and again, and again.
This will allow you to continue searching the rest of the list
beginning again one entry past the current node.

flags = LDF_VOLUMES|LDF_DEVICES|LDF_READ;
dl = IDOS->LockDosList(flags);

while(( dl = IDOS->FindDosEntry(dl,"name",flags) ))
{
	entry_found();

	dl = IDOS->NextDosEntry(dl,flags);
}

IDOS->UnLockDosList(flags);
```

**Notes:**
If you supply a NULL 'name', the name parameter will be ignored and 
only the flags will be compared to determine a match, this is 
effectively the same as using a NextDosEntry() loop only.

Supplying a NULL 'dlist' will simply cause a NULL return value.
For compatibility reasons, IoErr() is not currently affected by 
this function.

This function performs no locking or waiting, therefore is callable
from handlers and filesystems.

If using both V54+ Utility and DOS libraries, this function works
with a UTF-8 encoded strings.

**See also:** AddDosEntry(), RemDosEntry(), NextDosEntry(), LockDosList(),
MakeDosEntry(), FreeDosEntry()

---

### dos.library/FindSegment (V36)

**Synopsis:**
```c
struct DosResidentSeg * drs = FindSegment( CONST_STRPTR name, 
          const struct DosResidentSeg * start, int32 system);
```

**Description:**
Finds a DosResidentSeg on the Dos resident list by name and type, 
starting at the entry AFTER 'start', or at the beginning if start is 0.
If 'system' is FALSE, it will only return entries with a seg_UC 
of >= 0.   This function never alters the seg_UC value.

This function does NOT perform any locking of the list itself.

   V51 LOCKING 
From V51+ you MUST use the appropriate Semaphore locking before 
calling this function.  Obtain the semaphore from the public 
semaphore list by calling;  drsem = FindSemaphore("DosResident");
The semaphore pointer may be cached for the duration of the task.

For all WRITE operations, call;  ObtainSemaphore(drsem);
For all READ (only) operations, call;  ObtainSemaphoreShared(drsem);
Either of the above calls must be matched with a ReleaseSemaphore();

To use an entry you have found, you must: if the seg_UC is zero or 
greater, increment it, and decrement it (if it's >0) when you're 
done with the list.  (all while still WRITE semaphore locked!) 

The other values for seg_UC are:
	CMD_SYSTEM   = -1, a system module, such as a filesystem or shell.
	CMD_INTERNAL = -2, a resident shell command.
	CMD_DISABLED = -999, a disabled internal module/command.

Negative values should never be modified.  All other negative
values between 0 and -32767 are reserved by AmigaDos and should
not be used by anyone else.

**Inputs:**
name   - Name of DosResidentSeg entry to find. (or NULL)
start  - DosResidentSeg to start the search after. (or NULL)
system - DOSTRUE for (negative seg_UC) system entries, FALSE for others.

**Result:**
drs    - the DosResidentSeg pointer found, or NULL.
  If NULL, IoErr() will return ERROR_OBJECT_NOT_FOUND.

   V50 NOTES
Prior to V50 a NULL 'name' parameter was illegal and would cause
an invalid memory access with indeterminant results.
From DOS 50.77, this is no longer the case, instead, if the 'name'
parameter is set to NULL, the name string comparison will simply 
be skipped and the first entry that matches the 'system' flag state
will be returned from this function as a valid match, this also 
provides a method for scanning through the whole DosResidentSeg list.

**Notes:**
The default filesystem seglist can also be obtained here by using
"FileHandler" as the search string with DOSTRUE as 'system' flag.
Access to the; "con-handler", "CLI", "Shell", "BootShell" and 
some other seglists are also available via this function.
This backwardly compatible method supercedes the old methods of
peeking into the private DosLibrary base rootnode structure.

**Bugs:**
For backward compatibility reasons, some software may use a Seg_UC
value of one to indicate zero usage, rather than zero.
This should be fixed in a future release.

**See also:** AddSegment(), RemSegment(), ObtainSemaphore(), ReleaseSemaphore() 
FindSemaphore().

---

### dos.library/FindVar (V36)

**Finds a local variable.**

**Synopsis:**
```c
struct LocalVar *var = FindVar(CONST_STRPTR name, uint32 type );
```

**Description:**
Finds a local variable structure.

**Inputs:**
name - pointer to a variable name.  Note variable names follow
filesystem syntax and semantics.

type - type of local variable to be found (see <dos/var.h>)
Current types are; LV_VAR and LV_ALIAS.

**Result:**
var  - pointer to a LocalVar structure or NULL on failure.

**Notes:**
This function is NOT task callable.

**See also:** GetVar(), SetVar(), DeleteVar(), <dos/var.h>

---

### dos.library/FlushVolume

**Cause a filesystem to flush outstanding writes. (V53.58)**

**Synopsis:**
```c
int32 success = FlushVolume( CONST_STRPTR name );
```

**Description:**
Forces all pending writes to be written to the respective media.
Also causes the motor to be turned off, if it has one.

This call is syncronous, in that it does not return until the 
filesystem has completely finished the operation.

**Inputs:**
name    - (STRPTR)  Null-terminated string to identify the filesystem.
   (See GetDeviceProcFlags() for details about this.)

**Result:**
success - (BOOLEAN) Zero for failure, non-zero for success.

**Notes:**
This function is NOT task callable.

**See also:** FlushVolumePort(), GetDeviceProcFlags(), 
DevNameFromLock(), DevNameFromFH(), DevNameFromPort().

---

### dos.library/FlushVolumePort

**Cause a filesystem to flush outstanding writes. (V53.90)**

**Synopsis:**
```c
int32 success = FlushVolumePort( struct MsgPort *port );
```

**Description:**
Sends a flush request to the filesystem identified by the message port.
This forces all pending writes to be written to the respective media.
Also causes the motor to be turned off, if it has one that can be.

This call is syncronous, in that it does not return until the 
filesystem has completely finished the operation.

**Inputs:**
port    - (struct MsgPort *) Pointer to the handler message port.

**Result:**
success - (BOOLEAN) Zero for failure, non-zero for success.

**Notes:**
This function is NOT task callable.

**See also:** FlushVolume().

---

### dos.library/Format (V36)

**Causes a filesystem to initialize itself**

**Synopsis:**
```c
int32 success = Format(CONST_STRPTR filesystem,CONST_STRPTR volumename,
                uint32 dostype);
```

**Description:**
Initialize new media on a device.  This causes the filesystem to write
out an empty disk structure to the media, which should then be ready 
for use.  This assumes the media has been low-level formatted and 
verified already.

The filesystem MUST be inhibited before calling Format() to make
sure you don't get a failure with error code ERROR_OBJECT_IN_USE.

**Inputs:**
filesystem - Name of DEVICE to be formatted.  (':' must be supplied).
volumename - Name for volume (if supported).  (No ':').
dostype    - Type of format, if filesystem supports multiple types.

**Result:**
success    - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
From V51.30 this function will fail if the name supplied is not the
DEVICE name of the filesystem, volume names will be rejected.

This function is NOT task callable.

**Bugs:**
Existed, but was non-functional in V36 dos.  (The name wasn't
converted to a BSTR.)  Workaround: require V37, or under V36
convert volumename to a BPTR to a BSTR before calling Format().
Note: a number of printed packet docs for ACTION_FORMAT are wrong
as are the arguments.

**See also:** FormatPort(), Serialize(), Inhibit(), DevNameFromLock(), 
DevNameFromFH(), DevNameFromPort(), GetDeviceProcFlags().

---

### dos.library/FormatPort

**Causes a filesystem to initialize itself (V53.88)**

**Synopsis:**
```c
int32 success = FormatPort(struct MsgPort *port, 
                       CONST_STRPTR volumename,
                           uint32 dostype);
```

**Description:**
Initialize new media on a device.  This causes the filesystem to write
out an empty disk structure to the media, which should then be ready 
for use.  This assumes the media has been low-level formatted and 
verified already.

The filesystem MUST be inhibited before calling FormatPort() to make
sure you don't get an ERROR_OBJECT_IN_USE.

**Inputs:**
port       - Message Port of filesystem to be formatted.
volumename - Name for volume (if supported).  (No ':').
dostype    - DosType of format, if filesystem supports multiple types.

**Result:**
success    - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
This function is NOT task callable.
This function provides no locking for the 'port' of the handler.

**See also:** Format(), Serialize(), Inhibit(), DevNameFromLock(), DevNameFromFH(), 
DevNameFromPort(), GetDeviceProcFlags().

---

### dos.library/FPrintf (V36)

**format and print a string to a file. (buffered)**

**Synopsis:**
```c
int32 count = FPrintf(BPTR fh, CONST_STRPTR fmt, ...);

int32 count = VFPrintf(BPTR fh, CONST_STRPTR fmt, CONST_APTR argv);
```

**Description:**
Writes the formatted string and values to the given file.  This
routine is assumed to handle all internal buffering so that the
formatting string and resultant formatted values can be arbitrarily
long.  Any secondary error code is returned in IoErr().  This routine
is buffered.  See Notes for extended new V51 DOS format specifiers.

**Inputs:**
fh    - Filehandle to write to, (or 0).
fmt   - RawDoFmt() style formatting string
argv  - Pointer to array of formatting values

**Result:**
count - Number of bytes written or -1 (EOF) for an error.

**Example:**
```c
(1)     count = IDOS->FPrintf(fh,"%ld+%ld=%ld.\n", 1,2,3);

(2)     int32 array[3] = { 1,2,3 };
 count = IDOS->VFPrintf(fh,"%ld+%ld=%ld.\n", &array[0]);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

From 51.59 all DOS (only) string formatting functions now accept 
two additional special DOS format specifiers;  %m and %n.
These will be replaced by the error message (%m) such as would be
obtained by the Fault() function and the error number (%n) as returned
from IoErr() that was valid at the time this function was called.
In all other respects these functions work like they always did.

EG: 
count = IDOS->FPrintf(fh,"error message = %m, error code = %n\n",...);

This new functionality may need to allocate temporary memory before
it can print the error message. However, if the error came about 
because of memory shortage then the message/value string insertion 
may not be performed at all.

Internally, this function transforms the format string to include
the respective error message/number strings; these must not contain
format specifiers themselves or the underlying RawDoFmt() function
will end up trying to fetch parameters off the argument list which
are not available. To prevent this possibility, when the error message
is being inserted, any '%..' format specifiers found in the actual
error message will be removed entirely to prevent this happening.

**Bugs:**
The prototype for FPrintf() currently forces you to cast the first
varargs parameter to LONG due to a deficiency in the program
that generates fds, prototypes, and amiga.lib stubs.

From V50, it is now documented as safe to supply a 'fh' of zero, 
this function will and always did nothing but return -1.  (EOF).

There is currently a minor problem when using 64 bit stack args.
The current compiler for OS4 enforces 64 bit alignment of 64 bit
arguments, but Printf assumes 32 bit alignment (VARARGS68K).
It is relatively easy to workaround by making sure 64 bit arguments
are aligned appropriately.  Carefull placement of parameters will
be sufficient. eg;   

IDOS->FPrintf(fh,"%lld %ld\n", 64bit_val, 32bit_val);       /* works */
IDOS->FPrintf(fh,"%ld %lld\n", 32bit_val, 64bit_val);       /* fails */
IDOS->FPrintf(fh,"%ld %s%lld\n", 32bit_val, "", 64bit_val); /* works */
 
Therefore, always use carefull placement or pad 64 bit values with
empty 32 bit string ("") arguments to attain 64 bit alignment when
using 64 bit parameters with this function.

**See also:** VPrintf(), RawDoFmt(), FPutC(), FOpen(), FClose(),SetFileHandleAttr().

---

### dos.library/FPutC (V36)

**Write a character to the specified output. (buffered)**

**Synopsis:**
```c
int32 reschar = FPutC(BPTR fh, int32 character);
```

**Description:**
Writes a single character to the output stream.  This call is
buffered.  Use FFlush() between buffered and unbuffered I/O on a
filehandle.  Interactive filehandles are flushed automatically
on a newline, carriage return or '\0'.

**Inputs:**
fh        - filehandle to use for buffered I/O
character - character to write, (int32 value in the range 0-255)

**Result:**
reschar   - either the character written, or EOF for an error.

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function. 
If you are not sharing this filehandle between multiple tasks,
this function can be sped up substantially by disabling the
semaphore locking with SetFileHandleAttr(). 

Calling FPutC() with a NULL filehandle is safe, it just returns
ENDSTREAMCH if this situation occurs.

**Bugs:**
Older autodocs indicated that the 'character' was uint8.
The correct usage is to pass a 32 bit variable in the range 0-255.

**See also:** FGetC(), UnGetC(), FFlush(), SetFileHandleAttr()

---

### dos.library/FPuts (V36)

**Writes a string to the specified output. (buffered)**

**Synopsis:**
```c
int32 error = FPuts(BPTR fh, CONST_STRPTR str);
```

**Description:**
This routine writes an unformatted string to the filehandle.
No newline is appended to the string.  This routine is buffered.

**Inputs:**
fh    - filehandle to use for buffered I/O
str   - Null-terminated string to be written to default output

**Result:**
error - boolean; (zero or non-zero value), 
		0 if there were no errors, otherwise non-zero.
 Note that this is opposite of most other Dos functions,
 which return a success code.

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.
   
Calling FPuts() with a NULL filehandle is safe, it just returns error 
if this situation occurs.

**See also:** FGets(), FPutC(), FWrite(), PutStr(), SetFileHandleAttr().

---

### dos.library/FRead (V36)

**Reads a number of blocks from an input (buffered)**

**Synopsis:**
```c
uint32 count= FRead(BPTR fh,STRPTR buf,uint32 blocksize,uint32 blocks);
```

**Description:**
Attempts to read a number of blocks, each 'blocksize' bytes in size,
into the specified buffer from the input stream.  May return less
than the number of blocks requested, either due to EOF or read
errors. This call is buffered.

**Inputs:**
fh        - filehandle to use for buffered I/O
buf       - Area to read bytes into.
blocksize - number of bytes per block.
blocks    - number of blocks to read.

**Result:**
count     - Number of _blocks_ read, or 0 for EOF.  
     On error, the number of blocks actually read is returned.

**Example:**
```c
To use this function with the same parameters as the un-buffered 
Read() function, set blocksize to 1, as per the following example;
 bytes_read = FRead(fh, buf, 1, bytes_to_read);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

This call always clears your buffer upon entry, providing you have
supplied a non-NULL 'buf' pointer with 'blocks' and 'blocksize' > 0.

If 'blocks' or 'blocksize' == 0, this function will quietly return 0.

**See also:** FGetC(), FWrite(), FGets(), FOpen(), FClose(), SetFileHandleAttr()

---

### dos.library/FReadLine

**Reads a line or until EOF with dynamic buffering. (V51.47)**

**Synopsis:**
```c
int32 count = FReadLine(BPTR fh, struct FReadLineData *frld);
```

**Description:**
Given a struct FReadLineData pointer, which must be allocated with
AllocDosObject(DOS_FREADLINEDATA,...) and freed with FreeDosObject(),
this function will read from the filehandle 'fh' and dynamically
allocate sufficient memory to hold the entire content to EOF or until
the user-definable terminator character is encountered or to the
first '\n' character if no optional tag is supplied. (Default)

The FReadLineData structure serves as an anchor as well as provide 
access to the relevant information.  It is structured as follows;

struct FReadLineData
{
  STRPTR frld_Line;          /* Resultant buffer to access data  */
  uint32 frld_LineLength;    /* Number of bytes in buffer.       */

  uint32 frld_DosPrivate[8]; /* -- internal dos.library use only */
};

The function will return -1 on error, or the length of bytes read into
the internally allocated buffer, pointed to by frld_Line.
The resultant buffer points to the bytes of length frld_LineLength.
The buffer will always be nul-terminated to handle ascii data, but the
nul-terminator will not be included in frld_LineLength count.

You may re-read after SetFilePosition() or call FReadLine() with a 
different file handle after you have already used it, the buffer will
be nul-terminated again upon entry, for each call, however, the memory
allocated from the previous call will remain allocated and will be
reused or extended again as necessary to complete your operation.

You MUST call FreeDosObject(DOS_FREADLINEDATA,frld); when you have
finished, to release the memory held for the buffer and structure.

**Inputs:**
The following taglist options can be used with AllocDosObjectTags() 
when allocating the struct FReadLineData, the current tags are;
         
ADO_TermChar (int32) -- This is the single ascii value (0-255) used 
   to specify a different termination character other than the
   default '\n' character, which will be employed if no other
   tag value is supplied. 
   You may also specify a -1L to disable the default '\n' 
   character, and cause read termination to only occur when
   EOF (end of file) is reached . 

ADO_TermCharStr (STRPTR) -- This is an optional NUL-terminated ascii
   string used to specify any additional termination character/s
   to terminate on, when more than one is needed.
   For example, this can sometimes be required when reading from
   a source that uses both '\n' and '\r' to terminate lines.
   For this, you would supply the string; "\n\r" to this tag.
   (Default NULL)
   NB: This tag was a late addition for DOS 53.19 and will have no 
       effect with previous dos.library releases.
 
ADO_Mask (uint32) -- This tag specifies an optional break signal mask.
   This also works for Interactive streams. 
   See: <dos/dos.h> for;  SIGBREAKF_CTRL_C  etc...

**Result:**
count   - Bytes read, (same as frld_LineLength), or -1L on error.
   On error, queery IoErr() to find out more.

**Example:**
```c
struct FReadLineData *frld = IDOS->AllocDosObject(DOS_FREADLINEDATA,0);
if( frld )
{
     int32 rc = IDOS->FReadLine(fh, frld);
     if( -1 == rc )
     {
   IDOS->PrintFault(IDOS->IoErr(),"FReadLine() failed ");
     }
     else
     {
   IDOS->Printf("Line length is %ld bytes, Contents; %s\n",
           frld->frld_LineLength, frld->frld_Line);
     }
     IDOS->FreeDosObject(DOS_FREADLINEDATA,frld);
}
```

**Notes:**
Supplying a NULL frld or filehandle is safe, but will set IoErr()
to an appropriate error code and the function will return -1.

This function employs automatic task semaphore locking by default,
therefore it is safe to share a filehandle across multiple tasks 
which may call this or other buffered DOS I/O functions.

This function is not callable from tasks.

**See also:** FGetC(), FRead(), FGets(), FOpen(), FClose(), SetFileHandleAttr()

---

### dos.library/FreeArgs (V36)

**Synopsis:**
```c
FreeArgs(rdargs)

void FreeArgs(struct RDArgs *)
```

**Description:**
Frees memory associated for the ReadArgs() argument buffers as well
as any temporary internal storage areas.

If ReadArgs() allocated the RDArgs structure it will be freed.  
If NULL is passed in, this function does nothing.

**Inputs:**
rdargs - structure returned from ReadArgs() or NULL.

**Notes:**
If you allocate your own struct RDArgs with AllocDosObject()
you MUST still call FreeDosObject() on it,  FreeArgs() only frees 
the internal memory allocations associated with parsing the args
and not the allocated RDArgs structure itself.

If you call ReadArgs() with a NULL 'rdargs' parameter, 
ReadArgs() will allocate its own one, and only in this case will 
all the memory be automatically freed when FreeArgs() is called.

**See also:** ReadArgs(), ReadLineItem(), FindArg()

---

### dos.library/FreeDeviceProc (V36)

**Releases data returned by GetDeviceProc[Flags]()**

**Synopsis:**
```c
VOID FreeDeviceProc(struct DevProc * devproc);
```

**Description:**
Frees up the structure created by GetDeviceProc[Flags](), 
and any associated temporary locks.

Decrements the counter incremented by GetDeviceProc[Flags]().  
The counter is in an extension to the 1.3 process structure. 
After calling FreeDeviceProc(), do not use the port or lock again!
It is safe to call FreeDeviceProc(NULL).

**Inputs:**
devproc - A value returned by GetDeviceProc[Flags](). 
   ( NULL is safe, does nothing. )

**Notes:**
This function does not affect IoErr().

**Bugs:**
Counter not currently active in 2.0.

**See also:** GetDeviceProc(), GetDeviceProcFlags(), DeviceProc(), AssignLock(),
AssignLate(), AssignPath()

---

### dos.library/FreeDosObject (V36)

**Frees an object allocated by AllocDosObject().**

**Synopsis:**
```c
VOID FreeDosObject(uint32 object, APTR ptr);
```

**Description:**
Frees an object allocated by AllocDosObject().  
Do NOT call this for objects allocated in any other way.

**Inputs:**
object - object type passed to AllocDosObject(); this must be one of:
DOS_FILEHANDLE, DOS_EXALLCONTROL, DOS_FIB, DOS_STDPKT, 
DOS_CLI, DOS_RDARGS, DOS_ANCHORPATH, DOS_INFODATA, 
DOS_NOTIFYREQUEST, DOS_LOCK, DOS_FREADLINEDATA,
DOS_EXAMINEDATA, DOS_DOSLIST, DOS_VOLUMELIST,
or DOS_FSVECTORPORT.

ptr  - pointer returned by AllocDosObject()    (or NULL)

**Notes:**
FreeDosObject(DOS_CLI,cli)  will free all the buffers, the structure
itself as well as any pathnodes attached to the cli_PathList field
by calling FreeCmdPathList() internally.

This function is guaranteed to not change the state of IoErr().
This function is safe to call with a NULL 'ptr' argument.

**Bugs:**
Before V39, DOS_CLI objects will only have the 'struct
CommandLineInterface' freed, not the strings it points to. 
This was fixed in V39 dos.  Before V39, you can workaround this bug
by using FreeVec() with BADDR() on cli_CurrentDirName, cli_CommandFile,
cli_CommandName and cli_Prompt, and then setting them all to ZERO.
In V39 or above, do NOT use the workaround.

**See also:** AllocDosObject(), FreeVec(), <dos/dos.h>

---

### dos.library/FWrite (V36)

**Writes a number of blocks to an output. (buffered)**

**Synopsis:**
```c
uint32 count = FWrite(BPTR fh, CONST_APTR buf, uint32 blocksize,
              uint32 blocks);
```

**Description:**
Attempts to write a number of blocks, each 'blocksize' bytes in size,
from the specified buffer to the output stream.  May return less than
the number of blocks requested, if there is some error such as a full
disk or r/w error.  This call is buffered.

**Inputs:**
fh        - filehandle to use for buffered I/O
buf       - Area to write bytes from.
blocksize - number of bytes per block.
blocks    - number of blocks to write.

**Result:**
count     - Number of _blocks_ written.  On an error, the number of
     blocks actually written is returned.

**Example:**
```c
To emulate the unbuffered Write() function arguments, set the 
'blocksize' to 1, and the number of bytes to write as 'blocks',
as per the following example;
    bytes_written = FWrite(fh, buf, 1, bytes_to_write);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

If 'blocks' or 'blocksize' == 0, this function will quietly return 0.

**See also:** FPutC(), FRead(), FPuts(), FOpen(), FClose(), SetFileHandleAttr().

---

### dos.library/GetArgStr (V36)

**Returns the arguments for the process.**

**Synopsis:**
```c
STRPTR ptr = GetArgStr(VOID);
```

**Description:**
Returns a pointer to the (null-terminated) arguments for the program
(process).  This is the same string passed in 68000 register A0 on
startup from CLI.

**Result:**
ptr - pointer to the argument string. (or NULL)

**Notes:**
This function is NOT callable from a task.

   WARNING:
This function can return NULL if the process was started without
explicitly specifying an argument string with NP_Arguments.

**See also:** SetArgStr(), RunCommand(), CreateNewProc()

---

### dos.library/GetCliCurrentDirName (V36)

**returns the current directory name
                 from the CLI structure.**

**Synopsis:**
```c
int32 success = GetCliCurrentDirName(STRPTR buf, int32 len);
```

**Description:**
Extracts the current directory name from the CLI structure if this
process has a CLI attached.
The result is copied into the buffer.  
If the buffer is too small, the name is truncated appropriately
and a failure code returned (ERROR_LINE_TOO_LONG).

**Inputs:**
buf     - Buffer to hold extracted name.
len     - Number of bytes of space in buffer.

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
Prior to V50 this function was documented to fail if no CLI
structure was present, but this was NOT actually the case,
it always effectively called: NameFromLock( GetCurrentDir(), ...);
as a fallback.

Note that the data returned from accessing the CLI structure may
not yield a full path, depending on the length, but may instead 
just return the name of the currentdir component itself.

**Bugs:**
From v50, the value obtained from here is not always usefull,
due to the length limits of the CLI structure field cli_CurrentDirName.
This function will not always support V50 long pathnames.
If you do not have a CLI attached, then long path names will work.

You really should just use:  [Dev]NameFromLock( GetCurrentDir(), ...);
to obtain a fully qualified long pathname compliant string. 

This function cannot be fixed (yet) due to software dependencies,
but should use the suggested workaround in a later DOS version.

This function is NOT task callable.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**See also:** SetCliCurrentDirName().

---

### dos.library/GetCliProgramName (V36)

**Returns the current CLI program name from the
              attached CLI structure.**

**Synopsis:**
```c
int32 success = GetCliProgramName(STRPTR buf, int32 len);
```

**Description:**
Extracts the program name from the CLI structure cl->cli_CommandName
and puts it into the buffer.  
If the buffer is too small, the name is truncated and the error code:
ERROR_LINE_TOO_LONG will be returned by IoErr(), this function will
still return non-zero in this case.

If no CLI structure is present, a null string is returned in the
buffer, and failure is indicated by: ERROR_OBJECT_WRONG_TYPE by
a call to IoErr(), this function will then return FALSE.

**Inputs:**
buf     - Buffer to hold extracted name.
len     - Number of bytes of space in buffer.

**Result:**
success - boolean; (zero or non-zero value)

**Notes:**
This function is NOT task callable.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**Bugs:**
See SetCliProgramName() for pre-V50 bugs concerning name truncation.

For V40 compatibility, this function MAY, or MAY NOT, contain any
path component for the program name.

To extract only the program name, use this function in conjunction
with FilePart().

**See also:** SetCliProgramName()

---

### dos.library/GetCliPrompt (V36)

**Returns the prompt from the attached CLI structure.**

**Synopsis:**
```c
int32 success = GetCliPrompt(STRPTR buf, int32 len);
```

**Description:**
Extracts the prompt string from the CLI structure cl->cli_Prompt and
puts it into the buffer.  If the buffer is too small, the string is
truncated and the error code: ERROR_LINE_TOO_LONG will be returned by
IoErr(), however, this function will still return DOSTRUE in this case.

If no CLI structure is present, a null string is returned in the
buffer, and failure is indicated by: ERROR_OBJECT_WRONG_TYPE by
a call to IoErr() and this function will return FALSE.

**Inputs:**
buf     - Buffer to hold extracted prompt.
len     - Number of bytes of space in buffer.

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
This function is NOT task callable.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**See also:** SetCliPrompt()

---

### dos.library/GetConsolePort (V36)

**Returns the default console for the process.**

**Synopsis:**
```c
struct MsgPort *port = GetConsolePort(void);
```

**Description:**
Returns the default console task's port (pr_ConsolePort) for the
current process.

**Result:**
port - The pr_MsgPort of the console handler, or NULL.

**Notes:**
This function is NOT callable from a task.
This function used to be called GetConsoleTask.

**See also:** SetConsolePort(), Open()

---

### dos.library/GetDeviceProc (V36)

**Low level function to find a DOS handler.**

**Synopsis:**
```c
struct DevProc *devproc = GetDeviceProc(CONST_STRPTR name,
                                 struct DevProc *devproc);
```

**Description:**
Refer to GetDeviceProcFlags() for function documentation.

**Inputs:**
name    - Name of the object you wish to access.
devproc - A value returned by GetDeviceProc() before, or NULL

**Result:**
devproc - A pointer to a DevProc structure or NULL on failure.
   On success, it must be freed with FreeDeviceProc().

**Notes:**
This function is now a fast compatibility stub that calls;
   IDOS->GetDeviceProcFlags(name,devproc,LDF_ALL);

Application programmers should rarely if ever need this function,
When a unique fully resolved DOS path is required by an application,
call the IDOS->Lock() function and IDOS->DevNameFromLock().

This function is NOT task callable.

**See also:** FreeDeviceProc(), GetDeviceProcFlags(), AssignLock(), AssignLate(),
AssignPath(), Lock().

---

### dos.library/GetDiskInfo

**Returns information about a disk or handler. (51.96)**

**Synopsis:**
```c
int32 result = GetDiskInfo( const struct TagItem *tags );

int32 result = GetDiskInfoTags(uint32 Tag1, ...);
```

**Description:**
GetDiskInfo() can be used to find information about a handler.
This function will provide the same and extended features to the
existing V31 Info() function.

This function allows for a choice of handler identifiers to be used,
it also enables you to obtain information about disks without any
currently mounted volume, which Info() does not provide.  
Also, you can obtain information from other non-filesystem handlers
such as CON: etc...

**Inputs:**
tags -- Pointer to a tagitem array for the options listed below.

INPUT TAGS ; One mandatory tag item to enable handler identification.
      The following four tags are mutually exclusive.

GDI_StringNameInput (STRPTR) -- Pointer to a string identifier.
    Identify the handler by volume: device: assignment, or other legal
    reference. (See; IDOS->GetDeviceProcFlags() for more info)
    NB: If the volume that the object specified by the string name, 
 is not currently inserted, it will post the usual style of
 "Please Insert Volume ..." request unless specifically
 prevented in doing so beforehand with dos/SetProcWindow().

GDI_FileHandleInput (BPTR) -- BCPL pointer to a FileHandle.
    Identify the handler by the stream pointed to by a FileHandle.
    The opening mode does not affect identification.

GDI_LockInput   (BPTR) -- BCPL pointer to a Lock.
    Identify the handler by this associated Lock.
    The lock mode does not affect the identification.
    NB: Supplying a lock of ZERO will return InfoData from the handler
 process that is returned from GetFileSysPort(). 

GDI_MsgPortInput    (struct MsgPort *) -- Pointer to a message port.
    Identify the handler by this message port.

                            ===

OPTION TAGS ; The other options that control how this function works.
       (Currently only one available.)

GDI_VolumeRequired (BOOLEAN) -- defaults to FALSE if the tag
    GDI_MsgPortInput is used, otherwise TRUE for the other inputs.

    This tag is what controls what DOSPacket type or filesystem call
    is used to obtain the InfoData, these are as follows;

    If GID_VolumeRequired==FALSE then FSDeviceInfoData() or the 
    DOSPacket ACTION_DISK_INFO will be sent to obtain information.

    If GID_VolumeRequired==TRUE then FSVolumeInfoData() or the
    DOSPacket ACTION_INFO will be sent to obtain information.

    Note that the FSVolumeInfoData() / ACTION_INFO will fail if the
    mounted device has no volume node present, whereas the 
    FSDeviceInfoData() / ACTION_DISK_INFO method "always" works.
    (in theory at least.)

                            ===

OUTPUT TAG ; The mandatory destination where to store the InfoData.

GDI_InfoData (struct InfoData *)
    This must point to an InfoData structure to be filled in.

    With this function, it does NOT have to be longword aligned,
    unlike the old Info() which requires longword alignment.
    DOS will take care of this internally, if required.

    IDOS->AllocDosObject(DOS_INFODATA,0) will also provide a 
    correctly aligned InfoData struct for all situations.

    The contents of the InfoData structure are arranged as follows:

 id_NumSoftErrors    ( -- Deprecated field )
     Typically was for the number of media read/write errors
     encountered on this volume. This number increased for every
     error, regardless of which disk may be currently inserted,
     which means it's of little use for anything at all.
     Few file systems ever provided this information, it is
     generally always set to zero. This field will likely be
     reused in future for some other purpose, until then, 
     please do not access it.

 id_UnitNumber       ( -- Deprecated field )
     This can be the low level device driver unit number
     responsible for this disk drive, it also may not be.
     Few file systems ever provided this information, 
     and the operating system itself no longer uses it
     as of AmigaOS 2.04 and beyond.  This field is generally
     set to zero and will most likely be reused in future for
     some other purpose, until then, please do not access it.

 id_DiskState
     This indicates the state of the media in this device,
     it should always be one of the following values:

         ID_DISKSTATE_VALIDATED
             Medium is readable and writable.

         ID_DISKSTATE_WRITE_PROTECTED
             Medium is readable, but cannot be written to.

         ID_DISKSTATE_VALIDATING
             Medium may be readable and is currently being
             prepared to make it writable again.
             This is also the default "parking" state used when
             the filesystem is waiting for media to be inserted,
             or the file system is in an unknown state and unable
             return meaningfull information about the medium,
             Always refer to id_DiskType for device state info.

 id_NumBlocks
     The number of storage units ("blocks") which this
     file system consists of.

         NOTE: This value can be zero!

 id_NumBlocksUsed
     The number of storage units currently in use by
     the file system.

         NOTE: This value can be zero or identical to
               the id_NumBlocks value!

 id_BytesPerBlock
     The number of bytes that make up a single storage
            unit ("block"). Note that this number may not match
     the physical size of the storage block, as used by
     the underlying storage device. The file system might
     return the size of a single data block instead, which
     can be shorter.

 id_DiskType
     This field indicates both the state of the file system
     and what kind of file system is involved. 
     The following values indicate file system state:

         ID_NO_DISK_PRESENT
             No medium is currently present.

         ID_UNREADABLE_DISK
             A medium is present, but low level read
             errors have prevented the file system from
             figuring out what is stored on it. This
             medium may not be formatted or simply
             defective.

         ID_NOT_REALLY_DOS
             A medium is present, its contents are
             readable, but they are of no use for this
             file system.

         ID_BUSY
             The file system is currently "offline" and
             cannot access the medium. This may be because
             commands such as "Format" or "DiskCopy" are
             accessing the low level disk data and do not
             want the file system to interfere.

     Some of the types of file systems involved:

         ID_DOS_DISK
         ID_FFS_DISK
         ID_INTER_DOS_DISK
         ID_INTER_FFS_DISK
         ID_FASTDIR_DOS_DISK
         ID_FASTDIR_FFS_DISK
         ID_LONGNAME_DOS_DISK
         ID_LONGNAME_FFS_DISK
         ID_MSDOS_DISK
         ID_VP255_DOS_DISK
         ID_NGFS_DISK

     Each of these values stands for a particular type
     of file system and disk data format, there are others.

     The con-handler may return one of the following
     types, which indicate the state it currently
     operates in:

         ID_CON
             Input is line-buffered, i.e. you have to
             hit the [Return] key to transfer your input
             to the client reading data from this console
             stream.

         ID_RAWCON
             Input is unbuffered, i.e. each key you hit
             that produces a character immediately transfers
             input to the client software. This is the
             so-called 'single character' mode which can
             be enabled via SetMode(..,DOSTRUE).

     Last, but not least, you might very rarely encounter
     a so-called "Kickstart" disk which contains the
     operating system for the Amiga 1000 and Amiga 3000
     computers. It is identified by the following value:

         ID_KICKSTART_DISK

     Other disk type values may exist, which represent
     the file system signature stored on the disk (often
     in the first sector) or might just be random data
     found on an unformatted storage medium. Be prepared
     to handle this: always check the id_DiskState field
     to verify if the file system considers itself
     responsible for this disk. Do not make decisions
     based solely on the file system type found in the
     id_DiskType field! A file system should never report
     an id_DiskState value of ID_DISKSTATE_VALIDATED for 
     a medium it cannot use.

 id_VolumeNode
     This field is supposed to be a BCPL pointer to the volume
     node of the currently active filesystem volume.
     Not all file systems will supply this, or exactly this
     particular information.  Non filesystems may use this field
     for other completely incompatible purposes, for example,
     the con-handler may return a pointer to the console window.
     This field should be treated with caution.
     Note that it can also be ZERO!

 id_InUse
     This field is supposed to be set to FALSE/ZERO if there
     are currently no locks or files bound to the handler.
     Otherwise, the non-zero value returned from some old file
     systems may infact be any arbitrary non-zero boolean value.
     The now prefered V50+ use for filesystems is that they
     should actually return an integer for the number of locks
     currently in force. Stream handlers should indicate the
     number of streams currently open.
     The con-handler also uses this field for a completely
     different and incompatible purpose, such as storing a
     pointer to the console I/O request. As with id_VolumeNode
     this field should be treated with caution.

**Result:**
result - (zero or non-zero)
     The result will be zero for failure, or non-zero for
     success, the non-zero success value represents the
     number of tags passed to this function as parameters.

     On failure, call IoErr() [Fault(),PrintFault()] to find
     out more information with regard to what caused failure.

**Notes:**
This function is NOT task callable.

The default mode for a non-specified GDI_VolumeRequired tag was 
always TRUE before DOS 53.68, now it becomes FALSE if the message
port input source is used.

**See also:** Info(), GetDiskFileSystemData(), IoErr(), Fault(), PrintFault().

---

### dos.library/GetEntryData

**Obtain the entry data set by CreateNewProc() (V51.73)**

**Synopsis:**
```c
int32 data = GetEntryData(VOID);
```

**Description:**
Returns the data initialised by CreateNewProc() with NP_EntryData.

**Result:**
data - int32

**Notes:**
This function is NOT callable from a task.

**See also:** CreateNewProc()

---

### dos.library/GetFilePosition

**Return the current file cursor position. (51.64)**

**Synopsis:**
```c
int64 position = GetFilePosition( BPTR filehandle );
```

**Description:**
GetFilePosition() returns the current absolute file cursor position
of an open file, or the value of -1LL if an error occured.

**Inputs:**
filehandle - BCPL pointer to a file handle obtained from Open(),
      FOpen(), OpenFromLock(), FOpenFromLock().

**Result:**
position   - 64 bit integer of the absolute cursor position for file,
      or -1LL on failure.

**Notes:**
This function provides a working fallback using Seek(), if the new
packet is unsupported by the filesystem, providing the result falls
within 32 bit limits. Fallback function semantics will apply for
unsupporting filesystems.

This function works for both buffered and unbuffered streams.

This function is NOT callable via the legacy 68K jumptable.

**See also:** ChangeFileSize(), GetFileSize(), ChangeFilePosition(),
Open(), FOpen(), OpenFromLock(), FOpenFromLock(), Close(), FClose().

---

### dos.library/GetFileSize

**Obtain the size of a file. (V51.62)**

**Synopsis:**
```c
int64 filesize = GetFileSize( BPTR filehandle );
```

**Description:**
Returns the current file size from an open filehandle.

**Inputs:**
filehandle - BCPL pointer to an open filehandle obtained from
      Open(), FOpen(), OpenFromLock(), FOpenFromLock(), etc...

**Result:**
filesize   - 64 bit integer of the file size, or -1LL for error.
      On error, consult IoErr() to find out why.

**Notes:**
This function is NOT callable by legacy 68K applications.

This function also provides a working fallback using ExamineFH() if 
the new packet is unsupported by the filesystem, providing the result
falls within unsigned 32 bit limits,(4GB-1Byte).
Fallback function semantics may apply for unsupporting filesystems.

This function works for both buffered and unbuffered file streams.

**See also:** ChangeFilePosition(), GetFilePosition(), ChangeFileSize(), 
Open(), FOpen(), OpenFromLock(), FOpenFromLock(), Close(), FClose().

---

### dos.library/GetFileSysPort (V36)

**Synopsis:**
```c
struct MsgPort *port = GetFileSysPort(void);
```

**Description:**
Returns the current filesystem process' message port (pr_FileSystemPort)

**Result:**
port - The MsgPort of the current filesystem process, or NULL.

**Notes:**
This function is NOT callable from a task.
This function used to be called GetFileSysTask.

**See also:** SetFileSysPort(), Open(), Lock(), ParentDir()

---

### dos.library/GetFileSystemVectorPort

**Low level routine to return a pointer to a
                    filesystem vector-port interface. (V53.136)**

**Synopsis:**
```c
struct FileSystemVectorPort *fsvp = GetFileSystemVectorPort(
                       struct MsgPort *port, uint32 minver);
```

**Description:**
This function is mainly used inside dos.library for the purpose of
validating and returning a pointer to a filesystem vector-port interface
if the 'port' is for a vector-port type filesystem and the interface
version is at least the minimum version value 'minver'.

The first release vector-port version value was 53, this will be the
minimum value used to obtain a valid working vector-port interface as
described in the include file; dos/filehandler.h

Never use 0 as a minimum version, as this may infact return a pointer
to a vector-port that is in the process of being dismounted or deleted.

**Inputs:**
port   - (struct MsgPort *) Pointer to a filesystem message port.
minver - (uint32) Minimum interface version to return. (minimum 53)

**Result:**
fsvp   - (struct FileSystemVectorPort *) Pointer to a filesystem
  vector-port interface or NULL for DosPacket based filesystems,
  handlers, or for vector-port interfaces with a lower version.

**Notes:**
This function provides no locking for the 'port' of the handler.
Passing NULL for the 'port' argument is safe and just returns NULL.

**See also:** IsFileSystemPort().  <dos/filehandler.h>

---

### dos.library/GetOwnerInfo

**Get owner information for an object. (V52.18)**

**Synopsis:**
```c
int32 success = GetOwnerInfo( const struct TagItem *tags );

int32 success = GetOwnerInfoTags( uint32 Tag1, ...);
```

**Description:**
This function is a complement to the V52 SetOwnerInfo() function
which provides access to a filesystem objects UID and GID data.
This function additionally provides a method of retrieval of a
process structures pr_UID and pr_GID members.

A filesystem takes no interest in the values other than storing 
(and returning them) for the respective filesystem objects,
these are primarily for use by networking software (clients and hosts),
in conjunction with the ExamineData EXDF_OTR_xxx and EXDF_GRP_xxx 
protection bits, as well as the old FileInfoBlock FIBF_OTR_xxx and
FIBF_GRP_xxx protection bits.

**Inputs:**
SOURCE TAGS:  (Mutually Exclusive)
OI_StringNameInput (STRPTR) -- Pointer to a string name identifying a 
    filesystem object to read the UID and/or GID values via the
    OI_OwnerXXX tags listed below.
    This tag is mutually exclusive with OI_ProcessInput.

OI_ProcessInput (struct Process *) -- Pointer to a process structure, 
    (or NULL for this process), to read the process structure fields
    pr_UID and/or pr_GID via the OI_OwnerXXX tags listed below.
    This tag is mutually exclusive with OI_StringNameInput.

OTHER TAGS:
OI_OwnerUID (uint32 *) -- Pointer to a uint32 sized storage area.
    Returns the value of the objects UID field.

OI_OwnerGID (uint32 *) -- Pointer to a uint32 sized storage area.
    Returns the value of the objects GID field.

You may supply one or both of the above OI_OwnerXXX tags.
For a filesystem object, the value/s returned are the same as found in
their respective fields in a struct ExamineData; OwnerUID and OwnerGID.
For a process structure, the values returned are that of the Process
structure members; pr_UID and pr_GID respectively.

**Result:**
success    - boolean; (zero or non-zero)

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

**Notes:**
Before V50 there was a limit of 255 chars for a filesystem path/name.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

**See also:** SetOwnerInfo(), SetProtection(), ExamineObject(), ExamineDir(), 
<dos/dos.h>

---

### dos.library/GetPID

**Low level routine to obtain the process identifier number.
   (V53.58)**

**Synopsis:**
```c
uint32 pid = GetPID(const struct Process *proc, int32 which);
```

**Description:**
Returns the process identifier, or the parent process identifier.

**Inputs:**
proc  - struct Process *, or NULL for self.

which - GPID_PROCESS or GPID_PARENT.

 GPID_PROCESS returns the unique identifier of 'proc'. 
 GPID_PARENT  returns the identifier of the parent of 'proc'.

**Result:**
pid   - uint32, process identifier number, or 0 on error.

**Notes:**
You must NEVER use arbitrary memory addresses of process structures
as pseudo process identifier values.  It is absolutely guaranteed
that if a process exits and another one starts shortly afterwards,
the same memory address can be reused more often than one would expect,
a method like that is extremely unreliable and fraught with peril,
so don't do it.

---

### dos.library/GetProcSegList

**Obtain a seglist for a process. (V51.88)**

**Synopsis:**
```c
BPTR seglist = GetProcSegList( const struct Process *process,
                        uint32 whichseglist );
```

**Description:**
Returns the nominated seglist for a given process.
The value of 'whichseglist' determins what will be returned.

**Inputs:**
struct Process *, or NULL to obtain a seglist from this process.

uint32 whichseglist,  flags to identify which seglist you want,
    and/or the ORDER in which to search for a valid seglist.
    The search order is shown below within [ ] brackets.

    The currently supported flags are;

    [1] GPSLF_CLI -  Returns the seglist for the current CLI command.
              This is obtained from;  cli->cli_Module.
              If the program was not loaded by the shell or not
              started from a shell process, this will be zero.

    [2] GPSLF_SEG -  Returns the seglist supplied to CreateProc() or
              by the NP_SegList tag for CreateNewProc(), when
              the new process was created.
              This is obtained from the process' segarray[3].
              If the process was started by CLI, this will 
              usually return zero, otherwise, if it was started
              from workbench, this will be the seglist for the 
              program being run.

    [3] GPSLF_ENT -  Returns the pseudo seglist for the tag NP_Entry
              when this process was CreateNewProc()'ed.
              This is obtained from the process' segarray[2].
              If the program was not started as a function
              vector with NP_Entry, this will return zero. 

    [4] GPSLF_RUN -  Returns the seglist for the code running NOW.
              This is obtained from the process->pr_CurrentSeg.
              This seglist will be the same one supplied to the
              internal_RunCommand() function or via a call to
              RunCommand(), it may, or may not, be any one of
              the three seglists above. 
              It will always represent the current code that
              is being run, even if it is a recursive process,
              and will also return the seglist for newly loaded
              code being started within the same process via
              the RunCommand() function.


    Multiple 'OR'ed flags will be searched for in the order shown
    above within [ ], until the first non-zero seglist is found, 
    that will be the seglist which is returned.

    If you want to test for a specific seglist, be it zero or non-zero,
    then use only one flag per call to obtain what is in that slot only.

**Result:**
seglist - BPTR or 0 on failure.

**Notes:**
No arbitration is performed by this function when used to obtain the
seglist from a process, other than your own.
Another process may exit at any time, it is up to you to perform 
the required arbitration.

For GPSLF_CLI, this function will first check to see if the process
has a cli structure, so it is safe to use even for non-CLI processes,
although it would of course always return 0.

This function is safe to call from tasks, but will always return 0.

**See also:** GetSegListInfo()

---

### dos.library/GetProgramDir (V36)

**Returns a lock on the directory the program was 
          loaded from.**

**Synopsis:**
```c
BPTR lock = GetProgramDir(VOID);
```

**Description:**
Returns the shared lock for the directory the program was loaded from.
This can be used for a program to find data files, etc, that are
stored with the program, or to find the program file itself.

NULL returns are valid, and may occur for example, when running 
a program from the DOS resident list.  
You must NOT unlock the lock returned from this function.

This lock is the same one that will be used by referencing paths
relative to "PROGDIR:".

**Result:**
lock - A lock on the directory the current program was loaded from,
or NULL if loaded from resident list, etc.

**Notes:**
This function is NOT callable from a task.

**Bugs:**
Should return a lock for things loaded via dos resident.

**See also:** SetProgramDir(), Open(), NameFromLock()

---

### dos.library/GetVar (V36)

**Reads the value of a local or global variable.**

**Synopsis:**
```c
int32 len = GetVar( CONST_STRPTR name, STRPTR buffer, int32 bufsize,
             uint32 control );
```

**Description:**
Reads the value of an environment variable.  It is advised to only
use ASCII strings inside variables, but this is not required.
  
This function stops putting characters into the destination buffer 
when a '\n' or '\r' is encountered, unless GVF_BINARY_VAR is specified.
(The '\n' or '\r' is not stored in the buffer.)

Variable names follow filesystem syntax and semantics.
All variable names are relative to the root of the device.
The current directory lock has no effect on this function.

**Inputs:**
name    - Pointer to a variable name. (May use a volume spec, See NOTES)

buffer  - A user allocated area which will be used to store the value
   associated with the variable.

bufsize - Length of the buffer allocation in bytes.

control - Mixed control descriptor and bitmask.
   The low 8 bits describes the type of local var, while the
   upper bits form a bitmask to control the behavior of this 
   function.
  
   For local vars only, specify the type of local var to get
   with either LV_VAR or LV_ALIAS.  
   LV_VAR is the default type if not specified.  
   Then, 'OR' the LV_xxx type with any required GetVar 'GVF_xxx'
   control flags shown below, these currently include:

   GVF_LOCAL_ONLY  - get a local (to your process) variable.
                     Mutually exclusive with GVF_GLOBAL_ONLY.

   GVF_GLOBAL_ONLY - get a global environment variable.
                     Mutually exclusive with GVF_LOCAL_ONLY.
       If neither of these (Mutually exclusive) flags are
       specified, the function will try to get a local variable
       first, then try to get a global environment variable.

   GVF_BINARY_VAR  - treat variable as a binary variable.
       (Try to avoid using binary vars whenever possible.)

   GVF_DONT_NULL_TERM - no null termination.
       Only valid for binary variables. (V37)

   See also: dos/var.h

**Result:**
len     - Size of environment variable. 
   If successful, len is the strlen(buffer), and IoErr() will
   return the full size of the variable, this is regardless of
   the buffer contents.

   -1 indicates an error.
   If IoErr() returns ERROR_OBJECT_NOT_FOUND the variable did
   not exist.

   If IoErr() return ERROR_BAD_NUMBER you specify a size <1.

**Notes:**
This function is NOT task callable.
The flags; GVF_GLOBAL_ONLY and GVF_LOCAL_ONLY are mutually exclusive.
Upon success, the buffer content returned is null-terminated even if
GVF_BINARY_VAR is specified, unless GVF_DONT_NULL_TERM is in effect.
This function does not guarantee what is in your buffer on error,
due to compatibility issues, this cannot be changed for V50.
Variables are limited to a maximum size of 2 Gigs.
A volume specification is permitted with this function to read from
a different volume, without a specification, the default is ENV:

**Bugs:**
LV_VAR is the only type that can be a global variable.
Under V36, we documented (and it returned) the size of the variable,
not the number of characters transferred.  For V37 this was changed
to the number of characters put in the buffer, and the total size
of the variable is put in IoErr().
GVF_DONT_NULL_TERM only works for local variables under V37.
For V39, it also works for globals.

**See also:** SetVar(), DeleteVar(), FindVar(), <dos/var.h>

---

### dos.library/Info

**Returns information about the disk.**

**Synopsis:**
```c
int32 success = Info(BPTR lock, struct InfoData *parameterBlock);
```

**Description:**
Info() can be used to find information about any disk in use.
'lock' refers to the disk, or any file on the disk. 

The parameter block is returned with information about the size
of the disk, number of free blocks and any soft errors.

It is recommended that the new GetDiskInfo() function be used
for new software which permits unaligned InfoData and extra
features.

**Inputs:**
lock -- BCPL pointer to a lock, (or 0)

parameterBlock -- pointer to an InfoData structure, which MUST be
           longword aligned. The contents of the InfoData
           structure are arranged as follows:

 id_NumSoftErrors    ( -- Deprecated field )
     Typically was for the number of media read/write errors
     encountered on this volume. This number increased for every
     error, regardless of which disk may be currently inserted,
     which means it's of little use for anything at all.
     Few file systems ever provided this information, it is
     generally always set to zero. This field will likely be
     reused in future for some other purpose, until then,
     please do not access it.

 id_UnitNumber       ( -- Deprecated field )
     This can be the low level device driver unit number
     responsible for this disk drive, it also may not be.
     Few file systems ever provided this information,
     and the operating system itself no longer uses it
     as of AmigaOS 2.04 and beyond.  This field is generally
     set to zero and will most likely be reused in future for
     some other purpose, until then, please do not access it.

 id_DiskState
     This indicates the state of the media in this device,
     it should always be one of the following values:

         ID_DISKSTATE_VALIDATED
             Medium is readable and writable.

         ID_DISKSTATE_WRITE_PROTECTED
             Medium is readable, but cannot be written to.

         ID_DISKSTATE_VALIDATING
             Medium is readable and is currently being prepared
             to make it writable again.

             This is also the default "parking" state used when
             the filesystem is waiting for media to be inserted,
             or the file system is in an unknown state and unable
             return meaningfull information about the medium,
             Always refer to id_DiskType for device state info.

 id_NumBlocks
     The number of storage units ("blocks") which this
     file system consists of.

         NOTE: This value can be zero!

 id_NumBlocksUsed
     The number of storage units currently in use by
     the file system.

         NOTE: This value can be zero or identical to
               the id_NumBlocks value!

 id_BytesPerBlock
     The number of bytes that make up a single storage
            unit ("block"). Note that this number may not match
     the physical size of the storage block, as used by
     the underlying storage device. The file system might
     return the size of a single data block instead, which
     can be shorter.

 id_DiskType
     This field indicates both the state of the file system
     and what kind of file system is involved.
     The following values indicate file system state:

         ID_NO_DISK_PRESENT
             No medium is currently present.

         ID_UNREADABLE_DISK
             A medium is present, but low level read
             errors have prevented the file system from
             figuring out what is stored on it. This
             medium may not be formatted or simply
             defective.

         ID_NOT_REALLY_DOS
             A medium is present, its contents are
             readable, but they are of no use for this
             file system.

         ID_BUSY
             The file system is currently "offline" and
             cannot access the medium. This may be because
             commands such as "Format" or "DiskCopy" are
             accessing the low level disk data and do not
             want the file system to interfere.

     Some of the types of file systems involved:

         ID_DOS_DISK
         ID_FFS_DISK
         ID_INTER_DOS_DISK
         ID_INTER_FFS_DISK
         ID_FASTDIR_DOS_DISK
         ID_FASTDIR_FFS_DISK
         ID_LONGNAME_DOS_DISK
         ID_LONGNAME_FFS_DISK
         ID_MSDOS_DISK
         ID_VP255_DOS_DISK
         ID_NGFS_DISK

     Each of these values stands for a particular type
     of file system and disk data format.

     The con-handler may return one of the following
     types, which indicate the state it currently
     operates in:

         ID_CON
             Input is line-buffered, i.e. you have to
             hit the [Return] key to transfer your input
             to the client reading data from this console
             stream.

         ID_RAWCON
             Input is unbuffered, i.e. each key you hit
             that produces a character immediately transfers
             input to the client software. This is the
             so-called 'single character' mode which can
             be enabled via SetMode(..,DOSTRUE).

     Last, but not least, you might very rarely encounter
     a so-called "Kickstart" disk which contains the
     operating system for the Amiga 1000 and Amiga 3000
     computers. It is identified by the following value:

         ID_KICKSTART_DISK

     Other disk type values may exist, which represent
     the file system signature stored on the disk (often
     in the first sector) or might just be random data
     found on an unformatted storage medium. Be prepared
     to handle this: always check the id_DiskState field
     to verify if the file system considers itself
     responsible for this disk. Do not make decisions
     based solely on the file system type found in the
     id_DiskType field! A file system should never report
     an id_DiskState value of ID_DISKSTATE_VALIDATED for
     a medium it cannot use.

 id_VolumeNode
     This field is supposed to be a BCPL pointer to the volume
     node of the currently active filesystem volume.
     Not all file systems will supply this, or exactly this
     particular information.  Non filesystems may use this field
     for other completely incompatible purposes, for example,
     the con-handler may return a pointer to the console window.
     This field should be treated with caution.
     Note that it can also be ZERO!

 id_InUse
     This field is supposed to be set to FALSE/ZERO if there
     are currently no locks or files bound to the handler.
     Otherwise, the non-zero value returned from some old file
     systems may infact be any arbitrary non-zero boolean value.
     The now prefered V50+ use for filesystems is that they
     should actually return an integer for the number of locks
     currently in force. Stream handlers should indicate the
     number of streams currently open.
     The con-handler also uses this field for a completely
     different and incompatible purpose, such as storing a
     pointer to the console I/O request. As with id_VolumeNode
     this field should be treated with caution.

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
This function is NOT task callable.

Supplying a lock of 0 will return InfoData from the task
that is returned from GetFileSysPort(), this is usually the
boot volumes filesystem, assigned as "SYS:"

**See also:** GetDiskInfo(),GetFileSysPort(),GetDiskFileSystemData()

---

### dos.library/Inhibit (V36)

**Inhibits access to a filesystem.**

**Synopsis:**
```c
int32 success = Inhibit(CONST_STRPTR filesystem, int32 status);
```

**Description:**
Sends an ACTION_INHIBIT packet to the indicated handler. 
This stops all activity by the handler until uninhibited.

When inhibited, handlers must not access any underlying media and
must return an error code on all attempts to access the device.

When uninhibited, anything may have happened to the disk in the drive,
or there may no longer be one.

**Inputs:**
filesystem - Name of DEVICE to inhibit (with ':')
status     - New status.  TRUE == inhibited, FALSE == uninhibited.

**Result:**
success    - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
From V51.30 this function will fail if the name supplied is not the
device name of the filesystem, volume and assign names will be rejected.

The 'status' parameters actual TRUTH value may be adjusted for backward
semantical compatibility by this function, before passing it to the
filesystem, as some filesystems expect DOSTRUE/FALSE only.

Filesystems will usually flush any pending write buffer and generate
diskchange events by invoking this function.

This function is NOT task callable.

**See also:** InhibitPort(), Serialize(), Format(), DevNameFromLock(), DevNameFromFH(),
DevNameFromPort(), GetDeviceProcFlags().

---

### dos.library/InhibitPort

**Inhibits access to a filesystem. (V53.88)**

**Synopsis:**
```c
int32 success = InhibitPort(struct MsgPort *port, int32 status);
```

**Description:**
Sends an inhibit request to the handler identified by the message port.
This stops all activity by the handler until uninhibited.
When inhibited, handlers must not access any underlying media and
must return an error code on all attempts to access the device.
When uninhibited, anything may have happened to the disk in the drive,
or there may no longer be one.

**Inputs:**
port    - Message port of the filesystem to inhibit.
status  - New status.  TRUE == inhibited, FALSE == uninhibited.

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
The 'status' parameters actual TRUTH value may be adjusted by this
function for backward semantical compatibility before passing it to
the filesystem, as some filesystems expected DOSTRUE/FALSE only.

When invoking this function, all filesystems should flush any pending
write buffer and generate the appropriate diskchange events.

This function provides no locking for the 'port' of the handler.

This function is NOT task callable.

**See also:** Inhibit(), Serialize(), Format(), NonBlockingModifyDosEntry().

---

### dos.library/Input

**Identify the program's initial input file handle.**

**Synopsis:**
```c
BPTR file = Input(VOID);
```

**Description:**
Input() is used to access the initial input stream allocated when
the program was initiated.  This is stored in; Process->pr_CIS.
Never close the filehandle returned by Input!

To change the stream in an application, call SelectInput() to install
a new stream, while saving the return value for restoration before the
application terminates.

**Result:**
file - BCPL pointer to a file handle.

**Notes:**
This function is NOT callable from a task.

**See also:** Output(), ErrorOutput(), 
SelectOutput(), SelectInput(), SelectErrorOutput()

---

### dos.library/IoErr

**Return extra information from the system.**

**Synopsis:**
```c
int32 error = IoErr(void);
```

**Description:**
Nearly all DOS functions can return an error code to indicate failure
of some sort.  When this happens (for whatever reason) this routine
can be called to obtain more information about the error, if required.

It is also used (less frequently) by some routines to pass back a 
secondary result when the primary result indicates a success,
these cases are always documented and are the ONLY time when a
guaranteed value can be obtained from IoErr() upon primary success.

DOS attempts to avoid clearing this value so that secondary error
codes are not easily lost, therefore the only time you can be sure it
is cleared to zero, is when you do it yourself with IDOS->SetIoErr(0)
or when the program first begins execution.
Any exceptions to this rule are generally documented.

Never assume the error code will survive across ANY other DOS calls,
or calls from other subsystems that may indirectly call DOS, or even
clib wrapper calls that perform any I/O whatsoever, even to CONSOLE:. 

If not specifically testing for success or failure immediately after a
function call, always at least capture any possible error code there
for later processing, error handling or reporting.

**Result:**
error - 32 bit integer.

   ERROR CODES
Error conditions may be signalled by dos.library, handlers and file
systems. These are typically numbers between 100 and 500, consistent
with the error code definitions in the <dos/errors.h> header file.
If an error code < 100 is set, it is likely that a low level device
driver, such as trackdisk.device, generated it.

Listed below you will find a list of AmigaDOS error codes, accompanied
by explanations as to what may have caused them.

    ERROR_INVALID_PACKET_MESSAGE
 The contents of a packet ('struct DosPacket') are not
 initialized correctly, or even the packet address itself
 is invalid, or the wrong packet was returned.

    ERROR_NO_FREE_STORE
 Not enough memory available

    ERROR_BAD_TEMPLATE
 The AmigaDOS wildcard pattern used is inconsistent, or
 the command template given to ReadArgs() is faulty.

    ERROR_BAD_NUMBER
 A numerical argument is required, or, such as for
 ExAll(), an unsupported data type value was requested.

    ERROR_REQUIRED_ARG_MISSING
 An argument is required that you did not supply.

    ERROR_KEY_NEEDS_ARG
 Keyword was specified with no argument.

    ERROR_TOO_MANY_ARGS
 Too few or too many arguments.

    ERROR_UNMATCHED_QUOTES
 You have an odd number of quotation marks at the beginning
 or the end of a path or string.

    ERROR_LINE_TOO_LONG
 Your command line is incorrect or contains too many arguments,
 or a string parameter is too-long for the supported length.

    ERROR_FILE_NOT_OBJECT
 You misspelt the command name or the file is not a loadable
 (program or script) file.

    ERROR_INVALID_RESIDENT_LIBRARY
 The operating system does not match the required version.

    ERROR_OBJECT_IN_USE
 The specified file or directory is being edited by another
 application or is assigned.

    ERROR_OBJECT_EXISTS
 The name specified is assigned to another file or directory.

    ERROR_DIR_NOT_FOUND
 AmigaDOS cannot find the specified directory. This is often
 used in place of ERROR_OBJECT_NOT_FOUND if it is known
 beforehand that the object to be located must be a directory
 and cannot be found.

    ERROR_OBJECT_NOT_FOUND
 AmigaDOS cannot find the specified file or device.

    ERROR_BAD_STREAM_NAME
 Occurs when specifying a window size for a Shell, ED, or
 ICONX window. The window may be too big or too small or you
 omitted an argument. Also occurs with the NEWSHELL command,
 if a device name is supplied that is not a window.

    ERROR_ACTION_NOT_KNOWN
 The device handler cannot do the requested operation. 
 For example, the console handler cannot rename things.
 This error code is used ONLY to determine when a dospacket
 or filesystem vector-port function is not supported by the
 respective filesystem, never to be used for any other purpose.
 See also: ERROR_NOT_IMPLEMENTED 

    ERROR_NOT_IMPLEMENTED
 Used internally by dos.library to indicate that a dos.library
 function is not yet implemented, or a feature is unavailable. 
 Never, never, never use this error code in place of 
 ERROR_ACTION_NOT_KNOWN !!!

    ERROR_INVALID_COMPONENT_NAME
 There is an invalid character in the file name or the file
 name is too long.

    ERROR_INVALID_LOCK
 An operation was attempted on a Lock or FileHandle and
 the provided parameter was found to be inconsistent or
 invalid.

    ERROR_OBJECT_WRONG_TYPE
 You may have specified a file name for an operation that
 requires a directory name, or vice versa.

    ERROR_DISK_NOT_VALIDATED
 If you have just inserted a disk, the disk validation
 process may be in progress. It is also possible that the disk
 is corrupt.

    ERROR_DISK_WRITE_PROTECTED
 The plastic tab of a floppy disk is in the write-protect
 position or the disk has been locked. It's also possible that
 the file system cannot be written to (CD-ROM).

    ERROR_RENAME_ACROSS_DEVICES
 The Rename() function can move a file from one directory to
 another, but not from one volume to another.

    ERROR_DIRECTORY_NOT_EMPTY
 You tried to delete a directory that contains files or
 subdirectories.

    ERROR_TOO_MANY_LEVELS
 Directory nesting is too deep.

    ERROR_DEVICE_NOT_MOUNTED
 If the devices is a floppy disk, it has not been inserted in
 a drive. If it is another type of device, it has not been
 mounted, or the name is misspelt.

    ERROR_SEEK_ERROR
 This can occur if you are calling any function that changes the
 internal file pointer position and the final file position is
 beyond the beginning or the end of the file.

    ERROR_COMMENT_TOO_BIG
 This can occur with SetComment() if the comment string
 is larger than permitted (typically 80 characters).

    ERROR_DISK_FULL
 There is no more room on the medium to complete a
 file system operation.

    ERROR_DELETE_PROTECTED
 A file or directory on an otherwise write-enabled medium
 cannot be deleted or replaced.

    ERROR_WRITE_PROTECTED
 A file or directory on an otherwise write-enabled medium
 cannot be modified.

    ERROR_READ_PROTECTED
 A file cannot be read from.

    ERROR_NOT_A_DOS_DISK
 A medium cannot be accessed since the file system
 responsible for it cannot make sense of its contents.

    ERROR_NO_DISK
 There is no medium present in a disk drive. The
 requested file system operation cannot be completed.

    ERROR_NO_MORE_ENTRIES
 This error code indicates that the ExamineDir(), ExNext()
 or ExAll() functions have reached the end of a directory
 and will return no further entries.

    ERROR_IS_SOFT_LINK
 This is returned by file systems in order to indicate
 to dos.library that the name of the object given must
 be resolved as a soft link and does not point to a
 directory or file which the file system itself could
 handle.

    ERROR_BAD_HUNK
 The structure of an executable file is inconsistent.
 The file may have been damaged and corrupted.

    ERROR_RECORD_NOT_LOCKED
 The record you tried to unlock through UnLockRecord() is
 not actually locked.

    ERROR_LOCK_COLLISION
 The record you tried to lock is already locked.

    ERROR_LOCK_TIMEOUT
 Your attempt to lock a record failed, even after waiting
 for the period you specified.

    ERROR_BUFFER_OVERFLOW
 User or internal buffer overflow

    ERROR_BREAK
 A program was aborted, such as by sending it a Break
 signal in the Shell.

    ERROR_NOT_EXECUTABLE
 A command is neither a script file nor a program file.

    ERROR_IS_PIPE
 An operation, such as Seek() cannot be performed on
 certain types of file systems, such as the PIPE: device.

    ERROR_BROKEN_PIPE
 The connection between the producer and consumer of data
 sent and read from a pipe has been broken because the
 consumer has closed its side of the pipe.

    ERROR_WOULD_BLOCK
 An operation could not be performed immediately, as
 requested. This can happen, for example, when data is
 written to a non-blocking pipe and is rejected because
 the pipe buffer is already full.

    ERROR_INVALID_DEVICE_TYPE
 The device type given to MountDevice() is not supported.

    ERROR_INVALID_DEVICE_NAME
 The device name given to MountDevice() and other functions
 such as MakeDosEntry() or AllocDosObject() is not permitted.

    ERROR_DEVICE_NAME_TOO_LONG
 The device name given to MountDevice() and other functions
 such as MakeDosEntry() or AllocDosObject() is too long.
 DosList names cannot be longer than 255 characters.

    ERROR_INVALID_SECTOR_SIZE
 The sector size given to MountDevice() is not
 supported. It must be a multiple of 4.

    ERROR_CONTROL_STRING_TOO_LONG
 The control string given to MountDevice() is too
 long. It cannot be longer than 255 characters.

    ERROR_EXEC_DEVICE_NAME_TOO_LONG
 The device driver name given to MountDevice() is
 too long. It cannot be longer than 255 characters.

    ERROR_HANDLER_STRING_TOO_LONG
 The handler name given to to MountDevice() is too
 long. It cannot be longer than 255 characters.

    ERROR_STARTUP_STRING_TOO_LONG
 The startup string given to MountDevice() is too
 long. It cannot be longer than 255 characters.

    ERROR_SIZE_MISSING
 The file system size parameters (number of heads,
 number of sectors per block, number of blocks per
 track) given to MountDevice() are inconsistent.
 One of them is 0.

    ERROR_DEVICE_NAME_MISSING
 No device name was provided to MountDevice().

    ERROR_INVALID_NUMBER_OF_CYLINDERS
 The number of cylinders provided to MountDevice()
 is inconsistent.

    ERROR_HANDLER_CANNOT_BE_STARTED
 The handler mounted through MountDevice() cannot
 be started because no handler name, MsgPort or
 segment list were provided.

    ERROR_INVALID_GLOBAL_VECTOR
 The global vector value provided to MountDevice() is
 not supported.

    ERROR_INVALID_TASK_PRIORITY
 The handler process priority provided to MountDevice()
 is not supported.

    ERROR_OBJECT_TOO_LARGE
 A function parameter or object was larger than can be 
 handled by a particular function, or subsequently would
 have caused a numerical overflow.

The following error codes should be considered obsolete as
of AmigaOS release 4:

    ERROR_TASK_TABLE_FULL
    ERROR_NO_DEFAULT_DIR
    ERROR_OBJECT_LINKED
    ERROR_UNLOCK_ERROR

**Notes:**
This function will do nothing but return 0, if called from a task.
DOS guarantees that IoErr() is cleared only when your program starts.

**See also:** Fault(), PrintFault(), SetIoErr()

---

### dos.library/IsFileSystem (V36)

**Returns whether a Dos handler is a filesystem.**

**Synopsis:**
```c
int32 result = IsFileSystem(CONST_STRPTR name);
```

**Description:**
Returns whether the 'name' is a filesystem or not.
A filesystem supports separate files for storing information,
it is required to support locks to filesystem objects and
must respond positively to the object examination functions.
It may also support sub-directories, but is not required to.

**Inputs:**
name   - (STRPTR) Pointer to a nul-terminated string.
  (See GetDeviceProcFlags() for details about this.)

**Result:**
result - (int32) boolean; (zero or non-zero), non-zero indicates 
   the device is a file system.

**Notes:**
This function is NOT task callable.

If the filesystem is not a vector-port based filesystem or does not
support the dospacket which implements this query, IsFileSystem() will
search the 'name' string for a colon character (':'),  if one is found,
the handler identifier part will be used to Lock() the root directory
as an indicator whether the volume is a filesystem or not.

**See also:** IsFileSystemPort(), GetDeviceProcFlags().

---

### dos.library/IsFileSystemPort

**Determine if a port is for a filesystem. (V53.87)**

**Synopsis:**
```c
int32 result = IsFileSystemPort(struct MsgPort *port);
```

**Description:**
Returns whether the device port is for a filesystem or not. 
A filesystem supports separate files for storing information,
it is required to support locks to filesystem objects and
must respond positively to the object examination functions.
It may also support sub-directories, but is not required to.

**Inputs:**
port   - (struct MsgPort *) Pointer to a handler message port.

**Result:**
result - (int32) boolean; (zero or non-zero), non-zero indicates the
   handler is a file system.

**Example:**
```c
Test if a filehandle is for a filesystem, or a stream handler or nil.

static int32 IsFileSystemFH( BPTR bfilehandle )
{
    struct FileHandle *fh = BADDR(bfilehandle);
    return( (fh) ? IDOS->IsFileSystemPort(fh->fh_MsgPort) : FALSE );
}
```

**Notes:**
This function provides no locking for the 'port' of the handler.
Passing NULL for the 'port' argument returns FALSE. (ie; NIL:)
This function is NOT task callable.

**See also:** IsFileSystem().

---

### dos.library/IsInteractive

**Discover whether a file handle is "interactive".**

**Synopsis:**
```c
int32 status = IsInteractive( BPTR file );
```

**Description:**
The return value 'status' indicates whether the file associated
with the file handle 'file' is connected to a virtual terminal.

The handler concerned is responsible for setting the status of
the file handle field used by this function.

Currently, handlers such as AUX and the Port handlers set the state
of this field to be interactive.

**Inputs:**
file - BCPL pointer to an open file handle.

**Result:**
status - boolean; (zero or non-zero), non-zero if Interactive.

---

### dos.library/LoadSeg

**Loads a loadable file into memory. (68K or NATIVE)**

**Synopsis:**
```c
BPTR seglist = LoadSeg( CONST_STRPTR name );
```

**Description:**
Loads the file sections into memory using elf.library or hunk.library.
The file will be closed after loading, except for hunk overlay files.
All necessary relocation is handled here.

**Inputs:**
name    - STRPTR; pointer to a null-terminated string path/name.
           See GetDeviceProcFlags() for details about this.

**Result:**
seglist - BCPL pointer to a seglist.

**Notes:**
This function is NOT task callable.

Please note that LoadSeg() functions call the TrackSegmentList()
function internally, and UnLoadSeg() calls UnTrackSegmentList().

From V52.14, this functions has only one parameter, the old LoadSeg()
vector actually accepted three, for use with overlay hunk loadables,
that vector is now been renamed to OBSOLETELoadSeg().

From 53.74 all other legacy compatibility loadseg vectors are now small
stubs that simply call this function.

**See also:** GetSegListInfo(), UnLoadSeg(), CreateNewProc(), RunCommand(), 
AllocSegList().

---

### dos.library/Lock (V36)

**Lock a directory or file.**

**Synopsis:**
```c
BPTR lock = Lock( CONST_STRPTR name, int32 mode );
```

**Description:**
Return a filing system lock on the file or directory if possible.

If Lock() fails for any reason, the value returned will be zero, 
and a secondary error code will be available by calling IoErr().

Lock() will post a requester if the volume/device is currently not
mounted, see SetProcWindow() to disable requesters if required.

**Inputs:**
name  - (STRPTR) - pointer to a null-terminated string
 Identify the filesystem object with any of the standard
 filesystem supported access methods.

 It may be a current directory lock relative path;
 ("foo"), (""), ("foo/bar")

 Relative to the current directory volume root;
 (":foo"), (":"), (":foo/bar"),

 A device/volume/assignment relative specification;
 ("foo:"), ("foo:bar"), ("foo:bar/baz"),

 Or one of the built-in DOS pseudo devices;
 ("progdir:foo/bar"), ("currdir:foo/bar")

 Consult GetDeviceProcFlags() autodoc for more details.

mode  - (int32)  - SHARED_LOCK or EXCLUSIVE_LOCK.
 The following are mode synonyms defined in <dos/dos.h>:
 SHARED_LOCK    = ACCESS_READ
 EXCLUSIVE_LOCK = ACCESS_WRITE

 Do not use random values for mode.

 From V53+, requesting an exclusive lock on a directory shall
 always quietly return a shared lock from compliant filesystems,
 only files are permitted to have an exclusive lock.

**Result:**
lock  - BCPL pointer to a lock, or zero for failure.
 On failure, IoErr() will tell you why it failed.

**Notes:**
This function is NOT callable from exec tasks.

Tricky assumptions about the internal format of a lock are unwise,
as are any attempts to use the fl_Link, fl_Key or fl_Access fields.

Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

Make sure that you always pass either SHARED_LOCK or EXCLUSIVE_LOCK
(or the equivalent ACCESS_READ and ACCESS_WRITE, respectively) as
the access mode. These parameters may be passed straight down to the
file system which may react unpredictably if neither SHARED_LOCK
nor EXCLUSIVE_LOCK is used. It might grant you a lock which is
neither an exclusive nor a shared lock.

This function will always resolve multi-assignments and softlinks.

**See also:** LockTags(), UnLock(), DupLock(), ParentDir(), ChangeMode(), 
NameFromLock(), DevNameFromLock(), DupLockFromFH(), SetProcWindow()
   GetDeviceProcFlags().

---

### dos.library/LockDosList (V36)

**Locks the specified Dos lists for use.**

**Synopsis:**
```c
struct DosList *dlist = LockDosList(uint32 flags);
```

**Description:**
Application programmers should use the new DOS_VOLUMELIST (V53.52+)
feature of AllocDosObject() rather than locking the doslist
themselves if requiring a list of mounted volumes/devices/assigns.

This is a low level function that Locks the dos device list in 
preparation to walk the singly linked list.
If the list is 'busy' then this routine will not return until it is 
available.  This routine "nests": you can call it multiple times
and then must unlock it the same number of times.
  
The 'dlist' returned is NOT a valid DosList pointer, it contains 
special state information that is to be passed only to the other
DosEntry functions, such as NextDosEntry() and FindDosEntry().

**Inputs:**
flags - Flags stating which types of nodes you want to lock. 
 This must be a combination of the following:

 LDF_DEVICES -- File system devices, such as "DF0:".

 LDF_VOLUMES -- The names storage media bears, such as
     "Workbench:".

 LDF_ASSIGNS -- Names bound to directories and volumes,
     such as "LIBS:".

    Additionally, you must specify the manner in which you want
    to access the DosList. This must be one of the following:

 LDF_READ -- You will be looking at the DosList contents,
     but will not be modifying it. This implies shared
     access to the DosList.

 LDF_WRITE -- You will be removing, modifying or adding
     new entries to the DosList. This implies exclusive
     access.

    Note that you cannot combine the LDF_READ and LDF_WRITE
    flags with one another.

**Result:**
dlist - NULL or a "special" pointer to the beginning of the list. 
 The pointer is NOT a valid node and must only be passed as
 the 'dlist' parameter to NextDosEntry() and FindDosEntry()!

**Example:**
```c
As an example, here's how you can search for all volumes of a 
specific name and do something with them:

    dl = IDOS->LockDosList(LDF_VOLUMES|LDF_READ);
    while (dl = IDOS->FindDosEntry(dl,name,LDF_VOLUMES))
    {
    /*
     *  Add this entry to your private list of volumes to process later.
     *
     *  For simple processing, you could also use it inside here, 
     *  but for anything else I strongly advise against it unless you
     *  understand the semantics about avoiding semaphore deadlocks.
     *
     *  It is never acceptable to call functions that involve sending
     *  dospackets to any handler currently in the doslist while the 
     *  doslist is locked.
     */

 dl = IDOS->NextDosEntry(dl,LDF_VOLUMES);
    }
    
    /* Process list of volumes saved above, or the current entry if
     * you're only interested in the first one of that name.
     */

    IDOS->UnLockDosList(LDF_VOLUMES|LDF_READ);
    /* must not use dl after this! */
```

**Notes:**
This function is callable from exec tasks.

Note for handler writers: you should never call this function with
LDF_WRITE, since it can deadlock you (if someone has it read-locked
and they're trying to send you a packet).  Use AttemptLockDosList()
instead and otherwise keep processing incoming packets until you have
managed to lock the list.  It is not enough to pick up the incoming
packets and queue them for processing later: the software which
sent you the packet may be waiting for you to respond before it will
let go of the DosList.

Older documentation used to suggest that spawning a separate process
for arbitration or busy-waiting with small delays could be used to
work around the deadlock problem discussed in the previous paragraph.
Unfortunately, neither approach is really safe for a file system
handler. If it has to gain exclusive access to the DosList then
neither multithreading nor busy-waiting will solve the arbitration
problem. The handler must be able to respond to incoming packets
until the DosList is ready to be locked. This is the essence of the
problem.  See also; NonBlockingModifyDosEntry().

The 'dlist' pointer this function returns will be valid only as long
as the DosList has not been modified. For example, if you obtain
the list pointer with LockDosList(), then remove an entry which
you know is on the list (e.g. a volume node), you may invalidate
the list pointer LockDosList() returned to you: as luck may have
it, you may have just removed the list entry your previous call
to LockDosList() provided you with. In such cases it is recommended
to relock the list again with the same parameters as before, which
will return the now current head of the list (keep in mind that
LockDosList() will nest).

**See also:** AllocDosObject(), AttemptLockDosList(), UnLockDosList(),
NextDosEntry(), NonBlockingModifyDosEntry().

---

### dos.library/LockRecord

**Locks a portion of a file.**

**Synopsis:**
```c
int32 success = LockRecord(BPTR fh, int64 offset, int64 length,
                    uint32 mode, uint32 timeout);
```

**Description:**
This locks a portion of a file for exclusive or shared access.  
Timeout is how long to wait in ticks (1/50th sec) for the record to
become available.   For the IMMED modes, the timeout is ignored.

Valid locking modes are:
    REC_EXCLUSIVE         (Write)
    REC_EXCLUSIVE_IMMED   (Write)
    REC_SHARED            (Read)
    REC_SHARED_IMMED      (Read)

Control flags that may be ORed with one of the mode values above are:
    RECF_DOS_METHOD_ONLY  (Added 53.114)


Record locks are exclusively tied to the filehandle used to create them.
For example, the same filehandle can get any number of exclusive or
shared locks on the same record region.

The record locking arbitration only applies to record locks using
different filehandles on the same file.   These are co-operative locks,
they only affect other people calling the LockRecord[s]() functions
using different filehandles.

If an exclusive lock is granted for a record, then shared locks will be
rejected (IMMEDiate modes), or queued for up to the timeout value or 
until the exclusive record lock is released.

**Inputs:**
fh      - (BPTR)   File handle for which to lock the record
offset  - (int64)  Record start position in bytes
length  - (int64)  Length of record in bytes
mode    - (uint32) Type of lock requested, RECxxx (see:dos/record.h)
timeout - (uint32) Timeout interval in ticks.  0 is legal.

**Result:**
success - (int32)  boolean; (zero or non-zero)  Zero on error.

**Notes:**
Few filesystems implement this feature, however, from dos.library 
version 53.102 this function is now serviced by the built-in routine
if the filesystem rejects these requests.

From dos.library 53.114 a special control flag; RECF_DOS_METHOD_ONLY
may be ORed with the 'Mode' value to force the use of the dos.library
record locking even if record locking is supported by the underlying
filesystem.  This flag has been provided to be able to override the
automatic selection process that would normally be employed incase
the filesystems record locking function does not support a particular
feature that may only be available via the dos.library function.

Re: Close();
Please be advised that due to dependancies and idiosyncrasies of the
various filesystems that are available, the behavious of Close() with
regard to freeing filesystem record locking is currently indeterminant.
You are therefore advised to FreeRecord/s() of any records that may 
have been locked by the application, BEFORE calling Close().
For the V53.102+ dos.library built-in record locking functions only, 
the Close() function performs automatic record unlocking of all records
still remaining locked, that were created with the same filehandle
that is being Close()'ed.
 
The dos.library record locking permits locking of record regions yet
to be created, so that if a file is to be extended, it is possible
to pre-lock the new record region before it actually exists, 
filesystem supported record locking may not support this feature.

**Bugs:**
In 2.0 through 2.02 (V36), LockRecord() only worked in the ramdisk.
Attempting to lock records on the disk filesystem causes a crash.
This was fixed for V37.

**See also:** LockRecords(), UnLockRecord(), UnLockRecords()

---

### dos.library/LockRecords

**Lock a series of records.**

**Synopsis:**
```c
int32 success = LockRecords(struct RecordLock *record_array,
                     uint32 timeout);
```

**Description:**
This locks several records within a single file for exclusive access.
Timeout is how long to wait in ticks for the records to be available.
The wait is applied to each attempt to lock each record in the list.
It is recommended that you always lock a set of records in the same
order to reduce possibilities of deadlock.

The array of RecordLock structures is terminated by an entry with
rec_FH set to zero.

This is the structure passed to LockRecords() and UnLockRecords() from
dos.library v53.86+ 

struct RecordLock
{
    uint32   rec_Size;   /* MUST be set to sizeof(struct RecordLock) */
    BPTR     rec_FH;     /* filehandle */
    int64    rec_Offset; /* byte offset in file */
    int64    rec_Length; /* byte length of record to be locked */
    uint32   rec_Mode;   /* type of lock, REC_xxx (see: dos/record.h) */
};

Note that the rec_Size field MUST be set in each structure of the array
or it simply will not work, failing to do so will cause these functions
to assume the parameter being passed is the obsolete 32 bit style
structure definition found in dos/obsolete.h

**Inputs:**
record_array - Array of struct RecordLock structures to be locked.
timeout      - Timeout interval.  0 is legal.

**Result:**
success      - boolean; (zero or non-zero),  Zero on failure.

**Notes:**
Few filesystems implement this feature, however, from dos.library 
version 53.102 this function is now serviced by the built-in routine
if any filesystem rejects these requests.

Re: Close();
Please be advised that due to dependancies and idiosyncrasies of the
various filesystems that are available, the behaviour of Close() with
regard to freeing record locking is currently indeterminant.
You are therefore advised to FreeRecord/s() of any records that may 
have been locked by the application, BEFORE calling Close().
For the V53.102+ dos.library built-in record locking functions only,
the Close() function performs this automatically if required.
 
See LockRecord() for more information.

**See also:** LockRecord(), UnLockRecord(), UnLockRecords()

---

### dos.library/LockTagList

**Lock a directory or file, with extra features. (V53.56)**

**Synopsis:**
```c
BPTR lock = LockTagList( CONST struct TagItem * tags );

BPTR lock = LockTags( uint32 Tag1, ... );
```

**Description:**
Return a filing system lock on the file or directory if possible.
Performs the same basic function as Lock() but with extra features
such as being able to control automatic softlink resolution and also
control multi-assignment searching.
This function can also return optional information relating to the
number of soft linked objects in a given path and details of the object
reference method and some additional auxilliary information.
 
If the function fails for any reason, the value returned will be zero, 
and a secondary error code will be available by calling IoErr().

If the volume/device is currently not mounted, a requester will be
posted.  See SetProcWindow() to disable requesters if required.

**Inputs:**
LK_Name       (STRPTR)   -- Mandatory pointer to a nul-terminated string.
       Identify the filesystem object with any of the standard
       filesystem supported access methods.
       (See; IDOS->GetDeviceProcFlags() for more info on this.)

       It may be a current directory lock relative path;
       ("foo"), (""), ("foo/bar")

       Relative to the current directory volume root;
       (":foo"), (":"), (":foo/bar"),

       A device/volume/assignment relative specification;
       ("foo:"), ("foo:bar"), ("foo:bar/baz"),

       Or one of the built-in DOS pseudo devices;
       ("progdir:foo/bar"), ("currdir:foo/bar")

LK_Mode       (int32) -- Access mode;  SHARED_LOCK or EXCLUSIVE_LOCK.
       From V53+, requesting an exclusive lock on a directory
       shall always quietly return a shared lock from compliant
       filesystems, only files are to have exclusive locks.
       (Default; SHARED_LOCK when tag is not specified)

LK_ResolveMA  (int32) -- Optional switch to control multi-assignment
       resolution, when this tag is set to FALSE, if the object
       the LK_Name references is a multi-assignment, then this
       function will return failure with IoErr() set to the 
       error code ERROR_OBJECT_NOT_FOUND, rather than performing
       the normal automatic resolution.
       (Default; TRUE when tag is not specified) (Added 54.21)

LK_ResolveSL  (int32) -- Optional switch to control automatic softlink
       resolution, when this tag is set to FALSE, if the object
       the LK_Name references is a softlink, this function will
       return failure with IoErr() set to ERROR_IS_SOFT_LINK,
       rather than performing the normal automatic resolution.
       (Default; TRUE when tag is not specified) (Added 53.117)

LK_SoftLinks  (uint32 *) -- Optional pointer to a storage area that is
       the sizeof(uint32).
       On success, the value pointed to, will contain the number
       of softlinks resolved in the supplied path/name string.
       0 will be returned when there are no softlinks.
       (Currently 15 softlinks are the maximum for a path.)
       (Default; NULL)

LK_InfoMask   (uint32 *) -- Optional pointer to a storage area that is
       the sizeof(uint32).
       On success, the value pointed to, will have a bitfield set
       that represents various aspects about the object reference.
       The LOCKF_xx  field numbers are shown below for convenience,
       the bit definitions can be found in dos/dos.h
       (Default; NULL)

**Result:**
lock    --    BCPL pointer to a lock, or zero for failure.
       On failure, IoErr() will tell you why it failed.

**Notes:**
This function is NOT callable from exec tasks.

Tricky assumptions about the internal format of a lock are unwise,
as are any attempts to use the fl_Link, fl_Key or fl_Access fields.

Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

LK_Softlinks tag allows for the return of the number of softlinked
components that were automatically resolved in the path/name string.
The first two bitfields of the LK_InfoMask also relate to softlinks.

The LK_InfoMask tag allows for the return of a bitfield representing
information about the name string supplied and the filesystem object.
The current bit and field definitions can be found in dos/dos.h 
only the field number definitions are shown below for convenience;
 
LOCKF_SOFTLINK_MIDPART
    One or more soft links were found in the middle of the path but
    none of these formed the last component of the specified path.

LOCKF_SOFTLINK_ENDPART
    A soft link was the last component of the specified path.

LOCKF_DEVICE
    The supplied name is a device relative specification.

LOCKF_VOLUME
    The supplied name is a volume relative specification.

LOCKF_ASSIGNMENT
    The supplied name is an assignment relative specification.

LOCKF_PROGDIR
    The supplied name is a PROGDIR: relative specification.

LOCKF_CURRDIR
    The supplied name is a CURRDIR: relative specification.

LOCKF_ROOTDIR
    The supplied name is a root directory relative specification.

LOCKB_FILESYS
    The supplied specification returned the root of the filesystem
    from the message port stored in; process->pr_FileSystemPort.
    This can only occur if the process->pr_CurrentDir lock is ZERO when
    a current directory relative or root dir access is attempted.

**See also:** UnLock(), DupLock(), ParentDir(), Lock(), ChangeMode(), NameFromLock(),
DupLockFromFH(), SetProcWindow(), Fault(), GetDeviceProcFlags().

---

### dos.library/MakeLink (V36)

**Creates a filesystem link.**

**Synopsis:**
```c
int32 success = MakeLink(CONST_STRPTR linkname, APTR dest, int32 type);
```

**Description:**
Create a filesystem link called 'linkname' to object 'dest'.  

For creating softlinks, 'dest' is a pointer to a null-terminated
target string with 'type' set to LINK_SOFT.

For hardlinks, dest is a lock (BPTR) with the 'type' parameter
set to LINK_HARD.

Softlinks are resolved at access time by a combination of the
filesystem (by returning ERROR_IS_SOFT_LINK to DOS), and by DOS
calling the ReadSoftLink() function internally to resolve the target
object for any links that are encountered, which is now automatic when
using the new V50 64 bit ExamineData API functions.

Hardlinks are resolved by the filesystem in question.
A series of hardlinks to a file are all equivalent to the file itself.
If one of the links (or the original file) is deleted, the data remains
until there are no more hardlinks left.

Besides Delete(), and conditionally Rename(), this is the only other
function that can directly affect symbolic links.

**Inputs:**
linkname - (CONST_STRPTR) Name of the link to create.

dest     - (STRPTR) string, when 'type' = LINK_SOFT   or,
    (BPTR)   lock,   when 'type' = LINK_HARD.

type     - (int32) LINK_HARD for hard-links, LINK_SOFT for soft-links.

**Result:**
Success  - (int32) boolean, (zero or non-zero)

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

**Notes:**
This function is NOT callable from tasks.

For hardlinks, the supplied 'dest' target reference lock is not
harmed in the making of the hardlink. Like the examinations functions,
it is only used to identify the target object, it is never consumed. 

Supplying a 'dest' target argument of 0 will cause failure.

From 53.73 DOS explicitly checks for an existing object of the same
name as the linkname and fails with ERROR_OBJECT_EXISTS if one exists,
some filesystems didn't check for this and it was previously possible
to destroy an existing file by creating a link with the same name.


Broadly-speaking: you always have to handle links with caution. 
While hardlinks work just about the same as regular files and
directories, softlinks don't. 

The difference is in how you treat softlinks during directory scanning.

Pitfall #1.
If you examine a link object via ExamineObject(), it will be identified
not as a link (which it is) but rather as the target object the link
points to, because the simple act of locking the link name will cause
automatic resolution to the links target object by dos.library.  
(See also;  Lock(), LockTags() for more info and options)  

Pitfall #2.
When performing a directory scan via the ExamineDir() function,
in the listing, linked objects correctly appear as hard/soft links,
and optionally, the examinedata->Link field can also show the name of
the target object, if that option is selected.

Target object type checking for softlinks must be done by examining
the target object with ExamineObject() and using the appropriate 
EXD_IS_xxx macro.   Note that this call can fail because a soft linked
object might be on a volume that isn't currently mounted, 
it is therefore recommended to disable DOS requesters during the
ExamineObject() operation to prevent the "Please Insert Volume..."
requester appearing.  See; SetProcWindow().
Don't forget to free the result examinedata again and resume the
scanning process.
If you got what you wanted, you might want to report the correct type
of link in the directory listing, such as Workbench, the ASL file 
requester, the Dir and List commands, etc do. 

Pitfall #3 is recursive directory scanning.
If you want to stay out of trouble, never ever enter a linked directory
unless the user tells you to do it, and then, only enter once. 
The problem being that the directory scanning process might just restart
somewhere on the same file system above the directory you are currently
scanning: the link creates a "loop" in the directory tree. 
Your recursive scanning process may never terminate.
Newer filesystems are required to prevent you creating hard directory
links that would cause a "loop", but older filesystems may not check
this, and softlinks never check the target and can point to anywhere.

**Bugs:**
In V36, soft-links didn't work in the ROM filesystem, was fixed for V37.

From 53.130 DOS converted all relative softlink target paths to full
device centric DOS paths before calling the filesystem, this was fixed
in 53.155 so that softlink targets are not affected by this function.

**See also:** Rename(), Delete(), ReadSoftLink(), Open(), Lock(), ExamineObject(),
ExamineDir(), GetDeviceProcFlags(), SetProcWindow().

---

### dos.library/MatchEnd (V36)

**Free storage allocated for MatchFirst()/MatchNext()**

**Synopsis:**
```c
VOID MatchEnd(struct AnchorPath *AnchorPath);
```

**Description:**
Return all storage associated with a given search.

**Inputs:**
AnchorPath - Anchor used for MatchFirst()/MatchNext()
      MUST have been allocated with AllocDosObject().

**See also:** MatchFirst(), ParsePattern(), MatchNext(), AllocDosObject(),
<dos/anchorpath.h>

---

### dos.library/MatchFirst (V36)

**Finds a file that matches a string.**

**Synopsis:**
```c
int32 error = MatchFirst(CONST_STRPTR str, struct AnchorPath *anchor);
```

**Description:**
Locates the first file or directory that matches a given string.
MatchFirst() parses your string (you DO NOT pass it through
ParsePattern() - MatchFirst() does that for you), and the control
structure.  MatchFirst() normally initializes your AnchorPath
structure for you, and returns the first file that matched your
string, or an error.  Note that MatchFirst()/MatchNext() are unusual
for Dos in that they return 0 for success, or the error code (see
<dos/errors.h>), instead of the application getting the error code
from IoErr().

NB: Dos.library versions prior to 54.30 will have the ap_ExData pointer
set to NULL, this MUST be checked before access with previous releases.
The legacy fallback data will still be available in ap_Info but will
be limited to file sizes <4gig and names shorter than 108 bytes.
Always use the ap_ExData in preference to ap_Info when available.

When looking at the result of MatchFirst()/MatchNext(), the ap_ExData
(or ap_Info) field of your AnchorPath has the results of an examination
of the object.  You normally get the name of the object from the 
ap_ExData->Name, (or ap_Info.fib_FileName for legacy apps), 
and the directory it's located in from ap_Current->an_Lock. 
 
To access this object, normally you would temporarily SetCurrentDir()
to the directory lock, do an operation with the file/directory,
and then SetCurrentDir() back to your original directory.
This makes certain you affect the right object even when two volumes
of the same name are in the system.  
You can use ap_Buffer (with ap_Strlen, (set in the AllocDosObject())
to get a full path name to report to the user.

To initialize the AnchorPath struct (particularily when reusing it),
set ap_BreakBits to the signal bits (CDEF) that you want to take
a break on, or 0, if you want to inconvenience the user.
ap_Flags should be set to any flags you need or all 0's otherwise.
ap_FoundBreak should be cleared if you'll be using breaks.

If you want to have the full path name of the files you found,
allocate an appropriate space (1K min recommended) via your initial
call to AllocDosObject(), the size of it will be put in ap_Strlen
and the pointer to this buffer space will appear in ap_Buffer.

NB:   At all times ap_Buffer will be a non-NULL pointer, but unless
      you allocate additional space with ADO_Strlen, the buffer will
      simply point to a default one byte (cleared) memory area.
      So always check ap_Strlen to find out exactly how much space
      you really have, don't make assumptions about the pointer.

If you don't want the full path name, simply don't use the ADO_Strlen
tag with your call to AllocDosObject(), this will make sure the
ap_Strlen is zero.   In this case, the name of the file, and stats 
are available in the ExamineData ap_ExData, (or legacy ap_Info).

Then call MatchFirst() and then afterwards, MatchNext() with this
structure.  You should check the return value each time (see below)
and take the appropriate action, ultimately calling MatchEnd() when
there are no more files or you are done.  You can tell when you are
done by checking for the normal AmigaDOS return code
ERROR_NO_MORE_ENTRIES.

Note: Strings with trailing slashes may cause MatchFirst() /
      MatchNext() to return with an ap_Current->an_Lock on the
      object, and a filename of the empty string ("").

See ParsePattern() for more information on the patterns.

**Inputs:**
str     - Plain string or Pattern matching string to search for.
   This may be a simple "DEVS:" or a pattern such as "LIBS:#?".

anchor  - Place holder for search.  MUST be obtained from a call
   to AllocDosObjectTags(DOS_ANCHORPATH,...);

**Result:**
error   - 0 for success, or the non-zero error code.  
   (Opposite of most Dos calls!)

**Notes:**
New for V50: multi-volume assignments are also supported by the 
directory scanner but only if the argument string contains an
appropriate pattern-matching pattern that refers to an assignment
which represents a list of directories such as "LIBS:#?", then
subsequent calls to MatchNext() will end up visiting all entries of
the assignment list.  (Default = OFF) 
See: AllocDosObject() and MatchNext() documentation.

For V40 backward compatibility, this function will always clear 
IoErr() on entry.

**Bugs:**
In V36, there were a number of bugs with MatchFirst()/MatchNext().
One was that if you entered a directory with a name like "df0:l"
using DODIR, it would re-lock the full string "df0:l", which can
cause problems if the disk has changed.  It also had problems with
patterns such as #?/abc/def - the ap_Current->an_Lock would not
be on the directory def is found in.  ap_Buffer would be correct,
however.  It had similar problems with strings with trailing
slashes.  These have been fixed for V37 and later.

A bug that has not been fixed for V37 concerns a string argument of a
single directory name (such as "l").  If you enter such a directory
via DODIR, it re-locks "l" relative to the current directory.  Thus
you must not change the current directory before calling MatchNext()
with DODIR in that situation.  If you aren't using DODIR to enter
directories you can ignore this.  This may be fixed in some upcoming
release.

**See also:** MatchNext(), ParsePattern(), MatchEnd(), <dos/anchorpath.h>

---

### dos.library/MatchNext (V36)

**Synopsis:**
```c
int32 error = MatchNext(struct AnchorPath *AnchorPath);
```

**Description:**
Locates the next file or directory that matches a given pattern.
See <dos/anchorpath.h> for more information. Various bits in the
ap_Flags field allow the application to control the operation of
MatchNext().

These bits are either set automatically by subsequent calls to
MatchFirst()/MatchNext() or can be set by you to change the
operation of MatchNext():


APF_DOWILD - Unused.

APF_ITSWILD- Set by MatchFirst() if the name string submitted to 
      it does in fact contain wildcard patterns; otherwise
      it's clear.

APF_DODIR  - You can set this flag after MatchFirst()/MatchNext()
      has returned a directory entry in order to enter that
      directory during the next invocation of MatchNext().

APF_DIDDIR - Set by MatchNext() when the end of a directory is
      encountered which was previously entered by MatchNext()
      after the APF_DODIR flag was set.

      Note that every directory entered in this manner is
      returned "twice". That is, once when it is returned by
      MatchFirst()/MatchNext() and a second time when the
      end has been reached.

      You must clear the APF_DIDDIR flag after you have used
      it because MatchNext() will not clear it for you.

APF_NOMEMERR - May be set by MatchFirst()/MatchNext() if the 
      directory scanner ran out of memory. 
      If set, subsequent calls to MatchNext() will fail with 
      ERROR_NO_FREE_STORE set as the error code.

APF_DODOT -  Unused.

APF_DirChanged   - Set by MatchNext() if the lock stored in the
            AnchorPath->ap_Current->an_Lock field has changed
            since the last invocation.

APF_FollowHLinks - You can set this flag if you want MatchNext() to
            enter hard linked directories if the APF_DODIR
            flag is set. By default, hard linked directories
            will be skipped by the scanner which will pretend
            that they are empty.

APF_MultiAssigns - Set this bit with AllocDosObject() to allow
            Multi-Assign scanning to be enabled.  
            ( NOTE: ONLY AVAILABLE FROM DOS 50.77+ )

See MatchFirst() for other notes.

**Inputs:**
AnchorPath - Place holder for search.  
      MUST be allocated by AllocDosObject() !

**Result:**
error - 0 for success or error code.  (Opposite of most Dos calls!)

**Example:**
```c
/* Scan a directory recursively; the complete path names will
   be stored in the AnchorPath->ap_Buffer field and the scanning
   process can be aborted with Ctrl+C */

struct AnchorPath * ap;
int32 error,level,i;

ap = IDOS->AllocDosObjectTags( DOS_ANCHORPATH, 
                  ADO_Mask, SIGBREAKF_CTRL_C,
                  ADO_Strlen, 1024L,
                  TAG_END ); 

level = 0;

error = IDOS->MatchFirst("directory name",ap);
while(0 == error)
{
    if(ap->ap_Flags & APF_DIDDIR)
    {
 /* Leaving a directory entered below (APF_DODIR) */
 level--;
 ap->ap_Flags &= ~APF_DIDDIR;
    }
    else
    {
 /* Soft linked objects are returned by the scanner
    but they need special treatment; we are merely
    ignoring them here in order to keep this
    example simple */
 if(ap->ap_Info.fib_DirEntryType != ST_SOFTLINK)
 {
     /* Provide for some indentation */
     for(i = 0 ; i < level ; i++)
         IDOS->Printf(" ",0);

     IDOS->Printf("%s%s\n",ap->ap_Buffer,
         (ap->ap_Info.fib_DirEntryType < 0) ? "" : " (Dir)");

     /* If this is a directory, enter it */
     if(ap->ap_Info.fib_DirEntryType >= 0)
     {
         ap->ap_Flags |= APF_DODIR;
         level++;
     }
 }
    }

    error = IDOS->MatchNext(ap);
}

IDOS->MatchEnd(ap);
IDOS->FreeDosObject(DOS_ANCHORPATH,ap);
```

**Bugs:**
Prior to V50 directory entries which would match the syntax of
wildcard patterns could get caught up in the pattern matcher
which would then loop forever with each call to MatchNext().
This problem is no longer present in the V50 implementation, but
you may need to work around it if you are using MatchNext()
for directory scanning with no wildcard patterns involved. In that
case, it is recommended that you clear the AnchorPath->ap_Flags bit
APF_ITSWILD before each call to MatchNext().

See MatchFirst() for more.

**See also:** MatchFirst(), ParsePattern(), MatchEnd(), <dos/anchorpath.h>

---

### dos.library/MatchPattern (V36)

**Checks for a pattern match with a string.**

**Synopsis:**
```c
int32 match = MatchPattern(CONST_STRPTR pat, CONST_STRPTR str);
```

**Description:**
Checks for a pattern match with a string.  The pattern must be a
tokenized string output by ParsePattern().  
This routine is case-sensitive.

NOTE: this routine is highly recursive.  You must have at least
1500 free bytes of stack to call this (it will cut off it's
recursion before going any deeper than that and return failure).
That's _currently_ enough for about 100 levels deep of #, (, ~, etc.

**Inputs:**
pat   - Special pattern string to match as returned by ParsePattern()
str   - String to match against given pattern

**Result:**
match - boolean; (zero or non-zero), result of pattern match.  
 On failure, IoErr() will return 0 or ERROR_TOO_MANY_LEVELS.
 (starting with V37 - before that there was no stack checking).

**Notes:**
For V40 backward compatibility, this function will always clear 
IoErr() on entry.

**See also:** ParsePattern(), MatchPatternNoCase(), MatchFirst(), MatchNext()

---

### dos.library/MatchPatternNoCase (V36)

**Checks for a pattern match with a string.**

**Synopsis:**
```c
int32 match = MatchPatternNoCase(CONST_STRPTR pat, CONST_STRPTR str);
```

**Description:**
Checks for a pattern match with a string.  The pattern must be a
tokenized string output by ParsePatternNoCase().  This routine is
case-insensitive.

NOTE: this routine is highly recursive.  You must have at least
1500 free bytes of stack to call this (it will cut off it's
recursion before going any deeper than that and return failure).
That's _currently_ enough for about 100 levels deep of #, (, ~, etc.

**Inputs:**
pat   - Special pattern string to match as returned by
 ParsePatternNoCase()
str   - String to match against given pattern

**Result:**
match - boolean; (zero or non-zero), result of pattern match.
 On failure, IoErr() will return 0 or ERROR_TOO_MANY_LEVELS
 (starting with V37 - before that there was no stack checking).

**Notes:**
For V40 backward compatibility, this function will always clear 
IoErr() on entry.

**See also:** ParsePatternNoCase(), MatchPattern(), MatchFirst(), MatchNext()

---

### dos.library/MaxCli (V36)

**Synopsis:**
```c
uint32 number = MaxCli(void);
```

**Description:**
Scans the DOS CLI process list and returns the highest CLI number in use.
CLI numbers are reused, and are usually as small as possible.
To find all CLIs, scan using FindCliProc() from 1 to the value MaxCLI()
returned.  (avoid calling MaxCli() in the loop itself.)  
The number returned by MaxCli() may change as processes are created 
and terminated.  (See below.)

**Result:**
number - The highest CLI number that is in use. 
  If there are no CLI processes at all, zero will be returned.

   V51 LOCKING 
From V51+ this function will internally apply a READ (shared) semaphore
lock to the list by calling ObtainSemaphoreShared() / ReleaseSemaphore()
using the public list semaphore.   However, if this function is used in
conjunction with the function FindCliProc(), you will need to surround
the whole routine with a READ (shared) semaphore lock to avoid state 
changes occuring between function calls.    
(Also see; FindCliProc() documentation for more info)

**Notes:**
From V53.141 IoErr() will return the next free cli number that will
be used for the next CLI process to start up.  This feature is used
internally for allocating CLI numbers for new processes.

**See also:** FindCliProc().

---

### dos.library/NameFromFH (V36)

**Get the volume name/path of an open filehandle.**

**Synopsis:**
```c
int32 success = NameFromFH(BPTR filehandle,STRPTR buffer,int32 buflen);
```

**Description:**
Returns a fully qualified volume and path for the filehandle. 
This routine is guaranteed not to write more than 'buflen' bytes into
the buffer.  The buffer will be null-terminated.  

If the buffer is not large enough to hold the entire path, 
this function will fail and IoErr() will return ERROR_LINE_TOO_LONG.
If this occurs, use a larger buffer and try again.
Recommended minimum buffer size is 1024 bytes.

The buffer is guaranteed to be cleared on entry, providing a non-NULL
'buffer' is supplied and the 'buflen' is >0

**Inputs:**
filehandle - BPTR to a filehandle.
buffer     - Buffer to store object name and path.
buflen     - Length of buffer.

**Result:**
success    - boolean; (zero or non-zero)

**Example:**
```c
/*
**  Returns the volume centric path of a lock if no duplicate volumes
**  are ahead of it on the doslist, otherwise it returns the unique
**  device centric path name.
*/
int32 SaferNameFromFH(BPTR fh, STRPTR buffer, int32 len)
{
    int32 result = NameFromFH(fh, buffer, len);

    if( result )
    {
 BPTR testfh = Open(buffer, MODE_OLDFILE);

 if( testfh )
 {
     int32 samefh = SameFH(testfh,fh);

     Close(testfh);

     if( FH_SAME != samefh )
     {
         result = DevNameFromFH(fh,buffer,len,DN_FULLPATH);
     }
 }
    }

    return(result);
}
```

**Notes:**
This function is NOT task callable.
If the filehandle is zero, this function will fail.
This function will fail for "NIL:" streams, DevNameFromFH() will not.

**See also:** DevNameFromFH(), NameFromLock(), DevNameFromLock(), Lock(), IoErr(),
SetProcWindow().

---

### dos.library/NameFromLock (V36)

**Returns the volume name and path of a lock.**

**Synopsis:**
```c
int32 success = NameFromLock(BPTR lock, STRPTR buffer, int32 buflen);
```

**Description:**
Returns a fully qualified volume name and path for the lock.  
This routine is guaranteed not to write more than 'buflen' bytes into
the buffer.  The buffer will be null-terminated. 

If the buffer is not large enough to hold the entire path, 
this function will fail and IoErr() will return ERROR_LINE_TOO_LONG.
If this occurs, use a larger buffer and try again.
Recommended minimum buffer size is 1024 bytes.

If the lock argument is zero, the buffer will be filled with the
volume name for the assignment "SYS:".

The buffer is guaranteed to be cleared on entry, providing a non-NULL
'buffer' is supplied and the 'buflen' is >0

**Inputs:**
lock    - Lock of object to be examined.  (or zero)
buffer  - Buffer to store volume name and path.
buflen  - Length of buffer.

**Result:**
success - boolean; (zero or non-zero)

**Example:**
```c
/*
**  Returns the volume centric path of a lock if no duplicate volumes
**  are ahead of it on the doslist, otherwise it returns the device
**  centric path name.
*/
int32 SaferNameFromLock(BPTR lock, STRPTR buffer, int32 len)
{
    int32 result = NameFromLock(lock, buffer, len);

    if( result )
    {
 BPTR testlock = Lock(buffer, ACCESS_READ);

 if( testlock )
 {
    int32 samelock = SameLock(testlock,lock);

     UnLock(testlock);

     if( LOCK_SAME != samelock )
     {
         result = DevNameFromLock(lock,buffer,len,DN_FULLPATH);
     }
 }
    }

    return(result);
}
```

**Notes:**
This function is NOT task callable.

**Bugs:**
Prior to V50, a lock of NULL always literally returned "SYS:", 
it never tried to return the real volume name of the SYS volume.

**See also:** DevNameFromFH(), DevNameFromLock(), NameFromFH(), Lock(), IoErr(),
SetProcWindow().

---

### dos.library/NameFromPort

**Get the volume name of a handler by the MsgPort.
         (V53.63)**

**Synopsis:**
```c
int32 success = NameFromPort(struct MsgPort *port, STRPTR buffer, 
                      int32 buflen, int32 add_colon);
```

**Description:**
This function is similar to other (Dev)NameFromXXX() functions with
the difference being that the filesystem/handlers volume name will be
returned in the buffer, with or without a colon character appended.

This is a complementary function to DevNameFromPort() which returns the
device name associated with the port for a DOS handler/filesystem.

This routine is guaranteed not to write more than 'buflen' bytes into
the buffer.  The buffer will always be null-terminated.

This function WILL fail for filesystems / handlers that have no volume
node available, such as PAR: SER: ...   DevNameFromPort() will not.

If the buffer is not large enough to hold the entire string, 
this function will fail and IoErr() will return ERROR_LINE_TOO_LONG.
If this occurs, use a larger buffer and try again.
Recommended minimum buffer size is 258 bytes.

The buffer is guaranteed to be cleared on entry, providing a non-NULL
'buffer' is supplied and the 'buflen' is >0

Supplying a NULL port pointer returns "NIL" or "NIL:".

**Inputs:**
port      - Message port for the handler or filesystem.
buffer    - Buffer for volume name.
buflen    - Length of buffer.
add_colon - TRUE= colon character appended to buffer, FALSE= no colon.

**Result:**
success   - boolean; (zero or non-zero value)

**Notes:**
This function is NOT task callable.
This function provides no locking for the 'port' of the handler.
This function may perform a temporary read-lock on the DosList.

**See also:** DevNameFromPort(), NameFromFH(), DevNameFromFH(), NameFromLock(), 
DevNameFromLock(), Lock(), IoErr(), SetProcWindow()

---

### dos.library/NextDosEntry (V36)

**Get the next Dos List entry.**

**Synopsis:**
```c
struct DosList *newdlist = NextDosEntry(const struct DosList *dlist,
                                 uint32 flags);
```

**Description:**
Application programmers should use the new DOS_VOLUMELIST (V53.52+)
feature of AllocDosObject() rather than locking and itterating 
manually through the doslist themselves, if possible.

This function finds the next Dos List entry of the right type.  
You MUST have locked the types you're looking for 
(via AttempLockDosList() or LockDosList()).
Returns NULL if there are no more of that type in the list.

**Inputs:**
dlist    - The current device entry.
flags    - What type of entries to look for. This must be a
    combination of LDF_DEVICES, LDF_VOLUMES and LDF_ASSIGNS.
    All other flags are silently ignored.

**Result:**
newdlist - The next device entry of the right type or NULL.

**Example:**
```c
To search the doslist for a particular type, you may call this
function at the beginning of the loop, as calling NextDosEntry()
immediately after locking the list, will always begin searching
at the first node.  Be warned however, that after you have passed 
the returned doslist pointer through NextDosEntry(), subsequent 
calls to NextDosEntry() will search from the next entry in the list
from the supplied pointer.

flags = LDF_DEVICES|LDF_READ;
dl = IDOS->LockDosList(flags);

while(( dl = IDOS->NextDosEntry(dl,flags) ))
{
	found_dev_entry(dl);
}

IDOS->UnLockDosList(flags);
```

**Notes:**
From V50, a NULL 'dlist' parameter is now safe and simply returns
NULL as well as setting IoErr() to ERROR_REQUIRED_ARG_MISSING.

This function performs no locking or waiting internally.

**See also:** AddDosEntry(), RemDosEntry(), FindDosEntry(), LockDosList(),
MakeDosEntry(), FreeDosEntry()

---

### dos.library/NonBlockingModifyDosEntry

**Modify a DosList node without blocking.
                      (V51.29)**

**Synopsis:**
```c
int32 success = NonBlockingModifyDosEntry(struct DosList *dlist,
                          int32 mode, APTR arg1, APTR resv);
```

**Description:**
Modifies the DosList without blocking the caller, as is required for
handlers and filesystems.   

This function allows the caller to Add, Delete, Rename and Remove a
DosList node, signal doslist changes and cause notifications to happen,
in a way that makes it callable from handlers and filesystems that
cannot use wait locking from the handler process, as doing so could
easily cause a blocking deadlock situation.

NB:    You should NOT be in a Forbid() state before calling this
function for doslist node manipulations, as doing so will kill
any possibility of getting a second chance at obtaining a
syncronous write semaphore lock on the doslist if it happens to
be owned by another task, however, this will not stop the
function from still working, although it would be in your best
interests to avoid forcing the use of the workaround code.

Also, do NOT call AttemptLockDosList() or any other doslist
locking functions yourself, these all currently imply a Forbid(),
all needed locking will be handled here internally.

**Inputs:**
dlist  - Doslist entry to be modified, or NULL for auxilliary functions.

mode   - The function identification mode. (see;dos/dosextens.h)
      NBM_ADDDOSENTRY - Adds doslist entry.
          dlist = pointer to doslist node to add.
          arg1  = NULL.
          resv  = NULL.

      NBM_REMFREEDOSENTRY - Removes & frees doslist entry.
          dlist = pointer to doslist node to remove & free.
          arg1  = NULL.   (added 53.67)
          resv  = NULL.

      NBM_REMDOSENTRY - Removes doslist entry only.
          dlist = pointer to doslist node to remove.
          arg1  = NULL.
          resv  = NULL.

      NBM_RENAMEDOSENTRY - Rename doslist entry.
          dlist = pointer to doslist node to rename.
          arg1  = STRPTR to the new name. (without ':')
          resv  = NULL.

      NBM_CHANGESIGNAL - Cause a doslist change signal.
          dlist = NULL.
          arg1  = NULL.
          resv  = NULL.

      NBM_DISKINSERTED - Cause IECLASS_DISKINSERTED input event.
          dlist = NULL.  (added 53.73)
          arg1  = NULL.
          resv  = NULL.

      NBM_DISKREMOVED  - Cause IECLASS_DISKREMOVED input event.
          dlist = NULL.  (added 53.73)
          arg1  = NULL.
          resv  = NULL.

arg1   - Secondary parameter. (see above 'mode').

resv   - Reserved - currently unused parameter which MUST be set
  to NULL at this time, otherwise this function will fail.

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
NBM_ADDDOSENTRY and NBM_RENAMEDOSENTRY will obey the same rules for
AddDosEntry() and RenameDosEntry() with respect to node name conflicts.

NBM_REMFREEDOSENTRY and NBM_REMDOSENTRY will scan the doslist to find
the node matching the supplied 'dlist' argument, therefore if the 
node is not currently in the doslist this function will return FALSE,
however, the node will still be deleted with NBM_REMFREEDOSENTRY.

All the above functions generate one DosList change signal upon success,
this includes NBM_DISKINSERTED or NBM_DISKREMOVED signalling functions.

The NBM_CHANGESIGNAL option has been made available here to allow a
doslist change signal to be generated by the caller, for features other
than those covered above, this may be required by a filesystem or 
handler when it manually changes the validity of information in a 
DosList node (or for other disk related queery functions) where it needs
to indicate that the data should be re-read by any application that is
monitoring the doslist device states. See also; NotifyDosListChange().

All mode types are mutually exclusive.

**See also:** AddDosEntry(), RemDosEntry(), RenameDosEntry(), NotifyDosListChange().

---

### dos.library/NotifyDosListChange

**Synopsis:**
```c
int32 success = NotifyDosListChange(struct Process *process, 
                             uint32 signalnum, uint32 reserved);
```

**Description:**
NotifyDosListChange() sets up a signal specified by 'signalnum' for the
process 'process' to notify it when a change occurs to the DOS device
list that affects; volumes, devices or assigns. 
This being; adding, removing, renaming or changing any DosList node.

DosList changes signals will also be generated by dos.library when a
DOS handler or filesystem device process starts up or ends.

DosList change signals may also be generated by a given filesystem or
handler itself, for other types of events that change the validity of
information in the DosList or via other queery functions, which is used
to indicate that the data should be re-read by the application.

If you wish to discontinue a DosList notification signal, simply call
this function again with a 'signalnum' of NDLC_END and the 'process' 
parameter the same as when started.

**Inputs:**
process   -- The process to signal, or NULL for your current process.

signalnum -- Signal bit number to send to the process. 
      Signal number must be in the range of 0-31 to be valid,
      such signals are available from exec/AllocSignal() or 
      from the publicly defined signals in exec/task.h as; 
      SIGB_xxx or in dos/dos.h as;  SIGBREAKB_CTRL_xxx  
      Specifying any out of range values (except NDLC_END) will
      cause failure, with an error code returned by IoErr().

reserved  -- Reserved for future functional expansion.
      This parameter MUST always set to 0 for now.

**Result:**
success   -- boolean; (zero or non-zero), zero means failure.

**Example:**
```c
int32 main(void)
{
    uint32 signals;

    if( ! IDOS->NotifyDosListChange(NULL, SIGBREAKB_CTRL_E, 0))
    {
 IDOS->PrintFault(IDOS->IoErr(), NULL);
 return(RETURN_ERROR);
    }

    IDOS->PutStr("Notify test running, -  press [CTRL]-C to exit.\n");

    do
    {
 signals = IExec->Wait( SIGBREAKF_CTRL_E | SIGBREAKF_CTRL_C );

 if( signals & SIGBREAKF_CTRL_E )   /* Received ^E signal */
 {
     IDOS->PutStr("DosList notify signal received !!\n");
 }
    }
    while(  !  (signals & SIGBREAKF_CTRL_C ));  /* ^C exits */

    IDOS->NotifyDosListChange(NULL, NDLC_END, 0);  /* Turn it off */
    return(RETURN_OK);
}
```

**Notes:**
This function is not callable from a task.
   
DosList change signal notifications are always guaranteed to be
disabled by DOS just before the target process finally ends.

You _may_ get more than one notification signal per renaming action,
dependant upon whether the underlying filesystem calls RenameDosEntry()
or NonBlockingModifyDosEntry() or neither, to do the renaming action.
   
No arbitration is performed by this function when used on a process
other than your own.
Another process may exit at any time, it is up to you to perform 
the required arbitration.

**See also:** ProcessScan(), NotifyProcListChange(), exec/AllocSignal()
NonBlockingModifyDosEntry().

---

### dos.library/NotifyProcListChange

**Synopsis:**
```c
int32 success = NotifyProcListChange(struct Process *process, 
                             uint32 signalnum, uint32 reserved);
```

**Description:**
NotifyProcListChange() sets up a signal specified by 'signalnum' for
the process 'process' to notify it when a change occurs to the DOS 
process list, or the CLI program counter, which means one or more
processes (or any CLI commands) have either started or ended.

If you wish to discontinue a Process List notification signal,
simply call this function again with a 'signalnum' of NPLC_END and 
the 'process' parameter the same as when started.

**Inputs:**
process   -- The process to signal, or NULL for your current process.

signalnum -- Signal bit number for the signal to send to the process. 
      Signal number must be in the range of 0-31 to be valid,
      such signals are available from exec/AllocSignal() or 
      from the publicly defined signals in exec/task.h as; 
      SIGB_xxx or in dos/dos.h as;  SIGBREAKB_CTRL_xxx  
      Specifying any out of range values (except NPLC_END) will
      cause failure, with an error code returned by IoErr().

reserved  -- Reserved for future functional expansion.
      This parameter MUST always be set to 0 for now.

**Result:**
success   -- boolean; (zero or non-zero), zero means failure.

**Example:**
```c
int32 main(void)
{
    uint32 signals;

    if( ! IDOS->NotifyProcListChange(NULL, SIGBREAKB_CTRL_E, 0))
    {
 IDOS->PrintFault(IDOS->IoErr(), NULL);
 return(RETURN_ERROR);
    }

    IDOS->PutStr("Notify test running, -  press [CTRL]-C to exit.\n");

    do
    {
 signals = IExec->Wait( SIGBREAKF_CTRL_E | SIGBREAKF_CTRL_C );

 if( signals & SIGBREAKF_CTRL_E )   /* Received ^E signal */
 {
     IDOS->PutStr("Process list change signal received !!\n");
 }
    }
    while(  !  (signals & SIGBREAKF_CTRL_C ));  /* ^C exits */

    IDOS->NotifyProcListChange(NULL, NPLC_END, 0);    /* Turn it off */
    return(RETURN_OK);
}
```

**Notes:**
This function is not callable from a task.
   
Process list change signal notifications are always guaranteed to be
disabled by DOS just before the target process finally ends.

No arbitration is performed by this function when used on a process
other than your own.
Another process may exit at any time, it is up to you to perform 
the required arbitration.

**See also:** ProcessScan(), NotifyDosListChange(), exec/AllocSignal()

---

### dos.library/ObtainConsoleData

**Returns data about a console window. (53.59)**

**Synopsis:**
```c
struct ConsoleWindowData *dat = 
          ObtainConsoleData( struct TagItem *tags );

struct ConsoleWindowData *dat = 
          ObtainConsoleDataTags( uint32 Tag1, ...);
```

**Description:**
ObtainConsoleData() can be used to obtain information about a
console handler window.   This function allows for a choice of
handler identifiers to be used. 

The returned data must be released with ReleaseConsoleData().

**Inputs:**
tags -- Pointer to a tagitem array for the options listed below.

INPUT TAGS ; One mandatory tag item to enable handler identification.
      The following tags are mutually exclusive.

OCD_FileHandleInput (BPTR) -- BCPL pointer to a FileHandle.
    Identify the handler by the stream pointed to by a FileHandle.
    The opening mode does not affect identification.

OCD_MsgPortInput    (struct MsgPort *) -- Pointer to a message port.
    Identify the handler by this message port.

**Result:**
result - (struct ConsoleWindowData *) or NULL on failure.
  On failure, call IoErr() [Fault(),PrintFault()] to find
  out more information with regard to what caused failure.

**Notes:**
This function is NOT task callable.

It is mandatory to call ReleaseConsoleData() to dispose of the returned
structures memory and decrement the handlers use count.

**See also:** GetDiskInfo(), Info(), IoErr(), Fault(), PrintFault().

---

### dos.library/ObtainDirContext

**Creates a context for ExamineDir().
                (V51.104)**

**Synopsis:**
```c
APTR context = ObtainDirContext(const struct TagItem *tags);

APTR context = ObtainDirContextTags(uint32 Tag1, ...);
```

**Description:**
Creates a context in preparation for the ExamineDir() function.

This function creates a context for the filesystem object specified,
allocates resources for the filesystem requests, (which are initiated
automatically by calling the ExamineDir() function), as well as 
initialising the memory pool and other parameters specified via 
the taglist.

This context must eventually be released with ReleaseDirContext(),
it frees the entire data block memory pool all at once, as well as
releasing the other required resources.

**Inputs:**
tags - a pointer to a TagItem array;

   SOURCE TAGS ; Mandatory tag item to identify filesystem object.
       The following three tags are mutually exclusive.

EX_LockInput (BPTR) -- BCPL pointer to a Lock.
    Identify the filesystem object by this associated Lock.
    The lock must be on a directory.
    This lock is passed directly throught to the filesystem and
    will NOT otherwise be touched by DOS.

EX_FileHandleInput (BPTR) -- BCPL pointer to a FileHandle.
    Identify the parent directory from the stream pointed to by an
    open FileHandle.  DOS determins the parent directory of the
    file by calling ParentOfFH() internally. This internal lock 
    is UnLock'ed when the caller invokes ReleaseDirContext().

EX_StringNameInput (STRPTR) -- Pointer to a nul-terminated string name,
    to specify the filesystem directory required.
    This may be relative to the current directory an assignment
    or an absolute path.  DOS will internally perform a Lock() on the
    string provided, it will also Unlock() this internal lock when the
    caller invokes ReleaseDirContext().
    Failure will occur if the directory is already exclusively locked.
    Also, if the volume that is referenced by the string name, is not
    currently inserted, it will post the usual style of 
    "Please Insert Volume ..." request unless specifically prevented
    in doing so beforehand with SetProcWindow().


   OTHER TAGS ;

EX_DataFields  (uint32) -- A bitmask to indicate which items of data
    are to be filled out in your ExamineData by the filesystem.
    (Default = EXF_ALL when tag not supplied.)

    The following data items are currently available;
 EXF_TYPE       - The type field descriptor.
 EXF_SIZE       - The filesize field.
 EXF_DATE       - struct DateStamp for the object.
 EXF_NAME       - The object name.
 EXF_COMMENT    - The comment string.
 EXF_LINK       - The link target name string.
 EXF_PROTECTION - Protection bit flags.
 EXF_OWNER      - Both owner user-id and group-id fields.  
 EXF_OBJECTID   - The unique object ID field.
 EXF_REFCOUNT   - The hardlink reference count for the object.

 EXF_ALL        - All of the above. (Default)

    Combine any of the above flags by OR'ing them to form a bitmask.
    EG: If you wish to obtain the 'type', 'name' and 'date' fields,
 you would specify (EXF_TYPE | EXF_NAME | EXF_DATE) to the tag.

    NB: For maximum speed purposes, it is advisable to avoid EXF_ALL, 
 instead, specify only the items of interest to be copied.

EX_MatchString (STRPTR) -- A pointer to a pre-parsed pattern string.
    (Default = NULL) - If this field is NULL then all entries will be
    returned.   If this field is non-null then the string is passed
    to the default filter function to be used to pattern match each
    entry against the examinedata->Name field.

    This string MUST be pre-parsed by ParsePatternNoCase() before use.

    This parameter is also passed directly through to any custom hook
    function that may be specified with; EX_MatchFunc.
    If using a custom filter function, always remember to use the DOS
    caseless pattern matcher, ie; MatchPatternNoCase(). 


EX_MatchFunc (struct Hook *) -- Pointer to a Hook structure which has 
    the h_Entry function pointer set to a custom filter function that
    usually employs MatchPatternNoCase() on the required name field.
    The hook function finally decides if the entry will be returned.
    The hook is called with the following parameters; 
    (as is standard for hooks):

    int32 result = MatchFunc(struct Hook *hookptr, STRPTR match_string,
                      struct ExamineData *examinedata);

    MatchFunc() should return FALSE to stop the entry being returned,
    otherwise return any other boolean TRUTH value.


    If you DO NOT specify this tag, (or supply a NULL tag value),
    DOS will call the default filter function instead, which is
    equivalent to the following code;
    {
 int32 rc = TRUE;   /* return everything by default */

 if( match_string ) /* only filter if match_string supplied.*/
 {
     rc = IDOS->MatchPatternNoCase(match_string, exdata->Name);
 }
 return(rc);
    }
    NB: The default built-in filter function was added at version 52.17


EX_DoCurrentDir (int32;BOOLEAN) -- Set TRUE to automatically make the 
    reference to the directory being scanned, the 'current directory'
    immediately after the input source has been obtained. 
    This is generally for recursive directory scans of a sub-directory
    by using just a current directory relative examinedata->Name. 
    (Default=FALSE)

    This tag must be specified each time any input source is specified
    to ensure the current directory is set for the current input source.
    This tag is NOT persistent when reusing a context, it only sets the
    current directory and saves the old one for restoration when this
    tag is specified as TRUE.

    Specifying this tag may also be used to access the current directory
    lock to obtain a fully qualified path name for the current directory
    by using GetCurrentDir() with NameFromLock() / DevNameFromLock().

    NB: The old current directory will be restored by ReleaseDirContext(),
 or if a new input tag is specified when resetting a context,
 or on subsequent failure of this function.


EX_ResetContext (APTR) -- Pointer to a previous context obtained from
    this function, for which a change of any parameter/s are required.
    By passing in a previous context via this tag, the resources already
    allocated for the old context and ExamineData nodes will be reused,
    (if they are still on the internal lists and havn't been Remove()ed).
    All necessary filesystem context information will also be reset to
    allow a new scan to begin again.  (Default = NULL)

    Be aware that only the supplied tag items will be changed by this
    switch, all previous tag initialisations will stay in force,
    with the exception of EX_DoCurrentDir which is only done when 
    specifically asked.

    When specifying a new EX_xxx  source tag, the references to the
    previous object will be released and a new reference will be
    established for the specified source object, the old current dir
    will also be restored when this occurs, if it was previously saved
    with the EX_DoCurrentDir,TRUE tag.

	If using this tag and passing a NULL context pointer, it will be
    treated as if the tag was not supplied.

**Result:**
context - APTR;  Pointer to the DOS/FS private context block,
    or NULL on failure, call IoErr() for specific details on the error.

**Notes:**
This function employs task resource tracking, therefore the process that
called ObtainDirContext() MUST be the same process that eventually calls
ReleaseDirContext() for it to work.

**See also:** ExamineDir(), ReleaseDirContext(), ExamineObject(). dos/dos.h

---

### dos.library/Open (V30)

**Open a file for (unbuffered) input or output.**

**Synopsis:**
```c
BPTR file = Open( CONST_STRPTR name, int32 mode );
```

**Description:**
NB: Applications should not attempt to use normal filesystem access
    methods with ENV: or ENVARC:, there are dedicated environmental
    variable handling functions for these, such as; GetVar(), SetVar(),
    FindVar(), ScanVars(), DeleteVar(). (See these for details).

This function attempts to open the named file for unbuffered file i/o
and a file handle is returned if successful, otherwise ZERO on failure.

This function should be used only for unbuffered I/O from DOS V51+,
for buffered I/O, use the FOpen() function instead.
The behaviour of Open() is now different from FOpen() which performs
the same basic function, but FOpen() also allocates your desired size
of stream buffer at the same time, Open() doesn't, it also means that
using Open() for buffered calls would require a default minimum legacy
compatibility buffer be allocated and initialized upon the first access
to a buffered function, before I/O can commence.
So, from V51+, please use FOpen() if you require a buffered stream.


If the 'mode' is MODE_OLDFILE, an existing file is opened for 
reading or writing, this implies a shared lock, if the requested file
does not exist, Open() will fail.

If the 'mode' is MODE_READWRITE it opens a file with a shared lock,
but creates it if it didn't exist. 

If the 'mode' is MODE_NEWFILE, a new file is created, this implies
an exclusive lock, if the requested file already exists, it will have
the contents of the file effectively deleted and reset to a 'new' state.

Open types are documented in the <dos/dos.h> include file.

All modes above will place the internal file position pointer at the
beginning of the file.


The 'name' can be a file name, optionally prefaced by a device
name, with or without path, a simple device such as NIL:, a window
specification such as CON: or RAW: followed by window parameters,
assignments, (including multi-assignments if mode is not MODE_NEWFILE),
a virtual DOS device such as PROGDIR:, or CONSOLE: representing the
current console window which placed its message port in pr_ConsolePort,
or some other specification which can be found in the dos.library
IDOS->GetDeviceProcFlags() documentation.  

Note that as of V36, "*" is obsolete and must NOT be used anymore,
"CONSOLE:" must be used instead, support for "*" may be discontinued
at any time. You have been warned.!

If the file cannot be opened for any reason, the value returned
will be zero, and a secondary error code will be available by
calling the IoErr() function.

**Inputs:**
name - (CONST_STRPTR) pointer to a null-terminated string.
mode - (int32) MODE_OLDFILE, MODE_NEWFILE, MODE_READWRITE

**Result:**
file - (BPTR) BCPL pointer to a file handle, zero on failure.

**Notes:**
Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K absolute minimum recommended)

This function is not normally callable from tasks.
However, there is the one single exception of Open("NIL:",..) 
which is exempt from this convention due to CreateNewProc()'s 
need to open default filehandles from exec tasks calling it.

Passing NULL for the 'name' is now safe, it just returns 0,
with IoErr() set to ERROR_REQUIRED_ARG_MISSING   (V50).

When using MODE_NEWFILE on filesystem that support file hard links,
be aware that doing so with an existing file hard link name,
is equivalent to opening the target file itself in MODE_NEWFILE.
However, because that target file has hardlinks bound to it, 
the implied "delete first" behaviour of MODE_NEWFILE means that the
target file itself must not be physically "deleted" in the conventional
sense, as that would disconnect the hard file linkage.
Therefore only the content and associated data will be reset to that
of a newly created state, where it has the default attributes and a
file size of zero bytes, without affecting the hard file linkage.

The behaviour of MODE_READWRITE was changed with V36. 
Previously, it implied an exclusive lock. Now, after the change, 
it implies a shared lock.

**See also:** FOpen(), Close(), SetVar(), ChangeMode(), NameFromFH(), ParentOfFH(),
ExamineFH(), SetFileHandleAttr(), GetDeviceProcFlags().

---

### dos.library/OpenFromLock (V36)

**Opens a file you have a lock on.**

**Synopsis:**
```c
BPTR fh = OpenFromLock(BPTR lock);
```

**Description:**
Given a lock, this routine performs an open on that lock.  
If the open succeeds, the lock is (effectively) relinquished and
must not be UnLock()ed or used again.  
If the open fails, the lock is still usable.

The lock associated with the file internally is of the same access
mode as the lock you gave up - shared is similar to MODE_OLDFILE,
exclusive is similar to MODE_NEWFILE but without affecting the file
contents or meta-data.

Attempting to open a file using a directory lock will fail.

**Inputs:**
lock - Lock on the file to be opened.

**Result:**
fh   - Newly opened file handle or ZERO for failure.
On failure call IoErr() for more information.

**Bugs:**
In the original V36 autodocs, this was shown (incorrectly) as
taking a Mode parameter as well.  
The prototypes and pragmas were also wrong.

**See also:** Open(), Close(), Lock(), UnLock(), NameFromLock(), DevNameFromLock()

---

### dos.library/Output

**Identify the programs' initial output file handle.**

**Synopsis:**
```c
BPTR file = Output(VOID);
```

**Description:**
Output() is used to access the initial output stream allocated
when the program was initiated. This is stored in; Process->pr_COS.   
Never close the filehandle returned by Output().

To change the stream in an application, call SelectOutput() to install
a new stream, while saving the return value for restoration before the
application terminates.

**Result:**
file - BCPL pointer to a file handle.

**Notes:**
This function is NOT callable from a task.

**See also:** Input(), ErrorOutput(), 
SelectOutput(), SelectInput(), SelectErrorOutput()

---

### dos.library/ParentDir

**Obtain the parent dir for a directory or file lock.**

**Synopsis:**
```c
BPTR newlock = ParentDir( BPTR lock );
```

**Description:**
The argument 'lock' is associated with a given file or directory.
ParentDir() returns 'newlock' which is a SHARED_LOCK of the parent
directory of 'lock'. 

If 'lock' is for a directory, 'newlock' will return a directory lock
one directory level above.
If 'lock' is for a file, 'newlock' will returns a directory lock to
the directory level where the file is located.
 
Taking the ParentDir() of the root of the current filing system
returns a ZERO (0) lock, with no secondary error code.
Supplying a lock of ZERO will return ZERO and a secondary error code
of ERROR_REQUIRED_ARG_MISSING in IoErr().

**Inputs:**
lock    - BCPL pointer to a lock.  (ZERO safe, just returns ZERO)

**Result:**
newlock - BCPL pointer to a lock. (or ZERO for root)

**Notes:**
This function is NOT task callable.
You are responsible for unlocking the 'newlock' lock.

**See also:** Lock(), DupLock(), UnLock(), ParentOfFH(), DupLockFromFH()

---

### dos.library/ParentOfFH (V36)

**returns a lock on the parent directory of a file.**

**Synopsis:**
```c
BPTR lock = ParentOfFH( BPTR fh );
```

**Description:**
Returns a shared lock on the parent directory of the filehandle.

**Inputs:**
fh   - Filehandle you want the parent directory of.

**Result:**
lock - Lock on parent directory of the filehandle or NULL for failure.

**Notes:**
You are responsible for UnLock()'ing the newly obtained lock.

**See also:** Parent(), Lock(), UnLock() DupLockFromFH()

---

### dos.library/ParsePattern (V36)

**Create a tokenized string for MatchPattern().**

**Synopsis:**
```c
int32 IsWild = ParsePattern(CONST_STRPTR Source, STRPTR Dest, 
                     int32 DestLength);
```

**Description:**
Tokenizes a pattern, for use by MatchPattern().  Also indicates if
there are any wildcards in the pattern (i.e. whether it might match
more than one item).  Note that Dest must be at least 2 times as
large as Source plus two bytes to be (theoretically) 100% certain of no
buffer overflow.  This is because each input character can currently
expand to 2 tokens (with one exception that can expand to 3, but
only once per string).  Note: this implementation may change in
the future, so you should handle error returns in all cases, but
the size above should still be a reasonable upper bound for a buffer
allocation.

The patterns are fairly extensive, and approximate some of the ability
of Unix/grep "regular expression" patterns.  
Here are the available tokens:

?       Matches a single character.

#       Matches the following expression 0 or more times.

(ab|cd) Matches any one of the items separated by '|'.

~       Negates the following expression.  It matches all strings
 that do not match the expression (aka ~(foo) matches all
 strings that are not exactly "foo").

[abc]   Character class: matches any characters in the class.

[~bc]   Character class: matches any characters not in the class.

a-z     Character range (only within character classes).

%       Matches 0 characters always.  Useful as in "(foo|bar|%)".

*       Synonym for "#?", not available by default in 2.0+  
 Available as an option that can be turned on. (Re; DOS prefs)

'       The single quote character neutralizes the special meaning 
 of a special character.  Here are some examples:
 '#'? matches only the literal string "#?"
 '?(A|B|%)'# matches the literal strings "?#", "?A#", "?B#"

"Expression" in the above table means either a single character
(ex: "#?"), or an alternation (ex: "#(ab|cd|ef)"), or a character
class (ex: "#[a-zA-Z]").

**Inputs:**
Source     - unparsed wildcard string to search for.
Dest       - output string, gets tokenized version of input.
DestLength - length available in destination (must be at least
      twice as large as Source length + 2 bytes).

**Result:**
IsWild       1 means there were wildcards in the pattern,
      0 means there were no wildcards in the pattern,
     -1 means there was a buffer overflow or other error.
        ( Consult IoErr() for further information. )

**Notes:**
This function is not callable from a task, and will return -1
with IoErr() of ZERO.

It is generally not a good idea to use reserved pattern matching
characters in filesystem object names if you wish to pattern match,
otherwise you will need to use a single quote to neutralize each
literal reserved character in the pattern.

**Bugs:**
In V37 this call didn't always set IoErr() to something useful on an
error. Fixed in V39.

**See also:** ParsePatternNoCase(), MatchPattern(), MatchFirst(), MatchNext()

---

### dos.library/ParsePatternNoCase (V37)

**Create a tokenized string for
               MatchPatternNoCase().**

**Synopsis:**
```c
int32 IsWild = ParsePatternNoCase(CONST_STRPTR Source, STRPTR Dest,
                           int32 DestLength);
```

**Description:**
Tokenizes a pattern, for use by MatchPatternNoCase().  
Also indicates if there are any wildcards in the pattern 
(i.e. whether it might match more than one item).
Note that Dest must be at least 2 times as large as Source
plus 2 bytes.

For a description of the wildcards, see ParsePattern().

**Inputs:**
Source     - unparsed wildcard string to search for.
Dest       - output string, gets tokenized version of input.
DestLength - length available in destination (must be at least 
      twice as large as Source length + 2 bytes).

**Result:**
IsWild       1 means there were wildcards in the pattern,
      0 means there were no wildcards in the pattern,
     -1 means there was a buffer overflow or other error.

**Notes:**
This function is not callable from a task, and will return -1
with IoErr() of ZERO.

It is generally not a good idea to use reserved pattern matching
characters in filesystem object names if you wish to pattern match,
otherwise you will need to use a single quote to neutralize each
literal reserved character in the pattern.

**Bugs:**
In V37 this call didn't always set IoErr() to something useful on an
error. Fixed in V39.

In V37, it didn't properly convert character-classes ([x-y]) to
upper case.  Workaround: convert the input pattern to upper case
using ToUpper() from utility.library before calling
ParsePatternNoCase().  Fixed in V39 dos.

**See also:** ParsePattern(), MatchPatternNoCase(), MatchFirst(), MatchNext(),
utility.library/ToUpper()

---

### dos.library/PathPart (V36)

**Returns a pointer to the end of the next-to-last
     component of a path.**

**Synopsis:**
```c
STRPTR fileptr = PathPart( CONST_STRPTR path );
```

**Description:**
This function returns a pointer to the character after the 
next-to-last component of a path specification, which will normally
be the directory name separator.  If there is only one component, 
it returns a pointer to the beginning of the string.  The only real
difference between this and FilePart() is the handling of '/'.

**Inputs:**
path    - pointer to a path string.  May be relative to the current
   directory or the current disk.

**Result:**
fileptr - pointer to the end of the next-to-last component of 
the path.

**Example:**
```c
PathPart("xxx:yyy/zzz/qqq") would return a pointer to the last '/'
PathPart("xxx:yyy") would return a pointer to the first 'y').
PathPart("file")  would return a pointer to the character 'f'.
```

**Notes:**
From V50 this function is task callable.
This function will not affect IoErr().
The output of this function is typed as STRPTR even though it does not
modify the content of the supplied CONST_STRPTR 'path' itself, 
but only because the output string is usually directly used to truncate
the 'path' of its final component.

**See also:** FilePart(), AddPart(), SplitName()

---

### dos.library/Printf (V36)

**format and print string. (buffered)**

**Synopsis:**
```c
int32 count = Printf(CONST_STRPTR fmt, ...);

int32 count = VPrintf(CONST_STRPTR fmt, CONST_APTR argv);
```

**Description:**
Writes the formatted string and values to Output().  This routine 
is assumed to handle all internal buffering so that the formatting
string and resultant formatted values can be arbitrarily long.
Any secondary error code is returned in IoErr().  
This routine is buffered. 
See Notes for extended new V51 DOS format specifiers.

Note: RawDoFmt assumes 16 bit ints, so you will usually need 'l's in
your formats (ex: %ld versus %d).

**Inputs:**
fmt   - exec.library RawDoFmt() style formatting string.
argv  - Pointer to array of formatting values.

**Result:**
count - Number of bytes written or -1 (EOF) for an error.

**Example:**
```c
(1)     count = IDOS->Printf("%ld+%ld=%ld.\n", 1,2,3);

(2)     int32 array[3] = { 1,2,3 };
 count = IDOS->VPrintf("%ld+%ld=%ld.\n", &array[0]);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

From 51.59 all DOS (only) string formatting functions now accept 
two additional special DOS format specifiers;  %m and %n.
These will be replaced by the error message (%m) such as would be
obtained by the Fault() function and the error number (%n) as returned
from IoErr() that was valid at the time this function was called.
In all other respects these functions work like they always did.

EG: count = IDOS->Printf("error message = %m, error code = %n\n",0);

This new functionality may need to allocate temporary memory before
it can print the error message. However, if the error came about 
because of memory shortage then the message/value string insertion 
may not be performed at all.

Internally, this function transforms the format string to include
the respective error message/number strings; these must not contain
format specifiers themselves or the underlying RawDoFmt() function
will end up trying to fetch parameters off the argument list which
are not available. To prevent this possibility, when the error message
is being inserted, any '%..' format specifiers found in the actual
error message will be removed entirely to prevent this happening.

**Bugs:**
The prototype for Printf() currently forces you to cast the first
varargs parameter to LONG due to a deficiency in the program
that generates fds, prototypes, and amiga.lib stubs.

There is currently a minor problem when using 64 bit stack args.
The current compiler for OS4 enforces 64 bit alignment of 64 bit
arguments, but Printf assumes 32 bit alignment (VARARGS68K).
It is relatively easy to workaround by making sure 64 bit arguments
are aligned appropriately.  Carefull placement of parameters will
be sufficient. eg;   

IDOS->Printf("%lld %ld\n", 64bit_val, 32bit_val);        /* works */
IDOS->Printf("%ld %lld\n", 32bit_val, 64bit_val);        /* fails */
IDOS->Printf("%ld %s%lld\n", 32bit_val, "", 64bit_val);  /* works */
 
Therefore, always use carefull placement or pad 64 bit values with
empty 32 bit string ("") arguments to attain 64 bit alignment when
using 64 bit parameters with this function.

**See also:** VFPrintf(), RawDoFmt(), FPutC(), FOpen(), FClose(), SetFileHandleAttr()

---

### dos.library/PrintFault (V36)

**Prints the text associated for a DOS error code.**

**Synopsis:**
```c
int32 success = PrintFault(int32 code, CONST_STRPTR header);
```

**Description:**
This routine obtains the error text for the given error code.
This is similar to the Fault() function, except that the output is
written to the default (or error output) stream with buffering.
The value returned by IoErr() is set to the code number you supply.

**Inputs:**
code    - Error code.
header  - header to output before error text, (NULL for none).

**Result:**
success - boolean; (zero or non-zero), Failure/Success. 
   Result is determined by a invalid/valid 'code'.

**Notes:**
From V50, this function now calls PutErrStr() internally,
so that if a default error stream has been opened, it will use 
that in preference to the normal default output stream.

The internal formatting buffer is limited to 256 characters.
This function is NOT task callable.

**See also:** IoErr(), Fault(), SetIoErr(), Output(), ErrorOutput(), PutErrStr()

---

### dos.library/ProcessScan

**Low level routine to scan through the DOS process list.
        (V51.75)**

**Synopsis:**
```c
int32 result = ProcessScan( const struct Hook *hook, 
                     CONST_APTR userdata, uint32 reserved);
```

**Description:**
This function will scan through the list of running DOS processes
and invoke the hook function for each one, or until the scanning is
discontinued intensionally.

This function DOES NOT suspend multitasking, or inhibit the normal
running of all existing processes, so this is a very friendly way to
search through the DOS process list safely and efficiently.

It is guaranteed that the DOS process list will NOT be able to change
while inside this function, as it performs shared semaphore locking.
Adding or removing list entries require exclusive locking, such as is
done automatically by DOS when processes are started or terminate.
These events cannot complete while a shared semaphore lock is in force,
any process attempting to startup or terminate will be put to sleep
until the shared semaphore is released.  (ie; leave this function.)

NOTE; Even though the process list cannot change while inside here,
the individual DOS processes are still running normally and may change
their own data at will, so be prepared for files being opened or closed
as well as other resources changing state moments after being read.

**Inputs:**
hook     -- (const struct hook *)
     The hook function will be called for every process.
     You MUST initialise the hook struct h_Entry field to the
     function address to call before invoking this routine.

     The hook will be called as follows:
     int32 result = hook_func(struct hook *hook, APTR userdata,
                              struct Process *process)

     If your hook function returns 0, the scan will continue.

     If your hook function returns a non-zero value, this 
     indicates that the scan should be aborted (e.g. when the
     item in question has been found and the result extracted).
     This non-zero return value will also be passed on and 
     returned as the result of the ProcessScan() function. 

userdata -- (CONST_APTR)
     This parameter is passed to the hook function untouched.
     You may use it for any purpose.

reserved -- (int32)
     Reserved for future functional expansion.
     This parameter MUST always be set to 0 for now.
     If you do not set it to zero, this function will fail.

**Result:**
result   -- (int32) - boolean; (zero or non-zero), 

  -- Zero indicates that you never returned a non-zero result
     from your hook before you ran out of processes to scan.

  -- All non-zero values indicate success and will actually be
     the value that you returned from your hook function.


                          ===== 

   EXAMPLE 1
Count the number of running DOS processes without Forbid() locking.

/* This hook function will increment a variable on each call. */
STATIC int32 ASM hookfunc1( REG(a0, struct Hook *hook) UNUSED,
                     REG(a2, uint32 *counter), /* userdata */
                     REG(a1, struct Process *aprocess) UNUSED)
{
    (*counter) ++;                    /* increment counter */
    return(0);                        /* 0 = continue scan */
}
   
/* This function starts the hook calls via ProcessScan() */
uint32 Count_Running_Processes(VOID)
{
    struct Hook H;
    uint32 proc_count; /* we pass a pointer to this as 'userdata' */

    proc_count =0;                    /* set initial count to zero  */
    H.h_Entry = (APTR) hookfunc1;     /* initialise the hook struct */
    IDOS->ProcessScan(&H, &proc_count, 0); 

    IDOS->Printf("There were %lu processes running.\n", proc_count);
    return( proc_count );
}
   
                          ===== 
   
   EXAMPLE 2:
Implement a SafeSignal() style function that scans for a process by 
identifying it by the ProcessID (PID), then Signal the associated
process with the mask specified, if the process is still running.
The function will return TRUE if successfull, otherwise FALSE if the
process has already exited before you called this routine.
NB: Process Identification Numbers (PID) can never be zero.

/* This hook function will test for the same process and signal it. */
STATIC int32 ASM sighookfunc( REG(a0, struct Hook *hook ),
                       REG(a2, uint32 process_id ), /*userdata*/
                       REG(a1, struct Process *aprocess ))
{
    if( process_id == aprocess->pr_ProcessID )
    {
 IExec->Signal((APTR)aprocess,  (uint32)hook->h_Data );
 return(TRUE);       /* Done. Also stops further scanning */
    }
    return(FALSE);          /* Keep going, havn't found it yet */
}

/* This is the function that invokes the hook via ProcessScan() */
int32 SafeSignalProc( uint32 ProcessID, uint32 sigmask )
{
    struct Hook H;

    H.h_Entry = (APTR) sighookfunc;    /* init the hook()  */
    H.h_Data  = (APTR) sigmask;        /* pass the sigmask here */
    return  IDOS->ProcessScan( &H, (APTR)ProcessID, 0);
}

                          ===== 
   
   EXAMPLE 3:
Implement a method to send a signal to all child processes running
that this process has created, this could be used (as in this example)
to cause all children to exit upon request by the parent process.
This function will return the number of children actually signalled.

NB: Filesystems and handlers started by this process will also have
    the same parent process identifier, so be prepared for this.
    It is usually appropriate to add a second tier identification
    mechanism for the ones actually intended to be signalled.
    Such a mechanism could be to simply store a unique identification
    value in an unused field, such a pr_ExitData or tc_UserData,
    this would then be tested in the hook function before signalling.
      

/* This hook function will test for a child process and signal it. */
STATIC int32 ASM mysighookfunc( REG(a0, struct Hook *hook ),
                         REG(a2, uint32 parentID), /*userdata*/
                         REG(a1, struct Process *aproc ))
{
    if( parentID == aproc->pr_ParentID )
    {
 uint32 *hits = (uint32 *)hook->h_Data;
 (*hits) ++:          /* increment hit counter */
 IExec->Signal((APTR)aproc, SIGBREAKF_CTRL_C);
    }
    return(0);               /* 0 = keep going until the end */
}

/* This is the function that invokes the hook via ProcessScan() */
uint32 SignalMyChildProcsToExit( VOID )
{
    struct Hook H;
    uint32 hit_counter =0;
	struct Process *parent = (struct Process *)IExec->FindTask(NULL);

    H.h_Entry  = (APTR) mysighookfunc;    /* init the hook struct */
    H.h_Data   = (APTR) &hit_counter;     /* h_Data used for counter */
    IDOS->ProcessScan( &H, (APTR)parent->pr_ProcessID, 0);
    return(hit_counter);     /* return number of hits */
}

                          =====

**Notes:**
Exec tasks will not be found by this function, only DOS processes.
The process list is currently scanned from highest PID to lowest,
ie, the youngest processes are first, the oldest are at the end.
This function is callable by exec tasks.
Both 68K and Native callable hook constructs are shown in the examples.

**See also:** NotifyProcListChange(), NotifyDosListChange().

---

### dos.library/PutStr (V36)

**Writes a string to the default output. (buffered)**

**Synopsis:**
```c
int32 error = PutStr(CONST_STRPTR str);
```

**Description:**
This routine writes an unformatted string to the default output stream.  
No newline is appended to the string and any error is returned.
This routine is buffered.

**Inputs:**
str   - Null-terminated string to be written to default output.

**Result:**
error - boolean; (zero or non-zero), 0 for success, non-zero if any
 sort of error occured.  
 NOTE: this is opposite to most Dos function returns!

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

Calling PutStr() with a zero Output() stream is safe, it just 
returns error if this situation were to occur.

This function is now a compatibility stub that calls FPuts() as;
{
    return IDOS->FPuts(IDOS->Output(), str);
}

**See also:** FPuts(), FPutC(), FWrite(), WriteChars(), PutErrStr(), 
SetFileHandleAttr()

---

### dos.library/Read

**-- Low level routine to read data from a file. (unbuffered)**

**Synopsis:**
```c
int32 actualLength = Read( BPTR file, APTR buffer, int32 length );
```

**Description:**
Data can be copied using a combination of Read() and Write().
Read() reads bytes of information from an opened file (represented
here by the argument 'file') into the buffer given. The argument
'length' is the length of the buffer given.

The value returned is the length of the information actually read.
So, when 'actualLength' is greater than zero, the value of
'actualLength' is the the number of characters read. Usually Read
will try to fill up your buffer before returning. A value of zero
means that end-of-file has been reached. Errors are indicated by a
value of -1.

Note: this is an unbuffered routine (the request is passed directly
to the filesystem or handler.)  Buffered I/O is more efficient for
small reads and writes; see FGetC(), FRead().

**Inputs:**
file         - (BPTR)  BCPL pointer to a file handle.
buffer       - (APTR)  Pointer to buffer.
length       - (int32) 32 bit integer.

**Result:**
actualLength - (int32) 32 bit integer, -1 on error.

**Notes:**
This function is NOT callable by tasks.

**See also:** Open(), Close(), Write().

---

### dos.library/ReadArgs (V36)

**Synopsis:**
```c
struct RDArgs *result = ReadArgs(CONST_STRPTR template,
                          int32 *array, struct RDArgs *rdargs);
```

**Description:**
Parses and argument string according to a template.  Normally gets
the arguments by reading buffered IO from Input(), but also can be
made to parse a string.  MUST be matched by a call to FreeArgs().

ReadArgs() parses the commandline according to a template that is
passed to it.  This specifies the different command-line options and
their types.  A template consists of a list of options.  Options are
named in "full" names where possible (for example, "Quick" instead of
"Q").  Abbreviations can also be specified by using "abbrev=option"
(for example, "Q=Quick").

Options in the template are separated by commas.  To get the results
of ReadArgs(), you examine the array of longwords you passed to it
(one entry per option in the template).  This array should be cleared
(or initialized to your default values) before passing to ReadArgs().
Exactly what is put in a given entry by ReadArgs() depends on the 
type of option. The default is a string (a sequence of non-whitespace
characters, or delimited by quotes, which will be stripped by
ReadArgs()), in which case the entry will be a pointer.

Options can be followed by modifiers, which specify things such as
the type of the option.  Modifiers are specified by following the
option with a '/' and a single character modifier. Multiple modifiers
can be specified by using multiple '/'s.  Valid modifiers are:

/S - Switch.  This is considered a boolean variable, and will be
     set if the option name appears in the command-line.  The entry
     is the boolean (0 for not set, non-zero for set).

/K - Keyword.  This means that the option will not be filled unless
     the keyword appears.  For example if the template is "Name/K",
     then unless "Name=<string>" or "Name <string>" appears in the
     command line, Name will not be filled.

/N - Number.  This parameter is considered a decimal 32 bit integer,
     it will be converted by ReadArgs. If an invalid number is specified,
     an error will be returned.  The entry will be a pointer to the
     32 bit number (this is how you know if a number was specified).

/T - Toggle.  This parameter needs an ascii keyword, which must be one
     of "yes", "no", "on" or "off".    If the keyword is missing or 
     none of these four, it counts as an error.   
     The result produced by this parameter is the same as with /S, 
     i.e. non-zero for "yes" and "on", zero for "no" and "off".

/A - Required. This keyword must be given a value during command-line
     processing, or an error is returned.

/F - Rest of line.  If this is specified, the entire rest of the line
     is taken as the parameter for the option, even if other option
     keywords appear in it.

/M - Multiple strings.  This means the argument will take any number
     of strings, returning them as an array of strings. Any arguments
     not considered to be part of another option will be added to 
     this option.  Only one /M should be specified in a template.  
     Example:
     for a template "Dir/M,All/S" the command-line "foo bar all qwe"
     will set the boolean "all", and return an array consisting of
     "foo", "bar", and "qwe" The entry in the array will be a pointer
     to an array of string pointers, the last of which will be NULL.

     There is an interaction between /M parameters and /A parameters.
     If there are unfilled /A parameters after parsing, it will grab
     strings from the end of a previous /M parameter list to fill the
     /A's.  This is used for things like Copy ("From/A/M,To/A").

ReadArgs() returns a struct RDArgs if it succeeds.  This serves as an
"anchor" to allow FreeArgs() to free the associated memory.  You can
also pass in a struct RDArgs to control the operation of ReadArgs()
(normally you pass NULL for the parameter, and ReadArgs() allocates
one for you).  This allows providing different sources for the
arguments, providing your own string buffer space for temporary
storage, and extended help text.  See <dos/rdargs.h> for more
information on this.  Note: if you pass in a struct RDArgs, you must
still call FreeArgs() to release storage that gets attached to it,
but you are responsible for freeing the RDArgs yourself.

If you pass in a RDArgs structure, you MUST reset (clear or set)
RDA_Buffer for each new call to RDArgs.  The exact behavior if you
don't do this varies from release to release and case to case; don't
count on the behavior!

See BUGS regarding passing in strings.

**Inputs:**
template - formatting string
array    - array of longwords for results, 1 per template entry
rdargs   - optional rdargs structure for options.  AllocDosObject
    should be used for allocating them if you pass one in,
    or NULL if you want ReadArgs() to allocate its own.

**Result:**
result   - a struct RDArgs or NULL for failure.

**Bugs:**
In V36, there were a couple of minor bugs with certain argument
combinations (/M/N returned strings, /T didn't work, and /K and
/F interacted).  Also, a template with a /K before any non-switch
parameter will require the argument name to be given in order for
line to be accepted (i.e. "parm/K,xyzzy/A" would require
"xyzzy=xxxxx" in order to work - "xxxxx" would not work).  If you
need to avoid this for V36, put /K parameters after all non-switch
parameters.  These problems should be fixed for V37.

Currently, this function requires any strings passed in via CSource
to have a newline character at the end of the string.

**See also:** FindArg(), ReadLineItem(), FreeArgs(), AllocDosObject(), RunCommand()

---

### dos.library/ReadSoftLink (V36)

**Read the target string for a filesystem soft link.( Use the 64 bit ExamineData API functions from V52+ )**

**Synopsis:**
```c
int32 length = ReadSoftLink( struct MsgPort *port, BPTR lock,
           CONST_STRPTR path, STRPTR buffer, uint32 bufsize);
```

**Description:**
Returns the target object string descriptor for a soft link.
This function is primarily used by dos.library in resolving soft-links
in functions that accept string descriptors, such as Lock(), Open()...

This function is no longer required to be called by applications when
using the new ExamineData API functions, as the same link target string
can now be automatically returned in the examinedata->Link field.

ReadSoftLink() takes a relative lock + name pair and a handler port,
usually from a failed attempt to use them to access an object with
dospackets or vector-port calls, and asks the filesystem to return
the softlink target string.
The dos.library then starts the resolution process again with what
was returned in the output buffer, this occurs for as many soft-links
as are within the specified path, up to a maximum of 15 softlinks.

Soft links are resolved at access time by a combination of the
filesystem returning ERROR_IS_SOFT_LINK to DOS, and DOS calling
ReadSoftLink() to obtain the target descriptor for the soft link.

This function is NOT for resolving hardlinks, to do that with the old
functions, simply Lock() the link name and use [Dev]NameFromLock() to
obtain a fully qualified path to the target object.
When using the new 64 bit ExamineData API functions, the hardlink target
can also be automatically returned in the examinedata->Link field too.

**Inputs:**
port    - msgport of the filesystem.
lock    - relative lock for the link path on the filesystem.
path    - link path string that caused the ERROR_IS_SOFT_LINK.
buffer  - pointer to buffer for the targets path string.
bufsize - size of buffer.

**Result:**
length  - strlen() of the buffer, or a negative number which
   indicates an error:

-1 means that an I/O error occured which can be
   queried with the IoErr() function.

-2 means that the buffer you submitted is too small
   to hold the resolved link name; try again with a
   larger buffer.

**Bugs:**
In V36, soft-links didn't work in the ROM filesystem.  
This was fixed for V37.

Older documentation suggested that the ReadSoftLink() function had
a boolean return code. This was never the case. This function
always returned the string length of the target string buffer, 
or a negative number indicating that an error had occured.

From 53.122 supplying a NULL 'port' will no longer fail, providing
a non-zero relative 'lock' argument is supplied to obtain a port.

This function used to be called ReadLink().

**See also:** MakeLink(), Open(), Lock(), GetDeviceProc()

---

### dos.library/Relabel (V36)

**Change the volume name of a mounted device.**

**Synopsis:**
```c
int32 success = Relabel(CONST_STRPTR devicename, CONST_STRPTR newname);
```

**Description:**
Changes the volumename of a mounted device, if the  operation is
supported by the filesystem.

**Inputs:**
devicename - Full name of device to rename its volume (with ':')
newname    - New volume name to apply to the device (without ':')

**Result:**
success    - boolean; (zero or non-zero) Failure/Success indicator.

**Notes:**
This function is NOT task callable.

**See also:** GetDeviceProcFlags().

---

### dos.library/ReleaseConsoleData

**Releases the data obtained by ObtainConsoleData()
               (V53.59)**

**Synopsis:**
```c
VOID ReleaseConsoleData(struct ConsoleWindowData *data);
```

**Description:**
Releases internal locks, decrements handler usecount, deallocates the
associated memory block for the struct ConsoleWindowData.

**Inputs:**
data - (struct ConsoleWindowData *) a pointer to a data block previously
 obtained from ObtainConsoleData[Tags]().

**Notes:**
Passing in a NULL pointer is harmless.
IoErr() is unaffected by this function.

**See also:** ObtainConsoleData()

---

### dos.library/ReleaseDirContext

**Releases a context and data for ExamineDir(),
              obtained by ObtainDirContext(). (V51.104)**

**Synopsis:**
```c
VOID ReleaseDirContext(APTR context);
```

**Description:**
Releases internal locks, deallocates the memory pool with all of the
ExamineData blocks, frees any (DOS/FS) private data, and frees the 
context structure previously allocated by ObtainDirContext().

**Inputs:**
context - (APTR) a pointer to an ExamineDir() context. (or NULL)

**Notes:**
Passing in a NULL context pointer is harmless.
IoErr() is always unaffected by this function.

This function employs task resource tracking, therefore the process that
called ObtainDirContext() must be the same process that eventually calls
ReleaseDirContext() for it to work correctly.

**See also:** ObtainDirContext(), ExamineDir(), ExamineObject()

---

### dos.library/RemAssignList (V36)

**Remove an entry from a multi-assign.**

**Synopsis:**
```c
int32 success = RemAssignList(CONST_STRPTR name,BPTR lock);
```

**Description:**
Removes an entry from a multi-directory assign.
The entry removed is the first one for the object which 'lock' refers,
the entry in the list is removed and unlocked.
The 'lock' argument supplied to this function remains untouched.

Before V54, this function only worked on assignments of type DLT_LOCK,
from V54+ DLT_NONBINDING multi-assigns are also handled here.
To remove DLT_LATE assigns, refer to the function AssignLate().

**Inputs:**
name - Name of assignment to remove entry from, (without trailing ':')
lock - Lock associated with the entry to be removed from the list.

**Result:**
success - Success/failure indicator.

**Notes:**
From V50, 'name' is tested for NULL and now causes IoErr() to
return ERROR_REQUIRED_ARG_MISSING if this occurs.

**Bugs:**
In V36 through V39.23 dos, it would fail to remove the first lock
in the assign.  Fixed in V39.24 dos (after the V39.106 kickstart)
which means that the bug is present in all Kickstart versions 2.0
through 3.0 (inclusively).

**See also:** AssignLock(), AssignPath(), AssignLate(), AssignAdd[ToList](),
Lock(), DupLock(), UnLock()

---

### dos.library/RemDosEntry (V36)

**Removes a Dos List entry from its list.**

**Synopsis:**
```c
int32 success = RemDosEntry(struct DosList *dlist);
```

**Description:**
This removes an entry from the Dos Device list.  
The memory associated with the entry is NOT freed.
(See also; FreeDosEntry())

NB: you must have locked the Dos List with the appropriate flags
(via AttemptLockDosList() or LockDosList()) before calling this
routine.  Handler/filesystem implementors should see the
AddDosEntry() caveats about locking and use a similar workaround
to avoid deadlocks, or just call NonBlockingModifyDosEntry() instead.

**Inputs:**
dlist   - Device list entry to be removed.

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.
   This function will return failure if the entry to be 
   removed is not currently a member of the DosList.

**Notes:**
From V50, supplying a NULL 'dlist' will result in failure,
also, IoErr() will be set to ERROR_REQUIRED_ARG_MISSING.

**See also:** AddDosEntry(), FindDosEntry(), NextDosEntry(), LockDosList(),
MakeDosEntry(), FreeDosEntry(), NonBlockingModifyDosEntry().

---

### dos.library/RemSegment (V36)

**Synopsis:**
```c
int32 success = RemSegment(struct DosResidentSeg *drs);
```

**Description:**
Removes a resident segment from the Dos resident segment list,
unloads it, and does any other cleanup required.  
Will only succeed if the seg_UC (usecount) == 0.  (* see BUGS)

   V51 LOCKING 
From V51+ this function always internally WRITE semaphore locks the
DosResidentSeg list by calling ObtainSemaphore() / ReleaseSemaphore().
Do NOT attempt to employ a READ (shared) semaphore lock on the list
at the same time as you call this function, otherwise it will deadlock.

Obtain the semaphore pointer from the public semaphore list by calling;
    drsem = IExec->FindSemaphore("DosResident");
The semaphore pointer may be cached for the duration of the task.   
(Also see; FindSegment() documentation for more info.)

For all WRITE operations, call;  ObtainSemaphore(drsem);
The above call must be matched with a ReleaseSemaphore();

**Inputs:**
drs - pointer to the DosResidentSeg to be removed.

**Result:**
success - boolean; (zero or non-zero), 0 for failure.

**Bugs:**
Due to backward compatibility needs, some software used a Seg_UC
value of one to indicate zero usage, rather than zero.
For now, a Seg_UC of both 0 and 1 will succeed here, but this is not
guaranteed to remain so, only depend on 0 being successful in future.
Therefore, if you actually intend 1 to cause failure here,
you should check seg_UC yourself before calling this function.

**See also:** FindSegment(), AddSegment()

---

### dos.library/Rename

**Rename a file, directory or symbolic link.**

**Synopsis:**
```c
int32 success = Rename( CONST_STRPTR oldName, CONST_STRPTR newName );
```

**Description:**
Rename() attempts to rename the object specified as 'oldName' with the
name 'newName'.   If the object 'newName' already exists and it's not
the same object as 'oldName', Rename() will fail and return the
secondary error code  ERROR_OBJECT_EXISTS.
Both 'oldName' and the 'newName' can contain a directory specification,
in this case, the object will be moved from one directory to another.

It is perfectly legal to specify the same object for the 'oldName' and
'newName' strings, but with different case, by default, AmigaDOS is
always case insensitive, so an operation to change case must succeed.
EG:  IDOS->Rename("sys:foo","sys:FoO");

Symbolic links may also be renamed by supporting filesystems.
Besides MakeLink() and Delete(), this function is the only other
function that can directly affect symbolic links, all other operations
are performed on the links target object instead.

**Inputs:**
oldName - (CONST_STRPTR) pointer to a null-terminated string.
newName - (CONST_STRPTR) pointer to a null-terminated string.

**Result:**
success - boolean; (zero or non-zero)

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

**Notes:**
Renaming a directory with a trailing '/' in the name string, will fail.

It is not possible to Rename() an object from one volume to another.
It is not possible to Rename() a directory into a child of itself.

Before V50 there was a limit of 255 chars for the '..name' parameters.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1024 minimum recommended)

This function is NOT callable from tasks.

**See also:** Relabel(), GetDeviceProcFlags().

---

### dos.library/RenameDosEntry

**Renames a DosList node. (V51.13)**

**Synopsis:**
```c
int32 success = RenameDosEntry(struct DosList *dlist, 
                        CONST_STRPTR newname);
```

**Description:**
Renames a device, volume or assign node.  
This function may fail if the name conflicts with any existing entry.
If renaming fails, the old name will still be valid.

Note that the dos list does NOT have to be locked by a normal
application to call this function, as it is done internally for you.

The 'dlist' argument node also does not have to actually be in the
doslist when you call this function, it will still be renamed as long
as the conflict test allows it, it will compare it with all existing
nodes already on the doslist (except for itself).
 
An important note concerning calling this from within a handler:-
The function; NonBlockingModifyDosEntry() is provided for handlers to
avoid locking deadlocks, otherwise, in order to avoid deadlocks when
using this function, your handler must either be multi-threaded,
or it must attempt to lock the list before calling this function.
The code would look something like this:

if(IDOS->AttemptLockDosList(LDF_ALL|LDF_WRITE))
{
	rc = IDOS->RenameDosEntry(...);
	IDOS->UnLockDosList(LDF_ALL|LDF_WRITE);
}

See the LockDosList() documentation for information on this subject.
If AttemptLockDosList() fails (i.e. it's locked already), check for
messages at your filesystem port (don't wait!) and try the
AttemptLockDosList() again, however, the better option would be to
use the new dedicated V51 function;  NonBlockingModifyDosEntry().

**Inputs:**
dlist   - DosList node to be renamed.
newname - Nul-terminated string pointer to the new name. (without ':')

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
This function will definitely fail if a node is to be renamed with
a newname that exceeds 255 bytes in length, has a length of zero,
if there is insufficient memory for the newname buffer, or the node
conflicts with an existing entry using the canonical rules,
see AddDosEntry() for more details.

**See also:** RemDosEntry(), FindDosEntry(), NextDosEntry(), LockDosList(),
MakeDosEntry(), FreeDosEntry(), AttemptLockDosList(),
NonBlockingModifyDosEntry().

---

### dos.library/ReplyPkt (V36)

**Low level function to reply to a dospacket.**

**Synopsis:**
```c
int32 sent = ReplyPkt(struct DosPacket *packet, int32 result1,
                  int32 result2);
```

**Description:**
This returns a packet to the process which sent it to you.  
In addition, puts your pr_MsgPort address in dp_Port, so using 
ReplyPkt() again will send the message back to you.  
(This is used in "ping-ponging" packets between two processes).
It puts result1 and result2 into the dp_Res1 and dp_Res2 fields
of the packet on each send.

**Inputs:**
packet  - packet to reply, assumed to be set up correctly.
result1 - primary result.
result2 - secondary result.   ( for IoErr() )

**Result:**
sent    - boolean; (zero or non-zero) non-zero if packet was sent.

**Notes:**
This function is currently NOT callable from a task.

Until version 50, this function was declared as VOID,
but in fact it always returned BOOLEAN success, if the packet was 
actually sent it would return a TRUTH value, otherwise zero. 

This function calls SendPkt() internally to send the dospacket.
   NULL 'packet' argument is safe, does nothing.

**See also:** DoPkt(), SendPkt(), WaitPkt(), IoErr()

---

### dos.library/ResolvePath

**Internal DOS library path resolver.  (V53.137)**

**Synopsis:**
```c
int32 success = ResolvePath( struct MsgPort *filesystem_port,
                      CONST_STRPTR input_path_string,
                      BPTR   input_path_rel_lock,
 
                      STRPTR output_object_buffer,
                      uint32 output_object_buffer_size,

                      BPTR * output_object_dir_ptr,

                      uint32 * softlink_count_ptr );
```

**Description:**
This function resolves a DOS path to the final component name and its
associated directory lock.
Application programmers should rarely if ever need this function,
it is primarily used internally by dos.library for vector-port based
filesystems, and dospacket calls with paths longer than 255 bytes.

This function handles all legal path permutations as well as 
convolutions like; ":devs/printers///libs/charsets"

**Inputs:**
filesystem_port       -- Filesystem handler message port for the path.
input_path_string     -- DOS device and/or path string to resolve.
input_path_rel_lock   -- The relative base lock for the path string.

output_object_buffer  -- Buffer for the final object name, (or NULL).
output_object_buffer_size -- Size of object buffer, Use 256, (or 0).

output_object_dir_ptr -- Pointer to a BPTR sized area for storing the
                  output object relative directory lock, 
                  this pointer must never be NULL.
                  You are required to unlock the returned lock.

softlink_count_ptr    -- Pointer to a uint32 sized area to hold the
                  softlink resolution count, this pointer may be
                  NULL if this information is not needed.

**Result:**
success -- Boolean; Success / Failure indicator, FALSE on error.
             On error, call IoErr() to find out why it failed.

**Example:**
```c
This basic example resolves 'thepath' to a lock on the path part, 
with the object named 'multiview' in the object buffer. 

CONST TEXT thepath[] = "sys:utilities/multiview";
TEXT       object[256];
BPTR       object_dir =0;
uint32     softlinks =0;
struct DevProc *dp;

if(( dp = IDOS->GetDeviceProc(thepath, NULL) ))
{
    int32 success = IDOS->ResolvePath(dp->dvp_Port,
                               thepath, dp->dvp_Lock,
                               object, sizeof(object), 
                               &object_dir, &softlinks);
    if( success )
    {
 TEXT  dirname[1024];

 if( object_dir )  /* can be zero for root dir */
 {
    IDOS->NameFromLock(object_dir, dirname, sizeof(dirname));
		   IDOS->UnLock(object_dir);
		}
 else  /* root dir spec, just get volume name: */
 {
    IDOS->NameFromPort(dp->dvp_Port, dirname, sizeof(dirname),1);
 }

 IDOS->Printf("Object is '%s' in Dir '%s'\nSoftlinks = %lu\n\n",
               object, dirname, softlinks);
    }
    else
    {
 IDOS->Printf("Unable to resolve path, error code %n; [%m]\n",0);
    }

    IDOS->FreeDeviceProc(dp);
}

                        ==============
```

**Notes:**
This function is primarily used by dos.library in conjunction with the
IDOS->GetDeviceProc() function, to resolve DOS paths for API functions
that require a string input descriptor.

The 'filesystem_port', identifies the filesystem handler for the volume
and the 'input_path_rel_lock' identifies the relative directory part
for the specified 'input_path_string', both of these should be obtained
from the struct DevProc returned from IDOS->GetDeviceProc() or the 
IDOS->GetDeviceProcFlags() function to correctly handle resolution of
any assignments, or virtual DOS device references such as PROGDIR:
or CURRDIR: or future features.   The 'input_path_rel_lock' may also
be zero for root relative paths strings.

The 'input_path_string' supplied to this function should be the same
string as supplied to the IDOS->GetDeviceProc[Flags]() function.
If a colon ':' is specified within the 'input_path_string', all of
the bytes up to and including the colon will be skipped over by this
function, only GetDeviceProc[Flags]() uses that part of the string to
identify the handler or to resolve assignments, etc...

The 'output_object_directory_ptr' is a pointer to a BPTR sized storage
area for holding the objects relative directory lock, this pointer must
never be NULL otherwise this function will fail.
This function can never return success if this lock is not valid.
You must also unlock this lock after you are finished with it.
Note that it is possible for this to be ZERO for the root directory.

The 'softlink_count_ptr' is a pointer to a 32 bit variable to hold the
softlink resolution count within a given path, the pointer may be NULL
if the value is not required. If it is used, you are also required to
initialise the initial value to 0, as each softlink found within the
path will only increment the current value.

The 'output_object_buffer' and size should be a size of 256 bytes,
because 255 bytes + 0 terminator is currently the maximum size of
the name of any individual filesystem object.
From V54.24+, this pointer and size may be zero, if this information
is not required, valid parameters are required before that version. 

This function is NOT task callable.

                        ==============

**See also:** FreeDeviceProc(), GetDeviceProcFlags(), Lock(), UnLock().

---

### dos.library/RunCommand (V36)

**Runs a program using the current process.**

**Synopsis:**
```c
int32 rc = RunCommand(BPTR seglist, uint32 stacksize, 
                      CONST_STRPTR argptr, uint32 arglen);
```

**Description:**
Runs a command syncronously on your current process.

**Inputs:**
seglist   - (BPTR) Seglist of command to run.
     From V50 this must be a C language program seglist, 
     BCPL programs are no longer supported and will end up in
     the internal_BCPL_DeadEnd() function if you try to run one.

stacksize - (uint32) The absolute minimum stacksize in bytes you wish
     to allocate for the program being started.(0 for default).

argptr    - (STRPTR) Pointer to argument command string.
     A null-terminated string, it can be a nul-string
     (ie; an empty string ""),  but it must never be NULL here.

arglen    - (int32) The length of 'argptr' string.
     V50+: use -1 for normal nul-terminated C strings.
     Do not use this feature for software that needs to also run
     on earlier DOS versions, instead use; strlen(argptr).

**Result:**
rc        - (int32) Return code from the program that was run.
     Normally, this would be:-   (see dos.h)
         RETURN_OK     /* 0  = No problems, success. */
         RETURN_WARN   /* 5  = A warning only.       */
         RETURN_ERROR  /* 10 = Something wrong.      */
         RETURN_FAIL   /* 20 = Severe failure        */

     Or, -1 to indicate an error from RunCommand() itself.

Returns -1 if the stack couldn't be allocated, or if a zero seglist is
supplied, or if this function is called from a task, or other future,
yet undefined error conditions occur.  Consult IoErr() for details.

RunCommand() sets up the value returned by GetArgStr() to your supplied
'argptr' while the command is running, it then restores it on exit.  
RunCommand also takes care of setting up the current input filehandle
in such a way that ReadArgs() etc.. can be used in the program you are
starting, it restores the state of the Input() stream before returning.
NOTE: the setting of the argument string in the input filehandle
was added in V37.


   V50+ NOTES
If an Input() stream of zero is supplied, the argument string in 
the input filehandle feature will not be available to the command.

Also, for ReadArgs() and other parsers to work properly,
the argument string needs to have a newline character ('\n') on the
end.  So, to make sure this always occurs now, the 'argptr' string is 
copied to a buffer managed by RunCommand and a newline is appended 
if one is not already present.  This private buffer is for the input
streams use only, for compatibility reasons, your original 'argptr'
string is passed on to the program that is being run, without any
changes to it whatsoever, hence GetArgStr() will still return the
original 'argptr' string.

You may also use -1 for the 'arglen' parameter now, providing you 
pass in a normal nul-terminated argument c-string,  this will cause
RunCommand to automatically do; strlen(argptr) for you.
For software that must run on earlier dos.library versions, do not use
the -1 feature, use;  strlen(argptr) instead.

The stacksize for the code to be run is determined by the largest of
any of the following factors;
    1) The 'stacksize' parameter value supplied to this function.
    2) An embedded segment stack size cookie "$STACK;"
    3) The current process' pr_StackSize value upon entry.
    4) The current process' (optional) CLI struct; cli_DefaultStack.
    5) The DOS Prefs minimum process stack size value.
The largest of any of the above factors will be used to create the 
final stack size for the code being run.  This final value will be 
inserted into the pr_StackSize field and the (optional) cli structure
field; cli_DefaultStack, also, this stack size will also be reflected
by the task structure fields;  tc_SPUpper - tc_SPLower and also the
process structure field; pr_StackSize.
See also; FindSegmentStackSize() (called by this function internally).

The process structure fields that are modified by this function are
always restored upon exit from the command code, with the exception
of the (optional) cli_DefaultStack value, that may be modified by the
command intensionally,  EG; the "stack" shell command.
If the cli_DefaultStack was changed from the entry value, restoration
is not performed on this optional field.

Additionally, the following fields are always restored as per entry;
    pr_WindowPtr, pr_Arguments, pr_Task->tc_Node.ln_Name.
    pr_FinalData, pr_FinalCode. (V51.77)

The field; pr_CurrentSeg will be the same as the RunCommand() 'seglist'
argument only for the duration that the code is running, upon exit,
pr_CurrentSeg will be restored to its previous state for this process.
See also; GetProcSegList() for access to the various DOS seglists.

Programs started via RunCommand(), which also implies CreateNewProc(),
CreateProc(), Execute() and System() will be started through the common
code for this function with the following parameters supplied to the
command, depending on the executable type.  (See; dos/startup.h)

1)  Emulated 68K programs will have their entry() point called as;
      int32 returncode= entry(STRPTR args, int32 length, APTR execbase);
        D0                   A0           D0        A6

2)  Native PPC programs will have their _start() function called as;
      int32 returncode= _start(STRPTR args,int32 length, APTR execbase);

The parameters are:

    arguments -- (STRPTR) Pointer to a NUL-terminated string which
          may be NULL depending on how the process was started,
          for example; NP_Arguments was not specified in a call
          to CreateNewProc().     See also; GetArgStr()

    length    -- (int32) Length of the argument string, or 0 if no
          arguments are provided.

    execbase  -- (struct ExecBase *) Pointer to exec.library base.

   V50 NOTES
For V50, the structure of starting programs has been considerably
reworked, in that Internal_RunCommand() is now the unified function
for launching all DOS processes.

One reason for this is that the obsolete BCPL environment dictated
multiple ways of starting different styles of DOS processes,
resulting in different default register values and inconsistent
initialisations between the various methods.
From V50, all code starts via the Internal_RunCommand() to consolidate
compatibility and provide support for all new executable formats.

The DOS function calling order is as follows for all V50+ processes;

RunCommand()---------------------------------> Internal_RunCommand()
CreateProc()--------> CreateNewProc()--------> Internal_RunCommand()
System()------------> CreateNewProc()--------> Internal_RunCommand()
Execute()-----------> CreateNewProc()--------> Internal_RunCommand()

Shell programs also start via two of these entry points,
(a) For syncronous processes, RunCommand() is used directly.
(b) For asyncronous processes, (ie: "RUN") System() is used.

**Notes:**
From V50 onwards, user commands are intensionally prevented from
returning -1, this value is now for the exclusive use of RunCommand()
to indicate an internal failure to run the application for some reason,
this value is not for user code to return as a returncode.

This quirk was exploited right up to V40 for library modules and 
fonts,datatypes,etc..  that may have been run as an executable.
Now, if a command returns -1, the value will be changed by RunCommand()
to the value RETURN_FAIL with IoErr() set to ERROR_NOT_EXECUTABLE
(providing IoErr() is not already set to a non-zero value).

**See also:** CreateNewProc(), SystemTagList(), Execute(), GetArgStr(),
SetProgramName(), ReadArgs(), SelectInput(), SelectOutput(),
AllocSegList(), LoadSeg(), UnLoadSeg().

---

### dos.library/SameDevice (V37)

**Are two locks on partitions of the same device?**

**Synopsis:**
```c
int32 same = SameDevice(BPTR lock1, BPTR lock2);
```

**Description:**
SameDevice() returns whether two locks refer to partitions that
are on the same physical device (if it can figure it out).  This
may be useful in writing copy routines to take advantage of
asynchronous multi-device copies.

Entry existed in V36 and always returned 0.

**Inputs:**
lock1,lock2 -- (BPTR) filesystem locks.

**Result:**
same -- (int32) Success/Failure indicator; FALSE means "no match".

**Notes:**
This function may temporarily lock the DosList.

**Bugs:**
Until V51.28 passing a NULL lock for either parameter would cause
an illegal memory access, it would also leave the DosList locked in
(LDF_READ|LDF_ALL).

**See also:** LockDosList()

---

### dos.library/SameFH

**Returns whether two filehandles are on the same file.(V53.71)**

**Synopsis:**
```c
int32 value = SameFH(BPTR fh1, BPTR fh2);
```

**Description:**
Compares two open filehandles. 
Returns FH_SAME if they are on the same file,
Returns FH_SAME_VOLUME if on different objects but on the same volume,
Returns FH_DIFFERENT if they are on different volumes.

**Inputs:**
fh1   -- (BPTR) 1st filehandle for comparison
fh2   -- (BPTR) 2nd filehandle for comparison

**Result:**
value -- (int32) FH_SAME, FH_SAME_VOLUME, or FH_DIFFERENT

**Notes:**
Check for ZERO filehandles before calling this function because the
DOS.Library checks the parameters before calling the filesystem and
if one of the arguments is ZERO,  FH_DIFFERENT will always be returned.

Comparing two "NIL:" streams will return FH_SAME_VOLUME.

**See also:** <dos/dos.h>

---

### dos.library/SameLock (V36)

**Returns whether two locks are on the same object.**

**Synopsis:**
```c
int32 value = SameLock(BPTR lock1, BPTR lock2);
```

**Description:**
Compares two locks. 
Returns LOCK_SAME if they are on the same object,
Returns LOCK_SAME_VOLUME if on different objects but on the same volume,
Returns LOCK_DIFFERENT if they are on different volumes.

**Inputs:**
lock1 -- (BPTR) 1st lock for comparison
lock2 -- (BPTR) 2nd lock for comparison

**Result:**
value -- (int32) LOCK_SAME, LOCK_SAME_VOLUME, or LOCK_DIFFERENT

**Notes:**
Check for ZERO locks before calling this function because the
DOS.Library checks the locks before calling the filesystem and
if one of the locks is NULL,  LOCK_DIFFERENT will always be returned.

In V36, it would return  LOCK_SAME_VOLUME for different volumes on 
the same handler.  Also, LOCK_SAME_VOLUME was LOCK_SAME_HANDLER 
(now an obsolete define, see <dos/dos.h>).

**See also:** <dos/dos.h>

---

### dos.library/ScanVars

**Scan through global and/or local Vars.  (V50.64)**

**Synopsis:**
```c
int32 found = ScanVars(const struct Hook *hook, uint32 flags, 
                         CONST_APTR extradata);
```

**Description:**
This function can scan through the entire ENV: tree or walk the
local process variables list, (or both), depending on the 'flags'.

Each variable encountered that conforms to the 'flags' specification,
the hook function will be invoked.

**Inputs:**
extradata -- This parameter is passed to the hook function untouched.
      It is also used as a STRPTR for an additional control
      string when the V53 flag GVF_SCAN_STARTDIR is specified.

flags     -- Same as used by GetVar(), LV_xxx / GVF_xxx (see dos/var.h)
      (for both var types, local vars will be scanned first)

      Not specifying GVF_BINARY_VAR will cause the sv_Var to
      be treated as text and will be terminated at the first
      '\n' or '\r' character.

      New flags that are specific to ScanVars():
         GVF_SCAN_ENVARC will cause scanning of ENVARC:
             instead of ENV: when specified. (v50)
 
         GVF_SCAN_LEVEL prevents scanner from recursing
             into sub-directories, therefore returning a scan
             of only the one level of variables. (v53)

         GVF_SCAN_STARTDIR causes only the directory name
             which is specified with a c-string in 'extradata'
             to be the beginning of the virtual directory scan.
             An error will occur if the directory does not exist.

             Any path specified here will always be taken to be
             ENV: or ENVARC: root directory relative.
             This may be used in conjunction with the other flags
             for control of recursion and root device location.

             All characters before a ":" will be ignored here.
             EG:  "this_is_ignored:THIS/IS/USED"

             This flags was introduced in v53.61

 
hook      -- Pointer to a hook, which will be invoked for every var.
      You are only required to initialise only the hook struct
      h_Entry field to point to the function you wish called.
      The other fields of the Hook struct are not use here.

      The hook function will be invoked as follows:

      result = hook_function(hook,extradata,message)
      D0                      A0   A2       A1

    The message will look like this; note that its contents are 
    read-only, while inside the hook function:

 struct ScanVarsMsg
 {
     uint32 sv_SVMSize;
     uint32 sv_Flags;
     STRPTR sv_GDir;
     STRPTR sv_Name;
     STRPTR sv_Var;
     uint32 sv_VarLen;
     APTR   sv_DosPrivate;
 };

    The message structure members serve the following functions:

 sv_SVMSize
      The size of this data structure; it may grow in the
      future, so make sure that you always find the structure
      members you expect, especially if accessing anything past
      the sv_VarLen member as this was the last public member
      of the very first version of this structure.

 sv_Flags
      The flags parameter specified in the call to ScanVars().

 sv_GDir
      The read-only directory path for this Global variable,
      this will currently begin with either "ENV:" or "ENVARC:".
      For Local vars, this will point to a nul-string; "\0".

 sv_Name
      A read only pointer to the name of the variable.

 sv_Var
      A read only pointer to the contents of the variable.

      A GLOBAL var may be truncated if you did not specify
      GVF_BINARY_VAR in your flags, because this flags stops
      the data being terminated at the first \n or \r character.

 sv_VarLen
      The size of this variable, in bytes.
      If a GLOBAL var, this is the actual bytes read.

 sv_DosPrivate
      This is for private use by dos.library.

    If your hook function returns a 0, the search will continue.

    If your hook function returns a non-zero value, this indicates
    that the search should be aborted (e.g. when the object in 
    question has been found).  This return value will be passed on
    and returned as the result of the ScanVars() function.

**Result:**
found -- boolean; (zero or non-zero), A value of 0 indicates that the
  object/s in question could not be found or some other sort 
  of error occured.
  On error, use IoErr() to find out what type of error occurred.

      -- All other values indicate success and will actually be the 
  value that you returned from your hook function.

**Notes:**
This function is NOT task callable.

**See also:** GetVar(), SetVar(), DeleteVar(), FindVar(), <dos/var.h>

---

### dos.library/SelectInput (V36)

**Select a filehandle as the default input stream.**

**Synopsis:**
```c
BPTR old_fh = SelectInput(BPTR fh);
```

**Description:**
Set the current input as the default input for the process.
This changes the value returned by Input().  
old_fh should be closed or saved as needed.

**Inputs:**
fh     - Newly default input handle

**Result:**
old_fh - Previous default input filehandle

**Notes:**
This function is NOT callable from a task.

Normally all processes are started with a default set of file handles
for the Input(), Output() and ErrorOutput() streams.
However, it may be required that some of these be exchanged from within
the application or elsewhere to alternate file handles.

To do this, call SelectErrorOutput(), SelectInput() or SelectOutput()
to change the appropriate stream, while preserving the 'old_fh' value
for restoration before the application terminates, so that DOS can
access its originally provided stream/s when ending the process.

**See also:** Input(), Output(), SelectOutput(), ErrorOutput(), SelectErrorOutput()

---

### dos.library/SelectOutput (V36)

**Select a filehandle as the default output stream.**

**Synopsis:**
```c
BPTR old_fh = SelectOutput(BPTR fh);
```

**Description:**
Set the current output as the default output for the process.
This changes the value returned by Output().  old_fh should
be closed or saved as needed.

**Inputs:**
fh     - Newly desired output handle

**Result:**
old_fh - Previous current output handle

**Notes:**
This function is NOT callable from a task.

Normally all processes are started with a default set of file handles
for the Input(), Output() and ErrorOutput() streams.
However, it may be required that some of these be exchanged from within
the application or elsewhere to alternate file handles.

To do this, call SelectErrorOutput(), SelectInput() or SelectOutput()
to change the appropriate stream, while preserving the 'old_fh' value
for restoration before the application terminates, so that DOS can
access its originally provided stream/s when ending the process.

**See also:** Input(), Output(), ErrorOutput(), SelectInput(), SelectErrorOutput()

---

### dos.library/SendPkt (V36)

**Low level function to send a dospacket to a handler.**

**Synopsis:**
```c
VOID SendPkt(struct DosPacket *packet, struct MsgPort *sendport,
           struct MsgPort *replyport);
```

**Description:**
Sends a dospacket to a handler and does not wait.  All fields in the
dospacket must be initialized before calling this routine.

This function effectively performs the following actions;
    
    message = packet->dp_Link;          /* Get message pointer     */
    message->mn_ReplyPort = replyport;  /* Init the msg replyport  */
    packet->dp_Port       = replyport;  /* Init the pkt replyport  */
    IExec->PutMsg(sendport, message);   /* Send the packet.        */

If you wish to use this function in conjunction with WaitPkt()
via a PROCESS, you should use a pointer to your pr_MsgPort for
the replyport.  ( See; GetProcMsgPort() )

From a (V50+) TASK, you will need to supply your own replyport
to both this function as well as WaitPkt().

**Inputs:**
packet    - DosPacket to send, must be initialized and have a message.
sendport  - MsgPort of handler process to send to.
replyport - MsgPort for the dospacket to come back to.

**Notes:**
(V50) This function is now callable from a task.
Also note that none of the arguments are checked for validity.

**See also:** DoPkt(), WaitPkt(), AllocDosObject(), FreeDosObject(), GetProcMsgPort()

---

### dos.library/Serialize

**Serializes the current filesystem volume. (V53.60)**

**Synopsis:**
```c
int32 success = Serialize(CONST_STRPTR filesystem);
```

**Description:**
This function is not normally accessed by application software.

This function will tell a file system to serialize the current volume.
This is typically done by updating the creation date in the disk data
and by also updating the current datestamp for the DOS volume node.

DOS uses the volume node datestamp as a second tier check against
volume name collisions in the doslist.

**Inputs:**
filesystem - Name of DEVICE to Serialize (with ':')

**Result:**
success    - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
This function will fail if the name supplied is not the device name
of the filesystem, volume and assign names will be rejected.

This function is NOT task callable.

**See also:** SerializePort(), Inhibit(), Format(), DevNameFromLock(), 
DevNameFromFH(), DevNameFromPort(), GetDeviceProcFlags().

---

### dos.library/SerializePort

**Serializes the current filesystem volume. (V53.88)**

**Synopsis:**
```c
int32 success = SerializePort(struct MsgPort *filesystem_port);
```

**Description:**
This function is not normally accessed by application software.

This function will tell a file system to serialize the current volume.
This is typically done by updating the creation date in the disk data
and by also updating the current datestamp for the volume node.

DOS uses the volume node datestamp as a second tier check against
volume name collisions in the doslist.

**Inputs:**
filesystem_port - Message port of filesystem to serialize.

**Result:**
success - boolean; (zero or non-zero), Failure/Success indicator.

**Notes:**
This function is NOT task callable.
This function provides no locking for the 'port' of the handler.

**See also:** Serialize(), InhibitPort(), FormatPort(), DevNameFromLock(), 
DevNameFromFH(), DevNameFromPort().

---

### dos.library/SetArgStr (V36)

**Sets the argument string for the current process.**

**Synopsis:**
```c
STRPTR oldptr = SetArgStr(CONST_STRPTR ptr);
```

**Description:**
Sets the argument string for the current process.

**Inputs:**
ptr    - pointer to new argument string.

**Result:**
oldptr - the previous argument string.  (or NULL)

**Notes:**
From V50, the buffer that holds a copy of the original argument string
is now allocated by DOS and added to the task memory list and is freed
automatically on process termination.
This process structure pointer is no longer used to free resources.
This function simply places the 'ptr' value supplied into the current
process structre field; pr_Arguments, therefore any new string supplied
must remain persistent for the life of the current process.

This function is NOT callable from a task.

**Bugs:**
Before V50, this ptr MUST be reset to its original value before
the program exits, as pr_Arguments was passed to FreeVec() by the
DOS process cleanup code.

**See also:** GetArgStr(), RunCommand()

---

### dos.library/SetCliCurrentDirName (V36)

**Sets the directory name in the attached
                 CLI structure of this process.**

**Synopsis:**
```c
int32 success = SetCliCurrentDirName(CONST_STRPTR name);
```

**Description:**
Sets the name for the current dir in the cli structure.  
If the name is too long to fit, FALSE is returned, and the old value is
left intact.  It is advised that you inform the user of this condition.
This routine is safe to call even if there is no CLI structure,
however, it will do nothing at all but return FALSE.

V50 Note: If the supplied name is longer than the buffer,
   all path components will be stripped off and only the 
   directory name will be copied to the cli structure
   if it fits, otherwise FALSE is returned.

**Inputs:**
name    - Name of directory to be set.

**Result:**
success - boolean; (zero or non-zero).

**Notes:**
This function is NOT task callable.

**Bugs:**
From v50, the value set here is not entirely usefull,
due to the length limits of the CLI structure field cli_CurrentDirName.

This function cannot be fixed (yet) due to software dependencies,
this may change in a later DOS version.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**See also:** GetCliCurrentDirName().

---

### dos.library/SetCliProgramName (V36)

**Sets the name of the CLI program being run,
              in the attached CLI structure.**

**Synopsis:**
```c
int32 success = SetCliProgramName(CONST_STRPTR name);
```

**Description:**
Sets the name for the program in the cli structure.  
If the name is too long to fit, FALSE is returned, and the old value is
left intact. It is advised that you inform the user of this condition.
This routine is safe to call even if there is no CLI structure,
however, it will do nothing but return FALSE.

**Inputs:**
name    - Name of program to use.

**Result:**
success - boolean; (zero or non-zero value)

**Notes:**
This function is NOT task callable.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**Bugs:**
Prior to V50 this function would truncate the name to fit the 
available buffer, however, this would render the contents useless.
Now, if the buffer is insufficient, any path will be stripped off.
Failure will only be returned if the file part is still too-long.

**See also:** GetCliProgramName()

---

### dos.library/SetCliPrompt (V36)

**Sets the prompt string in the CLI structure.**

**Synopsis:**
```c
int32 success = SetCliPrompt(CONST_STRPTR name);
```

**Description:**
Sets the text for the prompt in the cli structure cli->cli_Prompt.
If the name is too long to fit, FALSE is returned, and the old 
value is left intact.  
It is advised that you inform the user of this condition.
This routine is safe to call even if there is no CLI structure,
however, it will do nothing but return FALSE.

**Inputs:**
name    - Name of prompt to be set.

**Result:**
success - boolean; (zero or non-zero)

**Notes:**
This function is NOT task callable.

This function has had a name change in V53, include dos/obsolete.h
for the compatibility macros when compiling older source code.

**See also:** GetCliPrompt()

---

### dos.library/SetComment

**Changes a comment string on a filesystem object.**

**Synopsis:**
```c
int32 success = SetComment( CONST_STRPTR name, CONST_STRPTR comment );
```

**Description:**
SetComment() sets a comment on a filesystem object. 
The comment is a pointer to a null-terminated string.

Note that not all filesystems will support comments (for example, NFS
usually will not), or the size of comment supported may vary,
but it can not exceed 255 bytes.

**Inputs:**
name    - (CONST_STRPTR) pointer to a null-terminated name string.
comment - (CONST_STRPTR) pointer to a null-terminated comment string.

**Result:**
success - (int32) boolean; (zero or non-zero)

If this function fails for any reason, the value returned will be zero,
with a secondary error code available by calling IoErr().

**Notes:**
Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

**See also:** ExamineObject(), ExamineDir(), SetProtection(), GetDeviceProcFlags().

---

### dos.library/SetConsolePort (V36)

**Sets the default console for the process.**

**Synopsis:**
```c
struct MsgPort *oldport = SetConsolePort(struct MsgPort *port);
```

**Description:**
Sets the default console tasks port (pr_ConsolePort) for the
current process.

The value set here determins the handler used for Open("CONSOLE:",..)

**Inputs:**
port - The pr_MsgPort of the default console handler for the process.

**Result:**
oldport - The previous ConsoleTask value.

**Notes:**
This function is NOT callable from a task.
This function used to be called SetConsoleTask.

**See also:** GetConsolePort(), Open()

---

### dos.library/SetCurrentDir

**Make a directory lock the current directory.**

**Synopsis:**
```c
BPTR oldLock = SetCurrentDir( BPTR lock );
```

**Description:**
SetCurrentDir() causes a directory associated with a lock to be made
the current directory. The old current directory lock is returned.
This function simply sets the value of thisprocess->pr_CurrentDir and
returns the previous value before the new value is written.

Any call that has to Open() or Lock() files (etc) requires that the
current directory be a valid lock, or zero for the 'default' volume.

Note well that using a value of zero here will generally represent the
root directory of the filesystem that you booted from, which may very
likely not be the same volume you actually want.  You should explicitly
set up the default volume handler if you intend to also use zero locks,
SetFileSysPort() sets up the default root volume for zero locks.

This lock is the same one that will be used by referencing paths
relative to "CURRDIR:".

**Inputs:**
lock    - BCPL pointer to a lock.

**Result:**
oldLock - BCPL pointer to a lock.

**Notes:**
You should be very, very carefull to preserve the current directory
your program was started with and to restore it before it exits.
Do not return with a different 'current directory' set, and do
not return with a different lock referring to the same directory
as the one you were started with. Always exit with exactly the
same lock on the current directory your program was started with.

This function is NOT callable from a task.
This function used to be called CurrentDir() before 53.151

**See also:** GetCurrentDir(), Lock(), UnLock(), Open(), DupLock()

---

### dos.library/SetDate (V36)

**Sets the modification date for a file or directory.**

**Synopsis:**
```c
int32 success = SetDate(CONST_STRPTR name, 
                 const struct DateStamp *date);
```

**Description:**
Sets the file date for a file or directory.

**Inputs:**
name    - (CONST_STRPTR) Name of object.
date    - (const struct DateStamp *) New modification date.

**Result:**
success - (int32) boolean; (zero or non-zero)

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

**Notes:**
Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

This function used to be called SetFileDate() even though it worked
on directories as well, it was renamed for consistency.

**See also:** DateStamp(), ExamineObject(), ExamineDir(), GetDeviceProcFlags().

---

### dos.library/SetFileHandleAttr

**Change attributes of a buffered FileHandle.
              (V51.49)**

**Synopsis:**
```c
int32 success = SetFileHandleAttr( BPTR fh, 
                            const struct TagItem *taglist);

int32 success = SetFileHandleAttrTags( BPTR fh, ... );
```

**Description:**
This function will allow you to change various attributes within
a buffered filehandle, such as replacing the buffer, the buffer size,
buffering modes or semaphore locking modes introduced in V51.45, etc..

This function replaces the deprecated V39 SetVBuf() function due to
excessive convolution and lack of expandability.

NOTE:  You MUST generally call this function, only before any I/O has 
begun for the supplied filehandle. ie, Immediately after opening.
Any exceptions to this rule will be documented below.

**Inputs:**
FH_BufferSize  (uint32) -- New size of the buffer for the FileHandle.  
        The allocation and freeing is done automatically unless
        you also wish to supply your own FH_UserBuffer buffer.
        Specifying a size >0 but less than the default minimum
        will be bumped up to the default minimum size.

FH_UserBuffer  (uint8 *) -- Pointer to a longword aligned user buffer
        that will be used instead of an internally allocated one,
        Any user buffer specified with this tag will not be freed
        by either further calls to this function, nor will it be
        freed on Close().

        NOTE:       You MUST also state the size of your user
                    buffer with the above FH_BufferSize tag,
                    not doing so will fail.  
                    Additionally, if you supply a NULL pointer
                    or a buffer that is not longword aligned, 
                    it will also fail.

FH_BufferMode  (int32)  -- BUF_LINE,BUF_FULL or BUF_NONE (dos/stdio.h)
        BUF_LINE -- Flush the buffer when a newline/cr character
                    is written to it or when the buffer is full.
                    (This is the interactive default)

        BUF_FULL -- Flush only when the buffer has been filled.

        BUF_NONE -- Perform no buffering at all.

FH_Locking     (int32; Boolean) -- DOSTRUE or DOSFALSE.
        DOSTRUE  -- Enable automatic task semaphore locked I/O.
                    This allows multiple tasks to safely access
                    the same filehandle concurrently. 
                    (From V51.45+ this is the default setting.)

        FALSE    -- Disable task semaphore locking for all
                    buffered I/O with this filehandle. 
   
                    WARNING:
                    Disabling semaphore locking for a filehandle
                    that can be accessed by more than just one
                    process concurrently, will probably crash 
                    the machine or cause an unprecedented level
                    of disaster that is usually system fatal.

                    However, as long as you understand the 
                    ramifications and take precautions against
                    sharing the filehandle with other processes, 
                    this option can positively influence single
                    character I/O speed with FGetC()/FPutC().
                    It will have little effect on anything else.

FH_EndStream   (int32; Boolean) -- DOSTRUE or FALSE.
        DOSTRUE  -- Make this buffered stream to report EOF(-1)
                    to all callers attempting to do any more I/O.
                    This causes anyone to think that end of file
                    has been reached, which usually aborts any
                    further operations.
                    This is how "EndCli" works on shell streams.
                    [ This option may be invoked at any time. ]

        FALSE    -- Restore the default behaviour of the stream,
                    the stream will have had its buffer flushed 
                    and seek position restored to the beginning.
                    [ This option may be invoked at any time. ]

**Result:**
success - boolean; (zero or non-zero), 0 on failure of any option.

**Notes:**
On error, and if multiple options tags are supplied, further operations
past the point of error will be skipped,  however, operations that were
successfull up to that point will have been successfully performed.
  
Passing a zero 'fh' or NULL 'taglist' is safe, it will simply return 
FALSE with IoErr() set to;  ERROR_REQUIRED_ARG_MISSING.

**See also:** FOpen(), FClose(), FRead(), FWrite(), FOpenFromLock()

---

### dos.library/SetFileSysPort (V36)

**Sets the current filesystem for the process.**

**Synopsis:**
```c
struct MsgPort *oldport = SetFileSysPort(const struct MsgPort *port);
```

**Description:**
Sets the current filesystem message port (pr_FileSystemPort) for the
current process. This is the filesystem for ZERO locks and operations
concerning the current volume when there is no current directory lock.
By default, this is initially set to the file system you booted from.

**Inputs:**
port - The pr_MsgPort of the current filesystem for the process.

**Result:**
oldport - The previous value.

**Notes:**
This function is NOT callable from a task.
This function used to be called SetFileSysTask.

**See also:** GetFileSysPort(), SetCurrentDir(), Open(), Lock(), ParentDir()

---

### dos.library/SetIoErr (V36)

**Sets the value returned by IoErr().**

**Synopsis:**
```c
int32 oldcode = SetIoErr(int32 code);
```

**Description:**
This routine sets up the secondary result (pr_Result2) return code
that is returned by the IoErr() function.

Most DOS functions call this to set the secondary error code value,
these may also be invoked by other operating system functions,
therefore do not expect this value to persist across any OS calls.

**Inputs:**
code    - Code value to be returned by a call to IoErr().

**Result:**
oldcode - The previous error code that IoErr() would have returned.

**Notes:**
This function will do nothing but return 0, if called from a task.

**See also:** IoErr(), Fault(), PrintFault()

---

### dos.library/SetMode (V36)

**Synopsis:**
```c
int32 success = SetMode(BPTR filehandle, int32 char_mode);
```

**Description:**
SetMode() sends an ACTION_SINGLE_CHARACTER_MODE packet to the
handler in question, normally for changing a CON: handler to
raw mode or vice-versa.  
For CON:, use TRUE to go to RAW: mode, FALSE for CON: mode.

What this function does is change the console's mode of operation
between single character (char_mode == TRUE) and line buffered
(char_mode == FALSE).

**Inputs:**
filehandle - filehandle
char_mode  - The new mode required. (TRUE=char or FALSE=line).

**Result:**
success - boolean; (zero or non-zero), zero means failure.

**Notes:**
SetMode(0,...) is now safe, it just returns FALSE,
with IoErr() set to ERROR_REQUIRED_ARGUMENT_MISSING.
 
Previous versions of dos.lirary did NOT check for fh==0
and would cause an illegal memory access, if attempted.

---

### dos.library/SetOwnerInfo

**Set owner / group information for an object. (V52.18)**

**Synopsis:**
```c
int32 success = SetOwnerInfo( const struct TagItem *tags );

int32 success = SetOwnerInfoTags( uint32 Tag1, ...);
```

**Description:**
This function replaces the deprecated V39 SetOwner() function.
It allows the caller to set the owner information for the file
or directory on a filesystem, as well as provide a method of
setting the two process structure owner fields; pr_UID and pr_GID.

A filesystem takes no interest in the values other than storing 
(and returning) them, for the respective filesystem objects,
these are primarily for use by networking software (clients and hosts),
in conjunction with the ExamineData EXDF_OTR_xxx and EXDF_GRP_xxx 
protection bits.

**Inputs:**
SOURCE TAGS:  (Mutually Exclusive)
OI_StringNameInput (STRPTR) -- Pointer to a string name identifying a 
    filesystem object to set the UID and/or GID values via the
    OI_OwnerXXX tags described below.
    This tag is mutually exclusive with OI_ProcessInput.

OI_ProcessInput (struct Process *) -- Pointer to a process structure, 
    (or NULL for this process), to set the process structure fields
    pr_UID and/or pr_GID to the UID / GID values via the OI_OwnerXXX
    tags described below.
    This tag is mutually exclusive with OI_StringNameInput.

OTHER TAGS:
OI_OwnerUID (uint32) -- Owner UID value.
    Set the value for the objects UID field. 
    By not specifying this tag, the UID field will remain unchanged.

OI_OwnerGID (uint32) -- Group GID value.
    Set the value for the objects GID field. 
    By not specifying this tag, the GID field will remain unchanged.

There are no default values for these tags, you must specify at least
one of the source tags when calling this function (mutually exclusive),
and at least one of OI_OwnerUID or OI_OwnerGID tags, or it will fail.
The dos.library will check for this before calling the filesystem
for filesystem object calls, as well as testing for a NULL 'tags' arg.

**Result:**
success - (int32) boolean; (zero or non-zero, zero on failure) 

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

This function also provides automatic fallback code using SetOwner()
(ACTION_SET_OWNER) if the respective filesystem does not support this
new packet or vector, fallback function semantics will apply.

**Notes:**
Before V50 there was a limit of 255 chars for a filesystem path/name.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

**Bugs:**
Until DOS version 54.20, this function would leave a lock on an objects
parent directory, if setting both OI_OwnerUID and OI_OwnerGID in the
same function call. As a workaround, use two calls instead.

**See also:** GetOwnerInfo(), SetProtection(), ExamineObject(), ExamineDir(),
GetDeviceProcFlags(),  <dos/dos.h>

---

### dos.library/SetProgramDir (V36)

**Sets the directory returned by GetProgramDir.**

**Synopsis:**
```c
BPTR oldlock = SetProgramDir(BPTR lock);
```

**Description:**
Sets a shared lock on the directory the program was loaded from.
This can be used for a program to find data files, etc, that are
stored with the program, or to find the program file itself.  
This lock can be accessed from GetProgramDir() or by using paths
relative to "PROGDIR:".

ZERO is also a valid input, but will cause accesses to "PROGDIR:"
to fail with no fallback.

**Inputs:**
lock - A lock on the directory the current program was loaded from.

**Result:**
oldlock - The previous Program Dir.

**Notes:**
This function is NOT callable from a task.
You must NOT UnLock() this directory lock.

You should be very, very carefull to preserve the program directory
your program was started with and to restore it before it exits.
Do not return with a different 'program directory' set, and do
not return with a different lock referring to the same directory
as the one you were started with. Always exit with exactly the
same lock on the program directory your program was started with.

**See also:** GetProgramDir(), Open()

---

### dos.library/SetProtection

**Set protection for a file or directory**

**Synopsis:**
```c
int32 success = SetProtection( CONST_STRPTR name, uint32 mask );
```

**Description:**
SetProtection() sets the protection attributes for a file or directory.
See <dos/dos.h> for a listing of protection bits.

The (A)rchive bit will be cleared by the filesystem whenever the 
file is changed, this should include at least the immediate parent
directory for the modified object. Backup utilities will generally set
this bit after backing up each object.

For files, the (R)ead, (W)rite and (D)elete bits control filesystem
functionality for their respective operations.

For directories, the (D)elete bit is the ONLY bit that is defined to
control the functionality of a filesystems, all other bits should not
affect filesystem operations in any way.

The Shell will look at the (E)xecutable, (P)ure and (H)old bits,
if the (E)xecutable bit is set, it will prevent a file being executed.
The (P)ure bit indicates this executable file is reentrant, which means
it is built in such a way so that one copy of a loaded executable may
be run by multiple proceses concurrently, this mainly requires that the
executable be built with no writable global data section.
The (H)old bit indicates to the shell that this executable should not
be unloaded after the initial loading, but instead held in the shells
DosResident executable list for later use, this feature requires that
the executable is also of a 'pure' construction.  

Other bits will be defined in the <dos/dos.h> include files.
Rather than referring to bits by number you should use the 
definitions in <dos/dos.h>.

The following is the currently defined behaviour with the bit set:

Bit 7, EXDF_HOLD       /* Hold a program in the DosResident list.   */
Bit 6, EXDF_SCRIPT     /* File is a script (execute) batch file.    */
Bit 5, EXDF_PURE       /* Program is reentrant and re-executable.   */
Bit 4, EXDF_ARCHIVE    /* File has not been modified.               */
Bit 3, EXDF_NO_READ    /* File is NOT readable, (Ignored by old FS) */
Bit 2, EXDF_NO_WRITE   /* File is NOT writable, (Ignored by old FS) */
Bit 1, EXDF_NO_EXECUTE /* File is NOT executable, (Used by shell)   */
Bit 0, EXDF_NO_DELETE  /* Object is NOT deleteable.                 */

Note that when bits 0,1,2,3 are set, this represent a negated function,
the names of these definitions reflect this.
The rest of the bits are set for the desired feature to be active.
This means that:   IDOS->SetProtection(name, 0)  sets the object as
being; (R)eadable, (W)ritable, (E)xecutable and (D)eleteable only.

**Inputs:**
name    - (CONST_STRPTR) pointer to a null-terminated string.
mask    - (uint32) the protection mask required.

**Result:**
success - (int32) boolean; (zero or non-zero) 

If this function fails for any reason, the value returned will be zero,
and a secondary error code will be available by calling IoErr().

**Notes:**
Before V50 there was a limit of 255 chars for the 'name' parameter.
This no longer applies, so ensure your buffer is large enough to
handle the longest possible paths and do check for overflows.
(1K minimum recommended)

This function is NOT callable from tasks.

**See also:** SetComment(), Examine(), ExNext(), GetDeviceProcFlags(),  <dos/dos.h>

---

### dos.library/SetVar (V36)

**Sets a local or global environment variable.**

**Synopsis:**
```c
int32 success = SetVar( CONST_STRPTR name, CONST_STRPTR buffer, 
                 int32 size, uint32 control );
```

**Description:**
Sets a local or environment variable.  It is advised to only use
text strings inside global variables, but this is not mandatory.

Variable names follow filesystem syntax and semantics.
Any and all directory paths in a variable name will be created
automatically if they do not already exist.

All variable names are always relative to the root of the device.
The current directory has no effect on this function.
If any "DEVICE:" part is specified in the variable name,
only the portion after the colon ':' will actually be used.

**Inputs:**
name    - Pointer to a variables name.  
   This may also include a directory path specification.

buffer  - A user allocated area which contains the data that is to be
   associated with this variable, may also be an empty string.

size    - Length of the data contained in buffer to store (in bytes). 
   A size of zero is permitted to create an empty var.
   Use -1 if buffer points to a null-terminated c-string,
   this will internally perform a;  size = strlen(buffer).

control - Type descriptor byte with semantic flags in the upper bits.
   The low 8 bits describes the type of local var, while the
   upper bits form a bitmask to control the behavior of this 
   routine.
  
   For local vars, specify the type of local var to set with
   either LV_VAR or LV_ALIAS. 
   ( LV_VAR is the default if not specified. )  
   Then, 'OR' that with any required GVF_xxx flags.
   Currently the following bitmask flags include:

   GVF_LOCAL_ONLY  - Set a local (to your process) variable.

   GVF_GLOBAL_ONLY - Set a global environment variable.
       The default is to set a local environment variable if
       neither of these are specified.  (Mutually exclusive)

   GVF_SAVE_VAR    - Save a copy of a global variable to ENVARC:

   GVF_BINARY_VAR  - Treat global variable as a binary variable.
       Local vars/alias' are always text, this flag has no 
       effect on them even if specified.
       ( Try to avoid using binary vars whenever possible. )

   See also: dos/var.h

**Result:**
success - boolean; (zero or non-zero), If non-zero, the variable was
   sucessfully set, FALSE indicates failure.

**Notes:**
This function is NOT task callable.
If LV_VAR is not specified, global vars cannot be created.

**Bugs:**
Until V51.23, passing 'size=-1' failed to guarantee a nul-terminated
string var. As a workaround, use;  1+strlen(buffer) for 'size'.

In version 53.48 it was not possible to create an empty local variable,
it is possible again and is now documented to be legal to do so.

**See also:** GetVar(), DeleteVar(), FindVar(), <dos/var.h>

---

### dos.library/SplitName (V36)

**Splits out a component of a pathname into a buffer.**

**Synopsis:**
```c
int32 newpos = SplitName(CONST_STRPTR name, int32 separator,
                  STRPTR buf, int32 oldpos, int32 bufsize);
```

**Description:**
This routine splits out the next piece of a name from a given file
name.  Each piece is copied into the buffer, truncating at bufsize-1
characters.  The new position is then returned so that it may be
passed in to the next call to splitname.  If the separator is not
found within 'bufsize' characters, then bufsize-1 characters plus a
null byte will be put into the buffer, and the position of the next
separator will be returned.

If a separator cannot be found, -1 is returned (but the characters
from the old position to the end of the string are copied into the
buffer, up to a maximum of bufsize-1 characters).  Both strings are
null-terminated.

This function is mainly intended to support handlers and traversing
path specifications for directory relative accessing.

**Inputs:**
name      - Name / path being parsed.
separator - Single separator character byte (0-255) to split by.
buf       - Buffer to hold separated name.
oldpos    - Starting position in the path.
bufsize   - Size of buf in bytes (including null termination).

**Result:**
newpos    - New position for next call to splitname. -1 for last one.

**Notes:**
From V50, this function is task callable.

A return value of -1 will also occur if 'bufsize' argument is <1,
or for an 'oldpos' of <0, or a NULL 'buf' is supplied.

'buf' is guaranteed to be cleared initially if the above fail 
condition does not cause a premature exit.

**Bugs:**
In V36 and V37, path portions greater than or equal to 'bufsize' 
caused the last character of the portion to be lost when followed
by a separator.  Fixed for V39 dos.  For V36 and V37, the suggested
work-around is to call SplitName() with a buffer one byte larger
than normal.
(for example, 32 bytes), and then set buf[bufsize-2] to '0' 
(for example, buf[30] = '\0';).

**See also:** FilePart(), PathPart(), AddPart()

---

### dos.library/StartNotify (V36)

**Starts notification on a file or directory.**

**Synopsis:**
```c
int32 success = StartNotify(struct NotifyRequest *notifystructure);
```

**Description:**
Posts a notification request.  Do not modify the notify structure 
while it is active.  You will be notified when the file or directory
changes.  For files, you will be notified after the file is closed.
Not all filesystems will support this: applications should NOT 
require it. In particular, most network filesystems won't support it.

However, from dos.library 52.33 local file and directory notification
is available via an internal dos.library handler,  by default this
handler is only used for your notify request, if the underlying 
filesystem does not support notifications, or the filesystem rejected
your request for some reason,  or if you specify the control flag
NRF_DOS_NOTIFY_ONLY, (via the AllocDosObject tag; ADO_DOSMethodOnly),
which forces dos.library to use the built-in file/dir notification
function, regardless of whether the underlying filesystem supports
it or not.

**Inputs:**
notifystructure - A filled-in NotifyRequest structure allocated by
    AllocDosObject() using DOS_NOTIFYREQUEST flag, (from V51 onwards).
    If you allocated the NotifyRequest structure all by yourself,
    see below for a description of how to fill it in properly.

**Result:**
success - boolean; (zero or non-zero), Failure/Success of request.

**Notes:**
Three notification methods are supported:
    1) A signal is sent to a task/process
    2) A message is sent to a message port
    3) A hook function is called

The three are mutually exclusive and you should be careful not to
enable more than one by mistake. It is recommended that you use
AllocDosObject() to allocate a properly initialized NotifyRequest,
but if you need to fill one in manually, here is what counts:

    NotifyRequest->nr_Name
 Must point to the name of the file or directory to be
 monitored, and for which changes should produce notifications.
 This name is evaluated exactly once when you submit the
 NotifyRequest.  The name is interpreted relative to the
 current directory of the caller at the time StartNotify()
 is invoked. 
 NB: It is recommended that the name string be persistent
     until EndNotify() is called on the NotifyRequest.

    NotifyRequest->nr_UserData
 This is free for your own use, very much like the
 Task->tc_UserData field or Hook->h_Data.

    NotifyRequest->nr_Flags
 A combination of several flags which control how the
 notification should be processed. The following
 flags select the notification method and are mutually
 exclusive:

     NRF_SEND_MESSAGE
         Send a message to the MsgPort pointed to by
         NotifyRequest->nr_stuff.nr_Msg.nr_Port;

     NRF_SEND_SIGNAL
         Send a signal to the Task pointed to by
         NotifyRequest->nr_stuff.nr_Signal.nr_Task;
         the signal itself comes from the bit number
         NotifyRequest->nr_stuff.nr_Signal.nr_SignalNum,
         which must be in the range 0..31. This will be
         translated into a function call like this:

         IExec->Signal(nr->nr_stuff.nr_Signal.nr_Task,
                 (1UL<<nr->nr_stuff.nr_Signal.nr_SignalNum);

     NRF_CALL_HOOK
         Invoke the Hook pointed to by
         NotifyRequest->nr_stuff.nr_CallHook.nr_Hook;
         Note that this feature may not be supported by
         all file systems (V50). 
         This notification method was intended to be used with
         directories and may not work with files when serviced
         by some filesystems, however, both are supported only if
         dos.library V52.28+ is used to handle the notification.
         
         NB: Your hook structure MUST remain persistent for
             the life of the notify request.

         The Hook function is invoked with the following
         parameters:

         result = func(hook,reserved,msg);
           D0           A0     A2     A1

         int32 func(struct Hook *hook,APTR reserved,
                    struct NotifyHookMsg *msg);

         The 'reserved' parameter is currently used for special
         features within the operating system when employing 
         dos.library handled notifications, otherwise set to 0.

         Your hook function should return 0 if successful.

         The NotifyHookMsg looks like this:

             struct NotifyHookMsg
             {
                 int32  nhm_Size;
                 int32  nhm_Action;
                 STRPTR nhm_Name;
             };

         The individual fields have the following meanings:

             nhm_Size
                 The size of this data structure (in bytes);
                 this must be >= 12; more fields may be added
                 in the future and by looking at nhm_Size you
                 can tell if the fields you are expecting are
                 actually present.

             nhm_Name
                 The name of the object.

             nhm_Action
                 This can be one of the following values:

                     NHM_ACTION_INITIAL
                         This is the initial notification
                         produced, as requested by setting
                         the NRF_NOTIFY_INITIAL flag in
                         NotifyRequest->nr_Flags (see below).

                     NHM_ACTION_ADD
                         An entry by the name given in the
                         nhm_Name field was added to the
                         directory being monitored.

                     NHM_ACTION_CHANGE
                         The directory entry, whose name is
                         given in the nhm_Name field, has
                         changed. For example, its size or
                         modification time may have changed.

                     NHM_ACTION_DELETE
                         An entry by the name given in the
                         nhm_Name field was removed from the
                         directory being monitoried.

                 Note that further actions may be supported in
                 the future. As a rule, if your hook cannot
                 support or 'understand' the action given,
                 then it should ignore it.

                 Only three different actions represent
                 changes to directory entries. For example,
                 creating a new file will produce a message
                 of type NHM_ACTION_ADD. Deleting a file will
                    produce a message of type NHM_ACTION_DELETE.
                 Changes to entries involving modification time,
                 comments, size, protection bits and owner info
                 will trigger NHM_ACTION_CHANGE messages.
                 You will need to find out for yourself what
                 exactly has changed.

 Note that if you select none of these methods, or pick a
 method which the file system does not support, you will
 never receive any notification at all even though the
 file system may not rejected your request at the time you
 posted it with StartNotify().

 From V52 this is being revised throughout various components,
 as well as when allocating requests through AllocDosObject(),
 so that unsupported methods or incorrect parameters will 
 be evaluated where possible and should now cause failure.

 The following flags control how and when the notification
 should be sent:

     NRF_WAIT_REPLY
         This flag has meaning only for the
         NRF_SEND_MESSAGE notification method. If in effect,
         no further notification messages will be sent for
         a NotifyRequest unless the last NotifyMessage has
         been replied first.

     NRF_NOTIFY_INITIAL
         Regardless of whether anything has changed, this
         flag causes a notification to be sent directly
         after the StartNotify() call succeeded.

     NRF_DOS_NOTIFY_ONLY
         From V52.33+ DOS, specifying this flag prevents the
         use of filesystem supported notification even if it
         is available, it forces usage of the dos.libraries
         own notification handler instead.
         This flag can be specified if you wish to use a method
         that is unsupported by the respective filesystem,
         but which does not actually cause failure from the
         filesystem, this would normally prevent the DOS
         notification function taking over automatically.
         Or, you may use this flag if you simply wish to have
         consistent behaviour regardless of what filesystem a
         user has installed on their system, the dos.library
         notification function supports all three methods with
         both file and directory monitoring.

         From 53.72 this flags bit will also be set by the dos
         notify handler if the request falls under the control
         of the dos notify handler.

All other fields of the NotifyRequest should be set to 0 before
StartNotify() is called.

Once a change is made to the file system contents which correspond to
a file or directory being monitored according to your NotifyRequest,
the file system will send a notification as explained above.

Some filesystems do not support some options, such as NRF_CALL_HOOK
on files,  however, the V52.33+ dos.library does support all methods
on filesystem directories and files if the respective filesystem
rejects your request, or you force dos.library to handle your request
by specifying NRF_DOS_NOTIFY_ONLY in your request type flags.

If requested that messages should be sent, via the NRF_SEND_MESSAGE
method, the MsgPort pointed to by the nreq->nr_stuff.nr_Msg.nr_Port
field will receive a NotifyMessage. The following message fields are
of interest:

    NotifyMessage->nm_Class
 This is set to the value NOTIFY_CLASS.

    NotifyMessage->nm_Code
 This is set to the value NOTIFY_CODE.

    NotifyMessage->nm_NReq
 This points back to the NotifyRequest which caused
 the NotifyMessage to be sent.

Note that you must return this message when you no longer need
it. Specifically, all NotifyMessages must be returned by using
IExec->ReplyMsg() before you can safely end the notification
process by calling EndNotify().

**Bugs:**
The V36 floppy/HD filesystem doesn't actually send notifications.
The V36 ram handler ("RAM:") does.  This has been fixed for V37.

Care must be taken when sending notification requests to file
systems mounted on removable media. It is unsafe to remove the
medium for which the file notification was requested and to
re-insert it, possibly into a different drive. Some file systems,
notably the V50 FastFileSystem, handle this issue gracefully.
Others may not...
DOS supported notify requests handle this situation correctly.

Read-only file system, such as for CD-ROM media, typically do not
support file notification. With the exception of Envoy 2 and beyond,
no networked file system supports file notification.

This function is NOT callable from a task.

**See also:** NotifyVar(), GetDeviceProcFlags(), 
EndNotify(), AllocDosObject(), <dos/notify.h>, <dos/dostags.h>

---

### dos.library/StrToDate (V36)

**Converts a string to a DateStamp.**

**Synopsis:**
```c
int32 success = StrToDate( struct DateTime * datetime );
```

**Description:**
Converts a human readable text string into an AmigaDOS
DateStamp.

**Inputs:**
DateTime   - a pointer to an initialized DateTime structure.

The DateTime structure should be initialized as follows:

dat_Stamp  - ignored on input, may legally contain anything.

dat_Format - a format byte which specifies the format of the
      dat_StrDat.  This can be any of the following;

      FORMAT_DOS: AmigaDOS format (dd-mmm-yy).

      FORMAT_INT: International format (yy-mmm-dd).

      FORMAT_USA: American format (mm-dd-yy).

      FORMAT_CDN: Canadian format (dd-mm-yy).

      FORMAT_DEF: Default format for locale.

      FORMAT_ISO: ISO 8601 format (yyyy-mm-dd).
	                     Requires locale.library V48+ or dos
                  V50.36+ if locale not available.

      If the value used is something other than those
      above, the default of FORMAT_DOS is used.

dat_Flags -  a flags byte.
      The only flags which affect this function are:

      DTF_SUBST:  Ignored by this function.

      DTF_FUTURE: If set, indicates that strings such
                  as (stored in dat_StrDate) "Monday"
                  refer to "next" monday. Otherwise,
                  if clear, strings like "Monday"
                  refer to "last" monday.

dat_StrDay - ignored by this function.

dat_StrDate- pointer to valid nul-terminated string representing
      the date.
      If locale library v48+ is available, this may also be a
      DTF_SUBST style string such as "Today" "Tomorrow" "Monday"
      Otherwise, this is normally a string as specified by the
      dat_Format byte. This string will be converted to the
      ds_Days portion of the DateStamp.
      If this pointer is NULL, DateStamp->ds_Days will not
      be affected.

dat_StrTime- Pointer to a buffer which contains a valid nul-terminated
      time string in the ASCII format hh:mm:ss.
      This will be converted to the ds_Minute and ds_Tick
      portions of the DateStamp.
      If this pointer is NULL, ds_Minute and ds_Tick will
      be left unchanged.

**Result:**
success -    (Boolean) a zero return indicates that a conversion
      could not be performed.

      A non-zero return indicates that the DateTime.dat_Stamp
      variable contains the converted values.

**Notes:**
Please note that this function is always redirected to locale.library
after it has been initially opened by at least one caller.
Prior to the availablility of locale.library, the DOS version of this
function is not Locale aware and only understands the English formats.
FORMAT_DEF callers will be interpreted as the FORMAT_DOS layout and
the dat_Flags will also be ignored at this time.

**Bugs:**
Prior to V50 StrToDate() would not set the IoErr() code
when it returned failure. It now tries to set the error code
to a meaningful value.

**See also:** DateStamp(), DateToStr(), <dos/datetime.h>

---

### dos.library/StrToLong (V36)

**Converts an ASCII decimal string to an int32 value.**

**Synopsis:**
```c
int32 bytes = StrToLong(CONST_STRPTR string, int32 *value);
```

**Description:**
Converts signed ascii decimal string into an int32 value.  
Returns number of bytes converted. 

Skips over leading spaces and tabs or an optional '+' sign. 
(included in byte count if present).
If no decimal digits are found (after skipping leading bytes),
or if an overflow occurs,  or a 'string' of NULL is supplied,
StrToLong returns -1 for bytes converted, and puts 0 into value.
(providing 'value' is a non-NULL pointer.)

Conversion is terminated by the first non-digit byte that is
encountered after the conversion process has begun.

**Inputs:**
string - Input string.    (NULL will do nothing but return -1)
value  - Pointer to long value.  Always puts 0 into 'value' even if
  no digits are converted, or if a conversion overflow occurs.
  (providing 'value' is a non-NULL pointer)

**Result:**
result - Number of bytes converted or -1 on error.

**Notes:**
From V50, this function is task callable and now skips leading '+'.
This function does not currently affect IoErr().
This function is task callable.

**Bugs:**
Before V39, if there were no convertible bytes it returned the
number of leading white-space bytes (space and tab in this case)

Before V50, the value returned from an overflow would be erroneous.

**See also:** HexToLong().

---

### dos.library/SystemTagList (V36)

**Have a shell execute a command line.**

**Synopsis:**
```c
int32 error = System(CONST_STRPTR command, 
                    const struct TagItem *tags);

int32 error = SystemTagList(CONST_STRPTR command,
                    const struct TagItem *tags);

int32 error = SystemTags(CONST_STRPTR command, uint32 Tag1, ...);
```

**Description:**
Spawns a distinct Shell process to execute the command or stream,
returns the return code the command produced, or -1 if the command
could not be run for any reason.  The input and output filehandles
will not be closed by System for syncronous running, you must close 
them (if needed) after System returns, if you specified them via 
SYS_Input or SYS_Output.

By default the new synchronous shell process will use your current
Input(), Output() and ErrorOutput() filehandles.  Normal Shell 
command-line parsing will be done including redirection on 'command'.
  
A copy of the current directory and path will be inherited from your
syncronous process by default.  
Your path will be used to find the command if no path is specified).


  	DANGER
You MUST NEVER pass the same filehandle for both SYS_Input and 
SYS_Output and/or SYS_Error.  
If you want input and output to both be to the same CON: window,
pass a filehandle for a CON: window to SYS_Input and then pass a 
SYS_Output of ZERO.  The shell will automatically set the default
Output() stream to the window you passed via SYS_Input.
Also, by passing a SYS_Error of ZERO, the SYS_Output stream will be
used for both purposes by past convention.

**Inputs:**
SYS_Input  (BPTR) -- Input stream; defaults to the parent.
              Passing a ZERO value with this tag will now cause
              this function to open a "NIL:" stream. (@ V53.65)

SYS_Output (BPTR) -- Output stream; defaults to the parent.
              Specify ZERO for a copy of the SYS_Input stream.

SYS_Error  (BPTR) -- Error Output stream; default is dependant on mode,
              For SYS_ASynch,FALSE - defaults to the parent.
              For SYS_ASynch,TRUE  - defaults to ZERO.
              This stream is never closed by default, 
              refer to NP_CloseError below.   (V50).

NP_CloseError (int32; boolean) -- Due to backward compatibility issues
    DOS is unable to allow the SYS_Error stream to be closed by default.
    You will have to specify this tag as TRUE to have it automatically
    close SYS_Error upon exit. 

SYS_Asynch (int32; boolean) -- If TRUE, this function will return
    as soon as the child process has been started, and once the
    child has returned, its input/output streams WILL be closed
    (even if these are the same as the parent's). 

    If FALSE, any supplied streams or inherited parent streams will not
    be closed when the command ends, streams supplied by you will need
    to be closed when the command returns.      Defaults to FALSE.

SYS_UserShell (int32; boolean) -- Make the user "Shell" execute the
    program instead of the "BootShell" or custom shell. 
    This tag will override SYS_CustomShell.  Defaults to FALSE.

SYS_CustomShell (STRPTR) -- Make the specified shell execute the
    program instead of the default. The parameter must be the
    name of the shell to use, as found on the dos resident seg list.
    The function IDOS->FindSegment() is used internally for this,
	to obtain the seglist to the specified shell.
    This tag is ignored if the tag 'SYS_UserShell,TRUE' was specified.
    Defaults to "BootShell".

SYS_ExecuteInputStream (int32; boolean) -- When TRUE, the 'command'
    string parameter will be ignored, (set it to "") and then the
    input file handle will be used to read shell commands from,
    this is supplied via the SYS_Input tag.
    SYS_Asynch tag will currently be forced to FALSE when this tag
    is specified, but do not depend on this behaviour for the future.
    The input file handle may also be a console descriptor to
    spawn a new syncronous interactive shell process.  (V53.45+)

NP_CurrentDir (BPTR) -- Current directory of the child process.
    Defaults to a (DupLock) copy of the parent's current directory.

NP_StackSize (int32) -- The stack size the child process should use.
    Defaults to the DOS prefs minimum value.

NP_Name (STRPTR) -- Name of the child process. 
    Defaults to "Background CLI" if no tag is specified.
    From V50, there is no maximum length limit imposed on this string.
    The child process' task structure; task->tc_Node.ln_Name will
    point to the DOS allocated buffer to where this string is copied.
    The exec function FindTask() searches on this string.

NP_Path (BPTR) -- BCPL pointer to a 'struct PathNode' which should
    be used for the child process. 
    Note: the path is used as is and not duplicated. 
    It will be freed automatically when the process exits and must 
    be freed manually if the process could not be created.

NP_Priority (int32; -128 .. 127) -- Task priority of the child
    process. Defaults to the same as the parent.

NP_ConsolePort (struct MsgPort *) -- Address of the console handler
    port the child process should use. 
    Defaults to the same as the parent.

NP_WindowPtr (APTR) -- Indicate where dos.library requesters should
    be displayed for the child process (on the Workbench screen,
    a custom screen or not at all). 
    Defaults to the same value as the parent process only if it is 
    a value of 0 or -1, and if the parent is a process, otherwise 0.

    EG; A value of 0, indicates requesters should be displayed on
 the default public screen.  (Usually WorkBench)
 A value of -1 indicates that no requesters shall be shown.
 Otherwise, a pointer to an open intuition window that all
 requesters should be opened on.

NP_CopyVars (int32; boolean) -- Indicate whether the local variables
    associated with the parent should be copied for the child
    process. Defaults to TRUE.

Other NP_xxxxxx tags that are not excludes above, please refer to
    the CreateNewProc() documentation for usage of these other 
    specialty tags that can also be of use with this function.

**Result:**
error -- 0 for success.

    Depending on the mode used, the value returned can mean
    different things.

    SYS_Asynch,TRUE:
      -1 = indicates System() failure.
       0 = indicates System() success, 

    SYS_Asynch,FALSE:
      -1 = indicates System() failure.
       n = non-zero  program error.
       0 = indicates program success.
       

    Note that *ONLY* with a -1 error code, the caller is responsible
    for filehandles, paths or other things passed in via tags.

    -1 error codes will be returned if DOS could not find the shell,
    or was otherwise unable to start the new shell process.
    Consult IoErr() to find out what actually happened.

**Notes:**
From V37+, if an input filehandle is passed, and it's either
interactive or a "NIL:" filehandle, the pr_ConsolePort of the new
process will be set to that filehandle's process.

Before 53.65 launching asynch commands from a workbench started process
that use clib/newlib wrappers would initialise their own pr_ConsolePort
and close it when that process ends, if an ASYNCH child shell process 
was started with the SYS_Input tag set to ZERO, it would copy the 
parents pr_ConsolePort which would leave the new ASYNCH child process
using a dead pr_ConsolePort when the parent process exits.
So now, specifying a ZERO input stream automatically opens "NIL:" 
no matter what mode is used.

This function will also send an ACTION_CHANGE_SIGNAL packet to the
input stream handler upon startup, and again upon returning, restoring
the sigtask to the parent process.  (the same applies to Execute()).

From 51.77   If an ASYNCH command was started ok, (returncode 0)
the new process identifier (PID), from the process structure field
process->pr_ProcessID, may be obtained by calling IoErr() immediately
after this function returns.  Note that PID numbers can never be zero.

**See also:** CreateNewProc(), <dos/dostags.h>, Input(), Output(), ErrorOutput(),
ProcessScan(), NotifyProcListChange().

---

### dos.library/TimedDosRequester

**EasyRequest() style function via DOS. (V51.12)**

**Synopsis:**
```c
int32 num = TimedDosRequester( const struct TagItem *taglist );

int32 num = TimedDosRequesterTags( uint32 Tag1, ... );
```

**Description:**
This function provides all calls from DOS library and any applications
that wish to use it,  access to intuitions EasyRequest() functionality
and the ability to have reaction style looking requesters with an added
timeout feature, that was not previously available directly.

The requester is constructed from parameters supplied from the taglist.
The handling of the timeout is provided by the timer device.

Refer to intuition/EasyRequest() for more information on how to 
correctly initialise the EasyStruct structure, if you wish to do this
yourself and not use the internally built one.

NB:  This function is usually redirected to use Reaction requesters 
     when IPrefs is started, to provide ongoing style consistency for
     dos.library and others that wish to call it.

     When TimedDosRequester() is redirected to use reaction style 
     requesters, it may also cause disk I/O to load images or fonts,
     therefore you should not use it with filesystems and handlers
     without specifying;  (TDR_NonBlocking,TRUE)  to avoid cases 
     where possible deadlocks may occur.  
     (The TDR_NonBlocking tag was added in V52.16)

**Inputs:**
TDR_IDCMP_Ptr (uint32 *) 
 -- OPTIONAL pointer to a longword initialised with the 
    IDCMP flags to terminate the requester on. (Default; NULL)

TDR_Timeout (int32)
 -- OPTIONAL value in seconds to wait before requester will close
    without intervention.  
    A timeout will only occur with values > 0.
    It is recommended that timouts less than 10 seconds be
    avoided whenever possible, to be user-friendly. (Default; 0)

TDR_Window (struct Window *)
 -- OPTIONAL pointer to an (over-riding) reference window.
    Normally, you would not need to specify this tag.

    However, if you are calling this function from a task, 
    the default process window value will not be available and
    you would normally finish up having the requester rendered
    on the default public screen instead, (usually workbench)
    therefore you can use this tag to force it to use your 
    own specified window, this will work from both a task or 
    a process. 
    (Default; process->pr_WindowPtr, or NULL from a task)

TDR_NonBlocking (int32; Boolean)    (tag added V52.16)
 -- OPTIONAL switch to prevent this function from attempting
    any disk based I/O whatsoever for filesystems and handlers.
    This makes the function safe to call at any time from
    handlers and filesystems and in some cases even performing
    dospacket I/O from a task context.

    This tag will effectively bypass the use of any reaction
    components that may cause blocking issues and re-apply the
    original dos.library code that only calls the EasyRequest()
    function, as if it were never patched by "Iprefs". 
    (Default; FALSE)

TDR_EasyStruct (struct EasyStruct *)
 -- OPTIONAL pointer to your own initialised private struct
    EasyStruct that you wish to use instead of the default one.
    If you do not specify this tag, DOS will allocate one and 
    also initialise the EasyStruct.es_StructSize field for you.
    (Default; internally allocated)

TDR_FormatString (STRPTR)
 -- The format string using RawDoFmt style specifiers that match
    the number of arguments you will supply.
    If this tag is present, it will override a formatstring that
    may have already been supplied with your own TDR_EasyStruct.
 
TDR_TitleString (STRPTR)
 -- The window title string for the requester.
    If this tag is present, it will override a title string that
    may have already been supplied with your own TDR_EasyStruct.
 
TDR_GadgetString (STRPTR)
 -- The string specifier for the gadgets/text for the requester.
    The format for this is the same as for an EasyRequest,
    the individual buttons being prepresented by separating the
    button text as follows: "ONE|TWO|THREE|ZERO".
    If this tag is present, it will override a Gadget string 
    that may have been supplied with your own TDR_EasyStruct.
    Note; The underscore '_' character may preceed any of
          the button texts to enable shortcut keys.
 
TDR_ArgArray (APTR)
 -- OPTIONAL pointer to your own properly initialised argument
    array structure with the full number of entries that
    correspond to the RawDoFmt() format specifiers in the
    format string.
    -> DO NOT <- use this tag if you wish to specify up to the
    first ten (32-bit wide) arguments individually by using the
    following TDR_Arg# tags.

TDR_Arg1 (APTR)
 -- Corresponding to the first argument in the formatstring. 

TDR_Arg2 (APTR)
 -- Corresponding to the second argument in the formatstring. 

TDR_Arg3 (APTR)
 -- Corresponding to the third argument in the formatstring. 

TDR_Arg4 (APTR)
 -- Corresponding to the fourth argument in the formatstring. 

TDR_Arg5 (APTR)
 -- Corresponding to the fifth argument in the formatstring. 

TDR_Arg6 (APTR)
 -- Corresponding to the sixth argument in the formatstring. 

TDR_Arg7 (APTR)
 -- Corresponding to the seventh argument in the formatstring. 

TDR_Arg8 (APTR)
 -- Corresponding to the eighth argument in the formatstring. 

TDR_Arg9 (APTR)
 -- Corresponding to the ninth argument in the formatstring. 

TDR_Arg10 (APTR)
 -- Corresponding to the tenth argument in the formatstring. 


TDR_ImageType (uint32)
 -- The visual style of this request. This argument currently
    has no effect before IPrefs is running, but should always
    be specified to indicate the style of request this is 
    directed for.   (Default; TDRIMAGE_DEFAULT)

    The values for this tag are found in the include file;
    include/dos/dostags.h and are specified as:

    TDRIMAGE_DEFAULT         /* general purpose             */ 
    TDRIMAGE_INFO            /* informative style '!'       */
    TDRIMAGE_WARNING         /* warning style               */
    TDRIMAGE_ERROR           /* error style   'X'           */
    TDRIMAGE_QUESTION        /* question '?'                */ 
    TDRIMAGE_INSERTDISK      /* request for a volume insert */

TDR_Inactive (int32; Boolean)
 -- OPTIONAL Boolean value to specify the requester window should
    not be activated to avoid it stealing the users input focus.
    You should set this to TRUE when the gadgets of your 
    requester contain keyboard shortcuts as it's possible that
    the user is currently typing text in another application
    (otherwise the user could answer the requester by accident).
    (Default; FALSE)

TDR_CharSet (uint32)
 -- OPTIONAL Character set for the requester's text and gadgets.
    Defaults to 0, meaning the charset of the screen font which
    will be the current system default charset in most cases.
    This argument has currently no effect before IPrefs has run.
    The value is based on the IANA MIBenum value for charsets.
    See the autodoc for diskfont.library/ObtainCharsetInfo().
    TDR_CharSet should be set by localized applications that want
    to display localized requesters, they tell locale.library in
    OpenCatalog() that it shall not convert the catalog charset
    to current system default charset and use the value of 
    Catalog->cat_CodeSet for the TDR_CharSet.    (Default; 0)

**Result:**
1,2,n,0 =  Successive GadgetID values for the gadgets you specify 
    for the requester.  
 
    NOTE: The numbering from left to right is:
    1, 2, 3,..., n, 0.
    This is for compatibility with AutoRequest(), which has
    FALSE for the right-most gadget.


-1       = Means that the user was unable to answer the requester.

    This may be because one of the caller-supplied IDCMP Flags
    occurred, the IDCMP message->im_Class flag is put into the
    longword pointed to by the supplied TDR_IDCMP_ptr tag, 
    otherwise zero.  (providing IDCMP ptr != NULL, ie: Default)

    Or the requester timed out, if the timeout value was >0.

    Or the requester was unable to post, either because the
    pr_WindowPtr or TDR_Window was set to -1 to intensionally
    suppress it, or some other error occured which prevented 
    the requester from opening, like; insufficient memory.


IDCMP_ptr = (See result -1).

**Notes:**
The TDR_Arg# tags always expect 32 bit wide parameters, your format
string should reflect this.  If you need to supply a different width,
you will need to use your own argarray structure instead.

At the time of publication, the only IDCMP flag recognised by the 
Reaction requester.class is IDCMP_DISKINSERTED. 

This function is callable from a task.

---

### dos.library/UnGetC (V36)

**Makes a char available for reading again. (buffered)**

**Synopsis:**
```c
int32 value = UnGetC(BPTR fh, int32 character);
```

**Description:**
Pushes the character specified back into the input buffer.  Every
time you use a buffered read routine, you can always push back 1
character.  You may be able to push back more, though it is not
recommended, since there is no guarantee on how many can be
pushed back at a given moment.

Passing -1 for the character will cause the last character read to
be pushed back.  If the last character read was an EOF, the next
character read will be an EOF.

Note: UnGetC can be used to make sure that a filehandle is set up
as a read filehandle.  This is only of importance if you are writing
a shell, and must manipulate the filehandle's buffer.

**Inputs:**
fh	      - filehandle to use for buffered I/O
character - character to push back or -1

**Result:**
value     - character pushed back, or FALSE if the character cannot
     be pushed back.

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

**Bugs:**
In V36, UnGetC(fh,-1) after an EOF would not cause the next character
read to be an EOF.  This was fixed for V37.

**See also:** FGetC(), FPutC(), FFlush(), SetFileHandleAttr()

---

### dos.library/UnLoadSeg

**Unloads a SegList or PseudoSegList.**

**Synopsis:**
```c
int32 success = UnLoadSeg( BPTR seglist );
```

**Description:**
Unload a seglist loaded by LoadSeg() or created by AllocSegList().
Overlay 68K, and Native seglists will have all needed cleanup done,
including closing the file for a 68k overlay seglist.

**Inputs:**
seglist - BCPL pointer to a seglist (or NULL).

**Result:**
success - non zero for success, returns zero on failure.
   Failure can occur if a seglist of ZERO was passed in,
   or if it failed to close an overlay 68k file,
   or if the seglist is tagged to prevent it being freed.

**Notes:**
Please note that LoadSeg() calls the TrackSegmentList() internally,
of course conversely, UnLoadSeg() calls UnTrackSegmentList().

This function returned a random value before V36!

Due to compatibility reasons this function is still callable from
exec tasks for ONLY non-overlay 68K style seglists, 
or PseudoSeglists constructs.
All other types of seglists will cause a notifiable failure if
a task attempts to call this function.

**See also:** LoadSeg(), GetSegListInfo(), AllocSegList().

---

### dos.library/UnLock

**Unlock a directory or file.**

**Synopsis:**
```c
VOID UnLock( BPTR lock );
```

**Description:**
Unlocks a filing system lock, as obtained from Lock(), DupLock(), 
DupLockFromFH(), ParentOfFH(), ParentDir(), CreateDir() or the
CreateDirTree() function.

**Inputs:**
lock - BCPL pointer to a lock. (or ZERO)

**Notes:**
This function is guaranteed not to change the state of IoErr().
Passing zero to UnLock() is harmless.
This function can also be called from an exec task.

**See also:** Lock(), DupLock(), ParentOfFH(), DupLockFromFH(), ParentDir(), 
CreateDir(), CreateDirTree().

---

### dos.library/UnLockDosList (V36)

**Unlocks the Dos List**

**Synopsis:**
```c
VOID UnLockDosList(uint32 flags);
```

**Description:**
Unlocks the access on the Dos Device List.  
You MUST pass the same flags you used to lock the list.

**Inputs:**
flags - MUST be the same flags passed to (Attempt)LockDosList()

**Notes:**
This function IS callable from exec tasks.

**See also:** AttemptLockDosList(), LockDosList(), Permit()

---

### dos.library/UnLockRecord

**Unlock a locked record.**

**Synopsis:**
```c
int32 success = UnLockRecord(BPTR fh, int64 offset, int64 length);
```

**Description:**
This releases the specified lock on a file.  Note that you must use
the same filehandle you used to lock the record, and offset and
length must be the same values used to lock it.  Every LockRecord()
call must be balanced with an UnLockRecord() call.

**Inputs:**
fh      - (BPTR)  BCPL pointer to open filehandle of file.
offset  - (int64) Byte offset of record start position.
length  - (int64) Byte length of record.

**Result:**
success - (int32) boolean; (zero or non-zero) Zero on falure.

**Notes:**
Re: Close();
Please be advised that due to dependancies and idiosyncrasies of the
various filesystems that are available, the behavious of Close() with
regard to freeing record locks is currently indeterminant.
You are therefore advised to FreeRecord/s() of any records that may 
have been locked by the application, BEFORE calling Close().

**See also:** LockRecords(), LockRecord(), UnLockRecords()

---

### dos.library/UnLockRecords (V36)

**Unlock a list of records.**

**Synopsis:**
```c
int32 success = UnLockRecords(struct RecordLock *record_array);
```

**Description:**
This releases an array of record locks obtained using LockRecords.
You should NOT modify the record_array while you have the records
locked.  Every LockRecords() call must be balanced with an
UnLockRecords() call.

**Inputs:**
record_array - List of records to be unlocked

**Result:**
success      - boolean; (zero or non-zero)

**Notes:**
Re: Close();
Please be advised that due to dependancies and idiosyncrasies of the
various filesystems that are available, the behaviour of Close() with
regard to freeing record locking is currently indeterminant.
You are therefore advised to FreeRecord/s() of any records that may 
have been locked by the application, BEFORE calling Close().

**Bugs:**
See LockRecord()

**See also:** LockRecords(), LockRecord(), UnLockRecord()

---

### dos.library/VFPrintf (V36)

**format and print a string to a file. (buffered)**

**Synopsis:**
```c
int32 count = VFPrintf(BPTR fh, CONST_STRPTR fmt, CONST_APTR argv);

int32 count = FPrintf(BPTR fh, CONST_STRPTR fmt, ...);
```

**Description:**
Writes the formatted string and values to the given file.  This
routine is assumed to handle all internal buffering so that the
formatting string and resultant formatted values can be arbitrarily
long.  Any secondary error code is returned in IoErr().  This routine
is buffered.  See Notes for extended new V51 DOS format specifiers.

**Inputs:**
fh    - Filehandle to write to, (or 0).
fmt   - RawDoFmt() style formatting string
argv  - Pointer to array of formatting values

**Result:**
count - Number of bytes written or -1 (EOF) for an error.

**Example:**
```c
(1)     count = IDOS->FPrintf(fh,"%ld+%ld=%ld.\n", 1,2,3);

(2)     int32 array[3] = { 1,2,3 };
 count = IDOS->VFPrintf(fh,"%ld+%ld=%ld.\n", &array[0]);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

From 51.59 all DOS (only) string formatting functions now accept 
two additional special DOS format specifiers;  %m and %n.
These will be replaced by the error message (%m) such as would be
obtained by the Fault() function and the error number (%n) as returned
from IoErr() that was valid at the time this function was called.
In all other respects these functions work like they always did.

EG: 
count = IDOS->FPrintf(fh,"error message = %m, error code = %n\n",...);

This new functionality may need to allocate temporary memory before
it can print the error message. However, if the error came about 
because of memory shortage then the message/value string insertion 
may not be performed at all.

Internally, this function transforms the format string to include
the respective error message/number strings; these must not contain
format specifiers themselves or the underlying RawDoFmt() function
will end up trying to fetch parameters off the argument list which
are not available. To prevent this possibility, when the error message
is being inserted, any '%..' format specifiers found in the actual
error message will be removed entirely to prevent this happening.

**Bugs:**
The prototype for FPrintf() currently forces you to cast the first
varargs parameter to LONG due to a deficiency in the program
that generates fds, prototypes, and amiga.lib stubs.

From V50, it is now documented as safe to supply a 'fh' of zero, 
this function will and always did nothing but return -1.  (EOF).

There is currently a minor problem when using 64 bit stack args.
The current compiler for OS4 enforces 64 bit alignment of 64 bit
arguments, but Printf assumes 32 bit alignment (VARARGS68K).
It is relatively easy to workaround by making sure 64 bit arguments
are aligned appropriately.  Carefull placement of parameters will
be sufficient. eg;   

IDOS->FPrintf(fh,"%lld %ld\n", 64bit_val, 32bit_val);       /* works */
IDOS->FPrintf(fh,"%ld %lld\n", 32bit_val, 64bit_val);       /* fails */
IDOS->FPrintf(fh,"%ld %s%lld\n", 32bit_val, "", 64bit_val); /* works */
 
Therefore, always use carefull placement or pad 64 bit values with
empty 32 bit string ("") arguments to attain 64 bit alignment when
using 64 bit parameters with this function.

**See also:** VPrintf(), RawDoFmt(), FPutC(), FOpen(), FClose(),SetFileHandleAttr().

---

### dos.library/VPrintf (V36)

**format and print string. (buffered)**

**Synopsis:**
```c
int32 count = VPrintf(CONST_STRPTR fmt, CONST_APTR argv);

int32 count = Printf(CONST_STRPTR fmt, ...);
```

**Description:**
Writes the formatted string and values to Output().  This routine 
is assumed to handle all internal buffering so that the formatting
string and resultant formatted values can be arbitrarily long.
Any secondary error code is returned in IoErr().  
This routine is buffered. 
See Notes for extended new V51 DOS format specifiers.

Note: RawDoFmt assumes 16 bit ints, so you will usually need 'l's in
your formats (ex: %ld versus %d).

**Inputs:**
fmt   - exec.library RawDoFmt() style formatting string.
argv  - Pointer to array of formatting values.

**Result:**
count - Number of bytes written or -1 (EOF) for an error.

**Example:**
```c
(1)     count = IDOS->Printf("%ld+%ld=%ld.\n", 1,2,3);

(2)     int32 array[3] = { 1,2,3 };
 count = IDOS->VPrintf("%ld+%ld=%ld.\n", &array[0]);
```

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

From 51.59 all DOS (only) string formatting functions now accept 
two additional special DOS format specifiers;  %m and %n.
These will be replaced by the error message (%m) such as would be
obtained by the Fault() function and the error number (%n) as returned
from IoErr() that was valid at the time this function was called.
In all other respects these functions work like they always did.

EG: count = IDOS->Printf("error message = %m, error code = %n\n",0);

This new functionality may need to allocate temporary memory before
it can print the error message. However, if the error came about 
because of memory shortage then the message/value string insertion 
may not be performed at all.

Internally, this function transforms the format string to include
the respective error message/number strings; these must not contain
format specifiers themselves or the underlying RawDoFmt() function
will end up trying to fetch parameters off the argument list which
are not available. To prevent this possibility, when the error message
is being inserted, any '%..' format specifiers found in the actual
error message will be removed entirely to prevent this happening.

**Bugs:**
The prototype for Printf() currently forces you to cast the first
varargs parameter to LONG due to a deficiency in the program
that generates fds, prototypes, and amiga.lib stubs.

There is currently a minor problem when using 64 bit stack args.
The current compiler for OS4 enforces 64 bit alignment of 64 bit
arguments, but Printf assumes 32 bit alignment (VARARGS68K).
It is relatively easy to workaround by making sure 64 bit arguments
are aligned appropriately.  Carefull placement of parameters will
be sufficient. eg;   

IDOS->Printf("%lld %ld\n", 64bit_val, 32bit_val);        /* works */
IDOS->Printf("%ld %lld\n", 32bit_val, 64bit_val);        /* fails */
IDOS->Printf("%ld %s%lld\n", 32bit_val, "", 64bit_val);  /* works */
 
Therefore, always use carefull placement or pad 64 bit values with
empty 32 bit string ("") arguments to attain 64 bit alignment when
using 64 bit parameters with this function.

**See also:** VFPrintf(), RawDoFmt(), FPutC(), FOpen(), FClose(), SetFileHandleAttr()

---

### dos.library/WaitForChar

**Determine if chars arrive within a time limit.**

**Synopsis:**
```c
int32 status = WaitForChar(BPTR file, int32 timeout );
```

**Description:**
If a character is available to be read from the handler that 'file'
is bound to, within the time (in microseconds) indicated by 'timeout',
WaitForChar() returns (TRUTH). 
If a character is available, you can use Read() to read it.
Note that WaitForChar() is only valid if the I/O stream is connected
to a virtual terminal device. If a character is not available within
'timeout', a (FALSE) is returned.

**Inputs:**
file    - BCPL pointer to a file handle.
timeout - integer (microseconds)

**Result:**
status  - boolean  (zero or non-zero)

**Notes:**
This function is NOT callable by tasks.
Only stream handlers support this functionality, filesystems do not.
All NIL: streams will return FALSE.
Always check the return code of this function and call IoErr() when
FALSE is returned to determine why it failed.

**Bugs:**
Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
of zero for WaitForChar() could cause the unreliable timer & floppy
disk operation.

**See also:** Read(), FGetC(), IsFileSystemPort().

---

### dos.library/WaitPkt (V36)

**Low level function to wait for a DosPacket to arrive.**

**Synopsis:**
```c
struct DosPacket *packet = WaitPkt(struct MsgPort *V50_task_replyport);
```

**Description:**
From a process only, waits for a packet to arrive at your pr_MsgPort.
If anyone has installed a packet wait function in pr_PktWait, 
it will be called instead of the default routine.

(V50) From a task only, waits for a packet to arrive at the replyport
specified by the argument 'V50_task_replyport'.

The message will then be automatically GetMsg()ed so that it is no 
longer on the port.  It assumes the message is a dos packet.  
It is NOT guaranteed to clear the signal for the port.

**Inputs:**
V50_task_replyport - A valid replyport ONLY for a TASK calling this;
              always ignored from a Process, therefore it 
              should be set to NULL in this case.

**Result:**
packet - the packet that arrived at the port. (from ln_Name of message)

**Notes:**
From V51.44, this function is now callable from a task, providing
that the task calling this function supplies a valid replyport.
For pre-V51 compatibility, this argument is ignored by any process. 

This function will no longer return until a DosPacket is received.

**Bugs:**
Until V51.44 when called from a task, this function would Wait() 
for the wrong signal bit for the port and would never return.

**See also:** SendPkt(), DoPkt()

---

### dos.library/Write

**Low level routine to write bytes of data to a file. (unbuffered)**

**Synopsis:**
```c
int32 returnedLength = Write(BPTR file,CONST_APTR buffer,int32 length);
```

**Description:**
Write() writes bytes of data to the opened file 'file'. 
'length' indicates the number of bytes to transfer from 'buffer'. 
The value returned is the length of information actually written.

An error has occured when 'returnedLength' is not equal to 'length',
in this situation, call IoErr() to find out what error occured.

Note: this is an unbuffered routine, the request is passed directly
to the underlying filesystem or handler.
Buffered I/O is more efficient for small reads and writes, see;
FPutC(), FWrite(), FPuts()...

**Inputs:**
file   - (BPTR) BCPL pointer to an open file handle.
buffer - (APTR) pointer to the buffer.
length - (int32) number of bytes to write.

**Result:**
returnedLength - (int32) number of bytes written, or -1 on error.

**Notes:**
Always test if returnedLength != length and treat this as an error
and call IoErr() to find out why the requested number of bytes were
not actually written, do not compare the retrunedLength to -1,
that is not enough, some earlier filesystems failed to return -1 on
errors such as ERROR_DISK_FULL and simply returned the number of bytes
it actually wrote before the disk was completely filled.
The V54 autodocs now specify that handlers return -1 for all errors,
but your software may still encounter older handlers, so be prepared.

Some file systems may not support the creation or writing to files
larger than 2 GBytes. Extending files beyond the 2 GByte mark or the
4 GByte mark may not be supported either, leading to unexpected
file system behaviour. If your software can be expected to create
or maintain files of such sizes you should implement safeguards
against accidental data corruption due to overly long files. 
For example, some file systems may not be able to tell the difference
between a file that is a three bytes in excess of 4 GBytes large and
a file which is exactly three bytes in size.

This function is NOT callable by tasks.

**See also:** Read(), Open(), Close().

---

### dos.library/WriteChars (V36)

**Writes bytes to the default output. (buffered)**

**Synopsis:**
```c
int32 count = WriteChars(CONST_STRPTR buffer, uint32 buflen);
```

**Description:**
This routine writes a number of bytes to the default output. 
The length written is returned.  This routine is buffered.

**Inputs:**
buffer - buffer of characters to write.
buflen - number of characters to write.

**Result:**
count  - Number of bytes written.  -1 (EOF) indicates an error

**Notes:**
From DOS 51.45 all buffered I/O functions now employ automatic task
semaphore locking by default, therefore it is now safe to share a 
filehandle across multiple tasks which may also call a buffered 
DOS I/O function.

This function is now a compatibility stub that calls FWrite() as;
    return IDOS->FWrite(IDOS->Output(), (APTR)buffer, 1, buflen);

**See also:** FPuts(), FPutC(), FWrite(), PutStr(), FOpen(), FClose(),
SetFileHandleAttr().

---

### dos.library/WriteProtectVolume

**Sets write protection status of a volume (V51.100)**

**Synopsis:**
```c
int32 success = WriteProtectVolume(CONST_STRPTR filesystem, 
             int32 on_off, uint32 passkey, int32 reserved);
```

**Description:**
Sends a write protect request to the indicated handler. 
Sets up whether the handler will prevent write access to the media.

When un-write protecting, if a 'passkey' value other than zero was 
specified when the volume was write protected, the same passkey must
be specified when un-write protecting before the handler will grant
write access again.

**Inputs:**
filesystem - (STRPTR) Identifier for the device/volume to write protect.
      (See GetDeviceProcFlags() for more details about this.)

on_off     - (BOOLEAN) TRUE=Write protected, FALSE=Un-write protected.

passkey    - (uint32)  Unsigned integer to secure the protection request.
               (A value of zero indicates no security.)

reserved   - (int32)   Reserved for expansion, (MUST BE SET TO ZERO).

**Result:**
success    - (BOOLEAN) Zero for failure, non-zero for success.

**Example:**
```c
/* Passkey may be derived from a hashed password string, like the
 * following example, or it can be any other arbitrary value you
 * wish to use to secure a write protection request. 
 */
 
uint32 calculate_passkey(CONST_STRPTR password_string)
{
    uint8 *p = (uint8 *)password_string;
    uint32 passkey = 0;

    while( *p )
    {
 passkey = (10 * passkey) + (uint32)*p++;
    }
    return(passkey);
}
```

**Notes:**
This function is NOT task callable.

The effect of this function is not permanent, it will last only until
the next reboot, disk change or handler restart.

The 'on_off' parameter value may be adjusted for backward semantical
compatibility by this function, before passing it to the filesystem.

The 'reserved' parameter MUST be set to zero or failure will occur.

**See also:** GetDeviceProcFlags().

---

### dos.library/WriteProtectVolumePort

**Sets write protection status of a volume
                   identified by its message port. (V53.149)**

**Synopsis:**
```c
int32 success = WriteProtectVolumePort(struct MsgPort *port, 
             int32 on_off, uint32 passkey, int32 reserved);
```

**Description:**
Sends a write protect request to the handler identified by the port.
Sets up whether the handler will prevent write access to the media.

When un-write protecting, if a 'passkey' value other than zero was 
specified when the volume was write protected, the same passkey must
be specified when un-write protecting before the handler will grant
write access again.

**Inputs:**
port     - (struct MsgPort *) Filesystem message port to write protect.

on_off   - (BOOLEAN) TRUE=Write protected, FALSE=Un-write protected.

passkey  - (uint32)  Unsigned integer to secure the protection request.
              (A value of zero indicates no security.)

reserved - (int32)   Reserved for expansion, (MUST BE SET TO ZERO).

**Result:**
success  - (BOOLEAN) Zero for failure, non-zero for success.

**Notes:**
This function is NOT task callable.

See WriteProtectVolume() for example 'passkey' generation code.

The effect of this function is not permanent, it will last only until
the next reboot, disk change or handler restart.

The 'on_off' parameter value may be adjusted for backward semantical
compatibility by this function, before passing it to the filesystem.

The 'reserved' parameter MUST be set to zero or failure will occur.

**See also:** WriteProtectVolume().

---

## Obsolete Functions

*These functions are deprecated and should not be used in new code.*

### dos.library/FreeDosEntry (V36) [OBSOLETE]

**Frees an entry created by MakeDosEntry[DEPRECATED V52.16]**

**Synopsis:**
```c
VOID FreeDosEntry(struct DosList * dlist);
```

**Description:**
Frees a single entry created by MakeDosEntry().

This function has been deprecated at V52.16 for FreeDosObject().

**Inputs:**
dlist - The DosList node to free.

**Notes:**
The entry that is being freed must NOT still be in the doslist.

From V52.16 this is now a stub that calls FreeDosObject().

**See also:** AddDosEntry(), RemDosEntry(), FindDosEntry(), LockDosList(),
NextDosEntry(), MakeDosEntry(), FreeDosObject().

---

### dos.library/MakeDosEntry (V36) [OBSOLETE]

**Allocate a DosList structure.[DEPRECATED V52.16]**

**Synopsis:**
```c
struct DosList *newdlist = MakeDosEntry(CONST_STRPTR name, int32 type);
```

**Description:**
Create a DosList structure, including allocating a name and 
correctly null-terminating the BSTR name. It also sets the dol_Type 
field from the parameter supplied, and sets all other fields to 0.

This function has been deprecated at V52.16 for AllocDosObject().

**Inputs:**
name - name for the device/volume/assign node.
type - type of node.   DLT_xxxx  (see dos/dosextens.h)

**Result:**
newdlist - The new device entry or NULL.

**Notes:**
From V50, a NULL 'name' parameter is now safe and simply returns
NULL and sets IoErr() to ERROR_REQUIRED_ARG_MISSING.

From V52.16, this is just a stub that calls AllocDosObject().

**See also:** AddDosEntry(), RemDosEntry(), FindDosEntry(), LockDosList(),
NextDosEntry(), FreeDosEntry(), AllocDosObject().

---

### dos.library/ReadItem (V36) [OBSOLETE]

**Synopsis:**
```c
int32 value = ReadItem(STRPTR buffer, int32 maxchars, 
                struct CSource *input);
```

**Description:**
DEPRECATED V36 function.  See ReadLineItem() documentation.

Reads a "word" from either: Input() or CSource, See <dos/dos.h>
Handles quoting and some escaped '*' substitutions.

**Inputs:**
buffer   - buffer to store word in.
maxchars - size of the buffer
input    - CSource input or NULL (uses FGetC(Input()))

**Result:**
Returns ITEM_xxx values defined in <dos/dos.h> depending on the
input arguments.

**Notes:**
From V51, this function is now deprecated due to compatibility
semantics that some pre-v50 68K software depended heavily upon,
which means it can't be fixed at this time, or if ever..
Therefore, do not use this function with new applications from 
V51 onwards, as it may eventually disappear when 68K compatibility
is no longer required.

**Bugs:**
This V36 version suppressed output which was dependant on white 
space placement or lack thereof. 
Terminator character was never available from this function.
Escape string "*" failed to return a null string,
Never set IoErr() to anything useful.

Use ReadLineItem() for new applications.

**See also:** ReadArgs(), FindArg(), UnGetC(), FGetC(), FGets(), Input(), 
<dos/dos.h>, <dos/rdargs.h>, FreeArgs()

---
