---
title: The Save Requester
manual: amiga-mail
chapter: amiga-mail
section: the-save-requester
functions: []
libraries: []
---

# The Save Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Save requester is a special type of file requester.  The release 2.0
save requester differs from the regular file requester in several ways.
The first is its appearance.  The color of the text making up the file
name list and the color of the backround the text is rendered on are
swapped for the save requester.  This makes the difference between the
save and file requesters visual as well as functional.  Another
difference, is that a save requester does not allow the user to select by
double-clicking on a file name.  This prevents the user from accidentally
double-clicking, and thus over-writing, the wrong file.  The other
difference is that if the user types a directory name into the save
requester and the directory doesn't exist, the save requester will create
that directory (after getting the user's permission via another requester).

The FILF_SAVE flag from the ASL_FuncFlags tag creates a save requester.
Note that it does not make sense to have multiple selection in a save
requester, so the FILF_SAVE flag overrides the FILF_MULTISELECT flag.

