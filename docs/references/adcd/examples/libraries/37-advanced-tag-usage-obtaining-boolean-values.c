/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-obtaining-boolean-values
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-obtaining-boolean-values.md
 */

    /* These are the attributes that we understand, with the
     * corresponding flag value. */
    struct TagItem activation_bools[] =
    {
        /* Attribute            Flags */
        {GA_ENDGADGET,          ENDGADGET},
        {GA_IMMEDIATE,          GADGIMMEDIATE},
        {GA_RELVERIFY,          RELVERIFY},
        {GA_FOLLOWMOUSE,        FOLLOWMOUSE},
        {GA_RIGHTBORDER,        RIGHTBORDER},
        {GA_LEFTBORDER,         LEFTBORDER},
        {GA_TOPBORDER,          TOPBORDER},
        {GA_BOTTOMBORDER,       BOTTOMBORDER},
        {GA_TOGGLESELECT,       TOGGLESELECT},

        /* Terminate the array */
        {TAG_END}
    };

    /* Set the activation field, based on the attributes passed */
    g->Activation = PackBoolTags(g->Activation, tags, activation_bools);
