---
title: 16 / Creating a File Requester / The Directory Requester
manual: libraries
chapter: libraries
section: 16-creating-a-file-requester-the-directory-requester
functions: [AslRequest]
libraries: [asl.library]
---

# 16 / Creating a File Requester / The Directory Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sometimes a program may only require a directory name from the user. There
is another variation on asl.library's file requester that allows this.
The ASL_ExtFlags1 tag contains a flag bit to toggle this option. If the
FIL1F_NOFILES flag of ASL_ExtFlags1 is set, the requester will appear
without a string gadget for file names and will display only directory
names in the scrolling list gadget. When [AslRequest()](libraries/16-asl-library-creating-a-file-requester.md) (or [AslRequestTags()](libraries/16-file-pattern-matching-and-multiple-selects.md)
) returns successfully, the rf_Dir field of the [FileRequester](libraries/16-asl-library-creating-a-file-requester.md) structure
contains the name of the directory the user selected.

Another flag defined for ASL_ExtFlags1 is FIL1F_MATCHDIRS. If file pattern
matching is on (see the [FILF_PATGAD](libraries/16-file-pattern-matching-and-multiple-selects.md) flag for ASL_FuncFlags, setting
FIL1F_MATCHDIRS tells the file requester to pattern match directory names
as well as file names.  Of course, if both of these ASL_ExtFlags1 flags
are set, the requester will only pattern match directory names.

---

## See Also

- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
