# 3 / / Bitplanes and Color / Selecting the Number of Bitplanes


After deciding how many colors you want and how many bitplanes are
required to give you those colors, you tell the system how many bitplanes
to use.

You select the number of bitplanes by writing the number into the register
 [BPLCON0](../Hardware_Manual_guide/node0092.html)  (for Bitplane Control Register 0) The relevant bits are bits 14,
13, and 12, named BPU2, BPU1, and BPU0 (for "Bitplanes Used"). Table 3-5
shows the values to write to these bits and how the system assigns
bitplane numbers.




```c
          Table 3-5: Setting the Number of Bitplanes


                    Number of     Name(s) of
          Value     Bitplanes     Bitplanes
          -----     ---------     ----------
           000       None *
           001         1           PLANE 1
           010         2           PLANES 1 and 2
           011         3           PLANES 1 - 3
           100         4           PLANES 1 - 4
           101         5           PLANES 1 - 5
           110         6           PLANES 1 - 6 **
           111                     Value not used.


     *  Shows only a background color; no playfield is visible.

     ** Sixth bitplane is used only in  [dual-playfield mode](../Hardware_Manual_guide/node0079.html)  and in
         [hold-and-modify mode](../Hardware_Manual_guide/node008F.html)  (described in the section called
        Advanced Topics.
```
   About the  [BPLCON0](../Hardware_Manual_guide/node0092.html)  register.
   ----------------------------
   The bits in the  [BPLCON0](../Hardware_Manual_guide/node0092.html)  register cannot be set independently.  To set
   any one bit, you must reload them all.


The following example shows how to tell the system to use two low
resolution bitplanes.


```c
        MOVE.W  #$2200,[BPLCON0](../Hardware_Manual_guide/node0092.html)+CUSTOM   ; Write to it
```
Because register  [BPLCON0](../Hardware_Manual_guide/node0092.html)  is used for setting other characteristics of the
display and the bits are not independently settable, the example above
also sets other parameters (all of these parameters are described later
in the chapter).

   [*](../Hardware_Manual_guide/node008F.html#line51)   Hold-and-modify mode is turned off.
   [*](../Hardware_Manual_guide/node007C.html)   Single-playfield mode is set.
   [*](../Hardware_Manual_guide/node0076.html)   Composite video color is enabled.  (Not applicable in all models.)
   [*](../Hardware_Manual_guide/node0092.html#line24)   Genlock audio is disabled.
   [*](../Hardware_Manual_guide/node018A.html#line26)   Light pen is disabled.
   [*](../Hardware_Manual_guide/node0069.html#line94)   Interlaced mode is disabled.
   [*](../Hardware_Manual_guide/node0092.html#line11)   External resynchronization is disabled. (genlock)

