---
title: A Directory Requester
manual: amiga-mail
chapter: amiga-mail
section: a-directory-requester
functions: [AslRequest]
libraries: [asl.library]
---

# A Directory Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A program may not need to process files in a requester, only the
directories.  There is another variation on asl.library's file requester
that allows this.  A new tag, ASL_ExtFlags1, toggles this option.
ASL_ExtFlags1 passes a bit field like ASL_FuncFlags.  One of
ASL_ExtFlags1's flags, FIL1F_NOFILES, sets up a requester that has no
string gadget for files and displays only directory names in the
requester's scrolling list.  When AslRequest() (or AslRequestTags() )
returns successfully, the FileRequester structure's rf__Dir field contains
the name of the directory the user selected.

Currently, there is another flag defined for ASL_ExtFlags1,
FIL1F_MATCHDIRS.  If file pattern matching is on (see the FILF_PATGAD flag
for ASL_FuncFlags), setting FIL1F_MATCHDIRS tells the file requester to
pattern match directory names as well as file names.  Of course, if both
of ASL_ExtFlags1's flags are set, the requester will only pattern match
directory names.

---

## See Also

- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
