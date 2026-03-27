/* Source: ADCD 2.1
 * Section: v-11-getaspect-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-11-getaspect-c.md
 */

    {
    struct Screen *first;
    struct ViewPort *vp;
    struct DisplayInfo DI;
    ULONG  modeid;
    UBYTE  xAspect, yAspect;

    if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
    {
    printf("%s\n%s\n",Copyright,usage);
    bye("",RETURN_OK);
    }

    /* We will check later to see if we can call V36 functions */
    IntuitionBase = OpenLibrary("intuition.library",34);
    GfxBase = OpenLibrary("graphics.library",34);
    if((!IntuitionBase)||(!GfxBase))
    bye("Can't open intuition or graphics library",RETURN_FAIL);

    printf("Using front screen's ViewPort (for example purposes only):\n");

    first = ((struct IntuitionBase *)IntuitionBase)->FirstScreen;
    vp = &first->ViewPort;

    xAspect = 0;    /* So we can tell when we've got it */

    if(GfxBase->lib_Version >= 36)
    {
        modeid = GetVPModeID(vp);

        if(GetDisplayInfoData(NULL, (UBYTE *)&DI, sizeof(struct DisplayInfo),
        DTAG_DISP, modeid))
        {
        printf("Running 2.0,  ViewPort modeid is $%08lx\n",modeid);
        xAspect = DI.Resolution.x;
        yAspect = DI.Resolution.y;
        printf("Pixel  xAspect=%ld  yAspect=%ld\n",xAspect, yAspect);
        printf("PaletteRange is %ld\n",DI.PaletteRange);
        }
    }

    if(!xAspect)  /* pre-2.0 or GetDisplayInfoData failed */
    {
    modeid = vp->Modes;
    printf("Not running 2.0, ViewPort mode is $%04lx\n",modeid);
        /* default lores pixel ratio */
        xAspect = 44;
        yAspect = ((struct GfxBase *)GfxBase)->DisplayFlags & PAL  ? 44 : 52;
        if(modeid & HIRES)      xAspect = xAspect >> 1;
        if(modeid & LACE)       yAspect = yAspect >> 1;
    printf("Pixel  xAspect=%ld  yAspect=%ld\n",xAspect, yAspect);
        }

    bye("",RETURN_OK);
    }
