---
title: 21 / Processor and Cache Control / DMA Cache Functions
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-dma-cache-functions
functions: [CachePostDMA, CachePreDMA]
libraries: [exec.library]
---

# 21 / Processor and Cache Control / DMA Cache Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [CachePreDMA()](autodocs-2.0/exec-library-cachepredma.md) and [CachePostDMA()](autodocs-2.0/exec-library-cachepostdma.md) functions allow you to flush the data
cache before and after Direct Memory Access. Typically only DMA device
drivers benefit from this. These functions take the processor type,
possible MMU and cache mode into account. When no cache is available they
end up doing nothing.  These functions can be replaced with ones suitable
for different cache hardware.  Refer to the ROM Kernel Reference Manual:
Includes and Autodocs for implementation specifics.

Since DMA device drivers read and write directly to memory, they are
effected by the [CopyBack](libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md) feature of the [MC68040](libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md) (explained below).  Using
DMA with CopyBack mode requires a cache flush.  If a DMA device needs to
read RAM via DMA, it must make sure that the data in the caches has been
written to memory first, by calling [CachePreDMA()](autodocs-2.0/exec-library-cachepredma.md).  In case of a write to
memory, the DMA device should first clear the caches with CachePreDMA(),
write the data and flush the caches again with [CachePostDMA()](autodocs-2.0/exec-library-cachepostdma.md).

---

## See Also

- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
