# 5 / / Custom String Editing / Actions with SGH_KEY


If [SGA_USE](../Libraries_Manual_guide/node0171.html#line5) is set in the [SGWork](../Libraries_Manual_guide/node016F.html) structure [Actions](../Libraries_Manual_guide/node016F.html#line54) field when the hook
returns, Intuition will use the values in the SGWork fields [WorkBuffer](../Libraries_Manual_guide/node016F.html#line30),
[NumChars](../Libraries_Manual_guide/node016F.html#line30), [BufferPos](../Libraries_Manual_guide/node016F.html#line30), and [LongInt](../Libraries_Manual_guide/node016F.html#line30); copying the WorkBuffer to the [StringInfo](../Libraries_Manual_guide/node016B.html)
[Buffer](../Libraries_Manual_guide/node016B.html#line19).  SGA_USE is set by Intuition prior to calling the hook, and must
be cleared by the hook if the changes are to be ignored.  If SGA_USE is
cleared when the hook returns, the [string](../Libraries_Manual_guide/node0164.html) gadget will be unchanged.

If [SGA_END](../Libraries_Manual_guide/node0171.html#line5) is set when the hook returns, Intuition will deactivate the
[string](../Libraries_Manual_guide/node0164.html) gadget.  In this case, Intuition will place the value found in
[SGWork](../Libraries_Manual_guide/node016F.html) structure [Code](../Libraries_Manual_guide/node016F.html#line40) field into the [IntuiMessage.Code](../Libraries_Manual_guide/node01D9.html#line33) field of the
[IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message it sends to the application.

If [SGA_REUSE](../Libraries_Manual_guide/node0171.html#line5) and [SGA_END](../Libraries_Manual_guide/node0171.html#line5) are set when the hook returns, Intuition will
reuse the input event after it deactivates the gadget.

Starting in V37, the hook may set [SGA_PREVACTIVE](../Libraries_Manual_guide/node0171.html#line5) or [SGA_NEXTACTIVE](../Libraries_Manual_guide/node0171.html#line5) with
[SGA_END](../Libraries_Manual_guide/node0171.html#line5).  This tells Intuition to activate the next or previous gadget
that has the [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) flag set.

If [SGA_BEEP](../Libraries_Manual_guide/node0171.html#line5) is set when the hook returns, Intuition will call
[DisplayBeep()](../Libraries_Manual_guide/node00FC.html).  Use this if the user has typed in error, or buffer is full.

Set [SGA_REDISPLAY](../Libraries_Manual_guide/node0171.html#line5) if the changes to the gadget warrant a gadget redisplay.
Changes to the cursor position require redisplay.

