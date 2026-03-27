/* Source: ADCD 2.1
 * Section: lib-examples-rawkey-c
 * Library: devices
 * ADCD reference: devices/lib-examples-rawkey-c.md
 */

    /* conversion failed, buffer too small. try to double the size of the buffer. */
    FreeMem(*buffer, *bufsize);
    *bufsize = *bufsize << 1;
    printf("Increasing buffer size to %d\n", *bufsize);

    if (NULL == (*buffer = AllocMem(*bufsize, MEMF_CLEAR)))  ret_code = FALSE;
    else  numchars = deadKeyConvert(msg, *buffer, *bufsize - 1, NULL, ievent);
    }
