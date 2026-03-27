---
title: exec.library/ReplyMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-replymsg
functions: []
libraries: []
---

# exec.library/ReplyMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReplyMsg -- put a message to its reply port
SYNOPSIS

```c
    ReplyMsg(message)
             A1

    void ReplyMsg(struct [Message](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    This function sends a message to its reply port.  This is usually
    done when the receiver of a message has finished and wants to
    return it to the sender (so that it can be re-used or deallocated,
    whatever).

    This call may be made from interrupts.
```
INPUT

    message - a pointer to the message
IMPLEMENTATION

```c
    1> Places "NT_REPLYMSG" into LN_TYPE.
    2> Puts the message to the port specified by MN_REPLYPORT
       If there is no replyport, sets LN_TYPE to "NT_FREEMSG" (use this
       feature only with extreeme care).
```
SEE ALSO

```c
    [GetMsg](autodocs-2.0/exec-library-getmsg.md), [PutMsg](autodocs-2.0/exec-library-putmsg.md), [exec/ports.h](autodocs-2.0/includes-exec-ports-h.md)
```
