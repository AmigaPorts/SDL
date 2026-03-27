---
title: 7 / Easy Requesters / Low Level Access to Easy Requesters
manual: libraries
chapter: libraries
section: 7-easy-requesters-low-level-access-to-easy-requesters
functions: [FreeSysRequest, SysReqHandler]
libraries: [intuition.library]
---

# 7 / Easy Requesters / Low Level Access to Easy Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md) function calls a lower level Intuition function named
[BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md) to construct the requester.  An application can call
BuildEasyRequest() directly if it needs to use an easy requester but
requires custom handling of the events sent to the requester.  Handling of
the events should be done using the [SysReqHandler()](autodocs-2.0/intuition-library-sysreqhandler.md) function as described
below.

The [BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md) functions take the same arguments as [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md):


```c
    struct Window *BuildEasyRequestArgs( struct Window *window,
                                         struct EasyStruct *easyStruct,
                                         unsigned long idcmp, APTR args );

    struct Window *BuildEasyRequest( struct Window *window,
                                     struct EasyStruct *easyStruct,
                                     unsigned long idcmp, APTR arg1, ... );
```
To process input event information directly while an easy requester is
displayed, first call [BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md) then call [SysReqHandler()](autodocs-2.0/intuition-library-sysreqhandler.md)
periodically to process user input.


```c
    LONG SysReqHandler( struct Window *window, ULONG *idcmpPtr,
                        long waitInput );
```
This will provide standard handling of events but allow the application to
control the timing of checking the events.  This handling includes checks
for left Amiga keys.

The [FreeSysRequest()](autodocs-2.0/intuition-library-freesysrequest.md) function must be called after an application has
finished with a requester (if it was created with [BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md) call).


```c
    void FreeSysRequest( struct Window *window );
```
This function ends the requester and frees any resources allocated with
the [BuildEasyRequest()](autodocs-2.0/intuition-library-buildeasyrequestargs.md) call.

---

## See Also

- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
