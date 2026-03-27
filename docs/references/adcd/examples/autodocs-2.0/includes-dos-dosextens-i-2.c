/* Source: ADCD 2.1
 * Section: includes-dos-dosextens-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-dosextens-i.md
 */

    STRUCT	dol_DiskType,0		; 'DOS', etc (UNION)
    BPTR	dol_SegList		; already loaded code for new task

    BPTR	dol_GlobVec		; BCPL global vector

    BSTR	dol_Name		; bptr to bcpl name
    LABEL	DosList_SIZEOF
