# 5 / / Custom String Editing / The SGH_CLICK Command


The SGH_CLICK command indicates that the user has clicked the select
button of the mouse within the gadget select box.  There are no parameters
following the SGH_CLICK command longword.

Intuition will have already calculated the mouse position character cell
and placed that value in [SGWork.BufferPos](../Libraries_Manual_guide/node016F.html#line30).  The previous BufferPos value
remains in the [SGWork](../Libraries_Manual_guide/node016F.html).[StringInfo.BufferPos](../Libraries_Manual_guide/node016B.html#line54).

Intuition will again use the [SGWork](../Libraries_Manual_guide/node016F.html) fields listed above for [SGH_KEY](../Libraries_Manual_guide/node0173.html).  That
is, the [WorkBuffer](../Libraries_Manual_guide/node016F.html#line30), [NumChars](../Libraries_Manual_guide/node016F.html#line30), [BufferPos](../Libraries_Manual_guide/node016F.html#line30) and [LongInt](../Libraries_Manual_guide/node016F.html#line30) fields values may be
modified by the hook and are used by Intuition if [SGA_USE](../Libraries_Manual_guide/node0171.html#line5) is set when the
hook returns.

