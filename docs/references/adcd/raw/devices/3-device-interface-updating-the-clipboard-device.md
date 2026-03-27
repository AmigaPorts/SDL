# 3 / Device Interface / Updating The Clipboard Device


When the final write is done, an update command must be sent to the device
to indicate that the writing is complete and the data is available. You
update the clipboard device by passing an IOClipReq to the device with
CMD_UPDATE set in io_Command.


```c
    ClipIO->io_Command = CMD_UPDATE;
    DoIO(ClipIO);
```
