/* Source: ADCD 2.1
 * Section: iii-19-memory-pools
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-19-memory-pools.md
 */

    struct timerequest *TimerReq;

    if (TimerReq = AllocPooled(mem_pool, sizeof(struct timerequest))
    {
        .  .  .
    }

    else
        printf("Memory could not be allocated.\n");
