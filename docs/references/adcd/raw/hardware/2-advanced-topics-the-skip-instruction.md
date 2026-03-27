# 2 / Advanced Topics / The SKIP Instruction


The SKIP instruction causes the Copper to skip the next instruction if the
video beam counters are equal to or greater than the value given in the
instruction.

The contents of the SKIP instruction's words are shown below. They are
identical to the  [WAIT](../Hardware_Manual_guide/node004B.html)  instruction, except that bit 0 of the second
instruction word is a 1 to identify this as a SKIP instruction.


```c
          FIRST SKIP INSTRUCTION WORD (IR1)
          ---------------------------------
          Bit 0           Always set to 1.

          Bits 15 - 8      [Vertical position](../Hardware_Manual_guide/node004D.html)  (called VP).

          Bits 7 - 1       [Horizontal position](../Hardware_Manual_guide/node004C.html)  (called HP).

                          Skip if the beam counter is equal to or
                          greater than these combined bits
                          (bits 15 through 1).


          SECOND SKIP INSTRUCTION WORD (IR2)
          ----------------------------------
          Bit 0           Always set to 1.

          Bit 15          The  [blitter-finished-disable bit](../Hardware_Manual_guide/node005D.html) .
                          (See "Using the Copper with the Blitter"
```
			  below.)



```c
          Bits 14 - 8     Vertical position compare enable bits
                          (called VE).

          Bits 7 - 1      Horizontal position compare enable bits
                          (called HE).
```
The notes about  [horizontal](../Hardware_Manual_guide/node004C.html)  and  [vertical beam position](../Hardware_Manual_guide/node004D.html)  found in the
discussion of the  [WAIT](../Hardware_Manual_guide/node004B.html)  instruction apply also to the SKIP instruction.

The following example SKIP instruction skips the instruction following it
if VP ( [vertical beam position](../Hardware_Manual_guide/node004D.html) ) is greater than or equal to 100 ($64).


```c
        DC.W    $6401,$FF01     ;If VP >= 100,
                                ;  skip next instruction (ignore HP)
```
