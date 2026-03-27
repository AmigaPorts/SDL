/* Source: ADCD 2.1
 * Section: 32-rom-based-and-autoboot-drivers-events-at-diag-time
 * Library: libraries
 * ADCD reference: libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md
 */

            dddd    ; Device node or structs/tables (patch names, vectors)
            bbbb    ; BootNode (patch ln_Name and bn_DeviceNode)
            pppp    ; MakeDosNode packet (patch dos and exec names)

            ssss    ; other name, ID, and library name strings
            ...
