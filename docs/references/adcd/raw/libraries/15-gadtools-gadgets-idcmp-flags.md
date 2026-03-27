# 15 / GadTools Gadgets / IDCMP Flags


The various GadTools gadget types require certain classes of IDCMP
messages in order to work.  Applications specify these IDCMP classes when
the window is opened or later with [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) (see "[Intuition Windows](../Libraries_Manual_guide/node0124.html#line35)"
chapter for more on this).  Each kind of GadTools gadget requires
one or more of these IDCMP classes: [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6), [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html),
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23), [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) and [IDCMP_INTUITICKS](../Libraries_Manual_guide/node01E1.html#line80).  As a
convenience, the IDCMP classes required by each kind of gadget are defined
in <libraries/[gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line60)>.  For example, SLIDERIDCMP is defined to be:


```c
    #define SLIDERIDCMP (IDCMP_GADGETUP | IDCMP_GADGETDOWN |
                                          IDCMP_MOUSEMOVE)


    Always OR the IDCMP Flag Bits.
    ------------------------------
    When specifying the IDCMP classes for a window, never add the
    flags together, always OR the bits together.  Since many of the
    GadTools IDCMP constants have multiple bits set, adding the values
    will not lead to the proper flag combination.
```
If a certain kind of GadTools gadget is used, the window must use all
IDCMP classes required by that kind of gadget.  Do not omit any that are
given for that class, even if the application does require the message
type.

Because of the way GadTools gadgets are implemented, programs that use
them always require notification about window refresh events.  Even if the
application performs no rendering of its own, it may not use the
[WFLG_NOCAREREFRESH](../Libraries_Manual_guide/node0125.html#line62) window flag and must always set [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7).
See the section on "[Gadget Refresh Functions](../Libraries_Manual_guide/node026F.html)" later in this chapter for
more on this.

