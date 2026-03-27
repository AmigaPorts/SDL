# 5 / / Custom String Editing / The SGH_KEY Command


The SGH_KEY command indicates that the user has pressed a key while the
gadget is active.  This may be any key, including non-character keys such
as Shift, Ctrl and Alt.  Repeat keys (one call per repeat) and the Amiga
keys also cause the hook to be called with the SGH_KEY command.  The hook
is not called for "key up" events.

The SGH_KEY command must be supported by any custom string editing hook.
There are no parameters following the SGH_KEY command longword.  All
information on the event must be derived from the [SGWork](../Libraries_Manual_guide/node016F.html) structure.

Intuition has already processed the event and filled-in the [SGWork](../Libraries_Manual_guide/node016F.html)
structure before calling the hook.  The information included in this
structure includes the type of action taken ([EditOp](../Libraries_Manual_guide/node016F.html#line57)), the new cursor
position ([BufferPos](../Libraries_Manual_guide/node016F.html#line30)), the new value in the buffer ([WorkBuffer](../Libraries_Manual_guide/node016F.html#line30)),  the
previous value in the buffer ([PrevBuffer](../Libraries_Manual_guide/node016F.html#line26)), the input event that caused
this call ([IEvent](../Libraries_Manual_guide/node016F.html#line35)) and more.

