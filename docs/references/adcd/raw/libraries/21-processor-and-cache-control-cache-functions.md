# 21 / Processor and Cache Control / Cache Functions


As of the MC68020 all processors have an instruction cache, 256 bytes on
the MC68020 and MC68030 and 4 KBytes on a [MC68040](../Libraries_Manual_guide/node02CF.html).  The MC68030 and
MC68040 have data caches as well, 256 bytes and 4 KBytes respectively. All
the processors load instructions ahead of the program counter (PC), albeit
it that the MC68000 and MC68010 only prefetch one and two words
respectively. This means the CPU loads instructions ahead of the current
program counter.  For this reason self-modifying code is strongly
discouraged.  If your code modifies or decrypts itself just ahead of the
program counter, the pre-fetched instructions may not match the modified
instructions.  If self-modifying code must be used, flushing the cache is
the safest way to prevent this.

