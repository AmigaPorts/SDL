/* Source: ADCD 2.1
 * Section: lib-examples-strhooks-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-strhooks-c.md
 */

    {
    /* mouse click
    ** zero the digit clicked on
    */
    if (sgw->BufferPos < sgw->NumChars)
        {
        work_ptr = sgw->WorkBuffer + sgw->BufferPos;
        *work_ptr = '0';
        }
    }
