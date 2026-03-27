# 8 / Creating Images / Image Data


Image data must be in Chip memory.  The [Image](../Libraries_Manual_guide/node01BA.html) structure itself may be in
any memory, but the actual data referenced by [ImageData](../Libraries_Manual_guide/node01BA.html#line47) field must be in
Chip memory.  This may be done by using compiler specific options, such as
the __chip keyword of SAS/C, or by allocating memory with the [MEMF_CHIP](../Libraries_Manual_guide/node02A8.html#line11)
attribute and copying the image data to that memory.

 [Defining Image Data](../Libraries_Manual_guide/node01BD.html) 

