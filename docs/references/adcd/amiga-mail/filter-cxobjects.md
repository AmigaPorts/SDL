---
title: Filter CxObjects
manual: amiga-mail
chapter: amiga-mail
section: filter-cxobjects
functions: [AddTail, AttachCxObj, ParseIX]
libraries: [commodities.library, exec.library]
---

# Filter CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because not all commodities are interested in every input event that
makes it way down the input chain, Commodities Exchange has a method
for filtering them.  A filter CxObject compares the CxMessages it
receives to a pattern.  If a CxMessage matches the pattern, the filter
diverts the CxMessage down its personal list of CxObjects.


```c
    CxObj *CxFilter(char *descriptionstring);
```
The C macro CxFilter() (defined in <libraries/commodities.h>) returns
a pointer to a filter CxObject.  The macro has only one argument, a
pointer to a string describing which input events to filter.  The
following regular expression outlines the format of a description
string (CX_POPKEY uses the same description string format):


```c
    [class]  ( [-] (qual | syn) )*  [ [-] upstroke]  [highmap |ANSICode]
             the * means zero or more occurances of ( [-] ( qual | syn ) )
```
where:

class can be any one of the strings in the table below.  Each string
corresponds to a class of input event (shown below).  The classes are
defined in <devices/inputevent.h>.  Commodities Exchange will assume
the class is rawkey if the class is not explici tly stated.



    "rawkey"        IECLASS_RAWKEY
    "rawmouse"      IECLASS_RAWMOUSE
    "event"         IECLASS_EVENT
    "pointerpos"    IECLASS_POINTERPOS
    "timer"         IECLASS_TIMER
    "newprefs"      IECLASS_NEWPREFS
    "diskremoved"   IECLASS_DISKREMOVED
    "diskinserted"  IECLASS_DISKINSERTED
qual is one of the strings in the table below.  Each string
corresponds to an input event qualifier (followed by its ID from
<devices/inputevent.h>).  A dash preceding the qualifier string tells
the filter object not to care if that qualifier is present i n the
input event.  Notice that there can be more than one qual (or none at
all) in the input description string.



    "lshift"            IEQUALIFIER_LSHIFT
    "rshift"            IEQUALIFIER_RSHIFT
    "capslock"          IEQUALIFIER_CAPSLOCK
    "control"           IEQUALIFIER_CONTROL
    "lalt"              IEQUALIFIER_LALT
    "ralt"              IEQUALIFIER_RALT
    "lcommand"          IEQUALIFIER_LCOMMAND
    "rcommand"          IEQUALIFIER_RCOMMAND
    "numericpad"        IEQUALIFIER_NUMERICPAD
    "repeat"            IEQUALIFIER_REPEAT
    "midbutton"         IEQUALIFIER_MIDBUTTON
    "rbutton"           IEQUALIFIER_RBUTTON
    "leftbutton"        IEQUALIFIER_LEFTBUTTON
    "relativemouse"     IEQUALIFIER_RELATIVEMOUSE
syn is one of the strings in the table below.  These strings act as
synonyms for groups of qualifiers.  Each string below is followed by
its identifier from <libraries/commodities.h>.  A dash preceding the
synonym string tells the filter object not to car e if that qualifier
is present in the input event.  Notice that there can be more than one
syn (or none at all) in the input description string.



    "shift"     IXSYM_SHIFT    /* look for either shift key */
    "caps"      IXSYM_CAPS     /* look for either shift key or capslock */
    "alt"       IXSYM_ALT      /* look for either alt key */
upstroke is the literal string "upstroke".  If this string is absent,
the filter considers only downstrokes.  If is present alone, the
filter considers only upstrokes.  If preceded by a dash, the filter
considers both upstrokes and downstrokes.


highmap is one of the following strings:



    "space", "backspace", "tab", "enter", "return", "esc", "del", "up",
    "down", "right", "left", "f1", "f2", "f3", "f4", "f5", "f6", "f7",
    "f8", "f9", "f10", "help".
ANSICode is a single character (for example `a`) that Commodities
Exchange looks up in the system default keymap.


The following are some example description strings:


    "rawkey lshift alt f2"    Function key f2 with the left shift and
                                either alt key pressed.
    "-shift -alt -control a"  The key that produces an 'a' with or
                                without any shift, alt, or control keys
                                pressed.
    "rawmouse rbutton"        A mouse move with the right mouse button
                                 down.
    "timer"                   A timer event.
As of commodities.library version 37.3, ParseIX(), the function used
to parse input description strings, does not parse certain classes
correctly.  Only the rawkey, diskremoved, and newprefs classes are
properly parsed.  For the moment, any commodity that needs to look
for the other classes must directly use Commodities Exchange's
internal format for input event descriptions, input expressions or
IX, discussed later in this article.

A filter has to be inserted into the Commodities network before it can
process any CxMessages.  AttachCxObj() adds a CxObject to the personal
list of another commodity.  The [HotKey.c](amiga-mail/xi-1-hotkey-c.md) example uses this function to
attach its filter to a broker.


```c
    void AttachCxObj(CxObj *HeadObj, CxObj *co);
```
This function uses the Exec function AddTail() to add the CxObject to
the end of HeadObj's personal list.  The position of a CxObject list
determines which CxObject gets CxMessages first.  Other functions
exist to add CxObjects at different points in the list (see the
commodities.doc Autodoc for details).

---

## See Also

- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
