---
title: II-49: Directory Scanning
manual: amiga-mail
chapter: amiga-mail
section: ii-49-directory-scanning
functions: []
libraries: []
---

# II-49: Directory Scanning

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Ewout Walraven


Prior to release 2.0, examining the contents of directories using
dos.library required the use of two functions: Examine() and ExNext().
Although these routines perform the task for which they were intended,
they have limitations.  One is that these functions require stepping
through a directory one entry at a time.  For most applications that need
to do directory scanning, it would more efficient to scan a directory in
one pass rather than many.  This would significantly reduce the time spent
scanning. Also, these functions don't know anything about the AmigaDOS
wildcards, so any wildcard processing must be done by the application, not
by the OS.

 [Atomic Directory Scanning](amiga-mail/atomic-directory-scanning.md) 
 [MultiDirectory Assigns](amiga-mail/multidirectory-assigns.md) 
 [Filename Matching](amiga-mail/filename-matching.md) 

