/* Source: ADCD 2.1
 * Section: devices-apps-rawtoilbm-rawtoilbm-c
 * Library: devices
 * ADCD reference: devices/devices-apps-rawtoilbm-rawtoilbm-c.md
 */

    {
    LONG	error = 0L, rawfile, rlen;
    USHORT	width, height, depth, pwidth, pheight, pmode, extra;
    ULONG 	plsize;
    char        *rawname,*ilbmname;
    int 	k;

    fromWB = (argc==0) ? TRUE : FALSE;

    if(!(IntuitionBase = OpenLibrary("intuition.library", 0)))
      bye("Can't open intuition library.\n",RETURN_WARN);

    if(!(GfxBase = OpenLibrary("graphics.library",0)))
      bye("Can't open graphics library.\n",RETURN_WARN);

    if(!(IFFParseBase = OpenLibrary("iffparse.library",0)))
      bye("Can't open iffparse library.\n",RETURN_WARN);

    if(!(ilbm.ParseInfo.iff = AllocIFF()))
      bye(IFFerr(IFFERR_NOMEM),RETURN_WARN);

    if(argc==MINARGS)                 /* Passed filenames via command line  */
      	{
      	rawname  = argv[1];
      	ilbmname = argv[2];
