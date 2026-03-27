/* Source: ADCD 2.1
 * Section: amiga-lib-setrexxvar
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-setrexxvar.md
 */

    char    *value;

    /* [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) is one from ARexx */
    if (!SetRexxVar(rxmsg,"TheVar","25 Dollars",10))
    {
            /* The value of TheVar will now be "25 Dollars" */
    }
