# 8 / Floppy Disk Controller / Disk Interrupts


The disk controller can issue three kinds of interrupts:

   *   [DSKSYNC](../Hardware_Manual_guide/node016D.html)  (level 5,  [INTREQ](../Hardware_Manual_guide/node0037.html)  bit 12) -- input stream matches the
                                             DSKSYNC register.
   *   [DSKBLK](../Hardware_Manual_guide/node016D.html)  (level 1,  [INTREQ](../Hardware_Manual_guide/node0037.html)  bit 1) -- disk DMA has completed.
   *   [INDEX](../Hardware_Manual_guide/node014A.html#line62)  (level 6, 8520 Flag pin) -- index sensor triggered.

Interrupts are explained further in the section
 [Length, Direction, DMA Enable](../Hardware_Manual_guide/node0192.html) .

See Chapter 7, "System Control Hardware," for more information about
  [interrupts](../Hardware_Manual_guide/node0160.html) .

See  [Appendix F](../Hardware_Manual_guide/node012E.html)  for more information on the 8520.

