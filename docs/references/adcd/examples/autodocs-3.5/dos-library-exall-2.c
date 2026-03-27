/* Source: ADCD 2.1
 * Section: dos-library-exall-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/dos-library-exall-2.md
 */

       more = ExAll(lock, EAData, sizeof(EAData), ED_FOO, eac);
       if ((!more) && (IoErr() != ERROR_NO_MORE_ENTRIES)) {
           * ExAll failed abnormally *
           break;
       }
       if (eac->eac_Entries == 0) {
           * ExAll failed normally with no entries *
           continue;                   * ("more" is *usually* zero) *
       }
       ead = (struct [ExAllData](../Includes_and_Autodocs_3._guide/node0608.html#line44) *) EAData;
       do {
           * use ead here *
           ...
           * get next ead *
           ead = ead->ed_Next;
       } while (ead);
