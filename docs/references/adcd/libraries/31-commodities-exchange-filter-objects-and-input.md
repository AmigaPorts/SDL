---
title: 31 Commodities Exchange / Filter Objects and Input Description Strings
manual: libraries
chapter: libraries
section: 31-commodities-exchange-filter-objects-and-input
functions: []
libraries: []
---

# 31 Commodities Exchange / Filter Objects and Input Description Strings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because not all commodities are interested in every input event that makes
it way down the input chain, Commodities Exchange has a method for
filtering them.  A filter [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) compares the [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md) it receives to
a pattern.  If a CxMessage matches the pattern, the filter diverts the
CxMessage down its personal list of CxObjects.


```c
    CxObj *CxFilter(UBYTE *descriptionstring);
```
The C macro [CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md) (defined in <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>) returns a
pointer to a filter [CxObject](libraries/31-commodities-exchange-library-cxobjects.md).  The macro has only one argument, a pointer
to a string describing which input events to filter.  The following
regular expression outlines the format of the input event description
string ([CX_POPKEY](libraries/31-commodities-exchange-library-commodity-tool-types.md) uses the same description string format):


```c
    [class]  {[-] (qualifier|synonym)}  [[-] upstroke]  [highmap|ANSICode]
```
Class can be any one of the class strings in the table below.  Each class
string corresponds to a class of input event as defined in
<devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md)>.  Commodities Exchange will assume the class is
rawkey if the class is not explicitly stated.




     Class String      Input Event Class
     ------------      -----------------
    "rawkey"           IECLASS_RAWKEY
    "rawmouse"         IECLASS_RAWMOUSE
    "event"            IECLASS_EVENT
    "pointerpos"       IECLASS_POINTERPOS
    "timer"            IECLASS_TIMER
    "newprefs"         IECLASS_NEWPREFS
    "diskremoved"      IECLASS_DISKREMOVED
    "diskinserted"     IECLASS_DISKINSERTED
Qualifier is one of the qualifier strings from the table below.  Each
string corresponds to an input event qualifier as defined in
<devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md)>).  A dash preceding the qualifier string tells the
filter object not to care if that qualifier is present in the input event.
Notice that there can be more than one qualifier (or none at all) in the
input description string.


   Qualifier String    Input Event Class
   ----------------    -----------------


    "lshift"           IEQUALIFIER_LSHIFT
    "rshift"           IEQUALIFIER_RSHIFT
    "capslock"         IEQUALIFIER_CAPSLOCK
    "control"          IEQUALIFIER_CONTROL
    "lalt"             IEQUALIFIER_LALT
    "ralt"             IEQUALIFIER_RALT
    "lcommand"         IEQUALIFIER_LCOMMAND
    "rcommand"         IEQUALIFIER_RCOMMAND
    "numericpad"       IEQUALIFIER_NUMERICPAD
    "repeat"           IEQUALIFIER_REPEAT
    "midbutton"        IEQUALIFIER_MIDBUTTON
    "rbutton"          IEQUALIFIER_RBUTTON
    "leftbutton"       IEQUALIFIER_LEFTBUTTON
    "relativemouse"    IEQUALIFIER_RELATIVEMOUSE
Synonym is one of the synonym strings from the table below.  These
strings act as synonyms for groups of qualifiers.  Each string corresponds
to a synonym identifier as defined in <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>.  A dash
preceding the synonym string tells the filter object not to care if that
synonym is present in the input event.  Notice that there can be more
than one synonym (or none at all) in the input description string.




    Synonym     Synonym
    String     Identifier
    -------    ----------
    "shift"    IXSYM_SHIFT    /* look for either shift key */
    "caps"     IXSYM_CAPS     /* look for either shift key or capslock */
    "alt"      IXSYM_ALT      /* look for either alt key */
Upstroke is the literal string "upstroke".  If this string is absent, the
filter considers only downstrokes.  If it is present alone, the filter
considers only upstrokes.  If preceded by a dash, the filter considers
both upstrokes and downstrokes.

Highmap is one of the following strings:


    "space", "backspace", "tab", "enter", "return", "esc", "del",
    "up", "down", "right", "left", "f1", "f2", "f3", "f4", "f5",
    "f6", "f7", "f8", "f9", "f10", "help".
ANSICode is a single character (for example `a') that Commodities Exchange
looks up in the system default keymap.

Here are some example description strings.  For function key F2 with the
left Shift and either Alt key pressed, the input description string would
be:


    "rawkey lshift alt f2"
To specify the key that produces an `a' (this may or may not be the A key
depending on the keymap), with or without any Shift, Alt, or control keys
pressed use:


    "-shift -alt -control a"
For a mouse move with the right mouse button down, use:


    "rawmouse rbutton"
To specify a timer event use:


    "timer"
