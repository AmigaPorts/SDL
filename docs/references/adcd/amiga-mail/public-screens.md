---
title: Public Screens
manual: amiga-mail
chapter: amiga-mail
section: public-screens
functions: [CloseWindow, LockPubScreen, LockPubScreenList, PubScreenStatus, UnlockPubScreen, UnlockPubScreenList]
libraries: [intuition.library]
---

# Public Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

V36 introduces the public screen, a custom screen on which other
applications can open their windows.  A familiar example of a public
screen is the Workbench screen.  The public screen provides the
ability to create system supported environment alternatives to the
Workbench.

Opening a public screen is just like opening a custom screen.  The
only difference is in the tags used when the screen is opened.  There
must be a SA_PubName tag, with the screen's name as the tag's data.
Applications will access the screen by this name.  When a public
screen is first opened, it is still private to the application that
opened it.  This will give the program that opened the screen the
opportunity to set up before other applications can access the screen.

After a public screen is explicitly made public, anybody can put a
lock on the screen or open a window on it.  Both locks and 'visitor
windows' prevent applications from closing their public screens.
Intuition keeps track of the number of locks and visitor windows on a
public screen by incrementing and decrementing the screen's visitor
count.  When the number of visitors is zero, the screen can be closed.

The following code fragment shows how to open a public screen and
change its status from private to public using the Intuition function
PubScreenStatus().


```c
    if (pubscreen = OpenScreenTags(NULL, SA_DisplayID, HIRES_KEY,
                    SA_Depth, 2, SA_Title, "AmigaMail Test Public Screen",
                    SA_PubName, "AmigaMail Test Public Screen",
                    /* By providing the public name, you indicate
                       it will be public */
                    SA_Pens, dri_Pens,
```
					SA_ErrorCode, &oserror,
					TAG_END)) {


```c
        /* change mode from 'private' to 'public' */
        oldstatus = PubScreenStatus(pubscreen, 0);}
```
If for any reason Intuition could not open the screen, the error
number will be returned in the data portion of the SA_ErrorCode tag
(the OpenScreen errors are listed in intuition/screens.h). This error
can indicate that the system is out of memory, that the requested
display mode is not supported by the video hardware or monitor, or
that the public screen name is already being used by another public
screen.

Some OpenScreen errors can be avoided.  Make sure the display mode a
screen requires is available (one of the previous examples shows how
to find all available display modes).  For example, before opening a
public screen, make sure its name is not already being used by an
existing public screen.  Before opening a public screen named
ExamplePublicScreen, try to put a lock on a screen with that name
using LockPubScreen().  If this call succeeds, the system has found
and locked a screen with that name, so you can't use it.  If the call
fails, the system does not have a screen by that name, indicating that
it's OK to open the new screen with that name.  An application should
make sure it removes all locks on a screen when the screen is no
longer needed.

If a screen already exists with that name, there are several options
available, all of which should reflect user preferences.  One option
is not to open a screen, using the existing screen instead.  For
example, if the user double-clicks an application's project icon, the
application would check if its public screen is already opened and
open windows there before trying to open a new screen.  Another option
is to open a new screen with a slightly different name.  A public
screen that would have been named ExamplePublicScreen might instead be
called ExamplePublicScreen2.  A third option is to quit.  In any case,
the user should normally be choosing the actions of the application,
not the programmer.

Programs find specific public screens by their name, so public screens
must have a unique name as identification.  With a maximum name length
of 139 characters, supplying a unique name shouldn't be a problem.
This name should reflect the nature of the screen's purpose, if for no
other reason, to make it easy to figure out what the screen is used
for.  Ambiguous names such as "PublicScreen" or "MyScreen" should not
be used as they tell nothing about the nature of the screen.  Also,
more than one "less creative" programmer might be inclined to give
such generic names to their public screen, which can confuse both user
and application.

As a public screen can be used as an alternative to the Workbench
environment, programs opening public screens should normally make the
screen is at least 640 pixels wide.  Many applications assume that the
Workbench is at least 640x200 and would be severely crippled if opened
on a 320x200 screen.

Before a public screen can be closed, it has to be made private again.
As long as there are visitors (windows and locks) on a public screen,
an attempt to change the screen's status to private will fail.  To
make closing down public screens easier, Intuition can signal an
application when the last visitor 'leaves' a public screen.  While
waiting to close a locked public screen, an application can start to
shut down by unloading code or closing windows.  After the screen has
been made private again, Intuition removes it from the public screen
list.  The following code illustrates this.


if ((oldstatus = PubScreenStatus(pubscreen, PSNF_PRIVATE)) & PSNF_PRIVATE)


```c
            CloseScreen(pubscreen);
```
To tell Intuition to signal when all the visitor windows on a public
screen have been closed, use the SA_PubSig and SA_PubTask tags when
opening the screen.  The SA_PubSig data is the number of a signal bit
you have allocated.  An application can specify which task to signal
when all the visitors have left by supplying a pointer to that task
with the SA_PubTask tag.  If this tag is absent or its data = NULL,
the task which opened the public screen will be signaled.

When putting up any requesters on a public screen, be sure to supply
the requester with a pointer to a visitor window on that screen.  This
will prevent the requester from popping up on the wrong screen.  This
will also prevent needless incrementing of the public screen's visitor
count as the requester will not be considered a visitor.

Prior to release 2.02, UnlockPublicScreen() did not signal when the
visitor count reached zero.  With release 2.02, UnlockPubScreen() will
signal the specified task when the visitor count reaches zero.  Under
2.00 and 2.01, only CloseWindow() would signal.

There is always a default public screen available.  Normally this
would be the Workbench, but an application can make its own public
screen the default, or better yet, a screen manager utility could let
the user choose the default public screen.  An application should not
automatically make its public screen the default as this might confuse
the user and can conflict with user preferences.

Because older programs do not know about public screens, The SHANGHAI
flag has been provided to 'shanghai' requests to open a window on the
Workbench screen, forcing the window to open on the default public
screen. Of course, a release 2.0 application that wants to open a
window on a specific public screen can do so provided that the
specific screen is available.  Another flag, POPPUBSCREEN, instructs
Intuition to move public screens to the front if a window is opened on
it.  The SHANGHAI and POPPUBSCREEN flags can be set using
PubScreenStatus() but, as the flags are global and should be set
according to the preferences of the user, applications should not be
changing them.

Example 2, [Pub.c](amiga-mail/iv-3-pub-c.md), shows how to open a public screen, make it the
default and shut it down.  The example can be found at the end of this
article.

To aid 'screen manager' utilities, the list of public screens can be
locked and copied using LockPubScreenList().  UnlockPubScreenList()
will unlock the list.  Don't try to interpret the list itself.
Instead, copy it and release the lock. To receive an updated copy
later on, lock and copy the list again. [Lockpub.c](amiga-mail/iv-3-lockpub-c.md) is a small example
of locking the public screen list.

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [PubScreenStatus — intuition.library](../autodocs/intuition.library.md#pubscreenstatus)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
