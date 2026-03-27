---
title: dos.library/DeleteFile
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-deletefile-2
functions: []
libraries: []
---

# dos.library/DeleteFile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeleteFile -- Delete a file or directory

    SYNOPSIS
	success = DeleteFile( name )
	D0		      D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) DeleteFile(STRPTR)

    FUNCTION
	This attempts to delete the file or directory specified by 'name'.
	An error is returned if the deletion fails. Note that all the files
	within a directory must be deleted before the directory itself can
	be deleted.

    INPUTS
	name - pointer to a null-terminated string

    RESULTS
	success - boolean


    SEE ALSO
