/* Source: ADCD 2.1
 * Section: 33-custom-stream-handlers-installing-a-custom-stream-handler
 * Library: libraries
 * ADCD reference: libraries/33-custom-stream-handlers-installing-a-custom-stream-handler.md
 */

    { NULL },
    (ULONG (*)()) HookEntry,        /* h_Entry, assembler stub entry */
    (ULONG (*)()) mystreamhandler,
                              /* h_SubEntry, std args function entry */
    NULL };
