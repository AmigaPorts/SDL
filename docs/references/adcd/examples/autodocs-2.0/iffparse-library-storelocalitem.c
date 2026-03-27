/* Source: ADCD 2.1
 * Section: iffparse-library-storelocalitem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-storelocalitem.md
 */

    error = StoreLocalItem (iff, item, position)
     d0                     a0    a1      d0

    LONG                    error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82)   *item;
    LONG                    position;
