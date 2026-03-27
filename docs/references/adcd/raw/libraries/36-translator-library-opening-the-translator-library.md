# 36 Translator Library / Opening the Translator Library


To use the [Translate()](../Libraries_Manual_guide/node0492.html) function, you must first open the translator
library. Setting a global variable, TranslatorBase, to the value returned
from the call to [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15) enables the Amiga linker to correctly
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
    [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15) will work only if the LIBS: directory contains
    translator.library.
```
