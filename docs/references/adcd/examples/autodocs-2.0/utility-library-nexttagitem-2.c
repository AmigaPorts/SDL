/* Source: ADCD 2.1
 * Section: utility-library-nexttagitem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-nexttagitem.md
 */

    Iterate( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tags );
    {
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tstate;
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tag;

            tstate = tags;
            while ( tag = NextTagItem( &tstate ) )
            {
                    switch ( tag->ti_Tag )
                    {
                    case TAG1:
                        ...
                        break;
                    case TAG2:
                        ...
                        break;
                    ...
                    }
            }
    }
