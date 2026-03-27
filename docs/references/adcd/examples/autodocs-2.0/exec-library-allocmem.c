/* Source: ADCD 2.1
 * Section: exec-library-allocmem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-allocmem.md
 */

    byteSize - the size of the desired block in bytes.  (The operating
            system will automatically round this number to a multiple of
            the system memory chunk size)

    attributes -
        requirements

            If no flags are set, the system will return the best
            available memory block.  For expanded systems, the fast
            memory pool is searched first.

            MEMF_CHIP:      If the requested memory will be used by
                            the Amiga custom chips, this flag *must*
                            be set.

                            Only certain parts of memory are reachable
                            by the special chip sets' DMA circuitry.
                            Chip DMA includes screen memory, images that
                            are blitted, audio data, copper lists, sprites
                            and Pre-V36 trackdisk.device buffers.


            MEMF_FAST:      This is non-chip memory.  If no flag is set
                            MEMF_FAST is taken as the default.

                            DO NOT SPECIFY MEMF_FAST unless you know
                            exactly what you are doing!  If MEMF_FAST is
                            set, AllocMem() will fail on machines that
                            only have chip memory!  This flag may not
                            be set when MEMF_CHIP is set.


            MEMF_PUBLIC:    Memory that must not be mapped, swapped,
                            or otherwise made non-addressable. ALL
                            MEMORY THAT IS REFERENCED VIA INTERRUPTS
                            AND/OR BY OTHER TASKS MUST BE EITHER PUBLIC
                            OR LOCKED INTO MEMORY! This includes both
                            code and data.


            MEMF_LOCAL:     This is memory that will not go away
                            after the CPU RESET instruction.  Normally,
                            autoconfig memory boards become unavailable
                            after RESET while motherboard memory
                            may still be available.  This memory type
                            is now automatically set in V36.  Pre-V36
                            systems may not have this memory type
                            and AllocMem() will then fail.


            MEMF_24BITDMA:  This is memory that is within the address
                            range of 24-bit DMA devices.  (Zorro-II)
                            This is required if you run a Zorro-II
                            DMA device on a machine that has memory
                            beyond the 24-bit addressing limit of
                            Zorro-II.  This memory type
                            is now automatically set in V36.  Pre-V36
                            systems may not have this memory type
                            and AllocMem() will then fail.


        options

            MEMF_CLEAR:     The memory will be initialized to all
                            zeros.


            MEMF_REVERSE:   This allocates memory from the top of
                            the memory pool.  It searches the pools
                            in the same order, such that FAST memory
                            will be found first.  However, the
                            memory will be allocated from the highest
                            address available in the pool.  This
                            option is new as of V36.
