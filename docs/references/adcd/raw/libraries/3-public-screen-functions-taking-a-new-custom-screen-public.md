# 3 / Public Screen Functions / Taking a New Custom Screen Public


Applications that open a new screen should consider taking the screen
[public](../Libraries_Manual_guide/node00E6.html).  If the screen's characteristics are not very esoteric, making the
screen public is useful because it allows other applications to share the
working context.  This makes an application more powerful and more
attractive to the user because it allows the user to add supporting
applications and utilities from other vendors to make a customized and
integrated work environment.

To make your own [custom screen](../Libraries_Manual_guide/node00DF.html) into a [public screen](../Libraries_Manual_guide/node00E6.html) that other
applications may use, you give the screen a public name and then register
the screen with Intuition.  The screen must be declared as public in the
[OpenScreenTagList()](../Libraries_Manual_guide/node00DF.html#line6) call by specifying a public name string with the
[SA_PubName](../Libraries_Manual_guide/node00E5.html#line234) tag.  The application's task ID and a signal bit may also be
registered when the screen is opened with the [SA_PubTask and SA_PubSig](../Libraries_Manual_guide/node00E5.html#line240)
tags.  If these tags are given, the system will signal your task when the
last window on the screen closes.

When a new [public screen](../Libraries_Manual_guide/node00E6.html) is opened, it starts out private so the
application can perform any desired initialization (for instance, opening
a backdrop window) before the screen is made public.  Use the
[PubScreenStatus()](../Libraries_Manual_guide/node00E6.html#line34) function to make the screen public and available to
other applications (or to take the screen private again, later).  The
screen may not be taken private or closed until all windows on the screen
are closed and all locksn on the screen are released.  However, the screen
does not need to be made private before closing it.

[CloseScreen()](../Libraries_Manual_guide/node00E4.html) will fail if an attempt is made to close a [public screen](../Libraries_Manual_guide/node00E6.html)
that still has visitor windows or locks on it.  If the user selects close
screen, but the screen will not close due to visitor windows, a requester
should be displayed informing the user of the condition and instructing
them to close any windows before closing the screen.

