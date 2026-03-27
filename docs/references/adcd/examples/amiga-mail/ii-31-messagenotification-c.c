/* Source: ADCD 2.1
 * Section: ii-31-messagenotification-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-31-messagenotification-c.md
 */

    struct RDArgs  *readargs;
    LONG            rargs[2];
    struct NotifyRequest *notifyrequest;
    struct NotifyMessage *notifymsg;
    struct List    *notifylist;
    struct MsgPort *notifyport;
    struct NotifyNode *nnode, *nextnode;
    UBYTE         **filenames;
    ULONG           signal, notifysignal;

    /* To appease amiga.lib */
    SysBase = (*((struct Library **) 4));

    /* Fail silently if < 37 */
    if (DOSBase = OpenLibrary("dos.library", 37))
    {

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("Filename/A/M", rargs, NULL))
        {
            /* Pointer to array of filenames */
            filenames = (UBYTE **) (rargs[0]);

            if (notifyport = CreateMsgPort())
            {
                if (notifylist = AllocMem(sizeof(struct List), MEMF_CLEAR))
                {
                    /* initialize list */
                    NewList(notifylist);

                    /* The list of filenames is terminated with a NULL */
                    while (*filenames)
                    {
                        /* Get a NotifyNode */
                        if (nnode = AllocMem(sizeof(struct NotifyNode), MEMF_CLEAR))
                        {
                            /*
                             * Use ln_Name to store qualified filename to
                             * monitor. Note that I keep using that pointer to
                             * the command argument line here. In a real life
                             * application you're better off copying the
                             * string.
                             */
                            nnode->nn_Node.ln_Name = (UBYTE *) * filenames++;
                            notifyrequest = &(nnode->nn_NotifyRequest);

                            /* Initialize notifcation request */
                            notifyrequest->nr_Name = nnode->nn_Node.ln_Name;
                            notifyrequest->nr_Flags = NRF_SEND_MESSAGE | NRF_WAIT_REPLY;
                            notifyrequest->nr_stuff.nr_Msg.nr_Port = notifyport;
                            /*
                             * I'm storing the address of the NotifyNode in
                             * nr_UserData. Not going to do anything with it
                             * here, but it would enable me to use the node
                             * immediately when I receive a NotifyMessage.
                             */
                            notifyrequest->nr_UserData = (ULONG) nnode;
                            /*
                             * only add the node to the list if notification is
                             * supported
                             */
                            if ((StartNotify(notifyrequest)) == DOSTRUE)
                            {
                                AddTail(notifylist, (struct Node *) nnode);
                                Printf("Notification on %s\n",
                                       (LONG) nnode->nn_Node.ln_Name);
                            }
                            else
                            {
                                Printf("Notification failed on %s\n",
                                       (LONG) nnode->nn_Node.ln_Name);
                                FreeMem(nnode, sizeof(struct NotifyNode));
                            }
                        }
                        else
                        {
                            PrintFault(ERROR_NO_FREE_STORE, NULL);
                            break;
                        }
                    }

                    /*
                     * Is list empty? If so get out of here. (Macro defined in
                     * <exec/lists.h>)
                     */
                    if (!(IsListEmpty(notifylist)))
                    {
                        /*
                         * No empty, so we've got outstanding NotifyRequests.
                         * Loop until Ctrl-C.
                         */
                        notifysignal = 1L << notifyport->mp_SigBit;
                        for (;;)
                        {
                            /* Wait for message port signals and break */
                            signal = Wait(notifysignal | SIGBREAKF_CTRL_C);

                            if (signal & notifysignal)
                            {
                                while (notifymsg =
                                        (struct NotifyMessage *) GetMsg(notifyport))
                                {
                                    /*
                                     * Here is that node again, stuffed in
                                     * nr_UserData. Can immediately reference
                                     * its data, like comparing filesize with
                                     * stored filesize in node, or remove it
                                     * (after an EndNotify() ofcourse).
                                     */
                                    Printf("Notification message for %s, Node at 0x%lx\n",
                                           (LONG) notifymsg->nm_NReq->nr_Name,
                                      (LONG) notifymsg->nm_NReq->nr_UserData);
                                    ReplyMsg((struct Message *) notifymsg);
                                }
                            }

                            if (signal & SIGBREAKF_CTRL_C)
                            {
                                /*
                                 * Walk down the list, remove all
                                 * NotifyRequests, free all nodes.
                                 */
                                nnode = (struct NotifyNode *) notifylist->lh_Head;
                                while (nextnode =
                                        (struct NotifyNode *) nnode->nn_Node.ln_Succ)
                                {
                                    notifyrequest = &(nnode->nn_NotifyRequest);
                                    Printf("Removing notifcation for %s\n",
                                           (LONG) notifyrequest->nr_Name);
                                    /*
                                     * remove this request. EndNotify() will
                                     * also remove any messages on the message
                                     * port.
                                     */
                                    EndNotify(notifyrequest);
                                    /*
                                     * Not really needed to Remove() the node,
                                     * never going to use this list again
                                     */
                                    Remove((struct Node *) nnode);
                                    FreeMem(nnode, sizeof(struct NotifyNode));
                                    nnode = nextnode;
                                }
                                break;
                            }
                        }
                    }
                    FreeMem(notifylist, sizeof(struct List));
                }
                DeleteMsgPort(notifyport);
            }
            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary(DOSBase);
    }
