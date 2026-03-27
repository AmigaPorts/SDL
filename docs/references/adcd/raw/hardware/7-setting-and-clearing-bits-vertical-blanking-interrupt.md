# 7 / / Setting and Clearing Bits / Vertical Blanking Interrupt


Bit 5, VERTB, causes an interrupt at line 0 (start of vertical blank) of
the video display frame. The system is often required to perform many
different tasks during the vertical blanking interval. Among these tasks
are the updating of various pointer registers, rewriting lists of Copper
tasks when necessary, and other system-control operations.

The minimum time of vertical blanking is 20 horizontal scan lines for an
NTSC system and 25 horizontal scan lines for a PAL system. The range
starts at line 0 and ends at line 20 for NTSC or line 25 for PAL. After
the minimum vertical blanking range, you can control where the display
actually starts by using the  [DIWSTRT](../Hardware_Manual_guide/node0083.html)  (display window start) register
to extend the effective vertical blanking time. See Chapter 3, "Playfield
Hardware," for more information on  [DIWSTRT](../Hardware_Manual_guide/node0083.html) .

If you find that you still require additional time during vertical
blanking, you can use the Copper to create a  [level 3 interrupt](../Hardware_Manual_guide/node016F.html) . This
Copper interrupt would be timed to occur just after the last line of
display on the screen (after the display window stop which you have
defined by using the  [DIWSTOP](../Hardware_Manual_guide/node0071.html)  register).

