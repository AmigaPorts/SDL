---
title: 2 / Audio And System I/O Functions / Wait() and WaitPort()
manual: devices
chapter: devices
section: 2-audio-and-system-i-o-functions-wait-and-waitport
functions: [GetMsg, Wait, WaitPort]
libraries: [exec.library]
---

# 2 / Audio And System I/O Functions / Wait() and WaitPort()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These functions can be used to put your task to sleep while a sound plays.
[Wait()](autodocs-2.0/exec-library-wait.md) takes a wake-up mask as its argument. The wake-up mask is usually
the mp_SigBit of a [MsgPort](autodocs-2.0/includes-exec-ports-h.md) that you have set up to get replies back from
the audio device.

[WaitPort()](autodocs-2.0/exec-library-waitport.md) will put your task to sleep while a sound plays.  The argument
to WaitPort() is a pointer to a MsgPort that you have set up to get
replies back from the audio device.

[Wait()](autodocs-2.0/exec-library-wait.md) and [WaitPort()](autodocs-2.0/exec-library-waitport.md) will not remove the message from the reply port.
You must use [GetMsg()](autodocs-2.0/exec-library-getmsg.md) to remove it.

You must always use Wait() or WaitPort() to wait for I/O to finish with
the audio device.

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
