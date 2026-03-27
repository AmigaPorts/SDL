/* Source: ADCD 2.1
 * Section: identifying-network-events-and-talking-to-the-client
 * Library: amiga-mail
 * ADCD reference: amiga-mail/identifying-network-events-and-talking-to-the-client.md
 */

    sockadd_in saddr;
    int len;

    if (!(nsock = accept( sock, (struct sockaddr *)&saddr, &len )))
    {
        AppPanic("Accept:",errno);
    }
