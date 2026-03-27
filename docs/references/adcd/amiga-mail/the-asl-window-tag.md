---
title: The ASL_Window Tag
manual: amiga-mail
chapter: amiga-mail
section: the-asl-window-tag
functions: []
libraries: []
---

# The ASL_Window Tag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application that uses a custom screen normally wants its requesters to
open on its screen.  Using the ASL_Window tag, a program can associate a
requester with a window so the requester appears on the window's screen.
The ASL_Window tag is followed by a pointer to a window structure.
ASL_Window works with both file and font requesters.

Normally, a requester associated with a window (using ASL_Window) uses the
window's IDCMP port for its communication.  An application may not want to
share an IDCMP port with the requester.  Using the ASL_FuncFlags tag, a
program can ask for a requester that creates its own IDCMP port.  There
are two flags that accomplish this.  The first, FILF_NEWIDCMP, is used on
file requesters.   The other, FONF_NEWIDCMP, is used on font requesters.

