# 5 / / Custom String Editing / Actions with SGH_CLICK


[SGA_END](../Libraries_Manual_guide/node0171.html#line5) or [SGA_REUSE](../Libraries_Manual_guide/node0171.html#line5) may not be set for the [SGH_CLICK command](../Libraries_Manual_guide/node0174.html). Intuition
will not allow gadgets which go inactive when chosen by the user. The
gadget always consumes mouse events in its select box.

With SGH_CLICK, always leave the [SGA_REDISPLAY](../Libraries_Manual_guide/node0171.html#line5) flag set, since Intuition
uses this when activating a [string](../Libraries_Manual_guide/node0164.html) gadget.

