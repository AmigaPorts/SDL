# G Keyboard Interface / Reset Warning



   About Reset Warning.
   -------------------
   This feature is available on some A1000 and A2000 keyboards. You
   cannot rely on this feature for all Amigas.

The keyboard has the additional task of resetting the computer on the
command of the user.  The user initiates Reset Warning by simultaneously
pressing the Ctrl key and the two Amiga keys.

The keyboard responds to this input by syncing up any pending transmit
operations.  The keyboard then sends a "reset warning" to the Amiga.  This
action alerts the Amiga software to finish up any pending operations (such
as disk DMA) and prepare for reset.

A specific sequence of operations ensure that the Amiga is in a state
where it can respond to the reset warning.  The keyboard sends two actual
"reset warning" keycodes.  The Amiga must handshake to the first code like
any normal keystroke, else the keyboard goes directly to  [Hard Reset](../Hardware_Manual_guide/node0179.html) .  On
the second "reset warning" code the Amiga must drive KDAT low within 250
milliseconds, else the keyboard goes directly to  [Hard Reset](../Hardware_Manual_guide/node0179.html) .  If all
the  [tests](../Hardware_Manual_guide/node0177.html#line5)  are passed, the Amiga has 10 full seconds to do emergency
processing.  When the Amiga pulls KDAT high again, the keyboard finally
asserts  [hard reset](../Hardware_Manual_guide/node0179.html) .

If the Amiga fails to pull KDAT high within 10 seconds,  [Hard Reset](../Hardware_Manual_guide/node0179.html)  is
asserted anyway.

