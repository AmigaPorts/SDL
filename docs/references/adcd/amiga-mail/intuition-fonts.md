---
title: Intuition Fonts
manual: amiga-mail
chapter: amiga-mail
section: intuition-fonts
functions: [LockPubScreen, OpenWindow, PrintIText, SetFont, Text]
libraries: [graphics.library, intuition.library]
---

# Intuition Fonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following table shows where the Intuition gets its fonts from:


   What you tell OpenScreen  Screen's Font          Windows' RPort's Font
   ------------------------  -------------          ---------------------
A. NewScreen.Font = myfont  myfont                          myfont
B. NewScreen.Font = NULL    GfxBase->DefaultFont    GfxBase->DefaultFont
C. {SA_Font, myfont}        myfont                          myfont
D. {SA_SysFont, 0}          GfxBase->DefaultFont    GfxBase->DefaultFont
E. {SA_SysFont, 1}          Font Prefs Screen text  GfxBase->DefaultFont


Notes:

  A and B are the options that existed in releases prior to V36.

  C and D are new V36 tags that are equivalent to A and B respectively.

  E is a NEW option for V36.  The Workbench screen uses this option.

  GfxBase->DefaultFont will always be monospace.  This is the
  ``System Default Text'' from Font Preferences.

  The ``Screen Text'' choice from Font Preferences can be monospace or
  proportional.

  'myfont' can be any font of the programmer's choosing, including a
  proportional one.  This is true under all releases of the OS.


The menu bar, window titles, menu-items, and the contents of a string
gadget use the screen's font.  The font used for menu items can be
overridden in the item's IntuiText structure.  Under V36 and higher, the
font used in a string gadget can be overridden through the StringExtend
structure.  The font of the menu bar and window titles cannot be
overridden.  Because the 2.0 Workbench screen uses option E to specify its
Screen font from the user's Screen font Preferences, applications which
open windows on the Workbench screen may get very large or proportional
fonts in their menu bars, window titles, menu-items and string gadgets.

To predict your window's titlebar height before you call OpenWindow():


```c
    topborder = screen->WBorTop + screen->Font->ta_YSize + 1
```
The screen's font may not legally be changed after a screen is opened.

Be sure the screen cannot go away on you.  This is true if:


```c
    1) You opened the screen yourself.
    2) You currently have a window open on the screen.
    3) You currently hold a lock on this screen (see LockPubScreen() ).
```
IntuiText rendered into a window (either through PrintIText() or as a
gadget's GadgetText) defaults to the Window RastPort font, but can be
overridden using its ITextFont field.  Text rendered with the Text()
graphics.library call appears in the Window RastPort font.

The Window's RPort's font shown above is the initial font that Intuition
sets for you in your window's RastPort.  It is legal to change that
subsequently with SetFont().

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
