---
title: 14 / Workbench Environment / WBStartup Message
manual: libraries
chapter: libraries
section: 14-workbench-environment-wbstartup-message
functions: [LoadSeg, UnLock]
libraries: [dos.library]
---

# 14 / Workbench Environment / WBStartup Message

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When Workbench loads and starts a program, its sends the program a
WBStartup message containing the arguments as summarized above.  Normally,
the startup code supplied with your compiler will place a pointer to
WBStartup in argv for you, set argc to zero and call your program.

The WBStartup message, whose structure is outlined in
<workbench/[startup.h](autodocs-2.0/includes-workbench-startup-h.md)>, has the following structure elements:


```c
    struct WBStartup
    {
        struct Message   sm_Message;    /* a standard message structure */
        struct MsgPort * sm_Process;    /* process descriptor for you */
        BPTR             sm_Segment;    /* a descriptor for your code */
        LONG             sm_NumArgs;    /* number of elements in ArgList */
        char *           sm_ToolWindow; /* reserved for future use */
        struct WBArg *   sm_ArgList;    /* the arguments themselves */
    };
```
The fields of the WBStartup structure are used as follows.


```c
    sm_Message
        A standard Exec message.  The reply port is set to the Workbench.

    sm_Process
        The process descriptor for the tool (as returned by
        [CreateProc()](autodocs-2.0/dos-library-createproc.md))

    sm_Segment
        The loaded code for the tool (returned by [LoadSeg()](autodocs-2.0/dos-library-loadseg.md))

    sm_NumArgs
        The number of arguments in sm_ArgList

    sm_ToolWindow
        Reserved (not currently passed in startup message)

    sm_ArgList
        This is the argument list itself.  It is a pointer to an array
        of WBArg structures with sm_NumArgs elements.
```
Workbench arguments are passed as an array of [WBArg](autodocs-2.0/includes-workbench-startup-h.md) structures in the
sm_ArgList field of WBStartup.  The first WBArg in the list is always the
tool itself.  If multiple icons have been selected when a tool is
activated, the selected icons are passed to the tool as additional WBArgs.
If the tool was derived from a default tool, the project will be the
second WBArg.  If extended select was used, arguments other than the tool
are passed in the order of selection; the first icon selected will be
first (after the tool), and so on.

Each argument is a struct [WBArg](autodocs-2.0/includes-workbench-startup-h.md) and has two parts:  wa_Name and wa_Lock.


```c
    struct WBArg
    {
        BPTR      wa_Lock;    /* a lock descriptor */
        BYTE *    wa_Name;    /* a string relative to that lock */
    };
```
The wa_Name element is the name of an AmigaDOS filing system object.  The
wa_Name field of the first WBArg is always the name of your program and
the wa_Lock field is an AmigaDOS Lock on the directory where your program
is stored.

If your program was started by activating a project icon, then you get a
second WBarg with the wa_Name field containing the file name of the
project and the wa_Lock containing an AmigaDOS Lock on the directory where
the project file is stored.

If your program was started through extended select, then you get one
WBArg for each icon in the selected group in the order they were selected.
The wa_Name field contains the file name corresponding to each icon unless
the icon is for a directory, disk, or the Trashcan in which case the
wa_Name is set to NULL.  The wa_Lock field contains an AmigaDOS Lock on
the directory where the file is stored.  (For disk or drawer icons the
wa_Lock is a lock on the directory represented by the icon.  Or, wa_Lock
may be NULL if the icon type does not support locks.)


```c
    Workbench Locks Belong to Workbench.
    ------------------------------------
    You must never call [UnLock()](autodocs-2.0/dos-library-unlock.md) on a wa_Lock.  These locks belong to
    Workbench, and Workbench will UnLock() them when the WBStartup
    message is replied by your startup code.  You must also never
    UnLock() your program's initial current directory lock (i.e., the
    lock returned by an initial [CurrentDir()](autodocs-2.0/dos-library-currentdir.md) call).  The classic symptom
    caused by unlocking Workbench locks is a system hang after your
    program exits, even though the same program exits with no problems
    when started from the Shell.

    You should save the lock returned from an initial [CurrentDir()](autodocs-2.0/dos-library-currentdir.md), and
    CurrentDir() back to it before exiting.  In the Workbench
    environment, depending on your startup code, the current directory
    will generally be set to one of the wa_Locks.  By using
    CurrentDir(wa_Lock) and then referencing wa_Name, you can find, read,
    and modify the files that have been passed to your program as WBArgs.
```

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
