# 21 / Processor and Cache Control / DMA Cache Functions


The [CachePreDMA()](../Includes_and_Autodocs_2._guide/node033C.html) and [CachePostDMA()](../Includes_and_Autodocs_2._guide/node033B.html) functions allow you to flush the data
cache before and after Direct Memory Access. Typically only DMA device
drivers benefit from this. These functions take the processor type,
possible MMU and cache mode into account. When no cache is available they
end up doing nothing.  These functions can be replaced with ones suitable
for different cache hardware.  Refer to the ROM Kernel Reference Manual:
Includes and Autodocs for implementation specifics.

Since DMA device drivers read and write directly to memory, they are
effected by the [CopyBack](../Libraries_Manual_guide/node02CF.html#line10) feature of the [MC68040](../Libraries_Manual_guide/node02CF.html) (explained below).  Using
DMA with CopyBack mode requires a cache flush.  If a DMA device needs to
read RAM via DMA, it must make sure that the data in the caches has been
written to memory first, by calling [CachePreDMA()](../Includes_and_Autodocs_2._guide/node033C.html).  In case of a write to
memory, the DMA device should first clear the caches with CachePreDMA(),
write the data and flush the caches again with [CachePostDMA()](../Includes_and_Autodocs_2._guide/node033B.html).

