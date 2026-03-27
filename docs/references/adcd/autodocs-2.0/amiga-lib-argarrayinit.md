---
title: amiga.lib/ArgArrayInit
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-argarrayinit
functions: [FindToolType, GetDiskObject]
libraries: [icon.library]
---

# amiga.lib/ArgArrayInit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ArgArrayInit -- allocate and initialize a tooltype array. (V36)
```
SYNOPSIS

```c
    ttypes = ArgArrayInit(argc,argv);

    UBYTE **ArgArrayInit(LONG,UBYTE **);
```
FUNCTION

```c
    This function returns a null-terminated array of strings
    suitable for sending to [icon.library/FindToolType()](autodocs-2.0/icon-library-findtooltype.md). This array will
    be the ToolTypes array of the program's icon, if it was started from
    Workbench. It will just be 'argv' if the program was started from
    a shell.

    Pass ArgArrayInit() your startup arguments received by main().

    ArgArrayInit() requires that icon.library be open (even if the caller
    was started from a shell, so that the function [FindToolType()](autodocs-2.0/icon-library-findtooltype.md) can be
    used) and may call [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), so clean up is necessary when
    the strings are no longer needed. The function [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md) does
    just that.
```
INPUTS

    argc - the number of arguments in argv, 0 when started from Workbench
    argv - an array of pointers to the program's arguments, or the
           Workbench startup message when started from WB.
RESULTS

    ttypes - the initialized argument array or NULL if it could not be
             allocated
EXAMPLE

```c
    Use of these routines facilitates the use of ToolTypes or command-
    line arguments to control end-user parameters in Commodities
    applications. For example, a filter used to trap a keystroke for
    popping up a window might be created by something like this:

            char   *ttypes  = ArgArrayInit(argc, argv);
            CxObj   *filter = UserFilter(ttypes, "POPWINDOW", "alt f1");

           ... with ...

           CxObj *UserFilter(char **tt, char *action_name,
                              char *default_descr)
            {
            char *desc;

                desc = FindToolType(tt,action_name);

                return(CxFilter((ULONG)(desc? desc: default_descr)));
            }

    In this way the user can assign "alt f2" to the action by
    entering a tooltype in the program's icon of the form:

            POPWINDOW=alt f2

    or by starting the program from the CLI like so:

            myprogram "POPWINDOW=alt f2"
```
NOTE

```c
    Your program must open icon.library and set up IconBase before calling
    this routine. In addition IconBase must remain valid until after
    [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md) has been called!
```
SEE ALSO

```c
    [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md), [ArgString()](autodocs-2.0/amiga-lib-argstring.md), [ArgInt()](autodocs-2.0/amiga-lib-argint.md), [icon.library/FindToolType()](autodocs-2.0/icon-library-findtooltype.md)
```

---

## See Also

- [FindToolType — icon.library](../autodocs/icon.library.md#findtooltype)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
