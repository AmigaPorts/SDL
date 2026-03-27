---
title: 13 / Preferences in Release 2 / INPT
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-inpt
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / INPT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct InputPrefs
    {
        LONG           ip_Reserved[4];
        UWORD          ip_PointerTicks; /* Sensitivity of the pointer */
        struct timeval ip_DoubleClick;  /* Interval between clicks */
        struct timeval ip_KeyRptDelay;  /* keyboard repeat delay   */
        struct timeval ip_KeyRptSpeed;  /* Keyboard repeat speed   */
        WORD           ip_MouseAccel;   /* Mouse acceleration      */
    };
```
