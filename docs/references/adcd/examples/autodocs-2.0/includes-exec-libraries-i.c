/* Source: ADCD 2.1
 * Section: includes-exec-libraries-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-libraries-i.md
 */

    BITDEF  LIB,SUMMING,0  ; system is currently checksumming
    BITDEF  LIB,CHANGED,1  ; something has changed the library since last sum
    BITDEF  LIB,SUMUSED,2  ; indicates if the library allows checksumming
    BITDEF  LIB,DELEXP,3   ; delayed expunge flag (for use by library)
    BITDEF  LIB,EXP0CNT,4  ; special system expunge flag.
