/* Source: ADCD 2.1
 * Section: samp-doc-additional-user-data-section
 * Library: devices
 * ADCD reference: devices/samp-doc-additional-user-data-section.md
 */

                  There are some samplers that allow more than just
                  one loop (Casio products primarily). Additional
                  looping info can be stored in this format:

                 UWORD numOfLoops;  /* number of loop points to follow */

                 ULONG StartLoop1,  /* BYTE offset from the beginning of
                                      the sample to the start of loop1 */
                 EndLoop1,          /* BYTE offset from the beginning of
                                      the sample to the end of loop1 */

                 StartLoop2,        /* ...etc */
