/* Source: ADCD 2.1
 * Section: xi-1-hotkey-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-1-hotkey-c.md
 */

    char *hotkey, **ttypes;

    if (CxBase = OpenLibrary("commodities.library", 37L))
    {
        /* open the icon.library for the support library
         * functions, ArgArrayInit() and ArgArrayDone()
         */
        if (IconBase = OpenLibrary("icon.library", 36L))
        {
            if (broker_mp = CreateMsgPort())
            {
                newbroker.nb_Port = broker_mp;
                cxsigflag = 1L << broker_mp->mp_SigBit;

                /* ArgArrayInit() is a support library function
                 * (from the 2.0 version of amiga.lib) that makes it
                 * easy to read arguments from either a CLI or from
                 * the Workbench's ToolTypes.  Because it uses
                 * icon.library, the library has to be open before
                 * calling this function.  ArgArrayDone() cleans up
                 * after this function.
                 */
                ttypes = ArgArrayInit(argc, argv);

                /* ArgInt() (also from amiga.lib) searches through the
                 * array set up by ArgArrayInit() for a specific
                 * ToolType.  If it finds one, it returns the numeric
                 * value of the number that followed the ToolType
                 * (i.e. CX_PRIORITY=7).  If it doesn't find the ToolType,
                 * it returns the default value (the third argument)
                 */
                newbroker.nb_Pri = (BYTE)ArgInt(ttypes, "CX_PRIORITY", 0);

                /* ArgString() works just like ArgInt(), except it
                 * returns a pointer to a string rather than an integer.
                 * In the example below, if there is no ToolType "HOTKEY",
                 * the function returns a pointer to "rawkey control esc".
                 */
                hotkey = ArgString(ttypes, "HOTKEY", "rawkey control esc");

                if (broker = CxBroker(&newbroker, NULL))
                {
                    /* CxFilter() is a macro that creates a filter
                     * CxObject.  This filter passes input events that
                     * match the string pointed to by hotkey.
                     */
                    if (filter = CxFilter(hotkey))
                    {
                        /* Add a CxObject to another's personal list */
                        AttachCxObj(broker, filter);

                        /* CxSender() creates a sender CxObject.  Every
                         * time a sender gets a CxMessage, it sends a new
                         * CxMessage to the port pointed to in the first
                         * argument.  CxSender()'s second argument will be
                         * the ID of any CxMessages the sender sends to
                         * the port.  The data pointer associated with the
                         * CxMessage will point to a *COPY* of the
                         * InputEvent structure associated with the orginal
                         * CxMessage.
                         */
                        if (sender = CxSender(broker_mp, EVT_HOTKEY))
                        {
                            AttachCxObj(filter, sender);

                            /* CxTranslate() creates a translate CxObject.
                             * When a translate CxObject gets a CxMessage,
                             * it deletes the original CxMessage and adds
                             * a new input event to the input.device's
                             * input stream after the Commodities input
                             * handler.  CxTranslate's argument points
                             * to an InputEvent structure from which to
                             * create the new input event.  In this example,
                             * the pointer is NULL, meaning no new event
                             * should be introduced.
                             */
                            if (translate = (CxTranslate(NULL)))
                            {
                                AttachCxObj(filter, translate);

                                /* CxObjError() is a commodities.library
                                 * function that returns the internal
                                 * accumulated error code of a CxObject.
                                 */
                                if (! CxObjError(filter))
                                {
                                    ActivateCxObj(broker, 1L);
                                    while (ProcessMsg());
                                }
                            }
                        }
                    }
                    /* DeleteCxObjAll() is a commodities.library function
                     * that not only deletes the CxObject pointed to in
                     * its argument, but it deletes all of the CxObjects
                     * that are attached to it.
                     */
                    DeleteCxObjAll(broker);
                }
                DeletePort(broker_mp);
            }

            /* this amiga.lib function cleans up after ArgArrayInit() */
            ArgArrayDone();
            CloseLibrary(IconBase);
        }
        CloseLibrary(CxBase);
    }
