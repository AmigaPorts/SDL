---
title: intuition.library/BuildEasyRequestArgs
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-buildeasyrequestargs
functions: [AutoRequest, BuildEasyRequestArgs, BuildSysRequest, EasyRequestArgs, FreeSysRequest, SysReqHandler]
libraries: [intuition.library]
---

# intuition.library/BuildEasyRequestArgs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    BuildEasyRequestArgs -- Simple creation of system request. (V36)
    BuildEasyRequest -- Varargs stub for BuildEasyRequestArgs(). (V36)
```
SYNOPSIS

```c
    ReqWindow = BuildEasyRequestArgs( RefWindow, easyStruct, IDCMP, Args )
    D0                                A0         A1          D0     A3

    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *BuildEasyRequestArgs( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [EasyStruct](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG, APTR );

    ReqWindow = BuildEasyRequest( RefWindow, easyStruct, IDCMP, Arg1, ... )

    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *BuildEasyRequest( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [EasyStruct](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG, APTR, ... );
```
FUNCTION

```c
    This function is to EasyRequest() as [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) is to
    AutoRequest(): it returns a pointer to the system requester
    window.  The input from that window can then be processed
    under application control.

    It is recommended that this processing be done with
    [SysReqHandler()](autodocs-2.0/intuition-library-sysreqhandler.md), so that future enhancement to the
    processing will be enjoyed.

    After you have determined that the requester is satisfied or
    cancelled, you must free this requester using [FreeSysRequest()](autodocs-2.0/intuition-library-freesysrequest.md).

    Please see the autodoc for EasyRequest().

    NOTE: This function switches the processor stack to ensure
    sufficient stack space for the function to complete.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = reference window for requester: determines the
        requester window title and screen.
    easyStruct = pointer to [EasyStruct](autodocs-2.0/includes-intuition-intuition-h.md) structure, as described
        in the EasyRequest() autodocs.
    IDCMP = (NOT A POINTER) provided application specific IDCMP
        flags for the system requester window.
    Args = see EasyRequest()
```
RESULT

```c
    A pointer to the system request window opened.  In the event
    of problems, you may also be returned the value '0' which
    is to be interpreted as the "FALSE, Cancel" choice, or
    (if you have a second gadget defined) the value '1', which
    is to be taken to mean the equivalent of your corresponding
    left-most gadget.

    If there is a problem creating the window, a recoverable alert may
    be substituted for the requester, and the result, either 0 or 1,
    returned.
```
BUGS

```c
    Does not put up alternative alert.
    See also BUGS listed for [EasyRequestArgs()](autodocs-2.0/intuition-library-easyrequestargs.md).
```
SEE ALSO

```c
    [EasyRequestArgs()](autodocs-2.0/intuition-library-easyrequestargs.md), [FreeSysRequest()](autodocs-2.0/intuition-library-freesysrequest.md), [SysReqHandler()](autodocs-2.0/intuition-library-sysreqhandler.md),
    [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md), [AutoRequest()](autodocs-2.0/intuition-library-autorequest.md)
```

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
