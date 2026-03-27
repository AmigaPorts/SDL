---
title: palette_gc/--styleguide--
manual: autodocs-3.5
chapter: autodocs-3.5
section: palette-gc-styleguide
functions: []
libraries: []
---

# palette_gc/--styleguide--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    PALETTE STYLE
        The usability of a palette gadget decreases as the number of
        colours it is displaying increases.  If there is a possibility
        that your palette gadget may be displaying a large number of
        colours (say, greater than 16), you should provide a means to
        simplify the colour selection.  Two possibilities would be to
        divide your colour palette into banks, and have users switch
        banks via a chooser gadget for example.  Another possibility
        would be to attach a scroller gadget to allow the user to
        scroll through the available colours, displaying just a
        subset of them on screen at a time.  You may also want to sort
        your colours in some logical manner and use PALETTE_ColourTable.
```
