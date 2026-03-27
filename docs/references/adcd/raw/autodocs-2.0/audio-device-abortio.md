# audio.device/AbortIO



NAME

    AbortIO - abort a device command
SYNOPSIS

```c
    AbortIO(iORequest);
                A1
```
FUNCTION

    AbortIO tries to abort a device command.  It is allowed to be
    unsuccessful.  If the Abort is successful, the io_Error field of the
    iORequest contains an indication that IO was aborted.
INPUTS

    iORequest -- pointer to the I/O Request for the command to abort
