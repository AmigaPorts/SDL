---
title: 15 / / The Kinds of GadTools Gadgets / Slider Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-slider-gadgets
functions: [RawDoFmt]
libraries: [exec.library]
---

# 15 / / The Kinds of GadTools Gadgets / Slider Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sliders are one of the two kinds of proportional gadgets offered by
GadTools.  Slider gadgets (SLIDER_KIND) are used to control an amount, a
level or an intensity, such as volume or color.  Scroller gadgets
(SCROLLER_KIND) are discussed below.

Slider gadgets accept the following tags:

GTSL_Min (WORD)

```c
    The minimum level of a slider.  The default is zero.  (Create and
    set.)
```
GTSL_Max (WORD)

```c
    The maximum level of a slider.  The default is 15.  (Create and set.)
```
GTSL_Level (WORD)

```c
    The current level of a slider. The default is zero. When the level is
    at its minimum, the knob will be all the way to the left for a
    horizontal slider or all the way at the bottom for a vertical slider.
    Conversely, the maximum level corresponds to the knob being to the
    extreme right or top.  (Create and set.)
```
GTSL_LevelFormat (STRPTR)

```c
    The current level of the slider may be displayed in real-time
    alongside the gadget.  To use the level-display feature, the program
    must be using a monospace font for this gadget.

    GTSL_LevelFormat specifies a [printf()](autodocs-2.0/amiga-lib-printf.md)-style formatting string used to
    render the slider level beside the slider (the complete set of
    formatting options is described in the Exec library function
    [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md)).  Be sure to use the `l' (long word) modifier for the
    number.  Field-width specifiers may be used to ensure that the
    resulting string is always of constant width.  The simplest would be
    "%2ld".  A 2-digit hexadecimal slider might use "%02lx", which adds
    leading zeros to the number.  Strings with extra text, such as "%3ld
    hours", are permissible.  If this tag is specified, the program must
    also provide GTSL_MaxLevelLen.  By default, the level is not
    displayed.  (Create only.)
```
GTSL_MaxLevelLen (UWORD)

```c
    The maximum length of the string that will result from the given
    level-formatting string.  If this tag is specified, the program must
    also provide GTSL_LevelFormat.  By default, the level is not
    displayed.  (Create only.)
```
GTSL_LevelPlace

```c
    To choose where the optional display of the level is positioned.  It
    must be one of PLACETEXT_LEFT, PLACETEXT_RIGHT, PLACETEXT_ABOVE or
    PLACETEXT_BELOW.  The level may be placed anywhere with the following
    exception: the level and the label may not be both above or both
    below the gadget.  To place them both on the same side, allow space
    in the gadget's label (see the example).  The default is
    PLACETEXT_LEFT.  (Create only.)
```
GTSL_DispFunc (LONG (*function)(struct Gadget *, WORD))

```c
    Optional function to convert the level for display.  A slider to
    select the number of colors for a screen may operate in screen depth
    (1 to 5, for instance), but actually display the number of colors (2,
    4, 8, 16 or 32).  This may be done by providing a GTSL_DispFunc
    function which returns 1 << level.  The function must take a pointer
    to the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) as the first parameter and the level, a WORD, as the
    second and return the result as a LONG.  The default behavior for
    displaying a level is to do so without any conversion.  (Create only.)
```
GA_Immediate (BOOL)

```c
    Set this to TRUE to receive an [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) when the
    user presses the mouse button over the slider.  The default is FALSE.
    (Create only.)
```
GA_RelVerify (BOOL)

```c
    Set this to TRUE to receive an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) when the
    user releases the mouse button after using the slider.  The default
    is FALSE.  (Create only.)
```
PGA_Freedom

```c
    Specifies which direction the knob may move.  Set to LORIENT_VERT for
    a vertical slider or LORIENT_HORIZ for a horizontal slider.  The
    default is LORIENT_HORIZ.  (Create only.)
```
GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable the slider, to FALSE otherwise.
    The default is FALSE.  (Create and set.)
```
Up to three different classes of [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) may be received at the port
when the user plays with a slider, these are [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md),
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) and [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md).  The program may examine the
IntuiMessage [Code](libraries/9-using-the-idcmp-intuimessages.md) field to discover the slider's level.

[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s will be heard whenever the slider's level
changes.  IDCMP_MOUSEMOVE IntuiMessages will not be heard if the knob has
not moved far enough for the level to actually change.  For example if the
slider runs from 0 to 15 and is currently set to 12, if the user drags the
slider all the way up the program will hear no more than three
IDCMP_MOUSEMOVEs, one each for 13, 14 and 15.

If {GA_Immediate, TRUE} is specified, then the program will always hear an
[IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) when the user begins to adjust a slider.  If
{GA_RelVerify, TRUE} is specified, then the program will always hear an
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) IntuiMessage when the user finishes adjusting the slider.
If IDCMP_GADGETUP or IDCMP_GADGETDOWN IntuiMessages are requested, the
program will always hear them, even if the level has not changed since the
previous IntuiMessage.

Note that the Code field of the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) structure is a UWORD, while
the slider's level may be negative, since it is a WORD.  Be sure to copy
or cast the [IntuiMessage->Code](libraries/9-using-the-idcmp-intuimessages.md) into a WORD if the slider has negative
levels.

If the user clicks in the container next to the knob, the slider level
will increase or decrease by one.  If the user drags the knob itself, then
the knob will snap to the nearest integral position when it is released.

Here is an example of the screen-depth slider discussed earlier:


```c
    /* NewGadget initialized here. Note the three spaces
     * after "Slider:", to allow a blank plus the two digits
     * of the level display
     */
    ng.ng_Flags = PLACETEXT_LEFT;
    ng.ng_GadgetText = "Slider:   ";

    LONG DepthToColors(struct Gadget *gad, WORD level)
    {
    return ((WORD)(1 << level));
    }

    ...

    gad = CreateGadget(SLIDER_KIND, gad, &ng,
        GTSL_Min, 1,
        GTSL_Max, 5,
        GTSL_Level, current_depth,
        GTSL_MaxLevelLen, 2,
        GTSL_LevelFormat, "%2ld",
        GTSL_DispFunc, DepthToColors,
        TAG_END);
```

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
