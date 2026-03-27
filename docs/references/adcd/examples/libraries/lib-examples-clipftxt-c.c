/* Source: ADCD 2.1
 * Section: lib-examples-clipftxt-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-clipftxt-c.md
 */

    struct IFFHandle	*iff = NULL;
    struct ContextNode  *cn;
    long		error=0, unitnumber=0, rlen;
    int textlen;
    UBYTE readbuf[RBUFSZ];

    	/* if not enough args or '?', print usage */
    	if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
