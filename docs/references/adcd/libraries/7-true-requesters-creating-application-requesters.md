---
title: 7 / True Requesters / Creating Application Requesters
manual: libraries
chapter: libraries
section: 7-true-requesters-creating-application-requesters
functions: [EndRequest, InitRequester, Request]
libraries: [intuition.library]
---

# 7 / True Requesters / Creating Application Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To create a requester, the application first allocates memory for or
declares an instance of the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure as defined in
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.  Once the Requester structure is set up, it is
initialized with the [InitRequester()](autodocs-2.0/intuition-library-initrequester.md) function.


```c
    void InitRequester( struct Requester *requester)
```
This function simply clears the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure.  The application
should do further initialization depending on its needs.  See the section
on the "[Requester Structure](libraries/7-intuition-requesters-and-alerts-requester-structure.md)" below for an explanation of all the Requester
fields and how to set them.

A [true](libraries/7-intuition-requesters-and-alerts-true-requesters.md) (modal) requester is attached to its parent window and displayed
with the [Request()](autodocs-2.0/intuition-library-request.md) function.


```c
    BOOL Request(struct Requester *requester, struct Window *window)
```
This function returns TRUE if the requester opens successfully or FALSE if
the requester cannot be opened.  If the requester opens successfully, menu
and gadget input in the parent window is blocked as long as the requester
is displayed.  The application should process input events from the
requester, which are sent to the parent window's [Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md), until
the requester is satisfied.

To remove a requester from its parent window and update the display, use
[EndRequest()](autodocs-2.0/intuition-library-endrequest.md).


```c
    void EndRequest( struct Requester *requester, struct Window *window );
```
This removes only the one requester specified.  It is possible to set up a
requester with a special gadget that, if selected, will automatically
close the requester.  In that case, [EndRequest()](autodocs-2.0/intuition-library-endrequest.md) need not be called.  If
the program needs to cancel the request early, or cancel it only after
some specific manipulation of the gadgets, EndRequest() should be used.

The application should always provide a safe way for the user to back out
of a requester without taking any action that affects the user's work.
Providing an escape hatch is important, for instance, a requester with the
message "Overwrite File?" should allow the user to cancel the operation
without losing the old data.

---

## See Also

- [EndRequest — intuition.library](../autodocs/intuition.library.md#endrequest)
- [InitRequester — intuition.library](../autodocs/intuition.library.md#initrequester)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
