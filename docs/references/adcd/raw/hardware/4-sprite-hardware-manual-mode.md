# 4 Sprite Hardware / Manual Mode


It is almost always best to load sprites using the  [automatic](../Hardware_Manual_guide/node00C8.html#line86)  DMA
channels. Sometimes, however, it is useful to load these registers
directly from one of the microprocessors. Sprites may be activated
"manually" whenever they are not being used by a DMA channel. The same
sprite that is showing a DMA-controlled icon near the top of the screen
can also be reloaded manually to show a vertical colored bar near the
bottom of the screen. Sprites can be activated manually even when the
sprite DMA is turned off.

You display sprites manually by writing to the sprite data registers
 [SPRxDATB and SPRxDATA](../Hardware_Manual_guide/node00C8.html#line8) , in that order. You write to  [SPRxDATA](../Hardware_Manual_guide/node00C8.html#line8)  last because
that address "arms" the sprite to be output at the next horizontal
comparison. The data written will then be displayed on every line, at the
horizontal position given in the "H" portion of the position registers
 [SPRxPOS](../Hardware_Manual_guide/node00CD.html)  and  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) . If the data is unchanged, the result will be a
vertical bar. If the data is reloaded for every line, a complex sprite can
be produced.

The sprite can be terminated ("disarmed") by writing to the  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) 
register. If you write to the  [SPRxPOS](../Hardware_Manual_guide/node00CD.html)  register, you can manually move the
sprite horizontally at any time, even during normal sprite usage.

