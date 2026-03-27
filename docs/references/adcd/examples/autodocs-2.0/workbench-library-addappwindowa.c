/* Source: ADCD 2.1
 * Section: workbench-library-addappwindowa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/workbench-library-addappwindowa.md
 */

    [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) = AddAppWindowA(id, userdata, window, msgport, taglist)
    D0                        D0     D1       A0      A1       A2

    struct [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) *AddAppWindowA(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) *AddAppWindow(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
