---
title: 13 / Preferences in Release 2 / SERL
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-serl
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / SERL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct SerialPrefs
    {
        LONG  sp_Reserved[4];     /* System reserved                  */
        ULONG sp_BaudRate;        /* Baud rate                        */

        ULONG sp_InputBuffer;     /* Input buffer: 0 - 64K          */
        ULONG sp_OutputBuffer;    /* Future: Output: 0 - 64K, def 0 */

        UBYTE sp_InputHandshake;  /* Input handshaking                */
        UBYTE sp_OutputHandshake; /* Future: Output handshaking       */

        UBYTE sp_Parity;          /* Parity                           */
        UBYTE sp_BitsPerChar;     /* I/O bits per character           */
        UBYTE sp_StopBits;        /* Stop bits                        */
    };
```
