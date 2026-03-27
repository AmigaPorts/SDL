# B / imageclass / New Methods: IM_ERASE


The IM_ERASE method tells an image to erase itself.  Applications should
not call this method directly, instead they should call the Intuition
function [EraseImage()](../Includes_and_Autodocs_2._guide/node0215.html).  The return value for this method is not explicitly
defined.

The IM_ERASE method uses a custom message structure:


```c
    struct impErase
    {
        ULONG           MethodID;   /* IM_ERASE */
        struct RastPort *imp_RPort; /* The image's RastPort */
        struct
        {
            WORD X;                 /* X and Y offset relative */
            WORD Y;                 /* to the image's IA_Left  */
        } imp_Offset;               /* and IA_Top attributes.  */
    };
```
The [imageclass](../Libraries_Manual_guide/node04D1.html) dispatcher calls the graphics.library function [EraseRect()](../Includes_and_Autodocs_2._guide/node0439.html)
to erase the image.  The imageclass dispatcher gets the position of the
image using the offsets from the IM_ERASE message and the dimensions it
finds in the object's [Image](../Libraries_Manual_guide/node01BA.html) structure.  The imageclass dispatcher does not
do any bounds checking before calling EraseRect().

