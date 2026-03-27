/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    UBYTE buf[256], *name;  /* general work buffer & pointer */
    struct FileInfoBlock *fib = (struct FileInfoBlock *) calloc(1, sizeof(*fib));
    int i;

    if (fib)
    {
        for (i = 0; i < am->am_NumArgs; ++i)    /* until list exhausted */
        {
            if (am->am_ArgList[i].wa_Lock)
            {
                if (Examine(am->am_ArgList[i].wa_Lock, fib))
                {
                    if (!NameFromLock(am->am_ArgList[i].wa_Lock, buf, sizeof(buf)))
                        fatal("ADC: GetPath failed!!");

                    if (buf[strlen(buf)-1] != ':') /* do we need to add a slash?    */
                    {
                        buf[strlen(buf)+1] = NULL;
                        buf[strlen(buf)] = '/';
                    }

                    /* append name to path
                    */
                    if (amicount < ASIZE)
                    {
                        appName[amicount] = name = (char*) strdup(am->am_ArgList[i].wa_Name);
                        strcat(buf, am->am_ArgList[i].wa_Name);
                        amenu[amicount] = (struct AppMenu*) AddAppMenuItem(amicount, strdup(buf), name, aport, NULL);
                        ++amicount;
                    }
                    else
                        warning2("ADC: Array Overflow - Cannot add", am->am_ArgList[i].wa_Name);
                }
                else
                    warning2("ADCCant find directory for", am->am_ArgList[i].wa_Name);
            }
            else
                warning2("ADC: Entry Without Lock!!", am->am_ArgList[i].wa_Name);
        }
        UpdateWindow(win);

        free(fib);
    }
