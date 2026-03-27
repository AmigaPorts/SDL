/* Source: ADCD 2.1
 * Section: drawlist-ic-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/drawlist-ic-datasheet.md
 */

    NAME
        drawlist_ic -- create drawlist BOOPSI objects

    SUPERCLASS
        imageclass

    REQUIRES
        None.

    DESCRIPTION
        This image class can create custom scaled glyphs via a
        "drawlist". The drawlist is an array of drawing directives
        such as lines, areafills, etc. All coordinates are based
        on an imaginary grid of a user specified size, then
        [ScalerDiv()](../Includes_and_Autodocs_3._guide/node0319.html) is used to scale these coordinates to the desired
        image size to be rendered. This is a lower level class utilized
        by glyph.image, if you create some interesting drawlist, please
        consider passing them on to others, or to us for inclusion.

    METHODS
        OM_NEW -- Create the drawlist image.  Passed to superclass, then
            OM_SET.

        OM_GET -- Get object attributes.  Passed to superclass first.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_UPDATE -- Set object notification attributes.  Passed to
            superclass first.

        IM_DRAW -- Renders the images.  Overrides the superclass.
        IM_DRAWFRAME -- Renders the images scaled to thee frame size.
            Overrides the superclass.

        All other methods are passed to the superclass, including OM_DISPOSE.

    ATTRIBUTES
        DRAWLIST_Directives (struct [DrawList](../Includes_and_Autodocs_3._guide/node0603.html#line67) *)
            An array of drawlist directive structures are passed
            to specify the vectors and render operation. The last
            entry must be DLST_END!

            struct [DrawList](../Includes_and_Autodocs_3._guide/node0603.html#line67)
            {
                WORD dl_Directive;
                WORD dl_X1, dl_Y1;
                WORD dl_X2, dl_Y2;
                WORD dl_Pen;
            };


            The following directives are supported;

            DLST_END      - End the directive list.
            DLST_LINE     - Render a line from dl_x1,dl_y1 to dl_x2,dl_y2
            DLST_RECT     - [Cause](../Includes_and_Autodocs_3._guide/node01F4.html) a [RectFill()](../Includes_and_Autodocs_3._guide/node0313.html) of size dl_x1,dl_y1,dl_x2,dl_y2
            DLST_LINEPAT  - Set the line pattern to value held in dl_Pen
            DLST_FILLPAT  - Set the fill pattern to value held in dl_Pen
            DLST_LINESIZE - Set the drawlist line thickness via dl_Pen
            DLST_AMOVE    - [AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) using dl_x1,dl_y1
            DLST_ADRAW    - [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) using dl_x1,dl_y1
            DLST_AFILL    - [Cause](../Includes_and_Autodocs_3._guide/node01F4.html) the AreaFill() operation
            DLST_FILL     - [Flood()](../Includes_and_Autodocs_3._guide/node02D4.html) an area.
            DLST_ELLIPSE  - [AreaEllipse()](../Includes_and_Autodocs_3._guide/node02A9.html)
            DLST_CIRCLE   - [AreaCircle()](../Includes_and_Autodocs_3._guide/node02A7.html)
            DLST_BEVELBOX - currently unsupported (alpha function removed)
            DLST_ARC      - currently unsupported
            DLST_START    - currently unsupported
            DLST_BOUNDS   - currently unsupported

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        DRAWLIST_RefHeight (WORD)
            Reference height of the drawlist imagary grid.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        DRAWLIST_RefWidth (WORD)
            Reference width of the drawlist imagary grid.

            Applicability is (OM_NEW, OM_SET, OM_GET)
