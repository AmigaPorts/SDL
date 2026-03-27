# sana2.device/S2_TRACKTYPE


NAME

    TrackType -- Accumulate statistics about a packet type.
FUNCTION

    This command causes the device driver to accumulate statistics about
    a particular packet type. Packet type statistics, for the particular
    packet type, are zeroed by this command.
IO REQUEST

    ios2_Command    - S2_TRACKTYPE.
    ios2_PacketType - Packet type of interest.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
```
NOTES

SEE ALSO

    S2_UNTRACKTYPE, S2_GETTYPESTATS
BUGS

