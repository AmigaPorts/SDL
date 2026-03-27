/* Source: ADCD 2.1
 * Section: 1-general-development-guidelines-68010-020-030-040-2
 * Library: hardware
 * ADCD reference: hardware/1-general-development-guidelines-68010-020-030-040-2.md
 */

        CACRF_ClearI    EQU      $0008  ;Bit for clear instruction cache
                        ;
                        ;Supervisor mode only.	Use only if you have taken
                        ;over the machine.  Read and store the ExecBase
                        ;processor AttnFlags flags at boot time, call this
                        ;code only if the "68020 or better" bit was set.
                        ;
        ClearICache:    dc.w    $4E7A,$0002   ;MOVEC CACR,D0
                        tst.w   d0            ;movec does not affect CC's
                        bmi.s   cic_040       ;A 68040 with enabled cache!
                        ori.w   #CACRF_ClearI,d0
                        dc.w    $4E7B,$0002   ;MOVEC D0,CACR
                        bra.s   cic_exit
        cic_040:        dc.w    $f4b8         ;CPUSHA (IC)
        cic_exit:
