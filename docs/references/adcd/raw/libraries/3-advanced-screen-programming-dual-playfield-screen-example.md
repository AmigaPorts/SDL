# 3 / Advanced Screen Programming / Dual-Playfield Screen Example


This example shows how to create a dual-playfield display.  Note that this
technique is only valid for screen modes which support dual-playfield, do
not try to convert other modes.

Setting up dual playfield mode in the [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) call is not the best
method of obtaining a dual playfield viewport for a screen.  It is better
to open a standard screen, passing to Intuition (or letting Intuition
create) only one of the playfield bitmaps (the front one).  Next allocate
and set up a second bitmap, its bitplanes, and a [RasInfo](../Libraries_Manual_guide/node032F.html) structure
installing these into the new screen's viewport.  Update the viewport
modes to include DUALPF and call [MakeScreen()](../Libraries_Manual_guide/node00F4.html#line5) and [RethinkDisplay()](../Libraries_Manual_guide/node00F4.html#line5).  This
method, shown in the example below, keeps Intuition rendering (gadgets,
menus, windows) in a single playfield.


```c
     [dualplayfield.c](../Libraries_Manual_guide/node05B4.html) 
```
