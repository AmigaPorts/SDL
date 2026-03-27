---
title: Lib_examples/istr.c
manual: libraries
chapter: libraries
section: lib-examples-istr-c
functions: []
libraries: []
---

# Lib_examples/istr.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* istr.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfis -j73 istr.c
Blink FROM LIB:c.o,istr.o TO istr LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
*/


```c
    #include <exec/types.h>
    #include <stdio.h>
    #include <string.h>

    #include <clib/exec_protos.h>
    #include <clib/utility_protos.h>

    void main(void);
    struct Library *UtilityBase;

    void main(void)
    {
        UBYTE *butter = "Bøtervløøt";
        UBYTE *bread = "Knåckerbrøt";
        UBYTE ch1, ch2;
        LONG result;

        /* Fails silently if < 37 */
        if (UtilityBase = OpenLibrary("utility.library", 37))
        {
                result = Stricmp(butter, bread);

                printf("comparing %s with %s yields %ld\n", butter, bread, result );

                result = Strnicmp(bread, butter, strlen(bread));

                printf("comparing (with length) %s with %s yields %ld\n", bread, butter, result );

                ch1 = ToUpper(0xE6); æ /* ASCII character 230 ae ligature */
                ch2 = ToLower(0xD0); Ð /* ASCII character 208 Icelandic Eth */

                printf("Chars %c %c\n", ch1, ch2);
        }
    }
```
