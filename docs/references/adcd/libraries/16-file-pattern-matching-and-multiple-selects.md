---
title: 16 / / File Pattern Matching and Multiple Selects
manual: libraries
chapter: libraries
section: 16-file-pattern-matching-and-multiple-selects
functions: [AllocAslRequest, AslRequest]
libraries: [asl.library]
---

# 16 / / File Pattern Matching and Multiple Selects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A file requester can filter out certain file and directory entries using
the "wildcard" feature of  AmigaDOS.  To activate the wildcard feature for
a file requester, you use the ASL_FuncFlags tag.  Each bit in the
ASL_FuncFlags tag item controls a special option of the requester
depending on its type (file or font).  See <libraries/[asl.h](autodocs-2.0/includes-libraries-asl-h.md)> for a
complete listing of the options that the ASL_FuncFlags tag controls.


 File Requester Flag  Used For
 -------------------  --------
  FILF_PATGAD         Enables the file name pattern matching gadget
  FILF_MULTISELECT    Enables multiple selection of files
  FILF_NEWIDCMP       Use separate IDCMP for requester sharing a custom
```c
                      screen ([see below](libraries/16-creating-a-file-requester-asl-requesters-and-custom.md))
```
  FILF_SAVE           Makes the file requester a save requester ([see below](libraries/16-creating-a-file-requester-the-save-requester.md))


If the FILF_PATGAD bit of the ASL_FuncFlags tag is set, the file requester
will appear with a "Pattern" gadget in addition to the usual file name and
directory name gadgets.  The user can type an AmigaDOS wildcard pattern
into this gadget and the pattern will be used to limit the file names that
appear in the requester.  An application can also supply a default pattern
using the ASL_Pattern tag item. A hidden unchangeable pattern can be
created by supplying an ASL_Pattern without a FILF_PATGAD gadget. Such
invisible patterns should not be used if there is any reason that the user
may need to access a file which does not match the pattern.

Another feature of the ASL file requester is multiple selection.  When
multiple selection is enabled, the user can choose more than one file name
in a single directory by selecting names in the requester's scrolling list
gadget with the mouse.  This option, like pattern matching, is set up with
the ASL_FuncFlags tag.

If the FILF_MULTISELECT bit of the ASL_FuncFlags tag is set, the file
requester will allow multiple selection.  When the user selects several
file names through the multiple selection feature, the [FileRequester](libraries/16-asl-library-creating-a-file-requester.md)'s
rf_NumArgs field contains the number of files selected and the rf_ArgList
field contains a pointer to an array of [WBArg](libraries/14-workbench-environment-wbstartup-message.md) structures (defined in
<workbench/[startup.h](autodocs-2.0/includes-workbench-startup-h.md)>).  There is a WBArg structure containing a file name
for each file the user selected.

The following example illustrates a file requester with both a pattern
matching gadget and multiple selection enabled.


```c
     [filepat.c](libraries/lib-examples-filepat-c.md) 
```
The previous example demonstrates two alternate functions for creating and
using ASL requesters:


```c
    APTR AllocAslRequestTags( unsigned long type, Tag Tag1, ... );
    BOOL AslRequestTags( APTR request, Tag Tag1, ... );
```
[AllocAslRequestTags()](autodocs-2.0/asl-library-allocaslrequest.md) can be used instead of [AllocAslRequest()](libraries/16-asl-library-creating-a-file-requester.md) to allocate
and set up the file requester.  This is an amiga.lib function that will
accept [TagItem](libraries/37-tags-tag-functions-and-structures.md)s directly in its parameter list, rather than a pointer to
an array of TagItems.

Similarly, [AslRequestTags()](autodocs-2.0/asl-library-aslrequest.md) will accept [TagItem](libraries/37-tags-tag-functions-and-structures.md)s directly instead of
requiring a pointer to an array of TagItems as [AslRequest()](libraries/16-asl-library-creating-a-file-requester.md) does.

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
