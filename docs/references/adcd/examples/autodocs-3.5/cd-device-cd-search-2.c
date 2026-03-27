/* Source: ADCD 2.1
 * Section: cd-device-cd-search
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-search.md
 */

       /* Search in fast forward mode. */
       ior->io_Command = CD_SEARCH;
       ior->io_Data    = NULL;
       ior->io_Offset  = 0;
       ior->io_Length  = CDMODE_FFWD;
       DoIO(ior);
