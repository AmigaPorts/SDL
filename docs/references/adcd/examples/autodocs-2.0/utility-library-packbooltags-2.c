/* Source: ADCD 2.1
 * Section: utility-library-packbooltags
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-packbooltags.md
 */

    /* define some nice user tag values ... */
    enum mytags { tag1 = TAG_USER+1, tag2, tag3, tag4, tag5 };

    /* this [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list defines the correspondence between Boolean tags
     * and bit-flag values.
     */
    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)       boolmap[] = {
        { tag1,  0x0001 },
        { tag2,  0x0002 },
        { tag3,  0x0004 },
        { tag4,  0x0008 },
        { TAG_DONE }
    };

    /* You are probably passed these by some client, and you want
     * to "collapse" the Boolean content into a single longword.
     */

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)       boolexample[] = {
        { tag1,  TRUE },
        { tag2,  FALSE },
        { tag5, Irrelevant },
        { tag3,  TRUE },
        { TAG_DONE }
    };

    /* Perhaps 'boolflags' already has a current value of 0x800002. */
    boolflags = PackBoolTags( boolflags, boolexample, boolmap );

    /* The resulting new value of 'boolflags' will be 0x80005. /*
