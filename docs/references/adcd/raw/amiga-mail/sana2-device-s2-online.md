# sana2.device/S2_ONLINE


NAME

    Online -- Put a network interface back in service.
FUNCTION

    This command places an offline network interface back into service.
IO REQUEST

    ios2_Command    - S2_ONLINE.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

```c
    This command is responsible for putting the network interface
    hardware back into a known state (as close as possible to the
    state before S2_OFFLINE) and resets the unit global and special
    statistics.
```
SEE ALSO

    S2_OFFLINE
BUGS

