# 3 / Color Selection / Color Selection in Extra Half Brite (EHB) Mode


The Amiga has a special mode called Extra Half Brite or EHB mode which
doubles the maximum number of colors that can be displayed at one time. To
use EHB mode, you must set up six bitplanes.  Then set  [BPU](../Hardware_Manual_guide/node0068.html#line4) =6 (bits 12,
13 and 14) in the  [BPLCON0](../Hardware_Manual_guide/node0092.html)  register. Set  [HOMOD](../Hardware_Manual_guide/node008F.html#line51) =0 (bit 11) and  [DBLPF](../Hardware_Manual_guide/node007C.html) =0
(bit 10) in  [BPLCON0](../Hardware_Manual_guide/node0092.html) .  In this mode, the information in bitplane 6
controls an intensity reduction in the other 5 bitplanes. The color
register output selected by the first five bitplanes is shifted to
half-intensity by the sixth bitplane. This allows 64 colors to be
displayed at one time instead of the usual 32.

   ECS playfield registers.
   -----------------------
   For  [information](../Hardware_Manual_guide/node00A1.html)  concerning the playfield hardware and the Enhanced
   Chip Set, see Appendix C.

