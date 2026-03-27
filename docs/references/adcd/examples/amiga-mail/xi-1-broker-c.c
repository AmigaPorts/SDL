/* Source: ADCD 2.1
 * Section: xi-1-broker-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-1-broker-c.md
 */

    /* Before bothering with anything else, open the library */
    if (CxBase = OpenLibrary("commodities.library", 37L))
    {
        /* Commodities talks to a Commodities application through
         * an Exec Message port, which the application provides
         */
        if (broker_mp = CreateMsgPort())
        {
            newbroker.nb_Port = broker_mp;

            /* The commodities.library function CxBroker() adds a
             * broker to the master list.  It takes two arguments,
             * a pointer to a NewBroker structure and a pointer to
             * a LONG.  The NewBroker structure contains information
             * to set up the broker.  If the second argument is not
             * NULL, CxBroker will fill it in with an error code.
             */
            if (broker = CxBroker(&newbroker, NULL))
            {
                cxsigflag = 1L << broker_mp->mp_SigBit;

                /* After it's set up correctly, the broker
                 * has to be activated
                 */
                ActivateCxObj(broker, 1L);

                /* the main processing loop */
                while (ProcessMsg());

                /* It's time to clean up.  Start by removing
                 * the broker from the Commodities master list.
                 * The DeleteCxObjAll() function will take care
                 * of removing a CxObject and all those connected
                 * to it from the Commodities network
                 */
                DeleteCxObj(broker);
            }
            DeletePort(broker_mp);
        }
        CloseLibrary(CxBase);
    }
