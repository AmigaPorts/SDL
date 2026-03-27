/* Source: ADCD 2.1
 * Section: devices-apps-ilbmtoraw-ilbmtoraw-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmtoraw-ilbmtoraw-c.md
 */

    ilbm.ParseInfo.propchks      = ilbmprops;
    ilbm.ParseInfo.collectchks   = ilbmcollects;
    ilbm.ParseInfo.stopchks      = ilbmstops;
    if(!(ilbm.ParseInfo.iff = AllocIFF()))
    	bye(IFFerr(IFFERR_NOMEM),RETURN_FAIL);	/* Alloc an IFFHandle */

    ilbmname = argv[1];

    /* Load as a brush since we don't need to display it */
    if (error = loadbrush(&ilbm,ilbmname))
        {
        printf("Can't load ilbm \"%s\", ifferr=%s\n",ilbmname,IFFerr(error));
        bye("",RETURN_WARN);
        }
    else /* Successfully loaded ILBM */
