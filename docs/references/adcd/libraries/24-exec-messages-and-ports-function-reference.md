---
title: 24 Exec Messages and Ports / Function Reference
manual: libraries
chapter: libraries
section: 24-exec-messages-and-ports-function-reference
functions: [AddPort, CreateMsgPort, DeleteMsgPort, FindPort, GetMsg, PutMsg, RemPort, ReplyMsg]
libraries: [exec.library]
---

# 24 Exec Messages and Ports / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following chart gives a brief description of the Exec functions that
control inter-task communication with messages and ports.  See the Amiga
ROM Kernel Reference Manual: Includes and Autodocs for details about each
call.

               Table 24-1: Exec Message and Port Functions
  _____________________________________________________________________
 |                                                                     |
 |       Function                   Description                        |
 |=====================================================================|
 |        [AddPort()](autodocs-2.0/exec-library-addport.md)  Add a public message port to the system list.     |
 |  [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md)  Allocate and initialize a new message port (V37). |
 |  [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md)  Free a message port, created with CreateMsgPort() |
 |                   (V37).                                            |
 |       [FindPort()](autodocs-2.0/exec-library-findport.md)  Find a public message port in the system list.    |
 |         [GetMsg()](autodocs-2.0/exec-library-getmsg.md)  Get next message from the message port.           |
 |         [PutMsg()](autodocs-2.0/exec-library-putmsg.md)  Put a message to a message port.                  |
 |        [RemPort()](autodocs-2.0/exec-library-remport.md)  Remove a message port from the system list.       |
 |       [ReplyMsg()](autodocs-2.0/exec-library-replymsg.md)  Reply to a message on its reply port.             |
 |_____________________________________________________________________|


               Table 24-2: Amiga.lib Exec Support Functions
  _____________________________________________________________________
 |                                                                     |
 |       Function                   Description                        |
 |=====================================================================|
 |     [CreatePort()](autodocs-2.0/amiga-lib-createport.md)  Allocate and initialize a new message port, make  |
 |                   public if named                                   |
 |     [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)  Delete a message port, created with CreatePort(). |
 |_____________________________________________________________________|

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
