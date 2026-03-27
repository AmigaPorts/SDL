# cia.resource/AbleICR



NAME

    AbleICR -- Enable/disable ICR interrupts.
SYNOPSIS

```c
    oldMask = AbleICR( Resource, mask )
    D0                 A6        D0

    WORD AbleICR( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD );
```
FUNCTION

```c
    This function provides a means of enabling and disabling 8520
    [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) interrupt control registers. In addition it returns the
    previous enable mask.
```
INPUTS

    mask            A bit mask indicating which interrupts to be
                        modified. If bit 7 is clear the mask
                        indicates interrupts to be disabled. If
                        bit 7 is set, the mask indicates
                        interrupts to be enabled. Bit positions
                        are identical to those in 8520 ICR.
RESULTS

    oldMask         The previous enable mask before the requested
                        changes. To get the current mask without
                        making changes, call the function with a
                        null parameter.
EXAMPLES

```c
    Get the current mask:
        mask = AbleICR(0)
    Enable both timer interrupts:
        AbleICR(0x83)
    Disable serial port interrupt:
        AbleICR(0x08)
```
EXCEPTIONS

```c
    Enabling the mask for a pending interrupt will cause an
    immediate processor interrupt (that is if everything else is
    enabled). You may want to clear the pending interrupts with
    [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) prior to enabling them.
```
NOTE

```c
    The [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources require an extra parameter
    to specify which [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    oldMask = AbleICR( Resource, mask )
    D0                 A6        D0

    WORD AbleICR( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD );
```
SEE ALSO

```c
    [cia.resource/SetICR()](../Includes_and_Autodocs_2._guide/node0539.html)
```
