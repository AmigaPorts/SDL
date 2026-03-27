---
title: gadtools.library/GT_SetGadgetAttrsA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-setgadgetattrsa
functions: [GT_BeginRefresh, GT_EndRefresh, GT_SetGadgetAttrsA]
libraries: [gadtools.library]
---

# gadtools.library/GT_SetGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_SetGadgetAttrsA -- Change the attributes of a GadTools gadget. (V36)
    GT_SetGadgetAttrs -- Varargs stub for GT_SetGadgetAttrsA(). (V36)
```
SYNOPSIS

```c
    GT_SetGadgetAttrsA(gad, win, req, taglist)
                       A0   A1   A2   A3

    VOID GT_SetGadgetAttrsA(struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
        struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    GT_SetGadgetAttrs(gad, win, req, firsttag, ...)

    VOID GT_SetGadgetAttrs(struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
        struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, Tag, ...);
```
FUNCTION

    Change the attributes of the specified gadget, according to the
    attributes chosen in the tag list.
INPUTS

```c
    gad - Pointer to the gadget in question.
    win - Pointer to the window containing the gadget.
    req - Pointer to the requester containing the gadget, or NULL if
        not in a requester.  (Not yet implemented, use NULL).
    taglist - Pointer to [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.
```
TAGS

```c
    BUTTON_KIND:
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CHECKBOX_KIND:
    GTCB_Checked (BOOL) - Initial state of checkbox, defaults to FALSE.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CYCLE_KIND:
    GTCY_Active (UWORD) - The ordinal number (counting from zero) of
        the active choice of a cycle gadget (defaults to zero).
    GTCY_Labels (STRPTR *) - (GadTools V37 and higher only)
        Pointer to NULL-terminated array of strings
        that are the choices offered by the cycle gadget.
    GA_Disabled (BOOL) - (GadTools V37 and higher only)
        Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    INTEGER_KIND:
    GTIN_Number (ULONG) - The initial contents of the integer gadget
        (default zero).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    LISTVIEW_KIND:
    GTLV_Top (WORD) - Top item visible in the listview.  This value
        will be made reasonable if out-of-range (defaults to zero).
    GTLV_Labels (struct [List](autodocs-2.0/includes-exec-lists-h.md) *) - [List](autodocs-2.0/includes-exec-lists-h.md) of labels whose ln_Name fields
        are to be displayed in the listview.  Use a value of ~0 to
        "detach" your [List](autodocs-2.0/includes-exec-lists-h.md) from the display.  You must detach your list
        before modifying the [List](autodocs-2.0/includes-exec-lists-h.md) structure, since GadTools reserves
        the right to traverse it on another task's schedule.  When you
        are done, attach the list by using the tag pair
        {GTLV_Labels, list}.
    GTLV_Selected (UWORD) - Ordinal number of currently selected
        item (defaults to zero if GTLV_ShowSelected is set).

    MX_KIND:
    GTMX_Active (UWORD) - The ordinal number (counting from zero) of
        the active choice of an mx gadget (Defaults to zero).

    NUMBER_KIND:
    GTNM_Number - A signed long integer to be displayed as a read-only
         number (default 0).

    PALETTE_KIND:
    GTPA_Color (UBYTE) - Initially selected color of the palette
        (defaults to 1).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SCROLLER_KIND:
    GTSC_Top (WORD) - Top visible in scroller (defaults to zero).
    GTSC_Total (WORD) - Total in scroller area (defaults to zero).
    GTSC_Visible (WORD) - Number visible in scroller (defaults to 2).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SLIDER_KIND:
    GTSL_Min (WORD) - Minimum level for slider (default 0).
    GTSL_Max (WORD) - Maximum level for slider (default 15).
    GTSL_Level (WORD) - Current level of slider (default 0).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    STRING_KIND:
    GTST_String (STRPTR) - The initial contents of the string gadget,
         or NULL (default) if string is to start empty.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    TEXT_KIND:
    GTTX_Text - Pointer to a NULL terminated string to be displayed,
        as a read-only text-display gadget, or NULL. defaults to NULL.
```
RESULT

    None.
EXAMPLE

NOTES

```c
    req must currently be NULL.  GadTools gadgets are not supported
    in requesters.  This field may allow such support at a future date.

    This function may not be called inside of a [GT_BeginRefresh()](autodocs-2.0/gadtools-library-gt-beginrefresh.md) /
    [GT_EndRefresh()](autodocs-2.0/gadtools-library-gt-endrefresh.md) session.  (As always, restrict yourself to simple
    rendering functions).
```
BUGS

SEE ALSO

---

## See Also

- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
- [GT_SetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_setgadgetattrsa)
