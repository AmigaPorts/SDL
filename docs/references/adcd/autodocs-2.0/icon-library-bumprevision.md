---
title: icon.library/BumpRevision
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-bumprevision
functions: []
libraries: []
---

# icon.library/BumpRevision

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BumpRevision - reformat a name for a second copy.
SYNOPSIS

```c
    result = BumpRevision(newbuf, oldname)
      D0                    A0      A1

    char *BumpRevision(char *, char *);
```
FUNCTION

```c
    BumpRevision takes a name and turns it into a "copy_of_name".
    It knows how to deal with copies of copies.  The routine
    will truncate the new name to the maximum dos name size
    (currently 30 characters).
```
INPUTS

```c
    newbuf - the new buffer that will receive the name
             (it must be at least 31 characters long).
    oldname - the original name
```
RESULTS

    result - a pointer to newbuf
EXAMPLE

    oldname                          newbuf
    -------                          ------
    "foo"                            "copy_of_foo"
    "copy_of_foo"                    "copy_2_of_foo"
    "copy_2_of_foo"                  "copy_3_of_foo"
    "copy_199_of_foo"                "copy_200_of_foo"
    "copy foo"                       "copy_of_copy foo"
    "copy_0_of_foo"                  "copy_1_of_foo"
    "012345678901234567890123456789" "copy_of_0123456789012345678901"
SEE ALSO

BUGS

    None
