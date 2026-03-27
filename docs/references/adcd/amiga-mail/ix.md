---
title: IX
manual: amiga-mail
chapter: amiga-mail
section: ix
functions: [CxObjError, ParseIX, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# IX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commodities Exchange does not use the input event description strings
discussed earlier to match input events.  Instead, Commodities
Exchange converts these strings to its own internal format.  These
input expressions are available for commodities to use instead of the
input description strings.

The following is the IX structure as defined in
<libraries/commodities.h>:


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
InputXpression structure.  The current version is defined as
IX_VERSION.  The ix_Class field contains the IECLASS_ constant (as
defined in <devices/inputevent.h>) of the particular class of i nput
event sought.  Commodities Exchange uses the ix_Code and ix_CodeMask
fields to match the ie_Code field of a struct InputEvent.  The bits of
ix_CodeMask indicate which bits are relevant in the ix_Code field when
trying to match against a ie_Code.  If any bits in ix_CodeMask are
off, Commodities Exchange does not consider the corresponding bit in
ie_Code when trying to match input events.  This is used primarily to
mask out the IECODE_UP_PREFIX bit of rawkey events, making it easier
to match both up an d down presses of a particular key.

IX's qualifier fields, ix_Qualifier, ix_QualMask, and ix_QualSame, are
used to match the ie_Qualifier field of an InputEvent structure.  The
ix_Qualifier and ix_QualMask fields work just like ix_Code and
ix_CodeMask.  The bits of ix_CodeMask indicate whic h bits are
relevant when comparing ix_Qualifier to ie_Qualifier.  The ix_QualSame
field tells Commodities Exchange that certain qualifiers are
equivalent.  The bits of this field can be set to any of the following
values:


    #define IXSYM_SHIFT  1  /* left- and right- shift are equivalent    */
    #define IXSYM_CAPS   2  /* either shift or caps lock are equivalent */
    #define IXSYM_ALT    4  /* left- and right- alt are equivalent      */
For example, the input description string


    "rawkey -caps -lalt -relativemouse -upstroke ralt tab"
matches a tab upstroke or downstroke with the right alt key pressed
whether or not the left alt, either shift, or the capslock keys are
down.  The following IX structure corresponds to that input
description string:


IX ix = {
```c
    IX_VERSION,             /* The version */
    IECLASS_RAWKEY,         /* We're looking for a RAWKEY event */
    0x42,                   /* The key the usa0 keymap maps to a tab */
    0x00FF & (~IECODE_UP_PREFIX), /* We want up and down key presses */
    IEQUALIFIER_RALT,             /* The right alt key must be down */
    0xFFFF & ~(IEQUALIFIER_LALT | IEQUALIFIER_LSHIFT | IEQUALIFIER_RSHIFT |
                IEQUALIFIER_CAPSLOCK | IEQUALIFIER_RELATIVEMOUSE),
                /* don't care about left alt, shift, capslock,
                   or relativemouse qualifiers */
    IXSYM_CAPS  /* The shift keys and the capslock
                   key qualifers are all equivalent */
```
};


The CxFilter() macro only accepts a description string to describe an
input event.  A commodity can change this filter, however.


```c
    void SetFilter( CxObj *filter, char *descrstring );
    void SetFilterIX( CxObj *filter, IX *ix );
```
SetFilter() and SetFilterIX() change which input events a filter
CxObject diverts.  SetFilter() accepts a pointer to an input
description string.  SetFilterIX() accepts a pointer to an IX input
expression.  A commodity that uses either of these functions should
check the filter's error code with CxObjError() to make sure the
change worked.


```c
    errorcode = LONG ParseIX( char *descrstring, IX *ix );
```
The function ParseIX() parses an input description string and
translates it into an IX input expression.  Commodities Exchange uses
ParseIX() to convert the description string in CxFilter() to an IX
input expression.  As was mentioned previously, as of co
mmodities.library version 37.3, ParseIX() does not work with certain
kinds of input strings.

This article is by no means an exhaustive description of Commodities
Exchange.  For more information, see the Commodities Exchange Autodocs
(commodities.doc for commodities.library and cx.doc for the macros and
linker library functions) and the sample commodities from the 1990
Atlanta DevCon disks.

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
