/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    APTR  rq_OlderRequest
    WORD rq_LeftEdge		; dimensions of the entire box
    WORD rq_TopEdge		; dimensions of the entire box
    WORD rq_Width		; dimensions of the entire box
    WORD rq_Height		; dimensions of the entire box

    WORD rq_RelLeft		; get POINTREL Pointer relativity offsets
    WORD rq_RelTop		; get POINTREL Pointer relativity offsets

    APTR  rq_ReqGadget     	; pointer to the first of a list of gadgets
    APTR  rq_ReqBorder		; the box's border
    APTR  rq_ReqText		; the box's text

    WORD  rq_Flags		; see definitions below

    UBYTE rq_BackFill		; pen number for back-plane fill before draws

    BYTE rq_KludgeFill00	; This is strictly for word-alignment

    APTR rq_ReqLayer		; layer in which requester rendered
    STRUCT rq_ReqPad1,32	; for backwards compatibility (reserved)

    ; If the BitMap plane pointers are non-zero, this tells the system
    ; that the image comes pre-drawn (if the appliprog wants to define
    ; its own box, in any shape or size it wants!); this is OK by
    ; Intuition as long as there's a good correspondence between the image
    ; and the specified Gadgets
    APTR  rq_ImageBMap		; points to the BitMap of PREDRAWN imagery

    APTR  rq_RWindow		; points back to requester's window
    APTR  rq_ReqImage		; new for V36: drawn if USEREQIMAGE set
    STRUCT rq_ReqPad2,32	; for backwards compatibility (reserved)

    LABEL rq_SIZEOF
