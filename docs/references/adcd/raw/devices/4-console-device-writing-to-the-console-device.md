# 4 Console Device / Writing to the Console Device


You write to the console device by passing an I/O request to the device
with a pointer to the write buffer set in io_Data, the number of bytes in
the buffer set in io_Length and [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0508.html) set in io_Command.


```c
    UBYTE *outstring= "Make it so.";

    ConsIO->io_Data = outstring;
    ConsIO->io_Length = strlen(outstring);
    ConsIO->io_Command = CMD_WRITE;
    DoIO(ConsIO);
```
You may also send NULL-terminated strings to the console device in the
same manner except that io_Length must be set to -1.


```c
    ConsIO->io_Data = "\033[3mOh boy.";
    ConsIO->io_Length = -1;
    ConsIO->io_Command = CMD_WRITE;
    DoIO(ConsIO);
```
The fragment above will output the string "Oh boy." in italics.  Keep in
mind that setting the text rendition to italics will remain in effect
until you specifically instruct the console device to change it to another
text style.

 [Hints For Writing Text](../Devices_Manual_guide/node008B.html) 
 [Control Sequences For Window Output](../Devices_Manual_guide/node008C.html) 
 [Example Console Control Sequences](../Devices_Manual_guide/node008E.html) 

