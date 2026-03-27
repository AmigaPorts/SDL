---
title: 13 / Preferences in Release 2 / The ENV: Directory and Notification
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-the-env-directory-and
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / The ENV: Directory and Notification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One advantage of the new Preferences system in Release 2 is file
notification.  File notification is a form of interprocess communication
available in Release 2 that allows an application to be automatically
notified if a change is made to a specific file or directory.  This makes
it easy for the application to react to changes the user makes to
Preferences files.

File notification is also used by the system itself.  The Release 2
Preferences control program, IPrefs, sets up notification on most of the
Preferences files in ENV:sys.  If the user alters a Preferences item
(normally this is done with a Preferences editor), the system will notify
IPrefs about the change and IPrefs will attempt to alter the user's
environment to reflect the change.

For example, if the user opens the ScreenMode Preferences editor and
changes the Workbench screen mode to high-resolution, the new settings are
saved in [Screenmode.prefs](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md) in the ENV:sys directory.  IPrefs sets up
notification on this file at boot time, so the file system will notify
IPrefs of the change.  IPrefs will read in the Screenmode.prefs file and
reset the Workbench screen to high resolution mode.

Here's a short example showing how to set up notification on the
serial.prefs file in ENV:sys.  The program displays a message in a window
whenever this file is changed (e.g., when the user selects the "Use" or
"Save" gadget in the Serial Preferences editor).


```c
     [prefnotify.c](libraries/lib-examples-prefnotify-c.md) 
```
