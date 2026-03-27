# 4 / / Building the Data Structure / Sprite Control Word 2 : SPRxCTL


This word contains the vertical stopping position of the sprite on the
screen (i.e., the line AFTER the last displayed row of the sprite). It
also contains some data having to do with  [sprite attachment](../Hardware_Manual_guide/node00C6.html) , which is
described later on.



```c
                                [SPRxCTL](../Hardware_Manual_guide/node00CE.html) 
                               ---------
          Bits 15-8       The low eight bits of VSTOP
          Bit 7           (Used in attachment)
          Bits 6-3        Unused (make zero)
          Bit 2           The VSTART high bit
          Bit 1           The VSTOP high bit
          Bit 0           The HSTART low bit
```
The value (VSTOP - VSTART) defines how many scan lines high the sprite
will be when it is displayed.

