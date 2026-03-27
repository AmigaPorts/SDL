# D / Errors / Fails only on machines with Fast RAM


Data and buffers which will be accessed directly by the custom chips must
be in Chip RAM.  This includes bitplanes (use [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) or
[AllocRaster()](../Libraries_Manual_guide/node032E.html)), audio samples, trackdisk buffers, and the graphic image
data for sprites, pointers, bobs, images, gadgets, etc.  Use compiler or
linker flags to force Chip RAM loading of any initialized data needing to
be in Chip RAM, or dynamically allocate Chip RAM and copy any
initialization data there.

