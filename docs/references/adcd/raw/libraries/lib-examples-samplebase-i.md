# lib_examples/samplebase.i


* samplebase.i -- definition of sample.library base

   IFND  SAMPLE_BASE_I
SAMPLE_BASE_I SET 1


   IFND  EXEC_TYPES_I
   INCLUDE  "exec/types.i"
   ENDC   ; EXEC_TYPES_I

   IFND  EXEC_LIBRARIES_I
   INCLUDE  "exec/libraries.i"
   ENDC   ; EXEC_LIBRARIES_I

;--------------------------
; library data structures
;--------------------------

;  Note that the library base begins with a library node

   STRUCTURE SampleBase,LIB_SIZE
   UBYTE   sb_Flags
   UBYTE   sb_pad
   ;We are now longword aligned
   ULONG   sb_SysLib
   ULONG   sb_DosLib
   ULONG   sb_SegList
   LABEL   SampleBase_SIZEOF


SAMPLENAME   MACRO

      DC.B   'sample.library',0
      ENDM
   ENDC  ;SAMPLE_BASE_I

