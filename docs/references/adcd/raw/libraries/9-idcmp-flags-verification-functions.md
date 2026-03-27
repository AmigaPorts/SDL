# 9 / IDCMP Flags / Verification Functions


IDCMP_SIZEVERIFY, IDCMP_REQVERIFY and IDCMP_MENUVERIFY are exceptional in
that Intuition sends an [IntuiMessage](../Libraries_Manual_guide/node01D9.html) to the application and then waits for
the application to reply before Intuition proceeds.  The application
replies by calling the Exec function [ReplyMsg()](../Libraries_Manual_guide/node02F3.html).

The implication is that the user requested some operation but the
operation will not happen immediately and, in fact, will not happen at all
until the application says it is safe.  Because this delay can be
frustrating and intimidating, the program should strive to make the delay
as short as possible.  An application should always reply to a
verification message as soon as possible.

These problems may be overcome by setting up a separate task to monitor
the IDCMP and respond to incoming [IntuiMessage](../Libraries_Manual_guide/node01D9.html)s immediately.  This is
recommended where there is heavy traffic through the IDCMP, which occurs
when many IDCMP flags are set.  Monitoring with a separate task may not be
appropriate if the main program must synchronize with the event before it
can respond to the message.

In previous versions of the operating system, it was not safe to leave any
of the VERIFY functions enabled at a time when the task is unable to
respond for a long period.  This restriction included calls to AmigaDOS
directly (with [Open()](../Includes_and_Autodocs_2._guide/node02D6.html), for example), or indirectly (with [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15),
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

The application should use [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) to turn off all VERIFY messages
before calling AmigaDOS, or functions that may call AmigaDOS.

If the application sets up a separate task to monitor the IDCMP, and the
task monitoring the IDCMP does not call AmigaDOS functions, and if the
monitor task will always be able to reply to the VERIFY message without
any help from the other task, then the above warning does not apply.

For additional information, see the [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) discussion in the
"[Intuition Menus](../Libraries_Manual_guide/node0193.html)" chapter, the [IDCMP_REQVERIFY](../Libraries_Manual_guide/node01DF.html#line8) discussion in the
"[Intuition Requesters and Alerts](../Libraries_Manual_guide/node01AA.html#line18)" chapter and the [IDCMP_SIZEVERIFY](../Libraries_Manual_guide/node01E0.html#line28)
discussion in the "[Intuition Windows](../Libraries_Manual_guide/node0111.html#line12)" chapter.

This message type is broadcast to all IDCMP on the screen that have this
flag set, not just to the active window.  If the application has this flag
set, it should be prepared to handle the event even if it is not active.

