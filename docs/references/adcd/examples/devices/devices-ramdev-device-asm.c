/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

     DC.W    RTC_MATCHWORD	; UWORD RT_MATCHWORD (Magic cookie)
     DC.L    initDDescrip	; APTR	RT_MATCHTAG  (Back pointer)
     DC.L    EndCode		; APTR	RT_ENDSKIP   (To end of this hunk)
     DC.B    RTF_AUTOINIT	; UBYTE RT_FLAGS     (magic-see "Init:")
     DC.B    VERSION		; UBYTE RT_VERSION
     DC.B    NT_DEVICE		; UBYTE RT_TYPE      (must be correct)
     DC.B    MYPRI		; BYTE	RT_PRI
     DC.L    myName		; APTR	RT_NAME      (exec name)
     DC.L    idString		; APTR	RT_IDSTRING  (text string)
     DC.L    Init		; APTR	RT_INIT
