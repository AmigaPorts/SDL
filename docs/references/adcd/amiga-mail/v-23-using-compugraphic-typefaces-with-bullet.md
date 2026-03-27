---
title: V-23: Using Compugraphic Typefaces with Bullet
manual: amiga-mail
chapter: amiga-mail
section: v-23-using-compugraphic-typefaces-with-bullet
functions: []
libraries: []
---

# V-23: Using Compugraphic Typefaces with Bullet

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by John Orr


One of the improvements made to the Amiga's operating system for
Workbench Release 2.1 is programmatic control of AGFA's IntelliFontÒ
scaling engine.  With this engine, application programs can fully
utilize Compugraphic (CG) typefaces installed by Fountain (the CG
typeface install that comes with 2.04 and 2.1).  Some of the features
that the font scaling engine offers include:



```c
    * Rasterization of a typeface to arbitrary vertical and horizontal
      resolutions.

    * Baseline rotation of glyphs to an arbitrary angle.

    * Glyph shearing (italicizing) to any angle from -45 to 45 degrees
      (inclusive).

    * Access to kerning tables.

    * Algorithmic emboldening.
```
 [Starting the Engine](amiga-mail/starting-the-engine.md)      [Width Lists](amiga-mail/width-lists.md)      [Other Level 0 Tags](amiga-mail/other-level-0-tags.md) 
 [Rasterizing a Glyph](amiga-mail/rasterizing-a-glyph.md)      [Rotating](amiga-mail/rotating.md)         [The Otag File Tags](amiga-mail/the-otag-file-tags.md) 
 [Kerning](amiga-mail/kerning.md)                  [Shearing](amiga-mail/shearing.md)         [About the Examples](amiga-mail/about-the-examples.md) 

 [Engine.c](amiga-mail/v-23-engine-c.md) 

