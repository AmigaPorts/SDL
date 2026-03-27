# 27 / / Viewport Display Modes / Single- vs. Dual-playfield Mode


When you specify single-playfield mode you are asking that the system
treat all bitplanes as part of the definition of a single playfield image.
Each of the bitplanes defined as part of this [ViewPort](../Libraries_Manual_guide/node032B.html#line59) contributes data
bits that determine the color of the pixels in a single playfield.


```c
     [Figure 27-12: A Single-playfield Display](../Libraries_Manual_guide/node05EF.html) 
```
If you use dual-playfield mode, you can define two independent, separately
controllable playfield areas as shown on the next page.


```c
     [Figure 27-13: A Dual-playfield Display](../Libraries_Manual_guide/node05F0.html) 
```
In the previous figure, [PFBA](../Libraries_Manual_guide/node0327.html#line19) was included in the display mode.  If PFBA
had not been included, the relative priorities would have been reversed;
playfield 2 would have appeared to be behind playfield 1.

