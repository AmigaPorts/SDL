---
title: 13 / Preferences in Release 2 / OSCN
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-oscn
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / OSCN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct OverscanPrefs
    {
        ULONG            os_Reserved[4];
        ULONG            os_DisplayID;   /* Displaymode ID */
        Point            os_ViewPos;     /* View X/Y Offset */
        Point            os_Text;        /* TEXT overscan dimension */
        struct Rectangle os_Standard;    /* STANDARD overscan dimension */
    };
```
