# 5 / String Gadget Type / Tabbing Between String Gadgets


The Amiga allows tabbing to the next [string](../Libraries_Manual_guide/node0164.html) gadget in a window or
requester and shifted tabbing to the previous string gadget.  This
function operates starting with V37.

If the [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) flag is set, this string participates in cycling
activation with Tab or Shift Tab.  If only a single gadget has this flag
set, then the Tab keys will have no effect.  If one of the Tab keys is
pressed while in a [string](../Libraries_Manual_guide/node0164.html) gadget without GFLG_TABCYCLE set, nothing will
happen, even though other string gadgets may have the flag set.

Activation order is determined by the order of the [string](../Libraries_Manual_guide/node0164.html) gadgets in the
gadget list, following the [NextGadget](../Libraries_Manual_guide/node0149.html#line21) link.  The tab key will advance to
the next string gadget with [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) set, shifted tab will move to
the previous gadget.  To order gadgets for tabbing (next/ previous string
gadget), place them in the correct order in the gadget list when they are
added to the system.  This order must be maintained if the gadgets are
removed and put back, or the tabbing order will change.

The tab keys will de-activate the current gadget as if one of the Return
or Enter keys had been pressed, sending an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message to the
application.  The application can recognize that tab was pressed by
looking for 0x09 (the ASCII tab character) in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field of the
IDCMP_GADGETUP [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  If necessary, it can then inspect the
qualifier field of that message to see if the shift key was pressed.  The
next [string](../Libraries_Manual_guide/node0164.html) gadget with [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) set will be activated, with shifted
tab activating the previous string gadget.

