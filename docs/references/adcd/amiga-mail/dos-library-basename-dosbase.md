---
title: dos.library (basename: _DOSBase)
manual: amiga-mail
chapter: amiga-mail
section: dos-library-basename-dosbase
functions: [AllocDosObject, Cli, GetArgStr, GetDeviceProc, GetProgramDir, IoErr, MatchFirst, MatchNext, MatchPattern, MaxCli, ReadArgs, WaitPkt]
libraries: [dos.library]
---

# dos.library (basename: _DOSBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AbortPkt(port,pkt)(d1/d2)               - Aborts an asynchronous packet,
```c
                                          if possible. (V36)
```
AddBuffers(name,number)(d1/d2)          - Changes the number of buffers
```c
                                          for a filesystem (V36)
```
AddDosEntry(dlist)(d1)                  - Add a Dos List entry to the
```c
                                          lists (V36)
```
AddPart(dirname,filename,size)(d1/d2/d3)- Appends a file/dir to the end of
```c
                                          a path (V36)
```
AddSegment(name,seg,system)(d1/d2/d3)   - Adds a resident segment to the
```c
                                          resident list (V36)
```
AllocDosObject(type,tags)(d1/d2)        - Creates a dos object (V36)
AssignAdd(name,lock)(d1/d2)             - Adds a lock to an assign for
```c
                                          multi-directory assigns (V36)
```
AssignLate(name,path)(d1/d2)            - Creates an assignment to a
```c
                                          specified path later (V36)
```
AssignLock(name,lock)(d1/d2)            - Creates an assignment to a
```c
                                          locked object (V36)
```
AssignPath(name,path)(d1/d2)            - Creates an assignment to a
```c
                                          specified path (V36)
```
AttemptLockDosList(flags)(d1)           - Attempt to lock the Dos Lists
```c
                                          for use (V36)
```
ChangeMode(type,fh,newmode)(d1/d2/d3)   - Change the current mode of a
```c
                                          lock or filehandle (V36)
```
CheckSignal(mask)(d1)                   - Checks for break signals (V36)
Cli()()                                 - Returns a pointer to the CLI
```c
                                          structure of the process (V36)
```
CliInitNewcli(dp)(a0)                   - Set up a process as a shell
                                          according to the inital packet.
CliInitRun(dp)(a0)                      - Set up a process as a shell
                                          according to the inital packet.
CompareDates(date1,date2)(d1/d2)        - Compares two datestamps (V36)
CreateNewProc(tags)(d1)                 - Create a new process (V36)
DateToStr(datetime)(d1)                 - Converts a DateStamp to a string
```c
                                          (V36)
```
DeleteVar(name,flags)(d1/d2)            - Deletes a local or environment
```c
                                          variable (V36)
```
DoPkt(port,action,arg1,arg2,arg3,arg4,arg5)(d1/d2/d3/d4/d5/d6/d7)
```c
                                        - Send a dos packet and wait for
                                          reply (V36)
```
DupLockFromFH(fh)(d1)                   - Gets a lock on an open file (V36)

EndNotify(notify)(d1)                   - Ends a notification request (V36)

ErrorReport(code,type,arg1,device)(d1/d2/d3/d4)
```c
                                        - Displays a Retry/Cancel
                                          requester for an error (V36)
```
ExAll(lock,buffer,size,data,control)(d1/d2/d3/d4/d5)

```c
                                        - Examine an entire directory (V36)
```
ExamineFH(fh,fib)(d1/d2)                - Gets information on an open file
```c
                                          (V36)
```
Fault(code,header,buffer,len)(d1/d2/d3/d4)
```c
                                        - Returns the text associated with
                                          a DOS error code (V36)
```
FGetC(fh)(d1)                           - Read a character from the
```c
                                          specified input (buffered) (V36)
```
FGets(fh,buf,buflen)(d1/d2/d3)          - Reads a line from the specified
```c
                                          input (buffered) (V36)
```
FilePart(path)(d1)                      - Returns the last component of a
```c
                                          path (V36)
```
FindArg(keyword,template)(d1/d2)        - Find a keyword in a template
```c
                                          (V36)
```
FindCliProc(num)(d1)                    - Returns a pointer to the
```c
                                          requested CLI process (V36)
```
FindDosEntry(dlist,name,flags)(d1/d2/d3)- Finds a specific Dos List entry
```c
                                          (V36)
```
FindSegment(name,seg,system)(d1/d2/d3)  - Finds a segment on the resident
```c
                                          list (V36)
```
FindVar(name,type)(d1/d2)               - Finds a local variable (V36)
Flush(fh)(d1)                           - Flushes buffers for a buffered
```c
                                          filehandle (V36)
```
Format(filesystem,volumename,dostype)(d1/d2/d3)
```c
                                        - Causes a filesystem to
                                          initialize itself (V36)
```
FPutC(fh,ch)(d1/d2)                     - Write a character to the
```c
                                          specified output (buffered) (V36)
```
FPuts(fh,str)(d1/d2)                    - Writes a string the the
```c
                                          specified output (buffered) (V36)
```
FRead(fh,block,blocklen,number)(d1/d2/d3/d4)
```c
                                        - Reads a number of blocks from an
                                          input (buffered) (V36)
```
FreeArgs(args)(d1)                      - Free allocated memory after
```c
                                          ReadArgs() (V36)
```
FreeDeviceProc(dp)(d1)                  - Releases port returned by
```c
                                          GetDeviceProc() (V36)
```
FreeDosEntry(dlist)(d1)                 - Frees an entry created by
```c
                                          MakeDosEntry (V36)
```
FreeDosObject(type,ptr)(d1/d2)          - Frees an object allocated by
```c
                                          AllocDosObject() (V36)
```
FWrite(fh,block,blocklen,number)(d1/d2/d3/d4)
```c
                                        - Writes a number of blocks to an
                                          output (buffered) (V36)
```
GetArgStr()()                           - Returns the arguments for the
```c
                                          process (V36)
```
GetConsoleTask()()                      - Returns the default console for
```c
                                          the process (V36)
```
GetCurrentDirName(buf,len)(d1/d2)       - Returns the current directory
```c
                                          name (V36)
```
GetDeviceProc(name,dp)(d1/d2)           - Finds a handler to send a
```c
                                          message to (V36)
```
GetFileSysTask()()                      - Returns the default filesystem
```c
                                          for the process (V36)
```
GetProgramDir()()                       - Returns a lock on the directory
                                          the program was loaded
