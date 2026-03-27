/* Source: ADCD 2.1
 * Section: text-autodocs-dos-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-dos-doc.md
 */

       more = ExAll(lock, EAData, sizeof(EAData), ED_FOO, eac);
       if ((!more) && (IoErr() != ERROR_NO_MORE_ENTRIES)) {
           /* ExAll failed abnormally */
           break;
       }
       if (eac->eac_Entries == 0) {
           /* ExAll failed normally with no entries */
           continue;                   /* ("more" is *usually* zero) */
       }
       ead = (struct ExAllData *) EAData;
       do {
           /* use ead here */
           ...
           /* get next ead */
           ead = ead->ed_Next;
       } while (ead);
