# audio.device/BeginIO



   NAME

       BeginIO - dispatch a device command
   SYNOPSIS

```c
       BeginIO(iORequest);
                   A1
```
   FUNCTION

       BeginIO has the responsibility of dispatching all device commands.
       Immediate commands are always called directly, and all other commands
       are queued to make them single threaded.
   INPUTS

```c
       iORequest -- pointer to the I/O [Request](../Includes_and_Autodocs_3._guide/node03E5.html) for this command
```
