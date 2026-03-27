# 10 Intuition Mouse and Keyboard / The Keyboard


A program can receive keyboard data through an IDCMP port by setting the
[IDCMP_RAWKEY](../Libraries_Manual_guide/node01E1.html#line19) flag, the [IDCMP_VANILLAKEY](../Libraries_Manual_guide/node01E1.html) flag or both.  IDCMP_VANILLAKEY
events provide for simple ASCII text and standard control keys like space,
return and backspace.  IDCMP_RAWKEY events provide a more complex input
stream, which the program must process to generate ASCII data.
IDCMP_RAWKEY returns all keycodes, both key-up and key-down, including
function keys.


    Keystrokes Are Not Always Paired.
    ---------------------------------
    Keystrokes do not always come in key-down/key-up pairs.  For
    example, repeating keys appear as a sequence of key-down messages.
[IDCMP_RAWKEY](../Libraries_Manual_guide/node01E1.html#line19) and [IDCMP_VANILLAKEY](../Libraries_Manual_guide/node01E1.html) may be set together.  When both flags
are set in the IDCMP, IDCMP_VANILLAKEY messages will be sent for
keystrokes that directly map to a single ASCII value.  IDCMP_RAWKEY
messages will be sent for key sequences that do not map to simple values,
i.e. if a key sequence does not map to an IDCMP_VANILLAKEY message, it
will be sent as an IDCMP_RAWKEY message.  This allows easy access to
mapped characters through IDCMP_VANILLAKEY with control characters
returned as IDCMP_RAWKEY.  Note that the IDCMP_RAWKEY events will only
return the key down events when used with IDCMP_VANILLAKEY.

When Intuition responds to an input event or sequence of events, the
application will not receive those events.  This happens for system
shortcuts (left Amiga + key) if the system shortcut is defined, and for
menu shortcuts (right Amiga + key) if the menu shortcut is defined for the
active window.  If the shortcut is not defined, then the appropriate key
event will be sent with the proper Amiga qualifier set.

Key repeat characters have a queue limit which may be set for each window,
much like the mouse queue described above.  The key repeat queue limit may
only be set when the window is opened using the [WA_RptQueue](../Libraries_Manual_guide/node0124.html#line159) tag, there is
no function call for modifying the value after the window is open.  The
default queue limit for key repeat characters is three.  This limit causes
any [IDCMP_RAWKEY](../Libraries_Manual_guide/node01E1.html#line19), [IDCMP_VANILLAKEY](../Libraries_Manual_guide/node01E1.html#line19) or [IDCMP_UPDATE](../Libraries_Manual_guide/node01E1.html#line98) message with the
[IEQUALIFIER_REPEAT](../Libraries_Manual_guide/node01F3.html#line51) bit set to be discarded if the queue is full
(IDCMP_UPDATE is discussed in the "[BOOPSI](../Libraries_Manual_guide/node020C.html#line42)" chapter).  The queue is said to
be full when the number of waiting repeat key messages is equal to the
queue limit.  Note that the limit is not per character, it is on the total
number of key messages with the repeat bit set.  Once the limit is
reached, no other repeat characters will be posted to the IDCMP until the
application replies to one of the outstanding repeat key messages.  The
repeat queue limit is not as dangerous as the mouse queue limit as only
duplicate keystroke information is discarded, where the mouse queue limit
discards information that cannot be easily reproduced.

 [Rawkey Keymapping Example](../Devices_Manual_guide/node0191.html)          [Menu Shortcuts](../Libraries_Manual_guide/node01F2.html) 
 [Keyboard Control of the Pointer](../Libraries_Manual_guide/node01F0.html)    [Amiga Qualifiers](../Libraries_Manual_guide/node01F3.html) 
 [Intuition Keyboard Shortcuts](../Libraries_Manual_guide/node01F1.html) 

