---
title: 9 / / Event Message Classes and Flags / Other Flags
manual: libraries
chapter: libraries
section: 9-event-message-classes-and-flags-other-flags
functions: [GetPrefs, MapRawKey, RawKeyConvert, SetPrefs]
libraries: [console.device, intuition.library, keymap.library]
---

# 9 / / Event Message Classes and Flags / Other Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IDCMP_VANILLAKEY

```c
    IDCMP_VANILLAKEY messages return keyboard events translated into the
    current default character keymap.  The mapped character value is
    returned in the [Code](libraries/9-using-the-idcmp-intuimessages.md) field of the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) structure.

    An IDCMP_VANILLAKEY message is sent only if the translation results
    in a single byte value, therefore the program cannot read the Help or
    function keys using IDCMP_VANILLAKEY.

    Starting with V36, programs using IDCMP_VANILLAKEY which also require
    the additional information of special keys, such as the Help key and
    the function keys, may set both IDCMP_VANILLAKEY and IDCMP_RAWKEY.
    When this combination is used, all keypresses that map to single
    character values will be returned as IDCMP_VANILLAKEY events; all
    other keyboard events will be sent as IDCMP_RAWKEY messages.  Note
    that IDCMP_VANILLAKEY processing uses all of the key-up events, so
    the application will only receive key-down events in the IDCMP_RAWKEY
    format.
```
IDCMP_RAWKEY

```c
    IDCMP_RAWKEY messages give the raw keycodes from the keyboard. The
    numeric value of the keycode is sent in the [Code](libraries/9-using-the-idcmp-intuimessages.md) field. Separate
    codes are returned for key down and key up.  Qualifier codes, such as
    Shift or Alt and whether this key is a repeat, may be found in the
    [Qualifier](libraries/9-using-the-idcmp-intuimessages.md) field of the message.

    In general, the application should not assume any correspondence
    between the keycode and the key value.  Character positions on the
    keyboard change from country to country, and the application should
    respect the keymap set by the user.

    Programs using IDCMP_RAWKEY messages should perform their own key
    mapping by calling the console.device function [RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md), or
    the keymap.library function [MapRawKey()](libraries/34-keymap-functions-mapping-key-codes-to-ansi-strings.md).  (The latter is a bit more
    convenient, but is only available under V36 and higher).  The Autodoc
    for the MapRawKey() function shows how you can process so-called dead
    keys.  A dead key is a key combination that has no immediate effect,
    but instead modifies a subsequent keystroke.  For example, on the
    default keymap, Alt-F is a dead key for the acute accent mark.  The
    sequence of Alt-F followed by the E key yields an é with an acute
    accent.

    For an example of key mapping using the [RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md) call, see the
    [rawkey.c](devices/lib-examples-rawkey-c.md) example in the "Intuition Mouse and Keyboard" chapter.

    The application can assume that certain keys will always return the
    same raw keycode, these keys do not have to be mapped.  In general
    these keys are in the high part of the keymap, above hex 40, and
    includes all non-alphanumeric keys.  The fixed keys include the
    function keys, backspace, delete, help and cursor keys.
```
IDCMP_NEWPREFS

```c
    IDCMP_NEWPREFS messages are sent when the system Preferences are
    changed by a call to [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md).  The program can learn of these
    changes by setting this flag.

    After receiving a message of class IDCMP_NEWPREFS, the application
    should call [GetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-reading-1-3.md) to obtain a copy of the new Preferences.

    Under the new Preferences scheme used in Release 2 and later versions
    of the OS, an IDCMP_NEWPREFS message will not always be sent when the
    user changes a Preferences setting.  Only Preferences values
    available under V34, i.e., those that can be modified by a call to
    [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md), will cause an IDCMP_NEWPREFS message to be sent.  New
    Preferences items such as overscan or font settings rely on
    filesystem notification for monitoring changes.  See the chapter on
    "[Preferences](libraries/13-preferences-in-1-3-and-older-versions-reading-1-3.md)" for more information.

    This message type is broadcast to all IDCMP that have this flag set,
    not just to the active window.  If the application has this flag set,
    it should be prepared to handle the event even if it is not active.
```
IDCMP_DISKINSERTED and IDCMP_DISKREMOVED

    When the user inserts or removes a floppy disk from any drive,
    Intuition will send one of these message types.

    This message type is broadcast to all IDCMP that have this flag set,
    not just to the active window.  If the application has this flag set,
    it should be prepared to handle the event even if it is not active.
IDCMP_INTUITICKS

    Intuition sends these messages to the active window based on an
    internal timer which "ticks" roughly ten times a second. This
    provides the application with simple timer events from Intuition.

    Intuition does not allow IDCMP_INTUITICKS events to accumulate at a
    port.  After an IDCMP_INTUITICKS message has been sent to a port,
    Intuition will not send another until the application replies to the
    first.  This means that an application that has not been able to
    service the IDCMP for an extended period can expect at most one
    IDCMP_INTUITICKS message to be waiting at the port.

    These events are to be used as "prods", and not as time counters.  Do
    not rely on the timing accuracy of the event, or on the exact
    frequency at which they appear.  Remember, IDCMP_INTUITICKS will only
    be sent to the active window.  If the user selects another window,
    the events will no longer be received at the first window.
IDCMP_IDCMPUPDATE

```c
    Used for notification from Boopsi custom gadgets.  See the chapter on
    "[BOOPSI](libraries/12-oop-overview-making-gadgets-talk-to-an-application.md)" for more information.  The [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field contains a pointer
    to a tag item list.  Tag lists are described in the chapter
    "[Utility Library](libraries/37-tags-simple-tag-usage.md)".
```
IDCMP_CHANGEWINDOW

    This message provides the window with notification of any change in
    the size or position of a window.
There are two other message classes reserved for system use:

IDCMP_WBENCHMESSAGE

    Special messages for Workbench, system use only.
IDCMP_LONELYMESSAGE

    For internal tracking by Intuition, system use only.

---

## See Also

- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
- [RawKeyConvert — console.device](../autodocs/console.device.md#rawkeyconvert)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
