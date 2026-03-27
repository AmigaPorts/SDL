# D / Errors / Fails only on 68020/30


The following programming practices can cause this problem: using the
upper bytes of addresses as flags; doing signed math on addresses;
self-modifying code; using the MOVE SR assembler instruction (use Exec
[GetCC()](../Libraries_Manual_guide/node02CC.html) instead); software delay loops; assumptions about the order in
which asynchronous tasks will finish.  The following differences in
68020/30 can cause problems: data and/or instruction caches must be
flushed if data or code is changed by DMA or other non-processor
modification; different exception stack frame; interrupt autovectors may
be moved by VBR; 68020/30 CLR instruction does a single write access
unlike the 68000 CLR instruction which does a separate read and write
access (this might affect a read-triggered register in I/O space--use MOVE
instead).

