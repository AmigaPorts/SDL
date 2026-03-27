# 28 / Using Simple (Hardware) Sprites / Simple Sprite Functions


There are four basic functions that you use to to control Simple Sprites:


```c
       [GetSprite()](../Libraries_Manual_guide/node037B.html)  Attempts to allocates a sprite for exclusive use
    [ChangeSprite()](../Libraries_Manual_guide/node037C.html)  Modifies a Simple Sprite's image data
      [MoveSprite()](../Libraries_Manual_guide/node037D.html)  Changes a Simple Sprite's position
      [FreeSprite()](../Libraries_Manual_guide/node037E.html)  Relinquishes a sprite so it can be used by others
```
To use these Simple Sprite functions (or the VSprite functions) the SPRITE
flag must have been set in the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure for [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6). If
Intuition is not being used, this flag must be specified in the [View](../Libraries_Manual_guide/node00F1.html#line4) and
[ViewPort](../Libraries_Manual_guide/node00F1.html#line4) data structures before [MakeVPort()](../Libraries_Manual_guide/node0332.html) is called.

 [Accessing A Hardware Sprite](../Libraries_Manual_guide/node037B.html) 
 [Changing The Appearance Of A Simple Sprite](../Libraries_Manual_guide/node037C.html) 
 [Moving A Simple Sprite](../Libraries_Manual_guide/node037D.html) 
 [Relinquishing A Simple Sprite](../Libraries_Manual_guide/node037E.html) 
 [Controlling Sprite DMA](../Libraries_Manual_guide/node037F.html) 
 [Complete Simple Sprite Example](../Libraries_Manual_guide/node05F3.html) 

