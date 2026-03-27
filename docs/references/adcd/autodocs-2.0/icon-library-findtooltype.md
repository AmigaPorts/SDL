---
title: icon.library/FindToolType
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-findtooltype
functions: [MatchToolValue]
libraries: [icon.library]
---

# icon.library/FindToolType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindToolType - find the value of a ToolType variable.
SYNOPSIS

```c
    value = FindToolType(toolTypeArray, typeName)
      D0                      A0           A1

    char *FindToolType(char **, char *);
```
FUNCTION

    This function searches a tool type array for a given entry,
    and returns a pointer to that entry.  This is useful for
    finding standard tool type variables.  The returned
    value is not a new copy of the string but is only
    a pointer to the part of the string after typeName.
INPUTS

```c
    toolTypeArray - an array of strings (char **).
    typeName - the name of the tooltype entry (char *).
```
RESULTS

    value - a pointer to a string that is the value bound to typeName,
            or NULL if typeName is not in the toolTypeArray.
EXAMPLE

```c
    Assume the tool type array has two strings in it:
        "FILETYPE=text"
        "TEMPDIR=:t"

    FindToolType( toolTypeArray, "FILETYPE" ) returns "text"
    FindToolType( toolTypeArray, "filetype" ) returns "text"
    FindToolType( toolTypeArray, "TEMPDIR" )  returns ":t"
    FindToolType( toolTypeArray, "MAXSIZE" )  returns NULL
```
SEE ALSO

```c
    [MatchToolValue()](autodocs-2.0/icon-library-matchtoolvalue.md)
```
BUGS

    None

---

## See Also

- [MatchToolValue — icon.library](../autodocs/icon.library.md#matchtoolvalue)
