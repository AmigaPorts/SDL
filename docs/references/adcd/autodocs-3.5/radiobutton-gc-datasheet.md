---
title: radiobutton_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: radiobutton-gc-datasheet
functions: []
libraries: []
---

# radiobutton_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        radiobutton_gc -- create radiobutton BOOPSI objects

    SUPERCLASS
        gadgetclass

     REQUIRES
        bevel.image, glyph.image

    DESCRIPTION
        The radiobutton gadget class is used to create a mutually exclusive
        (MX) selection button group. Selection of an associated option is
        denoted by the depressed/filled button. Unlike GadTools, GA_Width and
        GA_Height to not specify the size of a single radio button. Instead
        it marks the entire domain of the gadget which allows for easier
        group layout. When used outside of a layout group you must be
        sure to provide enough space for the gadget to completly render
        all radio buttons and labels. However, within a layout group such
        as ReAction's own layout.gadget this is automatic and of no
        concern to the application programmer.

        Advantages that this class provides over the standard gadtools
        radiobutton (MX_KIND) are:

         > Strumming of the radio buttons with the mouse.

         > Aspect correct scaled buttons with any screen resolution or font.

         > Works under OS 2.0 or greater.

    METHODS
        OM_NEW -- Passed to superclass first, defaults set, then OM_SET.

        OM_SET -- Passed to superclass first, then custom tags set.

        OM_GET -- Returns requested setting or passed to superclass

        OM_DISPOSE -- Passed to superclass.

        GM_GOACTIVE -- Passed to superclass first, then radio activated

        GM_GOINACTIVE -- Passed to superclass first, then radio deactivated

        GM_HANDLEINPUT -- Handles button selection/strum. Overrides superclass.

        GM_HITTEST -- Overrides superclass, returns GMR_HITTEST.

        GM_RENDER -- Renders radio button(s).

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

        GM_KEYACTIVE -- Activates button via keyboard. Advances selection
            to the next item (down), if SHIFT is pressed, it selects
            the previous item (up). Invoked by window.class only.

        GM_KEYINACTIVE -- Deactivates gadget. Invoked by window.class only.

        All other methods are passed to the superclass.


    ATTRIBUTES
        GA_ID (WORD)
            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

        GA_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
            Used to set the text font to render the radiobutton labels.

            Defaults to RPort->Font, which is often the screen or
            window font.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        RADIOBUTTON_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *)
            Used to set the text labels for the radiobutton group.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)


        RADIOBUTTON_Spacing (WORD)
            Spacing between the radio buttons.

            Defaults to 1.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

        RADIOBUTTON_Selected (WORD)
            Currently selected radio button number.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        RADIOBUTTON_LabelPlace (WORD)
            Location of radiobutton text labels. Supports:

                PLACETEXT_RIGHT

            Defaults to PLACETEXT_RIGHT.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

    NOTES
        GA_Height and GA_Width DO NOT specify the actual button size, but
        rather the entire "hit box" area which includes the text label.
        When being used with layout.gadget it will domain to a proper
        size to hold the number of buttons and largest text labels.
        Take care when designing interfaces with out layout to set
        a proper height and width to hold the radiobutton imagery.
        This may be done via sending a BOOPSI GM_DOMAIN GDOMAIN_MINIMUM
        method message to the object with DoGadgetMethod(), or computing
        a minimum size based on font height and length. In otherwords,
        use layout, its alot easier! :)
```
