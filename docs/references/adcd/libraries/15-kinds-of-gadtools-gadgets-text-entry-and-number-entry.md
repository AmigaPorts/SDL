---
title: 15 / / Kinds of GadTools Gadgets / Text-Entry and Number-Entry Gadgets
manual: libraries
chapter: libraries
section: 15-kinds-of-gadtools-gadgets-text-entry-and-number-entry
functions: [CreateGadgetA, GT_SetGadgetAttrsA]
libraries: [gadtools.library]
---

# 15 / / Kinds of GadTools Gadgets / Text-Entry and Number-Entry Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Text-entry (STRING_KIND) and number-entry (INTEGER_KIND) gadgets are
fairly typical Intuition string gadgets.  The typing area is contained by
a border which is a raised ridge.

Text-entry gadgets accept the following tags:

GTST_String (STRPTR)

```c
    A pointer to the string to be placed into the text-entry gadget
    buffer or NULL to get an empty text-entry gadget.  The string itself
    is actually copied into the gadget's buffer.  The default is NULL.
    (Create and set.)
```
GTST_MaxChars (UWORD)


```c
    The maximum number of characters that the text-entry gadget should
    hold.  The string buffer that gets created for the gadget will
    actually be one bigger than this number, in order to hold the
    trailing NULL.  The default is 64.  (Create only.)
```
Number-entry gadgets accept the following tags:

GTIN_Number (ULONG)

```c
    The number to be placed into the number-entry gadget.  The default is
    zero. (Create and set.)
```
GTIN_MaxChars (UWORD)


```c
    The maximum number of digits that the number-entry gadget should
    hold.  The string buffer that gets created for the gadget will
    actually be one bigger than this, in order to hold the trailing NULL.
    The default is 10. (Create only.)
```
Both text-entry and number-entry gadgets, which are collectively called
string gadgets, accept these common tags:

STRINGA_Justification

```c
    This attribute controls the placement of the string or number within
    its box and can be one of [GACT_STRINGLEFT](libraries/5-gadget-structure-gadget-activation-flags.md), [GACT_STRINGRIGHT](libraries/5-gadget-structure-gadget-activation-flags.md) or
    [GACT_STRINGCENTER](libraries/5-gadget-structure-gadget-activation-flags.md).  The default is GACT_STRINGLEFT.  (Create only.)
```
STRINGA_ReplaceMode (BOOL)

```c
    Set STRINGA_ReplaceMode to TRUE to get a string gadget which is in
    replace-mode, as opposed to auto-insert mode.  (Create only.)
```
GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable the string gadget, otherwise to
    FALSE.  The default is FALSE.  (Create and set.)
```
STRINGA_ExitHelp (BOOL)

```c
    (New for V37, ignored under V36).  Set this attribute to TRUE if the
    application wants to hear the Help key from within this string
    gadget.  This feature allows the program to hear the press of the
    Help key in all cases.  If TRUE, pressing the help key while this
    gadget is active will terminate the gadget and send a message.  The
    program will receive an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message having a [Code](libraries/9-using-the-idcmp-intuimessages.md) value of
    0x5F, the rawkey code for Help.  Typically, the program will want to
    reactivate the gadget after performing the help-display.  The default
    is FALSE.  (Create only.)
