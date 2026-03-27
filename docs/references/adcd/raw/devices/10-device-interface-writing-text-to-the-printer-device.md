# 10 / Device Interface / Writing Text To The Printer Device


Text written to a printer can be either processed text or unprocessed text.

Processed text is written to the device using the [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) command. The
printer device accepts a character stream, translates any embedded escape
sequences into the proper sequences for the printer being used and then
sends it to the printer.  The escape sequence translation is based on the
printer driver selected either through Preferences or through your
application.  You may also send a NULL-terminated string as processed text.

Unprocessed text is written to the device using the [PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html) command.
The printer device accepts a character stream and sends it unchanged to
the printer.  This implies that you know the exact escape sequences
required by the printer you are using.  You may not send a NULL-terminated
string as unprocessed text.

One additional point to keep in mind when using [PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html) is that
Preference settings for the printer are ignored.  Unless the printer has
already been initialized by another command, the printer's own default
settings will be used when printing raw, not the user's Preferences
settings.

You write processed text to the printer device by passing an [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line29) to
the device with [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) set in io_Command, the number of bytes to be
written set in io_Length and the address of the write buffer set in
io_Data.

To write a NULL-terminated string, set the length to -1; the device will
output from your buffer until it encounters a value of zero (0x00).


```c
    PrintIO->ios.io_Length  = -1;
    PrintIO->ios.io_Data    =
         (APTR)"I went to a fight and a hockey game broke out."
    PrintIO->ios.io_Command = CMD_WRITE;
    DoIO((struct IORequest *)PrintIO);
```
The length of the request is -1, meaning we are writing a NULL-terminated
string. The number of characters sent will be found in io_Actual after the
write request has completed.

You write unprocessed text to the printer device by passing an [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) to
the device with [PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html) set in io_Command, the number of bytes to be
written set in io_Length and the address of the write buffer set in
io_Data.


```c
    UBYTE *outbuffer;

    PrintIO->ios.io_Length   = strlen(outbuffer);
    PrintIO->ios.io_Data     = (APTR)outbuffer;
    PrintIO->ios.io_Command  = PRD_RAWWRITE;
    DoIO((struct IORequest *)PrintIO);
```
   IOStdReq Only.
   --------------
   I/O requests with [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) and [PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html) must use the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28)
   structure of the union [printerIO](../Devices_Manual_guide/node0044.html#line16).

