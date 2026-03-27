---
title: 7 Intuition Requesters and Alerts / Alerts
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-alerts
functions: []
libraries: []
---

# 7 Intuition Requesters and Alerts / Alerts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Alerts are for emergency messages.  They can be displayed even when the
system is in a very fragile state, such as when the system is low on
memory or when some of the system lists are corrupt.

Alerts can be displayed by either the system or an application.  They are
reserved for urgent messages and dire warnings in situations that require
the user to take some immediate action.  Alerts should only be used where
no other display type is possible.  For instance, when the system has
crashed or is about to crash, an alert could be used to inform the user of
the cause.

The sudden display of an alert is a jarring experience for the user.  The
system stops dead while the alert is displayed and waits for the user
input.  For this reason, alerts should only be used when there is no
recourse.  If possible, use requesters or windows to display warning
messages in place of alerts.

System alerts are managed entirely by Intuition.  The program does not
have to take any action to invoke or process these alerts.  Alerts do not
have access to the display database or other information required to open
in specialized display modes.  For this reason, alerts must appear in a
display mode available on all machines, namely high resolution,
non-interlaced.  Alerts do not use overscan, so the display is limited to
640 by 200 on an NTSC machine, and 640 by 256 on a PAL machine.

The alert appears at the top of the video display.  They are displayed the
full 640 pixels wide and as tall as needed, up to the limits described
above.  Alerts are always displayed on a black background.  The text of
the alert is displayed within a rectangular border.  Both the text and the
border are displayed in a single color which is determined by the type of
the alert.

The user responds to an alert by pressing one of the mouse buttons.  The
left mouse button signifies a positive response such as "Retry" or "OK".
The right mouse button signifies a negative response such as "Cancel" or
"Abort".


    Alerts Save Up User Input.
    --------------------------
    The events produced by the user during an alert are not consumed by
    the alert.  These events are passed through to the program when the
    alert returns.  There could be a great deal of input queued and
    waiting for processing by the application.
 [Types of Alerts](libraries/7-alerts-types-of-alerts.md)    [Creating Alerts](libraries/7-alerts-creating-alerts.md)    [Display Alert Example](libraries/lib-examples-displayalert-c.md) 

