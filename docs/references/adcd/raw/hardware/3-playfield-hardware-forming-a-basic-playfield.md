# 3 Playfield Hardware / Forming a Basic Playfield


To get you started, this section describes how to directly access hardware
registers to form a single basic playfield that is the same size as the
video screen. Here, "same size" means that the playfield is the same size
as the actual display window. This will leave a small border between the
playfield and the edge of the video screen. The playfield usually does not
extend all the way to the edge of the physical display.

To form a playfield, you need to define these characteristics:

   *  Height and width of the playfield and size of the display window
```c
      (that is, how much of the playfield actually appears on the screen).
```
   *  Color of each pixel in the playfield.
   *  Horizontal resolution.
   *  Vertical resolution, or interlacing.
   *  Data fetch and modulo, which tell the system how much data to put on

      a horizontal line and how to fetch data from memory to the screen.
In addition, you need to allocate memory to store the playfield, set
pointers to tell the system where to find the data in memory, and
(optionally) write a Copper routine to handle redisplay of the playfield.

 [Height and Width of the Playfield](../Hardware_Manual_guide/node0065.html) 
 [Bitplanes and Color](../Hardware_Manual_guide/node0066.html) 
 [Selecting Horizontal and Vertical Resolution](../Hardware_Manual_guide/node0069.html) 
 [Allocating Memory for Bitplanes](../Hardware_Manual_guide/node006A.html) 
 [Coding the Bitplanes for Correct Coloring](../Hardware_Manual_guide/node006C.html) 
 [Defining the Size of the Display Window](../Hardware_Manual_guide/node006F.html) 
 [Telling the System How to Fetch and Display Data](../Hardware_Manual_guide/node0072.html) 
 [Displaying and Redisplaying the Playfield](../Hardware_Manual_guide/node0075.html) 
 [Enabling the Color Display](../Hardware_Manual_guide/node0076.html) 
 [Basic Playfield Summary](../Hardware_Manual_guide/node0077.html) 
 [Example of Forming a Basic LORES Playfield](../Hardware_Manual_guide/node02CC.html) 
 [Example of Forming a Basic HIRES Playfield](../Hardware_Manual_guide/node02CD.html) 

