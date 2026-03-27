# 15 Resources / CIA Resource


The CIA resource provides access to the timers and timer interrupt bits of
the [8520 Complex Interface Adapter](../Hardware_Manual_guide/node012E.html) (CIA) A and B chips.   This resource is
intended for use by high performance timing applications such as MIDI time
stamping and SMPTE time coding.

Four functions allow you to interact with the CIA hardware.


```c
                           CIA Resource Functions
                           ----------------------
     [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html)             Enable or disable Interrupt Control
                           Register interrupts.  Can also return the
                           current or previous enabled interrupt mask.

     [AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html)        Allocate one of the CIA timers by assigning
                           an interrupt handler to an interrupt bit
                           and enabling the interrupt of one of the
                           timers. If the timer you request is not
                           available, a pointer to the interrupt
                           structure that owns it will be returned.

     [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html)        Remove an interrupt handler from an
                           interrupt bit and disable the interrupt.

     [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html)              Cause or clear one or more interrupts, or
                           return the current or previous interrupt
                           status.
```
Each CIA chip has two interval timers within it - Timer A and Timer
B - that may be available. The CIA chips operate at different interrupt
levels with the CIA-A timers at interrupt level 2 and the CIA-B timers at
interrupt level 6.

   Choose A Timer Wisely.
   ----------------------
   The timer you use should be based solely on interrupt level and
   availability. If the timer you request is not available, try for
   another.  Whatever you do, do not base your decision on what you
   think the timer is used for by the system.

You allocate a timer by calling [AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html). This is the only way you
should access a timer.   If the function returns zero, you have
successfully allocated that timer.  If it is unavailable, the owner
interrupt will be returned.

   /* allocate CIA-A Timer A */
   inta = AddICRVector (CIAResource, CIAICRB_TA, &tint);

   if (inta)  /* if allocate was not successful */
```c
       printf("Error: Could not allocate timer\n");
```
   else

```c
       {
       ...ready for timing
       }
```
The timer is deallocated by calling [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html).  This is the only way
you should deallocate a timer.

   RemICRVector(CIAResource, CIAICRB_TA, &tint);

Your application should not make any assumptions regarding which interval
timers (if any) are available for use; other tasks or critical operating
system routines may be using the interval timers. In fact, in the latest
version of the operating system, the [timer device](../Devices_Manual_guide/node00BD.html) may dynamically allocate
one of the interval timers.

   Time Is Of The Essence!
   -----------------------
   There are a limited number of free CIA interval timers.  Applications
   which use the interval timers may not be able to run at the same time
   if all interval timers are in use.  As a general rule, you should use
   the timer device for most interval timing.

You read from and write to the CIA interrupt control registers using
[SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) and [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html).  [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) is useful for sampling which cia
interrupts (if any) are active.  It can also be used to clear and generate
interrupts.  [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html) is used to disable and enable a particular CIA
interrupt.  Additional information about these functions can be found in
the Amiga ROM Kernel Reference Manual: Includes and Autodocs.

Things to keep in mind:

   1. Never directly read from or write to the CIA interrupt control

```c
      registers.  Always use [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) and [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html).
```
   2. Your interrupt routine will be called with a pointer to your data

      area in register A1, and a pointer to the code being called in
      register A5. No other registers are set up for you.  You must observe
      the standard convention of preserving all registers except D0-D1 and
      A0-A1.
   3. Never turn off all level 2 or level 6 interrupts.  The proper way to

```c
      disable interrupts for an interval timer that you've successfully
      allocated is via the [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html) function.
```
   4. Interrupt handling code should be written in assembly code and, if

      possible, should signal a task to do most of the work.
   5. Do not make assumptions about which CIA interval timers (if any) are

```c
      available for use.  The only proper way to own an interval timer is
      via the [AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html) function.
```
   6. Do not use [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html), [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html) and [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html) to affect timers or

      other CIA hardware which your task does not own.
Changes in the CIA resource:

   *  In pre-V36 versions of the operating system, [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) could return

```c
      FALSE for a particular interrupt just prior to processing the
      interrupt. [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) now returns TRUE for a particular interrupt until
      sometime after the interrupt has been processed.
```
   *  Applications which only need to read a CIA interval timer should use

```c
      the [ReadEClock()](../Includes_and_Autodocs_2._guide/node04FB.html) function of the timer device.  See "[Timer Device](../Devices_Manual_guide/node00C8.html)"
      chapter of this manual for more information on ReadEClock().
```
   *  The timer device may dynamically allocate a free CIA interval timer.

```c
      Do not make any assumptions regarding which interval timers are in
      use unless you are taking over the machine completely.

     [Cia_Interval.c](../Devices_Manual_guide/node01A2.html) 
```
Additional programming information on the CIA resource can be found in the
include files and the Autodocs for the CIA resource and the 8520 spec.
The includes files and Autodocs are in the Amiga ROM Kernel Reference
Manual: Includes and Autodocs and the 8520 spec is in the Amiga
[Hardware Reference Manual](../Hardware_Manual_guide/node012E.html).


```c
                         CIA Resource Information
                     -------------------------------
                     INCLUDES        resources/[cia.h](../Includes_and_Autodocs_2._guide/node010D.html)
                                     resources/[cia.i](../Includes_and_Autodocs_2._guide/node0110.html)
                                     hardware/[cia.h](../Includes_and_Autodocs_2._guide/node00C7.html)
                                     hardware/[cia.i](../Includes_and_Autodocs_2._guide/node00CA.html)

                     AUTODOCS        [cia.doc](../Includes_and_Autodocs_2._guide/node0535.html)

                     HARDWARE        8520 specification
```
