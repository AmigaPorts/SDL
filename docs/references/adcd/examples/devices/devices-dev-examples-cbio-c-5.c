/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

    {

    length = size;
    if (size & 1)
        length++;            /* if odd size, read 1 more */

    if (buf->mem = AllocMem(length+1L,MEMF_PUBLIC))
        {
        buf->size = length+1L;

        ior->io_Command = CMD_READ;
        ior->io_Data    = (STRPTR)buf->mem;
        ior->io_Length  = length;

        to = buf->mem;
        count = 0L;

        if (!(DoIO( (struct IOStdReq *) ior)))
            {
            if (ior->io_Actual == length)
                {
                success = buf;      /* everything succeeded */

                /* strip NULL bytes */
                for (x=0, from=buf->mem ;x<size;x++)
                     {
                     if (*from)
                         {
                         *to = *from;
                         to++;
                         count++;
                         }

                     from++;
                     }
                *to=0x0;            /* Null terminate buffer */
                buf->count = count; /* cache count of chars in buf */
                }
            }

        if (!(success))
            FreeMem(buf->mem,buf->size);
        }
    if (!(success))
        FreeMem(buf,sizeof(struct cbbuf));
    }
