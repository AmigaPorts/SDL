---
title: 4 Console Device / Writing to the Console Device
manual: devices
chapter: devices
section: 4-console-device-writing-to-the-console-device
functions: []
libraries: []
---

# 4 Console Device / Writing to the Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You write to the console device by passing an I/O request to the device
with a pointer to the write buffer set in io_Data, the number of bytes in
the buffer set in io_Length and [CMD_WRITE](autodocs-2.0/console-device-cmd-write.md) set in io_Command.


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

 [Hints For Writing Text](devices/4-writing-to-the-console-device-hints-for-writing-text.md) 
 [Control Sequences For Window Output](devices/4-writing-to-the-console-device-control-sequences-for.md) 
 [Example Console Control Sequences](devices/4-writing-to-the-console-device-example-console-control.md) 

