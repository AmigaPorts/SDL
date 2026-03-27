# 4 / / Building the Data Structure / End-of-data Words


When the vertical position of the  [beam counter](../Hardware_Manual_guide/node015E.html)  is equal to the VSTOP
value in the sprite  [control words](../Hardware_Manual_guide/node00BB.html) , the next two words fetched from the
sprite data structure are written into the sprite  [control registers](../Hardware_Manual_guide/node00CC.html) 
instead of being sent to the  [color registers](../Hardware_Manual_guide/node00D0.html) . These two words are
interpreted by the hardware in the same manner as the original words that
were first loaded into the  [control registers](../Hardware_Manual_guide/node00CC.html) . If the VSTART value
contained in these words is lower than the current beam position, this
sprite will not be reused in this display field. For consistency, the
value 0 should be used for both words when ending the usage of a sprite.
 [Sprite reuse](../Hardware_Manual_guide/node00C4.html)  is discussed later.

The following data structure is for the spaceship sprite. It will be
located at V = 65 and H = 128 on the normally visible part of the
screen.

SPRITE:

```c
        DC.W    $6D60,$7200     ;VSTART, HSTART, VSTOP
        DC.W    $0990,$07E0     ;First pair of descriptor words
        DC.W    $13C8,$0FF0
        DC.W    $23C4,$1FF8
        DC.W    $13C8,$0FF0
        DC.W    $0990,$07E0
        DC.W    $0000,$0000     ;End of sprite data
```
