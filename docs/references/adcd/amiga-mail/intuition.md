---
title: Intuition
manual: amiga-mail
chapter: amiga-mail
section: intuition
functions: [GetScreenData, GetVPModeID, LockPubScreen, NewModifyProp, OpenScreen, RefreshGList, ReplyMsg]
libraries: [exec.library, graphics.library, intuition.library]
---

# Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Private IBase variables have moved/changed.  Reading them is illegal.
  Writing them is both illegal and dangerous.

* Poking IBase MaxMouse variables is now a no-op, but please stop poking
  when Intuition version is >35.

* If you are opening on the Workbench screen, be prepared to handle
  larger screens, new modes, new fonts, and overscan.  Also see Font
  compatibility information. o Screen TopEdge and LeftEdge may be negative.

* LeftAmiga-Select is used for dragging large screens.  Do not use
  LeftAmiga-key combinations for application command keys.  The LeftAmiga
  key is reserved for system use.

* For compatibility reasons, GetScreenData() lies if the Workbench
  screen is a mode only available after release 1.3.  It will try to
  return the most sensible mode that old OpenScreen() can open.  This was
  necessary to keep applications that cloned the Workbench screen from
  having problems.  To properly handle new modes, see LockPubScreen() and
  GetVPModeID(), and the SA_DisplayID tag for OpenScreenTags().

* Using combined RAWKEY and VANILLAKEY now gives VANILLAKEY messages for
  regular keys, and RAWKEY messages for special keys (fkeys, help, etc.)

* Moving a SIMPLE_REFRESH window does not necessarily cause a
  REFRESHWINDOW event because layers now preserves all the bits it can.

* Sizing a SIMPLE_REFRESH window will not clear it.

* MENUVERIFY/REQVERIFY/SIZEVERIFY can time out if you take too long to
  ReplyMsg().

* Menu-key equivalents are ignored while string gadgets are active.

* You can't type control characters into string gadgets by default.  Use
  CTRL-Amiga-char to type them in or use IControl Prefs to change the
  default behavior.

* Width and Height parameters of AutoRequest are ignored.

* New default colors, new gadget images.

* JAM1 rendering/text in border may be invisible gadgets over default
  colors.

* The cursor for string gadgets can no longer reside outside the cleared
  container area.  If your gadget is (for example) 32 pixels wide, with
  MaxChars of 4, then all 32 pixels will be cleared, instead of just 24,
  as was true in 1.3.

* Applications and requesters that fail to specify desired fonts will
  get user 2.0 Font Pref fonts that may be much larger or proportional in
  some cases.  Screen and window titlebars (and their gadgets) will be
  taller when accomodating a larger font.  Applications which open on the
  Workbench screen must adapt to variable size titlebars.  Any application
  which accepts system defaults for its screen, window, menu, Text or
  IntuiText fonts must adapt to different fonts and titlebar sizes.
  String gadgets whose height is too small for a font will revert to a
  smaller ROM font.  There are now 2 different user-specifiable default
  system fonts which affect different Intuition features.  This can lead
  to mismatches in mixed gadgets and text.  For more information on where
  various system fonts come from and how they can be controlled, see
  Intuition Fonts in the Additional Information section at the end of this
  document.

* Don't modify gadgets directly without first removing them from the
  gadget list, unless you are using a system function designed for that
  purpose, such as NewModifyProp() or SetGadgetAttrs().

* Don't rely on NewModifyProp() to fully refresh your prop gadget after
  you've changed values in the structure.  NewModifyProp() will only
  correctly refresh changes which were passed to it as parameters.  Use
  Remove/Add/RefreshGList() for other kinds of changes.

* Custom screens must be of type CUSTOMSCREEN or PUBLICSCREEN.  Other
  types are illegal.  One application opens their screen with
  NewScreen.Type = 0 (instead of CUSTOMSCREEN, 0x0F).  Then, when they
  open their windows, they specify NewWindow.Type of 0 and
  NewWindow.Screen of NULL, instead of Type=CUSTOMSCREEN and Screen=(their
  screen).  That happened to work before, but they are now broken.

* Referencing IntuiMessage->IAddress as a Gadget pointer on non-Gadget
  IDCMP messages, or as a Window pointer (rather than looking at the
  proper field IntuiMessage->IDCMPWindow) may now cause Enforcer hits or
  crashes.  The IAddress field used to always contain a pointer of some
  type even for IDCMP events for which no IAddress value is documented.
  Now, for some IDCMP events, IAddress may contain other data (a
  non-address, possibly an odd value which would crash a 68000 based
  system).

* Using Intuition flags in the wrong structure fields (for example,
  using ACTIVEWINDOW instead of ACTIVATE).  To alleviate this problem, 2.0
  has introduced modern synonyms that are less confusing than the old
  ones.  For example, IDCMP_ACTIVEWINDOW and WFLG_ACTIVATE.  This
  particular example of confusion (there are several) was the nastiest,
  since IDCMP_ACTIVEWINDOW, when stuffed into NewWindow.Flags, corresponds
  numerically to WFLG_NW_EXTENDED, which informs Intuition that the
  NewWindow structure is immediately followed by a TagList, which isn't
  there!  Intuition does some validation on the tag-list pointer, in order
  to partially compensate.  To make your compiler use the new synonyms
  only, add this line to your code before Intuition include files: #define
  INTUI_V36_NAMES_ONLY.

* Do not place spaces into the StringInfo->Buffer of a LONGINT string
  gadget. Under 1.3, it turned out that worked, but under 2.0, the
  validation routine that checks for illegal keystrokes looks at the
  contents for illegal (i.e. non-numeric) characters, and if any are found
  assumes that the user typed an illegal keystroke.  The user's only
  options may be shift-delete or Amiga-X. Use the correct justification
  instead.

* If you specify NULL for a font in an IntuiText, don't assume you'll
  get Topaz 8.  Either explicitly supply the font you you need or be
  prepared to size accordingly.  Otherwise, your rendering will be wrong,
  and the user will have to reset his Preferences just to make your
  software work right.

* Window borders are now drawn in the screen's DetailPen and BlockPen
  rather than the Window's pens.  For best appearance, you should pass a
  SA_Pens array to OpenScreen().  This can be done in a backwards
  compatible manner with the ExtNewScreen structure and the NS_EXTENDED
  flag.

* The system now renders into the full width of window borders, although
  the widths themselves are unchanged.

* Window borders are filled upon activation and inactivation.

* Window border rendering has changed significantly for 2.0.  Note that
  the border dimensions are unchanged from 1.x (Look at
  window->BorderLeft/Top/Width/Height if you don't believe us!).  If your
  gadget intersects the border area, although it may have looked OK under
  1.3, a visual conflict may occur under 2.0.  If Intuition notices a
  gadget which is substantially in the border but not declared as such, it
  treats it as though it were (this is called ``bordersniffing'').  Never
  rely on Intuition to sniff these out for you; always declare them
  explicitly (see the Gadget Activation flags GACT_RIGHTBORDER etc.).  See
  Intuition Gadgets and Window Borders in the Additional Information
  section at the end of this article.

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
