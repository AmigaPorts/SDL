---
title: 13 / Preferences in Release 2 / SCRM
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-scrm
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / SCRM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct ScreenModePrefs
    {
        ULONG sm_Reserved[4];
        ULONG sm_DisplayID;              /* Displaymode ID */
        UWORD sm_Width;                  /* Screen width */
        UWORD sm_Height;                 /* Screen height */
        UWORD sm_Depth;                  /* Screen depth */
        UWORD sm_Control;                /* BIT 0, Autoscroll yes/no */
    };
```
