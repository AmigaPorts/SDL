---
title: 13 / Preferences in Release 2 / ICTL
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-ictl
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / ICTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct IControlPrefs
    {
        LONG  ic_Reserved[4];        /* System reserved            */
        UWORD ic_TimeOut;            /* Verify timeout             */
        WORD  ic_MetaDrag;           /* Meta drag mouse event      */
        ULONG ic_Flags;              /* IControl flags (see below) */
        UBYTE ic_WBtoFront;          /* CKey: WB to front          */
        UBYTE ic_FrontToBack;        /* CKey: front screen to back */
        UBYTE ic_ReqTrue;            /* CKey: Requester TRUE       */
        UBYTE ic_ReqFalse;           /* CKey: Requester FALSE      */
    };
```
The ic_Flags field can have the following values:

ICF_COERCE_COLORS

    This indicates that a displaymode with a matching number of colors
    has preference over a correct aspect ration when screen coercing
    takes place.
ICF_COERCE_LACE

    This indicates that chosing an interlaced display mode is allowed
    when coercing screens. Otherwise a non-interlaced display mode will
    be selected.
ICF_STRGAD_FILTER

    This indicates that control characters should be filtered out of
    string gadget user input.
ICF_MENUSNAP

    This indicates that an autoscroll screen should be snapped back to
    origin when the mouse menu-button is selected.
Note that the command key values in the last four fields of the
IControlPrefs structure are ANSI codes, not RAWKEY codes.

