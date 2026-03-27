/* Source: ADCD 2.1
 * Section: ii-77-fast-amigados-i-o
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-fast-amigados-i-o.md
 */

         request that OpenAsync() sent has not completed, ReadAsync()
         will put the application to sleep until that request
         returns. Ideally, the read will have returned, so the
         application won't have to wait. ReadAsync() will also
         initiate a new asynchronous read so new file data is ready
         when the application needs it.
