/* Source: ADCD 2.1
 * Section: lib-examples-sift-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-sift-c.md
 */

    struct IFFHandle	*iff = NULL;
    long		error;
    short		cbio;

    	/* if not enough args or '?', print usage */
    	if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
