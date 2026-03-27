/* Source: ADCD 2.1
 * Section: include-datatypes-datatypes-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-datatypes-datatypes-h.md
 */

    STRPTR	 dth_Name;				/* Descriptive name of the data type */
    STRPTR	 dth_BaseName;				/* Base name of the data type */
    STRPTR	 dth_Pattern;				/* Match pattern for file name. */
    WORD	*dth_Mask;				/* Comparision mask */
    ULONG	 dth_GroupID;				/* Group that the DataType is in */
    ULONG	 dth_ID;				/* ID for DataType (same as IFF FORM type) */
    WORD	 dth_MaskLen;				/* Length of comparision mask */
    WORD	 dth_Pad;				/* Unused at present (must be 0) */
    UWORD	 dth_Flags;				/* Flags */
    UWORD	 dth_Priority;				/* Priority */
