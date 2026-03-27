# E / / External Disk Interface Specification / Limitations


1.  The total cable length, including daisy chaining, must not exceed
    1 meter.
2.  A maximum of 3 external devices may reside on this interface,
    but specific implementations may support fewer external devices.
3.  Each device must provide a 1000-Ohm pull-up resistor on those
```c
    outputs driven by an open-collector device on the Amiga
    (pins 8-10, 16-21).
```
4.  The system provides power for only the first external device in

    the daisy chains.
