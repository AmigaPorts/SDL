# G Keyboard Interface / Hard Reset



   About Hard Reset.
   -----------------
   Hard Reset happens after  [Reset Warning](../Hardware_Manual_guide/node0178.html) . Valid for all keyboards
   except the Amiga 500.

The keyboard Hard Resets the Amiga by pulling KCLK low and starting a 500
millisecond timer.   When one or more of the keys is released and 500
milliseconds have passed, the keyboard will release KCLK. 500 milliseconds
is the minimum time KCLK must be held low.  The maximum KCLK time depends
on how long the user holds the three  [reset keys](../Hardware_Manual_guide/node0178.html#line6)  down.  Circuitry on the
Amiga motherboard detects the 500 millisecond KCLK pulse.

After releasing KCLK, the keyboard jumps to its start-up code (internal
RESET).  This will initialize the keyboard in the same way as cold
 [power-on](../Hardware_Manual_guide/node0177.html) .

   NOTE:
   -----
   The keyboard must resend the " [powerup key stream](../Hardware_Manual_guide/node0177.html#line46) "!

