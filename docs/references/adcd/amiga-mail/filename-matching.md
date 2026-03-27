---
title: Filename Matching
manual: amiga-mail
chapter: amiga-mail
section: filename-matching
functions: [MatchEnd, MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# Filename Matching

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The release 2.0 dos.library introduced several other functions for
directory scanning:


```c
    LONG MatchFirst(UBYTE *mypattern, struct AnchorPath *myanchorpath);
    LONG MatchNext(struct AnchorPath *myanchorpath);
    VOID MatchEnd(struct AnchorPath *myanchorpath);
```
When using these functions, an application first calls MatchFirst(), which
performs some initialization (like calling ParsePattern() on the pattern
matching string, mypattern) and finds the first directory entry that
matches the directory entry mypattern.  This pattern is relative to the
current directory.   An application must use the the MatchNext() call to
find subsequent matching directory entries.  After the application is done
looking for matches or the application encounters an error, it must call
MatchEnd() to release internal buffers.

Before using these functions, you need to set up an AnchorPath structure.
This structure must be initialized by MatchFirst() and passed to
MatchNext() and MatchEnd() so they can keep track of the directory scan.
An application must not make any changes to this structure while in the
middle of a directory scan (before calling MatchEnd()).  This AnchorPath
structure must be longword aligned and is defined in <dos/dosasl.h> as
follows:


struct AnchorPath {
```c
    struct AChain   *ap_Base;  /* Pointer to the first anchor */
```
#define ap_First ap_Base       /* Compatibility synonym. Don't use */
```c
    struct AChain   *ap_Last;  /* Pointer to the last anchor */
```
#define ap_Current ap_Last     /* Compatiblity synomym. Don't use */
```c
    LONG    ap_BreakBits;      /* Bit flags to stop scanning */
    LONG    ap_FoundBreak;     /* Bits flags which caused the stop */
    BYTE    ap_Flags;          /* Behaviour flags */
    BYTE    ap_Reserved;       /* Reserved for now */
    WORD    ap_Strlen;         /* Buffer size for path name */
                               /* This used to be ap_Length  */
```
#define ap_Length ap_Flags     /* Compatibility for LONGWORD ap_Length */
```c
                               /* Don't use */
    struct  FileInfoBlock ap_Info;  /* FileInfoBlock for matched entry */
    UBYTE   ap_Buf[1];         /* Application allocated buffer for full */
                               /* path name*/
```
};


If your application does not need a full path name to matching directory
entries, it should initialize the ap_Strlen field to zero.  In this case,
your application can get what it needs from the AnchorPath's ap_Info
field. It can also get a lock on the directory from ap_Current->an_Lock
field.  If your application needs the full path name of matching directory
entries, it must allocate a buffer at the end of the AnchorPath structure
and put the size of the buffer, in bytes, into ap_Strlen.

The ap_BreakBits field allows the user to abort a directory scan in
progress.  The bits in this field correspond to the SIGBREAKF_ bits
defined in <dos/dos.h>.  If the corresponding bit is set in ap_BreakBits,
MatchFirst() or MatchNext() will stop a scan in progress if one of those
signals occurs.  If this occurs, the bit of the signal that caused the
break will be set in ap_FoundBreak.

With this information alone it is possible to perform simple file pattern
matching.  As previously mentioned, the first match must be found with
MatchFirst().  If MatchFirst() (or MatchNext()) cannot find a match or it
encounters an error, it returns an error number, otherwise it returns a
zero (which is unusual for a dos.library function).  If MatchFirst() does
not encounter any problems, the application should look for subsequent
matches by calling MatchNext().  The application should call MatchNext()
until it returns an AmigaDOS error value.  MatchNext() accepts a pointer
to the AnchorPath structure initialized by MatchFirst().

Normally, the error that MatchNext() returns is ERROR_NO_MORE_ENTRIES,
indicating that there are no more directory entries that match mypattern.
MatchEnd() is used to release any resources that were allocated in the
scanning process.  Due to a number of bugs in the V36 implementation,
these functions should only be used as of V37.  [ListPattern.c](amiga-mail/ii-49-listpattern-c.md) is a simple
example of using MatchFirst()/MatchNext().

For more complex matching, the ap_Flags field can be used to define the
behavior of MatchFirst() and MatchNext().  Currently, there are several
flags defined:


    APF_ITSWILD
    APF_DODIR
    APF_DIDDIR
    APF_NOMEMERR
    APF_DirChanged
    APF_FollowHLinks
The APF_ITSWILD flag will be set if a wildcard was present in the pattern
after the call to MatchFirst().  It will be used to instruct MatchNext()
but your application can check it too and perform an action depending on
its status.

The APF_DODIR flag instructs MatchFirst/Next() to enter a directory if it
encounters one.  This flag can be set and reset on an individual basis.
Once MatchNext() is finished processing a directory, it will set the
APF_DIDDIR bit and will change the AnchorPath's directory back to the
parent directory.

APF_NOMEMERR indicates that MatchFirst/Next() encountered a fatal out of
memory error.  Processing the directory should be aborted and an error
returned to the user.

The APF_DirChanged flag indicates that MatchNext() noticed that directory
lock has changed since the previous MatchNext() call.

The APF_FollowHLinks flag tells MatchFirst/MatchNext() to follow hard link
directories if the APF_DODIR bit is set.  This feature is in place to
avoid confusing applications that do not know anything about hard links.

Most existing versions of the 2.0 include file <dos/dosasl.h> mention two
other flags, APF_DOWILD and APF_DODOT.  These are not currently in use by
the system.

The [DirComp.c](amiga-mail/ii-49-dircomp-c.md) example is a more complex example of using
MatchFirst()/Next().  It takes a path, which may include wildcards, and
compares the directory entries it finds with those in the target
directory. If the user specifies the DATE keyword, DirComp will also
compare the datestamps.  The ALL keyword tells DirComp to do a recursive
scan.  For deeply nested directories the BUFFER keyword can enlarge the
buffer that DirComp uses from its standard 256 bytes up to 4096 bytes
(calling it the ``Joanne'' keyword might be more appropriate).

---

## See Also

- [MatchEnd — dos.library](../autodocs/dos.library.md#matchend)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
