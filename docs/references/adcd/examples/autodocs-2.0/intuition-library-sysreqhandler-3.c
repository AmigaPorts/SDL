/* Source: ADCD 2.1
 * Section: intuition-library-sysreqhandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-sysreqhandler.md
 */

    Request a volume, but don't remove the requester when the
    user inserts the wrong disk:

    struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) volumeES = {
        sizeof (struct EasyStruct),
        0,
        "Volume Request",
        "Please insert volume %s in any drive.",
        "Cancel"
    };

    Volume *
    getVolume( volname )
    UBYTE   *volname;
    {
        struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797)       *window;
        Volume              *volume = NULL;
        Volume              *findVolume();
        int                 retval;

        window = BuildEasyRequest( NULL, &volumeES, IDCMP_DISKINSERTED,
                  volname );

        while ( (retval = SysReqHandler( window, NULL, TRUE )) != 0 )
        {
            /* not cancelled yet    */

            /* when IDCMP_DISKINSERTED, check for volume */
            if (( retval == -1 ) && (volume = findVolume( volname )))
                break;
        }
        FreeSysRequest( window );
        return ( volume );
    }
