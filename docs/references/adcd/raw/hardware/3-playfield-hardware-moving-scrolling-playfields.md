# 3 Playfield Hardware / Moving (Scrolling) Playfields


If you want a background display that moves, you can design a playfield
larger than the display window and scroll it. If you are using dual
playfields, you can scroll them separately.

In vertical scrolling, the playfield appears to move smoothly up or down
on the screen. All you need do for vertical scrolling is progressively
increase or decrease the starting address for the bitplane pointers by the
size of a horizontal line in the playfield. This has the effect of showing
a lower or higher part of the picture each field time.

In horizontal scrolling the playfield appears to move from right-to-left
or left-to-right on the screen. Horizontal scrolling works differently
from vertical scrolling -- you must arrange to fetch one more word of data
for each display line and delay the display of this data.

For either type of scrolling, resetting of pointers or data-fetch
registers can be handled by the Copper during the  [vertical blanking](../Hardware_Manual_guide/node0169.html) 
interval.

 [Vertical Scrolling](../Hardware_Manual_guide/node0087.html) 
 [Horizontal Scrolling](../Hardware_Manual_guide/node0088.html) 
 [Scrolling Playfield Summary](../Hardware_Manual_guide/node008C.html) 

