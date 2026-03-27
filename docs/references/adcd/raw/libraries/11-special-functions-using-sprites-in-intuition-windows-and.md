# 11 Special Functions / Using Sprites in Intuition Windows and Screens


Sprite functionality has limitations under Intuition.  The hardware and
graphics library sprite systems manage sprites independently of the
Intuition display.  In particular:

  * Sprites cannot be attached to any particular screen.  Instead, they

    always appear in front of every screen.
  * When a screen is moved, the sprites do not automatically move with

```c
    it. The sprites move to their correct locations only when the
    appropriate function is called (either [DrawGList()](../Libraries_Manual_guide/node038D.html) or [MoveSprite()](../Libraries_Manual_guide/node037D.html)).
```
Hardware sprites are of limited use under the Intuition paradigm.  They
travel out of windows and out of screens, unlike all other Intuition
mechanisms (except the Intuition pointer, which is meant to be global).

Remember that sprite data must be in Chip memory to be accessible to the
custom chips.  This may be done with a compiler specific feature, such as
the __chip keyword of SAS/C.  Otherwise, Chip memory can be allocated with
the Exec [AllocMem()](../Libraries_Manual_guide/node02A7.html) function or the Intuition [AllocRemember()](../Libraries_Manual_guide/node01F8.html) function,
setting the memory requirement flag to [MEMF_CHIP](../Libraries_Manual_guide/node0288.html#line27).  The sprite data may
then be copied to Chip memory using a function like [CopyMem()](../Libraries_Manual_guide/node02AF.html) in the Exec
library.  See the chapter "[Graphics Sprites, Bobs and Animation](../Libraries_Manual_guide/node037C.html)" for more
information.

