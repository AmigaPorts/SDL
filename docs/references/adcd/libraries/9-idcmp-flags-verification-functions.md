---
title: 9 / IDCMP Flags / Verification Functions
manual: libraries
chapter: libraries
section: 9-idcmp-flags-verification-functions
functions: [ModifyIDCMP, Open, OpenLibrary, ReplyMsg]
libraries: [dos.library, exec.library, intuition.library]
---

# 9 / IDCMP Flags / Verification Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IDCMP_SIZEVERIFY, IDCMP_REQVERIFY and IDCMP_MENUVERIFY are exceptional in
that Intuition sends an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) to the application and then waits for
the application to reply before Intuition proceeds.  The application
replies by calling the Exec function [ReplyMsg()](libraries/24-messages-replying.md).

The implication is that the user requested some operation but the
operation will not happen immediately and, in fact, will not happen at all
until the application says it is safe.  Because this delay can be
frustrating and intimidating, the program should strive to make the delay
as short as possible.  An application should always reply to a
verification message as soon as possible.

These problems may be overcome by setting up a separate task to monitor
the IDCMP and respond to incoming [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s immediately.  This is
recommended where there is heavy traffic through the IDCMP, which occurs
when many IDCMP flags are set.  Monitoring with a separate task may not be
appropriate if the main program must synchronize with the event before it
can respond to the message.

In previous versions of the operating system, it was not safe to leave any
of the VERIFY functions enabled at a time when the task is unable to
respond for a long period.  This restriction included calls to AmigaDOS
directly (with [Open()](autodocs-2.0/dos-library-open.md), for example), or indirectly (with [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md),
for a disk based library, for example), when a VERIFY function was active.
This was because there are many cases where AmigaDOS will put up a
requester prompting the user for input, and Intuition may end up waiting
for the application to reply to the VERIFY message, while the application
waits for the AmigaDOS call to finish.  Prior to Release 2, this deadlock
would freeze the Amiga.

Beginning with V36, Intuition will no longer wait forever for the
application to respond to the verify messages.  These messages will now
time-out; that is, if the application does not respond within a set
period, Intuition will act as if it had.  Even in this case, though, the
machine will appear to be locked up until the time-out occurs.

The application should use [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to turn off all VERIFY messages
before calling AmigaDOS, or functions that may call AmigaDOS.

If the application sets up a separate task to monitor the IDCMP, and the
task monitoring the IDCMP does not call AmigaDOS functions, and if the
monitor task will always be able to reply to the VERIFY message without
any help from the other task, then the above warning does not apply.

For additional information, see the [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) discussion in the
"[Intuition Menus](libraries/6-setting-up-menus-intercepting-normal-menu-operations.md)" chapter, the [IDCMP_REQVERIFY](libraries/9-event-message-classes-and-flags-requester-flags.md) discussion in the
"[Intuition Requesters and Alerts](libraries/7-true-requesters-idcmp-requester-features.md)" chapter and the [IDCMP_SIZEVERIFY](libraries/9-event-message-classes-and-flags-window-flags.md)
discussion in the "[Intuition Windows](libraries/4-the-idcmp-and-gadgets-system-gadgets.md)" chapter.

This message type is broadcast to all IDCMP on the screen that have this
flag set, not just to the active window.  If the application has this flag
set, it should be prepared to handle the event even if it is not active.

---

## See Also

- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
