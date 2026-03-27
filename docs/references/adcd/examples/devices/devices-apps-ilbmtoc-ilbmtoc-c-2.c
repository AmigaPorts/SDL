/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoc-ilbmtoc-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoc-ilbmtoc-c.md
 */

    ilbm.ParseInfo.propchks      = ilbmprops;
    ilbm.ParseInfo.collectchks   = ilbmcollects;
    ilbm.ParseInfo.stopchks      = ilbmstops;
    if(!(ilbm.ParseInfo.iff = AllocIFF()))
    	bye(IFFerr(IFFERR_NOMEM),RETURN_FAIL);	/* Alloc an IFFHandle */

    sw = (argc>2) ? (UBYTE *)argv[2] : defSwitch;
    ilbmname = argv[1];

    if (error = loadbrush(&ilbm,ilbmname))
        {
        printf("Can't load ilbm \"%s\", ifferr=%s\n",ilbmname,IFFerr(error));
        bye("",RETURN_WARN);
        }
    else /* Successfully loaded ILBM */
