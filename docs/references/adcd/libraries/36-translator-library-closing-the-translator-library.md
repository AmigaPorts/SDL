---
title: 36 Translator Library / Closing the Translator Library
manual: libraries
chapter: libraries
section: 36-translator-library-closing-the-translator-library
functions: []
libraries: []
---

# 36 Translator Library / Closing the Translator Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As with all other libraries of functions, if you have successfully opened
the translator library for use, be sure to close it before your program
exits. If the system needs memory resources, it can then expunge closed
libraries to gain additional memory space:


```c
    struct Library *TranslatorBase;

    if(TranslatorBase) CloseLibrary(TranslatorBase);
```
