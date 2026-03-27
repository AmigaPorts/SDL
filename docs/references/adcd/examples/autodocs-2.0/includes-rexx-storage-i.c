/* Source: ADCD 2.1
 * Section: includes-rexx-storage-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-rexx-storage-i.md
 */

         STRUCTURE NexxStr,0
         LONG     ns_Ivalue            ; integer value
         UWORD    ns_Length            ; length in bytes (excl null byte)
         UBYTE    ns_Flags             ; attribute flags
         UBYTE    ns_Hash              ; sum-of-characters hash code
         STRUCT   ns_Buff,8            ; buffer area for strings
         LABEL    NSMINSIZE            ; 16 bytes (minimum)
