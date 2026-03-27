/* Source: ADCD 2.1
 * Section: includes-exec-tasks-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-tasks-i.md
 */

    UBYTE   TC_FLAGS
    UBYTE   TC_STATE
    BYTE    TC_IDNESTCNT	    ; intr disabled nesting
    BYTE    TC_TDNESTCNT	    ; task disabled nesting
    ULONG   TC_SIGALLOC	    ; sigs allocated
    ULONG   TC_SIGWAIT		    ; sigs we are waiting for
    ULONG   TC_SIGRECVD	    ; sigs we have received
    ULONG   TC_SIGEXCEPT	    ; sigs we take as exceptions
    ;* Pointer to an extended task structure.  This structure is allocated
    ;* by V36 Exec if the proper flags in tc_ETaskFlags are set.  This
    ;* field was formerly defined as:
    ;*		UWORD	TC_TRAPALLOC	    ; traps allocated
    ;*		UWORD	TC_TRAPABLE	    ; traps enabled
    ;* Please see the Exec AllocTrap() and FreeTrap() calls.
    ;*
    APTR    tc_ETask		    ; pointer to extended task structure
    APTR    TC_EXCEPTDATA	    ; data for except proc
    APTR    TC_EXCEPTCODE	    ; exception procedure
    APTR    TC_TRAPDATA	    ; data for proc trap proc
    APTR    TC_TRAPCODE	    ; proc trap procedure
    APTR    TC_SPREG		    ; stack pointer
    APTR    TC_SPLOWER		    ; stack lower bound
    APTR    TC_SPUPPER		    ; stack upper bound + 2
    FPTR    TC_SWITCH		    ; task losing CPU (function pointer)
    FPTR    TC_LAUNCH		    ; task getting CPU (function pointer)
    STRUCT  TC_MEMENTRY,LH_SIZE     ; Allocated memory list.  Freed by RemTask()
    APTR    TC_Userdata		    ; For use by the task; no restrictions!
    LABEL   TC_SIZE
