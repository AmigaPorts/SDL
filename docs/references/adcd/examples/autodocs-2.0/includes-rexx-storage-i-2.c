/* Source: ADCD 2.1
 * Section: includes-rexx-storage-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-rexx-storage-i.md
 */

         STRUCTURE RexxMsg,MN_SIZE
         APTR     rm_TaskBlock         ; pointer to RexxTask structure
         APTR     rm_LibBase           ; library pointer
         LONG     rm_Action            ; command (action) code
         LONG     rm_Result1           ; return code
         LONG     rm_Result2           ; secondary result
         STRUCT   rm_Args,16*4         ; argument block (ARG0-ARG15)
         APTR     rm_PassPort          ; forwarding port
         APTR     rm_CommAddr          ; host address (port name)
         APTR     rm_FileExt           ; file extension
         LONG     rm_Stdin             ; input stream
         LONG     rm_Stdout            ; output stream
         LONG     rm_avail             ; future expansion
         LABEL    RMSIZEOF             ; size: 128 bytes
