# sana2.device/CMD_FLUSH


NAME

    Flush -- Clear all queued I/O requests for the SANA-II device.
FUNCTION

```c
    This command aborts all I/O requests in both the read and write
    request queues of the device.  All pending I/O requests are
    returned with an error message (IOERR_ABORTED).  CMD_FLUSH does not
    affect active requests.
```
IO REQUEST

    ios2_Command    - CMD_FLUSH.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
```
NOTES

SEE ALSO

BUGS

