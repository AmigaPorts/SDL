# 3 Playfield Hardware / Forming a Dual-playfield Display


For more flexibility in designing your background display, you can specify
two playfields instead of one.  In dual-playfield mode, one playfield is
displayed directly in front of the other.  For example, a computer game
display might have some action going on in one playfield in the
background, while the other playfield is showing a control panel in the
foreground. You can then change either the foreground or the background
without having to redesign the entire display. You can also move the two
playfields independently.

A dual-playfield display is similar to a single-playfield display,
differing only in these aspects:

   *  Each playfield in a dual display is formed from one, two or three

      bitplanes.
   *  The colors in each playfield (up to seven plus transparent) are

      taken from different sets of color registers.
   *  You must set a bit to activate dual-playfield mode.

Figure 3-12 shows a dual-playfield display.


```c
     [Figure 3-12: A Dual-playfield Display](../Hardware_Manual_guide/node02CE.html) 
```
In Figure 3-12, one of the colors in each playfield is "transparent"
(color 0 in playfield 1 and color 8 in playfield 2). You can use
transparency to allow selected features of the background playfield to
show through.

In dual-playfield mode, each playfield is formed from up to three
bitplanes.  Color registers 0 through 7 are assigned to playfield 1,
depending upon how many bitplanes you use.  Color registers 8 through 15
are assigned to playfield 2.

 [Bitplane Assignment in Dual-Playfield Mode](../Hardware_Manual_guide/node0079.html) 
 [Color Registers in Dual-Playfield Mode](../Hardware_Manual_guide/node007A.html) 
 [Dual-Playfield Priority and Control](../Hardware_Manual_guide/node007B.html) 
 [Activating Dual-Playfield Mode](../Hardware_Manual_guide/node007C.html) 
 [Dual Playfield Summary](../Hardware_Manual_guide/node007D.html) 

