/* Source: ADCD 2.1
 * Section: exec-library-allocmem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-allocmem.md
 */

    AllocMem(64,0L)         - Allocate the best available memory
    AllocMem(25,MEMF_CLEAR) - Allocate the best available memory, and
                              clear it before returning.
    AllocMem(128,MEMF_CHIP) - Allocate chip memory
    AllocMem(128,MEMF_CHIP|MEMF_CLEAR) - Allocate cleared chip memory
    AllocMem(821,MEMF_CHIP|MEMF_PUBLIC|MEMF_CLEAR) - Allocate cleared,
            public, chip memory.
