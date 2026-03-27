/* Source: ADCD 2.1
 * Section: graphics-library-fontextent
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-fontextent.md
 */

    The [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90), not the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), is specified -- unlike
    [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html), effect of algorithmic enhancements is not
    included, nor does te_Width include any effect of
    rp_TxSpacing.  The returned te_Width will be negative only
    when FPF_REVPATH is set in the tf_Flags of the font -- the
    effect of left-moving characters is ignored for the width of
    a normal font, and the effect of right-moving characters is
    ignored if a REVPATH font.  These characters will, however,
    be reflected in the bounding extent.
