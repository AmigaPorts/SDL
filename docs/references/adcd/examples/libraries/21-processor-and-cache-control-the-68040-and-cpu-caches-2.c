/* Source: ADCD 2.1
 * Section: 21-processor-and-cache-control-the-68040-and-cpu-caches
 * Library: libraries
 * ADCD reference: libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md
 */

    ***********************************************************************
    * Check to see if we are running in V37 ROM or better.  If so, we want
    * to call CacheClearU() to make sure we are safe on future hardware
    * such as the 68040.  This section of code assumes that a6 points at
    * ExecBase.  a0/a1/d0/d1 are trashed in CacheClearU()
    *
            cmpi.w  #37,LIB_VERSION(a6)    ; Check if exec is >= V37
            bcs.s   TooOld                 ; If less than V37, too old...
            jsr     _LVOCacheClearU(a6)    ; Clear the cache...
    TooOld:                                ; Exit gracefully.
    ***********************************************************************
