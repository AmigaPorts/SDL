/* Source: ADCD 2.1
 * Section: cachecontrol
 * Library: amiga-mail
 * ADCD reference: amiga-mail/cachecontrol.md
 */

    As a side effect, this function clears all caches.

    Selected bit definitions for Cache manipulation calls from
    <exec/execbase.i>

    BITDEF  CACR,EnableI,0          ;Enable instruction cache
    BITDEF  CACR,FreezeI,1          ;Freeze instruction cache
    BITDEF  CACR,ClearI,3           ;Clear instruction cache
    BITDEF  CACR,IBE,4              ;Instruction burst enable
    BITDEF  CACR,EnableD,8          ;68030 Enable data cache
    BITDEF  CACR,FreezeD,9          ;68030 Freeze data cache
    BITDEF  CACR,ClearD,11          ;68030 Clear data cache
    BITDEF  CACR,DBE,12             ;68030 Data burst enable
    BITDEF  CACR,WriteAllocate,13   ;68030 Write-Allocate mode (must
                                    ;always be set)
    BITDEF  CACR,EnableE,30
