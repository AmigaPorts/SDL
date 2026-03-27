---
title: Opening a Simple File Requester
manual: amiga-mail
chapter: amiga-mail
section: opening-a-simple-file-requester
functions: [AllocAslRequest, AllocFileRequest, AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# Opening a Simple File Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Using an ASL requester requires the use of three functions:


myrequester = APTR AllocAslRequest( ULONG type, struct TagItem *tagList );

```c
              void FreeAslRequest( APTR request );
```
made_selection = BOOL AslRequest( APTR request, struct TagItem *tagList );


An ASL requester is based on a FileRequester or a FontRequester structure.
Programs must allocate this structure with AllocAslRequest() (or
AllocFileRequest()see the asl.library Autodoc for more on this function).
Currently, the type field (from the above prototype) can be one of two
values (as defined in <libraries/asl.h> ), ASL_FileRequest, to ask for a
FileRequester structure, or ASL_FontRequest, to ask for a FontRequester
structure.  The values in this structure are for read access only.  Any
changes to them are carried out through asl.library function calls.  The
FreeAslRequest() function deallocates an ASL requester structure.


struct FileRequester    {   /* (from <libraries/asl.h>) */


```c
        APTR    rf_Reserved1;
        BYTE    *rf_File;       /* Filename pointer             */
        BYTE    *rf_Dir;        /* Directory name pointer       */
        CPTR    rf_Reserved2;
        UBYTE   rf_Reserved3;
        UBYTE   rf_Reserved4;
        APTR    rf_Reserved5;
        WORD    rf_LeftEdge,rf_TopEdge; /* Preferred window pos */
        WORD    rf_Width,rf_Height;   /* Preferred window size  */
        WORD    rf_Reserved6;
        LONG    rf_NumArgs;     /* A-la WB Args, for multiselects */
        struct WBArg *rf_ArgList;
        APTR    rf_UserData;    /* Applihandle (you may write!!) */
        APTR    rf_Reserved7;
        APTR    rf_Reserved8;
        BYTE    *rf_Pat;        /* Pattern match pointer */
        };                      /* note - more reserved fields follow */
```
Based on the requester structure passed to it, AslRequest() brings up a
font or file requester.  When the user makes a selection, AslRequest
returns a value.  If it returns anything but FALSE (0), the user selected
a file (or a font).  AslRequest() returns FALSE if the user cancels the
requester or the requester failed for some reason.

Both AslRequest() and AllocAslRequest() accept a tag list.  This tag list
is used to set the values in the FileRequester (or FontRequester)
structure.  The C code example [SimpleFR.c](amiga-mail/i-7-simplefr-c.md) at the end of this article uses
the following  tags (all the ASL tags are defined in <libraries/asl.h>):


    ASL_Hail
    ASL_Width
    ASL_Height
    ASL_LeftEdge
    ASL_TopEdge
    ASL_OKText
    ASL_CancelText
    ASL_File
    ASL_Dir
ASL_Hail supplies a requester with a string to placed in the title bar of
the requester window.  ASL_Width, _Height, _LeftEdge, and _TopEdge
describe the initial dimensions and position of the requester window.
ASL_OKText and ASL_CancelText provide alternate strings for the ``OK'' and
``Cancel'' gadgets.  Currently, the size of these gadgets limits the
length of the names to about six characters.  The two remaining tags from
the above list, ASL_File and ASL_Dir, tags are specific to file
requesters.  They supply the initial file and directory names for the file
requester.

For a file requester, if AslRequest() returns anything but FALSE,
[SimpleFR.c](amiga-mail/i-7-simplefr-c.md) looks at the FileRequester's rf_File and rf_Dir fields to get
the name and directory of the file the user selected.  Note that the
requester allows the user to type in a name for the file and directory,
which makes it possible for a file requester to return a file and
directory that do not (currently) exist.  In the case of a save requester
(discussed a little later), the requester can create that non-existent
directory.

   [Figure 1 - The SimpleFR.c file requester](amiga-mail/i-7-simplefr-ilbm.md) 

The [simpleFR.c](amiga-mail/i-7-simplefr-c.md) example (and the rest of the ASL examples for that matter)
may be a little misleading because it only uses the requester once.  Any
application that needs a requester should allocate the requester only once
and pop up that requester every time the application needs one.  If
instead, the application allocated, used, and deallocated a requester each
time it needed one, all of the settings the user left in the requester
(like the names the user last typed into the drawer or file string
gadgets) would be reset to their initial values.  By reusing a requester,
the values stored in it are preserved.

Although retaining previous requester values from one request to another
preserves user preferences, it also preserves other values stored in the
requester structure.  The file and font requester structures contain many
private fields that toggle various features of the ASL requesters (those
features are set via tags).  If a program sets up a file requester with a
specific feature, after the requester returns, the file requester
structure is still set up with the specific feature.  The next time the
application wants to use that file requester without that specific
feature, it must explicitly turn that feature off in the subsequent
AslRequest() call.

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
