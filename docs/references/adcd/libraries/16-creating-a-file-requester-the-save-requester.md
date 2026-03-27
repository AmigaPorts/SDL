---
title: 16 / Creating a File Requester / The Save Requester
manual: libraries
chapter: libraries
section: 16-creating-a-file-requester-the-save-requester
functions: [AslRequest]
libraries: [asl.library]
---

# 16 / Creating a File Requester / The Save Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The save requester is a special type of file requester used for save
operations.  It differs from the regular ASL file requester in several
ways.  First, the color of the text making up the file names and the
background color are interchanged.  This makes it more apparent to the
user that they are looking at a save requester (instead of the usual load
requester).

Another difference, is that a save requester does not allow the user to
select an existing file name by double-clicking on an entry in the
scrolling list gadget.  This helps prevent the user from accidentally
overwriting the wrong file.

Save requesters can also create directories.  If the user types a
directory name into the save requester and the directory doesn't exist,
the save requester will create that directory (after getting the user's
permission via another requester).

To create a save requester, set the [FILF_SAVE](libraries/16-file-pattern-matching-and-multiple-selects.md) flag of the ASL_FuncFlags
tag. Remember that ASL tags and flag values are preserved across calls to
[AslRequest()](libraries/16-asl-library-creating-a-file-requester.md), so if you use a save requester, you must clear the FILF_SAVE
bit and reset your ASL_FuncFlags when you want a load requester. Note that
it does not make sense to have multiselection in a save requester, so the
FILF_SAVE flag overrides the [FILF_MULTISELECT](libraries/16-file-pattern-matching-and-multiple-selects.md) flag.

---

## See Also

- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
