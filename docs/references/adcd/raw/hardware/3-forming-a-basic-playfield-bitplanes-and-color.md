# 3 / Forming a Basic Playfield / Bitplanes and Color


You define playfield color by:

   1. Deciding how many colors you need and how you want to color
      each pixel.
   2. Loading the colors into the color registers.
   3. Allocating memory for the number of bitplanes you need and setting
      a pointer to each bitplane.
   4. Writing instructions to place a value in each bit in the bitplanes

      to give you the correct color.
Table 3-1 shows how many bitplanes to use for the color selection you need.




                    Number of     Number of
                     Colors       Bitplanes
                    ---------     ---------
                      1 - 2           1
                      3 - 4           2
                      5 - 8           3
                     9 - 16           4
                    17 - 32           5


           Table 3-1: Colors in a Single Playfield
 [The Color Table](../Hardware_Manual_guide/node0067.html) 
 [Selecting the Number of Bitplanes](../Hardware_Manual_guide/node0068.html) 

