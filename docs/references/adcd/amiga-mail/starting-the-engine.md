---
title: Starting the Engine
manual: amiga-mail
chapter: amiga-mail
section: starting-the-engine
functions: []
libraries: []
---

# Starting the Engine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several steps involved in using a font outline on the Amiga.

[Step 1.](amiga-mail/step-1.md) Open the font contents file (the ".font" file) and verify that

```c
        it has a corresponding outline tag file (an ".otag" file).
```
[Step 2.](amiga-mail/step-2.md) Open the otag file, verify that it is valid, load its tag list

        into memory, and resolve any memory indirections in the tag list.
[Step 3.](amiga-mail/step-3.md) Find out the name of the typeface's scaling engine and obtain a

        pointer to the engine's GlyphEngine structure.
[Step 4.](amiga-mail/step-4.md) Tell the engine which typeface to use.

[Step 5.](amiga-mail/step-5.md) Set other scaling engine parameters.

