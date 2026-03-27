/* Source: ADCD 2.1
 * Section: utility-library-packbooltags
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-packbooltags.md
 */

    initialFlags    - a starting set of bit-flags which will be changed
                      by the processing of TRUE and FALSE Boolean tags
                      in tagList.
    tagList         - a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list which may contain several TagItems
                      defined to be "Boolean" by their presence in
                      boolMap.  The logical value of ti_Data determines
                      whether a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) causes the bit-flag value related
                      by boolMap to set or cleared in the returned flag
                      longword.
    boolMap         - a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list defining the Boolean Tags to be
                      recognized, and the bit (or bits) in the returned
                      longword that are to be set or cleared when a
                      Boolean Tag is found to be TRUE or FALSE in
                      tagList.
