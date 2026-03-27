/* Source: ADCD 2.1
 * Section: 34-keymap-functions-accessing-the-keymap-for-the-current
 * Library: libraries
 * ADCD reference: libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md
 */

    request->io_Command = CD_ASKKEYMAP;
    request->io_Length = sizeof(struct KeyMap);
    request->io_Data = (APTR)keymap;  /* where to put it */
    DoIO(request);
    if(request->io_Error) return(FALSE);
    else  return(TRUE); /* if no error, it worked. */
