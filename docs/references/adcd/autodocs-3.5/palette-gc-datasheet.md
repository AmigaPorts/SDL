---
title: palette_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: palette-gc-datasheet
functions: []
libraries: []
---

# palette_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     NAME
        palette_gc -- A colour selection gadget.

     SUPERCLASS
        gadgetclass

     REQUIRES
        bevel.image

     DESCRIPTION
        This gadget is equivalent to the GadTools PALETTE_KIND gadget, but
        implemented as a BOOPSI gadget class.  It displays a palette of
        colours, allowing the user to select one.

        Advantages that this class provides:

         > Right mouse button cancels gadget action.

         > Supports window relativity.

         > Supports gadget interconnections.

         > Supports OS 3.0 BOOPSI [Gadget](autodocs-3.5/include-intuition-intuition-h.md) HelpTest.

     METHODS
        OM_NEW -- Create the palette gadget, calls OM_SET.  Passed to
            superclass.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_GET -- Get object attributes.  Passed to superclass first.

        OM_NOTIFY -- Notify connections of attribute changes.

        OM_DISPOSE -- Frees resources and calls superclass.

        OM_UPDATE -- Calls OM_SET.

        GM_DOMAIN -- Return the maximum and minimum size of the gadget.

        GM_RENDER -- Renders the gadget imagry.  Overrides the superclass.

        GM_KEYACTIVE -- Handles keyboard activation.

        GM_KEYINACTIVE -- Handles keyboard de-activation.

        GM_GOACTIVE -- Activate the gadget on mouse click only.  Overrides
            the superclass.

        GM_HANDLEINPUT -- Handles input events once active.  Overrides the
            superclass.

        GM_GOINACTIVE -- Deactivates the gadget.  Passed to the superclass.

        All other methods are passed to the superclass.

     ATTRIBUTES
        GA_Disabled (BOOL)
            Set to TRUE to disable gadget, FALSE otherwise

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        PALETTE_Colour (UBYTE)
```
	        Initially selected color of the palette. This number is a pen
	        number, and not the ordinal color number within the palette
	        gadget itself.  The exception is when PALETTE_ColourTable is
	        used, in which case you will get an index into your table.


```c
            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        PALETTE_ColourOffset (UBYTE)
            First color to use in screen palette.
```
	        Defaults to 0.


```c
            Applicability is (OM_NEW, OM_SET, OM_GET)

        PALETTE_ColourTable (UBYTE *)
            Pointer to a table of pen numbers indicating  which colors
            should be used and edited by the palette gadget. This array
            must contain as many entries as there are colors displayed in
            the palette gadget PLUS the colour offset.  The array provided
            with this tag must remain valid for the life of the gadget or
            until a new table is provided.

            Default is NULL, which causes a 1-to-1 mapping of pen numbers.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        PALETTE_NumColours (UWORD)
            Number of colors to display in the palette gadget.  Currently
            this MUST be a power of
```
	        Defaults to 2.


```c
            Applicability is (OM_NEW, OM_SET, OM_GET)
```
