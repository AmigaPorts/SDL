/* Source: ADCD 2.1
 * Section: 7-intuition-requesters-and-alerts-easy-requesters
 * Library: libraries
 * ADCD reference: libraries/7-intuition-requesters-and-alerts-easy-requesters.md
 */

    Turn Off the Verify Messages.
    -----------------------------
    Use [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) to turn off all verify messages (such as
    [MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6)) before calling [EasyRequest()](../Includes_and_Autodocs_2._guide/node0212.html) or [AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21). Neglecting
    to do so can cause situations where Intuition is waiting for the
    return of a message that the application program cannot receive
    because its input is shut off while the requester is up.  If
    Intuition finds itself in a deadlock state, the verify function will
    timeout and will be automatically replied.
