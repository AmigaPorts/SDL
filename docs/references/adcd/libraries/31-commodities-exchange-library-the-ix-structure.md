---
title: 31 Commodities Exchange Library / The IX Structure
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-the-ix-structure
functions: [CxObjError, ParseIX, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / The IX Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commodities Exchange does not use the input event description strings
discussed earlier to match input events.  Instead, Commodities Exchange
converts these strings to its own internal format.  These input
expressions are available for commodities to use instead of the input
description strings.  The following is the IX structure as defined in
<libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>:


```c
    #define IX_VERSION   2

    struct InputXpression {
       UBYTE   ix_Version;     /* must be set to IX_VERSION  */
       UBYTE   ix_Class;       /* class must match exactly   */
       UWORD   ix_Code;
       UWORD   ix_CodeMask;    /* normally used for UPCODE   */
       UWORD   ix_Qualifier;
       UWORD   ix_QualMask;
       UWORD   ix_QualSame;    /* synonyms in qualifier      */
       };
    typedef struct InputXpression IX;
```
The ix_Version field contains the current version number of the
InputXpression structure.  The current version is defined as IX_VERSION.
The ix_Class field contains the [IECLASS_](libraries/31-commodities-exchange-filter-objects-and-input.md) constant (defined in
<devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md)>) of the class of input event sought.  Commodities
Exchange uses the ix_Code and ix_CodeMask fields to match the ie_Code
field of a struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md).  The bits of ix_CodeMask indicate which bits
are relevant in the ix_Code field when trying to match against a ie_Code.
If any bits in ix_CodeMask are off, Commodities Exchange does not consider
the corresponding bit in ie_Code when trying to match input events.  This
is used primarily to mask out the [IECODE_UP_PREFIX](autodocs-2.0/includes-devices-inputevent-h.md) bit of rawkey events,
making it easier to match both up and down presses of a particular key.

IX's qualifier fields, ix_Qualifier, ix_QualMask, and ix_QualSame, are
used to match the ie_Qualifier field of an [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) structure.  The
ix_Qualifier and ix_QualMask fields work just like ix_Code and
ix_CodeMask.  The bits of ix_QualMask indicate which bits are relevant
when comparing ix_Qualifier to ie_Qualifier.  The ix_QualSame field tells
Commodities Exchange that certain qualifiers are equivalent:


    #define IXSYM_SHIFT  1  /* left- and right- shift are equivalent     */
    #define IXSYM_CAPS   2  /* either shift or caps lock are equivalent  */
    #define IXSYM_ALT    4  /* left- and right- alt are equivalent       */
For example, the input description string


    "rawkey -caps -lalt -relativemouse -upstroke ralt tab"
matches a tab upstroke or downstroke with the right Alt key pressed
whether or not the left Alt, either Shift, or the Caps Lock keys are down.
The following IX structure corresponds to that input description string:


```c
    IX ix = {
        IX_VERSION,             /* The version */
        IECLASS_RAWKEY,         /* We're looking for a RAWKEY event */
        0x42,                   /* The key the usa0 keymap maps to a tab */
        0x00FF & (~IECODE_UP_PREFIX), /* We want up and down key presses */
        IEQUALIFIER_RALT,             /* The right alt key must be down */
        0xFFFF & ~(IEQUALIFIER_LALT | IEQUALIFIER_LSHIFT |
                   IEQUALIFIER_RSHIFT | IEQUALIFIER_CAPSLOCK |
                   IEQUALIFIER_RELATIVEMOUSE),
                   /* don't care about left alt, shift, capslock, or */
                   /* relativemouse qualifiers                       */
        IXSYM_CAPS  /* The shift keys and the capslock key */
                    /* qualifiers are all equivalent       */
    };
```
The [CxFilter()](libraries/31-commodities-exchange-filter-objects-and-input.md) macro only accepts a description string to describe an
input event.  A commodity can change this filter, however, with the
[SetFilter()](autodocs-2.0/commodities-library-setfilter.md) and [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md) function calls.


```c
    void SetFilter( CxObj *filter, UBYTE *descrstring );
    void SetFilterIX( CxObj *filter, IX *ix );
```
[SetFilter()](autodocs-2.0/commodities-library-setfilter.md) and [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md) change which input events a [filter CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md)
diverts.  SetFilter() accepts a pointer to an input description string.
SetFilterIX() accepts a pointer to an IX input expression.  A commodity
that uses either of these functions should check the filter's error code
with [CxObjError()](libraries/31-commodities-exchange-library-cxobject-errors.md) to make sure the change worked.

The function [ParseIX()](autodocs-2.0/commodities-library-parseix.md) parses an input description string and translates
it into an IX input expression.


```c
    errorcode = LONG ParseIX( UBYTE *descrstring, IX *ix );
```
Commodities Exchange uses [ParseIX()](autodocs-2.0/commodities-library-parseix.md) to convert the description string in
[CxFilter()](libraries/31-commodities-exchange-filter-objects-and-input.md) to an IX input expression.  As was mentioned previously, as of
commodities.library version 37.3, ParseIX() does not work with certain
kinds of input strings.

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
