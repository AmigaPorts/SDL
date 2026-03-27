---
title: 13 / Preferences in Release 2 / FONT
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-font
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / FONT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct FontPrefs
    {
        LONG            fp_Reserved[4];
        UBYTE           fp_FrontPen;     /* Textcolor */
        UBYTE           fp_BackPen;      /* Character background color */
        UBYTE           fp_DrawMode;
        struct TextAttr fp_TextAttr;
        BYTE            fp_Name[FONTNAMESIZE]; /* Font name */
    };
```
