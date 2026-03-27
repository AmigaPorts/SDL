# 6 Blitter Hardware / Zero Flag


A blitter zero flag is provided that can be tested to determine if the
logic operation selected has resulted in zero bits for all destination
bits, even if those destination bits are not written due to the D
 [DMA channel](../Hardware_Manual_guide/node011B.html)  being disabled.  This feature is often useful for
 [collision detection](../Hardware_Manual_guide/node015A.html) , by performing a logical "and" on two source images
to test for overlap. If the images do not overlap, the zero flag will stay
true.

The Zero flag is only valid after the blitter has completed its operation
and can be read from bit (13) DMAF_BLTNZERO of the  [DMACONR](../Hardware_Manual_guide/node0170.html)  register.

