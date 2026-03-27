---
title: 19 / Accessing a Device / Creating a Message Port
manual: libraries
chapter: libraries
section: 19-accessing-a-device-creating-a-message-port
functions: [CreateMsgPort, DeleteMsgPort]
libraries: [exec.library]
---

# 19 / Accessing a Device / Creating a Message Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a device completes the command in a message, it will return the
message to the message port specifed as the reply port in the message.  A
message port is obtained by calling the [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md) or [CreatePort()](libraries/24-message-ports-creating-a-message-port.md)
function.  You must delete the message port when you are finished by
calling the [DeleteMsgPort()](libraries/24-message-ports-deleting-a-message-port.md) or [DeletePort()](libraries/24-message-ports-deleting-a-message-port.md) function.

If your application needs to be compatible with pre-V36 versions of the
operating system, use the amiga.lib functions [CreatePort()](libraries/24-message-ports-creating-a-message-port.md) and
[DeletePort()](libraries/24-message-ports-deleting-a-message-port.md); if you require V36 or higher, you may use the Exec ROM
functions [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md) and [DeleteMsgPort()](libraries/24-message-ports-deleting-a-message-port.md).

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
