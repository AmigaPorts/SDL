---
title: chooser_gc/--styleguide--
manual: autodocs-3.5
chapter: autodocs-3.5
section: chooser-gc-styleguide
functions: []
libraries: []
---

# chooser_gc/--styleguide--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    CHOOSER STYLE
        The Chooser has two very distinct modes of operation, drop-down and
        pop-up.  It is important to understand the differences between these
        two modes and to use the proper mode in the proper context.

    POP-UP CHOOSERS
        A popup is generally used for setting an application mode or state,
        and in many cases it can replace a cycle gadget or MX (radio buttons)
        gadget.  In this mode, there is a currently active item in the list
        of selections, which will be display in the gadget select button.
        This has the same advantage of a cycle menu in that it is compact,
        with the further advantage that all values can be displayed at once
        and therefore the list of values can be much larger, though generally
        no more than a dozen items should be displayed.

    DROP-DOWN CHOOSERS
        A dropdown chooser is for performing an action from a list of
        available actions.  In this mode, the gadget select box contains a
        title indicating what the actions are for.  These actions should all
        be closely related, and specific to a certain context within the
        application.  This can be used to replace a group of buttons, or a
        cycle gadget and a button where the cycle gadget modifies the
        behaviour of the button.  Since using the chooser in this mode makes
        functions effectively hidden, it should generally only be used where
        compactness is a signficant issue.

        An alternate use for a drop-down is to use it as a means of accessing
        a "hot list" for a string or integer gadget.  For example, in a word
        processor you might have a string gadget at the top of the screen for
        entering the text point size.  Beside that you could have a drop-down
        chooser that lists some common point sizes that would then be copied
        into your integer gadget and change the text size when you make a
        selection.  When a drop-down is used this way, it is generally
        desirable not to have the drop-down display a title within the gadget
        box (pass NULL for CHOOSER_Title) and to  make the gadget this enough
        so that just the arrow is displayed (use about 20 for GA_Width if not
        using the chooser within a layout group).
```
