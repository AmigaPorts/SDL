/* Source: ADCD 2.1
 * Section: devices-dev-examples-clipdemo-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-clipdemo-c.md
 */

    {

    /* Look for FTXT in clipboard */

    if (CBQueryFTXT(ior))
        {

        /* Obtain a copy of the contents of each CHRS chunk */

        while (buf=CBReadCHRS(ior))
              {
              /* Process data */

              printf("%s\n",buf->mem);

              /* Free buffer allocated by CBReadCHRS() */

              CBFreeBuf(buf);
              }

        /* The next call is not really needed if you are sure */
        /* you read to the end of the clip.                   */

        CBReadDone(ior);
        }
    else
        {
        puts("No FTXT in clipboard");
        }

    CBClose(ior);
    }
