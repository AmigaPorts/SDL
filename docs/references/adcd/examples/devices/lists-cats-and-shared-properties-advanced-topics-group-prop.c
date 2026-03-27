/* Source: ADCD 2.1
 * Section: lists-cats-and-shared-properties-advanced-topics-group-prop
 * Library: devices
 * ADCD reference: devices/lists-cats-and-shared-properties-advanced-topics-group-prop.md
 */

    #define Roman           0
    #define Helvetica       1

    void main()
            {
            int font=Roman; /* The global default */
                    {
                    printf("The font number is %d\n",font);
                    }
                    {
                    int font=Helvetica;     /* local setting */
                    printf("The font number is %d\n",font);
                    }
                    {
                    printf("The font number is %d\n",font);
                    }
            }


    /*
    * Sample output:       The font number is 0
    *                      The font number is 1
    *                      The font number is 0
    */




    An IFF file could contain:

    LIST {
            PROP TEXT {
                    FONT {TimesRoman}       /* shared setting       */
                    }

            FORM TEXT {
                    FONT {Helvetica}        /* local setting        */
                    CHRS {Hello }           /* uses font Helvetica  */
                    }

            FORM TEXT {
                    CHRS {there.}           /* uses font TimesRoman */
                    }
            }
