---
title: 1 Introduction to Libraries / General Amiga Development Guidelines
manual: libraries
chapter: libraries
section: 1-introduction-to-libraries-general-amiga-development
functions: [AllocMem, Delay, Disable, Forbid, ReplyMsg, Wait, WaitTOF]
libraries: [dos.library, exec.library, graphics.library]
---

# 1 Introduction to Libraries / General Amiga Development Guidelines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the earlier sections of this chapter, the [basic environment](libraries/1-introduction-to-libraries-programming-in-the-amiga.md) of the
Amiga operating system was discussed.  This section presents specific
guidelines that all Amiga programmers must follow.  Some of these
guidelines are for advanced programmers or apply only to code written in
assembly language.

  * Check for [memory loss](libraries/d-errors-memory-loss.md).  Arrange your Workbench screen so that you

```c
    have a Shell available and can start your program without rearranging
    any windows.  In the Shell window type Avail flush several times (the
    flush option requires the [Release 2](libraries/1-operating-system-versions-about-release-2.md) version of the Avail command).
    Note the total amount of free memory.  Run your program (do not
    rearrange any windows other than those created by the program) and
    then exit.  At the Shell, type Avail flush several times again.
    Compare the total amount of free memory with the earlier figure.
    They should be the same.  Any difference indicates that your
    application is not freeing some memory it used or is not closing a
    disk-loaded library, device or font it opened.  Note that under
    Release 2, a small amount of memory loss is normal if your
    application is the first to use the audio or narrator device.
```
  * Use all of the program [debugging](libraries/d-troubleshooting-guide-general-debugging-techniques.md) and stress tools that are available

```c
    when writing and testing your code.  New debugging tools such as
    Enforcer, MungWall, and Scratch can help find uninitialized pointers,
    attempted use of freed memory and misuse of scratch registers or
    condition codes (even in programs that appear to work perfectly).
```
  * Always make sure you actually get any system resource that you ask

```c
    for.  This applies to memory, windows, screens, file handles,
    libraries, devices, ports, etc.  Where an error value or return is
    possible, ensure that there is a reasonable failure path.  Many
    poorly written programs will appear to be reliable, until some [error](libraries/d-troubleshooting-guide-errors.md)
    condition (such as memory full or a disk problem) causes the program
    to continue with an invalid or null pointer, or branch to untested
    error handling code.
```
  * Always clean up after yourself.  This applies for both normal program

```c
    exit and [program termination](libraries/21-exec-tasks-task-termination.md) due to error conditions. Anything that
    was opened must be closed, anything allocated must be deallocated.
    It is generally correct to do closes and deallocations in reverse
    order of the opens and allocations.  Be sure to check your
    development language manual and startup code; some items may be
    closed or deallocated automatically for you, especially in abort
    conditions.  If you write in the C language, make sure your code
    handles [Ctrl-C](libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md) properly.
```
  * Remember that memory, peripheral configurations, and ROMs differ

    between models and between individual systems.  Do not make
    assumptions about memory address ranges, storage device names, or the
    locations of system structures or code.  Never call ROM routines
    directly.  Beware of any example code you find that calls routines at
    addresses in the $F0 0000 - $FF FFFF range.  These are ROM routines
    and they will move with every OS release.  The only supported
    interface to system ROM code is through the library, device, and
    resource calls.
  * Never assume library bases or structures will exist at any particular

```c
    memory location.  The only [absolute address](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md) in the system is $0000
    0004, which contains a pointer to the Exec library base. Do not
    modify or depend on the format of private system structures. This
    includes the poking of [copper](libraries/27-introduction-role-of-the-copper-coprocessor.md) lists, memory lists, and library bases.
```
  * Never assume that programs can access hardware resources directly.

```c
    Most hardware is controlled by system software that will not respond
    well to interference from other programs.  Shared hardware requires
    programs to use the proper sharing protocols.  Use the defined
    interface; it is the best way to ensure that your software will
    continue to operate on future models of the Amiga.
```
  * Never access shared data structures directly without the proper

```c
    mutual exclusion ([locking](libraries/21-task-exclusion-task-semaphores.md)).  Remember that other tasks may be
    accessing the same structures.
```
  * The system does not monitor the size of a program's [stack](libraries/21-task-creation-task-stack.md).  (Your

```c
    compiler may have an [option](libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md) to do this for you.)  Take care that your
    program does not cause stack overflow and provide extra stack space
    for the possibility that some functions may use up additional stack
    space in future versions of the OS.
```
  * Never use a polling loop to test signal bits.  If your program waits

```c
    for external events like menu selection or keystrokes, do not bog
    down the [multitasking](libraries/1-programming-in-the-amiga-environment-multitasking.md) system by busy-waiting in a loop.  Instead, let
    your task go to sleep by [Wait()ing](libraries/22-the-signal-system-waiting-for-a-signal.md) on its signal bits.  For example:

        signals = (ULONG)Wait(  (1<<windowPtr->UserPort->mp_SigBit) |
                                    (1<<consoleMsgPortPtr->mp_SigBit)  );

    This turns the signal bit number for each port into a mask, then
    combines them as the argument for the Exec library [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) function.
    When your task wakes up, handle all of the messages at each port
    where the mp_SigBit is set.  There may be more than one message per
    port, or no messages at the port.  Make sure that you [ReplyMsg()](libraries/24-messages-replying.md) to
    all messages that are not replies themselves.  If you have no signal
    bits to Wait() on, use [Delay()](autodocs-2.0/dos-library-delay.md) or [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md) to provide a measured
    delay.
```
  * [Tasks (and processes)](libraries/17-introduction-to-exec-multitasking.md) execute in 680x0 user mode.  [Supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md) is

    reserved for interrupts, traps, and task dispatching.  Take extreme
    care if your code executes in supervisor mode.  Exceptions while in
    supervisor mode are deadly.
  * Most system functions require a particular execution environment.

