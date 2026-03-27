# 26 / Introduction / Sequence of Events During an Interrupt


Before useful interrupt handling code can be executed, a considerable
amount of hardware and software activity must occur.  Each interrupt must
propagate through several hardware and software interfaces before
application code is finally dispatched:

  * A hardware device decides to cause an interrupt and sends a signal to

```c
    the interrupt control portions of the 4703 (Paula) custom chip.
```
  * The 4703 interrupt control logic notices this new signal and performs

```c
    two primary operations.  First, it records that the interrupt has
    been requested by setting a flag bit in the [INTREQ](../Hardware_Manual_guide/node0164.html#line11) register.  Second,
    it examines the [INTENA](../Hardware_Manual_guide/node0164.html#line4) register to determine whether the
    corresponding interrupt and the interrupt master are enabled.  If
    both are enabled, the 4703 generates an interrupt request by placing
    the priority level of the request onto the three 68000 interrupt
    control input lines (IPL0, IPL1, IPL2).
```
  * These three signals correspond to seven interrupt priority levels in

```c
    the 68000.  If the priority of the new interrupt is greater than the
    current processor priority, an interrupt sequence is initiated. The
    priority level of the new interrupt is used to index into the top
    seven words of the processor address space.  The odd byte (a vector
    number) of the indexed word is fetched and then shifted left by two
    to create an offset into the processor's auto-vector interrupt table.
    The vector offsets used are in the range of $064 to $07C.  These are
    labeled as interrupt autovectors in the 68000 manual.  The
    auto-vector table appears in low memory on a 68000 system, but its
    location for other 68000 family processors is determined by the
    processor's CPU Vector Base Register (VBR).  VBR can be accessed from
    [supervisor mode](../Libraries_Manual_guide/node02CA.html) with the MOVEC instruction.
```
  * The processor then switches into [supervisor mode](../Libraries_Manual_guide/node02CA.html) (if it is not

```c
    already in that mode), and saves copies of the status register and
    program counter (PC) onto the top of the system stack (additional
    information may be saved by processors other than the 68000).  The
    processor priority is then raised to the level of the active
    interrupt.
```
  * From the low memory vector address (calculated in step three above),

    a 32-bit autovector address is fetched and loaded into the program
    counter.  This is an entry point into Exec's interrupt dispatcher.
  * Exec must now further decode the interrupt by examining the [INTREQ](../Hardware_Manual_guide/node0164.html#line11)

```c
    and [INTENA](../Hardware_Manual_guide/node0164.html#line4) 4703 chip registers.  Once the active interrupt has been
    determined, Exec indexes into an [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line31) array to fetch the
    interrupt's handler entry point and handler data pointer addresses.
```
  * Exec now turns control over to the interrupt handler by calling it as

    if it were a subroutine.  This handler may deal with the interrupt
    directly or may propagate control further by invoking interrupt
    server chain processing.
You can see from the above discussion that the interrupt autovectors
should never be altered by the user.  If you wish to provide your own
system interrupt handler, you must use the Exec [SetIntVector()](../Libraries_Manual_guide/node030A.html#line23) function.
You should not change the contents of any autovector location.

Task multiplexing usually occurs as the result of an interrupt.  When an
interrupt has finished and the processor is about to return to user mode,
Exec determines whether task-scheduling attention is required.  If a task
was signaled during interrupt processing, the task scheduler will be
invoked.  Because Exec uses preemptive task scheduling, it can be said
that the interrupt subsystem is the heart of task multiplexing.  If, for
some reason, interrupts do not occur, a task might execute forever because
it cannot be forced to relinquish the CPU.



```c
                    Table 26-1: Interrupts by Priority

                  Exec
    Hardware    Pseodo-
    Priority    Priority   Description                Label   Type
    --------    --------   -----------                -----   ----
              ____
             |     1    Serial transmit buffer empty  TBE      H
             |
       1 ----|     2    disk block complete           DSKBLK   H
             |
             |     3    software interrupt            SOFTINT  H
             |----
       2 ----|     4    external INT2 & CIAA          PORTS    S
             |----
             |     5    graphics coprocessor          COPER    S
             |
       3 ----|     6    vertical blank interval       VERTB    S
             |
             |     7    blitter finished              BLIT     H
             |----
             |     8    audio channel 2               AUD2     H
             |
             |     9    audio channel 0               AUD0     H
       4 ----|
             |     10   audio channel 3               AUD3     H
             |
             |     11   audio channel 1               AUD1     H
             |----
             |     12   Serial receive buffer full    RBF      H
       5 ----|
             |     13   disk sync pattern found       DSKSYNC  H
             |----
             |     14   external INT6 & CIAB          EXTER    S
       6 ----|
             |     15   special (master enable)       INTEN    -
             |----
       7 ----|____ --   non-maskable interrupt        [NMI](../Libraries_Manual_guide/node0305.html)      S
```
