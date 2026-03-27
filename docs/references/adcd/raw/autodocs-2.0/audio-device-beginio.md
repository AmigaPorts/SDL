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

    iORequest -- pointer to the I/O Request for this command