```c
    All DOS functions and any functions that might call DOS (such as the
    opening of a disk-resident library, font, or device) can only be
    executed from a [process](libraries/17-introduction-to-exec-multitasking.md).  A task is not sufficient.  Most other ROM
    kernel functions may be executed from tasks.  Only a few may be
    executed from interrupts.
```
  * Never [disable interrupts](libraries/26-exec-interrupts-disabling-interrupts.md) or multitasking for long periods.  If you

```c
    use [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md) or [Disable()](libraries/21-task-exclusion-disabling-tasks.md), you should be aware that execution of any
    system function that performs the [Wait()](libraries/24-messages-waiting-for-a-message.md) function will temporarily
    suspend the Forbid() or Disable() state, and allow multitasking and
    interrupts to occur.  Such functions include almost all forms of DOS
    and device I/O, including common stdio functions like [printf()](autodocs-2.0/amiga-lib-printf.md).
```
  * Never tie up system resources unless it is absolutely necessary. For

    example, if your program does not require constant use of the
    printer, open the printer device only when you need it.  This will
    allow other tasks to use the printer while your program is running.
    You must provide a reasonable error response if a resource is not
    available when you need it.
  * All data for the [custom chips](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md) must reside in [Chip memory](libraries/1-the-custom-chips-two-kinds-of-memory.md) (type

```c
    [MEMF_CHIP](libraries/20-memory-functions-memory-attributes.md)).  This includes bitplanes, sound samples, trackdisk
    buffers, and images for sprites, bobs, pointers, and gadgets.  The
    [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) call takes a flag for specifying the type of memory. A
    program that specifies the wrong type of memory may appear to run
    correctly because many Amigas have only Chip memory.  (On all models
    of the Amiga, the first 512K of memory is Chip memory.  In later
    models, Chip memory may occupy up to the first one or two megabytes).

    However, once [expansion memory](libraries/1-the-custom-chips-two-kinds-of-memory.md) has been added to an Amiga (type
    [MEMF_FAST](libraries/20-memory-functions-memory-attributes.md)), any memory allocations will be made in the expansion
    memory area by default.  Hence, a program can run correctly on an
    unexpanded Amiga which has only [Chip memory](libraries/1-the-custom-chips-two-kinds-of-memory.md) while [crashing](libraries/d-errors-fails-only-on-machines-with-fast-ram.md) on an
    Amiga which has expanded memory.  A developer with only Chip memory
    may fail to notice that memory was incorrectly specified.

    Most compilers have [options](libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md) to mark specific data structures or
    object modules so that they will load into [Chip RAM](libraries/1-the-custom-chips-two-kinds-of-memory.md).  Some older
    compilers provide the Atom utility for marking object modules.  If
    this method is unacceptable, use the [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) call to dynamically
    allocate Chip memory, and copy your data there.

    When making allocations that do not require [Chip memory](libraries/1-the-custom-chips-two-kinds-of-memory.md), do not
    explicitly ask for [Fast memory](libraries/1-the-custom-chips-two-kinds-of-memory.md).  Instead ask for memory type
    [MEMF_PUBLIC](libraries/20-memory-functions-memory-attributes.md) or 0L as appropriate.  If Fast memory is available, you
    will get it.
```
  * Never use software delay loops!  Under the [multitasking](libraries/1-programming-in-the-amiga-environment-multitasking.md) operating

```c
    system, the time spent in a loop can be better used by other tasks.
    Even ignoring the effect it has on multitasking, timing loops are
    inaccurate and will wait different amounts of time depending on the
    specific model of Amiga computer.  The timer device provides
    precision timing for use under the multitasking system and it works
    the same on all models of the Amiga.  The AmigaDOS [Delay()](autodocs-2.0/dos-library-delay.md) function
    or the graphics library [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md) function provide a simple interface
    for longer delays.  The [8520 I/O chips](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md) provide timers for developers
    who are bypassing the operating system (see the Amiga Hardware
    Reference Manual for more information).
```
  * Always obey structure conventions!


```c
      · All non-byte fields must be word-aligned.  Longwords should be
        longword-aligned for performance.

      · All address pointers should be 32 bits (not 24 bits).  Never use
        the upper byte for data.

      · Fields that are not defined to contain particular initial values
        must be initialized to zero.  This includes pointer fields.

      · All reserved or unused fields must be initialized to zero for
        future compatibility.

      · Data structures to be accessed by the [custom chips](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md), public data
        structures (such as a task control block), and structures which
        must be longword aligned must not be allocated on a program's
        stack.

      · Dynamic allocation of structures with [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) provides
        longword aligned memory of a specified type with optional
        initialization to zero, which is useful in the allocation of
        structures.
```
 [For 68010/68020/68030/68040 Compatibility](libraries/1-general-development-guidelines-68010-020-030-040.md) 
 [Hardware Programming Guidelines](libraries/1-general-development-guidelines-hardware-programming.md) 
 [Additional Assembler Development Guidelines](libraries/1-general-guidelines-additional-assembler-development.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [Delay — dos.library](../autodocs/dos.library.md#delay)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
