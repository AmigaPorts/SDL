# 8 / Device Interface / Closing The Narrator Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node04C8.html) must be eventually matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).
This is necessary to allow the system to expunge the device in low memory
conditions.  As long as any task has the device open, or has forgotten to
close it before terminating, the narrator device will not be expunged.

All I/O requests must have completed before the task can close the device.
If any requests are still pending, the user must abort them before closing
the device.


```c
    if (!(CheckIO(VoiceIO)
        {
        AbortIO(VoiceIO);  /* Abort queued or in progress request */
        }
    WaitIO((struct IORequest *)VoiceIO); /* Wait for abort to do its job */
    CloseDevice(VoiceIO);                /* Close the device */
```
