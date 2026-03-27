/* Source: ADCD 2.1
 * Section: 1-general-development-guidelines-68010-020-030-040
 * Library: libraries
 * ADCD reference: libraries/1-general-development-guidelines-68010-020-030-040.md
 */

    These caches store recently used instructions, but do not monitor
    writes.  After modifying or directly loading instructions, the cache
    must be flushed.  See the Exec library [CacheClearU()](../Includes_and_Autodocs_2._guide/node0339.html) Autodoc for more
    details.  If your code takes over the machine, flushing the cache
    will be trickier.  You can account for the current processors, and
    hope the same techniques will work in the future:

        CACRF_ClearI  EQU     $0008     ;Bit for clear instruction cache
        ;
        ;Supervisor mode only. Use this only if you have taken over
        ;the machine.  Read and store the ExecBase processor AttnFlags
        ;flags at boot time, call this code only if the "68020 or
        ; better" bit was set.
        ;
        ClearICache:  dc.w    $4E7A,$0002  ;MOVEC CACR,D0
                      tst.w   d0           ;movec does not affect CC's
                      bmi.s   cic_040      ;A 68040 with enabled cache!
                      ori.w   #CACRF_ClearI,d0
                      dc.w    $4E7B,$0002  ;MOVEC D0,CACR
                      bra.s   cic_exit
        cic_040:      dc.w    $f4b8        ;CPUSHA (IC)
        cic_exit:
