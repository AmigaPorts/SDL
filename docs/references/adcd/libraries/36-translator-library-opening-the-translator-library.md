---
title: 36 Translator Library / Opening the Translator Library
manual: libraries
chapter: libraries
section: 36-translator-library-opening-the-translator-library
functions: [OpenLibrary]
libraries: [exec.library]
---

# 36 Translator Library / Opening the Translator Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To use the [Translate()](libraries/36-translator-library-using-the-translate-function.md) function, you must first open the translator
library. Setting a global variable, TranslatorBase, to the value returned
from the call to [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) enables the Amiga linker to correctly
locate the translator library:


```c
    struct Library *TranslatorBase;

    TranslatorBase = OpenLibrary("translator.library",REVISION);
    if(TranslatorBase != NULL)
        {
        /* use translator here -- library open */
        }


    LIBS: must contain translator.library.
    --------------------------------------
    Since translator is a disk-based library, the call to
    [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) will work only if the LIBS: directory contains
    translator.library.
```

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
