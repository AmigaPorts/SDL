---
title: dos.library/DeleteFile
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-deletefile
functions: []
libraries: []
---

# dos.library/DeleteFile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DeleteFile -- Delete a file or directory
SYNOPSIS

```c
    success = DeleteFile( name )
    D0                    D1

    BOOL DeleteFile(STRPTR)
```
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

