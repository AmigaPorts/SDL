/* Source: ADCD 2.1
 * Section: workbench-library-addappicona
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/workbench-library-addappicona.md
 */

    AppIcon = AddAppIconA(id, userdata, text, msgport,
       D0                 D0     D1      A0     A1

                                    lock, diskobj, taglist)
                                     A2      A3      A4

    struct AppIcon *AddAppIconA(ULONG, ULONG, char *,
            struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [FileLock](../Includes_and_Autodocs_2._guide/node0078.html#line453) *, struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *,
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct AppIcon *AddAppIcon(ULONG, ULONG, char *,
                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [FileLock](../Includes_and_Autodocs_2._guide/node0078.html#line453) *,
                    struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *,
                    tag1, data1,
                    tag2, data2,
                    ...
                    TAG_END );
