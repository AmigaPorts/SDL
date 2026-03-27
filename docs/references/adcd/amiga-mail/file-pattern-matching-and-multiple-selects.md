---
title: File Pattern Matching and Multiple Selects
manual: amiga-mail
chapter: amiga-mail
section: file-pattern-matching-and-multiple-selects
functions: [AllocAslRequest]
libraries: [asl.library]
---

# File Pattern Matching and Multiple Selects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A file requester can filter out certain file and directory entries using
dos.library's ``wildcarding''.  Turning on a file requester's
``wildcarding'' requires using the ASL_FuncFlags tag.  This tag passes a
bit field to a requester to set several options.  The options are specific
to the type of requester (file or font).  The bitmasks are defined in
<libraries/asl.h>.

The ASL_FuncFlags's FILF_PATGAD flag toggles the file requester's
``Pattern'' gadget.  The user can type an AmigaDOS wildcard pattern into
this gadget that the requester uses to limit the file names that appear in
the requester.  An application can supply the ``Pattern'' gadget with a
default pattern matching string using the ASL_Pattern tag.

Another feature of the ASL file requester is multiple selection.  When an
application sets up a file requester, it can set the FILF_MULTISELECT flag
in the ASL_FuncFlags tag that allows the user to select several files at
once.

When the user selects several files in the requester, the FileRequester's
rf_NumArgs field contains the number of files selected.  When the
FILF_MULTISELECT bit is not set, rf_NumArgs is 0.  If rf_NumArgs is not
zero, rf_ArgList is a base pointer to an array of WBArg structures
(defined in <workbench/startup.h>).  There is a WBArg structure for each
file the user selected.

The example [FilePat.c](amiga-mail/i-7-filepat-c.md) illustrates multiple selection.

[FilePat.c](amiga-mail/i-7-filepat-c.md) also introduces a new function and a new tag.


```c
    APTR AllocAslRequestTags( unsigned long type, Tag Tag1, ... );
    BOOL AslRequestTags( APTR request, Tag Tag1, ... );
```
[FilePat.c](amiga-mail/i-7-filepat-c.md) uses AllocAslRequestTags() instead of AllocAslRequest() to
allocate and set up the file requester.  AllocAslRequestTags() is an
Amiga.lib function that accepts tag pairs in its parameter list, rather
than a pointer to a tag list.  AslRequestTags() also accepts tag pairs.

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
