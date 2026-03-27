# E / Release 2 Changes That Can Affect Compatibility / Intuition


  * Private [IntuitionBase](../Libraries_Manual_guide/node01F6.html) variables have moved/changed.  Reading them is

    illegal.  Writing them is both illegal and dangerous.
  * Poking [IntuitionBase](../Libraries_Manual_guide/node01F6.html) MaxMouse variables is now a no-op, but stop

    poking when Intuition version is >35.
  * If you are opening on the Workbench screen, be prepared to handle

```c
    larger screens, new modes, new fonts, and overscan.  Also see
    "[Fonts](../Libraries_Manual_guide/node0571.html)" compatibility information.
```
  * Screen TopEdge and LeftEdge may be negative.

  * Left-Amiga-Select is used for dragging large screens. Do not use

    left-Amiga-key combinations for application command keys.  The
    left-Amiga key is reserved for system use.
  * For compatibility reasons, [GetScreenData()](../Libraries_Manual_guide/node00FC.html#line20) lies if the Workbench

```c
    screen is a mode only available after 1.3.  It will try to return the
    most sensible mode that old [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) can open.  This was
    necessary to prevent problems in applications that cloned the
    Workbench screen. To properly handle new modes, see [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34),
    [GetVPModeID()](../Libraries_Manual_guide/node033C.html#line19), and the [SA_DisplayID](../Libraries_Manual_guide/node00E5.html#line74) tag for [OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6).
```
  * Using combined RAWKEY and VANILLAKEY now gives [VANILLAKEY](../Libraries_Manual_guide/node01E1.html) messages

```c
    for regular keys, and [RAWKEY](../Libraries_Manual_guide/node01E1.html#line19) messages for special keys (fkeys, help,
    etc.)
```
  * Moving a [SIMPLE_REFRESH](../Libraries_Manual_guide/node0125.html#line110) window does not necessarily cause a

```c
    [REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) event because layers now preserves all the bits it can.
```
  * Sizing a [SIMPLE_REFRESH](../Libraries_Manual_guide/node0125.html#line110) window will not clear it.

  * [MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6)/[REQVERIFY](../Libraries_Manual_guide/node01DF.html#line8)/[SIZEVERIFY](../Libraries_Manual_guide/node01E0.html#line28) can time out if you take too long to

```c
    [ReplyMsg()](../Libraries_Manual_guide/node02F3.html).
```
  * Menu-key equivalents are ignored while string gadgets are active.

  * You can't type control characters into string gadgets by default.

    Use Ctrl-Amiga-char to type them in or use IControl Prefs to change
    the default behavior.
  * Width and Height parameters of [AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21) are ignored.

  * New default colors, new gadget images.

  * JAM1 rendering/text in border may be invisible gadgets over default

    colors.
  * The cursor for string gadgets can no longer reside outside the

```c
    cleared container area.  If your gadget is 32 pixels wide, with
    [MaxChars](../Libraries_Manual_guide/node016B.html#line49) of 4, all 32 pixels will be cleared, instead of just 24, as
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
    menu, Text or [IntuiText](../Libraries_Manual_guide/node01C7.html) fonts must adapt to different fonts and
    titlebar sizes.  String gadgets whose height is too small for a font
    will revert to a smaller ROM font.  There are now 2 different
    user-specifiable default system fonts which affect different
    Intuition features.  This can lead to mismatches in mixed gadgets and
    text.  See the "[Intuition Screens](../Libraries_Manual_guide/node00E5.html#line130)" chapter.
```
  * Don't modify gadgets directly without first removing them from the

```c
    gadget list, unless you are using a system function designed for that
    purpose, such as [NewModifyProp()](../Libraries_Manual_guide/node0163.html) or [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5).
```
  * Don't rely on [NewModifyProp()](../Libraries_Manual_guide/node0163.html) to fully refresh your prop gadget after

```c
    you've changed values in the structure.  NewModifyProp() will only
    correctly refresh changes which were passed to it as parameters.  Use
    [Remove](../Libraries_Manual_guide/node0133.html#line27)/[Add](../Libraries_Manual_guide/node0133.html#line7)/[RefreshGList()](../Libraries_Manual_guide/node0146.html) for other kinds of changes.
```
  * Custom screens must be of type CUSTOMSCREEN or PUBLICSCREEN.  Other

```c
    types are illegal.  One application opens its screen with
    [NewScreen.Type](../Libraries_Manual_guide/node00E5.html#line183) = 0 (instead of [CUSTOMSCREEN](../Libraries_Manual_guide/node00E5.html#line183), 0x0F).  Then, when it
    opens its windows, it specifies [NewWindow](../Libraries_Manual_guide/node0102.html#line20).Type of 0 and
    NewWindow.Screen of NULL, instead of Type = [CUSTOMSCREEN](../Libraries_Manual_guide/node0124.html#line91) and
    Screen = (their screen). That happened to work before, but no longer.
```
  * Referencing [IntuiMessage->IAddress](../Libraries_Manual_guide/node01D9.html#line73) as a [Gadget](../Libraries_Manual_guide/node0149.html) pointer on non-Gadget

```c
    IDCMP messages, or as a [Window](../Libraries_Manual_guide/node0121.html) pointer (rather than looking at the
    proper field [IntuiMessage->IDCMPWindow](../Libraries_Manual_guide/node01D9.html#line101)) may now cause Enforcer hits
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
    ones.  For example, [IDCMP_ACTIVEWINDOW](../Libraries_Manual_guide/node01E0.html#line36) and [WFLG_ACTIVATE](../Libraries_Manual_guide/node0125.html#line90).  This
    particular example of confusion (there are several) was the nastiest,
    since IDCMP_ACTIVEWINDOW, when stuffed into NewWindow.Flags,
    corresponds numerically to [WFLG_NW_EXTENDED](../Libraries_Manual_guide/node0123.html), which informs Intuition
    that the [NewWindow](../Libraries_Manual_guide/node0102.html#line20) structure is immediately followed by a [TagItem](../Libraries_Manual_guide/node0497.html),
    list which isn't there!  Intuition does some validation on the
    tag-list pointer, in order to partially compensate.  To make your
    compiler use the new synonyms only, add this line to your code before
    Intuition include files: #define INTUI_V36_NAMES_ONLY.
```
  * Do not place spaces into the [StringInfo->Buffer](../Libraries_Manual_guide/node016B.html#line19) of a [GACT_LONGINT](../Libraries_Manual_guide/node014B.html#line91)

```c
    string gadget. Under 1.3, this worked, but the 2.0 validation routine
    that checks for illegal keystrokes looks at the contents for illegal
    (i.e., non-numeric) characters, and if any are found assumes that the
    user typed an illegal keystroke.  The user's only options may be
    shift-delete or Amiga-X. Use the correct justification instead.
```
  * If you specify NULL for a font in an [IntuiText](../Libraries_Manual_guide/node01C7.html), don't assume you'll

    get Topaz 8.  Either explicitly supply the font you you need or be
    prepared to size accordingly.  Otherwise, your rendering will be
    wrong, and the user will have to reset his Preferences just to make
    your software work right.
  * Window borders are now drawn in the screen's DetailPen and BlockPen

```c
    rather than the Window's pens.  For best appearance, you should pass
    an [SA_Pens](../Libraries_Manual_guide/node00E5.html#line82) array to [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6). This can be done in a backwards
    compatible manner with the [ExtNewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure and the [NS_EXTENDED](../Libraries_Manual_guide/node00E1.html#line15)
    flag.
```
  * The system now renders into the full width of window borders,

    although the widths themselves are unchanged.  Window borders are
    filled upon activation and inactivation.
  * Window border rendering has changed significantly for 2.0.  Note that

```c
    the border dimensions are unchanged from 1.x (Look at
    [Window->BorderLeft/Top/Right/Bottom](../Libraries_Manual_guide/node0121.html#line71) if you don't believe us!).  If
    your gadget intersects the border area, although it may have looked
    OK under 1.3, a visual conflict may occur under 2.0.  If Intuition
    notices a gadget which is substantially in the border but not
    declared as such, it treats it as though it were (this is called
    "bordersniffing").  Never rely on Intuition to sniff these out for
    you; always declare them explicitly (see the Gadget Activation flags
    [GACT_RIGHTBORDER](../Libraries_Manual_guide/node014B.html#line56), etc.).  See "[Intuition Gadgets and Window Borders](../Libraries_Manual_guide/node0575.html)"
    in the "Additional Information" section below.
```
