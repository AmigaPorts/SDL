/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {

    /* Very simple code to parse for arguments - will suffice for
     * the sake of this example
     */

    if (argc > 1)
       {
       if (!(strcmp(argv[1],"-r")))
           todo = READIT;
       if (!(strcmp(argv[1],"-w")))
           todo = WRITEIT;
       if (!(strcmp(argv[1],"-p")))
           todo = POSTIT;

       string = NULL;

       if (argc > 2)
           string=argv[2];

       }

    switch (todo)
            {

            case READIT:

                 ReadClip();
                 break;

            case POSTIT:

                 PostClip(string);
                 break;

            case WRITEIT:

                 WriteClip(string);
                 break;

            default:

                 printf("%s",message);
                 break;

            }
    }
