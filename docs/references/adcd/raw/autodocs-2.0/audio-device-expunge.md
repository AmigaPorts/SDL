# audio.device/Expunge



NAME

    EXPUNGE - indicate a desire to remove the Audio device
FUNCTION

```c
    The Expunge routine is called when a user issues a [RemDevice](../Includes_and_Autodocs_2._guide/node036F.html) call.  By
    the time it is called, the device has already been removed from the
    device list, so no new opens will succeed.  The existence of any other
    users of the device, as determined by the device open count being
    non-zero, will cause the Expunge to be deferred.  When the device is
    not in use, or no longer in use, the Expunge is actually performed.
```
