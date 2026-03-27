/* Source: ADCD 2.1
 * Section: iii-29-dillo-test-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-test-c.md
 */

    BOOL okay = FALSE;
    ULONG i = 0L;

    if (DilloBase = OpenLibrary("armadillo.library",0))
    {

        for (i=0;i<5;i++)
        {
            if (dillo[i] = CreateArmadillo())
            {
                if (okay = NameArmadillo( dillo[i], names[i], namlen[i] ))
                {
                    printf("Armadillo %ld named %s.\n",i,names[i]);
                }
                else
                {
                    printf("Armadillo %ld naming failure, it's anonymous.\n",i);
                }

                if (okay = FillArmadillo( dillo[i], weight[i] ))
                {
                    printf("Armadillo %ld weighs %ld.\n",i,weight[i]);
                }
                else
                {
                    printf("Armadillo %ld fill failure, it's dieting.\n",i);
                }

                if (i>2)
                {
                    if (okay = FlattenArmadillo( dillo[i], TRUE ))
                    {
                        printf("Armadillo %ld had a slight mishap.\n",i);
                    }
                }
            }
            else
            {
                printf("Couldn't create Armadillo %ld\n",i);
            }
        }

        /* Okay, all the armadillos are created (hopefully) and */
        /* so as proof of concept and to test the data access   */
        /* functions, now the program shows the status of each  */
        /* of the armadillos.                                   */

        printf("\nArmadillo Status Report\n");
        printf("-----------------------\n");

        for(i=0;i<5;i++)
        {
            UBYTE namebuf[33];

            printf("Armadillo #%ld\n",i);
            if (DilloName(dillo[i],(STRPTR)&namebuf,32))
            {
                printf("  Name   = \"%s\"\n",namebuf);
            }
            else
            {
                printf("  Name is invalid.\n");
            }
            printf("  Weight = %ld pounds\n\n",DilloWeight(dillo[i]));
            printf("  Dillo is %s\n",
                   (DilloFlat(dillo[i])?"flat":"lucky"));
            printf("-----\n");
        }

        printf("Total Dillos created: %ld\n\n",DilloBirths());

        /* Now that the armadillos have been tested, we can */
        /* delete them with gleeful abandon.                */

        for(i=0;i<5;i++)
        {
            DeleteArmadillo( dillo[i] );
        }

        /* We're done, so close the library... */
        CloseLibrary(DilloBase);
    }
    else
    {
        printf("Couldn't open armadillo.library!\n");
    }
