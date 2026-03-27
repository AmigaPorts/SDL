/* Source: ADCD 2.1
 * Section: label-ic-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/label-ic-datasheet.md
 */

    NAME
        label_ic -- [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) class for creating idenification labels

    SUPERCLASS
        imageclass

    REQUIRES
        None.

    DESCRIPTION
        Label is an image class suitable for creating identification labels,
        such as might appear next to or inside a gadget, or as some kind of
        title in a window.  A label consists of text and graphics mixed in
        a variety of ways.

    METHODS
        OM_NEW--Create the label image.  Passed to superclass, then OM_SET.

        OM_GET--Get object attributes.  Passed to superclass first.

        OM_SET--Set object attributes.  Passed to superclass first.

        OM_UPDATE--Set object notification attributes.  Passed to superclass
            first.

        IM_DRAW--Renders the images.  Overrides the superclass.

        All other methods are passed to the superclass, including OM_DISPOSE.

    ATTRIBUTES
        IA_Font (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *)
            Font to use for any label text.  Only affects text passed AFTER
            this tag is given.  If you did not use the LABEL_DrawInfo tag
            then you MUST use this tag to specify what font to use.

            Applicability is (OM_NEW)

        IA_FGPen (LONG)
            Foreground pen for any label text.  Only affects text passed AFTER
            this tag is given.

            Defaults to pen 1.

            Applicability is (OM_NEW)

        IA_BGPen (LONG)
            Background pen for any label text.  Only affects text passed AFTER
            this tag is given.

            Defaults to pen 0.

            Applicability is (OM_NEW)

        IA_Mode (UBYTE)
            [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) mode for rendering text.  Only affects text passed AFTER
            this tag is given.

            Defaults to JAM1.

            Applicability is (OM_NEW)

        LABEL_DrawInfo (struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) *)
            Contains important pen information.  This is used to get default
            font information.  If you do not use IA_Font to specify fonts
            then you MUST pass the screen [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) before you give the
            LABEL_Text tag.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET)

        LABEL_Text (STRPTR)
            A text string to render.  A 'n' in the string will cause the
            text position to move to a new line.  The first underscore ('_')
            in the string will be used to underline the proceeding character
            in the string.  Any number of text strings and images can be
            provided in a label, mixed at will.

            Applicability is (OM_NEW)

        LABEL_SoftStyle (UBYTE)
            SoftStyle for any label text.  Only affects text passed AFTER
            this tag is given.

            Defaults to FS_NORMAL.

            Applicability is (OM_NEW)


        LABEL_Image (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *)
            An image to render.  Any number of text strings and images can
            be provided in a label, mixed at will.

            Applicability is (OM_NEW)

        LABEL_DisposeImage (BOOL)
            Indicates that you want the NEXT image passed via LABEL_Image
            to be disposed automatically when the label instance is
            disposed.  This implies that the next image passed MUST be a
            BOOPSI image (since static images cannot be disposed).  This
            will only affect the next image passed, therefore you must
            specify this tag for every image you wish to have disposed of
            automatically.

            Defaults to FALSE.

            Applicability is (OM_NEW)

        LABEL_Mapping (UWORD *)
            Pen mapping array, affects the NEXT image passed via
            LABEL_Image ONLY.  You should pass a mapping for non-BOOPSI
            images only, it is expected that BOOPSI images would be
            correctly pen-mapped.

            The mapping array must have at least as many elements as the
            image has bit planes (i.e. 1 << Image.Depth).  For element
            i in the array you put in the new pen that you want pen i in
            your image to be mapped to.  For a typical 4-colour image, you
            might use the following mapping:

                [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) mapping[4];
                struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) *drinfo;

                /* Before hand we'll have obtained the screen's [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65).
                 */
                mapping[0] = drinfo->dri_Pens[BACKGROUNDPEN];
                mapping[1] = drinfo->dri_Pens[SHADOWPEN];
                mapping[2] = drinfo->dri_Pens[SHINEPEN];
                mapping[3] = drinfo->dri_Pens[FILLPEN];

            Applicability is (OM_NEW)

        LABEL_Justification (UWORD)
            Justification for entire label.  This can be either LJ_LEFT
            (the default), LJ_CENTRE or LJ_RIGHT.

            Applicability is (OM_NEW, OM_GET)

        LABEL_Key (UWORD)
            For getting the key that was underscored in text passed with
            LABEL_Text.

            Applicability is (OM_GET)

    SEE ALSO
        [intuition.library/GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html)
