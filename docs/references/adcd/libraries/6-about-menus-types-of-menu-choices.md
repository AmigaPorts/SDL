---
title: 6 / About Menus / Types of Menu Choices
manual: libraries
chapter: libraries
section: 6-about-menus-types-of-menu-choices
functions: []
libraries: []
---

# 6 / About Menus / Types of Menu Choices

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menu choices represent either actions or attributes.  Actions are
analogous to verbs.  An action is executed and then forgotten.  Actions
include such things as saving and printing files, calculating values and
displaying information on the program.

Attributes are analogous to adjectives.  An attribute stays in effect
until canceled.  Attributes include such things as pen type, color, draw
mode and numeric format.

For instance, in a word processor, menus could be used to control the
following types of features:


```c
      * File loading and saving (action).

      * Editing functions (action).

      * Formatting preferences (attributes).

      * Printing functions (action).

      * Current font and style (attributes).
```
Menus can be set up such that some attribute items are mutually exclusive
(selecting an attribute cancels the effects of one or more other
attributes).  For example, a drawing or graphics package may only allow
one color to be active at a time--selecting a color cancels the previous
active color.

The program can also allow a number of attributes to be in effect at the
same time.  A common example of this appears in most word processing
programs, where the text style may be bold, italic or underlined.
Selecting bold does not rule out italic or underlined, in fact, all three
may be active at the same time.

