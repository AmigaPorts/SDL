/* Source: ADCD 2.1
 * Section: include-devices-cd-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-cd-h.md
 */

    UWORD   PlaySpeed;	    /* Audio play speed	      (75)	  */
    UWORD   ReadSpeed;	    /* Data-rate of CD_READ command   (Max)	  */
    UWORD   ReadXLSpeed;    /* Data-rate of CD_READXL command (75)	  */
    UWORD   SectorSize;     /* Number of bytes per sector     (2048)	  */
    UWORD   XLECC;	    /* CDXL ECC enabled/disabled		  */
    UWORD   EjectReset;     /* Reset on eject enabled/disabled		  */
    UWORD   Reserved1[4];   /* Reserved for future expansion		  */

    UWORD   MaxSpeed;	    /* Maximum speed drive can handle (75, 150)   */
    UWORD   AudioPrecision; /* 0 = no attenuator, 1 = mute only,	  */
