# 3 / Forming a Basic Playfield / Enabling the Color Display


The stock A1000 has a color composite output and requires bit 9 (COLOR_ON)
set in  [BPLCON0](../Hardware_Manual_guide/node0092.html)  to create a color composite display signal. Without the
addition of specialized hardware, the A500, A2000 and A3000 cannot
generate color composite output.

   NOTE:
   -----
   The color burst enable does not affect the RGB video signal. RGB
   video is correctly generated regardless of the output of the
   composite video signal.

