/* Source: ADCD 2.1
 * Section: xi-25-appmap-demo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-25-appmap-demo-c.md
 */

    if (DoPkt (conport, ACTION_DISK_INFO, ((ULONG) id) >> 2, 0L, 0L, 0L, 0L))
    {
      if (replyport = CreateMsgPort ())
      {
        if (ior = CreateIORequest (replyport, sizeof (struct IOStdReq)))
        {
          ior->io_Device = ((struct IOStdReq *) id->id_InUse)->io_Device;
          ior->io_Unit = ((struct IOStdReq *) id->id_InUse)->io_Unit;
        }
      }
    }
    FreeMem (id, sizeof (struct InfoData));
