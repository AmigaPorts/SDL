# 1 / General Guidelines / Additional Assembler Development Guidelines


If you are writing in assembly language there are some extra rules to keep
in mind in addition to those listed above.

  * Never use the TAS instruction on the Amiga.  System DMA can conflict

    with this instruction's special indivisible read-modify-write cycle.
  * System functions must be called with [register](../Libraries_Manual_guide/node030A.html) A6 containing the

    library or device base.  Libraries and devices assume A6 is valid at
    the time of any function call.  Even if a particular function does
    not currently require its base register, you must provide it for
    compatibility with future system software releases.
  * Except as noted, system library functions use [registers](../Libraries_Manual_guide/node030C.html) D0, D1, A0,

    and A1 as scratch registers and you must consider their former
    contents to be lost after a system library call.  The contents of all
    other registers will be preserved.  System functions that provide a
    result will return the result in D0.
  * Never depend on processor condition codes after a system call. The

    caller must test the returned value before acting on a condition
    code.  This is usually done with a TST or MOVE instruction.
