---
title: Atomic Directory Scanning
manual: amiga-mail
chapter: amiga-mail
section: atomic-directory-scanning
functions: [AllocDosObject, FreeDosObject, ParsePatternNoCase]
libraries: [dos.library]
---

# Atomic Directory Scanning

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The dos.library function ExAll() is a powerful, V37 replacement for the
Examine() and ExNext() functions:


```c
    BOOL ExAll(BPTR mydirlock, UBYTE *mybuffer,
               LONG mybuffersize, LONG mydatatype,
               struct ExAllControl *myexall);
```
ExAll() performs a one pass directory scan on a directory lock (mydirlock
from the prototype above).  ExAll() fills a buffer (mybuffer from the
above prototype) with partial or whole ExAllData structures (from
<dos/exall.h>):


struct ExAllData {
```c
    struct ExAllData *ed_Next; /* Pointer to the next structure */
    UBYTE *ed_Name;		            /* File name */
    LONG  ed_Type;             /* File type */
    ULONG ed_Size;             /* File size */
    ULONG ed_Prot;  /* Protection bits (FIBF_ definitions in <dos/dos.h> */
    ULONG ed_Days;  /* Date in three longwords, forming a DateStamp. */
    ULONG ed_Mins;
    ULONG ed_Ticks;
    UBYTE *ed_Comment;         /* File comment.  Cannot be used */
```
};


ExAll() copies an ExAllData structure into mybuffer for each entry in the
directory.  The size of the ExAllData structure depends on the value in
mydatatype.  The mydatatype parameter can have the following values:

   ED_NAME        - ed_Name - file name
   ED_TYPE        - ed_Type - file type (directory, file, soft link, etc.)
   ED_SIZE        - ed_Size - file size
   ED_PROTECTION  - ed_Prot - file protection bits
   ED_DATE        - ed_Days, ed_Mins, ed_Ticks - file date in long words
   ED_COMMENT     - ed_Comment - file comment (not currently supported).

Each of the possible mydatatype values corresponds to a field (or in the
case of ED_DATE, a set of three fields) in the ExAllData structure.  When
ExAll() writes an ExAllData structure to mybuffer, it writes only the
field that corresponds to mydatatype plus the fields that precede that
datatype in the ExAllData structure.  For example, if mydatatype is
ED_SIZE, ExAll() would write ed_Next, ed_Type, and ed_Size to the buffer,
ignoring the fields that follow ed_Size in the the ExAllData structure.

The ExAllData structures in mybuffer are organized into a linked list.
The ExAllData structure's ed_Next field either points to the next
directory entry's ExAllData structure or is NULL if no directory entries
follow. Applications should only access the ExAllData structures using
this link list.

As ExAll() scans a directory, it copies partial or whole ExAllData
structure into mybuffer until it either runs out of directory entries or
until it runs out of room in mybuffer.  If ExAll() runs out of room, it
will return a non-zero value, indicating that your application needs to
perform more passes to finish scanning the directory.

To keep track of everything, ExAll() uses an application-supplied
structure called ExAllControl (from <dos/exall.h>):


struct ExAllControl {
```c
    ULONG eac_Entries; /* The number of entries returned in the buffer */
    ULONG eac_LastKey; /* Used to keep track of position in directory. */
```
		       /* Do not change this value! */
```c
    UBYTE *eac_MatchString; /* Optional parsed pattern for pattern match */
    struct Hook *eac_MatchFunc;
               /* Optional application hook to be called for each entry */
```
	       /* Can be used to individually allow entries in the      */
               /*  buffer or not                                        */
};


The ExAllControl structure must be allocated and freed using
AllocDosObject() and FreeDosObject():


```c
    myexallcontrol = AllocDosObject(DOS_EXALLCONTROL, NULL);
    FreeDosObject(DOS_EXALLCONTROL, myexallcontrol);
```
The ExAllControl structure's eac_Entries field contains the number of
directory entries that ExAll() wrote into mybuffer.  The eac_LastKey field
is used by the file system to keep track of its place in the directory.
An application must set this field to zero before calling ExAll() and must
not make any changes to this field between scans of a directory.

The eac_MatchString field is used to pattern match the names of directory
entries using the standard AmigaDOS pattern matching functions (for more
on AmigaDOS pattern matching see the article ``Using the AmigaDOS Pattern
Matching Functions'' in the September/October issue of Amiga Mail.  If
eac_MatchString is not NULL, ExAll() will only create ExAllData structures
for the directory entries whose names match the matching string.  Note
that this matching string must have been parsed by ParsePatternNoCase().
If eac_MatchString is NULL, ExAll() will not perform any pattern matching.

The eac_MatchFunc field points to an application-supplied hook function.
If this hook is not NULL, ExAll() will call the hook function.  If the
hook function returns TRUE, ExAll() will copy an ExAllData structure for
this directory entry into mybuffer.  The hook is called in the following
manner:


```c
    BOOL = MatchFunc(hookptr, exalldata, typeptr)
                       A0        A1         A2
```
where:

hookptr is a pointer to the hook being called exalldata is a pointer to
the exalldata structure of the current directory entry typeptr is a
pointer to a longword indicating the type of the ExAllData structure
(mydatatype from the ExAll() prototype above).

By supplying a hook, each entry in the directory can be accepted or
rejected according to your applications needs.  An application can use
both the matching string and MatchFunc() to perform AmigaDOS pattern
matching and custom matching on directory entries.

The code example [ListDir.c](amiga-mail/ii-49-listdir-c.md) at the end of this article is a simple example
of how to use ExAll().  The example [ListDir2.c](amiga-mail/ii-49-listdir2-c.md) is a more complicated
example that uses pattern matching and a hook function.

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [ParsePatternNoCase — dos.library](../autodocs/dos.library.md#parsepatternnocase)
