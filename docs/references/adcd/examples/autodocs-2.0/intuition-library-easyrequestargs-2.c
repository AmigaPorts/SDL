/* Source: ADCD 2.1
 * Section: intuition-library-easyrequestargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-easyrequestargs.md
 */

    /* varargs interface works for most C compilers */
    EasyRequest( w, es, ip, arg1 )
    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797)   *w;
    struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) *es;
    ULONG             *ip;
    int               arg1;
    {
        return ( EasyRequestArgs( w, es, ip, &arg1 ) );
    }

    /*********************************************/

    /* typical use */
    struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) volumeES = {
        sizeof (struct EasyStruct),
        0,
        "Volume Request",
        "Please insert volume %s in any drive.",
        "Retry|Cancel",
    };
    #define CANCEL  (0)

    Volume  *
    getVolume( volname )
    UBYTE   *volname;
    {
        Volume      *vptr;
        Volume      *findVolume();
        UWORD       reply;
        ULONG       iflags;

        iflags = IDCMP_DISKINSERTED;

    while ( ((vptr = findVolume( volname )) == NULL) &&
     (EasyRequest( w, &volumeES, &iflags, volname ) != CANCEL) )
            /* loop */ ;

        /* note that in some circumstances, you will have to
           re-initialize the value of 'iflags'.  Here, it
           is either unchanged, or returned as the single
           IDCMPFlag value IDCMP_DISKINSERTED.  If you combine
           multiple  IDCMPFlag values in 'iflags,' only
           one will be returned, so you must reinitialize
           'iflags' to be the combination.
          */
        return ( vptr );
    }
