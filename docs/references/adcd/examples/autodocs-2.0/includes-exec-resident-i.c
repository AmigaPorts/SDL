/* Source: ADCD 2.1
 * Section: includes-exec-resident-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-resident-i.md
 */

    UWORD RT_MATCHWORD			; word to match on (ILLEGAL)
    APTR  RT_MATCHTAG			; pointer to the above (RT_MATCHWORD)
    APTR  RT_ENDSKIP			; address to continue scan
    UBYTE RT_FLAGS			; various tag flags
    UBYTE RT_VERSION			; release version number
    UBYTE RT_TYPE			; type of module (NT_XXXXXX)
    BYTE  RT_PRI			; initialization priority
    APTR  RT_NAME			; pointer to node name
    APTR  RT_IDSTRING			; pointer to identification string
    APTR  RT_INIT			; pointer to init code
    LABEL RT_SIZE