GetProgramName(buf,len)(d1/d2)          - Returns the current program name
```c
                                          (V36)
```
GetPrompt(buf,len)(d1/d2)               - Returns the prompt for the
```c
                                          current process (V36)
```
GetVar(name,buffer,size,flags)(d1/d2/d3/d4)
```c
                                        - Returns the value of a local or
                                          global variable (V36)
```
Inhibit(name,onoff)(d1/d2)              - Inhibits access to a filesystem
```c
                                          (V36)
```
InternalLoadSeg(fh,table,funcarray,stack)(d0/a0/a1/a2)
```c
                                        - Low-level load routine (V36)
```
InternalUnLoadSeg(seglist,freefunc)(d1/a1)
```c
                                        - Unloads a seglist loaded with
                                          InternalLoadSeg() (V36)
```
IsFileSystem(name)(d1)                  - Returns whether a Dos handler is
```c
                                          a filesystem (V36)
```
LockDosList(flags)(d1)                  - Locks the specified Dos Lists
```c
                                          for use (V36)
```
LockRecord(fh,offset,length,mode,timeout)(d1/d2/d3/d4/d5)
```c
                                        - Locks a portion of a file (V36)
```
LockRecords(recArray,timeout)(d1/d2)    - Lock a series of records (V36)
MakeDosEntry(name,type)(d1/d2)          - Creates a DosList structure (V36)

MakeLink(name,dest,soft)(d1/d2/d3)      - Creates a filesystem link (V36)
MatchEnd(anchor)(d1)                    - Free storage allocated for
```c
                                          MatchFirst()/MatchNext() (V36)
```
MatchFirst(pat,anchor)(d1/d2)           - Finds file that matches pattern
```c
                                          (V36)
```
MatchNext(anchor)(d1)                   - Finds the next file or directory
```c
                                          that matches pattern (V36)
```
MatchPattern(pat,str)(d1/d2)            - Checks for a pattern match with
```c
                                          a string (V36)
```
MatchPatternNoCase(pat,str)(d1/d2)      - Checks for a pattern match with
```c
                                          a string (V37)
```
MaxCli()()                              - Returns the highest CLI process
```c
                                          number possibly in use (V36)
```
NameFromFH(fh,buffer,len)(d1/d2/d3)     - Get the name of an open
```c
                                          filehandle (V36)
```
NameFromLock(lock,buffer,len)(d1/d2/d3) - Returns the name of a locked
```c
                                          object (V36)
```
NewLoadSeg(file,tags)(d1/d2)            - Improved version of LoadSeg for
```c
                                          stacksizes (V36)
```
NextDosEntry(dlist,flags)(d1/d2)        - Get the next Dos List entry (V36)

OpenFromLock(lock)(d1)                  - Opens a file you have a lock on
```c
                                          (V36)
```
ParentOfFH(fh)(d1)                      - Returns a lock on the parent
```c
                                          directory of a file (V36)
```
ParsePattern(pat,buf,buflen)(d1/d2/d3)  - Create a tokenized string for
```c
                                          MatchPattern() (V36)
```
ParsePatternNoCase(pat,buf,buflen)(d1/d2/d3)
                                        - Create a tokenized string for
