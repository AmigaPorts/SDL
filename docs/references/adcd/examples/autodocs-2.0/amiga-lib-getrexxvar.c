/* Source: ADCD 2.1
 * Section: amiga-lib-getrexxvar
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-getrexxvar.md
 */

    char    *value;

    /* [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) is one from ARexx */
    if (!GetRexxVar(rxmsg,"TheVar",&value))
    {
            /* The value was gotten and now is pointed to by value */
            printf("Value of TheVar is %sn",value);
    }
