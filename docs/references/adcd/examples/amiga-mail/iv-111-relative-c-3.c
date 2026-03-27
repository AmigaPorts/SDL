/* Source: ADCD 2.1
 * Section: iv-111-relative-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-111-relative-c.md
 */

    /* gadgetup, time to go */
    if ( selected )
    {
      retval = GMR_NOREUSE | GMR_VERIFY;
    }
    else
    {
      retval = GMR_NOREUSE;
    }
    /* and unselect the gadget on our way out... */
    selected = 0;
