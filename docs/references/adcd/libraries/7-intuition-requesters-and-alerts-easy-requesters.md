---
title: 7 Intuition Requesters and Alerts / Easy Requesters
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-easy-requesters
functions: [AutoRequest, EasyRequestArgs, ModifyIDCMP]
libraries: [intuition.library]
---

# 7 Intuition Requesters and Alerts / Easy Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md) provides a simple way to make a requester that allows the
user to select one of a limited number of choices.  (A similar function,
[AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md), is also available but is not as flexible or as powerful.
See the Amiga ROM Kernel Reference Manual: Includes and Autodocs for more
information.)


```c
     [Figure 7-2: A Simple Requester Made with EasyRequest()](libraries/lib-pics-7-2-pic.md) 
```
The program supplies the text for the body of the requester, text for each
of the possible options, an optional title for the window, and other
arguments.  The body text can consist of one or more lines with lines
separated by the linefeed character.

Each option for an easy requester is displayed as a simple button gadget
positioned beneath the body text you specify.  The layout of the
requester, its text and buttons, is done automatically and is font
sensitive.  The screen font ([Screen.Font](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md)) is used for all text in the
requester.

Typically, easy requesters have one selection indicating a positive action
and one selection indicating a negative action.  The text used for the
positive action might be "OK", "Yes," "True," "Retry," or similar
responses.  Likewise, the text used for the negative action might be "No,"
"False," "Cancel," and so on.  The negative choice should always be the
rightmost or final choice and will return a zero if selected.

When [EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md) is called, Intuition will build the requester, display
it, and wait for user response.


```c
    LONG EasyRequest( struct Window *window,
                      struct EasyStruct *easyStruct,
                      ULONG *idcmpPtr, APTR arg1, ... );

    LONG EasyRequestArgs( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR args );
```
The window argument is a pointer to the reference window.  The requester
will be displayed on the same screen that the reference window is on and
also takes its title from the reference window, if not otherwise
specified.  This argument can be NULL, which means the requester is to
appear on the Workbench screen, or the default public screen, if defined.

The easyStruct argument is a pointer to an [EasyStruct](libraries/7-easy-requesters-the-easystruct-structure.md) structure which
defines the setup and the text of this easy requester (described below).

The idcmpPtr argument is a pointer to a ULONG containing the IDCMP flags
for the event that you want to terminate this requester.  If such an event
occurs the requester is terminated (with a result of -1) and the ULONG
that idcmpPtr points to will contain the actual class of the event
message.  This feature allows external events to satisfy the request, such
as the user inserting a disk in the disk drive.  This argument can be set
to NULL for no automatic termination.

The gadget and body text for an easy requester is specified in an
[EasyStruct](libraries/7-easy-requesters-the-easystruct-structure.md) structure (see below).  Body text can be specified using a
[printf()](autodocs-2.0/amiga-lib-printf.md)-style format string that also accepts variables as part of the
text.  If variables are specified in the requester text, their value is
taken from the args (or arg1,...) parameters shown in the prototypes
above.  [EasyRequestArgs()](autodocs-2.0/intuition-library-easyrequestargs.md) takes a pointer to an array of pointers to
arguments, while [EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md) has a varargs interface and takes
individual arguments as part of the function call.  The types of these
arguments are specified in the format strings of the EasyStruct structure.
Arguments for [es_GadgetFormat](libraries/7-easy-requesters-the-easystruct-structure.md) follow arguments for [es_TextFormat](libraries/7-easy-requesters-the-easystruct-structure.md).

The [EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md) functions return an integer from 0 to n - 1, where n is
the number of choices specified for the requester.  The numbering from
left-to-right is:  1, 2, ..., n - 1, 0.  This is for compatibility with
[AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) which returns FALSE for the rightmost gadget.

The function will return -1 if it receives an IDCMP event that matches one
of the termination events specified in the idcmpPtr argument.


```c
    Turn Off the Verify Messages.
    -----------------------------
    Use [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to turn off all verify messages (such as
    [MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md)) before calling [EasyRequest()](autodocs-2.0/intuition-library-easyrequestargs.md) or [AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md). Neglecting
    to do so can cause situations where Intuition is waiting for the
    return of a message that the application program cannot receive
    because its input is shut off while the requester is up.  If
    Intuition finds itself in a deadlock state, the verify function will
    timeout and will be automatically replied.
```
 [The Easystruct Structure](libraries/7-easy-requesters-the-easystruct-structure.md)    [Low Level Access to Easy Requesters](libraries/7-easy-requesters-low-level-access-to-easy-requesters.md) 

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
