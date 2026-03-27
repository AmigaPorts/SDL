---
title: fuelgauge_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: fuelgauge-gc-datasheet
functions: [RawDoFmt, Text, TextFit]
libraries: [exec.library, graphics.library]
---

# fuelgauge_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        fuelgauge_gc -- create fuelgauge BOOPSI objects

    SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image

    DESCRIPTION
        The fuelgauge gadget class is used to display stage of completion
        of some operation, such as formating a floppy. Or, perhaps as
        a means of indication, such as free drive space.

        Advantages that this class provides:

         > Supports window relativity.

         > Optional tick marks, and short ticks.

         > Ability to change background pen, text pen, and filltext pen.

         > Supports OS 3.0 BOOPSI [Gadget](autodocs-3.5/include-intuition-intuition-h.md) HelpTest.

    METHODS
        OM_NEW -- Passed to superclass to creates object instance

        OM_SET -- Sets all possible settings, then passed to superclass

        OM_GET -- Returns requested setting or passed to superclass

        OM_DISPOSE -- Passed to superclass

        GM_HITTEST -- Returns 0.

        GM_RENDER -- Passed to superclass, then renders fuelgauge

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM, GDOMAIN_NOMINAL and
            GDOMAIN_MAXIMUM dimensions.

        GM_GOACTIVE -- NO OP
        GM_HANDLEINPUT -- NO OP
        GM_GOINACTIVE -- NO OP

    ATTRIBUTES

        GA_Text (STRPTR)
            Used to specify the NULL terminated string to use
            as the text for the gadget.  The [Text()](autodocs-3.5/graphics-library-text-2.md) function is used to draw
            the text. NULL is valid input, and will enable the default
            centered percentage rendering. Changing the label will invoke
            GM_RENDER. [Text](autodocs-3.5/graphics-library-text-2.md) string is clipped to fit inside the gauge via
            the [TextFit()](autodocs-3.5/graphics-library-textfit-2.md) function. The text string may contain varargs
            format specifiers compatible to [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) if the varargs data
            is supplied via FUELGAUGE_VarArgs.

            Applicability is (OM_NEW, OM_SET)

        FUELGAUGE_Min (LONG)
            Minimum value of the gauge.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        FUELGAUGE_Max (LONG)
            Maximum value of the gauge.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        FUELGAUGE_Level (LONG)
            Current gauge setting, usually something between Min and Max.
            Base on Min, Max and Current a percentage can be calculated
            and displayed by the gadget.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        FUELGAUGE_Orientation (WORD)
            Sets the orientation of the fuel gauge to vertical or
            horizontal.

            Accepted values as defined in [<gadgets/fuelgauge.h>](autodocs-3.5/include-gadgets-fuelgauge-h.md) are:

               FGORIENT_HORIZ
               FGORIENT_VERT

            Defaults to FGORIENT_HORIZ

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_Percent (WORD)
            [Enable/Disable](autodocs-3.5/exec-library-disable-2.md) Percentage display.
            Percentage is displayed in the center of the gauge using
            the requested font, provided it fits within the gadget bounds.

            Defaults to TRUE

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        FUELGAUGE_Ticks (BOOL)
            Sets the number of "tickmarks" rendered along the bottom
            of the gadget. Take note, the tickmarks are rendered within
            the gadgets size dimentions. Values greater than 0 enable
            the tick mark(s).

            Defaults to 0

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_ShortTicks (BOOL)
            Enables rendering of "shortticks", smaller size tickmarks
            rendered in between the larger tick marks.

            Defaults to FALSE,

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_TickSize (WORD)
            Sets the size, in pixels, of the large tickmarks.
            Shorttick size is TickHeight / 2. Note, if NOT setting
            FUELGAUGE_Ticks non-zero, then you may need to 0 this as
            well depending on the fuelgauge release version!

            Defaults to 5 pixels

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_TickPen (WORD)
            Pen number used to render the tickmarks.

            Defaults to SHINEPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_PercentPen (WORD)
            Pen number used to render the percentage text label.

            Defaults to TEXTPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_EmptyPen (WORD)
            Pen number used to render the empty section of the gauge.

            Defaults to BACKGROUNDPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_FillPen (WORD)
            Pen number used to render the filled section of the gauge.

            Defaults to BACKGROUNDPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        FUELGAUGE_VarArgs (APTR)
            Varargs data array to supply data for [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) when
            format specifiers are to be used in GA_Text text strings.
            The VarArgs internal result buffer is 128 bytes, take care
            not to exceed this buffer.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        FUELGAUGE_Justification (WORD)
            Justification mode of fuelgauge (GA_Text) text label.
            Percentage rendering, when enabled, is always centered.

            Supports:

                FGJ_LEFT
                FGJ_CENTER

            Defaults to FGJ_LEFT.

            Applicability is (OM_NEW, OM_SET)
```

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
