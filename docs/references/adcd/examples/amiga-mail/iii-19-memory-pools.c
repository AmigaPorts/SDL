/* Source: ADCD 2.1
 * Section: iii-19-memory-pools
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-19-memory-pools.md
 */

    APTR mem_pool;

    if (mem_pool = CreatePool(MEMF_FAST,4096,2048))
    {
        .  .  .
    }

    else
        printf("Pool could not be created.\n");
