---
title: Sample Enforcer Output
manual: amiga-mail
chapter: amiga-mail
section: sample-enforcer-output
functions: []
libraries: []
---

# Sample Enforcer Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here is a sample Enforcer hit which was caused by a program called
Lawbreaker which tried to read from location $14.

Program Counter (approximate)=  343F4A                    Fault address       =      14
User stack pointer           =  348734                    DOS process address =  339590
Data: DDDD0000 DDDD1100 DDDD2200 DDDD3300 DDDD4400 DDDD5500 DDDD6600 DDDD7700
Addr: AAAA0000 AAAA1100 AAAA2200 AAAA3300 AAAA4400 AAAA5500 AAAA6600 00002E28
Stck: 00210D70 00000FA0 00339F84 BBBBBBBB BBBBBBBB BBBBBBBB BBBBBBBB BBBBBBBB
READ-WORD  (---)(-)(-)    SR=0008   SSW=0161
Background CLI, "lawbreaker", Hunk #0, Offset $5A

Program Counter - Normally, this is the address of the instruction that
was executing when the Enforcer hit occurred.  For some types of
Enforcer hits, this is the address of the instruction that executed
after the hit.  Note that if a program passes a bad pointer or an
improperly initialized structure to a system ROM routine, it can cause
the ROM code to read or write to an illegal address.

Fault Address - This is the address where the illegal access occurred.
In this example, the illegal access occurred at address $14, and as
specified later in the debugging output, this access was a READ-WORD
access.  So the illegal memory access was an attempt to read a word (2
bytes) at address $14.  Low memory accesses are often caused by NULL
pointers to structures.  If, for example, a ROM routine references a
WORD-sized structure member at offset $20, and an application passes
the ROM routine a NULL pointer as a pointer to that structure, Enforcer
will report that the ROM routine tried to read a word at address $20.

User Stack Pointer - This is the value that was in register A7 when the
Enforcer hit occurred.  It points to the top of the stack for the task
that was running when the Enforcer hit occurred.

DOS Process Address - This points to the Task structure of the task
that was running when the Enforcer hit occurred.

Data/Addr (Register Dump) - This is the contents of registers D0-D7 and
A0-A7.  This information can help assembly programmers and programmers
who like to debug at a low level.  Notice that register A7, the stack
pointer, no longer contains the stack pointer for the task that caused
the Enforcer hit (A7 does not match the user stack pointer above).
Ignore the value in A7.

Stck (Stack Dump) - This is the eight long words at the top of the
offending program's stack.  For those who need to see more of the
stack, there is a special version of Enforcer called
Enforcer.megastack.  that shows the last 32 long words on the stack.

Access Type - This tells what kind of memory access the Enforcer hit
is.  In this example the access is a READ-WORD, which most likely is a
result of Lawbreaker accessing a word-sized structure member.  There
are two other read access types: READ-BYTE, which is generally a result
of a bad string pointer, and READ-LONG, which is normally a result of a
bad pointer or a bad pointer within a structure.  When an errant
program directly or indirectly writes over Enforcer-protected memory,
Enforcer reports a  WRITE-BYTE, WRITE-WORD, or WRITE-LONG type access.
When Enforcer issues an INSTRUCTION type memory access, the CPU tried
to load an instruction from an invalid address.  Some common causes for
this type of Enforcer hit are:

An errant program has overwritten a program's instructions,
An errant program has overwritten a subroutine return address
        that was on the stack,
The CPU tried to execute a library function using an invalid library base.

Notice that the errant program is not necessarily the program that
caused the Enforcer hit.

Interrupt/Forbid/Disable - The series of parentheses after the access
type indicate if the Enforcer hit occurred in an interrupt (and if so,
the interrupt level), Forbid, or Disable state:

(I-n)(-)(-)     The hit occurred in an n level interrupt.
(---)(F)(-)     The hit occurred while the Amiga was in a Forbid state.
(---)(-)(D)     The hit occurred while the Amiga was in a Disable state.

SR (Status Register) - The CPU's status register (see 680x0 manual for
more information).

SSW (Special Status Word) - The special status word for 68010 though
68040 CPUs (see 680x0 manual for more information).

Program Name - The program name is the name of the task or command that
was executing when the Enforcer hit occurred.

Hunk Number and Offset - If possible, Enforcer also provides a hunk
offset to where the program counter was if the hit occurred within the
program's own code instructions.  This will only work if the errant
program was started from a shell.

