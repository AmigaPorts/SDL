---
title: 10 / Printer Device Access / Opening Prt:
manual: devices
chapter: devices
section: 10-printer-device-access-opening-prt
functions: []
libraries: []
---

# 10 / Printer Device Access / Opening Prt:

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When using the printer device as PRT:, you can open it just as though it
were a normal AmigaDOS output file.


```c
    struct FileHandle *file;

    file = Open( "PRT:", MODE_NEWFILE ); /* Open PRT: */
    if (file == 0)                       /* if the open was unsuccessful */
        exit(PRINTER_WONT_OPEN);
```
