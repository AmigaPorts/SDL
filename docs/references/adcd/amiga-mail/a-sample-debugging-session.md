---
title: A Sample Debugging Session
manual: amiga-mail
chapter: amiga-mail
section: a-sample-debugging-session
functions: [FindName, OpenFont]
libraries: [exec.library, graphics.library]
---

# A Sample Debugging Session

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following is an example of debugging an Enforcer hit that occurred
using a test program called ownertest.  This hit was generated on an
A2500 with a 2.04 ROM image loaded using ZKick:

Program Counter (approximate)=  201946          Fault address       =       0
User stack pointer           =  566110          DOS process address =  38E888
Data: 00282D90 00000000 000003ED 0038FD8C 00000001 00000001 000E203B 00000001
Addr: 00225469 00000001 00282DE0 00448A3A 004487C0 004487CC 00001420 00002E28
Stck: 00448A3A 00223BA2 00280810 000003ED 0038FD8C 00000001 00000001 000E203B
READ-BYTE  (---)(F)(-)    SR=0010   SSW=0751
Background CLI, "ownertest"

The Program Counter is at $201946.  On a machine with the Kickstart in
ROM, the ROM addresses range from $F80000 to $FFFFFF under 2.0 or
greater and from $FC0000 to $FFFFFF under 1.3.  On a softkicked A3000,
the addresses are in the same range as real ROM addresses.  On a
softkicked A2500, $201946 is a ROM address (in this case, the ROM
ranges from $200000 to $27FFFF).  The first thing to do is figure out
in which ROM module the Enforcer hit occurred.  The debugging tool
owner , by Michael Sinz, will figure that out:


```c
    1.Ram Disk:> owner 0x201946

    Address  - Owner
    --------   -----
    00201946 - in resident module: exec 37.132 (23.5.91)
```
Note that Owner looks at the ROM addresses of the Amiga on which it is
executing, so you must run owner on the machine that generated the
Enforcer hit.

Next, use the debugging tool lvo to figure out what function entry in
the Exec ROM module is closest to that ROM address.  Like owner, lvo
also looks at local machine's ROM addresses, so you have to run owner
on the machine that generated the Enforcer hit.  Note that lvo requires
the FD files to be in an ``FD:'' assign directory.  Pass the address
and the module name (from owner) to lvo.


```c
    1.Ram Disk:> lvo exec romaddress=0x201946

    Closest to $201946 without going over:
    exec.library LVO $feec -276 FindName() jumps to $20192a on this system
```
Hmmm.  A lot of functions use FindName() on Exec lists, so, in this
case, the Program Counter does not pinpoint the problem.  However, it
does hint that FindName() probably received a bad string pointer.  The
``READ-BYTE'' attribute of the Enforcer hit is an extra clue that the
Ownertest program has a problem with a string pointer, since the most
common READ-BYTE actions are on strings.

Let's check the Enforcer stack dump and see if there are any other ROM
addresses there which might have called FindName():


    Stck: 00448A3A 00223BA2 00280810 000003ED 0038FD8C 00000001 00000001
          000E203B
The address closest to the top of the stack that looks like a ROM
address on this particular system is 0x00223BA2.  Let's see what ROM
module contains this address:


```c
    1.Ram Disk:> owner 0x223BA2

    Address  - Owner
    --------   -----
    00223BA2 - in resident module: graphics 37.35 (23.5.91)
```
Let's see what function in the Graphics library is closest to this ROM
address:


```c
    1.Ram Disk:> lvo graphics 0x223BA2

    Closest to $223ba2 without going over:
    graphics.library  LVO $ffb8 -72  OpenFont() jumps to $223b84 on this
    system
```
It looks like the ownertest program has a problem with a font name that
was not properly initialized.

---

## See Also

- [FindName — exec.library](../autodocs/exec.library.md#findname)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
