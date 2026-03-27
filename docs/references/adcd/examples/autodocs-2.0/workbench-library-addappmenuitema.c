/* Source: ADCD 2.1
 * Section: workbench-library-addappmenuitema
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/workbench-library-addappmenuitema.md
 */

    [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) = AddAppMenuItemA(id, userdata, text, msgport, taglist)
    D0                            D0     D1      A0     A1       A2

    struct [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) *AddAppMenuItemA(ULONG, ULONG, char *,
                                            struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,
                                            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) *AddAppMenuItem(ULONG, ULONG, char *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