PathPart(path)(d1)                      - Returns a pointer to the end of
```c
                                          the next-to-last (V36)
```
PrintFault(code,header)(d1/d2)          - Returns the text associated with
```c
                                          a DOS error code (V36)
```
PutStr(str)(d1)                         - Writes a string the the default
```c
                                          output (buffered) (V36)
```
ReadArgs(template,array,args)(d1/d2/d3) - Parse the command line input
```c
                                          (V36)
```
ReadItem(name,maxchars,cSource)(d1/d2/d3)
```c
                                        - Reads a single argument/name
                                          from command line (V36)
```
ReadLink(port,lock,path,buffer,size)(d1/d2/d3/d4/d5)
```c
                                        - Reads the path for a soft
                                          filesystem link (V36)
```
Relabel(drive,newname)(d1/d2)           - Change the volume name of a
```c
                                          volume (V36)
```
RemAssignList(name,lock)(d1/d2)         - Remove an entry from a multi-dir
```c
                                          assign (V36)
```
RemDosEntry(dlist)(d1)                  - Removes a Dos List entry from
```c
                                          it's list (V36)
```
RemSegment(seg)(d1)                     - Removes a resident segment from
```c
                                          the resident list (V36)
```
ReplyPkt(dp,res1,res2)(d1/d2/d3)        - Replies a packet to the person
```c
                                          who sent it to you (V36)
```
RunCommand(seg,stack,paramptr,paramlen)(d1/d2/d3/d4)
```c
                                        - Runs a program using the current
                                          process (V36)
```
SameDevice(lock1,lock2)(d1/d2)          - Are two locks are on partitions
```c
                                          of the device? (V37)
```
SameLock(lock1,lock2)(d1/d2)            - Returns whether two locks are on
```c
                                          the same object (V36)
```
SelectInput(fh)(d1)                     - Select a filehandle as the
```c
                                          default input channel (V36)
```
SelectOutput(fh)(d1)                    - Select a filehandle as the
```c
                                          default input channel (V36)
```
SendPkt(dp,port,replyport)(d1/d2/d3)    - Sends a packet to a handler (V36)

SetArgStr(string)(d1)                   - Sets the arguments for the
```c
                                          current process (V36)
```
SetConsoleTask(task)(d1)                - Sets the default console for the
```c
                                          process (V36)
```
SetCurrentDirName(name)(d1)             - Sets the directory name for the
```c
                                          process (V36)
```
SetFileDate(name,date)(d1/d2)           - Sets the modification date for a
```c
                                          file or dir (V36)
```
SetFileSize(fh,pos,mode)(d1/d2/d3)      - Sets the size of a file (V36)
SetFileSysTask(task)(d1)                - Sets the default filesystem for
```c
                                          the process (V36)
```
SetIoErr(result)(d1)                    - Sets the value returned by
```c
                                          IoErr() (V36)
```
SetMode(fh,mode)(d1/d2)                 - Set the current behavior of a
```c
                                          handler (V36)
```
SetProgramDir(lock)(d1)                 - Sets the directory returned by
```c
                                          GetProgramDir (V36)
```
SetProgramName(name)(d1)                - Sets the name of the program
```c
                                          being run (V36)
```
SetPrompt(name)(d1)                     - Sets the CLI/shell prompt for
```c
                                          the current process (V36)
```
SetVar(name,buffer,size,flags)(d1/d2/d3/d4)
```c
                                        - Sets a local or environment
                                          variable (V36)
```
SetVBuf(fh,buff,type,size)(d1/d2/d3/d4) - Set buffering modes and size
```c
                                          (V36)
```
SplitName(name,seperator,buf,oldpos,size)(d1/d2/d3/d4/d5)
```c
                                        - Splits out a component of a
                                          pathname into a buffer (V36)
```
StartNotify(notify)(d1)                 - Starts notification on a file or
```c
                                          directory (V36)
```
StrToDate(datetime)(d1)                 - Converts a string to a DateStamp
```c
                                          (V36)
```
StrToLong(string,value)(d1/d2)          - String to long value (decimal)
```c
                                          (V36)
```
SystemTagList(command,tags)(d1/d2)      - Have a shell execute a command
```c
                                          line (V36)
```
UnGetC(fh,character)(d1/d2)             - Makes a char available for
```c
                                          reading again. (buffered) (V36)
```
UnLockDosList(flags)(d1)                - Unlocks the Dos List (V36)
UnLockRecord(fh,offset,length)(d1/d2/d3)- Unlock a record (V36)
UnLockRecords(recArray)(d1)             - Unlock a list of records (V36)
VFPrintf(fh,format,argarray)(d1/d2/d3)  - Format and print a string to a
```c
                                          file (buffered) (V36)
```
VFWritef(fh,format,argarray)(d1/d2/d3)  - Write a BCPL formatted string to
```c
                                          a file (buffered) (V36)
```
VPrintf(format,argarray)(d1/d2)         - Format and print string
```c
                                          (buffered) (V36)
```
WaitPkt()()                             - Waits for a packet to arrive at
```c
                                          your pr_MsgPort (V36)
```
WriteChars(buf,buflen)(d1/d2)           - Writes bytes to the the default

```c
                                          output (buffered) (V36)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [Cli — dos.library](../autodocs/dos.library.md#cli)
- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
- [GetProgramDir — dos.library](../autodocs/dos.library.md#getprogramdir)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [MatchPattern — dos.library](../autodocs/dos.library.md#matchpattern)
- [MaxCli — dos.library](../autodocs/dos.library.md#maxcli)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
