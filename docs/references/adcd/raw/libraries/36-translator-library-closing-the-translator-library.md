# 36 Translator Library / Closing the Translator Library


As with all other libraries of functions, if you have successfully opened
the translator library for use, be sure to close it before your program
exits. If the system needs memory resources, it can then expunge closed
libraries to gain additional memory space:


```c
    struct Library *TranslatorBase;

    if(TranslatorBase) CloseLibrary(TranslatorBase);
```
