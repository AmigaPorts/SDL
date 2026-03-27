/* Source: ADCD 2.1
 * Section: devices-other-sift-c
 * Library: devices
 * ADCD reference: devices/devices-other-sift-c.md
 */

    struct IFFHandle	*iff = NULL;
    long		error;
    short		cbio;

    	/* if not enough args or '?', print usage */
    	if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
