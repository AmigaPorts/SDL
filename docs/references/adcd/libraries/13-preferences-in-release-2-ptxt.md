---
title: 13 / Preferences in Release 2 / PTXT
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-ptxt
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / PTXT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct PrinterTxtPrefs
    {
        LONG  pt_Reserved[4];            /* System reserved            */
        UBYTE pt_Driver[DRIVERNAMESIZE]; /* printer driver filename    */
        UBYTE pt_Port;                   /* printer port connection    */

        UWORD pt_PaperType;              /* Fanfold or single */
        UWORD pt_PaperSize;              /* Standard, Legal, A4, A3 etc. */
        UWORD pt_PaperLength;            /* Paper length in # of lines */

        UWORD pt_Pitch;                  /* Pica or Elite */
        UWORD pt_Spacing;                /* 6 or 8 LPI */
        UWORD pt_LeftMargin;             /* Left margin */
        UWORD pt_RightMargin;            /* Right margin */
        UWORD pt_Quality;                /* Draft or Letter */
    };
```
