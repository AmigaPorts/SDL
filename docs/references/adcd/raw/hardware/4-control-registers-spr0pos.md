# 4 / / Control Registers / SPR0POS


This is the sprite 0 position register. The  [word](../Hardware_Manual_guide/node00BA.html)  written into this
register controls the position on the screen at which the upper left-hand
corner of the sprite is to be placed. The most significant bit of the
first  [data word](../Hardware_Manual_guide/node00BC.html)  will be placed in this position on the screen.

   Sprite placement resolution.
   ----------------------------
   The sprites have a placement resolution on a full screen of 320 by
   200 NTSC (320 by 256 PAL). The sprite resolution is independent of
   the bitplane resolution.

Bit positions:

   *  Bits 15-8 specify the vertical start position, bits V7 - V0.
   *  Bits 7-0 specify the horizontal start position, bits H8 - H1.

   Warning:
   --------
   This register is normally only written by the sprite  [DMA channel](../Hardware_Manual_guide/node00BF.html) 
   itself. See the details above regarding the organization of the
   sprite data.  This register is usually updated directly by DMA.

