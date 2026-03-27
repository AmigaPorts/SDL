---
title: E / Release 2 Changes That Can Affect Compatibility / Intuition
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-intuition
functions: [AutoRequest, GetScreenData, GetVPModeID, LockPubScreen, NewModifyProp, OpenScreen, RefreshGList, ReplyMsg]
libraries: [exec.library, graphics.library, intuition.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Private [IntuitionBase](libraries/11-intuition-special-functions-locking-intuitionbase.md) variables have moved/changed.  Reading them is

    illegal.  Writing them is both illegal and dangerous.
  * Poking [IntuitionBase](libraries/11-intuition-special-functions-locking-intuitionbase.md) MaxMouse variables is now a no-op, but stop

    poking when Intuition version is >35.
  * If you are opening on the Workbench screen, be prepared to handle

```c
    larger screens, new modes, new fonts, and overscan.  Also see
    "[Fonts](libraries/e-release-2-changes-that-can-affect-compatibility-fonts.md)" compatibility information.
```
  * Screen TopEdge and LeftEdge may be negative.

  * Left-Amiga-Select is used for dragging large screens. Do not use

    left-Amiga-key combinations for application command keys.  The
    left-Amiga key is reserved for system use.
  * For compatibility reasons, [GetScreenData()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) lies if the Workbench

```c
    screen is a mode only available after 1.3.  It will try to return the
    most sensible mode that old [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) can open.  This was
    necessary to prevent problems in applications that cloned the
    Workbench screen. To properly handle new modes, see [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md),
    [GetVPModeID()](libraries/27-the-display-database-and-the-displayinfo-record.md), and the [SA_DisplayID](libraries/3-custom-screen-functions-screen-attributes.md) tag for [OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md).
```
  * Using combined RAWKEY and VANILLAKEY now gives [VANILLAKEY](libraries/9-event-message-classes-and-flags-other-flags.md) messages

```c
    for regular keys, and [RAWKEY](libraries/9-event-message-classes-and-flags-other-flags.md) messages for special keys (fkeys, help,
    etc.)
```
  * Moving a [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) window does not necessarily cause a

```c
    [REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) event because layers now preserves all the bits it can.
```
  * Sizing a [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) window will not clear it.

  * [MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md)/[REQVERIFY](libraries/9-event-message-classes-and-flags-requester-flags.md)/[SIZEVERIFY](libraries/9-event-message-classes-and-flags-window-flags.md) can time out if you take too long to

```c
    [ReplyMsg()](libraries/24-messages-replying.md).
```
  * Menu-key equivalents are ignored while string gadgets are active.

  * You can't type control characters into string gadgets by default.

    Use Ctrl-Amiga-char to type them in or use IControl Prefs to change
    the default behavior.
  * Width and Height parameters of [AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) are ignored.

  * New default colors, new gadget images.

  * JAM1 rendering/text in border may be invisible gadgets over default

    colors.
  * The cursor for string gadgets can no longer reside outside the

```c
    cleared container area.  If your gadget is 32 pixels wide, with
    [MaxChars](libraries/5-string-gadget-type-stringinfo-structure.md) of 4, all 32 pixels will be cleared, instead of just 24, as
    was true in 1.3.
```
  * Applications and requesters that fail to specify desired fonts will

```c
    get the fonts the user sets up in Font Preferences in Release 2.
    These could be much larger, or proportional in some cases.  Screen
    and window titlebars (and their gadgets) will be taller when
    accommodating a larger font.  Applications which open on the
    Workbench screen must adapt to variable size titlebars.  Any
    application which accepts system defaults for its screen, window,
    menu, Text or [IntuiText](libraries/8-creating-text-intuitext-structure.md) fonts must adapt to different fonts and
    titlebar sizes.  String gadgets whose height is too small for a font
    will revert to a smaller ROM font.  There are now 2 different
    user-specifiable default system fonts which affect different
    Intuition features.  This can lead to mismatches in mixed gadgets and
    text.  See the "[Intuition Screens](libraries/3-custom-screen-functions-screen-attributes.md)" chapter.
```
  * Don't modify gadgets directly without first removing them from the

```c
    gadget list, unless you are using a system function designed for that
    purpose, such as [NewModifyProp()](libraries/5-proportional-gadget-type-modifying-an-existing-gadget.md) or [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md).
```
  * Don't rely on [NewModifyProp()](libraries/5-proportional-gadget-type-modifying-an-existing-gadget.md) to fully refresh your prop gadget after

```c
    you've changed values in the structure.  NewModifyProp() will only
    correctly refresh changes which were passed to it as parameters.  Use
    [Remove](libraries/5-about-gadgets-adding-and-removing-gadgets.md)/[Add](libraries/5-about-gadgets-adding-and-removing-gadgets.md)/[RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) for other kinds of changes.
```
  * Custom screens must be of type CUSTOMSCREEN or PUBLICSCREEN.  Other

```c
    types are illegal.  One application opens its screen with
    [NewScreen.Type](libraries/3-custom-screen-functions-screen-attributes.md) = 0 (instead of [CUSTOMSCREEN](libraries/3-custom-screen-functions-screen-attributes.md), 0x0F).  Then, when it
    opens its windows, it specifies [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Type of 0 and
    NewWindow.Screen of NULL, instead of Type = [CUSTOMSCREEN](libraries/4-window-attributes-window-attribute-tags.md) and
    Screen = (their screen). That happened to work before, but no longer.
```
  * Referencing [IntuiMessage->IAddress](libraries/9-using-the-idcmp-intuimessages.md) as a [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) pointer on non-Gadget

```c
    IDCMP messages, or as a [Window](libraries/4-intuition-windows-the-window-structure.md) pointer (rather than looking at the
    proper field [IntuiMessage->IDCMPWindow](libraries/9-using-the-idcmp-intuimessages.md)) may now cause Enforcer hits
    or crashes.  The IAddress field always used to contain a pointer of
    some type even for IDCMP events for which no IAddress value is
    documented.  Now, for some IDCMP events, IAddress may contain a
    non-address, possibly an odd value that would crash a 68000 based
    system).
```
  * Using Intuition flags in the wrong structure fields (for example,

```c
    using ACTIVEWINDOW instead of ACTIVATE).  To alleviate this problem,
    2.0 has introduced new synonyms that are less confusing than the old
    ones.  For example, [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) and [WFLG_ACTIVATE](libraries/4-window-attributes-boolean-window-attribute-tags.md).  This
    particular example of confusion (there are several) was the nastiest,
    since IDCMP_ACTIVEWINDOW, when stuffed into NewWindow.Flags,
    corresponds numerically to [WFLG_NW_EXTENDED](libraries/4-window-attributes-extended-new-window.md), which informs Intuition
    that the [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure is immediately followed by a [TagItem](libraries/37-tags-tag-functions-and-structures.md),
    list which isn't there!  Intuition does some validation on the
    tag-list pointer, in order to partially compensate.  To make your
    compiler use the new synonyms only, add this line to your code before
    Intuition include files: #define INTUI_V36_NAMES_ONLY.
```
  * Do not place spaces into the [StringInfo->Buffer](libraries/5-string-gadget-type-stringinfo-structure.md) of a [GACT_LONGINT](libraries/5-gadget-structure-gadget-activation-flags.md)

```c
    string gadget. Under 1.3, this worked, but the 2.0 validation routine
    that checks for illegal keystrokes looks at the contents for illegal
    (i.e., non-numeric) characters, and if any are found assumes that the
    user typed an illegal keystroke.  The user's only options may be
    shift-delete or Amiga-X. Use the correct justification instead.
```
  * If you specify NULL for a font in an [IntuiText](libraries/8-creating-text-intuitext-structure.md), don't assume you'll

    get Topaz 8.  Either explicitly supply the font you you need or be
    prepared to size accordingly.  Otherwise, your rendering will be
    wrong, and the user will have to reset his Preferences just to make
    your software work right.
  * Window borders are now drawn in the screen's DetailPen and BlockPen

```c
    rather than the Window's pens.  For best appearance, you should pass
    an [SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md) array to [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md). This can be done in a backwards
    compatible manner with the [ExtNewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure and the [NS_EXTENDED](libraries/3-creating-a-new-custom-screen-a-custom-screen-example.md)
    flag.
```
  * The system now renders into the full width of window borders,

    although the widths themselves are unchanged.  Window borders are
    filled upon activation and inactivation.
  * Window border rendering has changed significantly for 2.0.  Note that

```c
    the border dimensions are unchanged from 1.x (Look at
    [Window->BorderLeft/Top/Right/Bottom](libraries/4-intuition-windows-the-window-structure.md) if you don't believe us!).  If
    your gadget intersects the border area, although it may have looked
    OK under 1.3, a visual conflict may occur under 2.0.  If Intuition
    notices a gadget which is substantially in the border but not
    declared as such, it treats it as though it were (this is called
    "bordersniffing").  Never rely on Intuition to sniff these out for
    you; always declare them explicitly (see the Gadget Activation flags
    [GACT_RIGHTBORDER](libraries/5-gadget-structure-gadget-activation-flags.md), etc.).  See "[Intuition Gadgets and Window Borders](libraries/e-additional-information-intuition-gadgets-and-window.md)"
    in the "Additional Information" section below.
```

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
