---
title: Cleanup
manual: amiga-mail
chapter: amiga-mail
section: cleanup
functions: [Close, Output, ReplyPkt]
libraries: [dos.library]
---

# Cleanup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you're exiting, use fn to tell you what to close, etc.  First check if
fn contains valid flags ((fn & 0x80000000) != 0)).  If it does not have
valid flags, Flush() and Close() cli_StandardOutput (if non-NULL), and
Close() cli_StandardInput (if non-NULL).  If fn does contain valid flags,
Flush(Output()), then check the other flags in fn.  If (fn&2 == 0) (if the
user didn't provide an input stream), Close() cli_StandardInput.  If (fn&1
== 1) (if Run provided an output stream), Close() cli_StandardOutput
(note, this is opposite the previous flag!)  If (fn&8 == 0) (if this is
not an asynchronous System() call), you still have to ReplyPkt() the
initial packet.  Before sending back the packet put cli_ReturnCode in the
packet's result1 and cli_Result2 in the packet's result2 (i.e. return the
result of the last program run if this was a synchronous System() or
Execute() call).

In cleanup, unlock pr_CurrentDir and set it to NULL, free up anything you
allocated, and exit!  The system will take care of your
CommandLineInterface structure, and anything else it allocated.

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