```
GA_TabCycle (BOOL)

```c
    (New for V37, ignored under V36).  If the user types Tab or Shift Tab
    into a GA_TabCycle gadget, Intuition will activate the next or
    previous such gadget in sequence.  This gives the user easy keyboard
    control over which text-entry or number-entry gadget is active.  Tab
    moves to the next GA_TabCycle gadget in the gadget list and Shift Tab
    moves to the previous one.  When the user presses Tab or Shift Tab,
    Intuition will deactivate the gadget and send this program an
    [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message with the code field set to 0x09, the ASCII
    value for a tab.  Intuition will then activate the next indicated
    gadget.  Check the shift bits of the qualifier field to learn if
    Shift Tab was typed.  The ordering of the gadgets may only be
    controlled by the order in which they were added to the window.  For
    special cases, for example, if there is only one string gadget in the
    window, this feature can be suppressed by specifying the tagitem pair
    {GA_TabCycle, FALSE}.  The default is TRUE.  (Create only.)
```
GTST_EditHook (struct Hook *)

```c
    (New for V37, ignored under V36).  Pointer to a custom editing hook
    for this string or integer gadget.  See the "[Intuition Gadgets](libraries/5-string-gadget-type-custom-string-editing.md)"
    chapter for more information on string gadget edit-hooks.
```
As with all Intuition string gadgets, the program will receive an
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message only when the user presses Enter, Return, Help, Tab
or Shift Tab while typing in the gadget.  Note that, like Intuition string
gadgets, the program will not hear anything if the user deactivates the
string gadget by clicking elsewhere.  Therefore, it is a good idea to
always check the string gadget's buffer before using its contents, instead
of just tracking its value as IDCMP_GADGETUP messages are received for
this gadget.

Be sure the code is designed so that nothing drastic happens, like closing
a requester or opening a file, if the [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message has a
non-zero [Code](libraries/9-using-the-idcmp-intuimessages.md) field; the program will want to handle the Tab and Help
cases intelligently.

To read the string gadget's buffer, look at the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)'s [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) [Buffer](libraries/5-string-gadget-type-stringinfo-structure.md):


```c
    ((struct StringInfo *)gad->SpecialInfo)->Buffer
```
To determine the value of an integer gadget, look at the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)'s
[StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) [LongInt](libraries/5-string-gadget-type-stringinfo-structure.md) in the same way.

Always use the GTST_String or GTIN_Number tags to set these values.  Never
write to the [StringInfo->Buffer](libraries/5-string-gadget-type-stringinfo-structure.md) or [StringInfo->LongInt](libraries/5-string-gadget-type-stringinfo-structure.md) fields directly.

GadTools string and integer gadgets do not directly support the
GA_Immediate property (which would cause Intuition to send an
[IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) event when such a gadget is first selected).  However,
this property can be very important.  Therefore, the following technique
can be used to enable this property.


```c
    Warning:
    --------
    Note that the technique shown here relies on directly setting flags
    in a GadTools gadget; this is not normally allowed since it hinders
    future compatibility.  Do not attempt to change other flags or
    properties of GadTools gadgets except through the defined interfaces
    of [CreateGadgetA()](libraries/15-gadtools-gadgets-creating-gadgets.md) and [GT_SetGadgetAttrsA()](libraries/15-gadtools-gadgets-modifying-gadgets.md).  Directly modifying
    flags or properties is legal only when officially sanctioned by
    Amiga, Inc..
```
To get the GA_Immediate property, pass the {GA_Immediate,TRUE} tag to
[CreateGadgetA()](libraries/15-gadtools-gadgets-creating-gadgets.md).  Even though this tag is ignored for string and integer
gadgets under V37, this will allow future versions of GadTools to learn of
your request in the correct way.  Then, under V37 only, set the
[GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) flag in the gadget's [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field:


```c
    gad = CreateGadget( STRING_KIND, gad, &ng,
            /* string gadget tags go here */
            GTST_...,

            /* Add this tag for future GadTools releases */
            GA_Immediate, TRUE,
            ...
            TAG_DONE );

    if ( ( gad ) && ( GadToolsBase->lib_Version == 37) )
    {
            /* Under GadTools V37 only, set this attribute
             * directly.  Do not set this attribute under
             * future versions of GadTools, or for gadgets
             * other than STRING_KIND or INTEGER_KIND.
             */
            gad->Activation |= GACT_IMMEDIATE;
    }
```

---

## See Also

- [CreateGadgetA — gadtools.library](../autodocs/gadtools.library.md#creategadgeta)
- [GT_SetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_setgadgetattrsa)
