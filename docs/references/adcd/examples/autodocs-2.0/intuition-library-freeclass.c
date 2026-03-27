/* Source: ADCD 2.1
 * Section: intuition-library-freeclass
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-freeclass.md
 */

    Freeing a private class with dynamically allocated user data:

    freeMyClass( cl )
    struct IClass   *cl;
    {
        struct MyPerClassData       *mpcd;

        mpcd = (struct MyPerClassData *) cl->cl_UserData;
        if ( FreeClass( cl ) )
        {
            FreeMem( mpcd, sizeof mpcd );
            return ( TRUE );
        }
        else
        {
            return ( FALSE );
        }
    }
