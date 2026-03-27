# G Keyboard Interface / Special Codes


The special codes that the keyboard uses to communicate with the main unit
are summarized here.

   About the special codes.
   ------------------------
   The special codes are 8-bit numbers; there is no  [up/down flag](../Hardware_Manual_guide/node0174.html) 
   associated with them.  However, the  [transmission bit order](../Hardware_Manual_guide/node0173.html#line14)  is the
   same as previously described.



```c
        Code       Name            Meaning
        --------------------------------------------------------------
        78       [Reset warning](../Hardware_Manual_guide/node0178.html) .  Ctrl-Amiga-Amiga has been hit -
                computer will be reset in 10 seconds. (see text)
        F9      Last key code bad, next code is the same code
                   retransmitted (used when keyboard and main unit
                   get  [out of sync](../Hardware_Manual_guide/node0176.html) ).
        FA      Keyboard output buffer overflow
        FB      Unused (was controller failure)
        FC      Keyboard  [selftest failed](../Hardware_Manual_guide/node0177.html#line31) 
        FD      Initiate  [power-up key stream](../Hardware_Manual_guide/node0177.html#line46)  (keys pressed at powerup)
        FE      Terminate  [power-up key stream](../Hardware_Manual_guide/node0177.html#line46) 
        FF      Unused (was interrupt)
```
