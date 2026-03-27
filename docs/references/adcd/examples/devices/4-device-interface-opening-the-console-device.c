/* Source: ADCD 2.1
 * Section: 4-device-interface-opening-the-console-device
 * Library: devices
 * ADCD reference: devices/4-device-interface-opening-the-console-device.md
 */

    struct MsgPort *ConsoleMP;   /* Message port pointer */
    struct IOStdReq *ConsIO;     /* I/O structure pointer */
    struct Window   *win = NULL; /* Window pointer */

    struct NewWindow nw =
    {
        10, 10,                    /* starting position (left,top) */
        620,180,                   /* width, height */
        -1,-1,                     /* detailpen, blockpen */
        CLOSEWINDOW,               /* flags for idcmp */
        WINDOWDEPTH|WINDOWSIZING|
        WINDOWDRAG|WINDOWCLOSE|
        SIMPLE_REFRESH|ACTIVATE,    /* window flags */
        NULL,                      /* no user gadgets */
        NULL,                      /* no user checkmark */
        "Console Test",            /* title */
        NULL,                      /* pointer to window screen */
        NULL,                      /* pointer to super bitmap */
        100,45,                    /* min width, height */
        640,200,                   /* max width, height */
        WBENCHSCREEN               /* open on workbench screen */
    };

        /* Create reply port console */
    if (!(ConsoleMP = CreatePort("RKM.Console",0)))
        cleanexit("Can't create write port\n",RETURN_FAIL);

        /* Create message block for device I/O */
    if (!(ConsIO = CreateExtIO(ConsoleMP,sizeof(struct IOStdReq))))
        cleanexit("Can't create IORequest\n",RETURN_FAIL);

        /* Open a window - we assume intuition.library is already open */
    if (!(win = OpenWindow(&nw)))
        cleanexit("Can't open window\n",RETURN_FAIL);

        /* Set window pointer and size in I/O request */
    ConsIO->io_Data = (APTR) win;
    ConsIO->io_Length = sizeof(struct Window);

        /* Open the console device */
    if (error = OpenDevice("console.device",CONU_CHARMAP,ConsIO,
                                            CONFLAG_DEFAULT))
        cleanexit("Can't open console.device\n",RETURN_FAIL);
