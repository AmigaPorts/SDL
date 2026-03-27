---
title: 14 / The Icon Library / The Tool Types Array
manual: libraries
chapter: libraries
section: 14-the-icon-library-the-tool-types-array
functions: [FindToolType, MatchToolValue]
libraries: [icon.library]
---

# 14 / The Icon Library / The Tool Types Array

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Earlier sections discussed how Workbench passes filenames as arguments to
a program that's about to run.  Workbench also allows other types of
arguments to be passed in the Tool Types array of an icon. The Tool Types
array is found in the [do_ToolTypes](libraries/14-icon-library-data-structures-the-diskobject-structure.md) field of the icon's [DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md)
structure.

In brief, Tool Types is an array of pointers to strings that contain any
information an application wants to store such as the program options that
were in effect when the icon was created.  These strings can be used to
encode information which will be available to all applications that read
the icon's [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file.  Users can enter and change a selected icon's Tool
Types by choosing Information in the Workbench Icons menu.

Workbench does not place many restrictions on the Tool Types array, but
there are a few conventions you should follow.  A string may be no more
than 128 bytes long.  The alphabet used is 8-bit ANSI (for example, normal
ASCII with foreign-language extensions).  This means that users may enter
Tool Type strings containing international characters.  Avoid special or
nonprinting characters.  The case of the characters is currently
significant, so the string "Window" is not equal to "WINDOW".

The general format for a Tool Types entry is <name>=<value>[|<value>],
where <name> is the field name and <value> is the text to associate with
that name.  Multiple values for one name may be separated by a vertical
bar.  The values may be the type of the file, programs that can access the
data, parameters to be passed to an application, etc.  For example, a
paint program might set:


```c
         FILETYPE = PaintProgram | ILBM
```
This Tool Type indicates that the file is an ILBM, perhaps with some
additional chunks of data specific to PaintProgram.

Tool Type strings have few restrictions but there are some reserved Tool
Types that are parsed by Workbench itself when an application is started
from an icon.  The reserved Tool Types are TOOLPRI=n (sets the Exec task
priority at which Workbench will start the application), STARTPRI=n (sets
the starting order for icons in the Wbstartup drawer), and DONOTWAIT
(tells Workbench not to wait for the return of a program started via an
icon in the Wbstartup drawer).  In addition to the reserved Tool Types,
which applications should not use, there are standard Tool Types, which
applications should use only in the standard way.  For a list of standard
Tool Types refer to the Amiga User Interface Style Guide.

Two routines are provided to help you deal with the Tool Types array.
[FindToolType()](autodocs-2.0/icon-library-findtooltype.md) returns the value of a Tool Type element.  Using the above
example, if you are looking for FILETYPE, the string "PaintProgram|ILBM"
will be returned.  [MatchToolValue()](autodocs-2.0/icon-library-matchtoolvalue.md) returns nonzero if the specified
string is in the reference value string.  This routine knows how to parse
vertical bars.  For example, using the reference value strings of
"PaintProgram" or "ILBM", MatchToolValue() will return TRUE for "ILBM" and
"PaintProgram" and FALSE for everything else.

---

## See Also

- [FindToolType — icon.library](../autodocs/icon.library.md#findtooltype)
- [MatchToolValue — icon.library](../autodocs/icon.library.md#matchtoolvalue)
