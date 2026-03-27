# 3 Intuition Screens / Types of Screens


Screens are important because they determine the basic resolution and
maximum number of colors in the display.  Once a screen is set up, these
attributes cannot be changed so any graphics work done on a given screen
is restricted to that screen's resolution and number of colors.  Hence,
the type of screen used is a basic design decision.

With Intuition screens, a [video display](../Libraries_Manual_guide/node0313.html) can be created in any one of the
many Amiga display modes.  The basic parameters of the video display such
as resolution, total size, frame rate, genlock compatibility, support of
screen movement and number of colors are defined by these modes.  There
are currently four basic modes available on all Amiga models.  These basic
modes work with conventional monitors (15 kHz scan rate) and older
[versions](../Libraries_Manual_guide/node0014.html) of the operating system.




```c
            Table 3-1: Basic Amiga Display Modes


     Basic Amiga      Resolution  Maximum    Supports
    Display Modes        NTSC       PAL       Colors    HAM/EHB*
    -------------     ----------  -------    --------   -------
    [Lores](../Libraries_Manual_guide/node0317.html)              320x200    320x256   32 of 4096    Yes
    Lores-[Interlaced](../Libraries_Manual_guide/node0316.html)   320x400    320x512   32 of 4096    Yes
    [Hires](../Libraries_Manual_guide/node0317.html)              640x200    640x256   16 of 4096    No
    Hires-Interlaced   640x400    640x512   16 of 4096    No


    * [HAM](../Libraries_Manual_guide/node0348.html) and [EHB](../Libraries_Manual_guide/node0347.html) modes provide for additional colors with some
      restrictions.
```
With Release 2 of the operating system, many other display modes are
available (these usually require a [special monitor](../Libraries_Manual_guide/node0336.html) or [ECS](../Libraries_Manual_guide/node0319.html)).  All these
display modes, including the specialized modes, are integrated through the
graphics library display database.  See the "[Graphics Primitives](../Libraries_Manual_guide/node0318.html)" chapter
for a complete list of all Amiga display modes.

 [Multiple Screens](../Libraries_Manual_guide/node00D9.html) 
 [Public Screens and Custom Screens](../Libraries_Manual_guide/node00DA.html) 
 [Screen Components](../Libraries_Manual_guide/node00DB.html) 

