# 5 / / Initialization of Proportional Gadget / the PropInfo Structure


This is the special data required by the [proportional](../Libraries_Manual_guide/node0153.html) gadget.


```c
    struct [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line451)
        {
        UWORD Flags;
        UWORD HorizPot;
        UWORD VertPot;
        UWORD HorizBody;
        UWORD VertBody;
        UWORD CWidth;
        UWORD CHeight;
        UWORD HPotRes, VPotRes;
        UWORD LeftBorder;
        UWORD TopBorder;
        };
```
Flags

```c
    In the Flags variable, the following flag bits are of interest:

    PROPBORDERLESS
        Set the PROPBORDERLESS flag to create a [proportional](../Libraries_Manual_guide/node0153.html) gadget
        without a border.

    AUTOKNOB
        Set the AUTOKNOB flag in the Flags field to use the [auto-knob](../Libraries_Manual_guide/node015A.html#line16),
        otherwise the application must provide [knob](../Libraries_Manual_guide/node015A.html) imagery.

    FREEHORIZ and FREEVERT
        Set the FREEHORIZ flag to create a gadget that adjust
        left-to-right, set the FREEVERT flag for top-to-bottom movement.
        Both flags may be set in a single gadget.

    PROPNEWLOOK
        Set the PROPNEWLOOK flag to create a gadget with the new look.
        If this flag is not set, the gadget will be rendered using a V34
        compatible design.

    KNOBHIT
        The KNOBHIT flag is set by Intuition when this [knob](../Libraries_Manual_guide/node015A.html) is hit by
        the user.
```
HorizPot and VertPot

```c
    Initialize the [HorizPot](../Libraries_Manual_guide/node015B.html) and [VertPot](../Libraries_Manual_guide/node015B.html) variables to their starting
    values before the gadget is added to the system. The variables may be
    read by the application. The gadget must be removed before writing to
    these variables, or they may be modified with [NewModifyProp()](../Libraries_Manual_guide/node0163.html).
```
HorizBody and VertBody

```c
    Set the [HorizBody](../Libraries_Manual_guide/node015C.html) and [VertnBody](../Libraries_Manual_guide/node015C.html) variables to the desired increment. If
    there is no data to show or the total amount displayed is less than
    the area in which to display it, set the [body variables](../Libraries_Manual_guide/node015C.html) to the
    maximum, MAXBODY.
```
The remaining variables and flags are reserved for use by Intuition.

