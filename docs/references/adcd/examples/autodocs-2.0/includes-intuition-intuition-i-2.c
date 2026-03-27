/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    APTR gg_NextGadget		; next gadget in the list

    WORD gg_LeftEdge		; "hit box" of gadget
    WORD gg_TopEdge		; "hit box" of gadget
    WORD gg_Width		; "hit box" of gadget
    WORD gg_Height		; "hit box" of gadget

    WORD gg_Flags 		; see below for list of defines

    WORD gg_Activation		; see below for list of defines

    WORD gg_GadgetType		; see below for defines

    ; appliprog can specify that the Gadget be rendered as either as Border
    ; or an Image.  This variable points to which (or equals NULL if there's
    ; nothing to be rendered about this Gadget)
    APTR gg_GadgetRender

    ; appliprog can specify "highlighted" imagery rather than algorithmic
    ; this can point to either Border or Image data
    APTR gg_SelectRender

    APTR gg_GadgetText		; text for this gadget;

    ; MutualExclude, never implemented, is now declared obsolete.
    ; There are published examples of implementing a more general
    ; and practical exclusion in your applications.
    ;
    ; Starting V36, this field is used to point to a hook
    ; for a custom gadget.
    ;
    ; Programs using this field for their own processing will
    ; continue to work, as long as they don't try the
    ; trick with custom gadgets
    LONG gg_MutualExclude 	; obsolete

    ; pointer to a structure of special data required by Proportional, String
    ; and Integer Gadgets
    APTR gg_SpecialInfo

    WORD gg_GadgetID	; user-definable ID field
    APTR  gg_UserData	; ptr to general purpose User data (ignored by Intuit)

    LABEL gg_SIZEOF
