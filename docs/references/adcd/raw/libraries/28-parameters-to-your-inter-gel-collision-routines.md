# 28 / / / Parameters To Your Inter-GEL Collision Routines


If, instead of a GEL-to-boundary collision, [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16) senses a
GEL-to-GEL collision, the system calls your collision routine with the
following two arguments:

  * Address of the VSprite that is the uppermost (or leftmost if y

```c
    coordinates are identical) GEL of a colliding pair.
```
  * Address of the VSprite that is the lowermost (or rightmost if y

```c
    coordinates are identical) GEL of the pair.
```
