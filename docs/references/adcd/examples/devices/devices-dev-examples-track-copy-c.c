/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

    tsk=(struct Process *)FindTask(NULL);
    if (pk=AllocMem(sizeof(struct StandardPacket),MEMF_PUBLIC|MEMF_CLEAR))
    {
        pk->sp_Msg.mn_Node.ln_Name=(UBYTE *)&(pk->sp_Pkt);

        pk->sp_Pkt.dp_Link=&(pk->sp_Msg);
        pk->sp_Pkt.dp_Port=&(tsk->pr_MsgPort);
        pk->sp_Pkt.dp_Type=ACTION_INHIBIT;
        pk->sp_Pkt.dp_Arg1=(onflag ? -1L : 0L);

        PutMsg(DeviceProc(drive),(struct Message *)pk);
        WaitPort(&(tsk->pr_MsgPort));
        GetMsg(&(tsk->pr_MsgPort));
        FreeMem(pk,(long)sizeof(*pk));
    }
