# 7 / Collision Detection / How Collisions are Determined


The video output is formed when the input data from all of the bitplanes
and the sprites is combined into a common data stream for the display. For
each of the pixel positions on the screen, the color of the highest
priority object is displayed. Collisions are detected when two or more
objects attempt to overlap in the same pixel position. This will set a bit
in the  [collision data register](../Hardware_Manual_guide/node015C.html) .

