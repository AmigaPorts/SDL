/* Source: ADCD 2.1
 * Section: iv-111-relative-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-111-relative-c.md
 */

    gad->Flags ^= GFLG_SELECTED;
    if ( rp = ObtainGIRPort( msg->gpi_GInfo ) )
    {
      DoMethod( (Object *)gad, GM_RENDER, msg->gpi_GInfo, rp, GREDRAW_UPDATE );
      ReleaseGIRPort( rp );
    }
