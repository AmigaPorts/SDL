/* Source: ADCD 2.1
 * Section: intuition-library-nextobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-nextobject.md
 */

    /* here is the OM_DISPOSE case of some class's dispatcher */
    case OM_DISPOSE:
        /* dispose members  */
        object_state = mydata->md_CollectionList.lh_Head;
        while ( member_object = NextObject( &object_state ) )
        {
            DoMethod( member_object, OM_REMOVE ); /* remove from list */
            DM( member, msg );      /* and pass along dispose       */
        }
