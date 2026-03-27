/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    WORD pi_Flags	; general purpose flag bits (see defines below)

    ; You initialize the Pot variables before the Gadget is added to
    ; the system.  Then you can look here for the current settings
    ; any time, even while User is playing with this Gadget.  To
    ; adjust these after the Gadget is added to the System, use
    ; ModifyProp(); The Pots are the actual proportional settings,
    ; where a value of zero means zero and a value of MAXPOT means
    ; that the Gadget is set to its maximum setting.
    WORD pi_HorizPot	; 16-bit FixedPoint horizontal quantity percentage;
    WORD pi_VertPot	; 16-bit FixedPoint vertical quantity percentage;

    ; the 16-bit FixedPoint Body variables describe what percentage
    ; of the entire body of stuff referred to by this Gadget is
    ; actually shown at one time.  This is used with the AUTOKNOB
    ; routines, to adjust the size of the AUTOKNOB according to how
    ; much of the data can be seen.  This is also used to decide how
    ; far to advance the Pots when User hits the Container of the Gadget.
    ; For instance, if you were controlling the display of a 5-line
    ; Window of text with this Gadget, and there was a total of 15
    ; lines that could be displayed, you would set the VertBody value to
    ;	 (MAXBODY / (TotalLines / DisplayLines)) = MAXBODY / 3.
    ; Therefore, the AUTOKNOB would fill 1/3 of the container, and if
    ; User hits the Cotainer outside of the knob, the pot would advance
    ; 1/3 (plus or minus) If there's no body to show, or the total
    ; amount of displayable info is less than the display area, set the
    ; Body variables to the MAX.  To adjust these after the Gadget is
    ; added to the System, use ModifyProp().
    WORD pi_HorizBody	; horizontal Body
    WORD pi_VertBody	; vertical Body

    ; these are the variables that Intuition sets and maintains
    WORD pi_CWidth	; Container width (with any relativity absoluted)
    WORD pi_CHeight	; Container height (with any relativity absoluted)
    WORD pi_HPotRes	; pot increments
    WORD pi_VPotRes	; pot increments
    WORD pi_LeftBorder	; Container borders
    WORD pi_TopBorder	; Container borders
    LABEL  pi_SIZEOF
