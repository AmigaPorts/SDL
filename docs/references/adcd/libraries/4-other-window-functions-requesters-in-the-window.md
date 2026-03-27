---
title: 4 / Other Window Functions / Requesters in the Window
manual: libraries
chapter: libraries
section: 4-other-window-functions-requesters-in-the-window
functions: [EndRequest, Request]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Requesters in the Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Requesters are temporary sub-windows, usually containing several gadgets,
used to confirm actions, access files, or adjust the options of a command
the user has just given.  [Request()](libraries/7-true-requesters-creating-application-requesters.md) creates and activates a requester in
the window.  [EndRequest()](libraries/7-true-requesters-creating-application-requesters.md) removes the requester from the window.


```c
    BOOL Request( struct Requester *requester, struct Window *window );
    void EndRequest( struct Requester *requester, struct Window *window );
```
For simple requesters in a format that matches system requesters, two new
functions have been added to Release 2:


```c
    LONG EasyRequestArgs( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR args );
    LONG EasyRequest( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR arg1, ... );
```
The [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md) functions support requesters with one or more gadgets
automatically providing a layout that is sensitive to the current font and
screen resolution.  See the chapter "[Intuition Requesters and Alerts](libraries/7-intuition-requesters-and-alerts-easy-requesters.md)" for
more information on using requester functions.

---

## See Also

- [EndRequest — intuition.library](../autodocs/intuition.library.md#endrequest)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
