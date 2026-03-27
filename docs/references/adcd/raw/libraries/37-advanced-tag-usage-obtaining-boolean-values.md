# 37 / / Advanced Tag Usage / Obtaining Boolean Values


Often times data is best represented as simple boolean (TRUE or FALSE)
values.  The [PackBoolTags()](../Includes_and_Autodocs_2._guide/node03DB.html) function provides an easy method for
converting a tag list to bit fields.


```c
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
```
