# sana2.device/CMD_RESET


NAME

    Reset -- Reset the network interface to initialized state.
FUNCTION

```c
    Currently, SANA-II devices can only be configured once (with
    CMD_CONFIGINTERFACE) and cannot be re-configured, hence,
    CMD_RESET does not apply to this class of device.
```
IO REQUEST

    ios2_Command    - CMD_RESET.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

BUGS

