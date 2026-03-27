# speedbar_gc/SetSpeedButtonNodeAttrsA




```c
    NAME
        SetSpeedButtonNodeAttrsA -- Set attributes of a SpeedBar node. (V40)

    SYNOPSIS
        VOID SetSpeedButtonNodeAttrs(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...)
        SetSpeedButtonNodeAttrs(node, firsttag, ...)

        VOID SetSpeedButtonNodeAttrsA(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)
        SetSpeedButtonNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a SpeedBar node.  Since the SpeedBar
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a SpeedBar gadget.  You must first detach the list
        with SPEEDBAR_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        SBNA_Left (WORD)
        Left spacing offset of button from left of bar, set automatically.

        SBNA_Top (WORD)
        Top spacing offset of button from top of bar, set automatically.

        SBNA_Width (WORD)
        Width Of Button - these are set automatically.

        SBNA_Height (WORD)
        Height Of Button - these are set automatically.

        SBNA_Image (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *)
        Standard [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) or BOOPSI [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) to be displayed in this button.

        SBNA_SelImage (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *)
        Standard [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) or BOOPSI [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) to be displayed in this button
        when selected.

        SBNA_Spacing (WORD)
        Spacing between this button and the last button.

        SBNA_Highlight (WORD)
        Button selecting highlight mode, ant one of the following
        is supported:

                SBH_NONE        - Do not highlight.
                SBH_BACKFILL    - BackFill will FILLPEN
                SBH_RECESS      - Shift image right and down when selected.
                SBH_IMAGE       - Display alternate image (SBNA_SelImage)

        SBNA_Enabled (BOOL)
        Enabled (hidden/shown) state of a speed button.

        SBNA_Help (STRPTR)
        String Pointer to optional help text place in window titlebar
        when this speed button is active/selected.

        SBNA_UserData (APTR)
        User Data, use as desired.

        SBNA_Disabled (BOOL) (V41)
        Marks this button as disabled, it will render with a ghost pattern
        and will not allow it to be selected.

        SBNA_Toggle (BOOL) (V41)
        Designates the button as a boolean toggle button. Defaults FALSE.

        SBNA_Selected (BOOL) (V41)
        The current selection state of a Toggle/MX button. Defaults FALSE.

        SBNA_MXGroup (BOOL) (V41)
        Set the MXGroup a button belongs in. This setting implies the
        SBNA_Toggle setting as TRUE also. The default is ~0, or not
        in any MXGroup. Note, a single speedbar can contain several
        MX groupings and mixtures of toggles and normal selections!

    INPUTS
        node - [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) whose attributes you are changing.
        taglist - [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) list of attributes to change.

    SEE ALSO
        [GetSpeedButtonNodeAttrsA()](../Includes_and_Autodocs_3._guide/node056B.html)
```
