---
title: 5 / String Gadget Type / Tabbing Between String Gadgets
manual: libraries
chapter: libraries
section: 5-string-gadget-type-tabbing-between-string-gadgets
functions: []
libraries: []
---

# 5 / String Gadget Type / Tabbing Between String Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga allows tabbing to the next [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget in a window or
requester and shifted tabbing to the previous string gadget.  This
function operates starting with V37.

If the [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) flag is set, this string participates in cycling
activation with Tab or Shift Tab.  If only a single gadget has this flag
set, then the Tab keys will have no effect.  If one of the Tab keys is
pressed while in a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget without GFLG_TABCYCLE set, nothing will
happen, even though other string gadgets may have the flag set.

Activation order is determined by the order of the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets in the
gadget list, following the [NextGadget](libraries/5-intuition-gadgets-gadget-structure.md) link.  The tab key will advance to
the next string gadget with [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) set, shifted tab will move to
the previous gadget.  To order gadgets for tabbing (next/ previous string
gadget), place them in the correct order in the gadget list when they are
added to the system.  This order must be maintained if the gadgets are
removed and put back, or the tabbing order will change.

The tab keys will de-activate the current gadget as if one of the Return
or Enter keys had been pressed, sending an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) message to the
application.  The application can recognize that tab was pressed by
looking for 0x09 (the ASCII tab character) in the [Code](libraries/9-using-the-idcmp-intuimessages.md) field of the
IDCMP_GADGETUP [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).  If necessary, it can then inspect the
qualifier field of that message to see if the shift key was pressed.  The
next [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget with [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) set will be activated, with shifted
tab activating the previous string gadget.

